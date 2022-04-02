/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_cf1c6fab_77ee_49a9_a500_9774f2d50a49
#define nkr_INCLUDE_GUARD_cf1c6fab_77ee_49a9_a500_9774f2d50a49

#include "nkr/generic/implementing/self/constructor/move_tr_dec.h"

namespace nkr { namespace generic { namespace implementing { namespace self { namespace constructor { namespace move_tr$ {

    template <nkr::cpp::is_any_tr<nkr::generic::implementing::self::constructor::move_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return
            nkr::generic::implementing::self::constructor::move_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::generic::implementing::self::constructor::move_tg>;
    }

    template <nkr::cpp::is_any_tr<nkr::generic::implementing::self::constructor::move_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}}}}

namespace nkr { namespace generic { namespace implementing { namespace self { namespace constructor { namespace move_tr$ {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::generic::implementing::self::constructor::move_ttg>
    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i_tag_sp<template_p>::Is_Any()
        noexcept
    {
        return nkr::generic::implementing::self::constructor::move_ttr<other_p>;
    }

}}}}}}

#endif
