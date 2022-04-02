/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_7fc0fd8e_0bf5_4c94_a153_282127c65684
#define nkr_INCLUDE_GUARD_7fc0fd8e_0bf5_4c94_a153_282127c65684

#include "nkr/negatable/real_min_t_dec.h"

namespace nkr { namespace negatable { namespace real_min_t$ {

    template <nkr::cpp::is_any_tr<nkr::negatable::real_min_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return
            nkr::negatable::real_min_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::negatable::real_min_tg>;
    }

    template <nkr::cpp::is_any_tr<nkr::negatable::real_min_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}

#endif
