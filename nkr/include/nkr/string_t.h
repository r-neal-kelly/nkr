/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/charcoder_utf_8_t.h"
#include "nkr/intrinsics.h"
#include "nkr/string_dynamic_t.h"

namespace nkr {

    template <typename charcoder = charcoder_utf_8_t>
    using string_t  = string_dynamic_t<charcoder>;

}
