/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/cpp/randomness/distributor/bernoulli_t.h"
#include "nkr/cpp/randomness/distributor/uniform/integer_t.h"
#include "nkr/cpp/randomness/distributor/uniform/real_t.h"

#include "nkr/cpp/generic/randomness/distributor_tr.h"

#include "doctest.h"

namespace nkr {

    TEST_SUITE("nkr::cpp::generic::randomness::distributor_tr")
    {
        static_assert(nkr::cpp::generic::randomness::distributor_tr<nkr::cpp::randomness::distributor::bernoulli_t>);
        static_assert(nkr::cpp::generic::randomness::distributor_ttr<nkr::cpp::randomness::distributor::uniform::integer_t>);
        static_assert(nkr::cpp::generic::randomness::distributor_ttr<nkr::cpp::randomness::distributor::uniform::real_t>);
    }

}
