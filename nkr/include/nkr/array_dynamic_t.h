/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/allocator_heap_t.h"
#include "nkr/allocator_i.h"
#include "nkr/intrinsics.h"
#include "nkr/pointer_t.h"
#include "nkr/traits.h"

namespace nkr {

    template <
        type_tr     unit        = pointer_t<>::unit_t,
        allocator_i allocator   = allocator_heap_t<unit>
    > class array_dynamic_t
    {
    public:
        using unit_t        = unit;
        using allocator_t   = allocator;
    };

}

#include "nkr/array_dynamic_t.inl"
