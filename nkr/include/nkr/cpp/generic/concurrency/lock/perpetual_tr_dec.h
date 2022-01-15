/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsics_dec.h"

#include "nkr/cpp/concurrency/lock/perpetual/deep_t_dec.h"
#include "nkr/cpp/concurrency/lock/perpetual/unary_t_dec.h"
#include "nkr/cpp/concurrency/lock/perpetual/wide_t_dec.h"

namespace nkr { namespace cpp { namespace generic { namespace concurrency { namespace lock {

    struct  perpetual_tg    {};

    template <typename>
    struct  perpetual_ttg   {};

    template <typename type_p>
    concept perpetual_tr =
        nkr::cpp::concurrency::lock::perpetual::deep_tr<type_p> ||
        nkr::cpp::concurrency::lock::perpetual::unary_tr<type_p> ||
        nkr::cpp::concurrency::lock::perpetual::wide_tr<type_p>;

    template <template <typename ...> typename template_p>
    concept perpetual_ttr =
        perpetual_tr<typename nkr::interface::template_i<template_p>::example_t>;

}}}}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::cpp::generic::concurrency::lock::perpetual_tg>
    {
    public:
        using type_t    = nkr::cpp::generic::concurrency::lock::perpetual_tg;
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
    class template_i<nkr::cpp::generic::concurrency::lock::perpetual_ttg>
    {
    public:
        template <typename inner_p>
        using of_t      = nkr::cpp::generic::concurrency::lock::perpetual_tg;
        using example_t = nkr::cpp::generic::concurrency::lock::perpetual_tg;

    public:
        template <template <typename ...> typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr template_i(...) noexcept  = delete;
    };

}}

#include "nkr/cpp/generic/concurrency/lock/perpetual_tr_dec_def.h"
