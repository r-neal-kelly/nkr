/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_4749d08d_88b2_4454_b8c8_818d3eae93ec
#define nkr_INCLUDE_GUARD_4749d08d_88b2_4454_b8c8_818d3eae93ec

#include "nkr/constant/negatable/count_t_dec.h"

namespace nkr { namespace constant { namespace negatable { namespace count_t$ {

    template <nkr::cpp::is_any_tr<nkr::constant::negatable::count_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return
            nkr::constant::negatable::count_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::constant::negatable::count_tg>;
    }

    template <nkr::cpp::is_any_tr<nkr::constant::negatable::count_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}}

#endif
