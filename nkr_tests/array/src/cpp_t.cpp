/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/array/cpp_t.h"

#include "nkr/positive/integer_t.h"

#include "doctest.h"

namespace nkr { namespace boolean {

    TEST_CASE("temp")
    {
        array::cpp_t<positive::integer_t, positive::count_c<1>> array;

        CHECK(sizeof(array) == sizeof(positive::integer_t) * 1);

        static_assert(tr2<array::cpp_t<const positive::integer_t, positive::count_c<1>>,
                      any_tg, array::cpp_ttg, of_just_const_tg, positive::integer_t>);
    }

}}
