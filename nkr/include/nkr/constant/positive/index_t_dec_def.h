/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/constant/positive/index_t_dec.h"

namespace nkr { namespace constant { namespace positive { namespace index_t$ {

    template <nkr::cpp::is_any_tr<nkr::constant::positive::index_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return
            nkr::constant::positive::index_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::constant::positive::index_tg>;
    }

    template <nkr::cpp::is_any_tr<nkr::constant::positive::index_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}}
