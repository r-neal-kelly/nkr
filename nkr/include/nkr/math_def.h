/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/math_dec.h"

namespace nkr { namespace math { namespace $fraction_t {

    template <auto NUMERATOR_p, auto DENOMINATOR_p>
    inline constexpr typename integer_sp<NUMERATOR_p, DENOMINATOR_p>::numerator_t integer_sp<NUMERATOR_p, DENOMINATOR_p>::Numerator()
    {
        return NUMERATOR_p;
    }

    template <auto NUMERATOR_p, auto DENOMINATOR_p>
    inline constexpr typename integer_sp<NUMERATOR_p, DENOMINATOR_p>::denominator_t integer_sp<NUMERATOR_p, DENOMINATOR_p>::Denominator()
    {
        return DENOMINATOR_p;
    }

    template <auto NUMERATOR_p, auto DENOMINATOR_p>
    inline constexpr real_t integer_sp<NUMERATOR_p, DENOMINATOR_p>::To_Decimal()
    {
        static_assert(Denominator() >= 0, "denominator must be > 0");

        return static_cast<real_t>(Numerator()) / static_cast<real_t>(Denominator());
    }

}}}
