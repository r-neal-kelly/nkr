/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_98288b3c_5911_4e23_bfef_43223d2fa00e
#define nkr_INCLUDE_GUARD_98288b3c_5911_4e23_bfef_43223d2fa00e

#include "nkr/constant/negatable/real_t_dec.h"

namespace nkr { namespace constant { namespace negatable { namespace real_t$ {

    template <nkr::cpp::is_any_tr<nkr::constant::negatable::real_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return
            nkr::constant::negatable::real_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::constant::negatable::real_tg>;
    }

    template <nkr::cpp::is_any_tr<nkr::constant::negatable::real_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}}

#endif
