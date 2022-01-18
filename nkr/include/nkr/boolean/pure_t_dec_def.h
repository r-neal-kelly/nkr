/*
    Copyright 2021 r-neal-kelly
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
        pure_t::Assign(tr1<any_non_const_tg, pure_t> auto& self, const tr1<any_tg, pure_t> auto& other)
        noexcept
    {
        if (cpp::Address(self) != cpp::Address(other)) {
            self.value = other.value;
        }

        return self;
    }

    inline constexpr auto&
        pure_t::Assign(tr1<any_non_const_tg, pure_t> auto& self, tr1<any_non_const_tg, pure_t> auto&& other)
        noexcept
    {
        if (cpp::Address(self) != cpp::Address(other)) {
            self.value = cpp::Move(other.value);
        }

        return self;
    }

    inline constexpr pure_t::value_t
        pure_t::Value(const tr1<any_tg, pure_t> auto& self)
        noexcept
    {
        return self.value;
    }

    inline constexpr pure_t::pure_t() noexcept :
        value(false)
    {
    }

    inline constexpr pure_t::pure_t(const tr1<any_to_tg, value_t> auto& value) noexcept :
        value(value_t(value))
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
        value(cpp::Move(other.value))
    {
    }

    inline constexpr pure_t::pure_t(volatile pure_t&& other) noexcept :
        value(cpp::Move(other.value))
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
        return Assign(*this, cpp::Move(other));
    }

    inline constexpr volatile pure_t&
        pure_t::operator =(pure_t&& other)
        volatile noexcept
    {
        return Assign(*this, cpp::Move(other));
    }

    inline constexpr pure_t&
        pure_t::operator =(volatile pure_t&& other)
        noexcept
    {
        return Assign(*this, cpp::Move(other));
    }

    inline constexpr volatile pure_t&
        pure_t::operator =(volatile pure_t&& other)
        volatile noexcept
    {
        return Assign(*this, cpp::Move(other));
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

}}

inline constexpr nkr::boolean::cpp_t
    operator ==(const nkr::tr1<nkr::any_tg, nkr::boolean::pure_t> auto& a, const auto& b)
    noexcept
{
    using a_t = nkr::cpp::reference_value_t<decltype(a)>;
    using b_t = nkr::cpp::reference_value_t<decltype(b)>;

    if constexpr (nkr::cpp::can_be_equal_to_tr<nkr::boolean::cpp_t, b_t>) {
        return nkr::boolean::cpp_t(a) == b;
    } else if constexpr (nkr::cpp::to_tr<b_t, nkr::boolean::cpp_t>) {
        return nkr::boolean::cpp_t(a) == nkr::boolean::cpp_t(b);
    } else {
        static_assert(false, "these two values can not be equal to each other.");
    }
}

inline constexpr nkr::boolean::cpp_t
    operator ==(const nkr::tr1<nkr::any_tg, nkr::boolean::pure_t> auto& a, const auto&& b)
    noexcept
{
    return operator ==(a, b);
}

inline constexpr nkr::boolean::cpp_t
    operator ==(const nkr::tr1<nkr::any_tg, nkr::boolean::pure_t> auto&& a, const auto& b)
    noexcept
{
    return operator ==(a, b);
}

inline constexpr nkr::boolean::cpp_t
    operator ==(const nkr::tr1<nkr::any_tg, nkr::boolean::pure_t> auto&& a, const auto&& b)
    noexcept
{
    return operator ==(a, b);
}

inline constexpr nkr::boolean::cpp_t
    operator !=(const nkr::tr1<nkr::any_tg, nkr::boolean::pure_t> auto& a, const auto& b)
    noexcept
{
    return !operator ==(a, b);
}

inline constexpr nkr::boolean::cpp_t
    operator !=(const nkr::tr1<nkr::any_tg, nkr::boolean::pure_t> auto& a, const auto&& b)
    noexcept
{
    return !operator ==(a, b);
}

inline constexpr nkr::boolean::cpp_t
    operator !=(const nkr::tr1<nkr::any_tg, nkr::boolean::pure_t> auto&& a, const auto& b)
    noexcept
{
    return !operator ==(a, b);
}

inline constexpr nkr::boolean::cpp_t
    operator !=(const nkr::tr1<nkr::any_tg, nkr::boolean::pure_t> auto&& a, const auto&& b)
    noexcept
{
    return !operator ==(a, b);
}
