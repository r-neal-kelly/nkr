/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/tr_def.h"

#include "nkr/boolean/cpp_t_def.h"
#include "nkr/boolean/deleted_operators_t_def.h"

#include "nkr/interface/type_i_def.h"

#include "nkr/trait/boolean_tr_def.h"
#include "nkr/trait/boolean/any_tr_def.h"
#include "nkr/trait/boolean/pure_tr_def.h"

#include "nkr/boolean/safe_t_dec.h"

namespace nkr { namespace interface {

    template <typename other_p>
    inline constexpr boolean::cpp_t
        type_i<boolean::safe_tg>::Is_Any()
        noexcept
    {
        return boolean::safe_tr<other_p>;
    }

}}

namespace nkr { namespace boolean {

    inline constexpr boolean::cpp_t
        safe_t::Is_Boolean_Type()
        noexcept
    {
        return true;
    }

    inline constexpr auto&
        safe_t::Assign_Copy(tr1<any_non_const_tg, safe_t> auto& self, const tr1<any_tg, safe_t> auto& other)
        noexcept
    {
        if (cpp::Address(self) != cpp::Address(other)) {
            self.value = other.value;
        }

        return self;
    }

    inline constexpr auto&
        safe_t::Assign_Move(tr1<any_non_const_tg, safe_t> auto& self, tr1<any_non_const_tg, safe_t> auto&& other)
        noexcept
    {
        if (cpp::Address(self) != cpp::Address(other)) {
            self.value = cpp::Move(other.value);
        }

        return self;
    }

    inline constexpr safe_t::safe_t() noexcept :
        value(false)
    {
    }

    inline constexpr safe_t::safe_t(const tr1<any_to_tg, boolean::cpp_t> auto& value) noexcept :
        value(boolean::cpp_t(value))
    {
    }

    inline constexpr safe_t::safe_t(const safe_t& other) noexcept :
        value(other.value)
    {
    }

    inline constexpr safe_t::safe_t(const volatile safe_t& other) noexcept :
        value(other.value)
    {
    }

    inline constexpr safe_t::safe_t(safe_t&& other) noexcept :
        value(cpp::Move(other.value))
    {
    }

    inline constexpr safe_t::safe_t(volatile safe_t&& other) noexcept :
        value(cpp::Move(other.value))
    {
    }

    inline constexpr safe_t&
        safe_t::operator =(const safe_t& other)
        noexcept
    {
        return Assign_Copy(*this, other);
    }

    inline constexpr volatile safe_t&
        safe_t::operator =(const safe_t& other)
        volatile noexcept
    {
        return Assign_Copy(*this, other);
    }

    inline constexpr safe_t&
        safe_t::operator =(const volatile safe_t& other)
        noexcept
    {
        return Assign_Copy(*this, other);
    }

    inline constexpr volatile safe_t&
        safe_t::operator =(const volatile safe_t& other)
        volatile noexcept
    {
        return Assign_Copy(*this, other);
    }

    inline constexpr safe_t&
        safe_t::operator =(safe_t&& other)
        noexcept
    {
        return Assign_Move(*this, cpp::Move(other));
    }

    inline constexpr volatile safe_t&
        safe_t::operator =(safe_t&& other)
        volatile noexcept
    {
        return Assign_Move(*this, cpp::Move(other));
    }

    inline constexpr safe_t&
        safe_t::operator =(tr1<just_volatile_tg, safe_t> auto&& other)
        noexcept
    {
        return Assign_Move(*this, cpp::Move(other));
    }

    inline constexpr volatile safe_t&
        safe_t::operator =(tr1<just_volatile_tg, safe_t> auto&& other)
        volatile noexcept
    {
        return Assign_Move(*this, cpp::Move(other));
    }

#if defined(nkr_IS_DEBUG)
    inline constexpr safe_t::~safe_t() noexcept
    {
        this->value = false;
    }
#endif

    inline constexpr safe_t::operator boolean::cpp_t()
        const noexcept
    {
        return this->value;
    }

    inline constexpr safe_t::operator boolean::cpp_t()
        const volatile noexcept
    {
        return this->value;
    }

}}

namespace nkr {

    inline constexpr boolean::cpp_t
        operator ==(const tr1<any_tg, boolean::safe_t> auto& a, const tr0<any_tg> auto& b)
        noexcept
    {
        using a_t = cpp::reference_value_t<decltype(a)>;
        using b_t = cpp::reference_value_t<decltype(b)>;

        if constexpr (cpp::can_be_equal_to_tr<boolean::cpp_t, b_t>) {
            return boolean::cpp_t(a) == b;
        } else if constexpr (cpp::to_tr<b_t, boolean::cpp_t>) {
            return boolean::cpp_t(a) == boolean::cpp_t(b);
        } else {
            static_assert(false, "these two values can not be equal to each other.");
        }
    }

    inline constexpr boolean::cpp_t
        operator ==(const tr1<any_tg, boolean::safe_t> auto& a, const tr0<any_tg> auto&& b)
        noexcept
    {
        return operator ==(a, b);
    }

    inline constexpr boolean::cpp_t
        operator ==(const tr1<any_tg, boolean::safe_t> auto&& a, const tr0<any_tg> auto& b)
        noexcept
    {
        return operator ==(a, b);
    }

    inline constexpr boolean::cpp_t
        operator ==(const tr1<any_tg, boolean::safe_t> auto&& a, const tr0<any_tg> auto&& b)
        noexcept
    {
        return operator ==(a, b);
    }

    inline constexpr boolean::cpp_t
        operator !=(const tr1<any_tg, boolean::safe_t> auto& a, const tr0<any_tg> auto& b)
        noexcept
    {
        return !operator ==(a, b);
    }

    inline constexpr boolean::cpp_t
        operator !=(const tr1<any_tg, boolean::safe_t> auto& a, const tr0<any_tg> auto&& b)
        noexcept
    {
        return !operator ==(a, b);
    }

    inline constexpr boolean::cpp_t
        operator !=(const tr1<any_tg, boolean::safe_t> auto&& a, const tr0<any_tg> auto& b)
        noexcept
    {
        return !operator ==(a, b);
    }

    inline constexpr boolean::cpp_t
        operator !=(const tr1<any_tg, boolean::safe_t> auto&& a, const tr0<any_tg> auto&& b)
        noexcept
    {
        return !operator ==(a, b);
    }

}

namespace nkr { namespace boolean {

    static_assert(sizeof(safe_t) == sizeof(cpp_t));

    static_assert(trait::boolean_tr<safe_t>);
    static_assert(trait::boolean_tr<const safe_t>);
    static_assert(trait::boolean_tr<volatile safe_t>);
    static_assert(trait::boolean_tr<const volatile safe_t>);

    static_assert(trait::boolean::any_tr<safe_t>);
    static_assert(trait::boolean::any_tr<const safe_t>);
    static_assert(trait::boolean::any_tr<volatile safe_t>);
    static_assert(trait::boolean::any_tr<const volatile safe_t>);

    static_assert(trait::boolean::pure_tr<safe_t>);
    static_assert(trait::boolean::pure_tr<const safe_t>);
    static_assert(trait::boolean::pure_tr<volatile safe_t>);
    static_assert(trait::boolean::pure_tr<const volatile safe_t>);

}}
