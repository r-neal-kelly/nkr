/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/generic/built_in/number/enumeration/any_tr_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/none/type_t_dec.h"

namespace nkr { namespace generic { namespace built_in { namespace number {

    struct  enumeration_tg  {};

    template <typename>
    struct  enumeration_ttg {};

    template <typename type_p>
    concept enumeration_tr =
        nkr::generic::built_in::number::enumeration::any_tr<type_p>;

    template <template <typename ...> typename template_p>
    concept enumeration_ttr =
        nkr::generic::built_in::number::enumeration::any_ttr<template_p>;

}}}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::generic::built_in::number::enumeration_tg> :
        public type_i<nkr::generic::built_in::number::enumeration::any_tg>
    {
    public:
        using type_t    = nkr::generic::built_in::number::enumeration_tg;
        using of_t      = nkr::none::type_t;
    };

}}

namespace nkr { namespace interface {

    template <>
    class template_i<nkr::generic::built_in::number::enumeration_ttg> :
        public template_i<nkr::generic::built_in::number::enumeration::any_ttg>
    {
    public:
    };

}}

#include "nkr/generic/built_in/number/enumeration_tr_dec_def.h"
