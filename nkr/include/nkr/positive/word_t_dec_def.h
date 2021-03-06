/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_0ed75c20_790b_449a_a87d_8005965e1370
#define nkr_INCLUDE_GUARD_0ed75c20_790b_449a_a87d_8005965e1370

#include "nkr/positive/word_t_dec.h"

namespace nkr { namespace positive { namespace word_t$ {

    template <nkr::cpp::is_any_tr<nkr::positive::word_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return
            nkr::positive::word_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::positive::word_tg>;
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

#endif
