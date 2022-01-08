/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/intrinsics.h"

#include "nkr/random/distributor/uniform_t.h"
#include "nkr/random/generator/hardware/cpp_t.h"
#include "nkr/random/generator/software/cpp/mersenne_twister_19937_64_t.h"

#include "doctest.h"

namespace nkr {

    TEST_SUITE("nkr::random::distributor::uniform_t")
    {
    #define nkr_TYPES(TYPE_QUALIFIER_p)                                                             \
        TYPE_QUALIFIER_p nkr::random::distributor::uniform_t<boolean::cpp_t>,                       \
        TYPE_QUALIFIER_p nkr::random::distributor::uniform_t<positive::integer_t>,                  \
        TYPE_QUALIFIER_p nkr::random::distributor::uniform_t<negatable::integer_t>,                 \
        TYPE_QUALIFIER_p nkr::random::distributor::uniform_t<negatable::real_t>,                    \
        TYPE_QUALIFIER_p nkr::random::distributor::uniform_t<pointer::cpp_t<none::type_t>>,         \
        TYPE_QUALIFIER_p nkr::random::distributor::uniform_t<pointer::cpp_t<positive::integer_t>>   \

    #define nkr_JUST_NON_QUALIFIED  \
        nkr_TYPES(nkr_BLANK)        \

    #define nkr_JUST_CONST  \
        nkr_TYPES(const)    \

    #define nkr_JUST_VOLATILE   \
        nkr_TYPES(volatile)     \

    #define nkr_JUST_CONST_VOLATILE \
        nkr_TYPES(const volatile)   \

    #define nkr_ANY_QUALIFIED   \
        nkr_JUST_CONST,         \
        nkr_JUST_VOLATILE,      \
        nkr_JUST_CONST_VOLATILE \

    #define nkr_ANY_NON_QUALIFIED   \
        nkr_JUST_NON_QUALIFIED      \

    #define nkr_ANY_CONST       \
        nkr_JUST_CONST,         \
        nkr_JUST_CONST_VOLATILE \

    #define nkr_ANY_NON_CONST   \
        nkr_JUST_NON_QUALIFIED, \
        nkr_JUST_VOLATILE       \

    #define nkr_ANY_VOLATILE    \
        nkr_JUST_VOLATILE,      \
        nkr_JUST_CONST_VOLATILE \

    #define nkr_ANY_NON_VOLATILE    \
        nkr_JUST_NON_QUALIFIED,     \
        nkr_JUST_CONST              \

    #define nkr_ALL             \
        nkr_JUST_NON_QUALIFIED, \
        nkr_JUST_CONST,         \
        nkr_JUST_VOLATILE,      \
        nkr_JUST_CONST_VOLATILE \

        TEST_SUITE("static functions")
        {
            TEST_SUITE("Default_Min()")
            {
                TEST_CASE_TEMPLATE("should be <= Default_Max()", uniform_p, nkr_ALL)
                {
                    CHECK(uniform_p::Default_Min() <= uniform_p::Default_Max());
                }
            }

            TEST_SUITE("Default_Max()")
            {
                TEST_CASE_TEMPLATE("should be >= Default_Min()", uniform_p, nkr_ALL)
                {
                    CHECK(uniform_p::Default_Max() >= uniform_p::Default_Min());
                }
            }
        }

        TEST_CASE("temp")
        {
            nkr::random::generator::hardware::cpp_t hardware_generator;
            nkr::random::generator::software::cpp::mersenne_twister_19937_64_t generator(hardware_generator());
            nkr::random::distributor::uniform_t<boolean::cpp_t> distributor(false, true);

            CHECK(distributor.Min() == false);
            CHECK(distributor.Max() == true);

            for (positive::index_t idx = 0, end = 8; idx < end; idx += 1) {
                printf("value: %i\n", distributor.Value(generator));
            }
            printf("\n");

            distributor.Min(false);
            distributor.Max(false);

            for (positive::index_t idx = 0, end = 8; idx < end; idx += 1) {
                printf("value: %i\n", distributor.Value(generator));
            }
            printf("\n");

            distributor.Min(true);
            distributor.Max(true);

            for (positive::index_t idx = 0, end = 8; idx < end; idx += 1) {
                printf("value: %i\n", distributor.Value(generator));
            }
            printf("\n");
        }
    }

}
