/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/negatable/integer_t_dec.h"

namespace nkr { namespace negatable { namespace integer_t$ {

    template <nkr::cpp::is_any_tr<nkr::negatable::integer_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::negatable::integer_tr<other_p>;
    }

    template <nkr::cpp::is_any_tr<nkr::negatable::integer_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}
