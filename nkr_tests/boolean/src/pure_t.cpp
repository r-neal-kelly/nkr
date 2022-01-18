/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/boolean/pure_t.h"
#include "nkr/generic/boolean_tr.h"
#include "nkr/generic/boolean/any_tr.h"
#include "nkr/generic/boolean/pure_tr.h"
#include "nkr/generic/implementing/interface/none/value_tr.h"
#include "nkr/generic/implementing/interface/type_tr.h"
#include "nkr/generic/type_tr.h"
#include "nkr/none/value_t.h"

#include "doctest.h"

namespace nkr {

    static_assert(nkr::generic::boolean_tr<nkr::positive::integer_t>);

    TEST_SUITE("nkr::boolean::pure_t")
    {
        TEST_SUITE("identity")
        {
            static_assert(nkr::boolean::pure_tr<nkr::boolean::pure_t>);
            static_assert(nkr::boolean::pure_tr<const nkr::boolean::pure_t>);
            static_assert(nkr::boolean::pure_tr<volatile nkr::boolean::pure_t>);
            static_assert(nkr::boolean::pure_tr<const volatile nkr::boolean::pure_t>);

            static_assert(sizeof(nkr::boolean::pure_t) == sizeof(nkr::boolean::cpp_t));
        }

        TEST_SUITE("generic")
        {
            // not sure why intellisense thinks some of these are false. they do properly compile.
            // it's something to do with having an == check in the concept requires section?
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

            static_assert(nkr::generic::implementing::interface::none::value_tr<nkr::boolean::pure_t>);

            static_assert(nkr::generic::implementing::interface::type_tr<nkr::boolean::pure_t>);
            static_assert(nkr::generic::implementing::interface::type_tr<nkr::boolean::pure_tg>);

            static_assert(nkr::generic::type_tr<nkr::boolean::pure_t>);
            static_assert(nkr::generic::type_tr<const nkr::boolean::pure_t>);
            static_assert(nkr::generic::type_tr<volatile nkr::boolean::pure_t>);
            static_assert(nkr::generic::type_tr<const volatile nkr::boolean::pure_t>);
        }

        TEST_SUITE("interface")
        {
            TEST_SUITE("nkr::interface::none::value_i")
            {
                static_assert(nkr::interface::none::value_i<nkr::boolean::pure_t>::Value() == false);

                static_assert(nkr::none::value_t<nkr::boolean::pure_t>() == false);
                static_assert(nkr::none::value_t<nkr::boolean::pure_t>() == nkr::boolean::pure_t(false));
                static_assert(nkr::none::value_t<nkr::boolean::pure_t>() == nkr::none::value_t<nkr::boolean::pure_t>());

                static_assert(false == nkr::none::value_t<nkr::boolean::pure_t>());
                static_assert(nkr::boolean::pure_t(false) == nkr::none::value_t<nkr::boolean::pure_t>());
                static_assert(nkr::none::value_t<nkr::boolean::pure_t>() == nkr::none::value_t<nkr::boolean::pure_t>());
            }
        }

        TEST_SUITE("tr")
        {

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
