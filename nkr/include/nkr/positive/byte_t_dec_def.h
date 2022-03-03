/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/positive/byte_t_dec.h"

namespace nkr { namespace positive { namespace $byte_t {

    template <nkr::cpp::is_any_tr<nkr::positive::byte_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::positive::byte_tr<other_p>;
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
