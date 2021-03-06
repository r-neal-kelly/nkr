/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_44611d6f_cb20_43b0_91c4_e82db20a63d0
#define nkr_INCLUDE_GUARD_44611d6f_cb20_43b0_91c4_e82db20a63d0

#include "nkr/cpp/concurrency/locker/exclusive_t_dec.h"

namespace nkr { namespace cpp { namespace concurrency { namespace locker { namespace exclusive_t$ {

    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        Is_Any_General()
        noexcept
    {
        return
            nkr::cpp::concurrency::locker::exclusive_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::cpp::concurrency::locker::exclusive_tg>;
    }

    template <nkr::cpp::concurrency::locker::exclusive_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::cpp::concurrency::locker::exclusive_t$::Is_Any_General<other_p>();
    }

    template <nkr::cpp::concurrency::locker::exclusive_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

    template <nkr::cpp::is_any_tr<nkr::cpp::concurrency::locker::exclusive_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::cpp::concurrency::locker::exclusive_t$::Is_Any_General<other_p>();
    }

    template <nkr::cpp::is_any_tr<nkr::cpp::concurrency::locker::exclusive_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}}}

#endif
