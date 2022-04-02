/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_39a7f984_0ada_4bfd_87a0_c2e4412a1b78
#define nkr_INCLUDE_GUARD_39a7f984_0ada_4bfd_87a0_c2e4412a1b78

#include "nkr/cpp/generic/concurrency/lock/perpetual_tr_dec.h"

namespace nkr { namespace cpp { namespace generic { namespace concurrency { namespace lock { namespace perpetual_tr$ {

    template <nkr::cpp::is_any_tr<nkr::cpp::generic::concurrency::lock::perpetual_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return
            nkr::cpp::generic::concurrency::lock::perpetual_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::cpp::generic::concurrency::lock::perpetual_tg>;
    }

    template <nkr::cpp::is_any_tr<nkr::cpp::generic::concurrency::lock::perpetual_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}}}}

namespace nkr { namespace cpp { namespace generic { namespace concurrency { namespace lock { namespace perpetual_tr$ {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::cpp::generic::concurrency::lock::perpetual_ttg>
    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i_tag_sp<template_p>::Is_Any()
        noexcept
    {
        return nkr::cpp::generic::concurrency::lock::perpetual_ttr<other_p>;
    }

}}}}}}

#endif
