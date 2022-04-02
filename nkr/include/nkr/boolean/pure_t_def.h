/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_2519e504_a646_4aff_b08b_2027e8bbcf44
#define nkr_INCLUDE_GUARD_2519e504_a646_4aff_b08b_2027e8bbcf44

#include "nkr/boolean/cpp_t_def.h"
#include "nkr/boolean/deleted_operators_t_def.h"
#include "nkr/built_in/forward_def.h"
#include "nkr/cpp_def.h"
#include "nkr/interface/forward_def.h"
#include "nkr/interface/randomness/value_i_def.h"
#include "nkr/tr_def.h"

#include "nkr/boolean/pure_t_def.h"

namespace nkr { namespace boolean { namespace pure_t$ {

    template <nkr::boolean::pure_tr type_p>
    template <typename unused_p>
    inline randomness_value_i_sp<type_p>::value_t
        randomness_value_i_sp<type_p>::Value(nkr::negatable::real_t probability_for_true)
        noexcept
    {
        return nkr::interface::randomness::value_i<typename value_t::value_t>::template Value<unused_p>(probability_for_true);
    }

    template <nkr::boolean::pure_tr type_p>
    template <typename unused_p>
    inline randomness_value_i_sp<type_p>::value_t
        randomness_value_i_sp<type_p>::Value(tr<any_non_const_tg, t<nkr::cpp::generic::randomness::generator_tg>> auto& generator,
                                             nkr::negatable::real_t probability_for_true)
        noexcept
    {
        return nkr::interface::randomness::value_i<typename value_t::value_t>::template Value<unused_p>(generator, probability_for_true);
    }

    template <nkr::boolean::pure_tr type_p>
    template <typename unused_p>
    inline randomness_value_i_sp<type_p>::value_t
        randomness_value_i_sp<type_p>::Value(value_t min, value_t max)
        noexcept
    {
        return nkr::interface::randomness::value_i<typename value_t::value_t>::template Value<unused_p>(min(), max());
    }

    template <nkr::boolean::pure_tr type_p>
    template <typename unused_p>
    inline randomness_value_i_sp<type_p>::value_t
        randomness_value_i_sp<type_p>::Value(tr<any_non_const_tg, t<nkr::cpp::generic::randomness::generator_tg>> auto& generator,
                                             value_t min, value_t max)
        noexcept
    {
        return nkr::interface::randomness::value_i<typename value_t::value_t>::template Value<unused_p>(generator, min(), max());
    }

}}}

#endif
