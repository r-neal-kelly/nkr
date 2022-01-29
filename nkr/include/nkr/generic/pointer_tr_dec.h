/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/generic/pointer/any_tr_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/interface/template_i_generic_aliases_t_dec.h"
#include "nkr/none/type_t_dec.h"

namespace nkr { namespace generic {

    struct  pointer_tg  {};

    template <typename>
    struct  pointer_ttg {};

    template <typename type_p>
    concept pointer_tr =
        nkr::generic::pointer::any_tr<type_p>;

    template <template <typename ...> typename template_p>
    concept pointer_ttr =
        nkr::generic::pointer::any_ttr<template_p>;

}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::generic::pointer_tg> :
        public type_i<nkr::generic::pointer::any_tg>
    {
    public:
        using type_t    = nkr::generic::pointer_tg;
        using of_t      = nkr::none::type_t;
    };

}}

namespace nkr { namespace interface {

    template <>
    class template_i<nkr::generic::pointer_ttg> :
        public template_i<nkr::generic::pointer::any_ttg>
    {
    public:
    };

}}

#include "nkr/generic/pointer_tr_dec_def.h"
