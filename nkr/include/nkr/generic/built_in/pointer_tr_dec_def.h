/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_eef7d0df_47b8_4415_bdd4_febd7aea67f0
#define nkr_INCLUDE_GUARD_eef7d0df_47b8_4415_bdd4_febd7aea67f0

#include "nkr/generic/built_in/pointer_tr_dec.h"

namespace nkr { namespace generic { namespace built_in { namespace pointer_tr$ {

    template <nkr::cpp::is_any_tr<nkr::generic::built_in::pointer_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return
            nkr::generic::built_in::pointer_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::generic::built_in::pointer_tg>;
    }

    template <nkr::cpp::is_any_tr<nkr::generic::built_in::pointer_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}}

namespace nkr { namespace generic { namespace built_in { namespace pointer_tr$ {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::generic::built_in::pointer_ttg>
    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i_tag_sp<template_p>::Is_Any()
        noexcept
    {
        return nkr::generic::built_in::pointer_ttr<other_p>;
    }

}}}}

#endif
