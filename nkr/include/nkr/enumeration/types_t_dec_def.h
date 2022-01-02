/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/enumeration/types_t_dec.h"

namespace nkr { namespace interface {

    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i<nkr::enumeration::types_tg>::Is_Any()
        noexcept
    {
        return nkr::enumeration::types_tr<other_p>;
    }

}}

namespace nkr { namespace interface {

    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i<nkr::enumeration::types_ttg>::Is_Any()
        noexcept
    {
        return nkr::enumeration::types_ttr<other_p>;
    }

}}
