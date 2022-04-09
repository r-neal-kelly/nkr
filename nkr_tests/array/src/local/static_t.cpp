/*
    Copyright 2022 r-neal-kelly
*/

#include "nkr/array/local/static_t.h"

#include "doctest.h"

namespace nkr {

    TEST_SUITE("nkr::array::local::static_t")
    {
        TEST_SUITE("empty_sp")
        {
            constexpr nkr::array::local::static_t<int, nkr::constant::positive::count_t<0>> a;
            constexpr nkr::array::local::static_t<int, nkr::constant::positive::count_t<0>> b{};

            static_assert(a.Count() == 0);
            static_assert(a.Capacity() == 0);
            static_assert(b.Count() == 0);
            static_assert(b.Capacity() == 0);
        }

        TEST_CASE("non_const_default_sp")
        {
            nkr::array::local::static_t<int, nkr::constant::positive::count_t<2>> a{ 1, 2 };
            nkr::array::local::static_t<int, nkr::constant::positive::count_t<2>> b{ 3, 4 };

            a = b;
            a = nkr::cpp::Move(b);

            // check if we can move a c array or if we have to do it manually.

            CHECK(a.Units()[0] == b.Units()[0]);
            CHECK(a.Units()[1] == b.Units()[1]);
        }

        TEST_CASE("non_const_non_default_sp")
        {

        }

        TEST_CASE("const_default_sp")
        {
            nkr::array::local::static_t<const int, nkr::constant::positive::count_t<2>> a{ 1, 2 };
            nkr::array::local::static_t<const int, nkr::constant::positive::count_t<2>> b{ 3, 4 };

            CHECK(a.Units()[0] == 1);
            CHECK(a.Units()[1] == 2);
            CHECK(b.Units()[0] == 3);
            CHECK(b.Units()[1] == 4);
        }

        TEST_CASE("const_non_default_sp")
        {

        }
    }

}
