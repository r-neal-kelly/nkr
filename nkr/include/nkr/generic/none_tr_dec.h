/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/generic/none/any_tr_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/none/type_t_dec.h"

namespace nkr { namespace generic {

    struct  none_tg     {};

    template <typename>
    struct  none_ttg    {};

    template <typename type_p>
    concept none_tr =
        nkr::generic::none::any_tr<type_p>;

    template <template <typename ...> typename template_p>
    concept none_ttr =
        nkr::generic::none::any_ttr<template_p>;

}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::generic::none_tg> :
        public type_i<nkr::generic::none::any_tg>
    {
    public:
        using type_t    = nkr::generic::none_tg;
        using of_t      = nkr::none::type_t;
    };

}}

namespace nkr { namespace interface {

    template <>
    class template_i<nkr::generic::none_ttg> :
        public template_i<nkr::generic::none::any_ttg>
    {
    public:
    };

}}

#include "nkr/generic/none_tr_dec_def.h"
