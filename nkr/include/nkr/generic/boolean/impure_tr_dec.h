/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/built_in/forward_dec.h"
#include "nkr/generic/boolean/any_tr_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/interface/template_i_generic_aliases_t_dec.h"

namespace nkr { namespace generic { namespace boolean { namespace $impure_tr {

    template <typename type_p>
    concept any_impure_operator_i =
        requires(type_p type) { +type; } ||
        requires(type_p type) { -type; } ||

        requires(type_p type) { type + 1; } ||
        requires(type_p type) { type - 1; } ||
        requires(type_p type) { type * 1; } ||
        requires(type_p type) { type / 1; } ||
        requires(type_p type) { type % 1; } ||

        requires(type_p type) { ~type; } ||
        requires(type_p type) { type | 1; } ||
        requires(type_p type) { type & 1; } ||
        requires(type_p type) { type ^ 1; } ||
        requires(type_p type) { type << 1; } ||
        requires(type_p type) { type >> 1; } ||

        requires(type_p type) { type += 1; } ||
        requires(type_p type) { type -= 1; } ||
        requires(type_p type) { type *= 1; } ||
        requires(type_p type) { type /= 1; } ||
        requires(type_p type) { type %= 1; } ||

        requires(type_p type) { type |= 1; } ||
        requires(type_p type) { type &= 1; } ||
        requires(type_p type) { type ^= 1; } ||
        requires(type_p type) { type <<= 1; } ||
        requires(type_p type) { type >>= 1; } ||

        requires(type_p type) { ++type; } ||
        requires(type_p type) { type++; } ||
        requires(type_p type) { --type; } ||
        requires(type_p type) { type--; } ||

        requires(type_p type) { type < 1; } ||
        requires(type_p type) { type > 1; } ||
        requires(type_p type) { type <= 1; } ||
        requires(type_p type) { type >= 1; } ||
        requires(type_p type) { type <=> 1; };

}}}}

namespace nkr { namespace generic { namespace boolean {

    struct  impure_tg   {};

    template <typename>
    struct  impure_ttg  {};

    template <typename type_p>
    concept impure_tr =
        nkr::generic::boolean::any_tr<type_p> &&
        $impure_tr::any_impure_operator_i<type_p>;

    template <template <typename ...> typename template_p>
    concept impure_ttr =
        impure_tr<typename interface::template_i<template_p>::example_t>;

}}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::generic::boolean::impure_tg>
    {
    public:
        using type_t    = nkr::generic::boolean::impure_tg;
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
    class template_i<nkr::generic::boolean::impure_ttg> :
        public nkr::interface::template_i_generic_aliases_t<nkr::generic::boolean::impure_tg>
    {
    public:
        template <template <typename ...> typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr template_i(...) noexcept  = delete;
    };

}}

#include "nkr/generic/boolean/impure_tr_dec_def.h"
