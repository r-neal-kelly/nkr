/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/general/positive/any_tr_dec.h"

namespace nkr { namespace interface {

    template <typename other_p>
    inline constexpr boolean::cpp_t
        type_i<general::positive::any_tg>::Is_Any()
        noexcept
    {
        return general::positive::any_tr<other_p>;
    }

    inline constexpr boolean::cpp_t
        template_i<general::positive::any_ttg>::Is_Implemented()
        noexcept
    {
        return true;
    }

}}
