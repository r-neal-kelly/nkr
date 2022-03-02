/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/built_in/forward_dec.h"
#include "nkr/constant_t_dec.h"
#include "nkr/constant/positive/integer_t_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/generic/implementing/interface/enumeration/types_tr_dec.h"
#include "nkr/interface/enumeration/types_i_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/positive/integer_t_dec.h"
#include "nkr/tr_dec.h"
#include "nkr/tuple/types_t_dec.h"

namespace nkr { namespace enumeration { namespace $types_t {

    template <typename value_p>
    using interface_t       = nkr::interface::enumeration::types_i<value_p>;

    template <typename value_p>
    using integer_t         = interface_t<value_p>::integer_t;

    template <typename value_p>
    using default_none_t    = nkr::constant_t<integer_t<value_p>, interface_t<value_p>::Default_Integer()>;

}}}

namespace nkr { namespace enumeration {

    template <
        nkr::generic::implementing::interface::enumeration::types_tr    value_p,
        nkr::constant_of_tr<$types_t::integer_t<value_p>>               none_p      = $types_t::default_none_t<value_p>
    > class types_t;

    struct  types_tg    {};

    template <typename>
    struct  types_ttg   {};

    template <typename type_p>
    concept types_tr =
        nkr::cpp::is_any_tr<type_p, types_t<typename type_p::type_t, typename type_p::none_t>>;

    template <template <typename ...> typename template_p>
    concept types_ttr =
        nkr::cpp::is_any_ttr<template_p, types_t, nkr::positive::integer_t, nkr::constant::positive::integer_t<0>>;

}}

namespace nkr { namespace enumeration { namespace $types_t {

    template <nkr::enumeration::types_tr type_p>
    class type_i_type_sp
    {
    public:
        using type_t    = type_p;
        using of_t      = type_t::value_t;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any_General() noexcept;
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any_Specific() noexcept;

    public:
        template <typename ...>
        constexpr type_i_type_sp(...) noexcept  = delete;
    };

    template <nkr::cpp::is_any_tr<nkr::enumeration::types_tg> type_p>
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

}}}

namespace nkr { namespace interface {

    template <nkr::enumeration::types_tr type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::enumeration::$types_t::type_i_type_sp<type_p>;
    };

    template <nkr::cpp::is_any_tr<nkr::enumeration::types_tg> type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::enumeration::$types_t::type_i_tag_sp<type_p>;
    };

}}

namespace nkr { namespace interface {

    template <>
    class template_i<nkr::enumeration::types_ttg>
    {
    public:
        template <
            nkr::generic::implementing::interface::enumeration::types_tr        value_p,
            nkr::constant_of_tr<nkr::enumeration::$types_t::integer_t<value_p>> none_p      = nkr::enumeration::$types_t::default_none_t<value_p>
        > using template_t  = nkr::enumeration::types_t<value_p, none_p>;

        template <typename inner_p>
        using   of_t        = template_t<inner_p>;

        template <nkr::tuple::types_tr parameters_p>
            requires (parameters_p::Count() >= 1 && parameters_p::Count() <= 2)
        using   of_tuple_t  = parameters_p::template into_t<template_t>;

        template <typename ...parameters_p>
        using   of_pack_t   = of_tuple_t<nkr::tuple::types_t<parameters_p...>>;

        using   example_t   = of_t<nkr::positive::integer_t>;

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
        nkr::generic::implementing::interface::enumeration::types_tr    value_p,
        nkr::constant_of_tr<$types_t::integer_t<value_p>>               none_p
    > class types_t
    {
    public:
        using type_t        = value_p;
        using none_t        = none_p;

        using interface_t   = nkr::interface::enumeration::types_i<value_p>;
        using value_t       = interface_t::value_t;
        using integer_t     = interface_t::integer_t;

    private:
        static constexpr auto&  Assign_Integer(tr<any_non_const_tg, t<types_t>> auto& self,
                                               const tr<to_tg, t<integer_t>> auto& to_integer) noexcept;

        static constexpr auto&  Assign_Value(tr<any_non_const_tg, t<types_t>> auto& self,
                                             const tr<any_tg, t<value_t>> auto& other) noexcept;
        static constexpr auto&  Assign_Value(tr<any_non_const_tg, t<types_t>> auto& self,
                                             tr<any_non_const_tg, t<value_t>> auto&& other) noexcept;

        static constexpr auto&  Assign_Types(tr<any_non_const_tg, t<types_t>> auto& self,
                                             const tr<any_tg, t<types_t>> auto& other) noexcept;
        static constexpr auto&  Assign_Types(tr<any_non_const_tg, t<types_t>> auto& self,
                                             tr<any_non_const_tg, t<types_t>> auto&& other) noexcept;

    protected:
        value_t value;

    public:
        constexpr types_t() noexcept;

        constexpr types_t(const tr<to_tg, t<integer_t>> auto& to_integer) noexcept;

        constexpr types_t(const value_t& value) noexcept;
        constexpr types_t(const volatile value_t& value) noexcept;
        constexpr types_t(value_t&& value) noexcept;
        constexpr types_t(volatile value_t&& value) noexcept;

        constexpr types_t(const types_t& other) noexcept;
        constexpr types_t(const volatile types_t& other) noexcept;
        constexpr types_t(types_t&& other) noexcept;
        constexpr types_t(volatile types_t&& other) noexcept;

        constexpr types_t&          operator =(const tr<to_tg, t<integer_t>> auto& to_integer) noexcept;
        constexpr volatile types_t& operator =(const tr<to_tg, t<integer_t>> auto& to_integer) volatile noexcept;

        constexpr types_t&          operator =(const value_t& value) noexcept;
        constexpr volatile types_t& operator =(const value_t& value) volatile noexcept;
        constexpr types_t&          operator =(const volatile value_t& value) noexcept;
        constexpr volatile types_t& operator =(const volatile value_t& value) volatile noexcept;
        constexpr types_t&          operator =(value_t&& value) noexcept;
        constexpr volatile types_t& operator =(value_t&& value) volatile noexcept;
        constexpr types_t&          operator =(tr<just_volatile_tg, t<value_t>> auto&& value) noexcept;
        constexpr volatile types_t& operator =(tr<just_volatile_tg, t<value_t>> auto&& value) volatile noexcept;

        constexpr types_t&          operator =(const types_t& other) noexcept;
        constexpr volatile types_t& operator =(const types_t& other) volatile noexcept;
        constexpr types_t&          operator =(const volatile types_t& other) noexcept;
        constexpr volatile types_t& operator =(const volatile types_t& other) volatile noexcept;
        constexpr types_t&          operator =(types_t&& other) noexcept;
        constexpr volatile types_t& operator =(types_t&& other) volatile noexcept;
        constexpr types_t&          operator =(tr<just_volatile_tg, t<types_t>> auto&& other) noexcept;
        constexpr volatile types_t& operator =(tr<just_volatile_tg, t<types_t>> auto&& other) volatile noexcept;

#if defined(nkr_IS_DEBUG)
        constexpr ~types_t() noexcept;
#endif

    public:
        constexpr integer_t                 Integer() const noexcept;
        constexpr integer_t                 Integer() const volatile noexcept;
        constexpr types_t&                  Integer(const tr<to_tg, t<integer_t>> auto& to_integer) noexcept;
        constexpr volatile types_t&         Integer(const tr<to_tg, t<integer_t>> auto& to_integer) volatile noexcept;

        constexpr const value_t&            Value() const noexcept;
        constexpr const volatile value_t&   Value() const volatile noexcept;
        constexpr types_t&                  Value(const tr<any_tg, t<value_t>> auto& value) noexcept;
        constexpr volatile types_t&         Value(const tr<any_tg, t<value_t>> auto& value) volatile noexcept;
        constexpr types_t&                  Value(tr<any_non_const_tg, t<value_t>> auto&& value) noexcept;
        constexpr volatile types_t&         Value(tr<any_non_const_tg, t<value_t>> auto&& value) volatile noexcept;

    public:
        constexpr operator          types_t::integer_t() const noexcept;
        constexpr operator          types_t::integer_t() const volatile noexcept;

        explicit constexpr operator nkr::boolean::cpp_t() const noexcept;
        explicit constexpr operator nkr::boolean::cpp_t() const volatile noexcept;
    };

}}

namespace nkr { namespace enumeration { namespace $types_t {

    template <nkr::enumeration::types_tr type_p>
    class none_value_i_sp
    {
    public:
        using type_t    = type_p;
        using value_t   = nkr::cpp::just_non_qualified_t<type_t>;

    public:
        static constexpr value_t    Value() noexcept;

    public:
        template <typename ...>
        constexpr none_value_i_sp(...) noexcept = delete;
    };

}}}

namespace nkr { namespace interface { namespace none {

    template <nkr::enumeration::types_tr type_p>
    class value_i_sp<type_p>
    {
    public:
        using type_t    = nkr::enumeration::$types_t::none_value_i_sp<type_p>;
    };

}}}

#include "nkr/enumeration/types_t_dec_def.h"
