/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsics_dec.h"

#include "nkr/generic/built_in/number/enumeration/any_tr_dec.h"

namespace nkr { namespace generic { namespace built_in { namespace number {

    struct  enumeration_tg  {};

    template <typename>
    struct  enumeration_ttg {};

    template <typename type_p>
    concept enumeration_tr =
        enumeration::any_tr<type_p>;

    template <template <typename ...> typename template_p>
    concept enumeration_ttr =
        enumeration::any_ttr<template_p>;

}}}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::generic::built_in::number::enumeration_tg> :
        public type_i<nkr::generic::built_in::number::enumeration::any_tg>
    {
    public:
        using type_t    = nkr::generic::built_in::number::enumeration_tg;
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
