/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsics.h"
#include "nkr/maybe_pointer_t.h"

#include "nkr/charcoder_i.h"
#include "nkr/charcoder/utf_8_t.h"

namespace nkr {

    template <typename charcoder = charcoder_utf_8_t>
    requires charcoder_i<charcoder>
    class string_static_t
    {
    public:
        using charcoder_t   = charcoder;

    public:
        static size_t   unit_size();

    protected:
        //some_t<typename charcoder_t::unit_t*>   units;

    public:
        string_static_t();

    public:

    };

}

#include "nkr/string_static_t.inl"
