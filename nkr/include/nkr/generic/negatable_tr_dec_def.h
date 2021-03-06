/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_e8a3a4a9_4ef1_490e_bd69_fa43a03f7cfd
#define nkr_INCLUDE_GUARD_e8a3a4a9_4ef1_490e_bd69_fa43a03f7cfd

#include "nkr/generic/negatable_tr_dec.h"

namespace nkr { namespace generic { namespace negatable_tr$ {

    template <nkr::cpp::is_any_tr<nkr::generic::negatable_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return
            nkr::generic::negatable_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::generic::negatable_tg>;
    }

    template <nkr::cpp::is_any_tr<nkr::generic::negatable_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}

namespace nkr { namespace generic { namespace negatable_tr$ {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::generic::negatable_ttg>
    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i_tag_sp<template_p>::Is_Any()
        noexcept
    {
        return nkr::generic::negatable_ttr<other_p>;
    }

}}}

#endif
