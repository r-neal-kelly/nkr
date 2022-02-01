/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/boolean/cpp_t_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/generic/implementing/interface/none/value_tr_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/interface/none/value_i_dec.h"
#include "nkr/none/type_t_dec.h"
#include "nkr/positive/integer_t_dec.h"
#include "nkr/tr_dec.h"
#include "nkr/tuple/types_t_dec.h"

namespace nkr { namespace none {

    template <typename type_p>
    class   value_t;

    struct  value_tg    {};

    template <typename>
    struct  value_ttg   {};

    template <typename type_p>
    concept value_tr =
        nkr::cpp::is_any_tr<type_p, value_t<typename type_p::type_t>>;

    template <template <typename ...> typename template_p>
    concept value_ttr =
        nkr::cpp::is_any_ttr<template_p, value_t, nkr::positive::integer_t>;

}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::none::value_tg>
    {
    public:
        using type_t    = nkr::none::value_tg;
        using of_t      = nkr::none::type_t;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr type_i(...) noexcept  = delete;
    };

    template <nkr::none::value_tr type_p>
    class type_i<type_p> :
        public type_i<nkr::none::value_tg>
    {
    public:
        using type_t    = type_p;
        using of_t      = type_t::type_t;
    };

}}

namespace nkr { namespace interface {

    template <>
    class template_i<nkr::none::value_ttg>
    {
    public:
        template <typename type_p>
        using template_t    = nkr::none::value_t<type_p>;

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
        requires nkr::none::value_ttr<template_p>
    class template_i<template_p> :
        public template_i<nkr::none::value_ttg>
    {
    public:
    };

}}

namespace nkr { namespace none {

    template <nkr::generic::implementing::interface::none::value_tr type_p>
    class value_t<type_p>
    {
    public:
        using type_t        = type_p;
        using interface_t   = nkr::interface::none::value_i<type_t>;

    public:
        static constexpr value_t::type_t    Value() noexcept;

    public:
        constexpr value_t() noexcept;

        constexpr value_t(const value_t& other) noexcept;
        constexpr value_t(const volatile value_t& other) noexcept;
        constexpr value_t(value_t&& other) noexcept;
        constexpr value_t(volatile value_t&& other) noexcept;

        constexpr value_t&          operator =(const value_t& other) noexcept;
        constexpr volatile value_t& operator =(const value_t& other) volatile noexcept;
        constexpr value_t&          operator =(const volatile value_t& other) noexcept;
        constexpr volatile value_t& operator =(const volatile value_t& other) volatile noexcept;
        constexpr value_t&          operator =(value_t&& other) noexcept;
        constexpr volatile value_t& operator =(value_t&& other) volatile noexcept;
        constexpr value_t&          operator =(tr<just_volatile_tg, t<value_t>> auto&& other) noexcept;
        constexpr volatile value_t& operator =(tr<just_volatile_tg, t<value_t>> auto&& other) volatile noexcept;

#if defined(nkr_IS_DEBUG)
        constexpr ~value_t() noexcept;
#endif

    public:
        constexpr operator  value_t::type_t() const noexcept;
        constexpr operator  value_t::type_t() const volatile noexcept;

    public:
        constexpr value_t::type_t   operator ()() const noexcept;
        constexpr value_t::type_t   operator ()() const volatile noexcept;
    };

}}

constexpr nkr::boolean::cpp_t   operator ==(const nkr::tr<nkr::any_tg, nkr::t<nkr::none::value_tg>> auto& a, const auto& b) noexcept;
constexpr nkr::boolean::cpp_t   operator ==(const nkr::tr<nkr::any_tg, nkr::t<nkr::none::value_tg>> auto& a, const auto&& b) noexcept;
constexpr nkr::boolean::cpp_t   operator ==(const nkr::tr<nkr::any_tg, nkr::t<nkr::none::value_tg>> auto&& a, const auto& b) noexcept;
constexpr nkr::boolean::cpp_t   operator ==(const nkr::tr<nkr::any_tg, nkr::t<nkr::none::value_tg>> auto&& a, const auto&& b) noexcept;

constexpr nkr::boolean::cpp_t   operator !=(const nkr::tr<nkr::any_tg, nkr::t<nkr::none::value_tg>> auto& a, const auto& b) noexcept;
constexpr nkr::boolean::cpp_t   operator !=(const nkr::tr<nkr::any_tg, nkr::t<nkr::none::value_tg>> auto& a, const auto&& b) noexcept;
constexpr nkr::boolean::cpp_t   operator !=(const nkr::tr<nkr::any_tg, nkr::t<nkr::none::value_tg>> auto&& a, const auto& b) noexcept;
constexpr nkr::boolean::cpp_t   operator !=(const nkr::tr<nkr::any_tg, nkr::t<nkr::none::value_tg>> auto&& a, const auto&& b) noexcept;

#include "nkr/none/value_t_dec_def.h"
