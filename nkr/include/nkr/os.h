/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/bool_t.h"
#include "nkr/intrinsics.h"
#include "nkr/traits.h"

namespace nkr {

    /// @ingroup _d1cd4369_e0f4_4062_8f58_611395da215e
    /// @copydoc _ae5b9a84_c87b_4c0a_b714_4933761921d7
    namespace os {

        /// @ingroup _d1cd4369_e0f4_4062_8f58_611395da215e
        /// @copydoc _a6ff4022_7389_4e35_b146_066ce313290e
        namespace atomic {}

        
        /// @ingroup _d1cd4369_e0f4_4062_8f58_611395da215e
        /// @copydoc _652312c1_72a2_4b36_88ab_aee6adf8e9c9
        namespace endian {}

        
        /// @ingroup _d1cd4369_e0f4_4062_8f58_611395da215e
        /// @copydoc _a6c4699b_8fe4_4664_ac57_062765decc2b
        namespace heap {}

        namespace math {}

    }

}

namespace nkr { namespace os { namespace atomic {

    /// @name Access
    /// @copydoc _ebc609cf_5026_47e9_87e7_c8ea9ecc71a9
    /// @{
    template <fundamental_tr atom_p>
    atom_p  Access(volatile const atom_p& atom);    ///< @copydoc _7c65ec60_0408_4a55_8cb6_e01ed4e45aa8
    /// @}
    
    /// @name Assign
    /// @copydoc _d42247f7_a7b1_442f_beef_c88857ee5682
    /// @{
    template <fundamental_tr atom_p, convertible_tr<atom_p> value_p>
    atom_p  Assign(volatile atom_p& atom, value_p value);               ///< @copydoc _fab7ff12_4852_456f_ad51_fc9ec8b5fb4f

    template <number_tr atom_p, convertible_tr<atom_p> value_p>
    atom_p  Assign_Add(volatile atom_p& atom, value_p value);           ///< @copydoc _ae07793f_9604_443c_901c_718a00cc093c
    template <type_pointer_tr atom_p, integer_tr value_p>
    atom_p  Assign_Add(volatile atom_p& atom, value_p value);           ///< @copydoc _cbe72d03_f920_4d4d_a53c_68537d91e06e
    template <number_tr atom_p, convertible_tr<atom_p> value_p>
    atom_p  Assign_Subtract(volatile atom_p& atom, value_p value);      ///< @copydoc _61dc311f_27ca_49a9_950a_9f3c9171b715
    template <type_pointer_tr atom_p, integer_tr value_p>
    atom_p  Assign_Subtract(volatile atom_p& atom, value_p value);      ///< @copydoc _165233f2_0ca5_45bf_9b4d_c09253b1700c
    template <number_tr atom_p, convertible_tr<atom_p> value_p>
    atom_p  Assign_Multiply(volatile atom_p& atom, value_p value);      ///< @copydoc _db2ab814_83b3_42b5_9c32_44dfe8126b9d
    template <number_tr atom_p, convertible_tr<atom_p> value_p>
    atom_p  Assign_Divide(volatile atom_p& atom, value_p value);        ///< @copydoc _388e4f09_010e_4578_8cc7_2255da0a4b4c
    template <integer_tr atom_p, integer_tr value_p>
    atom_p  Assign_Modulus(volatile atom_p& atom, value_p value);       ///< @copydoc _76252e5c_09e8_446b_82dc_295f1dc684d2

    template <integer_tr atom_p, integer_tr value_p>
    atom_p  Assign_Or(volatile atom_p& atom, value_p value);            ///< @copydoc _3f60e4fa_e39f_4e59_b88c_610282e72227
    template <integer_tr atom_p, integer_tr value_p>
    atom_p  Assign_And(volatile atom_p& atom, value_p value);           ///< @copydoc _50094866_0d5e_4d6e_8003_080350799b02
    template <integer_tr atom_p, integer_tr value_p>
    atom_p  Assign_Xor(volatile atom_p& atom, value_p value);           ///< @copydoc _f6c4cd5b_7f03_477b_968b_b65a1d79c37b
    template <integer_tr atom_p, integer_tr value_p>
    atom_p  Assign_Left_Shift(volatile atom_p& atom, value_p value);    ///< @copydoc _1988a49f_e149_41e5_acf1_5ee55d64e7a9
    template <integer_tr atom_p, integer_tr value_p>
    atom_p  Assign_Right_Shift(volatile atom_p& atom, value_p value);   ///< @copydoc _33d2bc67_7ea7_4519_83e6_0145d0c4c10d
    /// @}
    
    /// @name Exchange
    /// @copydoc _73d8454a_28bc_4509_b695_6bd373d375f2
    /// @{
    template <fundamental_tr atom_p, convertible_tr<atom_p> value_p>
    atom_p  Exchange(volatile atom_p& atom, value_p value);                             ///< @copydoc _d3109948_6d58_465c_9c35_1b3bc078193b

    template <number_tr atom_p, convertible_tr<atom_p> value_p>
    atom_p  Exchange_Add(volatile atom_p& atom, value_p value);                         ///< @copydoc _1636a842_cd0e_4a20_a69b_08777cf45e13
    template <type_pointer_tr atom_p, integer_tr value_p>
    atom_p  Exchange_Add(volatile atom_p& atom, value_p value);                         ///< @copydoc _cc0888ae_0348_4464_8425_d59c2563a3b9
    template <number_tr atom_p, convertible_tr<atom_p> value_p>
    atom_p  Exchange_Subtract(volatile atom_p& atom, value_p value);                    ///< @copydoc _be5c47cb_bbce_4c8f_b1c9_f6f5564b1727
    template <type_pointer_tr atom_p, integer_tr value_p>
    atom_p  Exchange_Subtract(volatile atom_p& atom, value_p value);                    ///< @copydoc _4160b14b_f8e3_4e5b_8340_b8e9285d1caa
    template <number_tr atom_p, convertible_tr<atom_p> value_p>
    atom_p  Exchange_Multiply(volatile atom_p& atom, value_p value);                    ///< @copydoc _9b10e14c_d868_4740_b2dd_40ee361019f0
    template <number_tr atom_p, convertible_tr<atom_p> value_p>
    atom_p  Exchange_Divide(volatile atom_p& atom, value_p value);                      ///< @copydoc _0c2871ea_dbfa_4075_bee1_84f0017ec54c
    template <integer_tr atom_p, integer_tr value_p>
    atom_p  Exchange_Modulus(volatile atom_p& atom, value_p value);                     ///< @copydoc _75c6f727_7922_4ce2_8650_5c94e52b180e

    template <integer_tr atom_p, integer_tr value_p>
    atom_p  Exchange_Or(volatile atom_p& atom, value_p value);                          ///< @copydoc _67e27237_78f0_4fe0_b667_15076d266dbc
    template <integer_tr atom_p, integer_tr value_p>
    atom_p  Exchange_And(volatile atom_p& atom, value_p value);                         ///< @copydoc _43f052df_aa5c_4c1d_be58_1059147ba0c1
    template <integer_tr atom_p, integer_tr value_p>
    atom_p  Exchange_Xor(volatile atom_p& atom, value_p value);                         ///< @copydoc _46e8118f_a77b_41c8_9f75_d1953aad71d8
    template <integer_tr atom_p, integer_tr value_p>
    atom_p  Exchange_Left_Shift(volatile atom_p& atom, value_p value);                  ///< @copydoc _a5e26340_6895_4258_ab06_7f6968cd5830
    template <integer_tr atom_p, integer_tr value_p>
    atom_p  Exchange_Right_Shift(volatile atom_p& atom, value_p value);                 ///< @copydoc _37998d5d_eb21_4e93_83bf_ef1bfb1152c7

    template <fundamental_tr atom_p, convertible_tr<atom_p> value_p>
    bool_t  Exchange_If_Equals(volatile atom_p& atom, atom_p& snapshot, value_p value); ///< @copydoc _58b2d01f_9868_4a75_a3c8_da7371ab555e
    /// @}

}}}

namespace nkr { namespace os { namespace endian {

    /// @name Info
    /// @copydoc _026b191f_2e76_4010_9760_e1215a647d9c
    /// @{
    constexpr std_bool_t    Is_Big();       ///< @copydoc _9d5ef4e6_ff8f_4d63_9fdc_0c0422259d90
    constexpr std_bool_t    Is_Little();    ///< @copydoc _884ae9eb_da64_4306_aab9_50aeb3f85298
    /// @}

    /// @name Swap
    /// @copydoc _b5b179fb_1f64_485e_9510_80260e3a6c33
    /// @{
    template <integer_16_tr integer_p>
    integer_p   Swap(integer_p bytes);  ///< @copydoc _857ce8b6_02ca_48e5_9d19_4a7581b8e4c6
    template <integer_32_tr integer_p>
    integer_p   Swap(integer_p bytes);  ///< @copydoc _02c0499c_c8c8_43b9_8afc_96545310eb3a
    template <integer_64_tr integer_p>
    integer_p   Swap(integer_p bytes);  ///< @copydoc _eabf9a88_080f_445d_88ab_b0dae4a55316
    /// @}

}}}

namespace nkr { namespace os { namespace heap {

    /// @name Allocation
    /// @copydoc _30c0ffe4_d85f_45e5_ab29_bd3f18629cb9
    /// @{
    bool_t  Allocate(type_tr auto*& units, count_t unit_count);         ///< @copydoc _52a0d839_49c8_4d77_93b1_353137fecd3b
    bool_t  Reallocate(type_tr auto*& units, count_t new_unit_count);   ///< @copydoc _06fa627b_ba42_4b70_b0dd_66146e6d863a
    void_t  Deallocate(type_tr auto*& units);                           ///< @copydoc _de0237bf_9b0a_47fc_a5ab_99f21504f570
    /// @}
    
    /// @name Zero-Initialized Allocation
    /// @copydoc _eca47636_431b_4d2a_a102_679075b3cf17
    /// @{
    bool_t  Allocate_Zeros(type_tr auto*& units, count_t unit_count);       ///< @copydoc _9c5a7296_5644_47bf_bd3f_ff7de3518ce9
    bool_t  Reallocate_Zeros(type_tr auto*& units, count_t new_unit_count); ///< @copydoc _7d7887a0_3e2d_4502_af8c_d409aae73f0b
    void_t  Deallocate_Zeros(type_tr auto*& units);                         ///< @copydoc _04d9a3fe_30b3_4ae2_bbc4_2a3cfc4768d6
    /// @}

}}}

namespace nkr { namespace os { namespace math {

    /// @name Overflow
    /// @{
    template <number_tr number_p>
    bool_t  Will_Overflow_Add(number_p lhs, number_p rhs);
    template <number_tr number_p>
    bool_t  Will_Overflow_Subtract(number_p lhs, number_p rhs);
    template <number_tr number_p>
    bool_t  Will_Overflow_Multiply(number_p lhs, number_p rhs);
    template <number_tr number_p>
    bool_t  Will_Overflow_Divide(number_p lhs, number_p rhs);
    /// @}

}}}

#include "nkr/os.inl"
