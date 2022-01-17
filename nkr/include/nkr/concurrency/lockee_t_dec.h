/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/tr_dec.h"

#include "nkr/cpp/concurrency/lock/perpetual/unary_t_dec.h"
#include "nkr/cpp/concurrency/locker/exclusive_t_dec.h"

#include "nkr/generic/type_tr_dec.h"

/*
    lockee_t:
        Essentially a locker that accepts both a lock and a resource.
        Handles the thread-exclusive scoped locking of a supplied reference and associated lock.

        Makes it easy for functions to return a private static variable as a sharable resource.
*/

namespace nkr { namespace concurrency {

    template <tr1<just_non_qualified_tg, nkr::generic::type_tg> value_p>
    class   lockee_t;

    struct  lockee_tg   {};

    template <typename>
    struct  lockee_ttg  {};

    template <typename type_p>
    concept lockee_tr =
        nkr::cpp::is_any_tr<type_p, lockee_t<typename type_p::value_t>>;

    template <template <typename ...> typename template_p>
    concept lockee_ttr =
        nkr::cpp::is_any_ttr<template_p, lockee_t, positive::integer_t>;

}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::concurrency::lockee_tg>
    {
    public:
        using type_t    = nkr::concurrency::lockee_tg;
        using of_t      = nkr::none::type_t;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr type_i(...) noexcept  = delete;
    };

    template <nkr::concurrency::lockee_tr type_p>
    class type_i<type_p> :
        public type_i<nkr::concurrency::lockee_tg>
    {
    public:
        using type_t    = type_p;
        using of_t      = type_p::value_t;
    };

}}

namespace nkr { namespace interface {

    template <>
    class template_i<nkr::concurrency::lockee_ttg>
    {
    public:
        template <typename inner_p>
        using of_t      = nkr::concurrency::lockee_t<inner_p>;
        using example_t = of_t<nkr::positive::integer_t>;

    public:
        template <template <typename ...> typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr template_i(...) noexcept  = delete;
    };

    template <template <typename ...> typename template_p>
        requires nkr::concurrency::lockee_ttr<template_p>
    class template_i<template_p> :
        public template_i<nkr::concurrency::lockee_ttg>
    {
    public:
    };

}}

namespace nkr { namespace concurrency {

    template <tr1<just_non_qualified_tg, nkr::generic::type_tg> value_p>
    class lockee_t
    {
    public:
        using value_t   = value_p;
        using lock_t    = nkr::cpp::concurrency::lock::perpetual::deep_t;
        using locker_t  = nkr::cpp::concurrency::locker::exclusive_t<lock_t>;

    private:
        static auto     Assert(const tr1<any_tg, lockee_t> auto& self) noexcept;

    private:
        static auto&    Assign(tr1<any_non_const_tg, lockee_t> auto& self, tr1<any_non_const_tg, lockee_t> auto&& other) noexcept;

    private:
        static auto&    Value(const tr1<any_tg, lockee_t> auto& self) noexcept;
        static auto&    Value(tr1<any_non_const_tg, lockee_t> auto& self, const tr1<any_tg, value_t> auto& value) noexcept;
        static auto&    Value(tr1<any_non_const_tg, lockee_t> auto& self, tr1<any_non_const_tg, value_t> auto&& value) noexcept;

    protected:
        value_t&    value;
        lock_t&     lock;
        locker_t    locker;

    public:
        lockee_t(value_t& value, lock_t& lock) noexcept;

        lockee_t(const lockee_t& other) noexcept                                            = delete;
        lockee_t(const volatile lockee_t& other) noexcept                                   = delete;
        lockee_t(lockee_t&& other) noexcept;
        lockee_t(volatile lockee_t&& other) noexcept                                        = delete;

        lockee_t&           operator =(const lockee_t& other) noexcept                      = delete;
        volatile lockee_t&  operator =(const lockee_t& other) volatile noexcept             = delete;
        lockee_t&           operator =(const volatile lockee_t& other) noexcept             = delete;
        volatile lockee_t&  operator =(const volatile lockee_t& other) volatile noexcept    = delete;
        lockee_t&           operator =(lockee_t&& other) noexcept;
        volatile lockee_t&  operator =(lockee_t&& other) volatile noexcept                  = delete;
        lockee_t&           operator =(volatile lockee_t&& other) noexcept                  = delete;
        volatile lockee_t&  operator =(volatile lockee_t&& other) volatile noexcept         = delete;

        ~lockee_t() noexcept;

    public:
        value_t&                    Value() noexcept;
        const value_t&              Value() const noexcept;
        volatile value_t&           Value() volatile noexcept                                                   = delete;
        const volatile value_t&     Value() const volatile noexcept                                             = delete;

        lockee_t&                   Value(const tr1<any_tg, value_t> auto& value) noexcept;
        const lockee_t&             Value(const tr1<any_tg, value_t> auto& value) const noexcept;
        volatile lockee_t&          Value(const tr1<any_tg, value_t> auto& value) volatile noexcept             = delete;
        const volatile lockee_t&    Value(const tr1<any_tg, value_t> auto& value) const volatile noexcept       = delete;
        lockee_t&                   Value(tr1<any_non_const_tg, value_t> auto&& value) noexcept;
        const lockee_t&             Value(tr1<any_non_const_tg, value_t> auto&& value) const noexcept;
        volatile lockee_t&          Value(tr1<any_non_const_tg, value_t> auto&& value) volatile noexcept        = delete;
        const volatile lockee_t&    Value(tr1<any_non_const_tg, value_t> auto&& value) const volatile noexcept  = delete;

    public:
        operator                lockee_t::value_t&() noexcept;
        operator const          lockee_t::value_t&() const noexcept;
        operator volatile       lockee_t::value_t&() volatile noexcept          = delete;
        operator const volatile lockee_t::value_t&() const volatile noexcept    = delete;
    };

}}

#include "nkr/concurrency/lockee_t_dec_def.h"
