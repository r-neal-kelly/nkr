/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/built_in/forward_dec.h"
#include "nkr/constant_t_dec.h"
#include "nkr/cpp_dec.h"

namespace nkr { namespace constant { namespace boolean {

    template <nkr::boolean::cpp_t value_p>
    using   cpp_t =
        nkr::constant_t<nkr::boolean::cpp_t, value_p>;

    template <typename type_p>
    concept cpp_tr =
        nkr::constant_tr<type_p> &&
        nkr::cpp::is_tr<typename type_p::value_t, nkr::boolean::cpp_t>;

}}}

#include "nkr/constant/boolean/cpp_t_dec_def.h"
