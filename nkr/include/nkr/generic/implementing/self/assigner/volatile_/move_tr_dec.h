/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/boolean/cpp_t_dec.h"
#include "nkr/generic/implementing/self/assigner/volatile_/move/non_volatile_tr_dec.h"
#include "nkr/generic/implementing/self/assigner/volatile_/move/volatile_tr_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/none/type_t_dec.h"

namespace nkr { namespace generic { namespace implementing { namespace self { namespace assigner { namespace volatile_ {

    struct  move_tg     {};

    template <typename>
    struct  move_ttg    {};

    template <typename type_p>
    concept move_tr =
        nkr::generic::implementing::self::assigner::volatile_::move::non_volatile_tr<type_p> &&
        nkr::generic::implementing::self::assigner::volatile_::move::volatile_tr<type_p>;

    template <template <typename ...> typename template_p>
    concept move_ttr =
        move_tr<typename nkr::interface::template_i<template_p>::example_t>;

}}}}}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::generic::implementing::self::assigner::volatile_::move_tg>
    {
    public:
        using type_t    = nkr::generic::implementing::self::assigner::volatile_::move_tg;
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
    class template_i<nkr::generic::implementing::self::assigner::volatile_::move_ttg>
    {
    public:
        template <typename inner_p>
        using of_t      = nkr::generic::implementing::self::assigner::volatile_::move_tg;
        using example_t = nkr::generic::implementing::self::assigner::volatile_::move_tg;

    public:
        template <template <typename ...> typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr template_i(...) noexcept  = delete;
    };

}}

#include "nkr/generic/implementing/self/assigner/volatile_/move_tr_dec_def.h"
