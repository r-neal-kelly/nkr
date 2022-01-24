/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsics_dec.h"
#include "nkr/generic/implementing/interface/randomness/value_tr_dec.h"
#include "nkr/interface/randomness/value_i_dec.h"

namespace nkr { namespace randomness {

    template <
        nkr::generic::implementing::interface::randomness::value_tr value_p,
        typename ...template_parameters_p,
        typename ...function_parameters_p
    > auto  Value(function_parameters_p&&... function_arguments) noexcept;

}}

#include "nkr/randomness/value_dec_def.h"
