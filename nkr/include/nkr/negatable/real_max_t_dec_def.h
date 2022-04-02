/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_3336f615_f98e_4de2_8082_36db49ea5fba
#define nkr_INCLUDE_GUARD_3336f615_f98e_4de2_8082_36db49ea5fba

#include "nkr/negatable/real_max_t_dec.h"

namespace nkr { namespace negatable { namespace real_max_t$ {

    template <nkr::cpp::is_any_tr<nkr::negatable::real_max_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return
            nkr::negatable::real_max_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::negatable::real_max_tg>;
    }

    template <nkr::cpp::is_any_tr<nkr::negatable::real_max_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}

#endif
