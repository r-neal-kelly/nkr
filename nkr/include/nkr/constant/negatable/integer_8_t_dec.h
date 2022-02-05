/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/built_in/forward_dec.h"
#include "nkr/constant_t_dec.h"
#include "nkr/cpp_dec.h"

namespace nkr { namespace constant { namespace negatable {

    template <nkr::negatable::integer_8_t value_p>
    using   integer_8_t =
        nkr::constant_t<nkr::negatable::integer_8_t, value_p>;

    template <typename type_p>
    concept integer_8_tr =
        nkr::constant_tr<type_p> &&
        nkr::cpp::is_tr<typename type_p::value_t, nkr::negatable::integer_8_t>;

}}}

#include "nkr/constant/negatable/integer_8_t_dec_def.h"
