/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_5c925315_6c66_4dcf_a3e8_d0e894a21f71
#define nkr_INCLUDE_GUARD_5c925315_6c66_4dcf_a3e8_d0e894a21f71

#include "nkr/generic/implementing/interface/randomness/value_tr_dec.h"

namespace nkr { namespace randomness {

    template <
        nkr::generic::implementing::interface::randomness::value_tr value_p,
        typename ...template_parameters_p,
        typename ...function_parameters_p
    > auto  Value(function_parameters_p&&... function_arguments) noexcept;

}}

#include "nkr/randomness_dec_def.h"

#endif
