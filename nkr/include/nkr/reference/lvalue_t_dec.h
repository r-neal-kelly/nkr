/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/built_in/forward_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/tuple/types_t_dec.h"

namespace nkr { namespace reference {

    template <typename type_p>
    using   lvalue_t =
        type_p&;

    struct  lvalue_tg   {};

    template <typename>
    struct  lvalue_ttg  {};

    template <typename type_p>
    concept lvalue_tr =
        nkr::cpp::lvalue_reference_tr<type_p>;

    template <template <typename ...> typename template_p>
    concept lvalue_ttr =
        nkr::cpp::is_any_ttr<template_p, lvalue_t, nkr::positive::integer_t>;

}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::reference::lvalue_tg>
    {
    public:
        using type_t    = nkr::reference::lvalue_tg;
        using of_t      = nkr::none::type_t;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr type_i(...) noexcept  = delete;
    };

    template <nkr::reference::lvalue_tr type_p>
    class type_i<type_p> :
        public type_i<nkr::reference::lvalue_tg>
    {
    public:
        using type_t    = type_p;
        using of_t      = nkr::cpp::reference_value_t<type_t>;
    };

}}

namespace nkr { namespace interface {

    template <>
    class template_i<nkr::reference::lvalue_ttg>
    {
    public:
        template <typename type_p>
        using template_t    = nkr::reference::lvalue_t<type_p>;

        template <typename inner_p>
        using of_t          = template_t<inner_p>;

        template <nkr::tuple::types_tr parameters_p>
            requires (parameters_p::Count() == 1)
        using of_tuple_t    = parameters_p::template into_t<template_t>;

        template <typename ...parameters_p>
        using of_pack_t     = of_tuple_t<nkr::tuple::types_t<parameters_p...>>;

        using example_t     = of_t<nkr::positive::integer_t>;

    public:
        template <template <typename ...> typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr template_i(...) noexcept  = delete;
    };

    template <template <typename ...> typename template_p>
        requires nkr::reference::lvalue_ttr<template_p>
    class template_i<template_p> :
        public template_i<nkr::reference::lvalue_ttg>
    {
    public:
    };

}}

#include "nkr/reference/lvalue_t_dec_def.h"
