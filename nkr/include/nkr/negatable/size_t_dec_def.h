/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_b81991c5_8b36_4123_8df8_a22cac8817a2
#define nkr_INCLUDE_GUARD_b81991c5_8b36_4123_8df8_a22cac8817a2

#include "nkr/negatable/size_t_dec.h"

namespace nkr { namespace negatable { namespace size_t$ {

    template <nkr::cpp::is_any_tr<nkr::negatable::size_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return
            nkr::negatable::size_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::negatable::size_tg>;
    }

    template <nkr::cpp::is_any_tr<nkr::negatable::size_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}

#endif
