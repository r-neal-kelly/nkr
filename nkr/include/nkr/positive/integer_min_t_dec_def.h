/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_28d0e9da_38f6_4406_ae51_02a2b1f47fb5
#define nkr_INCLUDE_GUARD_28d0e9da_38f6_4406_ae51_02a2b1f47fb5

#include "nkr/positive/integer_min_t_dec.h"

namespace nkr { namespace positive { namespace integer_min_t$ {

    template <nkr::cpp::is_any_tr<nkr::positive::integer_min_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return
            nkr::positive::integer_min_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::positive::integer_min_tg>;
    }

    template <nkr::cpp::is_any_tr<nkr::positive::integer_min_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}

#endif
