/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/intrinsics.h"

#include "nkr/allocator_err.h"

#include "nkr/array/stack_t.h"
#include "nkr/array/static_t.h"

#include "nkr/hasher/fnv1a_t.h"

#include "doctest.h"

namespace nkr { namespace hasher {

    TEST_CASE("temp")
    {
        static_assert((1 << (sizeof(u8_t) * 8 - 1)) == 0x80);
        static_assert((1 << (sizeof(u32_t) * 8 - 1)) == 0x80000000);

        array::stack_t<u8_t, 2> number_a = { u8_t(0xFF), u8_t(0xFF) };
        array::stack_t<u8_t, 1> number_b = { u8_t(0xFF) };

        maybe_t<allocator_err> err;
        array::stack_t<u8_t, number_a.Capacity() + number_b.Capacity()> result; // apparently we can do this for multiplication also!

        err = Add<u8_t>(array::static_t<u8_t>(number_a),
                        array::static_t<u8_t>(number_b),
                        result);
        CHECK(err == allocator_err::NONE);
        CHECK(result.Count() == 3);
        CHECK(result[0] == 0xFE);
        CHECK(result[1] == 0x00);
        CHECK(result[2] == 0x01);

        err = Subtract<u8_t>(array::static_t<u8_t>(number_a),
                             array::static_t<u8_t>(number_b),
                             result);
        CHECK(err == allocator_err::NONE);
        CHECK(result.Count() == 2);
        CHECK(result[0] == 0x00);
        CHECK(result[1] == 0xFF);

        err = Subtract<u8_t>(array::static_t<u8_t>(number_b),
                             array::static_t<u8_t>(number_a),
                             result);
        CHECK(err == allocator_err::NONE);
        CHECK(result.Count() == 2);
        CHECK(result[0] == 0x00);
        CHECK(result[1] == 0x01);
    }

}}
