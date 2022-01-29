/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/generic/negatable/any_tr_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/interface/template_i_generic_aliases_t_dec.h"
#include "nkr/none/type_t_dec.h"

namespace nkr { namespace generic {

    struct  negatable_tg    {};

    template <typename>
    struct  negatable_ttg   {};

    template <typename type_p>
    concept negatable_tr =
        nkr::generic::negatable::any_tr<type_p>;

    template <template <typename ...> typename template_p>
    concept negatable_ttr =
        nkr::generic::negatable::any_ttr<template_p>;

}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::generic::negatable_tg> :
        public type_i<nkr::generic::negatable::any_tg>
    {
    public:
        using type_t    = nkr::generic::negatable_tg;
        using of_t      = nkr::none::type_t;
    };

}}

namespace nkr { namespace interface {

    template <>
    class template_i<nkr::generic::negatable_ttg> :
        public template_i<nkr::generic::negatable::any_ttg>
    {
    public:
    };

}}

#include "nkr/generic/negatable_tr_dec_def.h"
