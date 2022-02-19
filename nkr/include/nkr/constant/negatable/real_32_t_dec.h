/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/built_in/forward_dec.h"
#include "nkr/constant_t_dec.h"
#include "nkr/cpp_dec.h"

namespace nkr { namespace constant { namespace negatable {

    template <nkr::negatable::real_32_t value_p>
    using   real_32_t =
        nkr::constant_t<nkr::negatable::real_32_t, value_p>;

    template <typename type_p>
    concept real_32_tr =
        nkr::constant_tr<type_p> &&
        nkr::cpp::is_tr<typename type_p::value_t, nkr::negatable::real_32_t>;

}}}

#include "nkr/constant/negatable/real_32_t_dec_def.h"
