/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/constant_t_dec.h"

namespace nkr {

    template <nkr::generic::type_tr type_p, type_p value_p>
    inline constexpr constant_t<type_p, value_p>::value_t
        constant_t<type_p, value_p>::Value()
        noexcept
    {
        return value_p;
    }

    template <nkr::generic::type_tr type_p, type_p value_p>
    inline constexpr constant_t<type_p, value_p>::constant_t() noexcept
    {
    }

    template <nkr::generic::type_tr type_p, type_p value_p>
    inline constexpr constant_t<type_p, value_p>::constant_t(const constant_t& other) noexcept
    {
    }

    template <nkr::generic::type_tr type_p, type_p value_p>
    inline constexpr constant_t<type_p, value_p>::constant_t(const volatile constant_t& other) noexcept
    {
    }

    template <nkr::generic::type_tr type_p, type_p value_p>
    inline constexpr constant_t<type_p, value_p>::constant_t(constant_t&& other) noexcept
    {
    }

    template <nkr::generic::type_tr type_p, type_p value_p>
    inline constexpr constant_t<type_p, value_p>::constant_t(volatile constant_t&& other) noexcept
    {
    }

    template <nkr::generic::type_tr type_p, type_p value_p>
    inline constexpr constant_t<type_p, value_p>::operator constant_t<type_p, value_p>::value_t()
        const noexcept
    {
        return Value();
    }

    template <nkr::generic::type_tr type_p, type_p value_p>
    inline constexpr constant_t<type_p, value_p>::operator constant_t<type_p, value_p>::value_t()
        const volatile noexcept
    {
        return Value();
    }

    template <nkr::generic::type_tr type_p, type_p value_p>
    inline constexpr constant_t<type_p, value_p>::value_t
        constant_t<type_p, value_p>::operator ()()
        const noexcept
    {
        return Value();
    }

    template <nkr::generic::type_tr type_p, type_p value_p>
    inline constexpr constant_t<type_p, value_p>::value_t
        constant_t<type_p, value_p>::operator ()()
        const volatile noexcept
    {
        return Value();
    }

}
