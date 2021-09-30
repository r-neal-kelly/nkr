/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/bool_t.h"
#include "nkr/intrinsics.h"
#include "nkr/macros.h"
#include "nkr/none_i.h"
#include "nkr/traits.h"
#include "nkr/utils.h"

namespace nkr {

    /// @ingroup _d1cd4369_e0f4_4062_8f58_611395da215e
    /// @copydoc _80ba6268_583c_45c1_8d5c_d5d84565dae8
    namespace $atomic_t {};

}

namespace nkr {

    template <typename value_p>
    class atomic_t;

    template <typename atomic_p>
    concept any_atomic_tr =
        is_any_tr<atomic_p, atomic_t<typename atomic_p::value_t>>;

    nkr_DEFINE_CONTAINER_TRAITS(atomic, value_t);

    template <typename atomic_p>
    concept any_non_const_atomic_of_any_non_const_unsigned_integer_tr =
        any_non_const_atomic_tr<atomic_p> &&
        any_non_const_tr<typename atomic_p::value_t> &&
        integer_unsigned_tr<typename atomic_p::value_t>;

    template <typename atomic_p>
    concept any_non_const_atomic_of_any_non_const_signed_integer_tr =
        any_non_const_atomic_tr<atomic_p> &&
        any_non_const_tr<typename atomic_p::value_t> &&
        integer_signed_tr<typename atomic_p::value_t>;

    nkr_DEFINE_NOT_TRAIT_WITH_1_PARAM(any_non_const_atomic_of_any_non_const_unsigned_integer_tr, atomic_p);
    nkr_DEFINE_NOT_TRAIT_WITH_1_PARAM(any_non_const_atomic_of_any_non_const_signed_integer_tr, atomic_p);

}

namespace nkr { namespace $atomic_t {

    /// @nosubgrouping
    /// @copydoc _ec77c539_2ae5_4aa5_a156_d961c5ac098d
    template <boolean_tr boolean_p>
    class boolean_sp :
        public bool_deleted_operators_t
    {
    public:
        /// @name aliases
        /// @copydoc _b9aeddda_98ca_4f83_8d24_fb72a3337515
        /// @{
        using value_t   = boolean_p;    ///< @copydoc _d6588266_8070_4fb4_ba5b_12c444041857
        /// @}

    public:
        /// @name static data
        /// @copydoc _67fb1b7b_bf43_4612_aaed_fc5d2d13eead
        /// @{
        static const value_t    DEFAULT_VALUE;  ///< @copydoc _0ef02aea_a4be_4670_9219_06aa40b7690a
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
        boolean_sp();                                                                                       ///< @copydoc _95db9ad8_4d39_4de5_bc38_28d054451654
        
        boolean_sp(convertible_tr<value_t> auto value);                                                     ///< @copydoc _79178fc7_46e8_412f_b875_222389e8c699
        
        boolean_sp(const boolean_sp& other);                                                                ///< @copydoc _f13e81f0_5ced_4185_8bfb_6a17811bf402
        boolean_sp(const volatile boolean_sp& other);                                                       ///< @copydoc 
        boolean_sp(boolean_sp&& other) noexcept;                                                            ///< @copydoc _2051d33c_31c9_402b_b7b0_30ed311bae55
        boolean_sp(volatile boolean_sp&& other) noexcept;                                                   ///< @copydoc 

        boolean_sp&             operator =(const boolean_sp& other);                                        ///< @copydoc _754a3b96_c816_4875_b1c5_bd94f74975fe
        volatile boolean_sp&    operator =(const boolean_sp& other) volatile;                               ///< @copydoc 
        boolean_sp&             operator =(const volatile boolean_sp& other);                               ///< @copydoc 
        volatile boolean_sp&    operator =(const volatile boolean_sp& other) volatile;                      ///< @copydoc 
        boolean_sp&             operator =(boolean_sp&& other) noexcept;                                    ///< @copydoc _27b572bf_b851_4bbb_bf27_5be01e5164d0
        volatile boolean_sp&    operator =(boolean_sp&& other) volatile noexcept;                           ///< @copydoc 
        boolean_sp&             operator =(is_just_volatile_tr<boolean_sp> auto&& other) noexcept;          ///< @copydoc 
        volatile boolean_sp&    operator =(is_just_volatile_tr<boolean_sp> auto&& other) volatile noexcept; ///< @copydoc 
        
        ~boolean_sp();                                                                                      ///< @copydoc _70f5c9d9_6b00_4e4b_ab7a_8f43cf310780
        /// @}

    public:
        /// @name methods
        /// @copydoc _f8359bc4_053e_45a2_92c0_8cc2aec98f3c
        /// @{
        value_t Access() const;                                                                     ///< @copydoc _4dac77d5_7b0a_47be_8b54_55194f16d92c
        value_t Access() const volatile;                                                            ///< @copydoc 

        value_t Assign(convertible_tr<value_t> auto value);                                         ///< @copydoc _21eb4382_88d5_4c3d_8632_84e7a781884c
        value_t Assign(convertible_tr<value_t> auto value) volatile;                                ///< @copydoc 

        value_t Exchange(convertible_tr<value_t> auto value);                                       ///< @copydoc _36a45c7f_a017_48c8_9b38_80f41441dfd6
        value_t Exchange(convertible_tr<value_t> auto value) volatile;                              ///< @copydoc 
        bool_t  Exchange_If_Equals(value_t& snapshot, convertible_tr<value_t> auto value);          ///< @copydoc _f4834de8_17dd_46c2_851e_90cf412a7513
        bool_t  Exchange_If_Equals(value_t& snapshot, convertible_tr<value_t> auto value) volatile; ///< @copydoc 
        /// @}

    public:
        /// @name casts
        /// @copydoc _b471158e_1d68_4c75_a520_763cfb48f86b
        /// @{
        operator    std_bool_t() const;             ///< @copydoc _18ea22ec_be2e_42c9_a63d_b4af5e137aa5
        operator    std_bool_t() const volatile;    ///< @copydoc 
        /// @}

    public:
        /// @name operators
        /// @copydoc _0e407320_061a_4d4b_ae76_397896faa849
        /// @{
        value_t operator ()() const;            ///< @copydoc _9c15e3f8_92db_4474_ab7a_fb1486fc3800
        value_t operator ()() const volatile;   ///< @copydoc 
        /// @}

    public:
        /// @name none_t interface
        /// @copydoc _c2ec5f5b_f117_4208_bad6_a0ac7700c0e3
        /// @{
        boolean_sp(none_t);                                         ///< @copydoc _0de1f181_bf7f_4975_9c6d_076c1fedce94

        boolean_sp&             operator =(none_t);                 ///< @copydoc _3429943c_402f_43cb_936a_175319131f3f
        volatile boolean_sp&    operator =(none_t) volatile;        ///< @copydoc 

        bool_t                  operator ==(none_t) const;          ///< @copydoc _36cb7982_c38b_4058_8c15_3e142e7d2653
        bool_t                  operator ==(none_t) const volatile; ///< @copydoc 
        bool_t                  operator !=(none_t) const;          ///< @copydoc _2ee275c0_12a7_400c_ba80_08d8ef10d8db
        bool_t                  operator !=(none_t) const volatile; ///< @copydoc 
        /// @}
    };

    /// @nosubgrouping
    /// @copydoc _1eb34513_6d58_4671_bcfc_61834a0fa529
    template <integer_tr integer_p>
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
        static const value_t    DEFAULT_VALUE;  ///< @copydoc _5a3235cf_0d15_437b_a951_a18ac52dc5f9
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
        integer_sp();                                                                                       ///< @copydoc _6214730b_aeb9_4083_998c_f9e1c020924e
        
        integer_sp(convertible_tr<value_t> auto value);                                                     ///< @copydoc _934d0d25_c160_42c4_a269_363ce0e78da6
        
        integer_sp(const integer_sp& other);                                                                ///< @copydoc _ca4f92b3_f5c8_470d_a3da_c7f8a334d441
        integer_sp(const volatile integer_sp& other);                                                       ///< @copydoc 
        integer_sp(integer_sp&& other) noexcept;                                                            ///< @copydoc _0d15101b_2293_4225_8f70_3edb3f8618de
        integer_sp(volatile integer_sp&& other) noexcept;                                                   ///< @copydoc 

        integer_sp&             operator =(const integer_sp& other);                                        ///< @copydoc _eeeb1194_9900_46ab_8e15_1e8a0a663395
        volatile integer_sp&    operator =(const integer_sp& other) volatile;                               ///< @copydoc 
        integer_sp&             operator =(const volatile integer_sp& other);                               ///< @copydoc 
        volatile integer_sp&    operator =(const volatile integer_sp& other) volatile;                      ///< @copydoc 
        integer_sp&             operator =(integer_sp&& other) noexcept;                                    ///< @copydoc _ccf84af8_3181_43e0_a892_9850e2a4c6f0
        volatile integer_sp&    operator =(integer_sp&& other) volatile noexcept;                           ///< @copydoc 
        integer_sp&             operator =(is_just_volatile_tr<integer_sp> auto&& other) noexcept;          ///< @copydoc 
        volatile integer_sp&    operator =(is_just_volatile_tr<integer_sp> auto&& other) volatile noexcept; ///< @copydoc 
        
        ~integer_sp();                                                                                      ///< @copydoc _01602bc3_a017_47e4_b34e_b8a1dd6dae2f
        /// @}

    public:
        /// @name methods
        /// @copydoc _ebe2958b_6231_481e_819f_84d882989f41
        /// @{
        value_t Access() const;                                                                     ///< @copydoc _72e0df20_176a_4ad8_9350_7edcadf7d893
        value_t Access() const volatile;                                                            ///< @copydoc 

        value_t Assign(convertible_tr<value_t> auto value);                                         ///< @copydoc _921ddfce_4850_4bda_bd9a_04fc363a4891
        value_t Assign(convertible_tr<value_t> auto value) volatile;                                ///< @copydoc 
        value_t Assign_Add(convertible_tr<value_t> auto value);                                     ///< @copydoc _d09f0f0c_4e8e_4a47_8d93_3e7e9c0dabdd
        value_t Assign_Add(convertible_tr<value_t> auto value) volatile;                            ///< @copydoc 
        value_t Assign_Subtract(convertible_tr<value_t> auto value);                                ///< @copydoc _775e6700_6127_4c6d_a6ae_f9e0032aba91
        value_t Assign_Subtract(convertible_tr<value_t> auto value) volatile;                       ///< @copydoc 
        value_t Assign_Multiply(convertible_tr<value_t> auto value);                                ///< @copydoc _4d88c925_37c5_4639_9d23_192186152707
        value_t Assign_Multiply(convertible_tr<value_t> auto value) volatile;                       ///< @copydoc 
        value_t Assign_Divide(convertible_tr<value_t> auto value);                                  ///< @copydoc _0d0b5750_b10d_4e65_8af6_8f54cd3a54c3
        value_t Assign_Divide(convertible_tr<value_t> auto value) volatile;                         ///< @copydoc 
        value_t Assign_Modulus(integer_tr auto value);                                              ///< @copydoc _01f043fb_3ae1_4233_bb00_71f2fd2e204b
        value_t Assign_Modulus(integer_tr auto value) volatile;                                     ///< @copydoc 
        value_t Assign_Or(integer_tr auto value);                                                   ///< @copydoc _c59d3a53_f67f_4efb_830a_96b14e32ba0f
        value_t Assign_Or(integer_tr auto value) volatile;                                          ///< @copydoc 
        value_t Assign_And(integer_tr auto value);                                                  ///< @copydoc _d39105cd_1da2_442a_b146_edf5de564212
        value_t Assign_And(integer_tr auto value) volatile;                                         ///< @copydoc 
        value_t Assign_Xor(integer_tr auto value);                                                  ///< @copydoc _10c909ec_eb4f_40fd_a3e6_cd32023cb32b
        value_t Assign_Xor(integer_tr auto value) volatile;                                         ///< @copydoc 
        value_t Assign_Left_Shift(integer_tr auto value);                                           ///< @copydoc _9cec8a64_07fa_457f_94f2_062c50a8ba85
        value_t Assign_Left_Shift(integer_tr auto value) volatile;                                  ///< @copydoc 
        value_t Assign_Right_Shift(integer_tr auto value);                                          ///< @copydoc _e1ff5f86_4078_4364_ad8d_0aa458852ed5
        value_t Assign_Right_Shift(integer_tr auto value) volatile;                                 ///< @copydoc 
        
        value_t Exchange(convertible_tr<value_t> auto value);                                       ///< @copydoc _bf53feba_9fd9_4938_9e0a_6f020b7de344
        value_t Exchange(convertible_tr<value_t> auto value) volatile;                              ///< @copydoc 
        value_t Exchange_Add(convertible_tr<value_t> auto value);                                   ///< @copydoc _eb209d2b_53f3_4aaf_87c4_7e6f7415d7de
        value_t Exchange_Add(convertible_tr<value_t> auto value) volatile;                          ///< @copydoc 
        value_t Exchange_Subtract(convertible_tr<value_t> auto value);                              ///< @copydoc _9c87833c_f98e_420e_9451_7f047098b464
        value_t Exchange_Subtract(convertible_tr<value_t> auto value) volatile;                     ///< @copydoc 
        value_t Exchange_Multiply(convertible_tr<value_t> auto value);                              ///< @copydoc _8c447343_f4d4_4fd3_bcc6_14859390eaf9
        value_t Exchange_Multiply(convertible_tr<value_t> auto value) volatile;                     ///< @copydoc 
        value_t Exchange_Divide(convertible_tr<value_t> auto value);                                ///< @copydoc _bc057de1_5e36_47e1_8697_efa1194d1a23
        value_t Exchange_Divide(convertible_tr<value_t> auto value) volatile;                       ///< @copydoc 
        value_t Exchange_Modulus(integer_tr auto value);                                            ///< @copydoc _717e5d3d_5037_475a_b826_89461c3788e2
        value_t Exchange_Modulus(integer_tr auto value) volatile;                                   ///< @copydoc 
        value_t Exchange_Or(integer_tr auto value);                                                 ///< @copydoc _5a508f6d_abaf_409e_83dc_f7133a81fb6f
        value_t Exchange_Or(integer_tr auto value) volatile;                                        ///< @copydoc 
        value_t Exchange_And(integer_tr auto value);                                                ///< @copydoc _fe438ba0_c269_4703_b2f6_66a30e136f8a
        value_t Exchange_And(integer_tr auto value) volatile;                                       ///< @copydoc 
        value_t Exchange_Xor(integer_tr auto value);                                                ///< @copydoc _b9453618_fb4e_425d_a1b1_f88a5d272622
        value_t Exchange_Xor(integer_tr auto value) volatile;                                       ///< @copydoc 
        value_t Exchange_Left_Shift(integer_tr auto value);                                         ///< @copydoc _c9da5f3a_59b3_4b92_83c7_724a385cb092
        value_t Exchange_Left_Shift(integer_tr auto value) volatile;                                ///< @copydoc 
        value_t Exchange_Right_Shift(integer_tr auto value);                                        ///< @copydoc _c7342e20_fb3b_44ae_ab33_b8ec4f4552c2
        value_t Exchange_Right_Shift(integer_tr auto value) volatile;                               ///< @copydoc 
        bool_t  Exchange_If_Equals(value_t& snapshot, convertible_tr<value_t> auto value);          ///< @copydoc _de4d8d98_3a2b_4557_be66_5015696218c3
        bool_t  Exchange_If_Equals(value_t& snapshot, convertible_tr<value_t> auto value) volatile; ///< @copydoc 
        /// @}

    public:
        /// @name casts
        /// @copydoc _473fc73c_71f3_4897_b548_32326ec7f8ca
        /// @{
        operator    value_t() const;            ///< @copydoc _9ee8a537_8292_436e_b054_c74f3a74a281
        operator    value_t() const volatile;   ///< @copydoc 
        /// @}

    public:
        /// @name operators
        /// @copydoc _ebf639ee_013e_4e27_adc1_1752df597ddf
        /// @{
        value_t operator ()() const;                                        ///< @copydoc _788d318f_88ed_44b0_ae45_e260734bb5cd
        value_t operator ()() const volatile;                               ///< @copydoc 

        value_t operator +=(convertible_tr<value_t> auto value);            ///< @copydoc _85417b7a_dd77_4294_b67e_6e08ab7e27f9
        value_t operator +=(convertible_tr<value_t> auto value) volatile;   ///< @copydoc 
        value_t operator -=(convertible_tr<value_t> auto value);            ///< @copydoc _29505a0a_1b57_45eb_b075_8b2f3d3be8f3
        value_t operator -=(convertible_tr<value_t> auto value) volatile;   ///< @copydoc 
        value_t operator *=(convertible_tr<value_t> auto value);            ///< @copydoc _713ce567_d8be_442b_b578_c2ada942f6dc
        value_t operator *=(convertible_tr<value_t> auto value) volatile;   ///< @copydoc 
        value_t operator /=(convertible_tr<value_t> auto value);            ///< @copydoc _ba2e4618_9572_43ee_8b1b_096582c99707
        value_t operator /=(convertible_tr<value_t> auto value) volatile;   ///< @copydoc 
        value_t operator %=(integer_tr auto value);                         ///< @copydoc _8e7ba682_f853_4175_9f63_72e8141387d5
        value_t operator %=(integer_tr auto value) volatile;                ///< @copydoc 
        value_t operator |=(integer_tr auto value);                         ///< @copydoc _707c26ad_75fc_43cc_be98_233cb47d3eec
        value_t operator |=(integer_tr auto value) volatile;                ///< @copydoc 
        value_t operator &=(integer_tr auto value);                         ///< @copydoc _5a8f0664_0510_4f5d_991a_cc2a5eaea4b5
        value_t operator &=(integer_tr auto value) volatile;                ///< @copydoc 
        value_t operator ^=(integer_tr auto value);                         ///< @copydoc _77262a09_d572_440c_849c_d124b0d7dc6d
        value_t operator ^=(integer_tr auto value) volatile;                ///< @copydoc 
        value_t operator <<=(integer_tr auto value);                        ///< @copydoc _937d7488_c9e6_495c_9917_ff3676dd339b
        value_t operator <<=(integer_tr auto value) volatile;               ///< @copydoc 
        value_t operator >>=(integer_tr auto value);                        ///< @copydoc _b27449e8_bd83_418c_b0cf_5f419e5e06dd
        value_t operator >>=(integer_tr auto value) volatile;               ///< @copydoc 

        value_t operator ++();                                              ///< @copydoc _3706a8b1_15f5_4a60_94dd_b88bd37d602b
        value_t operator ++() volatile;                                     ///< @copydoc 
        value_t operator ++(int);                                           ///< @copydoc _23f284ee_6dd9_4b76_b361_1c0b287c4b8f
        value_t operator ++(int) volatile;                                  ///< @copydoc 
        value_t operator --();                                              ///< @copydoc _3a8149a1_3608_4c64_9ccc_98fbf01aa964
        value_t operator --() volatile;                                     ///< @copydoc 
        value_t operator --(int);                                           ///< @copydoc _0c3d89f4_6273_4a93_958f_631c8c7f1083
        value_t operator --(int) volatile;                                  ///< @copydoc 
        /// @}

    public:
        /// @name none_t interface
        /// @copydoc _feb54dad_7493_4e9d_9e24_2a69c9912f95
        /// @{
        integer_sp(none_t);                                         ///< @copydoc _a3b18509_3705_4a67_88cb_a5590f4cae24

        integer_sp&             operator =(none_t);                 ///< @copydoc _18865e46_d599_4053_a6dc_e0609fb811a1
        volatile integer_sp&    operator =(none_t) volatile;        ///< @copydoc 

        bool_t                  operator ==(none_t) const;          ///< @copydoc _e3609d5e_27c6_4a0e_8928_c54f879abb96
        bool_t                  operator ==(none_t) const volatile; ///< @copydoc 
        bool_t                  operator !=(none_t) const;          ///< @copydoc _cc53fec7_7977_4de9_9aa9_852cedd9134a
        bool_t                  operator !=(none_t) const volatile; ///< @copydoc 
        /// @}
    };

    /// @nosubgrouping
    /// @copydoc _253501fa_5219_4009_94e8_08f3a28881ee
    template <real_tr real_p>
    class real_sp
    {
    public:
        /// @name aliases
        /// @copydoc _05975b5a_a55a_449f_aaf5_1a45725160f0
        /// @{
        using value_t   = real_p;   ///< @copydoc _acf98834_4daf_433f_bb79_6db3fbbe4351
        /// @}

    public:
        /// @name static data
        /// @copydoc _c0ba4f80_8a10_495a_831e_0208a50ac9e0
        /// @{
        static const value_t    DEFAULT_VALUE;  ///< @copydoc _7ad42492_b8e5_43bd_a25d_d2a4eddb0c18
        /// @}

    public:
        /// @name object data
        /// @copydoc _736e305c_efd6_47cb_afc0_e754e260f06e
        /// @{
        volatile value_t    value;  ///< @copydoc _19250f59_8057_4e26_9180_a01f32df6660
        /// @}

    public:
        /// @name objects
        /// @copydoc _be559580_3edb_4338_b9e4_8281092c81ed
        /// @{
        real_sp();                                                                                      ///< @copydoc _78362e25_29db_484e_860f_66bf63ef0702
        
        real_sp(convertible_tr<value_t> auto value);                                                    ///< @copydoc _e33edbdb_fbf4_49f0_add1_08599e7824b6
        
        real_sp(const real_sp& other);                                                                  ///< @copydoc _61a595a9_8bea_4302_a9cf_5c0c84e88502
        real_sp(const volatile real_sp& other);                                                         ///< @copydoc 
        real_sp(real_sp&& other) noexcept;                                                              ///< @copydoc _d20308c7_ca46_4f3b_ac5d_4817164d0a99
        real_sp(volatile real_sp&& other) noexcept;                                                     ///< @copydoc 

        real_sp&            operator =(const real_sp& other);                                           ///< @copydoc _13e2fc20_6a84_42c2_8e14_5464b2a92bd2
        volatile real_sp&   operator =(const real_sp& other) volatile;                                  ///< @copydoc 
        real_sp&            operator =(const volatile real_sp& other);                                  ///< @copydoc 
        volatile real_sp&   operator =(const volatile real_sp& other) volatile;                         ///< @copydoc 
        real_sp&            operator =(real_sp&& other) noexcept;                                       ///< @copydoc _111623c4_8569_44fe_ac45_eb839d13677c
        volatile real_sp&   operator =(real_sp&& other) volatile noexcept;                              ///< @copydoc 
        real_sp&            operator =(is_just_volatile_tr<real_sp> auto&& other) noexcept;             ///< @copydoc 
        volatile real_sp&   operator =(is_just_volatile_tr<real_sp> auto&& other) volatile noexcept;    ///< @copydoc 

        ~real_sp();                                                                                     ///< @copydoc _41d0b192_af22_4282_b188_40f164bf851e
        /// @}

    public:
        /// @name methods
        /// @copydoc _d03d71df_9d3c_40d3_94ef_41ec0a768384
        /// @{
        value_t Access() const;                                                                     ///< @copydoc _5f07459b_cc2c_4df1_b8f8_df28d9c0c62a
        value_t Access() const volatile;                                                            ///< @copydoc 

        value_t Assign(convertible_tr<value_t> auto value);                                         ///< @copydoc _86090c8f_aa60_41b3_9d8d_c7811b288aac
        value_t Assign(convertible_tr<value_t> auto value) volatile;                                ///< @copydoc 
        value_t Assign_Add(convertible_tr<value_t> auto value);                                     ///< @copydoc _59a94c28_e4ae_4aca_af97_fe0a03d9a4d0
        value_t Assign_Add(convertible_tr<value_t> auto value) volatile;                            ///< @copydoc 
        value_t Assign_Subtract(convertible_tr<value_t> auto value);                                ///< @copydoc _684e4401_0e5b_4e8a_8376_5752bade8903
        value_t Assign_Subtract(convertible_tr<value_t> auto value) volatile;                       ///< @copydoc 
        value_t Assign_Multiply(convertible_tr<value_t> auto value);                                ///< @copydoc _ec53b9b0_5fb3_49c3_a1f5_aa0a2d7e9351
        value_t Assign_Multiply(convertible_tr<value_t> auto value) volatile;                       ///< @copydoc 
        value_t Assign_Divide(convertible_tr<value_t> auto value);                                  ///< @copydoc _c663a829_3893_4449_aa1b_ba5e0a26c6de
        value_t Assign_Divide(convertible_tr<value_t> auto value) volatile;                         ///< @copydoc 

        value_t Exchange(convertible_tr<value_t> auto value);                                       ///< @copydoc _ab0dd77c_4ae0_4d8a_94a4_78c85ed9872e
        value_t Exchange(convertible_tr<value_t> auto value) volatile;                              ///< @copydoc 
        value_t Exchange_Add(convertible_tr<value_t> auto value);                                   ///< @copydoc _f901edef_ee4f_446f_84ad_65f1f31f52af
        value_t Exchange_Add(convertible_tr<value_t> auto value) volatile;                          ///< @copydoc 
        value_t Exchange_Subtract(convertible_tr<value_t> auto value);                              ///< @copydoc _551c50b3_c942_4872_86de_edc3e1b6f615
        value_t Exchange_Subtract(convertible_tr<value_t> auto value) volatile;                     ///< @copydoc 
        value_t Exchange_Multiply(convertible_tr<value_t> auto value);                              ///< @copydoc _8418d17c_3335_4b14_989a_c7756f407cea
        value_t Exchange_Multiply(convertible_tr<value_t> auto value) volatile;                     ///< @copydoc 
        value_t Exchange_Divide(convertible_tr<value_t> auto value);                                ///< @copydoc _68377f8f_2dca_4787_ade4_4fb9922d88f3
        value_t Exchange_Divide(convertible_tr<value_t> auto value) volatile;                       ///< @copydoc 
        bool_t  Exchange_If_Equals(value_t& snapshot, convertible_tr<value_t> auto value);          ///< @copydoc _7dd1307a_b27e_458e_8c07_812523cb6cce
        bool_t  Exchange_If_Equals(value_t& snapshot, convertible_tr<value_t> auto value) volatile; ///< @copydoc 
        /// @}

    public:
        /// @name casts
        /// @copydoc _d06c6ef3_1cf6_4092_81d0_a32ff12fce58
        /// @{
        operator    value_t() const;            ///< @copydoc _9280eeed_487d_481e_a15d_1853a677bcc5
        operator    value_t() const volatile;   ///< @copydoc 
        /// @}

    public:
        /// @name operators
        /// @copydoc _59ee1957_70b1_4581_8181_7c9271104cd0
        /// @{
        value_t operator ()() const;                                        ///< @copydoc _da93485f_123d_4d5e_bdef_5aa33745b1c2
        value_t operator ()() const volatile;                               ///< @copydoc 

        value_t operator +=(convertible_tr<value_t> auto value);            ///< @copydoc _9440c8a7_f2e4_4dea_8202_eb1a3b33f624
        value_t operator +=(convertible_tr<value_t> auto value) volatile;   ///< @copydoc 
        value_t operator -=(convertible_tr<value_t> auto value);            ///< @copydoc _05c4f9da_6215_48ab_931f_6a63822fb3bc
        value_t operator -=(convertible_tr<value_t> auto value) volatile;   ///< @copydoc 
        value_t operator *=(convertible_tr<value_t> auto value);            ///< @copydoc _a9aa1790_c0ee_4ef3_985e_09c498389151
        value_t operator *=(convertible_tr<value_t> auto value) volatile;   ///< @copydoc 
        value_t operator /=(convertible_tr<value_t> auto value);            ///< @copydoc _68c79a5b_1514_4d9e_a931_2b08417794cc
        value_t operator /=(convertible_tr<value_t> auto value) volatile;   ///< @copydoc 

        value_t operator ++();                                              ///< @copydoc _40b4856c_dc14_4005_9cd1_f90ae5446d9f
        value_t operator ++() volatile;                                     ///< @copydoc 
        value_t operator ++(int);                                           ///< @copydoc _98d862c6_186a_4e4c_a727_0cd0272f37ba
        value_t operator ++(int) volatile;                                  ///< @copydoc 
        value_t operator --();                                              ///< @copydoc _060484a8_af7f_42f0_99b4_f8049e05c5fd
        value_t operator --() volatile;                                     ///< @copydoc 
        value_t operator --(int);                                           ///< @copydoc _f3294493_3779_4089_b875_5b0576479f2e
        value_t operator --(int) volatile;                                  ///< @copydoc 
        /// @}

    public:
        /// @name none_t interface
        /// @copydoc _50ecf924_c297_4baf_a55b_63473f74e9fd
        /// @{
        real_sp(none_t);                                        ///< @copydoc _3310ff90_5347_4ee8_a55f_6ee26684ae05

        real_sp&            operator =(none_t);                 ///< @copydoc _6c3ee7ad_411d_4f3f_adbc_4c793cb280aa
        volatile real_sp&   operator =(none_t) volatile;        ///< @copydoc 

        bool_t              operator ==(none_t) const;          ///< @copydoc _fb6fdd58_1c3a_4ced_8231_917ad7d8931c
        bool_t              operator ==(none_t) const volatile; ///< @copydoc 
        bool_t              operator !=(none_t) const;          ///< @copydoc _1d33ee84_f30a_40a2_8ba8_3f66bd115ea4
        bool_t              operator !=(none_t) const volatile; ///< @copydoc 
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
        static const value_t    DEFAULT_VALUE;  ///< @copydoc _d253babc_66d2_4245_bdef_4d4d9757bba8
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
        pointer_sp();                                                                                       ///< @copydoc _b54cf1c4_55a9_4de6_8d00_dcb2d3ca9d25
        
        pointer_sp(convertible_tr<value_t> auto value);                                                     ///< @copydoc _6fe3639a_9af9_482a_ac65_71dd762b87c4
        
        pointer_sp(const pointer_sp& other);                                                                ///< @copydoc _7daf8ec0_a6a6_422c_a4be_367b0a320abd
        pointer_sp(const volatile pointer_sp& other);                                                       ///< @copydoc 
        pointer_sp(pointer_sp&& other) noexcept;                                                            ///< @copydoc _9004776c_b34b_4004_a28b_aa3405d0705a
        pointer_sp(volatile pointer_sp&& other) noexcept;                                                   ///< @copydoc 

        pointer_sp&             operator =(const pointer_sp& other);                                        ///< @copydoc _4010b13b_d165_40e2_9ee1_4c1cd9d9347e
        volatile pointer_sp&    operator =(const pointer_sp& other) volatile;                               ///< @copydoc 
        pointer_sp&             operator =(const volatile pointer_sp& other);                               ///< @copydoc 
        volatile pointer_sp&    operator =(const volatile pointer_sp& other) volatile;                      ///< @copydoc 
        pointer_sp&             operator =(pointer_sp&& other) noexcept;                                    ///< @copydoc _aa527a17_a527_4c42_a747_e666b3ad3def
        volatile pointer_sp&    operator =(pointer_sp&& other) volatile noexcept;                           ///< @copydoc 
        pointer_sp&             operator =(is_just_volatile_tr<pointer_sp> auto&& other) noexcept;          ///< @copydoc 
        volatile pointer_sp&    operator =(is_just_volatile_tr<pointer_sp> auto&& other) volatile noexcept; ///< @copydoc 
        
        ~pointer_sp();                                                                                      ///< @copydoc _2f13ca94_e440_4c22_8716_ad04477faeec
        /// @}

    public:
        /// @name methods
        /// @copydoc _4d354065_6729_45ca_a929_ecf57cbaa63f
        /// @{
        value_t Access() const;                                                                     ///< @copydoc _c0c47fc9_d389_4d39_9c8b_ca60d166842d
        value_t Access() const volatile;                                                            ///< @copydoc 

        value_t Assign(convertible_tr<value_t> auto value);                                         ///< @copydoc _af9d53bf_c4e8_4bfb_b2a4_eb2caa1b4ce1
        value_t Assign(convertible_tr<value_t> auto value) volatile;                                ///< @copydoc 
        value_t Assign_Add(integer_tr auto value);                                                  ///< @copydoc _c8f00ac4_b591_419a_a3ca_9c1450aa4427
        value_t Assign_Add(integer_tr auto value) volatile;                                         ///< @copydoc 
        value_t Assign_Subtract(integer_tr auto value);                                             ///< @copydoc _90060189_8434_4919_9297_9b22a439076f
        value_t Assign_Subtract(integer_tr auto value) volatile;                                    ///< @copydoc 

        value_t Exchange(convertible_tr<value_t> auto value);                                       ///< @copydoc _d1dd2b4b_adf7_4f7e_9c62_f29519eda90f
        value_t Exchange(convertible_tr<value_t> auto value) volatile;                              ///< @copydoc 
        value_t Exchange_Add(integer_tr auto value);                                                ///< @copydoc _212049f1_8d3b_4529_99d0_f800a9711e4b
        value_t Exchange_Add(integer_tr auto value) volatile;                                       ///< @copydoc 
        value_t Exchange_Subtract(integer_tr auto value);                                           ///< @copydoc _2fcafb28_9779_4964_98af_e50b75de4903
        value_t Exchange_Subtract(integer_tr auto value) volatile;                                  ///< @copydoc 
        bool_t  Exchange_If_Equals(value_t& snapshot, convertible_tr<value_t> auto value);          ///< @copydoc _10426898_c8ab_44de_b7a7_748f31e5ad00
        bool_t  Exchange_If_Equals(value_t& snapshot, convertible_tr<value_t> auto value) volatile; ///< @copydoc 
        /// @}

    public:
        /// @name casts
        /// @copydoc _d6d6ad6c_4e44_4a66_af85_ecee32f79a63
        /// @{
        operator    value_t() const;            ///< @copydoc _692a5946_de1e_4633_a533_00fa4c7503bd
        operator    value_t() const volatile;   ///< @copydoc 
        /// @}

    public:
        /// @name operators
        /// @copydoc _5c4884cd_dbd5_4688_ac52_a6de0f6a8348
        /// @{
        value_t operator ()() const;                                ///< @copydoc _3ea0703e_60a3_487d_ab7a_40079a05c05d
        value_t operator ()() const volatile;                       ///< @copydoc 

        value_t operator +=(integer_tr auto value);                 ///< @copydoc _4bc62f6a_629b_4332_beb0_82873b0c0802
        value_t operator +=(integer_tr auto value) volatile;        ///< @copydoc 
        value_t operator -=(integer_tr auto value);                 ///< @copydoc _442d3e31_4638_469e_9d70_99ff94c0ddcf
        value_t operator -=(integer_tr auto value) volatile;        ///< @copydoc 

        value_t operator ++();                                      ///< @copydoc _05ce7c2c_3ac7_42dc_ba1b_3b6c5bfa358e
        value_t operator ++() volatile;                             ///< @copydoc 
        value_t operator ++(int);                                   ///< @copydoc _eae55e62_8447_4782_9be7_b642ff541fa8
        value_t operator ++(int) volatile;                          ///< @copydoc 
        value_t operator --();                                      ///< @copydoc _7a64b474_788e_4686_9093_30e9482db8f6
        value_t operator --() volatile;                             ///< @copydoc 
        value_t operator --(int);                                   ///< @copydoc _da7ec2ad_ad87_427e_8876_a9029c35af15
        value_t operator --(int) volatile;                          ///< @copydoc 

        value_t operator ->() const;                                ///< @copydoc _3dd98d85_e299_439b_902f_87e5ecc1a2be
        value_t operator ->() const volatile;                       ///< @copydoc 
        unit_t& operator *() const;                                 ///< @copydoc _626fbdfe_f1db_44c7_85ed_3db92e4fb3d1
        unit_t& operator *() const volatile;                        ///< @copydoc 
        unit_t& operator [](integer_tr auto index) const;           ///< @copydoc _141bf596_33d0_4a21_95b9_caa5166f0c04
        unit_t& operator [](integer_tr auto index) const volatile;  ///< @copydoc 
        /// @}

    public:
        /// @name none_t interface
        /// @copydoc _dcabeeed_678e_49d9_9020_9f67fb4b1bb4
        /// @{
        pointer_sp(none_t);                                         ///< @copydoc _8d49d4d6_1fd1_4a84_b537_aa06f5f720c4

        pointer_sp&             operator =(none_t);                 ///< @copydoc _8aedd3b6_6fe3_4db7_8c9e_8714e2449988
        volatile pointer_sp&    operator =(none_t) volatile;        ///< @copydoc 
        
        bool_t                  operator ==(none_t) const;          ///< @copydoc _96b228ef_64d8_4e9e_af2b_28d1e81bc25e
        bool_t                  operator ==(none_t) const volatile; ///< @copydoc 
        bool_t                  operator !=(none_t) const;          ///< @copydoc _3ea59cb3_9e9a_4b67_9023_bc6877f93102
        bool_t                  operator !=(none_t) const volatile; ///< @copydoc 
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
        static const value_t    DEFAULT_VALUE;  ///< @copydoc _7b0cb549_667e_406d_a8b7_ce953ed76b7f
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
        void_pointer_sp();                                                                                              ///< @copydoc _4aaf8533_9fae_4e73_a496_b809f4182419
        
        void_pointer_sp(convertible_tr<value_t> auto value);                                                            ///< @copydoc _6835eb33_5782_4b57_b536_6176a01989f8
        
        void_pointer_sp(const void_pointer_sp& other);                                                                  ///< @copydoc _c8551a6c_8e62_416a_9f73_a5b1b99f984f
        void_pointer_sp(const volatile void_pointer_sp& other);                                                         ///< @copydoc 
        void_pointer_sp(void_pointer_sp&& other) noexcept;                                                              ///< @copydoc _ebfcfe7d_9340_4d7a_b128_df74de441f1f
        void_pointer_sp(volatile void_pointer_sp&& other) noexcept;                                                     ///< @copydoc 

        void_pointer_sp&            operator =(const void_pointer_sp& other);                                           ///< @copydoc _86b76904_0174_4cdc_a369_2673d1740ec5
        volatile void_pointer_sp&   operator =(const void_pointer_sp& other) volatile;                                  ///< @copydoc 
        void_pointer_sp&            operator =(const volatile void_pointer_sp& other);                                  ///< @copydoc 
        volatile void_pointer_sp&   operator =(const volatile void_pointer_sp& other) volatile;                         ///< @copydoc 
        void_pointer_sp&            operator =(void_pointer_sp&& other) noexcept;                                       ///< @copydoc _0eea443f_df0b_442e_a8fa_3173c412e675
        volatile void_pointer_sp&   operator =(void_pointer_sp&& other) volatile noexcept;                              ///< @copydoc 
        void_pointer_sp&            operator =(is_just_volatile_tr<void_pointer_sp> auto&& other) noexcept;             ///< @copydoc 
        volatile void_pointer_sp&   operator =(is_just_volatile_tr<void_pointer_sp> auto&& other) volatile noexcept;    ///< @copydoc 
        
        ~void_pointer_sp();                                                                                             ///< @copydoc _e286417e_9f29_48fc_b76e_b118d557d1e1
        /// @}

    public:
        /// @name methods
        /// @copydoc _98ee4349_04dd_4841_9bfd_a2183df63d35
        /// @{
        value_t Access() const;                                                                     ///< @copydoc _a7b1972a_9ff7_4932_9a82_d4cb553f06c4
        value_t Access() const volatile;                                                            ///< @copydoc 

        value_t Assign(convertible_tr<value_t> auto value);                                         ///< @copydoc _1f246d11_214e_48b0_ab8d_2f7f96eecba1
        value_t Assign(convertible_tr<value_t> auto value) volatile;                                ///< @copydoc 

        value_t Exchange(convertible_tr<value_t> auto value);                                       ///< @copydoc _80c24152_78ec_41a9_935d_e4a3ba82dbb5
        value_t Exchange(convertible_tr<value_t> auto value) volatile;                              ///< @copydoc 
        bool_t  Exchange_If_Equals(value_t& snapshot, convertible_tr<value_t> auto value);          ///< @copydoc _559c10d8_e6bc_417d_81f6_276e9944ba9a
        bool_t  Exchange_If_Equals(value_t& snapshot, convertible_tr<value_t> auto value) volatile; ///< @copydoc 
        /// @}

    public:
        /// @name casts
        /// @copydoc _65d14b1d_763a_45d8_875b_9462769913c4
        /// @{
        operator    value_t() const;            ///< @copydoc _a1e15ae8_6b2d_4789_b02a_1139342e55d3
        operator    value_t() const volatile;   ///< @copydoc 
        /// @}

    public:
        /// @name operators
        /// @copydoc _f8bd3a76_a5a5_4a9f_80d0_c96830453035
        /// @{
        value_t operator ()() const;            ///< @copydoc _dd514422_ac54_4000_a920_0e7cd0c28a96
        value_t operator ()() const volatile;   ///< @copydoc 
        /// @}

    public:
        /// @name none_t interface
        /// @copydoc _02896e4d_eea6_4f9f_88d5_b3537f6031d0
        /// @{
        void_pointer_sp(none_t);                                        ///< @copydoc _5d892adb_d42c_46b2_8398_ea64333dc028

        void_pointer_sp&            operator =(none_t);                 ///< @copydoc _2ea4753b_1569_4b90_b19a_70e7f642b906
        volatile void_pointer_sp&   operator =(none_t) volatile;        ///< @copydoc 
        
        bool_t                      operator ==(none_t) const;          ///< @copydoc _97762179_237b_446c_85db_1278d91a8179
        bool_t                      operator ==(none_t) const volatile; ///< @copydoc 
        bool_t                      operator !=(none_t) const;          ///< @copydoc _0abf2389_f09c_4542_9e53_9b15e0c608b3
        bool_t                      operator !=(none_t) const volatile; ///< @copydoc 
        /// @}
    };

}}

namespace nkr {

    /// @nosubgrouping
    /// @copydoc _d6e046d8_6c2e_4075_905b_563f1c8f2455
    template <typename value_p>
    class atomic_t
    {
    public:
        /// @name objects
        /// @copydoc _dce4c888_983a_42e1_9fa3_2bf954717d41
        /// @{
        atomic_t()                                                                                      = delete;   ///< @copydoc _8e2cc8ab_3e8d_4c9a_8cbc_cf0f5ed55d1a

        atomic_t(const atomic_t& other)                                                                 = delete;   ///< @copydoc _9727488c_e0cc_4056_a68f_d12b84d5ceca
        atomic_t(const volatile atomic_t& other)                                                        = delete;   ///< @copydoc 
        atomic_t(atomic_t&& other) noexcept                                                             = delete;   ///< @copydoc _20433dd1_bd70_44ec_b6a3_7b5311f12825
        atomic_t(volatile atomic_t&& other) noexcept                                                    = delete;   ///< @copydoc 

        atomic_t&           operator =(const atomic_t& other)                                           = delete;   ///< @copydoc _28d6f470_34eb_4d0d_8dc5_239e23c1c253
        volatile atomic_t&  operator =(const atomic_t& other) volatile                                  = delete;   ///< @copydoc 
        atomic_t&           operator =(const volatile atomic_t& other)                                  = delete;   ///< @copydoc 
        volatile atomic_t&  operator =(const volatile atomic_t& other) volatile                         = delete;   ///< @copydoc 
        atomic_t&           operator =(atomic_t&& other) noexcept                                       = delete;   ///< @copydoc _388db58d_c89b_420b_bad9_c3e0334cdd9f
        volatile atomic_t&  operator =(atomic_t&& other) volatile noexcept                              = delete;   ///< @copydoc 
        atomic_t&           operator =(is_just_volatile_tr<atomic_t> auto&& other) noexcept             = delete;   ///< @copydoc 
        volatile atomic_t&  operator =(is_just_volatile_tr<atomic_t> auto&& other) volatile noexcept    = delete;   ///< @copydoc 

        ~atomic_t()                                                                                     = delete;   ///< @copydoc _e7cda9ac_182a_48c9_8ace_1a6f8887a65a
        /// @}
    };

    /// @nosubgrouping
    /// @copydoc _7179dda8_8fb2_43e5_9c7a_dbc08cedcbbb
    template <boolean_tr boolean_p>
    class atomic_t<boolean_p> :
        public $atomic_t::boolean_sp<boolean_p>
    {
    public:
        using base_t    = $atomic_t::boolean_sp<boolean_p>;

    public:
        /// @name objects
        /// @copydoc 
        /// @{
        nkr_DEFINE_INHERITANCE_WRAPPER_CTORS_AND_DTOR(atomic_t, base_t);
        /// @}
    };

    /// @nosubgrouping
    /// @copydoc _d976569a_30d5_4a15_8729_b7505132263c
    template <integer_tr integer_p>
    class atomic_t<integer_p> :
        public $atomic_t::integer_sp<integer_p>
    {
    public:
        using base_t    = $atomic_t::integer_sp<integer_p>;

    public:
        /// @name objects
        /// @copydoc 
        /// @{
        nkr_DEFINE_INHERITANCE_WRAPPER_CTORS_AND_DTOR(atomic_t, base_t);
        /// @}
    };

    /// @nosubgrouping
    /// @copydoc _b40d083f_64f4_4a9d_b384_331d91c07b57
    template <real_tr real_p>
    class atomic_t<real_p> :
        public $atomic_t::real_sp<real_p>
    {
    public:
        using base_t    = $atomic_t::real_sp<real_p>;

    public:
        /// @name objects
        /// @copydoc 
        /// @{
        nkr_DEFINE_INHERITANCE_WRAPPER_CTORS_AND_DTOR(atomic_t, base_t);
        /// @}
    };

    /// @nosubgrouping
    /// @copydoc _f8ce2e6d_230a_4ef2_801f_aecbc3571487
    template <pointer_tr pointer_p>
    class atomic_t<pointer_p> :
        public $atomic_t::pointer_sp<pointer_p>
    {
    public:
        using base_t    = $atomic_t::pointer_sp<pointer_p>;

    public:
        /// @name objects
        /// @copydoc 
        /// @{
        nkr_DEFINE_INHERITANCE_WRAPPER_CTORS_AND_DTOR(atomic_t, base_t);
        /// @}
    };

    /// @nosubgrouping
    /// @copydoc _99ace0a0_9530_4fb1_8179_90b7dd50e9ed
    template <>
    class atomic_t<void_t*> :
        public $atomic_t::void_pointer_sp
    {
    public:
        using base_t    = $atomic_t::void_pointer_sp;

    public:
        /// @name objects
        /// @copydoc 
        /// @{
        nkr_DEFINE_INHERITANCE_WRAPPER_CTORS_AND_DTOR(atomic_t, base_t);
        /// @}
    };

}
