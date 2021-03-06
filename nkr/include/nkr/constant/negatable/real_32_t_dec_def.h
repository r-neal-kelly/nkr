/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_c4a6ef31_e174_45f8_a069_5ad8001017c8
#define nkr_INCLUDE_GUARD_c4a6ef31_e174_45f8_a069_5ad8001017c8

#include "nkr/constant/negatable/real_32_t_dec.h"

namespace nkr { namespace constant { namespace negatable { namespace real_32_t$ {

    template <nkr::cpp::is_any_tr<nkr::constant::negatable::real_32_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return
            nkr::constant::negatable::real_32_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::constant::negatable::real_32_tg>;
    }

    template <nkr::cpp::is_any_tr<nkr::constant::negatable::real_32_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}}

#endif
