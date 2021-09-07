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

        TEST_SUITE("static functions")
        {
            TEST_SUITE("To_Value()")
            {
                TEST_CASE_TEMPLATE("should convert any integer into a valid value", sp_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sp_p::value_t;

                    const s64_t random = Random<s64_t>();
                    value_t value = sp_p::To_Value(random);
                    CHECK(value >= sp_p::MIN && value <= sp_p::MAX);
                }
            }
        }

        TEST_SUITE("object data")
        {
            TEST_SUITE("value")
            {
                TEST_CASE_TEMPLATE("should be a value_t", sp_p, types, consts, volatiles, volatile_consts)
                {
                    static_assert(std::same_as<decltype(sp_p::value), sp_p::value_t>);
                }
            }
        }

        TEST_SUITE("objects")
        {
            TEST_SUITE("default_ctor()")
            {
                TEST_CASE_TEMPLATE("should set value to MIN", sp_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sp_p::value_t;

                    sp_p sp;
                    CHECK(sp == sp_p::MIN);
                }
            }

            TEST_SUITE("value_ctor()")
            {
                TEST_CASE_TEMPLATE("should explicitly set passed value", sp_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sp_p::value_t;

                    const value_t random = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    sp_p sp(random);
                    CHECK(sp == random);
                }

                TEST_CASE_TEMPLATE("should implicitly set passed value", sp_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sp_p::value_t;

                    const value_t random = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    sp_p sp = random;
                    CHECK(sp == random);
                }

                TEST_CASE_TEMPLATE("should work with any integer", sp_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sp_p::value_t;

                    const u64_t random = Random<u64_t>(sp_p::MIN, sp_p::MAX);
                    sp_p sp(random);
                    CHECK(sp == static_cast<value_t>(random));
                }

                TEST_CASE_TEMPLATE("should wrap any negative numbers to be positive", sp_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sp_p::value_t;

                    const s64_t random = Random<s64_t>(std::numeric_limits<s64_t>::lowest(), 0);
                    sp_p sp(random);
                    CHECK(sp >= sp_p::MIN && sp <= sp_p::MAX);
                }

                TEST_CASE_TEMPLATE("should wrap any positive numbers to be in range", sp_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sp_p::value_t;

                    const u64_t random = Random<u64_t>(sp_p::TOTAL, std::numeric_limits<u64_t>::max());
                    sp_p sp(random);
                    CHECK(sp >= sp_p::MIN && sp <= sp_p::MAX);
                }

                TEST_CASE_TEMPLATE("should equate MAX when passed MIN - 1", sp_p, types, consts, volatiles, volatile_consts)
                {
                    sp_p sp(sp_p::MIN - 1);
                    CHECK(sp == sp_p::MAX);
                }

                TEST_CASE_TEMPLATE("should equate MIN when passed MAX + 1", sp_p, types, consts, volatiles, volatile_consts)
                {
                    sp_p sp(static_cast<u64_t>(sp_p::MAX) + 1);
                    CHECK(sp == sp_p::MIN);
                }
            }

            TEST_SUITE("copy_ctor()")
            {
                TEST_CASE_TEMPLATE("should explicitly copy the value of other", sp_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sp_p::value_t;

                    const value_t random = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    sp_p other(random);
                    sp_p sp(other);
                    CHECK(sp == random);
                }

                TEST_CASE_TEMPLATE("should implicitly copy the value of other", sp_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sp_p::value_t;

                    const value_t random = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    sp_p other(random);
                    sp_p sp = other;
                    CHECK(sp == random);
                }

                TEST_CASE_TEMPLATE("should not alter the value of other", sp_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sp_p::value_t;

                    const value_t random = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    sp_p other(random);
                    sp_p sp(other);
                    CHECK(other == random);
                }
            }

            TEST_SUITE("move_ctor()")
            {
                TEST_CASE_TEMPLATE("should explicitly move the value of other", sp_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sp_p::value_t;
                    using other_t = std::remove_const_t<sp_p>;

                    const value_t random = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    other_t other(random);
                    sp_p sp(std::move(other));
                    CHECK(sp == random);
                }

                TEST_CASE_TEMPLATE("should implicitly move the value of other", sp_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sp_p::value_t;
                    using other_t = std::remove_const_t<sp_p>;

                    const value_t random = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    other_t other(random);
                    sp_p sp = std::move(other);
                    CHECK(sp == random);
                }

                TEST_CASE_TEMPLATE("should set the value of other to the default", sp_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sp_p::value_t;
                    using other_t = std::remove_const_t<sp_p>;

                    const value_t random = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    other_t other(random);
                    sp_p sp(std::move(other));
                    CHECK(other == sp_p::MIN);
                }
            }

            TEST_SUITE("value_assignment_ctor()")
            {
                TEST_CASE_TEMPLATE("should set passed value", sp_p, types, volatiles)
                {
                    using value_t = sp_p::value_t;

                    const value_t random = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    sp_p sp;
                    sp = random;
                    CHECK(sp == random);
                }

                TEST_CASE_TEMPLATE("should return itself", sp_p, types, volatiles)
                {
                    using value_t = sp_p::value_t;

                    const value_t random = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    sp_p sp;
                    CHECK(&(sp = random) == &sp);
                }

                TEST_CASE_TEMPLATE("should work with any integer", sp_p, types, volatiles)
                {
                    using value_t = sp_p::value_t;

                    const u64_t random = Random<u64_t>(sp_p::MIN, sp_p::MAX);
                    sp_p sp;
                    sp = random;
                    CHECK(sp == static_cast<value_t>(random));
                }

                TEST_CASE_TEMPLATE("should wrap any negative numbers to be positive", sp_p, types, volatiles)
                {
                    using value_t = sp_p::value_t;

                    const s64_t random = Random<s64_t>(std::numeric_limits<s64_t>::lowest(), 0);
                    sp_p sp;
                    sp = random;
                    CHECK(sp >= sp_p::MIN && sp <= sp_p::MAX);
                }

                TEST_CASE_TEMPLATE("should wrap any positive numbers to be in range", sp_p, types, volatiles)
                {
                    using value_t = sp_p::value_t;

                    const u64_t random = Random<u64_t>(sp_p::TOTAL, std::numeric_limits<u64_t>::max());
                    sp_p sp;
                    sp = random;
                    CHECK(sp >= sp_p::MIN && sp <= sp_p::MAX);
                }

                TEST_CASE_TEMPLATE("should equate MAX when passed MIN - 1", sp_p, types, volatiles)
                {
                    sp_p sp;
                    sp = sp_p::MIN - 1;
                    CHECK(sp == sp_p::MAX);
                }

                TEST_CASE_TEMPLATE("should equate MIN when passed MAX + 1", sp_p, types, volatiles)
                {
                    sp_p sp;
                    sp = static_cast<u64_t>(sp_p::MAX) + 1;
                    CHECK(sp == sp_p::MIN);
                }
            }

            TEST_SUITE("copy_assignment_ctor()")
            {
                TEST_CASE_TEMPLATE("should copy the value of other", sp_p, types, volatiles)
                {
                    using value_t = sp_p::value_t;

                    const value_t random = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    const sp_p other(random);
                    sp_p sp;
                    sp = other;
                    CHECK(sp == random);
                }

                TEST_CASE_TEMPLATE("should return itself", sp_p, types, volatiles)
                {
                    using value_t = sp_p::value_t;

                    const value_t random = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    const sp_p other(random);
                    sp_p sp;
                    CHECK(&(sp = other) == &sp);
                }

                TEST_CASE_TEMPLATE("should not alter the value of other", sp_p, types, volatiles)
                {
                    using value_t = sp_p::value_t;

                    const value_t random = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    const sp_p other(random);
                    sp_p sp;
                    sp = other;
                    CHECK(other == random);
                }
            }

            TEST_SUITE("move_assignment_ctor()")
            {
                TEST_CASE_TEMPLATE("should move the value of other", sp_p, types, volatiles)
                {
                    using value_t = sp_p::value_t;

                    const value_t random = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    sp_p other(random);
                    sp_p sp;
                    sp = std::move(other);
                    CHECK(sp == random);
                }

                TEST_CASE_TEMPLATE("should return itself", sp_p, types, volatiles)
                {
                    using value_t = sp_p::value_t;

                    const value_t random = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    sp_p other(random);
                    sp_p sp;
                    CHECK(&(sp = std::move(other)) == &sp);
                }

                TEST_CASE_TEMPLATE("should set the value of other to the default", sp_p, types, volatiles)
                {
                    using value_t = sp_p::value_t;

                    const value_t random = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    sp_p other(random);
                    sp_p sp;
                    sp = std::move(other);
                    CHECK(other == sp_p::MIN);
                }
            }

            TEST_SUITE("dtor()")
            {
                TEST_CASE_TEMPLATE("should set value to MIN", sp_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sp_p::value_t;

                    const value_t random = Random<value_t>();
                    sp_p sp(random);
                    sp.~sp_p();
                    CHECK(sp == sp_p::MIN);
                }
            }
        }

        TEST_SUITE("casts")
        {
            TEST_SUITE("value_t()")
            {
                TEST_CASE_TEMPLATE("should explicitly return a copy of its value", sp_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sp_p::value_t;

                    const value_t random = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    sp_p sp(random);
                    value_t value = static_cast<value_t>(sp);
                    CHECK(value == random);
                }

                TEST_CASE_TEMPLATE("should implicitly return a copy of its value", sp_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sp_p::value_t;

                    const value_t random = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    sp_p sp(random);
                    value_t value = sp;
                    CHECK(value == random);
                }

                TEST_CASE_TEMPLATE("should not change its value", sp_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sp_p::value_t;

                    const value_t random = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    sp_p sp(random);
                    value_t value = sp;
                    CHECK(sp == random);
                }

                TEST_CASE_TEMPLATE("should implicitly allow for logical operators", sp_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sp_p::value_t;

                    const value_t random = Random<value_t>(sp_p::MIN + 1, sp_p::MAX);
                    sp_p sp(random);
                    CHECK(sp);
                    CHECK(!!sp);
                    CHECK(sp || false);
                    CHECK(sp && true);
                    CHECK(sp ? true : false);
                }

                TEST_CASE_TEMPLATE("should implicitly allow for comparison operators", sp_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sp_p::value_t;

                    const value_t random = Random<value_t>(sp_p::MIN + 1, sp_p::MAX);
                    sp_p sp(random);
                    CHECK(sp == random);
                    CHECK_FALSE(sp != random);
                    CHECK_FALSE(sp < random);
                    CHECK_FALSE(sp > random);
                    CHECK(sp <= random);
                    CHECK(sp >= random);
                    CHECK((sp <=> random == 0));
                }
            }
        }

        TEST_SUITE("operators")
        {
            TEST_SUITE("+()")
            {
                TEST_CASE_TEMPLATE("should return value + other", sp_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sp_p::value_t;

                    const value_t random_a = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    const value_t random_b = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    sp_p sp(random_a);
                    CHECK((sp + random_b) == (random_a + random_b));
                }

                TEST_CASE_TEMPLATE("should not change its value", sp_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sp_p::value_t;

                    const value_t random_a = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    const value_t random_b = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    sp_p sp(random_a);
                    value_t value = sp + random_b;
                    CHECK(sp == random_a);
                }

                TEST_CASE_TEMPLATE("should work with any integer", sp_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sp_p::value_t;

                    const value_t random_a = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    const u64_t random_b = Random<u64_t>();
                    sp_p sp(random_a);
                    CHECK((sp + random_b) == (random_a + random_b));
                }
            }

            TEST_SUITE("-()")
            {
                TEST_CASE_TEMPLATE("should return value - other", sp_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sp_p::value_t;

                    const value_t random_a = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    const value_t random_b = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    sp_p sp(random_a);
                    CHECK((sp - random_b) == (random_a - random_b));
                }

                TEST_CASE_TEMPLATE("should not change its value", sp_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sp_p::value_t;

                    const value_t random_a = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    const value_t random_b = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    sp_p sp(random_a);
                    value_t value = sp - random_b;
                    CHECK(sp == random_a);
                }

                TEST_CASE_TEMPLATE("should work with any integer", sp_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sp_p::value_t;

                    const value_t random_a = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    const u64_t random_b = Random<u64_t>();
                    sp_p sp(random_a);
                    CHECK((sp - random_b) == (random_a - random_b));
                }
            }

            TEST_SUITE("*()")
            {
                TEST_CASE_TEMPLATE("should return value * other", sp_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sp_p::value_t;

                    const value_t random_a = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    const value_t random_b = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    sp_p sp(random_a);
                    CHECK((sp * random_b) == (random_a * random_b));
                }

                TEST_CASE_TEMPLATE("should not change its value", sp_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sp_p::value_t;

                    const value_t random_a = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    const value_t random_b = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    sp_p sp(random_a);
                    value_t value = sp * random_b;
                    CHECK(sp == random_a);
                }

                TEST_CASE_TEMPLATE("should work with any integer", sp_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sp_p::value_t;

                    const value_t random_a = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    const u64_t random_b = Random<u64_t>();
                    sp_p sp(random_a);
                    CHECK((sp * random_b) == (random_a * random_b));
                }
            }

            TEST_SUITE("/()")
            {
                TEST_CASE_TEMPLATE("should return value / other", sp_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sp_p::value_t;

                    const value_t random_a = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    const value_t random_b = Random<value_t>(sp_p::MIN + 1, sp_p::MAX);
                    sp_p sp(random_a);
                    CHECK((sp / random_b) == (random_a / random_b));
                }

                TEST_CASE_TEMPLATE("should not change its value", sp_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sp_p::value_t;

                    const value_t random_a = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    const value_t random_b = Random<value_t>(sp_p::MIN + 1, sp_p::MAX);
                    sp_p sp(random_a);
                    value_t value = sp / random_b;
                    CHECK(sp == random_a);
                }

                TEST_CASE_TEMPLATE("should work with any integer", sp_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sp_p::value_t;

                    const value_t random_a = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    u64_t random_b;
                    do {
                        random_b = Random<u64_t>();
                    } while (random_b == 0);
                    sp_p sp(random_a);
                    CHECK((sp / random_b) == (random_a / random_b));
                }
            }

            TEST_SUITE("%()")
            {
                TEST_CASE_TEMPLATE("should return value % other", sp_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sp_p::value_t;

                    const value_t random_a = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    const value_t random_b = Random<value_t>(sp_p::MIN + 1, sp_p::MAX);
                    sp_p sp(random_a);
                    CHECK((sp % random_b) == (random_a % random_b));
                }

                TEST_CASE_TEMPLATE("should not change its value", sp_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sp_p::value_t;

                    const value_t random_a = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    const value_t random_b = Random<value_t>(sp_p::MIN + 1, sp_p::MAX);
                    sp_p sp(random_a);
                    value_t value = sp % random_b;
                    CHECK(sp == random_a);
                }

                TEST_CASE_TEMPLATE("should work with any integer", sp_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sp_p::value_t;

                    const value_t random_a = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    u64_t random_b;
                    do {
                        random_b = Random<u64_t>();
                    } while (random_b == 0);
                    sp_p sp(random_a);
                    CHECK((sp % random_b) == (random_a % random_b));
                }
            }

            TEST_SUITE("~()")
            {
                TEST_CASE_TEMPLATE("should return ~value", sp_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sp_p::value_t;

                    sp_p sp;
                    if constexpr (sizeof(value_t) == sizeof(s8_t)) {
                        CHECK(~sp == 0x7F);
                    } else if constexpr (sizeof(value_t) == sizeof(s16_t)) {
                        CHECK(~sp == 0x7FFF);
                    } else if constexpr (sizeof(value_t) == sizeof(s32_t)) {
                        CHECK(~sp == 0x7FFFFFFF);
                    } else if constexpr (sizeof(value_t) == sizeof(s64_t)) {
                        CHECK(~sp == 0x7FFFFFFFFFFFFFFF);
                    }
                }
            }

            TEST_SUITE("|()")
            {
                TEST_CASE_TEMPLATE("should return value | other", sp_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sp_p::value_t;

                    const value_t random_a = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    const value_t random_b = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    sp_p sp(random_a);
                    CHECK((sp | random_b) == (random_a | random_b));
                }

                TEST_CASE_TEMPLATE("should not change its value", sp_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sp_p::value_t;

                    const value_t random_a = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    const value_t random_b = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    sp_p sp(random_a);
                    value_t value = sp | random_b;
                    CHECK(sp == random_a);
                }

                TEST_CASE_TEMPLATE("should work with any integer", sp_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sp_p::value_t;

                    const value_t random_a = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    const u64_t random_b = Random<u64_t>();
                    sp_p sp(random_a);
                    CHECK((sp | random_b) == (random_a | random_b));
                }
            }

            TEST_SUITE("&()")
            {
                TEST_CASE_TEMPLATE("should return value & other", sp_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sp_p::value_t;

                    const value_t random_a = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    const value_t random_b = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    sp_p sp(random_a);
                    CHECK((sp & random_b) == (random_a & random_b));
                }

                TEST_CASE_TEMPLATE("should not change its value", sp_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sp_p::value_t;

                    const value_t random_a = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    const value_t random_b = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    sp_p sp(random_a);
                    value_t value = sp & random_b;
                    CHECK(sp == random_a);
                }

                TEST_CASE_TEMPLATE("should work with any integer", sp_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sp_p::value_t;

                    const value_t random_a = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    const u64_t random_b = Random<u64_t>();
                    sp_p sp(random_a);
                    CHECK((sp & random_b) == (random_a & random_b));
                }
            }

            TEST_SUITE("^()")
            {
                TEST_CASE_TEMPLATE("should return value ^ other", sp_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sp_p::value_t;

                    const value_t random_a = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    const value_t random_b = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    sp_p sp(random_a);
                    CHECK((sp ^ random_b) == (random_a ^ random_b));
                }

                TEST_CASE_TEMPLATE("should not change its value", sp_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sp_p::value_t;

                    const value_t random_a = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    const value_t random_b = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    sp_p sp(random_a);
                    value_t value = sp ^ random_b;
                    CHECK(sp == random_a);
                }

                TEST_CASE_TEMPLATE("should work with any integer", sp_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sp_p::value_t;

                    const value_t random_a = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    const u64_t random_b = Random<u64_t>();
                    sp_p sp(random_a);
                    CHECK((sp ^ random_b) == (random_a ^ random_b));
                }
            }

            TEST_SUITE("<<()")
            {
                TEST_CASE_TEMPLATE("should return value << other", sp_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sp_p::value_t;

                    const value_t random_a = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    const value_t random_b = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    sp_p sp(random_a);
                    CHECK((sp << random_b) == (random_a << random_b));
                }

                TEST_CASE_TEMPLATE("should not change its value", sp_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sp_p::value_t;

                    const value_t random_a = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    const value_t random_b = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    sp_p sp(random_a);
                    value_t value = sp << random_b;
                    CHECK(sp == random_a);
                }

                TEST_CASE_TEMPLATE("should work with any integer", sp_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sp_p::value_t;

                    const value_t random_a = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    const u64_t random_b = Random<u64_t>();
                    sp_p sp(random_a);
                    CHECK((sp << random_b) == (random_a << random_b));
                }
            }

            TEST_SUITE(">>()")
            {
                TEST_CASE_TEMPLATE("should return value >> other", sp_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sp_p::value_t;

                    const value_t random_a = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    const value_t random_b = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    sp_p sp(random_a);
                    CHECK((sp >> random_b) == (random_a >> random_b));
                }

                TEST_CASE_TEMPLATE("should not change its value", sp_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sp_p::value_t;

                    const value_t random_a = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    const value_t random_b = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    sp_p sp(random_a);
                    value_t value = sp >> random_b;
                    CHECK(sp == random_a);
                }

                TEST_CASE_TEMPLATE("should work with any integer", sp_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sp_p::value_t;

                    const value_t random_a = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    const u64_t random_b = Random<u64_t>();
                    sp_p sp(random_a);
                    CHECK((sp >> random_b) == (random_a >> random_b));
                }
            }

            TEST_SUITE("+=()")
            {
                TEST_CASE_TEMPLATE("should set value to value + other", sp_p, types, volatiles)
                {
                    using value_t = sp_p::value_t;

                    const value_t random_a = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    const value_t random_b = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    sp_p sp(random_a);
                    sp += random_b;
                    CHECK(sp == std::remove_cvref_t<sp_p>(random_a + random_b));
                }

                TEST_CASE_TEMPLATE("should return itself", sp_p, types, volatiles)
                {
                    using value_t = sp_p::value_t;

                    const value_t random_a = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    const value_t random_b = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    sp_p sp(random_a);
                    CHECK(&(sp += random_b) == &sp);
                }

                TEST_CASE_TEMPLATE("should work with any integer", sp_p, types, volatiles)
                {
                    using value_t = sp_p::value_t;

                    const value_t random_a = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    const u64_t random_b = Random<u64_t>();
                    sp_p sp(random_a);
                    CHECK((sp += random_b) == std::remove_cvref_t<sp_p>(random_a + random_b));
                }
            }

            TEST_SUITE("-=()")
            {
                TEST_CASE_TEMPLATE("should set value to value - other", sp_p, types, volatiles)
                {
                    using value_t = sp_p::value_t;

                    const value_t random_a = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    const value_t random_b = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    sp_p sp(random_a);
                    sp -= random_b;
                    CHECK(sp == std::remove_cvref_t<sp_p>(random_a - random_b));
                }

                TEST_CASE_TEMPLATE("should return itself", sp_p, types, volatiles)
                {
                    using value_t = sp_p::value_t;

                    const value_t random_a = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    const value_t random_b = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    sp_p sp(random_a);
                    CHECK(&(sp -= random_b) == &sp);
                }

                TEST_CASE_TEMPLATE("should work with any integer", sp_p, types, volatiles)
                {
                    using value_t = sp_p::value_t;

                    const value_t random_a = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    const u64_t random_b = Random<u64_t>();
                    sp_p sp(random_a);
                    CHECK((sp -= random_b) == std::remove_cvref_t<sp_p>(random_a - random_b));
                }
            }

            TEST_SUITE("*=()")
            {
                TEST_CASE_TEMPLATE("should set value to value * other", sp_p, types, volatiles)
                {
                    using value_t = sp_p::value_t;

                    const value_t random_a = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    const value_t random_b = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    sp_p sp(random_a);
                    sp *= random_b;
                    CHECK(sp == std::remove_cvref_t<sp_p>(random_a * random_b));
                }

                TEST_CASE_TEMPLATE("should return itself", sp_p, types, volatiles)
                {
                    using value_t = sp_p::value_t;

                    const value_t random_a = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    const value_t random_b = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    sp_p sp(random_a);
                    CHECK(&(sp *= random_b) == &sp);
                }

                TEST_CASE_TEMPLATE("should work with any integer", sp_p, types, volatiles)
                {
                    using value_t = sp_p::value_t;

                    const value_t random_a = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    const u64_t random_b = Random<u64_t>();
                    sp_p sp(random_a);
                    CHECK((sp *= random_b) == std::remove_cvref_t<sp_p>(random_a * random_b));
                }
            }

            TEST_SUITE("/=()")
            {
                TEST_CASE_TEMPLATE("should set value to value / other", sp_p, types, volatiles)
                {
                    using value_t = sp_p::value_t;

                    const value_t random_a = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    const value_t random_b = Random<value_t>(sp_p::MIN + 1, sp_p::MAX);
                    sp_p sp(random_a);
                    sp /= random_b;
                    CHECK(sp == std::remove_cvref_t<sp_p>(random_a / random_b));
                }

                TEST_CASE_TEMPLATE("should return itself", sp_p, types, volatiles)
                {
                    using value_t = sp_p::value_t;

                    const value_t random_a = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    const value_t random_b = Random<value_t>(sp_p::MIN + 1, sp_p::MAX);
                    sp_p sp(random_a);
                    CHECK(&(sp /= random_b) == &sp);
                }

                TEST_CASE_TEMPLATE("should work with any integer", sp_p, types, volatiles)
                {
                    using value_t = sp_p::value_t;

                    const value_t random_a = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    u64_t random_b;
                    do {
                        random_b = Random<u64_t>();
                    } while (random_b == 0);
                    sp_p sp(random_a);
                    CHECK((sp /= random_b) == std::remove_cvref_t<sp_p>(random_a / random_b));
                }
            }

            TEST_SUITE("%=()")
            {
                TEST_CASE_TEMPLATE("should set value to value % other", sp_p, types, volatiles)
                {
                    using value_t = sp_p::value_t;

                    const value_t random_a = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    const value_t random_b = Random<value_t>(sp_p::MIN + 1, sp_p::MAX);
                    sp_p sp(random_a);
                    sp %= random_b;
                    CHECK(sp == std::remove_cvref_t<sp_p>(random_a % random_b));
                }

                TEST_CASE_TEMPLATE("should return itself", sp_p, types, volatiles)
                {
                    using value_t = sp_p::value_t;

                    const value_t random_a = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    const value_t random_b = Random<value_t>(sp_p::MIN + 1, sp_p::MAX);
                    sp_p sp(random_a);
                    CHECK(&(sp %= random_b) == &sp);
                }

                TEST_CASE_TEMPLATE("should work with any integer", sp_p, types, volatiles)
                {
                    using value_t = sp_p::value_t;

                    const value_t random_a = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    u64_t random_b;
                    do {
                        random_b = Random<u64_t>();
                    } while (random_b == 0);
                    sp_p sp(random_a);
                    CHECK((sp %= random_b) == std::remove_cvref_t<sp_p>(random_a % random_b));
                }
            }

            TEST_SUITE("|=()")
            {
                TEST_CASE_TEMPLATE("should set value to value | other", sp_p, types, volatiles)
                {
                    using value_t = sp_p::value_t;

                    const value_t random_a = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    const value_t random_b = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    sp_p sp(random_a);
                    sp |= random_b;
                    CHECK(sp == std::remove_cvref_t<sp_p>(random_a | random_b));
                }

                TEST_CASE_TEMPLATE("should return itself", sp_p, types, volatiles)
                {
                    using value_t = sp_p::value_t;

                    const value_t random_a = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    const value_t random_b = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    sp_p sp(random_a);
                    CHECK(&(sp |= random_b) == &sp);
                }

                TEST_CASE_TEMPLATE("should work with any integer", sp_p, types, volatiles)
                {
                    using value_t = sp_p::value_t;

                    const value_t random_a = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    const u64_t random_b = Random<u64_t>();
                    sp_p sp(random_a);
                    CHECK((sp |= random_b) == std::remove_cvref_t<sp_p>(random_a | random_b));
                }
            }

            TEST_SUITE("&=()")
            {
                TEST_CASE_TEMPLATE("should set value to value & other", sp_p, types, volatiles)
                {
                    using value_t = sp_p::value_t;

                    const value_t random_a = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    const value_t random_b = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    sp_p sp(random_a);
                    sp &= random_b;
                    CHECK(sp == std::remove_cvref_t<sp_p>(random_a & random_b));
                }

                TEST_CASE_TEMPLATE("should return itself", sp_p, types, volatiles)
                {
                    using value_t = sp_p::value_t;

                    const value_t random_a = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    const value_t random_b = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    sp_p sp(random_a);
                    CHECK(&(sp &= random_b) == &sp);
                }

                TEST_CASE_TEMPLATE("should work with any integer", sp_p, types, volatiles)
                {
                    using value_t = sp_p::value_t;

                    const value_t random_a = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    const u64_t random_b = Random<u64_t>();
                    sp_p sp(random_a);
                    CHECK((sp &= random_b) == std::remove_cvref_t<sp_p>(random_a & random_b));
                }
            }

            TEST_SUITE("^=()")
            {
                TEST_CASE_TEMPLATE("should set value to value ^ other", sp_p, types, volatiles)
                {
                    using value_t = sp_p::value_t;

                    const value_t random_a = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    const value_t random_b = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    sp_p sp(random_a);
                    sp ^= random_b;
                    CHECK(sp == std::remove_cvref_t<sp_p>(random_a ^ random_b));
                }

                TEST_CASE_TEMPLATE("should return itself", sp_p, types, volatiles)
                {
                    using value_t = sp_p::value_t;

                    const value_t random_a = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    const value_t random_b = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    sp_p sp(random_a);
                    CHECK(&(sp ^= random_b) == &sp);
                }

                TEST_CASE_TEMPLATE("should work with any integer", sp_p, types, volatiles)
                {
                    using value_t = sp_p::value_t;

                    const value_t random_a = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    const u64_t random_b = Random<u64_t>();
                    sp_p sp(random_a);
                    CHECK((sp ^= random_b) == std::remove_cvref_t<sp_p>(random_a ^ random_b));
                }
            }

            TEST_SUITE("<<=()")
            {
                TEST_CASE_TEMPLATE("should set value to value << other", sp_p, types, volatiles)
                {
                    using value_t = sp_p::value_t;

                    const value_t random_a = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    const value_t random_b = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    sp_p sp(random_a);
                    sp <<= random_b;
                    CHECK(sp == std::remove_cvref_t<sp_p>(random_a << random_b));
                }

                TEST_CASE_TEMPLATE("should return itself", sp_p, types, volatiles)
                {
                    using value_t = sp_p::value_t;

                    const value_t random_a = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    const value_t random_b = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    sp_p sp(random_a);
                    CHECK(&(sp <<= random_b) == &sp);
                }

                TEST_CASE_TEMPLATE("should work with any integer", sp_p, types, volatiles)
                {
                    using value_t = sp_p::value_t;

                    const value_t random_a = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    const u64_t random_b = Random<u64_t>();
                    sp_p sp(random_a);
                    CHECK((sp <<= random_b) == std::remove_cvref_t<sp_p>(random_a << random_b));
                }
            }

            TEST_SUITE(">>=()")
            {
                TEST_CASE_TEMPLATE("should set value to value >> other", sp_p, types, volatiles)
                {
                    using value_t = sp_p::value_t;

                    const value_t random_a = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    const value_t random_b = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    sp_p sp(random_a);
                    sp >>= random_b;
                    CHECK(sp == std::remove_cvref_t<sp_p>(random_a >> random_b));
                }

                TEST_CASE_TEMPLATE("should return itself", sp_p, types, volatiles)
                {
                    using value_t = sp_p::value_t;

                    const value_t random_a = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    const value_t random_b = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    sp_p sp(random_a);
                    CHECK(&(sp >>= random_b) == &sp);
                }

                TEST_CASE_TEMPLATE("should work with any integer", sp_p, types, volatiles)
                {
                    using value_t = sp_p::value_t;

                    const value_t random_a = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    const u64_t random_b = Random<u64_t>();
                    sp_p sp(random_a);
                    CHECK((sp >>= random_b) == std::remove_cvref_t<sp_p>(random_a >> random_b));
                }
            }

            TEST_SUITE("++()")
            {
                TEST_CASE_TEMPLATE("should set value to value + 1", sp_p, types, volatiles)
                {
                    using value_t = sp_p::value_t;

                    const value_t random = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    sp_p sp(random);
                    ++sp;
                    CHECK(sp == std::remove_cvref_t<sp_p>(random + 1));
                }

                TEST_CASE_TEMPLATE("should return itself", sp_p, types, volatiles)
                {
                    using value_t = sp_p::value_t;

                    const value_t random = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    sp_p sp(random);
                    CHECK(&(++sp) == &sp);
                }
            }

            TEST_SUITE("++(int)")
            {
                TEST_CASE_TEMPLATE("should set value to value + 1", sp_p, types, volatiles)
                {
                    using value_t = sp_p::value_t;

                    const value_t random = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    sp_p sp(random);
                    sp++;
                    CHECK(sp == std::remove_cvref_t<sp_p>(random + 1));
                }

                TEST_CASE_TEMPLATE("should return the old value", sp_p, types, volatiles)
                {
                    using value_t = sp_p::value_t;

                    const value_t random = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    sp_p sp(random);
                    CHECK(sp++ == random);
                }
            }

            TEST_SUITE("--()")
            {
                TEST_CASE_TEMPLATE("should set value to value - 1", sp_p, types, volatiles)
                {
                    using value_t = sp_p::value_t;

                    const value_t random = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    sp_p sp(random);
                    --sp;
                    CHECK(sp == std::remove_cvref_t<sp_p>(random - 1));
                }

                TEST_CASE_TEMPLATE("should return itself", sp_p, types, volatiles)
                {
                    using value_t = sp_p::value_t;

                    const value_t random = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    sp_p sp(random);
                    CHECK(&(--sp) == &sp);
                }
            }

            TEST_SUITE("--(int)")
            {
                TEST_CASE_TEMPLATE("should set value to value - 1", sp_p, types, volatiles)
                {
                    using value_t = sp_p::value_t;

                    const value_t random = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    sp_p sp(random);
                    sp--;
                    CHECK(sp == std::remove_cvref_t<sp_p>(random - 1));
                }

                TEST_CASE_TEMPLATE("should return the old value", sp_p, types, volatiles)
                {
                    using value_t = sp_p::value_t;

                    const value_t random = Random<value_t>(sp_p::MIN, sp_p::MAX);
                    sp_p sp(random);
                    CHECK(sp-- == random);
                }
            }
        }

    #undef types
    #undef consts
    #undef volatiles
    #undef volatile_consts
    }

}
