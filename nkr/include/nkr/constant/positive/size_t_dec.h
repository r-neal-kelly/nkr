/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/built_in/forward_dec.h"
#include "nkr/constant_t_dec.h"
#include "nkr/cpp_dec.h"

namespace nkr { namespace constant { namespace positive {

    template <nkr::positive::size_t value_p>
    using   size_t =
        nkr::constant_t<nkr::positive::size_t, value_p>;

    template <typename type_p>
    concept size_tr =
        nkr::constant_tr<type_p> &&
        nkr::cpp::is_tr<typename type_p::value_t, nkr::positive::size_t>;

}}}

#include "nkr/constant/positive/size_t_dec_def.h"
