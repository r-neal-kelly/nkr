/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_d1f54754_c721_4a44_9093_7c050e82027d
#define nkr_INCLUDE_GUARD_d1f54754_c721_4a44_9093_7c050e82027d

#include "nkr/cpp/generic/concurrency/locker_tr_dec.h"

namespace nkr { namespace cpp { namespace generic { namespace concurrency { namespace locker_tr$ {

    template <nkr::cpp::is_any_tr<nkr::cpp::generic::concurrency::locker_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return
            nkr::cpp::generic::concurrency::locker_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::cpp::generic::concurrency::locker_tg>;
    }

    template <nkr::cpp::is_any_tr<nkr::cpp::generic::concurrency::locker_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}}}

namespace nkr { namespace cpp { namespace generic { namespace concurrency { namespace locker_tr$ {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::cpp::generic::concurrency::locker_ttg>
    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i_tag_sp<template_p>::Is_Any()
        noexcept
    {
        return nkr::cpp::generic::concurrency::locker_ttr<other_p>;
    }

}}}}}

#endif
