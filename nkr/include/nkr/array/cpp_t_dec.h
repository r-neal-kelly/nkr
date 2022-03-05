/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/built_in/forward_dec.h"
#include "nkr/constant/positive/count_t_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/generic/type_tr_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/tuple/types_t_dec.h"

namespace nkr { namespace array {

    template <nkr::generic::type_tr type_p, nkr::constant::positive::count_tr capacity_p>
    using   cpp_t =
        type_p[capacity_p::Value()];

    struct  cpp_tg  { class tag_lb; };

    template <typename>
    struct  cpp_ttg {};

    template <typename type_p>
    concept cpp_tr =
        nkr::cpp::array_tr<type_p>;

    template <template <typename ...> typename template_p>
    concept cpp_ttr =
        nkr::cpp::is_any_ttr<template_p, cpp_t, nkr::positive::integer_t, nkr::constant::positive::count_t<1>>;

}}

namespace nkr { namespace array { namespace $cpp_t {

    template <nkr::array::cpp_tr type_p>
    class type_i_type_sp
    {
    public:
        using type_t    = type_p;
        using of_t      = nkr::cpp::array_unit_t<type_t>;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any_General() noexcept;
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any_Specific() noexcept;

    public:
        template <typename ...>
        constexpr type_i_type_sp(...) noexcept  = delete;
    };

    template <nkr::cpp::is_any_tr<nkr::array::cpp_tg> type_p>
    class type_i_tag_sp
    {
    public:
        using type_t    = type_p;
        using of_t      = nkr::none::type_t;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any_General() noexcept;
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any_Specific() noexcept;

    public:
        template <typename ...>
        constexpr type_i_tag_sp(...) noexcept   = delete;
    };

}}}

namespace nkr { namespace interface {

    template <nkr::array::cpp_tr type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::array::$cpp_t::type_i_type_sp<type_p>;
    };

    template <nkr::cpp::is_any_tr<nkr::array::cpp_tg> type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::array::$cpp_t::type_i_tag_sp<type_p>;
    };

}}

namespace nkr { namespace array { namespace $cpp_t {

    template <template <typename ...> typename template_p>
        requires nkr::array::cpp_ttr<template_p>
    class template_i_template_sp
    {
    public:
        template <nkr::generic::type_tr type_p, nkr::constant::positive::count_tr capacity_p>
        using template_t    = nkr::array::cpp_t<type_p, capacity_p>;

        template <typename inner_p>
        using of_t          = template_t<inner_p, nkr::constant::positive::count_t<1>>;

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
        constexpr template_i_template_sp(...) noexcept  = delete;
    };

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::array::cpp_ttg, nkr::none::type_t>
    class template_i_tag_sp :
        public template_i_template_sp<nkr::array::cpp_t>
    {
    public:
    };

}}}

namespace nkr { namespace interface {

    template <template <typename ...> typename template_p>
        requires nkr::array::cpp_ttr<template_p>
    class template_i_sp<template_p>
    {
    public:
        using type_t    = nkr::array::$cpp_t::template_i_template_sp<template_p>;
    };

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::array::cpp_ttg, nkr::none::type_t>
    class template_i_sp<template_p>
    {
    public:
        using type_t    = nkr::array::$cpp_t::template_i_tag_sp<template_p>;
    };

}}

#include "nkr/array/cpp_t_dec_def.h"
