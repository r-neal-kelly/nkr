/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsics.h"

namespace nkr {

    static_assert(CHAR_BIT == 8, "This library requires that there be 8 bits in a byte.");

    static_assert(sizeof(f32_t) == sizeof(u32_t), "f32_t must be the same size as u32_t");
    static_assert(sizeof(f64_t) == sizeof(u64_t), "f64_t must be the same size as u64_t");

}
