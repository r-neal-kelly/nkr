/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/boolean/cpp_t_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/generic/type_tr_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/interface/template_i_generic_aliases_t_dec.h"
#include "nkr/none/type_t_dec.h"

namespace nkr { namespace generic { namespace implementing { namespace constructor { namespace $default_tr {

    template <typename type_p>
    concept constructors_i = requires
    {
        { nkr::cpp::just_non_qualified_t<type_p>() };
    };

}}}}}

namespace nkr { namespace generic { namespace implementing { namespace constructor {

    struct  default_tg  {};

    template <typename>
    struct  default_ttg {};

    template <typename type_p>
    concept default_tr =
        nkr::generic::type_tr<type_p> &&
        $default_tr::constructors_i<type_p>;

    template <template <typename ...> typename template_p>
    concept default_ttr =
        default_tr<typename nkr::interface::template_i<template_p>::example_t>;

}}}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::generic::implementing::constructor::default_tg>
    {
    public:
        using type_t    = nkr::generic::implementing::constructor::default_tg;
        using of_t      = nkr::none::type_t;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr type_i(...) noexcept  = delete;
    };

}}

namespace nkr { namespace interface {

    template <>
    class template_i<nkr::generic::implementing::constructor::default_ttg> :
        public nkr::interface::template_i_generic_aliases_t<nkr::generic::implementing::constructor::default_tg>
    {
    public:
        template <template <typename ...> typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr template_i(...) noexcept  = delete;
    };

}}

#include "nkr/generic/implementing/constructor/default_tr_dec_def.h"
