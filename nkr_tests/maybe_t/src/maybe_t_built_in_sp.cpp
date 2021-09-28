/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/bool_t.h"
#include "nkr/intrinsics.h"
#include "nkr/maybe_t.h"
#include "nkr/random.h"

#include "doctest.h"

namespace nkr {

    TEST_SUITE("maybe_t<built_in_p>")
    {
    #define nkr_ALL_PARAMS(QUALIFIER_p, UNIT_p)     \
        QUALIFIER_p maybe_t<UNIT_p>,                \
        QUALIFIER_p maybe_t<const UNIT_p>,          \
        QUALIFIER_p maybe_t<volatile UNIT_p>,       \
        QUALIFIER_p maybe_t<const volatile UNIT_p>

    #define nkr_VALUES(QUALIFIER_p)                 \
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

    #define nkr_NON_QUALIFIED   \
        nkr_VALUES(nkr_BLANK)

    #define nkr_NON_CONST       \
        nkr_VALUES(nkr_BLANK),  \
        nkr_VALUES(volatile)

    #define nkr_CONST               \
        nkr_VALUES(const),          \
        nkr_VALUES(const volatile)

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

            TEST_SUITE("std_bool_t")
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
