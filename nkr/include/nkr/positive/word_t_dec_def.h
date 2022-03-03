/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/positive/word_t_dec.h"

namespace nkr { namespace positive { namespace $word_t {

    template <nkr::cpp::is_any_tr<nkr::positive::word_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::positive::word_tr<other_p>;
    }

    template <nkr::cpp::is_any_tr<nkr::positive::word_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}
