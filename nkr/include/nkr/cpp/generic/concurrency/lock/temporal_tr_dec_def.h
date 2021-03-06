/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_58fde77d_399b_45d2_840b_6ea7fc679569
#define nkr_INCLUDE_GUARD_58fde77d_399b_45d2_840b_6ea7fc679569

#include "nkr/cpp/generic/concurrency/lock/temporal_tr_dec.h"

namespace nkr { namespace cpp { namespace generic { namespace concurrency { namespace lock { namespace temporal_tr$ {

    template <nkr::cpp::is_any_tr<nkr::cpp::generic::concurrency::lock::temporal_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return
            nkr::cpp::generic::concurrency::lock::temporal_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::cpp::generic::concurrency::lock::temporal_tg>;
    }

    template <nkr::cpp::is_any_tr<nkr::cpp::generic::concurrency::lock::temporal_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}}}}

namespace nkr { namespace cpp { namespace generic { namespace concurrency { namespace lock { namespace temporal_tr$ {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::cpp::generic::concurrency::lock::temporal_ttg>
    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i_tag_sp<template_p>::Is_Any()
        noexcept
    {
        return nkr::cpp::generic::concurrency::lock::temporal_ttr<other_p>;
    }

}}}}}}

#endif
