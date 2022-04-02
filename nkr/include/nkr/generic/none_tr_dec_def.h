/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_44dcab77_2003_403e_8265_98c278acf108
#define nkr_INCLUDE_GUARD_44dcab77_2003_403e_8265_98c278acf108

#include "nkr/generic/none_tr_dec.h"

namespace nkr { namespace generic { namespace none_tr$ {

    template <nkr::cpp::is_any_tr<nkr::generic::none_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return
            nkr::generic::none_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::generic::none_tg>;
    }

    template <nkr::cpp::is_any_tr<nkr::generic::none_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}

namespace nkr { namespace generic { namespace none_tr$ {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::generic::none_ttg>
    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i_tag_sp<template_p>::Is_Any()
        noexcept
    {
        return nkr::generic::none_ttr<other_p>;
    }

}}}

#endif
