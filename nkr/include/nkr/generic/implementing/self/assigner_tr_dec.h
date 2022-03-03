/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/built_in/forward_dec.h"
#include "nkr/generic/implementing/self/assigner/non_volatile_tr_dec.h"
#include "nkr/generic/implementing/self/assigner/volatile_tr_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/interface/template_i_generic_aliases_t_dec.h"

namespace nkr { namespace generic { namespace implementing { namespace self {

    struct  assigner_tg     {};

    template <typename>
    struct  assigner_ttg    {};

    template <typename type_p>
    concept assigner_tr =
        nkr::generic::implementing::self::assigner::non_volatile_tr<type_p> &&
        nkr::generic::implementing::self::assigner::volatile_tr<type_p>;

    template <template <typename ...> typename template_p>
    concept assigner_ttr =
        assigner_tr<typename nkr::interface::template_i<template_p>::example_t>;

}}}}

namespace nkr { namespace generic { namespace implementing { namespace self { namespace $assigner_tr {

    template <nkr::cpp::is_any_tr<nkr::generic::implementing::self::assigner_tg> type_p>
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

}}}}}

namespace nkr { namespace interface {

    template <nkr::cpp::is_any_tr<nkr::generic::implementing::self::assigner_tg> type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::generic::implementing::self::$assigner_tr::type_i_tag_sp<type_p>;
    };

}}

namespace nkr { namespace interface {

    template <>
    class template_i<nkr::generic::implementing::self::assigner_ttg> :
        public nkr::interface::template_i_generic_aliases_t<nkr::generic::implementing::self::assigner_tg>
    {
    public:
        template <template <typename ...> typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr template_i(...) noexcept  = delete;
    };

}}

#include "nkr/generic/implementing/self/assigner_tr_dec_def.h"
