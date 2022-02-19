/*
    Copyright 2022 r-neal-kelly
*/

#include "nkr/z_intrinsics.h"

#include "nkr/z_optional_t.h"

#include "doctest.h"

namespace nkr {

    TEST_SUITE("just_tr")
    {
        TEST_SUITE("types")
        {
            static_assert(just_non_qualified_tr<word_t>);
            static_assert(!just_non_qualified_tr<const word_t>);
            static_assert(!just_non_qualified_tr<volatile word_t>);
            static_assert(!just_non_qualified_tr<const volatile word_t>);

            static_assert(!just_const_tr<word_t>);
            static_assert(just_const_tr<const word_t>);
            static_assert(!just_const_tr<volatile word_t>);
            static_assert(!just_const_tr<const volatile word_t>);

            static_assert(!just_volatile_tr<word_t>);
            static_assert(!just_volatile_tr<const word_t>);
            static_assert(just_volatile_tr<volatile word_t>);
            static_assert(!just_volatile_tr<const volatile word_t>);

            static_assert(!just_const_volatile_tr<word_t>);
            static_assert(!just_const_volatile_tr<const word_t>);
            static_assert(!just_const_volatile_tr<volatile word_t>);
            static_assert(just_const_volatile_tr<const volatile word_t>);
        }
        
        TEST_SUITE("lvalue references")
        {
            static_assert(just_non_qualified_tr<word_t&>);
            static_assert(!just_non_qualified_tr<const word_t&>);
            static_assert(!just_non_qualified_tr<volatile word_t&>);
            static_assert(!just_non_qualified_tr<const volatile word_t&>);

            static_assert(!just_const_tr<word_t&>);
            static_assert(just_const_tr<const word_t&>);
            static_assert(!just_const_tr<volatile word_t&>);
            static_assert(!just_const_tr<const volatile word_t&>);

            static_assert(!just_volatile_tr<word_t&>);
            static_assert(!just_volatile_tr<const word_t&>);
            static_assert(just_volatile_tr<volatile word_t&>);
            static_assert(!just_volatile_tr<const volatile word_t&>);

            static_assert(!just_const_volatile_tr<word_t&>);
            static_assert(!just_const_volatile_tr<const word_t&>);
            static_assert(!just_const_volatile_tr<volatile word_t&>);
            static_assert(just_const_volatile_tr<const volatile word_t&>);
        }

        TEST_SUITE("rvalue references")
        {
            static_assert(just_non_qualified_tr<word_t&&>);
            static_assert(!just_non_qualified_tr<const word_t&&>);
            static_assert(!just_non_qualified_tr<volatile word_t&&>);
            static_assert(!just_non_qualified_tr<const volatile word_t&&>);

            static_assert(!just_const_tr<word_t&&>);
            static_assert(just_const_tr<const word_t&&>);
            static_assert(!just_const_tr<volatile word_t&&>);
            static_assert(!just_const_tr<const volatile word_t&&>);

            static_assert(!just_volatile_tr<word_t&&>);
            static_assert(!just_volatile_tr<const word_t&&>);
            static_assert(just_volatile_tr<volatile word_t&&>);
            static_assert(!just_volatile_tr<const volatile word_t&&>);

            static_assert(!just_const_volatile_tr<word_t&&>);
            static_assert(!just_const_volatile_tr<const word_t&&>);
            static_assert(!just_const_volatile_tr<volatile word_t&&>);
            static_assert(just_const_volatile_tr<const volatile word_t&&>);
        }
    }

}
