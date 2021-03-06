/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_33f262ce_69c5_4f8a_8db0_49a2381b9631
#define nkr_INCLUDE_GUARD_33f262ce_69c5_4f8a_8db0_49a2381b9631

#include "nkr/generic/implementing/interface/none/value_tr_dec.h"

namespace nkr { namespace generic { namespace implementing { namespace interface { namespace none { namespace value_tr$ {

    template <nkr::cpp::is_any_tr<nkr::generic::implementing::interface::none::value_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return
            nkr::generic::implementing::interface::none::value_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::generic::implementing::interface::none::value_tg>;
    }

    template <nkr::cpp::is_any_tr<nkr::generic::implementing::interface::none::value_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}}}}

namespace nkr { namespace generic { namespace implementing { namespace interface { namespace none { namespace value_tr$ {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::generic::implementing::interface::none::value_ttg>
    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i_tag_sp<template_p>::Is_Any()
        noexcept
    {
        return nkr::generic::implementing::interface::none::value_ttr<other_p>;
    }

}}}}}}

#endif
