/*
    Copyright 2022 r-neal-kelly
*/

#include "nkr/array/local/static_t.h"

#include "doctest.h"

namespace nkr {

    TEST_SUITE("nkr::array::local::static_t")
    {
        TEST_CASE("temp")
        {
            nkr::array::local::static_t<int, nkr::constant::positive::count_t<2>> a{ 1, 2 };
            nkr::array::local::static_t<int, nkr::constant::positive::count_t<2>> b{ 3, 4 };

            a = b;
            a = nkr::cpp::Move(b);

            CHECK(a.Units()[0] == b.Units()[0]);
            CHECK(a.Units()[1] == b.Units()[1]);
        }
    }

}
