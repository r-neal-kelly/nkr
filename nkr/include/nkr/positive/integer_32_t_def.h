/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/interface/type_i_def.h"

#include "nkr/positive/integer_32_t_dec.h"

namespace nkr { namespace interface {

    template <typename other_p>
    inline constexpr boolean::cpp_t
        type_i<positive::integer_32_tg>::Is_Any()
        noexcept
    {
        return positive::integer_32_tr<other_p>;
    }

}}

namespace nkr { namespace positive {



}}
