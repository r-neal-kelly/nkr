/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/intrinsics.h"

#include "nkr/charcoder/ascii_t.h"
#include "nkr/charcoder/utf_8_t.h"
#include "nkr/charcoder/utf_16_t.h"
#include "nkr/charcoder/utf_32_t.h"

#include "nkr/string/stack_t.h"

#include "doctest.h"

namespace nkr { namespace string {

    TEST_CASE("temp")
    {
        stack_t<charcoder::ascii_t, 5> stack("test");
        CHECK(stack.Point_Count() == 5);
    }

}}
