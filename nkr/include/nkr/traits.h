/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsics.h"

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

    /// @addtogroup _a5f738af_46d1_4576_aaf6_adbc60dc07fe
    /// @{
    template <typename type_p>
    concept any_tr =
        true;                                       ///< @copydoc _2a77c3a0_ab8b_448e_a181_72b8efb266bf

    template <typename type_p>
    concept type_tr =
        sizeof(type_p) > 0;                         ///< @copydoc _0faa812f_3422_4143_b1d3_8987fcf84eae

    template <typename non_type_p>
    concept non_type_tr =
        !type_tr<non_type_p>;

    template <typename type_p>
    concept writable_tr =
        type_tr<type_p> &&
        !std::is_const_v<type_p>;

    template <typename type_p>
    concept unwritable_tr =
        !type_tr<type_p> ||
        std::is_const_v<type_p>;

    template <typename from_p, typename to_p>
    concept convertible_tr =
        std::convertible_to<from_p, to_p>;

    template <typename type_p, typename other_p>
    concept size_eq_tr =
        sizeof(type_p) == sizeof(other_p);

    template <typename type_p, typename other_p>
    concept size_le_tr =
        sizeof(type_p) <= sizeof(other_p);

    template <typename type_p>
    concept boolean_tr =
        std::same_as<std::remove_cv_t<type_p>, bool_t> ||
        std::same_as<std::remove_cv_t<type_p>, std_bool_t>; /// @copydoc _3e4ef7df_7326_49f0_83e0_378911e03952

    template <typename type_p>
    concept to_boolean_tr =
        std::convertible_to<type_p, bool_t> ||
        std::convertible_to<type_p, std_bool_t>;    ///< @copydoc _2c84f547_56c5_48a6_b6eb_3c0244998edc

    template <typename type_p>
    concept to_std_bool_tr =
        std::convertible_to<type_p, std_bool_t>;
    /// @}

    /// @addtogroup _222d304c_42db_4988_8611_c8aedc33c6cc
    /// @{
    template <typename type_p>
    concept integer_tr =
        std::is_integral<type_p>::value &&
        !std::same_as<std::remove_cv_t<type_p>, std_bool_t>;    ///< @copydoc _ead4c138_69b3_4da6_905d_61c157fd5451

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
    concept pointer_tr =
        std::is_null_pointer<type_p>::value ||
        std::is_pointer<type_p>::value;         ///< @copydoc _42df3700_b206_4dec_a280_cc34bfd783ea

    template <typename type_p>
    concept void_pointer_tr =
        pointer_tr<type_p> &&
        !type_tr<std::remove_pointer_t<type_p>>;

    template <typename type_p>
    concept type_pointer_tr =
        pointer_tr<type_p> &&
        type_tr<std::remove_pointer_t<type_p>>; ///< @copydoc _6a988ebe_eb59_44c5_9b34_45259e710dc7

    template <typename type_p>
    concept array_tr =
        is_array_tmpl<type_p>::value;

    template <typename type_p, typename of_p>
    concept array_of_tr =
        array_tr<type_p> &&
        std::same_as<typename is_array_tmpl<type_p>::unit_t, of_p>;

    template <typename type_p>
    concept built_in_tr =
        std::same_as<std::remove_cv_t<type_p>, std_bool_t> ||
        integer_tr<type_p> ||
        real_tr<type_p> ||
        pointer_tr<type_p>;                     ///< @copydoc _13b4b6b8_807a_4ed1_beae_dfd94e04e0f0

    template <typename type_p>
    concept user_defined_tr =
        !built_in_tr<type_p>;                   ///< @copydoc _3818a648_654b_43d9_9c9d_18527bc45131

    template <typename type_p>
    concept fundamental_tr =
        boolean_tr<type_p> ||
        integer_tr<type_p> ||
        real_tr<type_p> ||
        pointer_tr<type_p>;
    /// @}

    // qualifiers
    template <typename type_p>
    concept const_tr =
        std::is_const_v<type_p>;

    template <typename type_p>
    concept volatile_tr =
        std::is_volatile_v<type_p>;

    template <typename type_p>
    concept unqualified_tr =
        !const_tr<type_p> &&
        !volatile_tr<type_p>;

    template <typename type_p>
    concept only_const_tr =
        const_tr<type_p> &&
        !volatile_tr<type_p>;

    template <typename type_p>
    concept only_volatile_tr =
        volatile_tr<type_p> &&
        !const_tr<type_p>;

    template <typename type_p>
    concept const_volatile_tr =
        const_tr<type_p> &&
        volatile_tr<type_p>;

    /// @addtogroup _a5f738af_46d1_4576_aaf6_adbc60dc07fe
    /// @{
    template <typename type_a_p, typename type_b_p>
    concept same_as_tr =
        std::same_as<type_a_p, type_b_p>;

    template <typename type_a_p, typename type_b_p>
    concept same_as_any_tr =
        same_as_tr<std::remove_cvref_t<type_a_p>, std::remove_cvref_t<type_b_p>>;

    template <typename type_a_p, typename type_b_p>
    concept same_as_any_lvalue_tr =
        same_as_any_tr<type_a_p, type_b_p> &&
        std::is_lvalue_reference_v<type_a_p>;

    template <typename type_a_p, typename type_b_p>
    concept same_as_any_writable_tr =
        same_as_any_tr<type_a_p, type_b_p> &&
        writable_tr<type_a_p>;

    template <typename type_a_p, typename type_b_p>
    concept same_as_any_writable_rvalue_tr =
        same_as_any_writable_tr<type_a_p, type_b_p> &&
        std::is_rvalue_reference_v<type_a_p>;

    template <typename type_a_p, typename type_b_p>
    concept same_as_any_unwritable_tr =
        same_as_any_tr<type_a_p, type_b_p> &&
        unwritable_tr<type_a_p>;

    template <typename type_a_p, typename type_b_p>
    concept convertible_to_tr =
        std::convertible_to<type_a_p, type_b_p>;

    template <typename type_a_p, typename type_b_p>
    concept convertible_to_any_tr =
        convertible_to_tr<std::remove_cvref_t<type_a_p>, std::remove_cvref_t<type_b_p>>;

    template <typename type_a_p, typename type_b_p>
    concept convertible_to_any_writable_tr =
        convertible_to_any_tr<type_a_p, type_b_p> &&
        writable_tr<type_a_p>;

    template <typename type_a_p, typename type_b_p>
    concept convertible_to_any_unwritable_tr =
        convertible_to_any_tr<type_a_p, type_b_p>;

    template <typename type_p, typename derived_p>
    concept same_or_base_of_tr =
        std::is_same<std::remove_cvref_t<type_p>, std::remove_cvref_t<derived_p>>::value ||
        std::is_base_of<std::remove_cvref_t<type_p>, std::remove_cvref_t<derived_p>>::value;    ///< @copydoc _eff1ff48_96ed_4134_abae_5d29c91fd554

    template <typename type_p, typename base_p>
    concept same_or_derived_from_tr =
        std::is_same<std::remove_cvref_t<type_p>, std::remove_cvref_t<base_p>>::value ||
        std::is_convertible<std::remove_cvref_t<type_p>, std::remove_cvref_t<base_p>>::value;   ///< @copydoc _a08a3aa7_12f3_4e3f_8515_610fa450219b
    /// @}

}
