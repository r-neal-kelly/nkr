/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_52bd638f_b753_464e_8733_efe64b5e8714
#define nkr_INCLUDE_GUARD_52bd638f_b753_464e_8733_efe64b5e8714

#include "nkr/built_in/forward_def.h"
#include "nkr/constant_t_def.h"
#include "nkr/constant/positive/count_t_def.h"
#include "nkr/cpp_def.h"
#include "nkr/cpp/generic/randomness/generator_tr_def.h"
#include "nkr/enumeration/cpp_t_def.h"
#include "nkr/enumeration/types_t_def.h"
#include "nkr/generic/implementing/interface/enumeration/types_tr_def.h"
#include "nkr/interface/enumeration/types_i_def.h"
#include "nkr/interface/forward_def.h"
#include "nkr/interface/template_i_identity_tag_t_def.h"
#include "nkr/interface/template_i_identity_template_t_def.h"
#include "nkr/positive/integer_t_def.h"
#include "nkr/reference/lvalue_t_def.h"
#include "nkr/reference/rvalue_t_def.h"
#include "nkr/tr_def.h"
#include "nkr/tuple/types_t_def.h"

#include "nkr/enumeration/errors_t_dec.h"

namespace nkr { namespace enumeration { namespace errors_t$ {

    template <nkr::enumeration::errors_tr type_p>
    template <typename unused_p>
    inline randomness_value_i_sp<type_p>::value_t
        randomness_value_i_sp<type_p>::Value(value_t min, value_t max)
        noexcept
    {
        return nkr::interface::randomness::value_i<typename value_t::enumeration_t>::template Value<>(
            typename value_t::enumeration_t(min.Integer()),
            typename value_t::enumeration_t(max.Integer()));
    }

    template <nkr::enumeration::errors_tr type_p>
    template <typename unused_p>
    inline randomness_value_i_sp<type_p>::value_t
        randomness_value_i_sp<type_p>::Value(tr<any_non_const_tg, t<nkr::cpp::generic::randomness::generator_tg>> auto& generator,
                                             value_t min, value_t max)
        noexcept
    {
        return nkr::interface::randomness::value_i<typename value_t::enumeration_t>::template Value<>(
            generator,
            typename value_t::enumeration_t(min.Integer()),
            typename value_t::enumeration_t(max.Integer()));
    }

}}}

#endif
