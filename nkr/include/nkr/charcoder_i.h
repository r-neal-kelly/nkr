/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include <concepts>

#include "nkr/intrinsic.h"

namespace nkr {

    template <typename T>
    concept charcoder_i = requires(T v)
    {
        { v.value_size() } -> std::same_as<size_t>;
    };

}
