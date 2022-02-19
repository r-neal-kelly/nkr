/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/built_in/forward_dec.h"
#include "nkr/generic/built_in/number/enumeration/any_tr_dec.h"
#include "nkr/generic/built_in/number/enumeration/limited_tr_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/interface/template_i_generic_aliases_t_dec.h"

namespace nkr { namespace generic { namespace built_in { namespace number { namespace enumeration {

    struct  unlimited_tg    {};

    template <typename>
    struct  unlimited_ttg   {};

    template <typename type_p>
    concept unlimited_tr =
        nkr::generic::built_in::number::enumeration::any_tr<type_p> &&
        !nkr::generic::built_in::number::enumeration::limited_tr<type_p>;

    template <template <typename ...> typename template_p>
    concept unlimited_ttr =
        unlimited_tr<typename interface::template_i<template_p>::example_t>;

}}}}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::generic::built_in::number::enumeration::unlimited_tg>
    {
    public:
        using type_t    = nkr::generic::built_in::number::enumeration::unlimited_tg;
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
    class template_i<nkr::generic::built_in::number::enumeration::unlimited_ttg> :
        public nkr::interface::template_i_generic_aliases_t<nkr::generic::built_in::number::enumeration::unlimited_tg>
    {
    public:
        template <template <typename ...> typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr template_i(...) noexcept  = delete;
    };

}}

#include "nkr/generic/built_in/number/enumeration/unlimited_tr_dec_def.h"
