/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/cpp/randomness/generator/software/mersenne_twister_t_dec.h"

namespace nkr { namespace cpp { namespace randomness { namespace generator { namespace software { namespace mersenne_twister_t$ {

    template <nkr::cpp::randomness::generator::software::mersenne_twister_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::cpp::randomness::generator::software::mersenne_twister_tr<other_p>;
    }

    template <nkr::cpp::randomness::generator::software::mersenne_twister_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

    template <nkr::cpp::is_any_tr<nkr::cpp::randomness::generator::software::mersenne_twister_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::cpp::randomness::generator::software::mersenne_twister_tr<other_p>;
    }

    template <nkr::cpp::is_any_tr<nkr::cpp::randomness::generator::software::mersenne_twister_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}}}}

namespace nkr { namespace cpp { namespace randomness { namespace generator { namespace software { namespace mersenne_twister_t$ {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::randomness::generator::software::mersenne_twister_ttr<template_p>
    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i_template_sp<template_p>::Is_Any()
        noexcept
    {
        return nkr::cpp::randomness::generator::software::mersenne_twister_ttr<other_p>;
    }

    template <template <typename ...> typename template_p>
        requires nkr::cpp::randomness::generator::software::mersenne_twister_ttr<template_p>
    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i_template_sp<template_p>::Is_Any_Actual()
        noexcept
    {
        return nkr::cpp::randomness::generator::software::mersenne_twister_ttr<other_p>;
    }

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::cpp::randomness::generator::software::mersenne_twister_ttg>
    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i_tag_sp<template_p>::Is_Any_Actual()
        noexcept
    {
        return nkr::cpp::is_any_ttr<other_p, actual_template_t>;
    }

}}}}}}
