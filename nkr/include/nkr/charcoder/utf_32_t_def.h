/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/macros_def.h"
#include "nkr/os.h"
#include "nkr/utils.h"

#include "nkr/charcoder/utf_32_t_dec.h"

namespace nkr { namespace charcoder {

    inline constexpr point_t
        utf_32_t::Last_Point()
    {
        return utf_32_t::POINT_LAST;
    }

    inline constexpr point_t
        utf_32_t::Replacement_Point()
    {
        return utf_32_t::REPLACEMENT_CHARACTER;
    }

    inline constexpr count_t
        utf_32_t::Max_Unit_Count()
    {
        return 1;
    }

    inline constexpr std_bool_t
        utf_32_t::Is_Point(point_t point)
    {
        return point <= POINT_LAST;
    }

    inline constexpr std_bool_t
        utf_32_t::Is_Scalar(point_t point)
    {
        return point <= POINT_LAST && (point < SURROGATE_HIGH_FIRST || point > SURROGATE_LOW_LAST);
    }

    inline constexpr std_bool_t
        utf_32_t::Is_Surrogate(point_t point)
    {
        return point >= SURROGATE_HIGH_FIRST && point <= SURROGATE_LOW_LAST;
    }

    inline constexpr std_bool_t
        utf_32_t::Is_Surrogate_High(point_t point)
    {
        return point >= SURROGATE_HIGH_FIRST && point <= SURROGATE_HIGH_LAST;
    }

    inline constexpr std_bool_t
        utf_32_t::Is_Surrogate_Low(point_t point)
    {
        return point >= SURROGATE_LOW_FIRST && point <= SURROGATE_LOW_LAST;
    }

    inline constexpr std_bool_t
        utf_32_t::Is_UTF_8_Bracket_1_Point(point_t point)
    {
        return point >= UTF_8_BRACKET_1_FIRST && point <= UTF_8_BRACKET_1_LAST;
    }

    inline constexpr std_bool_t
        utf_32_t::Is_UTF_8_Bracket_2_Point(point_t point)
    {
        return point >= UTF_8_BRACKET_2_FIRST && point <= UTF_8_BRACKET_2_LAST;
    }

    inline constexpr std_bool_t
        utf_32_t::Is_UTF_8_Bracket_3_Point(point_t point)
    {
        return point >= UTF_8_BRACKET_3_FIRST && point <= UTF_8_BRACKET_3_LAST;
    }

    inline constexpr std_bool_t
        utf_32_t::Is_UTF_8_Bracket_4_Point(point_t point)
    {
        return point >= UTF_8_BRACKET_4_FIRST && point <= UTF_8_BRACKET_4_LAST;
    }

    inline constexpr std_bool_t
        utf_32_t::Is_UTF_8_Lead_Byte(byte_t byte)
    {
        return (byte >> 6) != 2;
    }

    inline constexpr std_bool_t
        utf_32_t::Is_UTF_8_Trailing_Byte(byte_t byte)
    {
        return (byte >> 6) == 2;
    }

    inline auto&
        utf_32_t::Assign_Copy(is_any_non_const_tr<utf_32_t> auto& self, const is_any_tr<utf_32_t> auto& other)
    {
        if (&self != std::addressof(other)) {
            self.unit = other.unit;
        }
        return self;
    }

    inline auto&
        utf_32_t::Assign_Move(is_any_non_const_tr<utf_32_t> auto& self, is_any_non_const_tr<utf_32_t> auto& other)
    {
        if (&self != std::addressof(other)) {
            self.unit = nkr::Move(other.unit);
        }
        return self;
    }

    inline bool_t
        utf_32_t::Is_Well_Formed_Normal(const is_any_tr<utf_32_t> auto& self)
    {
        return Is_Scalar(self.unit);
    }

    inline bool_t
        utf_32_t::Is_Well_Formed_Swapped(const is_any_tr<utf_32_t> auto& self)
    {
        return Is_Scalar(os::endian::Swap(self.unit));
    }

    inline void_t
        utf_32_t::Encode_Normal(is_any_non_const_tr<utf_32_t> auto& self, point_t point)
    {
        if (Is_Scalar(point)) {
            self.unit = unit_t(point);
        } else {
            self.unit = REPLACEMENT_CHARACTER;
        }

        nkr_ASSERT_THAT(Is_Well_Formed_Normal(self));
    }

    inline void_t
        utf_32_t::Encode_Swapped(is_any_non_const_tr<utf_32_t> auto& self, point_t point)
    {
        if (Is_Scalar(point)) {
            self.unit = os::endian::Swap(unit_t(point));
        } else {
            self.unit = REPLACEMENT_CHARACTER_32_SWAPPED;
        }

        nkr_ASSERT_THAT(Is_Well_Formed_Swapped(self));
    }

    inline point_t
        utf_32_t::Decode_Normal(const is_any_tr<utf_32_t> auto& self)
    {
        nkr_ASSERT_THAT(Is_Well_Formed_Normal(self));

        return self.unit;
    }

    inline point_t
        utf_32_t::Decode_Swapped(const is_any_tr<utf_32_t> auto& self)
    {
        nkr_ASSERT_THAT(Is_Well_Formed_Swapped(self));

        return os::endian::Swap(self.unit);
    }

    inline count_t
        utf_32_t::Read_Forward_Normal(is_any_non_const_tr<utf_32_t> auto& self, const unit_t* from)
    {
        nkr_ASSERT_THAT(from);

        self.unit = *from;
        if (!Is_Well_Formed_Normal(self)) {
            self.unit = REPLACEMENT_CHARACTER;
        }

        return 1;
    }

    inline count_t
        utf_32_t::Read_Forward_Swapped(is_any_non_const_tr<utf_32_t> auto& self, const unit_t* from)
    {
        nkr_ASSERT_THAT(from);

        self.unit = *from;
        if (!Is_Well_Formed_Swapped(self)) {
            self.unit = REPLACEMENT_CHARACTER_32_SWAPPED;
        }

        return 1;
    }

    inline count_t
        utf_32_t::Read_Reverse_Normal(is_any_non_const_tr<utf_32_t> auto& self, const unit_t* from, const unit_t* first)
    {
        nkr_ASSERT_THAT(from);
        nkr_ASSERT_THAT(first);
        nkr_ASSERT_THAT(from > first);

        self.unit = *(from - 1);
        if (!Is_Well_Formed_Normal(self)) {
            self.unit = REPLACEMENT_CHARACTER;
        }

        return 1;
    }

    inline count_t
        utf_32_t::Read_Reverse_Swapped(is_any_non_const_tr<utf_32_t> auto& self, const unit_t* from, const unit_t* first)
    {
        nkr_ASSERT_THAT(from);
        nkr_ASSERT_THAT(first);
        nkr_ASSERT_THAT(from > first);

        self.unit = *(from - 1);
        if (!Is_Well_Formed_Swapped(self)) {
            self.unit = REPLACEMENT_CHARACTER_32_SWAPPED;
        }

        return 1;
    }

    inline count_t
        utf_32_t::Unit_Count(const is_any_tr<utf_32_t> auto& self)
    {
        return 1;
    }

    inline typename utf_32_t::unit_t
        utf_32_t::Operator_Access(const is_any_tr<utf_32_t> auto& self, index_t index)
    {
        nkr_ASSERT_THAT(index < 1);

        return self.unit;
    }

    inline auto&
        utf_32_t::Assign_None(is_any_non_const_tr<utf_32_t> auto& self)
    {
        self.unit = 0;

        return self;
    }

    inline bool_t
        utf_32_t::Is_Equal_To_None(const is_any_tr<utf_32_t> auto& self)
    {
        return self.unit == 0;
    }

    inline utf_32_t::utf_32_t() :
        unit(0)
    {
    }

    inline utf_32_t::utf_32_t(const utf_32_t& other) :
        unit(other.unit)
    {
    }

    inline utf_32_t::utf_32_t(const volatile utf_32_t& other) :
        unit(other.unit)
    {
    }

    inline utf_32_t::utf_32_t(utf_32_t&& other) noexcept :
        unit(nkr::Move(other.unit))
    {
    }

    inline utf_32_t::utf_32_t(volatile utf_32_t&& other) noexcept :
        unit(nkr::Move(other.unit))
    {
    }

    inline utf_32_t&
        utf_32_t::operator =(const utf_32_t& other)
    {
        return Assign_Copy(*this, other);
    }

    inline volatile utf_32_t&
        utf_32_t::operator =(const utf_32_t& other)
        volatile
    {
        return Assign_Copy(*this, other);
    }

    inline utf_32_t&
        utf_32_t::operator =(const volatile utf_32_t& other)
    {
        return Assign_Copy(*this, other);
    }

    inline volatile utf_32_t&
        utf_32_t::operator =(const volatile utf_32_t& other)
        volatile
    {
        return Assign_Copy(*this, other);
    }

    inline utf_32_t&
        utf_32_t::operator =(utf_32_t&& other)
        noexcept
    {
        return Assign_Move(*this, other);
    }

    inline volatile utf_32_t&
        utf_32_t::operator =(utf_32_t&& other)
        volatile noexcept
    {
        return Assign_Move(*this, other);
    }

    inline utf_32_t&
        utf_32_t::operator =(is_just_volatile_tr<utf_32_t> auto&& other)
        noexcept
    {
        return Assign_Move(*this, other);
    }

    inline volatile utf_32_t&
        utf_32_t::operator =(is_just_volatile_tr<utf_32_t> auto&& other)
        volatile noexcept
    {
        return Assign_Move(*this, other);
    }

    inline utf_32_t::~utf_32_t()
    {
        this->unit = 0;
    }

    inline bool_t
        utf_32_t::Is_Well_Formed_Normal()
        const
    {
        return Is_Well_Formed_Normal(*this);
    }

    inline bool_t
        utf_32_t::Is_Well_Formed_Normal()
        const volatile
    {
        return Is_Well_Formed_Normal(*this);
    }

    inline bool_t
        utf_32_t::Is_Well_Formed_Swapped()
        const
    {
        return Is_Well_Formed_Swapped(*this);
    }

    inline bool_t
        utf_32_t::Is_Well_Formed_Swapped()
        const volatile
    {
        return Is_Well_Formed_Swapped(*this);
    }

    inline void_t
        utf_32_t::Encode_Normal(point_t point)
    {
        return Encode_Normal(*this, point);
    }

    inline void_t
        utf_32_t::Encode_Normal(point_t point)
        volatile
    {
        return Encode_Normal(*this, point);
    }

    inline void_t
        utf_32_t::Encode_Swapped(point_t point)
    {
        return Encode_Swapped(*this, point);
    }

    inline void_t
        utf_32_t::Encode_Swapped(point_t point)
        volatile
    {
        return Encode_Swapped(*this, point);
    }

    inline point_t
        utf_32_t::Decode_Normal()
        const
    {
        return Decode_Normal(*this);
    }

    inline point_t
        utf_32_t::Decode_Normal()
        const volatile
    {
        return Decode_Normal(*this);
    }

    inline point_t
        utf_32_t::Decode_Swapped()
        const
    {
        return Decode_Swapped(*this);
    }

    inline point_t
        utf_32_t::Decode_Swapped()
        const volatile
    {
        return Decode_Swapped(*this);
    }

    inline count_t
        utf_32_t::Read_Forward_Normal(const unit_t* from)
    {
        return Read_Forward_Normal(*this, from);
    }

    inline count_t
        utf_32_t::Read_Forward_Normal(const unit_t* from)
        volatile
    {
        return Read_Forward_Normal(*this, from);
    }

    inline count_t
        utf_32_t::Read_Forward_Swapped(const unit_t* from)
    {
        return Read_Forward_Swapped(*this, from);
    }

    inline count_t
        utf_32_t::Read_Forward_Swapped(const unit_t* from)
        volatile
    {
        return Read_Forward_Swapped(*this, from);
    }

    inline count_t
        utf_32_t::Read_Reverse_Normal(const unit_t* from, const unit_t* first)
    {
        return Read_Reverse_Normal(*this, from, first);
    }

    inline count_t
        utf_32_t::Read_Reverse_Normal(const unit_t* from, const unit_t* first)
        volatile
    {
        return Read_Reverse_Normal(*this, from, first);
    }

    inline count_t
        utf_32_t::Read_Reverse_Swapped(const unit_t* from, const unit_t* first)
    {
        return Read_Reverse_Swapped(*this, from, first);
    }

    inline count_t
        utf_32_t::Read_Reverse_Swapped(const unit_t* from, const unit_t* first)
        volatile
    {
        return Read_Reverse_Swapped(*this, from, first);
    }

    inline count_t
        utf_32_t::Unit_Count()
        const
    {
        return Unit_Count(*this);
    }

    inline count_t
        utf_32_t::Unit_Count()
        const volatile
    {
        return Unit_Count(*this);
    }

    inline typename utf_32_t::unit_t
        utf_32_t::operator [](index_t index)
        const
    {
        return Operator_Access(*this, index);
    }

    inline typename utf_32_t::unit_t
        utf_32_t::operator [](index_t index)
        const volatile
    {
        return Operator_Access(*this, index);
    }

    inline utf_32_t::utf_32_t(none_t) :
        utf_32_t()
    {
    }

    inline utf_32_t&
        utf_32_t::operator =(none_t)
    {
        return Assign_None(*this);
    }

    inline volatile utf_32_t&
        utf_32_t::operator =(none_t)
        volatile
    {
        return Assign_None(*this);
    }

    inline bool_t
        utf_32_t::operator ==(none_t)
        const
    {
        return Is_Equal_To_None(*this);
    }

    inline bool_t
        utf_32_t::operator ==(none_t)
        const volatile
    {
        return Is_Equal_To_None(*this);
    }

    inline bool_t
        utf_32_t::operator !=(none_t)
        const
    {
        return !Is_Equal_To_None(*this);
    }

    inline bool_t
        utf_32_t::operator !=(none_t)
        const volatile
    {
        return !Is_Equal_To_None(*this);
    }

    inline bool_t
        utf_32_be_t::Is_Well_Formed(const is_any_tr<utf_32_be_t> auto& self)
    {
        if constexpr (os::endian::Is_Big()) {
            return self.Is_Well_Formed_Normal();
        } else if constexpr (os::endian::Is_Little()) {
            return self.Is_Well_Formed_Swapped();
        } else {
            static_assert(false);
        }
    }

    inline void_t
        utf_32_be_t::Encode(is_any_non_const_tr<utf_32_be_t> auto& self, point_t point)
    {
        if constexpr (os::endian::Is_Big()) {
            return self.Encode_Normal(point);
        } else if constexpr (os::endian::Is_Little()) {
            return self.Encode_Swapped(point);
        } else {
            static_assert(false);
        }
    }

    inline point_t
        utf_32_be_t::Decode(const is_any_tr<utf_32_be_t> auto& self)
    {
        if constexpr (os::endian::Is_Big()) {
            return self.Decode_Normal();
        } else if constexpr (os::endian::Is_Little()) {
            return self.Decode_Swapped();
        } else {
            static_assert(false);
        }
    }

    inline count_t
        utf_32_be_t::Read_Forward(is_any_non_const_tr<utf_32_be_t> auto& self, const unit_t* from)
    {
        if constexpr (os::endian::Is_Big()) {
            return self.Read_Forward_Normal(from);
        } else if constexpr (os::endian::Is_Little()) {
            return self.Read_Forward_Swapped(from);
        } else {
            static_assert(false);
        }
    }

    inline count_t
        utf_32_be_t::Read_Reverse(is_any_non_const_tr<utf_32_be_t> auto& self, const unit_t* from, const unit_t* first)
    {
        if constexpr (os::endian::Is_Big()) {
            return self.Read_Reverse_Normal(from, first);
        } else if constexpr (os::endian::Is_Little()) {
            return self.Read_Reverse_Swapped(from, first);
        } else {
            static_assert(false);
        }
    }

    inline utf_32_be_t::utf_32_be_t(point_t point) :
        utf_32_be_t()
    {
        Encode(*this, point);
    }

    inline bool_t
        utf_32_be_t::Is_Well_Formed()
        const
    {
        return Is_Well_Formed(*this);
    }

    inline bool_t
        utf_32_be_t::Is_Well_Formed()
        const volatile
    {
        return Is_Well_Formed(*this);
    }

    inline void_t
        utf_32_be_t::Encode(point_t point)
    {
        return Encode(*this, point);
    }

    inline void_t
        utf_32_be_t::Encode(point_t point)
        volatile
    {
        return Encode(*this, point);
    }

    inline point_t
        utf_32_be_t::Decode()
        const
    {
        return Decode(*this);
    }

    inline point_t
        utf_32_be_t::Decode()
        const volatile
    {
        return Decode(*this);
    }

    inline count_t
        utf_32_be_t::Read_Forward(const unit_t* from)
    {
        return Read_Forward(*this, from);
    }

    inline count_t
        utf_32_be_t::Read_Forward(const unit_t* from)
        volatile
    {
        return Read_Forward(*this, from);
    }

    inline count_t
        utf_32_be_t::Read_Reverse(const unit_t* from, const unit_t* first)
    {
        return Read_Reverse(*this, from, first);
    }

    inline count_t
        utf_32_be_t::Read_Reverse(const unit_t* from, const unit_t* first)
        volatile
    {
        return Read_Reverse(*this, from, first);
    }

    inline bool_t
        utf_32_le_t::Is_Well_Formed(const is_any_tr<utf_32_le_t> auto& self)
    {
        if constexpr (os::endian::Is_Big()) {
            return self.Is_Well_Formed_Swapped();
        } else if constexpr (os::endian::Is_Little()) {
            return self.Is_Well_Formed_Normal();
        } else {
            static_assert(false);
        }
    }

    inline void_t
        utf_32_le_t::Encode(is_any_non_const_tr<utf_32_le_t> auto& self, point_t point)
    {
        if constexpr (os::endian::Is_Big()) {
            return self.Encode_Swapped(point);
        } else if constexpr (os::endian::Is_Little()) {
            return self.Encode_Normal(point);
        } else {
            static_assert(false);
        }
    }

    inline point_t
        utf_32_le_t::Decode(const is_any_tr<utf_32_le_t> auto& self)
    {
        if constexpr (os::endian::Is_Big()) {
            return self.Decode_Swapped();
        } else if constexpr (os::endian::Is_Little()) {
            return self.Decode_Normal();
        } else {
            static_assert(false);
        }
    }

    inline count_t
        utf_32_le_t::Read_Forward(is_any_non_const_tr<utf_32_le_t> auto& self, const unit_t* from)
    {
        if constexpr (os::endian::Is_Big()) {
            return self.Read_Forward_Swapped(from);
        } else if constexpr (os::endian::Is_Little()) {
            return self.Read_Forward_Normal(from);
        } else {
            static_assert(false);
        }
    }

    inline count_t
        utf_32_le_t::Read_Reverse(is_any_non_const_tr<utf_32_le_t> auto& self, const unit_t* from, const unit_t* first)
    {
        if constexpr (os::endian::Is_Big()) {
            return self.Read_Reverse_Swapped(from, first);
        } else if constexpr (os::endian::Is_Little()) {
            return self.Read_Reverse_Normal(from, first);
        } else {
            static_assert(false);
        }
    }

    inline utf_32_le_t::utf_32_le_t(point_t point) :
        utf_32_le_t()
    {
        Encode(*this, point);
    }

    inline bool_t
        utf_32_le_t::Is_Well_Formed()
        const
    {
        return Is_Well_Formed(*this);
    }

    inline bool_t
        utf_32_le_t::Is_Well_Formed()
        const volatile
    {
        return Is_Well_Formed(*this);
    }

    inline void_t
        utf_32_le_t::Encode(point_t point)
    {
        return Encode(*this, point);
    }

    inline void_t
        utf_32_le_t::Encode(point_t point)
        volatile
    {
        return Encode(*this, point);
    }

    inline point_t
        utf_32_le_t::Decode()
        const
    {
        return Decode(*this);
    }

    inline point_t
        utf_32_le_t::Decode()
        const volatile
    {
        return Decode(*this);
    }

    inline count_t
        utf_32_le_t::Read_Forward(const unit_t* from)
    {
        return Read_Forward(*this, from);
    }

    inline count_t
        utf_32_le_t::Read_Forward(const unit_t* from)
        volatile
    {
        return Read_Forward(*this, from);
    }

    inline count_t
        utf_32_le_t::Read_Reverse(const unit_t* from, const unit_t* first)
    {
        return Read_Reverse(*this, from, first);
    }

    inline count_t
        utf_32_le_t::Read_Reverse(const unit_t* from, const unit_t* first)
        volatile
    {
        return Read_Reverse(*this, from, first);
    }

}}
