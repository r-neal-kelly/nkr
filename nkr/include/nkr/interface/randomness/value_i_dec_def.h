/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/interface/randomness/value_i_dec.h"

namespace nkr { namespace interface { namespace randomness { namespace $value_i {

    template <nkr::interface::randomness::value_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::interface::randomness::value_tr<other_p>;
    }

    template <nkr::interface::randomness::value_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

    template <nkr::cpp::is_any_tr<nkr::interface::randomness::value_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::interface::randomness::value_tr<other_p>;
    }

    template <nkr::cpp::is_any_tr<nkr::interface::randomness::value_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}}

namespace nkr { namespace interface { namespace randomness { namespace $value_i {

    template <template <typename ...> typename template_p>
        requires nkr::interface::randomness::value_ttr<template_p>
    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i_template_sp<template_p>::Is_Any()
        noexcept
    {
        return nkr::interface::randomness::value_ttr<other_p>;
    }

}}}}
