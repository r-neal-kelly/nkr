/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsics_dec.h"

#include "nkr/generic/implementing/interface/randomness_tr_dec.h"

namespace nkr { namespace $randomness {



}}

namespace nkr { namespace randomness {

    template <
        nkr::generic::implementing::interface::randomness_tr value_p,
        typename ...template_parameters_p,
        typename ...function_parameters_p
    > auto  Value(function_parameters_p... function_arguments) noexcept;

}}

#include "nkr/randomness/native_dec_def.h"
