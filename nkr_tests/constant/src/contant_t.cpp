/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/built_in/forward.h"
#include "nkr/constant_t.h"

#include "doctest.h"

namespace nkr {

    TEST_SUITE("nkr::constant_t")
    {
        TEST_CASE("temp")
        {
            using false_t = nkr::constant_t<nkr::boolean::cpp_t, false>;
            using true_t = nkr::constant_t<nkr::boolean::cpp_t, true>;

            CHECK(false_t::Value() == false);
            CHECK(true_t::Value() == true);
        }
    }

}
