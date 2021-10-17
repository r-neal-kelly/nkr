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
#include "nkr/string/stack_t.h"

#include "doctest.h"

namespace nkr {

    TEST_SUITE("string_itr<string_p>")
    {
    #define nkr_UNIT(QUALIFIER_p, STRING_p, CHARCODER_p)                \
        QUALIFIER_p string_itr<STRING_p<CHARCODER_p>>,                  \
        QUALIFIER_p string_itr<volatile STRING_p<CHARCODER_p>>,         \
        QUALIFIER_p string_itr<const STRING_p<CHARCODER_p>>,            \
        QUALIFIER_p string_itr<const volatile STRING_p<CHARCODER_p>>

    #define nkr_CHARCODERS(QUALIFIER_p, STRING_p)                   \
        nkr_UNIT(QUALIFIER_p, STRING_p, charcoder::ascii_t),        \
        nkr_UNIT(QUALIFIER_p, STRING_p, charcoder::utf_8_t),        \
        nkr_UNIT(QUALIFIER_p, STRING_p, charcoder::utf_16_be_t),    \
        nkr_UNIT(QUALIFIER_p, STRING_p, charcoder::utf_16_le_t),    \
        nkr_UNIT(QUALIFIER_p, STRING_p, charcoder::utf_32_be_t),    \
        nkr_UNIT(QUALIFIER_p, STRING_p, charcoder::utf_32_le_t)

    #define nkr_STRINGS(QUALIFIER_p)                    \
        nkr_CHARCODERS(QUALIFIER_p, string::dynamic_t), \
        nkr_CHARCODERS(QUALIFIER_p, string::stack_t)

    #define nkr_REGULAR         \
        nkr_STRINGS(nkr_BLANK)

    #define nkr_NON_CONST       \
        nkr_STRINGS(nkr_BLANK), \
        nkr_STRINGS(volatile)

    #define nkr_CONST               \
        nkr_STRINGS(const),         \
        nkr_STRINGS(const volatile)

    #define nkr_ALL     \
        nkr_NON_CONST,  \
        nkr_CONST

        template <charcoder_i charcoder_p, count_t point_count_p>
        auto Random_Stack_String()
        {
            string::stack_t<charcoder_p, point_count_p* charcoder_p::Max_Unit_Count()> string;
            for (index_t idx = 0, end = point_count_p - 1; idx < end; idx += 1) {
                string.Push(nkr::Random<string::point_t>(1, charcoder_p::Last_Point())).Ignore_Error();
            }

            return string;
        }

        TEST_SUITE("aliases")
        {
            TEST_SUITE("string_t")
            {
                TEST_CASE_TEMPLATE("should have a string_t", itr_p, nkr_ALL)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    static_assert(any_string_tr<string_t>);
                }
            }

            TEST_SUITE("charcoder_t")
            {
                TEST_CASE_TEMPLATE("should have the same charcoder_t as its string_t", itr_p, nkr_ALL)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    static_assert(is_tr<charcoder_t, typename string_t::charcoder_t>);
                }
            }

            TEST_SUITE("unit_t")
            {
                TEST_CASE_TEMPLATE("should have the same unit_t as its string_t", itr_p, nkr_ALL)
                {
                    using string_t = itr_p::string_t;
                    using charcoder_t = itr_p::charcoder_t;
                    using unit_t = itr_p::unit_t;

                    static_assert(is_tr<unit_t, string_t::unit_t>);
                }
            }
        }

        TEST_CASE("temp")
        {
            auto stack_string = Random_Stack_String<charcoder::ascii_t, 128>();
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

            CHECK(string.At(4).Point() == '.');
            CHECK(string.At(9).Point() == '.');
            CHECK(string.At(14).Point() == '.');
            CHECK(string.At(19).Point() == '.');
        }
    }
}
