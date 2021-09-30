/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/intrinsics.h"
#include "nkr/macros.h"

#include "nkr/enumeration/types_t.h"

#include "doctest.h"

namespace nkr {

    TEST_CASE("temp")
    {
        enumeration::types_t<int> types;
        static_assert(enumeration::types_t<int>::NONE == -1);
    }

}
