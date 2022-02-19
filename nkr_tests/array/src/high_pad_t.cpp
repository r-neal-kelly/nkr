/*
    Copyright 2022 r-neal-kelly
*/

#include "nkr/z_intrinsics.h"
#include "nkr/z_utils.h"

#include "nkr/z_array/high_pad_t.h"
#include "nkr/z_array/stack_t.h"

#include "doctest.h"

namespace nkr { namespace array {

    TEST_CASE("temp")
    {
        stack_t<u8_t, 2> source = {
                u8_t(0xF0),
                u8_t(0x0F)
        };
        high_pad_t<u8_t> array(source, u8_t(4), u8_t(0x00));
        CHECK(array.Count() == 4);
        CHECK(array[0] == 0xF0);
        CHECK(array[1] == 0x0F);
        CHECK(array[2] == 0x00);
        CHECK(array[3] == 0x00);
        {
            auto split = array.Split(2);
            CHECK(split[0].Count() == 2);
            CHECK(split[1].Count() == 2);

            CHECK(split[0][0] == 0xF0);
            CHECK(split[0][1] == 0x0F);
            CHECK(split[1][0] == 0x00);
            CHECK(split[1][1] == 0x00);
        }
        {
            auto split = array.Split(0);
            CHECK(split[0].Count() == 0);
            CHECK(split[1].Count() == 4);

            CHECK(split[1][0] == 0xF0);
            CHECK(split[1][1] == 0x0F);
            CHECK(split[1][2] == 0x00);
            CHECK(split[1][3] == 0x00);
        }
        {
            auto split = array.Split(4);
            CHECK(split[0].Count() == 4);
            CHECK(split[1].Count() == 0);

            CHECK(split[0][0] == 0xF0);
            CHECK(split[0][1] == 0x0F);
            CHECK(split[0][2] == 0x00);
            CHECK(split[0][3] == 0x00);
        }
    }

}}
