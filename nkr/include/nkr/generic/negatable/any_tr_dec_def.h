/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_7cb51044_01cb_4cf9_9a08_19c27ab4e0b2
#define nkr_INCLUDE_GUARD_7cb51044_01cb_4cf9_9a08_19c27ab4e0b2

#include "nkr/generic/negatable/any_tr_dec.h"

namespace nkr { namespace generic { namespace negatable { namespace any_tr$ {

    template <nkr::cpp::is_any_tr<nkr::generic::negatable::any_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return
            nkr::generic::negatable::any_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::generic::negatable::any_tg>;
    }

    template <nkr::cpp::is_any_tr<nkr::generic::negatable::any_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}}

namespace nkr { namespace generic { namespace negatable { namespace any_tr$ {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::generic::negatable::any_ttg>
    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i_tag_sp<template_p>::Is_Any()
        noexcept
    {
        return nkr::generic::negatable::any_ttr<other_p>;
    }

}}}}

#endif
