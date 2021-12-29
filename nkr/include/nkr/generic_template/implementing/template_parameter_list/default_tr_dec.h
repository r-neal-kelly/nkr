/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/built_ins_dec.h"

namespace nkr { namespace generic_template { namespace implementing { namespace template_parameter_list {

    template <typename>
    struct  default_ttg {};

    template <template <template <typename ...> typename ...> typename template_p>
    concept default_tr =
        cpp::is_tr<template_p<>, template_p<>>;

}}}}

namespace nkr { namespace interface {

    template <>
    class template_i<nkr::generic_template::implementing::template_parameter_list::default_ttg>
    {
    public:
        template <typename of_p>
        using type_t    = nkr::none::type_t;

    public:
        template <typename ...>
        constexpr template_i(...) noexcept  = delete;
    };

}}

#include "nkr/generic_template/implementing/template_parameter_list/default_tr_dec_def.h"
