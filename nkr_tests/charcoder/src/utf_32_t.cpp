/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/intrinsics.h"

#include "nkr/charcoder/utf_32_t.h"

#include "doctest.h"

namespace nkr { namespace charcoder {

    TEST_CASE("temp")
    {
        utf_32_be_t utf_32_be;
        CHECK(utf_32_be[0] == 0);
    }

}}
