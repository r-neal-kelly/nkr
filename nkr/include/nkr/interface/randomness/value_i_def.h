/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/built_in/forward_def.h"
#include "nkr/cpp_def.h"
#include "nkr/cpp/generic/randomness/generator_tr_def.h"
#include "nkr/generic/built_in/boolean_tr_def.h"
#include "nkr/generic/built_in/number/enumeration/limited_tr_def.h"
#include "nkr/generic/built_in/number/integer_tr_def.h"
#include "nkr/generic/built_in/number/real_tr_def.h"
#include "nkr/generic/built_in/pointer_tr_def.h"
#include "nkr/generic/implementing/constructor/default_tr_def.h"
#include "nkr/generic/type_tr_def.h"
#include "nkr/interface/forward_def.h"
#include "nkr/negatable/real_t_def.h"
#include "nkr/positive/integer_t_def.h"
#include "nkr/randomness/generator/software/default_t_def.h"
#include "nkr/tr_def.h"
#include "nkr/tuple/types_t_def.h"

#include "nkr/interface/randomness/value_i_dec.h"

#include "nkr/randomness/distributor/uniform_t_def.h"

namespace nkr { namespace interface { namespace randomness { namespace $value_i {

    template <nkr::generic::built_in::number::integer_tr type_p>
    template <typename unused_p>
    inline integer_sp<type_p>::value_t
        integer_sp<type_p>::Value(value_t min, value_t max)
        noexcept
    {
        auto generator = nkr::randomness::generator::software::Default();

        return Value(generator.Value(), min, max);
    }

    template <nkr::generic::built_in::number::integer_tr type_p>
    template <typename unused_p>
    inline integer_sp<type_p>::value_t
        integer_sp<type_p>::Value(tr<any_non_const_tg, t<nkr::cpp::generic::randomness::generator_tg>> auto& generator,
                                  value_t min, value_t max)
        noexcept
    {
        nkr_ASSERT_THAT(min >= nkr::cpp::Default_Min<value_t>());
        nkr_ASSERT_THAT(max <= nkr::cpp::Default_Max<value_t>());
        nkr_ASSERT_THAT(min <= max);

        return nkr::randomness::distributor::uniform_t<value_t>(min, max).Value(generator);
    }

}}}}

namespace nkr { namespace interface { namespace randomness { namespace $value_i {

    template <nkr::generic::built_in::number::real_tr type_p>
    template <typename unused_p>
    inline real_sp<type_p>::value_t
        real_sp<type_p>::Value(value_t min, value_t max)
        noexcept
    {
        auto generator = nkr::randomness::generator::software::Default();

        return Value(generator.Value(), min, max);
    }

    template <nkr::generic::built_in::number::real_tr type_p>
    template <typename unused_p>
    inline real_sp<type_p>::value_t
        real_sp<type_p>::Value(tr<any_non_const_tg, t<nkr::cpp::generic::randomness::generator_tg>> auto& generator,
                               value_t min, value_t max)
        noexcept
    {
        nkr_ASSERT_THAT(min >= nkr::cpp::Default_Min<value_t>());
        nkr_ASSERT_THAT(max <= nkr::cpp::Default_Max<value_t>());
        nkr_ASSERT_THAT(min <= max);

        return nkr::randomness::distributor::uniform_t<value_t>(min, max).Value(generator);
    }

}}}}
