/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/built_in/forward_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/macros_dec.h"

namespace nkr { namespace interface {

    template <typename tag_p, template <typename ...> typename template_tag_p>
    class template_i_generic_aliases_t
    {
    public:
        template <typename ...parameters_p>
        using template_t        = tag_p;

        template <typename inner_p>
        using of_t              = tag_p;

        template <typename parameters_p>
        using of_tuple_t        = tag_p;

        template <typename ...parameters_p>
        using of_pack_t         = tag_p;

        using example_t         = tag_p;

        template <typename ...parameters_p>
        using actual_template_t = template_tag_p<parameters_p...>;

        template <typename inner_p>
        using actual_of_t       = actual_template_t<inner_p>;

        template <typename parameters_p>
        using actual_of_tuple_t = parameters_p::template into_t<actual_template_t>;

        template <typename ...parameters_p>
        using actual_of_pack_t  = actual_template_t<parameters_p...>;

        using actual_example_t  = actual_template_t<>;

    public:
        template <template <typename ...> typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any_Actual() noexcept;
    };

}}

#include "nkr/interface/template_i_generic_aliases_t_dec_def.h"
