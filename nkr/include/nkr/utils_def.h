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

}
