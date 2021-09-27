/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/intrinsics.h"

#include "nkr/charcoder/utf_8_t.h"

#include "doctest.h"

namespace nkr { namespace charcoder {

    TEST_CASE("temp")
    {
        utf_8_t utf_8;
        CHECK(utf_8[0] == 0);
    }

}}
