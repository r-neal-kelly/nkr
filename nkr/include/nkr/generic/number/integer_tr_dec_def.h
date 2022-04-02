/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_d6991b77_0ff4_4687_af64_54e2deb5214f
#define nkr_INCLUDE_GUARD_d6991b77_0ff4_4687_af64_54e2deb5214f

#include "nkr/generic/number/integer_tr_dec.h"

namespace nkr { namespace generic { namespace number { namespace integer_tr$ {

    template <nkr::cpp::is_any_tr<nkr::generic::number::integer_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return
            nkr::generic::number::integer_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::generic::number::integer_tg>;
    }

    template <nkr::cpp::is_any_tr<nkr::generic::number::integer_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}}

namespace nkr { namespace generic { namespace number { namespace integer_tr$ {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::generic::number::integer_ttg>
    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i_tag_sp<template_p>::Is_Any()
        noexcept
    {
        return nkr::generic::number::integer_ttr<other_p>;
    }

}}}}

#endif
