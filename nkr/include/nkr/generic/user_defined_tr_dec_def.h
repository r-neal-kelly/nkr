/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_ee4c7887_5c96_4483_abeb_d194e7d68168
#define nkr_INCLUDE_GUARD_ee4c7887_5c96_4483_abeb_d194e7d68168

#include "nkr/generic/user_defined_tr_dec.h"

namespace nkr { namespace generic { namespace user_defined_tr$ {

    template <nkr::cpp::is_any_tr<nkr::generic::user_defined_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return
            nkr::generic::user_defined_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::generic::user_defined_tg>;
    }

    template <nkr::cpp::is_any_tr<nkr::generic::user_defined_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}

namespace nkr { namespace generic { namespace user_defined_tr$ {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::generic::user_defined_ttg>
    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i_tag_sp<template_p>::Is_Any()
        noexcept
    {
        return nkr::generic::user_defined_ttr<other_p>;
    }

}}}

#endif
