/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/none/type_t_dec.h"

namespace nkr { namespace interface {

    template <typename other_p>
    inline constexpr boolean::cpp_t
        type_i<none::type_tg>::Is_Any()
        noexcept
    {
        return none::type_tr<other_p>;
    }

}}
