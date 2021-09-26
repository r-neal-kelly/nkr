/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/charcoder_utf_32_t.h"
#include "nkr/os.h"

namespace nkr { namespace charcoder {

    inline bool_t utf_32_t::Is_Point(point_t point)
    {
        return point <= POINT_LAST;
    }

    inline bool_t utf_32_t::Is_Scalar(point_t point)
    {
        return point <= POINT_LAST && (point < SURROGATE_HIGH_FIRST || point > SURROGATE_LOW_LAST);
    }

    inline bool_t utf_32_t::Is_Surrogate(point_t point)
    {
        return point >= SURROGATE_HIGH_FIRST && point <= SURROGATE_LOW_LAST;
    }

    inline bool_t utf_32_t::Is_Surrogate_High(point_t point)
    {
        return point >= SURROGATE_HIGH_FIRST && point <= SURROGATE_HIGH_LAST;
    }

    inline bool_t utf_32_t::Is_Surrogate_Low(point_t point)
    {
        return point >= SURROGATE_LOW_FIRST && point <= SURROGATE_LOW_LAST;
    }

    inline utf_32_t::utf_32_t()
    {
        this->unit = 0;
    }

    inline utf_32_t::utf_32_t(const utf_32_t& other)
    {
        this->unit = other.unit;
    }

    inline utf_32_t::utf_32_t(const volatile utf_32_t& other)
    {
        this->unit = other.unit;
    }

    inline utf_32_t::utf_32_t(utf_32_t&& other) noexcept
    {
        this->unit = std::exchange(other.unit, 0);
    }

    inline utf_32_t::utf_32_t(volatile utf_32_t&& other) noexcept
    {
        this->unit = std::exchange(other.unit, 0);
    }

    inline utf_32_t& utf_32_t::operator =(const utf_32_t& other)
    {
        if (this != std::addressof(other)) {
            this->unit = other.unit;
        }
        return *this;
    }

    inline volatile utf_32_t& utf_32_t::operator =(const utf_32_t& other) volatile
    {
        if (this != std::addressof(other)) {
            this->unit = other.unit;
        }
        return *this;
    }

    inline utf_32_t& utf_32_t::operator =(const volatile utf_32_t& other)
    {
        if (this != std::addressof(other)) {
            this->unit = other.unit;
        }
        return *this;
    }

    inline volatile utf_32_t& utf_32_t::operator =(const volatile utf_32_t& other) volatile
    {
        if (this != std::addressof(other)) {
            this->unit = other.unit;
        }
        return *this;
    }

    inline utf_32_t& utf_32_t::operator =(utf_32_t&& other) noexcept
    {
        if (this != std::addressof(other)) {
            this->unit = std::exchange(other.unit, 0);
        }
        return *this;
    }

    inline volatile utf_32_t& utf_32_t::operator =(utf_32_t&& other) volatile noexcept
    {
        if (this != std::addressof(other)) {
            this->unit = std::exchange(other.unit, 0);
        }
        return *this;
    }

    inline utf_32_t& utf_32_t::operator =(is_just_volatile_tr<utf_32_t> auto&& other) noexcept
    {
        if (this != std::addressof(other)) {
            this->unit = std::exchange(other.unit, 0);
        }
        return *this;
    }

    inline volatile utf_32_t& utf_32_t::operator =(is_just_volatile_tr<utf_32_t> auto&& other) volatile noexcept
    {
        if (this != std::addressof(other)) {
            this->unit = std::exchange(other.unit, 0);
        }
        return *this;
    }

    inline utf_32_t::~utf_32_t()
    {
        this->unit = 0;
    }

    inline bool_t utf_32_t::Is_Well_Formed_Normal() const
    {
        return Is_Scalar(this->unit);
    }

    inline bool_t utf_32_t::Is_Well_Formed_Swapped() const
    {
        return Is_Scalar(os::endian::Swap(this->unit));
    }

    inline void_t utf_32_t::Encode_Normal(point_t point)
    {
        if (Is_Scalar(point)) {
            this->unit = static_cast<unit_t>(point);
        } else {
            this->unit = REPLACEMENT_CHARACTER;
        }

        assert(Is_Well_Formed_Normal());
    }

    inline void_t utf_32_t::Encode_Swapped(point_t point)
    {
        if (Is_Scalar(point)) {
            this->unit = os::endian::Swap(static_cast<unit_t>(point));
        } else {
            this->unit = REPLACEMENT_CHARACTER_32_SWAPPED;
        }

        assert(Is_Well_Formed_Swapped());
    }

    inline point_t utf_32_t::Decode_Normal() const
    {
        assert(Is_Well_Formed_Normal());

        return this->unit;
    }

    inline point_t utf_32_t::Decode_Swapped() const
    {
        assert(Is_Well_Formed_Swapped());

        return os::endian::Swap(this->unit);
    }

    inline count_t utf_32_t::Read_Forward_Normal(const unit_t* from)
    {
        assert(from);

        this->unit = *from;
        if (!Is_Well_Formed_Normal()) {
            this->unit = REPLACEMENT_CHARACTER;
        }

        return 1;
    }

    inline count_t utf_32_t::Read_Forward_Swapped(const unit_t* from)
    {
        assert(from);

        this->unit = *from;
        if (!Is_Well_Formed_Swapped()) {
            this->unit = REPLACEMENT_CHARACTER_32_SWAPPED;
        }

        return 1;
    }

    inline count_t utf_32_t::Read_Reverse_Normal(const unit_t* from, const unit_t* first)
    {
        assert(from);
        assert(first);
        assert(from > first);

        this->unit = *(from - 1);
        if (!Is_Well_Formed_Normal()) {
            this->unit = REPLACEMENT_CHARACTER;
        }

        return 1;
    }

    inline count_t utf_32_t::Read_Reverse_Swapped(const unit_t* from, const unit_t* first)
    {
        assert(from);
        assert(first);
        assert(from > first);

        this->unit = *(from - 1);
        if (!Is_Well_Formed_Swapped()) {
            this->unit = REPLACEMENT_CHARACTER_32_SWAPPED;
        }

        return 1;
    }

    inline count_t utf_32_t::Unit_Count() const
    {
        return 1;
    }

    inline typename utf_32_t::unit_t utf_32_t::operator [](index_t index) const
    {
        assert(index < 1);

        return this->unit;
    }

    template <typename>
    inline bool_t utf_32_be_t::Is_Well_Formed() const
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
    inline void_t utf_32_be_t::Encode(point_t point)
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
    inline point_t utf_32_be_t::Decode() const
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
    inline count_t utf_32_be_t::Read_Forward(const unit_t* from)
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
    inline count_t utf_32_be_t::Read_Reverse(const unit_t* from, const unit_t* first)
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
    inline bool_t utf_32_le_t::Is_Well_Formed() const
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
    inline void_t utf_32_le_t::Encode(point_t point)
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
    inline point_t utf_32_le_t::Decode() const
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
    inline count_t utf_32_le_t::Read_Forward(const unit_t* from)
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
    inline count_t utf_32_le_t::Read_Reverse(const unit_t* from, const unit_t* first)
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
