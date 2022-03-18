/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/generic/implementing/self/constructor_tr_dec.h"

namespace nkr { namespace generic { namespace implementing { namespace self { namespace constructor_tr$ {

    template <nkr::cpp::is_any_tr<nkr::generic::implementing::self::constructor_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return
            nkr::generic::implementing::self::constructor_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::generic::implementing::self::constructor_tg>;
    }

    template <nkr::cpp::is_any_tr<nkr::generic::implementing::self::constructor_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}}}

namespace nkr { namespace generic { namespace implementing { namespace self { namespace constructor_tr$ {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::generic::implementing::self::constructor_ttg>
    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i_tag_sp<template_p>::Is_Any()
        noexcept
    {
        return nkr::generic::implementing::self::constructor_ttr<other_p>;
    }

}}}}}
