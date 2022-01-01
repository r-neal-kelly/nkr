/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsics_dec.h"

#include "nkr/generic/positive/any_tr_dec.h"

namespace nkr { namespace generic { namespace positive {

    struct  real_tg     {};

    template <typename>
    struct  real_ttg    {};

    template <typename type_p>
    concept real_tr =
        any_tr<type_p> &&
        cpp::real_tr<type_p>;

    template <template <typename ...> typename template_p>
    concept real_ttr =
        real_tr<typename interface::template_i<template_p>::example_t>;

}}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::generic::positive::real_tg>
    {
    public:
        using type_t    = nkr::generic::positive::real_tg;
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
    class template_i<nkr::generic::positive::real_ttg>
    {
    public:
        template <typename inner_p>
        using of_t      = nkr::generic::positive::real_tg;
        using example_t = nkr::generic::positive::real_tg;

    public:
        template <template <typename ...> typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr template_i(...) noexcept  = delete;
    };

}}

#include "nkr/generic/positive/real_tr_dec_def.h"
