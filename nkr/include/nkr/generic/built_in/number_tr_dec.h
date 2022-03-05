/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/generic/built_in/number/any_tr_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/interface/template_i_generic_aliases_t_dec.h"
#include "nkr/none/type_t_dec.h"

namespace nkr { namespace generic { namespace built_in {

    struct  number_tg   { class tag_lb; class generic; };

    template <typename>
    struct  number_ttg  {};

    template <typename type_p>
    concept number_tr =
        nkr::generic::built_in::number::any_tr<type_p>;

    template <template <typename ...> typename template_p>
    concept number_ttr =
        nkr::generic::built_in::number::any_ttr<template_p>;

}}}

namespace nkr { namespace generic { namespace built_in { namespace $number_tr {

    template <nkr::cpp::is_any_tr<nkr::generic::built_in::number_tg> type_p>
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

    template <nkr::cpp::is_any_tr<nkr::generic::built_in::number_tg> type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::generic::built_in::$number_tr::type_i_tag_sp<type_p>;
    };

}}

namespace nkr { namespace generic { namespace built_in { namespace $number_tr {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::generic::built_in::number_ttg, nkr::none::type_t>
    class template_i_tag_sp :
        public nkr::interface::template_i_generic_aliases_t<nkr::generic::built_in::number_tg>
    {
    public:
        template <template <typename ...> typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr template_i_tag_sp(...) noexcept   = delete;
    };

}}}}

namespace nkr { namespace interface {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::generic::built_in::number_ttg, nkr::none::type_t>
    class template_i_sp<template_p>
    {
    public:
        using type_t    = nkr::generic::built_in::$number_tr::template_i_tag_sp<template_p>;
    };

}}

#include "nkr/generic/built_in/number_tr_dec_def.h"
