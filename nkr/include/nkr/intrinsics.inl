/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsics.h"

namespace nkr {

#if defined(nkr_IS_32_BIT)
    static_assert(sizeof(std::size_t) == sizeof(u32_t), "word_t must be the same size as u32_t.");
#elif defined(nkr_IS_64_BIT)
    static_assert(sizeof(std::size_t) == sizeof(u64_t), "word_t must be the same size as u64_t.");
#endif

}
