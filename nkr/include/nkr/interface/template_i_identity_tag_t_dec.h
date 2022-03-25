/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/built_in/forward_dec.h"
#include "nkr/cpp_dec.h"

namespace nkr { namespace tuple {

    template <typename ...types_p>
    class types_t;

}}

namespace nkr { namespace interface {

    template <typename template_specialization_p>
    class template_i_identity_tag_t :
        public template_specialization_p
    {
    public:
        template <typename ...parameters_p>
        using actual_template_t             = template_specialization_p::template template_ttg<parameters_p...>;

        using actual_default_arguments_t    = nkr::tuple::types_t<>;

        template <typename inner_p>
        using actual_of_t                   = actual_template_t<inner_p>;

        template <typename parameters_p>
        using actual_of_tuple_t             = parameters_p::template into_t<actual_template_t>;

        template <typename ...parameters_p>
        using actual_of_pack_t              = actual_template_t<parameters_p...>;

        using actual_example_t              = actual_default_arguments_t::template into_t<actual_template_t>;

    public:
        static constexpr nkr::positive::count_t Actual_Min_Argument_Count() noexcept;
        static constexpr nkr::positive::count_t Actual_Max_Argument_Count() noexcept;

        template <template <typename ...> typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any_Actual() noexcept;

    public:
        template <typename ...>
        constexpr template_i_identity_tag_t(...) noexcept   = delete;
    };

}}

#include "nkr/interface/template_i_identity_tag_t_dec_def.h"
