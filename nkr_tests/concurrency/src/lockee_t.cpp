/*
    Copyright 2022 r-neal-kelly
*/

#include "nkr/concurrency/lockee_t.h"
#include "nkr/randomness/generator/software/default_t.h"

#include "doctest.h"

namespace nkr {

    TEST_SUITE("nkr::interface::template_i")
    {
        static_assert(nkr::generic::implementing::interface::template_ttr<nkr::concurrency::lockee_t>);
        using template_i = nkr::interface::template_i<nkr::concurrency::lockee_t>;

        static_assert(nkr::cpp::is_tr<template_i::template_t<int>, nkr::concurrency::lockee_t<int>>);
        static_assert(nkr::cpp::is_tr<template_i::of_t<int>, nkr::concurrency::lockee_t<int>>);
        static_assert(nkr::cpp::is_tr<template_i::of_tuple_t<nkr::tuple::types_t<int>>, nkr::concurrency::lockee_t<int>>);
        static_assert(nkr::cpp::is_tr<template_i::of_pack_t<int>, nkr::concurrency::lockee_t<int>>);
        static_assert(nkr::cpp::is_tr<template_i::example_t, nkr::concurrency::lockee_t<nkr::positive::integer_t>>);

        static_assert(nkr::cpp::is_tr<template_i::actual_template_t<int>, nkr::concurrency::lockee_t<int>>);
        static_assert(nkr::cpp::is_tr<template_i::actual_of_t<int>, nkr::concurrency::lockee_t<int>>);
        static_assert(nkr::cpp::is_tr<template_i::actual_of_tuple_t<nkr::tuple::types_t<int>>, nkr::concurrency::lockee_t<int>>);
        static_assert(nkr::cpp::is_tr<template_i::actual_of_pack_t<int>, nkr::concurrency::lockee_t<int>>);
        static_assert(nkr::cpp::is_tr<template_i::actual_example_t, nkr::concurrency::lockee_t<nkr::positive::integer_t>>);

        static_assert(nkr::generic::implementing::interface::template_ttr<nkr::concurrency::lockee_ttg>);
        using template_tag_i = nkr::interface::template_i<nkr::concurrency::lockee_ttg>;

        static_assert(nkr::cpp::is_tr<template_tag_i::template_t<int>, nkr::concurrency::lockee_t<int>>);
        static_assert(nkr::cpp::is_tr<template_tag_i::of_t<int>, nkr::concurrency::lockee_t<int>>);
        static_assert(nkr::cpp::is_tr<template_tag_i::of_tuple_t<nkr::tuple::types_t<int>>, nkr::concurrency::lockee_t<int>>);
        static_assert(nkr::cpp::is_tr<template_tag_i::of_pack_t<int>, nkr::concurrency::lockee_t<int>>);
        static_assert(nkr::cpp::is_tr<template_tag_i::example_t, nkr::concurrency::lockee_t<nkr::positive::integer_t>>);

        static_assert(nkr::cpp::is_tr<template_tag_i::actual_template_t<int>, nkr::concurrency::lockee_ttg<int>>);
        static_assert(nkr::cpp::is_tr<template_tag_i::actual_of_t<int>, nkr::concurrency::lockee_ttg<int>>);
        static_assert(nkr::cpp::is_tr<template_tag_i::actual_of_tuple_t<nkr::tuple::types_t<int>>, nkr::concurrency::lockee_ttg<int>>);
        static_assert(nkr::cpp::is_tr<template_tag_i::actual_of_pack_t<int>, nkr::concurrency::lockee_ttg<int>>);
        static_assert(nkr::cpp::is_tr<template_tag_i::actual_example_t, nkr::concurrency::lockee_ttg<>>);
    }

    nkr::concurrency::lockee_t<nkr::positive::integer_t> Shared_Positive_Integer()
    {
        static nkr::positive::integer_t positive_integer = 0;
        static nkr::cpp::concurrency::lock::perpetual::deep_t lock;

        return nkr::concurrency::lockee_t<nkr::positive::integer_t>(positive_integer, lock);
    }

    TEST_SUITE("nkr::concurrency::lockee_t")
    {
        TEST_CASE("should be able to get multiple times in the same thread")
        {
            auto shared_positive_integer = Shared_Positive_Integer();
            auto duplicate = Shared_Positive_Integer();

            CHECK(shared_positive_integer == 0);
            shared_positive_integer.Value() = 1;
            duplicate.Value(positive::integer_t(2));
        }

        TEST_CASE("should be able to move without causing a deadlock on destruction")
        {
            auto shared_positive_integer = Shared_Positive_Integer();
            auto moved = nkr::cpp::Move(shared_positive_integer);

            CHECK(moved == 2);
        }

        TEST_CASE("should implictly cast to value_t")
        {
            auto shared_positive_integer = Shared_Positive_Integer();
            nkr::positive::integer_t positive_integer = shared_positive_integer;

            CHECK(positive_integer == 2);
        }
    }

}
