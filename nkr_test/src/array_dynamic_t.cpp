/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/array_dynamic_t.h"

#include "intrinsics.h"

namespace nkr {

    TEST_CASE("temp")
    {
        array_dynamic_t<int, allocator::heap_t<int>, math::fraction_t<17, 10>> array_dynamic;
        CHECK(array_dynamic.Grow_Rate() == static_cast<real_t>(1.7));
        CHECK(array_dynamic.Reserve(16));
    }

}
