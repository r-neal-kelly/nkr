/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsics_def.h"

#include "nkr/cpp_dec.h"

namespace nkr { namespace cpp {

    inline constexpr bool_t
        Is_Big_Endian()
    {
        return std::endian::native == std::endian::big;
    }

    inline constexpr bool_t
        Is_Little_Endian()
    {
        return std::endian::native == std::endian::little;
    }

    inline constexpr count_t
        Byte_Bit_Count()
    {
        return CHAR_BIT;
    }

}}
