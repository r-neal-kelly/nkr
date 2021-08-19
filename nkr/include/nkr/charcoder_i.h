/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsics.h"

namespace nkr {

    template <typename T>
    concept charcoder_i = requires(T v)
    {
        typename T::unit_t;

        { v.unit_size() } -> std::same_as<size_t>;
    };

}
