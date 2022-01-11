/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsics_dec.h"

namespace nkr { namespace generic { namespace built_in {

    struct  pointer_tg  {};

    template <typename>
    struct  pointer_ttg {};

    template <typename type_p>
    concept pointer_tr =
        cpp::pointer_tr<type_p>;

    template <template <typename ...> typename template_p>
    concept pointer_ttr =
        pointer_tr<typename interface::template_i<template_p>::example_t>;

}}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::generic::built_in::pointer_tg>
    {
    public:
        using type_t    = nkr::generic::built_in::pointer_tg;
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
    class template_i<nkr::generic::built_in::pointer_ttg>
    {
    public:
        template <typename inner_p>
        using of_t      = nkr::generic::built_in::pointer_tg;
        using example_t = nkr::generic::built_in::pointer_tg;

    public:
        template <template <typename ...> typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr template_i(...) noexcept  = delete;
    };

}}

#include "nkr/generic/built_in/pointer_tr_dec_def.h"
