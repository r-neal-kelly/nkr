/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/reference/lvalue_t_dec.h"

namespace nkr { namespace reference { namespace lvalue_t$ {

    template <nkr::reference::lvalue_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::reference::lvalue_tr<other_p>;
    }

    template <nkr::reference::lvalue_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

    template <nkr::cpp::is_any_tr<nkr::reference::lvalue_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::reference::lvalue_tr<other_p>;
    }

    template <nkr::cpp::is_any_tr<nkr::reference::lvalue_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}

namespace nkr { namespace reference { namespace lvalue_t$ {

    template <template <typename ...> typename template_p>
        requires nkr::reference::lvalue_ttr<template_p>
    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i_template_sp<template_p>::Is_Any()
        noexcept
    {
        return nkr::reference::lvalue_ttr<other_p>;
    }

}}}
