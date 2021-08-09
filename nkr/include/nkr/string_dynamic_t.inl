/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/string_dynamic_t.h"

namespace nkr {

    template <typename charcoder>
    requires charcoder_i<charcoder>
    inline string_dynamic_t<charcoder>::string_dynamic_t() :
        string_static_t<charcoder>()
    {
    }

}
