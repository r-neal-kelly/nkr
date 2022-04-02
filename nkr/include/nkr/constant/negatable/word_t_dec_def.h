/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_846d58ee_d7b0_44ba_bfaa_0688072f95f1
#define nkr_INCLUDE_GUARD_846d58ee_d7b0_44ba_bfaa_0688072f95f1

#include "nkr/constant/negatable/word_t_dec.h"

namespace nkr { namespace constant { namespace negatable { namespace word_t$ {

    template <nkr::cpp::is_any_tr<nkr::constant::negatable::word_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return
            nkr::constant::negatable::word_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::constant::negatable::word_tg>;
    }

    template <nkr::cpp::is_any_tr<nkr::constant::negatable::word_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}}

#endif
