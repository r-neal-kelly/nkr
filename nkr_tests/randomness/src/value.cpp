/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/boolean/cpp_t.h"
#include "nkr/negatable/integer_t.h"
#include "nkr/negatable/real_t.h"
#include "nkr/pointer/cpp_t.h"
#include "nkr/positive/integer_t.h"
#include "nkr/randomness/value.h"

#include "doctest.h"

namespace nkr {

    TEST_SUITE("nkr::randomness::Value")
    {
        enum built_in_enumeration_e
        {
            A, B, C, D, E, F, G, H, I, J, K, L, M,
            N, O, P, Q, R, S, T, U, V, W, X, Y, Z,

            MIN_tg = A,
            MAX_tg = Z,
        };

        enum class built_in_enumeration_class_e
        {
            A, B, C, D, E, F, G, H, I, J, K, L, M,
            N, O, P, Q, R, S, T, U, V, W, X, Y, Z,

            MIN_tg = A,
            MAX_tg = Z,
        };

    #define nkr_BUILT_IN_BOOLEANS   \
        nkr::boolean::cpp_t         \

    #define nkr_BUILT_IN_INTEGERS       \
        nkr::positive::integer_8_t,     \
        nkr::positive::integer_16_t,    \
        nkr::positive::integer_32_t,    \
        nkr::positive::integer_64_t,    \
        nkr::negatable::integer_8_t,    \
        nkr::negatable::integer_16_t,   \
        nkr::negatable::integer_32_t,   \
        nkr::negatable::integer_64_t    \

    #define nkr_BUILT_IN_REALS      \
        nkr::negatable::real_32_t,  \
        nkr::negatable::real_64_t   \

    #define nkr_BUILT_IN_ENUMERATIONS   \
        built_in_enumeration_e,         \
        built_in_enumeration_class_e    \

    #define nkr_BUILT_IN_POINTERS                       \
        nkr::pointer::cpp_t<nkr::none::type_t>,         \
        nkr::pointer::cpp_t<nkr::positive::integer_t>   \

        static constexpr nkr::positive::index_t
            Iteration_Count()
            noexcept
        {
            return 128;
        }

        TEST_SUITE("built-in booleans")
        {
            TEST_CASE_TEMPLATE("should always return true when given 1.0 probability_for_true",
                               boolean_p, nkr_BUILT_IN_BOOLEANS)
            {
                for (nkr::positive::index_t idx = 0, end = Iteration_Count(); idx < end; idx += 1) {
                    boolean_p value = nkr::randomness::Value<boolean_p>(nkr::negatable::real_t(1.0));

                    CHECK(value == true);
                }
            }

            TEST_CASE_TEMPLATE("should always return false when given 0.0 probability_for_true",
                               boolean_p, nkr_BUILT_IN_BOOLEANS)
            {
                for (nkr::positive::index_t idx = 0, end = Iteration_Count(); idx < end; idx += 1) {
                    boolean_p value = nkr::randomness::Value<boolean_p>(nkr::negatable::real_t(0.0));

                    CHECK(value == false);
                }
            }

            TEST_CASE_TEMPLATE("should return either true or false when given any other probability_for_true",
                               boolean_p, nkr_BUILT_IN_BOOLEANS)
            {
                for (nkr::positive::index_t idx = 0, end = Iteration_Count(); idx < end; idx += 1) {
                    boolean_p probability_for_true = nkr::randomness::Value<nkr::negatable::real_t>
                        (nkr::negatable::real_t(0.01), nkr::negatable::real_t(0.99));
                    boolean_p value = nkr::randomness::Value<boolean_p>(probability_for_true);

                    CHECK((value || !value));
                }
            }

            TEST_CASE_TEMPLATE("should eventually return true and false when given the default min and max",
                               boolean_p, nkr_BUILT_IN_BOOLEANS)
            {
                boolean_p got_true = false;
                boolean_p got_false = false;
                for (nkr::positive::index_t idx = 0, end = Iteration_Count(); idx < end; idx += 1) {
                    boolean_p value = nkr::randomness::Value<boolean_p>();
                    if (value) {
                        got_true = true;
                    } else {
                        got_false = true;
                    }
                }

                CHECK(got_true);
                CHECK(got_false);
            }

            TEST_CASE_TEMPLATE("should always return the same value when given a min that equals the max",
                               boolean_p, nkr_BUILT_IN_BOOLEANS)
            {
                for (nkr::positive::index_t idx = 0, end = Iteration_Count(); idx < end; idx += 1) {
                    boolean_p min_max = nkr::randomness::Value<boolean_p>();
                    boolean_p value = nkr::randomness::Value<boolean_p>(min_max, min_max);

                    CHECK(value == min_max);
                }
            }

            TEST_CASE_TEMPLATE("should never return an value out of bounds",
                               boolean_p, nkr_BUILT_IN_BOOLEANS)
            {
                for (nkr::positive::index_t idx = 0, end = Iteration_Count(); idx < end; idx += 1) {
                    boolean_p boundary_a = nkr::randomness::Value<boolean_p>();
                    boolean_p boundary_b = nkr::randomness::Value<boolean_p>();
                    if (boundary_a < boundary_b) {
                        boolean_p value = nkr::randomness::Value<boolean_p>(boundary_a, boundary_b);

                        CHECK(value >= boundary_a);
                        CHECK(value <= boundary_b);
                    } else {
                        boolean_p value = nkr::randomness::Value<boolean_p>(boundary_b, boundary_a);

                        CHECK(value >= boundary_b);
                        CHECK(value <= boundary_a);
                    }
                }
            }
        }

        TEST_SUITE("built-in integers, built-in reals, built-in enumerations, built-in pointers")
        {
            TEST_CASE_TEMPLATE("should almost always return a different value when given the default min and max",
                               value_p, nkr_BUILT_IN_INTEGERS, nkr_BUILT_IN_REALS, nkr_BUILT_IN_ENUMERATIONS, nkr_BUILT_IN_POINTERS)
            {
                constexpr nkr::positive::count_t max_failure_count = 2;

                value_p last_value = value_p();
                for (nkr::positive::index_t idx = 0, end = Iteration_Count(); idx < end; idx += 1) {
                    nkr::positive::count_t failure_count = 0;
                    value_p value = nkr::randomness::Value<value_p>();
                    while (value == last_value) {
                        failure_count += 1;
                        value = nkr::randomness::Value<value_p>();
                    }
                    last_value = value;

                    CHECK(failure_count <= max_failure_count);
                }
            }

            TEST_CASE_TEMPLATE("should always return the same value when given a min that equals the max",
                               value_p, nkr_BUILT_IN_INTEGERS, nkr_BUILT_IN_REALS, nkr_BUILT_IN_ENUMERATIONS, nkr_BUILT_IN_POINTERS)
            {
                for (nkr::positive::index_t idx = 0, end = Iteration_Count(); idx < end; idx += 1) {
                    value_p min_max = nkr::randomness::Value<value_p>();
                    value_p value = nkr::randomness::Value<value_p>(min_max, min_max);

                    CHECK(value == min_max);
                }
            }

            TEST_CASE_TEMPLATE("should never return an value out of bounds",
                               value_p, nkr_BUILT_IN_INTEGERS, nkr_BUILT_IN_REALS, nkr_BUILT_IN_ENUMERATIONS, nkr_BUILT_IN_POINTERS)
            {
                for (nkr::positive::index_t idx = 0, end = Iteration_Count(); idx < end; idx += 1) {
                    value_p boundary_a = nkr::randomness::Value<value_p>();
                    value_p boundary_b = nkr::randomness::Value<value_p>();
                    if (boundary_a < boundary_b) {
                        value_p value = nkr::randomness::Value<value_p>(boundary_a, boundary_b);

                        CHECK(value >= boundary_a);
                        CHECK(value <= boundary_b);
                    } else {
                        value_p value = nkr::randomness::Value<value_p>(boundary_b, boundary_a);

                        CHECK(value >= boundary_b);
                        CHECK(value <= boundary_a);
                    }
                }
            }
        }
    }

}
