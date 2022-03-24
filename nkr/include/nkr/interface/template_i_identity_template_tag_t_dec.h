/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/cpp_dec.h"
#include "nkr/tuple/types_t_dec.h"

namespace nkr { namespace interface {

    template <typename template_specialization_p>
    class template_i_identity_template_tag_t :
        public template_specialization_p
    {
    public:
        template <typename ...parameters_p>
        using actual_template_t = template_specialization_p::template template_ttg<parameters_p...>;

        template <typename inner_p>
        using actual_of_t       = actual_template_t<inner_p>;

        template <nkr::tuple::types_tr parameters_p>
        using actual_of_tuple_t = parameters_p::template into_t<actual_template_t>;

        template <typename ...parameters_p>
        using actual_of_pack_t  = actual_template_t<parameters_p...>;

        using actual_example_t  = actual_template_t<>;

    public:
        template <typename ...>
        constexpr template_i_identity_template_tag_t(...) noexcept  = delete;
    };

}}

#include "nkr/interface/template_i_identity_template_tag_t_dec_def.h"
