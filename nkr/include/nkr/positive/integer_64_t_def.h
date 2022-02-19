/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/built_in/forward_def.h"
#include "nkr/cpp_def.h"
#include "nkr/cpp/generic/randomness/generator_tr_def.h"
#include "nkr/interface/forward_def.h"
#include "nkr/tr_def.h"

#include "nkr/positive/integer_64_t_dec.h"

#include "nkr/randomness/distributor/uniform_t_def.h"
#include "nkr/randomness/generator/software/default_t_def.h"

namespace nkr { namespace positive { namespace $integer_64_t {

    template <nkr::positive::integer_64_tr type_p>
    template <typename unused_p>
    inline randomness_value_i_sp<type_p>::value_t
        randomness_value_i_sp<type_p>::Value(value_t min, value_t max)
        noexcept
    {
        auto generator = nkr::randomness::generator::software::Default();

        return Value(generator.Value(), min, max);
    }

    template <nkr::positive::integer_64_tr type_p>
    template <typename unused_p>
    inline randomness_value_i_sp<type_p>::value_t
        randomness_value_i_sp<type_p>::Value(tr<any_non_const_tg, t<nkr::cpp::generic::randomness::generator_tg>> auto& generator,
                                             value_t min, value_t max)
        noexcept
    {
        nkr_ASSERT_THAT(min >= nkr::cpp::Default_Min<value_t>());
        nkr_ASSERT_THAT(max <= nkr::cpp::Default_Max<value_t>());
        nkr_ASSERT_THAT(min <= max);

        return nkr::randomness::distributor::uniform_t<value_t>(min, max).Value(generator);
    }

}}}
