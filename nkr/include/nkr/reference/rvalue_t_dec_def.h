/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_02d02763_0cb9_4faa_9a54_2d38311f6876
#define nkr_INCLUDE_GUARD_02d02763_0cb9_4faa_9a54_2d38311f6876

#include "nkr/reference/rvalue_t_dec.h"

namespace nkr { namespace reference { namespace rvalue_t$ {

    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        Is_Any_General()
        noexcept
    {
        return
            nkr::reference::rvalue_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::reference::rvalue_tg>;
    }

    template <nkr::reference::rvalue_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::reference::rvalue_t$::Is_Any_General<other_p>();
    }

    template <nkr::reference::rvalue_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

    template <nkr::cpp::is_any_tr<nkr::reference::rvalue_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::reference::rvalue_t$::Is_Any_General<other_p>();
    }

    template <nkr::cpp::is_any_tr<nkr::reference::rvalue_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}

#endif
