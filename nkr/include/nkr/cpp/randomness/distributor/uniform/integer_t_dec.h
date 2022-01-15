/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/tr_dec.h"

namespace nkr { namespace cpp { namespace randomness { namespace distributor { namespace uniform {

    template <typename integer_p>
    using   integer_t =
        std::uniform_int_distribution<integer_p>;

    struct  integer_tg  {};

    template <typename>
    struct  integer_ttg {};

    template <typename type_p>
    concept integer_tr =
        nkr::cpp::is_any_tr<type_p, integer_t<typename type_p::result_type>>;

    template <template <typename ...> typename template_p>
    concept integer_ttr =
        nkr::cpp::is_any_ttr<template_p, integer_t, positive::integer_t>;

}}}}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::cpp::randomness::distributor::uniform::integer_tg>
    {
    public:
        using type_t    = nkr::cpp::randomness::distributor::uniform::integer_tg;
        using of_t      = nkr::none::type_t;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr type_i(...) noexcept  = delete;
    };

    template <nkr::cpp::randomness::distributor::uniform::integer_tr type_p>
    class type_i<type_p> :
        public type_i<nkr::cpp::randomness::distributor::uniform::integer_tg>
    {
    public:
        using type_t    = type_p;
        using of_t      = type_p::result_type;
    };

}}

namespace nkr { namespace interface {

    template <>
    class template_i<nkr::cpp::randomness::distributor::uniform::integer_ttg>
    {
    public:
        template <typename inner_p>
        using of_t      = nkr::cpp::randomness::distributor::uniform::integer_t<inner_p>;
        using example_t = of_t<nkr::positive::integer_t>;

    public:
        template <template <typename ...> typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr template_i(...) noexcept  = delete;
    };

    template <template <typename ...> typename template_p>
        requires nkr::cpp::randomness::distributor::uniform::integer_ttr<template_p>
    class template_i<template_p> :
        public template_i<nkr::cpp::randomness::distributor::uniform::integer_ttg>
    {
    public:
    };

}}

#include "nkr/cpp/randomness/distributor/uniform/integer_t_dec_def.h"
