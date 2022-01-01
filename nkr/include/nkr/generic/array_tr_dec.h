/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsics_dec.h"

#include "nkr/generic/array/any_tr_dec.h"

namespace nkr { namespace generic {

    struct  array_tg    {};

    template <typename>
    struct  array_ttg   {};

    template <typename type_p>
    concept array_tr =
        array::any_tr<type_p>;

    template <template <typename ...> typename template_p>
    concept array_ttr =
        array::any_ttr<template_p>;

}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::generic::array_tg> :
        public type_i<nkr::generic::array::any_tg>
    {
    public:
        using type_t    = nkr::generic::array_tg;
    };

}}

namespace nkr { namespace interface {

    template <>
    class template_i<nkr::generic::array_ttg> :
        public template_i<nkr::generic::array::any_ttg>
    {
    public:
    };

}}

#include "nkr/generic/array_tr_dec_def.h"
