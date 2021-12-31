/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/z_intrinsics.h"
#include "nkr/z_utils.h"

#include "nkr/z_array/stack_t.h"
#include "nkr/z_array/static_t.h"

#include "doctest.h"

namespace nkr { namespace array {

    TEST_CASE("temp")
    {
        stack_t<u8_t, 2> source = {
                u8_t(0xF0),
                u8_t(0x0F)
        };
        static_t<u8_t> array(source);
        {
            auto split = array.Split(1);
            CHECK(split[0].Count() == 1);
            CHECK(split[1].Count() == 1);

            CHECK(split[0][0] == 0xF0);
            CHECK(split[1][0] == 0x0F);
        }
        {
            auto split = array.Split(0);
            CHECK(split[0].Count() == 0);
            CHECK(split[1].Count() == 2);

            CHECK(split[1][0] == 0xF0);
            CHECK(split[1][1] == 0x0F);
        }
        {
            auto split = array.Split(2);
            CHECK(split[0].Count() == 2);
            CHECK(split[1].Count() == 0);

            CHECK(split[0][0] == 0xF0);
            CHECK(split[0][1] == 0x0F);
        }
    }

}}
