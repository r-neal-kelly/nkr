/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/intrinsics.h"

#include "nkr/charcoder/ascii_t.h"
#include "nkr/charcoder/utf_8_t.h"
#include "nkr/charcoder/utf_16_t.h"
#include "nkr/charcoder/utf_32_t.h"

#include "nkr/string_itr.h"
#include "nkr/string/dynamic_t.h"

#include "doctest.h"

#include "nkr_tests/charcoder/include/random.h"

namespace nkr {

    TEST_SUITE("string_itr<string_p>")
    {
        TEST_SUITE("aliases")
        {

        }
    }

    TEST_CASE("temp")
    {
        auto stack_string = Random_Stack_String<128, charcoder::ascii_t>();
        CHECK(stack_string.Point_Count() == 128);
        CHECK(stack_string.Has_Terminus());



        string::dynamic_t<charcoder::utf_8_t> string(u8"neal.νηαλ.נהאל.ነሐአለ.𐌍𐌄𐌀𐌋");

        auto Print_Point = [](auto& itr)
        {
            printf("%8zX ( ", itr.Point());
            for (index_t idx = 0, end = itr.Point_Unit_Count(); idx < end; idx += 1) {
                printf("%2X ", itr.Point_Unit(idx));
            }
            printf(")\n");
        };

        for (auto itr = string.First(); !itr.Is_Postfix(); itr.Next()) {
            Print_Point(itr);
        }
        for (auto itr = string.Terminus(); !itr.Is_Prefix(); itr.Prior()) {
            Print_Point(itr);
        }
        for (auto itr = string.Last(); !itr.Is_Prefix(); itr.Prior()) {
            Print_Point(itr);
        }
        for (auto itr = string.First(); !itr.Is_Last(); itr.Next()) {
            Print_Point(itr);
        }

        /*CHECK(string.At(4).Point() == '.');
        CHECK(string.At(9).Point() == '.');
        CHECK(string.At(14).Point() == '.');
        CHECK(string.At(19).Point() == '.');*/
    }

}
