/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/bool_t.h"
#include "nkr/intrinsics.h"
#include "nkr/none_t.h"
#include "nkr/random.h"

#include "doctest.h"

namespace nkr {

    TEST_SUITE("none_t")
    {
    #define nkr_ALL_PARAMS(QUALIFIER_p) \
        QUALIFIER_p none_t,             \
        QUALIFIER_p none_t,             \
        QUALIFIER_p none_t,             \
        QUALIFIER_p none_t

    #define nkr_NON_QUALIFIED       \
        nkr_ALL_PARAMS(nkr_BLANK)

    #define nkr_NON_CONST           \
        nkr_ALL_PARAMS(nkr_BLANK),  \
        nkr_ALL_PARAMS(volatile)

    #define nkr_CONST                   \
        nkr_ALL_PARAMS(const),          \
        nkr_ALL_PARAMS(volatile const)

    #define nkr_ALL     \
        nkr_NON_CONST,  \
        nkr_CONST

        TEST_SUITE("objects")
        {
            TEST_SUITE("default_ctor()")
            {
                TEST_CASE_TEMPLATE("should create a simple none_t", none_p, nkr_ALL)
                {
                    none_p none;
                }
            }

            TEST_SUITE("dtor()")
            {
                TEST_CASE_TEMPLATE("should destroy a simple none_t", none_p, nkr_ALL)
                {
                    none_p none;
                    none.~none_p();
                }
            }
        }
    }

}
