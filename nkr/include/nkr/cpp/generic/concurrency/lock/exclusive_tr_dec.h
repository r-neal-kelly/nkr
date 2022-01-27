/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/boolean/cpp_t_dec.h"
#include "nkr/cpp/generic/concurrency/lock/deep_tr_dec.h"
#include "nkr/cpp/generic/concurrency/lock/unary_tr_dec.h"
#include "nkr/cpp/generic/concurrency/lock/wide_tr_dec.h"
#include "nkr/none/type_t_dec.h"

namespace nkr { namespace interface {

    template <template <typename ...> typename template_p>
    class   template_i;

}}

namespace nkr { namespace interface {

    template <typename type_p>
    class   type_i;

}}

namespace nkr { namespace cpp { namespace generic { namespace concurrency { namespace lock {

    struct  exclusive_tg    {};

    template <typename>
    struct  exclusive_ttg   {};

    template <typename type_p>
    concept exclusive_tr =
        nkr::cpp::generic::concurrency::lock::deep_tr<type_p> ||
        nkr::cpp::generic::concurrency::lock::unary_tr<type_p> ||
        nkr::cpp::generic::concurrency::lock::wide_tr<type_p>;

    template <template <typename ...> typename template_p>
    concept exclusive_ttr =
        exclusive_tr<typename nkr::interface::template_i<template_p>::example_t>;

}}}}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::cpp::generic::concurrency::lock::exclusive_tg>
    {
    public:
        using type_t    = nkr::cpp::generic::concurrency::lock::exclusive_tg;
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
    class template_i<nkr::cpp::generic::concurrency::lock::exclusive_ttg>
    {
    public:
        template <typename inner_p>
        using of_t      = nkr::cpp::generic::concurrency::lock::exclusive_tg;
        using example_t = nkr::cpp::generic::concurrency::lock::exclusive_tg;

    public:
        template <template <typename ...> typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr template_i(...) noexcept  = delete;
    };

}}

#include "nkr/cpp/generic/concurrency/lock/exclusive_tr_dec_def.h"
