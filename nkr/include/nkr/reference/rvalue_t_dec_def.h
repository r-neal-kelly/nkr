/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/reference/rvalue_t_dec.h"

namespace nkr { namespace reference { namespace $rvalue_t {

    template <nkr::reference::rvalue_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::reference::rvalue_tr<other_p>;
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
        return nkr::reference::rvalue_tr<other_p>;
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

namespace nkr { namespace interface {

    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i<nkr::reference::rvalue_ttg>::Is_Any()
        noexcept
    {
        return nkr::reference::rvalue_ttr<other_p>;
    }

}}
