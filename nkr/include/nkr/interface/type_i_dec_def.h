/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_e89211f6_593a_452a_8159_9bc2412dfc0d
#define nkr_INCLUDE_GUARD_e89211f6_593a_452a_8159_9bc2412dfc0d

#include "nkr/interface/type_i_dec.h"

namespace nkr { namespace interface { namespace type_i$ {

    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        Is_Any_General()
        noexcept
    {
        return
            nkr::interface::type_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::interface::type_tg>;
    }

    template <nkr::interface::type_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::interface::type_i$::Is_Any_General<other_p>();
    }

    template <nkr::interface::type_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

    template <nkr::cpp::is_any_tr<nkr::interface::type_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::interface::type_i$::Is_Any_General<other_p>();
    }

    template <nkr::cpp::is_any_tr<nkr::interface::type_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}

#endif
