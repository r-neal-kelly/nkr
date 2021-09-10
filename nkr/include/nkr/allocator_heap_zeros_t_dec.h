/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/allocator_i.h"
#include "nkr/intrinsics.h"
#include "nkr/pointer_t.h"
#include "nkr/traits.h"

namespace nkr { namespace allocator {

    template <type_tr unit_p>
    class heap_zeros_t
    {
    public:
        using unit_t    = unit_p;

    public:
        bool_t  Allocate(pointer_t<unit_t>& units, count_t unit_count);
        bool_t  Reallocate(pointer_t<unit_t>& units, count_t new_unit_count);
        void_t  Deallocate(pointer_t<unit_t>& units);
    };
    static_assert(allocator_i<heap_zeros_t<word_t>>);

}}
