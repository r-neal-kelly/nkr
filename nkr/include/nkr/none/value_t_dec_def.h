/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/none/value_t_dec.h"

namespace nkr { namespace interface {

    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i<nkr::none::value_tg>::Is_Any()
        noexcept
    {
        return nkr::none::value_tr<other_p>;
    }

}}

namespace nkr { namespace interface {

    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i<nkr::none::value_ttg>::Is_Any()
        noexcept
    {
        return nkr::none::value_ttr<other_p>;
    }

}}

namespace nkr { namespace none {

    template <generic::implementing::interface::none::value_tr type_p>
    inline constexpr value_t<type_p>::type_t value_t<type_p>::Value()
        noexcept
    {
        return interface_t::Value();
    }

    template <generic::implementing::interface::none::value_tr type_p>
    inline constexpr value_t<type_p>::value_t() noexcept
    {
    }

    template <generic::implementing::interface::none::value_tr type_p>
    inline constexpr value_t<type_p>::value_t(const value_t& other) noexcept
    {
    }

    template <generic::implementing::interface::none::value_tr type_p>
    inline constexpr value_t<type_p>::value_t(const volatile value_t& other) noexcept
    {
    }

    template <generic::implementing::interface::none::value_tr type_p>
    inline constexpr value_t<type_p>::value_t(value_t&& other) noexcept
    {
    }

    template <generic::implementing::interface::none::value_tr type_p>
    inline constexpr value_t<type_p>::value_t(volatile value_t&& other) noexcept
    {
    }

    template <generic::implementing::interface::none::value_tr type_p>
    inline constexpr value_t<type_p>&
        value_t<type_p>::operator =(const value_t& other)
        noexcept
    {
        return *this;
    }

    template <generic::implementing::interface::none::value_tr type_p>
    inline constexpr volatile value_t<type_p>&
        value_t<type_p>::operator =(const value_t& other)
        volatile noexcept
    {
        return *this;
    }

    template <generic::implementing::interface::none::value_tr type_p>
    inline constexpr value_t<type_p>&
        value_t<type_p>::operator =(const volatile value_t& other)
        noexcept
    {
        return *this;
    }

    template <generic::implementing::interface::none::value_tr type_p>
    inline constexpr volatile value_t<type_p>&
        value_t<type_p>::operator =(const volatile value_t& other)
        volatile noexcept
    {
        return *this;
    }

    template <generic::implementing::interface::none::value_tr type_p>
    inline constexpr value_t<type_p>&
        value_t<type_p>::operator =(value_t&& other)
        noexcept
    {
        return *this;
    }

    template <generic::implementing::interface::none::value_tr type_p>
    inline constexpr volatile value_t<type_p>&
        value_t<type_p>::operator =(value_t&& other)
        volatile noexcept
    {
        return *this;
    }

    template <generic::implementing::interface::none::value_tr type_p>
    inline constexpr value_t<type_p>&
        value_t<type_p>::operator =(tr1<just_volatile_tg, value_t> auto&& other)
        noexcept
    {
        return *this;
    }

    template <generic::implementing::interface::none::value_tr type_p>
    inline constexpr volatile value_t<type_p>&
        value_t<type_p>::operator =(tr1<just_volatile_tg, value_t> auto&& other)
        volatile noexcept
    {
        return *this;
    }

#if defined(nkr_IS_DEBUG)
    template <generic::implementing::interface::none::value_tr type_p>
    inline constexpr value_t<type_p>::~value_t() noexcept
    {
    }
#endif

    template <generic::implementing::interface::none::value_tr type_p>
    inline constexpr value_t<type_p>::operator value_t<type_p>::type_t()
        const noexcept
    {
        return interface_t::Value();
    }

    template <generic::implementing::interface::none::value_tr type_p>
    inline constexpr value_t<type_p>::operator value_t<type_p>::type_t()
        const volatile noexcept
    {
        return interface_t::Value();
    }

    template <generic::implementing::interface::none::value_tr type_p>
    inline constexpr value_t<type_p>::type_t value_t<type_p>::operator ()()
        const noexcept
    {
        return interface_t::Value();
    }

    template <generic::implementing::interface::none::value_tr type_p>
    inline constexpr value_t<type_p>::type_t value_t<type_p>::operator ()()
        const volatile noexcept
    {
        return interface_t::Value();
    }

}}

inline constexpr nkr::boolean::cpp_t
    operator ==(const nkr::tr1<nkr::any_tg, nkr::none::value_tg> auto& a, const auto& b)
    noexcept
{
    using a_t = nkr::cpp::reference_value_t<decltype(a)>;
    using b_t = nkr::cpp::reference_value_t<decltype(b)>;

    if constexpr (nkr::cpp::is_any_tr<b_t, a_t>) {
        return a() == b();
    } else if constexpr (nkr::cpp::to_tr<b_t, nkr::cpp::just_non_qualified_t<typename a_t::type_t>>) {
        return a() == static_cast<nkr::cpp::just_non_qualified_t<typename a_t::type_t>>(b);
    } else if constexpr (nkr::cpp::to_tr<b_t, nkr::cpp::just_non_qualified_t<a_t>>) {
        return a == static_cast<nkr::cpp::just_non_qualified_t<a_t>>(b);
    } else if constexpr (nkr::cpp::to_tr<a_t, nkr::cpp::just_non_qualified_t<b_t>>) {
        return static_cast<nkr::cpp::just_non_qualified_t<b_t>>(a) == b;
    } else {
        static_assert(false, "these two values can not be equal to each other.");
    }
}

inline constexpr nkr::boolean::cpp_t
    operator ==(const nkr::tr1<nkr::any_tg, nkr::none::value_tg> auto& a, const auto&& b)
    noexcept
{
    return operator ==(a, b);
}

inline constexpr nkr::boolean::cpp_t
    operator ==(const nkr::tr1<nkr::any_tg, nkr::none::value_tg> auto&& a, const auto& b)
    noexcept
{
    return operator ==(a, b);
}

inline constexpr nkr::boolean::cpp_t
    operator ==(const nkr::tr1<nkr::any_tg, nkr::none::value_tg> auto&& a, const auto&& b)
    noexcept
{
    return operator ==(a, b);
}

inline constexpr nkr::boolean::cpp_t
    operator !=(const nkr::tr1<nkr::any_tg, nkr::none::value_tg> auto& a, const auto& b)
    noexcept
{
    return !operator ==(a, b);
}

inline constexpr nkr::boolean::cpp_t
    operator !=(const nkr::tr1<nkr::any_tg, nkr::none::value_tg> auto& a, const auto&& b)
    noexcept
{
    return !operator ==(a, b);
}

inline constexpr nkr::boolean::cpp_t
    operator !=(const nkr::tr1<nkr::any_tg, nkr::none::value_tg> auto&& a, const auto& b)
    noexcept
{
    return !operator ==(a, b);
}

inline constexpr nkr::boolean::cpp_t
    operator !=(const nkr::tr1<nkr::any_tg, nkr::none::value_tg> auto&& a, const auto&& b)
    noexcept
{
    return !operator ==(a, b);
}
