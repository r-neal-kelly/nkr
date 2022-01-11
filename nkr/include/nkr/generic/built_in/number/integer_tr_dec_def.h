/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/generic/built_in/number/integer_tr_dec.h"

namespace nkr { namespace interface {

    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i<nkr::generic::built_in::number::integer_tg>::Is_Any()
        noexcept
    {
        return nkr::generic::built_in::number::integer_tr<other_p>;
    }

}}

namespace nkr { namespace interface {

    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i<nkr::generic::built_in::number::integer_ttg>::Is_Any()
        noexcept
    {
        return nkr::generic::built_in::number::integer_ttr<other_p>;
    }

}}
