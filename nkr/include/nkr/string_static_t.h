/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/charcoder_i.h"
#include "nkr/charcoder_utf_8_t.h"
#include "nkr/intrinsic.h"
#include "nkr/maybe_pointer_t.h"

namespace nkr {

    template <typename charcoder = charcoder_utf_8_t>
        requires charcoder_i<charcoder>
    class string_static_t
    {
    public:
        using charcoder_t = charcoder;

    protected:
        some_t<typename charcoder_t::value_t*>  c_string;

    public:
        string_static_t() = default;
    };

}

#include "nkr/string_static_t.inl"
