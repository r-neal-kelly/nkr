/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/interface/template_i_generic_aliases_t_dec.h"

namespace nkr { namespace interface {

    template <typename tag_p, template <typename ...> typename template_tag_p>
    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i_generic_aliases_t<tag_p, template_tag_p>::Is_Any_Actual()
        noexcept
    {
        return nkr::cpp::is_any_ttr<other_p, actual_template_t>;
    }

}}
