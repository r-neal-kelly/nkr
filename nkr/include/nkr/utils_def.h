/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/utils_dec.h"

namespace nkr {

    inline constexpr auto Move(built_in_tr auto& value) noexcept
    {
        auto old = static_cast<std::remove_reference_t<decltype(value)>&&>(value);
        value = static_cast<std::remove_cvref_t<decltype(value)>>(0);

        return old;
    }

    inline constexpr auto&& Move(const built_in_tr auto& value) noexcept
    {
        return static_cast<std::remove_reference_t<decltype(value)>&&>(value);
    }

    inline constexpr auto&& Move(built_in_tr auto&& value) noexcept
    {
        return static_cast<std::remove_reference_t<decltype(value)>&&>(value);
    }

    inline constexpr auto&& Move(const built_in_tr auto&& value) noexcept
    {
        return static_cast<std::remove_reference_t<decltype(value)>&&>(value);
    }

    inline constexpr auto&& Move(user_defined_tr auto& value) noexcept
    {
        return static_cast<std::remove_reference_t<decltype(value)>&&>(value);
    }

    inline constexpr auto&& Move(user_defined_tr auto&& value) noexcept
    {
        return static_cast<std::remove_reference_t<decltype(value)>&&>(value);
    }

    inline constexpr auto Exchange(any_type_tr auto& value, any_type_tr auto& with) noexcept
    {
        using value_t = std::remove_reference_t<decltype(value)>;
        using with_t = std::remove_reference_t<decltype(with)>;

        value_t old = static_cast<value_t&&>(value);
        value = with;

        return old;
    }

    inline constexpr auto Exchange(any_type_tr auto& value, any_non_const_tr auto&& with) noexcept
    {
        using value_t = std::remove_reference_t<decltype(value)>;
        using with_t = std::remove_reference_t<decltype(with)>;

        value_t old = static_cast<value_t&&>(value);
        value = static_cast<with_t&&>(with);

        return old;
    }

    inline constexpr auto Is_LValue(any_tr auto& value)
    {
        return std::true_type();
    }

    inline constexpr auto Is_LValue(any_tr auto&& value)
    {
        return std::false_type();
    }

    inline constexpr auto Is_RValue(any_tr auto& value)
    {
        return std::false_type();
    }

    inline constexpr auto Is_RValue(any_tr auto&& value)
    {
        return std::true_type();
    }

}
