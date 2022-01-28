/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/boolean/cpp_t_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/none/type_t_dec.h"
#include "nkr/positive/count_t_dec.h"
#include "nkr/positive/integer_t_dec.h"
#include "nkr/tuple/types_t_dec.h"

namespace nkr { namespace array {

    template <nkr::cpp::type_tr type_p, nkr::positive::count_ctr capacity_p>
    using   cpp_t =
        type_p[capacity_p::Value()];

    struct  cpp_tg  {};

    template <typename>
    struct  cpp_ttg {};

    template <typename type_p>
    concept cpp_tr =
        nkr::cpp::array_tr<type_p>;

    template <template <typename ...> typename template_p>
    concept cpp_ttr =
        nkr::cpp::is_any_ttr<template_p, cpp_t, nkr::positive::integer_t, nkr::positive::count_c<1>>;

    template <nkr::cpp::type_tr type_p, nkr::positive::count_t capacity_p, type_p value_p[capacity_p]>
    using   cpp_c =
        nkr::cpp::constant_t<type_p[capacity_p], value_p>;

    template <typename type_p>
    concept cpp_ctr =
        nkr::cpp::constant_of_tr<type_p, nkr::cpp::array_unit_t<type_p>[nkr::cpp::Array_Capacity<type_p>()]>;

}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::array::cpp_tg>
    {
    public:
        using type_t    = nkr::array::cpp_tg;
        using of_t      = nkr::none::type_t;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr type_i(...) noexcept  = delete;
    };

    template <nkr::array::cpp_tr type_p>
    class type_i<type_p> :
        public type_i<nkr::array::cpp_tg>
    {
    public:
        using type_t    = type_p;
        using of_t      = nkr::cpp::array_unit_t<type_t>;
    };

}}

namespace nkr { namespace interface {

    template <>
    class template_i<nkr::array::cpp_ttg>
    {
    public:
        template <nkr::cpp::type_tr type_p, nkr::positive::count_ctr capacity_p>
        using template_t    = nkr::array::cpp_t<type_p, capacity_p>;

        template <typename inner_p>
        using of_t          = template_t<inner_p, nkr::positive::count_c<1>>;

        template <nkr::tuple::types_tr parameters_p>
            requires (parameters_p::Count() == 2)
        using of_tuple_t    = parameters_p::template into_t<template_t>;

        template <typename ...parameters_p>
        using of_pack_t     = of_tuple_t<nkr::tuple::types_t<parameters_p...>>;

        using example_t     = of_t<nkr::positive::integer_t>;

    public:
        template <template <typename ...> typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr template_i(...) noexcept  = delete;
    };

    template <template <typename ...> typename template_p>
        requires nkr::array::cpp_ttr<template_p>
    class template_i<template_p> :
        public template_i<nkr::array::cpp_ttg>
    {
    public:
    };

}}

#include "nkr/array/cpp_t_dec_def.h"
