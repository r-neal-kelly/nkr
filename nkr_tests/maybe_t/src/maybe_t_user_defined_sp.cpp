/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/bool_t.h"
#include "nkr/intrinsics.h"
#include "nkr/maybe_t.h"
#include "nkr/random.h"
#include "nkr/utils.h"

#include "doctest.h"

namespace nkr {

    TEST_SUITE("maybe_t<user_defined_p>")
    {
    #define nkr_ALL_PARAMS(QUALIFIER_p, UNIT_p)     \
        QUALIFIER_p maybe_t<UNIT_p>,                \
        QUALIFIER_p maybe_t<const UNIT_p>,          \
        QUALIFIER_p maybe_t<volatile UNIT_p>,       \
        QUALIFIER_p maybe_t<const volatile UNIT_p>

    #define nkr_VALUES(QUALIFIER_p)          \
        nkr_ALL_PARAMS(QUALIFIER_p, bool_t)

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

                    value_t value;
                    maybe_p maybe;
                    CHECK(maybe == value);
                }

                TEST_CASE_TEMPLATE("may equal none_t()", maybe_p, nkr_ALL)
                {
                    using value_t = maybe_p::value_t;

                    maybe_p maybe;
                    if (maybe == none_t()) {
                        CHECK(maybe == none_t());
                    }
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

                    value_t random = Random<value_t>();
                    std::add_const_t<maybe_p> other = random;
                    maybe_p maybe;
                    maybe = other;
                    CHECK(maybe == other);
                    CHECK(other == random);
                }

                TEST_CASE_TEMPLATE("should copy another value", maybe_p, nkr_NON_CONST)
                {
                    using value_t = maybe_p::value_t;

                    value_t random = Random<value_t>();
                    std::add_const_t<value_t> other = random;
                    maybe_p maybe;
                    maybe = other;
                    CHECK(maybe == other);
                    CHECK(other == random);
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

                    value_t random = Random<value_t>();
                    std::remove_const_t<value_t> other = random;
                    maybe_p maybe;
                    maybe = nkr::Move(other);
                    CHECK(maybe == random);
                    CHECK(other == none_t());
                }
            }

            TEST_SUITE("dtor()")
            {
                TEST_CASE_TEMPLATE("may set the value to none_t()", maybe_p, nkr_ALL)
                {
                    using value_t = maybe_p::value_t;

                    value_t random = Random<value_t>();
                    maybe_p maybe = random;
                    maybe.~maybe_p();
                    if (maybe == none_t()) {
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

                TEST_CASE_TEMPLATE("should implicitly allow for base_t constructors", maybe_p, nkr_ALL)
                {
                    using value_t = maybe_p::value_t;

                    if constexpr (is_any_tr<value_t, bool_t>) {
                        std_bool_t random = Random<std_bool_t>();
                        maybe_p maybe(random);
                        CHECK(maybe == random);
                    }
                }

                TEST_CASE_TEMPLATE("should implicitly allow for logical operators", maybe_p, nkr_ALL)
                {
                    using value_t = maybe_p::value_t;

                    if constexpr (is_any_tr<value_t, bool_t>) {
                        maybe_p maybe(true);
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

                    if constexpr (is_any_tr<value_t, bool_t>) {
                        value_t random = Random<value_t>();
                        maybe_p maybe(random);
                        CHECK(maybe == random);
                        CHECK_FALSE(maybe != random);
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

                TEST_CASE_TEMPLATE("should be able to alter its value", maybe_p, nkr_NON_CONST)
                {
                    using value_t = maybe_p::value_t;

                    if constexpr (not_any_const_tr<value_t>) {
                        value_t random_a = Random<value_t>();
                        value_t random_b = Random<value_t>();
                        maybe_p maybe = random_a;
                        maybe() = random_b;
                        CHECK(maybe == random_b);
                    }
                }
            }
        }
    }

}
