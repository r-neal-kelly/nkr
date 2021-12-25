/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/general/implementing/constructor/default_tr_dec.h"

namespace nkr { namespace interface {

    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i<nkr::general::implementing::constructor::default_tg>::Is_Any()
        noexcept
    {
        return nkr::general::implementing::constructor::default_tr<other_p>;
    }

    inline constexpr nkr::boolean::cpp_t
        template_i<general::implementing::constructor::default_ttg>::Is_Implemented()
        noexcept
    {
        return true;
    }

}}
