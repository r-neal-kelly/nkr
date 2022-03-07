/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/built_in/forward_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/generic/type_tr_dec.h"

namespace nkr {

    /// @copydoc _09f6d63e_f4b7_46e1_b499_fcfa5132d76f
    template <nkr::generic::type_tr type_p, type_p value_p>
    class   constant_t;

    struct  constant_tg     { class tag_lb; };

    template <typename>
    struct  constant_ttg    {};

    template <typename type_p>
    concept constant_tr =
        nkr::cpp::is_any_tr<type_p, constant_t<typename type_p::value_t, type_p::Value()>>;

    template <template <typename ...> typename template_p>
    concept constant_ttr =
        nkr::cpp::is_any_ttr<template_p, constant_t, nkr::positive::integer_t>;

}

namespace nkr {

    template <typename type_p, typename value_p>
    concept constant_of_tr =
        nkr::constant_tr<type_p> &&
        nkr::cpp::is_tr<typename type_p::value_t, value_p>;

}

namespace nkr {

    template <nkr::generic::type_tr type_p, type_p value_p>
    class constant_t
    {
    public:
        /// @name aliases
        /// @{
        using value_t   = type_p;
        /// @}

    public:
        /// @name static functions
        /// @{
        static constexpr value_t    Value() noexcept;
        /// @}

    public:
        /// @name constructors
        /// @{
        constexpr constant_t() noexcept;

        constexpr constant_t(const constant_t& other) noexcept;
        constexpr constant_t(const volatile constant_t& other) noexcept;
        constexpr constant_t(constant_t&& other) noexcept;
        constexpr constant_t(volatile constant_t&& other) noexcept;
        /// @}

        /// @name assigners
        /// @{
        constexpr constant_t&           operator =(const constant_t& other) noexcept                    = delete;
        constexpr volatile constant_t&  operator =(const constant_t& other) volatile noexcept           = delete;
        constexpr constant_t&           operator =(const volatile constant_t& other) noexcept           = delete;
        constexpr volatile constant_t&  operator =(const volatile constant_t& other) volatile noexcept  = delete;
        constexpr constant_t&           operator =(constant_t&& other) noexcept                         = delete;
        constexpr volatile constant_t&  operator =(constant_t&& other) volatile noexcept                = delete;
        constexpr constant_t&           operator =(volatile constant_t&& other) noexcept                = delete;
        constexpr volatile constant_t&  operator =(volatile constant_t&& other) volatile noexcept       = delete;
        /// @}

    public:
        /// @name casts
        /// @{
        constexpr operator  constant_t<type_p, value_p>::value_t() const noexcept;
        constexpr operator  constant_t<type_p, value_p>::value_t() const volatile noexcept;
        /// @}

    public:
        /// @name operators
        /// @{
        constexpr value_t   operator ()() const noexcept;
        constexpr value_t   operator ()() const volatile noexcept;
        /// @}
    };

}

#include "nkr/constant_t_dec_def.h"
