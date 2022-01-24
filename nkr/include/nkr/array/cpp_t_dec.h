/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/tr_dec.h"

#include "nkr/generic/array_tr_dec.h"
#include "nkr/generic/array/any_tr_dec.h"

namespace nkr { namespace array {

    struct  cpp_tg  {};

    template <typename>
    struct  cpp_ttg {};

    template <typename type_p>
    concept cpp_tr =
        cpp::array_tr<type_p>;

    template <template <typename ...> typename template_p>
    concept cpp_ttr =
        cpp::is_any_ttr<template_p, cpp_t, positive::word_t, positive::count_c<1>>;

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
        template <typename inner_p>
        using of_t          = nkr::array::cpp_t<inner_p, nkr::positive::count_c<1>>;
        template <nkr::tuple::types_tr parameters_p>
            requires (parameters_p::Count() == 2)
        using of_tuple_t    = nkr::array::cpp_t<
            typename parameters_p::template at_t<nkr::positive::index_c<0>>,
            typename parameters_p::template at_t<nkr::positive::index_c<1>>
        >;
        template <typename ...parameters_p>
        using of_pack_t     = of_tuple_t<nkr::tuple::types_t<parameters_p...>>;

        using example_t     = of_t<nkr::positive::word_t>;

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

namespace nkr { namespace array {

    static_assert(generic::array_tr<cpp_t<positive::integer_t, positive::count_c<2>>>);
    static_assert(generic::array_tr<const cpp_t<positive::integer_t, positive::count_c<2>>>);
    static_assert(generic::array_tr<volatile cpp_t<positive::integer_t, positive::count_c<2>>>);
    static_assert(generic::array_tr<const volatile cpp_t<positive::integer_t, positive::count_c<2>>>);

    static_assert(generic::array::any_tr<cpp_t<positive::integer_t, positive::count_c<2>>>);
    static_assert(generic::array::any_tr<const cpp_t<positive::integer_t, positive::count_c<2>>>);
    static_assert(generic::array::any_tr<volatile cpp_t<positive::integer_t, positive::count_c<2>>>);
    static_assert(generic::array::any_tr<const volatile cpp_t<positive::integer_t, positive::count_c<2>>>);

}}
