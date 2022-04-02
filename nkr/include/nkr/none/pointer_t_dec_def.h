/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_875f905c_9df0_43e3_bf1e_3336574af96a
#define nkr_INCLUDE_GUARD_875f905c_9df0_43e3_bf1e_3336574af96a

#include "nkr/none/pointer_t_dec.h"

namespace nkr { namespace none { namespace pointer_t$ {

    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        Is_Any_General()
        noexcept
    {
        return
            nkr::none::pointer_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::none::pointer_tg>;
    }

    template <nkr::none::pointer_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::none::pointer_t$::Is_Any_General<other_p>();
    }

    template <nkr::none::pointer_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

    template <nkr::cpp::is_any_tr<nkr::none::pointer_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::none::pointer_t$::Is_Any_General<other_p>();
    }

    template <nkr::cpp::is_any_tr<nkr::none::pointer_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}

#endif
