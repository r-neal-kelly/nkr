/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_cad4c4ee_e465_4dfb_8530_920f29943d59
#define nkr_INCLUDE_GUARD_cad4c4ee_e465_4dfb_8530_920f29943d59

#include "nkr/constant/negatable/size_t_dec.h"

namespace nkr { namespace constant { namespace negatable { namespace size_t$ {

    template <nkr::cpp::is_any_tr<nkr::constant::negatable::size_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return
            nkr::constant::negatable::size_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::constant::negatable::size_tg>;
    }

    template <nkr::cpp::is_any_tr<nkr::constant::negatable::size_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}}

#endif
