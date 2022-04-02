/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_01662ac3_1aa9_40ed_a84f_72f174b1bc17
#define nkr_INCLUDE_GUARD_01662ac3_1aa9_40ed_a84f_72f174b1bc17

#include "nkr/constant/negatable/byte_t_dec.h"

namespace nkr { namespace constant { namespace negatable { namespace byte_t$ {

    template <nkr::cpp::is_any_tr<nkr::constant::negatable::byte_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return
            nkr::constant::negatable::byte_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::constant::negatable::byte_tg>;
    }

    template <nkr::cpp::is_any_tr<nkr::constant::negatable::byte_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}}

#endif
