/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/cpp/randomness/generator/hardware_t_dec.h"

namespace nkr { namespace interface {

    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i<nkr::cpp::randomness::generator::hardware_tg>::Is_Any()
        noexcept
    {
        return nkr::cpp::randomness::generator::hardware_tr<other_p>;
    }

}}
