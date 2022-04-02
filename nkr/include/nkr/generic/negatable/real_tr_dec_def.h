/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_9c4a84e2_f2da_4a7c_8709_174229e0d29f
#define nkr_INCLUDE_GUARD_9c4a84e2_f2da_4a7c_8709_174229e0d29f

#include "nkr/generic/negatable/real_tr_dec.h"

namespace nkr { namespace generic { namespace negatable { namespace real_tr$ {

    template <nkr::cpp::is_any_tr<nkr::generic::negatable::real_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return
            nkr::generic::negatable::real_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::generic::negatable::real_tg>;
    }

    template <nkr::cpp::is_any_tr<nkr::generic::negatable::real_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}}

namespace nkr { namespace generic { namespace negatable { namespace real_tr$ {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::generic::negatable::real_ttg>
    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i_tag_sp<template_p>::Is_Any()
        noexcept
    {
        return nkr::generic::negatable::real_ttr<other_p>;
    }

}}}}

#endif
