/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include <bit>

#include "nkr/z_intrinsics_dec.h"

namespace nkr {

    static_assert(CHAR_BIT == 8, "This library requires that there be 8 bits in a byte.");

    static_assert(sizeof(r32_t) == sizeof(u32_t), "r32_t must be the same size as u32_t");
    static_assert(sizeof(r64_t) == sizeof(u64_t), "r64_t must be the same size as u64_t");

    static_assert(sizeof(void_t*) == sizeof(word_t), "void_t* must be the same size as word_t");
    static_assert(sizeof(address_t) == sizeof(word_t), "address_t must be the same size as word_t");

    static_assert(std::endian::native == std::endian::big || std::endian::native == std::endian::little,
                  "must be a big endian or little endian machine.");

}
