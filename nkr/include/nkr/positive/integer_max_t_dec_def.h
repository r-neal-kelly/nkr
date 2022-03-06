/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/positive/integer_max_t_dec.h"

namespace nkr { namespace positive { namespace integer_max_t$ {

    template <nkr::cpp::is_any_tr<nkr::positive::integer_max_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::positive::integer_max_tr<other_p>;
    }

    template <nkr::cpp::is_any_tr<nkr::positive::integer_max_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}
