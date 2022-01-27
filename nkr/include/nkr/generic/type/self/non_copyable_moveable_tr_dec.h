/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/boolean/cpp_t_dec.h"
#include "nkr/generic/implementing/self_tr_dec.h"
#include "nkr/generic/type_tr_dec.h"
#include "nkr/none/type_t_dec.h"

namespace nkr { namespace interface {

    template <template <typename ...> typename template_p>
    class   template_i;

}}

namespace nkr { namespace interface {

    template <typename type_p>
    class   type_i;

}}

namespace nkr { namespace generic { namespace type { namespace self {

    struct  non_copyable_moveable_tg    {};

    template <typename>
    struct  non_copyable_moveable_ttg   {};

    template <typename type_p>
    concept non_copyable_moveable_tr =
        nkr::generic::type_tr<type_p> &&

        !nkr::generic::implementing::self::constructor::copy::non_volatile_tr<type_p> &&
        !nkr::generic::implementing::self::constructor::copy::volatile_tr<type_p> &&
        !nkr::generic::implementing::self::assigner::non_volatile::copy::non_volatile_tr<type_p> &&
        !nkr::generic::implementing::self::assigner::non_volatile::copy::volatile_tr<type_p> &&
        !nkr::generic::implementing::self::assigner::volatile_::copy::non_volatile_tr<type_p> &&
        !nkr::generic::implementing::self::assigner::volatile_::copy::volatile_tr<type_p> &&

        nkr::generic::implementing::self::constructor::move::non_volatile_tr<type_p> &&
        nkr::generic::implementing::self::constructor::move::volatile_tr<type_p> &&
        nkr::generic::implementing::self::assigner::non_volatile::move::non_volatile_tr<type_p> &&
        nkr::generic::implementing::self::assigner::non_volatile::move::volatile_tr<type_p> &&
        nkr::generic::implementing::self::assigner::volatile_::move::non_volatile_tr<type_p> &&
        nkr::generic::implementing::self::assigner::volatile_::move::volatile_tr<type_p>;

    template <template <typename ...> typename template_p>
    concept non_copyable_moveable_ttr =
        non_copyable_moveable_tr<typename nkr::interface::template_i<template_p>::example_t>;

}}}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::generic::type::self::non_copyable_moveable_tg>
    {
    public:
        using type_t    = nkr::generic::type::self::non_copyable_moveable_tg;
        using of_t      = nkr::none::type_t;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr type_i(...) noexcept  = delete;
    };

}}

namespace nkr { namespace interface {

    template <>
    class template_i<nkr::generic::type::self::non_copyable_moveable_ttg>
    {
    public:
        template <typename inner_p>
        using of_t      = nkr::generic::type::self::non_copyable_moveable_tg;
        using example_t = nkr::generic::type::self::non_copyable_moveable_tg;

    public:
        template <template <typename ...> typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr template_i(...) noexcept  = delete;
    };

}}

#include "nkr/generic/type/self/non_copyable_moveable_tr_dec_def.h"
