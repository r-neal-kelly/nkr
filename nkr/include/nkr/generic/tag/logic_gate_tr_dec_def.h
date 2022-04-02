/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_f37a7dc9_0a91_4904_b260_3fdcaa091912
#define nkr_INCLUDE_GUARD_f37a7dc9_0a91_4904_b260_3fdcaa091912

#include "nkr/generic/tag/logic_gate_tr_dec.h"

namespace nkr { namespace generic { namespace tag { namespace logic_gate_tr$ {

    template <nkr::cpp::is_any_tr<nkr::generic::tag::logic_gate_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return
            nkr::generic::tag::logic_gate_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::generic::tag::logic_gate_tg>;
    }

    template <nkr::cpp::is_any_tr<nkr::generic::tag::logic_gate_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}}

namespace nkr { namespace generic { namespace tag { namespace logic_gate_tr$ {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::generic::tag::logic_gate_ttg>
    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i_tag_sp<template_p>::Is_Any()
        noexcept
    {
        return nkr::generic::tag::logic_gate_ttr<other_p>;
    }

}}}}

#endif
