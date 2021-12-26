/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/negatable/integer_16_t_dec.h"

namespace nkr { namespace interface {

    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i<nkr::negatable::integer_16_tg>::Is_Any()
        noexcept
    {
        return nkr::negatable::integer_16_tr<other_p>;
    }

}}
