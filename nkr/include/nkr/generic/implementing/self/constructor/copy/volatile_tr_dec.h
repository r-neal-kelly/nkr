/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/built_in/forward_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/interface/template_i_generic_aliases_t_dec.h"

namespace nkr { namespace generic { namespace implementing { namespace self { namespace constructor {
namespace copy { namespace $volatile_tr {

    template <typename type_p>
    concept constructors_i =
        (requires(type_p instance,
                  const type_p const_instance,
                  volatile type_p volatile_instance,
                  const volatile type_p const_volatile_instance)
    {
        { type_p(volatile_instance) };
        { type_p(const_volatile_instance) };
    });

}}}}}}}

namespace nkr { namespace generic { namespace implementing { namespace self { namespace constructor {
namespace copy {

    struct  volatile_tg     {};

    template <typename>
    struct  volatile_ttg    {};

    template <typename type_p>
    concept volatile_tr =
        $volatile_tr::constructors_i<nkr::cpp::just_non_qualified_t<type_p>>;

    template <template <typename ...> typename template_p>
    concept volatile_ttr =
        volatile_tr<typename nkr::interface::template_i<template_p>::example_t>;

}}}}}}

namespace nkr { namespace generic { namespace implementing { namespace self { namespace constructor {
namespace copy { namespace $volatile_tr {

    template <nkr::cpp::is_any_tr<nkr::generic::implementing::self::constructor::copy::volatile_tg> type_p>
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

}}}}}}}

namespace nkr { namespace interface {

    template <nkr::cpp::is_any_tr<nkr::generic::implementing::self::constructor::copy::volatile_tg> type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::generic::implementing::self::constructor::copy::$volatile_tr::type_i_tag_sp<type_p>;
    };

}}

namespace nkr { namespace generic { namespace implementing { namespace self { namespace constructor {
namespace copy { namespace $volatile_tr {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::generic::implementing::self::constructor::copy::volatile_ttg, nkr::none::type_t>
    class template_i_tag_sp :
        public nkr::interface::template_i_generic_aliases_t<nkr::generic::implementing::self::constructor::copy::volatile_tg>
    {
    public:
        template <template <typename ...> typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr template_i_tag_sp(...) noexcept   = delete;
    };

}}}}}}}

namespace nkr { namespace interface {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::generic::implementing::self::constructor::copy::volatile_ttg, nkr::none::type_t>
    class template_i_sp<template_p>
    {
    public:
        using type_t    = nkr::generic::implementing::self::constructor::copy::$volatile_tr::template_i_tag_sp<template_p>;
    };

}}

#include "nkr/generic/implementing/self/constructor/copy/volatile_tr_dec_def.h"
