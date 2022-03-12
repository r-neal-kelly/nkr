/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/constant_t_dec.h"

namespace nkr { namespace constant_t$ {

    template <nkr::constant_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::constant_tr<other_p>;
    }

    template <nkr::constant_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

    template <nkr::cpp::is_any_tr<nkr::constant_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::constant_tr<other_p>;
    }

    template <nkr::cpp::is_any_tr<nkr::constant_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}

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
    inline constexpr constant_t<type_p, value_p>::operator nkr::constant_t<type_p, value_p>::value_t()
        const noexcept
    {
        return Value();
    }

    template <nkr::generic::type_tr type_p, type_p value_p>
    inline constexpr constant_t<type_p, value_p>::operator nkr::constant_t<type_p, value_p>::value_t()
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
