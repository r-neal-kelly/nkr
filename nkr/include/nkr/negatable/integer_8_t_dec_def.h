/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/negatable/integer_8_t_dec.h"

namespace nkr { namespace interface {

    template <typename other_p>
    inline constexpr boolean::cpp_t
        type_i<negatable::integer_8_tg>::Is_Any()
        noexcept
    {
        return negatable::integer_8_tr<other_p>;
    }

}}