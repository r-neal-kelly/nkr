/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_e8de8d7d_bd0e_47e7_b410_870671b5bd8d
#define nkr_INCLUDE_GUARD_e8de8d7d_bd0e_47e7_b410_870671b5bd8d

#include "nkr/generic/implementing/label/none_tr_dec.h"

namespace nkr { namespace generic { namespace implementing { namespace label { namespace none_tr$ {

    template <nkr::cpp::is_any_tr<nkr::generic::implementing::label::none_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return
            nkr::generic::implementing::label::none_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::generic::implementing::label::none_tg>;
    }

    template <nkr::cpp::is_any_tr<nkr::generic::implementing::label::none_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}}}

namespace nkr { namespace generic { namespace implementing { namespace label { namespace none_tr$ {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::generic::implementing::label::none_ttg>
    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i_tag_sp<template_p>::Is_Any()
        noexcept
    {
        return nkr::generic::implementing::label::none_ttr<other_p>;
    }

}}}}}

#endif
