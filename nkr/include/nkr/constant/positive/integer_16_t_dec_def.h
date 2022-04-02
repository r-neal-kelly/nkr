/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_b5de0a91_788a_4ce7_86e3_974e07edd629
#define nkr_INCLUDE_GUARD_b5de0a91_788a_4ce7_86e3_974e07edd629

#include "nkr/constant/positive/integer_16_t_dec.h"

namespace nkr { namespace constant { namespace positive { namespace integer_16_t$ {

    template <nkr::cpp::is_any_tr<nkr::constant::positive::integer_16_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return
            nkr::constant::positive::integer_16_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::constant::positive::integer_16_tg>;
    }

    template <nkr::cpp::is_any_tr<nkr::constant::positive::integer_16_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}}

#endif
