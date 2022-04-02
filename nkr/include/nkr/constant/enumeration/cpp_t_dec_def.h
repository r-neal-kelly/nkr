/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_c255dbf3_d7b5_4c20_8658_9fb6cd1b69a1
#define nkr_INCLUDE_GUARD_c255dbf3_d7b5_4c20_8658_9fb6cd1b69a1

#include "nkr/constant/enumeration/cpp_t_dec.h"

namespace nkr { namespace constant { namespace enumeration { namespace cpp_t$ {

    template <nkr::cpp::is_any_tr<nkr::constant::enumeration::cpp_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return
            nkr::constant::enumeration::cpp_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::constant::enumeration::cpp_tg>;
    }

    template <nkr::cpp::is_any_tr<nkr::constant::enumeration::cpp_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}}

#endif
