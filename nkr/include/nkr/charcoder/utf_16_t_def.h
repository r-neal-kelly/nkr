/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/os.h"
#include "nkr/utils.h"

#include "nkr/charcoder/utf_16_t_dec.h"
#include "nkr/charcoder/utf_32_t.h"

namespace nkr { namespace charcoder {

    inline utf_16_t::utf_16_t()
    {
        this->units[0] = 0;
        this->units[1] = 0;
        this->unit_count = 1;
    }

    inline utf_16_t::utf_16_t(const utf_16_t& other)
    {
        this->units[0] = other.units[0];
        this->units[1] = other.units[1];
        this->unit_count = other.unit_count;
    }

    inline utf_16_t::utf_16_t(const volatile utf_16_t& other)
    {
        this->units[0] = other.units[0];
        this->units[1] = other.units[1];
        this->unit_count = other.unit_count;
    }

    inline utf_16_t::utf_16_t(utf_16_t&& other) noexcept
    {
        this->units[0] = nkr::Move(other.units[0]);
        this->units[1] = nkr::Move(other.units[1]);
        this->unit_count = nkr::Exchange(other.unit_count, 1);
    }

    inline utf_16_t::utf_16_t(volatile utf_16_t&& other) noexcept
    {
        this->units[0] = nkr::Move(other.units[0]);
        this->units[1] = nkr::Move(other.units[1]);
        this->unit_count = nkr::Exchange(other.unit_count, 1);
    }

    inline utf_16_t&
        utf_16_t::operator =(const utf_16_t& other)
    {
        if (this != std::addressof(other)) {
            this->units[0] = other.units[0];
            this->units[1] = other.units[1];
            this->unit_count = other.unit_count;
        }
        return *this;
    }

    inline volatile utf_16_t&
        utf_16_t::operator =(const utf_16_t& other)
        volatile
    {
        if (this != std::addressof(other)) {
            this->units[0] = other.units[0];
            this->units[1] = other.units[1];
            this->unit_count = other.unit_count;
        }
        return *this;
    }

    inline utf_16_t&
        utf_16_t::operator =(const volatile utf_16_t& other)
    {
        if (this != std::addressof(other)) {
            this->units[0] = other.units[0];
            this->units[1] = other.units[1];
            this->unit_count = other.unit_count;
        }
        return *this;
    }

    inline volatile utf_16_t&
        utf_16_t::operator =(const volatile utf_16_t& other)
        volatile
    {
        if (this != std::addressof(other)) {
            this->units[0] = other.units[0];
            this->units[1] = other.units[1];
            this->unit_count = other.unit_count;
        }
        return *this;
    }

    inline utf_16_t&
        utf_16_t::operator =(utf_16_t&& other)
        noexcept
    {
        if (this != std::addressof(other)) {
            this->units[0] = nkr::Move(other.units[0]);
            this->units[1] = nkr::Move(other.units[1]);
            this->unit_count = nkr::Exchange(other.unit_count, 1);
        }
        return *this;
    }

    inline volatile utf_16_t&
        utf_16_t::operator =(utf_16_t&& other)
        volatile noexcept
    {
        if (this != std::addressof(other)) {
            this->units[0] = nkr::Move(other.units[0]);
            this->units[1] = nkr::Move(other.units[1]);
            this->unit_count = nkr::Exchange(other.unit_count, 1);
        }
        return *this;
    }

    inline utf_16_t&
        utf_16_t::operator =(is_just_volatile_tr<utf_16_t> auto&& other)
        noexcept
    {
        if (this != std::addressof(other)) {
            this->units[0] = nkr::Move(other.units[0]);
            this->units[1] = nkr::Move(other.units[1]);
            this->unit_count = nkr::Exchange(other.unit_count, 1);
        }
        return *this;
    }

    inline volatile utf_16_t&
        utf_16_t::operator =(is_just_volatile_tr<utf_16_t> auto&& other)
        volatile noexcept
    {
        if (this != std::addressof(other)) {
            this->units[0] = nkr::Move(other.units[0]);
            this->units[1] = nkr::Move(other.units[1]);
            this->unit_count = nkr::Exchange(other.unit_count, 1);
        }
        return *this;
    }

    inline utf_16_t::~utf_16_t()
    {
        this->units[0] = 0;
        this->units[1] = 0;
        this->unit_count = 1;
    }

    inline bool_t
        utf_16_t::Is_Well_Formed_Normal()
        const
    {
        if (this->unit_count == 1) {
            return
                utf_32_t::Is_Scalar(this->units[0]);
        } else if (this->unit_count == 2) {
            return
                utf_32_t::Is_Surrogate_High(this->units[0]) &&
                utf_32_t::Is_Surrogate_Low(this->units[1]);
        } else {
            return false;
        }
    }

    inline bool_t
        utf_16_t::Is_Well_Formed_Swapped()
        const
    {
        if (this->unit_count == 1) {
            return
                utf_32_t::Is_Scalar(os::endian::Swap(this->units[0]));
        } else if (this->unit_count == 2) {
            return
                utf_32_t::Is_Surrogate_High(os::endian::Swap(this->units[0])) &&
                utf_32_t::Is_Surrogate_Low(os::endian::Swap(this->units[1]));
        } else {
            return false;
        }
    }

    inline void_t
        utf_16_t::Encode_Normal(point_t point)
    {
        if (utf_32_t::Is_Scalar(point)) {
            if (point <= 0xFFFF) {
                this->units[0] =
                    static_cast<unit_t>(point);
                this->unit_count = 1;
            } else {
                this->units[0] =
                    static_cast<unit_t>(((point - 0x10000) >> 10) + utf_32_t::SURROGATE_HIGH_FIRST);
                this->units[1] =
                    static_cast<unit_t>(((point - 0x10000) & 0x3FF) + utf_32_t::SURROGATE_LOW_FIRST);
                this->unit_count = 2;
            }
        } else {
            this->units[0] = utf_32_t::REPLACEMENT_CHARACTER;
            this->unit_count = 1;
        }

        assert(Is_Well_Formed_Normal());
    }

    inline void_t
        utf_16_t::Encode_Swapped(point_t point)
    {
        if (utf_32_t::Is_Scalar(point)) {
            if (point <= 0xFFFF) {
                this->units[0] =
                    os::endian::Swap(static_cast<unit_t>(point));
                this->unit_count = 1;
            } else {
                this->units[0] =
                    os::endian::Swap(static_cast<unit_t>(((point - 0x10000) >> 10) + utf_32_t::SURROGATE_HIGH_FIRST));
                this->units[1] =
                    os::endian::Swap(static_cast<unit_t>(((point - 0x10000) & 0x3FF) + utf_32_t::SURROGATE_LOW_FIRST));
                this->unit_count = 2;
            }
        } else {
            this->units[0] = utf_32_t::REPLACEMENT_CHARACTER_16_SWAPPED;
            this->unit_count = 1;
        }

        assert(Is_Well_Formed_Swapped());
    }

    inline point_t
        utf_16_t::Decode_Normal()
        const
    {
        assert(Is_Well_Formed_Normal());

        if (this->unit_count == 1) {
            return
                static_cast<u32_t>(this->units[0]);
        } else {
            return
                ((static_cast<u32_t>(this->units[0]) - utf_32_t::SURROGATE_HIGH_FIRST) << 10) +
                (static_cast<u32_t>(this->units[1]) - utf_32_t::SURROGATE_LOW_FIRST) + 0x10000;
        }
    }

    inline point_t
        utf_16_t::Decode_Swapped()
        const
    {
        assert(Is_Well_Formed_Swapped());

        if (this->unit_count == 1) {
            return
                static_cast<u32_t>(os::endian::Swap(this->units[0]));
        } else {
            return
                ((static_cast<u32_t>(os::endian::Swap(this->units[0])) - utf_32_t::SURROGATE_HIGH_FIRST) << 10) +
                (static_cast<u32_t>(os::endian::Swap(this->units[1])) - utf_32_t::SURROGATE_LOW_FIRST) + 0x10000;
        }
    }

    inline count_t
        utf_16_t::Read_Forward_Normal(const unit_t* from)
    {
        assert(from);

        this->units[0] = *from;
        if (utf_32_t::Is_Surrogate_High(this->units[0])) {
            this->units[1] = *(from + 1);
            if (utf_32_t::Is_Surrogate_Low(this->units[1])) {
                this->unit_count = 2;
            } else {
                this->units[0] = utf_32_t::REPLACEMENT_CHARACTER;
                this->unit_count = 1;
            }
        } else if (utf_32_t::Is_Surrogate_Low(this->units[0])) {
            this->units[0] = utf_32_t::REPLACEMENT_CHARACTER;
            this->unit_count = 1;
        } else {
            this->unit_count = 1;
        }

        return this->unit_count;
    }

    inline count_t
        utf_16_t::Read_Forward_Swapped(const unit_t* from)
    {
        assert(from);

        this->units[0] = *from;
        if (utf_32_t::Is_Surrogate_High(os::endian::Swap(this->units[0]))) {
            this->units[1] = *(from + 1);
            if (utf_32_t::Is_Surrogate_Low(os::endian::Swap(this->units[1]))) {
                this->unit_count = 2;
            } else {
                this->units[0] = utf_32_t::REPLACEMENT_CHARACTER_16_SWAPPED;
                this->unit_count = 1;
            }
        } else if (utf_32_t::Is_Surrogate_Low(os::endian::Swap(this->units[0]))) {
            this->units[0] = utf_32_t::REPLACEMENT_CHARACTER_16_SWAPPED;
            this->unit_count = 1;
        } else {
            this->unit_count = 1;
        }

        return this->unit_count;
    }

    inline count_t
        utf_16_t::Read_Reverse_Normal(const unit_t* from, const unit_t* first)
    {
        assert(from);
        assert(first);
        assert(from > first);

        unit_t unit_a = *(from - 1);
        if (utf_32_t::Is_Surrogate_Low(unit_a)) {
            if (from - 2 >= first) {
                unit_t unit_b = *(from - 2);
                if (utf_32_t::Is_Surrogate_High(unit_b)) {
                    this->units[0] = unit_b;
                    this->units[1] = unit_a;
                    this->unit_count = 2;
                } else {
                    this->units[0] = utf_32_t::REPLACEMENT_CHARACTER;
                    this->unit_count = 1;
                }
            } else {
                this->units[0] = utf_32_t::REPLACEMENT_CHARACTER;
                this->unit_count = 1;
            }
        } else if (utf_32_t::Is_Surrogate_High(unit_a)) {
            this->units[0] = utf_32_t::REPLACEMENT_CHARACTER;
            this->unit_count = 1;
        } else {
            this->units[0] = unit_a;
            this->unit_count = 1;
        }

        return this->unit_count;
    }

    inline count_t
        utf_16_t::Read_Reverse_Swapped(const unit_t* from, const unit_t* first)
    {
        assert(from);
        assert(first);
        assert(from > first);

        unit_t unit_a = *(from - 1);
        if (utf_32_t::Is_Surrogate_Low(os::endian::Swap(unit_a))) {
            if (from - 2 >= first) {
                unit_t unit_b = *(from - 2);
                if (utf_32_t::Is_Surrogate_High(os::endian::Swap(unit_b))) {
                    this->units[0] = unit_b;
                    this->units[1] = unit_a;
                    this->unit_count = 2;
                } else {
                    this->units[0] = utf_32_t::REPLACEMENT_CHARACTER_16_SWAPPED;
                    this->unit_count = 1;
                }
            } else {
                this->units[0] = utf_32_t::REPLACEMENT_CHARACTER_16_SWAPPED;
                this->unit_count = 1;
            }
        } else if (utf_32_t::Is_Surrogate_High(os::endian::Swap(unit_a))) {
            this->units[0] = utf_32_t::REPLACEMENT_CHARACTER_16_SWAPPED;
            this->unit_count = 1;
        } else {
            this->units[0] = unit_a;
            this->unit_count = 1;
        }

        return this->unit_count;
    }

    inline count_t
        utf_16_t::Unit_Count()
        const
    {
        return this->unit_count;
    }

    inline typename utf_16_t::unit_t
        utf_16_t::operator [](index_t index)
        const
    {
        assert(index < this->unit_count);

        return this->units[index];
    }

    template <typename>
    inline bool_t
        utf_16_be_t::Is_Well_Formed()
        const
    {
        if constexpr (os::endian::Is_Big()) {
            return Is_Well_Formed_Normal();
        } else if constexpr (os::endian::Is_Little()) {
            return Is_Well_Formed_Swapped();
        } else {
            static_assert(false);
        }
    }

    template <typename>
    inline void_t
        utf_16_be_t::Encode(point_t point)
    {
        if constexpr (os::endian::Is_Big()) {
            return Encode_Normal(point);
        } else if constexpr (os::endian::Is_Little()) {
            return Encode_Swapped(point);
        } else {
            static_assert(false);
        }
    }

    template <typename>
    inline point_t
        utf_16_be_t::Decode()
        const
    {
        if constexpr (os::endian::Is_Big()) {
            return Decode_Normal();
        } else if constexpr (os::endian::Is_Little()) {
            return Decode_Swapped();
        } else {
            static_assert(false);
        }
    }

    template <typename>
    inline count_t
        utf_16_be_t::Read_Forward(const unit_t* from)
    {
        if constexpr (os::endian::Is_Big()) {
            return Read_Forward_Normal(from);
        } else if constexpr (os::endian::Is_Little()) {
            return Read_Forward_Swapped(from);
        } else {
            static_assert(false);
        }
    }

    template <typename>
    inline count_t
        utf_16_be_t::Read_Reverse(const unit_t* from, const unit_t* first)
    {
        if constexpr (os::endian::Is_Big()) {
            return Read_Reverse_Normal(from, first);
        } else if constexpr (os::endian::Is_Little()) {
            return Read_Reverse_Swapped(from, first);
        } else {
            static_assert(false);
        }
    }

    template <typename>
    inline bool_t
        utf_16_le_t::Is_Well_Formed()
        const
    {
        if constexpr (os::endian::Is_Big()) {
            return Is_Well_Formed_Swapped();
        } else if constexpr (os::endian::Is_Little()) {
            return Is_Well_Formed_Normal();
        } else {
            static_assert(false);
        }
    }

    template <typename>
    inline void_t
        utf_16_le_t::Encode(point_t point)
    {
        if constexpr (os::endian::Is_Big()) {
            return Encode_Swapped(point);
        } else if constexpr (os::endian::Is_Little()) {
            return Encode_Normal(point);
        } else {
            static_assert(false);
        }
    }

    template <typename>
    inline point_t
        utf_16_le_t::Decode()
        const
    {
        if constexpr (os::endian::Is_Big()) {
            return Decode_Swapped();
        } else if constexpr (os::endian::Is_Little()) {
            return Decode_Normal();
        } else {
            static_assert(false);
        }
    }

    template <typename>
    inline count_t
        utf_16_le_t::Read_Forward(const unit_t* from)
    {
        if constexpr (os::endian::Is_Big()) {
            return Read_Forward_Swapped(from);
        } else if constexpr (os::endian::Is_Little()) {
            return Read_Forward_Normal(from);
        } else {
            static_assert(false);
        }
    }

    template <typename>
    inline count_t
        utf_16_le_t::Read_Reverse(const unit_t* from, const unit_t* first)
    {
        if constexpr (os::endian::Is_Big()) {
            return Read_Reverse_Swapped(from, first);
        } else if constexpr (os::endian::Is_Little()) {
            return Read_Reverse_Normal(from, first);
        } else {
            static_assert(false);
        }
    }

}}
