/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsics_dec.h"

#include "nkr/interface/randomness_i_dec.h"

namespace nkr { namespace generic { namespace implementing { namespace interface {

    struct  randomness_tg   {};

    template <typename>
    struct  randomness_ttg  {};

    template <typename type_p>
    concept randomness_tr =
        nkr::interface::randomness_tr<nkr::interface::randomness_i<type_p>>;

    template <template <typename ...> typename template_p>
    concept randomness_ttr =
        randomness_tr<typename nkr::interface::template_i<template_p>::example_t>;

}}}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::generic::implementing::interface::randomness_tg>
    {
    public:
        using type_t    = nkr::generic::implementing::interface::randomness_tg;
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
    class template_i<nkr::generic::implementing::interface::randomness_ttg>
    {
    public:
        template <typename inner_p>
        using of_t      = nkr::generic::implementing::interface::randomness_tg;
        using example_t = nkr::generic::implementing::interface::randomness_tg;

    public:
        template <template <typename ...> typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr template_i(...) noexcept  = delete;
    };

}}

#include "nkr/generic/implementing/interface/randomness_tr_dec_def.h"
