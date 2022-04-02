/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_017ef821_10f6_4d11_b079_ea3f430c3e8b
#define nkr_INCLUDE_GUARD_017ef821_10f6_4d11_b079_ea3f430c3e8b

#include "nkr/constant/positive/integer_max_t_dec.h"

namespace nkr { namespace constant { namespace positive { namespace integer_max_t$ {

    template <nkr::cpp::is_any_tr<nkr::constant::positive::integer_max_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return
            nkr::constant::positive::integer_max_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::constant::positive::integer_max_tg>;
    }

    template <nkr::cpp::is_any_tr<nkr::constant::positive::integer_max_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}}

#endif
