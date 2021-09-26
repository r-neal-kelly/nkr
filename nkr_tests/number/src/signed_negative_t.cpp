/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/intrinsics.h"
#include "nkr/random.h"
#include "nkr/signed_negative_t.h"

#include "doctest.h"

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
        const volatile sn8_t,   \
        const volatile sn16_t,  \
        const volatile sn32_t,  \
        const volatile sn64_t

        TEST_SUITE("aliases")
        {
            TEST_SUITE("value_t")
            {
                TEST_CASE_TEMPLATE("should equal the passed in type", sn_p, types, consts, volatiles, volatile_consts)
                {
                    if constexpr (is_tr<std::remove_cvref_t<sn_p>, sn8_t>) {
                        static_assert(is_tr<sn_p::value_t, s8_t>);
                    } else if constexpr (is_tr<std::remove_cvref_t<sn_p>, sn16_t>) {
                        static_assert(is_tr<sn_p::value_t, s16_t>);
                    } else if constexpr (is_tr<std::remove_cvref_t<sn_p>, sn32_t>) {
                        static_assert(is_tr<sn_p::value_t, s32_t>);
                    } else if constexpr (is_tr<std::remove_cvref_t<sn_p>, sn64_t>) {
                        static_assert(is_tr<sn_p::value_t, s64_t>);
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
                    static_assert(is_tr<decltype(sn_p::value), sn_p::value_t>);
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

            TEST_SUITE("value_ctor()")
            {
                TEST_CASE_TEMPLATE("should explicitly set passed value", sn_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sn_p::value_t;

                    const value_t random = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    sn_p sn(random);
                    CHECK(sn == random);
                }

                TEST_CASE_TEMPLATE("should implicitly set passed value", sn_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sn_p::value_t;

                    const value_t random = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    sn_p sn = random;
                    CHECK(sn == random);
                }

                TEST_CASE_TEMPLATE("should work with any integer", sn_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sn_p::value_t;

                    const u64_t random = Random<u64_t>();
                    sn_p sn(random);
                    CHECK(sn == sn_p::To_Value(random));
                }

                TEST_CASE_TEMPLATE("should wrap any positive numbers to be negative", sn_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sn_p::value_t;

                    const u64_t random = Random<u64_t>(0, std::numeric_limits<u64_t>::max());
                    sn_p sn(random);
                    CHECK(sn >= sn_p::MIN && sn <= sn_p::MAX);
                }

                TEST_CASE_TEMPLATE("should wrap any negative numbers to be in range", sn_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sn_p::value_t;

                    const s64_t random = Random<s64_t>(std::numeric_limits<s64_t>::lowest(),
                                                       std::numeric_limits<value_t>::lowest());
                    sn_p sn(random);
                    CHECK(sn >= sn_p::MIN && sn <= sn_p::MAX);
                }

                TEST_CASE_TEMPLATE("should equate MAX when passed MIN - 1", sn_p, types, consts, volatiles, volatile_consts)
                {
                    sn_p sn(static_cast<u64_t>(sn_p::MIN) - static_cast<u64_t>(1));
                    CHECK(sn == sn_p::MAX);
                }

                TEST_CASE_TEMPLATE("should equate MIN when passed MAX + 1", sn_p, types, consts, volatiles, volatile_consts)
                {
                    sn_p sn(static_cast<u64_t>(sn_p::MAX) + static_cast<u64_t>(1));
                    CHECK(sn == sn_p::MIN);
                }
            }

            TEST_SUITE("copy_ctor()")
            {
                TEST_CASE_TEMPLATE("should explicitly copy the value of other", sn_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sn_p::value_t;

                    const value_t random = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    sn_p other(random);
                    sn_p sn(other);
                    CHECK(sn == random);
                }

                TEST_CASE_TEMPLATE("should implicitly copy the value of other", sn_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sn_p::value_t;

                    const value_t random = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    sn_p other(random);
                    sn_p sn = other;
                    CHECK(sn == random);
                }

                TEST_CASE_TEMPLATE("should not alter the value of other", sn_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sn_p::value_t;

                    const value_t random = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    sn_p other(random);
                    sn_p sn(other);
                    CHECK(other == random);
                }
            }

            TEST_SUITE("move_ctor()")
            {
                TEST_CASE_TEMPLATE("should explicitly move the value of other", sn_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sn_p::value_t;
                    using other_t = std::remove_const_t<sn_p>;

                    const value_t random = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    other_t other(random);
                    sn_p sn(std::move(other));
                    CHECK(sn == random);
                }

                TEST_CASE_TEMPLATE("should implicitly move the value of other", sn_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sn_p::value_t;
                    using other_t = std::remove_const_t<sn_p>;

                    const value_t random = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    other_t other(random);
                    sn_p sn = std::move(other);
                    CHECK(sn == random);
                }

                TEST_CASE_TEMPLATE("should set the value of other to the default", sn_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sn_p::value_t;
                    using other_t = std::remove_const_t<sn_p>;

                    const value_t random = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    other_t other(random);
                    sn_p sn(std::move(other));
                    CHECK(other == sn_p::MAX);
                }
            }

            TEST_SUITE("value_assignment_ctor()")
            {
                TEST_CASE_TEMPLATE("should set passed value", sn_p, types, volatiles)
                {
                    using value_t = sn_p::value_t;

                    const value_t random = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    sn_p sn;
                    sn = random;
                    CHECK(sn == random);
                }

                TEST_CASE_TEMPLATE("should return itself", sn_p, types, volatiles)
                {
                    using value_t = sn_p::value_t;

                    const value_t random = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    sn_p sn;
                    CHECK(&(sn = random) == &sn);
                }

                TEST_CASE_TEMPLATE("should work with any integer", sn_p, types, volatiles)
                {
                    using value_t = sn_p::value_t;

                    const u64_t random = Random<u64_t>();
                    sn_p sn;
                    sn = random;
                    CHECK(sn == sn_p::To_Value(random));
                }

                TEST_CASE_TEMPLATE("should wrap any positive numbers to be negative", sn_p, types, volatiles)
                {
                    using value_t = sn_p::value_t;

                    const u64_t random = Random<u64_t>(0, std::numeric_limits<u64_t>::max());
                    sn_p sn;
                    sn = random;
                    CHECK(sn >= sn_p::MIN && sn <= sn_p::MAX);
                }

                TEST_CASE_TEMPLATE("should wrap any negative numbers to be in range", sn_p, types, volatiles)
                {
                    using value_t = sn_p::value_t;

                    const s64_t random = Random<s64_t>(std::numeric_limits<s64_t>::lowest(),
                                                       std::numeric_limits<value_t>::lowest());
                    sn_p sn;
                    sn = random;
                    CHECK(sn >= sn_p::MIN && sn <= sn_p::MAX);
                }

                TEST_CASE_TEMPLATE("should equate MAX when passed MIN - 1", sn_p, types, volatiles)
                {
                    sn_p sn;
                    sn = static_cast<u64_t>(sn_p::MIN) - static_cast<u64_t>(1);
                    CHECK(sn == sn_p::MAX);
                }

                TEST_CASE_TEMPLATE("should equate MIN when passed MAX + 1", sn_p, types, volatiles)
                {
                    sn_p sn;
                    sn = static_cast<u64_t>(sn_p::MAX) + static_cast<u64_t>(1);
                    CHECK(sn == sn_p::MIN);
                }
            }

            TEST_SUITE("copy_assignment_ctor()")
            {
                TEST_CASE_TEMPLATE("should copy the value of other", sn_p, types, volatiles)
                {
                    using value_t = sn_p::value_t;

                    const value_t random = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    const sn_p other(random);
                    sn_p sn;
                    sn = other;
                    CHECK(sn == random);
                }

                TEST_CASE_TEMPLATE("should return itself", sn_p, types, volatiles)
                {
                    using value_t = sn_p::value_t;

                    const value_t random = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    const sn_p other(random);
                    sn_p sn;
                    CHECK(&(sn = other) == &sn);
                }

                TEST_CASE_TEMPLATE("should not alter the value of other", sn_p, types, volatiles)
                {
                    using value_t = sn_p::value_t;

                    const value_t random = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    const sn_p other(random);
                    sn_p sn;
                    sn = other;
                    CHECK(other == random);
                }
            }

            TEST_SUITE("move_assignment_ctor()")
            {
                TEST_CASE_TEMPLATE("should move the value of other", sn_p, types, volatiles)
                {
                    using value_t = sn_p::value_t;

                    const value_t random = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    sn_p other(random);
                    sn_p sn;
                    sn = std::move(other);
                    CHECK(sn == random);
                }

                TEST_CASE_TEMPLATE("should return itself", sn_p, types, volatiles)
                {
                    using value_t = sn_p::value_t;

                    const value_t random = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    sn_p other(random);
                    sn_p sn;
                    CHECK(&(sn = std::move(other)) == &sn);
                }

                TEST_CASE_TEMPLATE("should set the value of other to the default", sn_p, types, volatiles)
                {
                    using value_t = sn_p::value_t;

                    const value_t random = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    sn_p other(random);
                    sn_p sn;
                    sn = std::move(other);
                    CHECK(other == sn_p::MAX);
                }
            }

            TEST_SUITE("dtor()")
            {
                TEST_CASE_TEMPLATE("should set value to the default", sn_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sn_p::value_t;

                    const value_t random = Random<value_t>();
                    sn_p sn(random);
                    sn.~sn_p();
                    CHECK(sn == sn_p::MAX);
                }
            }
        }

        TEST_SUITE("casts")
        {
            TEST_SUITE("value_t()")
            {
                TEST_CASE_TEMPLATE("should explicitly return a copy of its value", sn_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sn_p::value_t;

                    const value_t random = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    sn_p sn(random);
                    value_t value = static_cast<value_t>(sn);
                    CHECK(value == random);
                }

                TEST_CASE_TEMPLATE("should implicitly return a copy of its value", sn_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sn_p::value_t;

                    const value_t random = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    sn_p sn(random);
                    value_t value = sn;
                    CHECK(value == random);
                }

                TEST_CASE_TEMPLATE("should not change its value", sn_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sn_p::value_t;

                    const value_t random = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    sn_p sn(random);
                    value_t value = sn;
                    CHECK(sn == random);
                }

                TEST_CASE_TEMPLATE("should implicitly allow for logical operators", sn_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sn_p::value_t;

                    const value_t random = Random<value_t>(sn_p::MIN, sn_p::MAX - 1);
                    sn_p sn(random);
                    CHECK(sn);
                    CHECK(!!sn);
                    CHECK(sn || false);
                    CHECK(sn && true);
                    CHECK(sn ? true : false);
                }

                TEST_CASE_TEMPLATE("should implicitly allow for comparison operators", sn_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sn_p::value_t;

                    const value_t random = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    sn_p sn(random);
                    CHECK(sn == random);
                    CHECK_FALSE(sn != random);
                    CHECK_FALSE(sn < random);
                    CHECK_FALSE(sn > random);
                    CHECK(sn <= random);
                    CHECK(sn >= random);
                    CHECK((sn <=> random == 0));
                }
            }
        }

        TEST_SUITE("operators")
        {
            TEST_SUITE("+()")
            {
                TEST_CASE_TEMPLATE("should return value + other", sn_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sn_p::value_t;

                    const value_t random_a = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    const value_t random_b = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    sn_p sn(random_a);
                    CHECK((sn + random_b) == (random_a + random_b));
                }

                TEST_CASE_TEMPLATE("should not change its value", sn_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sn_p::value_t;

                    const value_t random_a = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    const value_t random_b = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    sn_p sn(random_a);
                    value_t value = sn + random_b;
                    CHECK(sn == random_a);
                }

                TEST_CASE_TEMPLATE("should work with any integer", sn_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sn_p::value_t;

                    const value_t random_a = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    const u64_t random_b = Random<u64_t>();
                    sn_p sn(random_a);
                    CHECK((sn + random_b) == (random_a + random_b));
                }
            }

            TEST_SUITE("-()")
            {
                TEST_CASE_TEMPLATE("should return value - other", sn_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sn_p::value_t;

                    const value_t random_a = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    const value_t random_b = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    sn_p sn(random_a);
                    CHECK((sn - random_b) == (random_a - random_b));
                }

                TEST_CASE_TEMPLATE("should not change its value", sn_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sn_p::value_t;

                    const value_t random_a = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    const value_t random_b = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    sn_p sn(random_a);
                    value_t value = sn - random_b;
                    CHECK(sn == random_a);
                }

                TEST_CASE_TEMPLATE("should work with any integer", sn_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sn_p::value_t;

                    const value_t random_a = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    const u64_t random_b = Random<u64_t>();
                    sn_p sn(random_a);
                    CHECK((sn - random_b) == (random_a - random_b));
                }
            }

            TEST_SUITE("*()")
            {
                TEST_CASE_TEMPLATE("should return value * other", sn_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sn_p::value_t;

                    const value_t random_a = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    const value_t random_b = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    sn_p sn(random_a);
                    CHECK((sn * random_b) == (random_a * random_b));
                }

                TEST_CASE_TEMPLATE("should not change its value", sn_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sn_p::value_t;

                    const value_t random_a = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    const value_t random_b = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    sn_p sn(random_a);
                    value_t value = sn * random_b;
                    CHECK(sn == random_a);
                }

                TEST_CASE_TEMPLATE("should work with any integer", sn_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sn_p::value_t;

                    const value_t random_a = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    const u64_t random_b = Random<u64_t>();
                    sn_p sn(random_a);
                    CHECK((sn * random_b) == (random_a * random_b));
                }
            }

            TEST_SUITE("/()")
            {
                TEST_CASE_TEMPLATE("should return value / other", sn_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sn_p::value_t;

                    const value_t random_a = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    const value_t random_b = Random<value_t>(sn_p::MIN, sn_p::MAX - 1);
                    sn_p sn(random_a);
                    CHECK((sn / random_b) == (random_a / random_b));
                }

                TEST_CASE_TEMPLATE("should not change its value", sn_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sn_p::value_t;

                    const value_t random_a = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    const value_t random_b = Random<value_t>(sn_p::MIN, sn_p::MAX - 1);
                    sn_p sn(random_a);
                    value_t value = sn / random_b;
                    CHECK(sn == random_a);
                }

                TEST_CASE_TEMPLATE("should work with any integer", sn_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sn_p::value_t;

                    const value_t random_a = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    u64_t random_b;
                    do {
                        random_b = Random<u64_t>();
                    } while (random_b == 0);
                    sn_p sn(random_a);
                    CHECK((sn / random_b) == (random_a / random_b));
                }
            }

            TEST_SUITE("%()")
            {
                TEST_CASE_TEMPLATE("should return value % other", sn_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sn_p::value_t;

                    const value_t random_a = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    const value_t random_b = Random<value_t>(sn_p::MIN, sn_p::MAX - 1);
                    sn_p sn(random_a);
                    CHECK((sn % random_b) == (random_a % random_b));
                }

                TEST_CASE_TEMPLATE("should not change its value", sn_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sn_p::value_t;

                    const value_t random_a = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    const value_t random_b = Random<value_t>(sn_p::MIN, sn_p::MAX - 1);
                    sn_p sn(random_a);
                    value_t value = sn % random_b;
                    CHECK(sn == random_a);
                }

                TEST_CASE_TEMPLATE("should work with any integer", sn_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sn_p::value_t;

                    const value_t random_a = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    u64_t random_b;
                    do {
                        random_b = Random<u64_t>();
                    } while (random_b == 0);
                    sn_p sn(random_a);
                    CHECK((sn % random_b) == (random_a % random_b));
                }
            }

            TEST_SUITE("~()")
            {
                TEST_CASE_TEMPLATE("should return ~value without changing signedness", sn_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sn_p::value_t;

                    sn_p sn;
                    if constexpr (sizeof(value_t) == sizeof(s8_t)) {
                        CHECK(~sn == static_cast<s8_t>(0xFF));
                    } else if constexpr (sizeof(value_t) == sizeof(s16_t)) {
                        CHECK(~sn == static_cast<s16_t>(0xFFFF));
                    } else if constexpr (sizeof(value_t) == sizeof(s32_t)) {
                        CHECK(~sn == static_cast<s32_t>(0xFFFFFFFF));
                    } else if constexpr (sizeof(value_t) == sizeof(s64_t)) {
                        CHECK(~sn == static_cast<s64_t>(0xFFFFFFFFFFFFFFFF));
                    }
                }
            }

            TEST_SUITE("|()")
            {
                TEST_CASE_TEMPLATE("should return value | other", sn_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sn_p::value_t;

                    const value_t random_a = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    const value_t random_b = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    sn_p sn(random_a);
                    CHECK((sn | random_b) == (random_a | random_b));
                }

                TEST_CASE_TEMPLATE("should not change its value", sn_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sn_p::value_t;

                    const value_t random_a = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    const value_t random_b = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    sn_p sn(random_a);
                    value_t value = sn | random_b;
                    CHECK(sn == random_a);
                }

                TEST_CASE_TEMPLATE("should work with any integer", sn_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sn_p::value_t;

                    const value_t random_a = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    const u64_t random_b = Random<u64_t>();
                    sn_p sn(random_a);
                    CHECK((sn | random_b) == (random_a | random_b));
                }
            }

            TEST_SUITE("&()")
            {
                TEST_CASE_TEMPLATE("should return value & other", sn_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sn_p::value_t;

                    const value_t random_a = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    const value_t random_b = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    sn_p sn(random_a);
                    CHECK((sn & random_b) == (random_a & random_b));
                }

                TEST_CASE_TEMPLATE("should not change its value", sn_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sn_p::value_t;

                    const value_t random_a = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    const value_t random_b = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    sn_p sn(random_a);
                    value_t value = sn & random_b;
                    CHECK(sn == random_a);
                }

                TEST_CASE_TEMPLATE("should work with any integer", sn_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sn_p::value_t;

                    const value_t random_a = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    const u64_t random_b = Random<u64_t>();
                    sn_p sn(random_a);
                    CHECK((sn & random_b) == (random_a & random_b));
                }
            }

            TEST_SUITE("^()")
            {
                TEST_CASE_TEMPLATE("should return value ^ other", sn_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sn_p::value_t;

                    const value_t random_a = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    const value_t random_b = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    sn_p sn(random_a);
                    CHECK((sn ^ random_b) == (random_a ^ random_b));
                }

                TEST_CASE_TEMPLATE("should not change its value", sn_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sn_p::value_t;

                    const value_t random_a = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    const value_t random_b = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    sn_p sn(random_a);
                    value_t value = sn ^ random_b;
                    CHECK(sn == random_a);
                }

                TEST_CASE_TEMPLATE("should work with any integer", sn_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sn_p::value_t;

                    const value_t random_a = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    const u64_t random_b = Random<u64_t>();
                    sn_p sn(random_a);
                    CHECK((sn ^ random_b) == (random_a ^ random_b));
                }
            }

            TEST_SUITE(">>()")
            {
                TEST_CASE_TEMPLATE("should return value >> other", sn_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sn_p::value_t;

                    const value_t random_a = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    const value_t random_b = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    sn_p sn(random_a);
                    CHECK((sn >> random_b) == (random_a >> random_b));
                }

                TEST_CASE_TEMPLATE("should not change its value", sn_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sn_p::value_t;

                    const value_t random_a = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    const value_t random_b = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    sn_p sn(random_a);
                    value_t value = sn >> random_b;
                    CHECK(sn == random_a);
                }

                TEST_CASE_TEMPLATE("should work with any integer", sn_p, types, consts, volatiles, volatile_consts)
                {
                    using value_t = sn_p::value_t;

                    const value_t random_a = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    const u64_t random_b = Random<u64_t>();
                    sn_p sn(random_a);
                    CHECK((sn >> random_b) == (random_a >> random_b));
                }
            }

            TEST_SUITE("+=()")
            {
                TEST_CASE_TEMPLATE("should set value to value + other", sn_p, types, volatiles)
                {
                    using value_t = sn_p::value_t;

                    const value_t random_a = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    const value_t random_b = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    sn_p sn(random_a);
                    sn += random_b;
                    CHECK(sn == std::remove_cvref_t<sn_p>(random_a + random_b));
                }

                TEST_CASE_TEMPLATE("should return itself", sn_p, types, volatiles)
                {
                    using value_t = sn_p::value_t;

                    const value_t random_a = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    const value_t random_b = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    sn_p sn(random_a);
                    CHECK(&(sn += random_b) == &sn);
                }

                TEST_CASE_TEMPLATE("should work with any integer", sn_p, types, volatiles)
                {
                    using value_t = sn_p::value_t;

                    const value_t random_a = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    const u64_t random_b = Random<u64_t>();
                    sn_p sn(random_a);
                    CHECK((sn += random_b) == std::remove_cvref_t<sn_p>(random_a + random_b));
                }
            }

            TEST_SUITE("-=()")
            {
                TEST_CASE_TEMPLATE("should set value to value - other", sn_p, types, volatiles)
                {
                    using value_t = sn_p::value_t;

                    const value_t random_a = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    const value_t random_b = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    sn_p sn(random_a);
                    sn -= random_b;
                    CHECK(sn == std::remove_cvref_t<sn_p>(random_a - random_b));
                }

                TEST_CASE_TEMPLATE("should return itself", sn_p, types, volatiles)
                {
                    using value_t = sn_p::value_t;

                    const value_t random_a = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    const value_t random_b = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    sn_p sn(random_a);
                    CHECK(&(sn -= random_b) == &sn);
                }

                TEST_CASE_TEMPLATE("should work with any integer", sn_p, types, volatiles)
                {
                    using value_t = sn_p::value_t;

                    const value_t random_a = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    const u64_t random_b = Random<u64_t>();
                    sn_p sn(random_a);
                    CHECK((sn -= random_b) == std::remove_cvref_t<sn_p>(random_a - random_b));
                }
            }

            TEST_SUITE("*=()")
            {
                TEST_CASE_TEMPLATE("should set value to value * other", sn_p, types, volatiles)
                {
                    using value_t = sn_p::value_t;

                    const value_t random_a = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    const value_t random_b = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    sn_p sn(random_a);
                    sn *= random_b;
                    CHECK(sn == std::remove_cvref_t<sn_p>(random_a * random_b));
                }

                TEST_CASE_TEMPLATE("should return itself", sn_p, types, volatiles)
                {
                    using value_t = sn_p::value_t;

                    const value_t random_a = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    const value_t random_b = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    sn_p sn(random_a);
                    CHECK(&(sn *= random_b) == &sn);
                }

                TEST_CASE_TEMPLATE("should work with any integer", sn_p, types, volatiles)
                {
                    using value_t = sn_p::value_t;

                    const value_t random_a = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    const u64_t random_b = Random<u64_t>();
                    sn_p sn(random_a);
                    CHECK((sn *= random_b) == std::remove_cvref_t<sn_p>(random_a * random_b));
                }
            }

            TEST_SUITE("/=()")
            {
                TEST_CASE_TEMPLATE("should set value to value / other", sn_p, types, volatiles)
                {
                    using value_t = sn_p::value_t;

                    const value_t random_a = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    const value_t random_b = Random<value_t>(sn_p::MIN, sn_p::MAX - 1);
                    sn_p sn(random_a);
                    sn /= random_b;
                    CHECK(sn == std::remove_cvref_t<sn_p>(random_a / random_b));
                }

                TEST_CASE_TEMPLATE("should return itself", sn_p, types, volatiles)
                {
                    using value_t = sn_p::value_t;

                    const value_t random_a = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    const value_t random_b = Random<value_t>(sn_p::MIN, sn_p::MAX - 1);
                    sn_p sn(random_a);
                    CHECK(&(sn /= random_b) == &sn);
                }

                TEST_CASE_TEMPLATE("should work with any integer", sn_p, types, volatiles)
                {
                    using value_t = sn_p::value_t;

                    const value_t random_a = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    u64_t random_b;
                    do {
                        random_b = Random<u64_t>();
                    } while (random_b == 0);
                    sn_p sn(random_a);
                    CHECK((sn /= random_b) == std::remove_cvref_t<sn_p>(random_a / random_b));
                }
            }

            TEST_SUITE("%=()")
            {
                TEST_CASE_TEMPLATE("should set value to value % other", sn_p, types, volatiles)
                {
                    using value_t = sn_p::value_t;

                    const value_t random_a = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    const value_t random_b = Random<value_t>(sn_p::MIN, sn_p::MAX - 1);
                    sn_p sn(random_a);
                    sn %= random_b;
                    CHECK(sn == std::remove_cvref_t<sn_p>(random_a % random_b));
                }

                TEST_CASE_TEMPLATE("should return itself", sn_p, types, volatiles)
                {
                    using value_t = sn_p::value_t;

                    const value_t random_a = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    const value_t random_b = Random<value_t>(sn_p::MIN, sn_p::MAX - 1);
                    sn_p sn(random_a);
                    CHECK(&(sn %= random_b) == &sn);
                }

                TEST_CASE_TEMPLATE("should work with any integer", sn_p, types, volatiles)
                {
                    using value_t = sn_p::value_t;

                    const value_t random_a = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    u64_t random_b;
                    do {
                        random_b = Random<u64_t>();
                    } while (random_b == 0);
                    sn_p sn(random_a);
                    CHECK((sn %= random_b) == std::remove_cvref_t<sn_p>(random_a % random_b));
                }
            }

            TEST_SUITE("|=()")
            {
                TEST_CASE_TEMPLATE("should set value to value | other", sn_p, types, volatiles)
                {
                    using value_t = sn_p::value_t;

                    const value_t random_a = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    const value_t random_b = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    sn_p sn(random_a);
                    sn |= random_b;
                    CHECK(sn == std::remove_cvref_t<sn_p>(random_a | random_b));
                }

                TEST_CASE_TEMPLATE("should return itself", sn_p, types, volatiles)
                {
                    using value_t = sn_p::value_t;

                    const value_t random_a = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    const value_t random_b = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    sn_p sn(random_a);
                    CHECK(&(sn |= random_b) == &sn);
                }

                TEST_CASE_TEMPLATE("should work with any integer", sn_p, types, volatiles)
                {
                    using value_t = sn_p::value_t;

                    const value_t random_a = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    const u64_t random_b = Random<u64_t>();
                    sn_p sn(random_a);
                    CHECK((sn |= random_b) == std::remove_cvref_t<sn_p>(random_a | random_b));
                }
            }

            TEST_SUITE("&=()")
            {
                TEST_CASE_TEMPLATE("should set value to value & other", sn_p, types, volatiles)
                {
                    using value_t = sn_p::value_t;

                    const value_t random_a = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    const value_t random_b = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    sn_p sn(random_a);
                    sn &= random_b;
                    CHECK(sn == std::remove_cvref_t<sn_p>(random_a & random_b));
                }

                TEST_CASE_TEMPLATE("should return itself", sn_p, types, volatiles)
                {
                    using value_t = sn_p::value_t;

                    const value_t random_a = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    const value_t random_b = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    sn_p sn(random_a);
                    CHECK(&(sn &= random_b) == &sn);
                }

                TEST_CASE_TEMPLATE("should work with any integer", sn_p, types, volatiles)
                {
                    using value_t = sn_p::value_t;

                    const value_t random_a = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    const u64_t random_b = Random<u64_t>();
                    sn_p sn(random_a);
                    CHECK((sn &= random_b) == std::remove_cvref_t<sn_p>(random_a & random_b));
                }
            }

            TEST_SUITE("^=()")
            {
                TEST_CASE_TEMPLATE("should set value to value ^ other", sn_p, types, volatiles)
                {
                    using value_t = sn_p::value_t;

                    const value_t random_a = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    const value_t random_b = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    sn_p sn(random_a);
                    sn ^= random_b;
                    CHECK(sn == std::remove_cvref_t<sn_p>(random_a ^ random_b));
                }

                TEST_CASE_TEMPLATE("should return itself", sn_p, types, volatiles)
                {
                    using value_t = sn_p::value_t;

                    const value_t random_a = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    const value_t random_b = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    sn_p sn(random_a);
                    CHECK(&(sn ^= random_b) == &sn);
                }

                TEST_CASE_TEMPLATE("should work with any integer", sn_p, types, volatiles)
                {
                    using value_t = sn_p::value_t;

                    const value_t random_a = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    const u64_t random_b = Random<u64_t>();
                    sn_p sn(random_a);
                    CHECK((sn ^= random_b) == std::remove_cvref_t<sn_p>(random_a ^ random_b));
                }
            }

            TEST_SUITE(">>=()")
            {
                TEST_CASE_TEMPLATE("should set value to value >> other", sn_p, types, volatiles)
                {
                    using value_t = sn_p::value_t;

                    const value_t random_a = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    const value_t random_b = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    sn_p sn(random_a);
                    sn >>= random_b;
                    CHECK(sn == std::remove_cvref_t<sn_p>(random_a >> random_b));
                }

                TEST_CASE_TEMPLATE("should return itself", sn_p, types, volatiles)
                {
                    using value_t = sn_p::value_t;

                    const value_t random_a = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    const value_t random_b = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    sn_p sn(random_a);
                    CHECK(&(sn >>= random_b) == &sn);
                }

                TEST_CASE_TEMPLATE("should work with any integer", sn_p, types, volatiles)
                {
                    using value_t = sn_p::value_t;

                    const value_t random_a = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    const u64_t random_b = Random<u64_t>();
                    sn_p sn(random_a);
                    CHECK((sn >>= random_b) == std::remove_cvref_t<sn_p>(random_a >> random_b));
                }
            }

            TEST_SUITE("++()")
            {
                TEST_CASE_TEMPLATE("should set value to value + 1", sn_p, types, volatiles)
                {
                    using value_t = sn_p::value_t;

                    const value_t random = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    sn_p sn(random);
                    ++sn;
                    CHECK(sn == std::remove_cvref_t<sn_p>(random + 1));
                }

                TEST_CASE_TEMPLATE("should return itself", sn_p, types, volatiles)
                {
                    using value_t = sn_p::value_t;

                    const value_t random = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    sn_p sn(random);
                    CHECK(&(++sn) == &sn);
                }
            }

            TEST_SUITE("++(int)")
            {
                TEST_CASE_TEMPLATE("should set value to value + 1", sn_p, types, volatiles)
                {
                    using value_t = sn_p::value_t;

                    const value_t random = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    sn_p sn(random);
                    sn++;
                    CHECK(sn == std::remove_cvref_t<sn_p>(random + 1));
                }

                TEST_CASE_TEMPLATE("should return the old value", sn_p, types, volatiles)
                {
                    using value_t = sn_p::value_t;

                    const value_t random = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    sn_p sn(random);
                    CHECK(sn++ == random);
                }
            }

            TEST_SUITE("--()")
            {
                TEST_CASE_TEMPLATE("should set value to value - 1", sn_p, types, volatiles)
                {
                    using value_t = sn_p::value_t;

                    const value_t random = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    sn_p sn(random);
                    --sn;
                    CHECK(sn == std::remove_cvref_t<sn_p>(random - 1));
                }

                TEST_CASE_TEMPLATE("should return itself", sn_p, types, volatiles)
                {
                    using value_t = sn_p::value_t;

                    const value_t random = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    sn_p sn(random);
                    CHECK(&(--sn) == &sn);
                }
            }

            TEST_SUITE("--(int)")
            {
                TEST_CASE_TEMPLATE("should set value to value - 1", sn_p, types, volatiles)
                {
                    using value_t = sn_p::value_t;

                    const value_t random = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    sn_p sn(random);
                    sn--;
                    CHECK(sn == std::remove_cvref_t<sn_p>(random - 1));
                }

                TEST_CASE_TEMPLATE("should return the old value", sn_p, types, volatiles)
                {
                    using value_t = sn_p::value_t;

                    const value_t random = Random<value_t>(sn_p::MIN, sn_p::MAX);
                    sn_p sn(random);
                    CHECK(sn-- == random);
                }
            }
        }

    #undef types
    #undef consts
    #undef volatiles
    #undef volatile_consts
    }

}
