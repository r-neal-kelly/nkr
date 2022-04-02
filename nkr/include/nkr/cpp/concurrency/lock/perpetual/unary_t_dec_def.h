/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_3966b73c_6c51_4f4b_82dc_a7075ef46980
#define nkr_INCLUDE_GUARD_3966b73c_6c51_4f4b_82dc_a7075ef46980

#include "nkr/cpp/concurrency/lock/perpetual/unary_t_dec.h"

namespace nkr { namespace cpp { namespace concurrency { namespace lock { namespace perpetual { namespace unary_t$ {

    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        Is_Any_General()
        noexcept
    {
        return
            nkr::cpp::concurrency::lock::perpetual::unary_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::cpp::concurrency::lock::perpetual::unary_tg>;
    }

    template <nkr::cpp::concurrency::lock::perpetual::unary_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::cpp::concurrency::lock::perpetual::unary_t$::Is_Any_General<other_p>();
    }

    template <nkr::cpp::concurrency::lock::perpetual::unary_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

    template <nkr::cpp::is_any_tr<nkr::cpp::concurrency::lock::perpetual::unary_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::cpp::concurrency::lock::perpetual::unary_t$::Is_Any_General<other_p>();
    }

    template <nkr::cpp::is_any_tr<nkr::cpp::concurrency::lock::perpetual::unary_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}}}}

#endif
