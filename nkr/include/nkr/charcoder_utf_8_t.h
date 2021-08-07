/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsic.h"

namespace nkr {

    class charcoder_utf_8_t
    {
    public:
        using value_t   = u8_t;

    public:
        static inline size_t    value_size();
    };

}

#include "nkr/charcoder_utf_8_t.inl"
