/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/built_in/forward_dec.h"
#include "nkr/generic/type_tr_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/interface/template_i_generic_aliases_t_dec.h"

namespace nkr { namespace generic {

    struct  non_type_tg     {};

    template <typename>
    struct  non_type_ttg    {};

    template <typename type_p>
    concept non_type_tr =
        !nkr::generic::type_tr<type_p>;

    template <template <typename ...> typename template_p>
    concept non_type_ttr =
        non_type_tr<typename interface::template_i<template_p>::example_t>;

}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::generic::non_type_tg>
    {
    public:
        using type_t    = nkr::generic::non_type_tg;
        using of_t      = nkr::none::type_t;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr type_i(...) noexcept  = delete;
    };

}}

namespace nkr { namespace interface {

    template <>
    class template_i<nkr::generic::non_type_ttg> :
        public nkr::interface::template_i_generic_aliases_t<nkr::generic::non_type_tg>
    {
    public:
        template <template <typename ...> typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr template_i(...) noexcept  = delete;
    };

}}

#include "nkr/generic/non_type_tr_dec_def.h"
