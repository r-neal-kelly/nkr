/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_b1d66896_2bf5_4dd0_98bc_5b80878cf932
#define nkr_INCLUDE_GUARD_b1d66896_2bf5_4dd0_98bc_5b80878cf932

#include "nkr/cpp/concurrency/locker/inclusive_t_dec.h"

namespace nkr { namespace cpp { namespace concurrency { namespace locker { namespace inclusive_t$ {

    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        Is_Any_General()
        noexcept
    {
        return
            nkr::cpp::concurrency::locker::inclusive_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::cpp::concurrency::locker::inclusive_tg>;
    }

    template <nkr::cpp::concurrency::locker::inclusive_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::cpp::concurrency::locker::inclusive_t$::Is_Any_General<other_p>();
    }

    template <nkr::cpp::concurrency::locker::inclusive_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

    template <nkr::cpp::is_any_tr<nkr::cpp::concurrency::locker::inclusive_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::cpp::concurrency::locker::inclusive_t$::Is_Any_General<other_p>();
    }

    template <nkr::cpp::is_any_tr<nkr::cpp::concurrency::locker::inclusive_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}}}

#endif
