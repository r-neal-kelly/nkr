/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/generic/number/any_tr_dec.h"

namespace nkr { namespace interface {

    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i<nkr::generic::number::any_tg>::Is_Any()
        noexcept
    {
        return nkr::generic::number::any_tr<other_p>;
    }

}}

namespace nkr { namespace interface {

    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i<nkr::generic::number::any_ttg>::Is_Any()
        noexcept
    {
        return nkr::generic::number::any_ttr<other_p>;
    }

}}
