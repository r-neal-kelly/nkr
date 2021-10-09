/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/intrinsics.h"

#include "nkr/charcoder/ascii_t.h"

#include "nkr/string/dynamic_t.h"

#include "doctest.h"

namespace nkr { namespace string {

    TEST_CASE("temp")
    {
        dynamic_t<charcoder::ascii_t> dynamic("test");
        CHECK(dynamic.Point_Count() == 5);
    }

}}
