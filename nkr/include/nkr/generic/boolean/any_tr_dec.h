/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsics_dec.h"

namespace nkr { namespace generic { namespace boolean { namespace $any_tr {

    template <typename type_p>
    concept static_constexpr_methods_i = requires
    {
        { type_p::Is_Boolean_Type() }   -> cpp::is_any_tr<nkr::boolean::cpp_t>;
    };

    template <typename type_p>
    concept operators_i = requires(cpp::just_non_qualified_t<type_p> type,
                                   cpp::just_const_t<type_p> const_type,
                                   cpp::just_volatile_t<type_p> volatile_type,
                                   cpp::just_const_volatile_t<type_p> const_volatile_type)
    {
        true;

        /*{ type == true };
        { const_type == true };
        { volatile_type == true };
        { const_volatile_type == true };

        { type != true };
        { const_type != true };
        { volatile_type != true };
        { const_volatile_type != true };*/
    };

}}}}

namespace nkr { namespace generic { namespace boolean {

    struct  any_tg  {};

    template <typename>
    struct  any_ttg {};

    template <typename type_p>
    concept any_tr =
        cpp::is_any_tr<type_p, nkr::boolean::cpp_t> ||
        ($any_tr::static_constexpr_methods_i<type_p> &&
         $any_tr::operators_i<type_p> &&
         type_p::Is_Boolean_Type());

    template <template <typename ...> typename template_p>
    concept any_ttr =
        any_tr<typename interface::template_i<template_p>::example_t>;

}}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::generic::boolean::any_tg>
    {
    public:
        using type_t    = nkr::generic::boolean::any_tg;
        using of_t      = nkr::none::type_t;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr type_i(...) noexcept  = delete;
    };

}}

namespace nkr { namespace interface {

    template <>
    class template_i<nkr::generic::boolean::any_ttg>
    {
    public:
        template <typename inner_p>
        using of_t      = nkr::generic::boolean::any_tg;
        using example_t = nkr::generic::boolean::any_tg;

    public:
        template <template <typename ...> typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr template_i(...) noexcept  = delete;
    };

}}

#include "nkr/generic/boolean/any_tr_dec_def.h"
