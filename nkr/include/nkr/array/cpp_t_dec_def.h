/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_a5ca7e22_b60b_43d5_ab9e_47489889d77c
#define nkr_INCLUDE_GUARD_a5ca7e22_b60b_43d5_ab9e_47489889d77c

#include "nkr/array/cpp_t_dec.h"

namespace nkr { namespace array { namespace cpp_t$ {

    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        Is_Any_General()
        noexcept
    {
        return
            nkr::array::cpp_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::array::cpp_tg>;
    }

    template <nkr::array::cpp_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::array::cpp_t$::Is_Any_General<other_p>();
    }

    template <nkr::array::cpp_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

    template <nkr::cpp::is_any_tr<nkr::array::cpp_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::array::cpp_t$::Is_Any_General<other_p>();
    }

    template <nkr::cpp::is_any_tr<nkr::array::cpp_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}

#endif
