/*
    Copyright 2022 r-neal-kelly
*/

#include "nkr/cpp/concurrency/locker/exclusive_t.h"
#include "nkr/cpp/concurrency/locker/inclusive_t.h"
#include "nkr/cpp/concurrency/locker/scoped_t.h"

#include "nkr/cpp/generic/concurrency/locker_tr.h"

#include "doctest.h"

namespace nkr {

    TEST_SUITE("nkr::cpp::generic::concurrency::locker_tr")
    {
        static_assert(nkr::cpp::generic::concurrency::locker_ttr<nkr::cpp::concurrency::locker::exclusive_t>);
        static_assert(nkr::cpp::generic::concurrency::locker_ttr<nkr::cpp::concurrency::locker::inclusive_t>);
        static_assert(nkr::cpp::generic::concurrency::locker_ttr<nkr::cpp::concurrency::locker::scoped_t>);
    }

}
