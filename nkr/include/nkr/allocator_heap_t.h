/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsic.h"
#include "nkr/pointer_t.h"
#include "nkr/traits.h"

namespace nkr {

    template <sized_tr unit = pointer_t<>::unit_t>
    class allocator_heap_t
    {
    public:
        using unit_t    = unit;

    public:
        static bool_t   allocate(pointer_t<unit_t>& units, count_t unit_count);
        static bool_t   reallocate(pointer_t<unit_t>& units, count_t new_unit_count);
        static void_t   deallocate(pointer_t<unit_t>& units);
    };

}

#include "nkr/allocator_heap_t.inl"
