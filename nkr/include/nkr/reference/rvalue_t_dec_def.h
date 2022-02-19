/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/reference/rvalue_t_dec.h"

namespace nkr { namespace interface {

    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i<nkr::reference::rvalue_tg>::Is_Any()
        noexcept
    {
        return nkr::reference::rvalue_tr<other_p>;
    }

}}

namespace nkr { namespace interface {

    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i<nkr::reference::rvalue_ttg>::Is_Any()
        noexcept
    {
        return nkr::reference::rvalue_ttr<other_p>;
    }

}}
