/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_104d7a77_ee31_48cb_98df_39a10c3f948d
#define nkr_INCLUDE_GUARD_104d7a77_ee31_48cb_98df_39a10c3f948d

#include "nkr/constant/positive/size_t_dec.h"

namespace nkr { namespace constant { namespace positive { namespace size_t$ {

    template <nkr::cpp::is_any_tr<nkr::constant::positive::size_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return
            nkr::constant::positive::size_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::constant::positive::size_tg>;
    }

    template <nkr::cpp::is_any_tr<nkr::constant::positive::size_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}}

#endif
