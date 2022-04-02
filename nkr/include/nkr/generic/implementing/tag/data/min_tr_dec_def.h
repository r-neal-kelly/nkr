/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_5d8e5926_442b_4fe0_baf6_1d441f1dbb07
#define nkr_INCLUDE_GUARD_5d8e5926_442b_4fe0_baf6_1d441f1dbb07

#include "nkr/generic/implementing/tag/data/min_tr_dec.h"

namespace nkr { namespace generic { namespace implementing { namespace tag { namespace data { namespace min_tr$ {

    template <nkr::cpp::is_any_tr<nkr::generic::implementing::tag::data::min_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return
            nkr::generic::implementing::tag::data::min_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::generic::implementing::tag::data::min_tg>;
    }

    template <nkr::cpp::is_any_tr<nkr::generic::implementing::tag::data::min_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}}}}

namespace nkr { namespace generic { namespace implementing { namespace tag { namespace data { namespace min_tr$ {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::generic::implementing::tag::data::min_ttg>
    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i_tag_sp<template_p>::Is_Any()
        noexcept
    {
        return nkr::generic::implementing::tag::data::min_ttr<other_p>;
    }

}}}}}}

#endif
