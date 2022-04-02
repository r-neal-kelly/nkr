/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_a826bccd_12c5_47f6_bf32_40f3dbff5c41
#define nkr_INCLUDE_GUARD_a826bccd_12c5_47f6_bf32_40f3dbff5c41

#include "nkr/constant/reference/lvalue_t_dec.h"

namespace nkr { namespace constant { namespace reference { namespace lvalue_t$ {

    template <nkr::cpp::is_any_tr<nkr::constant::reference::lvalue_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return
            nkr::constant::reference::lvalue_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::constant::reference::lvalue_tg>;
    }

    template <nkr::cpp::is_any_tr<nkr::constant::reference::lvalue_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}}

#endif
