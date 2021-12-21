/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/cpp_def.h"
#include "nkr/intrinsics_def.h"
#include "nkr/tr_def.h"

#include "nkr/interface/type_i_def.h"

#include "nkr/trait/boolean_tr_def.h"
#include "nkr/trait/boolean/any_tr_def.h"
#include "nkr/trait/boolean/impure_tr_def.h"

#include "nkr/boolean/cpp_t_dec.h"

namespace nkr { namespace interface {

    template <typename other_p>
    inline constexpr cpp::bool_t
        type_i<boolean::cpp_tg>::Is_Any()
        noexcept
    {
        return boolean::cpp_tr<other_p>;
    }

}}

namespace nkr { namespace boolean {

    inline constexpr cpp_t
        cpp_t::Is_Boolean_Type()
        noexcept
    {
        return true;
    }

    inline constexpr auto&
        cpp_t::Assign_Copy(tr1<any_non_const_tg, cpp_t> auto& self, const tr1<any_tg, cpp_t> auto& other)
        noexcept
    {
        if (cpp::Address(self) != cpp::Address(other)) {
            self.value = other.value;
        }

        return self;
    }

    inline constexpr auto&
        cpp_t::Assign_Move(tr1<any_non_const_tg, cpp_t> auto& self, tr1<any_non_const_tg, cpp_t> auto&& other)
        noexcept
    {
        if (cpp::Address(self) != cpp::Address(other)) {
            self.value = cpp::Exchange(other.value, false);
        }

        return self;
    }

    inline constexpr auto&
        cpp_t::Value(tr1<any_tg, cpp_t> auto& self)
        noexcept
    {
        return self.value;
    }

    inline constexpr cpp_t::cpp_t() noexcept :
        value(false)
    {
    }

    inline constexpr cpp_t::cpp_t(const cpp::to_tr<value_t> auto& value) noexcept :
        value(value_t(value))
    {
    }

    inline constexpr cpp_t::cpp_t(const cpp::to_tr<value_t> auto&& value) noexcept :
        value(value_t(value))
    {
    }

    inline constexpr cpp_t::cpp_t(const cpp_t& other) noexcept :
        value(other.value)
    {
    }

    inline constexpr cpp_t::cpp_t(const volatile cpp_t& other) noexcept :
        value(other.value)
    {
    }

    inline constexpr cpp_t::cpp_t(cpp_t&& other) noexcept :
        value(cpp::Exchange(other.value, false))
    {
    }

    inline constexpr cpp_t::cpp_t(volatile cpp_t&& other) noexcept :
        value(cpp::Exchange(other.value, false))
    {
    }

    inline constexpr cpp_t&
        cpp_t::operator =(const cpp_t& other)
        noexcept
    {
        return Assign_Copy(*this, other);
    }

    inline constexpr volatile cpp_t&
        cpp_t::operator =(const cpp_t& other)
        volatile noexcept
    {
        return Assign_Copy(*this, other);
    }

    inline constexpr cpp_t&
        cpp_t::operator =(const volatile cpp_t& other)
        noexcept
    {
        return Assign_Copy(*this, other);
    }

    inline constexpr volatile cpp_t&
        cpp_t::operator =(const volatile cpp_t& other)
        volatile noexcept
    {
        return Assign_Copy(*this, other);
    }

    inline constexpr cpp_t&
        cpp_t::operator =(cpp_t&& other)
        noexcept
    {
        return Assign_Move(*this, cpp::Move(other));
    }

    inline constexpr volatile cpp_t&
        cpp_t::operator =(cpp_t&& other)
        volatile noexcept
    {
        return Assign_Move(*this, cpp::Move(other));
    }

    inline constexpr cpp_t&
        cpp_t::operator =(tr1<just_volatile_tg, cpp_t> auto&& other)
        noexcept
    {
        return Assign_Move(*this, cpp::Move(other));
    }

    inline constexpr volatile cpp_t&
        cpp_t::operator =(tr1<just_volatile_tg, cpp_t> auto&& other)
        volatile noexcept
    {
        return Assign_Move(*this, cpp::Move(other));
    }

#if defined(nkr_IS_DEBUG)
    inline constexpr cpp_t::~cpp_t() noexcept
    {
        this->value = false;
    }
#endif

    inline constexpr cpp_t::operator cpp_t::value_t&()
        noexcept
    {
        return Value(*this);
    }

    inline constexpr cpp_t::operator const cpp_t::value_t&()
        const noexcept
    {
        return Value(*this);
    }

    inline constexpr cpp_t::operator volatile cpp_t::value_t&()
        volatile noexcept
    {
        return Value(*this);
    }

    inline constexpr cpp_t::operator const volatile cpp_t::value_t&()
        const volatile noexcept
    {
        return Value(*this);
    }

    inline constexpr cpp_t::value_t&
        cpp_t::operator ()()
        noexcept
    {
        return Value(*this);
    }

    inline constexpr const cpp_t::value_t&
        cpp_t::operator ()()
        const noexcept
    {
        return Value(*this);
    }

    inline constexpr volatile cpp_t::value_t&
        cpp_t::operator ()()
        volatile noexcept
    {
        return Value(*this);
    }

    inline constexpr const volatile cpp_t::value_t&
        cpp_t::operator ()()
        const volatile noexcept
    {
        return Value(*this);
    }

}}

#include "nkr/boolean/fast_t_def.h"

namespace nkr {

    inline constexpr boolean::fast_t
        operator ==(const tr1<any_tg, boolean::cpp_t> auto& a, const tr0<any_tg> auto& b)
        noexcept
    {
        using a_t = cpp::reference_value_t<decltype(a)>;
        using b_t = cpp::reference_value_t<decltype(b)>;

        if constexpr (cpp::can_be_equal_to_tr<b_t, boolean::cpp_t::value_t>) {
            return b == boolean::cpp_t::value_t(a);
        } else if constexpr (cpp::to_tr<b_t, boolean::cpp_t>) {
            return boolean::cpp_t::value_t(boolean::cpp_t(b)) == boolean::cpp_t::value_t(a);
        } else {
            static_assert(false, "these two values can not be equal to each other.");
        }
    }

    inline constexpr boolean::fast_t
        operator ==(const tr1<any_tg, boolean::cpp_t> auto& a, const tr0<any_tg> auto&& b)
        noexcept
    {
        return operator ==(a, b);
    }

    inline constexpr boolean::fast_t
        operator ==(const tr1<any_tg, boolean::cpp_t> auto&& a, const tr0<any_tg> auto& b)
        noexcept
    {
        return operator ==(a, b);
    }

    inline constexpr boolean::fast_t
        operator ==(const tr1<any_tg, boolean::cpp_t> auto&& a, const tr0<any_tg> auto&& b)
        noexcept
    {
        return operator ==(a, b);
    }

    inline constexpr boolean::fast_t
        operator !=(const tr1<any_tg, boolean::cpp_t> auto& a, const tr0<any_tg> auto& b)
        noexcept
    {
        return !operator ==(a, b);
    }

    inline constexpr boolean::fast_t
        operator !=(const tr1<any_tg, boolean::cpp_t> auto& a, const tr0<any_tg> auto&& b)
        noexcept
    {
        return !operator ==(a, b);
    }

    inline constexpr boolean::fast_t
        operator !=(const tr1<any_tg, boolean::cpp_t> auto&& a, const tr0<any_tg> auto& b)
        noexcept
    {
        return !operator ==(a, b);
    }

    inline constexpr boolean::fast_t
        operator !=(const tr1<any_tg, boolean::cpp_t> auto&& a, const tr0<any_tg> auto&& b)
        noexcept
    {
        return !operator ==(a, b);
    }

}

namespace nkr { namespace boolean {

    static_assert(sizeof(cpp_t) == sizeof(cpp_t::value_t));

    static_assert(trait::boolean_tr<cpp_t>);
    static_assert(trait::boolean_tr<const cpp_t>);
    static_assert(trait::boolean_tr<volatile cpp_t>);
    static_assert(trait::boolean_tr<const volatile cpp_t>);

    static_assert(trait::boolean::any_tr<cpp_t>);
    static_assert(trait::boolean::any_tr<const cpp_t>);
    static_assert(trait::boolean::any_tr<volatile cpp_t>);
    static_assert(trait::boolean::any_tr<const volatile cpp_t>);

    static_assert(trait::boolean::impure_tr<cpp_t>);
    static_assert(trait::boolean::impure_tr<const cpp_t>);
    static_assert(trait::boolean::impure_tr<volatile cpp_t>);
    static_assert(trait::boolean::impure_tr<const volatile cpp_t>);

}}
