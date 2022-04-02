/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_841ab998_ff48_4b4a_b173_fc011e8779e9
#define nkr_INCLUDE_GUARD_841ab998_ff48_4b4a_b173_fc011e8779e9

#include "nkr/positive/integer_t_dec.h"

namespace nkr { namespace positive { namespace integer_t$ {

    template <nkr::cpp::is_any_tr<nkr::positive::integer_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return
            nkr::positive::integer_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::positive::integer_tg>;
    }

    template <nkr::cpp::is_any_tr<nkr::positive::integer_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}

#endif
