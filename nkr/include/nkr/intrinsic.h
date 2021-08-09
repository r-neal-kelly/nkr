/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include <cassert>
#include <concepts>
#include <cstdint>
#include <limits>
#include <memory>
#include <utility>

namespace nkr {

    using u8_t      = uint8_t;
    using u16_t     = uint16_t;
    using u32_t     = uint32_t;
    using u64_t     = uint64_t;

    using s8_t      = int8_t;
    using s16_t     = int16_t;
    using s32_t     = int32_t;
    using s64_t     = int64_t;

    using void_t    = void;
    using bool_t    = bool;
    using byte_t    = u8_t;
    using word_t    = std::size_t;

    using size_t    = word_t;
    using count_t   = word_t;
    using index_t   = word_t;

    using address_t = uintptr_t;

}
