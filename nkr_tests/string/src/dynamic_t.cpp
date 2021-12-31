/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/z_intrinsics.h"

#include "nkr/z_charcoder/ascii_t.h"
#include "nkr/z_charcoder/utf_8_t.h"
#include "nkr/z_charcoder/utf_16_t.h"
#include "nkr/z_charcoder/utf_32_t.h"

#include "nkr/z_string/dynamic_t.h"

#include "doctest.h"

namespace nkr { namespace string {

    TEST_CASE("temp")
    {
        dynamic_t<charcoder::ascii_t> dynamic("test");
        CHECK(dynamic.Point_Count() == 5);
    }

}}
