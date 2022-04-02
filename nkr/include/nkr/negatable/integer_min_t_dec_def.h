/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_5888ba5e_a674_4d39_b2ea_558f34aa804b
#define nkr_INCLUDE_GUARD_5888ba5e_a674_4d39_b2ea_558f34aa804b

#include "nkr/negatable/integer_min_t_dec.h"

namespace nkr { namespace negatable { namespace integer_min_t$ {

    template <nkr::cpp::is_any_tr<nkr::negatable::integer_min_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return
            nkr::negatable::integer_min_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::negatable::integer_min_tg>;
    }

    template <nkr::cpp::is_any_tr<nkr::negatable::integer_min_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}

#endif
