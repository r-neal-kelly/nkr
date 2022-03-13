/*
    Copyright 2022 r-neal-kelly
*/

#include "nkr/array/cpp_t.h"
#include "nkr/constant/positive/count_t.h"
#include "nkr/generic/array_tr.h"
#include "nkr/generic/implementing/interface/template_tr.h"
#include "nkr/generic/negatable_tr.h"
#include "nkr/generic/positive_tr.h"
#include "nkr/negatable/integer_t.h"
#include "nkr/positive/integer_t.h"
#include "nkr/tr.h"
#include "nkr/tuple/templates_t.h"
#include "nkr/tuple/types_t.h"

#include "doctest.h"

namespace nkr { namespace array {

    TEST_CASE("temp")
    {
        static_assert(nkr::generic::implementing::interface::template_ttr<nkr::array::cpp_t>);
    }

    TEST_CASE("temp")
    {
        using template_i = nkr::interface::template_i<nkr::array::cpp_t>;

        static_assert(nkr::cpp::is_tr<
                      nkr::array::cpp_t<nkr::positive::integer_t, nkr::constant::positive::count_t<1>>,
                      template_i::template template_t<nkr::positive::integer_t, nkr::constant::positive::count_t<1>>
        >);

        static_assert(!nkr::cpp::is_ttr<
                      nkr::array::cpp_t,
                      template_i::template template_t
        >);

        static_assert(nkr::cpp::is_any_ttr<
                      nkr::array::cpp_t,
                      template_i::template template_t,
                      nkr::positive::integer_t, nkr::constant::positive::count_t<1>
        >);

        static_assert(nkr::array::cpp_tr<
                      template_i::template of_tuple_t<nkr::tuple::types_t<nkr::positive::integer_t, nkr::constant::positive::count_t<1>>>
        >);

        static_assert(nkr::array::cpp_tr<
                      template_i::template of_pack_t<nkr::positive::integer_t, nkr::constant::positive::count_t<1>>
        >);

        static_assert(nkr::array::cpp_ttr<nkr::array::cpp_t> && nkr::array::cpp_ttr<template_i::template template_t>);
        static_assert(nkr::array::cpp_ttr<nkr::array::cpp_t> && nkr::array::cpp_ttr<template_i::template of_pack_t>);

        static_assert(nkr::cpp::is_tr<nkr::interface::template_i<nkr::generic::array_ttg>::template of_pack_t<>, nkr::generic::array_tg>);
    }

    TEST_CASE("temp")
    {
        nkr::array::cpp_t<nkr::positive::integer_t, nkr::constant::positive::count_t<1>> array;

        CHECK(sizeof(array) == sizeof(positive::integer_t) * 1);

        static_assert(tr<array::cpp_t<const positive::integer_t, nkr::constant::positive::count_t<1>>,
                      any_tg, tt<array::cpp_ttg>, of_just_const_tg, t<positive::integer_t>>);
    }

    TEST_SUITE("temp")
    {
        static_assert(nkr::array::cpp_ttr<nkr::array::cpp_t>);
        static_assert(nkr::cpp::is_tr<
                      nkr::array::cpp_t<nkr::positive::integer_t, nkr::constant::positive::count_t<1>>,
                      nkr::tuple::templates_t<nkr::array::cpp_t>::head_t<nkr::positive::integer_t, nkr::constant::positive::count_t<1>>
        >);

        static_assert(nkr::array::cpp_ttr<nkr::array::cpp_t>);
        static_assert(nkr::array::cpp_ttr<nkr::tuple::templates_t<nkr::array::cpp_t>::head_t>);

        static_assert(tr<nkr::array::cpp_t<nkr::positive::integer_t, nkr::constant::positive::count_t<1>>,
                      any_tg, tt<nkr::array::cpp_t>, of_any_tg, t<nkr::positive::integer_t>>);

        static_assert(TR<
                      ts<AND_tg,
                      const nkr::array::cpp_t<nkr::positive::integer_t, nkr::constant::positive::count_t<1>>,
                      nkr::array::cpp_t<const nkr::positive::integer_t, nkr::constant::positive::count_t<2>>>,

                      any_tg, tts<AND_tg, nkr::array::cpp_t, nkr::array::cpp_ttg>,
                      of_any_access_const_tg, ts<AND_tg, nkr::positive::integer_t, nkr::positive::integer_tg, nkr::generic::positive_tg>
        >());

        static_assert(TR<
                      ts<AND_tg,
                      const volatile nkr::array::cpp_t<nkr::negatable::integer_t, nkr::constant::positive::count_t<3>>,
                      nkr::array::cpp_t<const volatile nkr::negatable::integer_t, nkr::constant::positive::count_t<4>>>,

                      any_tg, tts<AND_tg, nkr::array::cpp_t, nkr::array::cpp_ttg>,
                      of_any_access_const_tg, ts<AND_tg, nkr::negatable::integer_t, nkr::negatable::integer_tg, nkr::generic::negatable_tg>
        >());

        static_assert(TR<
                      ts<AND_tg,
                      const nkr::array::cpp_t<nkr::positive::integer_t, nkr::constant::positive::count_t<1>>,
                      nkr::array::cpp_t<const nkr::positive::integer_t, nkr::constant::positive::count_t<2>>,
                      const volatile nkr::array::cpp_t<nkr::negatable::integer_t, nkr::constant::positive::count_t<3>>,
                      nkr::array::cpp_t<const volatile nkr::negatable::integer_t, nkr::constant::positive::count_t<4>>>,

                      any_tg, tts<AND_tg, nkr::array::cpp_t, nkr::array::cpp_ttg>,
                      of_any_access_const_tg, ts<OR_tg, nkr::positive::integer_t, nkr::negatable::integer_t>
        >());
    }

}}
