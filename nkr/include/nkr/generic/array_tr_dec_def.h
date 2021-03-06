/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_5b931e4b_4462_4f1d_a0f1_f699dbaa5c5c
#define nkr_INCLUDE_GUARD_5b931e4b_4462_4f1d_a0f1_f699dbaa5c5c

#include "nkr/generic/array_tr_dec.h"

namespace nkr { namespace generic { namespace array_tr$ {

    template <nkr::cpp::is_any_tr<nkr::generic::array_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return
            nkr::generic::array_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::generic::array_tg>;
    }

    template <nkr::cpp::is_any_tr<nkr::generic::array_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}

namespace nkr { namespace generic { namespace array_tr$ {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::generic::array_ttg>
    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i_tag_sp<template_p>::Is_Any()
        noexcept
    {
        return nkr::generic::array_ttr<other_p>;
    }

}}}

#endif
