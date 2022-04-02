/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_33663217_b388_47ec_bebb_a95c5c15f0e7
#define nkr_INCLUDE_GUARD_33663217_b388_47ec_bebb_a95c5c15f0e7

#include "nkr/cpp/randomness/generator/hardware_t_dec.h"

namespace nkr { namespace cpp { namespace randomness { namespace generator { namespace hardware_t$ {

    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        Is_Any_General()
        noexcept
    {
        return
            nkr::cpp::randomness::generator::hardware_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::cpp::randomness::generator::hardware_tg>;
    }

    template <nkr::cpp::randomness::generator::hardware_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::cpp::randomness::generator::hardware_t$::Is_Any_General<other_p>();
    }

    template <nkr::cpp::randomness::generator::hardware_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

    template <nkr::cpp::is_any_tr<nkr::cpp::randomness::generator::hardware_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::cpp::randomness::generator::hardware_t$::Is_Any_General<other_p>();
    }

    template <nkr::cpp::is_any_tr<nkr::cpp::randomness::generator::hardware_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}}}

#endif
