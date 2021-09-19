/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsics.h"
#include "nkr/traits.h"

namespace nkr {

    constexpr auto      Move(built_in_tr auto& value) noexcept;
    constexpr auto&&    Move(const built_in_tr auto& value) noexcept;
    constexpr auto&&    Move(built_in_tr auto&& value) noexcept;
    constexpr auto&&    Move(const built_in_tr auto&& value) noexcept;
    constexpr auto&&    Move(user_defined_tr auto& value) noexcept;
    constexpr auto&&    Move(const user_defined_tr auto& value) noexcept    = delete;
    constexpr auto&&    Move(user_defined_tr auto&& value) noexcept;
    constexpr auto&&    Move(const user_defined_tr auto&& value) noexcept   = delete;

}
