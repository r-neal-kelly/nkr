/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/built_ins_dec.h"

namespace nkr { namespace generic_template { namespace implementing { namespace parameter_list {

    template <typename>
    struct  default_ttg {};

    template <template <typename ...> typename template_p>
    concept default_ttr =
        cpp::is_tr<template_p<>, template_p<>>;

}}}}

namespace nkr { namespace interface {

    template <>
    class template_i<nkr::generic_template::implementing::parameter_list::default_ttg>
    {
    public:
        template <typename inner_p>
        using of_t      = nkr::none::type_t;
        using example_t = nkr::none::type_t;

    public:
        template <template <typename ...> typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr template_i(...) noexcept  = delete;
    };

}}

#include "nkr/generic_template/implementing/parameter_list/default_tr_dec_def.h"
