/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_f2509540_2fdd_44db_b217_e39543880a6d
#define nkr_INCLUDE_GUARD_f2509540_2fdd_44db_b217_e39543880a6d

#include "nkr/constant/negatable/integer_32_t_dec.h"

namespace nkr { namespace constant { namespace negatable { namespace integer_32_t$ {

    template <nkr::cpp::is_any_tr<nkr::constant::negatable::integer_32_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return
            nkr::constant::negatable::integer_32_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::constant::negatable::integer_32_tg>;
    }

    template <nkr::cpp::is_any_tr<nkr::constant::negatable::integer_32_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}}

#endif
