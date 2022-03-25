/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include <tuple>

#include "nkr/built_in/forward_dec.h"
#include "nkr/constant/boolean/cpp_t_dec.h"
#include "nkr/constant/positive/count_t_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/interface/template_i_identity_tag_t_dec.h"
#include "nkr/interface/template_i_identity_template_t_dec.h"
#include "nkr/tuple/types_t_dec.h"

namespace nkr { namespace cpp { namespace tuple { namespace values_t$ {

    template <typename type_p>
    class   is_tmpl;

    template <typename type_p>
    class   of_tmpl;

}}}}

namespace nkr { namespace cpp { namespace tuple {

    template <typename ...types_p>
    using   values_t =
        std::tuple<types_p...>;

    struct  values_tg   { class tag_lb; };

    template <typename ...>
    struct  values_ttg  {};

    template <typename type_p>
    concept values_tr =
        values_t$::is_tmpl<nkr::cpp::just_non_qualified_t<type_p>>::Value();

    template <template <typename ...> typename template_p>
    concept values_ttr =
        nkr::cpp::is_any_ttr<template_p, values_t>;

}}}

namespace nkr { namespace cpp { namespace tuple { namespace values_t$ {

    template <nkr::cpp::tuple::values_tr type_p>
    class type_i_type_sp
    {
    public:
        using type_t    = type_p;
        using of_t      = nkr::cpp::tuple::values_t$::of_tmpl<type_p>::type_t;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any_General() noexcept;
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any_Specific() noexcept;

    public:
        template <typename ...>
        constexpr type_i_type_sp(...) noexcept  = delete;
    };

    template <nkr::cpp::is_any_tr<nkr::cpp::tuple::values_tg> type_p>
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

}}}}

namespace nkr { namespace interface {

    template <nkr::cpp::tuple::values_tr type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::cpp::tuple::values_t$::type_i_type_sp<type_p>;
    };

    template <nkr::cpp::is_any_tr<nkr::cpp::tuple::values_tg> type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::cpp::tuple::values_t$::type_i_tag_sp<type_p>;
    };

}}

namespace nkr { namespace cpp { namespace tuple { namespace values_t$ {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::tuple::values_ttr<template_p>
    class template_i_template_sp :
        public nkr::interface::template_i_identity_template_t<
            nkr::cpp::tuple::values_t,
            nkr::tuple::types_t<>,
            nkr::constant::positive::count_t<0>,
            nkr::constant::positive::count_t<~0>,
            nkr::cpp::tuple::values_tg,
            nkr::cpp::tuple::values_ttg
        >
    {
    public:
    };

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::cpp::tuple::values_ttg>
    class template_i_tag_sp :
        public nkr::interface::template_i_identity_tag_t<
            template_i_template_sp<nkr::cpp::tuple::values_t>
        >
    {
    public:
    };

}}}}

namespace nkr { namespace interface {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::tuple::values_ttr<template_p>
    class template_i_sp<template_p>
    {
    public:
        using type_t    = nkr::cpp::tuple::values_t$::template_i_template_sp<template_p>;
    };

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::cpp::tuple::values_ttg>
    class template_i_sp<template_p>
    {
    public:
        using type_t    = nkr::cpp::tuple::values_t$::template_i_tag_sp<template_p>;
    };

}}

#include "nkr/cpp/tuple/values_t_dec_def.h"
