/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/array/cpp_t_dec.h"
#include "nkr/built_in/forward_dec.h"
#include "nkr/constant_t_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/generic/type_tr_dec.h"

namespace nkr { namespace constant { namespace array {

    template <nkr::generic::type_tr unit_p, nkr::positive::count_t capacity_p, unit_p value_p[capacity_p]>
    using   cpp_t =
        nkr::constant_t<unit_p[capacity_p], value_p>;

    template <typename type_p>
    concept cpp_tr =
        nkr::constant_tr<type_p> &&
        nkr::array::cpp_tr<typename type_p::value_t>;

}}}

#include "nkr/constant/array/cpp_t_dec_def.h"
