/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/interface/template_i_identity_template_t_dec.h"

namespace nkr { namespace interface { namespace template_i_identity_template_t$ {

    template <
        template <typename ...> typename template_a_p,
        template <typename ...> typename template_b_p
    > class is_any_tmpl
    {
    public:
        template <typename ...arguments_p>
        class with_t
        {
        public:
            static constexpr nkr::boolean::cpp_t value =
                nkr::cpp::is_any_ttr<template_a_p, template_b_p, arguments_p...>;
        };
    };

}}}

namespace nkr { namespace interface {

    template <
        template <typename ...> typename    template_p,
        typename                            type_tag_p,
        template <typename ...> typename    template_tag_p,
        nkr::tuple::types_tr                default_arguments_p,
        typename                            min_argument_count_p,
        typename                            max_argument_count_p
    > template <template <typename ...> typename other_p>
        inline constexpr nkr::boolean::cpp_t
        template_i_identity_template_without_of_t<
            template_p,
            type_tag_p,
            template_tag_p,
            default_arguments_p,
            min_argument_count_p,
            max_argument_count_p
        >::Is_Any()
        noexcept
    {
        return default_arguments_p::template into_t<
            template_i_identity_template_t$::is_any_tmpl<other_p, template_t>::template with_t
        >::value;
    }

    template <
        template <typename ...> typename    template_p,
        typename                            type_tag_p,
        template <typename ...> typename    template_tag_p,
        nkr::tuple::types_tr                default_arguments_p,
        typename                            min_argument_count_p,
        typename                            max_argument_count_p
    > template <template <typename ...> typename other_p>
        static constexpr nkr::boolean::cpp_t
        template_i_identity_template_without_of_t<
            template_p,
            type_tag_p,
            template_tag_p,
            default_arguments_p,
            min_argument_count_p,
            max_argument_count_p
        >::Is_Any_Actual()
        noexcept
    {
        return Is_Any<other_p>();
    }

}}
