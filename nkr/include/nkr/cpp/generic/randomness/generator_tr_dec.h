/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsics_dec.h"

#include "nkr/cpp/randomness/generator/hardware_t_dec.h"
#include "nkr/cpp/randomness/generator/software/mersenne_twister_t_dec.h"

namespace nkr { namespace cpp { namespace generic { namespace randomness {

    struct  generator_tg    {};

    template <typename>
    struct  generator_ttg   {};

    template <typename type_p>
    concept generator_tr =
        nkr::cpp::randomness::generator::hardware_tr<type_p> ||
        nkr::cpp::randomness::generator::software::mersenne_twister_tr<type_p>;

    template <template <typename ...> typename template_p>
    concept generator_ttr =
        generator_tr<typename nkr::interface::template_i<template_p>::example_t>;

}}}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::cpp::generic::randomness::generator_tg>
    {
    public:
        using type_t    = nkr::cpp::generic::randomness::generator_tg;
        using of_t      = nkr::none::type_t;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr type_i(...) noexcept  = delete;
    };

}}

namespace nkr { namespace interface {

    template <>
    class template_i<nkr::cpp::generic::randomness::generator_ttg>
    {
    public:
        template <typename inner_p>
        using of_t      = nkr::cpp::generic::randomness::generator_tg;
        using example_t = nkr::cpp::generic::randomness::generator_tg;

    public:
        template <template <typename ...> typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr template_i(...) noexcept  = delete;
    };

}}

#include "nkr/cpp/generic/randomness/generator_tr_dec_def.h"
