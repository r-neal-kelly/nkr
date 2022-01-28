/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/array/cpp_t.h"
#include "nkr/generic/negatable_tr.h"
#include "nkr/generic/positive_tr.h"
#include "nkr/negatable/integer_t.h"
#include "nkr/positive/integer_t.h"
#include "nkr/tr.h"
#include "nkr/tuple/templates_t.h"
#include "nkr/tuple/types_t.h"

#include "doctest.h"

namespace nkr { namespace boolean {

    TEST_CASE("temp")
    {
        using template_i = nkr::interface::template_i<nkr::array::cpp_t>;

        static_assert(nkr::cpp::is_tr<
                      nkr::array::cpp_t<nkr::positive::integer_t, nkr::positive::count_c<1>>,
                      template_i::template template_t<nkr::positive::integer_t, nkr::positive::count_c<1>>
        >);

        static_assert(!nkr::cpp::is_ttr<
                      nkr::array::cpp_t,
                      template_i::template template_t
        >);

        static_assert(nkr::cpp::is_any_ttr<
                      nkr::array::cpp_t,
                      template_i::template template_t,
                      nkr::positive::integer_t, nkr::positive::count_c<1>
        >);

        static_assert(nkr::array::cpp_tr<
                      template_i::template of_tuple_t<nkr::tuple::types_t<nkr::positive::integer_t, nkr::positive::count_c<1>>>
        >);

        static_assert(nkr::array::cpp_tr<
                      template_i::template of_pack_t<nkr::positive::integer_t, nkr::positive::count_c<1>>
        >);

        static_assert(nkr::array::cpp_ttr<nkr::array::cpp_t> && nkr::array::cpp_ttr<template_i::template template_t>);
        static_assert(nkr::array::cpp_ttr<nkr::array::cpp_t> && nkr::array::cpp_ttr<template_i::template of_pack_t>);
    }

    TEST_CASE("temp")
    {
        nkr::array::cpp_t<nkr::positive::integer_t, nkr::positive::count_c<1>> array;

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

        // wow, our new bulk traits tester are extremely powerful! we just need to update all template_i's to have the new aliases defined
        static_assert(tr2s_t<
                      any_tg, nkr::tuple::templates_t<nkr::array::cpp_t, nkr::array::cpp_ttg>,
                      of_any_access_const_tg, nkr::tuple::types_t<nkr::positive::integer_t, nkr::positive::integer_tg, nkr::generic::positive_tg>
        >::Every<
                      const nkr::array::cpp_t<nkr::positive::integer_t, nkr::positive::count_c<1>>,
                      nkr::array::cpp_t<const nkr::positive::integer_t, nkr::positive::count_c<2>>
        >());

        static_assert(tr2s_t<
                      any_tg, nkr::tuple::templates_t<nkr::array::cpp_t, nkr::array::cpp_ttg>,
                      of_any_access_const_tg, nkr::tuple::types_t<nkr::negatable::integer_t, nkr::negatable::integer_tg, nkr::generic::negatable_tg>
        >::Every<
                      const volatile nkr::array::cpp_t<nkr::negatable::integer_t, nkr::positive::count_c<3>>,
                      nkr::array::cpp_t<const volatile nkr::negatable::integer_t, nkr::positive::count_c<4>>
        >());

        static_assert(tr2s_t<
                      any_tg, nkr::tuple::templates_t<nkr::array::cpp_t, nkr::array::cpp_ttg>,
                      of_any_access_const_tg, nkr::tuple::types_t<nkr::positive::integer_t, nkr::negatable::integer_t>
        >::Any<
                      const nkr::array::cpp_t<nkr::positive::integer_t, nkr::positive::count_c<1>>,
                      nkr::array::cpp_t<const nkr::positive::integer_t, nkr::positive::count_c<2>>,

                      const volatile nkr::array::cpp_t<nkr::negatable::integer_t, nkr::positive::count_c<3>>,
                      nkr::array::cpp_t<const volatile nkr::negatable::integer_t, nkr::positive::count_c<4>>
        >());
    }

}}
