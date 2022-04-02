/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_18ae3c44_c60b_49df_b624_345d2b8d9062
#define nkr_INCLUDE_GUARD_18ae3c44_c60b_49df_b624_345d2b8d9062

#include "nkr/constant/pointer/cpp_t_dec.h"

namespace nkr { namespace constant { namespace pointer { namespace cpp_t$ {

    template <nkr::cpp::is_any_tr<nkr::constant::pointer::cpp_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return
            nkr::constant::pointer::cpp_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::constant::pointer::cpp_tg>;
    }

    template <nkr::cpp::is_any_tr<nkr::constant::pointer::cpp_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}}

#endif
