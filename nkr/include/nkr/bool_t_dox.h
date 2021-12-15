/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

/////////////////////////////////////////////////////////////////////////////// Docs
// bool_deleted_operators_t
/**
* @class _56a7c1d1_2a01_4357_bfd8_68f2c4ba0a0b
* @private
* 
* @brief
*   Operators that shouldn't be usable with a boolean value.
* 
* @details
*   Although there is nothing prohibiting a user from using a nkr::c_bool_t to achieve anything they need to with the regular C++ `bool`, our custom nkr::bool_t and other types which act as a bool disallow any usage of operators which just don't make any sense with a boolean data type.
*/

    // operators
    /**
    * @class _63992199_008e_4db4_a4fe_1b42753f9108
    * @private
    */

        // +()
        /**
        * @class _1f100902_7552_43e6_8b6a_6b1e0874da84
        * @private
        */

        // -()
        /**
        * @class _9ad48fba_f897_41ea_8039_347ee09b54e3
        * @private
        */

        // +(auto)
        /**
        * @class _12fff5f7_a821_4366_b614_6403de624cb6
        * @private
        */

        // -(auto)
        /**
        * @class _e82bd7a7_f549_4832_8529_0dbc6b8d812b
        * @private
        */

        // *(auto)
        /**
        * @class _a58ca6c0_d1ac_4b78_bac7_4f81d6032960
        * @private
        */

        // /(auto)
        /**
        * @class _3d24a3f6_1d75_403c_91ee_82a596041ddc
        * @private
        */

        // %(auto)
        /**
        * @class _140cc050_58e7_46d7_808b_ae8f051ab06d
        * @private
        */

        // ~()
        /**
        * @class _3adc796a_c73a_40e1_8f65_b26d327f103f
        * @private
        */

        // |(auto)
        /**
        * @class _6ba0b8a2_e68a_4eeb_a391_2eb7edad5aa0
        * @private
        */

        // &(auto)
        /**
        * @class _90f4bff8_0678_46a2_84b7_9b7081cebae4
        * @private
        */

        // ^(auto)
        /**
        * @class _85dd34aa_8e29_40e9_a4ac_de6637d556c2
        * @private
        */

        // <<(auto)
        /**
        * @class _894a3185_160f_4018_8114_561e44f9aaa7
        * @private
        */

        // >>(auto)
        /**
        * @class _7e7d875d_e409_4654_b45f_501feb2ffc3f
        * @private
        */

        // +=(auto)
        /**
        * @class _73d1ce59_ce48_4c32_bbbb_03a378c8ca48
        * @private
        */

        // -=(auto)
        /**
        * @class _8d3e20f7_f92a_4591_a545_4de2ffdb43a4
        * @private
        */

        // *=(auto)
        /**
        * @class _d8920ba2_44e0_4516_aca0_99439cca0de0
        * @private
        */

        // /=(auto)
        /**
        * @class _f5499a07_cc9e_43c2_9a20_deab15ec0aff
        * @private
        */

        // %=(auto)
        /**
        * @class _c03ae8be_f59f_496e_8b17_f1edb7a67ae9
        * @private
        */

        // |=(auto)
        /**
        * @class _90422d47_6b7c_49fc_9393_1089e91f341a
        * @private
        */

        // &=(auto)
        /**
        * @class _479241c9_0a76_4cb9_a26f_3f35b56f90aa
        * @private
        */

        // ^=(auto)
        /**
        * @class _c164e46c_c85c_4ab2_be03_3ddc622e3646
        * @private
        */

        // <<=(auto)
        /**
        * @class _518b4d5f_320b_46b8_8971_4a4ea3dde917
        * @private
        */

        // >>=(auto)
        /**
        * @class _115ae575_9520_4203_b9d0_e319faf4a676
        * @private
        */

        // ++()
        /**
        * @class _36330991_852b_4ed5_9dcb_c51ab1d90bfb
        * @private
        */

        // ++(int)
        /**
        * @class _b883f925_4116_4058_a59a_b74f1c6bea0c
        * @private
        */

        // --()
        /**
        * @class _ae2ac00f_983e_4d1f_8aa7_a932a2463539
        * @private
        */

        // --(int)
        /**
        * @class _aae68f23_68be_4723_b129_27e1b064b688
        * @private
        */

        // <(auto)
        /**
        * @class _c7f6c32d_df0d_488b_ae25_2cec51909868
        * @private
        */

        // >(auto)
        /**
        * @class _e9f6726d_8a63_4bc6_b512_4853ec37dc10
        * @private
        */

        // <=(auto)
        /**
        * @class _8b0e6e22_70f4_408a_9775_352018b7c1d1
        * @private
        */

        // >=(auto)
        /**
        * @class _f570ba0f_2172_4ea8_b0ea_c6ec4d6ed994
        * @private
        */

        // <=>(auto)
        /**
        * @class _28e396ed_43f8_42b1_80ce_7042c690e66f
        * @private
        */

// bool_t
/**
* @class _2add9928_e370_4943_ba5b_2950d9e1da99
* @private
* 
* @brief
*   The default boolean type of this library which replaces nkr::c_bool_t.
* 
* @details
*   Because nkr::c_bool_t (or `bool`) allows for integer operations to be done upon it, we've made a wrapper that completely disallows all such operations, truly making nkr::bool_t a real boolean value as opposed to a pseudo-integer. It behaves like a boolean should and transiently works in expressions like nkr::c_bool_t. It also matches the size of the word of the machine, that is nkr::word_t, whereas nkr::c_bool_t is implementation defined. All library types and functions utilitze nkr::bool_t and use nkr::c_bool_t only for necessary C++ idioms.
* 
* @snippet "./src/bool_t.cpp" _29b44101_c393_4fdd_b59d_cb9a75802d5a
*/

    // object data
    /**
    * @class _3dbc082f_9df8_4eda_b07f_fca297cc63a9
    * @private
    */

        // value
        /**
        * @class _9eefd4d6_1786_42ec_970a_c16c9bde2d42
        * @private
        * 
        * @details
        *   Although this is protected, you can still directly change the underlying value through the cast operators.
        * 
        * @copydoc _cba26a61_2c51_4e87_90c7_26cb873a083d
        * 
        * @snippet "./src/bool_t.cpp" _a89a1659_6cb8_4255_a6da_a2c1e5869af4
        * @snippet "./src/bool_t.cpp" _7d5433ff_7c1f_4566_b1ab_55367dfb36b8
        */

    // objects
    /**
    * @class _727e30a1_ed17_4451_aefd_e9ff35d4be9c
    * @private
    */

        // default_ctor()
        /**
        * @class _507e6865_70dc_4e5b_97ab_c0d33e53dc67
        * @private
        * 
        * @snippet "./src/bool_t.cpp" _a4d6c055_2b65_4b1f_90ca_28a60ebf4eab
        */

        // value_ctor()
        /**
        * @class _2381ceb1_96d5_433e_a68e_898e08e5ef7f
        * @private
        * 
        * @snippet "./src/bool_t.cpp" _62211c6c_3f81_4429_ab68_5fb576cd2e2e
        * @snippet "./src/bool_t.cpp" _df5e960b_9224_4646_b4fb_593e26554f6f
        */

        // copy_ctor()
        /**
        * @class _c692880f_ea8a_47c2_b8c8_98a00607b79b
        * @private
        * 
        * @snippet "./src/bool_t.cpp" _5481d9e8_2096_40da_a7a0_22d0b80308fb
        * @snippet "./src/bool_t.cpp" _9c61dce0_72c4_4990_bdc7_531edda971d3
        */

        // move_ctor()
        /**
        * @class _f2621569_562c_44b6_a4be_cddfaf0b1147
        * @private
        * 
        * @snippet "./src/bool_t.cpp" _93151c91_7466_446f_9886_a448bfa178dc
        * @snippet "./src/bool_t.cpp" _23f44a66_a616_4359_8cc3_7c98f7f2227c
        */

        // volatile_copy_ctor()
        /**
        * @class _c2c40c6d_4153_4079_8231_a8f818fc4999
        * @private
        * 
        * @snippet "./src/bool_t.cpp" _cb2b3c43_0b96_4dfe_b9b3_81951cfaa93e
        * @snippet "./src/bool_t.cpp" _24bbff36_522f_42fd_8f12_454437c24c51
        */

        // volatile_move_ctor()
        /**
        * @class _e5e66483_541d_4798_b386_2874446fb0de
        * @private
        * 
        * @snippet "./src/bool_t.cpp" _1b1d0b0f_2c1e_46d8_924b_cbaaf8a604d6
        * @snippet "./src/bool_t.cpp" _95b07b9c_0cd5_4b6a_9575_3ae7a8d5853e
        */

        // copy_assignment_ctor()
        /**
        * @class _9b3a1871_d4ff_4afb_886d_e0d16ebaad08
        * @private
        * 
        * @snippet "./src/bool_t.cpp" _3f590aea_1f04_4fea_bd78_8c165201a062
        */

        // move_assignment_ctor()
        /**
        * @class _cf5bcded_4eb2_4cdb_92cd_aa5b66b3138b
        * @private
        * 
        * @snippet "./src/bool_t.cpp" _89dafc76_93be_49dc_b612_2cd3989b0c3c
        */

        // volatile_copy_assignment_ctor()
        /**
        * @class _462d0286_9a2d_4ea9_8b92_3f75d50199ae
        * @private
        * 
        * @snippet "./src/bool_t.cpp" _915f296c_5a2a_44ab_bd99_04367377d7bd
        */

        // volatile_move_assignment_ctor()
        /**
        * @class _b047b3ab_68ee_46f3_b210_6f27f6f34ef1
        * @private
        * 
        * @snippet "./src/bool_t.cpp" _e57cfa69_54fa_4e91_8509_2cd75aedcb1a
        */

        // dtor()
        /**
        * @class _4c312eec_919f_4b48_98e5_a3539442c7d2
        * @private
        * 
        * @snippet "./src/bool_t.cpp" _6fd7e147_ba41_4d98_adfe_e140a227e79a
        */

    // casts
    /**
    * @class _6a6f9172_06fd_4b0f_b1ee_1817e0c013a9
    * @private
    */

        // c_bool_t() const
        /**
        * @class _27d5dbc6_c0b3_47f7_94c9_fda617dd82c8
        * @private
        * 
        * @snippet "./src/bool_t.cpp" _c90cbd67_36ee_49a8_809d_380c54085e40
        */

        // c_bool_t() const volatile
        /**
        * @class _676141d7_bb06_45a8_8b65_0f5ae7bee673
        * @private
        * 
        * @snippet "./src/bool_t.cpp" _21637196_10ce_4fc2_add4_3d95f5351f34
        */

        // word_t&()
        /**
        * @class _4d0e7d29_353a_459f_89af_e11de2f19eea
        * @private
        * 
        * @copydoc _80a093e0_e0e5_4e31_ae14_915759c06011
        * 
        * @snippet "./src/bool_t.cpp" _dfb57b0b_8471_44f7_9333_166571f405ae
        */

        // const word_t&()
        /**
        * @class _9f6d257a_fc13_4dda_ad1b_7b268caf6dff
        * @private
        * 
        * @snippet "./src/bool_t.cpp" _0fa2a600_9160_4608_89aa_1ff52d9865ae
        */

        // volatile word_t&()
        /**
        * @class _64e5638b_29ea_4e16_bde9_bfddde8c22b2
        * @private
        * 
        * @copydoc _80a093e0_e0e5_4e31_ae14_915759c06011
        * 
        * @snippet "./src/bool_t.cpp" _7acf2bea_986a_4fea_ac75_b69447b0b864
        */

        // const volatile word_t&()
        /**
        * @class _3e6e7fd1_df11_44b3_a3d6_4f5073359d92
        * @private
        * 
        * @snippet "./src/bool_t.cpp" _ff97659e_50ba_4233_820b_c1f30f56a4b4
        */

    // none_t interface
    /**
    * @class _a3769981_7e0b_4a14_9376_c341849febfb
    * @private
    */

        // none_ctor()
        /**
        * @class _a74f5e68_66db_41d5_8778_6d49efcefb3f
        * @private
        * 
        * @snippet "./src/bool_t.cpp" _d2eb2094_38e0_4df3_b3f4_d21934bdcea1
        * @snippet "./src/bool_t.cpp" _593e9222_eae5_40ed_a624_f8b6901271dc
        */

        // =(none_t)
        /**
        * @class _9a7b8a4a_ce15_44e4_8900_5a09049c8b8a
        * @private
        * 
        * @snippet "./src/bool_t.cpp" _054daa01_e0d0_4313_bc9f_02f277d97bcd
        */

        // ==(none_t)
        /**
        * @class _c21ea269_d645_4b2c_b938_27fce7ad0617
        * @private
        * 
        * @snippet "./src/bool_t.cpp" _53ec2db4_77be_49a2_a3d4_395f5515d4a9
        */

        // !=(none_t)
        /**
        * @class _37796b19_cde7_4029_a5f3_4203fa2315c8
        * @private
        * 
        * @snippet "./src/bool_t.cpp" _9a721957_28c0_4dbc_a65e_a74d4f395002
        */
