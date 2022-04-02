/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_7c30f4a5_e64d_4c6c_98e3_355ce97eabde
#define nkr_INCLUDE_GUARD_7c30f4a5_e64d_4c6c_98e3_355ce97eabde

#include "nkr/negatable/integer_max_t_dec.h"

namespace nkr { namespace negatable { namespace integer_max_t$ {

    template <nkr::cpp::is_any_tr<nkr::negatable::integer_max_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return
            nkr::negatable::integer_max_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::negatable::integer_max_tg>;
    }

    template <nkr::cpp::is_any_tr<nkr::negatable::integer_max_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}

#endif
