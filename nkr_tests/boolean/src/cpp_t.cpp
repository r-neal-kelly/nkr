/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/tr.h"

#include "nkr/boolean/cpp_t.h"
#include "nkr/boolean/fast_t.h"

#include "nkr/trait/boolean_tr.h"
#include "nkr/trait/boolean/impure_tr.h"
#include "nkr/trait/boolean/pure_tr.h"

#include "doctest.h"

namespace nkr { namespace boolean {

    TEST_CASE("temp")
    {
        CHECK(boolean::cpp_t(true));
        CHECK(boolean::cpp_t(true) == true);
        CHECK(!boolean::cpp_t(false));
        CHECK(boolean::cpp_t(false) != true);

        CHECK(boolean::fast_t(true));
        CHECK((boolean::fast_t(true) == true));
        CHECK(!boolean::fast_t(false));
        CHECK((boolean::fast_t(false) != true));

        CHECK(boolean::cpp_t(boolean::fast_t(true)));
        CHECK(!boolean::cpp_t(boolean::fast_t(false)));
        CHECK(boolean::fast_t(boolean::cpp_t(true)));
        CHECK(!boolean::fast_t(boolean::cpp_t(false)));

        CHECK((boolean::cpp_t(true) == boolean::fast_t(true)));
        CHECK((boolean::fast_t(true) == boolean::cpp_t(true)));
        CHECK((boolean::cpp_t(true) != boolean::fast_t(false)));
        CHECK((boolean::fast_t(true) != boolean::cpp_t(false)));
    }

}}
