/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include <tuple>

#include "nkr/built_in/forward_dec.h"
#include "nkr/constant/boolean/cpp_t_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/tuple/types_t_dec.h"

namespace nkr { namespace cpp { namespace tuple_t$ {

    template <typename type_p>
    class   is_tmpl;

    template <typename type_p>
    class   of_tmpl;

}}}

namespace nkr { namespace cpp {

    template <typename ...types_p>
    using   tuple_t =
        std::tuple<types_p...>;

    struct  tuple_tg    { class tag_lb; };

    template <typename ...>
    struct  tuple_ttg   {};

    template <typename type_p>
    concept tuple_tr =
        tuple_t$::is_tmpl<nkr::cpp::just_non_qualified_t<type_p>>::Value();

    template <template <typename ...> typename template_p>
    concept tuple_ttr =
        nkr::cpp::is_any_ttr<template_p, tuple_t>;

}}

namespace nkr { namespace cpp { namespace tuple_t$ {

    template <nkr::cpp::tuple_tr type_p>
    class type_i_type_sp
    {
    public:
        using type_t    = type_p;
        using of_t      = nkr::cpp::tuple_t$::of_tmpl<type_p>::type_t;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any_General() noexcept;
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any_Specific() noexcept;

    public:
        template <typename ...>
        constexpr type_i_type_sp(...) noexcept  = delete;
    };

    template <nkr::cpp::is_any_tr<nkr::cpp::tuple_tg> type_p>
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

    template <nkr::cpp::tuple_tr type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::cpp::tuple_t$::type_i_type_sp<type_p>;
    };

    template <nkr::cpp::is_any_tr<nkr::cpp::tuple_tg> type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::cpp::tuple_t$::type_i_tag_sp<type_p>;
    };

}}

namespace nkr { namespace cpp { namespace tuple_t$ {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::tuple_ttr<template_p>
    class template_i_template_sp
    {
    public:
        template <typename ...types_p>
        using template_t        = nkr::cpp::tuple_t<types_p...>;

        template <typename inner_p>
        using of_t              = template_t<inner_p>;

        template <nkr::tuple::types_tr parameters_p>
        using of_tuple_t        = parameters_p::template into_t<template_t>;

        template <typename ...parameters_p>
        using of_pack_t         = of_tuple_t<nkr::tuple::types_t<parameters_p...>>;

        using example_t         = of_t<nkr::positive::integer_t>;

        template <typename integer_p>
        using actual_template_t = template_t<integer_p>;

        template <typename inner_p>
        using actual_of_t       = of_t<inner_p>;

        template <nkr::tuple::types_tr parameters_p>
        using actual_of_tuple_t = of_tuple_t<parameters_p>;

        template <typename ...parameters_p>
        using actual_of_pack_t  = of_pack_t<parameters_p...>;

        using actual_example_t  = example_t;

        using type_tg           = nkr::cpp::tuple_tg;

        template <typename ...parameters_p>
        using template_ttg      = nkr::cpp::tuple_ttg<parameters_p...>;

    public:
        template <template <typename ...> typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;
        template <template <typename ...> typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any_Actual() noexcept;

    public:
        template <typename ...>
        constexpr template_i_template_sp(...) noexcept  = delete;
    };

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::cpp::tuple_ttg>
    class template_i_tag_sp :
        public template_i_template_sp<nkr::cpp::tuple_t>
    {
    public:
        template <typename ...parameters_p>
        using actual_template_t = template_ttg<parameters_p...>;

        template <typename inner_p>
        using actual_of_t       = actual_template_t<inner_p>;

        template <nkr::tuple::types_tr parameters_p>
        using actual_of_tuple_t = parameters_p::template into_t<actual_template_t>;

        template <typename ...parameters_p>
        using actual_of_pack_t  = actual_template_t<parameters_p...>;

        using actual_example_t  = actual_template_t<>;

    public:
        template <template <typename ...> typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any_Actual() noexcept;
    };

}}}

namespace nkr { namespace interface {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::tuple_ttr<template_p>
    class template_i_sp<template_p>
    {
    public:
        using type_t    = nkr::cpp::tuple_t$::template_i_template_sp<template_p>;
    };

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::cpp::tuple_ttg>
    class template_i_sp<template_p>
    {
    public:
        using type_t    = nkr::cpp::tuple_t$::template_i_tag_sp<template_p>;
    };

}}

#include "nkr/cpp/tuple_t_dec_def.h"
