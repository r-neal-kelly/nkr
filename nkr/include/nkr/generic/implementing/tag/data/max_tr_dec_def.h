/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_3c8663fc_a6ba_4f73_8f4f_48f1bd8a41cb
#define nkr_INCLUDE_GUARD_3c8663fc_a6ba_4f73_8f4f_48f1bd8a41cb

#include "nkr/generic/implementing/tag/data/max_tr_dec.h"

namespace nkr { namespace generic { namespace implementing { namespace tag { namespace data { namespace max_tr$ {

    template <nkr::cpp::is_any_tr<nkr::generic::implementing::tag::data::max_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return
            nkr::generic::implementing::tag::data::max_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::generic::implementing::tag::data::max_tg>;
    }

    template <nkr::cpp::is_any_tr<nkr::generic::implementing::tag::data::max_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}}}}

namespace nkr { namespace generic { namespace implementing { namespace tag { namespace data { namespace max_tr$ {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::generic::implementing::tag::data::max_ttg>
    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i_tag_sp<template_p>::Is_Any()
        noexcept
    {
        return nkr::generic::implementing::tag::data::max_ttr<other_p>;
    }

}}}}}}

#endif
