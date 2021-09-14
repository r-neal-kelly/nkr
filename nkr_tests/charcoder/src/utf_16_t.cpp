/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/charcoder_utf_16_t.h"
#include "nkr/intrinsics.h"

#include "doctest.h"

namespace nkr { namespace charcoder {

    TEST_CASE("temp")
    {
        utf_16_t utf_16;
        CHECK(utf_16[0] == 0);
    }

}}
