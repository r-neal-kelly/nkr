/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/cpp_def.h"
#include "nkr/intrinsics_def.h"

#include "nkr/interface/template_i_dec.h"

namespace nkr { namespace interface {

    template <template <typename ...> typename template_p>
    inline constexpr cpp::bool_t
        template_i<template_p>::Is_Implemented()
        noexcept
    {
        static_assert(false, "you need to implement or include a template_i for this template");
    }

}}
