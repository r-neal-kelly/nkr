/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/built_in/forward_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/cpp/generic/randomness/generator_tr_dec.h"
#include "nkr/generic/built_in/boolean_tr_dec.h"
#include "nkr/generic/built_in/number/integer_tr_dec.h"
#include "nkr/generic/built_in/number/real_tr_dec.h"
#include "nkr/generic/built_in/pointer_tr_dec.h"
#include "nkr/generic/implementing/constructor/default_tr_dec.h"
#include "nkr/generic/type_tr_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/positive/integer_t_dec.h"
#include "nkr/randomness/generator/software/default_t_dec.h"
#include "nkr/tr_dec.h"
#include "nkr/tuple/types_t_dec.h"

namespace nkr { namespace interface { namespace randomness { namespace value_i$ {

    template <typename type_p>
    concept aliases_i =
        nkr::generic::type_tr<typename type_p::type_t> &&

        nkr::cpp::is_tr<typename type_p::value_t, nkr::cpp::just_non_qualified_t<typename type_p::type_t>>;

    template <typename type_p>
    concept static_functions_i =
        (requires(nkr::randomness::generator::software::default_t generator)
    {
        { type_p::template Value<>() }          -> nkr::cpp::is_tr<typename type_p::value_t>;
        { type_p::template Value<>(generator) } -> nkr::cpp::is_tr<typename type_p::value_t>;
    });

    template <typename type_p>
    concept objects_i =
        !nkr::generic::implementing::constructor::default_tr<type_p>;

}}}}

namespace nkr { namespace interface { namespace randomness {

    struct  value_tg    { class tag_lb; };

    template <typename ...>
    struct  value_ttg   {};

    template <typename type_p>
    concept value_tr =
        nkr::cpp::is_any_tr<type_p, value_i<typename type_p::type_t>> &&
        value_i$::aliases_i<type_p> &&
        value_i$::static_functions_i<type_p> &&
        value_i$::objects_i<type_p>;

    template <template <typename ...> typename template_p>
    concept value_ttr =
        nkr::cpp::is_any_ttr<template_p, value_i, nkr::positive::integer_t>;

}}}

namespace nkr { namespace interface { namespace randomness { namespace value_i$ {

    template <nkr::interface::randomness::value_tr type_p>
    class type_i_type_sp
    {
    public:
        using type_t    = type_p;
        using of_t      = type_t::value_t;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any_General() noexcept;
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any_Specific() noexcept;

    public:
        template <typename ...>
        constexpr type_i_type_sp(...) noexcept  = delete;
    };

    template <nkr::cpp::is_any_tr<nkr::interface::randomness::value_tg> type_p>
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

    template <nkr::interface::randomness::value_tr type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::interface::randomness::value_i$::type_i_type_sp<type_p>;
    };

    template <nkr::cpp::is_any_tr<nkr::interface::randomness::value_tg> type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::interface::randomness::value_i$::type_i_tag_sp<type_p>;
    };

}}

namespace nkr { namespace interface { namespace randomness { namespace value_i$ {

    template <template <typename ...> typename template_p>
        requires nkr::interface::randomness::value_ttr<template_p>
    class template_i_template_sp
    {
    public:
        template <typename type_p>
        using template_t        = nkr::interface::randomness::value_i<type_p>;

        template <typename inner_p>
        using of_t              = template_t<inner_p>;

        template <nkr::tuple::types_tr parameters_p>
            requires (parameters_p::Count() == 1)
        using of_tuple_t        = parameters_p::template into_t<template_t>;

        template <typename ...parameters_p>
        using of_pack_t         = of_tuple_t<nkr::tuple::types_t<parameters_p...>>;

        using example_t         = of_t<nkr::positive::integer_t>;

        template <typename type_p>
        using actual_template_t = template_t<type_p>;

        template <typename inner_p>
        using actual_of_t       = of_t<inner_p>;

        template <nkr::tuple::types_tr parameters_p>
        using actual_of_tuple_t = of_tuple_t<parameters_p>;

        template <typename ...parameters_p>
        using actual_of_pack_t  = of_pack_t<parameters_p...>;

        using actual_example_t  = example_t;

        using type_tg           = nkr::interface::randomness::value_tg;

        template <typename ...parameters_p>
        using template_tg       = nkr::interface::randomness::value_ttg<parameters_p...>;

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
        requires nkr::cpp::is_any_ttr<template_p, nkr::interface::randomness::value_ttg>
    class template_i_tag_sp :
        public template_i_template_sp<nkr::interface::randomness::value_i>
    {
    public:
        template <typename ...parameters_p>
        using actual_template_t = nkr::interface::randomness::value_ttg<parameters_p...>;

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

}}}}

namespace nkr { namespace interface {

    template <template <typename ...> typename template_p>
        requires nkr::interface::randomness::value_ttr<template_p>
    class template_i_sp<template_p>
    {
    public:
        using type_t    = nkr::interface::randomness::value_i$::template_i_template_sp<template_p>;
    };

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::interface::randomness::value_ttg>
    class template_i_sp<template_p>
    {
    public:
        using type_t    = nkr::interface::randomness::value_i$::template_i_tag_sp<template_p>;
    };

}}

#include "nkr/interface/randomness/value_i_dec_def.h"
