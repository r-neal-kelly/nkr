/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_b5584cba_acec_45ab_b563_da816e141c7f
#define nkr_INCLUDE_GUARD_b5584cba_acec_45ab_b563_da816e141c7f

#include "nkr/generic/tag/type_tr_dec.h"

namespace nkr { namespace generic { namespace tag { namespace type_tr$ {

    template <nkr::cpp::is_any_tr<nkr::generic::tag::type_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return
            nkr::generic::tag::type_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::generic::tag::type_tg>;
    }

    template <nkr::cpp::is_any_tr<nkr::generic::tag::type_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}}

namespace nkr { namespace generic { namespace tag { namespace type_tr$ {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::generic::tag::type_ttg>
    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i_tag_sp<template_p>::Is_Any()
        noexcept
    {
        return nkr::generic::tag::type_ttr<other_p>;
    }

}}}}

#endif
