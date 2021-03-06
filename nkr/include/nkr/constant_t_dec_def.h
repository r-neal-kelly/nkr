/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_e4d1dce6_26d0_47c7_a6ec_c1264f998d45
#define nkr_INCLUDE_GUARD_e4d1dce6_26d0_47c7_a6ec_c1264f998d45

#include "nkr/constant_t_dec.h"

namespace nkr { namespace constant_t$ {

    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        Is_Any_General()
        noexcept
    {
        return
            nkr::constant_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::constant_tg>;
    }

    template <nkr::constant_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::constant_t$::Is_Any_General<other_p>();
    }

    template <nkr::constant_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

    template <nkr::cpp::is_any_tr<nkr::constant_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::constant_t$::Is_Any_General<other_p>();
    }

    template <nkr::cpp::is_any_tr<nkr::constant_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}

namespace nkr { namespace constant_t$ {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::constant_ttg>
    inline constexpr nkr::positive::count_t
        template_i_tag_sp<template_p>::Min_Argument_Count()
        noexcept
    {
        return nkr::positive::count_t(1);
    }

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::constant_ttg>
    inline constexpr nkr::positive::count_t
        template_i_tag_sp<template_p>::Max_Argument_Count()
        noexcept
    {
        return nkr::positive::count_t(1);
    }

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::constant_ttg>
    inline constexpr nkr::positive::count_t
        template_i_tag_sp<template_p>::Actual_Min_Argument_Count()
        noexcept
    {
        return nkr::positive::count_t(0);
    }

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::constant_ttg>
    inline constexpr nkr::positive::count_t
        template_i_tag_sp<template_p>::Actual_Max_Argument_Count()
        noexcept
    {
        return nkr::positive::count_t(~0);
    }

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::constant_ttg>
    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i_tag_sp<template_p>::Is_Any()
        noexcept
    {
        return false;
    }

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::constant_ttg>
    template <template <typename inner_p, inner_p> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i_tag_sp<template_p>::Is_Any()
        noexcept
    {
        return nkr::constant_ttr<other_p>;
    }

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::constant_ttg>
    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i_tag_sp<template_p>::Is_Any_Actual()
        noexcept
    {
        return nkr::cpp::is_any_ttr<other_p, actual_template_t>;
    }

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::constant_ttg>
    template <template <typename inner_p, inner_p> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i_tag_sp<template_p>::Is_Any_Actual()
        noexcept
    {
        return false;
    }

}}

namespace nkr {

    template <nkr::cpp::type_tr type_p, type_p value_p>
    inline constexpr typename constant_t<type_p, value_p>::value_t
        constant_t<type_p, value_p>::Value()
        noexcept
    {
        return value_p;
    }

    template <nkr::cpp::type_tr type_p, type_p value_p>
    inline constexpr constant_t<type_p, value_p>::constant_t() noexcept
    {
    }

    template <nkr::cpp::type_tr type_p, type_p value_p>
    inline constexpr constant_t<type_p, value_p>::constant_t(const constant_t& other) noexcept
    {
    }

    template <nkr::cpp::type_tr type_p, type_p value_p>
    inline constexpr constant_t<type_p, value_p>::constant_t(const volatile constant_t& other) noexcept
    {
    }

    template <nkr::cpp::type_tr type_p, type_p value_p>
    inline constexpr constant_t<type_p, value_p>::constant_t(constant_t&& other) noexcept
    {
    }

    template <nkr::cpp::type_tr type_p, type_p value_p>
    inline constexpr constant_t<type_p, value_p>::constant_t(volatile constant_t&& other) noexcept
    {
    }

    template <nkr::cpp::type_tr type_p, type_p value_p>
    inline constexpr constant_t<type_p, value_p>::operator nkr::constant_t<type_p, value_p>::value_t()
        const noexcept
    {
        return Value();
    }

    template <nkr::cpp::type_tr type_p, type_p value_p>
    inline constexpr constant_t<type_p, value_p>::operator nkr::constant_t<type_p, value_p>::value_t()
        const volatile noexcept
    {
        return Value();
    }

    template <nkr::cpp::type_tr type_p, type_p value_p>
    inline constexpr typename constant_t<type_p, value_p>::value_t
        constant_t<type_p, value_p>::operator ()()
        const noexcept
    {
        return Value();
    }

    template <nkr::cpp::type_tr type_p, type_p value_p>
    inline constexpr typename constant_t<type_p, value_p>::value_t
        constant_t<type_p, value_p>::operator ()()
        const volatile noexcept
    {
        return Value();
    }

}

#endif
