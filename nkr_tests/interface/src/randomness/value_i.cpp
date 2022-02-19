/*
    Copyright 2022 r-neal-kelly
*/

#include "nkr/boolean/cpp_t.h"
#include "nkr/enumeration/cpp_t.h"
#include "nkr/interface/randomness/value_i.h"
#include "nkr/negatable/integer_t.h"
#include "nkr/negatable/real_t.h"
#include "nkr/pointer/cpp_t.h"
#include "nkr/positive/integer_t.h"
#include "nkr/randomness/value.h" // temp

#include "doctest.h"

namespace nkr {

    TEST_CASE("built_in boolean")
    {
        using interface_t = nkr::interface::randomness::value_i<nkr::boolean::cpp_t>;

        for (nkr::positive::index_t idx = 0, end = 24; idx < end; idx += 1) {
            //printf("%zu: %i\n", idx, interface_t::Value<>(0.1));
            printf("%zu: %i\n", idx, nkr::randomness::Value<nkr::boolean::cpp_t>(nkr::negatable::real_t(0.1)));
        }
    }

    TEST_CASE("built_in enum")
    {
        enum test_e :
            nkr::positive::integer_8_t
        {
            A = 1,
            B,
            C,
            D,

            MIN_tg = A,
            MAX_tg = D,
        };

        using interface_t = nkr::interface::randomness::value_i<test_e>;

        for (nkr::positive::index_t idx = 0, end = 24; idx < end; idx += 1) {
            //printf("%zu: %i\n", idx, interface_t::Value<>(B, C);
            printf("%zu: %i\n", idx, nkr::randomness::Value<test_e>(B, C));
        }
    }

    TEST_CASE("built_in enum class")
    {
        enum class test_e :
            nkr::positive::integer_8_t
        {
            A = 1,
            B,
            C,
            D,

            MIN_tg = A,
            MAX_tg = D,
        };

        using interface_t = nkr::interface::randomness::value_i<test_e>;

        for (nkr::positive::index_t idx = 0, end = 24; idx < end; idx += 1) {
            //printf("%zu: %i\n", idx, interface_t::Value<>(test_e::C, test_e::D));
            printf("%zu: %i\n", idx, nkr::randomness::Value<test_e>(test_e::C, test_e::D));
        }
    }

    TEST_CASE("built_in integer")
    {
        using interface_t = nkr::interface::randomness::value_i<nkr::positive::integer_t>;

        for (nkr::positive::index_t idx = 0, end = 24; idx < end; idx += 1) {
            //printf("%zu: %i\n", idx, interface_t::Value<>(0, 16));
            printf("%zu: %zu\n", idx, nkr::randomness::Value<nkr::positive::integer_t>(0, 16));
        }
    }

    TEST_CASE("built_in real")
    {
        using interface_t = nkr::interface::randomness::value_i<nkr::negatable::real_t>;

        for (nkr::positive::index_t idx = 0, end = 24; idx < end; idx += 1) {
            //printf("%zu: %i\n", idx, interface_t::Value<>(nkr::negatable::real_t(0.0), nkr::negatable::real_t(16.0)));
            printf("%zu: %g\n", idx, nkr::randomness::Value<nkr::negatable::real_t>(nkr::negatable::real_t(-16.0), nkr::negatable::real_t(16.0)));
        }
    }

    TEST_CASE("built_in pointer")
    {
        using interface_t = nkr::interface::randomness::value_i<nkr::pointer::cpp_t<nkr::positive::integer_t>>;

        nkr::positive::integer_t integers[16] = { 0 };

        for (nkr::positive::index_t idx = 0, end = 24; idx < end; idx += 1) {
            //printf("%zu: %i\n", idx, interface_t::Value<>(&integers[0], &integers[15]));
            printf("%zu: %p\n", idx, nkr::randomness::Value<nkr::pointer::cpp_t<nkr::positive::integer_t>>(&integers[0], &integers[15]));
        }
    }

}
