/*
    Copyright 2022 r-neal-kelly
*/

#include "tr.h"

namespace nkr { namespace traits {

    TEST_SUITE("tr0")
    {
        TEST_SUITE("any_tg")
        {
            TEST_CASE_TEMPLATE("should allow any subject", subject_p, nkr_ANY_NON_QUALIFIED_TYPES)
            {
                static_assert(tr0<subject_p,
                              any_tg>);
                static_assert(tr0<const subject_p,
                              any_tg>);
                static_assert(tr0<volatile subject_p,
                              any_tg>);
                static_assert(tr0<const volatile subject_p,
                              any_tg>);
            }
        }

        TEST_SUITE("any_qualified_tg")
        {
            TEST_CASE_TEMPLATE("should allow any qualified subject", subject_p, nkr_ANY_NON_QUALIFIED_TYPES)
            {
                static_assert(tr0<const subject_p,
                              any_qualified_tg>);
                static_assert(tr0<volatile subject_p,
                              any_qualified_tg>);
                static_assert(tr0<const volatile subject_p,
                              any_qualified_tg>);
            }

            TEST_CASE_TEMPLATE("should not allow any other subject", subject_p, nkr_ANY_NON_QUALIFIED_TYPES)
            {
                static_assert(!tr0<subject_p,
                              any_qualified_tg>);
            }
        }

        TEST_SUITE("any_non_qualified_tg")
        {
            TEST_CASE_TEMPLATE("should allow any non-qualified subject", subject_p, nkr_ANY_NON_QUALIFIED_TYPES)
            {
                static_assert(tr0<subject_p,
                              any_non_qualified_tg>);
            }

            TEST_CASE_TEMPLATE("should not allow any other subject", subject_p, nkr_ANY_NON_QUALIFIED_TYPES)
            {
                static_assert(!tr0<const subject_p,
                              any_non_qualified_tg>);
                static_assert(!tr0<volatile subject_p,
                              any_non_qualified_tg>);
                static_assert(!tr0<const volatile subject_p,
                              any_non_qualified_tg>);
            }
        }

        TEST_SUITE("any_const_tg")
        {
            TEST_CASE_TEMPLATE("should allow any const subject", subject_p, nkr_ANY_NON_QUALIFIED_TYPES)
            {
                static_assert(tr0<const subject_p,
                              any_const_tg>);
                static_assert(tr0<const volatile subject_p,
                              any_const_tg>);
            }

            TEST_CASE_TEMPLATE("should not allow any other subject", subject_p, nkr_ANY_NON_QUALIFIED_TYPES)
            {
                static_assert(!tr0<subject_p,
                              any_const_tg>);
                static_assert(!tr0<volatile subject_p,
                              any_const_tg>);
            }
        }

        TEST_SUITE("any_non_const_tg")
        {
            TEST_CASE_TEMPLATE("should allow any non-const subject", subject_p, nkr_ANY_NON_QUALIFIED_TYPES)
            {
                static_assert(tr0<subject_p,
                              any_non_const_tg>);
                static_assert(tr0<volatile subject_p,
                              any_non_const_tg>);
            }

            TEST_CASE_TEMPLATE("should not allow any other subject", subject_p, nkr_ANY_NON_QUALIFIED_TYPES)
            {
                static_assert(!tr0<const subject_p,
                              any_non_const_tg>);
                static_assert(!tr0<const volatile subject_p,
                              any_non_const_tg>);
            }
        }

        TEST_SUITE("any_volatile_tg")
        {
            TEST_CASE_TEMPLATE("should allow any volatile subject", subject_p, nkr_ANY_NON_QUALIFIED_TYPES)
            {
                static_assert(tr0<volatile subject_p,
                              any_volatile_tg>);
                static_assert(tr0<const volatile subject_p,
                              any_volatile_tg>);
            }

            TEST_CASE_TEMPLATE("should not allow any other subject", subject_p, nkr_ANY_NON_QUALIFIED_TYPES)
            {
                static_assert(!tr0<subject_p,
                              any_volatile_tg>);
                static_assert(!tr0<const subject_p,
                              any_volatile_tg>);
            }
        }

        TEST_SUITE("any_non_volatile_tg")
        {
            TEST_CASE_TEMPLATE("should allow any non-volatile subject", subject_p, nkr_ANY_NON_QUALIFIED_TYPES)
            {
                static_assert(tr0<subject_p,
                              any_non_volatile_tg>);
                static_assert(tr0<const subject_p,
                              any_non_volatile_tg>);
            }

            TEST_CASE_TEMPLATE("should not allow any other subject", subject_p, nkr_ANY_NON_QUALIFIED_TYPES)
            {
                static_assert(!tr0<volatile subject_p,
                              any_non_volatile_tg>);
                static_assert(!tr0<const volatile subject_p,
                              any_non_volatile_tg>);
            }
        }

        TEST_SUITE("not_any_tg")
        {
            TEST_CASE_TEMPLATE("should not allow any subject", subject_p, nkr_ANY_NON_QUALIFIED_TYPES)
            {
                static_assert(!tr0<subject_p,
                              not_any_tg>);
                static_assert(!tr0<const subject_p,
                              not_any_tg>);
                static_assert(!tr0<volatile subject_p,
                              not_any_tg>);
                static_assert(!tr0<const volatile subject_p,
                              not_any_tg>);
            }
        }

        TEST_SUITE("not_any_qualified_tg")
        {
            TEST_CASE_TEMPLATE("should not allow any qualified subject", subject_p, nkr_ANY_NON_QUALIFIED_TYPES)
            {
                static_assert(!tr0<const subject_p,
                              not_any_qualified_tg>);
                static_assert(!tr0<volatile subject_p,
                              not_any_qualified_tg>);
                static_assert(!tr0<const volatile subject_p,
                              not_any_qualified_tg>);
            }

            TEST_CASE_TEMPLATE("should allow any other subject", subject_p, nkr_ANY_NON_QUALIFIED_TYPES)
            {
                static_assert(tr0<subject_p,
                              not_any_qualified_tg>);
            }
        }

        TEST_SUITE("not_any_non_qualified_tg")
        {
            TEST_CASE_TEMPLATE("should not allow any non-qualified subject", subject_p, nkr_ANY_NON_QUALIFIED_TYPES)
            {
                static_assert(!tr0<subject_p,
                              not_any_non_qualified_tg>);
            }

            TEST_CASE_TEMPLATE("should allow any other subject", subject_p, nkr_ANY_NON_QUALIFIED_TYPES)
            {
                static_assert(tr0<const subject_p,
                              not_any_non_qualified_tg>);
                static_assert(tr0<volatile subject_p,
                              not_any_non_qualified_tg>);
                static_assert(tr0<const volatile subject_p,
                              not_any_non_qualified_tg>);
            }
        }

        TEST_SUITE("not_any_const_tg")
        {
            TEST_CASE_TEMPLATE("should not allow any const subject", subject_p, nkr_ANY_NON_QUALIFIED_TYPES)
            {
                static_assert(!tr0<const subject_p,
                              not_any_const_tg>);
                static_assert(!tr0<const volatile subject_p,
                              not_any_const_tg>);
            }

            TEST_CASE_TEMPLATE("should allow any other subject", subject_p, nkr_ANY_NON_QUALIFIED_TYPES)
            {
                static_assert(tr0<subject_p,
                              not_any_const_tg>);
                static_assert(tr0<volatile subject_p,
                              not_any_const_tg>);
            }
        }

        TEST_SUITE("not_any_non_const_tg")
        {
            TEST_CASE_TEMPLATE("should not allow any non-const subject", subject_p, nkr_ANY_NON_QUALIFIED_TYPES)
            {
                static_assert(!tr0<subject_p,
                              not_any_non_const_tg>);
                static_assert(!tr0<volatile subject_p,
                              not_any_non_const_tg>);
            }

            TEST_CASE_TEMPLATE("should allow any other subject", subject_p, nkr_ANY_NON_QUALIFIED_TYPES)
            {
                static_assert(tr0<const subject_p,
                              not_any_non_const_tg>);
                static_assert(tr0<const volatile subject_p,
                              not_any_non_const_tg>);
            }
        }

        TEST_SUITE("not_any_volatile_tg")
        {
            TEST_CASE_TEMPLATE("should not allow any volatile subject", subject_p, nkr_ANY_NON_QUALIFIED_TYPES)
            {
                static_assert(!tr0<volatile subject_p,
                              not_any_volatile_tg>);
                static_assert(!tr0<const volatile subject_p,
                              not_any_volatile_tg>);
            }

            TEST_CASE_TEMPLATE("should allow any other subject", subject_p, nkr_ANY_NON_QUALIFIED_TYPES)
            {
                static_assert(tr0<subject_p,
                              not_any_volatile_tg>);
                static_assert(tr0<const subject_p,
                              not_any_volatile_tg>);
            }
        }

        TEST_SUITE("not_any_non_volatile_tg")
        {
            TEST_CASE_TEMPLATE("should not allow any non-volatile subject", subject_p, nkr_ANY_NON_QUALIFIED_TYPES)
            {
                static_assert(!tr0<subject_p,
                              not_any_non_volatile_tg>);
                static_assert(!tr0<const subject_p,
                              not_any_non_volatile_tg>);
            }

            TEST_CASE_TEMPLATE("should allow any other subject", subject_p, nkr_ANY_NON_QUALIFIED_TYPES)
            {
                static_assert(tr0<volatile subject_p,
                              not_any_non_volatile_tg>);
                static_assert(tr0<const volatile subject_p,
                              not_any_non_volatile_tg>);
            }
        }

        TEST_SUITE("just_tg")
        {
            TEST_CASE_TEMPLATE("should just allow a subject", subject_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                static_assert(tr0<subject_p,
                              just_tg>);
                static_assert(tr0<const subject_p,
                              just_tg>);
                static_assert(tr0<volatile subject_p,
                              just_tg>);
                static_assert(tr0<const volatile subject_p,
                              just_tg>);
            }
        }

        TEST_SUITE("just_non_qualified_tg")
        {
            TEST_CASE_TEMPLATE("should just allow a non-qualified subject", subject_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                static_assert(tr0<subject_p,
                              just_non_qualified_tg>);
            }

            TEST_CASE_TEMPLATE("should not allow any other subject", subject_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                static_assert(!tr0<const subject_p,
                              just_non_qualified_tg>);
                static_assert(!tr0<volatile subject_p,
                              just_non_qualified_tg>);
                static_assert(!tr0<const volatile subject_p,
                              just_non_qualified_tg>);
            }
        }

        TEST_SUITE("just_const_tg")
        {
            TEST_CASE_TEMPLATE("should just allow a const subject", subject_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                static_assert(tr0<const subject_p,
                              just_const_tg>);
            }

            TEST_CASE_TEMPLATE("should not allow any other subject", subject_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                static_assert(!tr0<subject_p,
                              just_const_tg>);
                static_assert(!tr0<volatile subject_p,
                              just_const_tg>);
                static_assert(!tr0<const volatile subject_p,
                              just_const_tg>);
            }
        }

        TEST_SUITE("just_volatile_tg")
        {
            TEST_CASE_TEMPLATE("should just allow a volatile subject", subject_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                static_assert(tr0<volatile subject_p,
                              just_volatile_tg>);
            }

            TEST_CASE_TEMPLATE("should not allow any other subject", subject_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                static_assert(!tr0<subject_p,
                              just_volatile_tg>);
                static_assert(!tr0<const subject_p,
                              just_volatile_tg>);
                static_assert(!tr0<const volatile subject_p,
                              just_volatile_tg>);
            }
        }

        TEST_SUITE("just_const_volatile_tg")
        {
            TEST_CASE_TEMPLATE("should just allow a const volatile subject", subject_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                static_assert(tr0<const volatile subject_p,
                              just_const_volatile_tg>);
            }

            TEST_CASE_TEMPLATE("should not allow any other subject", subject_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                static_assert(!tr0<subject_p,
                              just_const_volatile_tg>);
                static_assert(!tr0<const subject_p,
                              just_const_volatile_tg>);
                static_assert(!tr0<volatile subject_p,
                              just_const_volatile_tg>);
            }
        }

        TEST_SUITE("just_not_tg")
        {
            TEST_CASE_TEMPLATE("should just not allow a subject", subject_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                static_assert(!tr0<subject_p,
                              just_not_tg>);
                static_assert(!tr0<const subject_p,
                              just_not_tg>);
                static_assert(!tr0<volatile subject_p,
                              just_not_tg>);
                static_assert(!tr0<const volatile subject_p,
                              just_not_tg>);
            }
        }

        TEST_SUITE("just_not_non_qualified_tg")
        {
            TEST_CASE_TEMPLATE("should just not allow a non-qualified subject", subject_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                static_assert(!tr0<subject_p,
                              just_not_non_qualified_tg>);
            }

            TEST_CASE_TEMPLATE("should allow any other subject", subject_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                static_assert(tr0<const subject_p,
                              just_not_non_qualified_tg>);
                static_assert(tr0<volatile subject_p,
                              just_not_non_qualified_tg>);
                static_assert(tr0<const volatile subject_p,
                              just_not_non_qualified_tg>);
            }
        }

        TEST_SUITE("just_not_const_tg")
        {
            TEST_CASE_TEMPLATE("should just not allow a const subject", subject_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                static_assert(!tr0<const subject_p,
                              just_not_const_tg>);
            }

            TEST_CASE_TEMPLATE("should allow any other subject", subject_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                static_assert(tr0<subject_p,
                              just_not_const_tg>);
                static_assert(tr0<volatile subject_p,
                              just_not_const_tg>);
                static_assert(tr0<const volatile subject_p,
                              just_not_const_tg>);
            }
        }

        TEST_SUITE("just_not_volatile_tg")
        {
            TEST_CASE_TEMPLATE("should just not allow a volatile subject", subject_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                static_assert(!tr0<volatile subject_p,
                              just_not_volatile_tg>);
            }

            TEST_CASE_TEMPLATE("should allow any other subject", subject_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                static_assert(tr0<subject_p,
                              just_not_volatile_tg>);
                static_assert(tr0<const subject_p,
                              just_not_volatile_tg>);
                static_assert(tr0<const volatile subject_p,
                              just_not_volatile_tg>);
            }
        }

        TEST_SUITE("just_not_const_volatile_tg")
        {
            TEST_CASE_TEMPLATE("should just not allow a const volatile subject", subject_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                static_assert(!tr0<const volatile subject_p,
                              just_not_const_volatile_tg>);
            }

            TEST_CASE_TEMPLATE("should allow any other subject", subject_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                static_assert(tr0<subject_p,
                              just_not_const_volatile_tg>);
                static_assert(tr0<const subject_p,
                              just_not_const_volatile_tg>);
                static_assert(tr0<volatile subject_p,
                              just_not_const_volatile_tg>);
            }
        }
    }

}}
