/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/boolean/cpp_t_dec.h"
#include "nkr/interface/none/value_i_dec.h"
#include "nkr/none/type_t_dec.h"

namespace nkr { namespace interface {

    template <template <typename ...> typename template_p>
    class   template_i;

}}

namespace nkr { namespace interface {

    template <typename type_p>
    class   type_i;

}}

namespace nkr { namespace generic { namespace implementing { namespace interface { namespace none {

    struct  value_tg    {};

    template <typename>
    struct  value_ttg   {};

    template <typename type_p>
    concept value_tr =
        nkr::interface::none::value_tr<nkr::interface::none::value_i<type_p>>;

    template <template <typename ...> typename template_p>
    concept value_ttr =
        value_tr<typename nkr::interface::template_i<template_p>::example_t>;

}}}}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::generic::implementing::interface::none::value_tg>
    {
    public:
        using type_t    = nkr::generic::implementing::interface::none::value_tg;
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
    class template_i<nkr::generic::implementing::interface::none::value_ttg>
    {
    public:
        template <typename inner_p>
        using of_t      = nkr::generic::implementing::interface::none::value_tg;
        using example_t = nkr::generic::implementing::interface::none::value_tg;

    public:
        template <template <typename ...> typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr template_i(...) noexcept  = delete;
    };

}}

#include "nkr/generic/implementing/interface/none/value_tr_dec_def.h"
