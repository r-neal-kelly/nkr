/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/boolean/cpp_t_dec.h"
#include "nkr/cpp/randomness/distributor/uniform/integer_t_dec.h"
#include "nkr/cpp/randomness/distributor/uniform/real_t_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/none/type_t_dec.h"

namespace nkr { namespace cpp { namespace generic { namespace randomness { namespace distributor {

    struct  uniform_tg  {};

    template <typename>
    struct  uniform_ttg {};

    template <typename type_p>
    concept uniform_tr =
        nkr::cpp::randomness::distributor::uniform::integer_tr<type_p> ||
        nkr::cpp::randomness::distributor::uniform::real_tr<type_p>;

    template <template <typename ...> typename template_p>
    concept uniform_ttr =
        uniform_tr<typename nkr::interface::template_i<template_p>::example_t>;

}}}}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::cpp::generic::randomness::distributor::uniform_tg>
    {
    public:
        using type_t    = nkr::cpp::generic::randomness::distributor::uniform_tg;
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
    class template_i<nkr::cpp::generic::randomness::distributor::uniform_ttg>
    {
    public:
        template <typename inner_p>
        using of_t      = nkr::cpp::generic::randomness::distributor::uniform_tg;
        using example_t = nkr::cpp::generic::randomness::distributor::uniform_tg;

    public:
        template <template <typename ...> typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr template_i(...) noexcept  = delete;
    };

}}

#include "nkr/cpp/generic/randomness/distributor/uniform_tr_dec_def.h"
