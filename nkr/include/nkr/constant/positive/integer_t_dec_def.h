/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_539980b7_6478_48b7_8548_eb891535d85d
#define nkr_INCLUDE_GUARD_539980b7_6478_48b7_8548_eb891535d85d

#include "nkr/constant/positive/integer_t_dec.h"

namespace nkr { namespace constant { namespace positive { namespace integer_t$ {

    template <nkr::cpp::is_any_tr<nkr::constant::positive::integer_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return
            nkr::constant::positive::integer_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::constant::positive::integer_tg>;
    }

    template <nkr::cpp::is_any_tr<nkr::constant::positive::integer_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}}

#endif
