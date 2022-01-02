/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsics_dec.h"

namespace nkr { namespace generic {

    struct  user_defined_tg     {};

    template <typename>
    struct  user_defined_ttg    {};

    template <typename type_p>
    concept user_defined_tr =
        cpp::user_defined_tr<type_p>;

    template <template <typename ...> typename template_p>
    concept user_defined_ttr =
        user_defined_tr<typename interface::template_i<template_p>::example_t>;

}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::generic::user_defined_tg>
    {
    public:
        using type_t    = nkr::generic::user_defined_tg;
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
    class template_i<nkr::generic::user_defined_ttg>
    {
    public:
        template <typename inner_p>
        using of_t      = nkr::generic::user_defined_tg;
        using example_t = nkr::generic::user_defined_tg;

    public:
        template <template <typename ...> typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr template_i(...) noexcept  = delete;
    };

}}

#include "nkr/generic/user_defined_tr_dec_def.h"
