/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/boolean/cpp_t_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/cpp/concurrency/lock/perpetual/unary_t_dec.h"
#include "nkr/cpp/generic/concurrency/lock/exclusive_tr_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/none/type_t_dec.h"
#include "nkr/positive/index_t_dec.h"
#include "nkr/tuple/types_t_dec.h"

namespace nkr { namespace cpp { namespace concurrency { namespace locker {

    template <nkr::cpp::generic::concurrency::lock::exclusive_tr lock_p>
    using   exclusive_t =
        std::unique_lock<lock_p>;

    struct  exclusive_tg    {};

    template <typename>
    struct  exclusive_ttg   {};

    template <typename type_p>
    concept exclusive_tr =
        nkr::cpp::is_any_tr<type_p, exclusive_t<typename type_p::mutex_type>>;

    template <template <typename ...> typename template_p>
    concept exclusive_ttr =
        nkr::cpp::is_any_ttr<template_p, exclusive_t, nkr::cpp::concurrency::lock::perpetual::unary_t>;

}}}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::cpp::concurrency::locker::exclusive_tg>
    {
    public:
        using type_t    = nkr::cpp::concurrency::locker::exclusive_tg;
        using of_t      = nkr::none::type_t;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr type_i(...) noexcept  = delete;
    };

    template <nkr::cpp::concurrency::locker::exclusive_tr type_p>
    class type_i<type_p> :
        public type_i<nkr::cpp::concurrency::locker::exclusive_tg>
    {
    public:
        using type_t    = type_p;
        using of_t      = type_p::mutex_type;
    };

}}

namespace nkr { namespace interface {

    template <>
    class template_i<nkr::cpp::concurrency::locker::exclusive_ttg>
    {
    public:
        template <nkr::cpp::generic::concurrency::lock::exclusive_tr lock_p>
        using template_t    = nkr::cpp::concurrency::locker::exclusive_t<lock_p>;

        template <typename inner_p>
        using of_t          = template_t<inner_p>;

        template <nkr::tuple::types_tr parameters_p>
            requires (parameters_p::Count() == 1)
        using of_tuple_t    = template_t<
            typename parameters_p::template at_t<nkr::positive::index_c<0>>
        >;

        template <typename ...parameters_p>
        using of_pack_t     = of_tuple_t<nkr::tuple::types_t<parameters_p...>>;

        using example_t     = of_t<nkr::cpp::concurrency::lock::perpetual::unary_t>;

    public:
        template <template <typename ...> typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr template_i(...) noexcept  = delete;
    };

    template <template <typename ...> typename template_p>
        requires nkr::cpp::concurrency::locker::exclusive_ttr<template_p>
    class template_i<template_p> :
        public template_i<nkr::cpp::concurrency::locker::exclusive_ttg>
    {
    public:
    };

}}

#include "nkr/cpp/concurrency/locker/exclusive_t_dec_def.h"
