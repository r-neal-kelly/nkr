/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include <bit>
#include <cassert>
#include <cerrno>
#include <climits>
#include <concepts>
#include <cstdint>
#include <limits>
#include <memory>
#include <mutex>
#include <random>
#include <utility>

#include "nkr/intrinsics_dec.h"

namespace nkr { namespace cpp {

    using void_t            = void;
    using bool_t            = bool;

    using u8_t              = std::uint8_t;
    using u16_t             = std::uint16_t;
    using u32_t             = std::uint32_t;
    using u64_t             = std::uint64_t;
    using s8_t              = std::int8_t;
    using s16_t             = std::int16_t;
    using s32_t             = std::int32_t;
    using s64_t             = std::int64_t;

    using c8_t              = char8_t;
    using c16_t             = char16_t;
    using c32_t             = char32_t;

    using r32_t             = float;
    using r64_t             = double;
#if defined(nkr_IS_64_BIT)
    using real_t            = r64_t;
#elif defined(nkr_IS_32_BIT)
    using real_t            = r32_t;
#endif

#if defined(nkr_IS_64_BIT)
    using word_t            = u64_t;
    using unsigned_word_t   = u64_t;
    using signed_word_t     = s64_t;
#elif defined(nkr_IS_32_BIT)
    using word_t            = u32_t;
    using unsigned_word_t   = u32_t;
    using signed_word_t     = s32_t;
#endif

    using byte_t            = u8_t;
    using size_t            = word_t;
    using count_t           = word_t;
    using index_t           = word_t;
    using address_t         = std::uintptr_t;
    using nullptr_t         = std::nullptr_t;

}}

namespace nkr { namespace cpp {

    template <typename type_p>
    class array_tmpl :
        public std::false_type
    {
    public:
    };

    template <typename type_p>
    class array_tmpl<type_p[]> :
        public std::true_type
    {
    public:
        using unit_t    = type_p;
    };

}}

namespace nkr { namespace cpp {

    template <typename type_p>
    concept pointer_tr =
        std::is_pointer<type_p>::value ||
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

}}

namespace nkr { namespace cpp {

    template <pointer_tr type_p>
    using pointer_unit_t    = std::remove_pointer_t<type_p>;

    template <array_tr type_p>
    using array_unit_t      = array_tmpl<type_p>::unit_t;

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
    concept is_tr =
        std::same_as<type_a_p, type_b_p>;

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
    using any_const_t           = std::add_const_t<type_p>;

    template <any_tr type_p>
    using any_volatile_t        = std::add_volatile_t<type_p>;

    template <any_tr type_p>
    using any_const_volatile_t  = std::add_const_t<std::add_volatile_t<type_p>>;

    template <any_tr type_p>
    using just_non_qualified_t  = std::remove_cv_t<type_p>;

    template <any_tr type_p>
    using just_const_t          = std::add_const_t<std::remove_cv_t<type_p>>;

    template <any_tr type_p>
    using just_volatile_t       = std::add_volatile_t<std::remove_cv_t<type_p>>;

    template <any_tr type_p>
    using just_const_volatile_t = std::add_const_t<std::add_volatile_t<std::remove_cv_t<type_p>>>;

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

    constexpr bool_t    Is_Big_Endian();
    constexpr bool_t    Is_Little_Endian();

    constexpr count_t   Byte_Bit_Count();

}}
