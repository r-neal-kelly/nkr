/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/safe_numbers.h"

#include "intrinsics.h"

namespace nkr {

    TEST_SUITE("signed_positive_t")
    {
    #define types   \
        sp8_t,      \
        sp16_t,     \
        sp32_t,     \
        sp64_t

    #define consts      \
        const sp8_t,    \
        const sp16_t,   \
        const sp32_t,   \
        const sp64_t

    #define volatiles       \
        volatile sp8_t,     \
        volatile sp16_t,    \
        volatile sp32_t,    \
        volatile sp64_t

    #define volatile_consts     \
        volatile const sp8_t,   \
        volatile const sp16_t,  \
        volatile const sp32_t,  \
        volatile const sp64_t

        TEST_SUITE("aliases")
        {
            TEST_SUITE("value_t")
            {
                TEST_CASE_TEMPLATE("should equal the passed in type", sp_p, types, consts, volatiles, volatile_consts)
                {
                    if constexpr (std::same_as<std::remove_cvref_t<sp_p>, sp8_t>) {
                        static_assert(std::same_as<sp_p::value_t, s8_t>);
                    } else if constexpr (std::same_as<std::remove_cvref_t<sp_p>, sp16_t>) {
                        static_assert(std::same_as<sp_p::value_t, s16_t>);
                    } else if constexpr (std::same_as<std::remove_cvref_t<sp_p>, sp32_t>) {
                        static_assert(std::same_as<sp_p::value_t, s32_t>);
                    } else if constexpr (std::same_as<std::remove_cvref_t<sp_p>, sp64_t>) {
                        static_assert(std::same_as<sp_p::value_t, s64_t>);
                    }
                }
            }
        }

        TEST_SUITE("static data")
        {
            TEST_SUITE("MIN")
            {
                TEST_CASE_TEMPLATE("should equal zero", sp_p, types, consts, volatiles, volatile_consts)
                {
                    CHECK(sp_p::MIN == 0);
                }
            }

            TEST_SUITE("MAX")
            {
                TEST_CASE_TEMPLATE("should equal the max of value_t", sp_p, types, consts, volatiles, volatile_consts)
                {
                    CHECK(sp_p::MAX == std::numeric_limits<sp_p::value_t>::max());
                }
            }

            TEST_SUITE("TOTAL")
            {
                TEST_CASE_TEMPLATE("should equal the total number of possible values for value_t", sp_p, types, consts, volatiles, volatile_consts)
                {
                    CHECK(sp_p::TOTAL == static_cast<u64_t>(std::numeric_limits<sp_p::value_t>::max()) + 1);
                }
            }
        }

        TEST_SUITE("object data")
        {

        }

        TEST_SUITE("objects")
        {
            TEST_SUITE("default_ctor()")
            {
                TEST_CASE_TEMPLATE("should set value to MIN", sp_p, types, consts, volatiles, volatile_consts)
                {
                    sp_p sp;
                    CHECK(sp == sp_p::MIN);
                }

                TEST_CASE_TEMPLATE("should set value to 0", sp_p, types, consts, volatiles, volatile_consts)
                {
                    sp_p sp;
                    CHECK(sp == 0);
                }
            }

            TEST_SUITE("value_ctor()")
            {
                TEST_CASE_TEMPLATE("should set a positive value in range", sp_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sp_p::value_t;

                    value_t random = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    sp_p sp(random);
                    CHECK(sp == random);
                }
            }

            TEST_SUITE("copy_ctor()")
            {

            }

            TEST_SUITE("move_ctor()")
            {

            }

            TEST_SUITE("value_assignment_ctor()")
            {

            }

            TEST_SUITE("copy_assignment_ctor()")
            {

            }

            TEST_SUITE("move_assignment_ctor()")
            {

            }

            TEST_SUITE("dtor()")
            {

            }
        }

        TEST_SUITE("casts")
        {
            TEST_SUITE("value_t()")
            {

            }
        }

        TEST_SUITE("operators")
        {
            TEST_SUITE("+()")
            {
                TEST_CASE_TEMPLATE("", sp_p, types, consts, volatiles, volatile_consts)
                {
                    /*CHECK(positive_p(-1) == positive_p::MAX);
                    CHECK(positive_p(static_cast<count_t>(positive_p::MAX) + 1) == 0);

                    CHECK(positive_p(0) + -1 == positive_p::MAX);
                    CHECK(positive_p(0) + -2 == positive_p::MAX - 1);
                    CHECK(positive_p(positive_p::MAX) + 1 == 0);
                    CHECK(positive_p(positive_p::MAX) + 2 == 1);

                    CHECK(positive_p(0) - 1 == positive_p::MAX);
                    CHECK(positive_p(0) - 2 == positive_p::MAX - 1);
                    CHECK(positive_p(positive_p::MAX) - -1 == 0);
                    CHECK(positive_p(positive_p::MAX) - -2 == 1);

                    CHECK((positive_p(0) += -1) == positive_p::MAX);

                    CHECK((positive_p(0) -= 1) == positive_p::MAX);
                    CHECK((positive_p(positive_p::MAX / 2) *= 2) + 2 == positive_p::MIN);*/
                }
            }

            TEST_SUITE("-()")
            {

            }

            TEST_SUITE("*()")
            {

            }

            TEST_SUITE("/()")
            {

            }

            TEST_SUITE("%()")
            {

            }

            TEST_SUITE("~()")
            {

            }

            TEST_SUITE("|()")
            {

            }

            TEST_SUITE("&()")
            {

            }

            TEST_SUITE("^()")
            {

            }

            TEST_SUITE("<<()")
            {

            }

            TEST_SUITE(">>()")
            {

            }

            TEST_SUITE("+=()")
            {

            }

            TEST_SUITE("-=()")
            {

            }

            TEST_SUITE("*=()")
            {

            }

            TEST_SUITE("/=()")
            {

            }

            TEST_SUITE("%=()")
            {

            }

            TEST_SUITE("|=()")
            {

            }

            TEST_SUITE("&=()")
            {

            }

            TEST_SUITE("^=()")
            {

            }

            TEST_SUITE("<<=()")
            {

            }

            TEST_SUITE(">>=()")
            {

            }

            TEST_SUITE("++()")
            {

            }

            TEST_SUITE("++(int)")
            {

            }

            TEST_SUITE("--()")
            {

            }

            TEST_SUITE("--(int)")
            {

            }
        }

    #undef types
    #undef consts
    #undef volatiles
    #undef volatile_consts
    }

}
