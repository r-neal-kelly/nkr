/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_f1adc0d4_7016_48c0_9f6f_214566918fdc
#define nkr_INCLUDE_GUARD_f1adc0d4_7016_48c0_9f6f_214566918fdc

#include "nkr/built_in/forward_def.h"
#include "nkr/cpp_def.h"
#include "nkr/cpp/generic/randomness/generator_tr_def.h"
#include "nkr/generic/built_in/number/enumeration/any_tr_def.h"
#include "nkr/generic/built_in/number/enumeration/limited_tr_def.h"
#include "nkr/generic/built_in/number/enumeration/unlimited_tr_def.h"
#include "nkr/generic/implementing/label/none_tr_def.h"
#include "nkr/generic/negatable_tr_def.h"
#include "nkr/generic/positive_tr_def.h"
#include "nkr/interface/forward_def.h"
#include "nkr/tr_def.h"

#include "nkr/enumeration/cpp_t_dec.h"

#include "nkr/randomness/distributor/uniform_t_def.h"
#include "nkr/randomness/generator/software/default_t_def.h"

namespace nkr { namespace enumeration { namespace cpp_t$ {

    template <nkr::generic::built_in::number::enumeration::limited_tr type_p>
    template <typename unused_p>
    inline randomness_value_i_sp<type_p>::value_t
        randomness_value_i_sp<type_p>::Value(value_t min, value_t max)
        noexcept
    {
        auto generator = nkr::randomness::generator::software::Default();

        return Value(generator.Value(), min, max);
    }

    template <nkr::generic::built_in::number::enumeration::limited_tr type_p>
    template <typename unused_p>
    inline randomness_value_i_sp<type_p>::value_t
        randomness_value_i_sp<type_p>::Value(tr<any_non_const_tg, t<nkr::cpp::generic::randomness::generator_tg>> auto& generator,
                                             value_t min, value_t max)
        noexcept
    {
        nkr_ASSERT_THAT(min >= value_t::MIN_lb);
        nkr_ASSERT_THAT(max <= value_t::MAX_lb);
        nkr_ASSERT_THAT(min <= max);

        return nkr::randomness::distributor::uniform_t<value_t>(min, max).Value(generator);
    }

}}}

#endif
