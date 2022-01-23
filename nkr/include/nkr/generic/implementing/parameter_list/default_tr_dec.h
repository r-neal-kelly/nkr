/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsics_dec.h"

namespace nkr { namespace generic { namespace implementing { namespace parameter_list {

    template <typename>
    struct  default_ttg     {};

    template <template <typename ...> typename>
    struct  default_tttg    {};

    template <template <typename ...> typename template_p>
    concept default_ttr =
        nkr::cpp::is_tr<template_p<>, template_p<>>;

    template <template <template <typename ...> typename ...> typename template_template_p>
    concept default_tttr =
        nkr::cpp::is_tr<template_template_p<>, template_template_p<>>;

}}}}

namespace nkr { namespace interface {

    template <>
    class template_i<nkr::generic::implementing::parameter_list::default_ttg>
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

#include "nkr/generic/implementing/parameter_list/default_tr_dec_def.h"