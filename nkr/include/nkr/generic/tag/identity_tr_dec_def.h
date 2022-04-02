/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_ec4e99ee_218d_4d4a_9a9c_7084f4730286
#define nkr_INCLUDE_GUARD_ec4e99ee_218d_4d4a_9a9c_7084f4730286

#include "nkr/generic/tag/identity_tr_dec.h"

namespace nkr { namespace generic { namespace tag { namespace identity_tr$ {

    template <nkr::cpp::is_any_tr<nkr::generic::tag::identity_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return
            nkr::generic::tag::identity_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::generic::tag::identity_tg>;
    }

    template <nkr::cpp::is_any_tr<nkr::generic::tag::identity_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}}

namespace nkr { namespace generic { namespace tag { namespace identity_tr$ {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::generic::tag::identity_ttg>
    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i_tag_sp<template_p>::Is_Any()
        noexcept
    {
        return nkr::generic::tag::identity_ttr<other_p>;
    }

}}}}

#endif
