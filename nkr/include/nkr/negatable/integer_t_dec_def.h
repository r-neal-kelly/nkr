/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_854b56ae_3221_4c68_9c78_f6a986e6858a
#define nkr_INCLUDE_GUARD_854b56ae_3221_4c68_9c78_f6a986e6858a

#include "nkr/negatable/integer_t_dec.h"

namespace nkr { namespace negatable { namespace integer_t$ {

    template <nkr::cpp::is_any_tr<nkr::negatable::integer_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return
            nkr::negatable::integer_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::negatable::integer_tg>;
    }

    template <nkr::cpp::is_any_tr<nkr::negatable::integer_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}

#endif
