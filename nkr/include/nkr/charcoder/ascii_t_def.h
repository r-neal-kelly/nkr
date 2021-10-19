/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/macros_def.h"
#include "nkr/utils.h"

#include "nkr/charcoder/ascii_t_dec.h"

namespace nkr { namespace charcoder {

    inline constexpr point_t
        ascii_t::Last_Point()
    {
        return 127;
    }

    inline constexpr point_t
        ascii_t::Replacement_Point()
    {
        return '?';
    }

    inline constexpr count_t
        ascii_t::Max_Unit_Count()
    {
        return 1;
    }

    inline auto&
        ascii_t::Assign_Copy(is_any_non_const_tr<ascii_t> auto& self, const is_any_tr<ascii_t> auto& other)
    {
        if (&self != std::addressof(other)) {
            self.unit = other.unit;
        }
        return self;
    }

    inline auto&
        ascii_t::Assign_Move(is_any_non_const_tr<ascii_t> auto& self, is_any_non_const_tr<ascii_t> auto& other)
    {
        if (&self != std::addressof(other)) {
            self.unit = nkr::Move(other.unit);
        }
        return self;
    }

    inline bool_t
        ascii_t::Is_Well_Formed(const is_any_tr<ascii_t> auto& self)
    {
        return self.unit > -1;
    }

    inline void_t
        ascii_t::Encode(is_any_non_const_tr<ascii_t> auto& self, point_t point)
    {
        if (point >= 0 && point <= Last_Point()) {
            self.unit = unit_t(point);
        } else {
            self.unit = '?';
        }

        nkr_ASSERT_THAT(Is_Well_Formed(self));
    }

    inline point_t
        ascii_t::Decode(const is_any_tr<ascii_t> auto& self)
    {
        nkr_ASSERT_THAT(Is_Well_Formed(self));

        return static_cast<point_t>(self.unit);
    }

    inline count_t
        ascii_t::Read_Forward(is_any_non_const_tr<ascii_t> auto& self, const is_any_tr<unit_t> auto* from)
    {
        nkr_ASSERT_THAT(from);

        Encode(self, *from);

        return 1;
    }

    inline count_t
        ascii_t::Read_Reverse(is_any_non_const_tr<ascii_t> auto& self, const is_any_tr<unit_t> auto* from, const is_any_tr<unit_t> auto* first)
    {
        nkr_ASSERT_THAT(from);
        nkr_ASSERT_THAT(first);
        nkr_ASSERT_THAT(from > first);

        Encode(self, *(from - 1));

        return 1;
    }

    inline count_t
        ascii_t::Unit_Count(const is_any_tr<ascii_t> auto& self)
    {
        return 1;
    }

    inline typename ascii_t::unit_t
        ascii_t::Operator_Access(const is_any_tr<ascii_t> auto& self, index_t index)
    {
        nkr_ASSERT_THAT(index < 1);

        return self.unit;
    }

    inline auto&
        ascii_t::Assign_None(is_any_non_const_tr<ascii_t> auto& self)
    {
        self.unit = 0;

        return self;
    }

    inline bool_t
        ascii_t::Is_Equal_To_None(const is_any_tr<ascii_t> auto& self)
    {
        return self.unit == 0;
    }

    inline ascii_t::ascii_t() :
        unit(0)
    {
    }

    inline ascii_t::ascii_t(point_t point) :
        ascii_t()
    {
        Encode(*this, point);
    }

    inline ascii_t::ascii_t(const ascii_t& other) :
        unit(other.unit)
    {
    }

    inline ascii_t::ascii_t(const volatile ascii_t& other) :
        unit(other.unit)
    {
    }

    inline ascii_t::ascii_t(ascii_t&& other) noexcept :
        unit(nkr::Move(other.unit))
    {
    }

    inline ascii_t::ascii_t(volatile ascii_t&& other) noexcept :
        unit(nkr::Move(other.unit))
    {
    }

    inline ascii_t&
        ascii_t::operator =(const ascii_t& other)
    {
        return Assign_Copy(*this, other);
    }

    inline volatile ascii_t&
        ascii_t::operator =(const ascii_t& other)
        volatile
    {
        return Assign_Copy(*this, other);
    }

    inline ascii_t&
        ascii_t::operator =(const volatile ascii_t& other)
    {
        return Assign_Copy(*this, other);
    }

    inline volatile ascii_t&
        ascii_t::operator =(const volatile ascii_t& other)
        volatile
    {
        return Assign_Copy(*this, other);
    }

    inline ascii_t&
        ascii_t::operator =(ascii_t&& other)
        noexcept
    {
        return Assign_Move(*this, other);
    }

    inline volatile ascii_t&
        ascii_t::operator =(ascii_t&& other)
        volatile noexcept
    {
        return Assign_Move(*this, other);
    }

    inline ascii_t&
        ascii_t::operator =(is_just_volatile_tr<ascii_t> auto&& other)
        noexcept
    {
        return Assign_Move(*this, other);
    }

    inline volatile ascii_t&
        ascii_t::operator =(is_just_volatile_tr<ascii_t> auto&& other)
        volatile noexcept
    {
        return Assign_Move(*this, other);
    }

    inline ascii_t::~ascii_t()
    {
        this->unit = 0;
    }

    inline bool_t
        ascii_t::Is_Well_Formed()
        const
    {
        return Is_Well_Formed(*this);
    }

    inline bool_t
        ascii_t::Is_Well_Formed()
        const volatile
    {
        return Is_Well_Formed(*this);
    }

    inline void_t
        ascii_t::Encode(point_t point)
    {
        return Encode(*this, point);
    }

    inline void_t
        ascii_t::Encode(point_t point)
        volatile
    {
        return Encode(*this, point);
    }

    inline point_t
        ascii_t::Decode()
        const
    {
        return Decode(*this);
    }

    inline point_t
        ascii_t::Decode()
        const volatile
    {
        return Decode(*this);
    }

    inline count_t
        ascii_t::Read_Forward(const is_any_tr<unit_t> auto* from)
    {
        return Read_Forward(*this, from);
    }

    inline count_t
        ascii_t::Read_Forward(const is_any_tr<unit_t> auto* from)
        volatile
    {
        return Read_Forward(*this, from);
    }

    inline count_t
        ascii_t::Read_Reverse(const is_any_tr<unit_t> auto* from, const is_any_tr<unit_t> auto* first)
    {
        return Read_Reverse(*this, from, first);
    }

    inline count_t
        ascii_t::Read_Reverse(const is_any_tr<unit_t> auto* from, const is_any_tr<unit_t> auto* first)
        volatile
    {
        return Read_Reverse(*this, from, first);
    }

    inline count_t
        ascii_t::Unit_Count()
        const
    {
        return Unit_Count(*this);
    }

    inline count_t
        ascii_t::Unit_Count()
        const volatile
    {
        return Unit_Count(*this);
    }

    inline typename ascii_t::unit_t
        ascii_t::operator [](index_t index)
        const
    {
        return Operator_Access(*this, index);
    }

    inline typename ascii_t::unit_t
        ascii_t::operator [](index_t index)
        const volatile
    {
        return Operator_Access(*this, index);
    }

    inline ascii_t::ascii_t(none_t) :
        ascii_t()
    {
    }

    inline ascii_t&
        ascii_t::operator =(none_t)
    {
        return Assign_None(*this);
    }

    inline volatile ascii_t&
        ascii_t::operator =(none_t)
        volatile
    {
        return Assign_None(*this);
    }

    inline bool_t
        ascii_t::operator ==(none_t)
        const
    {
        return Is_Equal_To_None(*this);
    }

    inline bool_t
        ascii_t::operator ==(none_t)
        const volatile
    {
        return Is_Equal_To_None(*this);
    }

    inline bool_t
        ascii_t::operator !=(none_t)
        const
    {
        return !Is_Equal_To_None(*this);
    }

    inline bool_t
        ascii_t::operator !=(none_t)
        const volatile
    {
        return !Is_Equal_To_None(*this);
    }

}}
