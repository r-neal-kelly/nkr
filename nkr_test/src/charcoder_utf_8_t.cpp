/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/charcoder_utf_8_t.h"

#include "intrinsics.h"

namespace nkr { namespace charcoder {

    TEST_CASE("temp")
    {
        utf_8_t utf_8;
        CHECK(utf_8[0] == 0);
    }

}}
