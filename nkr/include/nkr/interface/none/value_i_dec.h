/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/built_in/forward_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/generic/implementing/constructor/default_tr_dec.h"
#include "nkr/generic/type_tr_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/positive/integer_t_dec.h"
#include "nkr/tuple/types_t_dec.h"

namespace nkr { namespace interface { namespace none { namespace $value_i {

    template <typename type_p>
    concept aliases_i =
        nkr::cpp::is_any_tr<type_p, nkr::interface::none::value_i<typename type_p::type_t>> &&
        nkr::generic::type_tr<typename type_p::type_t> &&

        nkr::cpp::is_tr<typename type_p::value_t, nkr::cpp::just_non_qualified_t<typename type_p::type_t>>;

    template <typename type_p>
    concept static_constexpr_functions_i = requires
    {
        { type_p::Value() } -> nkr::cpp::is_just_non_qualified_tr<typename type_p::value_t>;
    };

    template <typename type_p>
    concept objects_i =
        !nkr::generic::implementing::constructor::default_tr<type_p>;

}}}}

namespace nkr { namespace interface { namespace none {

    template <typename value_p>
    using   value_i =
        value_i_sp<value_p>::type_t;

    struct  value_tg    {};

    template <typename>
    struct  value_ttg   {};

    template <typename type_p>
    concept value_tr =
        $value_i::aliases_i<type_p> &&
        $value_i::static_constexpr_functions_i<type_p> &&
        $value_i::objects_i<type_p>;

    template <template <typename ...> typename template_p>
    concept value_ttr =
        nkr::cpp::is_any_ttr<template_p, value_i, nkr::positive::integer_t>;

}}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::interface::none::value_tg>
    {
    public:
        using type_t    = nkr::interface::none::value_tg;
        using of_t      = nkr::none::type_t;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr type_i(...) noexcept  = delete;
    };

    template <nkr::interface::none::value_tr type_p>
    class type_i<type_p> :
        public type_i<nkr::interface::none::value_tg>
    {
    public:
        using type_t    = type_p;
        using of_t      = type_p::type_t;
    };

}}

namespace nkr { namespace interface {

    template <>
    class template_i<nkr::interface::none::value_ttg>
    {
    public:
        template <typename type_p>
        using template_t    = nkr::interface::none::value_i<type_p>;

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
        requires nkr::interface::none::value_ttr<template_p>
    class template_i<template_p> :
        public template_i<nkr::interface::none::value_ttg>
    {
    public:
    };

}}

#include "nkr/interface/none/value_i_dec_def.h"
