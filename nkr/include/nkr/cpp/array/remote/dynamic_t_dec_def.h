/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/cpp/array/remote/dynamic_t_dec.h"

namespace nkr { namespace cpp { namespace array { namespace remote { namespace dynamic_t$ {

    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        Is_Any_General()
        noexcept
    {
        return
            nkr::cpp::array::remote::dynamic_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::cpp::array::remote::dynamic_tg>;
    }

    template <nkr::cpp::array::remote::dynamic_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::cpp::array::remote::dynamic_t$::Is_Any_General<other_p>();
    }

    template <nkr::cpp::array::remote::dynamic_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

    template <nkr::cpp::is_any_tr<nkr::cpp::array::remote::dynamic_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::cpp::array::remote::dynamic_t$::Is_Any_General<other_p>();
    }

    template <nkr::cpp::is_any_tr<nkr::cpp::array::remote::dynamic_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}}}
