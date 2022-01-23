/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsics_dec.h"
#include "nkr/tuple/types_t_dec.h"

namespace nkr { namespace tuple { namespace $templates_t {

    template <typename type_p>
    class   is_tmpl;

}}}

namespace nkr { namespace tuple {

    template <template <typename ...> typename ...templates_p>
    class   templates_t;

    struct  templates_tg    {};

    template <template <typename ...> typename>
    struct  templates_tttg  {};

    template <typename type_p>
    concept templates_tr =
        $templates_t::is_tmpl<nkr::cpp::just_non_qualified_t<type_p>>::Value();

    template <template <template <typename ...> typename ...> typename template_template_p>
    concept templates_tttr =
        nkr::cpp::is_any_tttr<template_template_p, templates_t, nkr::pointer::cpp_t>;

}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::tuple::templates_tg>
    {
    public:
        using type_t    = nkr::tuple::templates_tg;
        using of_t      = nkr::none::type_t;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr type_i(...) noexcept  = delete;
    };

    template <nkr::tuple::templates_tr type_p>
    class type_i<type_p> :
        public type_i<nkr::tuple::templates_tg>
    {
    public:
        using type_t    = type_p;
        using of_t      = nkr::none::type_t;
    };

}}

namespace nkr { namespace tuple { namespace $templates_t {

    template <typename type_p>
    class is_tmpl :
        public nkr::boolean::cpp_c<false>
    {
    public:
    };

    template <template <typename ...> typename head_p, template <typename ...> typename ...tail_p>
    class is_tmpl<templates_t<head_p, tail_p...>> :
        public nkr::boolean::cpp_c<true>
    {
    public:
    };

}}}

namespace nkr { namespace tuple { namespace $templates_t {

    template <typename tuple_p, nkr::positive::index_t index_p>
    class unit_t;

    template <template <typename ...> typename head_p, template <typename ...> typename ...tail_p>
    class unit_t<templates_t<head_p, tail_p...>, 0>
    {
    public:
        template <typename ...types_p>
        using template_t    = nkr::interface::template_i<head_p>::template from_tuple_t<nkr::tuple::types_t<types_p...>>;
    };

    template <template <typename ...> typename head_p, template <typename ...> typename ...tail_p, nkr::positive::index_t index_p>
    class unit_t<templates_t<head_p, tail_p...>, index_p> :
        public unit_t<templates_t<tail_p...>, index_p - 1>
    {
    public:
    };

}}}

namespace nkr { namespace tuple {

    template <template <typename ...> typename head_p, template <typename ...> typename ...tail_p>
    class templates_t<head_p, tail_p...>
    {
    public:
        template <typename ...types_p>
        using head_t    = nkr::interface::template_i<head_p>::template from_tuple_t<nkr::tuple::types_t<types_p...>>;
        using tail_t    = templates_t<tail_p...>;
        template <nkr::cpp::constant_of_tr<nkr::positive::index_t> index_p, typename ...types_p>
        using at_t      = $templates_t::unit_t<templates_t, index_p::Value()>::template template_t<types_p...>;

    public:
        static constexpr nkr::positive::count_t Count() noexcept;

    public:
        template <typename ...>
        constexpr templates_t(...) noexcept = delete;
    };

}}

#include "nkr/tuple/templates_t_dec_def.h"
