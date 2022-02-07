/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/boolean/cpp_t.h"
#include "nkr/boolean/pure_t.h"
#include "nkr/none/value_t.h"

#include "doctest.h"

namespace nkr { namespace boolean {

    TEST_CASE("temp")
    {
        CHECK(boolean::cpp_t(true));
        CHECK(boolean::cpp_t(true) == true);
        CHECK(!boolean::cpp_t(false));
        CHECK(boolean::cpp_t(false) != true);

        CHECK(boolean::pure_t(true));
        CHECK((boolean::pure_t(true) == true));
        CHECK(!boolean::pure_t(false));
        CHECK((boolean::pure_t(false) != true));

        CHECK(boolean::cpp_t(boolean::pure_t(true)));
        CHECK(!boolean::cpp_t(boolean::pure_t(false)));
        CHECK(boolean::pure_t(boolean::cpp_t(true)));
        CHECK(!boolean::pure_t(boolean::cpp_t(false)));

        CHECK((boolean::cpp_t(true) == boolean::pure_t(true)));
        CHECK((boolean::pure_t(true) == boolean::cpp_t(true)));
        CHECK((boolean::cpp_t(true) != boolean::pure_t(false)));
        CHECK((boolean::pure_t(true) != boolean::cpp_t(false)));
    }

    TEST_CASE("temp")
    {
        CHECK(nkr::none::value_t<nkr::boolean::cpp_t>() == false);
    }

}}
