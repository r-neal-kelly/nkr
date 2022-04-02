/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_02bb205b_1523_4a92_8c45_00ad157971f7
#define nkr_INCLUDE_GUARD_02bb205b_1523_4a92_8c45_00ad157971f7

#include "nkr/interface/template_i_dec.h"

namespace nkr { namespace interface { namespace template_i$ {

    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        Is_Any_General()
        noexcept
    {
        return
            nkr::interface::template_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::interface::template_tg>;
    }

    template <nkr::interface::template_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::interface::template_i$::Is_Any_General<other_p>();
    }

    template <nkr::interface::template_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

    template <nkr::cpp::is_any_tr<nkr::interface::template_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::interface::template_i$::Is_Any_General<other_p>();
    }

    template <nkr::cpp::is_any_tr<nkr::interface::template_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}

#endif
