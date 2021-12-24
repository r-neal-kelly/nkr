/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/trait/negatable/integer_tr_dec.h"

namespace nkr { namespace interface {

    template <typename other_p>
    inline constexpr boolean::cpp_t
        type_i<trait::negatable::integer_tg>::Is_Any()
        noexcept
    {
        return trait::negatable::integer_tr<other_p>;
    }

    inline constexpr boolean::cpp_t
        template_i<trait::negatable::integer_ttg>::Is_Implemented()
        noexcept
    {
        return true;
    }

}}
