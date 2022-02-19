/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/built_in/forward_dec.h"
#include "nkr/constant_t_dec.h"
#include "nkr/cpp_dec.h"

namespace nkr { namespace constant { namespace negatable {

    template <nkr::negatable::real_max_t value_p>
    using   real_max_t =
        nkr::constant_t<nkr::negatable::real_max_t, value_p>;

    template <typename type_p>
    concept real_max_tr =
        nkr::constant_tr<type_p> &&
        nkr::cpp::is_tr<typename type_p::value_t, nkr::negatable::real_max_t>;

}}}

#include "nkr/constant/negatable/real_max_t_dec_def.h"
