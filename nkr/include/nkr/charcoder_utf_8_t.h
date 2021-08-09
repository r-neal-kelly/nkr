/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsic.h"

namespace nkr {

    class charcoder_utf_8_t
    {
    public:
        using unit_t    = u8_t;

    public:
        static constexpr const size_t   UNIT_SIZE = sizeof(unit_t);

    public:
        static inline size_t    unit_size();
    };

}

#include "nkr/charcoder_utf_8_t.inl"
