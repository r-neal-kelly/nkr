/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/tuple/types_t_dec.h"

namespace nkr { namespace tuple { namespace $types_t {

    template <nkr::tuple::types_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::tuple::types_tr<other_p>;
    }

    template <nkr::tuple::types_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

    template <nkr::cpp::is_any_tr<nkr::tuple::types_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::tuple::types_tr<other_p>;
    }

    template <nkr::cpp::is_any_tr<nkr::tuple::types_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}

namespace nkr { namespace tuple { namespace $types_t {

    template <template <typename ...> typename template_p>
        requires nkr::tuple::types_ttr<template_p>
    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i_template_sp<template_p>::Is_Any()
        noexcept
    {
        return nkr::tuple::types_ttr<other_p>;
    }

}}}

namespace nkr { namespace tuple {

    template <typename ...types_p>
    inline constexpr nkr::positive::count_t
        types_t<types_p...>::Count()
        noexcept
    {
        return 0;
    }

}}

namespace nkr { namespace tuple {

    template <typename head_p, typename ...tail_p>
    inline constexpr nkr::positive::count_t
        types_t<head_p, tail_p...>::Count()
        noexcept
    {
        return 1 + sizeof...(tail_p);
    }

}}
