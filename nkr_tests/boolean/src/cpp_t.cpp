/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/tr.h"

#include "nkr/boolean/cpp_t.h"
#include "nkr/boolean/safe_t.h"

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

        CHECK(boolean::safe_t(true));
        CHECK((boolean::safe_t(true) == true));
        CHECK(!boolean::safe_t(false));
        CHECK((boolean::safe_t(false) != true));

        CHECK(boolean::cpp_t(boolean::safe_t(true)));
        CHECK(!boolean::cpp_t(boolean::safe_t(false)));
        CHECK(boolean::safe_t(boolean::cpp_t(true)));
        CHECK(!boolean::safe_t(boolean::cpp_t(false)));

        CHECK((boolean::cpp_t(true) == boolean::safe_t(true)));
        CHECK((boolean::safe_t(true) == boolean::cpp_t(true)));
        CHECK((boolean::cpp_t(true) != boolean::safe_t(false)));
        CHECK((boolean::safe_t(true) != boolean::cpp_t(false)));
    }

}}
