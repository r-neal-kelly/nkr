/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsics.h"
#include "nkr/maybe_t.h"
#include "nkr/traits.h"

namespace nkr { namespace $atomic_t {

    /// @nosubgrouping
    /// @copydoc _ec77c539_2ae5_4aa5_a156_d961c5ac098d
    class bool_sp
    {
    public:
        /// @name aliases
        /// @copydoc _b9aeddda_98ca_4f83_8d24_fb72a3337515
        /// @{
        using value_t   = bool_t;   ///< @copydoc _d6588266_8070_4fb4_ba5b_12c444041857
        /// @}

    public:
        /// @name static data
        /// @copydoc _67fb1b7b_bf43_4612_aaed_fc5d2d13eead
        /// @{
        static constexpr value_t    DEFAULT_VALUE   = false;    ///< @copydoc _0ef02aea_a4be_4670_9219_06aa40b7690a
        /// @}

    public:
        /// @name object data
        /// @copydoc _566de746_f599_4b33_b092_b69b6d7bcf4d
        /// @{
        volatile value_t    value;  ///< @copydoc _22e6ea05_aa91_45e7_8095_c06decdf01d6
        /// @}

    public:
        /// @name objects
        /// @copydoc _1053c39e_78e4_4501_bdd5_fa790bfe8bd5
        /// @{
        bool_sp();                                      ///< @copydoc _95db9ad8_4d39_4de5_bc38_28d054451654
        bool_sp(value_t value);                         ///< @copydoc _79178fc7_46e8_412f_b875_222389e8c699
        bool_sp(const bool_sp& other);                  ///< @copydoc _f13e81f0_5ced_4185_8bfb_6a17811bf402
        bool_sp(bool_sp&& other) noexcept;              ///< @copydoc _2051d33c_31c9_402b_b7b0_30ed311bae55
        bool_sp& operator =(const bool_sp& other);      ///< @copydoc _754a3b96_c816_4875_b1c5_bd94f74975fe
        bool_sp& operator =(bool_sp&& other) noexcept;  ///< @copydoc _27b572bf_b851_4bbb_bf27_5be01e5164d0
        ~bool_sp();                                     ///< @copydoc _70f5c9d9_6b00_4e4b_ab7a_8f43cf310780
        /// @}

    public:
        /// @name methods
        /// @copydoc _f8359bc4_053e_45a2_92c0_8cc2aec98f3c
        /// @{
        value_t Access() const;                                     ///< @copydoc _4dac77d5_7b0a_47be_8b54_55194f16d92c

        value_t Assign(value_t value);                              ///< @copydoc _21eb4382_88d5_4c3d_8632_84e7a781884c

        value_t Exchange(value_t value);                            ///< @copydoc _36a45c7f_a017_48c8_9b38_80f41441dfd6
        value_t Exchange_If_Equals(value_t value, value_t target);  ///< @copydoc _f4834de8_17dd_46c2_851e_90cf412a7513
        /// @}

    public:
        /// @name casts
        /// @copydoc _b471158e_1d68_4c75_a520_763cfb48f86b
        /// @{
        operator    value_t() const;    ///< @copydoc _18ea22ec_be2e_42c9_a63d_b4af5e137aa5
        /// @}

    public:
        /// @name operators
        /// @copydoc _0e407320_061a_4d4b_ae76_397896faa849
        /// @{
        value_t operator ()() const;        ///< @copydoc _9c15e3f8_92db_4474_ab7a_fb1486fc3800

        value_t operator =(value_t value);  ///< @copydoc _0e3f005e_ea7e_4114_8c29_5c23bbc840c2
        /// @}
    };

    /// @nosubgrouping
    /// @copydoc _1eb34513_6d58_4671_bcfc_61834a0fa529
    template <integer_tr integer_p = word_t>
    class integer_sp
    {
    public:
        /// @name aliases
        /// @copydoc _3e2133e0_58a8_4588_befa_ae433363cf01
        /// @{
        using value_t   = integer_p;    ///< @copydoc _5f6fc64f_c566_4b81_9c95_bca7d9672f17
        /// @}

    public:
        /// @name static data
        /// @copydoc _a85423a0_a295_431f_9020_6c99e5c5620c
        /// @{
        static constexpr value_t    DEFAULT_VALUE   = 0;    ///< @copydoc _5a3235cf_0d15_437b_a951_a18ac52dc5f9
        /// @}

    public:
        /// @name object data
        /// @copydoc _67c3c408_1756_4f1e_a966_cc5ad1f3dfd2
        /// @{
        volatile value_t    value;  ///< @copydoc _93d24339_6dae_40f2_9f11_c9305ebb3816
        /// @}

    public:
        /// @name objects
        /// @copydoc _162f5a89_c587_40d2_ac4c_9b43659dfa9a
        /// @{
        integer_sp();                                           ///< @copydoc _6214730b_aeb9_4083_998c_f9e1c020924e
        integer_sp(value_t value);                              ///< @copydoc _934d0d25_c160_42c4_a269_363ce0e78da6
        integer_sp(const integer_sp& other);                    ///< @copydoc _ca4f92b3_f5c8_470d_a3da_c7f8a334d441
        integer_sp(integer_sp&& other) noexcept;                ///< @copydoc _0d15101b_2293_4225_8f70_3edb3f8618de
        integer_sp& operator =(const integer_sp& other);        ///< @copydoc _eeeb1194_9900_46ab_8e15_1e8a0a663395
        integer_sp& operator =(integer_sp&& other) noexcept;    ///< @copydoc _ccf84af8_3181_43e0_a892_9850e2a4c6f0
        ~integer_sp();                                          ///< @copydoc _01602bc3_a017_47e4_b34e_b8a1dd6dae2f
        /// @}

    public:
        /// @name methods
        /// @copydoc _ebe2958b_6231_481e_819f_84d882989f41
        /// @{
        value_t Access() const;                                                     ///< @copydoc _72e0df20_176a_4ad8_9350_7edcadf7d893
        value_t Access_Add(integer_tr auto value) const;                            ///< @copydoc _daba458f_9452_4329_8340_b48050ca53c9
        value_t Access_Subtract(integer_tr auto value) const;                       ///< @copydoc _18fd7b62_b0dd_4997_91cf_fbd22ffb25ce
        value_t Access_Or(integer_tr auto value) const;                             ///< @copydoc _fe58aaa7_2827_412c_9e8e_446d14af1863
        value_t Access_And(integer_tr auto value) const;                            ///< @copydoc _f5960380_cec0_4d63_a5d9_f1a0c0b03990
        value_t Access_Xor(integer_tr auto value) const;                            ///< @copydoc _b46a1eee_f92b_4c4a_a6b8_cdae969b81ca

        value_t Assign(integer_tr auto value);                                      ///< @copydoc _921ddfce_4850_4bda_bd9a_04fc363a4891
        value_t Assign_Add(integer_tr auto value);                                  ///< @copydoc _d09f0f0c_4e8e_4a47_8d93_3e7e9c0dabdd
        value_t Assign_Subtract(integer_tr auto value);                             ///< @copydoc _775e6700_6127_4c6d_a6ae_f9e0032aba91
        value_t Assign_Or(integer_tr auto value);                                   ///< @copydoc _c59d3a53_f67f_4efb_830a_96b14e32ba0f
        value_t Assign_And(integer_tr auto value);                                  ///< @copydoc _d39105cd_1da2_442a_b146_edf5de564212
        value_t Assign_Xor(integer_tr auto value);                                  ///< @copydoc _10c909ec_eb4f_40fd_a3e6_cd32023cb32b

        value_t Exchange(integer_tr auto value);                                    ///< @copydoc _bf53feba_9fd9_4938_9e0a_6f020b7de344
        value_t Exchange_If_Equals(integer_tr auto value, integer_tr auto target);  ///< @copydoc _de4d8d98_3a2b_4557_be66_5015696218c3
        value_t Exchange_Add(integer_tr auto value);                                ///< @copydoc _eb209d2b_53f3_4aaf_87c4_7e6f7415d7de
        value_t Exchange_Subtract(integer_tr auto value);                           ///< @copydoc _9c87833c_f98e_420e_9451_7f047098b464
        value_t Exchange_Or(integer_tr auto value);                                 ///< @copydoc _5a508f6d_abaf_409e_83dc_f7133a81fb6f
        value_t Exchange_And(integer_tr auto value);                                ///< @copydoc _fe438ba0_c269_4703_b2f6_66a30e136f8a
        value_t Exchange_Xor(integer_tr auto value);                                ///< @copydoc _b9453618_fb4e_425d_a1b1_f88a5d272622
        /// @}

    public:
        /// @name casts
        /// @copydoc _473fc73c_71f3_4897_b548_32326ec7f8ca
        /// @{
        operator    value_t() const;    ///< @copydoc _9ee8a537_8292_436e_b054_c74f3a74a281
        /// @}

    public:
        /// @name operators
        /// @copydoc _ebf639ee_013e_4e27_adc1_1752df597ddf
        /// @{
        value_t operator ()() const;                        ///< @copydoc _a36f993e_fcec_4321_a995_31aca1a50f6a

        value_t operator =(integer_tr auto value);          ///< @copydoc _0bc23dd6_f475_4a9d_a3ee_dad400a9bb94

        value_t operator +(integer_tr auto value) const;    ///< @copydoc _447eac95_eaf7_4ef2_9065_04b1f87b7a0c
        value_t operator -(integer_tr auto value) const;    ///< @copydoc _38798051_deb1_4f18_98b9_6886fd14b32f
        value_t operator +=(integer_tr auto value);         ///< @copydoc _85417b7a_dd77_4294_b67e_6e08ab7e27f9
        value_t operator -=(integer_tr auto value);         ///< @copydoc _29505a0a_1b57_45eb_b075_8b2f3d3be8f3
        value_t operator ++();                              ///< @copydoc _3706a8b1_15f5_4a60_94dd_b88bd37d602b
        value_t operator ++(int);                           ///< @copydoc _23f284ee_6dd9_4b76_b361_1c0b287c4b8f
        value_t operator --();                              ///< @copydoc _3a8149a1_3608_4c64_9ccc_98fbf01aa964
        value_t operator --(int);                           ///< @copydoc _0c3d89f4_6273_4a93_958f_631c8c7f1083

        value_t operator ~() const;                         ///< @copydoc _b6b05dcd_53e8_4131_b3a7_dcd8211fb8a9
        value_t operator |(integer_tr auto value) const;    ///< @copydoc _36f1a3f7_ee14_48c8_ac91_02b66e1ad3a2
        value_t operator &(integer_tr auto value) const;    ///< @copydoc _55c8e8c5_5c97_426f_80bb_deb683554b7d
        value_t operator ^(integer_tr auto value) const;    ///< @copydoc _f8a7aef9_6b08_4b14_aa8d_0d10b5d8de5f
        value_t operator |=(integer_tr auto value);         ///< @copydoc _707c26ad_75fc_43cc_be98_233cb47d3eec
        value_t operator &=(integer_tr auto value);         ///< @copydoc _5a8f0664_0510_4f5d_991a_cc2a5eaea4b5
        value_t operator ^=(integer_tr auto value);         ///< @copydoc _77262a09_d572_440c_849c_d124b0d7dc6d
        /// @}

    public:
        /// @name none_t interface
        /// @copydoc _feb54dad_7493_4e9d_9e24_2a69c9912f95
        /// @{
        integer_sp& operator =(none_t);         ///< @copydoc _18865e46_d599_4053_a6dc_e0609fb811a1
        bool_t      operator ==(none_t) const;  ///< @copydoc _e3609d5e_27c6_4a0e_8928_c54f879abb96
        bool_t      operator !=(none_t) const;  ///< @copydoc _cc53fec7_7977_4de9_9aa9_852cedd9134a
        /// @}
    };

    /// @nosubgrouping
    /// @copydoc _3a98b216_8b25_4340_96d3_01a5f49f336b
    template <pointer_tr pointer_p>
    class pointer_sp
    {
    public:
        /// @name aliases
        /// @copydoc _57e44386_ab72_48cd_9f58_b96db313eb43
        /// @{
        using value_t   = pointer_p;                        ///< @copydoc _49ad8151_d840_47b0_9c65_30ef2fed49ec
        using units_t   = pointer_p;                        ///< @copydoc _2f52ee02_6b80_4a43_ae33_b4c25732c0ac
        using unit_t    = std::remove_pointer_t<pointer_p>; ///< @copydoc _f910fbfb_b77d_4d4d_867e_96e9cd364d49
        /// @}

    public:
        /// @name static data
        /// @copydoc _fd3e4b48_2e69_4d53_ace3_6e394411f439
        /// @{
        static constexpr value_t    DEFAULT_VALUE   = nullptr;  ///< @copydoc _d253babc_66d2_4245_bdef_4d4d9757bba8
        /// @}

    public:
        /// @name object data
        /// @copydoc _13318dd2_920a_4f61_a67c_4529599ed223
        /// @{
        volatile value_t    value;  ///< @copydoc _232c56f4_18f7_4148_937e_9e0013037db7
        /// @}

    public:
        /// @name objects
        /// @copydoc _02cb02e0_23f1_48c1_94fb_56163a661f5f
        /// @{
        pointer_sp();                                           ///< @copydoc _b54cf1c4_55a9_4de6_8d00_dcb2d3ca9d25
        pointer_sp(value_t value);                              ///< @copydoc _6fe3639a_9af9_482a_ac65_71dd762b87c4
        pointer_sp(const pointer_sp& other);                    ///< @copydoc _7daf8ec0_a6a6_422c_a4be_367b0a320abd
        pointer_sp(pointer_sp&& other) noexcept;                ///< @copydoc _9004776c_b34b_4004_a28b_aa3405d0705a
        pointer_sp& operator =(const pointer_sp& other);        ///< @copydoc _4010b13b_d165_40e2_9ee1_4c1cd9d9347e
        pointer_sp& operator =(pointer_sp&& other) noexcept;    ///< @copydoc _aa527a17_a527_4c42_a747_e666b3ad3def
        ~pointer_sp();                                          ///< @copydoc _2f13ca94_e440_4c22_8716_ad04477faeec
        /// @}

    public:
        /// @name methods
        /// @copydoc _4d354065_6729_45ca_a929_ecf57cbaa63f
        /// @{
        value_t Access() const;                                                     ///< @copydoc _c0c47fc9_d389_4d39_9c8b_ca60d166842d
        value_t Access_Add(integer_tr auto value) const;                            ///< @copydoc _b5c98ea6_065d_47eb_89eb_0c575f3f81fb
        value_t Access_Subtract(integer_tr auto value) const;                       ///< @copydoc _f04f55a5_0706_435b_8eee_10f7ede33793

        value_t Assign(pointer_tr auto value);                                      ///< @copydoc _af9d53bf_c4e8_4bfb_b2a4_eb2caa1b4ce1
        value_t Assign_Add(integer_tr auto value);                                  ///< @copydoc _c8f00ac4_b591_419a_a3ca_9c1450aa4427
        value_t Assign_Subtract(integer_tr auto value);                             ///< @copydoc _90060189_8434_4919_9297_9b22a439076f

        value_t Exchange(pointer_tr auto value);                                    ///< @copydoc _d1dd2b4b_adf7_4f7e_9c62_f29519eda90f
        value_t Exchange_If_Equals(pointer_tr auto value, pointer_tr auto target);  ///< @copydoc _10426898_c8ab_44de_b7a7_748f31e5ad00
        value_t Exchange_Add(integer_tr auto value);                                ///< @copydoc _212049f1_8d3b_4529_99d0_f800a9711e4b
        value_t Exchange_Subtract(integer_tr auto value);                           ///< @copydoc _2fcafb28_9779_4964_98af_e50b75de4903
        /// @}

    public:
        /// @name casts
        /// @copydoc _d6d6ad6c_4e44_4a66_af85_ecee32f79a63
        /// @{
        operator    value_t() const;    ///< @copydoc _692a5946_de1e_4633_a533_00fa4c7503bd
        /// @}

    public:
        /// @name operators
        /// @copydoc _5c4884cd_dbd5_4688_ac52_a6de0f6a8348
        /// @{
        value_t operator ()() const;                        ///< @copydoc _3ea0703e_60a3_487d_ab7a_40079a05c05d

        value_t operator =(pointer_tr auto value);          ///< @copydoc _6beb0750_750d_455a_94a1_a8972f7d5cad

        value_t operator +(integer_tr auto value) const;    ///< @copydoc _c2fdbd23_4f48_440c_a626_ecb57891827b
        value_t operator -(integer_tr auto value) const;    ///< @copydoc _a5528a8c_e36d_4403_bb87_694562f3ddec
        value_t operator +=(integer_tr auto value);         ///< @copydoc _4bc62f6a_629b_4332_beb0_82873b0c0802
        value_t operator -=(integer_tr auto value);         ///< @copydoc _442d3e31_4638_469e_9d70_99ff94c0ddcf
        value_t operator ++();                              ///< @copydoc _05ce7c2c_3ac7_42dc_ba1b_3b6c5bfa358e
        value_t operator ++(int);                           ///< @copydoc _eae55e62_8447_4782_9be7_b642ff541fa8
        value_t operator --();                              ///< @copydoc _7a64b474_788e_4686_9093_30e9482db8f6
        value_t operator --(int);                           ///< @copydoc _da7ec2ad_ad87_427e_8876_a9029c35af15

        value_t operator ->() const;                        ///< @copydoc _3dd98d85_e299_439b_902f_87e5ecc1a2be
        unit_t& operator *() const;                         ///< @copydoc _626fbdfe_f1db_44c7_85ed_3db92e4fb3d1
        unit_t& operator [](integer_tr auto index) const;   ///< @copydoc _141bf596_33d0_4a21_95b9_caa5166f0c04
        /// @}
    };

    /// @nosubgrouping
    /// @copydoc _82a1e5b2_d82c_4a8e_b740_b84adc2a71ab
    class void_pointer_sp
    {
    public:
        /// @name aliases
        /// @copydoc _3ce9f30f_4c23_477d_bad4_3d783300f8e2
        /// @{
        using value_t   = void_t*;  ///< @copydoc _c6fdd2d1_2286_487b_8787_429c166ddc49
        using units_t   = void_t*;  ///< @copydoc _f1e35d96_32c1_4177_92a2_c99aa04b7713
        using unit_t    = void_t;   ///< @copydoc _502af4e2_e9d4_4590_b3d6_c06581562cc4
        /// @}

    public:
        /// @name static data
        /// @copydoc _30e0294f_b04e_4352_a087_c44e87f7fe56
        /// @{
        static constexpr value_t    DEFAULT_VALUE   = nullptr;  ///< @copydoc _7b0cb549_667e_406d_a8b7_ce953ed76b7f
        /// @}

    public:
        /// @name object data
        /// @copydoc _c4c691b3_1e6d_4ab5_9d74_c9451050d44b
        /// @{
        volatile value_t    value;  ///< @copydoc _ef881fc0_08a4_47d9_b568_16b8bc3350f6
        /// @}

    public:
        /// @name objects
        /// @copydoc _efde0406_9ccb_4bb9_a8d3_233743e9bea5
        /// @{
        void_pointer_sp();                                              ///< @copydoc _4aaf8533_9fae_4e73_a496_b809f4182419
        void_pointer_sp(value_t value);                                 ///< @copydoc _6835eb33_5782_4b57_b536_6176a01989f8
        void_pointer_sp(const void_pointer_sp& other);                  ///< @copydoc _c8551a6c_8e62_416a_9f73_a5b1b99f984f
        void_pointer_sp(void_pointer_sp&& other) noexcept;              ///< @copydoc _ebfcfe7d_9340_4d7a_b128_df74de441f1f
        void_pointer_sp& operator =(const void_pointer_sp& other);      ///< @copydoc _86b76904_0174_4cdc_a369_2673d1740ec5
        void_pointer_sp& operator =(void_pointer_sp&& other) noexcept;  ///< @copydoc _0eea443f_df0b_442e_a8fa_3173c412e675
        ~void_pointer_sp();                                             ///< @copydoc _e286417e_9f29_48fc_b76e_b118d557d1e1
        /// @}

    public:
        /// @name methods
        /// @copydoc _98ee4349_04dd_4841_9bfd_a2183df63d35
        /// @{
        value_t Access() const;                                                     ///< @copydoc _a7b1972a_9ff7_4932_9a82_d4cb553f06c4

        value_t Assign(pointer_tr auto value);                                      ///< @copydoc _1f246d11_214e_48b0_ab8d_2f7f96eecba1

        value_t Exchange(pointer_tr auto value);                                    ///< @copydoc _80c24152_78ec_41a9_935d_e4a3ba82dbb5
        value_t Exchange_If_Equals(pointer_tr auto value, pointer_tr auto target);  ///< @copydoc _559c10d8_e6bc_417d_81f6_276e9944ba9a
        /// @}

    public:
        /// @name casts
        /// @copydoc _65d14b1d_763a_45d8_875b_9462769913c4
        /// @{
        operator    value_t() const;    ///< @copydoc _a1e15ae8_6b2d_4789_b02a_1139342e55d3
        /// @}

    public:
        /// @name operators
        /// @copydoc _f8bd3a76_a5a5_4a9f_80d0_c96830453035
        /// @{
        value_t operator ()() const;                ///< @copydoc _dd514422_ac54_4000_a920_0e7cd0c28a96

        value_t operator =(pointer_tr auto value);  ///< @copydoc _c84a863c_e1fe_4c06_a827_716a2749bfa3
        /// @}
    };

}}

namespace nkr {

    /// @nosubgrouping
    /// @copydoc _d6e046d8_6c2e_4075_905b_563f1c8f2455
    template <typename invalid_p>
    class atomic_t
    {
    public:
        /// @name objects
        /// @copydoc 
        /// @{
        atomic_t()                                      = delete;   ///< @copydoc _8e2cc8ab_3e8d_4c9a_8cbc_cf0f5ed55d1a
        atomic_t(const atomic_t& other)                 = delete;   ///< @copydoc _9727488c_e0cc_4056_a68f_d12b84d5ceca
        atomic_t(atomic_t&& other) noexcept             = delete;   ///< @copydoc _20433dd1_bd70_44ec_b6a3_7b5311f12825
        atomic_t& operator =(const atomic_t& other)     = delete;   ///< @copydoc _28d6f470_34eb_4d0d_8dc5_239e23c1c253
        atomic_t& operator =(atomic_t&& other) noexcept = delete;   ///< @copydoc _388db58d_c89b_420b_bad9_c3e0334cdd9f
        ~atomic_t()                                     = delete;   ///< @copydoc _e7cda9ac_182a_48c9_8ace_1a6f8887a65a
        /// @}
    };

    /// @nosubgrouping
    /// @copydoc _7179dda8_8fb2_43e5_9c7a_dbc08cedcbbb
    template <>
    class atomic_t<bool_t> :
        public $atomic_t::bool_sp
    {
    public:
        using $atomic_t::bool_sp::bool_sp;
        using $atomic_t::bool_sp::operator =;
    };

    /// @nosubgrouping
    /// @copydoc _d976569a_30d5_4a15_8729_b7505132263c
    template <integer_tr integer_p>
    class atomic_t<integer_p> :
        public $atomic_t::integer_sp<integer_p>
    {
    public:
        using $atomic_t::integer_sp<integer_p>::integer_sp;
        using $atomic_t::integer_sp<integer_p>::operator =;
    };

    /// @nosubgrouping
    /// @copydoc _f8ce2e6d_230a_4ef2_801f_aecbc3571487
    template <pointer_tr pointer_p>
    class atomic_t<pointer_p> :
        public $atomic_t::pointer_sp<pointer_p>
    {
    public:
        using $atomic_t::pointer_sp<pointer_p>::pointer_sp;
        using $atomic_t::pointer_sp<pointer_p>::operator =;
    };

    /// @nosubgrouping
    /// @copydoc _99ace0a0_9530_4fb1_8179_90b7dd50e9ed
    template <>
    class atomic_t<void_t*> :
        public $atomic_t::void_pointer_sp
    {
    public:
        using $atomic_t::void_pointer_sp::void_pointer_sp;
        using $atomic_t::void_pointer_sp::operator =;
    };

}

#include "nkr/atomic_t.inl"
