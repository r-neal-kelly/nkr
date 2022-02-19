/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/generic/non_type_tr_dec.h"

namespace nkr { namespace interface {

    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i<nkr::generic::non_type_tg>::Is_Any()
        noexcept
    {
        return nkr::generic::non_type_tr<other_p>;
    }

}}

namespace nkr { namespace interface {

    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i<nkr::generic::non_type_ttg>::Is_Any()
        noexcept
    {
        return nkr::generic::non_type_ttr<other_p>;
    }

}}
