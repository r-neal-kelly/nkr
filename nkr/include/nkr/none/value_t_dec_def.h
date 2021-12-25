/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/none/value_t_dec.h"

namespace nkr { namespace interface {

    template <typename other_p>
    inline constexpr boolean::cpp_t
        type_i<nkr::none::value_tg>::Is_Any()
        noexcept
    {
        return nkr::none::value_tr<other_p>;
    }

    inline constexpr boolean::cpp_t
        template_i<nkr::none::value_ttg>::Is_Implemented()
        noexcept
    {
        return true;
    }

}}

namespace nkr { namespace none {

    template <general::implementing::interface::none::value_tr type_p>
    inline constexpr value_t<type_p>::value_t() noexcept
    {
    }

    template <general::implementing::interface::none::value_tr type_p>
    inline constexpr value_t<type_p>::value_t(const value_t& other) noexcept
    {
    }

    template <general::implementing::interface::none::value_tr type_p>
    inline constexpr value_t<type_p>::value_t(const volatile value_t& other) noexcept
    {
    }

    template <general::implementing::interface::none::value_tr type_p>
    inline constexpr value_t<type_p>::value_t(value_t&& other) noexcept
    {
    }

    template <general::implementing::interface::none::value_tr type_p>
    inline constexpr value_t<type_p>::value_t(volatile value_t&& other) noexcept
    {
    }

    template <general::implementing::interface::none::value_tr type_p>
    inline constexpr value_t<type_p>&
        value_t<type_p>::operator =(const value_t& other)
        noexcept
    {
        return *this;
    }

    template <general::implementing::interface::none::value_tr type_p>
    inline constexpr volatile value_t<type_p>&
        value_t<type_p>::operator =(const value_t& other)
        volatile noexcept
    {
        return *this;
    }

    template <general::implementing::interface::none::value_tr type_p>
    inline constexpr value_t<type_p>&
        value_t<type_p>::operator =(const volatile value_t& other)
        noexcept
    {
        return *this;
    }

    template <general::implementing::interface::none::value_tr type_p>
    inline constexpr volatile value_t<type_p>&
        value_t<type_p>::operator =(const volatile value_t& other)
        volatile noexcept
    {
        return *this;
    }

    template <general::implementing::interface::none::value_tr type_p>
    inline constexpr value_t<type_p>&
        value_t<type_p>::operator =(value_t&& other)
        noexcept
    {
        return *this;
    }

    template <general::implementing::interface::none::value_tr type_p>
    inline constexpr volatile value_t<type_p>&
        value_t<type_p>::operator =(value_t&& other)
        volatile noexcept
    {
        return *this;
    }

    template <general::implementing::interface::none::value_tr type_p>
    inline constexpr value_t<type_p>&
        value_t<type_p>::operator =(tr1<just_volatile_tg, value_t> auto&& other)
        noexcept
    {
        return *this;
    }

    template <general::implementing::interface::none::value_tr type_p>
    inline constexpr volatile value_t<type_p>&
        value_t<type_p>::operator =(tr1<just_volatile_tg, value_t> auto&& other)
        volatile noexcept
    {
        return *this;
    }

#if defined(nkr_IS_DEBUG)
    template <general::implementing::interface::none::value_tr type_p>
    inline constexpr value_t<type_p>::~value_t() noexcept
    {
    }
#endif

    template <general::implementing::interface::none::value_tr type_p>
    inline constexpr value_t<type_p>::operator value_t<type_p>::type_t()
        const noexcept
    {
        return interface_t::Value();
    }

    template <general::implementing::interface::none::value_tr type_p>
    inline constexpr value_t<type_p>::operator value_t<type_p>::type_t()
        const volatile noexcept
    {
        return interface_t::Value();
    }

}}
