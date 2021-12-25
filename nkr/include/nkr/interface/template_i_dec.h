/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/built_ins_dec.h"

#include "nkr/general/implementing/constructor/default_tr_dec.h"

namespace nkr { namespace interface { namespace $template_i {

    template <typename type_p>
    concept aliases_i = requires
    {
        typename type_p::template type_t<nkr::none::type_t>;
    };

    template <typename type_p>
    concept objects_i =
        !general::implementing::constructor::default_tr<type_p>;

}}}

namespace nkr { namespace interface {

    template <template <typename ...> typename template_p>
    class   template_i;

    struct  template_tg     {};

    template <typename type_p>
    struct  template_ttg    {};

    template <typename type_p>
    concept template_tr =
        cpp::is_tr<typename type_p::template type_t<nkr::none::type_t>, typename template_i<type_p::template type_t>::template type_t<nkr::none::type_t>> &&
        $template_i::aliases_i<type_p> &&
        $template_i::objects_i<type_p>;

}}

namespace nkr { namespace interface {

    template <template <typename ...> typename template_p>
    class template_i
    {
    public:
        template <typename of_p>
        using type_t    = template_p<of_p>;

    public:
        template <typename ...>
        constexpr template_i(...) noexcept  = delete;
    };

    template <>
    class template_i<nkr::interface::template_ttg>
    {
    public:
        template <typename of_p>
        using type_t    = nkr::interface::template_ttg<of_p>;

    public:
        template <typename ...>
        constexpr template_i(...) noexcept  = delete;
    };

}}

#include "nkr/interface/template_i_dec_def.h"

namespace nkr { namespace interface {

    static_assert(template_tr<template_i<template_ttg>>);

}}
