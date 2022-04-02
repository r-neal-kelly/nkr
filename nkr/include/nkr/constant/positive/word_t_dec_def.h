/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_5b663f52_b117_48b4_9aaa_1e240e6a855f
#define nkr_INCLUDE_GUARD_5b663f52_b117_48b4_9aaa_1e240e6a855f

#include "nkr/constant/positive/word_t_dec.h"

namespace nkr { namespace constant { namespace positive { namespace word_t$ {

    template <nkr::cpp::is_any_tr<nkr::constant::positive::word_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return
            nkr::constant::positive::word_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::constant::positive::word_tg>;
    }

    template <nkr::cpp::is_any_tr<nkr::constant::positive::word_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}}

#endif
