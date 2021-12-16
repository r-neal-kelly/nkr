/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsics.h"
#include "nkr/macros.h"

// ideas:
// we should basically make types for each c_type, and group everything into folders.
// instead of $type_t::any_tr, just use type_tr instead, e.g. $optional_t::any_tr becomes optional_tr.
// so for our c_bool_t, we would have c_bool_tr and trait::type_i<c_bool_tg>, etc. c_bool_t and bool_t go into the boolean folder,
// which satisfies the boolean_i which for such a simple type is the same as boolean_tr, but compare that to our array_i, which...
// actually, boolean_i and boolean_tr are essentially the same thing at that point. but optional_t and optional_tr are simply not,
// and optional_tr is certainly not an interface. so we should ditch the _tr for interfaces in many of these abstract non-concrete types.

namespace nkr {

    class bool_t;

    template <typename type_p>
    class is_array_tmpl :
        public std::false_type
    {
    public:
    };

    template <typename type_p>
    class is_array_tmpl<type_p[]> :
        public std::true_type
    {
    public:
        using unit_t    = type_p;
    };

    template <typename type_p, count_t count_p>
    class is_array_tmpl<type_p[count_p]> :
        public std::true_type
    {
    public:
        using unit_t    = type_p;

    public:
        static constexpr count_t Count()
        {
            return count_p;
        }
    };

    template <typename type_p>
    concept reference_tr =
        std::is_reference<type_p>::value;

    template <typename type_p>
    concept lvalue_reference_tr =
        std::is_lvalue_reference<type_p>::value;

    template <typename type_p>
    concept rvalue_reference_tr =
        std::is_rvalue_reference<type_p>::value;

    /// @{
    template <typename type_p>
    concept any_tr =
        true;

    template <typename type_p>
    concept just_tr =
        true;

    nkr_DEFINE_NOT_TRAIT_WITH_1_PARAM(any_tr, type_p);
    nkr_DEFINE_NOT_TRAIT_WITH_1_PARAM(just_tr, type_p);
    /// @}

    /// @{
    template <typename type_a_p, typename type_b_p>
    concept is_tr =
        std::same_as<type_a_p, type_b_p>;

    template <typename type_a_p, typename type_b_p>
    concept is_any_tr =
        std::same_as<std::remove_cv_t<type_a_p>, std::remove_cv_t<type_b_p>>;

    template <typename type_a_p, typename type_b_p>
    concept is_just_tr =
        std::same_as<type_a_p, type_b_p>;

    nkr_DEFINE_NOT_TRAIT_WITH_2_PARAMS(is_tr, type_a_p, type_b_p);
    nkr_DEFINE_NOT_TRAIT_WITH_2_PARAMS(is_any_tr, type_a_p, type_b_p);
    nkr_DEFINE_NOT_TRAIT_WITH_2_PARAMS(is_just_tr, type_a_p, type_b_p);
    /// @}

    /// @{
    template <typename type_p>
    concept any_type_tr =
        sizeof(type_p) > 0;                         ///< @copydoc _0faa812f_3422_4143_b1d3_8987fcf84eae

    template <typename type_p>
    concept any_non_type_tr =
        !any_type_tr<type_p>;

    nkr_DEFINE_NOT_TRAIT_WITH_1_PARAM(any_type_tr, type_p);
    nkr_DEFINE_NOT_TRAIT_WITH_1_PARAM(any_non_type_tr, type_p);
    /// @}

    /// @{
    template <typename type_p>
    concept any_qualified_tr =
        std::is_const_v<type_p> ||
        std::is_volatile_v<type_p>;

    template <typename type_p>
    concept any_non_qualified_tr =
        !std::is_const_v<type_p> &&
        !std::is_volatile_v<type_p>;

    template <typename type_p>
    concept any_const_tr =
        std::is_const_v<type_p>;

    template <typename type_p>
    concept any_non_const_tr =
        !std::is_const_v<type_p>;

    template <typename type_p>
    concept any_volatile_tr =
        std::is_volatile_v<type_p>;

    template <typename type_p>
    concept any_non_volatile_tr =
        !std::is_volatile_v<type_p>;

    template <typename type_p>
    concept just_non_qualified_tr =
        lvalue_reference_tr<type_p> && std::same_as<type_p, std::remove_cvref_t<type_p>&> ||
        rvalue_reference_tr<type_p> && std::same_as<type_p, std::remove_cvref_t<type_p>&&> ||
        !reference_tr<type_p> && std::same_as<type_p, std::remove_cv_t<type_p>>;

    template <typename type_p>
    concept just_const_tr =
        lvalue_reference_tr<type_p> && std::same_as<type_p, const std::remove_cvref_t<type_p>&> ||
        rvalue_reference_tr<type_p> && std::same_as<type_p, const std::remove_cvref_t<type_p>&&> ||
        !reference_tr<type_p> && std::same_as<type_p, const std::remove_cv_t<type_p>>;

    template <typename type_p>
    concept just_volatile_tr =
        lvalue_reference_tr<type_p> && std::same_as<type_p, volatile std::remove_cvref_t<type_p>&> ||
        rvalue_reference_tr<type_p> && std::same_as<type_p, volatile std::remove_cvref_t<type_p>&&> ||
        !reference_tr<type_p> && std::same_as<type_p, volatile std::remove_cv_t<type_p>>;

    template <typename type_p>
    concept just_const_volatile_tr =
        lvalue_reference_tr<type_p> && std::same_as<type_p, const volatile std::remove_cvref_t<type_p>&> ||
        rvalue_reference_tr<type_p> && std::same_as<type_p, const volatile std::remove_cvref_t<type_p>&&> ||
        !reference_tr<type_p> && std::same_as<type_p, const volatile std::remove_cv_t<type_p>>;

    nkr_DEFINE_NOT_TRAIT_WITH_1_PARAM(any_qualified_tr, type_p);
    nkr_DEFINE_NOT_TRAIT_WITH_1_PARAM(any_non_qualified_tr, type_p);
    nkr_DEFINE_NOT_TRAIT_WITH_1_PARAM(any_const_tr, type_p);
    nkr_DEFINE_NOT_TRAIT_WITH_1_PARAM(any_non_const_tr, type_p);
    nkr_DEFINE_NOT_TRAIT_WITH_1_PARAM(any_volatile_tr, type_p);
    nkr_DEFINE_NOT_TRAIT_WITH_1_PARAM(any_non_volatile_tr, type_p);
    nkr_DEFINE_NOT_TRAIT_WITH_1_PARAM(just_non_qualified_tr, type_p);
    nkr_DEFINE_NOT_TRAIT_WITH_1_PARAM(just_const_tr, type_p);
    nkr_DEFINE_NOT_TRAIT_WITH_1_PARAM(just_volatile_tr, type_p);
    nkr_DEFINE_NOT_TRAIT_WITH_1_PARAM(just_const_volatile_tr, type_p);
    /// @}

    /// @{
    template <typename type_p>
    concept any_unsigned_integer_tr =
        is_any_tr<type_p, u8_t> ||
        is_any_tr<type_p, u16_t> ||
        is_any_tr<type_p, u32_t> ||
        is_any_tr<type_p, u64_t>;

    template <typename type_p>
    concept any_signed_integer_tr =
        is_any_tr<type_p, s8_t> ||
        is_any_tr<type_p, s16_t> ||
        is_any_tr<type_p, s32_t> ||
        is_any_tr<type_p, s64_t>;

    template <typename type_p>
    concept any_integer_tr =
        any_unsigned_integer_tr<type_p> ||
        any_signed_integer_tr<type_p>;
    /// @}

    /// @{
    template <typename type_p>
    concept any_character_tr =
        is_any_tr<type_p, char> ||
        is_any_tr<type_p, c8_t> ||
        is_any_tr<type_p, c16_t> ||
        is_any_tr<type_p, c32_t>;

    nkr_DEFINE_NOT_TRAIT_WITH_1_PARAM(any_character_tr, type_p);
    /// @}

    /// @{
    template <typename type_a_p, typename type_b_p>
    concept is_any_type_tr =
        is_any_tr<type_a_p, type_b_p> &&
        any_type_tr<type_a_p>;

    template <typename type_a_p, typename type_b_p>
    concept is_any_non_type_tr =
        is_any_tr<type_a_p, type_b_p> &&
        any_non_type_tr<type_a_p>;

    nkr_DEFINE_NOT_TRAIT_WITH_2_PARAMS(is_any_type_tr, type_a_p, type_b_p);
    nkr_DEFINE_NOT_TRAIT_WITH_2_PARAMS(is_any_non_type_tr, type_a_p, type_b_p);
    /// @}

    /// @{
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

    nkr_DEFINE_NOT_TRAIT_WITH_2_PARAMS(is_any_qualified_tr, type_a_p, type_b_p);
    nkr_DEFINE_NOT_TRAIT_WITH_2_PARAMS(is_any_non_qualified_tr, type_a_p, type_b_p);
    nkr_DEFINE_NOT_TRAIT_WITH_2_PARAMS(is_any_const_tr, type_a_p, type_b_p);
    nkr_DEFINE_NOT_TRAIT_WITH_2_PARAMS(is_any_non_const_tr, type_a_p, type_b_p);
    nkr_DEFINE_NOT_TRAIT_WITH_2_PARAMS(is_any_volatile_tr, type_a_p, type_b_p);
    nkr_DEFINE_NOT_TRAIT_WITH_2_PARAMS(is_any_non_volatile_tr, type_a_p, type_b_p);
    nkr_DEFINE_NOT_TRAIT_WITH_2_PARAMS(is_just_non_qualified_tr, type_a_p, type_b_p);
    nkr_DEFINE_NOT_TRAIT_WITH_2_PARAMS(is_just_const_tr, type_a_p, type_b_p);
    nkr_DEFINE_NOT_TRAIT_WITH_2_PARAMS(is_just_volatile_tr, type_a_p, type_b_p);
    nkr_DEFINE_NOT_TRAIT_WITH_2_PARAMS(is_just_const_volatile_tr, type_a_p, type_b_p);
    /// @}

    /// @addtogroup _a5f738af_46d1_4576_aaf6_adbc60dc07fe
    /// @{
    template <typename from_p, typename to_p>
    concept convertible_tr =
        std::convertible_to<from_p, to_p>;

    template <typename type_p, typename other_p>
    concept size_eq_tr =
        sizeof(type_p) == sizeof(other_p);

    template <typename type_p, typename other_p>
    concept size_le_tr =
        sizeof(type_p) <= sizeof(other_p);
    /// @}

    /// @{
    template <typename type_p>
    concept boolean_tr =
        is_any_tr<type_p, bool_t> ||
        is_any_tr<type_p, c_bool_t>;            /// @copydoc _3e4ef7df_7326_49f0_83e0_378911e03952

    template <typename type_p>
    concept to_boolean_tr =
        std::convertible_to<type_p, bool_t> ||
        std::convertible_to<type_p, c_bool_t>;  ///< @copydoc _2c84f547_56c5_48a6_b6eb_3c0244998edc

    template <typename type_p>
    concept to_c_bool_tr =
        std::convertible_to<type_p, c_bool_t>;
    /// @}

    /// @addtogroup _222d304c_42db_4988_8611_c8aedc33c6cc
    /// @{
    template <typename type_p>
    concept integer_tr =
        std::is_integral<type_p>::value &&
        !is_any_tr<type_p, c_bool_t>;           ///< @copydoc _ead4c138_69b3_4da6_905d_61c157fd5451

    template <typename type_p>
    concept integer_unsigned_tr =
        integer_tr<type_p> &&
        std::is_unsigned<type_p>::value;        ///< @copydoc _7099e20b_1e48_4d00_93a4_4932ad1baf1d

    template <typename type_p>
    concept integer_signed_tr =
        integer_tr<type_p> &&
        std::is_signed<type_p>::value;          ///< @copydoc _f2900e04_a6a5_4d04_bed5_61932038deb2

    template <typename type_p>
    concept integer_word_tr =
        integer_tr<type_p> &&
        (sizeof(type_p) == sizeof(word_t));     ///< @copydoc _ddbfd7fa_7bd7_4121_988b_671b57bcd24f

    template <typename type_p>
    concept integer_8_tr =
        integer_tr<type_p> &&
        (sizeof(type_p) == sizeof(u8_t));       ///< @copydoc _b70bda64_61e7_4743_a015_ed6cf0bb426f

    template <typename type_p>
    concept integer_16_tr =
        integer_tr<type_p> &&
        (sizeof(type_p) == sizeof(u16_t));      ///< @copydoc _fa1ef979_a5ad_4040_9824_060e12cac0a9

    template <typename type_p>
    concept integer_32_tr =
        integer_tr<type_p> &&
        (sizeof(type_p) == sizeof(u32_t));      ///< @copydoc _3e2e08b8_7594_4766_8c65_d8ab87b0ed43

    template <typename type_p>
    concept integer_64_tr =
        integer_tr<type_p> &&
        (sizeof(type_p) == sizeof(u64_t));      ///< @copydoc _a5b7d6de_d392_48a1_893d_8bdc9d2ba8e6

    template <typename type_p>
    concept to_integer_8_tr =
        std::convertible_to<type_p, u8_t> ||
        std::convertible_to<type_p, s8_t>;

    template <typename type_p>
    concept to_integer_16_tr =
        std::convertible_to<type_p, u16_t> ||
        std::convertible_to<type_p, s16_t>;

    template <typename type_p>
    concept to_integer_32_tr =
        std::convertible_to<type_p, u32_t> ||
        std::convertible_to<type_p, s32_t>;

    template <typename type_p>
    concept to_integer_64_tr =
        std::convertible_to<type_p, u64_t> ||
        std::convertible_to<type_p, s64_t>;

    template <typename type_p>
    concept to_integer_tr =
        to_integer_8_tr<type_p> ||
        to_integer_16_tr<type_p> ||
        to_integer_32_tr<type_p> ||
        to_integer_64_tr<type_p>;               ///< @copydoc _c60bd667_fcb7_46cb_9c59_7ebcdf40c878
    /// @}

    /// @addtogroup _8f223336_ce2a_4589_b4c1_75cd98cd393d
    /// @{
    template <typename type_p>
    concept real_tr =
        std::is_floating_point<type_p>::value;  ///< @copydoc _7436208f_39ce_49f4_accb_a3bee797b12a

    template <typename type_p>
    concept real_32_tr =
        real_tr<type_p> &&
        (sizeof(type_p) == sizeof(r32_t));      ///< @copydoc _63562b29_b254_4e38_b931_b895a7d86c75

    template <typename type_p>
    concept real_64_tr =
        real_tr<type_p> &&
        (sizeof(type_p) == sizeof(r64_t));      ///< @copydoc _5a831ea1_e707_476a_9f37_317ad35b94c7

    template <typename type_p>
    concept to_real_tr =
        std::convertible_to<type_p, r32_t> ||
        std::convertible_to<type_p, r64_t>;     ///< @copydoc _f7cc78f8_c257_4193_b5bb_749f1656e614
    /// @}

    /// @addtogroup _a5f738af_46d1_4576_aaf6_adbc60dc07fe
    /// @{
    template <typename type_p>
    concept number_tr =
        integer_tr<type_p> ||
        real_tr<type_p>;

    template <typename type_p>
    concept c_pointer_tr =
        std::is_null_pointer<type_p>::value ||
        std::is_pointer<type_p>::value;         ///< @copydoc _42df3700_b206_4dec_a280_cc34bfd783ea

    template <typename type_p>
    concept void_pointer_tr =
        c_pointer_tr<type_p> &&
        !any_type_tr<std::remove_pointer_t<type_p>>;

    template <typename type_p>
    concept type_pointer_tr =
        c_pointer_tr<type_p> &&
        any_type_tr<std::remove_pointer_t<type_p>>; ///< @copydoc _6a988ebe_eb59_44c5_9b34_45259e710dc7

    template <typename type_p>
    concept c_array_tr =
        is_array_tmpl<type_p>::value;

    template <typename type_p, typename of_p>
    concept c_array_of_tr =
        c_array_tr<type_p> &&
        is_tr<typename is_array_tmpl<type_p>::unit_t, of_p>;

    template <typename type_p>
    concept built_in_tr =
        is_any_tr<type_p, c_bool_t> ||
        integer_tr<type_p> ||
        real_tr<type_p> ||
        c_pointer_tr<type_p>;                   ///< @copydoc _13b4b6b8_807a_4ed1_beae_dfd94e04e0f0

    template <typename type_p>
    concept user_defined_tr =
        !built_in_tr<type_p>;                   ///< @copydoc _3818a648_654b_43d9_9c9d_18527bc45131

    template <typename type_p>
    concept fundamental_tr =
        boolean_tr<type_p> ||
        integer_tr<type_p> ||
        real_tr<type_p> ||
        c_pointer_tr<type_p>;
    /// @}

    template <typename type_a_p, typename type_b_p>
    concept can_equal_to_tr =
        requires(type_a_p type_a, type_b_p type_b)
    {
        type_a == type_b;
    };

    /// @addtogroup _a5f738af_46d1_4576_aaf6_adbc60dc07fe
    /// @{
    template <typename type_a_p, typename type_b_p>
    concept is_just_volatile_base_of_tr =
        just_volatile_tr<type_a_p> &&
        std::is_base_of_v<std::remove_cv_t<type_a_p>, std::remove_cv_t<type_b_p>>;

    template <typename type_a_p, typename type_b_p>
    concept is_just_volatile_or_just_volatile_base_of_tr =
        is_just_volatile_tr<type_a_p, type_b_p> ||
        is_just_volatile_base_of_tr<type_a_p, type_b_p>;

    template <typename type_p, typename other_p>
    concept is_lvalue_reference_of_tr =
        std::is_lvalue_reference_v<std::remove_cv_t<type_p>> &&
        is_tr<std::remove_reference_t<type_p>, other_p>;

    template <typename type_p, typename derived_p>
    concept is_base_lvalue_reference_of_tr =
        std::is_lvalue_reference_v<std::remove_cv_t<type_p>> &&
        std::is_base_of_v<std::remove_reference_t<type_p>, derived_p>;

    template <typename type_p, typename other_p>
    concept is_or_is_base_lvalue_reference_of_tr =
        is_lvalue_reference_of_tr<type_p, other_p> ||
        is_base_lvalue_reference_of_tr<type_p, other_p>;

    template <typename type_p, typename derived_p>
    concept same_or_base_of_tr =
        std::is_same<std::remove_cvref_t<type_p>, std::remove_cvref_t<derived_p>>::value ||
        std::is_base_of<std::remove_cvref_t<type_p>, std::remove_cvref_t<derived_p>>::value;    ///< @copydoc _eff1ff48_96ed_4134_abae_5d29c91fd554

    template <typename type_p, typename base_p>
    concept same_or_derived_from_tr =
        std::is_same<std::remove_cvref_t<type_p>, std::remove_cvref_t<base_p>>::value ||
        std::is_convertible<std::remove_cvref_t<type_p>, std::remove_cvref_t<base_p>>::value;   ///< @copydoc _a08a3aa7_12f3_4e3f_8515_610fa450219b
    /// @}

    /// @{
    template <typename c_pointer_p>
    concept any_c_pointer_tr =
        c_pointer_tr<c_pointer_p>;
    /// @}

}

namespace nkr {

    template <typename type_p>
    class other_qualifications_of_tmpl;

    template <just_non_qualified_tr type_p>
    class other_qualifications_of_tmpl<type_p>
    {
    public:
        using type_a_t  = std::add_const_t<std::remove_cv_t<type_p>>;
        using type_b_t  = std::add_volatile_t<std::remove_cv_t<type_p>>;
        using type_c_t  = std::add_const_t<std::add_volatile_t<std::remove_cv_t<type_p>>>;
    };

    template <just_const_tr type_p>
    class other_qualifications_of_tmpl<type_p>
    {
    public:
        using type_a_t  = std::remove_cv_t<type_p>;
        using type_b_t  = std::add_volatile_t<std::remove_cv_t<type_p>>;
        using type_c_t  = std::add_const_t<std::add_volatile_t<std::remove_cv_t<type_p>>>;
    };

    template <just_volatile_tr type_p>
    class other_qualifications_of_tmpl<type_p>
    {
    public:
        using type_a_t  = std::remove_cv_t<type_p>;
        using type_b_t  = std::add_const_t<std::remove_cv_t<type_p>>;
        using type_c_t  = std::add_const_t<std::add_volatile_t<std::remove_cv_t<type_p>>>;
    };

    template <just_const_volatile_tr type_p>
    class other_qualifications_of_tmpl<type_p>
    {
    public:
        using type_a_t  = std::remove_cv_t<type_p>;
        using type_b_t  = std::add_const_t<std::remove_cv_t<type_p>>;
        using type_c_t  = std::add_volatile_t<std::remove_cv_t<type_p>>;
    };

    template <typename subject_p, typename object_p>
    class same_qualification_as_tmpl;

    template <typename subject_p, just_non_qualified_tr object_p>
    class same_qualification_as_tmpl<subject_p, object_p>
    {
    public:
        using type_t    = std::remove_cv_t<subject_p>;
    };

    template <typename subject_p, just_const_tr object_p>
    class same_qualification_as_tmpl<subject_p, object_p>
    {
    public:
        using type_t    = std::add_const_t<std::remove_cv_t<subject_p>>;
    };

    template <typename subject_p, just_volatile_tr object_p>
    class same_qualification_as_tmpl<subject_p, object_p>
    {
    public:
        using type_t    = std::add_volatile_t<std::remove_cv_t<subject_p>>;
    };

    template <typename subject_p, just_const_volatile_tr object_p>
    class same_qualification_as_tmpl<subject_p, object_p>
    {
    public:
        using type_t    = std::add_const_t<std::add_volatile_t<std::remove_cv_t<subject_p>>>;
    };

    template <typename subject_p, typename object_p>
    using same_qualification_as_t   = same_qualification_as_tmpl<subject_p, object_p>::type_t;

    template <typename child_p, typename parent_p>
    class accessed_qualification_of_tmpl;

    template <typename child_p, just_non_qualified_tr parent_p>
    class accessed_qualification_of_tmpl<child_p, parent_p>
    {
    public:
        using type_t    = child_p;
    };

    template <typename child_p, just_const_tr parent_p>
    class accessed_qualification_of_tmpl<child_p, parent_p>
    {
    public:
        using type_t    = std::add_const_t<child_p>;
    };

    template <typename child_p, just_volatile_tr parent_p>
    class accessed_qualification_of_tmpl<child_p, parent_p>
    {
    public:
        using type_t    = std::add_volatile_t<child_p>;
    };

    template <typename child_p, just_const_volatile_tr parent_p>
    class accessed_qualification_of_tmpl<child_p, parent_p>
    {
    public:
        using type_t    = std::add_const_t<std::add_volatile_t<child_p>>;
    };

    template <typename child_p, typename parent_p>
    using accessed_qualification_of_t   = accessed_qualification_of_tmpl<child_p, parent_p>::type_t;

}

namespace nkr {

    template <typename type_p>
    class type_traits_i
    {
    public:
        using of_t  = void_t;

    public:
        template <typename other_p>
        static constexpr c_bool_t   Is_Any()
        {
            static_assert(false, "you need to implement a type_traits_i for this type");
        }
    };

    template <template <typename ...> typename template_p>
    class template_traits_i
    {
    public:
        template <typename of_p>
        using type_t    = void_t;

    public:
        static constexpr c_bool_t   Is_Implemented()
        {
            static_assert(false, "you need to implement a template_traits_i for this template");
        }
    };

}

namespace nkr {

    template <any_non_type_tr type_p>
    class type_traits_i<type_p>
    {
    public:
        using of_t  = void_t;

    public:
        template <typename other_p>
        static constexpr c_bool_t   Is_Any()
        {
            return is_any_tr<other_p, type_p>;
        }
    };

}

namespace nkr {

    template <boolean_tr type_p>
    class type_traits_i<type_p>
    {
    public:
        using of_t  = void_t;

    public:
        template <typename other_p>
        static constexpr c_bool_t   Is_Any()
        {
            return is_any_tr<other_p, type_p>;
        }
    };

}

namespace nkr {

    template <number_tr type_p>
    class type_traits_i<type_p>
    {
    public:
        using of_t  = void_t;

    public:
        template <typename other_p>
        static constexpr c_bool_t   Is_Any()
        {
            return is_any_tr<other_p, type_p>;
        }
    };

}

namespace nkr {

    struct                      c_pointer_tg    {};
    template <typename> struct  c_pointer_ttg   {};

    template <c_pointer_tr type_p>
    class type_traits_i<type_p>
    {
    public:
        using of_t  = std::remove_pointer_t<type_p>;

    public:
        template <typename other_p>
        static constexpr c_bool_t   Is_Any()
        {
            return c_pointer_tr<other_p>;
        }
    };

    template <>
    class template_traits_i<c_pointer_ttg>
    {
    public:
        template <typename of_p>
        using type_t    = of_p*;

    public:
        static constexpr c_bool_t   Is_Implemented()
        {
            return true;
        }
    };

}

namespace nkr {

    struct                      c_array_tg  {};
    template <typename> struct  c_array_ttg {};

    template <c_array_tr type_p>
    class type_traits_i<type_p>
    {
    public:
        using of_t  = std::remove_reference_t<decltype(std::declval<type_p>()[0])>;

    public:
        template <typename other_p>
        static constexpr c_bool_t   Is_Any()
        {
            return c_array_tr<other_p>;
        }
    };

    template <>
    class template_traits_i<c_array_ttg>
    {
    public:
        template <typename of_p>
        using type_t    = of_p[1];

    public:
        static constexpr c_bool_t   Is_Implemented()
        {
            return true;
        }
    };

}

namespace nkr {

    template <typename type_p>
    class c_array_or_type_traits_i :
        public type_traits_i<std::remove_cv_t<type_p>>
    {
    public:
    };

    template <c_array_tr type_p>
    class c_array_or_type_traits_i<type_p> :
        public type_traits_i<type_p>
    {
    public:
    };

    template <typename child_p, typename parent_p, c_bool_t do_access>
    class accessed_or_not_tmpl
    {
    public:
        using type_t    = child_p;
    };

    template <typename child_p, typename parent_p>
    class accessed_or_not_tmpl<child_p, parent_p, true>
    {
    public:
        using type_t    = accessed_qualification_of_t<child_p, parent_p>;
    };

    template <typename child_p, typename parent_p, c_bool_t do_access>
    using accessed_or_not_t = accessed_or_not_tmpl<child_p, parent_p, do_access>::type_t;

    struct any_tg                                   { static const c_bool_t is_not = false; };
    struct any_qualified_tg                         { static const c_bool_t is_not = false; };
    struct any_non_qualified_tg                     { static const c_bool_t is_not = false; };
    struct any_const_tg                             { static const c_bool_t is_not = false; };
    struct any_non_const_tg                         { static const c_bool_t is_not = false; };
    struct any_volatile_tg                          { static const c_bool_t is_not = false; };
    struct any_non_volatile_tg                      { static const c_bool_t is_not = false; };

    struct not_any_tg                               { static const c_bool_t is_not = true; using is_tg = any_tg; };
    struct not_any_qualified_tg                     { static const c_bool_t is_not = true; using is_tg = any_qualified_tg; };
    struct not_any_non_qualified_tg                 { static const c_bool_t is_not = true; using is_tg = any_non_qualified_tg; };
    struct not_any_const_tg                         { static const c_bool_t is_not = true; using is_tg = any_const_tg; };
    struct not_any_non_const_tg                     { static const c_bool_t is_not = true; using is_tg = any_non_const_tg; };
    struct not_any_volatile_tg                      { static const c_bool_t is_not = true; using is_tg = any_volatile_tg; };
    struct not_any_non_volatile_tg                  { static const c_bool_t is_not = true; using is_tg = any_non_volatile_tg; };

    struct just_tg                                  { static const c_bool_t is_not = false; };
    struct just_non_qualified_tg                    { static const c_bool_t is_not = false; };
    struct just_const_tg                            { static const c_bool_t is_not = false; };
    struct just_volatile_tg                         { static const c_bool_t is_not = false; };
    struct just_const_volatile_tg                   { static const c_bool_t is_not = false; };

    struct just_not_tg                              { static const c_bool_t is_not = true; using is_tg = just_tg; };
    struct just_not_non_qualified_tg                { static const c_bool_t is_not = true; using is_tg = just_non_qualified_tg; };
    struct just_not_const_tg                        { static const c_bool_t is_not = true; using is_tg = just_const_tg; };
    struct just_not_volatile_tg                     { static const c_bool_t is_not = true; using is_tg = just_volatile_tg; };
    struct just_not_const_volatile_tg               { static const c_bool_t is_not = true; using is_tg = just_const_volatile_tg; };

    struct of_any_tg                                { static const c_bool_t is_accessed = false; using related_tg = any_tg; };
    struct of_any_qualified_tg                      { static const c_bool_t is_accessed = false; using related_tg = any_qualified_tg; };
    struct of_any_non_qualified_tg                  { static const c_bool_t is_accessed = false; using related_tg = any_non_qualified_tg; };
    struct of_any_const_tg                          { static const c_bool_t is_accessed = false; using related_tg = any_const_tg; };
    struct of_any_non_const_tg                      { static const c_bool_t is_accessed = false; using related_tg = any_non_const_tg; };
    struct of_any_volatile_tg                       { static const c_bool_t is_accessed = false; using related_tg = any_volatile_tg; };
    struct of_any_non_volatile_tg                   { static const c_bool_t is_accessed = false; using related_tg = any_non_volatile_tg; };

    struct of_not_any_tg                            { static const c_bool_t is_accessed = false; using related_tg = not_any_tg; };
    struct of_not_any_qualified_tg                  { static const c_bool_t is_accessed = false; using related_tg = not_any_qualified_tg; };
    struct of_not_any_non_qualified_tg              { static const c_bool_t is_accessed = false; using related_tg = not_any_non_qualified_tg; };
    struct of_not_any_const_tg                      { static const c_bool_t is_accessed = false; using related_tg = not_any_const_tg; };
    struct of_not_any_non_const_tg                  { static const c_bool_t is_accessed = false; using related_tg = not_any_non_const_tg; };
    struct of_not_any_volatile_tg                   { static const c_bool_t is_accessed = false; using related_tg = not_any_volatile_tg; };
    struct of_not_any_non_volatile_tg               { static const c_bool_t is_accessed = false; using related_tg = not_any_non_volatile_tg; };

    struct of_just_tg                               { static const c_bool_t is_accessed = false; using related_tg = just_tg; };
    struct of_just_non_qualified_tg                 { static const c_bool_t is_accessed = false; using related_tg = just_non_qualified_tg; };
    struct of_just_const_tg                         { static const c_bool_t is_accessed = false; using related_tg = just_const_tg; };
    struct of_just_volatile_tg                      { static const c_bool_t is_accessed = false; using related_tg = just_volatile_tg; };
    struct of_just_const_volatile_tg                { static const c_bool_t is_accessed = false; using related_tg = just_const_volatile_tg; };

    struct of_just_not_tg                           { static const c_bool_t is_accessed = false; using related_tg = just_not_tg; };
    struct of_just_not_non_qualified_tg             { static const c_bool_t is_accessed = false; using related_tg = just_not_non_qualified_tg; };
    struct of_just_not_const_tg                     { static const c_bool_t is_accessed = false; using related_tg = just_not_const_tg; };
    struct of_just_not_volatile_tg                  { static const c_bool_t is_accessed = false; using related_tg = just_not_volatile_tg; };
    struct of_just_not_const_volatile_tg            { static const c_bool_t is_accessed = false; using related_tg = just_not_const_volatile_tg; };

    struct of_any_accessed_tg                       { static const c_bool_t is_accessed = true; using related_tg = any_tg; };
    struct of_any_accessed_qualified_tg             { static const c_bool_t is_accessed = true; using related_tg = any_qualified_tg; };
    struct of_any_accessed_non_qualified_tg         { static const c_bool_t is_accessed = true; using related_tg = any_non_qualified_tg; };
    struct of_any_accessed_const_tg                 { static const c_bool_t is_accessed = true; using related_tg = any_const_tg; };
    struct of_any_accessed_non_const_tg             { static const c_bool_t is_accessed = true; using related_tg = any_non_const_tg; };
    struct of_any_accessed_volatile_tg              { static const c_bool_t is_accessed = true; using related_tg = any_volatile_tg; };
    struct of_any_accessed_non_volatile_tg          { static const c_bool_t is_accessed = true; using related_tg = any_non_volatile_tg; };

    struct of_not_any_accessed_tg                   { static const c_bool_t is_accessed = true; using related_tg = not_any_tg; };
    struct of_not_any_accessed_qualified_tg         { static const c_bool_t is_accessed = true; using related_tg = not_any_qualified_tg; };
    struct of_not_any_accessed_non_qualified_tg     { static const c_bool_t is_accessed = true; using related_tg = not_any_non_qualified_tg; };
    struct of_not_any_accessed_const_tg             { static const c_bool_t is_accessed = true; using related_tg = not_any_const_tg; };
    struct of_not_any_accessed_non_const_tg         { static const c_bool_t is_accessed = true; using related_tg = not_any_non_const_tg; };
    struct of_not_any_accessed_volatile_tg          { static const c_bool_t is_accessed = true; using related_tg = not_any_volatile_tg; };
    struct of_not_any_accessed_non_volatile_tg      { static const c_bool_t is_accessed = true; using related_tg = not_any_non_volatile_tg; };

    struct of_just_accessed_tg                      { static const c_bool_t is_accessed = true; using related_tg = just_tg; };
    struct of_just_accessed_non_qualified_tg        { static const c_bool_t is_accessed = true; using related_tg = just_non_qualified_tg; };
    struct of_just_accessed_const_tg                { static const c_bool_t is_accessed = true; using related_tg = just_const_tg; };
    struct of_just_accessed_volatile_tg             { static const c_bool_t is_accessed = true; using related_tg = just_volatile_tg; };
    struct of_just_accessed_const_volatile_tg       { static const c_bool_t is_accessed = true; using related_tg = just_const_volatile_tg; };

    struct of_just_not_accessed_tg                  { static const c_bool_t is_accessed = true; using related_tg = just_not_tg; };
    struct of_just_not_accessed_non_qualified_tg    { static const c_bool_t is_accessed = true; using related_tg = just_not_non_qualified_tg; };
    struct of_just_not_accessed_const_tg            { static const c_bool_t is_accessed = true; using related_tg = just_not_const_tg; };
    struct of_just_not_accessed_volatile_tg         { static const c_bool_t is_accessed = true; using related_tg = just_not_volatile_tg; };
    struct of_just_not_accessed_const_volatile_tg   { static const c_bool_t is_accessed = true; using related_tg = just_not_const_volatile_tg; };

    template <
        typename subject_p,
        typename operator_p
    > constexpr c_bool_t TR0()
    {
        using subject_t = subject_p;

        if constexpr (is_tr<operator_p, any_tg>)                            return true;
        else if constexpr (is_tr<operator_p, any_qualified_tg>)             return any_qualified_tr<subject_t>;
        else if constexpr (is_tr<operator_p, any_non_qualified_tg>)         return any_non_qualified_tr<subject_t>;
        else if constexpr (is_tr<operator_p, any_const_tg>)                 return any_const_tr<subject_t>;
        else if constexpr (is_tr<operator_p, any_non_const_tg>)             return any_non_const_tr<subject_t>;
        else if constexpr (is_tr<operator_p, any_volatile_tg>)              return any_volatile_tr<subject_t>;
        else if constexpr (is_tr<operator_p, any_non_volatile_tg>)          return any_non_volatile_tr<subject_t>;

        else if constexpr (is_tr<operator_p, not_any_tg>)                   return false;
        else if constexpr (is_tr<operator_p, not_any_qualified_tg>)         return not_any_qualified_tr<subject_t>;
        else if constexpr (is_tr<operator_p, not_any_non_qualified_tg>)     return not_any_non_qualified_tr<subject_t>;
        else if constexpr (is_tr<operator_p, not_any_const_tg>)             return not_any_const_tr<subject_t>;
        else if constexpr (is_tr<operator_p, not_any_non_const_tg>)         return not_any_non_const_tr<subject_t>;
        else if constexpr (is_tr<operator_p, not_any_volatile_tg>)          return not_any_volatile_tr<subject_t>;
        else if constexpr (is_tr<operator_p, not_any_non_volatile_tg>)      return not_any_non_volatile_tr<subject_t>;

        else if constexpr (is_tr<operator_p, just_tg>)                      return true;
        else if constexpr (is_tr<operator_p, just_non_qualified_tg>)        return just_non_qualified_tr<subject_t>;
        else if constexpr (is_tr<operator_p, just_const_tg>)                return just_const_tr<subject_t>;
        else if constexpr (is_tr<operator_p, just_volatile_tg>)             return just_volatile_tr<subject_t>;
        else if constexpr (is_tr<operator_p, just_const_volatile_tg>)       return just_const_volatile_tr<subject_t>;

        else if constexpr (is_tr<operator_p, just_not_tg>)                  return false;
        else if constexpr (is_tr<operator_p, just_not_non_qualified_tg>)    return not_just_non_qualified_tr<subject_t>;
        else if constexpr (is_tr<operator_p, just_not_const_tg>)            return not_just_const_tr<subject_t>;
        else if constexpr (is_tr<operator_p, just_not_volatile_tg>)         return not_just_volatile_tr<subject_t>;
        else if constexpr (is_tr<operator_p, just_not_const_volatile_tg>)   return not_just_const_volatile_tr<subject_t>;

        else                                                                static_assert(false, "undefined operator");
    }

    template <
        typename subject_p,
        typename operator_p, typename operand_p
    > constexpr c_bool_t TR1()
    {
        using subject_t = subject_p;
        using object_t = operand_p;

        if constexpr (type_traits_i<std::remove_cv_t<object_t>>::template Is_Any<std::remove_cv_t<subject_t>>()) {
            if constexpr (is_tr<operator_p, just_tg>) {
                return is_tr<object_t, same_qualification_as_t<object_t, subject_p>>;
            } else if constexpr (is_tr<operator_p, just_not_tg>) {
                return !is_tr<object_t, same_qualification_as_t<object_t, subject_p>>;
            } else {
                return TR0<subject_t, operator_p>();
            }
        } else {
            return operator_p::is_not;
        }
    }

    template <
        typename subject_p,
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, typename of_operand_p
    > constexpr c_bool_t TR2()
    {
        static_assert(template_traits_i<operand_p>::Is_Implemented());

        using subject_t = subject_p;
        using of_subject_t = accessed_or_not_t<typename c_array_or_type_traits_i<subject_t>::of_t, subject_t, of_operator_p::is_accessed>;
        using object_t = template_traits_i<operand_p>::template type_t<of_operand_p>;
        using of_object_t = of_operand_p;

        if constexpr (operator_p::is_not) {
            return
                !(TR1<subject_t, typename operator_p::is_tg, object_t>() &&
                  TR1<of_subject_t, typename of_operator_p::related_tg, of_object_t>());
        } else {
            return
                TR1<subject_t, operator_p, object_t>() &&
                TR1<of_subject_t, typename of_operator_p::related_tg, of_object_t>();
        }
    }

    template <
        typename subject_p,
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, template <typename ...> typename of_operand_p,
        typename of_of_operator_p, typename of_of_operand_p
    > constexpr c_bool_t TR3()
    {
        static_assert(template_traits_i<of_operand_p>::Is_Implemented());

        using subject_t = subject_p;
        using of_subject_t = accessed_or_not_t<typename c_array_or_type_traits_i<subject_t>::of_t, subject_t, of_of_operator_p::is_accessed>;
        using of_of_subject_t = accessed_or_not_t<typename c_array_or_type_traits_i<of_subject_t>::of_t, of_subject_t, of_of_operator_p::is_accessed>;
        using of_object_t = template_traits_i<of_operand_p>::template type_t<of_of_operand_p>;
        using of_of_object_t = of_of_operand_p;

        if constexpr (operator_p::is_not) {
            return
                !(TR2<subject_t, typename operator_p::is_tg, operand_p, of_operator_p, of_object_t>() &&
                  TR1<of_of_subject_t, typename of_of_operator_p::related_tg, of_of_object_t>());
        } else {
            return
                TR2<subject_t, operator_p, operand_p, of_operator_p, of_object_t>() &&
                TR1<of_of_subject_t, typename of_of_operator_p::related_tg, of_of_object_t>();
        }
    }

    template <
        typename subject_p,
        typename operator_p
    > concept tr0 =
        TR0<subject_p, operator_p>();

    template <
        typename subject_p,
        typename operator_p, typename operand_p
    > concept tr1 =
        TR1<subject_p, operator_p, operand_p>();

    template <
        typename subject_p,
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, typename of_operand_p
    > concept tr2 =
        TR2<subject_p, operator_p, operand_p, of_operator_p, of_operand_p>();

    template <
        typename subject_p,
        typename operator_p, template <typename ...> typename operand_p,
        typename of_operator_p, template <typename ...> typename of_operand_p,
        typename of_of_operator_p, typename of_of_operand_p
    > concept tr3 =
        TR3<subject_p, operator_p, operand_p, of_operator_p, of_operand_p, of_of_operator_p, of_of_operand_p>();

}