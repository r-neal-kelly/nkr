/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_65d4e1c4_1e32_4035_9c9e_4729942d831f
#define nkr_INCLUDE_GUARD_65d4e1c4_1e32_4035_9c9e_4729942d831f

#include "nkr/cpp/list/remote/forward_t_dec.h"

namespace nkr { namespace cpp { namespace list { namespace remote { namespace forward_t$ {

    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        Is_Any_General()
        noexcept
    {
        return
            nkr::cpp::list::remote::forward_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::cpp::list::remote::forward_tg>;
    }

    template <nkr::cpp::list::remote::forward_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::cpp::list::remote::forward_t$::Is_Any_General<other_p>();
    }

    template <nkr::cpp::list::remote::forward_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

    template <nkr::cpp::is_any_tr<nkr::cpp::list::remote::forward_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::cpp::list::remote::forward_t$::Is_Any_General<other_p>();
    }

    template <nkr::cpp::is_any_tr<nkr::cpp::list::remote::forward_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}}}

#endif
