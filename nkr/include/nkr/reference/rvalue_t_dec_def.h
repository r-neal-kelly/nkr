/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/reference/rvalue_t_dec.h"

namespace nkr { namespace reference { namespace rvalue_t$ {

    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        Is_Any_General()
        noexcept
    {
        return
            nkr::reference::rvalue_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::reference::rvalue_tg>;
    }

    template <nkr::reference::rvalue_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::reference::rvalue_t$::Is_Any_General<other_p>();
    }

    template <nkr::reference::rvalue_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

    template <nkr::cpp::is_any_tr<nkr::reference::rvalue_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::reference::rvalue_t$::Is_Any_General<other_p>();
    }

    template <nkr::cpp::is_any_tr<nkr::reference::rvalue_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}

namespace nkr { namespace reference { namespace rvalue_t$ {

    template <template <typename ...> typename template_p>
        requires nkr::reference::rvalue_ttr<template_p>
    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i_template_sp<template_p>::Is_Any()
        noexcept
    {
        return nkr::reference::rvalue_ttr<other_p>;
    }

    template <template <typename ...> typename template_p>
        requires nkr::reference::rvalue_ttr<template_p>
    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i_template_sp<template_p>::Is_Any_Actual()
        noexcept
    {
        return nkr::reference::rvalue_ttr<other_p>;
    }

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::reference::rvalue_ttg>
    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i_tag_sp<template_p>::Is_Any_Actual()
        noexcept
    {
        return nkr::cpp::is_any_ttr<other_p, actual_template_t>;
    }

}}}
