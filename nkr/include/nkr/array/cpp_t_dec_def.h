/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/array/cpp_t_dec.h"

namespace nkr { namespace array { namespace $cpp_t {

    template <nkr::array::cpp_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::array::cpp_tr<other_p>;
    }

    template <nkr::array::cpp_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

    template <nkr::cpp::is_any_tr<nkr::array::cpp_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::array::cpp_tr<other_p>;
    }

    template <nkr::cpp::is_any_tr<nkr::array::cpp_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}

namespace nkr { namespace array { namespace $cpp_t {

    template <template <typename ...> typename template_p>
        requires nkr::array::cpp_ttr<template_p>
    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i_template_sp<template_p>::Is_Any()
        noexcept
    {
        return nkr::array::cpp_ttr<other_p>;
    }

}}}
