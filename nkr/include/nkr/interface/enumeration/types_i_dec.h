/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/built_in/forward_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/generic/built_in_tr_dec.h"
#include "nkr/generic/implementing/constructor/default_tr_dec.h"
#include "nkr/generic/implementing/interface/none/value_tr_dec.h"
#include "nkr/generic/implementing/self_tr_dec.h"
#include "nkr/generic/number/integer_tr_dec.h"
#include "nkr/generic/type_tr_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/tr_dec.h"
#include "nkr/tuple/types_t_dec.h"

namespace nkr { namespace interface { namespace enumeration { namespace $types_i {

    template <typename type_p>
    concept default_tr =
        nkr::cpp::just_non_qualified_tr<type_p> &&
        nkr::generic::type_tr<type_p> &&
        nkr::generic::built_in_tr<type_p> &&
        nkr::generic::number::integer_tr<type_p> &&
        nkr::generic::implementing::interface::none::value_tr<type_p>;

    template <typename type_p>
    concept aliases_i =
        nkr::cpp::just_non_qualified_tr<typename type_p::type_t> &&
        nkr::generic::type_tr<typename type_p::type_t> &&
        nkr::generic::implementing::self_tr<typename type_p::type_t> &&
        (requires(typename type_p::integer_t integer) { { typename type_p::type_t(integer) }; }) &&

        nkr::cpp::just_non_qualified_tr<typename type_p::integer_t>&&
        nkr::generic::type_tr<typename type_p::integer_t>&&
        nkr::generic::built_in_tr<typename type_p::integer_t>&&
        nkr::generic::number::integer_tr<typename type_p::integer_t>&&
        nkr::generic::implementing::interface::none::value_tr<typename type_p::integer_t>;

    template <typename type_p>
    concept static_constexpr_functions_i = requires(typename type_p::type_t type,
                                                    const typename type_p::type_t const_type,
                                                    volatile typename type_p::type_t volatile_type,
                                                    const volatile typename type_p::type_t const_volatile_type,

                                                    typename type_p::integer_t integer)
    {
        { type_p::Default_None_Value() }            -> nkr::cpp::is_tr<typename type_p::integer_t>;

        { type_p::Value(const_type) }               -> nkr::cpp::is_tr<typename type_p::integer_t>;
        { type_p::Value(const_volatile_type) }      -> nkr::cpp::is_tr<typename type_p::integer_t>;

        { type_p::Value(type, integer) }            -> nkr::cpp::is_tr<nkr::none::type_t>;
        { type_p::Value(volatile_type, integer) }   -> nkr::cpp::is_tr<nkr::none::type_t>;
    };

    template <typename type_p>
    concept objects_i =
        !nkr::generic::implementing::constructor::default_tr<type_p>;

}}}}

namespace nkr { namespace interface { namespace enumeration {

    template <typename type_p>
    class   types_i;

    struct  types_tg    {};

    template <typename>
    struct  types_ttg   {};

    template <typename type_p>
    concept types_tr =
        nkr::cpp::is_any_tr<type_p, types_i<typename type_p::type_t>> &&
        $types_i::aliases_i<type_p> &&
        $types_i::static_constexpr_functions_i<type_p > &&
        $types_i::objects_i<type_p>;

    template <template <typename ...> typename template_p>
    concept types_ttr =
        nkr::cpp::is_any_ttr<template_p, types_i, nkr::positive::integer_t>;

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
        template <typename type_p>
        using template_t    = nkr::interface::enumeration::types_i<type_p>;

        template <typename inner_p>
        using of_t          = template_t<inner_p>;

        template <nkr::tuple::types_tr parameters_p>
            requires (parameters_p::Count() == 1)
        using of_tuple_t    = parameters_p::template into_t<template_t>;

        template <typename ...parameters_p>
        using of_pack_t     = of_tuple_t<nkr::tuple::types_t<parameters_p...>>;

        using example_t     = of_t<nkr::positive::integer_t>;

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

        static constexpr integer_t          Value(const tr<any_tg, t<type_t>> auto& type) noexcept;
        static constexpr nkr::none::type_t  Value(tr<any_non_const_tg, t<type_t>> auto& type, integer_t integer) noexcept;

    public:
        template <typename ...>
        constexpr types_i(...) noexcept = delete;
    };

}}}

#include "nkr/interface/enumeration/types_i_dec_def.h"
