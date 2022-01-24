/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/tr_def.h"

#include "nkr/boolean/cpp_t_def.h"
#include "nkr/boolean/deleted_operators_t_def.h"
#include "nkr/interface/randomness/value_i_def.h"

#include "nkr/boolean/pure_t_dec.h"

namespace nkr { namespace boolean { namespace $pure_t {

    template <typename unused_p>
    inline randomness_value_i_sp::value_t
        randomness_value_i_sp::Value(nkr::negatable::real_t probability_for_true)
        noexcept
    {
        return nkr::interface::randomness::value_i<typename value_t::value_t>::template Value<unused_p>(probability_for_true);
    }

    template <typename unused_p>
    inline randomness_value_i_sp::value_t
        randomness_value_i_sp::Value(tr1<any_non_const_tg, nkr::cpp::generic::randomness::generator_tg> auto& generator,
                                     nkr::negatable::real_t probability_for_true)
        noexcept
    {
        return nkr::interface::randomness::value_i<typename value_t::value_t>::template Value<unused_p>(generator, probability_for_true);
    }

    template <typename unused_p>
    inline randomness_value_i_sp::value_t
        randomness_value_i_sp::Value(value_t min, value_t max)
        noexcept
    {
        return nkr::interface::randomness::value_i<typename value_t::value_t>::template Value<unused_p>(min(), max());
    }

    template <typename unused_p>
    inline randomness_value_i_sp::value_t
        randomness_value_i_sp::Value(tr1<any_non_const_tg, nkr::cpp::generic::randomness::generator_tg> auto& generator,
                                     value_t min, value_t max)
        noexcept
    {
        return nkr::interface::randomness::value_i<typename value_t::value_t>::template Value<unused_p>(generator, min(), max());
    }

}}}
