/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/trait/non_type_tr_dec.h"

namespace nkr { namespace interface {

    template <typename other_p>
    inline constexpr boolean::cpp_t
        type_i<trait::non_type_tg>::Is_Any()
        noexcept
    {
        return trait::non_type_tr<other_p>;
    }

    inline constexpr boolean::cpp_t
        template_i<trait::non_type_ttg>::Is_Implemented()
        noexcept
    {
        return true;
    }

}}
