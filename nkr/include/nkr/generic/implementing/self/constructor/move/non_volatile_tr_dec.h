/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsics_dec.h"

namespace nkr { namespace generic { namespace implementing { namespace self { namespace constructor {
namespace move { namespace $non_volatile_tr {

    template <typename type_p>
    concept constructors_i =
        (requires(type_p instance,
                  const type_p const_instance,
                  volatile type_p volatile_instance,
                  const volatile type_p const_volatile_instance)
    {
        { type_p(nkr::cpp::Move(instance)) };
    });

}}}}}}}

namespace nkr { namespace generic { namespace implementing { namespace self { namespace constructor {
namespace move {

    struct  non_volatile_tg     {};

    template <typename>
    struct  non_volatile_ttg    {};

    template <typename type_p>
    concept non_volatile_tr =
        $non_volatile_tr::constructors_i<nkr::cpp::just_non_qualified_t<type_p>>;

    template <template <typename ...> typename template_p>
    concept non_volatile_ttr =
        non_volatile_tr<typename nkr::interface::template_i<template_p>::example_t>;

}}}}}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::generic::implementing::self::constructor::move::non_volatile_tg>
    {
    public:
        using type_t    = nkr::generic::implementing::self::constructor::move::non_volatile_tg;
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
    class template_i<nkr::generic::implementing::self::constructor::move::non_volatile_ttg>
    {
    public:
        template <typename inner_p>
        using of_t      = nkr::generic::implementing::self::constructor::move::non_volatile_tg;
        using example_t = nkr::generic::implementing::self::constructor::move::non_volatile_tg;

    public:
        template <template <typename ...> typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr template_i(...) noexcept  = delete;
    };

}}

#include "nkr/generic/implementing/self/constructor/move/non_volatile_tr_dec_def.h"
