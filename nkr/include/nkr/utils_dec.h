/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include <mutex>
#include <random>

#include "nkr/intrinsics.h"
#include "nkr/traits.h"

namespace nkr {

    constexpr auto      Move(built_in_tr auto& value) noexcept;
    constexpr auto&&    Move(const built_in_tr auto& value) noexcept;
    constexpr auto&&    Move(built_in_tr auto&& value) noexcept;
    constexpr auto&&    Move(const built_in_tr auto&& value) noexcept;
    constexpr auto&&    Move(user_defined_tr auto& value) noexcept;
    constexpr auto&&    Move(const user_defined_tr auto& value) noexcept                            = delete;
    constexpr auto&&    Move(user_defined_tr auto&& value) noexcept;
    constexpr auto&&    Move(const user_defined_tr auto&& value) noexcept                           = delete;

    constexpr auto      Exchange(any_type_tr auto& value, any_type_tr auto& with) noexcept;
    constexpr auto      Exchange(any_type_tr auto& value, any_non_const_tr auto&& with) noexcept;

    constexpr auto      Is_LValue(any_tr auto& value);
    constexpr auto      Is_LValue(any_tr auto&& value);
    constexpr auto      Is_RValue(any_tr auto& value);
    constexpr auto      Is_RValue(any_tr auto&& value);

    count_t C_String_Unit_Count(const any_character_tr auto* c_string);
    count_t C_String_Unit_Length(const any_character_tr auto* c_string);

    extern std::random_device   random_device;
    extern std::mt19937_64      random_generator;
    extern std::mutex           random_lock;

    template <boolean_tr boolean_p>
    boolean_p   Random(real_t probability_for_true);
    template <integer_tr integer_p>
    integer_p   Random(std::remove_cv_t<integer_p> from_inclusive, std::remove_cv_t<integer_p> to_inclusive);
    template <integer_tr integer_p, real_tr real_p>
    integer_p   Random(real_p from_inclusive, real_p to_inclusive);
    template <real_tr real_p>
    real_p      Random(std::remove_cv_t<real_p> from_inclusive, std::remove_cv_t<real_p> to_inclusive);
    template <real_tr real_p, integer_tr integer_p>
    real_p      Random(integer_p from_inclusive, integer_p to_inclusive);
    template <pointer_tr pointer_p>
    pointer_p   Random();

}
