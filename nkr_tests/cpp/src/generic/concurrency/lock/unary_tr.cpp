/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/intrinsics.h"

#include "nkr/cpp/concurrency/lock/perpetual/deep_t.h"
#include "nkr/cpp/concurrency/lock/perpetual/unary_t.h"
#include "nkr/cpp/concurrency/lock/perpetual/wide_t.h"
#include "nkr/cpp/concurrency/lock/temporal/deep_t.h"
#include "nkr/cpp/concurrency/lock/temporal/unary_t.h"
#include "nkr/cpp/concurrency/lock/temporal/wide_t.h"

#include "nkr/cpp/generic/concurrency/lock/unary_tr.h"

#include "doctest.h"

namespace nkr {

    TEST_SUITE("nkr::cpp::generic::concurrency::lock::unary_tr")
    {
        static_assert(!nkr::cpp::generic::concurrency::lock::unary_tr<nkr::cpp::concurrency::lock::perpetual::deep_t>);
        static_assert(nkr::cpp::generic::concurrency::lock::unary_tr<nkr::cpp::concurrency::lock::perpetual::unary_t>);
        static_assert(!nkr::cpp::generic::concurrency::lock::unary_tr<nkr::cpp::concurrency::lock::perpetual::wide_t>);
        static_assert(!nkr::cpp::generic::concurrency::lock::unary_tr<nkr::cpp::concurrency::lock::temporal::deep_t>);
        static_assert(nkr::cpp::generic::concurrency::lock::unary_tr<nkr::cpp::concurrency::lock::temporal::unary_t>);
        static_assert(!nkr::cpp::generic::concurrency::lock::unary_tr<nkr::cpp::concurrency::lock::temporal::wide_t>);
    }

}
