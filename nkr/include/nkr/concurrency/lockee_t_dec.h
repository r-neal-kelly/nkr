/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/built_in/forward_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/cpp/concurrency/lock/perpetual/deep_t_dec.h"
#include "nkr/cpp/concurrency/locker/exclusive_t_dec.h"
#include "nkr/generic/type_tr_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/tr_dec.h"

/*
    lockee_t:
        - Handles the thread-exclusive scoped locking of a supplied reference and associated deep lock.
        - Makes it easy for functions to return a private static variable as a sharable resource.
        - We use a deep lock to avoid the same thread causing a deadlock when getting the resource more than once.

        - We may add a specialization for an inclusive locker.
*/

namespace nkr { namespace concurrency {

    template <tr<just_non_qualified_tg, t<nkr::generic::type_tg>> value_p>
    class   lockee_t;

    struct  lockee_tg   { class tag_lb; };

    template <typename>
    struct  lockee_ttg  {};

    template <typename type_p>
    concept lockee_tr =
        nkr::cpp::is_any_tr<type_p, lockee_t<typename type_p::value_t>>;

    template <template <typename ...> typename template_p>
    concept lockee_ttr =
        nkr::cpp::is_any_ttr<template_p, lockee_t, nkr::positive::integer_t>;

}}

namespace nkr { namespace concurrency { namespace lockee_t$ {

    template <nkr::concurrency::lockee_tr type_p>
    class type_i_type_sp
    {
    public:
        using type_t    = type_p;
        using of_t      = type_t::value_t;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any_General() noexcept;
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any_Specific() noexcept;

    public:
        template <typename ...>
        constexpr type_i_type_sp(...) noexcept  = delete;
    };

    template <nkr::cpp::is_any_tr<nkr::concurrency::lockee_tg> type_p>
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

}}}

namespace nkr { namespace interface {

    template <nkr::concurrency::lockee_tr type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::concurrency::lockee_t$::type_i_type_sp<type_p>;
    };

    template <nkr::cpp::is_any_tr<nkr::concurrency::lockee_tg> type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::concurrency::lockee_t$::type_i_tag_sp<type_p>;
    };

}}

namespace nkr { namespace concurrency { namespace lockee_t$ {

    template <template <typename ...> typename template_p>
        requires nkr::concurrency::lockee_ttr<template_p>
    class template_i_template_sp
    {
    public:
        template <tr<just_non_qualified_tg, t<nkr::generic::type_tg>> value_p>
        using template_t    = nkr::concurrency::lockee_t<value_p>;

        template <typename inner_p>
        using of_t          = template_t<inner_p>;

        template <nkr::tuple::types_tr parameters_p>
            requires (parameters_p::Count() == 1)
        using of_tuple_t    = parameters_p::template into_t<template_t>;

        template <typename ...parameters_p>
        using of_pack_t     = of_tuple_t<nkr::tuple::types_t<parameters_p...>>;

        using example_t     = of_t<nkr::positive::integer_t>;

    public:
        template <template <typename ...> typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr template_i_template_sp(...) noexcept  = delete;
    };

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::concurrency::lockee_ttg, nkr::none::type_t>
    class template_i_tag_sp :
        public template_i_template_sp<nkr::concurrency::lockee_t>
    {
    public:
    };

}}}

namespace nkr { namespace interface {

    template <template <typename ...> typename template_p>
        requires nkr::concurrency::lockee_ttr<template_p>
    class template_i_sp<template_p>
    {
    public:
        using type_t    = nkr::concurrency::lockee_t$::template_i_template_sp<template_p>;
    };

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::concurrency::lockee_ttg, nkr::none::type_t>
    class template_i_sp<template_p>
    {
    public:
        using type_t    = nkr::concurrency::lockee_t$::template_i_tag_sp<template_p>;
    };

}}

namespace nkr { namespace concurrency {

    template <tr<just_non_qualified_tg, t<nkr::generic::type_tg>> value_p>
    class lockee_t
    {
    public:
        using value_t   = value_p;
        using lock_t    = nkr::cpp::concurrency::lock::perpetual::deep_t;
        using locker_t  = nkr::cpp::concurrency::locker::exclusive_t<lock_t>;

    private:
        static auto     Assert(const tr<any_tg, t<lockee_t>> auto& self) noexcept;

    private:
        static auto&    Assign(tr<any_non_const_tg, t<lockee_t>> auto& self, tr<any_non_const_tg, t<lockee_t>> auto&& other) noexcept;

    private:
        static auto&    Value(const tr<any_tg, t<lockee_t>> auto& self) noexcept;
        static auto&    Value(tr<any_non_const_tg, t<lockee_t>> auto& self, const tr<any_tg, t<value_t>> auto& value) noexcept;
        static auto&    Value(tr<any_non_const_tg, t<lockee_t>> auto& self, tr<any_non_const_tg, t<value_t>> auto&& value) noexcept;

    protected:
        value_t&    value;
        lock_t&     lock;
        locker_t    locker;

    public:
        lockee_t(value_t& value, lock_t& lock) noexcept;

        lockee_t(const lockee_t& other) noexcept                                                            = delete;
        lockee_t(const volatile lockee_t& other) noexcept                                                   = delete;
        lockee_t(lockee_t&& other) noexcept;
        lockee_t(volatile lockee_t&& other) noexcept                                                        = delete;

        lockee_t&           operator =(const lockee_t& other) noexcept                                      = delete;
        volatile lockee_t&  operator =(const lockee_t& other) volatile noexcept                             = delete;
        lockee_t&           operator =(const volatile lockee_t& other) noexcept                             = delete;
        volatile lockee_t&  operator =(const volatile lockee_t& other) volatile noexcept                    = delete;
        lockee_t&           operator =(lockee_t&& other) noexcept;
        volatile lockee_t&  operator =(lockee_t&& other) volatile noexcept                                  = delete;
        lockee_t&           operator =(tr<just_volatile_tg, t<lockee_t>> auto&& other) noexcept             = delete;
        volatile lockee_t&  operator =(tr<just_volatile_tg, t<lockee_t>> auto&& other) volatile noexcept    = delete;
        // tr<just_volatile_tg, t<pure_t>> auto

        ~lockee_t() noexcept;

    public:
        value_t&                    Value() noexcept;
        const value_t&              Value() const noexcept;
        volatile value_t&           Value() volatile noexcept                                                       = delete;
        const volatile value_t&     Value() const volatile noexcept                                                 = delete;

        lockee_t&                   Value(const tr<any_tg, t<value_t>> auto& value) noexcept;
        const lockee_t&             Value(const tr<any_tg, t<value_t>> auto& value) const noexcept;
        volatile lockee_t&          Value(const tr<any_tg, t<value_t>> auto& value) volatile noexcept               = delete;
        const volatile lockee_t&    Value(const tr<any_tg, t<value_t>> auto& value) const volatile noexcept         = delete;
        lockee_t&                   Value(tr<any_non_const_tg, t<value_t>> auto&& value) noexcept;
        const lockee_t&             Value(tr<any_non_const_tg, t<value_t>> auto&& value) const noexcept;
        volatile lockee_t&          Value(tr<any_non_const_tg, t<value_t>> auto&& value) volatile noexcept          = delete;
        const volatile lockee_t&    Value(tr<any_non_const_tg, t<value_t>> auto&& value) const volatile noexcept    = delete;

    public:
        operator                lockee_t::value_t&() noexcept;
        operator const          lockee_t::value_t&() const noexcept;
        operator volatile       lockee_t::value_t&() volatile noexcept          = delete;
        operator const volatile lockee_t::value_t&() const volatile noexcept    = delete;
    };

}}

#include "nkr/concurrency/lockee_t_dec_def.h"
