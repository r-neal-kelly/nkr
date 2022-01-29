/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/boolean/cpp_t_dec.h"
#include "nkr/cpp/concurrency/locker/exclusive_t_dec.h"
#include "nkr/cpp/concurrency/locker/inclusive_t_dec.h"
#include "nkr/cpp/concurrency/locker/scoped_t_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/none/type_t_dec.h"
#include "nkr/tuple/types_t_dec.h"

namespace nkr { namespace cpp { namespace generic { namespace concurrency {

    struct  locker_tg   {};

    template <typename>
    struct  locker_ttg  {};

    template <typename type_p>
    concept locker_tr =
        nkr::cpp::concurrency::locker::exclusive_tr<type_p> ||
        nkr::cpp::concurrency::locker::inclusive_tr<type_p> ||
        nkr::cpp::concurrency::locker::scoped_tr<type_p>;

    template <template <typename ...> typename template_p>
    concept locker_ttr =
        locker_tr<typename nkr::interface::template_i<template_p>::example_t>;

}}}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::cpp::generic::concurrency::locker_tg>
    {
    public:
        using type_t    = nkr::cpp::generic::concurrency::locker_tg;
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
    class template_i<nkr::cpp::generic::concurrency::locker_ttg>
    {
    public:
        template <typename ...>
        using template_t    = nkr::cpp::generic::concurrency::locker_tg;

        template <typename inner_p>
        using of_t          = nkr::cpp::generic::concurrency::locker_tg;

        template <nkr::tuple::types_tr parameters_p>
        using of_tuple_t    = nkr::cpp::generic::concurrency::locker_tg;

        template <typename ...parameters_p>
        using of_pack_t     = nkr::cpp::generic::concurrency::locker_tg;

        using example_t     = nkr::cpp::generic::concurrency::locker_tg;

    public:
        template <template <typename ...> typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr template_i(...) noexcept  = delete;
    };

}}

#include "nkr/cpp/generic/concurrency/locker_tr_dec_def.h"
