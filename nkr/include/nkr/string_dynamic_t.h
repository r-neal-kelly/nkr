/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/charcoder_i.h"
#include "nkr/charcoder_utf_8_t.h"
#include "nkr/intrinsic.h"
#include "nkr/string_static_t.h"

namespace nkr {

    template <typename charcoder = charcoder_utf_8_t>
    requires charcoder_i<charcoder>
    class string_dynamic_t :
        public string_static_t<charcoder>
    {
    public:
        string_dynamic_t();
    };

}

#include "nkr/string_dynamic_t.inl"
