/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_f6e8b16a_6ce1_4b4a_a4a4_45e3f48b5529
#define nkr_INCLUDE_GUARD_f6e8b16a_6ce1_4b4a_a4a4_45e3f48b5529

#include "nkr/constant/negatable/integer_64_t_dec.h"

namespace nkr { namespace constant { namespace negatable { namespace integer_64_t$ {

    template <nkr::cpp::is_any_tr<nkr::constant::negatable::integer_64_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return
            nkr::constant::negatable::integer_64_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::constant::negatable::integer_64_tg>;
    }

    template <nkr::cpp::is_any_tr<nkr::constant::negatable::integer_64_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}}

#endif
