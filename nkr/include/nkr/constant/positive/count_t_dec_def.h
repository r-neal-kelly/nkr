/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_b64bf640_5ff9_431d_82b1_dc18bcd94e3c
#define nkr_INCLUDE_GUARD_b64bf640_5ff9_431d_82b1_dc18bcd94e3c

#include "nkr/constant/positive/count_t_dec.h"

namespace nkr { namespace constant { namespace positive { namespace count_t$ {

    template <nkr::cpp::is_any_tr<nkr::constant::positive::count_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return
            nkr::constant::positive::count_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::constant::positive::count_tg>;
    }

    template <nkr::cpp::is_any_tr<nkr::constant::positive::count_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}}

#endif
