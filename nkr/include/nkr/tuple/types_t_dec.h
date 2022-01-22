/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsics_dec.h"

namespace nkr { namespace tuple { namespace $types_t {

    template <typename type_p>
    class   is_tmpl;

}}}

namespace nkr { namespace tuple {

    template <typename ...types_p>
    class   types_t;

    struct  types_tg    {};

    template <typename>
    struct  types_ttg   {};

    template <typename type_p>
    concept types_tr =
        $types_t::is_tmpl<nkr::cpp::just_non_qualified_t<type_p>>::Value();

    template <template <typename ...> typename template_p>
    concept types_ttr =
        nkr::cpp::is_any_ttr<template_p, types_t, nkr::positive::integer_t>;

}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::tuple::types_tg>
    {
    public:
        using type_t    = nkr::tuple::types_tg;
        using of_t      = nkr::none::type_t;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr type_i(...) noexcept  = delete;
    };

    template <nkr::tuple::types_tr type_p>
    class type_i<type_p> :
        public type_i<nkr::tuple::types_tg>
    {
    public:
        using type_t    = type_p;
        using of_t      = type_p::template at_t<nkr::positive::index_c<0>>;
    };

}}

namespace nkr { namespace interface {

    template <>
    class template_i<nkr::tuple::types_ttg>
    {
    public:
        template <typename inner_p>
        using of_t      = nkr::tuple::types_t<inner_p>;
        using example_t = of_t<nkr::positive::integer_t>;

    public:
        template <template <typename ...> typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr template_i(...) noexcept  = delete;
    };

    template <template <typename ...> typename template_p>
        requires nkr::tuple::types_ttr<template_p>
    class template_i<template_p> :
        public template_i<nkr::tuple::types_ttg>
    {
    public:
    };

}}

namespace nkr { namespace tuple { namespace $types_t {

    template <typename type_p>
    class is_tmpl :
        public nkr::boolean::cpp_c<false>
    {
    public:
    };

    template <typename head_p, typename ...tail_p>
    class is_tmpl<types_t<head_p, tail_p...>> :
        public nkr::boolean::cpp_c<true>
    {
    public:
    };

}}}

namespace nkr { namespace tuple { namespace $types_t {

    template <typename tuple_p, nkr::positive::index_t index_p>
    class unit_t;

    template <typename head_p, typename ...tail_p>
    class unit_t<types_t<head_p, tail_p...>, 0>
    {
    public:
        using type_t    = head_p;
    };

    template <typename head_p, typename ...tail_p, nkr::positive::index_t index_p>
    class unit_t<types_t<head_p, tail_p...>, index_p> :
        public unit_t<types_t<tail_p...>, index_p - 1>
    {
    public:
    };

}}}

namespace nkr { namespace tuple {

    template <typename head_p, typename ...tail_p>
    class types_t<head_p, tail_p...>
    {
    public:
        using head_t    = head_p;
        using tail_t    = types_t<tail_p...>;
        template <nkr::cpp::constant_of_tr<nkr::positive::index_t> index_p>
        using at_t      = $types_t::unit_t<types_t, index_p::Value()>::type_t;

    public:
        static constexpr nkr::positive::count_t Count() noexcept;

    public:
        template <typename ...>
        constexpr types_t(...) noexcept = delete;
    };

}}

#include "nkr/tuple/types_t_dec_def.h"
