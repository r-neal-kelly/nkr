/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_1119ec0b_35d1_45f0_86e1_eef9fa9fa091
#define nkr_INCLUDE_GUARD_1119ec0b_35d1_45f0_86e1_eef9fa9fa091

#include "nkr/generic/built_in/number/enumeration/limited_tr_dec.h"

namespace nkr { namespace generic { namespace built_in { namespace number { namespace enumeration { namespace limited_tr$ {

    template <nkr::cpp::is_any_tr<nkr::generic::built_in::number::enumeration::limited_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return
            nkr::generic::built_in::number::enumeration::limited_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::generic::built_in::number::enumeration::limited_tg>;
    }

    template <nkr::cpp::is_any_tr<nkr::generic::built_in::number::enumeration::limited_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}}}}

namespace nkr { namespace generic { namespace built_in { namespace number { namespace enumeration { namespace limited_tr$ {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::generic::built_in::number::enumeration::limited_ttg>
    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i_tag_sp<template_p>::Is_Any()
        noexcept
    {
        return nkr::generic::built_in::number::enumeration::limited_ttr<other_p>;
    }

}}}}}}

#endif
