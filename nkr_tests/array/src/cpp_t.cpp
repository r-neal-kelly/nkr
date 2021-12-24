/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/array/cpp_t.h"

#include "nkr/positive/integer_t.h"

#include "doctest.h"

namespace nkr { namespace boolean {

    TEST_CASE("temp")
    {
        array::cpp_t<positive::integer_t, 1> array;

        CHECK(sizeof(array) == sizeof(positive::integer_t) * 1);
    }

}}
