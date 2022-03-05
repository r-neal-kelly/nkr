/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/built_in/forward_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/cpp/concurrency/lock/perpetual/unary_t_dec.h"
#include "nkr/cpp/generic/concurrency/lock/exclusive_tr_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/tuple/types_t_dec.h"

namespace nkr { namespace cpp { namespace concurrency { namespace locker {

    template <nkr::cpp::generic::concurrency::lock::exclusive_tr lock_p>
    using   exclusive_t =
        std::unique_lock<lock_p>;

    struct  exclusive_tg    { class tag_lb; };

    template <typename>
    struct  exclusive_ttg   {};

    template <typename type_p>
    concept exclusive_tr =
        nkr::cpp::is_any_tr<type_p, exclusive_t<typename type_p::mutex_type>>;

    template <template <typename ...> typename template_p>
    concept exclusive_ttr =
        nkr::cpp::is_any_ttr<template_p, exclusive_t, nkr::cpp::concurrency::lock::perpetual::unary_t>;

}}}}

namespace nkr { namespace cpp { namespace concurrency { namespace locker { namespace $exclusive_t {

    template <nkr::cpp::concurrency::locker::exclusive_tr type_p>
    class type_i_type_sp
    {
    public:
        using type_t    = type_p;
        using of_t      = type_t::mutex_type;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any_General() noexcept;
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any_Specific() noexcept;

    public:
        template <typename ...>
        constexpr type_i_type_sp(...) noexcept  = delete;
    };

    template <nkr::cpp::is_any_tr<nkr::cpp::concurrency::locker::exclusive_tg> type_p>
    class type_i_tag_sp
    {
    public:
        using type_t    = type_p;
        using of_t      = nkr::none::type_t;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any_General() noexcept;
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any_Specific() noexcept;

    public:
        template <typename ...>
        constexpr type_i_tag_sp(...) noexcept   = delete;
    };

}}}}}

namespace nkr { namespace interface {

    template <nkr::cpp::concurrency::locker::exclusive_tr type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::cpp::concurrency::locker::$exclusive_t::type_i_type_sp<type_p>;
    };

    template <nkr::cpp::is_any_tr<nkr::cpp::concurrency::locker::exclusive_tg> type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::cpp::concurrency::locker::$exclusive_t::type_i_tag_sp<type_p>;
    };

}}

namespace nkr { namespace cpp { namespace concurrency { namespace locker { namespace $exclusive_t {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::concurrency::locker::exclusive_ttr<template_p>
    class template_i_template_sp
    {
    public:
        template <nkr::cpp::generic::concurrency::lock::exclusive_tr lock_p>
        using template_t    = nkr::cpp::concurrency::locker::exclusive_t<lock_p>;

        template <typename inner_p>
        using of_t          = template_t<inner_p>;

        template <nkr::tuple::types_tr parameters_p>
            requires (parameters_p::Count() == 1)
        using of_tuple_t    = parameters_p::template into_t<template_t>;

        template <typename ...parameters_p>
        using of_pack_t     = of_tuple_t<nkr::tuple::types_t<parameters_p...>>;

        using example_t     = of_t<nkr::cpp::concurrency::lock::perpetual::unary_t>;

    public:
        template <template <typename ...> typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr template_i_template_sp(...) noexcept  = delete;
    };

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::cpp::concurrency::locker::exclusive_ttg, nkr::none::type_t>
    class template_i_tag_sp :
        public template_i_template_sp<nkr::cpp::concurrency::locker::exclusive_t>
    {
    public:
    };

}}}}}

namespace nkr { namespace interface {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::concurrency::locker::exclusive_ttr<template_p>
    class template_i_sp<template_p>
    {
    public:
        using type_t    = nkr::cpp::concurrency::locker::$exclusive_t::template_i_template_sp<template_p>;
    };

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::cpp::concurrency::locker::exclusive_ttg, nkr::none::type_t>
    class template_i_sp<template_p>
    {
    public:
        using type_t    = nkr::cpp::concurrency::locker::$exclusive_t::template_i_tag_sp<template_p>;
    };

}}

#include "nkr/cpp/concurrency/locker/exclusive_t_dec_def.h"
