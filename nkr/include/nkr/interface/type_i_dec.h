/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/built_in/forward_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/generic/implementing/constructor/default_tr_dec.h"
#include "nkr/generic/type_tr_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/tuple/types_t_dec.h"

namespace nkr { namespace interface { namespace $type_i {

    template <typename type_p>
    concept aliases_i = requires
    {
        typename type_p::type_t;
        typename type_p::of_t;
        nkr::cpp::just_non_qualified_tr<typename type_p::type_t>;
        nkr::generic::type_tr<typename type_p::type_t>;
    };

    template <typename type_p>
    concept static_constexpr_functions_i = requires
    {
        { type_p::template Is_Any<typename type_p::type_t>() }  -> nkr::cpp::is_tr<nkr::boolean::cpp_t>;
    };

    template <typename type_p>
    concept objects_i =
        !nkr::generic::implementing::constructor::default_tr<type_p>;

}}}

namespace nkr { namespace interface {

    template <typename type_p>
    class   type_i;

    struct  type_tg     {};

    template <typename>
    struct  type_ttg    {};

    template <typename type_p>
    concept type_tr =
        nkr::cpp::is_any_tr<type_p, type_i<typename type_p::type_t>> &&
        $type_i::aliases_i<type_p> &&
        $type_i::static_constexpr_functions_i<type_p> &&
        $type_i::objects_i<type_p>;

    template <template <typename ...> typename template_p>
    concept type_ttr =
        nkr::cpp::is_any_ttr<template_p, type_i, nkr::none::type_t>;

}}

namespace nkr { namespace interface { namespace $type_i {

    template <typename type_p>
    concept inner_type_tr = requires
    {
        typename type_p::type_t;
    };

    template <typename type_p>
    concept inner_value_tr = requires
    {
        typename type_p::value_t;
    };

    template <typename type_p>
    concept inner_unit_tr = requires
    {
        typename type_p::unit_t;
    };

    template <typename type_p>
    concept just_inner_type_tr =
        inner_type_tr<type_p> &&
        !inner_value_tr<type_p> &&
        !inner_unit_tr<type_p>;

    template <typename type_p>
    concept just_inner_value_tr =
        !inner_type_tr<type_p> &&
        inner_value_tr<type_p> &&
        !inner_unit_tr<type_p>;

    template <typename type_p>
    concept just_inner_unit_tr =
        !inner_type_tr<type_p> &&
        !inner_value_tr<type_p> &&
        inner_unit_tr<type_p>;

    template <typename type_p>
    class default_inner_tmpl
    {
    public:
        using type_t    = nkr::none::type_t;
    };

    template <just_inner_type_tr type_p>
    class default_inner_tmpl<type_p>
    {
    public:
        using type_t    = type_p::type_t;
    };

    template <just_inner_value_tr type_p>
    class default_inner_tmpl<type_p>
    {
    public:
        using type_t    = type_p::value_t;
    };

    template <just_inner_unit_tr type_p>
    class default_inner_tmpl<type_p>
    {
    public:
        using type_t    = type_p::unit_t;
    };

    template <typename type_p>
    using default_inner_t   = default_inner_tmpl<type_p>::type_t;

}}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::interface::type_tg>
    {
    public:
        using type_t    = nkr::interface::type_tg;
        using of_t      = nkr::none::type_t;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr type_i(...) noexcept  = delete;
    };

    template <nkr::interface::type_tr type_p>
    class type_i<type_p> :
        public type_i<nkr::interface::type_tg>
    {
    public:
        using type_t    = type_p;
        using of_t      = type_t::type_t;
    };

}}

namespace nkr { namespace interface {

    template <>
    class template_i<nkr::interface::type_ttg>
    {
    public:
        template <typename type_p>
        using template_t    = nkr::interface::type_i<type_p>;

        template <typename inner_p>
        using of_t          = template_t<inner_p>;

        template <nkr::tuple::types_tr parameters_p>
            requires (parameters_p::Count() == 1)
        using of_tuple_t    = parameters_p::template into_t<template_t>;

        template <typename ...parameters_p>
        using of_pack_t     = of_tuple_t<nkr::tuple::types_t<parameters_p...>>;

        using example_t     = of_t<nkr::none::type_t>;

    public:
        template <template <typename ...> typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr template_i(...) noexcept  = delete;
    };

    template <template <typename ...> typename template_p>
        requires nkr::interface::type_ttr<template_p>
    class template_i<template_p> :
        public template_i<nkr::interface::type_ttg>
    {
    public:
    };

}}

#include "nkr/interface/type_i_dec_def.h"
