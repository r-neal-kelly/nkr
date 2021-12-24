/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/pointer/cpp_t_dec.h"

namespace nkr { namespace interface {

    template <typename other_p>
    inline constexpr boolean::cpp_t
        type_i<pointer::cpp_tg>::Is_Any()
        noexcept
    {
        return pointer::cpp_tr<other_p>;
    }

    inline constexpr boolean::cpp_t
        template_i<pointer::cpp_ttg>::Is_Implemented()
        noexcept
    {
        return true;
    }

}}
