/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_45300129_5a48_4211_8668_e10dfe228842
#define nkr_INCLUDE_GUARD_45300129_5a48_4211_8668_e10dfe228842

#include "nkr/generic/built_in/boolean_tr_dec.h"

namespace nkr { namespace generic { namespace built_in { namespace boolean_tr$ {

    template <nkr::cpp::is_any_tr<nkr::generic::built_in::boolean_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return
            nkr::generic::built_in::boolean_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::generic::built_in::boolean_tg>;
    }

    template <nkr::cpp::is_any_tr<nkr::generic::built_in::boolean_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}}

namespace nkr { namespace generic { namespace built_in { namespace boolean_tr$ {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::generic::built_in::boolean_ttg>
    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i_tag_sp<template_p>::Is_Any()
        noexcept
    {
        return nkr::generic::built_in::boolean_ttr<other_p>;
    }

}}}}

#endif
