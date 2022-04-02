/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_7d8934b4_4e44_4d3b_8bb5_acf2c11ad6c1
#define nkr_INCLUDE_GUARD_7d8934b4_4e44_4d3b_8bb5_acf2c11ad6c1

#include "nkr/none/type_t_dec.h"

namespace nkr { namespace none { namespace type_t$ {

    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        Is_Any_General()
        noexcept
    {
        return
            nkr::none::type_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::none::type_tg>;
    }

    template <nkr::none::type_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::none::type_t$::Is_Any_General<other_p>();
    }

    template <nkr::none::type_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

    template <nkr::cpp::is_any_tr<nkr::none::type_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::none::type_t$::Is_Any_General<other_p>();
    }

    template <nkr::cpp::is_any_tr<nkr::none::type_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}

#endif
