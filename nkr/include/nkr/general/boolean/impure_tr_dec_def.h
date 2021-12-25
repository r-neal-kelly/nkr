/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/general/boolean/impure_tr_dec.h"

namespace nkr { namespace interface {

    template <typename other_p>
    inline constexpr boolean::cpp_t
        type_i<general::boolean::impure_tg>::Is_Any()
        noexcept
    {
        return general::boolean::impure_tr<other_p>;
    }

    inline constexpr boolean::cpp_t
        template_i<general::boolean::impure_ttg>::Is_Implemented()
        noexcept
    {
        return true;
    }

}}
