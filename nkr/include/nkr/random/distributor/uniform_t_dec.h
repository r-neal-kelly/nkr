/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/tr_dec.h"

#include "nkr/generic/boolean_tr_dec.h"
#include "nkr/generic/number/integer_tr_dec.h"
#include "nkr/generic/number/real_tr_dec.h"
#include "nkr/generic/pointer_tr_dec.h"
#include "nkr/generic/random/generator_tr_dec.h"

#include "nkr/none/value_t_dec.h"

#include "nkr/random/distributor/cpp/uniform/integer_t_dec.h"
#include "nkr/random/distributor/cpp/uniform/real_t_dec.h"

namespace nkr { namespace random { namespace distributor { namespace $uniform_t {

    template <tr1<just_non_qualified_tg, generic::boolean_tg> value_p>
    class   boolean_sp;

    template <tr1<just_non_qualified_tg, generic::number::integer_tg> value_p>
    class   integer_sp;

    template <tr1<just_non_qualified_tg, generic::number::real_tg> value_p>
    class   real_sp;

    template <tr1<just_non_qualified_tg, generic::pointer_tg> value_p>
    class   pointer_sp;

}}}}

namespace nkr { namespace random { namespace distributor { namespace $uniform_t {

    template <typename value_p>
    class specialization_tmpl;

    template <tr1<just_non_qualified_tg, generic::boolean_tg> value_p>
    class specialization_tmpl<value_p>
    {
    public:
        using type_t    = boolean_sp<value_p>;
    };

    template <tr1<just_non_qualified_tg, generic::number::integer_tg> value_p>
    class specialization_tmpl<value_p>
    {
    public:
        using type_t    = integer_sp<value_p>;
    };

    template <tr1<just_non_qualified_tg, generic::number::real_tg> value_p>
    class specialization_tmpl<value_p>
    {
    public:
        using type_t    = real_sp<value_p>;
    };

    template <tr1<just_non_qualified_tg, generic::pointer_tg> value_p>
    class specialization_tmpl<value_p>
    {
    public:
        using type_t    = pointer_sp<value_p>;
    };

}}}}

namespace nkr { namespace random { namespace distributor {

    template <typename value_p>
    using   uniform_t =
        $uniform_t::specialization_tmpl<value_p>::type_t;

    struct  uniform_tg  {};

    template <typename>
    struct  uniform_ttg {};

    template <typename type_p>
    concept uniform_tr =
        nkr::cpp::is_any_tr<type_p, uniform_t<typename type_p::value_t>>;

    template <template <typename ...> typename template_p>
    concept uniform_ttr =
        nkr::cpp::is_any_ttr<template_p, uniform_t, positive::integer_t>;

}}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::random::distributor::uniform_tg>
    {
    public:
        using type_t    = nkr::random::distributor::uniform_tg;
        using of_t      = nkr::none::type_t;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr type_i(...) noexcept  = delete;
    };

    template <nkr::random::distributor::uniform_tr type_p>
    class type_i<type_p> :
        public type_i<nkr::random::distributor::uniform_tg>
    {
    public:
        using type_t    = type_p;
        using of_t      = type_p::value_t;
    };

}}

namespace nkr { namespace interface {

    template <>
    class template_i<nkr::random::distributor::uniform_ttg>
    {
    public:
        template <typename inner_p>
        using of_t      = nkr::random::distributor::uniform_t<inner_p>;
        using example_t = of_t<nkr::positive::integer_t>;

    public:
        template <template <typename ...> typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr template_i(...) noexcept  = delete;
    };

    template <template <typename ...> typename template_p>
        requires nkr::random::distributor::uniform_ttr<template_p>
    class template_i<template_p> :
        public template_i<nkr::random::distributor::uniform_ttg>
    {
    public:
    };

}}

namespace nkr { namespace random { namespace distributor { namespace $uniform_t {

    template <tr1<just_non_qualified_tg, generic::boolean_tg> value_p>
    class boolean_sp
    {
    public:
        using value_t   = value_p;

    public:
        static constexpr value_t    Default_Min() noexcept;
        static constexpr value_t    Default_Max() noexcept;

    private:
        static constexpr auto&  Assign(tr1<any_non_const_tg, boolean_sp> auto& self, const tr1<any_tg, boolean_sp> auto& other) noexcept;
        static constexpr auto&  Assign(tr1<any_non_const_tg, boolean_sp> auto& self, tr1<any_non_const_tg, boolean_sp> auto&& other) noexcept;

    private:
        static constexpr value_t    Min(tr1<any_tg, boolean_sp> auto& self) noexcept;
        static constexpr auto&      Min(tr1<any_non_const_tg, boolean_sp> auto& self, const value_t& value) noexcept;
        static constexpr auto&      Min(tr1<any_non_const_tg, boolean_sp> auto& self, value_t&& value) noexcept;

        static constexpr value_t    Max(tr1<any_tg, boolean_sp> auto& self) noexcept;
        static constexpr auto&      Max(tr1<any_non_const_tg, boolean_sp> auto& self, const value_t& value) noexcept;
        static constexpr auto&      Max(tr1<any_non_const_tg, boolean_sp> auto& self, value_t&& value) noexcept;

        static constexpr value_t    Value(tr1<any_tg, boolean_sp> auto& self, tr1<any_non_const_tg, generic::random::generator_tg> auto& generator) noexcept;

    protected:
        value_t min;
        value_t max;

    public:
        constexpr boolean_sp() noexcept;

        constexpr boolean_sp(value_t min, value_t max) noexcept;

        constexpr boolean_sp(const boolean_sp& other) noexcept;
        constexpr boolean_sp(const volatile boolean_sp& other) noexcept;
        constexpr boolean_sp(boolean_sp&& other) noexcept;
        constexpr boolean_sp(volatile boolean_sp&& other) noexcept;

        constexpr boolean_sp&           operator =(const boolean_sp& other) noexcept;
        constexpr volatile boolean_sp&  operator =(const boolean_sp& other) volatile noexcept;
        constexpr boolean_sp&           operator =(const volatile boolean_sp& other) noexcept;
        constexpr volatile boolean_sp&  operator =(const volatile boolean_sp& other) volatile noexcept;
        constexpr boolean_sp&           operator =(boolean_sp&& other) noexcept;
        constexpr volatile boolean_sp&  operator =(boolean_sp&& other) volatile noexcept;
        constexpr boolean_sp&           operator =(volatile boolean_sp&& other) noexcept;
        constexpr volatile boolean_sp&  operator =(volatile boolean_sp&& other) volatile noexcept;

    #if defined(nkr_IS_DEBUG)
        constexpr ~boolean_sp() noexcept;
    #endif

    public:
        constexpr value_t               Min() const noexcept;
        constexpr value_t               Min() const volatile noexcept;
        constexpr boolean_sp&           Min(const value_t& value) noexcept;
        constexpr volatile boolean_sp&  Min(const value_t& value) volatile noexcept;
        constexpr boolean_sp&           Min(value_t&& value) noexcept;
        constexpr volatile boolean_sp&  Min(value_t&& value) volatile noexcept;

        constexpr value_t               Max() const noexcept;
        constexpr value_t               Max() const volatile noexcept;
        constexpr boolean_sp&           Max(const value_t& value) noexcept;
        constexpr volatile boolean_sp&  Max(const value_t& value) volatile noexcept;
        constexpr boolean_sp&           Max(value_t&& value) noexcept;
        constexpr volatile boolean_sp&  Max(value_t&& value) volatile noexcept;

        constexpr value_t               Value(tr1<any_non_const_tg, generic::random::generator_tg> auto& generator) const noexcept;
        constexpr value_t               Value(tr1<any_non_const_tg, generic::random::generator_tg> auto& generator) const volatile noexcept;
    };

}}}}

namespace nkr { namespace random { namespace distributor { namespace $uniform_t {

    template <tr1<just_non_qualified_tg, generic::number::integer_tg> value_p>
    class integer_sp
    {
    public:
        using value_t   = value_p;

    public:
        static constexpr value_t    Default_Min() noexcept;
        static constexpr value_t    Default_Max() noexcept;
    };

}}}}

namespace nkr { namespace random { namespace distributor { namespace $uniform_t {

    template <tr1<just_non_qualified_tg, generic::number::real_tg> value_p>
    class real_sp
    {
    public:
        using value_t   = value_p;

    public:
        static constexpr value_t    Default_Min() noexcept;
        static constexpr value_t    Default_Max() noexcept;
    };

}}}}

namespace nkr { namespace random { namespace distributor { namespace $uniform_t {

    template <tr1<just_non_qualified_tg, generic::pointer_tg> value_p>
    class pointer_sp
    {
    public:
        using value_t   = value_p;

    public:
        static constexpr value_t    Default_Min() noexcept;
        static constexpr value_t    Default_Max() noexcept;
    };

}}}}

#include "nkr/random/distributor/uniform_t_dec_def.h"
