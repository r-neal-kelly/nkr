/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/some_t_dec.h"

namespace nkr {

    template <typename other_p>
    inline constexpr c_bool_t
        type_traits_i<some_tg>::Is_Any()
    {
        return $some_t::any_tr<other_p> || is_any_tr<other_p, some_tg>;
    }

    inline constexpr c_bool_t
        template_traits_i<some_ttg>::Is_Implemented()
    {
        return true;
    }

}
