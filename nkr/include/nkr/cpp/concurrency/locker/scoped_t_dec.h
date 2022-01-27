/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/boolean/cpp_t_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/cpp/concurrency/lock/perpetual/unary_t_dec.h"
#include "nkr/cpp/generic/concurrency/lock_tr_dec.h"
#include "nkr/none/type_t_dec.h"

namespace nkr { namespace interface {

    template <template <typename ...> typename template_p>
    class   template_i;

}}

namespace nkr { namespace interface {

    template <typename type_p>
    class   type_i;

}}

namespace nkr { namespace cpp { namespace concurrency { namespace locker { namespace $scoped_t {

    template <typename type_p>
    class is_tmpl :
        public std::false_type
    {
    public:
    };

    template <nkr::cpp::generic::concurrency::lock_tr ...locks_p>
    class is_tmpl<std::scoped_lock<locks_p...>> :
        public std::true_type
    {
    public:
    };

    template <typename type_p>
    class inner_tmpl
    {
    public:
        using type_t    = nkr::none::type_t;
    };

    template <nkr::cpp::generic::concurrency::lock_tr lock_p>
    class inner_tmpl<std::scoped_lock<lock_p>>
    {
    public:
        using type_t    = lock_p;
    };

    template <typename type_p>
    using inner_t   = inner_tmpl<type_p>::type_t;

}}}}}

namespace nkr { namespace cpp { namespace concurrency { namespace locker {

    template <nkr::cpp::generic::concurrency::lock_tr ...locks_p>
    using   scoped_t =
        std::scoped_lock<locks_p...>;

    struct  scoped_tg   {};

    template <typename>
    struct  scoped_ttg  {};

    template <typename type_p>
    concept scoped_tr =
        $scoped_t::is_tmpl<nkr::cpp::just_non_qualified_t<type_p>>::value;

    template <template <typename ...> typename template_p>
    concept scoped_ttr =
        nkr::cpp::is_any_ttr<template_p, scoped_t, nkr::cpp::concurrency::lock::perpetual::unary_t>;

}}}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::cpp::concurrency::locker::scoped_tg>
    {
    public:
        using type_t    = nkr::cpp::concurrency::locker::scoped_tg;
        using of_t      = nkr::none::type_t;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr type_i(...) noexcept  = delete;
    };

    template <nkr::cpp::concurrency::locker::scoped_tr type_p>
    class type_i<type_p> :
        public type_i<nkr::cpp::concurrency::locker::scoped_tg>
    {
    public:
        using type_t    = type_p;
        using of_t      = nkr::cpp::concurrency::locker::$scoped_t::inner_t<type_t>;
    };

}}

namespace nkr { namespace interface {

    template <>
    class template_i<nkr::cpp::concurrency::locker::scoped_ttg>
    {
    public:
        template <typename inner_p>
        using of_t      = nkr::cpp::concurrency::locker::scoped_t<inner_p>;
        using example_t = of_t<nkr::cpp::concurrency::lock::perpetual::unary_t>;

    public:
        template <template <typename ...> typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr template_i(...) noexcept  = delete;
    };

    template <template <typename ...> typename template_p>
        requires nkr::cpp::concurrency::locker::scoped_ttr<template_p>
    class template_i<template_p> :
        public template_i<nkr::cpp::concurrency::locker::scoped_ttg>
    {
    public:
    };

}}

#include "nkr/cpp/concurrency/locker/scoped_t_dec_def.h"
