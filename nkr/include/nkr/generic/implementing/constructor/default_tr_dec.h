/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/built_ins_dec.h"

namespace nkr { namespace generic { namespace implementing { namespace constructor { namespace $default_tr {

    template <typename type_p>
    concept constructors_i = requires
    {
        { cpp::just_non_qualified_t<type_p>() };
    };

}}}}}

namespace nkr { namespace generic { namespace implementing { namespace constructor {

    struct  default_tg  {};

    template <typename>
    struct  default_ttg {};

    template <typename type_p>
    concept default_tr =
        $default_tr::constructors_i<type_p>;

    template <template <typename ...> typename template_p>
    concept default_ttr =
        default_tr<typename interface::template_i<template_p>::example_t>;

}}}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::generic::implementing::constructor::default_tg>
    {
    public:
        using type_t    = nkr::generic::implementing::constructor::default_tg;
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
    class template_i<nkr::generic::implementing::constructor::default_ttg>
    {
    public:
        template <typename inner_p>
        using of_t      = nkr::generic::implementing::constructor::default_tg;
        using example_t = nkr::generic::implementing::constructor::default_tg;

    public:
        template <template <typename ...> typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr template_i(...) noexcept  = delete;
    };

}}

#include "nkr/generic/implementing/constructor/default_tr_dec_def.h"