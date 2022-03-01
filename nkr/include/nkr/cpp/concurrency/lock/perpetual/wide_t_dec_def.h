/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/cpp/concurrency/lock/perpetual/wide_t_dec.h"

namespace nkr { namespace cpp { namespace concurrency { namespace lock { namespace perpetual { namespace $wide_t {

    template <nkr::cpp::concurrency::lock::perpetual::wide_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::cpp::concurrency::lock::perpetual::wide_tr<other_p>;
    }

    template <nkr::cpp::concurrency::lock::perpetual::wide_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

    template <nkr::cpp::is_any_tr<nkr::cpp::concurrency::lock::perpetual::wide_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::cpp::concurrency::lock::perpetual::wide_tr<other_p>;
    }

    template <nkr::cpp::is_any_tr<nkr::cpp::concurrency::lock::perpetual::wide_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}}}}
