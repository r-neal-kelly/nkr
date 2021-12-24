/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/negatable/real_32_t_dec.h"

namespace nkr { namespace interface {

    template <typename other_p>
    inline constexpr boolean::cpp_t
        type_i<negatable::real_32_tg>::Is_Any()
        noexcept
    {
        return negatable::real_32_tr<other_p>;
    }

}}
