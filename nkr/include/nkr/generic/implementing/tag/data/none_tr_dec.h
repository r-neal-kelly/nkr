/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/built_in/forward_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/interface/template_i_generic_aliases_t_dec.h"

namespace nkr { namespace generic { namespace implementing { namespace tag { namespace data {

    struct  none_tg     {};

    template <typename>
    struct  none_ttg    {};

    template <typename type_p>
    concept none_tr =
        (requires { type_p::NONE_tg; });

    template <template <typename ...> typename template_p>
    concept none_ttr =
        none_tr<typename nkr::interface::template_i<template_p>::example_t>;

}}}}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::generic::implementing::tag::data::none_tg>
    {
    public:
        using type_t    = nkr::generic::implementing::tag::data::none_tg;
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
    class template_i<nkr::generic::implementing::tag::data::none_ttg> :
        public nkr::interface::template_i_generic_aliases_t<nkr::generic::implementing::tag::data::none_tg>
    {
    public:
        template <template <typename ...> typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr template_i(...) noexcept  = delete;
    };

}}

#include "nkr/generic/implementing/tag/data/none_tr_dec_def.h"
