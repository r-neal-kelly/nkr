/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/intrinsics.h"

#include "nkr/cpp/randomness/generator/hardware_t.h"
#include "nkr/cpp/randomness/generator/software/mersenne_twister_t.h"
#include "nkr/cpp/randomness/generator/software/mersenne_twister_19937_32_t.h"
#include "nkr/cpp/randomness/generator/software/mersenne_twister_19937_64_t.h"

#include "nkr/cpp/generic/randomness/generator_tr.h"

#include "doctest.h"

namespace nkr {

    TEST_SUITE("nkr::cpp::generic::randomness::generator_tr")
    {
        static_assert(nkr::cpp::generic::randomness::generator_tr<nkr::cpp::randomness::generator::hardware_t>);
        static_assert(nkr::cpp::generic::randomness::generator_ttr<nkr::cpp::randomness::generator::software::mersenne_twister_t>);
        static_assert(nkr::cpp::generic::randomness::generator_tr<nkr::cpp::randomness::generator::software::mersenne_twister_19937_32_t>);
        static_assert(nkr::cpp::generic::randomness::generator_tr<nkr::cpp::randomness::generator::software::mersenne_twister_19937_64_t>);
    }

}
