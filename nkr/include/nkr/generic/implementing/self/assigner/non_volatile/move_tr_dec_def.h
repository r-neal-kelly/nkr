/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_64134d30_9c74_4c1e_b1b2_556d3f75053f
#define nkr_INCLUDE_GUARD_64134d30_9c74_4c1e_b1b2_556d3f75053f

#include "nkr/generic/implementing/self/assigner/non_volatile/move_tr_dec.h"

namespace nkr { namespace generic { namespace implementing { namespace self { namespace assigner { namespace non_volatile { namespace move_tr$ {

    template <nkr::cpp::is_any_tr<nkr::generic::implementing::self::assigner::non_volatile::move_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return
            nkr::generic::implementing::self::assigner::non_volatile::move_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::generic::implementing::self::assigner::non_volatile::move_tg>;
    }

    template <nkr::cpp::is_any_tr<nkr::generic::implementing::self::assigner::non_volatile::move_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}}}}}

namespace nkr { namespace generic { namespace implementing { namespace self { namespace assigner { namespace non_volatile { namespace move_tr$ {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::generic::implementing::self::assigner::non_volatile::move_ttg>
    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i_tag_sp<template_p>::Is_Any()
        noexcept
    {
        return nkr::generic::implementing::self::assigner::non_volatile::move_ttr<other_p>;
    }

}}}}}}}

#endif
