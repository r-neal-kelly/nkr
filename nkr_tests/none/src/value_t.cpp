/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/positive/integer_t.h"

#include "nkr/none/value_t.h"

#include "doctest.h"

namespace nkr { namespace none {

    TEST_CASE("temp")
    {
        value_t<positive::integer_t> none = value_t<positive::integer_t>();

        CHECK(static_cast<positive::integer_t>(none) == 0);
    }

}}
