/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/bool_t.h"
#include "nkr/intrinsics.h"
#include "nkr/some_t.h"
#include "nkr/utils.h"

#include "doctest.h"

namespace nkr {

    TEST_SUITE("some_t<any_p>")
    {
    #define nkr_ALL_PARAMS(QUALIFIER_p, UNIT_p)     \
        QUALIFIER_p some_t<UNIT_p>,                 \
        QUALIFIER_p some_t<const UNIT_p>,           \
        QUALIFIER_p some_t<volatile UNIT_p>,        \
        QUALIFIER_p some_t<const volatile UNIT_p>

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
        nkr_ALL_PARAMS(QUALIFIER_p, word_t*),       \
                                                    \
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
                TEST_CASE_TEMPLATE("should have a value_t", some_p, nkr_ALL)
                {
                    using value_t = some_p::value_t;

                    static_assert(is_tr<value_t, value_t>);
                }
            }
        }

        TEST_SUITE("objects")
        {
            TEST_SUITE("default_ctor()")
            {
                TEST_CASE_TEMPLATE("should equal the default value", some_p, nkr_ALL)
                {
                    using value_t = some_p::value_t;

                    if constexpr (built_in_tr<value_t>) {
                        value_t value = static_cast<std::remove_cv_t<value_t>>(0);
                        some_p some;
                        CHECK(some == value);
                    } else if constexpr (user_defined_tr<value_t>) {
                        value_t value;
                        some_p some;
                        CHECK(some == value);
                    }
                }

                TEST_CASE_TEMPLATE("may equal none_t()", some_p, nkr_ALL)
                {
                    using value_t = some_p::value_t;

                    some_p some;
                    if (some == none_t()) {
                        CHECK(some == none_t());
                    }
                }
            }

            TEST_SUITE("copy_ctor()")
            {
                TEST_CASE_TEMPLATE("should copy another", some_p, nkr_ALL)
                {
                    using value_t = some_p::value_t;

                    value_t random = Random<value_t>();
                    some_p other = random;
                    some_p some = other;
                    CHECK(some == other);
                    CHECK(other == random);
                }

                TEST_CASE_TEMPLATE("should copy another value", some_p, nkr_ALL)
                {
                    using value_t = some_p::value_t;

                    value_t random = Random<value_t>();
                    value_t other = random;
                    some_p some = other;
                    CHECK(some == other);
                    CHECK(other == random);
                }
            }

            TEST_SUITE("move_ctor()")
            {
                TEST_CASE_TEMPLATE("should move another, setting it to none_t()", some_p, nkr_ALL)
                {
                    using value_t = some_p::value_t;

                    if constexpr (any_non_const_tr<value_t>) {
                        value_t random = Random<value_t>();
                        std::remove_const_t<some_p> other = random;
                        some_p some = nkr::Move(other);
                        CHECK(some == random);
                        CHECK(other == none_t());
                    }
                }

                TEST_CASE_TEMPLATE("should move another value, setting it to none_t()", some_p, nkr_ALL)
                {
                    using value_t = some_p::value_t;

                    value_t random = Random<value_t>();
                    std::remove_const_t<value_t> other = random;
                    some_p some = nkr::Move(other);
                    CHECK(some == random);
                    CHECK(other == none_t());
                }
            }

            TEST_SUITE("copy_assignment_ctor()")
            {
                TEST_CASE_TEMPLATE("should copy another", some_p, nkr_NON_CONST)
                {
                    using value_t = some_p::value_t;

                    if constexpr (any_non_const_tr<value_t>) {
                        value_t random = Random<value_t>();
                        std::add_const_t<some_p> other = random;
                        some_p some;
                        some = other;
                        CHECK(some == other);
                        CHECK(other == random);
                    }
                }

                TEST_CASE_TEMPLATE("should copy another value", some_p, nkr_NON_CONST)
                {
                    using value_t = some_p::value_t;

                    if constexpr (any_non_const_tr<value_t>) {
                        value_t random = Random<value_t>();
                        std::add_const_t<value_t> other = random;
                        some_p some;
                        some = other;
                        CHECK(some == other);
                        CHECK(other == random);
                    }
                }
            }

            TEST_SUITE("move_assignment_ctor()")
            {
                TEST_CASE_TEMPLATE("should move another, setting it to none_t()", some_p, nkr_NON_CONST)
                {
                    using value_t = some_p::value_t;

                    if constexpr (any_non_const_tr<value_t>) {
                        value_t random = Random<value_t>();
                        some_p other = random;
                        some_p some;
                        some = nkr::Move(other);
                        CHECK(some == random);
                        CHECK(other == none_t());
                    }
                }

                TEST_CASE_TEMPLATE("should move another value, setting it to none_t()", some_p, nkr_NON_CONST)
                {
                    using value_t = some_p::value_t;

                    if constexpr (any_non_const_tr<value_t>) {
                        value_t random = Random<value_t>();
                        value_t other = random;
                        some_p some;
                        some = nkr::Move(other);
                        CHECK(some == random);
                        CHECK(other == none_t());
                    }
                }
            }

            TEST_SUITE("dtor()")
            {
                TEST_CASE_TEMPLATE("may set the value to none_t()", some_p, nkr_ALL)
                {
                    using value_t = some_p::value_t;

                    value_t random = Random<value_t>();
                    some_p some = random;
                    some.~some_p();
                    if (some == none_t()) {
                        CHECK(some == none_t());
                    }
                }
            }
        }
    }

}
