/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_ef8e2a42_911d_408c_b480_737cf9662601
#define nkr_INCLUDE_GUARD_ef8e2a42_911d_408c_b480_737cf9662601

#include "nkr/generic/tag_tr_dec.h"

namespace nkr { namespace generic { namespace tag_tr$ {

    template <nkr::cpp::is_any_tr<nkr::generic::tag_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return
            nkr::generic::tag_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::generic::tag_tg>;
    }

    template <nkr::cpp::is_any_tr<nkr::generic::tag_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}

namespace nkr { namespace generic { namespace tag_tr$ {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::generic::tag_ttg>
    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i_tag_sp<template_p>::Is_Any()
        noexcept
    {
        return nkr::generic::tag_ttr<other_p>;
    }

}}}

#endif
