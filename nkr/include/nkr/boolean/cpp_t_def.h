/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/built_in/forward_def.h"
#include "nkr/cpp_def.h"
#include "nkr/cpp/generic/randomness/generator_tr_def.h"
#include "nkr/interface/forward_def.h"
#include "nkr/tr_def.h"

#include "nkr/boolean/cpp_t_dec.h"

#include "nkr/cpp/randomness/distributor/bernoulli_t_def.h"
#include "nkr/randomness/distributor/uniform_t_def.h"
#include "nkr/randomness/generator/software/default_t_def.h"

namespace nkr { namespace boolean { namespace $cpp_t {

    template <nkr::boolean::cpp_tr type_p>
    template <typename unused_p>
    inline randomness_value_i_sp<type_p>::value_t
        randomness_value_i_sp<type_p>::Value(nkr::negatable::real_t probability_for_true)
        noexcept
    {
        auto generator = nkr::randomness::generator::software::Default();

        return Value(generator.Value(), probability_for_true);
    }

    template <nkr::boolean::cpp_tr type_p>
    template <typename unused_p>
    inline randomness_value_i_sp<type_p>::value_t
        randomness_value_i_sp<type_p>::Value(tr<any_non_const_tg, t<nkr::cpp::generic::randomness::generator_tg>> auto& generator,
                                             nkr::negatable::real_t probability_for_true)
        noexcept
    {
        nkr_ASSERT_THAT(probability_for_true >= nkr::negatable::real_t(0.0));
        nkr_ASSERT_THAT(probability_for_true <= nkr::negatable::real_t(1.0));

        return nkr::cpp::randomness::distributor::bernoulli_t(probability_for_true)(generator);
    }

    template <nkr::boolean::cpp_tr type_p>
    template <typename unused_p>
    inline randomness_value_i_sp<type_p>::value_t
        randomness_value_i_sp<type_p>::Value(value_t min, value_t max)
        noexcept
    {
        auto generator = nkr::randomness::generator::software::Default();

        return Value(generator.Value(), min, max);
    }

    template <nkr::boolean::cpp_tr type_p>
    template <typename unused_p>
    inline randomness_value_i_sp<type_p>::value_t
        randomness_value_i_sp<type_p>::Value(tr<any_non_const_tg, t<nkr::cpp::generic::randomness::generator_tg>> auto& generator,
                                             value_t min, value_t max)
        noexcept
    {
        nkr_ASSERT_THAT(min <= max);

        return nkr::randomness::distributor::uniform_t<value_t>(min, max).Value(generator);
    }

}}}
