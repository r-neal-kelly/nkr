/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/built_ins_dec.h"

namespace nkr { namespace interface {

    template <nkr::cpp::just_non_qualified_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i<type_p>::Is_Any()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}

namespace nkr { namespace interface {

    template <template <typename ...> typename template_p>
    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i<template_p>::Is()
        noexcept
    {
        return nkr::cpp::is_any_ttr<template_t, other_p, typename nkr::interface::default_child_of_i<template_t>::child_t>;
    }

}}
