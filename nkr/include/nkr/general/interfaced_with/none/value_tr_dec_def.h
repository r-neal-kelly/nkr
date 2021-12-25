/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/general/interfaced_with/none/value_tr_dec.h"

namespace nkr { namespace interface {

    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i<nkr::general::interfaced_with::none::value_tg>::Is_Any()
        noexcept
    {
        return nkr::general::interfaced_with::none::value_tr<other_p>;
    }

    inline constexpr nkr::boolean::cpp_t
        template_i<nkr::general::interfaced_with::none::value_ttg>::Is_Implemented()
        noexcept
    {
        return true;
    }

}}
