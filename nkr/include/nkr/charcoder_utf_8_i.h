/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/charcoder_utf_8_t.h"

namespace nkr {

    inline size_t charcoder_utf_8_t::value_size()
    {
        return sizeof(value_t);
    }

}
