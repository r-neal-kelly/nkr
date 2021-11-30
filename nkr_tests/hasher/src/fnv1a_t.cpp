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
            




            constexpr bool test = u64_t(0xFFFFFF) * u64_t(0xFFFFFF) == u64_t(0xFFFFFE000001);

            array::stack_t<u8_t, 4> number_a = {
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0x00)
            };
            array::stack_t<u8_t, 4> number_b = {
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0xFF),
                u8_t(0x00)
            };
            array::stack_t<u8_t, 8> result;


            array::static_t<u8_t> a0(maybe_t<pointer_t<u8_t>>(&number_a[0], 2));
            array::static_t<u8_t> a1(maybe_t<pointer_t<u8_t>>(&number_a[2], 2));
            array::dynamic_t<u8_t> a0_plus_a1(4);
            Add<u8_t>(a0, a1, a0_plus_a1).Ignore_Error();
            CHECK(a0_plus_a1.Count() == 3);
            CHECK(a0_plus_a1[0] == 0xFE);
            CHECK(a0_plus_a1[1] == 0x00);
            CHECK(a0_plus_a1[2] == 0x01);

            Karatsuba_Multiply<u8_t>(array::static_t<u8_t>(number_a),
                                     array::static_t<u8_t>(number_b),
                                     result);
            CHECK(result.Count() == 8);
            CHECK(result[0] == 0x01);
            CHECK(result[1] == 0x00);
            CHECK(result[2] == 0x00);
            CHECK(result[3] == 0xFE);
            CHECK(result[4] == 0xFF);
            CHECK(result[5] == 0xFF);
            CHECK(result[6] == 0x00);
            CHECK(result[7] == 0x00);
        }
        /*{
            array::stack_t<u8_t, 4> number_a = { u8_t(0xFF), u8_t(0xFF), u8_t(0xFF), u8_t(0xFF) };
            array::stack_t<u8_t, 4> number_b = { u8_t(0xFF), u8_t(0xFF), u8_t(0xFF), u8_t(0xFF) };
            array::stack_t<u8_t, 8> result;
            Karatsuba_Multiply<u8_t>(array::static_t<u8_t>(number_a),
                                     array::static_t<u8_t>(number_b),
                                     result);
            CHECK(result.Count() == 8);
            CHECK(result[0] == 0x00);
            CHECK(result[1] == 0x00);
            CHECK(result[2] == 0x00);
            CHECK(result[3] == 0x00);
            CHECK(result[4] == 0xFE);
            CHECK(result[5] == 0xFF);
            CHECK(result[6] == 0xFF);
            CHECK(result[7] == 0xFF);

            constexpr u64_t test = u64_t(0xFFFFFFFF) * u64_t(0xFFFFFFFF);
            static_assert(test == 0xFFFFFFFE00000000);
        }*/
    }

}}
