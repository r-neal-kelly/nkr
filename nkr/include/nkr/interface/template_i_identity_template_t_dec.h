/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/cpp_dec.h"
#include "nkr/tuple/types_t_dec.h"

namespace nkr { namespace interface {

    template <
        template <typename ...> typename    template_p,
        typename                            type_tag_p,
        template <typename ...> typename    template_tag_p,
        typename                            example_p,
        nkr::positive::count_t              min_argument_count_p,
        nkr::positive::count_t              max_argument_count_p    = min_argument_count_p
    > class template_i_identity_template_t
    {
    public:
        template <typename ...parameters_p>
            requires (sizeof...(parameters_p) >= min_argument_count_p && sizeof...(parameters_p) <= max_argument_count_p)
        using template_t        = nkr::tuple::types_t<parameters_p...>::template into_t<template_p>;

        template <nkr::tuple::types_tr parameters_p>
            requires (parameters_p::Count() >= min_argument_count_p && parameters_p::Count() <= max_argument_count_p)
        using of_tuple_t        = parameters_p::template into_t<template_p>;

        template <typename ...parameters_p>
            requires (sizeof...(parameters_p) >= min_argument_count_p && sizeof...(parameters_p) <= max_argument_count_p)
        using of_pack_t         = of_tuple_t<nkr::tuple::types_t<parameters_p...>>;

        using example_t         = example_p;

        template <typename ...parameters_p>
        using actual_template_t = template_t<parameters_p...>;

        template <nkr::tuple::types_tr parameters_p>
            requires (parameters_p::Count() >= min_argument_count_p && parameters_p::Count() <= max_argument_count_p)
        using actual_of_tuple_t = of_tuple_t<parameters_p>;

        template <typename ...parameters_p>
            requires (sizeof...(parameters_p) >= min_argument_count_p && sizeof...(parameters_p) <= max_argument_count_p)
        using actual_of_pack_t  = of_pack_t<parameters_p...>;

        using actual_example_t  = example_t;

        using type_tg           = type_tag_p;

        template <typename ...parameters_p>
        using template_ttg      = template_tag_p<parameters_p...>;

    public:
        template <typename ...>
        constexpr template_i_identity_template_t(...) noexcept  = delete;
    };

}}

#include "nkr/interface/template_i_identity_template_t_dec_def.h"
