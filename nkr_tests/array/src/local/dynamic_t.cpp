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
            nkr::array::local::dynamic_t<int, nkr::constant::positive::count_t<2>> d(c);

            CHECK(c.Unit_Count() == 2);
            CHECK(c.Unit(0) == 1);
            CHECK(c.Unit(1) == 2);
            CHECK(c.Pop_Unit() == 2);
            CHECK(c.Unit_Count() == 1);

            CHECK(d.Unit_Count() == 2);
            CHECK(d[0] == 1);
            CHECK(d[1] == 2);

            c = a;
            CHECK(c.Unit_Count() == 0);

            nkr::array::local::dynamic_t<volatile int, nkr::constant::positive::count_t<2>> e{ int(1), int(2) };
            CHECK(e.Unit_Count() == 2);
            CHECK(e[0] == 1);
            CHECK(e[1] == 2);
            CHECK(e.Pop_Unit() == 2);
            CHECK(e.Unit_Count() == 1);
        }
    }

}
