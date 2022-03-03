/*
    Copyright 2022 r-neal-kelly
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

namespace nkr { namespace generic { namespace $negatable_tr {

    template <nkr::cpp::is_any_tr<nkr::generic::negatable_tg> type_p>
    class type_i_tag_sp
    {
    public:
        using type_t    = type_p;
        using of_t      = nkr::none::type_t;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any_General() noexcept;
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any_Specific() noexcept;

    public:
        template <typename ...>
        constexpr type_i_tag_sp(...) noexcept   = delete;
    };

}}}

namespace nkr { namespace interface {

    template <nkr::cpp::is_any_tr<nkr::generic::negatable_tg> type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::generic::$negatable_tr::type_i_tag_sp<type_p>;
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
