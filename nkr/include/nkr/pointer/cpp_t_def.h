/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_82a0da25_ef3b_45ec_9520_ea674814682f
#define nkr_INCLUDE_GUARD_82a0da25_ef3b_45ec_9520_ea674814682f

#include "nkr/built_in/forward_def.h"
#include "nkr/constant/positive/count_t_def.h"
#include "nkr/cpp_def.h"
#include "nkr/cpp/generic/randomness/generator_tr_def.h"
#include "nkr/interface/forward_def.h"
#include "nkr/interface/template_i_identity_tag_t_def.h"
#include "nkr/interface/template_i_identity_template_t_def.h"
#include "nkr/tuple/types_t_def.h"
#include "nkr/tr_def.h"

#include "nkr/pointer/cpp_t_dec.h"

#include "nkr/randomness/distributor/uniform_t_def.h"
#include "nkr/randomness/generator/software/default_t_def.h"

namespace nkr { namespace pointer { namespace cpp_t$ {

    template <nkr::pointer::cpp_tr type_p>
    template <typename unused_p>
    inline randomness_value_i_sp<type_p>::value_t
        randomness_value_i_sp<type_p>::Value(value_t min, value_t max)
        noexcept
    {
        auto generator = nkr::randomness::generator::software::Default();

        return Value(generator.Value(), min, max);
    }

    template <nkr::pointer::cpp_tr type_p>
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

#endif
