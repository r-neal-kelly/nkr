/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/interface/enumeration/types_i_dec.h"

namespace nkr { namespace interface { namespace enumeration { namespace $types_i {

    template <nkr::cpp::is_any_tr<example_t> type_p>
    inline constexpr example_types_i_sp<type_p>::integer_t
        example_types_i_sp<type_p>::Default_Integer()
        noexcept
    {
        return value_t(~0);
    }

    template <nkr::cpp::is_any_tr<example_t> type_p>
    inline constexpr example_types_i_sp<type_p>::integer_t
        example_types_i_sp<type_p>::Integer(const tr<any_tg, t<value_t>> auto& value)
        noexcept
    {
        return static_cast<integer_t>(value);
    }

    template <nkr::cpp::is_any_tr<example_t> type_p>
    inline constexpr nkr::none::type_t
        example_types_i_sp<type_p>::Integer(tr<any_non_const_tg, t<value_t>> auto& value, integer_t integer)
        noexcept
    {
        value = static_cast<value_t>(integer);
    }

}}}}

namespace nkr { namespace interface { namespace enumeration { namespace $types_i {

    template <nkr::interface::enumeration::types_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::interface::enumeration::types_tr<other_p>;
    }

    template <nkr::interface::enumeration::types_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

    template <nkr::cpp::is_any_tr<nkr::interface::enumeration::types_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::interface::enumeration::types_tr<other_p>;
    }

    template <nkr::cpp::is_any_tr<nkr::interface::enumeration::types_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}}

namespace nkr { namespace interface { namespace enumeration { namespace $types_i {

    template <template <typename ...> typename template_p>
        requires nkr::interface::enumeration::types_ttr<template_p>
    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i_template_sp<nkr::interface::enumeration::types_ttg>::Is_Any()
        noexcept
    {
        return nkr::interface::enumeration::types_ttr<other_p>;
    }

}}}}
