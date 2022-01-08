/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include <bit>
#include <cassert>
#include <cerrno>
#include <climits>
#include <cmath>
#include <concepts>
#include <cstdint>
#include <limits>
#include <memory>
#include <mutex>
#include <random>
#include <shared_mutex>
#include <utility>

#include "nkr/macros_dec.h"

namespace nkr { namespace cpp {

    using   boolean_t   = bool;

}}

namespace nkr { namespace cpp { namespace none {

    using   type_t      = void;
    using   pointer_t   = std::nullptr_t;

}}}

namespace nkr { namespace cpp { namespace positive {

    using   integer_8_t     = std::uint8_t;
    using   integer_16_t    = std::uint16_t;
    using   integer_32_t    = std::uint32_t;
    using   integer_64_t    = std::uint64_t;
#if defined(nkr_IS_64_BIT)
    using   integer_t       = integer_64_t;
#elif defined(nkr_IS_32_BIT)
    using   integer_t       = integer_32_t;
#endif

    using   byte_t          = integer_8_t;
    using   word_t          = integer_t;

    using   size_t          = integer_t;
    using   count_t         = integer_t;
    using   index_t         = integer_t;

}}}

namespace nkr { namespace cpp { namespace negatable {

    using   integer_8_t     = std::int8_t;
    using   integer_16_t    = std::int16_t;
    using   integer_32_t    = std::int32_t;
    using   integer_64_t    = std::int64_t;
#if defined(nkr_IS_64_BIT)
    using   integer_t       = integer_64_t;
#elif defined(nkr_IS_32_BIT)
    using   integer_t       = integer_32_t;
#endif

    using   real_32_t       = float;
    using   real_64_t       = double;
#if defined(nkr_IS_64_BIT)
    using   real_t          = real_64_t;
#elif defined(nkr_IS_32_BIT)
    using   real_t          = real_32_t;
#endif

    using   byte_t          = integer_8_t;
    using   word_t          = integer_t;

    using   size_t          = integer_t;
    using   count_t         = integer_t;
    using   index_t         = integer_t;

}}}

namespace nkr { namespace cpp {

    template <typename type_p>
    class array_tmpl :
        public std::false_type
    {
    public:
    };

    template <typename type_p, positive::count_t capacity_p>
    class array_tmpl<type_p[capacity_p]> :
        public std::true_type
    {
    public:
        using unit_t    = type_p;
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
        std::is_same<std::remove_cv_t<type_p>, boolean_t>::value;

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
        std::is_convertible<from_p, to_p>::value ||
        requires(from_p from) { static_cast<to_p>(from_p()); };

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

// nkr::cpp::lock
namespace nkr { namespace cpp { namespace lock {

    using   unary_t = std::mutex;
    using   deep_t  = std::recursive_mutex;
    using   wide_t  = std::shared_mutex;

}}}

namespace nkr { namespace cpp { namespace lock { namespace timed {

    using   unary_t = std::timed_mutex;
    using   deep_t  = std::recursive_timed_mutex;
    using   wide_t  = std::shared_timed_mutex;

}}}}

namespace nkr { namespace cpp { namespace generic { namespace lock {

    template <typename type_p>
    concept unary_tr =
        is_any_tr<type_p, cpp::lock::unary_t> ||
        is_any_tr<type_p, cpp::lock::timed::unary_t>;

    template <typename type_p>
    concept deep_tr =
        is_any_tr<type_p, cpp::lock::deep_t> ||
        is_any_tr<type_p, cpp::lock::timed::deep_t>;

    template <typename type_p>
    concept wide_tr =
        is_any_tr<type_p, cpp::lock::wide_t> ||
        is_any_tr<type_p, cpp::lock::timed::wide_t>;

    template <typename type_p>
    concept perpetual_tr =
        is_any_tr<type_p, cpp::lock::unary_t> ||
        is_any_tr<type_p, cpp::lock::deep_t> ||
        is_any_tr<type_p, cpp::lock::wide_t>;

    template <typename type_p>
    concept timed_tr =
        is_any_tr<type_p, cpp::lock::timed::unary_t> ||
        is_any_tr<type_p, cpp::lock::timed::deep_t> ||
        is_any_tr<type_p, cpp::lock::timed::wide_t>;

    template <typename type_p>
    concept exclusive_tr =
        unary_tr<type_p> ||
        deep_tr<type_p> ||
        wide_tr<type_p>;

    template <typename type_p>
    concept inclusive_tr =
        wide_tr<type_p>;

}}}}

namespace nkr { namespace cpp { namespace generic {

    template <typename type_p>
    concept lock_tr =
        lock::unary_tr<type_p> ||
        lock::deep_tr<type_p> ||
        lock::wide_tr<type_p>;

}}}

// nkr::cpp::locker
namespace nkr { namespace cpp { namespace locker {

    template <generic::lock_tr ...locks_p>
    using   scoped_t    = std::scoped_lock<locks_p...>;
    template <generic::lock::exclusive_tr lock_p>
    using   exclusive_t = std::unique_lock<lock_p>;
    template <generic::lock::inclusive_tr lock_p>
    using   inclusive_t = std::shared_lock<lock_p>;

}}}

namespace nkr { namespace cpp { namespace locker { namespace $scoped_t {

    template <typename type_p>
    class is_tmpl :
        public std::false_type
    {
    public:
    };

    template <generic::lock_tr ...locks_p>
    class is_tmpl<scoped_t<locks_p...>> :
        public std::true_type
    {
    public:
    };

}}}}

namespace nkr { namespace cpp { namespace generic {

    template <typename type_p>
    concept locker_tr =
        locker::$scoped_t::is_tmpl<just_non_qualified_t<type_p>>::value ||
        is_any_tr<type_p, locker::exclusive_t<typename type_p::mutex_type>> ||
        is_any_tr<type_p, locker::inclusive_t<typename type_p::mutex_type>>;

}}}

// nkr::cpp::random::distributor
namespace nkr { namespace cpp { namespace random { namespace distributor {

    using   bernoulli_t = std::bernoulli_distribution;

}}}}

namespace nkr { namespace cpp { namespace random { namespace distributor { namespace uniform {

    template <typename integer_p>
    using   integer_t   = std::uniform_int_distribution<integer_p>;
    template <typename real_p>
    using   real_t      = std::uniform_real_distribution<real_p>;

}}}}}

namespace nkr { namespace cpp { namespace random { namespace distributor {

    template <typename type_p>
    concept bernoulli_tr =
        is_any_tr<type_p, bernoulli_t>;

}}}}

namespace nkr { namespace cpp { namespace random { namespace distributor { namespace uniform {

    template <typename type_p>
    concept integer_tr =
        is_any_tr<type_p, integer_t<typename type_p::result_type>>;

    template <typename type_p>
    concept real_tr =
        is_any_tr<type_p, real_t<typename type_p::result_type>>;

}}}}}

namespace nkr { namespace cpp { namespace generic { namespace random {

    template <typename type_p>
    concept distributor_tr =
        nkr::cpp::random::distributor::bernoulli_tr<type_p> ||
        nkr::cpp::random::distributor::uniform::integer_tr<type_p> ||
        nkr::cpp::random::distributor::uniform::real_tr<type_p>;

}}}}

// nkr::cpp::random::generator
namespace nkr { namespace cpp { namespace random { namespace generator {

    using   hardware_t                  = std::random_device;

    template <
        typename result_p,
        size_t w_p, size_t n_p, size_t m_p, size_t r_p,
        result_p a_p, size_t u_p, result_p d_p, size_t s_p, result_p b_p, size_t t_p, result_p c_p, size_t l_p,
        result_p f_p
    > using mersenne_twister_t          = std::mersenne_twister_engine<
        result_p,
        w_p, n_p, m_p, r_p,
        a_p, u_p, d_p, s_p, b_p, t_p, c_p, l_p,
        f_p
    >;
    using   mersenne_twister_19937_32_t = std::mt19937;
    using   mersenne_twister_19937_64_t = std::mt19937_64;

}}}}

namespace nkr { namespace cpp { namespace random { namespace generator { namespace $mersenne_twister_t {

    template <typename type_p>
    class is_tmpl :
        public std::false_type
    {
    public:
    };

    template <
        typename result_p,
        size_t w_p, size_t n_p, size_t m_p, size_t r_p,
        result_p a_p, size_t u_p, result_p d_p, size_t s_p, result_p b_p, size_t t_p, result_p c_p, size_t l_p,
        result_p f_p
    > class is_tmpl<mersenne_twister_t<result_p, w_p, n_p, m_p, r_p, a_p, u_p, d_p, s_p, b_p, t_p, c_p, l_p, f_p>> :
        public std::true_type
    {
    public:
    };

}}}}}

namespace nkr { namespace cpp { namespace random { namespace generator {

    template <typename type_p>
    concept hardware_tr =
        is_any_tr<type_p, hardware_t>;

    template <typename type_p>
    concept mersenne_twister_tr =
        $mersenne_twister_t::is_tmpl<just_non_qualified_t<type_p>>::value;

}}}}

namespace nkr { namespace cpp { namespace generic { namespace random {

    template <typename type_p>
    concept generator_tr =
        nkr::cpp::random::generator::hardware_tr<type_p> ||
        nkr::cpp::random::generator::mersenne_twister_tr<type_p>;

}}}}

// nkr::cpp functions
namespace nkr { namespace cpp {

    constexpr boolean_t         Is_Big_Endian() noexcept;
    constexpr boolean_t         Is_Little_Endian() noexcept;

    constexpr positive::count_t Byte_Bit_Count() noexcept;

    constexpr auto*             Address(const auto& of) noexcept;

    // here we can also use the nkr_IS_DEBUG to switch between the variant that actually exchanges fundamentals with 0.
    constexpr auto&&            Move(auto& value) noexcept;
    constexpr auto&&            Move(const auto& value) noexcept                        = delete;
    constexpr auto&&            Move(auto&& value) noexcept;
    constexpr auto&&            Move(const auto&& value) noexcept                       = delete;

    constexpr auto              Exchange(auto& value, const auto& with) noexcept;
    constexpr auto              Exchange(const auto& value, const auto& with) noexcept  = delete;
    constexpr auto              Exchange(auto& value, auto&& with) noexcept;
    constexpr auto              Exchange(const auto& value, auto&& with) noexcept       = delete;

    template <typename value_p>
        requires boolean_tr<value_p> || integer_tr<value_p> || real_tr<value_p> || pointer_tr<value_p>
    constexpr value_p           Min_Value() noexcept;
    template <typename value_p>
        requires boolean_tr<value_p> || integer_tr<value_p> || real_tr<value_p> || pointer_tr<value_p>
    constexpr value_p           Max_Value() noexcept;

}}

// nkr::cpp::constant_t
namespace nkr { namespace cpp {

    template <type_tr type_p, type_p value_p>
    class constant_t;

    template <typename type_p>
    concept constant_tr =
        is_any_tr<type_p, constant_t<typename type_p::value_t, type_p::Value()>>;

    template <typename type_p, typename value_p>
    concept constant_of_tr =
        constant_tr<type_p> &&
        is_tr<typename type_p::value_t, value_p>;

    template <type_tr type_p, type_p value_p>
    class constant_t
    {
    public:
        using value_t   = type_p;

    public:
        static constexpr constant_t::value_t    Value() noexcept;

    public:
        constexpr constant_t() noexcept;

        constexpr constant_t(const constant_t& other) noexcept;
        constexpr constant_t(const volatile constant_t& other) noexcept;
        constexpr constant_t(constant_t&& other) noexcept;
        constexpr constant_t(volatile constant_t&& other) noexcept;

        constexpr constant_t&           operator =(const constant_t& other) noexcept                                = delete;
        constexpr volatile constant_t&  operator =(const constant_t& other) volatile noexcept                       = delete;
        constexpr constant_t&           operator =(const volatile constant_t& other) noexcept                       = delete;
        constexpr volatile constant_t&  operator =(const volatile constant_t& other) volatile noexcept              = delete;
        constexpr constant_t&           operator =(constant_t&& other) noexcept                                     = delete;
        constexpr volatile constant_t&  operator =(constant_t&& other) volatile noexcept                            = delete;
        constexpr constant_t&           operator =(is_just_volatile_tr<constant_t> auto&& other) noexcept           = delete;
        constexpr volatile constant_t&  operator =(is_just_volatile_tr<constant_t> auto&& other) volatile noexcept  = delete;

#if defined(nkr_IS_DEBUG)
        constexpr ~constant_t() noexcept;
#endif

    public:
        constexpr operator  constant_t::value_t() const noexcept;
        constexpr operator  constant_t::value_t() const volatile noexcept;

    public:
        constexpr constant_t::value_t   operator ()() const noexcept;
        constexpr constant_t::value_t   operator ()() const volatile noexcept;
    };

}}

#include "nkr/cpp_dec_def.h"

// requirements
namespace nkr { namespace cpp {

    static_assert(Is_Big_Endian() || Is_Little_Endian(), "This library requires either a big or little endian machine.");
    static_assert(Byte_Bit_Count() == 8, "This library requires that there be 8 bits in a byte.");

    static_assert(sizeof(negatable::real_32_t) == sizeof(negatable::integer_32_t), "Mismatching size for 32 bit real and integer types!");
    static_assert(sizeof(negatable::real_64_t) == sizeof(negatable::integer_64_t), "Mismatching size for 64 bit real and integer types!");
    
    static_assert(sizeof(none::pointer_t) == sizeof(positive::word_t), "Mismatching size for pointer and word types!");
    static_assert(sizeof(none::type_t*) == sizeof(positive::word_t), "Mismatching size for pointer and word types!");

}}
