/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

// will get mixed with the old traits until we remove them
//#include "nkr/tr_dec.h"

namespace nkr { namespace boolean {

    /// @nosubgrouping
    /// @copydoc _56a7c1d1_2a01_4357_bfd8_68f2c4ba0a0b
    class deleted_operators_t
    {
    public:
        /// @name operators
        /// @copydoc _63992199_008e_4db4_a4fe_1b42753f9108
        /// @{
        auto    operator +() const volatile         = delete;   ///< @copydoc _1f100902_7552_43e6_8b6a_6b1e0874da84
        auto    operator -() const volatile         = delete;   ///< @copydoc _9ad48fba_f897_41ea_8039_347ee09b54e3

        auto    operator +(auto) const volatile     = delete;   ///< @copydoc _12fff5f7_a821_4366_b614_6403de624cb6
        auto    operator -(auto) const volatile     = delete;   ///< @copydoc _e82bd7a7_f549_4832_8529_0dbc6b8d812b
        auto    operator *(auto) const volatile     = delete;   ///< @copydoc _a58ca6c0_d1ac_4b78_bac7_4f81d6032960
        auto    operator /(auto) const volatile     = delete;   ///< @copydoc _3d24a3f6_1d75_403c_91ee_82a596041ddc
        auto    operator %(auto) const volatile     = delete;   ///< @copydoc _140cc050_58e7_46d7_808b_ae8f051ab06d

        auto    operator ~() const volatile         = delete;   ///< @copydoc _3adc796a_c73a_40e1_8f65_b26d327f103f
        auto    operator |(auto) const volatile     = delete;   ///< @copydoc _6ba0b8a2_e68a_4eeb_a391_2eb7edad5aa0
        auto    operator &(auto) const volatile     = delete;   ///< @copydoc _90f4bff8_0678_46a2_84b7_9b7081cebae4
        auto    operator ^(auto) const volatile     = delete;   ///< @copydoc _85dd34aa_8e29_40e9_a4ac_de6637d556c2
        auto    operator <<(auto) const volatile    = delete;   ///< @copydoc _894a3185_160f_4018_8114_561e44f9aaa7
        auto    operator >>(auto) const volatile    = delete;   ///< @copydoc _7e7d875d_e409_4654_b45f_501feb2ffc3f

        auto    operator +=(auto) const volatile    = delete;   ///< @copydoc _73d1ce59_ce48_4c32_bbbb_03a378c8ca48
        auto    operator -=(auto) const volatile    = delete;   ///< @copydoc _8d3e20f7_f92a_4591_a545_4de2ffdb43a4
        auto    operator *=(auto) const volatile    = delete;   ///< @copydoc _d8920ba2_44e0_4516_aca0_99439cca0de0
        auto    operator /=(auto) const volatile    = delete;   ///< @copydoc _f5499a07_cc9e_43c2_9a20_deab15ec0aff
        auto    operator %=(auto) const volatile    = delete;   ///< @copydoc _c03ae8be_f59f_496e_8b17_f1edb7a67ae9

        auto    operator |=(auto) const volatile    = delete;   ///< @copydoc _90422d47_6b7c_49fc_9393_1089e91f341a
        auto    operator &=(auto) const volatile    = delete;   ///< @copydoc _479241c9_0a76_4cb9_a26f_3f35b56f90aa
        auto    operator ^=(auto) const volatile    = delete;   ///< @copydoc _c164e46c_c85c_4ab2_be03_3ddc622e3646
        auto    operator <<=(auto) const volatile   = delete;   ///< @copydoc _518b4d5f_320b_46b8_8971_4a4ea3dde917
        auto    operator >>=(auto) const volatile   = delete;   ///< @copydoc _115ae575_9520_4203_b9d0_e319faf4a676

        auto    operator ++() const volatile        = delete;   ///< @copydoc _36330991_852b_4ed5_9dcb_c51ab1d90bfb
        auto    operator ++(int) const volatile     = delete;   ///< @copydoc _b883f925_4116_4058_a59a_b74f1c6bea0c
        auto    operator --() const volatile        = delete;   ///< @copydoc _ae2ac00f_983e_4d1f_8aa7_a932a2463539
        auto    operator --(int) const volatile     = delete;   ///< @copydoc _aae68f23_68be_4723_b129_27e1b064b688

        auto    operator <(auto) const volatile     = delete;   ///< @copydoc _c7f6c32d_df0d_488b_ae25_2cec51909868
        auto    operator >(auto) const volatile     = delete;   ///< @copydoc _e9f6726d_8a63_4bc6_b512_4853ec37dc10
        auto    operator <=(auto) const volatile    = delete;   ///< @copydoc _8b0e6e22_70f4_408a_9775_352018b7c1d1
        auto    operator >=(auto) const volatile    = delete;   ///< @copydoc _f570ba0f_2172_4ea8_b0ea_c6ec4d6ed994
        auto    operator <=>(auto) const volatile   = delete;   ///< @copydoc _28e396ed_43f8_42b1_80ce_7042c690e66f
        /// @}
    };

}}
