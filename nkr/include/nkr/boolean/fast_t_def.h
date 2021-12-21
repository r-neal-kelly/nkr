/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/cpp_def.h"
#include "nkr/intrinsics_def.h"
#include "nkr/tr_def.h"

#include "nkr/boolean/cpp_t_def.h"
#include "nkr/boolean/deleted_operators_t_def.h"

#include "nkr/interface/type_i_def.h"

#include "nkr/trait/boolean_tr_def.h"
#include "nkr/trait/boolean/any_tr_def.h"
#include "nkr/trait/boolean/pure_tr_def.h"

#include "nkr/boolean/fast_t_dec.h"

namespace nkr { namespace interface {

    template <typename other_p>
    inline constexpr cpp::bool_t
        type_i<boolean::fast_tg>::Is_Any()
        noexcept
    {
        return boolean::fast_tr<other_p>;
    }

}}

namespace nkr { namespace boolean {

    inline constexpr boolean::cpp_t
        fast_t::Is_Boolean_Type()
        noexcept
    {
        return true;
    }

    inline constexpr auto&
        fast_t::Assign_Copy(tr1<any_non_const_tg, fast_t> auto& self, const tr1<any_tg, fast_t> auto& other)
        noexcept
    {
        if (cpp::Address(self) != cpp::Address(other)) {
            self.value = other.value;
        }

        return self;
    }

    inline constexpr auto&
        fast_t::Assign_Move(tr1<any_non_const_tg, fast_t> auto& self, tr1<any_non_const_tg, fast_t> auto&& other)
        noexcept
    {
        if (cpp::Address(self) != cpp::Address(other)) {
            self.value = cpp::Move(other.value);
        }

        return self;
    }

    inline constexpr fast_t::fast_t() noexcept :
        value(value_t(false))
    {
    }

    inline constexpr fast_t::fast_t(const tr1<any_to_tg, boolean::cpp_t> auto& value) noexcept :
        value(value_t(boolean::cpp_t(value)))
    {
    }

    inline constexpr fast_t::fast_t(const fast_t& other) noexcept :
        value(other.value)
    {
    }

    inline constexpr fast_t::fast_t(const volatile fast_t& other) noexcept :
        value(other.value)
    {
    }

    inline constexpr fast_t::fast_t(fast_t&& other) noexcept :
        value(cpp::Move(other.value))
    {
    }

    inline constexpr fast_t::fast_t(volatile fast_t&& other) noexcept :
        value(cpp::Move(other.value))
    {
    }

    inline constexpr fast_t&
        fast_t::operator =(const fast_t& other)
        noexcept
    {
        return Assign_Copy(*this, other);
    }

    inline constexpr volatile fast_t&
        fast_t::operator =(const fast_t& other)
        volatile noexcept
    {
        return Assign_Copy(*this, other);
    }

    inline constexpr fast_t&
        fast_t::operator =(const volatile fast_t& other)
        noexcept
    {
        return Assign_Copy(*this, other);
    }

    inline constexpr volatile fast_t&
        fast_t::operator =(const volatile fast_t& other)
        volatile noexcept
    {
        return Assign_Copy(*this, other);
    }

    inline constexpr fast_t&
        fast_t::operator =(fast_t&& other)
        noexcept
    {
        return Assign_Move(*this, cpp::Move(other));
    }

    inline constexpr volatile fast_t&
        fast_t::operator =(fast_t&& other)
        volatile noexcept
    {
        return Assign_Move(*this, cpp::Move(other));
    }

    inline constexpr fast_t&
        fast_t::operator =(tr1<just_volatile_tg, fast_t> auto&& other)
        noexcept
    {
        return Assign_Move(*this, cpp::Move(other));
    }

    inline constexpr volatile fast_t&
        fast_t::operator =(tr1<just_volatile_tg, fast_t> auto&& other)
        volatile noexcept
    {
        return Assign_Move(*this, cpp::Move(other));
    }

#if defined(nkr_IS_DEBUG)
    inline constexpr fast_t::~fast_t() noexcept
    {
        this->value = value_t(false);
    }
#endif

    inline constexpr fast_t::operator boolean::cpp_t::value_t()
        const noexcept
    {
        return boolean::cpp_t(this->value);
    }

    inline constexpr fast_t::operator boolean::cpp_t::value_t()
        const volatile noexcept
    {
        return boolean::cpp_t(this->value);
    }

}}

namespace nkr {

    inline constexpr boolean::fast_t
        operator ==(const tr1<any_tg, boolean::fast_t> auto& a, const tr0<any_tg> auto& b)
        noexcept
    {
        using a_t = cpp::reference_value_t<decltype(a)>;
        using b_t = cpp::reference_value_t<decltype(b)>;

        if constexpr (cpp::can_be_equal_to_tr<b_t, boolean::cpp_t::value_t>) {
            return b == boolean::cpp_t::value_t(a);
        } else if constexpr (cpp::to_tr<b_t, boolean::fast_t>) {
            return boolean::cpp_t::value_t(boolean::fast_t(b)) == boolean::cpp_t::value_t(a);
        } else {
            static_assert(false, "these two values can not be equal to each other.");
        }
    }

    inline constexpr boolean::fast_t
        operator ==(const tr1<any_tg, boolean::fast_t> auto& a, const tr0<any_tg> auto&& b)
        noexcept
    {
        return operator ==(a, b);
    }

    inline constexpr boolean::fast_t
        operator ==(const tr1<any_tg, boolean::fast_t> auto&& a, const tr0<any_tg> auto& b)
        noexcept
    {
        return operator ==(a, b);
    }

    inline constexpr boolean::fast_t
        operator ==(const tr1<any_tg, boolean::fast_t> auto&& a, const tr0<any_tg> auto&& b)
        noexcept
    {
        return operator ==(a, b);
    }

    inline constexpr boolean::fast_t
        operator !=(const tr1<any_tg, boolean::fast_t> auto& a, const tr0<any_tg> auto& b)
        noexcept
    {
        return !operator ==(a, b);
    }

    inline constexpr boolean::fast_t
        operator !=(const tr1<any_tg, boolean::fast_t> auto& a, const tr0<any_tg> auto&& b)
        noexcept
    {
        return !operator ==(a, b);
    }

    inline constexpr boolean::fast_t
        operator !=(const tr1<any_tg, boolean::fast_t> auto&& a, const tr0<any_tg> auto& b)
        noexcept
    {
        return !operator ==(a, b);
    }

    inline constexpr boolean::fast_t
        operator !=(const tr1<any_tg, boolean::fast_t> auto&& a, const tr0<any_tg> auto&& b)
        noexcept
    {
        return !operator ==(a, b);
    }

}

namespace nkr { namespace boolean {

    static_assert(sizeof(fast_t) == sizeof(fast_t::value_t));

    static_assert(trait::boolean_tr<fast_t>);
    static_assert(trait::boolean_tr<const fast_t>);
    static_assert(trait::boolean_tr<volatile fast_t>);
    static_assert(trait::boolean_tr<const volatile fast_t>);

    static_assert(trait::boolean::any_tr<fast_t>);
    static_assert(trait::boolean::any_tr<const fast_t>);
    static_assert(trait::boolean::any_tr<volatile fast_t>);
    static_assert(trait::boolean::any_tr<const volatile fast_t>);

    static_assert(trait::boolean::pure_tr<fast_t>);
    static_assert(trait::boolean::pure_tr<const fast_t>);
    static_assert(trait::boolean::pure_tr<volatile fast_t>);
    static_assert(trait::boolean::pure_tr<const volatile fast_t>);

}}
