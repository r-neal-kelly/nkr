/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_def82e17_cffc_4cc9_93db_86851c9d6f90
#define nkr_INCLUDE_GUARD_def82e17_cffc_4cc9_93db_86851c9d6f90

#include "nkr/generic/number_tr_dec.h"

namespace nkr { namespace generic { namespace number_tr$ {

    template <nkr::cpp::is_any_tr<nkr::generic::number_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return
            nkr::generic::number_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::generic::number_tg>;
    }

    template <nkr::cpp::is_any_tr<nkr::generic::number_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}

namespace nkr { namespace generic { namespace number_tr$ {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::generic::number_ttg>
    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i_tag_sp<template_p>::Is_Any()
        noexcept
    {
        return nkr::generic::number_ttr<other_p>;
    }

}}}

#endif
