/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsics.h"
#include "nkr/none_t.h"
#include "nkr/traits.h"

namespace nkr {

    /// @nosubgrouping
    /// @copydoc _56a7c1d1_2a01_4357_bfd8_68f2c4ba0a0b
    class bool_deleted_operators_t
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

    template <typename type_p>
    concept has_bool_deleted_operator_tr =
        requires(type_p instance) { +instance; } ||
        requires(type_p instance) { -instance; } ||

        requires(type_p instance) { instance + 1; } ||
        requires(type_p instance) { instance - 1; } ||
        requires(type_p instance) { instance * 1; } ||
        requires(type_p instance) { instance / 1; } ||
        requires(type_p instance) { instance % 1; } ||

        requires(type_p instance) { ~instance; } ||
        requires(type_p instance) { instance | 1; } ||
        requires(type_p instance) { instance & 1; } ||
        requires(type_p instance) { instance ^ 1; } ||
        requires(type_p instance) { instance << 1; } ||
        requires(type_p instance) { instance >> 1; } ||

        requires(type_p instance) { instance += 1; } ||
        requires(type_p instance) { instance -= 1; } ||
        requires(type_p instance) { instance *= 1; } ||
        requires(type_p instance) { instance /= 1; } ||
        requires(type_p instance) { instance %= 1; } ||

        requires(type_p instance) { instance |= 1; } ||
        requires(type_p instance) { instance &= 1; } ||
        requires(type_p instance) { instance ^= 1; } ||
        requires(type_p instance) { instance <<= 1; } ||
        requires(type_p instance) { instance >>= 1; } ||

        requires(type_p instance) { ++instance; } ||
        requires(type_p instance) { instance++; } ||
        requires(type_p instance) { --instance; } ||
        requires(type_p instance) { instance--; } ||

        requires(type_p instance) { instance < 1; } ||
        requires(type_p instance) { instance > 1; } ||
        requires(type_p instance) { instance <= 1; } ||
        requires(type_p instance) { instance >= 1; } ||
        requires(type_p instance) { instance <=> 1; };

    /// @nosubgrouping
    /// @copydoc _2add9928_e370_4943_ba5b_2950d9e1da99
    class bool_t :
        public bool_deleted_operators_t
    {
    protected:
        /// @name object data
        /// @copydoc _3dbc082f_9df8_4eda_b07f_fca297cc63a9
        /// @{
        word_t  value;  ///< @copydoc _9eefd4d6_1786_42ec_970a_c16c9bde2d42
        /// @}

    public:
        /// @name objects
        /// @copydoc _727e30a1_ed17_4451_aefd_e9ff35d4be9c
        /// @{
        bool_t();                                                                                   ///< @copydoc _507e6865_70dc_4e5b_97ab_c0d33e53dc67

        bool_t(to_c_bool_tr auto value);                                                            ///< @copydoc _2381ceb1_96d5_433e_a68e_898e08e5ef7f
        
        bool_t(const bool_t& other);                                                                ///< @copydoc _c692880f_ea8a_47c2_b8c8_98a00607b79b
        bool_t(const volatile bool_t& other);                                                       ///< @copydoc _c2c40c6d_4153_4079_8231_a8f818fc4999
        bool_t(bool_t&& other) noexcept;                                                            ///< @copydoc _f2621569_562c_44b6_a4be_cddfaf0b1147
        bool_t(volatile bool_t&& other) noexcept;                                                   ///< @copydoc _e5e66483_541d_4798_b386_2874446fb0de

        bool_t&             operator =(const bool_t& other);                                        ///< @copydoc _9b3a1871_d4ff_4afb_886d_e0d16ebaad08
        volatile bool_t&    operator =(const bool_t& other) volatile;                               ///< @copydoc 
        bool_t&             operator =(const volatile bool_t& other);                               ///< @copydoc 
        volatile bool_t&    operator =(const volatile bool_t& other) volatile;                      ///< @copydoc _462d0286_9a2d_4ea9_8b92_3f75d50199ae
        bool_t&             operator =(bool_t&& other) noexcept;                                    ///< @copydoc _cf5bcded_4eb2_4cdb_92cd_aa5b66b3138b
        volatile bool_t&    operator =(bool_t&& other) volatile noexcept;                           ///< @copydoc 
        bool_t&             operator =(is_just_volatile_tr<bool_t> auto&& other) noexcept;          ///< @copydoc 
        volatile bool_t&    operator =(is_just_volatile_tr<bool_t> auto&& other) volatile noexcept; ///< @copydoc _b047b3ab_68ee_46f3_b210_6f27f6f34ef1

        ~bool_t();                                                                                  ///< @copydoc _4c312eec_919f_4b48_98e5_a3539442c7d2
        /// @}

    public:
        /// @name casts
        /// @copydoc _6a6f9172_06fd_4b0f_b1ee_1817e0c013a9
        /// @{
        operator            c_bool_t() const;                           ///< @copydoc _27d5dbc6_c0b3_47f7_94c9_fda617dd82c8
        operator            c_bool_t() const volatile;                  ///< @copydoc _676141d7_bb06_45a8_8b65_0f5ae7bee673

        explicit operator   word_t&();                                  ///< @copydoc _4d0e7d29_353a_459f_89af_e11de2f19eea
        explicit operator   const word_t&() const;                      ///< @copydoc _9f6d257a_fc13_4dda_ad1b_7b268caf6dff
        explicit operator   volatile word_t&() volatile;                ///< @copydoc _64e5638b_29ea_4e16_bde9_bfddde8c22b2
        explicit operator   const volatile word_t&() const volatile;    ///< @copydoc _3e6e7fd1_df11_44b3_a3d6_4f5073359d92
        /// @}

    public:
        /// @name none_t interface
        /// @copydoc _a3769981_7e0b_4a14_9376_c341849febfb
        /// @{
        bool_t(none_t);                                         ///< @copydoc _a74f5e68_66db_41d5_8778_6d49efcefb3f

        bool_t&             operator =(none_t);                 ///< @copydoc _9a7b8a4a_ce15_44e4_8900_5a09049c8b8a
        volatile bool_t&    operator =(none_t) volatile;        ///< @copydoc 

        bool_t              operator ==(none_t) const;          ///< @copydoc _c21ea269_d645_4b2c_b938_27fce7ad0617
        bool_t              operator ==(none_t) const volatile; ///< @copydoc 
        bool_t              operator !=(none_t) const;          ///< @copydoc _37796b19_cde7_4029_a5f3_4203fa2315c8
        bool_t              operator !=(none_t) const volatile; ///< @copydoc 
        /// @}
    };
    static_assert(sizeof(bool_t) == sizeof(word_t));

}
