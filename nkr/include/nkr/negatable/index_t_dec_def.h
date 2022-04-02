/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_c5b5b99f_f90a_49f8_82e3_c7b79ca00b98
#define nkr_INCLUDE_GUARD_c5b5b99f_f90a_49f8_82e3_c7b79ca00b98

#include "nkr/negatable/index_t_dec.h"

namespace nkr { namespace negatable { namespace index_t$ {

    template <nkr::cpp::is_any_tr<nkr::negatable::index_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return
            nkr::negatable::index_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::negatable::index_tg>;
    }

    template <nkr::cpp::is_any_tr<nkr::negatable::index_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}

#endif
