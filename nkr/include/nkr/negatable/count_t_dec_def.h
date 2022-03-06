/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/negatable/count_t_dec.h"

namespace nkr { namespace negatable { namespace count_t$ {

    template <nkr::cpp::is_any_tr<nkr::negatable::count_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::negatable::count_tr<other_p>;
    }

    template <nkr::cpp::is_any_tr<nkr::negatable::count_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}
