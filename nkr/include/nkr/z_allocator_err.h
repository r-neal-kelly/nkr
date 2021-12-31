/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/z_intrinsics.h"
#include "nkr/z_macros.h"

#include "nkr/z_enumeration/errors_t.h"

namespace nkr {

    class allocator_err :
        public enumeration::errors_t<signed_word_t, 0>
    {
    public:
        using base_t    = enumeration::errors_t<signed_word_t, 0>;

    public:
        enum : value_t
        {
            NONE            = base_t::NONE,

            OUT_OF_MEMORY,
        };

    public:
        nkr_DEFINE_INHERITANCE_WRAPPER_CTORS_AND_DTOR(allocator_err, base_t);
    };

}
