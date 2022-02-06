/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/built_in/forward_dec.h"
#include "nkr/generic/implementing/self/assigner/volatile_/copy_tr_dec.h"
#include "nkr/generic/implementing/self/assigner/volatile_/move_tr_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/interface/template_i_generic_aliases_t_dec.h"

namespace nkr { namespace generic { namespace implementing { namespace self { namespace assigner {

    struct  volatile_tg     {};

    template <typename>
    struct  volatile_ttg    {};

    template <typename type_p>
    concept volatile_tr =
        nkr::generic::implementing::self::assigner::volatile_::copy_tr<type_p> &&
        nkr::generic::implementing::self::assigner::volatile_::move_tr<type_p>;

    template <template <typename ...> typename template_p>
    concept volatile_ttr =
        volatile_tr<typename nkr::interface::template_i<template_p>::example_t>;

}}}}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::generic::implementing::self::assigner::volatile_tg>
    {
    public:
        using type_t    = nkr::generic::implementing::self::assigner::volatile_tg;
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
    class template_i<nkr::generic::implementing::self::assigner::volatile_ttg> :
        public nkr::interface::template_i_generic_aliases_t<nkr::generic::implementing::self::assigner::volatile_tg>
    {
    public:
        template <template <typename ...> typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr template_i(...) noexcept  = delete;
    };

}}

#include "nkr/generic/implementing/self/assigner/volatile_tr_dec_def.h"
