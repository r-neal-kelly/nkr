/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/built_in/forward_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/cpp/generic/randomness/generator_tr_dec.h"
#include "nkr/cpp/randomness/distributor/bernoulli_t_dec.h"
#include "nkr/cpp/randomness/distributor/uniform/integer_t_dec.h"
#include "nkr/cpp/randomness/distributor/uniform/real_t_dec.h"
#include "nkr/generic/built_in/number/integer_tr_dec.h"
#include "nkr/generic/built_in/number/real_tr_dec.h"
#include "nkr/generic/implementing/interface/randomness/distributor/uniform_tr_dec.h"
#include "nkr/generic/positive_tr_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/interface/randomness/distributor/uniform_i_dec.h"
#include "nkr/tr_dec.h"
#include "nkr/tuple/types_t_dec.h"

namespace nkr { namespace randomness { namespace distributor {

    template <typename value_p>
    class   uniform_t;

    struct  uniform_tg  {};

    template <typename>
    struct  uniform_ttg {};

    template <typename type_p>
    concept uniform_tr =
        nkr::cpp::is_any_tr<type_p, uniform_t<typename type_p::value_t>>;

    template <template <typename ...> typename template_p>
    concept uniform_ttr =
        nkr::cpp::is_any_ttr<template_p, uniform_t, nkr::positive::integer_t>;

}}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::randomness::distributor::uniform_tg>
    {
    public:
        using type_t    = nkr::randomness::distributor::uniform_tg;
        using of_t      = nkr::none::type_t;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr type_i(...) noexcept  = delete;
    };

    template <nkr::randomness::distributor::uniform_tr type_p>
    class type_i<type_p> :
        public type_i<nkr::randomness::distributor::uniform_tg>
    {
    public:
        using type_t    = type_p;
        using of_t      = type_p::value_t;
    };

}}

namespace nkr { namespace interface {

    template <>
    class template_i<nkr::randomness::distributor::uniform_ttg>
    {
    public:
        template <typename value_p>
        using template_t    = nkr::randomness::distributor::uniform_t<value_p>;

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
        constexpr template_i(...) noexcept  = delete;
    };

    template <template <typename ...> typename template_p>
        requires nkr::randomness::distributor::uniform_ttr<template_p>
    class template_i<template_p> :
        public template_i<nkr::randomness::distributor::uniform_ttg>
    {
    public:
    };

}}

namespace nkr { namespace randomness { namespace distributor {

    template <nkr::generic::implementing::interface::randomness::distributor::uniform_tr value_p>
    class uniform_t<value_p>
    {
    public:
        using value_t       = value_p;
        using interface_t   = nkr::interface::randomness::distributor::uniform_i<value_t>;

    public:
        static constexpr value_t    Default_Min() noexcept;
        static constexpr value_t    Default_Max() noexcept;

    private:
        static constexpr auto&  Assign(tr<any_non_const_tg, t<uniform_t>> auto& self, const tr<any_tg, t<uniform_t>> auto& other) noexcept;
        static constexpr auto&  Assign(tr<any_non_const_tg, t<uniform_t>> auto& self, tr<any_non_const_tg, t<uniform_t>> auto&& other) noexcept;

    private:
        static constexpr const auto&    Min(tr<any_tg, t<uniform_t>> auto& self) noexcept;
        static constexpr auto&          Min(tr<any_non_const_tg, t<uniform_t>> auto& self, const value_t& value) noexcept;
        static constexpr auto&          Min(tr<any_non_const_tg, t<uniform_t>> auto& self, value_t&& value) noexcept;

        static constexpr const auto&    Max(tr<any_tg, t<uniform_t>> auto& self) noexcept;
        static constexpr auto&          Max(tr<any_non_const_tg, t<uniform_t>> auto& self, const value_t& value) noexcept;
        static constexpr auto&          Max(tr<any_non_const_tg, t<uniform_t>> auto& self, value_t&& value) noexcept;

        static constexpr value_t        Value(tr<any_tg, t<uniform_t>> auto& self, tr<any_non_const_tg, t<nkr::cpp::generic::randomness::generator_tg>> auto& generator) noexcept;

    protected:
        value_t min;
        value_t max;

    public:
        constexpr uniform_t() noexcept;

        constexpr uniform_t(const value_t& min, const value_t& max) noexcept;
        constexpr uniform_t(value_t&& min, value_t&& max) noexcept;

        constexpr uniform_t(const uniform_t& other) noexcept;
        constexpr uniform_t(const volatile uniform_t& other) noexcept;
        constexpr uniform_t(uniform_t&& other) noexcept;
        constexpr uniform_t(volatile uniform_t&& other) noexcept;

        constexpr uniform_t&            operator =(const uniform_t& other) noexcept;
        constexpr volatile uniform_t&   operator =(const uniform_t& other) volatile noexcept;
        constexpr uniform_t&            operator =(const volatile uniform_t& other) noexcept;
        constexpr volatile uniform_t&   operator =(const volatile uniform_t& other) volatile noexcept;
        constexpr uniform_t&            operator =(uniform_t&& other) noexcept;
        constexpr volatile uniform_t&   operator =(uniform_t&& other) volatile noexcept;
        constexpr uniform_t&            operator =(tr<just_volatile_tg, t<uniform_t>> auto&& other) noexcept;
        constexpr volatile uniform_t&   operator =(tr<just_volatile_tg, t<uniform_t>> auto&& other) volatile noexcept;

    #if defined(nkr_IS_DEBUG)
        constexpr ~uniform_t() noexcept;
    #endif

    public:
        constexpr const value_t&            Min() const noexcept;
        constexpr const volatile value_t&   Min() const volatile noexcept;
        constexpr uniform_t&                Min(const value_t& value) noexcept;
        constexpr volatile uniform_t&       Min(const value_t& value) volatile noexcept;
        constexpr uniform_t&                Min(value_t&& value) noexcept;
        constexpr volatile uniform_t&       Min(value_t&& value) volatile noexcept;

        constexpr const value_t&            Max() const noexcept;
        constexpr const volatile value_t&   Max() const volatile noexcept;
        constexpr uniform_t&                Max(const value_t& value) noexcept;
        constexpr volatile uniform_t&       Max(const value_t& value) volatile noexcept;
        constexpr uniform_t&                Max(value_t&& value) noexcept;
        constexpr volatile uniform_t&       Max(value_t&& value) volatile noexcept;

        constexpr value_t                   Value(tr<any_non_const_tg, t<nkr::cpp::generic::randomness::generator_tg>> auto& generator) const noexcept;
        constexpr value_t                   Value(tr<any_non_const_tg, t<nkr::cpp::generic::randomness::generator_tg>> auto& generator) const volatile noexcept;
    };

}}}

#include "nkr/randomness/distributor/uniform_t_dec_def.h"
