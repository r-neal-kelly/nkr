/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsics.h"
#include "nkr/traits.h"

namespace nkr { namespace math {

    template <integer_tr auto NUMERATOR_p, integer_tr auto DENOMINATOR_p>
    class fraction_t
    {
    public:
        static constexpr decltype(NUMERATOR_p)      NUMERATOR   = NUMERATOR_p;
        static constexpr decltype(DENOMINATOR_p)    DENOMINATOR = DENOMINATOR_p;
    };

    template <typename fraction_p>
    concept fraction_i = requires()
    {
        fraction_p::NUMERATOR;
        fraction_p::DENOMINATOR;
    };

}}
