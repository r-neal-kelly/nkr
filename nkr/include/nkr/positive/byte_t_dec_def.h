/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_851375ca_272a_423c_b879_931fcd7eb6f7
#define nkr_INCLUDE_GUARD_851375ca_272a_423c_b879_931fcd7eb6f7

#include "nkr/positive/byte_t_dec.h"

namespace nkr { namespace positive { namespace byte_t$ {

    template <nkr::cpp::is_any_tr<nkr::positive::byte_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return
            nkr::positive::byte_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::positive::byte_tg>;
    }

    template <nkr::cpp::is_any_tr<nkr::positive::byte_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}

#endif
