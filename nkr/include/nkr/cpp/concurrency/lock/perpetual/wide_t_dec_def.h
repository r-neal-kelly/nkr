/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_bad1f570_b034_4a43_9ed7_063f5c33f336
#define nkr_INCLUDE_GUARD_bad1f570_b034_4a43_9ed7_063f5c33f336

#include "nkr/cpp/concurrency/lock/perpetual/wide_t_dec.h"

namespace nkr { namespace cpp { namespace concurrency { namespace lock { namespace perpetual { namespace wide_t$ {

    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        Is_Any_General()
        noexcept
    {
        return
            nkr::cpp::concurrency::lock::perpetual::wide_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::cpp::concurrency::lock::perpetual::wide_tg>;
    }

    template <nkr::cpp::concurrency::lock::perpetual::wide_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::cpp::concurrency::lock::perpetual::wide_t$::Is_Any_General<other_p>();
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
        return nkr::cpp::concurrency::lock::perpetual::wide_t$::Is_Any_General<other_p>();
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

#endif
