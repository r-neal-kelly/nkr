/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/intrinsics.h"

#include "nkr/allocator_err.h"

#include "nkr/array/stack_t.h"
#include "nkr/array/static_t.h"

#include "nkr/number/unsigned_arbitrary_t.h"

#include "doctest.h"

namespace nkr { namespace number {

    TEST_CASE("temp")
    {
        //static_assert((1 << (sizeof(u8_t) * 8 - 1)) == 0x80);
        //static_assert((1 << (sizeof(u32_t) * 8 - 1)) == 0x80000000);

        //array::stack_t<u8_t, 2> number_a = { u8_t(0xFF), u8_t(0xFF) };
        //array::stack_t<u8_t, 1> number_b = { u8_t(0xFF) };

        //maybe_t<allocator_err> err;
        //array::stack_t<u8_t, number_a.Capacity() + number_b.Capacity()> result; // apparently we can do this for multiplication also!

        //err = Add<u8_t>(array::static_t<u8_t>(number_a),
        //                array::static_t<u8_t>(number_b),
        //                result);
        //CHECK(err == allocator_err::NONE);
        //CHECK(result.Count() == 3);
        //CHECK(result[0] == 0xFE);
        //CHECK(result[1] == 0x00);
        //CHECK(result[2] == 0x01);

        //err = Subtract<u8_t>(array::static_t<u8_t>(number_a),
        //                     array::static_t<u8_t>(number_b),
        //                     result);
        //CHECK(err == allocator_err::NONE);
        //CHECK(result.Count() == 2);
        //CHECK(result[0] == 0x00);
        //CHECK(result[1] == 0xFF);

        //err = Subtract<u8_t>(array::static_t<u8_t>(number_b),
        //                     array::static_t<u8_t>(number_a),
        //                     result);
        //CHECK(err == allocator_err::NONE);
        //CHECK(result.Count() == 2);
        //CHECK(result[0] == 0x00);
        //CHECK(result[1] == 0x01);

        /*{
            array::stack_t<u8_t, 2> number_a = {
                u8_t(0x02),
                u8_t(0x22)
            };
            array::stack_t<u8_t, 2> number_b = {
                u8_t(0x44),
                u8_t(0x00)
            };
            array::stack_t<u8_t, 4> result;
            Karatsuba_Multiply<u8_t>(array::static_t<u8_t>(number_a),
                                     array::static_t<u8_t>(number_b),
                                     result);
            CHECK(result.Count() == 4);
            CHECK(result[0] == 0x88);
            CHECK(result[1] == 0x08);
            CHECK(result[2] == 0x09);
            CHECK(result[3] == 0x00);
        }
        {
            array::stack_t<u8_t, 2> number_a = {
                u8_t(0xFF),
                u8_t(0x00)
            };
            array::stack_t<u8_t, 2> number_b = {
                u8_t(0xFF),
                u8_t(0x00)
            };
            array::stack_t<u8_t, 4> result;
            Karatsuba_Multiply<u8_t>(array::static_t<u8_t>(number_a),
                                     array::static_t<u8_t>(number_b),
                                     result);
            CHECK(result.Count() == 4);
            CHECK(result[0] == 0x01);
            CHECK(result[1] == 0xFE);
            CHECK(result[2] == 0x00);
            CHECK(result[3] == 0x00);
        }
        {
            array::stack_t<u8_t, 2> number_a = { u8_t(0xFF), u8_t(0xFF) };
            array::stack_t<u8_t, 2> number_b = { u8_t(0xFF), u8_t(0xFF) };
            array::stack_t<u8_t, 4> result;
            Karatsuba_Multiply<u8_t>(array::static_t<u8_t>(number_a),
                                     array::static_t<u8_t>(number_b),
                                     result);
            CHECK(result.Count() == 4);
            CHECK(result[0] == 0x01);
            CHECK(result[1] == 0x00);
            CHECK(result[2] == 0xFE);
            CHECK(result[3] == 0xFF);
        }*/

        {
            array::stack_t<u16_t, 2> number_a = {
                u16_t(0xFFFF),
                u16_t(0x00FF)
            };
            array::stack_t<u16_t, 2> number_b = {
                u16_t(0xFFFF),
                u16_t(0x00FF)
            };
            array::stack_t<u16_t, 4> result;
            Karatsuba_Multiply<u16_t>(number_a, number_b, result);
            CHECK(result.Count() == 4);
            CHECK(result[0] == 0x0001);
            CHECK(result[1] == 0xFE00);
            CHECK(result[2] == 0xFFFF);
            CHECK(result[3] == 0x0000);
        }
        {
            array::stack_t<u8_t, 8> number_a = {
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF)
            };
            array::stack_t<u8_t, 8> number_b = {
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF)
            };
            array::stack_t<u8_t, 16> result;
            Karatsuba_Multiply<u8_t>(number_a, number_b, result);
            CHECK(result.Count() == 16);
            CHECK(result[0] == 0x01);
            CHECK(result[1] == 0x00);
            CHECK(result[2] == 0x00);
            CHECK(result[3] == 0x00);
            CHECK(result[4] == 0x00);
            CHECK(result[5] == 0x00);
            CHECK(result[6] == 0x00);
            CHECK(result[7] == 0x00);
            CHECK(result[8] == 0xFE);
            CHECK(result[9] == 0xFF);
            CHECK(result[10] == 0xFF);
            CHECK(result[11] == 0xFF);
            CHECK(result[12] == 0xFF);
            CHECK(result[13] == 0xFF);
            CHECK(result[14] == 0xFF);
            CHECK(result[15] == 0xFF);
        }
        {
            array::stack_t<u8_t, 8> number_a = {
                u8_t(0xbe),
                u8_t(0x40),
                u8_t(0xc2),
                u8_t(0xed),
                u8_t(0x5d),
                u8_t(0xd9),
                u8_t(0x7b),
                u8_t(0xbd)
            };
            array::stack_t<u8_t, 8> number_b = {
                u8_t(0x74),
                u8_t(0x6b),
                u8_t(0x8a),
                u8_t(0xc9),
                u8_t(0xac),
                u8_t(0xca),
                u8_t(0x3b),
                u8_t(0x24)
            };
            array::stack_t<u8_t, 16> result;
            Karatsuba_Multiply<u8_t>(number_a, number_b, result);
            CHECK(result.Count() == 16);
            CHECK(result[0] == 0x18);
            CHECK(result[1] == 0xc0);
            CHECK(result[2] == 0x80);
            CHECK(result[3] == 0x01);
            CHECK(result[4] == 0x24);
            CHECK(result[5] == 0xdc);
            CHECK(result[6] == 0xab);
            CHECK(result[7] == 0x35);
            CHECK(result[8] == 0x8d);
            CHECK(result[9] == 0xf7);
            CHECK(result[10] == 0xfb);
            CHECK(result[11] == 0xeb);
            CHECK(result[12] == 0x1f);
            CHECK(result[13] == 0xac);
            CHECK(result[14] == 0xd1);
            CHECK(result[15] == 0x1a);
        }
    }

}}
