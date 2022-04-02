/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_bea82a7f_ffe6_432b_a1f5_96fe8f31a568
#define nkr_INCLUDE_GUARD_bea82a7f_ffe6_432b_a1f5_96fe8f31a568

#include "nkr/generic/non_type_tr_dec.h"

namespace nkr { namespace generic { namespace non_type_tr$ {

    template <nkr::cpp::is_any_tr<nkr::generic::non_type_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return
            nkr::generic::non_type_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::generic::non_type_tg>;
    }

    template <nkr::cpp::is_any_tr<nkr::generic::non_type_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}

namespace nkr { namespace generic { namespace non_type_tr$ {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::generic::non_type_ttg>
    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i_tag_sp<template_p>::Is_Any()
        noexcept
    {
        return nkr::generic::non_type_ttr<other_p>;
    }

}}}

#endif
