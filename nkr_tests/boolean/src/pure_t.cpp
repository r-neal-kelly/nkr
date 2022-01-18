/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/boolean/pure_t.h"
#include "nkr/generic/boolean_tr.h"
#include "nkr/generic/boolean/any_tr.h"
#include "nkr/generic/boolean/pure_tr.h"

#include "doctest.h"

namespace nkr {

    static_assert(nkr::generic::boolean_tr<nkr::positive::integer_t>);

    TEST_SUITE("nkr::boolean::pure_t")
    {
        TEST_SUITE("identity")
        {
            static_assert(sizeof(nkr::boolean::pure_t) == sizeof(nkr::boolean::cpp_t));

            static_assert(nkr::boolean::pure_tr<nkr::boolean::pure_t>);
            static_assert(nkr::boolean::pure_tr<const nkr::boolean::pure_t>);
            static_assert(nkr::boolean::pure_tr<volatile nkr::boolean::pure_t>);
            static_assert(nkr::boolean::pure_tr<const volatile nkr::boolean::pure_t>);
        }

        TEST_SUITE("generics")
        {
            static_assert(nkr::generic::boolean::$any_tr::constructors_i<nkr::boolean::pure_t>);
            static_assert(nkr::generic::boolean::$any_tr::casts_i<nkr::boolean::pure_t>);
            static_assert(nkr::generic::boolean::$any_tr::operators_i<nkr::boolean::pure_t>); // not sure why intellisense thinks this is false

            static_assert(nkr::generic::boolean_tr<nkr::boolean::pure_t>);
            static_assert(nkr::generic::boolean_tr<const nkr::boolean::pure_t>);
            static_assert(nkr::generic::boolean_tr<volatile nkr::boolean::pure_t>);
            static_assert(nkr::generic::boolean_tr<const volatile nkr::boolean::pure_t>);

            static_assert(nkr::generic::boolean::any_tr<nkr::boolean::pure_t>);
            static_assert(nkr::generic::boolean::any_tr<const nkr::boolean::pure_t>);
            static_assert(nkr::generic::boolean::any_tr<volatile nkr::boolean::pure_t>);
            static_assert(nkr::generic::boolean::any_tr<const volatile nkr::boolean::pure_t>);

            static_assert(nkr::generic::boolean::pure_tr<nkr::boolean::pure_t>);
            static_assert(nkr::generic::boolean::pure_tr<const nkr::boolean::pure_t>);
            static_assert(nkr::generic::boolean::pure_tr<volatile nkr::boolean::pure_t>);
            static_assert(nkr::generic::boolean::pure_tr<const volatile nkr::boolean::pure_t>);
        }

        TEST_SUITE("operators")
        {
            TEST_CASE("temp")
            {
                nkr::boolean::pure_t boolean;
                volatile nkr::boolean::cpp_t test = false;
                boolean = nkr::boolean::cpp_t();
                boolean = nkr::cpp::Move(test);

                CHECK((boolean == nkr::cpp::Move(test)));
            }
        }
    }

}
