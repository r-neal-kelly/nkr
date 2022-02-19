/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/none/pointer_t_dec.h"

namespace nkr { namespace interface {

    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i<nkr::none::pointer_tg>::Is_Any()
        noexcept
    {
        return nkr::none::pointer_tr<other_p>;
    }

}}
