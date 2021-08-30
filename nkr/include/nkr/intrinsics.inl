/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsics.h"

namespace nkr {

    static_assert(CHAR_BIT == 8, "This library requires that there be 8 bits in a byte.");

    static_assert(sizeof(r32_t) == sizeof(u32_t), "r32_t must be the same size as u32_t");
    static_assert(sizeof(r64_t) == sizeof(u64_t), "r64_t must be the same size as u64_t");

}
