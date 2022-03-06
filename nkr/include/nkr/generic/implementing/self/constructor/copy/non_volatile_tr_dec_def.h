/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/generic/implementing/self/constructor/copy/non_volatile_tr_dec.h"

namespace nkr { namespace generic { namespace implementing { namespace self { namespace constructor {
namespace copy { namespace non_volatile_tr$ {

    template <nkr::cpp::is_any_tr<nkr::generic::implementing::self::constructor::copy::non_volatile_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::generic::implementing::self::constructor::copy::non_volatile_tr<other_p>;
    }

    template <nkr::cpp::is_any_tr<nkr::generic::implementing::self::constructor::copy::non_volatile_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}}}}}

namespace nkr { namespace generic { namespace implementing { namespace self { namespace constructor {
namespace copy { namespace non_volatile_tr$ {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::generic::implementing::self::constructor::copy::non_volatile_ttg, nkr::none::type_t>
    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i_tag_sp<template_p>::Is_Any()
        noexcept
    {
        return nkr::generic::implementing::self::constructor::copy::non_volatile_ttr<other_p>;
    }

}}}}}}}
