/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/tr_dec.h"

namespace nkr { namespace random { namespace distributor { namespace cpp { namespace uniform {

    template <typename real_p>
    using   real_t =
        nkr::cpp::random::distributor::uniform::real_t<real_p>;

    struct  real_tg     {};

    template <typename>
    struct  real_ttg    {};

    template <typename type_p>
    concept real_tr =
        nkr::cpp::random::distributor::uniform::real_tr<type_p>;

    template <template <typename ...> typename template_p>
    concept real_ttr =
        nkr::cpp::is_any_ttr<template_p, real_t, negatable::real_t>;

}}}}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::random::distributor::cpp::uniform::real_tg>
    {
    public:
        using type_t    = nkr::random::distributor::cpp::uniform::real_tg;
        using of_t      = nkr::none::type_t;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr type_i(...) noexcept  = delete;
    };

    template <nkr::random::distributor::cpp::uniform::real_tr type_p>
    class type_i<type_p> :
        public type_i<nkr::random::distributor::cpp::uniform::real_tg>
    {
    public:
        using type_t    = type_p;
        using of_t      = type_p::result_type;
    };

}}

namespace nkr { namespace interface {

    template <>
    class template_i<nkr::random::distributor::cpp::uniform::real_ttg>
    {
    public:
        template <typename inner_p>
        using of_t      = nkr::random::distributor::cpp::uniform::real_t<inner_p>;
        using example_t = of_t<nkr::negatable::real_t>;

    public:
        template <template <typename ...> typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr template_i(...) noexcept  = delete;
    };

    template <template <typename ...> typename template_p>
        requires nkr::random::distributor::cpp::uniform::real_ttr<template_p>
    class template_i<template_p> :
        public template_i<nkr::random::distributor::cpp::uniform::real_ttg>
    {
    public:
    };

}}

#include "nkr/random/distributor/cpp/uniform/real_t_dec_def.h"
