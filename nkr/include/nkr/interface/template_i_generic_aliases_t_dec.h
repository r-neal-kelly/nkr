/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/tuple/types_t_dec.h"

namespace nkr { namespace interface {

    template <typename tag_p>
    class template_i_generic_aliases_t
    {
    public:
        template <typename ...>
        using template_t    = tag_p;

        template <typename inner_p>
        using of_t          = tag_p;

        template <nkr::tuple::types_tr parameters_p>
        using of_tuple_t    = tag_p;

        template <typename ...parameters_p>
        using of_pack_t     = tag_p;

        using example_t     = tag_p;
    };

}}

#include "nkr/interface/template_i_generic_aliases_t_dec_def.h"
