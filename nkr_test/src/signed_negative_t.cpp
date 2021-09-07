/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/signed_negative_t.h"

#include "intrinsics.h"

namespace nkr {

    TEST_SUITE("signed_negative_t")
    {
    #define types   \
        sn8_t,      \
        sn16_t,     \
        sn32_t,     \
        sn64_t

    #define consts      \
        const sn8_t,    \
        const sn16_t,   \
        const sn32_t,   \
        const sn64_t

    #define volatiles       \
        volatile sn8_t,     \
        volatile sn16_t,    \
        volatile sn32_t,    \
        volatile sn64_t

    #define volatile_consts     \
        volatile const sn8_t,   \
        volatile const sn16_t,  \
        volatile const sn32_t,  \
        volatile const sn64_t

        TEST_SUITE("aliases")
        {
            TEST_SUITE("value_t")
            {
                TEST_CASE_TEMPLATE("should equal the passed in type", sn_p, types, consts, volatiles, volatile_consts)
                {
                    if constexpr (std::same_as<std::remove_cvref_t<sn_p>, sn8_t>) {
                        static_assert(std::same_as<sn_p::value_t, s8_t>);
                    } else if constexpr (std::same_as<std::remove_cvref_t<sn_p>, sn16_t>) {
                        static_assert(std::same_as<sn_p::value_t, s16_t>);
                    } else if constexpr (std::same_as<std::remove_cvref_t<sn_p>, sn32_t>) {
                        static_assert(std::same_as<sn_p::value_t, s32_t>);
                    } else if constexpr (std::same_as<std::remove_cvref_t<sn_p>, sn64_t>) {
                        static_assert(std::same_as<sn_p::value_t, s64_t>);
                    }
                }
            }
        }

        TEST_SUITE("static data")
        {
            TEST_SUITE("MIN")
            {
                TEST_CASE_TEMPLATE("should equal the lowest of value_t + 1", sn_p, types, consts, volatiles, volatile_consts)
                {
                    CHECK(sn_p::MIN == std::numeric_limits<sn_p::value_t>::lowest() + 1);
                }
            }

            TEST_SUITE("MAX")
            {
                TEST_CASE_TEMPLATE("should equal 0", sn_p, types, consts, volatiles, volatile_consts)
                {
                    CHECK(sn_p::MAX == 0);
                }
            }

            TEST_SUITE("TOTAL")
            {
                TEST_CASE_TEMPLATE("should equal the total number of possible values", sn_p, types, consts, volatiles, volatile_consts)
                {
                    CHECK(sn_p::TOTAL == static_cast<u64_t>(std::numeric_limits<sn_p::value_t>::max()) + 1);
                }
            }
        }

        TEST_SUITE("static functions")
        {
            TEST_SUITE("To_Value()")
            {
                TEST_CASE_TEMPLATE("should convert any integer into a valid value", sn_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sn_p::value_t;

                    const s64_t random = Random<s64_t>();
                    value_t value = sn_p::To_Value(random);
                    CHECK(value >= sn_p::MIN && value <= sn_p::MAX);
                }
            }
        }

        TEST_SUITE("object data")
        {
            TEST_SUITE("value")
            {
                TEST_CASE_TEMPLATE("should be a value_t", sn_p, types, consts, volatiles, volatile_consts)
                {
                    static_assert(std::same_as<decltype(sn_p::value), sn_p::value_t>);
                }
            }
        }

        TEST_SUITE("objects")
        {
            TEST_SUITE("default_ctor()")
            {
                TEST_CASE_TEMPLATE("should set value to MAX", sn_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sn_p::value_t;

                    sn_p sn;
                    CHECK(sn == sn_p::MAX);
                }
            }

            TEST_SUITE("")
            {

            }
        }

        TEST_SUITE("casts")
        {

        }

        TEST_SUITE("operators")
        {

        }

    #undef types
    #undef consts
    #undef volatiles
    #undef volatile_consts
    }

}
