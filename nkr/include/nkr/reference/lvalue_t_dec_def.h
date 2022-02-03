/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/reference/lvalue_t_dec.h"

namespace nkr { namespace interface {

    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i<nkr::reference::lvalue_tg>::Is_Any()
        noexcept
    {
        return nkr::reference::lvalue_tr<other_p>;
    }

}}

namespace nkr { namespace interface {

    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i<nkr::reference::lvalue_ttg>::Is_Any()
        noexcept
    {
        return nkr::reference::lvalue_ttr<other_p>;
    }

}}
