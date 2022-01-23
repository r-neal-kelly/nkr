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

    TEST_SUITE("temp")
    {
        static_assert(nkr::array::cpp_ttr<nkr::array::cpp_t>);
        static_assert(nkr::cpp::is_tr<
                      nkr::array::cpp_t<nkr::positive::integer_t, nkr::positive::count_c<1>>,
                      nkr::tuple::templates_t<nkr::array::cpp_t>::head_t<nkr::positive::integer_t, nkr::positive::count_c<1>>
        >);

        static_assert(nkr::array::cpp_ttr<nkr::array::cpp_t>);
        static_assert(nkr::array::cpp_ttr<nkr::tuple::templates_t<nkr::array::cpp_t>::head_t>);

        static_assert(tr2<nkr::array::cpp_t<nkr::positive::integer_t, nkr::positive::count_c<1>>,
                      any_tg, nkr::tuple::templates_t<nkr::array::cpp_t>::head_t, of_any_tg, nkr::positive::integer_t>);
        static_assert(tr2s_t<any_tg, nkr::tuple::templates_t<nkr::array::cpp_t>, of_any_tg, nkr::positive::integer_t>::OR<
                      nkr::array::cpp_t<nkr::positive::integer_t, nkr::positive::count_c<1>>,
                      nkr::array::cpp_t<nkr::negatable::integer_t, nkr::positive::count_c<2>>
        >());
    }

}}
