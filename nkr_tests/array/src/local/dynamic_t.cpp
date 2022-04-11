/*
    Copyright 2022 r-neal-kelly
*/

#include "nkr/array/local/dynamic_t.h"

#include "doctest.h"

namespace nkr {

    TEST_SUITE("nkr::array::local::dynamic_t")
    {
        TEST_CASE("temp")
        {
            nkr::array::local::dynamic_t<int, nkr::constant::positive::count_t<2>> a;
            nkr::array::local::dynamic_t<int, nkr::constant::positive::count_t<2>> b;

            nkr::array::local::dynamic_t<int, nkr::constant::positive::count_t<2>> c{ int(1), int(2) };
            CHECK(c.count == 2);
            CHECK(c.bytes[0] == 1);
            CHECK(c.bytes[4] == 2);

            c = a;
            CHECK(c.count == 0);
        }
    }

}
