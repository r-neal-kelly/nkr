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
        CHECK(array_dynamic.Capacity(16));
        array_dynamic.Push(8);
        array_dynamic.Push(16);
        array_dynamic.Push(32);
        array_dynamic.Push(64);
        CHECK(array_dynamic.At(0) == 8);
        CHECK(array_dynamic.At(1) == 16);
        CHECK(array_dynamic.At(2) == 32);
        CHECK(array_dynamic.At(3) == 64);
        while (array_dynamic.Count() > 0) {
            array_dynamic.Pop();
        }
        array_dynamic.Fit();
        CHECK(array_dynamic.Capacity() == 0);
        CHECK(array_dynamic.Pointer() == nullptr);
    }

}
