/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include <bit>
#include <cassert>
#include <cerrno>
#include <climits>
#include <cmath>
#include <concepts>
#include <limits>
#include <memory>
#include <mutex>
#include <random>
#include <shared_mutex>
#include <utility>

#include "nkr/built_in/forward_dec.h"

namespace nkr { namespace cpp {

    template <typename type_p>
    class array_tmpl :
        public std::false_type
    {
    public:
    };

    template <typename type_p, nkr::positive::count_t capacity_p>
    class array_tmpl<type_p[capacity_p]> :
        public std::true_type
    {
    public:
        using unit_t    = type_p;

    public:
        static constexpr nkr::positive::count_t Capacity() noexcept;
    };

    template <template <typename ...> typename template_a_p, template <typename ...> typename template_b_p>
    class is_same_template_tmpl :
        public std::false_type
    {
    public:
    };

    template <template <typename ...> typename template_p>
    class is_same_template_tmpl<template_p, template_p> :
        public std::true_type
    {
    public:
    };

    template <
        template <template <typename ...> typename ...> typename template_template_a_p,
        template <template <typename ...> typename ...> typename template_template_b_p
    > class is_same_template_template_tmpl :
        public std::false_type
    {
    public:
    };

    template <
        template <template <typename ...> typename ...> typename template_template_p
    > class is_same_template_template_tmpl<template_template_p, template_template_p> :
        public std::true_type
    {
    public:
    };

    // doesn't work with template aliases
    template <typename type_p, template <typename ...> typename template_p>
    class is_of_template_tmpl :
        public std::false_type
    {
    public:
    };

    template <template <typename ...> typename template_p, typename ...types_p>
    class is_of_template_tmpl<template_p<types_p...>, template_p> :
        public std::true_type
    {
    public:
    };

}}

namespace nkr { namespace cpp {

    template <typename type_p>
    concept type_tr =
        sizeof(type_p) > 0;

    template <typename type_p>
    concept none_type_tr =
        !type_tr<type_p>;

    template <typename type_p>
    concept boolean_tr =
        std::is_same<std::remove_cv_t<type_p>, nkr::boolean::cpp_t>::value;

    template <typename type_p>
    concept integer_tr =
        !boolean_tr<type_p> &&
        std::is_integral<type_p>::value;

    template <typename type_p>
    concept positive_integer_tr =
        integer_tr<type_p> &&
        std::is_unsigned<type_p>::value;

    template <typename type_p>
    concept negatable_integer_tr =
        integer_tr<type_p> &&
        std::is_signed<type_p>::value;

    template <typename type_p>
    concept real_tr =
        std::is_floating_point<type_p>::value;

    template <typename type_p>
    concept positive_real_tr =
        real_tr<type_p> &&
        std::is_unsigned<type_p>::value;

    template <typename type_p>
    concept negatable_real_tr =
        real_tr<type_p> &&
        std::is_signed<type_p>::value;

    template <typename type_p>
    concept pointer_tr =
        std::is_pointer<type_p>::value;

    template <typename type_p>
    concept none_pointer_tr =
        std::is_null_pointer<type_p>::value;

    template <typename type_p>
    concept array_tr =
        array_tmpl<type_p>::value;

    template <typename type_p>
    concept reference_tr =
        std::is_reference<type_p>::value;

    template <typename type_p>
    concept lvalue_reference_tr =
        std::is_lvalue_reference<type_p>::value;

    template <typename type_p>
    concept rvalue_reference_tr =
        std::is_rvalue_reference<type_p>::value;

    template <typename type_p>
    concept enumeration_tr =
        std::is_enum<type_p>::value;

    template <typename type_p>
    concept c_enumeration_tr =
        enumeration_tr<type_p> &&
        (requires { type_p(0) == 0; });

    template <typename type_p>
    concept cpp_enumeration_tr =
        enumeration_tr<type_p> &&
        !c_enumeration_tr<type_p>;

    template <typename type_p>
    concept number_tr =
        integer_tr<type_p> ||
        real_tr<type_p> ||
        enumeration_tr<type_p>;

    template <typename type_p>
    concept built_in_tr =
        none_type_tr<type_p> ||
        boolean_tr<type_p> ||
        integer_tr<type_p> ||
        real_tr<type_p> ||
        pointer_tr<type_p> ||
        none_pointer_tr<type_p> ||
        array_tr<type_p> ||
        reference_tr<type_p> ||
        enumeration_tr<type_p>;

    template <typename type_p>
    concept user_defined_tr =
        !built_in_tr<type_p>;

}}

namespace nkr { namespace cpp {

    template <pointer_tr type_p>
    using   pointer_unit_t      = std::remove_pointer_t<type_p>;

    template <array_tr type_p>
    using   array_unit_t        = array_tmpl<type_p>::unit_t;

    template <reference_tr type_p>
    using   reference_value_t   = std::remove_reference_t<type_p>;

}}

namespace nkr { namespace cpp {

    template <typename type_a_p, typename type_b_p>
    concept is_tr =
        std::same_as<type_a_p, type_b_p>;

    template <typename from_p, typename to_p>
    concept to_tr =
        (std::is_rvalue_reference<from_p>::value &&
         !std::is_const<std::remove_reference_t<from_p>>::value &&
         (std::is_volatile<std::remove_reference_t<from_p>>::value &&
          (requires(volatile std::add_rvalue_reference_t<std::remove_cvref_t<from_p>> from) { std::remove_cv_t<to_p>(std::move(from)); }) ||
          (requires(std::add_rvalue_reference_t<std::remove_cvref_t<from_p>> from) { std::remove_cv_t<to_p>(std::move(from)); }))) ||
        (std::is_lvalue_reference<from_p>::value &&
         (requires(std::add_lvalue_reference_t<std::remove_reference_t<from_p>> from) { std::remove_cv_t<to_p>(from); })) ||
        (!std::is_reference<from_p>::value &&
         (requires(std::remove_reference_t<from_p> from) { std::remove_cv_t<to_p>(from); }));

    template <template <typename ...> typename template_a_p, template <typename ...> typename template_b_p>
    concept is_ttr =
        is_same_template_tmpl<template_a_p, template_b_p>::value;

    template <typename type_p, template <typename ...> typename template_p>
    concept of_ttr =
        is_of_template_tmpl<type_p, template_p>::value;

    template <template <typename ...> typename template_a_p, template <typename ...> typename template_b_p, typename ...types_p>
    concept is_any_ttr =
        is_tr<template_a_p<types_p...>, template_b_p<types_p...>>;

    template <template <typename ...> typename template_a_p, template <typename ...> typename template_b_p, typename ...types_p>
    concept is_alias_ttr =
        !is_ttr<template_a_p, template_b_p> &&
        is_any_ttr<template_a_p, template_b_p, types_p...>;

    template <
        template <template <typename ...> typename ...> typename template_template_a_p,
        template <template <typename ...> typename ...> typename template_template_b_p
    > concept   is_tttr =
        is_same_template_template_tmpl<template_template_a_p, template_template_b_p>::value;

    template <
        template <template <typename ...> typename ...> typename template_template_a_p,
        template <template <typename ...> typename ...> typename template_template_b_p,
        template <typename ...> typename ...templates_p
    > concept   is_any_tttr =
        is_tr<template_template_a_p<templates_p...>, template_template_b_p<templates_p...>>;

    template <
        template <template <typename ...> typename ...> typename template_template_a_p,
        template <template <typename ...> typename ...> typename template_template_b_p,
        template <typename ...> typename ...templates_p
    > concept   is_alias_tttr =
        !is_tttr<template_template_a_p, template_template_b_p> &&
        is_any_tttr<template_template_a_p, template_template_b_p, templates_p...>;

}}

namespace nkr { namespace cpp {

    template <typename type_a_p, typename type_b_p>
    concept can_be_equal_to_tr =
        requires(type_a_p type_a, type_b_p type_b)
    {
        type_a == type_b;
    };

    // etc.

}}

namespace nkr { namespace cpp {

    template <typename type_p>
    concept any_tr =
        true;

    template <typename type_p>
    concept any_qualified_tr =
        std::is_const<type_p>::value ||
        std::is_volatile<type_p>::value;

    template <typename type_p>
    concept any_non_qualified_tr =
        !std::is_const<type_p>::value &&
        !std::is_volatile<type_p>::value;

    template <typename type_p>
    concept any_const_tr =
        std::is_const<type_p>::value;

    template <typename type_p>
    concept any_non_const_tr =
        !std::is_const<type_p>::value;

    template <typename type_p>
    concept any_volatile_tr =
        std::is_volatile<type_p>::value;

    template <typename type_p>
    concept any_non_volatile_tr =
        !std::is_volatile<type_p>::value;

    template <typename type_p>
    concept just_tr =
        true;

    template <typename type_p>
    concept just_non_qualified_tr =
        !reference_tr<type_p> && std::same_as<type_p, std::remove_cv_t<type_p>> ||
        lvalue_reference_tr<type_p> && std::same_as<type_p, std::remove_cvref_t<type_p>&> ||
        rvalue_reference_tr<type_p> && std::same_as<type_p, std::remove_cvref_t<type_p>&&>;

    template <typename type_p>
    concept just_const_tr =
        !reference_tr<type_p> && std::same_as<type_p, const std::remove_cv_t<type_p>> ||
        lvalue_reference_tr<type_p> && std::same_as<type_p, const std::remove_cvref_t<type_p>&> ||
        rvalue_reference_tr<type_p> && std::same_as<type_p, const std::remove_cvref_t<type_p>&&>;

    template <typename type_p>
    concept just_volatile_tr =
        !reference_tr<type_p> && std::same_as<type_p, volatile std::remove_cv_t<type_p>> ||
        lvalue_reference_tr<type_p> && std::same_as<type_p, volatile std::remove_cvref_t<type_p>&> ||
        rvalue_reference_tr<type_p> && std::same_as<type_p, volatile std::remove_cvref_t<type_p>&&>;

    template <typename type_p>
    concept just_const_volatile_tr =
        !reference_tr<type_p> && std::same_as<type_p, const volatile std::remove_cv_t<type_p>> ||
        lvalue_reference_tr<type_p> && std::same_as<type_p, const volatile std::remove_cvref_t<type_p>&> ||
        rvalue_reference_tr<type_p> && std::same_as<type_p, const volatile std::remove_cvref_t<type_p>&&>;

    template <typename type_a_p, typename type_b_p>
    concept is_any_tr =
        std::same_as<std::remove_cv_t<type_a_p>, std::remove_cv_t<type_b_p>>;

    template <typename type_a_p, typename type_b_p>
    concept is_any_qualified_tr =
        is_any_tr<type_a_p, type_b_p> &&
        any_qualified_tr<type_a_p>;

    template <typename type_a_p, typename type_b_p>
    concept is_any_non_qualified_tr =
        is_any_tr<type_a_p, type_b_p> &&
        any_non_qualified_tr<type_a_p>;

    template <typename type_a_p, typename type_b_p>
    concept is_any_const_tr =
        is_any_tr<type_a_p, type_b_p> &&
        any_const_tr<type_a_p>;

    template <typename type_a_p, typename type_b_p>
    concept is_any_non_const_tr =
        is_any_tr<type_a_p, type_b_p> &&
        any_non_const_tr<type_a_p>;

    template <typename type_a_p, typename type_b_p>
    concept is_any_volatile_tr =
        is_any_tr<type_a_p, type_b_p> &&
        any_volatile_tr<type_a_p>;

    template <typename type_a_p, typename type_b_p>
    concept is_any_non_volatile_tr =
        is_any_tr<type_a_p, type_b_p> &&
        any_non_volatile_tr<type_a_p>;

    template <typename type_a_p, typename type_b_p>
    concept is_just_tr =
        std::same_as<type_a_p, type_b_p>;

    template <typename type_a_p, typename type_b_p>
    concept is_just_non_qualified_tr =
        is_just_tr<type_a_p, std::remove_cv_t<type_b_p>>;

    template <typename type_a_p, typename type_b_p>
    concept is_just_const_tr =
        is_just_tr<type_a_p, const std::remove_cv_t<type_b_p>>;

    template <typename type_a_p, typename type_b_p>
    concept is_just_volatile_tr =
        is_just_tr<type_a_p, volatile std::remove_cv_t<type_b_p>>;

    template <typename type_a_p, typename type_b_p>
    concept is_just_const_volatile_tr =
        is_just_tr<type_a_p, const volatile std::remove_cv_t<type_b_p>>;

}}

namespace nkr { namespace cpp {

    template <any_tr type_p>
    using   any_const_t             = std::add_const_t<type_p>;

    template <any_tr type_p>
    using   any_volatile_t          = std::add_volatile_t<type_p>;

    template <any_tr type_p>
    using   any_const_volatile_t    = std::add_const_t<std::add_volatile_t<type_p>>;

    template <any_tr type_p>
    using   just_non_qualified_t    = std::remove_cv_t<type_p>;

    template <any_tr type_p>
    using   just_const_t            = std::add_const_t<std::remove_cv_t<type_p>>;

    template <any_tr type_p>
    using   just_volatile_t         = std::add_volatile_t<std::remove_cv_t<type_p>>;

    template <any_tr type_p>
    using   just_const_volatile_t   = std::add_const_t<std::add_volatile_t<std::remove_cv_t<type_p>>>;

}}

namespace nkr { namespace cpp {

    template <typename subject_p, typename object_p>
    class same_qualification_as_tmpl;

    template <typename subject_p, just_non_qualified_tr object_p>
    class same_qualification_as_tmpl<subject_p, object_p>
    {
    public:
        using type_t    = just_non_qualified_t<subject_p>;
    };

    template <typename subject_p, just_const_tr object_p>
    class same_qualification_as_tmpl<subject_p, object_p>
    {
    public:
        using type_t    = just_const_t<subject_p>;
    };

    template <typename subject_p, just_volatile_tr object_p>
    class same_qualification_as_tmpl<subject_p, object_p>
    {
    public:
        using type_t    = just_volatile_t<subject_p>;
    };

    template <typename subject_p, just_const_volatile_tr object_p>
    class same_qualification_as_tmpl<subject_p, object_p>
    {
    public:
        using type_t    = just_const_volatile_t<subject_p>;
    };

    template <typename subject_p, typename object_p>
    using same_qualification_as_t   = same_qualification_as_tmpl<subject_p, object_p>::type_t;

}}

namespace nkr { namespace cpp {

    template <typename child_p, typename parent_p>
    class access_qualification_of_tmpl;

    template <typename child_p, just_non_qualified_tr parent_p>
    class access_qualification_of_tmpl<child_p, parent_p>
    {
    public:
        using type_t    = child_p;
    };

    template <typename child_p, just_const_tr parent_p>
    class access_qualification_of_tmpl<child_p, parent_p>
    {
    public:
        using type_t    = any_const_t<child_p>;
    };

    template <typename child_p, just_volatile_tr parent_p>
    class access_qualification_of_tmpl<child_p, parent_p>
    {
    public:
        using type_t    = any_volatile_t<child_p>;
    };

    template <typename child_p, just_const_volatile_tr parent_p>
    class access_qualification_of_tmpl<child_p, parent_p>
    {
    public:
        using type_t    = any_const_volatile_t<child_p>;
    };

    template <typename child_p, typename parent_p>
    using access_qualification_of_t = access_qualification_of_tmpl<child_p, parent_p>::type_t;

}}

namespace nkr { namespace cpp {

    template <typename type_p>
    class other_qualifications_of_tmpl;

    template <just_non_qualified_tr type_p>
    class other_qualifications_of_tmpl<type_p>
    {
    public:
        using type_a_t  = just_const_t<type_p>;
        using type_b_t  = just_volatile_t<type_p>;
        using type_c_t  = just_const_volatile_t<type_p>;
    };

    template <just_const_tr type_p>
    class other_qualifications_of_tmpl<type_p>
    {
    public:
        using type_a_t  = just_non_qualified_t<type_p>;
        using type_b_t  = just_volatile_t<type_p>;
        using type_c_t  = just_const_volatile_t<type_p>;
    };

    template <just_volatile_tr type_p>
    class other_qualifications_of_tmpl<type_p>
    {
    public:
        using type_a_t  = just_non_qualified_t<type_p>;
        using type_b_t  = just_const_t<type_p>;
        using type_c_t  = just_const_volatile_t<type_p>;
    };

    template <just_const_volatile_tr type_p>
    class other_qualifications_of_tmpl<type_p>
    {
    public:
        using type_a_t  = just_non_qualified_t<type_p>;
        using type_b_t  = just_const_t<type_p>;
        using type_c_t  = just_volatile_t<type_p>;
    };

}}

namespace nkr { namespace cpp {

    template <integer_tr integer_p>
    class relative_integer_tmpl;

    template <>
    class relative_integer_tmpl<nkr::positive::integer_8_t>
    {
    public:
        using type_t    = nkr::negatable::integer_8_t;
    };

    template <>
    class relative_integer_tmpl<nkr::positive::integer_16_t>
    {
    public:
        using type_t    = nkr::negatable::integer_16_t;
    };

    template <>
    class relative_integer_tmpl<nkr::positive::integer_32_t>
    {
    public:
        using type_t    = nkr::negatable::integer_32_t;
    };

    template <>
    class relative_integer_tmpl<nkr::positive::integer_64_t>
    {
    public:
        using type_t    = nkr::negatable::integer_64_t;
    };

    template <>
    class relative_integer_tmpl<nkr::negatable::integer_8_t>
    {
    public:
        using type_t    = nkr::positive::integer_8_t;
    };

    template <>
    class relative_integer_tmpl<nkr::negatable::integer_16_t>
    {
    public:
        using type_t    = nkr::positive::integer_16_t;
    };

    template <>
    class relative_integer_tmpl<nkr::negatable::integer_32_t>
    {
    public:
        using type_t    = nkr::positive::integer_32_t;
    };

    template <>
    class relative_integer_tmpl<nkr::negatable::integer_64_t>
    {
    public:
        using type_t    = nkr::positive::integer_64_t;
    };

    template <integer_tr integer_p>
    using relative_integer_t = relative_integer_tmpl<integer_p>::type_t;

}}

// nkr::cpp functions
namespace nkr { namespace cpp {

    constexpr nkr::boolean::cpp_t       Is_Big_Endian() noexcept;
    constexpr nkr::boolean::cpp_t       Is_Little_Endian() noexcept;

    constexpr nkr::positive::count_t    Byte_Bit_Count() noexcept;

    constexpr auto*                     Address(const auto& of) noexcept;

    constexpr auto&&                    Move(auto& value) noexcept;
    constexpr auto&&                    Move(const auto& value) noexcept                        = delete;
    constexpr auto&&                    Move(auto&& value) noexcept;
    constexpr auto&&                    Move(const auto&& value) noexcept                       = delete;

    constexpr auto                      Exchange(auto& value, const auto& with) noexcept;
    constexpr auto                      Exchange(const auto& value, const auto& with) noexcept  = delete;
    constexpr auto                      Exchange(auto& value, auto&& with) noexcept;
    constexpr auto                      Exchange(const auto& value, auto&& with) noexcept       = delete;

    template <typename parameter_p>
    constexpr parameter_p&&             Forward(std::remove_reference_t<parameter_p>& argument) noexcept;
    template <typename parameter_p>
        requires (!lvalue_reference_tr<parameter_p>)
    constexpr parameter_p&&             Forward(std::remove_reference_t<parameter_p>&& argument) noexcept;

    template <typename value_p>
        requires boolean_tr<value_p> || integer_tr<value_p> || real_tr<value_p> || pointer_tr<value_p>
    constexpr value_p                   Default_Min() noexcept;
    template <typename value_p>
        requires boolean_tr<value_p> || integer_tr<value_p> || real_tr<value_p> || pointer_tr<value_p>
    constexpr value_p                   Default_Max() noexcept;

    template <array_tr array_p>
    constexpr nkr::positive::count_t    Array_Capacity() noexcept;

}}

#include "nkr/cpp_dec_def.h"

// requirements
namespace nkr { namespace cpp {

    static_assert(Is_Big_Endian() || Is_Little_Endian(), "This library requires either a big or little endian machine.");
    static_assert(Byte_Bit_Count() == 8, "This library requires that there be 8 bits in a byte.");

}}
