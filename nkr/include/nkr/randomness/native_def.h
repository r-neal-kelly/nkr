/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsics_def.h"

#include "nkr/generic/implementing/interface/randomness_tr_def.h"

#include "nkr/randomness/native_dec.h"

#include "nkr/interface/randomness_i_def.h"

namespace nkr { namespace randomness {

    template <
        nkr::generic::implementing::interface::randomness_tr value_p,
        typename ...template_parameters_p,
        typename ...function_parameters_p
    > inline auto
        Value(function_parameters_p... function_arguments)
        noexcept
    {
        return nkr::interface::randomness_i<value_p>::template Value<template_parameters_p...>(function_arguments...);
    }

}}
