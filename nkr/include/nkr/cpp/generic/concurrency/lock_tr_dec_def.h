/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_1d382e21_7f0a_4ca1_b719_8f2c1c3b0dca
#define nkr_INCLUDE_GUARD_1d382e21_7f0a_4ca1_b719_8f2c1c3b0dca

#include "nkr/cpp/generic/concurrency/lock_tr_dec.h"

namespace nkr { namespace cpp { namespace generic { namespace concurrency { namespace lock_tr$ {

    template <nkr::cpp::is_any_tr<nkr::cpp::generic::concurrency::lock_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return
            nkr::cpp::generic::concurrency::lock_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::cpp::generic::concurrency::lock_tg>;
    }

    template <nkr::cpp::is_any_tr<nkr::cpp::generic::concurrency::lock_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}}}

namespace nkr { namespace cpp { namespace generic { namespace concurrency { namespace lock_tr$ {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::cpp::generic::concurrency::lock_ttg>
    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i_tag_sp<template_p>::Is_Any()
        noexcept
    {
        return nkr::cpp::generic::concurrency::lock_ttr<other_p>;
    }

}}}}}

#endif
