/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/generic/implementing/interface/randomness/value_tr_def.h"

#include "nkr/randomness/value_dec.h"

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
