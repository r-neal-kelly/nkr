/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsics.h"

#include "nkr/charcoder_i.h"
#include "nkr/charcoder/utf_8_t.h"

namespace nkr { namespace string {

    template <charcoder_i charcoder_p = charcoder::utf_8_t>
    class static_t
    {
    public:
    };

}}
