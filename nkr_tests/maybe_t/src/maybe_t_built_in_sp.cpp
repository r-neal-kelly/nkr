/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/bool_t.h"
#include "nkr/intrinsics.h"
#include "nkr/maybe_t.h"
#include "nkr/utils.h"

#include "doctest.h"

namespace nkr {

    TEST_SUITE("maybe_t<built_in_p>")
    {
    #define nkr_QUALIFIED_VALUES(QUALIFIER_p)   \
        QUALIFIER_p u8_t,                       \
        QUALIFIER_p s8_t,                       \
        QUALIFIER_p u16_t,                      \
        QUALIFIER_p s16_t,                      \
        QUALIFIER_p u32_t,                      \
        QUALIFIER_p s32_t,                      \
        QUALIFIER_p u64_t,                      \
        QUALIFIER_p s64_t,                      \
        QUALIFIER_p c8_t,                       \
        QUALIFIER_p c16_t,                      \
        QUALIFIER_p c32_t,                      \
        QUALIFIER_p r32_t,                      \
        QUALIFIER_p r64_t,                      \
        void_t* QUALIFIER_p,                    \
        word_t* QUALIFIER_p

    #define nkr_JUST_NON_QUALIFIED_VALUES   \
        nkr_QUALIFIED_VALUES(nkr_BLANK)

    #define nkr_JUST_CONST_VALUES   \
        nkr_QUALIFIED_VALUES(const)

    #define nkr_JUST_VOLATILE_VALUES    \
        nkr_QUALIFIED_VALUES(volatile)

    #define nkr_JUST_CONST_VOLATILE_VALUES      \
        nkr_QUALIFIED_VALUES(const volatile)

    #define nkr_ALL_VALUES              \
        nkr_JUST_NON_QUALIFIED_VALUES,  \
        nkr_JUST_CONST_VALUES,          \
        nkr_JUST_VOLATILE_VALUES,       \
        nkr_JUST_CONST_VOLATILE_VALUES

    #define nkr_ALL_PARAMS(QUALIFIER_p, UNIT_p)     \
        QUALIFIER_p maybe_t<UNIT_p>,                \
        QUALIFIER_p maybe_t<const UNIT_p>,          \
        QUALIFIER_p maybe_t<volatile UNIT_p>,       \
        QUALIFIER_p maybe_t<const volatile UNIT_p>

    #define nkr_MAYBE_VALUES(QUALIFIER_p)           \
        nkr_ALL_PARAMS(QUALIFIER_p, std_bool_t),    \
        nkr_ALL_PARAMS(QUALIFIER_p, u8_t),          \
        nkr_ALL_PARAMS(QUALIFIER_p, s8_t),          \
        nkr_ALL_PARAMS(QUALIFIER_p, u16_t),         \
        nkr_ALL_PARAMS(QUALIFIER_p, s16_t),         \
        nkr_ALL_PARAMS(QUALIFIER_p, u32_t),         \
        nkr_ALL_PARAMS(QUALIFIER_p, s32_t),         \
        nkr_ALL_PARAMS(QUALIFIER_p, u64_t),         \
        nkr_ALL_PARAMS(QUALIFIER_p, s64_t),         \
        nkr_ALL_PARAMS(QUALIFIER_p, c8_t),          \
        nkr_ALL_PARAMS(QUALIFIER_p, c16_t),         \
        nkr_ALL_PARAMS(QUALIFIER_p, c32_t),         \
        nkr_ALL_PARAMS(QUALIFIER_p, r32_t),         \
        nkr_ALL_PARAMS(QUALIFIER_p, r64_t),         \
        nkr_ALL_PARAMS(QUALIFIER_p, void_t*),       \
        nkr_ALL_PARAMS(QUALIFIER_p, word_t*)

    #define nkr_NON_QUALIFIED       \
        nkr_MAYBE_VALUES(nkr_BLANK)

    #define nkr_NON_CONST               \
        nkr_MAYBE_VALUES(nkr_BLANK),    \
        nkr_MAYBE_VALUES(volatile)

    #define nkr_CONST                       \
        nkr_MAYBE_VALUES(const),            \
        nkr_MAYBE_VALUES(const volatile)

    #define nkr_ALL     \
        nkr_NON_CONST,  \
        nkr_CONST

        TEST_SUITE("aliases")
        {
            TEST_SUITE("value_t")
            {
                TEST_CASE_TEMPLATE("should have a value_t", maybe_p, nkr_ALL)
                {
                    using value_t = maybe_p::value_t;

                    static_assert(is_tr<value_t, value_t>);
                }
            }
        }

        TEST_SUITE("objects")
        {
            TEST_SUITE("default_ctor()")
            {
                TEST_CASE_TEMPLATE("should equal the default value", maybe_p, nkr_ALL)
                {
                    using value_t = maybe_p::value_t;

                    value_t value = static_cast<std::remove_cv_t<value_t>>(0);
                    maybe_p maybe;
                    CHECK(maybe == value);
                }

                TEST_CASE_TEMPLATE("should equal none_t()", maybe_p, nkr_ALL)
                {
                    using value_t = maybe_p::value_t;

                    maybe_p maybe;
                    CHECK(maybe == none_t());
                }
            }

            TEST_SUITE("copy_ctor()")
            {
                TEST_CASE_TEMPLATE("should copy another", maybe_p, nkr_ALL)
                {
                    using value_t = maybe_p::value_t;

                    value_t random = Random<value_t>();
                    maybe_p other = random;
                    maybe_p maybe = other;
                    CHECK(maybe == other);
                    CHECK(other == random);
                }

                TEST_CASE_TEMPLATE("should copy another value", maybe_p, nkr_ALL)
                {
                    using value_t = maybe_p::value_t;

                    value_t random = Random<value_t>();
                    value_t other = random;
                    maybe_p maybe = other;
                    CHECK(maybe == other);
                    CHECK(other == random);
                }
            }

            TEST_SUITE("move_ctor()")
            {
                TEST_CASE_TEMPLATE("should move another, setting it to none_t()", maybe_p, nkr_ALL)
                {
                    using value_t = maybe_p::value_t;

                    if constexpr (any_non_const_tr<value_t>) {
                        value_t random = Random<value_t>();
                        std::remove_const_t<maybe_p> other = random;
                        maybe_p maybe = nkr::Move(other);
                        CHECK(maybe == random);
                        CHECK(other == none_t());
                    }
                }

                TEST_CASE_TEMPLATE("should move another value, setting it to none_t()", maybe_p, nkr_ALL)
                {
                    using value_t = maybe_p::value_t;

                    value_t random = Random<value_t>();
                    std::remove_const_t<value_t> other = random;
                    maybe_p maybe = nkr::Move(other);
                    CHECK(maybe == random);
                    CHECK(other == none_t());
                }
            }

            TEST_SUITE("copy_assignment_ctor()")
            {
                TEST_CASE_TEMPLATE("should copy another", maybe_p, nkr_NON_CONST)
                {
                    using value_t = maybe_p::value_t;

                    if constexpr (any_non_const_tr<value_t>) {
                        value_t random = Random<value_t>();
                        std::add_const_t<maybe_p> other = random;
                        maybe_p maybe;
                        maybe = other;
                        CHECK(maybe == other);
                        CHECK(other == random);
                    }
                }

                TEST_CASE_TEMPLATE("should copy another value", maybe_p, nkr_NON_CONST)
                {
                    using value_t = maybe_p::value_t;

                    if constexpr (any_non_const_tr<value_t>) {
                        value_t random = Random<value_t>();
                        std::add_const_t<value_t> other = random;
                        maybe_p maybe;
                        maybe = other;
                        CHECK(maybe == other);
                        CHECK(other == random);
                    }
                }
            }

            TEST_SUITE("move_assignment_ctor()")
            {
                TEST_CASE_TEMPLATE("should move another, setting it to none_t()", maybe_p, nkr_NON_CONST)
                {
                    using value_t = maybe_p::value_t;

                    if constexpr (any_non_const_tr<value_t>) {
                        value_t random = Random<value_t>();
                        maybe_p other = random;
                        maybe_p maybe;
                        maybe = nkr::Move(other);
                        CHECK(maybe == random);
                        CHECK(other == none_t());
                    }
                }

                TEST_CASE_TEMPLATE("should move another value, setting it to none_t()", maybe_p, nkr_NON_CONST)
                {
                    using value_t = maybe_p::value_t;

                    if constexpr (any_non_const_tr<value_t>) {
                        value_t random = Random<value_t>();
                        value_t other = random;
                        maybe_p maybe;
                        maybe = nkr::Move(other);
                        CHECK(maybe == random);
                        CHECK(other == none_t());
                    }
                }
            }

            TEST_SUITE("dtor()")
            {
                TEST_CASE_TEMPLATE("should set the value to none_t()", maybe_p, nkr_ALL)
                {
                    using value_t = maybe_p::value_t;

                    if constexpr (any_non_const_tr<value_t>) {
                        value_t random = Random<value_t>();
                        maybe_p maybe = random;
                        maybe.~maybe_p();
                        CHECK(maybe == none_t());
                    }
                }
            }
        }

        TEST_SUITE("casts")
        {
            TEST_SUITE("value_t")
            {
                TEST_CASE_TEMPLATE("should explicitly return a reference to its value", maybe_p, nkr_ALL)
                {
                    using value_t = maybe_p::value_t;

                    value_t random = Random<value_t>();
                    maybe_p maybe = random;
                    if constexpr (just_non_qualified_tr<maybe_p>) {
                        CHECK(static_cast<value_t&>(maybe) == random);
                    } else if constexpr (just_const_tr<maybe_p>) {
                        CHECK(static_cast<const value_t&>(maybe) == random);
                    } else if constexpr (just_volatile_tr<maybe_p>) {
                        CHECK(static_cast<volatile value_t&>(maybe) == random);
                    } else if constexpr (just_const_volatile_tr<maybe_p>) {
                        CHECK(static_cast<const volatile value_t&>(maybe) == random);
                    }
                }

                TEST_CASE_TEMPLATE("should implicitly return a reference to its value", maybe_p, nkr_ALL)
                {
                    using value_t = maybe_p::value_t;

                    value_t random = Random<value_t>();
                    maybe_p maybe = random;
                    CHECK(maybe == random);
                }

                TEST_CASE_TEMPLATE("should be able to alter non-const values", maybe_p, nkr_NON_CONST)
                {
                    using value_t = maybe_p::value_t;

                    if constexpr (any_non_const_tr<value_t>) {
                        value_t random_a = Random<value_t>();
                        value_t random_b = Random<value_t>();
                        maybe_p maybe = random_a;
                        if constexpr (just_non_qualified_tr<maybe_p>) {
                            static_cast<value_t&>(maybe) = random_b;
                        } else if constexpr (just_const_tr<maybe_p>) {
                            static_cast<const value_t&>(maybe) = random_b;
                        } else if constexpr (just_volatile_tr<maybe_p>) {
                            static_cast<volatile value_t&>(maybe) = random_b;
                        } else if constexpr (just_const_volatile_tr<maybe_p>) {
                            static_cast<const volatile value_t&>(maybe) = random_b;
                        }
                        CHECK(maybe == random_b);
                    }
                }

                TEST_CASE_TEMPLATE("should implicitly allow for logical operators", maybe_p, nkr_ALL)
                {
                    using value_t = maybe_p::value_t;

                    if constexpr (boolean_tr<value_t> || integer_tr<value_t> || real_tr<value_t> || pointer_tr<value_t>) {
                        std::remove_const_t<value_t> random;
                        do {
                            random = Random<std::remove_const_t<value_t>>();
                        } while (random == none_t());

                        maybe_p maybe(random);
                        CHECK(maybe);
                        CHECK(!!maybe);
                        CHECK(maybe || false);
                        CHECK(maybe && true);
                        CHECK(maybe ? true : false);
                    }
                }

                TEST_CASE_TEMPLATE("should implicitly allow for comparison operators", maybe_p, nkr_ALL)
                {
                    using value_t = maybe_p::value_t;

                    if constexpr (boolean_tr<value_t>) {
                        value_t random = Random<value_t>();
                        maybe_p maybe(random);
                        CHECK(maybe == random);
                        CHECK_FALSE(maybe != random);
                    } else if constexpr (integer_tr<value_t> || real_tr<value_t> || pointer_tr<value_t>) {
                        value_t random = Random<value_t>();
                        maybe_p maybe(random);
                        CHECK(maybe == random);
                        CHECK_FALSE(maybe != random);
                        CHECK_FALSE(maybe < random);
                        CHECK_FALSE(maybe > random);
                        CHECK(maybe <= random);
                        CHECK(maybe >= random);
                        CHECK((maybe <=> random == 0));
                    }
                }

                TEST_CASE_TEMPLATE("should implicitly allow for arithmetic operators", maybe_p, nkr_ALL)
                {
                    using value_t = maybe_p::value_t;

                    if constexpr (integer_tr<value_t>) {
                        std::remove_const_t<value_t> random_a = Random<std::remove_const_t<value_t>>();
                        std::remove_const_t<value_t> random_b;
                        do {
                            random_b = Random<std::remove_const_t<value_t>>();
                        } while (random_b == none_t());
                        maybe_p maybe(random_a);
                        CHECK(+maybe == +random_a);
                        if constexpr (integer_signed_tr<value_t>) {
                            CHECK(-maybe == -random_a);
                        }
                        CHECK((maybe + random_b) == (random_a + random_b));
                        CHECK((maybe - random_b) == (random_a - random_b));
                        CHECK((maybe * random_b) == (random_a * random_b));
                        CHECK((maybe / random_b) == (random_a / random_b));
                        CHECK((maybe % random_b) == (random_a % random_b));
                        if constexpr (any_non_const_tr<maybe_p> && any_non_const_tr<value_t>) {
                            CHECK((maybe += random_b) == (random_a += random_b));
                            CHECK((maybe -= random_b) == (random_a -= random_b));
                            CHECK((maybe *= random_b) == (random_a *= random_b));
                            CHECK((maybe /= random_b) == (random_a /= random_b));
                            CHECK((maybe %= random_b) == (random_a %= random_b));
                        }
                    } else if constexpr (real_tr<value_t>) {
                        std::remove_const_t<value_t> random_a = Random<std::remove_const_t<value_t>>();
                        std::remove_const_t<value_t> random_b;
                        do {
                            random_b = Random<std::remove_const_t<value_t>>();
                        } while (random_b == none_t());
                        maybe_p maybe(random_a);
                        CHECK(+maybe == +random_a);
                        CHECK(-maybe == -random_a);
                        CHECK((maybe + random_b) == (random_a + random_b));
                        CHECK((maybe - random_b) == (random_a - random_b));
                        CHECK((maybe * random_b) == (random_a * random_b));
                        CHECK((maybe / random_b) == (random_a / random_b));
                        if constexpr (any_non_const_tr<maybe_p> && any_non_const_tr<value_t>) {
                            CHECK((maybe += random_b) == (random_a += random_b));
                            CHECK((maybe -= random_b) == (random_a -= random_b));
                            CHECK((maybe *= random_b) == (random_a *= random_b));
                            CHECK((maybe /= random_b) == (random_a /= random_b));
                        }
                    } else if constexpr (type_pointer_tr<value_t>) {
                        std::remove_const_t<value_t> random_a = Random<std::remove_const_t<value_t>>();
                        word_t random_b = Random<word_t>();
                        maybe_p maybe(random_a);
                        CHECK((maybe + random_b) == (random_a + random_b));
                        CHECK((maybe - random_b) == (random_a - random_b));
                        if constexpr (any_non_const_tr<maybe_p> && any_non_const_tr<value_t>) {
                            CHECK((maybe += random_b) == (random_a += random_b));
                            CHECK((maybe -= random_b) == (random_a -= random_b));
                        }
                    }
                }

                TEST_CASE_TEMPLATE("should implicitly allow for bitwise operators", maybe_p, nkr_ALL)
                {
                    using value_t = maybe_p::value_t;

                    if constexpr (integer_tr<value_t>) {
                        std::remove_const_t<value_t> random_a = Random<std::remove_const_t<value_t>>();
                        std::remove_const_t<value_t> random_b = Random<std::remove_const_t<value_t>>();
                        word_t random_c = Random<word_t>(0, sizeof(value_t) * 8);
                        maybe_p maybe(random_a);
                        CHECK(~maybe == ~random_a);
                        CHECK((maybe | random_b) == (random_a | random_b));
                        CHECK((maybe & random_b) == (random_a & random_b));
                        CHECK((maybe ^ random_b) == (random_a ^ random_b));
                        if constexpr (integer_unsigned_tr<value_t>) {
                            CHECK((maybe << random_c) == (random_a << random_c));
                            CHECK((maybe >> random_c) == (random_a >> random_c));
                        }
                        if constexpr (any_non_const_tr<maybe_p> && any_non_const_tr<value_t>) {
                            CHECK((maybe |= random_b) == (random_a |= random_b));
                            CHECK((maybe &= random_b) == (random_a &= random_b));
                            CHECK((maybe ^= random_b) == (random_a ^= random_b));
                            if constexpr (integer_unsigned_tr<value_t>) {
                                CHECK((maybe <<= random_c) == (random_a <<= random_c));
                                CHECK((maybe >>= random_c) == (random_a >>= random_c));
                            }
                        }
                    }
                }
            }

            TEST_SUITE("c_bool_t")
            {
                TEST_CASE_TEMPLATE("should cast to true if its underlying value does not equal none_t()", maybe_p, nkr_ALL)
                {
                    using value_t = maybe_p::value_t;

                    value_t random = Random<value_t>();
                    maybe_p maybe = random;
                    if (random != none_t()) {
                        CHECK(maybe);
                    } else {
                        CHECK(!maybe);
                    }
                }
            }
        }

        TEST_SUITE("static operators")
        {
            TEST_SUITE("==(maybe_t, maybe_t)")
            {
                TEST_CASE_TEMPLATE("should return true for two maybes with the same type that have an equal value", maybe_p, nkr_ALL)
                {
                    using value_t = maybe_p::value_t;

                    value_t random = Random<value_t>();
                    maybe_p maybe_a = random;
                    maybe_p maybe_b = random;

                    CHECK_TRUE(maybe_a == maybe_b);
                }

                TEST_CASE_TEMPLATE("should return false for two maybes with the same type that do not have an equal value", maybe_p, nkr_ALL)
                {
                    using value_t = maybe_p::value_t;

                    value_t random_a = Random<value_t>();
                    std::remove_const_t<value_t> random_b;
                    do {
                        random_b = Random<value_t>();
                    } while (random_b == random_a);
                    maybe_p maybe_a = random_a;
                    maybe_p maybe_b = random_b;

                    CHECK_FALSE(maybe_a == maybe_b);
                }

                TEST_CASE_TEMPLATE("should return true for two maybes of different reference types with the same type that have an equal value", value_p, nkr_ALL_VALUES)
                {
                    value_p random = Random<value_p>();
                    maybe_t<value_p> maybe_a = random;
                    maybe_t<value_p> maybe_b = random;

                    CHECK_TRUE(maybe_a == maybe_b);
                    CHECK_TRUE(maybe_a == maybe_t<value_p>(random));
                    CHECK_TRUE(maybe_t<value_p>(random) == maybe_b);
                    CHECK_TRUE(maybe_t<value_p>(random) == maybe_t<value_p>(random));
                }

                TEST_CASE_TEMPLATE("should return false for two maybes of different reference types with the same type that do not have an equal value", value_p, nkr_ALL_VALUES)
                {
                    value_p random_a = Random<value_p>();
                    std::remove_const_t<value_p> random_b;
                    do {
                        random_b = Random<value_p>();
                    } while (random_b == random_a);
                    maybe_t<value_p> maybe_a = random_a;
                    maybe_t<value_p> maybe_b = random_b;

                    CHECK_FALSE(maybe_a == maybe_b);
                    CHECK_FALSE(maybe_a == maybe_t<value_p>(random_b));
                    CHECK_FALSE(maybe_t<value_p>(random_a) == maybe_b);
                    CHECK_FALSE(maybe_t<value_p>(random_a) == maybe_t<value_p>(random_b));
                }

                TEST_CASE_TEMPLATE("should return true for two maybes with the same but differently qualified types that have an equal value", value_p, nkr_JUST_NON_QUALIFIED_VALUES)
                {
                    value_p random = Random<value_p>();

                    CHECK_TRUE(maybe_t<value_p>(random) == maybe_t<const value_p>(random));
                    CHECK_TRUE(maybe_t<value_p>(random) == maybe_t<volatile value_p>(random));
                    CHECK_TRUE(maybe_t<value_p>(random) == maybe_t<const volatile value_p>(random));

                    CHECK_TRUE(maybe_t<const value_p>(random) == maybe_t<value_p>(random));
                    CHECK_TRUE(maybe_t<const value_p>(random) == maybe_t<volatile value_p>(random));
                    CHECK_TRUE(maybe_t<const value_p>(random) == maybe_t<const volatile value_p>(random));

                    CHECK_TRUE(maybe_t<volatile value_p>(random) == maybe_t<value_p>(random));
                    CHECK_TRUE(maybe_t<volatile value_p>(random) == maybe_t<const value_p>(random));
                    CHECK_TRUE(maybe_t<volatile value_p>(random) == maybe_t<const volatile value_p>(random));

                    CHECK_TRUE(maybe_t<const volatile value_p>(random) == maybe_t<value_p>(random));
                    CHECK_TRUE(maybe_t<const volatile value_p>(random) == maybe_t<const value_p>(random));
                    CHECK_TRUE(maybe_t<const volatile value_p>(random) == maybe_t<volatile value_p>(random));
                }

                TEST_CASE_TEMPLATE("should return false for two maybes with the same but differently qualified types that do not have an equal value", value_p, nkr_JUST_NON_QUALIFIED_VALUES)
                {
                    value_p random_a = Random<value_p>();
                    value_p random_b;
                    do {
                        random_b = Random<value_p>();
                    } while (random_b == random_a);

                    CHECK_FALSE(maybe_t<value_p>(random_a) == maybe_t<const value_p>(random_b));
                    CHECK_FALSE(maybe_t<value_p>(random_a) == maybe_t<volatile value_p>(random_b));
                    CHECK_FALSE(maybe_t<value_p>(random_a) == maybe_t<const volatile value_p>(random_b));

                    CHECK_FALSE(maybe_t<const value_p>(random_a) == maybe_t<value_p>(random_b));
                    CHECK_FALSE(maybe_t<const value_p>(random_a) == maybe_t<volatile value_p>(random_b));
                    CHECK_FALSE(maybe_t<const value_p>(random_a) == maybe_t<const volatile value_p>(random_b));

                    CHECK_FALSE(maybe_t<volatile value_p>(random_a) == maybe_t<value_p>(random_b));
                    CHECK_FALSE(maybe_t<volatile value_p>(random_a) == maybe_t<const value_p>(random_b));
                    CHECK_FALSE(maybe_t<volatile value_p>(random_a) == maybe_t<const volatile value_p>(random_b));

                    CHECK_FALSE(maybe_t<const volatile value_p>(random_a) == maybe_t<value_p>(random_b));
                    CHECK_FALSE(maybe_t<const volatile value_p>(random_a) == maybe_t<const value_p>(random_b));
                    CHECK_FALSE(maybe_t<const volatile value_p>(random_a) == maybe_t<volatile value_p>(random_b));
                }

                TEST_CASE_TEMPLATE("should return true for two differently qualified maybes with the same type that have an equal value", value_p, nkr_ALL_VALUES)
                {
                    value_p random = Random<value_p>();
                    maybe_t<value_p> maybe = random;
                    const maybe_t<value_p> const_maybe = random;
                    volatile maybe_t<value_p> volatile_maybe = random;
                    const volatile maybe_t<value_p> const_volatile_maybe = random;

                    CHECK_TRUE(maybe == const_maybe);
                    CHECK_TRUE(maybe == volatile_maybe);
                    CHECK_TRUE(maybe == const_volatile_maybe);

                    CHECK_TRUE(const_maybe == maybe);
                    CHECK_TRUE(const_maybe == volatile_maybe);
                    CHECK_TRUE(const_maybe == const_volatile_maybe);

                    CHECK_TRUE(volatile_maybe == maybe);
                    CHECK_TRUE(volatile_maybe == const_maybe);
                    CHECK_TRUE(volatile_maybe == const_volatile_maybe);

                    CHECK_TRUE(const_volatile_maybe == maybe);
                    CHECK_TRUE(const_volatile_maybe == const_maybe);
                    CHECK_TRUE(const_volatile_maybe == volatile_maybe);
                }

                TEST_CASE_TEMPLATE("should return false for two differently qualified maybes with the same type that do not have an equal value", value_p, nkr_ALL_VALUES)
                {
                    value_p random_a = Random<value_p>();
                    std::remove_const_t<value_p> random_b;
                    do {
                        random_b = Random<value_p>();
                    } while (random_b == random_a);
                    maybe_t<value_p> maybe_a = random_a;
                    maybe_t<value_p> maybe_b = random_b;
                    const maybe_t<value_p> const_maybe_a = random_a;
                    const maybe_t<value_p> const_maybe_b = random_b;
                    volatile maybe_t<value_p> volatile_maybe_a = random_a;
                    volatile maybe_t<value_p> volatile_maybe_b = random_b;
                    const volatile maybe_t<value_p> const_volatile_maybe_a = random_a;
                    const volatile maybe_t<value_p> const_volatile_maybe_b = random_b;

                    CHECK_FALSE(maybe_a == const_maybe_b);
                    CHECK_FALSE(maybe_a == volatile_maybe_b);
                    CHECK_FALSE(maybe_a == const_volatile_maybe_b);

                    CHECK_FALSE(const_maybe_a == maybe_b);
                    CHECK_FALSE(const_maybe_a == volatile_maybe_b);
                    CHECK_FALSE(const_maybe_a == const_volatile_maybe_b);

                    CHECK_FALSE(volatile_maybe_a == maybe_b);
                    CHECK_FALSE(volatile_maybe_a == const_maybe_b);
                    CHECK_FALSE(volatile_maybe_a == const_volatile_maybe_b);

                    CHECK_FALSE(const_volatile_maybe_a == maybe_b);
                    CHECK_FALSE(const_volatile_maybe_a == const_maybe_b);
                    CHECK_FALSE(const_volatile_maybe_a == volatile_maybe_b);
                }

                TEST_CASE_TEMPLATE("should return true for two differently qualified maybes with the same but differently qualified types that have an equal value", value_p, nkr_JUST_NON_QUALIFIED_VALUES)
                {
                    value_p random = Random<value_p>();
                    maybe_t<value_p> maybe = random;
                    maybe_t<const value_p> maybe_c = random;
                    maybe_t<volatile value_p> maybe_v = random;
                    maybe_t<const volatile value_p> maybe_cv = random;
                    const maybe_t<value_p> const_maybe = random;
                    const maybe_t<const value_p> const_maybe_c = random;
                    const maybe_t<volatile value_p> const_maybe_v = random;
                    const maybe_t<const volatile value_p> const_maybe_cv = random;
                    volatile maybe_t<value_p> volatile_maybe = random;
                    volatile maybe_t<const value_p> volatile_maybe_c = random;
                    volatile maybe_t<volatile value_p> volatile_maybe_v = random;
                    volatile maybe_t<const volatile value_p> volatile_maybe_cv = random;
                    const volatile maybe_t<value_p> const_volatile_maybe = random;
                    const volatile maybe_t<const value_p> const_volatile_maybe_c = random;
                    const volatile maybe_t<volatile value_p> const_volatile_maybe_v = random;
                    const volatile maybe_t<const volatile value_p> const_volatile_maybe_cv = random;

                    CHECK_TRUE(maybe == maybe);
                    CHECK_TRUE(maybe == maybe_c);
                    CHECK_TRUE(maybe == maybe_v);
                    CHECK_TRUE(maybe == maybe_cv);
                    CHECK_TRUE(maybe == const_maybe);
                    CHECK_TRUE(maybe == const_maybe_c);
                    CHECK_TRUE(maybe == const_maybe_v);
                    CHECK_TRUE(maybe == const_maybe_cv);
                    CHECK_TRUE(maybe == volatile_maybe);
                    CHECK_TRUE(maybe == volatile_maybe_c);
                    CHECK_TRUE(maybe == volatile_maybe_v);
                    CHECK_TRUE(maybe == volatile_maybe_cv);
                    CHECK_TRUE(maybe == const_volatile_maybe);
                    CHECK_TRUE(maybe == const_volatile_maybe_c);
                    CHECK_TRUE(maybe == const_volatile_maybe_v);
                    CHECK_TRUE(maybe == const_volatile_maybe_cv);

                    CHECK_TRUE(maybe_c == maybe);
                    CHECK_TRUE(maybe_c == maybe_c);
                    CHECK_TRUE(maybe_c == maybe_v);
                    CHECK_TRUE(maybe_c == maybe_cv);
                    CHECK_TRUE(maybe_c == const_maybe);
                    CHECK_TRUE(maybe_c == const_maybe_c);
                    CHECK_TRUE(maybe_c == const_maybe_v);
                    CHECK_TRUE(maybe_c == const_maybe_cv);
                    CHECK_TRUE(maybe_c == volatile_maybe);
                    CHECK_TRUE(maybe_c == volatile_maybe_c);
                    CHECK_TRUE(maybe_c == volatile_maybe_v);
                    CHECK_TRUE(maybe_c == volatile_maybe_cv);
                    CHECK_TRUE(maybe_c == const_volatile_maybe);
                    CHECK_TRUE(maybe_c == const_volatile_maybe_c);
                    CHECK_TRUE(maybe_c == const_volatile_maybe_v);
                    CHECK_TRUE(maybe_c == const_volatile_maybe_cv);

                    CHECK_TRUE(maybe_v == maybe);
                    CHECK_TRUE(maybe_v == maybe_c);
                    CHECK_TRUE(maybe_v == maybe_v);
                    CHECK_TRUE(maybe_v == maybe_cv);
                    CHECK_TRUE(maybe_v == const_maybe);
                    CHECK_TRUE(maybe_v == const_maybe_c);
                    CHECK_TRUE(maybe_v == const_maybe_v);
                    CHECK_TRUE(maybe_v == const_maybe_cv);
                    CHECK_TRUE(maybe_v == volatile_maybe);
                    CHECK_TRUE(maybe_v == volatile_maybe_c);
                    CHECK_TRUE(maybe_v == volatile_maybe_v);
                    CHECK_TRUE(maybe_v == volatile_maybe_cv);
                    CHECK_TRUE(maybe_v == const_volatile_maybe);
                    CHECK_TRUE(maybe_v == const_volatile_maybe_c);
                    CHECK_TRUE(maybe_v == const_volatile_maybe_v);
                    CHECK_TRUE(maybe_v == const_volatile_maybe_cv);

                    CHECK_TRUE(maybe_cv == maybe);
                    CHECK_TRUE(maybe_cv == maybe_c);
                    CHECK_TRUE(maybe_cv == maybe_v);
                    CHECK_TRUE(maybe_cv == maybe_cv);
                    CHECK_TRUE(maybe_cv == const_maybe);
                    CHECK_TRUE(maybe_cv == const_maybe_c);
                    CHECK_TRUE(maybe_cv == const_maybe_v);
                    CHECK_TRUE(maybe_cv == const_maybe_cv);
                    CHECK_TRUE(maybe_cv == volatile_maybe);
                    CHECK_TRUE(maybe_cv == volatile_maybe_c);
                    CHECK_TRUE(maybe_cv == volatile_maybe_v);
                    CHECK_TRUE(maybe_cv == volatile_maybe_cv);
                    CHECK_TRUE(maybe_cv == const_volatile_maybe);
                    CHECK_TRUE(maybe_cv == const_volatile_maybe_c);
                    CHECK_TRUE(maybe_cv == const_volatile_maybe_v);
                    CHECK_TRUE(maybe_cv == const_volatile_maybe_cv);

                    CHECK_TRUE(const_maybe == maybe);
                    CHECK_TRUE(const_maybe == maybe_c);
                    CHECK_TRUE(const_maybe == maybe_v);
                    CHECK_TRUE(const_maybe == maybe_cv);
                    CHECK_TRUE(const_maybe == const_maybe);
                    CHECK_TRUE(const_maybe == const_maybe_c);
                    CHECK_TRUE(const_maybe == const_maybe_v);
                    CHECK_TRUE(const_maybe == const_maybe_cv);
                    CHECK_TRUE(const_maybe == volatile_maybe);
                    CHECK_TRUE(const_maybe == volatile_maybe_c);
                    CHECK_TRUE(const_maybe == volatile_maybe_v);
                    CHECK_TRUE(const_maybe == volatile_maybe_cv);
                    CHECK_TRUE(const_maybe == const_volatile_maybe);
                    CHECK_TRUE(const_maybe == const_volatile_maybe_c);
                    CHECK_TRUE(const_maybe == const_volatile_maybe_v);
                    CHECK_TRUE(const_maybe == const_volatile_maybe_cv);

                    CHECK_TRUE(const_maybe_c == maybe);
                    CHECK_TRUE(const_maybe_c == maybe_c);
                    CHECK_TRUE(const_maybe_c == maybe_v);
                    CHECK_TRUE(const_maybe_c == maybe_cv);
                    CHECK_TRUE(const_maybe_c == const_maybe);
                    CHECK_TRUE(const_maybe_c == const_maybe_c);
                    CHECK_TRUE(const_maybe_c == const_maybe_v);
                    CHECK_TRUE(const_maybe_c == const_maybe_cv);
                    CHECK_TRUE(const_maybe_c == volatile_maybe);
                    CHECK_TRUE(const_maybe_c == volatile_maybe_c);
                    CHECK_TRUE(const_maybe_c == volatile_maybe_v);
                    CHECK_TRUE(const_maybe_c == volatile_maybe_cv);
                    CHECK_TRUE(const_maybe_c == const_volatile_maybe);
                    CHECK_TRUE(const_maybe_c == const_volatile_maybe_c);
                    CHECK_TRUE(const_maybe_c == const_volatile_maybe_v);
                    CHECK_TRUE(const_maybe_c == const_volatile_maybe_cv);

                    CHECK_TRUE(const_maybe_v == maybe);
                    CHECK_TRUE(const_maybe_v == maybe_c);
                    CHECK_TRUE(const_maybe_v == maybe_v);
                    CHECK_TRUE(const_maybe_v == maybe_cv);
                    CHECK_TRUE(const_maybe_v == const_maybe);
                    CHECK_TRUE(const_maybe_v == const_maybe_c);
                    CHECK_TRUE(const_maybe_v == const_maybe_v);
                    CHECK_TRUE(const_maybe_v == const_maybe_cv);
                    CHECK_TRUE(const_maybe_v == volatile_maybe);
                    CHECK_TRUE(const_maybe_v == volatile_maybe_c);
                    CHECK_TRUE(const_maybe_v == volatile_maybe_v);
                    CHECK_TRUE(const_maybe_v == volatile_maybe_cv);
                    CHECK_TRUE(const_maybe_v == const_volatile_maybe);
                    CHECK_TRUE(const_maybe_v == const_volatile_maybe_c);
                    CHECK_TRUE(const_maybe_v == const_volatile_maybe_v);
                    CHECK_TRUE(const_maybe_v == const_volatile_maybe_cv);

                    CHECK_TRUE(const_maybe_cv == maybe);
                    CHECK_TRUE(const_maybe_cv == maybe_c);
                    CHECK_TRUE(const_maybe_cv == maybe_v);
                    CHECK_TRUE(const_maybe_cv == maybe_cv);
                    CHECK_TRUE(const_maybe_cv == const_maybe);
                    CHECK_TRUE(const_maybe_cv == const_maybe_c);
                    CHECK_TRUE(const_maybe_cv == const_maybe_v);
                    CHECK_TRUE(const_maybe_cv == const_maybe_cv);
                    CHECK_TRUE(const_maybe_cv == volatile_maybe);
                    CHECK_TRUE(const_maybe_cv == volatile_maybe_c);
                    CHECK_TRUE(const_maybe_cv == volatile_maybe_v);
                    CHECK_TRUE(const_maybe_cv == volatile_maybe_cv);
                    CHECK_TRUE(const_maybe_cv == const_volatile_maybe);
                    CHECK_TRUE(const_maybe_cv == const_volatile_maybe_c);
                    CHECK_TRUE(const_maybe_cv == const_volatile_maybe_v);
                    CHECK_TRUE(const_maybe_cv == const_volatile_maybe_cv);

                    CHECK_TRUE(volatile_maybe == maybe);
                    CHECK_TRUE(volatile_maybe == maybe_c);
                    CHECK_TRUE(volatile_maybe == maybe_v);
                    CHECK_TRUE(volatile_maybe == maybe_cv);
                    CHECK_TRUE(volatile_maybe == const_maybe);
                    CHECK_TRUE(volatile_maybe == const_maybe_c);
                    CHECK_TRUE(volatile_maybe == const_maybe_v);
                    CHECK_TRUE(volatile_maybe == const_maybe_cv);
                    CHECK_TRUE(volatile_maybe == volatile_maybe);
                    CHECK_TRUE(volatile_maybe == volatile_maybe_c);
                    CHECK_TRUE(volatile_maybe == volatile_maybe_v);
                    CHECK_TRUE(volatile_maybe == volatile_maybe_cv);
                    CHECK_TRUE(volatile_maybe == const_volatile_maybe);
                    CHECK_TRUE(volatile_maybe == const_volatile_maybe_c);
                    CHECK_TRUE(volatile_maybe == const_volatile_maybe_v);
                    CHECK_TRUE(volatile_maybe == const_volatile_maybe_cv);

                    CHECK_TRUE(volatile_maybe_c == maybe);
                    CHECK_TRUE(volatile_maybe_c == maybe_c);
                    CHECK_TRUE(volatile_maybe_c == maybe_v);
                    CHECK_TRUE(volatile_maybe_c == maybe_cv);
                    CHECK_TRUE(volatile_maybe_c == const_maybe);
                    CHECK_TRUE(volatile_maybe_c == const_maybe_c);
                    CHECK_TRUE(volatile_maybe_c == const_maybe_v);
                    CHECK_TRUE(volatile_maybe_c == const_maybe_cv);
                    CHECK_TRUE(volatile_maybe_c == volatile_maybe);
                    CHECK_TRUE(volatile_maybe_c == volatile_maybe_c);
                    CHECK_TRUE(volatile_maybe_c == volatile_maybe_v);
                    CHECK_TRUE(volatile_maybe_c == volatile_maybe_cv);
                    CHECK_TRUE(volatile_maybe_c == const_volatile_maybe);
                    CHECK_TRUE(volatile_maybe_c == const_volatile_maybe_c);
                    CHECK_TRUE(volatile_maybe_c == const_volatile_maybe_v);
                    CHECK_TRUE(volatile_maybe_c == const_volatile_maybe_cv);

                    CHECK_TRUE(volatile_maybe_v == maybe);
                    CHECK_TRUE(volatile_maybe_v == maybe_c);
                    CHECK_TRUE(volatile_maybe_v == maybe_v);
                    CHECK_TRUE(volatile_maybe_v == maybe_cv);
                    CHECK_TRUE(volatile_maybe_v == const_maybe);
                    CHECK_TRUE(volatile_maybe_v == const_maybe_c);
                    CHECK_TRUE(volatile_maybe_v == const_maybe_v);
                    CHECK_TRUE(volatile_maybe_v == const_maybe_cv);
                    CHECK_TRUE(volatile_maybe_v == volatile_maybe);
                    CHECK_TRUE(volatile_maybe_v == volatile_maybe_c);
                    CHECK_TRUE(volatile_maybe_v == volatile_maybe_v);
                    CHECK_TRUE(volatile_maybe_v == volatile_maybe_cv);
                    CHECK_TRUE(volatile_maybe_v == const_volatile_maybe);
                    CHECK_TRUE(volatile_maybe_v == const_volatile_maybe_c);
                    CHECK_TRUE(volatile_maybe_v == const_volatile_maybe_v);
                    CHECK_TRUE(volatile_maybe_v == const_volatile_maybe_cv);

                    CHECK_TRUE(volatile_maybe_cv == maybe);
                    CHECK_TRUE(volatile_maybe_cv == maybe_c);
                    CHECK_TRUE(volatile_maybe_cv == maybe_v);
                    CHECK_TRUE(volatile_maybe_cv == maybe_cv);
                    CHECK_TRUE(volatile_maybe_cv == const_maybe);
                    CHECK_TRUE(volatile_maybe_cv == const_maybe_c);
                    CHECK_TRUE(volatile_maybe_cv == const_maybe_v);
                    CHECK_TRUE(volatile_maybe_cv == const_maybe_cv);
                    CHECK_TRUE(volatile_maybe_cv == volatile_maybe);
                    CHECK_TRUE(volatile_maybe_cv == volatile_maybe_c);
                    CHECK_TRUE(volatile_maybe_cv == volatile_maybe_v);
                    CHECK_TRUE(volatile_maybe_cv == volatile_maybe_cv);
                    CHECK_TRUE(volatile_maybe_cv == const_volatile_maybe);
                    CHECK_TRUE(volatile_maybe_cv == const_volatile_maybe_c);
                    CHECK_TRUE(volatile_maybe_cv == const_volatile_maybe_v);
                    CHECK_TRUE(volatile_maybe_cv == const_volatile_maybe_cv);

                    CHECK_TRUE(const_volatile_maybe == maybe);
                    CHECK_TRUE(const_volatile_maybe == maybe_c);
                    CHECK_TRUE(const_volatile_maybe == maybe_v);
                    CHECK_TRUE(const_volatile_maybe == maybe_cv);
                    CHECK_TRUE(const_volatile_maybe == const_maybe);
                    CHECK_TRUE(const_volatile_maybe == const_maybe_c);
                    CHECK_TRUE(const_volatile_maybe == const_maybe_v);
                    CHECK_TRUE(const_volatile_maybe == const_maybe_cv);
                    CHECK_TRUE(const_volatile_maybe == volatile_maybe);
                    CHECK_TRUE(const_volatile_maybe == volatile_maybe_c);
                    CHECK_TRUE(const_volatile_maybe == volatile_maybe_v);
                    CHECK_TRUE(const_volatile_maybe == volatile_maybe_cv);
                    CHECK_TRUE(const_volatile_maybe == const_volatile_maybe);
                    CHECK_TRUE(const_volatile_maybe == const_volatile_maybe_c);
                    CHECK_TRUE(const_volatile_maybe == const_volatile_maybe_v);
                    CHECK_TRUE(const_volatile_maybe == const_volatile_maybe_cv);

                    CHECK_TRUE(const_volatile_maybe_c == maybe);
                    CHECK_TRUE(const_volatile_maybe_c == maybe_c);
                    CHECK_TRUE(const_volatile_maybe_c == maybe_v);
                    CHECK_TRUE(const_volatile_maybe_c == maybe_cv);
                    CHECK_TRUE(const_volatile_maybe_c == const_maybe);
                    CHECK_TRUE(const_volatile_maybe_c == const_maybe_c);
                    CHECK_TRUE(const_volatile_maybe_c == const_maybe_v);
                    CHECK_TRUE(const_volatile_maybe_c == const_maybe_cv);
                    CHECK_TRUE(const_volatile_maybe_c == volatile_maybe);
                    CHECK_TRUE(const_volatile_maybe_c == volatile_maybe_c);
                    CHECK_TRUE(const_volatile_maybe_c == volatile_maybe_v);
                    CHECK_TRUE(const_volatile_maybe_c == volatile_maybe_cv);
                    CHECK_TRUE(const_volatile_maybe_c == const_volatile_maybe);
                    CHECK_TRUE(const_volatile_maybe_c == const_volatile_maybe_c);
                    CHECK_TRUE(const_volatile_maybe_c == const_volatile_maybe_v);
                    CHECK_TRUE(const_volatile_maybe_c == const_volatile_maybe_cv);

                    CHECK_TRUE(const_volatile_maybe_v == maybe);
                    CHECK_TRUE(const_volatile_maybe_v == maybe_c);
                    CHECK_TRUE(const_volatile_maybe_v == maybe_v);
                    CHECK_TRUE(const_volatile_maybe_v == maybe_cv);
                    CHECK_TRUE(const_volatile_maybe_v == const_maybe);
                    CHECK_TRUE(const_volatile_maybe_v == const_maybe_c);
                    CHECK_TRUE(const_volatile_maybe_v == const_maybe_v);
                    CHECK_TRUE(const_volatile_maybe_v == const_maybe_cv);
                    CHECK_TRUE(const_volatile_maybe_v == volatile_maybe);
                    CHECK_TRUE(const_volatile_maybe_v == volatile_maybe_c);
                    CHECK_TRUE(const_volatile_maybe_v == volatile_maybe_v);
                    CHECK_TRUE(const_volatile_maybe_v == volatile_maybe_cv);
                    CHECK_TRUE(const_volatile_maybe_v == const_volatile_maybe);
                    CHECK_TRUE(const_volatile_maybe_v == const_volatile_maybe_c);
                    CHECK_TRUE(const_volatile_maybe_v == const_volatile_maybe_v);
                    CHECK_TRUE(const_volatile_maybe_v == const_volatile_maybe_cv);

                    CHECK_TRUE(const_volatile_maybe_cv == maybe);
                    CHECK_TRUE(const_volatile_maybe_cv == maybe_c);
                    CHECK_TRUE(const_volatile_maybe_cv == maybe_v);
                    CHECK_TRUE(const_volatile_maybe_cv == maybe_cv);
                    CHECK_TRUE(const_volatile_maybe_cv == const_maybe);
                    CHECK_TRUE(const_volatile_maybe_cv == const_maybe_c);
                    CHECK_TRUE(const_volatile_maybe_cv == const_maybe_v);
                    CHECK_TRUE(const_volatile_maybe_cv == const_maybe_cv);
                    CHECK_TRUE(const_volatile_maybe_cv == volatile_maybe);
                    CHECK_TRUE(const_volatile_maybe_cv == volatile_maybe_c);
                    CHECK_TRUE(const_volatile_maybe_cv == volatile_maybe_v);
                    CHECK_TRUE(const_volatile_maybe_cv == volatile_maybe_cv);
                    CHECK_TRUE(const_volatile_maybe_cv == const_volatile_maybe);
                    CHECK_TRUE(const_volatile_maybe_cv == const_volatile_maybe_c);
                    CHECK_TRUE(const_volatile_maybe_cv == const_volatile_maybe_v);
                    CHECK_TRUE(const_volatile_maybe_cv == const_volatile_maybe_cv);
                }

                TEST_CASE_TEMPLATE("should return false for two differently qualified maybes with the same but differently qualified types that do not have an equal value", value_p, nkr_JUST_NON_QUALIFIED_VALUES)
                {
                    value_p random_a = Random<value_p>();
                    std::remove_const_t<value_p> random_b;
                    do {
                        random_b = Random<value_p>();
                    } while (random_b == random_a);
                    maybe_t<value_p> maybe_a = random_a;
                    maybe_t<value_p> maybe_b = random_b;
                    maybe_t<const value_p> maybe_c_a = random_a;
                    maybe_t<const value_p> maybe_c_b = random_b;
                    maybe_t<volatile value_p> maybe_v_a = random_a;
                    maybe_t<volatile value_p> maybe_v_b = random_b;
                    maybe_t<const volatile value_p> maybe_cv_a = random_a;
                    maybe_t<const volatile value_p> maybe_cv_b = random_b;
                    const maybe_t<value_p> const_maybe_a = random_a;
                    const maybe_t<value_p> const_maybe_b = random_b;
                    const maybe_t<const value_p> const_maybe_c_a = random_a;
                    const maybe_t<const value_p> const_maybe_c_b = random_b;
                    const maybe_t<volatile value_p> const_maybe_v_a = random_a;
                    const maybe_t<volatile value_p> const_maybe_v_b = random_b;
                    const maybe_t<const volatile value_p> const_maybe_cv_a = random_a;
                    const maybe_t<const volatile value_p> const_maybe_cv_b = random_b;
                    volatile maybe_t<value_p> volatile_maybe_a = random_a;
                    volatile maybe_t<value_p> volatile_maybe_b = random_b;
                    volatile maybe_t<const value_p> volatile_maybe_c_a = random_a;
                    volatile maybe_t<const value_p> volatile_maybe_c_b = random_b;
                    volatile maybe_t<volatile value_p> volatile_maybe_v_a = random_a;
                    volatile maybe_t<volatile value_p> volatile_maybe_v_b = random_b;
                    volatile maybe_t<const volatile value_p> volatile_maybe_cv_a = random_a;
                    volatile maybe_t<const volatile value_p> volatile_maybe_cv_b = random_b;
                    const volatile maybe_t<value_p> const_volatile_maybe_a = random_a;
                    const volatile maybe_t<value_p> const_volatile_maybe_b = random_b;
                    const volatile maybe_t<const value_p> const_volatile_maybe_c_a = random_a;
                    const volatile maybe_t<const value_p> const_volatile_maybe_c_b = random_b;
                    const volatile maybe_t<volatile value_p> const_volatile_maybe_v_a = random_a;
                    const volatile maybe_t<volatile value_p> const_volatile_maybe_v_b = random_b;
                    const volatile maybe_t<const volatile value_p> const_volatile_maybe_cv_a = random_a;
                    const volatile maybe_t<const volatile value_p> const_volatile_maybe_cv_b = random_b;

                    CHECK_FALSE(maybe_a == maybe_b);
                    CHECK_FALSE(maybe_a == maybe_c_b);
                    CHECK_FALSE(maybe_a == maybe_v_b);
                    CHECK_FALSE(maybe_a == maybe_cv_b);
                    CHECK_FALSE(maybe_a == const_maybe_b);
                    CHECK_FALSE(maybe_a == const_maybe_c_b);
                    CHECK_FALSE(maybe_a == const_maybe_v_b);
                    CHECK_FALSE(maybe_a == const_maybe_cv_b);
                    CHECK_FALSE(maybe_a == volatile_maybe_b);
                    CHECK_FALSE(maybe_a == volatile_maybe_c_b);
                    CHECK_FALSE(maybe_a == volatile_maybe_v_b);
                    CHECK_FALSE(maybe_a == volatile_maybe_cv_b);
                    CHECK_FALSE(maybe_a == const_volatile_maybe_b);
                    CHECK_FALSE(maybe_a == const_volatile_maybe_c_b);
                    CHECK_FALSE(maybe_a == const_volatile_maybe_v_b);
                    CHECK_FALSE(maybe_a == const_volatile_maybe_cv_b);

                    CHECK_FALSE(maybe_c_a == maybe_b);
                    CHECK_FALSE(maybe_c_a == maybe_c_b);
                    CHECK_FALSE(maybe_c_a == maybe_v_b);
                    CHECK_FALSE(maybe_c_a == maybe_cv_b);
                    CHECK_FALSE(maybe_c_a == const_maybe_b);
                    CHECK_FALSE(maybe_c_a == const_maybe_c_b);
                    CHECK_FALSE(maybe_c_a == const_maybe_v_b);
                    CHECK_FALSE(maybe_c_a == const_maybe_cv_b);
                    CHECK_FALSE(maybe_c_a == volatile_maybe_b);
                    CHECK_FALSE(maybe_c_a == volatile_maybe_c_b);
                    CHECK_FALSE(maybe_c_a == volatile_maybe_v_b);
                    CHECK_FALSE(maybe_c_a == volatile_maybe_cv_b);
                    CHECK_FALSE(maybe_c_a == const_volatile_maybe_b);
                    CHECK_FALSE(maybe_c_a == const_volatile_maybe_c_b);
                    CHECK_FALSE(maybe_c_a == const_volatile_maybe_v_b);
                    CHECK_FALSE(maybe_c_a == const_volatile_maybe_cv_b);

                    CHECK_FALSE(maybe_v_a == maybe_b);
                    CHECK_FALSE(maybe_v_a == maybe_c_b);
                    CHECK_FALSE(maybe_v_a == maybe_v_b);
                    CHECK_FALSE(maybe_v_a == maybe_cv_b);
                    CHECK_FALSE(maybe_v_a == const_maybe_b);
                    CHECK_FALSE(maybe_v_a == const_maybe_c_b);
                    CHECK_FALSE(maybe_v_a == const_maybe_v_b);
                    CHECK_FALSE(maybe_v_a == const_maybe_cv_b);
                    CHECK_FALSE(maybe_v_a == volatile_maybe_b);
                    CHECK_FALSE(maybe_v_a == volatile_maybe_c_b);
                    CHECK_FALSE(maybe_v_a == volatile_maybe_v_b);
                    CHECK_FALSE(maybe_v_a == volatile_maybe_cv_b);
                    CHECK_FALSE(maybe_v_a == const_volatile_maybe_b);
                    CHECK_FALSE(maybe_v_a == const_volatile_maybe_c_b);
                    CHECK_FALSE(maybe_v_a == const_volatile_maybe_v_b);
                    CHECK_FALSE(maybe_v_a == const_volatile_maybe_cv_b);

                    CHECK_FALSE(maybe_cv_a == maybe_b);
                    CHECK_FALSE(maybe_cv_a == maybe_c_b);
                    CHECK_FALSE(maybe_cv_a == maybe_v_b);
                    CHECK_FALSE(maybe_cv_a == maybe_cv_b);
                    CHECK_FALSE(maybe_cv_a == const_maybe_b);
                    CHECK_FALSE(maybe_cv_a == const_maybe_c_b);
                    CHECK_FALSE(maybe_cv_a == const_maybe_v_b);
                    CHECK_FALSE(maybe_cv_a == const_maybe_cv_b);
                    CHECK_FALSE(maybe_cv_a == volatile_maybe_b);
                    CHECK_FALSE(maybe_cv_a == volatile_maybe_c_b);
                    CHECK_FALSE(maybe_cv_a == volatile_maybe_v_b);
                    CHECK_FALSE(maybe_cv_a == volatile_maybe_cv_b);
                    CHECK_FALSE(maybe_cv_a == const_volatile_maybe_b);
                    CHECK_FALSE(maybe_cv_a == const_volatile_maybe_c_b);
                    CHECK_FALSE(maybe_cv_a == const_volatile_maybe_v_b);
                    CHECK_FALSE(maybe_cv_a == const_volatile_maybe_cv_b);

                    CHECK_FALSE(const_maybe_a == maybe_b);
                    CHECK_FALSE(const_maybe_a == maybe_c_b);
                    CHECK_FALSE(const_maybe_a == maybe_v_b);
                    CHECK_FALSE(const_maybe_a == maybe_cv_b);
                    CHECK_FALSE(const_maybe_a == const_maybe_b);
                    CHECK_FALSE(const_maybe_a == const_maybe_c_b);
                    CHECK_FALSE(const_maybe_a == const_maybe_v_b);
                    CHECK_FALSE(const_maybe_a == const_maybe_cv_b);
                    CHECK_FALSE(const_maybe_a == volatile_maybe_b);
                    CHECK_FALSE(const_maybe_a == volatile_maybe_c_b);
                    CHECK_FALSE(const_maybe_a == volatile_maybe_v_b);
                    CHECK_FALSE(const_maybe_a == volatile_maybe_cv_b);
                    CHECK_FALSE(const_maybe_a == const_volatile_maybe_b);
                    CHECK_FALSE(const_maybe_a == const_volatile_maybe_c_b);
                    CHECK_FALSE(const_maybe_a == const_volatile_maybe_v_b);
                    CHECK_FALSE(const_maybe_a == const_volatile_maybe_cv_b);

                    CHECK_FALSE(const_maybe_c_a == maybe_b);
                    CHECK_FALSE(const_maybe_c_a == maybe_c_b);
                    CHECK_FALSE(const_maybe_c_a == maybe_v_b);
                    CHECK_FALSE(const_maybe_c_a == maybe_cv_b);
                    CHECK_FALSE(const_maybe_c_a == const_maybe_b);
                    CHECK_FALSE(const_maybe_c_a == const_maybe_c_b);
                    CHECK_FALSE(const_maybe_c_a == const_maybe_v_b);
                    CHECK_FALSE(const_maybe_c_a == const_maybe_cv_b);
                    CHECK_FALSE(const_maybe_c_a == volatile_maybe_b);
                    CHECK_FALSE(const_maybe_c_a == volatile_maybe_c_b);
                    CHECK_FALSE(const_maybe_c_a == volatile_maybe_v_b);
                    CHECK_FALSE(const_maybe_c_a == volatile_maybe_cv_b);
                    CHECK_FALSE(const_maybe_c_a == const_volatile_maybe_b);
                    CHECK_FALSE(const_maybe_c_a == const_volatile_maybe_c_b);
                    CHECK_FALSE(const_maybe_c_a == const_volatile_maybe_v_b);
                    CHECK_FALSE(const_maybe_c_a == const_volatile_maybe_cv_b);

                    CHECK_FALSE(const_maybe_v_a == maybe_b);
                    CHECK_FALSE(const_maybe_v_a == maybe_c_b);
                    CHECK_FALSE(const_maybe_v_a == maybe_v_b);
                    CHECK_FALSE(const_maybe_v_a == maybe_cv_b);
                    CHECK_FALSE(const_maybe_v_a == const_maybe_b);
                    CHECK_FALSE(const_maybe_v_a == const_maybe_c_b);
                    CHECK_FALSE(const_maybe_v_a == const_maybe_v_b);
                    CHECK_FALSE(const_maybe_v_a == const_maybe_cv_b);
                    CHECK_FALSE(const_maybe_v_a == volatile_maybe_b);
                    CHECK_FALSE(const_maybe_v_a == volatile_maybe_c_b);
                    CHECK_FALSE(const_maybe_v_a == volatile_maybe_v_b);
                    CHECK_FALSE(const_maybe_v_a == volatile_maybe_cv_b);
                    CHECK_FALSE(const_maybe_v_a == const_volatile_maybe_b);
                    CHECK_FALSE(const_maybe_v_a == const_volatile_maybe_c_b);
                    CHECK_FALSE(const_maybe_v_a == const_volatile_maybe_v_b);
                    CHECK_FALSE(const_maybe_v_a == const_volatile_maybe_cv_b);

                    CHECK_FALSE(const_maybe_cv_a == maybe_b);
                    CHECK_FALSE(const_maybe_cv_a == maybe_c_b);
                    CHECK_FALSE(const_maybe_cv_a == maybe_v_b);
                    CHECK_FALSE(const_maybe_cv_a == maybe_cv_b);
                    CHECK_FALSE(const_maybe_cv_a == const_maybe_b);
                    CHECK_FALSE(const_maybe_cv_a == const_maybe_c_b);
                    CHECK_FALSE(const_maybe_cv_a == const_maybe_v_b);
                    CHECK_FALSE(const_maybe_cv_a == const_maybe_cv_b);
                    CHECK_FALSE(const_maybe_cv_a == volatile_maybe_b);
                    CHECK_FALSE(const_maybe_cv_a == volatile_maybe_c_b);
                    CHECK_FALSE(const_maybe_cv_a == volatile_maybe_v_b);
                    CHECK_FALSE(const_maybe_cv_a == volatile_maybe_cv_b);
                    CHECK_FALSE(const_maybe_cv_a == const_volatile_maybe_b);
                    CHECK_FALSE(const_maybe_cv_a == const_volatile_maybe_c_b);
                    CHECK_FALSE(const_maybe_cv_a == const_volatile_maybe_v_b);
                    CHECK_FALSE(const_maybe_cv_a == const_volatile_maybe_cv_b);

                    CHECK_FALSE(volatile_maybe_a == maybe_b);
                    CHECK_FALSE(volatile_maybe_a == maybe_c_b);
                    CHECK_FALSE(volatile_maybe_a == maybe_v_b);
                    CHECK_FALSE(volatile_maybe_a == maybe_cv_b);
                    CHECK_FALSE(volatile_maybe_a == const_maybe_b);
                    CHECK_FALSE(volatile_maybe_a == const_maybe_c_b);
                    CHECK_FALSE(volatile_maybe_a == const_maybe_v_b);
                    CHECK_FALSE(volatile_maybe_a == const_maybe_cv_b);
                    CHECK_FALSE(volatile_maybe_a == volatile_maybe_b);
                    CHECK_FALSE(volatile_maybe_a == volatile_maybe_c_b);
                    CHECK_FALSE(volatile_maybe_a == volatile_maybe_v_b);
                    CHECK_FALSE(volatile_maybe_a == volatile_maybe_cv_b);
                    CHECK_FALSE(volatile_maybe_a == const_volatile_maybe_b);
                    CHECK_FALSE(volatile_maybe_a == const_volatile_maybe_c_b);
                    CHECK_FALSE(volatile_maybe_a == const_volatile_maybe_v_b);
                    CHECK_FALSE(volatile_maybe_a == const_volatile_maybe_cv_b);

                    CHECK_FALSE(volatile_maybe_c_a == maybe_b);
                    CHECK_FALSE(volatile_maybe_c_a == maybe_c_b);
                    CHECK_FALSE(volatile_maybe_c_a == maybe_v_b);
                    CHECK_FALSE(volatile_maybe_c_a == maybe_cv_b);
                    CHECK_FALSE(volatile_maybe_c_a == const_maybe_b);
                    CHECK_FALSE(volatile_maybe_c_a == const_maybe_c_b);
                    CHECK_FALSE(volatile_maybe_c_a == const_maybe_v_b);
                    CHECK_FALSE(volatile_maybe_c_a == const_maybe_cv_b);
                    CHECK_FALSE(volatile_maybe_c_a == volatile_maybe_b);
                    CHECK_FALSE(volatile_maybe_c_a == volatile_maybe_c_b);
                    CHECK_FALSE(volatile_maybe_c_a == volatile_maybe_v_b);
                    CHECK_FALSE(volatile_maybe_c_a == volatile_maybe_cv_b);
                    CHECK_FALSE(volatile_maybe_c_a == const_volatile_maybe_b);
                    CHECK_FALSE(volatile_maybe_c_a == const_volatile_maybe_c_b);
                    CHECK_FALSE(volatile_maybe_c_a == const_volatile_maybe_v_b);
                    CHECK_FALSE(volatile_maybe_c_a == const_volatile_maybe_cv_b);

                    CHECK_FALSE(volatile_maybe_v_a == maybe_b);
                    CHECK_FALSE(volatile_maybe_v_a == maybe_c_b);
                    CHECK_FALSE(volatile_maybe_v_a == maybe_v_b);
                    CHECK_FALSE(volatile_maybe_v_a == maybe_cv_b);
                    CHECK_FALSE(volatile_maybe_v_a == const_maybe_b);
                    CHECK_FALSE(volatile_maybe_v_a == const_maybe_c_b);
                    CHECK_FALSE(volatile_maybe_v_a == const_maybe_v_b);
                    CHECK_FALSE(volatile_maybe_v_a == const_maybe_cv_b);
                    CHECK_FALSE(volatile_maybe_v_a == volatile_maybe_b);
                    CHECK_FALSE(volatile_maybe_v_a == volatile_maybe_c_b);
                    CHECK_FALSE(volatile_maybe_v_a == volatile_maybe_v_b);
                    CHECK_FALSE(volatile_maybe_v_a == volatile_maybe_cv_b);
                    CHECK_FALSE(volatile_maybe_v_a == const_volatile_maybe_b);
                    CHECK_FALSE(volatile_maybe_v_a == const_volatile_maybe_c_b);
                    CHECK_FALSE(volatile_maybe_v_a == const_volatile_maybe_v_b);
                    CHECK_FALSE(volatile_maybe_v_a == const_volatile_maybe_cv_b);

                    CHECK_FALSE(volatile_maybe_cv_a == maybe_b);
                    CHECK_FALSE(volatile_maybe_cv_a == maybe_c_b);
                    CHECK_FALSE(volatile_maybe_cv_a == maybe_v_b);
                    CHECK_FALSE(volatile_maybe_cv_a == maybe_cv_b);
                    CHECK_FALSE(volatile_maybe_cv_a == const_maybe_b);
                    CHECK_FALSE(volatile_maybe_cv_a == const_maybe_c_b);
                    CHECK_FALSE(volatile_maybe_cv_a == const_maybe_v_b);
                    CHECK_FALSE(volatile_maybe_cv_a == const_maybe_cv_b);
                    CHECK_FALSE(volatile_maybe_cv_a == volatile_maybe_b);
                    CHECK_FALSE(volatile_maybe_cv_a == volatile_maybe_c_b);
                    CHECK_FALSE(volatile_maybe_cv_a == volatile_maybe_v_b);
                    CHECK_FALSE(volatile_maybe_cv_a == volatile_maybe_cv_b);
                    CHECK_FALSE(volatile_maybe_cv_a == const_volatile_maybe_b);
                    CHECK_FALSE(volatile_maybe_cv_a == const_volatile_maybe_c_b);
                    CHECK_FALSE(volatile_maybe_cv_a == const_volatile_maybe_v_b);
                    CHECK_FALSE(volatile_maybe_cv_a == const_volatile_maybe_cv_b);

                    CHECK_FALSE(const_volatile_maybe_a == maybe_b);
                    CHECK_FALSE(const_volatile_maybe_a == maybe_c_b);
                    CHECK_FALSE(const_volatile_maybe_a == maybe_v_b);
                    CHECK_FALSE(const_volatile_maybe_a == maybe_cv_b);
                    CHECK_FALSE(const_volatile_maybe_a == const_maybe_b);
                    CHECK_FALSE(const_volatile_maybe_a == const_maybe_c_b);
                    CHECK_FALSE(const_volatile_maybe_a == const_maybe_v_b);
                    CHECK_FALSE(const_volatile_maybe_a == const_maybe_cv_b);
                    CHECK_FALSE(const_volatile_maybe_a == volatile_maybe_b);
                    CHECK_FALSE(const_volatile_maybe_a == volatile_maybe_c_b);
                    CHECK_FALSE(const_volatile_maybe_a == volatile_maybe_v_b);
                    CHECK_FALSE(const_volatile_maybe_a == volatile_maybe_cv_b);
                    CHECK_FALSE(const_volatile_maybe_a == const_volatile_maybe_b);
                    CHECK_FALSE(const_volatile_maybe_a == const_volatile_maybe_c_b);
                    CHECK_FALSE(const_volatile_maybe_a == const_volatile_maybe_v_b);
                    CHECK_FALSE(const_volatile_maybe_a == const_volatile_maybe_cv_b);

                    CHECK_FALSE(const_volatile_maybe_c_a == maybe_b);
                    CHECK_FALSE(const_volatile_maybe_c_a == maybe_c_b);
                    CHECK_FALSE(const_volatile_maybe_c_a == maybe_v_b);
                    CHECK_FALSE(const_volatile_maybe_c_a == maybe_cv_b);
                    CHECK_FALSE(const_volatile_maybe_c_a == const_maybe_b);
                    CHECK_FALSE(const_volatile_maybe_c_a == const_maybe_c_b);
                    CHECK_FALSE(const_volatile_maybe_c_a == const_maybe_v_b);
                    CHECK_FALSE(const_volatile_maybe_c_a == const_maybe_cv_b);
                    CHECK_FALSE(const_volatile_maybe_c_a == volatile_maybe_b);
                    CHECK_FALSE(const_volatile_maybe_c_a == volatile_maybe_c_b);
                    CHECK_FALSE(const_volatile_maybe_c_a == volatile_maybe_v_b);
                    CHECK_FALSE(const_volatile_maybe_c_a == volatile_maybe_cv_b);
                    CHECK_FALSE(const_volatile_maybe_c_a == const_volatile_maybe_b);
                    CHECK_FALSE(const_volatile_maybe_c_a == const_volatile_maybe_c_b);
                    CHECK_FALSE(const_volatile_maybe_c_a == const_volatile_maybe_v_b);
                    CHECK_FALSE(const_volatile_maybe_c_a == const_volatile_maybe_cv_b);

                    CHECK_FALSE(const_volatile_maybe_v_a == maybe_b);
                    CHECK_FALSE(const_volatile_maybe_v_a == maybe_c_b);
                    CHECK_FALSE(const_volatile_maybe_v_a == maybe_v_b);
                    CHECK_FALSE(const_volatile_maybe_v_a == maybe_cv_b);
                    CHECK_FALSE(const_volatile_maybe_v_a == const_maybe_b);
                    CHECK_FALSE(const_volatile_maybe_v_a == const_maybe_c_b);
                    CHECK_FALSE(const_volatile_maybe_v_a == const_maybe_v_b);
                    CHECK_FALSE(const_volatile_maybe_v_a == const_maybe_cv_b);
                    CHECK_FALSE(const_volatile_maybe_v_a == volatile_maybe_b);
                    CHECK_FALSE(const_volatile_maybe_v_a == volatile_maybe_c_b);
                    CHECK_FALSE(const_volatile_maybe_v_a == volatile_maybe_v_b);
                    CHECK_FALSE(const_volatile_maybe_v_a == volatile_maybe_cv_b);
                    CHECK_FALSE(const_volatile_maybe_v_a == const_volatile_maybe_b);
                    CHECK_FALSE(const_volatile_maybe_v_a == const_volatile_maybe_c_b);
                    CHECK_FALSE(const_volatile_maybe_v_a == const_volatile_maybe_v_b);
                    CHECK_FALSE(const_volatile_maybe_v_a == const_volatile_maybe_cv_b);

                    CHECK_FALSE(const_volatile_maybe_cv_a == maybe_b);
                    CHECK_FALSE(const_volatile_maybe_cv_a == maybe_c_b);
                    CHECK_FALSE(const_volatile_maybe_cv_a == maybe_v_b);
                    CHECK_FALSE(const_volatile_maybe_cv_a == maybe_cv_b);
                    CHECK_FALSE(const_volatile_maybe_cv_a == const_maybe_b);
                    CHECK_FALSE(const_volatile_maybe_cv_a == const_maybe_c_b);
                    CHECK_FALSE(const_volatile_maybe_cv_a == const_maybe_v_b);
                    CHECK_FALSE(const_volatile_maybe_cv_a == const_maybe_cv_b);
                    CHECK_FALSE(const_volatile_maybe_cv_a == volatile_maybe_b);
                    CHECK_FALSE(const_volatile_maybe_cv_a == volatile_maybe_c_b);
                    CHECK_FALSE(const_volatile_maybe_cv_a == volatile_maybe_v_b);
                    CHECK_FALSE(const_volatile_maybe_cv_a == volatile_maybe_cv_b);
                    CHECK_FALSE(const_volatile_maybe_cv_a == const_volatile_maybe_b);
                    CHECK_FALSE(const_volatile_maybe_cv_a == const_volatile_maybe_c_b);
                    CHECK_FALSE(const_volatile_maybe_cv_a == const_volatile_maybe_v_b);
                    CHECK_FALSE(const_volatile_maybe_cv_a == const_volatile_maybe_cv_b);
                }

                TEST_CASE("should return true for two maybes with different number types that have an equal value")
                {
                    u8_t random = Random<u8_t>(0, std::numeric_limits<s8_t>::max());
                    maybe_t<u8_t> maybe = random;

                    CHECK_TRUE(maybe == maybe_t<u16_t>(u16_t(random)));
                    CHECK_TRUE(maybe == maybe_t<u32_t>(u32_t(random)));
                    CHECK_TRUE(maybe == maybe_t<u64_t>(u64_t(random)));

                    CHECK_TRUE(maybe == maybe_t<s8_t>(s8_t(random)));
                    CHECK_TRUE(maybe == maybe_t<s16_t>(s16_t(random)));
                    CHECK_TRUE(maybe == maybe_t<s32_t>(s32_t(random)));
                    CHECK_TRUE(maybe == maybe_t<s64_t>(s64_t(random)));

                    CHECK_TRUE(maybe == maybe_t<r32_t>(r32_t(random)));
                    CHECK_TRUE(maybe == maybe_t<r64_t>(r64_t(random)));
                }

                TEST_CASE("should return false for two maybes with different number types that do not have an equal value")
                {
                    u8_t random_a = Random<u8_t>(0, std::numeric_limits<s8_t>::max());
                    u8_t random_b;
                    do {
                        random_b = Random<u8_t>(0, std::numeric_limits<s8_t>::max());
                    } while (random_b == random_a);
                    maybe_t<u8_t> maybe_a = random_a;

                    CHECK_FALSE(maybe_a == maybe_t<u16_t>(u16_t(random_b)));
                    CHECK_FALSE(maybe_a == maybe_t<u32_t>(u32_t(random_b)));
                    CHECK_FALSE(maybe_a == maybe_t<u64_t>(u64_t(random_b)));

                    CHECK_FALSE(maybe_a == maybe_t<s8_t>(s8_t(random_b)));
                    CHECK_FALSE(maybe_a == maybe_t<s16_t>(s16_t(random_b)));
                    CHECK_FALSE(maybe_a == maybe_t<s32_t>(s32_t(random_b)));
                    CHECK_FALSE(maybe_a == maybe_t<s64_t>(s64_t(random_b)));

                    CHECK_FALSE(maybe_a == maybe_t<r32_t>(r32_t(random_b)));
                    CHECK_FALSE(maybe_a == maybe_t<r64_t>(r64_t(random_b)));
                }
            }

            TEST_SUITE("!=(maybe_t, maybe_t)")
            {
                TEST_CASE_TEMPLATE("should return true for two maybes with the same type that do not have an equal value", maybe_p, nkr_ALL)
                {
                    using value_t = maybe_p::value_t;

                    value_t random_a = Random<value_t>();
                    std::remove_const_t<value_t> random_b;
                    do {
                        random_b = Random<value_t>();
                    } while (random_b == random_a);
                    maybe_p maybe_a = random_a;
                    maybe_p maybe_b = random_b;

                    CHECK_TRUE(maybe_a != maybe_b);
                }

                TEST_CASE_TEMPLATE("should return false for two maybes with the same type that have an equal value", maybe_p, nkr_ALL)
                {
                    using value_t = maybe_p::value_t;

                    value_t random = Random<value_t>();
                    maybe_p maybe_a = random;
                    maybe_p maybe_b = random;

                    CHECK_FALSE(maybe_a != maybe_b);
                }

                TEST_CASE_TEMPLATE("should return true for two maybes of different reference types with the same type that do not have an equal value", value_p, nkr_ALL_VALUES)
                {
                    value_p random_a = Random<value_p>();
                    std::remove_const_t<value_p> random_b;
                    do {
                        random_b = Random<value_p>();
                    } while (random_b == random_a);
                    maybe_t<value_p> maybe_a = random_a;
                    maybe_t<value_p> maybe_b = random_b;

                    CHECK_TRUE(maybe_a != maybe_b);
                    CHECK_TRUE(maybe_a != maybe_t<value_p>(random_b));
                    CHECK_TRUE(maybe_t<value_p>(random_a) != maybe_b);
                    CHECK_TRUE(maybe_t<value_p>(random_a) != maybe_t<value_p>(random_b));
                }

                TEST_CASE_TEMPLATE("should return false for two maybes of different reference types with the same type that have an equal value", value_p, nkr_ALL_VALUES)
                {
                    value_p random = Random<value_p>();
                    maybe_t<value_p> maybe_a = random;
                    maybe_t<value_p> maybe_b = random;

                    CHECK_FALSE(maybe_a != maybe_b);
                    CHECK_FALSE(maybe_a != maybe_t<value_p>(random));
                    CHECK_FALSE(maybe_t<value_p>(random) != maybe_b);
                    CHECK_FALSE(maybe_t<value_p>(random) != maybe_t<value_p>(random));
                }

                TEST_CASE_TEMPLATE("should return true for two maybes with the same but differently qualified types that do not have an equal value", value_p, nkr_JUST_NON_QUALIFIED_VALUES)
                {
                    value_p random_a = Random<value_p>();
                    value_p random_b;
                    do {
                        random_b = Random<value_p>();
                    } while (random_b == random_a);

                    CHECK_TRUE(maybe_t<value_p>(random_a) != maybe_t<const value_p>(random_b));
                    CHECK_TRUE(maybe_t<value_p>(random_a) != maybe_t<volatile value_p>(random_b));
                    CHECK_TRUE(maybe_t<value_p>(random_a) != maybe_t<const volatile value_p>(random_b));

                    CHECK_TRUE(maybe_t<const value_p>(random_a) != maybe_t<value_p>(random_b));
                    CHECK_TRUE(maybe_t<const value_p>(random_a) != maybe_t<volatile value_p>(random_b));
                    CHECK_TRUE(maybe_t<const value_p>(random_a) != maybe_t<const volatile value_p>(random_b));

                    CHECK_TRUE(maybe_t<volatile value_p>(random_a) != maybe_t<value_p>(random_b));
                    CHECK_TRUE(maybe_t<volatile value_p>(random_a) != maybe_t<const value_p>(random_b));
                    CHECK_TRUE(maybe_t<volatile value_p>(random_a) != maybe_t<const volatile value_p>(random_b));

                    CHECK_TRUE(maybe_t<const volatile value_p>(random_a) != maybe_t<value_p>(random_b));
                    CHECK_TRUE(maybe_t<const volatile value_p>(random_a) != maybe_t<const value_p>(random_b));
                    CHECK_TRUE(maybe_t<const volatile value_p>(random_a) != maybe_t<volatile value_p>(random_b));
                }

                TEST_CASE_TEMPLATE("should return false for two maybes with the same but differently qualified types that have an equal value", value_p, nkr_JUST_NON_QUALIFIED_VALUES)
                {
                    value_p random = Random<value_p>();

                    CHECK_FALSE(maybe_t<value_p>(random) != maybe_t<const value_p>(random));
                    CHECK_FALSE(maybe_t<value_p>(random) != maybe_t<volatile value_p>(random));
                    CHECK_FALSE(maybe_t<value_p>(random) != maybe_t<const volatile value_p>(random));

                    CHECK_FALSE(maybe_t<const value_p>(random) != maybe_t<value_p>(random));
                    CHECK_FALSE(maybe_t<const value_p>(random) != maybe_t<volatile value_p>(random));
                    CHECK_FALSE(maybe_t<const value_p>(random) != maybe_t<const volatile value_p>(random));

                    CHECK_FALSE(maybe_t<volatile value_p>(random) != maybe_t<value_p>(random));
                    CHECK_FALSE(maybe_t<volatile value_p>(random) != maybe_t<const value_p>(random));
                    CHECK_FALSE(maybe_t<volatile value_p>(random) != maybe_t<const volatile value_p>(random));

                    CHECK_FALSE(maybe_t<const volatile value_p>(random) != maybe_t<value_p>(random));
                    CHECK_FALSE(maybe_t<const volatile value_p>(random) != maybe_t<const value_p>(random));
                    CHECK_FALSE(maybe_t<const volatile value_p>(random) != maybe_t<volatile value_p>(random));
                }

                TEST_CASE_TEMPLATE("should return true for two differently qualified maybes with the same type that do not have an equal value", value_p, nkr_ALL_VALUES)
                {
                    value_p random_a = Random<value_p>();
                    std::remove_const_t<value_p> random_b;
                    do {
                        random_b = Random<value_p>();
                    } while (random_b == random_a);
                    maybe_t<value_p> maybe_a = random_a;
                    maybe_t<value_p> maybe_b = random_b;
                    const maybe_t<value_p> const_maybe_a = random_a;
                    const maybe_t<value_p> const_maybe_b = random_b;
                    volatile maybe_t<value_p> volatile_maybe_a = random_a;
                    volatile maybe_t<value_p> volatile_maybe_b = random_b;
                    const volatile maybe_t<value_p> const_volatile_maybe_a = random_a;
                    const volatile maybe_t<value_p> const_volatile_maybe_b = random_b;

                    CHECK_TRUE(maybe_a != const_maybe_b);
                    CHECK_TRUE(maybe_a != volatile_maybe_b);
                    CHECK_TRUE(maybe_a != const_volatile_maybe_b);

                    CHECK_TRUE(const_maybe_a != maybe_b);
                    CHECK_TRUE(const_maybe_a != volatile_maybe_b);
                    CHECK_TRUE(const_maybe_a != const_volatile_maybe_b);

                    CHECK_TRUE(volatile_maybe_a != maybe_b);
                    CHECK_TRUE(volatile_maybe_a != const_maybe_b);
                    CHECK_TRUE(volatile_maybe_a != const_volatile_maybe_b);

                    CHECK_TRUE(const_volatile_maybe_a != maybe_b);
                    CHECK_TRUE(const_volatile_maybe_a != const_maybe_b);
                    CHECK_TRUE(const_volatile_maybe_a != volatile_maybe_b);
                }

                TEST_CASE_TEMPLATE("should return false for two differently qualified maybes with the same type that have an equal value", value_p, nkr_ALL_VALUES)
                {
                    value_p random = Random<value_p>();
                    maybe_t<value_p> maybe = random;
                    const maybe_t<value_p> const_maybe = random;
                    volatile maybe_t<value_p> volatile_maybe = random;
                    const volatile maybe_t<value_p> const_volatile_maybe = random;

                    CHECK_FALSE(maybe != const_maybe);
                    CHECK_FALSE(maybe != volatile_maybe);
                    CHECK_FALSE(maybe != const_volatile_maybe);

                    CHECK_FALSE(const_maybe != maybe);
                    CHECK_FALSE(const_maybe != volatile_maybe);
                    CHECK_FALSE(const_maybe != const_volatile_maybe);

                    CHECK_FALSE(volatile_maybe != maybe);
                    CHECK_FALSE(volatile_maybe != const_maybe);
                    CHECK_FALSE(volatile_maybe != const_volatile_maybe);

                    CHECK_FALSE(const_volatile_maybe != maybe);
                    CHECK_FALSE(const_volatile_maybe != const_maybe);
                    CHECK_FALSE(const_volatile_maybe != volatile_maybe);
                }

                TEST_CASE_TEMPLATE("should return true for two differently qualified maybes with the same but differently qualified types that do not have an equal value", value_p, nkr_JUST_NON_QUALIFIED_VALUES)
                {
                    value_p random_a = Random<value_p>();
                    std::remove_const_t<value_p> random_b;
                    do {
                        random_b = Random<value_p>();
                    } while (random_b == random_a);
                    maybe_t<value_p> maybe_a = random_a;
                    maybe_t<value_p> maybe_b = random_b;
                    maybe_t<const value_p> maybe_c_a = random_a;
                    maybe_t<const value_p> maybe_c_b = random_b;
                    maybe_t<volatile value_p> maybe_v_a = random_a;
                    maybe_t<volatile value_p> maybe_v_b = random_b;
                    maybe_t<const volatile value_p> maybe_cv_a = random_a;
                    maybe_t<const volatile value_p> maybe_cv_b = random_b;
                    const maybe_t<value_p> const_maybe_a = random_a;
                    const maybe_t<value_p> const_maybe_b = random_b;
                    const maybe_t<const value_p> const_maybe_c_a = random_a;
                    const maybe_t<const value_p> const_maybe_c_b = random_b;
                    const maybe_t<volatile value_p> const_maybe_v_a = random_a;
                    const maybe_t<volatile value_p> const_maybe_v_b = random_b;
                    const maybe_t<const volatile value_p> const_maybe_cv_a = random_a;
                    const maybe_t<const volatile value_p> const_maybe_cv_b = random_b;
                    volatile maybe_t<value_p> volatile_maybe_a = random_a;
                    volatile maybe_t<value_p> volatile_maybe_b = random_b;
                    volatile maybe_t<const value_p> volatile_maybe_c_a = random_a;
                    volatile maybe_t<const value_p> volatile_maybe_c_b = random_b;
                    volatile maybe_t<volatile value_p> volatile_maybe_v_a = random_a;
                    volatile maybe_t<volatile value_p> volatile_maybe_v_b = random_b;
                    volatile maybe_t<const volatile value_p> volatile_maybe_cv_a = random_a;
                    volatile maybe_t<const volatile value_p> volatile_maybe_cv_b = random_b;
                    const volatile maybe_t<value_p> const_volatile_maybe_a = random_a;
                    const volatile maybe_t<value_p> const_volatile_maybe_b = random_b;
                    const volatile maybe_t<const value_p> const_volatile_maybe_c_a = random_a;
                    const volatile maybe_t<const value_p> const_volatile_maybe_c_b = random_b;
                    const volatile maybe_t<volatile value_p> const_volatile_maybe_v_a = random_a;
                    const volatile maybe_t<volatile value_p> const_volatile_maybe_v_b = random_b;
                    const volatile maybe_t<const volatile value_p> const_volatile_maybe_cv_a = random_a;
                    const volatile maybe_t<const volatile value_p> const_volatile_maybe_cv_b = random_b;

                    CHECK_TRUE(maybe_a != maybe_b);
                    CHECK_TRUE(maybe_a != maybe_c_b);
                    CHECK_TRUE(maybe_a != maybe_v_b);
                    CHECK_TRUE(maybe_a != maybe_cv_b);
                    CHECK_TRUE(maybe_a != const_maybe_b);
                    CHECK_TRUE(maybe_a != const_maybe_c_b);
                    CHECK_TRUE(maybe_a != const_maybe_v_b);
                    CHECK_TRUE(maybe_a != const_maybe_cv_b);
                    CHECK_TRUE(maybe_a != volatile_maybe_b);
                    CHECK_TRUE(maybe_a != volatile_maybe_c_b);
                    CHECK_TRUE(maybe_a != volatile_maybe_v_b);
                    CHECK_TRUE(maybe_a != volatile_maybe_cv_b);
                    CHECK_TRUE(maybe_a != const_volatile_maybe_b);
                    CHECK_TRUE(maybe_a != const_volatile_maybe_c_b);
                    CHECK_TRUE(maybe_a != const_volatile_maybe_v_b);
                    CHECK_TRUE(maybe_a != const_volatile_maybe_cv_b);

                    CHECK_TRUE(maybe_c_a != maybe_b);
                    CHECK_TRUE(maybe_c_a != maybe_c_b);
                    CHECK_TRUE(maybe_c_a != maybe_v_b);
                    CHECK_TRUE(maybe_c_a != maybe_cv_b);
                    CHECK_TRUE(maybe_c_a != const_maybe_b);
                    CHECK_TRUE(maybe_c_a != const_maybe_c_b);
                    CHECK_TRUE(maybe_c_a != const_maybe_v_b);
                    CHECK_TRUE(maybe_c_a != const_maybe_cv_b);
                    CHECK_TRUE(maybe_c_a != volatile_maybe_b);
                    CHECK_TRUE(maybe_c_a != volatile_maybe_c_b);
                    CHECK_TRUE(maybe_c_a != volatile_maybe_v_b);
                    CHECK_TRUE(maybe_c_a != volatile_maybe_cv_b);
                    CHECK_TRUE(maybe_c_a != const_volatile_maybe_b);
                    CHECK_TRUE(maybe_c_a != const_volatile_maybe_c_b);
                    CHECK_TRUE(maybe_c_a != const_volatile_maybe_v_b);
                    CHECK_TRUE(maybe_c_a != const_volatile_maybe_cv_b);

                    CHECK_TRUE(maybe_v_a != maybe_b);
                    CHECK_TRUE(maybe_v_a != maybe_c_b);
                    CHECK_TRUE(maybe_v_a != maybe_v_b);
                    CHECK_TRUE(maybe_v_a != maybe_cv_b);
                    CHECK_TRUE(maybe_v_a != const_maybe_b);
                    CHECK_TRUE(maybe_v_a != const_maybe_c_b);
                    CHECK_TRUE(maybe_v_a != const_maybe_v_b);
                    CHECK_TRUE(maybe_v_a != const_maybe_cv_b);
                    CHECK_TRUE(maybe_v_a != volatile_maybe_b);
                    CHECK_TRUE(maybe_v_a != volatile_maybe_c_b);
                    CHECK_TRUE(maybe_v_a != volatile_maybe_v_b);
                    CHECK_TRUE(maybe_v_a != volatile_maybe_cv_b);
                    CHECK_TRUE(maybe_v_a != const_volatile_maybe_b);
                    CHECK_TRUE(maybe_v_a != const_volatile_maybe_c_b);
                    CHECK_TRUE(maybe_v_a != const_volatile_maybe_v_b);
                    CHECK_TRUE(maybe_v_a != const_volatile_maybe_cv_b);

                    CHECK_TRUE(maybe_cv_a != maybe_b);
                    CHECK_TRUE(maybe_cv_a != maybe_c_b);
                    CHECK_TRUE(maybe_cv_a != maybe_v_b);
                    CHECK_TRUE(maybe_cv_a != maybe_cv_b);
                    CHECK_TRUE(maybe_cv_a != const_maybe_b);
                    CHECK_TRUE(maybe_cv_a != const_maybe_c_b);
                    CHECK_TRUE(maybe_cv_a != const_maybe_v_b);
                    CHECK_TRUE(maybe_cv_a != const_maybe_cv_b);
                    CHECK_TRUE(maybe_cv_a != volatile_maybe_b);
                    CHECK_TRUE(maybe_cv_a != volatile_maybe_c_b);
                    CHECK_TRUE(maybe_cv_a != volatile_maybe_v_b);
                    CHECK_TRUE(maybe_cv_a != volatile_maybe_cv_b);
                    CHECK_TRUE(maybe_cv_a != const_volatile_maybe_b);
                    CHECK_TRUE(maybe_cv_a != const_volatile_maybe_c_b);
                    CHECK_TRUE(maybe_cv_a != const_volatile_maybe_v_b);
                    CHECK_TRUE(maybe_cv_a != const_volatile_maybe_cv_b);

                    CHECK_TRUE(const_maybe_a != maybe_b);
                    CHECK_TRUE(const_maybe_a != maybe_c_b);
                    CHECK_TRUE(const_maybe_a != maybe_v_b);
                    CHECK_TRUE(const_maybe_a != maybe_cv_b);
                    CHECK_TRUE(const_maybe_a != const_maybe_b);
                    CHECK_TRUE(const_maybe_a != const_maybe_c_b);
                    CHECK_TRUE(const_maybe_a != const_maybe_v_b);
                    CHECK_TRUE(const_maybe_a != const_maybe_cv_b);
                    CHECK_TRUE(const_maybe_a != volatile_maybe_b);
                    CHECK_TRUE(const_maybe_a != volatile_maybe_c_b);
                    CHECK_TRUE(const_maybe_a != volatile_maybe_v_b);
                    CHECK_TRUE(const_maybe_a != volatile_maybe_cv_b);
                    CHECK_TRUE(const_maybe_a != const_volatile_maybe_b);
                    CHECK_TRUE(const_maybe_a != const_volatile_maybe_c_b);
                    CHECK_TRUE(const_maybe_a != const_volatile_maybe_v_b);
                    CHECK_TRUE(const_maybe_a != const_volatile_maybe_cv_b);

                    CHECK_TRUE(const_maybe_c_a != maybe_b);
                    CHECK_TRUE(const_maybe_c_a != maybe_c_b);
                    CHECK_TRUE(const_maybe_c_a != maybe_v_b);
                    CHECK_TRUE(const_maybe_c_a != maybe_cv_b);
                    CHECK_TRUE(const_maybe_c_a != const_maybe_b);
                    CHECK_TRUE(const_maybe_c_a != const_maybe_c_b);
                    CHECK_TRUE(const_maybe_c_a != const_maybe_v_b);
                    CHECK_TRUE(const_maybe_c_a != const_maybe_cv_b);
                    CHECK_TRUE(const_maybe_c_a != volatile_maybe_b);
                    CHECK_TRUE(const_maybe_c_a != volatile_maybe_c_b);
                    CHECK_TRUE(const_maybe_c_a != volatile_maybe_v_b);
                    CHECK_TRUE(const_maybe_c_a != volatile_maybe_cv_b);
                    CHECK_TRUE(const_maybe_c_a != const_volatile_maybe_b);
                    CHECK_TRUE(const_maybe_c_a != const_volatile_maybe_c_b);
                    CHECK_TRUE(const_maybe_c_a != const_volatile_maybe_v_b);
                    CHECK_TRUE(const_maybe_c_a != const_volatile_maybe_cv_b);

                    CHECK_TRUE(const_maybe_v_a != maybe_b);
                    CHECK_TRUE(const_maybe_v_a != maybe_c_b);
                    CHECK_TRUE(const_maybe_v_a != maybe_v_b);
                    CHECK_TRUE(const_maybe_v_a != maybe_cv_b);
                    CHECK_TRUE(const_maybe_v_a != const_maybe_b);
                    CHECK_TRUE(const_maybe_v_a != const_maybe_c_b);
                    CHECK_TRUE(const_maybe_v_a != const_maybe_v_b);
                    CHECK_TRUE(const_maybe_v_a != const_maybe_cv_b);
                    CHECK_TRUE(const_maybe_v_a != volatile_maybe_b);
                    CHECK_TRUE(const_maybe_v_a != volatile_maybe_c_b);
                    CHECK_TRUE(const_maybe_v_a != volatile_maybe_v_b);
                    CHECK_TRUE(const_maybe_v_a != volatile_maybe_cv_b);
                    CHECK_TRUE(const_maybe_v_a != const_volatile_maybe_b);
                    CHECK_TRUE(const_maybe_v_a != const_volatile_maybe_c_b);
                    CHECK_TRUE(const_maybe_v_a != const_volatile_maybe_v_b);
                    CHECK_TRUE(const_maybe_v_a != const_volatile_maybe_cv_b);

                    CHECK_TRUE(const_maybe_cv_a != maybe_b);
                    CHECK_TRUE(const_maybe_cv_a != maybe_c_b);
                    CHECK_TRUE(const_maybe_cv_a != maybe_v_b);
                    CHECK_TRUE(const_maybe_cv_a != maybe_cv_b);
                    CHECK_TRUE(const_maybe_cv_a != const_maybe_b);
                    CHECK_TRUE(const_maybe_cv_a != const_maybe_c_b);
                    CHECK_TRUE(const_maybe_cv_a != const_maybe_v_b);
                    CHECK_TRUE(const_maybe_cv_a != const_maybe_cv_b);
                    CHECK_TRUE(const_maybe_cv_a != volatile_maybe_b);
                    CHECK_TRUE(const_maybe_cv_a != volatile_maybe_c_b);
                    CHECK_TRUE(const_maybe_cv_a != volatile_maybe_v_b);
                    CHECK_TRUE(const_maybe_cv_a != volatile_maybe_cv_b);
                    CHECK_TRUE(const_maybe_cv_a != const_volatile_maybe_b);
                    CHECK_TRUE(const_maybe_cv_a != const_volatile_maybe_c_b);
                    CHECK_TRUE(const_maybe_cv_a != const_volatile_maybe_v_b);
                    CHECK_TRUE(const_maybe_cv_a != const_volatile_maybe_cv_b);

                    CHECK_TRUE(volatile_maybe_a != maybe_b);
                    CHECK_TRUE(volatile_maybe_a != maybe_c_b);
                    CHECK_TRUE(volatile_maybe_a != maybe_v_b);
                    CHECK_TRUE(volatile_maybe_a != maybe_cv_b);
                    CHECK_TRUE(volatile_maybe_a != const_maybe_b);
                    CHECK_TRUE(volatile_maybe_a != const_maybe_c_b);
                    CHECK_TRUE(volatile_maybe_a != const_maybe_v_b);
                    CHECK_TRUE(volatile_maybe_a != const_maybe_cv_b);
                    CHECK_TRUE(volatile_maybe_a != volatile_maybe_b);
                    CHECK_TRUE(volatile_maybe_a != volatile_maybe_c_b);
                    CHECK_TRUE(volatile_maybe_a != volatile_maybe_v_b);
                    CHECK_TRUE(volatile_maybe_a != volatile_maybe_cv_b);
                    CHECK_TRUE(volatile_maybe_a != const_volatile_maybe_b);
                    CHECK_TRUE(volatile_maybe_a != const_volatile_maybe_c_b);
                    CHECK_TRUE(volatile_maybe_a != const_volatile_maybe_v_b);
                    CHECK_TRUE(volatile_maybe_a != const_volatile_maybe_cv_b);

                    CHECK_TRUE(volatile_maybe_c_a != maybe_b);
                    CHECK_TRUE(volatile_maybe_c_a != maybe_c_b);
                    CHECK_TRUE(volatile_maybe_c_a != maybe_v_b);
                    CHECK_TRUE(volatile_maybe_c_a != maybe_cv_b);
                    CHECK_TRUE(volatile_maybe_c_a != const_maybe_b);
                    CHECK_TRUE(volatile_maybe_c_a != const_maybe_c_b);
                    CHECK_TRUE(volatile_maybe_c_a != const_maybe_v_b);
                    CHECK_TRUE(volatile_maybe_c_a != const_maybe_cv_b);
                    CHECK_TRUE(volatile_maybe_c_a != volatile_maybe_b);
                    CHECK_TRUE(volatile_maybe_c_a != volatile_maybe_c_b);
                    CHECK_TRUE(volatile_maybe_c_a != volatile_maybe_v_b);
                    CHECK_TRUE(volatile_maybe_c_a != volatile_maybe_cv_b);
                    CHECK_TRUE(volatile_maybe_c_a != const_volatile_maybe_b);
                    CHECK_TRUE(volatile_maybe_c_a != const_volatile_maybe_c_b);
                    CHECK_TRUE(volatile_maybe_c_a != const_volatile_maybe_v_b);
                    CHECK_TRUE(volatile_maybe_c_a != const_volatile_maybe_cv_b);

                    CHECK_TRUE(volatile_maybe_v_a != maybe_b);
                    CHECK_TRUE(volatile_maybe_v_a != maybe_c_b);
                    CHECK_TRUE(volatile_maybe_v_a != maybe_v_b);
                    CHECK_TRUE(volatile_maybe_v_a != maybe_cv_b);
                    CHECK_TRUE(volatile_maybe_v_a != const_maybe_b);
                    CHECK_TRUE(volatile_maybe_v_a != const_maybe_c_b);
                    CHECK_TRUE(volatile_maybe_v_a != const_maybe_v_b);
                    CHECK_TRUE(volatile_maybe_v_a != const_maybe_cv_b);
                    CHECK_TRUE(volatile_maybe_v_a != volatile_maybe_b);
                    CHECK_TRUE(volatile_maybe_v_a != volatile_maybe_c_b);
                    CHECK_TRUE(volatile_maybe_v_a != volatile_maybe_v_b);
                    CHECK_TRUE(volatile_maybe_v_a != volatile_maybe_cv_b);
                    CHECK_TRUE(volatile_maybe_v_a != const_volatile_maybe_b);
                    CHECK_TRUE(volatile_maybe_v_a != const_volatile_maybe_c_b);
                    CHECK_TRUE(volatile_maybe_v_a != const_volatile_maybe_v_b);
                    CHECK_TRUE(volatile_maybe_v_a != const_volatile_maybe_cv_b);

                    CHECK_TRUE(volatile_maybe_cv_a != maybe_b);
                    CHECK_TRUE(volatile_maybe_cv_a != maybe_c_b);
                    CHECK_TRUE(volatile_maybe_cv_a != maybe_v_b);
                    CHECK_TRUE(volatile_maybe_cv_a != maybe_cv_b);
                    CHECK_TRUE(volatile_maybe_cv_a != const_maybe_b);
                    CHECK_TRUE(volatile_maybe_cv_a != const_maybe_c_b);
                    CHECK_TRUE(volatile_maybe_cv_a != const_maybe_v_b);
                    CHECK_TRUE(volatile_maybe_cv_a != const_maybe_cv_b);
                    CHECK_TRUE(volatile_maybe_cv_a != volatile_maybe_b);
                    CHECK_TRUE(volatile_maybe_cv_a != volatile_maybe_c_b);
                    CHECK_TRUE(volatile_maybe_cv_a != volatile_maybe_v_b);
                    CHECK_TRUE(volatile_maybe_cv_a != volatile_maybe_cv_b);
                    CHECK_TRUE(volatile_maybe_cv_a != const_volatile_maybe_b);
                    CHECK_TRUE(volatile_maybe_cv_a != const_volatile_maybe_c_b);
                    CHECK_TRUE(volatile_maybe_cv_a != const_volatile_maybe_v_b);
                    CHECK_TRUE(volatile_maybe_cv_a != const_volatile_maybe_cv_b);

                    CHECK_TRUE(const_volatile_maybe_a != maybe_b);
                    CHECK_TRUE(const_volatile_maybe_a != maybe_c_b);
                    CHECK_TRUE(const_volatile_maybe_a != maybe_v_b);
                    CHECK_TRUE(const_volatile_maybe_a != maybe_cv_b);
                    CHECK_TRUE(const_volatile_maybe_a != const_maybe_b);
                    CHECK_TRUE(const_volatile_maybe_a != const_maybe_c_b);
                    CHECK_TRUE(const_volatile_maybe_a != const_maybe_v_b);
                    CHECK_TRUE(const_volatile_maybe_a != const_maybe_cv_b);
                    CHECK_TRUE(const_volatile_maybe_a != volatile_maybe_b);
                    CHECK_TRUE(const_volatile_maybe_a != volatile_maybe_c_b);
                    CHECK_TRUE(const_volatile_maybe_a != volatile_maybe_v_b);
                    CHECK_TRUE(const_volatile_maybe_a != volatile_maybe_cv_b);
                    CHECK_TRUE(const_volatile_maybe_a != const_volatile_maybe_b);
                    CHECK_TRUE(const_volatile_maybe_a != const_volatile_maybe_c_b);
                    CHECK_TRUE(const_volatile_maybe_a != const_volatile_maybe_v_b);
                    CHECK_TRUE(const_volatile_maybe_a != const_volatile_maybe_cv_b);

                    CHECK_TRUE(const_volatile_maybe_c_a != maybe_b);
                    CHECK_TRUE(const_volatile_maybe_c_a != maybe_c_b);
                    CHECK_TRUE(const_volatile_maybe_c_a != maybe_v_b);
                    CHECK_TRUE(const_volatile_maybe_c_a != maybe_cv_b);
                    CHECK_TRUE(const_volatile_maybe_c_a != const_maybe_b);
                    CHECK_TRUE(const_volatile_maybe_c_a != const_maybe_c_b);
                    CHECK_TRUE(const_volatile_maybe_c_a != const_maybe_v_b);
                    CHECK_TRUE(const_volatile_maybe_c_a != const_maybe_cv_b);
                    CHECK_TRUE(const_volatile_maybe_c_a != volatile_maybe_b);
                    CHECK_TRUE(const_volatile_maybe_c_a != volatile_maybe_c_b);
                    CHECK_TRUE(const_volatile_maybe_c_a != volatile_maybe_v_b);
                    CHECK_TRUE(const_volatile_maybe_c_a != volatile_maybe_cv_b);
                    CHECK_TRUE(const_volatile_maybe_c_a != const_volatile_maybe_b);
                    CHECK_TRUE(const_volatile_maybe_c_a != const_volatile_maybe_c_b);
                    CHECK_TRUE(const_volatile_maybe_c_a != const_volatile_maybe_v_b);
                    CHECK_TRUE(const_volatile_maybe_c_a != const_volatile_maybe_cv_b);

                    CHECK_TRUE(const_volatile_maybe_v_a != maybe_b);
                    CHECK_TRUE(const_volatile_maybe_v_a != maybe_c_b);
                    CHECK_TRUE(const_volatile_maybe_v_a != maybe_v_b);
                    CHECK_TRUE(const_volatile_maybe_v_a != maybe_cv_b);
                    CHECK_TRUE(const_volatile_maybe_v_a != const_maybe_b);
                    CHECK_TRUE(const_volatile_maybe_v_a != const_maybe_c_b);
                    CHECK_TRUE(const_volatile_maybe_v_a != const_maybe_v_b);
                    CHECK_TRUE(const_volatile_maybe_v_a != const_maybe_cv_b);
                    CHECK_TRUE(const_volatile_maybe_v_a != volatile_maybe_b);
                    CHECK_TRUE(const_volatile_maybe_v_a != volatile_maybe_c_b);
                    CHECK_TRUE(const_volatile_maybe_v_a != volatile_maybe_v_b);
                    CHECK_TRUE(const_volatile_maybe_v_a != volatile_maybe_cv_b);
                    CHECK_TRUE(const_volatile_maybe_v_a != const_volatile_maybe_b);
                    CHECK_TRUE(const_volatile_maybe_v_a != const_volatile_maybe_c_b);
                    CHECK_TRUE(const_volatile_maybe_v_a != const_volatile_maybe_v_b);
                    CHECK_TRUE(const_volatile_maybe_v_a != const_volatile_maybe_cv_b);

                    CHECK_TRUE(const_volatile_maybe_cv_a != maybe_b);
                    CHECK_TRUE(const_volatile_maybe_cv_a != maybe_c_b);
                    CHECK_TRUE(const_volatile_maybe_cv_a != maybe_v_b);
                    CHECK_TRUE(const_volatile_maybe_cv_a != maybe_cv_b);
                    CHECK_TRUE(const_volatile_maybe_cv_a != const_maybe_b);
                    CHECK_TRUE(const_volatile_maybe_cv_a != const_maybe_c_b);
                    CHECK_TRUE(const_volatile_maybe_cv_a != const_maybe_v_b);
                    CHECK_TRUE(const_volatile_maybe_cv_a != const_maybe_cv_b);
                    CHECK_TRUE(const_volatile_maybe_cv_a != volatile_maybe_b);
                    CHECK_TRUE(const_volatile_maybe_cv_a != volatile_maybe_c_b);
                    CHECK_TRUE(const_volatile_maybe_cv_a != volatile_maybe_v_b);
                    CHECK_TRUE(const_volatile_maybe_cv_a != volatile_maybe_cv_b);
                    CHECK_TRUE(const_volatile_maybe_cv_a != const_volatile_maybe_b);
                    CHECK_TRUE(const_volatile_maybe_cv_a != const_volatile_maybe_c_b);
                    CHECK_TRUE(const_volatile_maybe_cv_a != const_volatile_maybe_v_b);
                    CHECK_TRUE(const_volatile_maybe_cv_a != const_volatile_maybe_cv_b);
                }

                TEST_CASE_TEMPLATE("should return false for two differently qualified maybes with the same but differently qualified types that have an equal value", value_p, nkr_JUST_NON_QUALIFIED_VALUES)
                {
                    value_p random = Random<value_p>();
                    maybe_t<value_p> maybe = random;
                    maybe_t<const value_p> maybe_c = random;
                    maybe_t<volatile value_p> maybe_v = random;
                    maybe_t<const volatile value_p> maybe_cv = random;
                    const maybe_t<value_p> const_maybe = random;
                    const maybe_t<const value_p> const_maybe_c = random;
                    const maybe_t<volatile value_p> const_maybe_v = random;
                    const maybe_t<const volatile value_p> const_maybe_cv = random;
                    volatile maybe_t<value_p> volatile_maybe = random;
                    volatile maybe_t<const value_p> volatile_maybe_c = random;
                    volatile maybe_t<volatile value_p> volatile_maybe_v = random;
                    volatile maybe_t<const volatile value_p> volatile_maybe_cv = random;
                    const volatile maybe_t<value_p> const_volatile_maybe = random;
                    const volatile maybe_t<const value_p> const_volatile_maybe_c = random;
                    const volatile maybe_t<volatile value_p> const_volatile_maybe_v = random;
                    const volatile maybe_t<const volatile value_p> const_volatile_maybe_cv = random;

                    CHECK_FALSE(maybe != maybe);
                    CHECK_FALSE(maybe != maybe_c);
                    CHECK_FALSE(maybe != maybe_v);
                    CHECK_FALSE(maybe != maybe_cv);
                    CHECK_FALSE(maybe != const_maybe);
                    CHECK_FALSE(maybe != const_maybe_c);
                    CHECK_FALSE(maybe != const_maybe_v);
                    CHECK_FALSE(maybe != const_maybe_cv);
                    CHECK_FALSE(maybe != volatile_maybe);
                    CHECK_FALSE(maybe != volatile_maybe_c);
                    CHECK_FALSE(maybe != volatile_maybe_v);
                    CHECK_FALSE(maybe != volatile_maybe_cv);
                    CHECK_FALSE(maybe != const_volatile_maybe);
                    CHECK_FALSE(maybe != const_volatile_maybe_c);
                    CHECK_FALSE(maybe != const_volatile_maybe_v);
                    CHECK_FALSE(maybe != const_volatile_maybe_cv);

                    CHECK_FALSE(maybe_c != maybe);
                    CHECK_FALSE(maybe_c != maybe_c);
                    CHECK_FALSE(maybe_c != maybe_v);
                    CHECK_FALSE(maybe_c != maybe_cv);
                    CHECK_FALSE(maybe_c != const_maybe);
                    CHECK_FALSE(maybe_c != const_maybe_c);
                    CHECK_FALSE(maybe_c != const_maybe_v);
                    CHECK_FALSE(maybe_c != const_maybe_cv);
                    CHECK_FALSE(maybe_c != volatile_maybe);
                    CHECK_FALSE(maybe_c != volatile_maybe_c);
                    CHECK_FALSE(maybe_c != volatile_maybe_v);
                    CHECK_FALSE(maybe_c != volatile_maybe_cv);
                    CHECK_FALSE(maybe_c != const_volatile_maybe);
                    CHECK_FALSE(maybe_c != const_volatile_maybe_c);
                    CHECK_FALSE(maybe_c != const_volatile_maybe_v);
                    CHECK_FALSE(maybe_c != const_volatile_maybe_cv);

                    CHECK_FALSE(maybe_v != maybe);
                    CHECK_FALSE(maybe_v != maybe_c);
                    CHECK_FALSE(maybe_v != maybe_v);
                    CHECK_FALSE(maybe_v != maybe_cv);
                    CHECK_FALSE(maybe_v != const_maybe);
                    CHECK_FALSE(maybe_v != const_maybe_c);
                    CHECK_FALSE(maybe_v != const_maybe_v);
                    CHECK_FALSE(maybe_v != const_maybe_cv);
                    CHECK_FALSE(maybe_v != volatile_maybe);
                    CHECK_FALSE(maybe_v != volatile_maybe_c);
                    CHECK_FALSE(maybe_v != volatile_maybe_v);
                    CHECK_FALSE(maybe_v != volatile_maybe_cv);
                    CHECK_FALSE(maybe_v != const_volatile_maybe);
                    CHECK_FALSE(maybe_v != const_volatile_maybe_c);
                    CHECK_FALSE(maybe_v != const_volatile_maybe_v);
                    CHECK_FALSE(maybe_v != const_volatile_maybe_cv);

                    CHECK_FALSE(maybe_cv != maybe);
                    CHECK_FALSE(maybe_cv != maybe_c);
                    CHECK_FALSE(maybe_cv != maybe_v);
                    CHECK_FALSE(maybe_cv != maybe_cv);
                    CHECK_FALSE(maybe_cv != const_maybe);
                    CHECK_FALSE(maybe_cv != const_maybe_c);
                    CHECK_FALSE(maybe_cv != const_maybe_v);
                    CHECK_FALSE(maybe_cv != const_maybe_cv);
                    CHECK_FALSE(maybe_cv != volatile_maybe);
                    CHECK_FALSE(maybe_cv != volatile_maybe_c);
                    CHECK_FALSE(maybe_cv != volatile_maybe_v);
                    CHECK_FALSE(maybe_cv != volatile_maybe_cv);
                    CHECK_FALSE(maybe_cv != const_volatile_maybe);
                    CHECK_FALSE(maybe_cv != const_volatile_maybe_c);
                    CHECK_FALSE(maybe_cv != const_volatile_maybe_v);
                    CHECK_FALSE(maybe_cv != const_volatile_maybe_cv);

                    CHECK_FALSE(const_maybe != maybe);
                    CHECK_FALSE(const_maybe != maybe_c);
                    CHECK_FALSE(const_maybe != maybe_v);
                    CHECK_FALSE(const_maybe != maybe_cv);
                    CHECK_FALSE(const_maybe != const_maybe);
                    CHECK_FALSE(const_maybe != const_maybe_c);
                    CHECK_FALSE(const_maybe != const_maybe_v);
                    CHECK_FALSE(const_maybe != const_maybe_cv);
                    CHECK_FALSE(const_maybe != volatile_maybe);
                    CHECK_FALSE(const_maybe != volatile_maybe_c);
                    CHECK_FALSE(const_maybe != volatile_maybe_v);
                    CHECK_FALSE(const_maybe != volatile_maybe_cv);
                    CHECK_FALSE(const_maybe != const_volatile_maybe);
                    CHECK_FALSE(const_maybe != const_volatile_maybe_c);
                    CHECK_FALSE(const_maybe != const_volatile_maybe_v);
                    CHECK_FALSE(const_maybe != const_volatile_maybe_cv);

                    CHECK_FALSE(const_maybe_c != maybe);
                    CHECK_FALSE(const_maybe_c != maybe_c);
                    CHECK_FALSE(const_maybe_c != maybe_v);
                    CHECK_FALSE(const_maybe_c != maybe_cv);
                    CHECK_FALSE(const_maybe_c != const_maybe);
                    CHECK_FALSE(const_maybe_c != const_maybe_c);
                    CHECK_FALSE(const_maybe_c != const_maybe_v);
                    CHECK_FALSE(const_maybe_c != const_maybe_cv);
                    CHECK_FALSE(const_maybe_c != volatile_maybe);
                    CHECK_FALSE(const_maybe_c != volatile_maybe_c);
                    CHECK_FALSE(const_maybe_c != volatile_maybe_v);
                    CHECK_FALSE(const_maybe_c != volatile_maybe_cv);
                    CHECK_FALSE(const_maybe_c != const_volatile_maybe);
                    CHECK_FALSE(const_maybe_c != const_volatile_maybe_c);
                    CHECK_FALSE(const_maybe_c != const_volatile_maybe_v);
                    CHECK_FALSE(const_maybe_c != const_volatile_maybe_cv);

                    CHECK_FALSE(const_maybe_v != maybe);
                    CHECK_FALSE(const_maybe_v != maybe_c);
                    CHECK_FALSE(const_maybe_v != maybe_v);
                    CHECK_FALSE(const_maybe_v != maybe_cv);
                    CHECK_FALSE(const_maybe_v != const_maybe);
                    CHECK_FALSE(const_maybe_v != const_maybe_c);
                    CHECK_FALSE(const_maybe_v != const_maybe_v);
                    CHECK_FALSE(const_maybe_v != const_maybe_cv);
                    CHECK_FALSE(const_maybe_v != volatile_maybe);
                    CHECK_FALSE(const_maybe_v != volatile_maybe_c);
                    CHECK_FALSE(const_maybe_v != volatile_maybe_v);
                    CHECK_FALSE(const_maybe_v != volatile_maybe_cv);
                    CHECK_FALSE(const_maybe_v != const_volatile_maybe);
                    CHECK_FALSE(const_maybe_v != const_volatile_maybe_c);
                    CHECK_FALSE(const_maybe_v != const_volatile_maybe_v);
                    CHECK_FALSE(const_maybe_v != const_volatile_maybe_cv);

                    CHECK_FALSE(const_maybe_cv != maybe);
                    CHECK_FALSE(const_maybe_cv != maybe_c);
                    CHECK_FALSE(const_maybe_cv != maybe_v);
                    CHECK_FALSE(const_maybe_cv != maybe_cv);
                    CHECK_FALSE(const_maybe_cv != const_maybe);
                    CHECK_FALSE(const_maybe_cv != const_maybe_c);
                    CHECK_FALSE(const_maybe_cv != const_maybe_v);
                    CHECK_FALSE(const_maybe_cv != const_maybe_cv);
                    CHECK_FALSE(const_maybe_cv != volatile_maybe);
                    CHECK_FALSE(const_maybe_cv != volatile_maybe_c);
                    CHECK_FALSE(const_maybe_cv != volatile_maybe_v);
                    CHECK_FALSE(const_maybe_cv != volatile_maybe_cv);
                    CHECK_FALSE(const_maybe_cv != const_volatile_maybe);
                    CHECK_FALSE(const_maybe_cv != const_volatile_maybe_c);
                    CHECK_FALSE(const_maybe_cv != const_volatile_maybe_v);
                    CHECK_FALSE(const_maybe_cv != const_volatile_maybe_cv);

                    CHECK_FALSE(volatile_maybe != maybe);
                    CHECK_FALSE(volatile_maybe != maybe_c);
                    CHECK_FALSE(volatile_maybe != maybe_v);
                    CHECK_FALSE(volatile_maybe != maybe_cv);
                    CHECK_FALSE(volatile_maybe != const_maybe);
                    CHECK_FALSE(volatile_maybe != const_maybe_c);
                    CHECK_FALSE(volatile_maybe != const_maybe_v);
                    CHECK_FALSE(volatile_maybe != const_maybe_cv);
                    CHECK_FALSE(volatile_maybe != volatile_maybe);
                    CHECK_FALSE(volatile_maybe != volatile_maybe_c);
                    CHECK_FALSE(volatile_maybe != volatile_maybe_v);
                    CHECK_FALSE(volatile_maybe != volatile_maybe_cv);
                    CHECK_FALSE(volatile_maybe != const_volatile_maybe);
                    CHECK_FALSE(volatile_maybe != const_volatile_maybe_c);
                    CHECK_FALSE(volatile_maybe != const_volatile_maybe_v);
                    CHECK_FALSE(volatile_maybe != const_volatile_maybe_cv);

                    CHECK_FALSE(volatile_maybe_c != maybe);
                    CHECK_FALSE(volatile_maybe_c != maybe_c);
                    CHECK_FALSE(volatile_maybe_c != maybe_v);
                    CHECK_FALSE(volatile_maybe_c != maybe_cv);
                    CHECK_FALSE(volatile_maybe_c != const_maybe);
                    CHECK_FALSE(volatile_maybe_c != const_maybe_c);
                    CHECK_FALSE(volatile_maybe_c != const_maybe_v);
                    CHECK_FALSE(volatile_maybe_c != const_maybe_cv);
                    CHECK_FALSE(volatile_maybe_c != volatile_maybe);
                    CHECK_FALSE(volatile_maybe_c != volatile_maybe_c);
                    CHECK_FALSE(volatile_maybe_c != volatile_maybe_v);
                    CHECK_FALSE(volatile_maybe_c != volatile_maybe_cv);
                    CHECK_FALSE(volatile_maybe_c != const_volatile_maybe);
                    CHECK_FALSE(volatile_maybe_c != const_volatile_maybe_c);
                    CHECK_FALSE(volatile_maybe_c != const_volatile_maybe_v);
                    CHECK_FALSE(volatile_maybe_c != const_volatile_maybe_cv);

                    CHECK_FALSE(volatile_maybe_v != maybe);
                    CHECK_FALSE(volatile_maybe_v != maybe_c);
                    CHECK_FALSE(volatile_maybe_v != maybe_v);
                    CHECK_FALSE(volatile_maybe_v != maybe_cv);
                    CHECK_FALSE(volatile_maybe_v != const_maybe);
                    CHECK_FALSE(volatile_maybe_v != const_maybe_c);
                    CHECK_FALSE(volatile_maybe_v != const_maybe_v);
                    CHECK_FALSE(volatile_maybe_v != const_maybe_cv);
                    CHECK_FALSE(volatile_maybe_v != volatile_maybe);
                    CHECK_FALSE(volatile_maybe_v != volatile_maybe_c);
                    CHECK_FALSE(volatile_maybe_v != volatile_maybe_v);
                    CHECK_FALSE(volatile_maybe_v != volatile_maybe_cv);
                    CHECK_FALSE(volatile_maybe_v != const_volatile_maybe);
                    CHECK_FALSE(volatile_maybe_v != const_volatile_maybe_c);
                    CHECK_FALSE(volatile_maybe_v != const_volatile_maybe_v);
                    CHECK_FALSE(volatile_maybe_v != const_volatile_maybe_cv);

                    CHECK_FALSE(volatile_maybe_cv != maybe);
                    CHECK_FALSE(volatile_maybe_cv != maybe_c);
                    CHECK_FALSE(volatile_maybe_cv != maybe_v);
                    CHECK_FALSE(volatile_maybe_cv != maybe_cv);
                    CHECK_FALSE(volatile_maybe_cv != const_maybe);
                    CHECK_FALSE(volatile_maybe_cv != const_maybe_c);
                    CHECK_FALSE(volatile_maybe_cv != const_maybe_v);
                    CHECK_FALSE(volatile_maybe_cv != const_maybe_cv);
                    CHECK_FALSE(volatile_maybe_cv != volatile_maybe);
                    CHECK_FALSE(volatile_maybe_cv != volatile_maybe_c);
                    CHECK_FALSE(volatile_maybe_cv != volatile_maybe_v);
                    CHECK_FALSE(volatile_maybe_cv != volatile_maybe_cv);
                    CHECK_FALSE(volatile_maybe_cv != const_volatile_maybe);
                    CHECK_FALSE(volatile_maybe_cv != const_volatile_maybe_c);
                    CHECK_FALSE(volatile_maybe_cv != const_volatile_maybe_v);
                    CHECK_FALSE(volatile_maybe_cv != const_volatile_maybe_cv);

                    CHECK_FALSE(const_volatile_maybe != maybe);
                    CHECK_FALSE(const_volatile_maybe != maybe_c);
                    CHECK_FALSE(const_volatile_maybe != maybe_v);
                    CHECK_FALSE(const_volatile_maybe != maybe_cv);
                    CHECK_FALSE(const_volatile_maybe != const_maybe);
                    CHECK_FALSE(const_volatile_maybe != const_maybe_c);
                    CHECK_FALSE(const_volatile_maybe != const_maybe_v);
                    CHECK_FALSE(const_volatile_maybe != const_maybe_cv);
                    CHECK_FALSE(const_volatile_maybe != volatile_maybe);
                    CHECK_FALSE(const_volatile_maybe != volatile_maybe_c);
                    CHECK_FALSE(const_volatile_maybe != volatile_maybe_v);
                    CHECK_FALSE(const_volatile_maybe != volatile_maybe_cv);
                    CHECK_FALSE(const_volatile_maybe != const_volatile_maybe);
                    CHECK_FALSE(const_volatile_maybe != const_volatile_maybe_c);
                    CHECK_FALSE(const_volatile_maybe != const_volatile_maybe_v);
                    CHECK_FALSE(const_volatile_maybe != const_volatile_maybe_cv);

                    CHECK_FALSE(const_volatile_maybe_c != maybe);
                    CHECK_FALSE(const_volatile_maybe_c != maybe_c);
                    CHECK_FALSE(const_volatile_maybe_c != maybe_v);
                    CHECK_FALSE(const_volatile_maybe_c != maybe_cv);
                    CHECK_FALSE(const_volatile_maybe_c != const_maybe);
                    CHECK_FALSE(const_volatile_maybe_c != const_maybe_c);
                    CHECK_FALSE(const_volatile_maybe_c != const_maybe_v);
                    CHECK_FALSE(const_volatile_maybe_c != const_maybe_cv);
                    CHECK_FALSE(const_volatile_maybe_c != volatile_maybe);
                    CHECK_FALSE(const_volatile_maybe_c != volatile_maybe_c);
                    CHECK_FALSE(const_volatile_maybe_c != volatile_maybe_v);
                    CHECK_FALSE(const_volatile_maybe_c != volatile_maybe_cv);
                    CHECK_FALSE(const_volatile_maybe_c != const_volatile_maybe);
                    CHECK_FALSE(const_volatile_maybe_c != const_volatile_maybe_c);
                    CHECK_FALSE(const_volatile_maybe_c != const_volatile_maybe_v);
                    CHECK_FALSE(const_volatile_maybe_c != const_volatile_maybe_cv);

                    CHECK_FALSE(const_volatile_maybe_v != maybe);
                    CHECK_FALSE(const_volatile_maybe_v != maybe_c);
                    CHECK_FALSE(const_volatile_maybe_v != maybe_v);
                    CHECK_FALSE(const_volatile_maybe_v != maybe_cv);
                    CHECK_FALSE(const_volatile_maybe_v != const_maybe);
                    CHECK_FALSE(const_volatile_maybe_v != const_maybe_c);
                    CHECK_FALSE(const_volatile_maybe_v != const_maybe_v);
                    CHECK_FALSE(const_volatile_maybe_v != const_maybe_cv);
                    CHECK_FALSE(const_volatile_maybe_v != volatile_maybe);
                    CHECK_FALSE(const_volatile_maybe_v != volatile_maybe_c);
                    CHECK_FALSE(const_volatile_maybe_v != volatile_maybe_v);
                    CHECK_FALSE(const_volatile_maybe_v != volatile_maybe_cv);
                    CHECK_FALSE(const_volatile_maybe_v != const_volatile_maybe);
                    CHECK_FALSE(const_volatile_maybe_v != const_volatile_maybe_c);
                    CHECK_FALSE(const_volatile_maybe_v != const_volatile_maybe_v);
                    CHECK_FALSE(const_volatile_maybe_v != const_volatile_maybe_cv);

                    CHECK_FALSE(const_volatile_maybe_cv != maybe);
                    CHECK_FALSE(const_volatile_maybe_cv != maybe_c);
                    CHECK_FALSE(const_volatile_maybe_cv != maybe_v);
                    CHECK_FALSE(const_volatile_maybe_cv != maybe_cv);
                    CHECK_FALSE(const_volatile_maybe_cv != const_maybe);
                    CHECK_FALSE(const_volatile_maybe_cv != const_maybe_c);
                    CHECK_FALSE(const_volatile_maybe_cv != const_maybe_v);
                    CHECK_FALSE(const_volatile_maybe_cv != const_maybe_cv);
                    CHECK_FALSE(const_volatile_maybe_cv != volatile_maybe);
                    CHECK_FALSE(const_volatile_maybe_cv != volatile_maybe_c);
                    CHECK_FALSE(const_volatile_maybe_cv != volatile_maybe_v);
                    CHECK_FALSE(const_volatile_maybe_cv != volatile_maybe_cv);
                    CHECK_FALSE(const_volatile_maybe_cv != const_volatile_maybe);
                    CHECK_FALSE(const_volatile_maybe_cv != const_volatile_maybe_c);
                    CHECK_FALSE(const_volatile_maybe_cv != const_volatile_maybe_v);
                    CHECK_FALSE(const_volatile_maybe_cv != const_volatile_maybe_cv);
                }

                TEST_CASE("should return true for two maybes with different number types that do not have an equal value")
                {
                    u8_t random_a = Random<u8_t>(0, std::numeric_limits<s8_t>::max());
                    u8_t random_b;
                    do {
                        random_b = Random<u8_t>(0, std::numeric_limits<s8_t>::max());
                    } while (random_b == random_a);
                    maybe_t<u8_t> maybe_a = random_a;

                    CHECK_TRUE(maybe_a != maybe_t<u16_t>(u16_t(random_b)));
                    CHECK_TRUE(maybe_a != maybe_t<u32_t>(u32_t(random_b)));
                    CHECK_TRUE(maybe_a != maybe_t<u64_t>(u64_t(random_b)));

                    CHECK_TRUE(maybe_a != maybe_t<s8_t>(s8_t(random_b)));
                    CHECK_TRUE(maybe_a != maybe_t<s16_t>(s16_t(random_b)));
                    CHECK_TRUE(maybe_a != maybe_t<s32_t>(s32_t(random_b)));
                    CHECK_TRUE(maybe_a != maybe_t<s64_t>(s64_t(random_b)));

                    CHECK_TRUE(maybe_a != maybe_t<r32_t>(r32_t(random_b)));
                    CHECK_TRUE(maybe_a != maybe_t<r64_t>(r64_t(random_b)));
                }

                TEST_CASE("should return false for two maybes with different number types that have an equal value")
                {
                    u8_t random = Random<u8_t>(0, std::numeric_limits<s8_t>::max());
                    maybe_t<u8_t> maybe = random;

                    CHECK_FALSE(maybe != maybe_t<u16_t>(u16_t(random)));
                    CHECK_FALSE(maybe != maybe_t<u32_t>(u32_t(random)));
                    CHECK_FALSE(maybe != maybe_t<u64_t>(u64_t(random)));

                    CHECK_FALSE(maybe != maybe_t<s8_t>(s8_t(random)));
                    CHECK_FALSE(maybe != maybe_t<s16_t>(s16_t(random)));
                    CHECK_FALSE(maybe != maybe_t<s32_t>(s32_t(random)));
                    CHECK_FALSE(maybe != maybe_t<s64_t>(s64_t(random)));

                    CHECK_FALSE(maybe != maybe_t<r32_t>(r32_t(random)));
                    CHECK_FALSE(maybe != maybe_t<r64_t>(r64_t(random)));
                }
            }
        }

        TEST_SUITE("operators")
        {
            TEST_SUITE("()()")
            {
                TEST_CASE_TEMPLATE("should return a reference to its value", maybe_p, nkr_ALL)
                {
                    using value_t = maybe_p::value_t;

                    value_t random = Random<value_t>();
                    maybe_p maybe = random;
                    CHECK(maybe() == random);
                }

                TEST_CASE_TEMPLATE("should be able to alter non-const values", maybe_p, nkr_NON_CONST)
                {
                    using value_t = maybe_p::value_t;

                    if constexpr (any_non_const_tr<value_t>) {
                        value_t random_a = Random<value_t>();
                        value_t random_b = Random<value_t>();
                        maybe_p maybe = random_a;
                        maybe() = random_b;
                        CHECK(maybe == random_b);
                    }
                }
            }
        }

        TEST_SUITE("none_t interface")
        {
            TEST_SUITE("none_ctor()")
            {
                TEST_CASE_TEMPLATE("should set its value to the default value", maybe_p, nkr_ALL)
                {
                    using value_t = maybe_p::value_t;

                    maybe_p maybe = none_t();
                    CHECK(maybe == static_cast<std::remove_cv_t<value_t>>(0));
                }
            }

            TEST_SUITE("=(none_t)")
            {
                TEST_CASE_TEMPLATE("should set its value to none", maybe_p, nkr_NON_CONST)
                {
                    using value_t = maybe_p::value_t;

                    if constexpr (any_non_const_tr<value_t>) {
                        value_t random = Random<value_t>();
                        maybe_p maybe(random);
                        maybe = none_t();
                        CHECK(maybe == none_t());
                    }
                }

                TEST_CASE_TEMPLATE("should evaluate as false after being set to none", maybe_p, nkr_NON_CONST)
                {
                    using value_t = maybe_p::value_t;

                    if constexpr (any_non_const_tr<value_t>) {
                        value_t random = Random<value_t>();
                        maybe_p maybe(random);
                        maybe = none_t();
                        CHECK_FALSE(maybe);
                    }
                }

                TEST_CASE_TEMPLATE("should return itself", maybe_p, nkr_NON_CONST)
                {
                    using value_t = maybe_p::value_t;

                    if constexpr (any_non_const_tr<value_t>) {
                        value_t random = Random<value_t>();
                        maybe_p maybe(random);
                        CHECK(&(maybe = none_t()) == &maybe);
                    }
                }
            }

            TEST_SUITE("==(none_t)")
            {
                TEST_CASE_TEMPLATE("should return true when default constructed", maybe_p, nkr_ALL)
                {
                    using value_t = maybe_p::value_t;

                    const maybe_p maybe;
                    CHECK(maybe == none_t());
                }

                TEST_CASE_TEMPLATE("should return true if its value is the default", maybe_p, nkr_ALL)
                {
                    using value_t = maybe_p::value_t;

                    const maybe_p maybe(std::remove_cv_t<value_t>(0));
                    CHECK(maybe == none_t());
                }

                TEST_CASE_TEMPLATE("should return false if its value is not the default", maybe_p, nkr_ALL)
                {
                    using value_t = maybe_p::value_t;

                    std::remove_const_t<value_t> random;
                    do {
                        random = Random<std::remove_const_t<value_t>>();
                    } while (random == std::remove_cv_t<value_t>(0));
                    const maybe_p maybe(random);
                    CHECK_FALSE(maybe == none_t());
                }

                TEST_CASE_TEMPLATE("should not change its value", maybe_p, nkr_ALL)
                {
                    using value_t = maybe_p::value_t;

                    value_t random = Random<value_t>();
                    const maybe_p maybe(random);
                    maybe == none_t();
                    CHECK(maybe == random);
                }
            }

            TEST_SUITE("!=(none_t)")
            {
                TEST_CASE_TEMPLATE("should return false when default constructed", maybe_p, nkr_ALL)
                {
                    using value_t = maybe_p::value_t;

                    const maybe_p maybe;
                    CHECK_FALSE(maybe != none_t());
                }

                TEST_CASE_TEMPLATE("should return false if its value is the default", maybe_p, nkr_ALL)
                {
                    using value_t = maybe_p::value_t;

                    const maybe_p maybe(std::remove_cv_t<value_t>(0));
                    CHECK_FALSE(maybe != none_t());
                }

                TEST_CASE_TEMPLATE("should return true if its value is not the default", maybe_p, nkr_ALL)
                {
                    using value_t = maybe_p::value_t;

                    std::remove_const_t<value_t> random;
                    do {
                        random = Random<std::remove_const_t<value_t>>();
                    } while (random == std::remove_cv_t<value_t>(0));
                    const maybe_p maybe(random);
                    CHECK(maybe != none_t());
                }

                TEST_CASE_TEMPLATE("should not change its value", maybe_p, nkr_ALL)
                {
                    using value_t = maybe_p::value_t;

                    value_t random = Random<value_t>();
                    const maybe_p maybe(random);
                    maybe != none_t();
                    CHECK(maybe == random);
                }
            }
        }
    }

}
