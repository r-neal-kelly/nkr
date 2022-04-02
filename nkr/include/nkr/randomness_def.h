/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_7c08ed0b_9b6f_4a10_8077_ff7850ce328b
#define nkr_INCLUDE_GUARD_7c08ed0b_9b6f_4a10_8077_ff7850ce328b

#include "nkr/generic/implementing/interface/randomness/value_tr_def.h"

#include "nkr/randomness_dec.h"

#include "nkr/cpp_def.h"
#include "nkr/interface/forward_def.h"
#include "nkr/interface/randomness/value_i_def.h"

namespace nkr { namespace randomness {

    template <
        nkr::generic::implementing::interface::randomness::value_tr value_p,
        typename ...template_parameters_p,
        typename ...function_parameters_p
    > inline auto
        Value(function_parameters_p&&... function_arguments)
        noexcept
    {
        return nkr::interface::randomness::value_i<value_p>::template Value<template_parameters_p...>
            (nkr::cpp::Forward<function_parameters_p>(function_arguments)...);
    }

}}

#endif
