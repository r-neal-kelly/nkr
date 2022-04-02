/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_a7068075_7f6a_4e7f_8461_9429594f891d
#define nkr_INCLUDE_GUARD_a7068075_7f6a_4e7f_8461_9429594f891d

#include "nkr/constant/negatable/integer_min_t_dec.h"

namespace nkr { namespace constant { namespace negatable { namespace integer_min_t$ {

    template <nkr::cpp::is_any_tr<nkr::constant::negatable::integer_min_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return
            nkr::constant::negatable::integer_min_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::constant::negatable::integer_min_tg>;
    }

    template <nkr::cpp::is_any_tr<nkr::constant::negatable::integer_min_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}}

#endif
