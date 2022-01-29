/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/boolean/cpp_t_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/interface/template_i_generic_aliases_t_dec.h"
#include "nkr/none/type_t_dec.h"

namespace nkr { namespace generic { namespace implementing { namespace tag { namespace data {

    struct  min_tg  {};

    template <typename>
    struct  min_ttg {};

    template <typename type_p>
    concept min_tr =
        (requires { type_p::MIN_tg; });

    template <template <typename ...> typename template_p>
    concept min_ttr =
        min_tr<typename nkr::interface::template_i<template_p>::example_t>;

}}}}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::generic::implementing::tag::data::min_tg>
    {
    public:
        using type_t    = nkr::generic::implementing::tag::data::min_tg;
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
    class template_i<nkr::generic::implementing::tag::data::min_ttg> :
        public nkr::interface::template_i_generic_aliases_t<nkr::generic::implementing::tag::data::min_tg>
    {
    public:
        template <template <typename ...> typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr template_i(...) noexcept  = delete;
    };

}}

#include "nkr/generic/implementing/tag/data/min_tr_dec_def.h"
