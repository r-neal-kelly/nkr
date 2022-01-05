/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/cpp.h"

#include "doctest.h"

namespace nkr {

    TEST_SUITE("locks")
    {
        static_assert(cpp::generic::lock_tr<cpp::lock::unary_t>);
        static_assert(cpp::generic::lock_tr<cpp::lock::deep_t>);
        static_assert(cpp::generic::lock_tr<cpp::lock::wide_t>);

        static_assert(cpp::generic::lock_tr<cpp::lock::timed::unary_t>);
        static_assert(cpp::generic::lock_tr<cpp::lock::timed::deep_t>);
        static_assert(cpp::generic::lock_tr<cpp::lock::timed::wide_t>);
    }

    TEST_SUITE("lockers")
    {
        static_assert(cpp::generic::locker_tr<cpp::locker::scoped_t<cpp::lock::unary_t>>);
        static_assert(cpp::generic::locker_tr<cpp::locker::scoped_t<cpp::lock::deep_t>>);
        static_assert(cpp::generic::locker_tr<cpp::locker::scoped_t<cpp::lock::wide_t>>);
        static_assert(cpp::generic::locker_tr<cpp::locker::scoped_t<cpp::lock::timed::unary_t>>);
        static_assert(cpp::generic::locker_tr<cpp::locker::scoped_t<cpp::lock::timed::deep_t>>);
        static_assert(cpp::generic::locker_tr<cpp::locker::scoped_t<cpp::lock::timed::wide_t>>);
        static_assert(cpp::generic::locker_tr<cpp::locker::scoped_t<cpp::lock::unary_t, cpp::lock::deep_t, cpp::lock::wide_t>>);
        static_assert(cpp::generic::locker_tr<cpp::locker::scoped_t<cpp::lock::timed::unary_t, cpp::lock::timed::deep_t, cpp::lock::timed::wide_t>>);

        static_assert(cpp::generic::locker_tr<cpp::locker::exclusive_t<cpp::lock::unary_t>>);
        static_assert(cpp::generic::locker_tr<cpp::locker::exclusive_t<cpp::lock::deep_t>>);
        static_assert(cpp::generic::locker_tr<cpp::locker::exclusive_t<cpp::lock::wide_t>>);
        static_assert(cpp::generic::locker_tr<cpp::locker::exclusive_t<cpp::lock::timed::unary_t>>);
        static_assert(cpp::generic::locker_tr<cpp::locker::exclusive_t<cpp::lock::timed::deep_t>>);
        static_assert(cpp::generic::locker_tr<cpp::locker::exclusive_t<cpp::lock::timed::wide_t>>);

        static_assert(cpp::generic::locker_tr<cpp::locker::inclusive_t<cpp::lock::wide_t>>);
        static_assert(cpp::generic::locker_tr<cpp::locker::inclusive_t<cpp::lock::timed::wide_t>>);
    }

}
