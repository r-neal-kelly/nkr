/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/boolean/cpp_t_dec.h"
#include "nkr/interface/template_i_dec.h"
#include "nkr/none/type_t_dec.h"

namespace nkr { namespace interface {

    template <template <typename ...> typename template_p>
    class   template_i;

}}

namespace nkr { namespace generic { namespace implementing { namespace interface {

    template <typename>
    struct  template_ttg    {};

    template <template <typename ...> typename template_p>
    concept template_ttr =
        nkr::interface::template_tr<nkr::interface::template_i<template_p>>;

}}}}

namespace nkr { namespace interface {

    template <>
    class template_i<nkr::generic::implementing::interface::template_ttg>
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

#include "nkr/generic/implementing/interface/template_tr_dec_def.h"
