/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/intrinsics.h"

#include "nkr/charcoder/ascii_t.h"

#include "doctest.h"

namespace nkr { namespace charcoder {

    TEST_CASE("temp")
    {
        ascii_t ascii;
        CHECK(ascii[0] == 0);
    }

}}
