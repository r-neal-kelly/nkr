/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/intrinsics.h"

#include "doctest.h"

namespace nkr {

    TEST_SUITE("cpp tmpl")
    {
        TEST_SUITE("cpp::is_of_template_tmpl")
        {
            template <typename type_p>
            class a_t
            {
            public:
            };

            template <typename type_p>
            class b_t
            {
            public:
            };

            static_assert(cpp::is_of_template_tmpl<a_t<positive::integer_t>, a_t>::value);
            static_assert(!cpp::is_of_template_tmpl<a_t<positive::integer_t>, b_t>::value);
            static_assert(!cpp::is_of_template_tmpl<b_t<positive::integer_t>, a_t>::value);
            static_assert(cpp::is_of_template_tmpl<b_t<positive::integer_t>, b_t>::value);
        }
    }

    TEST_SUITE("cpp::lock")
    {
        static_assert(cpp::generic::lock_tr<cpp::lock::unary_t>);
        static_assert(cpp::generic::lock_tr<cpp::lock::deep_t>);
        static_assert(cpp::generic::lock_tr<cpp::lock::wide_t>);

        static_assert(cpp::generic::lock_tr<cpp::lock::timed::unary_t>);
        static_assert(cpp::generic::lock_tr<cpp::lock::timed::deep_t>);
        static_assert(cpp::generic::lock_tr<cpp::lock::timed::wide_t>);
    }

    TEST_SUITE("cpp::locker")
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

    TEST_SUITE("cpp::random")
    {
        TEST_SUITE("cpp::random::distributor")
        {
            static_assert(cpp::random::distributor::bernoulli_tr<cpp::random::distributor::bernoulli_t>);
            static_assert(cpp::random::distributor::uniform::integer_tr<cpp::random::distributor::uniform::integer_t<positive::integer_t>>);
            static_assert(cpp::random::distributor::uniform::real_tr<cpp::random::distributor::uniform::real_t<negatable::real_t>>);

            static_assert(cpp::generic::random::distributor_tr<cpp::random::distributor::bernoulli_t>);
            static_assert(cpp::generic::random::distributor_tr<cpp::random::distributor::uniform::integer_t<positive::integer_t>>);
            static_assert(cpp::generic::random::distributor_tr<cpp::random::distributor::uniform::real_t<negatable::real_t>>);
        }

        TEST_SUITE("cpp::random::generator")
        {
            static_assert(cpp::random::generator::hardware_tr<cpp::random::generator::hardware_t>);
            static_assert(cpp::random::generator::mersenne_twister_tr<cpp::random::generator::mersenne_twister_t<positive::integer_t, 3, 1, 1, 3, 0, 3, 0, 3, 0, 3, 0, 3, 0>>);
            static_assert(cpp::random::generator::mersenne_twister_tr<cpp::random::generator::mersenne_twister_19937_32_t>);
            static_assert(cpp::random::generator::mersenne_twister_tr<cpp::random::generator::mersenne_twister_19937_64_t>);

            static_assert(cpp::generic::random::generator_tr<cpp::random::generator::hardware_t>);
            static_assert(cpp::generic::random::generator_tr<cpp::random::generator::mersenne_twister_t<positive::integer_t, 3, 1, 1, 3, 0, 3, 0, 3, 0, 3, 0, 3, 0>>);
            static_assert(cpp::generic::random::generator_tr<cpp::random::generator::mersenne_twister_19937_32_t>);
            static_assert(cpp::generic::random::generator_tr<cpp::random::generator::mersenne_twister_19937_64_t>);
        }
    }

}
