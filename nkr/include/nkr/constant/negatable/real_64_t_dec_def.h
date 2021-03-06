/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_892a8375_ea64_4578_825d_f36aa23c87a2
#define nkr_INCLUDE_GUARD_892a8375_ea64_4578_825d_f36aa23c87a2

#include "nkr/constant/negatable/real_64_t_dec.h"

namespace nkr { namespace constant { namespace negatable { namespace real_64_t$ {

    template <nkr::cpp::is_any_tr<nkr::constant::negatable::real_64_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return
            nkr::constant::negatable::real_64_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::constant::negatable::real_64_tg>;
    }

    template <nkr::cpp::is_any_tr<nkr::constant::negatable::real_64_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}}

#endif
