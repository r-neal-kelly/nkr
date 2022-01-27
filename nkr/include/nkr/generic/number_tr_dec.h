/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/generic/number/any_tr_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/none/type_t_dec.h"

namespace nkr { namespace generic {

    struct  number_tg   {};

    template <typename>
    struct  number_ttg  {};

    template <typename type_p>
    concept number_tr =
        nkr::generic::number::any_tr<type_p>;

    template <template <typename ...> typename template_p>
    concept number_ttr =
        nkr::generic::number::any_ttr<template_p>;

}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::generic::number_tg> :
        public type_i<nkr::generic::number::any_tg>
    {
    public:
        using type_t    = nkr::generic::number_tg;
        using of_t      = nkr::none::type_t;
    };

}}

namespace nkr { namespace interface {

    template <>
    class template_i<nkr::generic::number_ttg> :
        public template_i<nkr::generic::number::any_ttg>
    {
    public:
    };

}}

#include "nkr/generic/number_tr_dec_def.h"
