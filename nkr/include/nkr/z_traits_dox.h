/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

/**
* @defgroup _a5f738af_46d1_4576_aaf6_adbc60dc07fe traits
*
* @brief
*   C++20 concepts that are used to filter types in templates.
*
* @details
*   The term "trait" is not used in any standard C++ capacity, but specifically for use with this library. All trait names are followed by the "_tr" postfix to indicate that they are C++20 concepts used in place of 'typename' in template declarations.
*
* @todo
*   Add an example or several.
*/

    // any_type_tr
    /**
    * @class _0faa812f_3422_4143_b1d3_8987fcf84eae
    * @private
    * 
    * @brief
    *   An actual type. Pretty much anything but nkr::void_t.
    */

    // boolean_tr
    /**
    * @class _3e4ef7df_7326_49f0_83e0_378911e03952
    * @private
    * 
    * @brief
    *   Includes both nkr::c_bool_t and nkr::bool_t.
    */

    // to_boolean_tr
    /**
    * @class _2c84f547_56c5_48a6_b6eb_3c0244998edc
    * @private
    */

    /**
    * @defgroup _222d304c_42db_4988_8611_c8aedc33c6cc integers
    * @ingroup _a5f738af_46d1_4576_aaf6_adbc60dc07fe
    *
    * @brief
    *   Filter types that can be treated as integers.
    * 
    * @note
    *   None of these integer traits allow nkr::bool_t.
    */

        // integer_tr
        /**
        * @class _ead4c138_69b3_4da6_905d_61c157fd5451
        * @private
        * 
        * @brief
        *   Either unsigned or signed integers.
        */

        // integer_unsigned_tr
        /**
        * @class _7099e20b_1e48_4d00_93a4_4932ad1baf1d
        * @private
        */

        // integer_signed_tr
        /**
        * @class _f2900e04_a6a5_4d04_bed5_61932038deb2
        * @private
        */

        // integer_word_tr
        /**
        * @class _ddbfd7fa_7bd7_4121_988b_671b57bcd24f
        * @private
        * 
        * @brief
        *   Only allows integers that are the same size as nkr::word_t.
        */

        // integer_8_tr
        /**
        * @class _b70bda64_61e7_4743_a015_ed6cf0bb426f
        * @private
        */

        // integer_16_tr
        /**
        * @class _fa1ef979_a5ad_4040_9824_060e12cac0a9
        * @private
        */

        // integer_32_tr
        /**
        * @class _3e2e08b8_7594_4766_8c65_d8ab87b0ed43
        * @private
        */

        // integer_64_tr
        /**
        * @class _a5b7d6de_d392_48a1_893d_8bdc9d2ba8e6
        * @private
        */

        // to_integer_tr
        /**
        * @class _c60bd667_fcb7_46cb_9c59_7ebcdf40c878
        * @private
        */

    /**
    * @defgroup _8f223336_ce2a_4589_b4c1_75cd98cd393d reals
    * @ingroup _a5f738af_46d1_4576_aaf6_adbc60dc07fe
    */

        // real_tr
        /**
        * @class _7436208f_39ce_49f4_accb_a3bee797b12a
        * @private
        */

        // real_32_tr
        /**
        * @class _63562b29_b254_4e38_b931_b895a7d86c75
        * @private
        */

        // real_64_tr
        /**
        * @class _5a831ea1_e707_476a_9f37_317ad35b94c7
        * @private
        */

        // to_real_tr
        /**
        * @class _f7cc78f8_c257_4193_b5bb_749f1656e614
        * @private
        */

    // c_pointer_tr
    /**
    * @class _42df3700_b206_4dec_a280_cc34bfd783ea
    * @private
    * 
    * @brief
    *   In addition to regular pointers, this also includes nullptr.
    */

    // type_pointer_tr
    /**
    * @class _6a988ebe_eb59_44c5_9b34_45259e710dc7
    * @private
    * 
    * @brief
    *   Only pointers that point to a any_type_tr type, which includes std::nullptr_t.
    */

    // built_in_tr
    /**
    * @class _13b4b6b8_807a_4ed1_beae_dfd94e04e0f0
    * @private
    *
    * @brief
    *   Includes nkr::c_bool_t, nkr::integer_tr, nkr::real_tr, and nkr::c_pointer_tr. The opposite of nkr::user_defined_tr.
    */

    // user_defined_tr
    /**
    * @class _3818a648_654b_43d9_9c9d_18527bc45131
    * @private
    * 
    * @brief
    *   Includes non-built-in types, the opposite of nkr::built_in_tr.
    */

    // same_or_base_of_tr
    /**
    * @class _eff1ff48_96ed_4134_abae_5d29c91fd554
    * @private
    */

    // same_or_derived_from_tr
    /**
    * @class _a08a3aa7_12f3_4e3f_8515_610fa450219b
    * @private
    */
