/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/tr_dec.h"

#include "nkr/generic/built_in_tr_dec.h"
#include "nkr/generic/implementing/constructor/default_tr_dec.h"
#include "nkr/generic/implementing/interface/none/value_tr_dec.h"
#include "nkr/generic/negatable_tr_dec.h"
#include "nkr/generic/number/integer_tr_dec.h"
#include "nkr/generic/positive_tr_dec.h"
#include "nkr/generic/type_tr_dec.h"

namespace nkr { namespace interface { namespace enumeration { namespace $types_i {

    template <typename type_p>
    concept default_tr =
        cpp::just_non_qualified_tr<type_p> &&
        nkr::generic::type_tr<type_p> &&
        nkr::generic::built_in_tr<type_p> &&
        nkr::generic::number::integer_tr<type_p> &&
        nkr::generic::implementing::interface::none::value_tr<type_p>;

    template <typename type_p>
    concept aliases_i =
        cpp::just_non_qualified_tr<typename type_p::type_t> &&
        nkr::generic::type_tr<typename type_p::type_t> &&

        cpp::just_non_qualified_tr<typename type_p::integer_t> &&
        nkr::generic::type_tr<typename type_p::integer_t> &&
        nkr::generic::built_in_tr<typename type_p::integer_t> &&
        nkr::generic::number::integer_tr<typename type_p::integer_t> &&
        nkr::generic::implementing::interface::none::value_tr<typename type_p::integer_t>

        && requires(typename type_p::type_t type,
                    const typename type_p::type_t const_type,
                    volatile typename type_p::type_t volatile_type,
                    const volatile typename type_p::type_t const_volatile_type,

                    typename type_p::integer_t integer)
    {
        // it's possible to replace some of these with the interface Value() getter and setter,
        // but if type_p::type_t is complicated enough, wouldn't they want direct move semantics, etc?
        // And also, the Value() getter and setter allow for cheap ops rather than what could be expensive copies.

        // we should wrap this into a general trait, except the integer ctor. it's essentially feature complete
        // ctors and assigners which every type in the library should be implementing.

        { typename type_p::type_t(type) };
        { typename type_p::type_t(volatile_type) };
        { typename type_p::type_t(const_type) };
        { typename type_p::type_t(const_volatile_type) };

        { typename type_p::type_t(cpp::Move(type)) };
        { typename type_p::type_t(cpp::Move(volatile_type)) };

        { typename type_p::type_t(integer) };

        { type = type }                                         -> cpp::is_tr<typename type_p::type_t&>;
        { type = const_type }                                   -> cpp::is_tr<typename type_p::type_t&>;
        { type = volatile_type }                                -> cpp::is_tr<typename type_p::type_t&>;
        { type = const_volatile_type }                          -> cpp::is_tr<typename type_p::type_t&>;

        { type = cpp::Move(type) }                              -> cpp::is_tr<typename type_p::type_t&>;
        { type = cpp::Move(volatile_type) }                     -> cpp::is_tr<typename type_p::type_t&>;

        { volatile_type = type }                                -> cpp::is_tr<volatile typename type_p::type_t&>;
        { volatile_type = const_type }                          -> cpp::is_tr<volatile typename type_p::type_t&>;
        { volatile_type = volatile_type }                       -> cpp::is_tr<volatile typename type_p::type_t&>;
        { volatile_type = const_volatile_type }                 -> cpp::is_tr<volatile typename type_p::type_t&>;

        { volatile_type = cpp::Move(type) }                     -> cpp::is_tr<volatile typename type_p::type_t&>;
        { volatile_type = cpp::Move(volatile_type) }            -> cpp::is_tr<volatile typename type_p::type_t&>;
    };

    template <typename type_p>
    concept static_constexpr_functions_i = requires(typename type_p::type_t type,
                                                    const typename type_p::type_t const_type,
                                                    volatile typename type_p::type_t volatile_type,
                                                    const volatile typename type_p::type_t const_volatile_type,

                                                    typename type_p::integer_t integer)
    {
        { type_p::Default_None_Value() }            -> cpp::is_tr<typename type_p::integer_t>;

        { type_p::Value(const_type) }               -> cpp::is_tr<typename type_p::integer_t>;
        { type_p::Value(const_volatile_type) }      -> cpp::is_tr<typename type_p::integer_t>;

        { type_p::Value(type, integer) }            -> cpp::is_tr<nkr::none::type_t>;
        { type_p::Value(volatile_type, integer) }   -> cpp::is_tr<nkr::none::type_t>;
    };

    template <typename type_p>
    concept objects_i =
        !generic::implementing::constructor::default_tr<type_p>;

}}}}

namespace nkr { namespace interface { namespace enumeration {

    template <typename type_p>
    class   types_i;

    struct  types_tg    {};

    template <typename>
    struct  types_ttg   {};

    template <typename type_p>
    concept types_tr =
        cpp::is_any_tr<type_p, types_i<typename type_p::type_t>> &&
        $types_i::aliases_i<type_p> &&
        $types_i::static_constexpr_functions_i<type_p > &&
        $types_i::objects_i<type_p>;

    template <template <typename ...> typename template_p>
    concept types_ttr =
        cpp::is_any_ttr<template_p, types_i, nkr::positive::integer_t>;

}}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::interface::enumeration::types_tg>
    {
    public:
        using type_t    = nkr::interface::enumeration::types_tg;
        using of_t      = nkr::none::type_t;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr type_i(...) noexcept  = delete;
    };

    template <nkr::interface::enumeration::types_tr type_p>
    class type_i<type_p> :
        public type_i<nkr::interface::enumeration::types_tg>
    {
    public:
        using type_t    = type_p;
        using of_t      = type_p::type_t;
    };

}}

namespace nkr { namespace interface {

    template <>
    class template_i<nkr::interface::enumeration::types_ttg>
    {
    public:
        template <typename inner_p>
        using of_t      = nkr::interface::enumeration::types_i<inner_p>;
        using example_t = of_t<nkr::positive::integer_t>;

    public:
        template <template <typename ...> typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr template_i(...) noexcept  = delete;
    };

    template <template <typename ...> typename template_p>
        requires nkr::interface::enumeration::types_ttr<template_p>
    class template_i<template_p> :
        public template_i<nkr::interface::enumeration::types_ttg>
    {
    public:
    };

}}

namespace nkr { namespace interface { namespace enumeration {

    template <$types_i::default_tr type_p>
    class types_i<type_p>
    {
    public:
        using type_t    = type_p;
        using integer_t = type_p;

    public:
        static constexpr integer_t          Default_None_Value() noexcept;

        static constexpr integer_t          Value(const tr1<any_tg, type_t> auto& type) noexcept;
        static constexpr nkr::none::type_t  Value(tr1<any_non_const_tg, type_t> auto& type, integer_t integer) noexcept;

    public:
        template <typename ...>
        constexpr types_i(...) noexcept = delete;
    };

}}}

#include "nkr/interface/enumeration/types_i_dec_def.h"

namespace nkr { namespace interface { namespace enumeration {

    static_assert(types_tr<types_i<positive::integer_t>>);

}}}
