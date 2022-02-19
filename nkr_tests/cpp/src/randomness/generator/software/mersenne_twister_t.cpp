/*
    Copyright 2022 r-neal-kelly
*/

#include "nkr/constant/positive/integer_t.h"
#include "nkr/constant/positive/size_t.h"
#include "nkr/cpp/randomness/generator/software/mersenne_twister_t.h"

#include "doctest.h"

namespace nkr {

    TEST_SUITE("temp")
    {
        using mersenne_twister_a_t = nkr::cpp::randomness::generator::software::mersenne_twister_t<
            nkr::positive::integer_t,

            nkr::constant::positive::size_t<3>,
            nkr::constant::positive::size_t<1>,
            nkr::constant::positive::size_t<1>,
            nkr::constant::positive::size_t<3>,

            nkr::constant::positive::integer_t<0>,
            nkr::constant::positive::size_t<3>,
            nkr::constant::positive::integer_t<0>,
            nkr::constant::positive::size_t<3>,
            nkr::constant::positive::integer_t<0>,
            nkr::constant::positive::size_t<3>,
            nkr::constant::positive::integer_t<0>,
            nkr::constant::positive::size_t<3>,

            nkr::constant::positive::integer_t<0>
        >;

        static_assert(nkr::cpp::randomness::generator::software::mersenne_twister_tr<mersenne_twister_a_t>);

        using template_i = nkr::interface::template_i<nkr::cpp::randomness::generator::software::mersenne_twister_t>;

        static_assert(nkr::cpp::randomness::generator::software::mersenne_twister_tr<template_i::template of_t<int>>);

        static_assert(nkr::cpp::randomness::generator::software::mersenne_twister_ttr<template_i::template template_t>);
        static_assert(nkr::cpp::randomness::generator::software::mersenne_twister_ttr<template_i::template of_pack_t>);

        using mersenne_twister_parameters_t = nkr::tuple::types_t<
            nkr::positive::integer_t,

            nkr::constant::positive::size_t<3>,
            nkr::constant::positive::size_t<1>,
            nkr::constant::positive::size_t<1>,
            nkr::constant::positive::size_t<3>,

            nkr::constant::positive::integer_t<0>,
            nkr::constant::positive::size_t<3>,
            nkr::constant::positive::integer_t<0>,
            nkr::constant::positive::size_t<3>,
            nkr::constant::positive::integer_t<0>,
            nkr::constant::positive::size_t<3>,
            nkr::constant::positive::integer_t<0>,
            nkr::constant::positive::size_t<3>,

            nkr::constant::positive::integer_t<0>
        >;

        static_assert(nkr::cpp::randomness::generator::software::mersenne_twister_tr<template_i::template of_tuple_t<mersenne_twister_parameters_t>>);
    }

}
