/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_f1811402_2bcf_45b8_b73e_d058244755b7
#define nkr_INCLUDE_GUARD_f1811402_2bcf_45b8_b73e_d058244755b7

#include "nkr/constant/negatable/real_min_t_dec.h"

namespace nkr { namespace constant { namespace negatable { namespace real_min_t$ {

    template <nkr::cpp::is_any_tr<nkr::constant::negatable::real_min_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return
            nkr::constant::negatable::real_min_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::constant::negatable::real_min_tg>;
    }

    template <nkr::cpp::is_any_tr<nkr::constant::negatable::real_min_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}}

#endif
