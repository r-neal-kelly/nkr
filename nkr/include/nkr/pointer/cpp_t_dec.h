/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/built_in/forward_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/cpp/generic/randomness/generator_tr_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/positive/index_t_dec.h"
#include "nkr/tuple/types_t_dec.h"
#include "nkr/tr_dec.h"

namespace nkr { namespace pointer {

    template <typename type_p>
    using   cpp_t =
        type_p*;

    struct  cpp_tg  {};

    template <typename>
    struct  cpp_ttg {};

    template <typename type_p>
    concept cpp_tr =
        nkr::cpp::pointer_tr<type_p>;

    template <template <typename ...> typename template_p>
    concept cpp_ttr =
        nkr::cpp::is_any_ttr<template_p, cpp_t, nkr::none::type_t>;

}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::pointer::cpp_tg>
    {
    public:
        using type_t    = nkr::pointer::cpp_tg;
        using of_t      = nkr::none::type_t;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr type_i(...) noexcept  = delete;
    };

    template <nkr::pointer::cpp_tr type_p>
    class type_i<type_p> :
        public type_i<nkr::pointer::cpp_tg>
    {
    public:
        using type_t    = type_p;
        using of_t      = nkr::cpp::pointer_unit_t<type_t>;
    };

}}

namespace nkr { namespace interface {

    template <>
    class template_i<nkr::pointer::cpp_ttg>
    {
    public:
        template <typename type_p>
        using template_t    = nkr::pointer::cpp_t<type_p>;

        template <typename inner_p>
        using of_t          = template_t<inner_p>;

        template <nkr::tuple::types_tr parameters_p>
            requires (parameters_p::Count() == 1)
        using of_tuple_t    = parameters_p::template into_t<template_t>;

        template <typename ...parameters_p>
        using of_pack_t     = of_tuple_t<nkr::tuple::types_t<parameters_p...>>;

        using example_t     = of_t<nkr::none::type_t>;

    public:
        template <template <typename ...> typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr template_i(...) noexcept  = delete;
    };

    template <template <typename ...> typename template_p>
        requires nkr::pointer::cpp_ttr<template_p>
    class template_i<template_p> :
        public template_i<nkr::pointer::cpp_ttg>
    {
    public:
    };

}}

namespace nkr { namespace pointer { namespace $cpp_t {

    template <nkr::pointer::cpp_tr type_p>
    class none_value_i_sp
    {
    public:
        using type_t    = type_p;
        using value_t   = nkr::cpp::just_non_qualified_t<type_t>;

    public:
        static constexpr value_t    Value() noexcept;

    public:
        template <typename ...>
        constexpr none_value_i_sp(...) noexcept = delete;
    };

}}}

namespace nkr { namespace interface { namespace none {

    template <nkr::pointer::cpp_tr type_p>
    class value_i_sp<type_p>
    {
    public:
        using type_t    = nkr::pointer::$cpp_t::none_value_i_sp<type_p>;
    };

}}}

namespace nkr { namespace pointer { namespace $cpp_t {

    template <nkr::pointer::cpp_tr type_p>
    class randomness_value_i_sp
    {
    public:
        using type_t    = type_p;
        using value_t   = nkr::cpp::just_non_qualified_t<type_t>;

    public:
        template <typename unused_p = nkr::none::type_t>
        static value_t  Value(value_t min = nkr::cpp::Default_Min<value_t>(), value_t max = nkr::cpp::Default_Max<value_t>()) noexcept;
        template <typename unused_p = nkr::none::type_t>
        static value_t  Value(tr<any_non_const_tg, t<nkr::cpp::generic::randomness::generator_tg>> auto& generator,
                              value_t min = nkr::cpp::Default_Min<value_t>(), value_t max = nkr::cpp::Default_Max<value_t>()) noexcept;

    public:
        template <typename ...>
        constexpr randomness_value_i_sp(...) noexcept   = delete;
    };

}}}

namespace nkr { namespace interface { namespace randomness {

    template <nkr::pointer::cpp_tr type_p>
    class value_i_sp<type_p>
    {
    public:
        using type_t    = nkr::pointer::$cpp_t::randomness_value_i_sp<type_p>;
    };

}}}

#include "nkr/pointer/cpp_t_dec_def.h"
