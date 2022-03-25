/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/built_in/forward_dec.h"
#include "nkr/constant/positive/count_t_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/generic/implementing/interface/none/value_tr_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/interface/none/value_i_dec.h"
#include "nkr/interface/template_i_identity_tag_t_dec.h"
#include "nkr/interface/template_i_identity_template_t_dec.h"
#include "nkr/tr_dec.h"
#include "nkr/tuple/types_t_dec.h"

namespace nkr { namespace none {

    template <typename type_p>
    class   value_t;

    struct  value_tg    { class tag_lb; };

    template <typename ...>
    struct  value_ttg   {};

    template <typename type_p>
    concept value_tr =
        nkr::cpp::is_any_tr<type_p, value_t<typename type_p::type_t>>;

    template <template <typename ...> typename template_p>
    concept value_ttr =
        nkr::cpp::is_any_ttr<template_p, value_t, nkr::positive::integer_t>;

}}

namespace nkr { namespace none { namespace value_t$ {

    template <nkr::none::value_tr type_p>
    class type_i_type_sp
    {
    public:
        using type_t    = type_p;
        using of_t      = type_t::type_t;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any_General() noexcept;
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any_Specific() noexcept;

    public:
        template <typename ...>
        constexpr type_i_type_sp(...) noexcept  = delete;
    };

    template <nkr::cpp::is_any_tr<nkr::none::value_tg> type_p>
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

    template <nkr::none::value_tr type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::none::value_t$::type_i_type_sp<type_p>;
    };

    template <nkr::cpp::is_any_tr<nkr::none::value_tg> type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::none::value_t$::type_i_tag_sp<type_p>;
    };

}}

namespace nkr { namespace none { namespace value_t$ {

    template <template <typename ...> typename template_p>
        requires nkr::none::value_ttr<template_p>
    class template_i_template_sp :
        public nkr::interface::template_i_identity_template_t<
            nkr::none::value_t,
            nkr::tuple::types_t<nkr::positive::integer_t>,
            nkr::constant::positive::count_t<1>,
            nkr::constant::positive::count_t<1>,
            nkr::none::value_tg,
            nkr::none::value_ttg
        >
    {
    public:
    };

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::none::value_ttg>
    class template_i_tag_sp :
        public nkr::interface::template_i_identity_tag_t<
            template_i_template_sp<nkr::none::value_t>
        >
    {
    public:
    };

}}}

namespace nkr { namespace interface {

    template <template <typename ...> typename template_p>
        requires nkr::none::value_ttr<template_p>
    class template_i_sp<template_p>
    {
    public:
        using type_t    = nkr::none::value_t$::template_i_template_sp<template_p>;
    };

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::none::value_ttg>
    class template_i_sp<template_p>
    {
    public:
        using type_t    = nkr::none::value_t$::template_i_tag_sp<template_p>;
    };

}}

namespace nkr { namespace none {

    template <nkr::generic::implementing::interface::none::value_tr type_p>
    class value_t<type_p>
    {
    public:
        using interface_t   = nkr::interface::none::value_i<type_p>;
        using type_t        = interface_t::value_t;

    public:
        static constexpr type_t Value() noexcept;

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
        constexpr operator  value_t<type_p>::type_t() const noexcept;
        constexpr operator  value_t<type_p>::type_t() const volatile noexcept;

    public:
        constexpr type_t    operator ()() const noexcept;
        constexpr type_t    operator ()() const volatile noexcept;
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
