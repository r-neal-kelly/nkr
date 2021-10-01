/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/intrinsics.h"
#include "nkr/math.h"

#include "doctest.h"

namespace nkr { namespace math {

    TEST_SUITE("Absolute")
    {

    }

    TEST_SUITE("Is_Power_Of_2")
    {
        TEST_CASE_TEMPLATE("should return true only if the integer is a power of 2", integer_p, u8_t, s8_t, u16_t, s16_t, u32_t, s32_t, u64_t, s64_t)
        {
            integer_p integer = 1;

            CHECK(math::Is_Power_Of_2(integer_p(integer << 0)));
            CHECK(math::Is_Power_Of_2(integer_p(integer << 1)));
            CHECK(math::Is_Power_Of_2(integer_p(integer << 2)));
            CHECK(math::Is_Power_Of_2(integer_p(integer << 3)));
            CHECK(math::Is_Power_Of_2(integer_p(integer << 4)));
            CHECK(math::Is_Power_Of_2(integer_p(integer << 5)));
            CHECK(math::Is_Power_Of_2(integer_p(integer << 6)));
            CHECK(math::Is_Power_Of_2(integer_p(integer << 7)));
            if constexpr (sizeof(integer_p) >= 2) {
                CHECK(math::Is_Power_Of_2(integer_p(integer << 8)));
                CHECK(math::Is_Power_Of_2(integer_p(integer << 9)));
                CHECK(math::Is_Power_Of_2(integer_p(integer << 10)));
                CHECK(math::Is_Power_Of_2(integer_p(integer << 11)));
                CHECK(math::Is_Power_Of_2(integer_p(integer << 12)));
                CHECK(math::Is_Power_Of_2(integer_p(integer << 13)));
                CHECK(math::Is_Power_Of_2(integer_p(integer << 14)));
                CHECK(math::Is_Power_Of_2(integer_p(integer << 15)));
                if constexpr (sizeof(integer_p) >= 4) {
                    CHECK(math::Is_Power_Of_2(integer_p(integer << 16)));
                    CHECK(math::Is_Power_Of_2(integer_p(integer << 17)));
                    CHECK(math::Is_Power_Of_2(integer_p(integer << 18)));
                    CHECK(math::Is_Power_Of_2(integer_p(integer << 19)));
                    CHECK(math::Is_Power_Of_2(integer_p(integer << 20)));
                    CHECK(math::Is_Power_Of_2(integer_p(integer << 21)));
                    CHECK(math::Is_Power_Of_2(integer_p(integer << 22)));
                    CHECK(math::Is_Power_Of_2(integer_p(integer << 23)));
                    CHECK(math::Is_Power_Of_2(integer_p(integer << 24)));
                    CHECK(math::Is_Power_Of_2(integer_p(integer << 25)));
                    CHECK(math::Is_Power_Of_2(integer_p(integer << 26)));
                    CHECK(math::Is_Power_Of_2(integer_p(integer << 27)));
                    CHECK(math::Is_Power_Of_2(integer_p(integer << 28)));
                    CHECK(math::Is_Power_Of_2(integer_p(integer << 29)));
                    CHECK(math::Is_Power_Of_2(integer_p(integer << 30)));
                    CHECK(math::Is_Power_Of_2(integer_p(integer << 31)));
                    if constexpr (sizeof(integer_p) >= 8) {
                        CHECK(math::Is_Power_Of_2(integer_p(integer << 32)));
                        CHECK(math::Is_Power_Of_2(integer_p(integer << 33)));
                        CHECK(math::Is_Power_Of_2(integer_p(integer << 34)));
                        CHECK(math::Is_Power_Of_2(integer_p(integer << 35)));
                        CHECK(math::Is_Power_Of_2(integer_p(integer << 36)));
                        CHECK(math::Is_Power_Of_2(integer_p(integer << 37)));
                        CHECK(math::Is_Power_Of_2(integer_p(integer << 38)));
                        CHECK(math::Is_Power_Of_2(integer_p(integer << 39)));
                        CHECK(math::Is_Power_Of_2(integer_p(integer << 40)));
                        CHECK(math::Is_Power_Of_2(integer_p(integer << 41)));
                        CHECK(math::Is_Power_Of_2(integer_p(integer << 42)));
                        CHECK(math::Is_Power_Of_2(integer_p(integer << 43)));
                        CHECK(math::Is_Power_Of_2(integer_p(integer << 44)));
                        CHECK(math::Is_Power_Of_2(integer_p(integer << 45)));
                        CHECK(math::Is_Power_Of_2(integer_p(integer << 46)));
                        CHECK(math::Is_Power_Of_2(integer_p(integer << 47)));
                        CHECK(math::Is_Power_Of_2(integer_p(integer << 48)));
                        CHECK(math::Is_Power_Of_2(integer_p(integer << 49)));
                        CHECK(math::Is_Power_Of_2(integer_p(integer << 50)));
                        CHECK(math::Is_Power_Of_2(integer_p(integer << 51)));
                        CHECK(math::Is_Power_Of_2(integer_p(integer << 52)));
                        CHECK(math::Is_Power_Of_2(integer_p(integer << 53)));
                        CHECK(math::Is_Power_Of_2(integer_p(integer << 54)));
                        CHECK(math::Is_Power_Of_2(integer_p(integer << 55)));
                        CHECK(math::Is_Power_Of_2(integer_p(integer << 56)));
                        CHECK(math::Is_Power_Of_2(integer_p(integer << 57)));
                        CHECK(math::Is_Power_Of_2(integer_p(integer << 58)));
                        CHECK(math::Is_Power_Of_2(integer_p(integer << 59)));
                        CHECK(math::Is_Power_Of_2(integer_p(integer << 60)));
                        CHECK(math::Is_Power_Of_2(integer_p(integer << 61)));
                        CHECK(math::Is_Power_Of_2(integer_p(integer << 62)));
                        CHECK(math::Is_Power_Of_2(integer_p(integer << 63)));
                    }
                }
            }

            CHECK_FALSE(math::Is_Power_Of_2(0));
            CHECK_FALSE(math::Is_Power_Of_2(3));
            CHECK_FALSE(math::Is_Power_Of_2(5));
            CHECK_FALSE(math::Is_Power_Of_2((1ull << 63) - 1));
        }

        TEST_CASE_TEMPLATE("should work as a constexpr", integer_p, u8_t, s8_t, u16_t, s16_t, u32_t, s32_t, u64_t, s64_t)
        {
            static_assert(math::Is_Power_Of_2(integer_p(1 << 0)));
            static_assert(math::Is_Power_Of_2(integer_p(1 << 1)));
            static_assert(math::Is_Power_Of_2(integer_p(1 << 2)));
            static_assert(math::Is_Power_Of_2(integer_p(1 << 3)));
            static_assert(math::Is_Power_Of_2(integer_p(1 << 4)));
            static_assert(math::Is_Power_Of_2(integer_p(1 << 5)));
            static_assert(math::Is_Power_Of_2(integer_p(1 << 6)));
            static_assert(math::Is_Power_Of_2(integer_p(1 << 7)));
        }
    }

    TEST_SUITE("Overflow")
    {
    #define numbers \
        u8_t,       \
        s8_t,       \
        u16_t,      \
        s16_t,      \
        u32_t,      \
        s32_t,      \
        u64_t,      \
        s64_t,      \
        r32_t,      \
        r64_t

        TEST_SUITE("Will_Overflow_Add")
        {
            TEST_CASE_TEMPLATE("should return true if a + b would overflow", number_p, numbers)
            {
                CHECK(Will_Overflow_Add(std::numeric_limits<number_p>::max(), number_p(1)) == true);

                if constexpr (std::is_signed_v<number_p>) {
                    CHECK(Will_Overflow_Add(std::numeric_limits<number_p>::lowest(), number_p(-1)) == true);
                } else {
                    CHECK(Will_Overflow_Add(std::numeric_limits<number_p>::lowest(), number_p(-1)) == false);
                }

                CHECK(Will_Overflow_Add<number_p>(0, -1) == false);
            }
        }

        TEST_SUITE("Will_Overflow_Subtract")
        {
            TEST_CASE_TEMPLATE("should return true if a - b would overflow", number_p, numbers)
            {

            }
        }

        TEST_SUITE("Will_Overflow_Multiply")
        {
            TEST_CASE_TEMPLATE("should return true if a * b would overflow", number_p, numbers)
            {
                CHECK(Will_Overflow_Multiply<number_p>(std::numeric_limits<number_p>::max(), 2) == true);

                for (u8_t count = 1, last = 5; count <= last; count += 1) {
                    number_p random_a = Random<number_p>(0, std::numeric_limits<number_p>::max() / count);
                    number_p random_b = Random<number_p>(1, count);
                    CHECK(Will_Overflow_Multiply<number_p>(random_a, random_b) == false);
                    if constexpr (std::is_signed_v<number_p>) {
                        CHECK(Will_Overflow_Multiply<number_p>(random_a, -random_b) == false);
                    }
                }

                if constexpr (std::is_signed_v<number_p>) {
                    CHECK(Will_Overflow_Multiply<number_p>(2, -2) == false);
                }
            }
        }

        TEST_SUITE("Will_Overflow_Divide")
        {
            TEST_CASE_TEMPLATE("should return true if a / b would overflow", number_p, numbers)
            {
                if constexpr (std::is_signed_v<number_p>) {
                    CHECK(Will_Overflow_Divide<number_p>(std::numeric_limits<number_p>::lowest(), -1) == true);
                }
            }
        }

    #undef numbers
    }

}}
