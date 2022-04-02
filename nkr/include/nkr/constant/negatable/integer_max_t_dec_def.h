/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_235d9674_2507_496d_a7f9_70f8bf85290d
#define nkr_INCLUDE_GUARD_235d9674_2507_496d_a7f9_70f8bf85290d

#include "nkr/constant/negatable/integer_max_t_dec.h"

namespace nkr { namespace constant { namespace negatable { namespace integer_max_t$ {

    template <nkr::cpp::is_any_tr<nkr::constant::negatable::integer_max_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return
            nkr::constant::negatable::integer_max_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::constant::negatable::integer_max_tg>;
    }

    template <nkr::cpp::is_any_tr<nkr::constant::negatable::integer_max_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}}

#endif
