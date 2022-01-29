/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/boolean/cpp_t_dec.h"
#include "nkr/cpp/generic/randomness/distributor/uniform_tr_dec.h"
#include "nkr/cpp/randomness/distributor/bernoulli_t_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/interface/template_i_generic_aliases_t_dec.h"
#include "nkr/none/type_t_dec.h"

namespace nkr { namespace cpp { namespace generic { namespace randomness {

    struct  distributor_tg  {};

    template <typename>
    struct  distributor_ttg {};

    template <typename type_p>
    concept distributor_tr =
        nkr::cpp::randomness::distributor::bernoulli_tr<type_p> ||
        nkr::cpp::generic::randomness::distributor::uniform_tr<type_p>;

    template <template <typename ...> typename template_p>
    concept distributor_ttr =
        distributor_tr<typename nkr::interface::template_i<template_p>::example_t>;

}}}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::cpp::generic::randomness::distributor_tg>
    {
    public:
        using type_t    = nkr::cpp::generic::randomness::distributor_tg;
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
    class template_i<nkr::cpp::generic::randomness::distributor_ttg> :
        public nkr::interface::template_i_generic_aliases_t<nkr::cpp::generic::randomness::distributor_tg>
    {
    public:
        template <template <typename ...> typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr template_i(...) noexcept  = delete;
    };

}}

#include "nkr/cpp/generic/randomness/distributor_tr_dec_def.h"
