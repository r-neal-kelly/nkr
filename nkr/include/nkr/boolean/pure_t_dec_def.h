/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/boolean/pure_t_dec.h"

namespace nkr { namespace interface {

    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i<nkr::boolean::pure_tg>::Is_Any()
        noexcept
    {
        return nkr::boolean::pure_tr<other_p>;
    }

}}

namespace nkr { namespace boolean {

    inline constexpr auto&
        pure_t::Assign(tr<any_non_const_tg, t<pure_t>> auto& self, const tr<any_tg, t<pure_t>> auto& other)
        noexcept
    {
        if (nkr::cpp::Address(self) != nkr::cpp::Address(other)) {
            self.value = other.value;
        }

        return self;
    }

    inline constexpr auto&
        pure_t::Assign(tr<any_non_const_tg, t<pure_t>> auto& self, tr<any_non_const_tg, t<pure_t>> auto&& other)
        noexcept
    {
        if (nkr::cpp::Address(self) != nkr::cpp::Address(other)) {
        #if defined(nkr_IS_DEBUG)
            self.value = nkr::cpp::Exchange(other.value, false);
        #else
            self.value = nkr::cpp::Move(other.value);
        #endif
        }

        return self;
    }

    inline constexpr pure_t::value_t
        pure_t::Value(const tr<any_tg, t<pure_t>> auto& self)
        noexcept
    {
        return self.value;
    }

    inline constexpr pure_t::pure_t() noexcept :
        value(false)
    {
    }

    inline constexpr pure_t::pure_t(tr<to_tg, t<value_t>> auto&& from) noexcept :
        value(value_t(from))
    {
    }

    inline constexpr pure_t::pure_t(const pure_t& other) noexcept :
        value(other.value)
    {
    }

    inline constexpr pure_t::pure_t(const volatile pure_t& other) noexcept :
        value(other.value)
    {
    }

    inline constexpr pure_t::pure_t(pure_t&& other) noexcept :
    #if defined(nkr_IS_DEBUG)
        value(nkr::cpp::Exchange(other.value, false))
    #else
        value(nkr::cpp::Move(other.value))
    #endif
    {
    }

    inline constexpr pure_t::pure_t(volatile pure_t&& other) noexcept :
    #if defined(nkr_IS_DEBUG)
        value(nkr::cpp::Exchange(other.value, false))
    #else
        value(nkr::cpp::Move(other.value))
    #endif
    {
    }

    inline constexpr pure_t&
        pure_t::operator =(const pure_t& other)
        noexcept
    {
        return Assign(*this, other);
    }

    inline constexpr volatile pure_t&
        pure_t::operator =(const pure_t& other)
        volatile noexcept
    {
        return Assign(*this, other);
    }

    inline constexpr pure_t&
        pure_t::operator =(const volatile pure_t& other)
        noexcept
    {
        return Assign(*this, other);
    }

    inline constexpr volatile pure_t&
        pure_t::operator =(const volatile pure_t& other)
        volatile noexcept
    {
        return Assign(*this, other);
    }

    inline constexpr pure_t&
        pure_t::operator =(pure_t&& other)
        noexcept
    {
        return Assign(*this, nkr::cpp::Move(other));
    }

    inline constexpr volatile pure_t&
        pure_t::operator =(pure_t&& other)
        volatile noexcept
    {
        return Assign(*this, nkr::cpp::Move(other));
    }

    inline constexpr pure_t&
        pure_t::operator =(tr<just_volatile_tg, t<pure_t>> auto&& other)
        noexcept
    {
        return Assign(*this, nkr::cpp::Move(other));
    }

    inline constexpr volatile pure_t&
        pure_t::operator =(tr<just_volatile_tg, t<pure_t>> auto&& other)
        volatile noexcept
    {
        return Assign(*this, nkr::cpp::Move(other));
    }

#if defined(nkr_IS_DEBUG)
    inline constexpr pure_t::~pure_t() noexcept
    {
        this->value = false;
    }
#endif

    inline constexpr pure_t::operator pure_t::value_t()
        const noexcept
    {
        return Value(*this);
    }

    inline constexpr pure_t::operator pure_t::value_t()
        const volatile noexcept
    {
        return Value(*this);
    }

    inline constexpr pure_t::value_t
        pure_t::operator ()()
        const noexcept
    {
        return Value(*this);
    }

    inline constexpr pure_t::value_t
        pure_t::operator ()()
        const volatile noexcept
    {
        return Value(*this);
    }

}}

namespace nkr { namespace boolean { namespace $pure_t {

    template <nkr::boolean::pure_tr type_p>
    inline constexpr none_value_i_sp<type_p>::value_t
        none_value_i_sp<type_p>::Value()
        noexcept
    {
        return value_t();
    }

}}}

inline constexpr nkr::boolean::cpp_t
    operator ==(const nkr::tr<nkr::any_tg, nkr::t<nkr::boolean::pure_t>> auto& a, const auto& b)
    noexcept
{
    using a_t = nkr::cpp::reference_value_t<decltype(a)>;
    using b_t = nkr::cpp::reference_value_t<decltype(b)>;

    if constexpr (nkr::cpp::is_any_tr<b_t, a_t>) {
        return a() == b();
    } else if constexpr (nkr::cpp::to_tr<b_t, nkr::cpp::just_non_qualified_t<typename a_t::value_t>>) {
        return a() == static_cast<nkr::cpp::just_non_qualified_t<typename a_t::value_t>>(b);
    } else if constexpr (nkr::cpp::to_tr<b_t, nkr::cpp::just_non_qualified_t<a_t>>) {
        return a == static_cast<nkr::cpp::just_non_qualified_t<a_t>>(b);
    } else if constexpr (nkr::cpp::to_tr<a_t, nkr::cpp::just_non_qualified_t<b_t>>) {
        return static_cast<nkr::cpp::just_non_qualified_t<b_t>>(a) == b;
    } else {
        static_assert(false, "these two values can not be compared.");
    }
}

inline constexpr nkr::boolean::cpp_t
    operator ==(const nkr::tr<nkr::any_tg, nkr::t<nkr::boolean::pure_t>> auto& a, const auto&& b)
    noexcept
{
    return operator ==(a, b);
}

inline constexpr nkr::boolean::cpp_t
    operator ==(const nkr::tr<nkr::any_tg, nkr::t<nkr::boolean::pure_t>> auto&& a, const auto& b)
    noexcept
{
    return operator ==(a, b);
}

inline constexpr nkr::boolean::cpp_t
    operator ==(const nkr::tr<nkr::any_tg, nkr::t<nkr::boolean::pure_t>> auto&& a, const auto&& b)
    noexcept
{
    return operator ==(a, b);
}

inline constexpr nkr::boolean::cpp_t
    operator !=(const nkr::tr<nkr::any_tg, nkr::t<nkr::boolean::pure_t>> auto& a, const auto& b)
    noexcept
{
    return !operator ==(a, b);
}

inline constexpr nkr::boolean::cpp_t
    operator !=(const nkr::tr<nkr::any_tg, nkr::t<nkr::boolean::pure_t>> auto& a, const auto&& b)
    noexcept
{
    return !operator ==(a, b);
}

inline constexpr nkr::boolean::cpp_t
    operator !=(const nkr::tr<nkr::any_tg, nkr::t<nkr::boolean::pure_t>> auto&& a, const auto& b)
    noexcept
{
    return !operator ==(a, b);
}

inline constexpr nkr::boolean::cpp_t
    operator !=(const nkr::tr<nkr::any_tg, nkr::t<nkr::boolean::pure_t>> auto&& a, const auto&& b)
    noexcept
{
    return !operator ==(a, b);
}
