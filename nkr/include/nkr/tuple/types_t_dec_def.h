/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/tuple/types_t_dec.h"

namespace nkr { namespace tuple { namespace types_t$ {

    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        Is_Any_General()
        noexcept
    {
        return
            nkr::tuple::types_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::tuple::types_tg>;
    }

    template <nkr::tuple::types_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::tuple::types_t$::Is_Any_General<other_p>();
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
        return nkr::tuple::types_t$::Is_Any_General<other_p>();
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

namespace nkr { namespace tuple { namespace types_t$ {

    template <template <typename ...> typename template_p>
        requires nkr::tuple::types_ttr<template_p>
    inline constexpr nkr::positive::count_t
        template_i_template_sp<template_p>::Min_Argument_Count()
        noexcept
    {
        return nkr::positive::count_t(0);
    }

    template <template <typename ...> typename template_p>
        requires nkr::tuple::types_ttr<template_p>
    inline constexpr nkr::positive::count_t
        template_i_template_sp<template_p>::Max_Argument_Count()
        noexcept
    {
        return nkr::positive::count_t(~0);
    }

    template <template <typename ...> typename template_p>
        requires nkr::tuple::types_ttr<template_p>
    inline constexpr nkr::positive::count_t
        template_i_template_sp<template_p>::Actual_Min_Argument_Count()
        noexcept
    {
        return Min_Argument_Count();
    }

    template <template <typename ...> typename template_p>
        requires nkr::tuple::types_ttr<template_p>
    inline constexpr nkr::positive::count_t
        template_i_template_sp<template_p>::Actual_Max_Argument_Count()
        noexcept
    {
        return Max_Argument_Count();
    }

    template <template <typename ...> typename template_p>
        requires nkr::tuple::types_ttr<template_p>
    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i_template_sp<template_p>::Is_Any()
        noexcept
    {
        return nkr::tuple::types_ttr<other_p>;
    }

    template <template <typename ...> typename template_p>
        requires nkr::tuple::types_ttr<template_p>
    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i_template_sp<template_p>::Is_Any_Actual()
        noexcept
    {
        return nkr::tuple::types_ttr<other_p>;
    }

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::tuple::types_ttg>
    inline constexpr nkr::positive::count_t
        template_i_tag_sp<template_p>::Actual_Min_Argument_Count()
        noexcept
    {
        return nkr::positive::count_t(0);
    }

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::tuple::types_ttg>
    inline constexpr nkr::positive::count_t
        template_i_tag_sp<template_p>::Actual_Max_Argument_Count()
        noexcept
    {
        return nkr::positive::count_t(~0);
    }

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::tuple::types_ttg>
    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i_tag_sp<template_p>::Is_Any_Actual()
        noexcept
    {
        return nkr::cpp::is_any_ttr<other_p, actual_template_t>;
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

    template <typename ...types_p>
    template <typename iterator_p>
    inline constexpr nkr::none::type_t
        types_t<types_p...>::Iterate_Forward()
        noexcept
    {
        return;
    }

    template <typename ...types_p>
    inline constexpr nkr::none::type_t
        types_t<types_p...>::Iterate_Forward(auto& iterator)
        noexcept
    {
        return;
    }

    template <typename ...types_p>
    template <typename algorithm_p>
    inline constexpr nkr::boolean::cpp_t
        types_t<types_p...>::AND()
        noexcept
    {
        return true;
    }

    template <typename ...types_p>
    inline constexpr nkr::boolean::cpp_t
        types_t<types_p...>::AND(auto& algorithm)
        noexcept
    {
        return true;
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

    template <typename head_p, typename ...tail_p>
    template <typename iterator_p>
    inline constexpr nkr::none::type_t
        types_t<head_p, tail_p...>::Iterate_Forward()
        noexcept
    {
        iterator_p iterator;
        Iterate_Forward(iterator);
    }

    template <typename head_p, typename ...tail_p>
    inline constexpr nkr::none::type_t
        types_t<head_p, tail_p...>::Iterate_Forward(auto& iterator)
        noexcept
    {
        iterator.template operator ()<head_p>();
        tail_t::Iterate_Forward(iterator);
    }

    template <typename head_p, typename ...tail_p>
    template <typename algorithm_p>
    inline constexpr nkr::boolean::cpp_t
        types_t<head_p, tail_p...>::AND()
        noexcept
    {
        algorithm_p algorithm;

        return AND(algorithm);
    }

    template <typename head_p, typename ...tail_p>
    inline constexpr nkr::boolean::cpp_t
        types_t<head_p, tail_p...>::AND(auto& algorithm)
        noexcept
    {
        if (algorithm.template operator ()<head_p>()) {
            return tail_t::AND(algorithm);
        } else {
            return false;
        }
    }

}}
