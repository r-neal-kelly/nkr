/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/charcoder_utf_32_t.h"

#include "intrinsics.h"

namespace nkr { namespace charcoder {

    TEST_CASE("temp")
    {
        utf_32_be_t utf_32_be;
        CHECK(utf_32_be[0] == 0);
        CHECK(utf_32_be.Is_Well_Formed());
    }

}}