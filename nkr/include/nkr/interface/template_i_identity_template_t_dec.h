/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/built_in/forward_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/tuple/types_t_dec.h"

namespace nkr { namespace interface {

    template <
        template <typename ...> typename    template_p,
        nkr::tuple::types_tr                default_arguments_p,
        typename                            min_argument_count_p    = nkr::constant::positive::count_t<default_arguments_p::Count()>,
        typename                            max_argument_count_p    = min_argument_count_p,
        typename                            type_tag_p              = nkr::none::type_t,
        template <typename ...> typename    template_tag_p          = nkr::none::template_t
    > class template_i_identity_template_basic_t
    {
    public:
        static_assert(default_arguments_p::Count() >= min_argument_count_p::Value() &&
                      default_arguments_p::Count() <= max_argument_count_p::Value());

    public:
        template <typename ...parameters_p>
            requires (sizeof...(parameters_p) >= min_argument_count_p::Value() && sizeof...(parameters_p) <= max_argument_count_p::Value())
        using template_t        = nkr::tuple::types_t<parameters_p...>::template into_t<template_p>;

        template <nkr::tuple::types_tr parameters_p>
            requires (parameters_p::Count() >= min_argument_count_p::Value() && parameters_p::Count() <= max_argument_count_p::Value())
        using of_tuple_t        = parameters_p::template into_t<template_p>;

        template <typename ...parameters_p>
            requires (sizeof...(parameters_p) >= min_argument_count_p::Value() && sizeof...(parameters_p) <= max_argument_count_p::Value())
        using of_pack_t         = of_tuple_t<nkr::tuple::types_t<parameters_p...>>;

        using example_t         = default_arguments_p::template into_t<template_p>;

        template <typename ...parameters_p>
        using actual_template_t = template_t<parameters_p...>;

        template <nkr::tuple::types_tr parameters_p>
            requires (parameters_p::Count() >= min_argument_count_p::Value() && parameters_p::Count() <= max_argument_count_p::Value())
        using actual_of_tuple_t = of_tuple_t<parameters_p>;

        template <typename ...parameters_p>
            requires (sizeof...(parameters_p) >= min_argument_count_p::Value() && sizeof...(parameters_p) <= max_argument_count_p::Value())
        using actual_of_pack_t  = of_pack_t<parameters_p...>;

        using actual_example_t  = example_t;

        using type_tg           = type_tag_p;

        template <typename ...parameters_p>
        using template_ttg      = template_tag_p<parameters_p...>;

    public:
        static constexpr nkr::positive::count_t Min_Argument_Count() noexcept;
        static constexpr nkr::positive::count_t Max_Argument_Count() noexcept;
        static constexpr nkr::positive::count_t Actual_Min_Argument_Count() noexcept;
        static constexpr nkr::positive::count_t Actual_Max_Argument_Count() noexcept;

        template <template <typename ...> typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;
        template <template <typename ...> typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any_Actual() noexcept;

    public:
        template <typename ...>
        constexpr template_i_identity_template_basic_t(...) noexcept    = delete;
    };

    /*
        We need to have this separate for the sake of types such as nkr::array::cpp_t
        which cannot define defaults for their subsequent parameters. Overshadowing
        these aliases causes compiler error in all major compilers, so it's a no go.
    */
    template <template <typename ...> typename template_p>
    class template_i_identity_template_of_t
    {
    public:
        template <typename inner_p>
        using of_t          = template_p<inner_p>;

        template <typename inner_p>
        using actual_of_t   = template_p<inner_p>;

    public:
        template <typename ...>
        constexpr template_i_identity_template_of_t(...) noexcept   = delete;
    };

    template <
        template <typename ...> typename    template_p,
        nkr::tuple::types_tr                default_arguments_p,
        typename                            min_argument_count_p    = nkr::constant::positive::count_t<default_arguments_p::Count()>,
        typename                            max_argument_count_p    = min_argument_count_p,
        typename                            type_tag_p              = nkr::none::type_t,
        template <typename ...> typename    template_tag_p          = nkr::none::template_t
    > class template_i_identity_template_t :
        public template_i_identity_template_basic_t<
            template_p,
            default_arguments_p,
            min_argument_count_p,
            max_argument_count_p,
            type_tag_p,
            template_tag_p
        >,
        public template_i_identity_template_of_t<
            template_p
        >
    {
    public:
        template <typename ...>
        constexpr template_i_identity_template_t(...) noexcept  = delete;
    };

}}

#include "nkr/interface/template_i_identity_template_t_dec_def.h"
