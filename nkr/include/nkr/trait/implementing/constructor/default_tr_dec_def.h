/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/trait/implementing/constructor/default_tr_dec.h"

namespace nkr { namespace interface {

    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i<nkr::trait::implementing::constructor::default_tg>::Is_Any()
        noexcept
    {
        return nkr::trait::implementing::constructor::default_tr<other_p>;
    }

    inline constexpr nkr::boolean::cpp_t
        template_i<trait::implementing::constructor::default_ttg>::Is_Implemented()
        noexcept
    {
        return true;
    }

}}
