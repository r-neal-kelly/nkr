/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_cc563f16_91b3_45db_ac69_e78ac578a7bb
#define nkr_INCLUDE_GUARD_cc563f16_91b3_45db_ac69_e78ac578a7bb

#include "nkr/cpp/randomness/distributor/uniform/real_t_dec.h"

namespace nkr { namespace cpp { namespace randomness { namespace distributor { namespace uniform { namespace real_t$ {

    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        Is_Any_General()
        noexcept
    {
        return
            nkr::cpp::randomness::distributor::uniform::real_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::cpp::randomness::distributor::uniform::real_tg>;
    }

    template <nkr::cpp::randomness::distributor::uniform::real_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::cpp::randomness::distributor::uniform::real_t$::Is_Any_General<other_p>();
    }

    template <nkr::cpp::randomness::distributor::uniform::real_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

    template <nkr::cpp::is_any_tr<nkr::cpp::randomness::distributor::uniform::real_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::cpp::randomness::distributor::uniform::real_t$::Is_Any_General<other_p>();
    }

    template <nkr::cpp::is_any_tr<nkr::cpp::randomness::distributor::uniform::real_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}}}}

#endif
