/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/built_in/forward_dec.h"
#include "nkr/constant/boolean/cpp_t_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/generic/implementing/constructor/default_tr_dec.h"
#include "nkr/interface/forward_dec.h"

namespace nkr { namespace interface { namespace $template_i {

    template <typename type_p>
    class is_tmpl :
        public nkr::constant::boolean::cpp_t<false>
    {
    public:
    };

    template <template <typename ...> typename template_p>
    class is_tmpl<template_i<template_p>> :
        public nkr::constant::boolean::cpp_t<true>
    {
    public:
    };

    template <typename ...>
    class dummy_template_t
    {
    public:
    };

    template <typename type_p>
    concept aliases_i =
        nkr::cpp::is_ttr<type_p::template template_t, type_p::template template_t> &&
        nkr::cpp::is_ttr<type_p::template of_t, type_p::template of_t> &&
        nkr::cpp::is_ttr<type_p::template of_tuple_t, type_p::template of_tuple_t> &&
        nkr::cpp::is_ttr<type_p::template of_pack_t, type_p::template of_pack_t> &&
        nkr::cpp::is_tr<typename type_p::example_t, typename type_p::example_t>;

    template <typename type_p>
    concept static_constexpr_functions_i = requires
    {
        { type_p::template Is_Any<dummy_template_t>() } -> nkr::cpp::is_tr<nkr::boolean::cpp_t>;
    };

    template <typename type_p>
    concept objects_i =
        !nkr::generic::implementing::constructor::default_tr<type_p>;

}}}

namespace nkr { namespace interface {

    template <template <typename ...> typename template_p>
    class   template_i;

    struct  template_tg     {};

    template <template <typename ...> typename>
    struct  template_tttg   {};

    template <typename type_p>
    concept template_tr =
        $template_i::is_tmpl<type_p>::Value() &&
        $template_i::aliases_i<type_p> &&
        $template_i::static_constexpr_functions_i<type_p> &&
        $template_i::objects_i<type_p>;

}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::interface::template_tg>
    {
    public:
        using type_t    = nkr::interface::template_tg;
        using of_t      = nkr::none::type_t;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr type_i(...) noexcept  = delete;
    };

    template <nkr::interface::template_tr type_p>
    class type_i<type_p> :
        public type_i<nkr::interface::template_tg>
    {
    public:
        using type_t    = type_p;
        using of_t      = nkr::none::type_t;
    };

}}

#include "nkr/interface/template_i_dec_def.h"
