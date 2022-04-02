/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_a3dccb4d_8fa7_4761_ab36_902ee01c68bf
#define nkr_INCLUDE_GUARD_a3dccb4d_8fa7_4761_ab36_902ee01c68bf

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
        nkr::tuple::types_tr                example_arguments_p,
        typename                            min_argument_count_p,
        typename                            max_argument_count_p,
        typename                            type_tag_p,
        template <typename ...> typename    template_tag_p
    > inline constexpr nkr::positive::count_t
        template_i_identity_template_basic_t<
            template_p,
            example_arguments_p,
            min_argument_count_p,
            max_argument_count_p,
            type_tag_p,
            template_tag_p
        >::Min_Argument_Count()
        noexcept
    {
        return min_argument_count_p::Value();
    }

    template <
        template <typename ...> typename    template_p,
        nkr::tuple::types_tr                example_arguments_p,
        typename                            min_argument_count_p,
        typename                            max_argument_count_p,
        typename                            type_tag_p,
        template <typename ...> typename    template_tag_p
    > inline constexpr nkr::positive::count_t
        template_i_identity_template_basic_t<
            template_p,
            example_arguments_p,
            min_argument_count_p,
            max_argument_count_p,
            type_tag_p,
            template_tag_p
        >::Max_Argument_Count()
        noexcept
    {
        return max_argument_count_p::Value();
    }

    template <
        template <typename ...> typename    template_p,
        nkr::tuple::types_tr                example_arguments_p,
        typename                            min_argument_count_p,
        typename                            max_argument_count_p,
        typename                            type_tag_p,
        template <typename ...> typename    template_tag_p
    > inline constexpr nkr::positive::count_t
        template_i_identity_template_basic_t<
            template_p,
            example_arguments_p,
            min_argument_count_p,
            max_argument_count_p,
            type_tag_p,
            template_tag_p
        >::Actual_Min_Argument_Count()
        noexcept
    {
        return Min_Argument_Count();
    }

    template <
        template <typename ...> typename    template_p,
        nkr::tuple::types_tr                example_arguments_p,
        typename                            min_argument_count_p,
        typename                            max_argument_count_p,
        typename                            type_tag_p,
        template <typename ...> typename    template_tag_p
    > inline constexpr nkr::positive::count_t
        template_i_identity_template_basic_t<
            template_p,
            example_arguments_p,
            min_argument_count_p,
            max_argument_count_p,
            type_tag_p,
            template_tag_p
        >::Actual_Max_Argument_Count()
        noexcept
    {
        return Max_Argument_Count();
    }

    template <
        template <typename ...> typename    template_p,
        nkr::tuple::types_tr                example_arguments_p,
        typename                            min_argument_count_p,
        typename                            max_argument_count_p,
        typename                            type_tag_p,
        template <typename ...> typename    template_tag_p
    > template <
        template <typename ...> typename    other_p
    > inline constexpr nkr::boolean::cpp_t
        template_i_identity_template_basic_t<
            template_p,
            example_arguments_p,
            min_argument_count_p,
            max_argument_count_p,
            type_tag_p,
            template_tag_p
        >::Is_Any()
        noexcept
    {
        return example_arguments_t::template into_t<
            template_i_identity_template_t$::is_any_tmpl<other_p, template_t>::template with_t
        >::value;
    }

    template <
        template <typename ...> typename    template_p,
        nkr::tuple::types_tr                example_arguments_p,
        typename                            min_argument_count_p,
        typename                            max_argument_count_p,
        typename                            type_tag_p,
        template <typename ...> typename    template_tag_p
    > template <
        template <typename ...> typename    other_p
    > inline constexpr nkr::boolean::cpp_t
        template_i_identity_template_basic_t<
            template_p,
            example_arguments_p,
            min_argument_count_p,
            max_argument_count_p,
            type_tag_p,
            template_tag_p
        >::Is_Any_Actual()
        noexcept
    {
        return Is_Any<other_p>();
    }

}}

#endif
