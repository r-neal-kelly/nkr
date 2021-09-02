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

    }

}

namespace nkr { namespace os { namespace atomic {

    /// @name Access
    /// @copydoc _ebc609cf_5026_47e9_87e7_c8ea9ecc71a9
    /// @{
    template <boolean_tr atom_p>
    atom_p  Access(const volatile atom_p& atom);    ///< @copydoc _f108db58_8738_44fc_8660_a9f2806661f3
    template <integer_tr atom_p>
    atom_p  Access(const volatile atom_p& atom);    ///< @copydoc _483f958d_a7c0_4bad_9626_abec8c6bbe3d
    template <real_tr atom_p>
    atom_p  Access(const volatile atom_p& atom);    ///< @copydoc _21cc14ae_45f0_4855_84d4_42e7393be6b2
    template <pointer_tr atom_p>
    atom_p  Access(const volatile atom_p& atom);    ///< @copydoc _440abed9_9a06_4236_b1ae_3ef1e8960885
    /// @}
    
    /// @name Assign
    /// @copydoc _d42247f7_a7b1_442f_beef_c88857ee5682
    /// @{
    template <boolean_tr atom_p, convertible_tr<atom_p> value_p>
    atom_p  Assign(volatile atom_p& atom, value_p with);                ///< @copydoc _645a3b7d_7d4e_47c4_a1a7_c06bc5778bb4
    template <integer_tr atom_p, convertible_tr<atom_p> value_p>
    atom_p  Assign(volatile atom_p& atom, value_p with);                ///< @copydoc _6f92a7bd_b994_40e0_9602_4f8e9d4cb33c
    template <real_tr atom_p, convertible_tr<atom_p> value_p>
    atom_p  Assign(volatile atom_p& atom, value_p with);                ///< @copydoc _58358f73_b528_40f6_afea_c92e99ceacf5
    template <pointer_tr atom_p, convertible_tr<atom_p> value_p>
    atom_p  Assign(volatile atom_p& atom, value_p with);                ///< @copydoc _5be6c133_51a1_4505_9817_7ad90111f2c5

    template <integer_tr atom_p, convertible_tr<atom_p> value_p>
    atom_p  Assign_Add(volatile atom_p& atom, value_p with);            ///< @copydoc _ccdd9ac1_cec8_41f3_9cdd_c35c4bd0e5e3
    template <real_tr atom_p, convertible_tr<atom_p> value_p>
    atom_p  Assign_Add(volatile atom_p& atom, value_p with);            ///< @copydoc _56449aaf_1ec1_45b6_affe_5c9e52cb054b
    template <type_pointer_tr atom_p, integer_tr value_p>
    atom_p  Assign_Add(volatile atom_p& atom, value_p with);            ///< @copydoc _cbe72d03_f920_4d4d_a53c_68537d91e06e

    template <integer_tr atom_p, convertible_tr<atom_p> value_p>
    atom_p  Assign_Subtract(volatile atom_p& atom, value_p with);       ///< @copydoc _c47b944b_9b57_4e37_9f5c_6bfaaf2cfd3b
    template <real_tr atom_p, convertible_tr<atom_p> value_p>
    atom_p  Assign_Subtract(volatile atom_p& atom, value_p with);       ///< @copydoc _00e757d4_7f46_4c49_ab21_abe2c125f3a0
    template <type_pointer_tr atom_p, integer_tr value_p>
    atom_p  Assign_Subtract(volatile atom_p& atom, value_p with);       ///< @copydoc _165233f2_0ca5_45bf_9b4d_c09253b1700c

    template <integer_tr atom_p, convertible_tr<atom_p> value_p>
    atom_p  Assign_Multiply(volatile atom_p& atom, value_p with);       ///< @copydoc _0a5bb6e1_7810_42d0_9898_7f620006a6e5
    template <real_tr atom_p, convertible_tr<atom_p> value_p>
    atom_p  Assign_Multiply(volatile atom_p& atom, value_p with);       ///< @copydoc _57c963ce_3ec5_4e5a_b8ee_f86fa3a621aa

    template <integer_tr atom_p, convertible_tr<atom_p> value_p>
    atom_p  Assign_Divide(volatile atom_p& atom, value_p with);         ///< @copydoc _c3e4cffc_7761_480a_a537_89224911c230
    template <real_tr atom_p, convertible_tr<atom_p> value_p>
    atom_p  Assign_Divide(volatile atom_p& atom, value_p with);         ///< @copydoc _410d4ab2_a256_46fb_a3d1_81d5df42d754

    template <integer_tr atom_p, integer_tr value_p>
    atom_p  Assign_Modulus(volatile atom_p& atom, value_p with);        ///< @copydoc _ac58790f_ee6f_4a0b_a0ec_5dd0150ceec3

    template <integer_tr atom_p, integer_tr value_p>
    atom_p  Assign_Or(volatile atom_p& atom, value_p with);             ///< @copydoc _eec76f63_67cd_4ba6_bc4a_ab65768fa8b4

    template <integer_tr atom_p, integer_tr value_p>
    atom_p  Assign_And(volatile atom_p& atom, value_p with);            ///< @copydoc _5909da00_4e2f_4cdb_91af_2b8293db4cdf

    template <integer_tr atom_p, integer_tr value_p>
    atom_p  Assign_Xor(volatile atom_p& atom, value_p with);            ///< @copydoc _ce711298_5896_45dd_ba04_6814d9ef7a9f

    template <integer_tr atom_p, integer_tr value_p>
    atom_p  Assign_Left_Shift(volatile atom_p& atom, value_p with);     ///< @copydoc _18b2190d_5468_4bbd_8130_309a6012b2fe

    template <integer_tr atom_p, integer_tr value_p>
    atom_p  Assign_Right_Shift(volatile atom_p& atom, value_p with);    ///< @copydoc _086dff2e_9081_4674_8250_1a79c00517be
    /// @}
    
    /// @name Exchange
    /// @copydoc _73d8454a_28bc_4509_b695_6bd373d375f2
    /// @{
    template <boolean_tr atom_p, convertible_tr<atom_p> value_p>
    atom_p  Exchange(volatile atom_p& atom, value_p with);                              ///< @copydoc _009a1021_3a6f_4648_a80f_9522b995e3fb
    template <integer_8_tr atom_p, convertible_tr<atom_p> value_p>
    atom_p  Exchange(volatile atom_p& atom, value_p with);                              ///< @copydoc _2b361fda_4d67_4814_bc34_18174ce62931
    template <integer_16_tr atom_p, convertible_tr<atom_p> value_p>
    atom_p  Exchange(volatile atom_p& atom, value_p with);                              ///< @copydoc _d45e6db8_de88_4978_ba48_0ae8426c5e2e
    template <integer_32_tr atom_p, convertible_tr<atom_p> value_p>
    atom_p  Exchange(volatile atom_p& atom, value_p with);                              ///< @copydoc _f5f5a380_a53e_4d06_9616_03e50cac0eb9
    template <integer_64_tr atom_p, convertible_tr<atom_p> value_p>
    atom_p  Exchange(volatile atom_p& atom, value_p with);                              ///< @copydoc _85282c8e_2d62_422a_b627_44b00a14f62d
    template <real_32_tr atom_p, convertible_tr<atom_p> value_p>
    atom_p  Exchange(volatile atom_p& atom, value_p with);                              ///< @copydoc _c3e1ae09_ea1d_4180_8ade_03f55a2697de
    template <real_64_tr atom_p, convertible_tr<atom_p> value_p>
    atom_p  Exchange(volatile atom_p& atom, value_p with);                              ///< @copydoc _10dfb789_0e5e_4cf7_bbab_fa016d811d0f
    template <pointer_tr atom_p, convertible_tr<atom_p> value_p>
    atom_p  Exchange(volatile atom_p& atom, value_p with);                              ///< @copydoc _55307842_7fcf_4db9_bae9_7b6a5fe398c0

    template <integer_8_tr atom_p, convertible_tr<atom_p> value_p>
    atom_p  Exchange_Add(volatile atom_p& atom, value_p with);                          ///< @copydoc _90cc9495_1773_47e3_9adc_3043338299c6
    template <integer_16_tr atom_p, convertible_tr<atom_p> value_p>
    atom_p  Exchange_Add(volatile atom_p& atom, value_p with);                          ///< @copydoc _d176607d_46f2_4ff9_b6ad_33070618987c
    template <integer_32_tr atom_p, convertible_tr<atom_p> value_p>
    atom_p  Exchange_Add(volatile atom_p& atom, value_p with);                          ///< @copydoc _10f9260e_f689_443b_8670_e517d157aa0c
    template <integer_64_tr atom_p, convertible_tr<atom_p> value_p>
    atom_p  Exchange_Add(volatile atom_p& atom, value_p with);                          ///< @copydoc _c26197a1_d6b8_4e67_8a13_235c91e48f6e
    template <real_32_tr atom_p, convertible_tr<atom_p> value_p>
    atom_p  Exchange_Add(volatile atom_p& atom, value_p with);                          ///< @copydoc _3d5ff86d_f19b_4f2e_9aee_c26dfb6cc70c
    template <real_64_tr atom_p, convertible_tr<atom_p> value_p>
    atom_p  Exchange_Add(volatile atom_p& atom, value_p with);                          ///< @copydoc _e05e5c49_c9e5_4b2e_b6b7_78c1b162efae
    template <type_pointer_tr atom_p, integer_tr value_p>
    atom_p  Exchange_Add(volatile atom_p& atom, value_p with);                          ///< @copydoc _cc0888ae_0348_4464_8425_d59c2563a3b9

    template <integer_8_tr atom_p, convertible_tr<atom_p> value_p>
    atom_p  Exchange_Subtract(volatile atom_p& atom, value_p with);                     ///< @copydoc _e84e6359_fa11_4b0b_b41a_438749057a46
    template <integer_16_tr atom_p, convertible_tr<atom_p> value_p>
    atom_p  Exchange_Subtract(volatile atom_p& atom, value_p with);                     ///< @copydoc _3b55c955_7c4e_4b27_9678_c5397933d8a2
    template <integer_32_tr atom_p, convertible_tr<atom_p> value_p>
    atom_p  Exchange_Subtract(volatile atom_p& atom, value_p with);                     ///< @copydoc _3a8e59a8_1d32_40aa_b053_f1b24faad6be
    template <integer_64_tr atom_p, convertible_tr<atom_p> value_p>
    atom_p  Exchange_Subtract(volatile atom_p& atom, value_p with);                     ///< @copydoc _d1d7f54b_5e04_4efb_a29b_5443a9dde40e
    template <real_32_tr atom_p, convertible_tr<atom_p> value_p>
    atom_p  Exchange_Subtract(volatile atom_p& atom, value_p with);                     ///< @copydoc _8d728a53_9ae5_4021_afc3_f7eddc191837
    template <real_64_tr atom_p, convertible_tr<atom_p> value_p>
    atom_p  Exchange_Subtract(volatile atom_p& atom, value_p with);                     ///< @copydoc _fa5d91a7_6a85_4a90_b53e_13979f43e7e3
    template <type_pointer_tr atom_p, integer_tr value_p>
    atom_p  Exchange_Subtract(volatile atom_p& atom, value_p with);                     ///< @copydoc _4160b14b_f8e3_4e5b_8340_b8e9285d1caa

    template <integer_8_tr atom_p, convertible_tr<atom_p> value_p>
    atom_p  Exchange_Multiply(volatile atom_p& atom, value_p with);                     ///< @copydoc _d1abee16_9935_4078_8cac_b87fd83c0ca7
    template <integer_16_tr atom_p, convertible_tr<atom_p> value_p>
    atom_p  Exchange_Multiply(volatile atom_p& atom, value_p with);                     ///< @copydoc _37bb69e1_23a5_4e0d_a69a_194ea23ab3ee
    template <integer_32_tr atom_p, convertible_tr<atom_p> value_p>
    atom_p  Exchange_Multiply(volatile atom_p& atom, value_p with);                     ///< @copydoc _e7fbb898_298e_4cf1_81bb_fd131cbf7fde
    template <integer_64_tr atom_p, convertible_tr<atom_p> value_p>
    atom_p  Exchange_Multiply(volatile atom_p& atom, value_p with);                     ///< @copydoc _7ef23b38_fb34_49fb_9f0d_2b8cb3d467e7
    template <real_32_tr atom_p, convertible_tr<atom_p> value_p>
    atom_p  Exchange_Multiply(volatile atom_p& atom, value_p with);                     ///< @copydoc _67c3f25b_3381_4848_8aef_831f33b031ec
    template <real_64_tr atom_p, convertible_tr<atom_p> value_p>
    atom_p  Exchange_Multiply(volatile atom_p& atom, value_p with);                     ///< @copydoc _89e821f5_52eb_4658_ab7c_a39e3ff2ec98

    template <integer_8_tr atom_p, convertible_tr<atom_p> value_p>
    atom_p  Exchange_Divide(volatile atom_p& atom, value_p with);                       ///< @copydoc _f65078b9_2799_401c_a104_b3ec26a48442
    template <integer_16_tr atom_p, convertible_tr<atom_p> value_p>
    atom_p  Exchange_Divide(volatile atom_p& atom, value_p with);                       ///< @copydoc _4e3628fa_d048_443a_9ed5_51b90a3b8a9d
    template <integer_32_tr atom_p, convertible_tr<atom_p> value_p>
    atom_p  Exchange_Divide(volatile atom_p& atom, value_p with);                       ///< @copydoc _79ece834_7894_4526_befe_fde94d06dae1
    template <integer_64_tr atom_p, convertible_tr<atom_p> value_p>
    atom_p  Exchange_Divide(volatile atom_p& atom, value_p with);                       ///< @copydoc _cea69ea3_c8e8_480a_98ee_fe3873553add
    template <real_32_tr atom_p, convertible_tr<atom_p> value_p>
    atom_p  Exchange_Divide(volatile atom_p& atom, value_p with);                       ///< @copydoc _c0da5851_8733_4691_a50d_af820ca8299f
    template <real_64_tr atom_p, convertible_tr<atom_p> value_p>
    atom_p  Exchange_Divide(volatile atom_p& atom, value_p with);                       ///< @copydoc _3b59e0d7_49ad_4e48_abbe_b493eeb2d453

    template <integer_8_tr atom_p, integer_tr value_p>
    atom_p  Exchange_Modulus(volatile atom_p& atom, value_p with);                      ///< @copydoc _500b91ce_f331_40cb_adba_d584104f996a
    template <integer_16_tr atom_p, integer_tr value_p>
    atom_p  Exchange_Modulus(volatile atom_p& atom, value_p with);                      ///< @copydoc _5a348d64_b4f5_4073_96ba_7b00c95ccfbb
    template <integer_32_tr atom_p, integer_tr value_p>
    atom_p  Exchange_Modulus(volatile atom_p& atom, value_p with);                      ///< @copydoc _95d9f9f8_c6a9_4e14_bfab_404e91ac833c
    template <integer_64_tr atom_p, integer_tr value_p>
    atom_p  Exchange_Modulus(volatile atom_p& atom, value_p with);                      ///< @copydoc _0830419d_cd3a_4dae_867a_5becf02985a0

    template <integer_8_tr atom_p, integer_tr value_p>
    atom_p  Exchange_Or(volatile atom_p& atom, value_p with);                           ///< @copydoc _80a5ea1d_312a_4ac3_b376_51430f5aa6d8
    template <integer_16_tr atom_p, integer_tr value_p>
    atom_p  Exchange_Or(volatile atom_p& atom, value_p with);                           ///< @copydoc _411912ba_8497_4fb3_b779_3c5f086e838b
    template <integer_32_tr atom_p, integer_tr value_p>
    atom_p  Exchange_Or(volatile atom_p& atom, value_p with);                           ///< @copydoc _5d26a69b_6892_46aa_843a_ff6022bdac14
    template <integer_64_tr atom_p, integer_tr value_p>
    atom_p  Exchange_Or(volatile atom_p& atom, value_p with);                           ///< @copydoc _f12c18ab_957d_4403_b27c_a611c9556e44

    template <integer_8_tr atom_p, integer_tr value_p>
    atom_p  Exchange_And(volatile atom_p& atom, value_p with);                          ///< @copydoc _c446d7c8_d702_42b5_8039_019f8c3f2ab2
    template <integer_16_tr atom_p, integer_tr value_p>
    atom_p  Exchange_And(volatile atom_p& atom, value_p with);                          ///< @copydoc _ed1566c9_1802_4542_9361_554abd50b4eb
    template <integer_32_tr atom_p, integer_tr value_p>
    atom_p  Exchange_And(volatile atom_p& atom, value_p with);                          ///< @copydoc _ed83d819_9b39_459a_b9d3_5d9195ce9fda
    template <integer_64_tr atom_p, integer_tr value_p>
    atom_p  Exchange_And(volatile atom_p& atom, value_p with);                          ///< @copydoc _48c953c9_bf1a_4370_85c3_ee16276cff88

    template <integer_8_tr atom_p, integer_tr value_p>
    atom_p  Exchange_Xor(volatile atom_p& atom, value_p with);                          ///< @copydoc _c1790859_bff8_4a23_bee6_ee89467b4e33
    template <integer_16_tr atom_p, integer_tr value_p>
    atom_p  Exchange_Xor(volatile atom_p& atom, value_p with);                          ///< @copydoc _8b7a9669_ad61_40f2_a489_adc47ec4bce3
    template <integer_32_tr atom_p, integer_tr value_p>
    atom_p  Exchange_Xor(volatile atom_p& atom, value_p with);                          ///< @copydoc _9d8f873f_79a5_408b_a222_02d094780da3
    template <integer_64_tr atom_p, integer_tr value_p>
    atom_p  Exchange_Xor(volatile atom_p& atom, value_p with);                          ///< @copydoc _57265bb5_d63d_4413_9a9a_85929455b121
    
    template <integer_8_tr atom_p, integer_tr value_p>
    atom_p  Exchange_Left_Shift(volatile atom_p& atom, value_p with);                   ///< @copydoc _ff2fa1a3_d455_4961_8f62_7b7b49fae349
    template <integer_16_tr atom_p, integer_tr value_p>
    atom_p  Exchange_Left_Shift(volatile atom_p& atom, value_p with);                   ///< @copydoc _d3f0c9e2_dffc_4e4a_9646_34c4f87f9e67
    template <integer_32_tr atom_p, integer_tr value_p>
    atom_p  Exchange_Left_Shift(volatile atom_p& atom, value_p with);                   ///< @copydoc _fdc94a39_e761_4163_bec4_3bf4a5042d24
    template <integer_64_tr atom_p, integer_tr value_p>
    atom_p  Exchange_Left_Shift(volatile atom_p& atom, value_p with);                   ///< @copydoc _a80396ed_f0de_43cf_90a5_4c873d2d3634

    template <integer_8_tr atom_p, integer_tr value_p>
    atom_p  Exchange_Right_Shift(volatile atom_p& atom, value_p with);                  ///< @copydoc _765569a5_fc51_4965_862f_1f575f9da279
    template <integer_16_tr atom_p, integer_tr value_p>
    atom_p  Exchange_Right_Shift(volatile atom_p& atom, value_p with);                  ///< @copydoc _38af98a8_dc0f_45b6_9a69_35b391ba9ac3
    template <integer_32_tr atom_p, integer_tr value_p>
    atom_p  Exchange_Right_Shift(volatile atom_p& atom, value_p with);                  ///< @copydoc _d4f5dc80_6146_4d2f_a145_eb4b46c2bf9c
    template <integer_64_tr atom_p, integer_tr value_p>
    atom_p  Exchange_Right_Shift(volatile atom_p& atom, value_p with);                  ///< @copydoc _629b3d0b_4519_46f4_83c8_7b8512e75580

    template <boolean_tr atom_p, convertible_tr<atom_p> value_p>
    bool_t  Exchange_If_Equals(volatile atom_p& atom, atom_p& snapshot, value_p with);  ///< @copydoc _94d5bd96_1eac_4fc5_b933_46e1ad384e3e
    template <integer_8_tr atom_p, convertible_tr<atom_p> value_p>
    bool_t  Exchange_If_Equals(volatile atom_p& atom, atom_p& snapshot, value_p with);  ///< @copydoc _a7202b5d_807f_48f5_bd33_eda99d40bed7
    template <integer_16_tr atom_p, convertible_tr<atom_p> value_p>
    bool_t  Exchange_If_Equals(volatile atom_p& atom, atom_p& snapshot, value_p with);  ///< @copydoc _3ac8b80b_0d2b_46e2_9800_b14383eeb9a6
    template <integer_32_tr atom_p, convertible_tr<atom_p> value_p>
    bool_t  Exchange_If_Equals(volatile atom_p& atom, atom_p& snapshot, value_p with);  ///< @copydoc _53d6f485_5987_4ecf_9422_92912eec2709
    template <integer_64_tr atom_p, convertible_tr<atom_p> value_p>
    bool_t  Exchange_If_Equals(volatile atom_p& atom, atom_p& snapshot, value_p with);  ///< @copydoc _745d8457_f0d1_4e79_a5a6_9014206c41c2
    template <real_32_tr atom_p, convertible_tr<atom_p> value_p>
    bool_t  Exchange_If_Equals(volatile atom_p& atom, atom_p& snapshot, value_p with);  ///< @copydoc _d0f2c440_7414_4a14_b280_88fc0da4b8c6
    template <real_64_tr atom_p, convertible_tr<atom_p> value_p>
    bool_t  Exchange_If_Equals(volatile atom_p& atom, atom_p& snapshot, value_p with);  ///< @copydoc _78557f24_7a3b_48e5_a010_7af0eb4ccb51
    template <pointer_tr atom_p, convertible_tr<atom_p> value_p>
    bool_t  Exchange_If_Equals(volatile atom_p& atom, atom_p& snapshot, value_p with);  ///< @copydoc _45614630_d644_4318_96c7_fc5ccefd6675
    /// @}

}}}

namespace nkr { namespace os { namespace endian {

    /// @name Info
    /// @copydoc _026b191f_2e76_4010_9760_e1215a647d9c
    /// @{
    bool_t  Is_Big();       ///< @copydoc _9d5ef4e6_ff8f_4d63_9fdc_0c0422259d90
    bool_t  Is_Little();    ///< @copydoc _884ae9eb_da64_4306_aab9_50aeb3f85298
    /// @}

    /// @name Swap
    /// @copydoc _b5b179fb_1f64_485e_9510_80260e3a6c33
    /// @{
    integer_16_tr auto  Swap(integer_16_tr auto bytes); ///< @copydoc _857ce8b6_02ca_48e5_9d19_4a7581b8e4c6
    integer_32_tr auto  Swap(integer_32_tr auto bytes); ///< @copydoc _02c0499c_c8c8_43b9_8afc_96545310eb3a
    integer_64_tr auto  Swap(integer_64_tr auto bytes); ///< @copydoc _eabf9a88_080f_445d_88ab_b0dae4a55316
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

#include "nkr/os.inl"
