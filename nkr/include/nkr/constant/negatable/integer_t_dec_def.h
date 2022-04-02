/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_49d5af37_e24e_425c_bf02_362657e7709d
#define nkr_INCLUDE_GUARD_49d5af37_e24e_425c_bf02_362657e7709d

#include "nkr/constant/negatable/integer_t_dec.h"

namespace nkr { namespace constant { namespace negatable { namespace integer_t$ {

    template <nkr::cpp::is_any_tr<nkr::constant::negatable::integer_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return
            nkr::constant::negatable::integer_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::constant::negatable::integer_tg>;
    }

    template <nkr::cpp::is_any_tr<nkr::constant::negatable::integer_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}}

#endif
