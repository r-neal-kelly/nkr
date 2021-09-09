/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/charcoder_i.h"
#include "nkr/charcoder_utf_8_t.h"
#include "nkr/intrinsics.h"
#include "nkr/string_static_t.h"

namespace nkr {

    template <charcoder_i charcoder_p = charcoder::utf_8_t>
    class string_dynamic_t :
        public string_static_t<charcoder_p>
    {
    public:
        string_dynamic_t();
    };

}

#include "nkr/string_dynamic_t.inl"
