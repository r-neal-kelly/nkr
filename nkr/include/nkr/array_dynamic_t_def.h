/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "array_dynamic_t_dec.h"

namespace nkr {

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline constexpr real_t array_dynamic_t<unit_p, allocator_p, grow_rate_p>::Grow_Rate()
    {
        static_assert(grow_rate_p::NUMERATOR >= 0, "numerator must be > 0");
        static_assert(grow_rate_p::DENOMINATOR >= 0, "denominator must be > 0");

        constexpr real_t grow_rate =
            static_cast<real_t>(grow_rate_p::NUMERATOR) /
            static_cast<real_t>(grow_rate_p::DENOMINATOR);

        static_assert(grow_rate >= 1.0, "grow_rate must be >= 1.0");

        return grow_rate;
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline array_dynamic_t<unit_p, allocator_p, grow_rate_p>::array_dynamic_t() :
        units(), unit_count(0), allocator()
    {
    }

}
