/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_d20f24e3_0d6b_417a_954b_ce44748a97ed
#define nkr_INCLUDE_GUARD_d20f24e3_0d6b_417a_954b_ce44748a97ed

#include "nkr/constant/negatable/real_max_t_dec.h"

namespace nkr { namespace constant { namespace negatable { namespace real_max_t$ {

    template <nkr::cpp::is_any_tr<nkr::constant::negatable::real_max_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return
            nkr::constant::negatable::real_max_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::constant::negatable::real_max_tg>;
    }

    template <nkr::cpp::is_any_tr<nkr::constant::negatable::real_max_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}}

#endif
