/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_37088a83_1065_4b84_9014_183cb27bdff0
#define nkr_INCLUDE_GUARD_37088a83_1065_4b84_9014_183cb27bdff0

#include "nkr/negatable/byte_t_dec.h"

namespace nkr { namespace negatable { namespace byte_t$ {

    template <nkr::cpp::is_any_tr<nkr::negatable::byte_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return
            nkr::negatable::byte_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::negatable::byte_tg>;
    }

    template <nkr::cpp::is_any_tr<nkr::negatable::byte_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}

#endif
