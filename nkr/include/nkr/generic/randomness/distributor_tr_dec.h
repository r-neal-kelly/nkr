/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsics_dec.h"

#include "nkr/cpp/randomness/generator/software/mersenne_twister_19937_32_t_dec.h"
#include "nkr/cpp/randomness/generator/software/mersenne_twister_19937_64_t_dec.h"

#include "nkr/generic/implementing/self_tr_dec.h"
#include "nkr/generic/type_tr_dec.h"

namespace nkr { namespace generic { namespace randomness { namespace $distributor_tr {

    template <typename type_p>
    concept aliases_i =
        nkr::cpp::just_non_qualified_tr<typename type_p::value_t> &&
        nkr::generic::type_tr<typename type_p::value_t>;

    template <typename type_p>
    concept methods_i =
        (requires(type_p object,
                  const type_p const_object,
                  volatile type_p volatile_object,
                  const volatile type_p const_volatile_object,

                  nkr::cpp::randomness::generator::software::mersenne_twister_19937_32_t mersenne_twister_32,
                  nkr::cpp::randomness::generator::software::mersenne_twister_19937_64_t mersenne_twister_64)
    {
        { object.Value(mersenne_twister_32) }                   -> nkr::cpp::is_tr<typename type_p::value_t>;
        { const_object.Value(mersenne_twister_32) }             -> nkr::cpp::is_tr<typename type_p::value_t>;
        { volatile_object.Value(mersenne_twister_32) }          -> nkr::cpp::is_tr<typename type_p::value_t>;
        { const_volatile_object.Value(mersenne_twister_32) }    -> nkr::cpp::is_tr<typename type_p::value_t>;

        { object.Value(mersenne_twister_64) }                   -> nkr::cpp::is_tr<typename type_p::value_t>;
        { const_object.Value(mersenne_twister_64) }             -> nkr::cpp::is_tr<typename type_p::value_t>;
        { volatile_object.Value(mersenne_twister_64) }          -> nkr::cpp::is_tr<typename type_p::value_t>;
        { const_volatile_object.Value(mersenne_twister_64) }    -> nkr::cpp::is_tr<typename type_p::value_t>;
    });

    template <typename type_p>
    concept objects_i =
        nkr::generic::implementing::self_tr<type_p>;

}}}}

namespace nkr { namespace generic { namespace randomness {

    struct  distributor_tg  {};

    template <typename>
    struct  distributor_ttg {};

    template <typename type_p>
    concept distributor_tr =
        $distributor_tr::aliases_i<type_p> &&
        $distributor_tr::methods_i<type_p> &&
        $distributor_tr::objects_i<type_p>;

    template <template <typename ...> typename template_p>
    concept distributor_ttr =
        distributor_tr<typename interface::template_i<template_p>::example_t>;

}}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::generic::randomness::distributor_tg>
    {
    public:
        using type_t    = nkr::generic::randomness::distributor_tg;
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
    class template_i<nkr::generic::randomness::distributor_ttg>
    {
    public:
        template <typename inner_p>
        using of_t      = nkr::generic::randomness::distributor_tg;
        using example_t = nkr::generic::randomness::distributor_tg;

    public:
        template <template <typename ...> typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr template_i(...) noexcept  = delete;
    };

}}

#include "nkr/generic/randomness/distributor_tr_dec_def.h"