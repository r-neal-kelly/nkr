/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/boolean/cpp_t_dec.h"

namespace nkr { namespace interface {

    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i<nkr::boolean::cpp_tg>::Is_Any()
        noexcept
    {
        return nkr::boolean::cpp_tr<other_p>;
    }

}}
