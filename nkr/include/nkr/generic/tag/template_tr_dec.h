/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/built_in/forward_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/generic/tag_tr_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/interface/template_i_generic_aliases_t_dec.h"

namespace nkr { namespace generic { namespace tag {

    struct  template_tg     { class tag_lb; class generic_lb; };

    template <typename>
    struct  template_ttg    {};

    template <typename type_p>
    concept template_tr =
        nkr::generic::tag_tr<type_p> &&
        (requires { typename type_p::template_lb; });

    template <template <typename ...> typename template_p>
    concept template_ttr =
        template_tr<template_p<nkr::none::type_t>>;

}}}

namespace nkr { namespace generic { namespace tag { namespace template_tr$ {

    template <nkr::cpp::is_any_tr<nkr::generic::tag::template_tg> type_p>
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

}}}}

namespace nkr { namespace interface {

    template <nkr::cpp::is_any_tr<nkr::generic::tag::template_tg> type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::generic::tag::template_tr$::type_i_tag_sp<type_p>;
    };

}}

namespace nkr { namespace generic { namespace tag { namespace template_tr$ {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::generic::tag::template_ttg, nkr::none::type_t>
    class template_i_tag_sp :
        public nkr::interface::template_i_generic_aliases_t<nkr::generic::tag::template_tg>
    {
    public:
        template <template <typename ...> typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr template_i_tag_sp(...) noexcept   = delete;
    };

}}}}

namespace nkr { namespace interface {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::generic::tag::template_ttg, nkr::none::type_t>
    class template_i_sp<template_p>
    {
    public:
        using type_t    = nkr::generic::tag::template_tr$::template_i_tag_sp<template_p>;
    };

}}

#include "nkr/generic/tag/template_tr_dec_def.h"
