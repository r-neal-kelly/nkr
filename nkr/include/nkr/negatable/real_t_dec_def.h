/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_5d173259_c039_4e23_af3a_0343cadb238f
#define nkr_INCLUDE_GUARD_5d173259_c039_4e23_af3a_0343cadb238f

#include "nkr/negatable/real_t_dec.h"

namespace nkr { namespace negatable { namespace real_t$ {

    template <nkr::cpp::is_any_tr<nkr::negatable::real_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return
            nkr::negatable::real_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::negatable::real_tg>;
    }

    template <nkr::cpp::is_any_tr<nkr::negatable::real_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}

#endif
