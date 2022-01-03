/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/tr_dec.h"

#include "nkr/generic/implementing/interface/enumeration/types_tr_dec.h"

#include "nkr/interface/enumeration/types_i_dec.h"

#include "nkr/none/value_t_dec.h"

namespace nkr { namespace enumeration { namespace $types_t {

    template <generic::implementing::interface::enumeration::types_tr value_p>
    using interface_of_t    = interface::enumeration::types_i<value_p>;

    template <generic::implementing::interface::enumeration::types_tr value_p>
    using integer_of_t      = interface_of_t<value_p>::integer_t;

    template <generic::implementing::interface::enumeration::types_tr value_p>
    using default_none_of_t = cpp::constant_t<integer_of_t<value_p>, interface_of_t<value_p>::Default_None_Value()>;

}}}

namespace nkr { namespace enumeration {

    template <
        generic::implementing::interface::enumeration::types_tr value_p,
        cpp::constant_of_tr<$types_t::integer_of_t<value_p>> none_p         = $types_t::default_none_of_t<value_p>
    > class types_t;

    struct  types_tg    {};

    template <typename>
    struct  types_ttg   {};

    template <typename type_p>
    concept types_tr =
        cpp::is_any_tr<type_p, types_t<typename type_p::value_t, typename type_p::none_t>>;

    template <template <typename ...> typename template_p>
    concept types_ttr =
        cpp::is_any_ttr<template_p, types_t, positive::integer_t, positive::integer_c<0>>;

}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::enumeration::types_tg>
    {
    public:
        using type_t    = nkr::enumeration::types_tg;
        using of_t      = nkr::none::type_t;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr type_i(...) noexcept  = delete;
    };

    template <nkr::enumeration::types_tr type_p>
    class type_i<type_p> :
        public type_i<nkr::enumeration::types_tg>
    {
    public:
        using type_t    = type_p;
        using of_t      = type_t::value_t;
    };

}}

namespace nkr { namespace interface {

    template <>
    class template_i<nkr::enumeration::types_ttg>
    {
    public:
        template <typename inner_p>
        using of_t      = nkr::enumeration::types_t<inner_p, cpp::constant_t<inner_p, 0>>;
        using example_t = of_t<nkr::positive::integer_t>;

    public:
        template <template <typename ...> typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr template_i(...) noexcept  = delete;
    };

    template <template <typename ...> typename template_p>
        requires nkr::enumeration::types_ttr<template_p>
    class template_i<template_p> :
        public template_i<nkr::enumeration::types_ttg>
    {
    public:
    };

}}

namespace nkr { namespace enumeration {

    template <
        generic::implementing::interface::enumeration::types_tr value_p,
        cpp::constant_of_tr<$types_t::integer_of_t<value_p>> none_p
    > class types_t
    {
    public:
        using value_t       = value_p;
        using none_t        = none_p;
        using interface_t   = interface::enumeration::types_i<value_t>;
        using integer_t     = interface_t::integer_t;
    };

}}

#include "nkr/enumeration/types_t_dec_def.h"

namespace nkr { namespace enumeration {

    static_assert(types_tr<types_t<positive::integer_t>>);
    static_assert(types_tr<types_t<positive::integer_t, positive::integer_c<0>>>);

    static_assert(types_tr<types_t<negatable::integer_t>>);
    static_assert(types_tr<types_t<negatable::integer_t, negatable::integer_c<0>>>);

}}
