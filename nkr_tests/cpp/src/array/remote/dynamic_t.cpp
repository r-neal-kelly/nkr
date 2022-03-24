/*
    Copyright 2022 r-neal-kelly
*/

#include "nkr/cpp/array/remote/dynamic_t.h"
#include "nkr/generic/implementing/interface/template_tr.h"

#include "doctest.h"

namespace nkr {

    TEST_SUITE("temp")
    {
        static_assert(nkr::generic::implementing::interface::template_ttr<nkr::cpp::array::remote::dynamic_t>);
        using template_i = nkr::interface::template_i<nkr::cpp::array::remote::dynamic_t>;

        static_assert(nkr::cpp::is_tr<template_i::template_t<int>, nkr::cpp::array::remote::dynamic_t<int>>);
        static_assert(nkr::cpp::is_tr<template_i::of_t<int>, nkr::cpp::array::remote::dynamic_t<int>>);
        static_assert(nkr::cpp::is_tr<template_i::of_tuple_t<nkr::tuple::types_t<int>>, nkr::cpp::array::remote::dynamic_t<int>>);
        static_assert(nkr::cpp::is_tr<template_i::of_tuple_t<nkr::tuple::types_t<int, std::allocator<int>>>, nkr::cpp::array::remote::dynamic_t<int>>);
        static_assert(nkr::cpp::is_tr<template_i::of_pack_t<int>, nkr::cpp::array::remote::dynamic_t<int>>);
        static_assert(nkr::cpp::is_tr<template_i::of_pack_t<int, std::allocator<int>>, nkr::cpp::array::remote::dynamic_t<int>>);
        static_assert(nkr::cpp::is_tr<template_i::example_t, nkr::cpp::array::remote::dynamic_t<nkr::positive::integer_t>>);

        static_assert(nkr::cpp::is_tr<template_i::actual_template_t<int>, nkr::cpp::array::remote::dynamic_t<int>>);
        static_assert(nkr::cpp::is_tr<template_i::actual_of_t<int>, nkr::cpp::array::remote::dynamic_t<int>>);
        static_assert(nkr::cpp::is_tr<template_i::actual_of_tuple_t<nkr::tuple::types_t<int>>, nkr::cpp::array::remote::dynamic_t<int>>);
        static_assert(nkr::cpp::is_tr<template_i::actual_of_tuple_t<nkr::tuple::types_t<int, std::allocator<int>>>, nkr::cpp::array::remote::dynamic_t<int>>);
        static_assert(nkr::cpp::is_tr<template_i::actual_of_pack_t<int>, nkr::cpp::array::remote::dynamic_t<int>>);
        static_assert(nkr::cpp::is_tr<template_i::actual_of_pack_t<int, std::allocator<int>>, nkr::cpp::array::remote::dynamic_t<int>>);
        static_assert(nkr::cpp::is_tr<template_i::actual_example_t, nkr::cpp::array::remote::dynamic_t<nkr::positive::integer_t>>);

        static_assert(nkr::generic::implementing::interface::template_ttr<nkr::cpp::array::remote::dynamic_ttg>);
        using template_tag_i = nkr::interface::template_i<nkr::cpp::array::remote::dynamic_ttg>;

        static_assert(nkr::cpp::is_tr<template_tag_i::template_t<int>, nkr::cpp::array::remote::dynamic_t<int>>);
        static_assert(nkr::cpp::is_tr<template_tag_i::of_t<int>, nkr::cpp::array::remote::dynamic_t<int>>);
        static_assert(nkr::cpp::is_tr<template_tag_i::of_tuple_t<nkr::tuple::types_t<int>>, nkr::cpp::array::remote::dynamic_t<int>>);
        static_assert(nkr::cpp::is_tr<template_tag_i::of_tuple_t<nkr::tuple::types_t<int, std::allocator<int>>>, nkr::cpp::array::remote::dynamic_t<int>>);
        static_assert(nkr::cpp::is_tr<template_tag_i::of_pack_t<int>, nkr::cpp::array::remote::dynamic_t<int>>);
        static_assert(nkr::cpp::is_tr<template_tag_i::of_pack_t<int, std::allocator<int>>, nkr::cpp::array::remote::dynamic_t<int>>);
        static_assert(nkr::cpp::is_tr<template_tag_i::example_t, nkr::cpp::array::remote::dynamic_t<nkr::positive::integer_t>>);

        static_assert(nkr::cpp::is_tr<template_tag_i::actual_template_t<int>, nkr::cpp::array::remote::dynamic_ttg<int>>);
        static_assert(nkr::cpp::is_tr<template_tag_i::actual_of_t<int>, nkr::cpp::array::remote::dynamic_ttg<int>>);
        static_assert(nkr::cpp::is_tr<template_tag_i::actual_of_tuple_t<nkr::tuple::types_t<int>>, nkr::cpp::array::remote::dynamic_ttg<int>>);
        static_assert(nkr::cpp::is_tr<template_tag_i::actual_of_tuple_t<nkr::tuple::types_t<int, std::allocator<int>>>, nkr::cpp::array::remote::dynamic_ttg<int, std::allocator<int>>>);
        static_assert(nkr::cpp::is_tr<template_tag_i::actual_of_pack_t<int>, nkr::cpp::array::remote::dynamic_ttg<int>>);
        static_assert(nkr::cpp::is_tr<template_tag_i::actual_of_pack_t<int, std::allocator<int>>, nkr::cpp::array::remote::dynamic_ttg<int, std::allocator<int>>>);
        static_assert(nkr::cpp::is_tr<template_tag_i::actual_example_t, nkr::cpp::array::remote::dynamic_ttg<>>);
    }

}
