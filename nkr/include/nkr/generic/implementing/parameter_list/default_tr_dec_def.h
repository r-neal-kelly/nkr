/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/generic/implementing/parameter_list/default_tr_dec.h"

namespace nkr { namespace generic { namespace implementing { namespace parameter_list { namespace default_tr$ {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::generic::implementing::parameter_list::default_ttg, nkr::none::type_t>
    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i_tag_sp<template_p>::Is_Any()
        noexcept
    {
        return nkr::generic::implementing::parameter_list::default_ttr<other_p>;
    }

}}}}}
