/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/built_in/forward_dec.h"
#include "nkr/constant_t_dec.h"
#include "nkr/cpp_dec.h"

namespace nkr { namespace constant { namespace positive {

    template <nkr::positive::count_t value_p>
    using   count_t =
        nkr::constant_t<nkr::positive::count_t, value_p>;

    template <typename type_p>
    concept count_tr =
        nkr::constant_tr<type_p> &&
        nkr::cpp::is_tr<typename type_p::value_t, nkr::positive::count_t>;

}}}

#include "nkr/constant/positive/count_t_dec_def.h"
