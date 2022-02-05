/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/constant_t_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/enumeration/cpp_t_dec.h"

namespace nkr { namespace constant { namespace enumeration {

    template <nkr::enumeration::cpp_tr enumeration_p, enumeration_p value_p>
    using   cpp_t =
        nkr::constant_t<enumeration_p, value_p>;

    template <typename type_p>
    concept cpp_tr =
        nkr::constant_tr<type_p> &&
        nkr::enumeration::cpp_tr<typename type_p::value_t>;

}}}

#include "nkr/constant/enumeration/cpp_t_dec_def.h"