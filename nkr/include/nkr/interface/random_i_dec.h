/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsics_dec.h"

#include "nkr/generic/implementing/constructor/default_tr_dec.h"
#include "nkr/generic/type_tr_dec.h"

namespace nkr { namespace interface { namespace $random_i {

    template <typename type_p>
    concept aliases_i =
        cpp::just_non_qualified_tr<typename type_p::type_t> &&
        nkr::generic::type_tr<typename type_p::type_t>;

    template <typename type_p>
    concept static_functions_i = requires
    {
        { type_p::Value() } -> cpp::is_tr<typename type_p::type_t>;
        // should also accept a generic::randomness::generator_tr, but above it needs to be defaulted by the implementor
        // it can also have any number of overloads to facilitate use per type, not constrained here of course. it should accept a last param defaulted to generic::randomness::generator_tr though.
    };

    template <typename type_p>
    concept objects_i =
        !generic::implementing::constructor::default_tr<type_p>;

}}}

namespace nkr { namespace interface {

    template <typename type_p>
    class   random_i;

    struct  random_tg   {};

    template <typename>
    struct  random_ttg  {};

    template <typename type_p>
    concept random_tr =
        cpp::is_any_tr<type_p, random_i<typename type_p::type_t>> &&
        $random_i::aliases_i<type_p> &&
        $random_i::static_functions_i<type_p> &&
        $random_i::objects_i<type_p>;

    template <template <typename ...> typename template_p>
    concept random_ttr =
        cpp::is_any_ttr<template_p, random_i, nkr::positive::integer_t>;

}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::interface::random_tg>
    {
    public:
        using type_t    = nkr::interface::random_tg;
        using of_t      = nkr::none::type_t;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr type_i(...) noexcept  = delete;
    };

    template <nkr::interface::random_tr type_p>
    class type_i<type_p> :
        public type_i<nkr::interface::random_tg>
    {
    public:
        using type_t    = type_p;
        using of_t      = type_t::type_t;
    };

}}

namespace nkr { namespace interface {

    template <>
    class template_i<nkr::interface::random_ttg>
    {
    public:
        template <typename inner_p>
        using of_t      = nkr::interface::random_i<inner_p>;
        using example_t = of_t<nkr::positive::integer_t>;

    public:
        template <template <typename ...> typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr template_i(...) noexcept  = delete;
    };

    template <template <typename ...> typename template_p>
        requires nkr::interface::random_ttr<template_p>
    class template_i<template_p> :
        public template_i<nkr::interface::random_ttg>
    {
    public:
    };

}}

#include "nkr/interface/random_i_dec_def.h"
