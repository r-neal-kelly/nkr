/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsics.h"
#include "nkr/traits.h"
#include "nkr/utils.h"

#include "nkr/charcoder_i.h"
#include "nkr/charcoder/ascii_t.h"
#include "nkr/charcoder/utf_8_t.h"
#include "nkr/charcoder/utf_16_t.h"
#include "nkr/charcoder/utf_32_t.h"

#include "nkr/string/stack_t.h"

namespace nkr {

    void_t Test()
    {
        1 + 1 == 2;
    }

    template <count_t point_count_p, charcoder_i charcoder_p>
    string::stack_t<point_count_p, charcoder_p> Random_Stack_String()
    {
        if constexpr (is_tr<charcoder_p, charcoder::ascii_t>) {
            return string::stack_t<point_count_p, charcoder::ascii_t>();
        } else {
            static_assert(false, "undefined Random_Stack_String() for passed charcoder");
        }
    }

}
