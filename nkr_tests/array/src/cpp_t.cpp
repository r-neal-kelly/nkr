/*
    Copyright 2022 r-neal-kelly
*/

#include "nkr/array/cpp_t.h"
#include "nkr/constant/positive/count_t.h"
#include "nkr/generic/array_tr.h"
#include "nkr/generic/implementing/interface/template_tr.h"
#include "nkr/generic/negatable_tr.h"
#include "nkr/generic/pointer_tr.h"
#include "nkr/generic/positive_tr.h"
#include "nkr/negatable/integer_t.h"
#include "nkr/pointer/cpp_t.h"
#include "nkr/positive/integer_t.h"
#include "nkr/tr.h"
#include "nkr/tuple/templates_t.h"
#include "nkr/tuple/types_t.h"

#include "doctest.h"

#include "nkr/randomness/generator/hardware/default_t.h"

namespace nkr {

    TEST_SUITE("nkr::interface::template_i")
    {
        static_assert(nkr::generic::implementing::interface::template_ttr<nkr::array::cpp_t>);
        using template_template_i = nkr::interface::template_i<nkr::array::cpp_t>;

        static_assert(nkr::cpp::is_tr<
                      template_template_i::default_arguments_t,
                      nkr::tuple::types_t<nkr::positive::integer_t, nkr::constant::positive::count_t<1>>
        >);
        static_assert(nkr::cpp::is_tr<
                      template_template_i::template_t<nkr::positive::integer_t, nkr::constant::positive::count_t<1>>,
                      nkr::array::cpp_t<nkr::positive::integer_t, nkr::constant::positive::count_t<1>>
        >);
        static_assert(nkr::cpp::is_tr<
                      template_template_i::of_t<nkr::positive::integer_t>,
                      nkr::array::cpp_t<nkr::positive::integer_t, nkr::constant::positive::count_t<1>>
        >);
        static_assert(nkr::cpp::is_tr<
                      template_template_i::of_tuple_t<nkr::tuple::types_t<nkr::positive::integer_t, nkr::constant::positive::count_t<1>>>,
                      nkr::array::cpp_t<nkr::positive::integer_t, nkr::constant::positive::count_t<1>>
        >);
        static_assert(nkr::cpp::is_tr<
                      template_template_i::of_pack_t<nkr::positive::integer_t, nkr::constant::positive::count_t<1>>,
                      nkr::array::cpp_t<nkr::positive::integer_t, nkr::constant::positive::count_t<1>>
        >);
        static_assert(nkr::cpp::is_tr<
                      template_template_i::example_t,
                      nkr::array::cpp_t<nkr::positive::integer_t, nkr::constant::positive::count_t<1>>
        >);

        static_assert(nkr::cpp::is_tr<
                      template_template_i::actual_default_arguments_t,
                      nkr::tuple::types_t<nkr::positive::integer_t, nkr::constant::positive::count_t<1>>
        >);
        static_assert(nkr::cpp::is_tr<
                      template_template_i::actual_template_t<nkr::positive::integer_t, nkr::constant::positive::count_t<1>>,
                      nkr::array::cpp_t<nkr::positive::integer_t, nkr::constant::positive::count_t<1>>
        >);
        static_assert(nkr::cpp::is_tr<
                      template_template_i::actual_of_t<nkr::positive::integer_t>,
                      nkr::array::cpp_t<nkr::positive::integer_t, nkr::constant::positive::count_t<1>>
        >);
        static_assert(nkr::cpp::is_tr<
                      template_template_i::actual_of_tuple_t<nkr::tuple::types_t<nkr::positive::integer_t, nkr::constant::positive::count_t<1>>>,
                      nkr::array::cpp_t<nkr::positive::integer_t, nkr::constant::positive::count_t<1>>
        >);
        static_assert(nkr::cpp::is_tr<
                      template_template_i::actual_of_pack_t<nkr::positive::integer_t, nkr::constant::positive::count_t<1>>,
                      nkr::array::cpp_t<nkr::positive::integer_t, nkr::constant::positive::count_t<1>>
        >);
        static_assert(nkr::cpp::is_tr<
                      template_template_i::actual_example_t,
                      nkr::array::cpp_t<nkr::positive::integer_t, nkr::constant::positive::count_t<1>>
        >);

        static_assert(nkr::generic::implementing::interface::template_ttr<nkr::array::cpp_ttg>);
        using template_tag_i = nkr::interface::template_i<nkr::array::cpp_ttg>;

        static_assert(nkr::cpp::is_tr<
                      template_tag_i::default_arguments_t,
                      nkr::tuple::types_t<nkr::positive::integer_t, nkr::constant::positive::count_t<1>>
        >);
        static_assert(nkr::cpp::is_tr<
                      template_tag_i::template_t<nkr::positive::integer_t, nkr::constant::positive::count_t<1>>,
                      nkr::array::cpp_t<nkr::positive::integer_t, nkr::constant::positive::count_t<1>>
        >);
        static_assert(nkr::cpp::is_tr<
                      template_tag_i::of_t<nkr::positive::integer_t>,
                      nkr::array::cpp_t<nkr::positive::integer_t, nkr::constant::positive::count_t<1>>
        >);
        static_assert(nkr::cpp::is_tr<
                      template_tag_i::of_tuple_t<nkr::tuple::types_t<nkr::positive::integer_t, nkr::constant::positive::count_t<1>>>,
                      nkr::array::cpp_t<nkr::positive::integer_t, nkr::constant::positive::count_t<1>>
        >);
        static_assert(nkr::cpp::is_tr<
                      template_tag_i::of_pack_t<nkr::positive::integer_t, nkr::constant::positive::count_t<1>>,
                      nkr::array::cpp_t<nkr::positive::integer_t, nkr::constant::positive::count_t<1>>
        >);
        static_assert(nkr::cpp::is_tr<
                      template_tag_i::example_t,
                      nkr::array::cpp_t<nkr::positive::integer_t, nkr::constant::positive::count_t<1>>
        >);

        static_assert(nkr::cpp::is_tr<
                      template_tag_i::actual_default_arguments_t,
                      nkr::tuple::types_t<>
        >);
        static_assert(nkr::cpp::is_tr<
                      template_tag_i::actual_template_t<nkr::positive::integer_t, nkr::constant::positive::count_t<1>>,
                      nkr::array::cpp_ttg<nkr::positive::integer_t, nkr::constant::positive::count_t<1>>
        >);
        static_assert(nkr::cpp::is_tr<
                      template_tag_i::actual_of_t<nkr::positive::integer_t>,
                      nkr::array::cpp_ttg<nkr::positive::integer_t>
        >);
        static_assert(nkr::cpp::is_tr<
                      template_tag_i::actual_of_tuple_t<nkr::tuple::types_t<nkr::positive::integer_t, nkr::constant::positive::count_t<1>>>,
                      nkr::array::cpp_ttg<nkr::positive::integer_t, nkr::constant::positive::count_t<1>>
        >);
        static_assert(nkr::cpp::is_tr<
                      template_tag_i::actual_of_pack_t<nkr::positive::integer_t, nkr::constant::positive::count_t<1>>,
                      nkr::array::cpp_ttg<nkr::positive::integer_t, nkr::constant::positive::count_t<1>>
        >);
        static_assert(nkr::cpp::is_tr<
                      template_tag_i::actual_example_t,
                      nkr::array::cpp_ttg<>
        >);
    }

}

namespace nkr { namespace array {

    TEST_CASE("temp")
    {
        using type_t = nkr::array::cpp_t<int, nkr::constant::positive::count_t<1>>;
        using tag_t = nkr::array::cpp_tg;

        using type_type_i = nkr::interface::type_i<type_t>;
        using type_tag_i = nkr::interface::type_i<tag_t>;

        static_assert(type_type_i::template Is_Any_General<type_t>() == true);
        static_assert(type_type_i::template Is_Any_General<tag_t>() == true);

        static_assert(type_tag_i::template Is_Any_General<type_t>() == true);
        static_assert(type_tag_i::template Is_Any_General<tag_t>() == true);
    }

    TEST_CASE("temp")
    {
        static_assert(nkr::generic::implementing::interface::template_ttr<nkr::array::cpp_t>);

        // now tt works as a last argument
        static_assert(nkr::TR<
                      t<int[1]>,
                      any_tg, tt<nkr::array::cpp_t>
        >() == true);

        static_assert(nkr::TR<
                      t<int[1]>,
                      any_tg, tt<nkr::array::cpp_ttg>
        >() == true);

        static_assert(nkr::TR<
                      t<int[1]>,
                      any_tg, tt<nkr::generic::array_ttg>
        >() == true);

        static_assert(nkr::TR<
                      t<int*>,
                      any_tg, tt<nkr::array::cpp_t>
        >() == false);

        static_assert(nkr::TR<
                      t<int*>,
                      any_tg, tt<nkr::array::cpp_ttg>
        >() == false);

        static_assert(nkr::TR<
                      t<int*>,
                      any_tg, tt<nkr::generic::array_ttg>
        >() == false);

        // even tts<>
        static_assert(nkr::TR<
                      ts<AND_tg, int[1], int*>,
                      any_tg, tts<OR_tg, nkr::array::cpp_t, nkr::pointer::cpp_t>
        >() == true);

        static_assert(nkr::TR<
                      ts<AND_tg, volatile int[1], int* volatile>,
                      just_tg, volatile tts<OR_tg, nkr::array::cpp_t, nkr::pointer::cpp_t>
        >() == true);

        static_assert(nkr::TR<
                      ts<AND_tg, int[1], int*>,
                      just_tg, volatile tts<OR_tg, nkr::array::cpp_t, nkr::pointer::cpp_t>
        >() == false);

        static_assert(nkr::TR<
                      ts<AND_tg, volatile int[1], int* volatile>,
                      just_tg, volatile ts<OR_tg, nkr::array::cpp_t<int, nkr::constant::positive::count_t<1>>, nkr::pointer::cpp_t<int>>
        >() == true);
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
