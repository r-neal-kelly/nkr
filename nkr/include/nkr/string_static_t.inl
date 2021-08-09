/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/string_static_t.h"

namespace nkr {

    template <typename charcoder>
    requires charcoder_i<charcoder>
        inline size_t string_static_t<charcoder>::unit_size()
    {
        return charcoder_t::unit_size();
    }

    template <typename charcoder>
    requires charcoder_i<charcoder>
        inline string_static_t<charcoder>::string_static_t() :
        units(nullptr)
    {
    }

}
