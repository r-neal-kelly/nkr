/*
    Copyright 2021 r-neal-kelly
*/

#include "tr.h"

namespace nkr { namespace traits {

    TEST_SUITE("tr1")
    {
        TEST_SUITE("any_tg")
        {
            TEST_CASE_TEMPLATE("should allow any matching type", type_p, nkr_ANY_NON_QUALIFIED_TYPES)
            {
                static_assert(tr1<type_p,
                              any_tg, type_p>);
                static_assert(tr1<const type_p,
                              any_tg, type_p>);
                static_assert(tr1<volatile type_p,
                              any_tg, type_p>);
                static_assert(tr1<const volatile type_p,
                              any_tg, type_p>);
            }

            TEST_CASE_TEMPLATE("should not allow any non-matching type", type_p, nkr_ANY_NON_QUALIFIED_TYPES)
            {
                static_assert(!tr1<non_match_t,
                              any_tg, type_p>);
                static_assert(!tr1<const non_match_t,
                              any_tg, type_p>);
                static_assert(!tr1<volatile non_match_t,
                              any_tg, type_p>);
                static_assert(!tr1<const volatile non_match_t,
                              any_tg, type_p>);
            }
        }

        TEST_SUITE("any_qualified_tg")
        {
            TEST_CASE_TEMPLATE("should allow any matching qualified type", type_p, nkr_ANY_NON_QUALIFIED_TYPES)
            {
                static_assert(tr1<const type_p,
                              any_qualified_tg, type_p>);
                static_assert(tr1<volatile type_p,
                              any_qualified_tg, type_p>);
                static_assert(tr1<const volatile type_p,
                              any_qualified_tg, type_p>);
            }

            TEST_CASE_TEMPLATE("should not allow any matching non-qualified type", type_p, nkr_ANY_NON_QUALIFIED_TYPES)
            {
                static_assert(!tr1<type_p,
                              any_qualified_tg, type_p>);
            }

            TEST_CASE_TEMPLATE("should not allow any non-matching type", type_p, nkr_ANY_NON_QUALIFIED_TYPES)
            {
                static_assert(!tr1<non_match_t,
                              any_qualified_tg, type_p>);
                static_assert(!tr1<const non_match_t,
                              any_qualified_tg, type_p>);
                static_assert(!tr1<volatile non_match_t,
                              any_qualified_tg, type_p>);
                static_assert(!tr1<const volatile non_match_t,
                              any_qualified_tg, type_p>);
            }
        }

        TEST_SUITE("any_non_qualified_tg")
        {
            TEST_CASE_TEMPLATE("should allow any matching non-qualified type", type_p, nkr_ANY_NON_QUALIFIED_TYPES)
            {
                static_assert(tr1<type_p,
                              any_non_qualified_tg, type_p>);
            }

            TEST_CASE_TEMPLATE("should not allow any matching qualified type", type_p, nkr_ANY_NON_QUALIFIED_TYPES)
            {
                static_assert(!tr1<const type_p,
                              any_non_qualified_tg, type_p>);
                static_assert(!tr1<volatile type_p,
                              any_non_qualified_tg, type_p>);
                static_assert(!tr1<const volatile type_p,
                              any_non_qualified_tg, type_p>);
            }

            TEST_CASE_TEMPLATE("should not allow any non-matching type", type_p, nkr_ANY_NON_QUALIFIED_TYPES)
            {
                static_assert(!tr1<non_match_t,
                              any_non_qualified_tg, type_p>);
                static_assert(!tr1<const non_match_t,
                              any_non_qualified_tg, type_p>);
                static_assert(!tr1<volatile non_match_t,
                              any_non_qualified_tg, type_p>);
                static_assert(!tr1<const volatile non_match_t,
                              any_non_qualified_tg, type_p>);
            }
        }

        TEST_SUITE("any_const_tg")
        {
            TEST_CASE_TEMPLATE("should allow any matching const type", type_p, nkr_ANY_NON_QUALIFIED_TYPES)
            {
                static_assert(tr1<const type_p,
                              any_const_tg, type_p>);
                static_assert(tr1<const volatile type_p,
                              any_const_tg, type_p>);
            }

            TEST_CASE_TEMPLATE("should not allow any matching non-const type", type_p, nkr_ANY_NON_QUALIFIED_TYPES)
            {
                static_assert(!tr1<type_p,
                              any_const_tg, type_p>);
                static_assert(!tr1<volatile type_p,
                              any_const_tg, type_p>);
            }

            TEST_CASE_TEMPLATE("should not allow any non-matching type", type_p, nkr_ANY_NON_QUALIFIED_TYPES)
            {
                static_assert(!tr1<non_match_t,
                              any_const_tg, type_p>);
                static_assert(!tr1<const non_match_t,
                              any_const_tg, type_p>);
                static_assert(!tr1<volatile non_match_t,
                              any_const_tg, type_p>);
                static_assert(!tr1<const volatile non_match_t,
                              any_const_tg, type_p>);
            }
        }

        TEST_SUITE("any_non_const_tg")
        {
            TEST_CASE_TEMPLATE("should allow any matching non-const type", type_p, nkr_ANY_NON_QUALIFIED_TYPES)
            {
                static_assert(tr1<type_p,
                              any_non_const_tg, type_p>);
                static_assert(tr1<volatile type_p,
                              any_non_const_tg, type_p>);
            }

            TEST_CASE_TEMPLATE("should not allow any matching const type", type_p, nkr_ANY_NON_QUALIFIED_TYPES)
            {
                static_assert(!tr1<const type_p,
                              any_non_const_tg, type_p>);
                static_assert(!tr1<const volatile type_p,
                              any_non_const_tg, type_p>);
            }

            TEST_CASE_TEMPLATE("should not allow any non-matching type", type_p, nkr_ANY_NON_QUALIFIED_TYPES)
            {
                static_assert(!tr1<non_match_t,
                              any_non_const_tg, type_p>);
                static_assert(!tr1<const non_match_t,
                              any_non_const_tg, type_p>);
                static_assert(!tr1<volatile non_match_t,
                              any_non_const_tg, type_p>);
                static_assert(!tr1<const volatile non_match_t,
                              any_non_const_tg, type_p>);
            }
        }

        TEST_SUITE("any_volatile_tg")
        {
            TEST_CASE_TEMPLATE("should allow any matching volatile type", type_p, nkr_ANY_NON_QUALIFIED_TYPES)
            {
                static_assert(tr1<volatile type_p,
                              any_volatile_tg, type_p>);
                static_assert(tr1<const volatile type_p,
                              any_volatile_tg, type_p>);
            }

            TEST_CASE_TEMPLATE("should not allow any matching non-volatile type", type_p, nkr_ANY_NON_QUALIFIED_TYPES)
            {
                static_assert(!tr1<type_p,
                              any_volatile_tg, type_p>);
                static_assert(!tr1<const type_p,
                              any_volatile_tg, type_p>);
            }

            TEST_CASE_TEMPLATE("should not allow any non-matching type", type_p, nkr_ANY_NON_QUALIFIED_TYPES)
            {
                static_assert(!tr1<non_match_t,
                              any_volatile_tg, type_p>);
                static_assert(!tr1<const non_match_t,
                              any_volatile_tg, type_p>);
                static_assert(!tr1<volatile non_match_t,
                              any_volatile_tg, type_p>);
                static_assert(!tr1<const volatile non_match_t,
                              any_volatile_tg, type_p>);
            }
        }

        TEST_SUITE("any_non_volatile_tg")
        {
            TEST_CASE_TEMPLATE("should allow any matching non-volatile type", type_p, nkr_ANY_NON_QUALIFIED_TYPES)
            {
                static_assert(tr1<type_p,
                              any_non_volatile_tg, type_p>);
                static_assert(tr1<const type_p,
                              any_non_volatile_tg, type_p>);
            }

            TEST_CASE_TEMPLATE("should not allow any matching volatile type", type_p, nkr_ANY_NON_QUALIFIED_TYPES)
            {
                static_assert(!tr1<volatile type_p,
                              any_non_volatile_tg, type_p>);
                static_assert(!tr1<const volatile type_p,
                              any_non_volatile_tg, type_p>);
            }

            TEST_CASE_TEMPLATE("should not allow any non-matching type", type_p, nkr_ANY_NON_QUALIFIED_TYPES)
            {
                static_assert(!tr1<non_match_t,
                              any_non_volatile_tg, type_p>);
                static_assert(!tr1<const non_match_t,
                              any_non_volatile_tg, type_p>);
                static_assert(!tr1<volatile non_match_t,
                              any_non_volatile_tg, type_p>);
                static_assert(!tr1<const volatile non_match_t,
                              any_non_volatile_tg, type_p>);
            }
        }

        TEST_SUITE("not_any_tg")
        {
            TEST_CASE_TEMPLATE("should not allow any matching type", type_p, nkr_ANY_NON_QUALIFIED_TYPES)
            {
                static_assert(!tr1<type_p,
                              not_any_tg, type_p>);
                static_assert(!tr1<const type_p,
                              not_any_tg, type_p>);
                static_assert(!tr1<volatile type_p,
                              not_any_tg, type_p>);
                static_assert(!tr1<const volatile type_p,
                              not_any_tg, type_p>);
            }

            TEST_CASE_TEMPLATE("should allow any non-matching type", type_p, nkr_ANY_NON_QUALIFIED_TYPES)
            {
                static_assert(tr1<non_match_t,
                              not_any_tg, type_p>);
                static_assert(tr1<const non_match_t,
                              not_any_tg, type_p>);
                static_assert(tr1<volatile non_match_t,
                              not_any_tg, type_p>);
                static_assert(tr1<const volatile non_match_t,
                              not_any_tg, type_p>);
            }
        }

        TEST_SUITE("not_any_qualified_tg")
        {
            TEST_CASE_TEMPLATE("should not allow any matching qualified type", type_p, nkr_ANY_NON_QUALIFIED_TYPES)
            {
                static_assert(!tr1<const type_p,
                              not_any_qualified_tg, type_p>);
                static_assert(!tr1<volatile type_p,
                              not_any_qualified_tg, type_p>);
                static_assert(!tr1<const volatile type_p,
                              not_any_qualified_tg, type_p>);
            }

            TEST_CASE_TEMPLATE("should allow any matching non-qualified type", type_p, nkr_ANY_NON_QUALIFIED_TYPES)
            {
                static_assert(tr1<type_p,
                              not_any_qualified_tg, type_p>);
            }

            TEST_CASE_TEMPLATE("should allow any non-matching type", type_p, nkr_ANY_NON_QUALIFIED_TYPES)
            {
                static_assert(tr1<non_match_t,
                              not_any_qualified_tg, type_p>);
                static_assert(tr1<const non_match_t,
                              not_any_qualified_tg, type_p>);
                static_assert(tr1<volatile non_match_t,
                              not_any_qualified_tg, type_p>);
                static_assert(tr1<const volatile non_match_t,
                              not_any_qualified_tg, type_p>);
            }
        }

        TEST_SUITE("not_any_non_qualified_tg")
        {
            TEST_CASE_TEMPLATE("should not allow any matching non-qualified type", type_p, nkr_ANY_NON_QUALIFIED_TYPES)
            {
                static_assert(!tr1<type_p,
                              not_any_non_qualified_tg, type_p>);
            }

            TEST_CASE_TEMPLATE("should allow any matching qualified type", type_p, nkr_ANY_NON_QUALIFIED_TYPES)
            {
                static_assert(tr1<const type_p,
                              not_any_non_qualified_tg, type_p>);
                static_assert(tr1<volatile type_p,
                              not_any_non_qualified_tg, type_p>);
                static_assert(tr1<const volatile type_p,
                              not_any_non_qualified_tg, type_p>);
            }

            TEST_CASE_TEMPLATE("should allow any non-matching type", type_p, nkr_ANY_NON_QUALIFIED_TYPES)
            {
                static_assert(tr1<non_match_t,
                              not_any_non_qualified_tg, type_p>);
                static_assert(tr1<const non_match_t,
                              not_any_non_qualified_tg, type_p>);
                static_assert(tr1<volatile non_match_t,
                              not_any_non_qualified_tg, type_p>);
                static_assert(tr1<const volatile non_match_t,
                              not_any_non_qualified_tg, type_p>);
            }
        }

        TEST_SUITE("not_any_const_tg")
        {
            TEST_CASE_TEMPLATE("should not allow any matching const type", type_p, nkr_ANY_NON_QUALIFIED_TYPES)
            {
                static_assert(!tr1<const type_p,
                              not_any_const_tg, type_p>);
                static_assert(!tr1<const volatile type_p,
                              not_any_const_tg, type_p>);
            }

            TEST_CASE_TEMPLATE("should allow any matching non-const type", type_p, nkr_ANY_NON_QUALIFIED_TYPES)
            {
                static_assert(tr1<type_p,
                              not_any_const_tg, type_p>);
                static_assert(tr1<volatile type_p,
                              not_any_const_tg, type_p>);
            }

            TEST_CASE_TEMPLATE("should allow any non-matching type", type_p, nkr_ANY_NON_QUALIFIED_TYPES)
            {
                static_assert(tr1<non_match_t,
                              not_any_const_tg, type_p>);
                static_assert(tr1<const non_match_t,
                              not_any_const_tg, type_p>);
                static_assert(tr1<volatile non_match_t,
                              not_any_const_tg, type_p>);
                static_assert(tr1<const volatile non_match_t,
                              not_any_const_tg, type_p>);
            }
        }

        TEST_SUITE("not_any_non_const_tg")
        {
            TEST_CASE_TEMPLATE("should not allow any matching non-const type", type_p, nkr_ANY_NON_QUALIFIED_TYPES)
            {
                static_assert(!tr1<type_p,
                              not_any_non_const_tg, type_p>);
                static_assert(!tr1<volatile type_p,
                              not_any_non_const_tg, type_p>);
            }

            TEST_CASE_TEMPLATE("should allow any matching const type", type_p, nkr_ANY_NON_QUALIFIED_TYPES)
            {
                static_assert(tr1<const type_p,
                              not_any_non_const_tg, type_p>);
                static_assert(tr1<const volatile type_p,
                              not_any_non_const_tg, type_p>);
            }

            TEST_CASE_TEMPLATE("should allow any non-matching type", type_p, nkr_ANY_NON_QUALIFIED_TYPES)
            {
                static_assert(tr1<non_match_t,
                              not_any_non_const_tg, type_p>);
                static_assert(tr1<const non_match_t,
                              not_any_non_const_tg, type_p>);
                static_assert(tr1<volatile non_match_t,
                              not_any_non_const_tg, type_p>);
                static_assert(tr1<const volatile non_match_t,
                              not_any_non_const_tg, type_p>);
            }
        }

        TEST_SUITE("not_any_volatile_tg")
        {
            TEST_CASE_TEMPLATE("should not allow any matching volatile type", type_p, nkr_ANY_NON_QUALIFIED_TYPES)
            {
                static_assert(!tr1<volatile type_p,
                              not_any_volatile_tg, type_p>);
                static_assert(!tr1<const volatile type_p,
                              not_any_volatile_tg, type_p>);
            }

            TEST_CASE_TEMPLATE("should allow any matching non-volatile type", type_p, nkr_ANY_NON_QUALIFIED_TYPES)
            {
                static_assert(tr1<type_p,
                              not_any_volatile_tg, type_p>);
                static_assert(tr1<const type_p,
                              not_any_volatile_tg, type_p>);
            }

            TEST_CASE_TEMPLATE("should allow any non-matching type", type_p, nkr_ANY_NON_QUALIFIED_TYPES)
            {
                static_assert(tr1<non_match_t,
                              not_any_volatile_tg, type_p>);
                static_assert(tr1<const non_match_t,
                              not_any_volatile_tg, type_p>);
                static_assert(tr1<volatile non_match_t,
                              not_any_volatile_tg, type_p>);
                static_assert(tr1<const volatile non_match_t,
                              not_any_volatile_tg, type_p>);
            }
        }

        TEST_SUITE("not_any_non_volatile_tg")
        {
            TEST_CASE_TEMPLATE("should not allow any matching non-volatile type", type_p, nkr_ANY_NON_QUALIFIED_TYPES)
            {
                static_assert(!tr1<type_p,
                              not_any_non_volatile_tg, type_p>);
                static_assert(!tr1<const type_p,
                              not_any_non_volatile_tg, type_p>);
            }

            TEST_CASE_TEMPLATE("should allow any matching volatile type", type_p, nkr_ANY_NON_QUALIFIED_TYPES)
            {
                static_assert(tr1<volatile type_p,
                              not_any_non_volatile_tg, type_p>);
                static_assert(tr1<const volatile type_p,
                              not_any_non_volatile_tg, type_p>);
            }

            TEST_CASE_TEMPLATE("should allow any non-matching type", type_p, nkr_ANY_NON_QUALIFIED_TYPES)
            {
                static_assert(tr1<non_match_t,
                              not_any_non_volatile_tg, type_p>);
                static_assert(tr1<const non_match_t,
                              not_any_non_volatile_tg, type_p>);
                static_assert(tr1<volatile non_match_t,
                              not_any_non_volatile_tg, type_p>);
                static_assert(tr1<const volatile non_match_t,
                              not_any_non_volatile_tg, type_p>);
            }
        }

        TEST_SUITE("just_tg")
        {
            TEST_CASE_TEMPLATE("should just allow a matching type with the matching qualification", type_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                static_assert(tr1<type_p,
                              just_tg, type_p>);
                static_assert(!tr1<const type_p,
                              just_tg, type_p>);
                static_assert(!tr1<volatile type_p,
                              just_tg, type_p>);
                static_assert(!tr1<const volatile type_p,
                              just_tg, type_p>);

                static_assert(!tr1<type_p,
                              just_tg, const type_p>);
                static_assert(tr1<const type_p,
                              just_tg, const type_p>);
                static_assert(!tr1<volatile type_p,
                              just_tg, const type_p>);
                static_assert(!tr1<const volatile type_p,
                              just_tg, const type_p>);

                static_assert(!tr1<type_p,
                              just_tg, volatile type_p>);
                static_assert(!tr1<const type_p,
                              just_tg, volatile type_p>);
                static_assert(tr1<volatile type_p,
                              just_tg, volatile type_p>);
                static_assert(!tr1<const volatile type_p,
                              just_tg, volatile type_p>);

                static_assert(!tr1<type_p,
                              just_tg, const volatile type_p>);
                static_assert(!tr1<const type_p,
                              just_tg, const volatile type_p>);
                static_assert(!tr1<volatile type_p,
                              just_tg, const volatile type_p>);
                static_assert(tr1<const volatile type_p,
                              just_tg, const volatile type_p>);
            }

            TEST_CASE_TEMPLATE("should not allow any non-matching type", type_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                static_assert(!tr1<non_match_t,
                              just_tg, type_p>);
                static_assert(!tr1<const non_match_t,
                              just_tg, type_p>);
                static_assert(!tr1<volatile non_match_t,
                              just_tg, type_p>);
                static_assert(!tr1<const volatile non_match_t,
                              just_tg, type_p>);
            }
        }

        TEST_SUITE("just_non_qualified_tg")
        {
            TEST_CASE_TEMPLATE("should just allow a matching non-qualified type", type_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                static_assert(tr1<type_p,
                              just_non_qualified_tg, type_p>);
            }

            TEST_CASE_TEMPLATE("should not allow any other matching type", type_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                static_assert(!tr1<const type_p,
                              just_non_qualified_tg, type_p>);
                static_assert(!tr1<volatile type_p,
                              just_non_qualified_tg, type_p>);
                static_assert(!tr1<const volatile type_p,
                              just_non_qualified_tg, type_p>);
            }

            TEST_CASE_TEMPLATE("should not allow any non-matching type", type_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                static_assert(!tr1<non_match_t,
                              just_non_qualified_tg, type_p>);
                static_assert(!tr1<const non_match_t,
                              just_non_qualified_tg, type_p>);
                static_assert(!tr1<volatile non_match_t,
                              just_non_qualified_tg, type_p>);
                static_assert(!tr1<const volatile non_match_t,
                              just_non_qualified_tg, type_p>);
            }
        }

        TEST_SUITE("just_const_tg")
        {
            TEST_CASE_TEMPLATE("should just allow a matching const type", type_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                static_assert(tr1<const type_p,
                              just_const_tg, type_p>);
            }

            TEST_CASE_TEMPLATE("should not allow any other matching type", type_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                static_assert(!tr1<type_p,
                              just_const_tg, type_p>);
                static_assert(!tr1<volatile type_p,
                              just_const_tg, type_p>);
                static_assert(!tr1<const volatile type_p,
                              just_const_tg, type_p>);
            }

            TEST_CASE_TEMPLATE("should not allow any non-matching type", type_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                static_assert(!tr1<non_match_t,
                              just_const_tg, type_p>);
                static_assert(!tr1<const non_match_t,
                              just_const_tg, type_p>);
                static_assert(!tr1<volatile non_match_t,
                              just_const_tg, type_p>);
                static_assert(!tr1<const volatile non_match_t,
                              just_const_tg, type_p>);
            }
        }

        TEST_SUITE("just_volatile_tg")
        {
            TEST_CASE_TEMPLATE("should just allow a matching volatile type", type_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                static_assert(tr1<volatile type_p,
                              just_volatile_tg, type_p>);
            }

            TEST_CASE_TEMPLATE("should not allow any other matching type", type_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                static_assert(!tr1<type_p,
                              just_volatile_tg, type_p>);
                static_assert(!tr1<const type_p,
                              just_volatile_tg, type_p>);
                static_assert(!tr1<const volatile type_p,
                              just_volatile_tg, type_p>);
            }

            TEST_CASE_TEMPLATE("should not allow any non-matching type", type_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                static_assert(!tr1<non_match_t,
                              just_volatile_tg, type_p>);
                static_assert(!tr1<const non_match_t,
                              just_volatile_tg, type_p>);
                static_assert(!tr1<volatile non_match_t,
                              just_volatile_tg, type_p>);
                static_assert(!tr1<const volatile non_match_t,
                              just_volatile_tg, type_p>);
            }
        }

        TEST_SUITE("just_const_volatile_tg")
        {
            TEST_CASE_TEMPLATE("should just allow a matching const volatile type", type_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                static_assert(tr1<const volatile type_p,
                              just_const_volatile_tg, type_p>);
            }

            TEST_CASE_TEMPLATE("should not allow any other matching type", type_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                static_assert(!tr1<type_p,
                              just_const_volatile_tg, type_p>);
                static_assert(!tr1<const type_p,
                              just_const_volatile_tg, type_p>);
                static_assert(!tr1<volatile type_p,
                              just_const_volatile_tg, type_p>);
            }

            TEST_CASE_TEMPLATE("should not allow any non-matching type", type_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                static_assert(!tr1<non_match_t,
                              just_const_volatile_tg, type_p>);
                static_assert(!tr1<const non_match_t,
                              just_const_volatile_tg, type_p>);
                static_assert(!tr1<volatile non_match_t,
                              just_const_volatile_tg, type_p>);
                static_assert(!tr1<const volatile non_match_t,
                              just_const_volatile_tg, type_p>);
            }
        }

        TEST_SUITE("just_not_tg")
        {
            TEST_CASE_TEMPLATE("should just not allow a matching type with the matching qualification", type_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                static_assert(!tr1<type_p,
                              just_not_tg, type_p>);
                static_assert(tr1<const type_p,
                              just_not_tg, type_p>);
                static_assert(tr1<volatile type_p,
                              just_not_tg, type_p>);
                static_assert(tr1<const volatile type_p,
                              just_not_tg, type_p>);

                static_assert(tr1<type_p,
                              just_not_tg, const type_p>);
                static_assert(!tr1<const type_p,
                              just_not_tg, const type_p>);
                static_assert(tr1<volatile type_p,
                              just_not_tg, const type_p>);
                static_assert(tr1<const volatile type_p,
                              just_not_tg, const type_p>);

                static_assert(tr1<type_p,
                              just_not_tg, volatile type_p>);
                static_assert(tr1<const type_p,
                              just_not_tg, volatile type_p>);
                static_assert(!tr1<volatile type_p,
                              just_not_tg, volatile type_p>);
                static_assert(tr1<const volatile type_p,
                              just_not_tg, volatile type_p>);

                static_assert(tr1<type_p,
                              just_not_tg, const volatile type_p>);
                static_assert(tr1<const type_p,
                              just_not_tg, const volatile type_p>);
                static_assert(tr1<volatile type_p,
                              just_not_tg, const volatile type_p>);
                static_assert(!tr1<const volatile type_p,
                              just_not_tg, const volatile type_p>);
            }

            TEST_CASE_TEMPLATE("should allow any non-matching type", type_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                static_assert(tr1<non_match_t,
                              just_not_tg, type_p>);
                static_assert(tr1<const non_match_t,
                              just_not_tg, type_p>);
                static_assert(tr1<volatile non_match_t,
                              just_not_tg, type_p>);
                static_assert(tr1<const volatile non_match_t,
                              just_not_tg, type_p>);
            }
        }

        TEST_SUITE("just_not_non_qualified_tg")
        {
            TEST_CASE_TEMPLATE("should just not allow a matching non-qualified type", type_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                static_assert(!tr1<type_p,
                              just_not_non_qualified_tg, type_p>);
            }

            TEST_CASE_TEMPLATE("should allow any other matching type", type_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                static_assert(tr1<const type_p,
                              just_not_non_qualified_tg, type_p>);
                static_assert(tr1<volatile type_p,
                              just_not_non_qualified_tg, type_p>);
                static_assert(tr1<const volatile type_p,
                              just_not_non_qualified_tg, type_p>);
            }

            TEST_CASE_TEMPLATE("should allow any non-matching type", type_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                static_assert(tr1<non_match_t,
                              just_not_non_qualified_tg, type_p>);
                static_assert(tr1<const non_match_t,
                              just_not_non_qualified_tg, type_p>);
                static_assert(tr1<volatile non_match_t,
                              just_not_non_qualified_tg, type_p>);
                static_assert(tr1<const volatile non_match_t,
                              just_not_non_qualified_tg, type_p>);
            }
        }

        TEST_SUITE("just_not_const_tg")
        {
            TEST_CASE_TEMPLATE("should just not allow a matching const type", type_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                static_assert(!tr1<const type_p,
                              just_not_const_tg, type_p>);
            }

            TEST_CASE_TEMPLATE("should allow any other matching type", type_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                static_assert(tr1<type_p,
                              just_not_const_tg, type_p>);
                static_assert(tr1<volatile type_p,
                              just_not_const_tg, type_p>);
                static_assert(tr1<const volatile type_p,
                              just_not_const_tg, type_p>);
            }

            TEST_CASE_TEMPLATE("should allow any non-matching type", type_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                static_assert(tr1<non_match_t,
                              just_not_const_tg, type_p>);
                static_assert(tr1<const non_match_t,
                              just_not_const_tg, type_p>);
                static_assert(tr1<volatile non_match_t,
                              just_not_const_tg, type_p>);
                static_assert(tr1<const volatile non_match_t,
                              just_not_const_tg, type_p>);
            }
        }

        TEST_SUITE("just_not_volatile_tg")
        {
            TEST_CASE_TEMPLATE("should just not allow a matching volatile type", type_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                static_assert(!tr1<volatile type_p,
                              just_not_volatile_tg, type_p>);
            }

            TEST_CASE_TEMPLATE("should allow any other matching type", type_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                static_assert(tr1<type_p,
                              just_not_volatile_tg, type_p>);
                static_assert(tr1<const type_p,
                              just_not_volatile_tg, type_p>);
                static_assert(tr1<const volatile type_p,
                              just_not_volatile_tg, type_p>);
            }

            TEST_CASE_TEMPLATE("should allow any non-matching type", type_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                static_assert(tr1<non_match_t,
                              just_not_volatile_tg, type_p>);
                static_assert(tr1<const non_match_t,
                              just_not_volatile_tg, type_p>);
                static_assert(tr1<volatile non_match_t,
                              just_not_volatile_tg, type_p>);
                static_assert(tr1<const volatile non_match_t,
                              just_not_volatile_tg, type_p>);
            }
        }

        TEST_SUITE("just_not_const_volatile_tg")
        {
            TEST_CASE_TEMPLATE("should just not allow a matching const volatile type", type_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                static_assert(!tr1<const volatile type_p,
                              just_not_const_volatile_tg, type_p>);
            }

            TEST_CASE_TEMPLATE("should allow any other matching type", type_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                static_assert(tr1<type_p,
                              just_not_const_volatile_tg, type_p>);
                static_assert(tr1<const type_p,
                              just_not_const_volatile_tg, type_p>);
                static_assert(tr1<volatile type_p,
                              just_not_const_volatile_tg, type_p>);
            }

            TEST_CASE_TEMPLATE("should allow any non-matching type", type_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                static_assert(tr1<non_match_t,
                              just_not_const_volatile_tg, type_p>);
                static_assert(tr1<const non_match_t,
                              just_not_const_volatile_tg, type_p>);
                static_assert(tr1<volatile non_match_t,
                              just_not_const_volatile_tg, type_p>);
                static_assert(tr1<const volatile non_match_t,
                              just_not_const_volatile_tg, type_p>);
            }
        }
    }

}}
