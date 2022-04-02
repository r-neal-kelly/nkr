/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_4018b0ec_ba13_4911_ae80_6a3454106892
#define nkr_INCLUDE_GUARD_4018b0ec_ba13_4911_ae80_6a3454106892

#include "nkr/built_in/forward_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/generic/built_in/number_tr_dec.h"
#include "nkr/generic/built_in/number/integer_tr_dec.h"
#include "nkr/generic/negatable_tr_dec.h"
#include "nkr/generic/positive_tr_dec.h"

namespace nkr { namespace math {

    constexpr auto                      Absolute(nkr::generic::positive_tr auto positive_integer) noexcept;
    constexpr auto                      Absolute(nkr::generic::negatable_tr auto negatable_integer) noexcept;

    constexpr nkr::boolean::cpp_t       Is_Odd(nkr::generic::built_in::number::integer_tr auto integer) noexcept;
    constexpr nkr::boolean::cpp_t       Is_Even(nkr::generic::built_in::number::integer_tr auto integer) noexcept;

    constexpr nkr::boolean::cpp_t       Is_Power_Of_2(nkr::generic::positive_tr auto positive_integer) noexcept;
    constexpr nkr::boolean::cpp_t       Is_Power_Of_2(nkr::generic::negatable_tr auto negatable_integer) noexcept;
    constexpr nkr::positive::integer_t  Round_To_Power_Of_2(nkr::generic::positive_tr auto positive_integer) noexcept; // can we make this auto and return 64 bit integer in 32 bit mode if 32 bit is not big enough?

    template <nkr::generic::built_in::number_tr number_p>
    constexpr nkr::boolean::cpp_t       Will_Overflow_Add(number_p lhs, number_p rhs) noexcept;
    template <nkr::generic::built_in::number_tr number_p>
    constexpr nkr::boolean::cpp_t       Will_Overflow_Subtract(number_p lhs, number_p rhs) noexcept;
    template <nkr::generic::built_in::number_tr number_p>
    constexpr nkr::boolean::cpp_t       Will_Overflow_Multiply(number_p lhs, number_p rhs) noexcept;
    template <nkr::generic::built_in::number_tr number_p>
    constexpr nkr::boolean::cpp_t       Will_Overflow_Divide(number_p lhs, number_p rhs) noexcept;

}}

#include "nkr/math_dec_def.h"

#endif
