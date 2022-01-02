/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsics_dec.h"

#include "nkr/generic/implementing/constructor/default_tr_dec.h"
#include "nkr/generic/type_tr_dec.h"

namespace nkr { namespace interface { namespace $type_i {

    template <typename type_p>
    concept aliases_i = requires
    {
        typename type_p::type_t;
        typename type_p::of_t;
        cpp::just_non_qualified_tr<typename type_p::type_t>;
        nkr::generic::type_tr<typename type_p::type_t>;
    };

    template <typename type_p>
    concept static_constexpr_functions_i = requires
    {
        { type_p::template Is_Any<typename type_p::type_t>() }  -> cpp::is_tr<boolean::cpp_t>;
    };

    template <typename type_p>
    concept objects_i =
        !generic::implementing::constructor::default_tr<type_p>;

}}}

namespace nkr { namespace interface {

    struct  type_tg     {};

    template <typename type_p>
    struct  type_ttg    {};

    template <typename type_p>
    concept type_tr =
        cpp::is_any_tr<type_p, type_i<typename type_p::type_t>> &&
        $type_i::aliases_i<type_p> &&
        $type_i::static_constexpr_functions_i<type_p> &&
        $type_i::objects_i<type_p>;

    template <template <typename ...> typename template_p>
    concept type_ttr =
        cpp::is_any_ttr<template_p, type_i, nkr::none::type_t>;

}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::interface::type_tg>
    {
    public:
        using type_t    = nkr::interface::type_tg;
        using of_t      = nkr::none::type_t;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr type_i(...) noexcept  = delete;
    };

    template <nkr::interface::type_tr type_p>
    class type_i<type_p> :
        public type_i<nkr::interface::type_tg>
    {
    public:
        using type_t    = type_p;
        using of_t      = type_t::type_t;
    };

}}

namespace nkr { namespace interface {

    template <>
    class template_i<nkr::interface::type_ttg>
    {
    public:
        template <typename inner_p>
        using of_t      = nkr::interface::type_i<inner_p>;
        using example_t = of_t<nkr::none::type_t>;

    public:
        template <template <typename ...> typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr template_i(...) noexcept  = delete;
    };

    template <template <typename ...> typename template_p>
        requires nkr::interface::type_ttr<template_p>
    class template_i<template_p> :
        public template_i<nkr::interface::type_ttg>
    {
    public:
    };

}}

#include "nkr/interface/type_i_dec_def.h"
