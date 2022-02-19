/*
    Copyright 2022 r-neal-kelly
*/

#include "nkr/cpp/concurrency/lock/perpetual/deep_t.h"
#include "nkr/cpp/concurrency/lock/perpetual/unary_t.h"
#include "nkr/cpp/concurrency/locker/scoped_t.h"

#include "doctest.h"

namespace nkr {

    TEST_SUITE("temp")
    {
        using template_i = nkr::interface::template_i<nkr::cpp::concurrency::locker::scoped_t>;

        static_assert(nkr::cpp::concurrency::locker::scoped_tr<typename template_i::template of_pack_t<
                      nkr::cpp::concurrency::lock::perpetual::unary_t,
                      nkr::cpp::concurrency::lock::perpetual::deep_t
                      >>);
    }

}
