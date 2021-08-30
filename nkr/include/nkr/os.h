/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

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
    boolean_tr auto         Access(const volatile boolean_tr auto& atom);                                       ///< @copydoc _f108db58_8738_44fc_8660_a9f2806661f3
    integer_tr auto         Access(const volatile integer_tr auto& atom);                                       ///< @copydoc _483f958d_a7c0_4bad_9626_abec8c6bbe3d
    float_tr auto           Access(const volatile float_tr auto& atom);                                         ///< @copydoc _21cc14ae_45f0_4855_84d4_42e7393be6b2
    pointer_tr auto         Access(const volatile pointer_tr auto& atom);                                       ///< @copydoc _440abed9_9a06_4236_b1ae_3ef1e8960885

    integer_tr auto         Access_Add(const volatile integer_tr auto& atom, to_integer_tr auto with);          ///< @copydoc _a8afe657_40ce_4947_b12a_e64fff9a75f3
    float_tr auto           Access_Add(const volatile float_tr auto& atom, to_float_tr auto with);              ///< @copydoc _2dbe104d_074e_4b0f_9881_92f5904668c1
    type_pointer_tr auto    Access_Add(const volatile type_pointer_tr auto& atom, integer_tr auto with);        ///< @copydoc _a9743336_7a5f_43c1_9a78_2269868e56c6

    integer_tr auto         Access_Subtract(const volatile integer_tr auto& atom, to_integer_tr auto with);     ///< @copydoc _ba08ae59_7317_41d8_9218_3dcb7e560408
    float_tr auto           Access_Subtract(const volatile float_tr auto& atom, to_float_tr auto with);         ///< @copydoc _20004723_e811_4a0e_b0f4_200ce9abb23b
    type_pointer_tr auto    Access_Subtract(const volatile type_pointer_tr auto& atom, integer_tr auto with);   ///< @copydoc _6dd5e90f_7f13_4a99_a2c4_acc32ba11b47

    integer_tr auto         Access_Multiply(const volatile integer_tr auto& atom, to_integer_tr auto with);     ///< @copydoc _9bb44e8b_b3ef_4481_bb6a_ccdb5f0ac9f9
    float_tr auto           Access_Multiply(const volatile float_tr auto& atom, to_float_tr auto with);         ///< @copydoc _4f2854a6_8748_464a_b349_27cc7c6b75bb

    integer_tr auto         Access_Divide(const volatile integer_tr auto& atom, to_integer_tr auto with);       ///< @copydoc _12a09817_5dae_440b_99d5_ed0bbe5cc3b7
    float_tr auto           Access_Divide(const volatile float_tr auto& atom, to_float_tr auto with);           ///< @copydoc _af12bfd4_f332_402e_966e_fae3d1def171

    integer_tr auto         Access_Modulus(const volatile integer_tr auto& atom, integer_tr auto with);         ///< @copydoc _3bba7a36_b47d_4132_8268_38d9f8072569

    integer_tr auto         Access_Or(const volatile integer_tr auto& atom, integer_tr auto with);              ///< @copydoc _6d0f786a_e25a_4bc6_ada7_2f228cf08769

    integer_tr auto         Access_And(const volatile integer_tr auto& atom, integer_tr auto with);             ///< @copydoc _7c5f2ff1_b767_4edd_949b_1c0d8929a1bb

    integer_tr auto         Access_Xor(const volatile integer_tr auto& atom, integer_tr auto with);             ///< @copydoc _a58b5b46_c958_4ffd_8293_acd1692c4f31

    integer_tr auto         Access_Left_Shift(const volatile integer_tr auto& atom, integer_tr auto with);      ///< @copydoc _c41a95ae_b038_496d_84d4_1204b9b9d869

    integer_tr auto         Access_Right_Shift(const volatile integer_tr auto& atom, integer_tr auto with);     ///< @copydoc _c3f8d30f_5d9d_4c85_af2f_3ea8dbdd1691
    /// @}

    /// @name Assign
    /// @copydoc _d42247f7_a7b1_442f_beef_c88857ee5682
    /// @{
    boolean_tr auto         Assign(volatile boolean_tr auto& atom, boolean_tr auto with);               ///< @copydoc _645a3b7d_7d4e_47c4_a1a7_c06bc5778bb4
    integer_tr auto         Assign(volatile integer_tr auto& atom, to_integer_tr auto with);            ///< @copydoc _6f92a7bd_b994_40e0_9602_4f8e9d4cb33c
    float_tr auto           Assign(volatile float_tr auto& atom, to_float_tr auto with);                ///< @copydoc _58358f73_b528_40f6_afea_c92e99ceacf5
    pointer_tr auto         Assign(volatile pointer_tr auto& atom, pointer_tr auto with);               ///< @copydoc _5be6c133_51a1_4505_9817_7ad90111f2c5

    integer_tr auto         Assign_Add(volatile integer_tr auto& atom, to_integer_tr auto with);        ///< @copydoc _ccdd9ac1_cec8_41f3_9cdd_c35c4bd0e5e3
    float_tr auto           Assign_Add(volatile float_tr auto& atom, to_float_tr auto with);            ///< @copydoc _56449aaf_1ec1_45b6_affe_5c9e52cb054b
    type_pointer_tr auto    Assign_Add(volatile type_pointer_tr auto& atom, integer_tr auto with);      ///< @copydoc _cbe72d03_f920_4d4d_a53c_68537d91e06e

    integer_tr auto         Assign_Subtract(volatile integer_tr auto& atom, to_integer_tr auto with);   ///< @copydoc _c47b944b_9b57_4e37_9f5c_6bfaaf2cfd3b
    float_tr auto           Assign_Subtract(volatile float_tr auto& atom, to_float_tr auto with);       ///< @copydoc _00e757d4_7f46_4c49_ab21_abe2c125f3a0
    type_pointer_tr auto    Assign_Subtract(volatile type_pointer_tr auto& atom, integer_tr auto with); ///< @copydoc _165233f2_0ca5_45bf_9b4d_c09253b1700c

    integer_tr auto         Assign_Multiply(volatile integer_tr auto& atom, to_integer_tr auto with);   ///< @copydoc _0a5bb6e1_7810_42d0_9898_7f620006a6e5
    float_tr auto           Assign_Multiply(volatile float_tr auto& atom, to_float_tr auto with);       ///< @copydoc _57c963ce_3ec5_4e5a_b8ee_f86fa3a621aa

    integer_tr auto         Assign_Divide(volatile integer_tr auto& atom, to_integer_tr auto with);     ///< @copydoc _c3e4cffc_7761_480a_a537_89224911c230
    float_tr auto           Assign_Divide(volatile float_tr auto& atom, to_float_tr auto with);         ///< @copydoc _410d4ab2_a256_46fb_a3d1_81d5df42d754

    integer_tr auto         Assign_Modulus(volatile integer_tr auto& atom, integer_tr auto with);       ///< @copydoc _ac58790f_ee6f_4a0b_a0ec_5dd0150ceec3

    integer_tr auto         Assign_Or(volatile integer_tr auto& atom, integer_tr auto with);            ///< @copydoc _eec76f63_67cd_4ba6_bc4a_ab65768fa8b4

    integer_tr auto         Assign_And(volatile integer_tr auto& atom, integer_tr auto with);           ///< @copydoc _5909da00_4e2f_4cdb_91af_2b8293db4cdf

    integer_tr auto         Assign_Xor(volatile integer_tr auto& atom, integer_tr auto with);           ///< @copydoc _ce711298_5896_45dd_ba04_6814d9ef7a9f

    integer_tr auto         Assign_Left_Shift(volatile integer_tr auto& atom, integer_tr auto with);    ///< @copydoc _18b2190d_5468_4bbd_8130_309a6012b2fe

    integer_tr auto         Assign_Right_Shift(volatile integer_tr auto& atom, integer_tr auto with);   ///< @copydoc _086dff2e_9081_4674_8250_1a79c00517be
    /// @}
    
    /// @name Exchange
    /// @copydoc _73d8454a_28bc_4509_b695_6bd373d375f2
    /// @{
    boolean_tr auto         Exchange(volatile boolean_tr auto& atom, boolean_tr auto with);                                                 ///< @copydoc _009a1021_3a6f_4648_a80f_9522b995e3fb
    integer_8_tr auto       Exchange(volatile integer_8_tr auto& atom, to_integer_tr auto with);                                            ///< @copydoc _2b361fda_4d67_4814_bc34_18174ce62931
    integer_16_tr auto      Exchange(volatile integer_16_tr auto& atom, to_integer_tr auto with);                                           ///< @copydoc _d45e6db8_de88_4978_ba48_0ae8426c5e2e
    integer_32_tr auto      Exchange(volatile integer_32_tr auto& atom, to_integer_tr auto with);                                           ///< @copydoc _f5f5a380_a53e_4d06_9616_03e50cac0eb9
    integer_64_tr auto      Exchange(volatile integer_64_tr auto& atom, to_integer_tr auto with);                                           ///< @copydoc _85282c8e_2d62_422a_b627_44b00a14f62d
    float_32_tr auto        Exchange(volatile float_32_tr auto& atom, to_float_tr auto with);                                               ///< @copydoc _c3e1ae09_ea1d_4180_8ade_03f55a2697de
    float_64_tr auto        Exchange(volatile float_64_tr auto& atom, to_float_tr auto with);                                               ///< @copydoc _10dfb789_0e5e_4cf7_bbab_fa016d811d0f
    pointer_tr auto         Exchange(volatile pointer_tr auto& atom, pointer_tr auto with);                                                 ///< @copydoc _55307842_7fcf_4db9_bae9_7b6a5fe398c0

    integer_8_tr auto       Exchange_Add(volatile integer_8_tr auto& atom, to_integer_tr auto with);                                        ///< @copydoc _90cc9495_1773_47e3_9adc_3043338299c6
    integer_16_tr auto      Exchange_Add(volatile integer_16_tr auto& atom, to_integer_tr auto with);                                       ///< @copydoc _d176607d_46f2_4ff9_b6ad_33070618987c
    integer_32_tr auto      Exchange_Add(volatile integer_32_tr auto& atom, to_integer_tr auto with);                                       ///< @copydoc _10f9260e_f689_443b_8670_e517d157aa0c
    integer_64_tr auto      Exchange_Add(volatile integer_64_tr auto& atom, to_integer_tr auto with);                                       ///< @copydoc _c26197a1_d6b8_4e67_8a13_235c91e48f6e
    float_32_tr auto        Exchange_Add(volatile float_32_tr auto& atom, to_float_tr auto with);                                           ///< @copydoc _3d5ff86d_f19b_4f2e_9aee_c26dfb6cc70c
    float_64_tr auto        Exchange_Add(volatile float_64_tr auto& atom, to_float_tr auto with);                                           ///< @copydoc _e05e5c49_c9e5_4b2e_b6b7_78c1b162efae
    type_pointer_tr auto    Exchange_Add(volatile type_pointer_tr auto& atom, integer_tr auto with);                                        ///< @copydoc _cc0888ae_0348_4464_8425_d59c2563a3b9

    integer_8_tr auto       Exchange_Subtract(volatile integer_8_tr auto& atom, to_integer_tr auto with);                                   ///< @copydoc _e84e6359_fa11_4b0b_b41a_438749057a46
    integer_16_tr auto      Exchange_Subtract(volatile integer_16_tr auto& atom, to_integer_tr auto with);                                  ///< @copydoc _3b55c955_7c4e_4b27_9678_c5397933d8a2
    integer_32_tr auto      Exchange_Subtract(volatile integer_32_tr auto& atom, to_integer_tr auto with);                                  ///< @copydoc _3a8e59a8_1d32_40aa_b053_f1b24faad6be
    integer_64_tr auto      Exchange_Subtract(volatile integer_64_tr auto& atom, to_integer_tr auto with);                                  ///< @copydoc _d1d7f54b_5e04_4efb_a29b_5443a9dde40e
    float_32_tr auto        Exchange_Subtract(volatile float_32_tr auto& atom, to_float_tr auto with);                                      ///< @copydoc _8d728a53_9ae5_4021_afc3_f7eddc191837
    float_64_tr auto        Exchange_Subtract(volatile float_64_tr auto& atom, to_float_tr auto with);                                      ///< @copydoc _fa5d91a7_6a85_4a90_b53e_13979f43e7e3
    type_pointer_tr auto    Exchange_Subtract(volatile type_pointer_tr auto& atom, integer_tr auto with);                                   ///< @copydoc _4160b14b_f8e3_4e5b_8340_b8e9285d1caa

    integer_8_tr auto       Exchange_Multiply(volatile integer_8_tr auto& atom, to_integer_tr auto with);                                   ///< @copydoc _d1abee16_9935_4078_8cac_b87fd83c0ca7
    integer_16_tr auto      Exchange_Multiply(volatile integer_16_tr auto& atom, to_integer_tr auto with);                                  ///< @copydoc _37bb69e1_23a5_4e0d_a69a_194ea23ab3ee
    integer_32_tr auto      Exchange_Multiply(volatile integer_32_tr auto& atom, to_integer_tr auto with);                                  ///< @copydoc _e7fbb898_298e_4cf1_81bb_fd131cbf7fde
    integer_64_tr auto      Exchange_Multiply(volatile integer_64_tr auto& atom, to_integer_tr auto with);                                  ///< @copydoc _7ef23b38_fb34_49fb_9f0d_2b8cb3d467e7
    float_32_tr auto        Exchange_Multiply(volatile float_32_tr auto& atom, to_float_tr auto with);                                      ///< @copydoc _67c3f25b_3381_4848_8aef_831f33b031ec
    float_64_tr auto        Exchange_Multiply(volatile float_64_tr auto& atom, to_float_tr auto with);                                      ///< @copydoc _89e821f5_52eb_4658_ab7c_a39e3ff2ec98

    integer_8_tr auto       Exchange_Divide(volatile integer_8_tr auto& atom, to_integer_tr auto with);                                     ///< @copydoc _f65078b9_2799_401c_a104_b3ec26a48442
    integer_16_tr auto      Exchange_Divide(volatile integer_16_tr auto& atom, to_integer_tr auto with);                                    ///< @copydoc _4e3628fa_d048_443a_9ed5_51b90a3b8a9d
    integer_32_tr auto      Exchange_Divide(volatile integer_32_tr auto& atom, to_integer_tr auto with);                                    ///< @copydoc _79ece834_7894_4526_befe_fde94d06dae1
    integer_64_tr auto      Exchange_Divide(volatile integer_64_tr auto& atom, to_integer_tr auto with);                                    ///< @copydoc _cea69ea3_c8e8_480a_98ee_fe3873553add
    float_32_tr auto        Exchange_Divide(volatile float_32_tr auto& atom, to_float_tr auto with);                                        ///< @copydoc _c0da5851_8733_4691_a50d_af820ca8299f
    float_64_tr auto        Exchange_Divide(volatile float_64_tr auto& atom, to_float_tr auto with);                                        ///< @copydoc _3b59e0d7_49ad_4e48_abbe_b493eeb2d453

    integer_8_tr auto       Exchange_Modulus(volatile integer_8_tr auto& atom, integer_tr auto with);                                       ///< @copydoc _500b91ce_f331_40cb_adba_d584104f996a
    integer_16_tr auto      Exchange_Modulus(volatile integer_16_tr auto& atom, integer_tr auto with);                                      ///< @copydoc _5a348d64_b4f5_4073_96ba_7b00c95ccfbb
    integer_32_tr auto      Exchange_Modulus(volatile integer_32_tr auto& atom, integer_tr auto with);                                      ///< @copydoc _95d9f9f8_c6a9_4e14_bfab_404e91ac833c
    integer_64_tr auto      Exchange_Modulus(volatile integer_64_tr auto& atom, integer_tr auto with);                                      ///< @copydoc _0830419d_cd3a_4dae_867a_5becf02985a0

    integer_8_tr auto       Exchange_Or(volatile integer_8_tr auto& atom, integer_tr auto with);                                            ///< @copydoc _80a5ea1d_312a_4ac3_b376_51430f5aa6d8
    integer_16_tr auto      Exchange_Or(volatile integer_16_tr auto& atom, integer_tr auto with);                                           ///< @copydoc _411912ba_8497_4fb3_b779_3c5f086e838b
    integer_32_tr auto      Exchange_Or(volatile integer_32_tr auto& atom, integer_tr auto with);                                           ///< @copydoc _5d26a69b_6892_46aa_843a_ff6022bdac14
    integer_64_tr auto      Exchange_Or(volatile integer_64_tr auto& atom, integer_tr auto with);                                           ///< @copydoc _f12c18ab_957d_4403_b27c_a611c9556e44

    integer_8_tr auto       Exchange_And(volatile integer_8_tr auto& atom, integer_tr auto with);                                           ///< @copydoc _c446d7c8_d702_42b5_8039_019f8c3f2ab2
    integer_16_tr auto      Exchange_And(volatile integer_16_tr auto& atom, integer_tr auto with);                                          ///< @copydoc _ed1566c9_1802_4542_9361_554abd50b4eb
    integer_32_tr auto      Exchange_And(volatile integer_32_tr auto& atom, integer_tr auto with);                                          ///< @copydoc _ed83d819_9b39_459a_b9d3_5d9195ce9fda
    integer_64_tr auto      Exchange_And(volatile integer_64_tr auto& atom, integer_tr auto with);                                          ///< @copydoc _48c953c9_bf1a_4370_85c3_ee16276cff88

    integer_8_tr auto       Exchange_Xor(volatile integer_8_tr auto& atom, integer_tr auto with);                                           ///< @copydoc _c1790859_bff8_4a23_bee6_ee89467b4e33
    integer_16_tr auto      Exchange_Xor(volatile integer_16_tr auto& atom, integer_tr auto with);                                          ///< @copydoc _8b7a9669_ad61_40f2_a489_adc47ec4bce3
    integer_32_tr auto      Exchange_Xor(volatile integer_32_tr auto& atom, integer_tr auto with);                                          ///< @copydoc _9d8f873f_79a5_408b_a222_02d094780da3
    integer_64_tr auto      Exchange_Xor(volatile integer_64_tr auto& atom, integer_tr auto with);                                          ///< @copydoc _57265bb5_d63d_4413_9a9a_85929455b121
    
    integer_8_tr auto       Exchange_Left_Shift(volatile integer_8_tr auto& atom, integer_tr auto with);                                    ///< @copydoc _ff2fa1a3_d455_4961_8f62_7b7b49fae349
    integer_16_tr auto      Exchange_Left_Shift(volatile integer_16_tr auto& atom, integer_tr auto with);                                   ///< @copydoc _d3f0c9e2_dffc_4e4a_9646_34c4f87f9e67
    integer_32_tr auto      Exchange_Left_Shift(volatile integer_32_tr auto& atom, integer_tr auto with);                                   ///< @copydoc _fdc94a39_e761_4163_bec4_3bf4a5042d24
    integer_64_tr auto      Exchange_Left_Shift(volatile integer_64_tr auto& atom, integer_tr auto with);                                   ///< @copydoc _a80396ed_f0de_43cf_90a5_4c873d2d3634

    integer_8_tr auto       Exchange_Right_Shift(volatile integer_8_tr auto& atom, integer_tr auto with);                                   ///< @copydoc _765569a5_fc51_4965_862f_1f575f9da279
    integer_16_tr auto      Exchange_Right_Shift(volatile integer_16_tr auto& atom, integer_tr auto with);                                  ///< @copydoc _38af98a8_dc0f_45b6_9a69_35b391ba9ac3
    integer_32_tr auto      Exchange_Right_Shift(volatile integer_32_tr auto& atom, integer_tr auto with);                                  ///< @copydoc _d4f5dc80_6146_4d2f_a145_eb4b46c2bf9c
    integer_64_tr auto      Exchange_Right_Shift(volatile integer_64_tr auto& atom, integer_tr auto with);                                  ///< @copydoc _629b3d0b_4519_46f4_83c8_7b8512e75580

    boolean_tr auto         Exchange_If_Equals(volatile boolean_tr auto& atom, boolean_tr auto& snapshot, boolean_tr auto with);            ///< @copydoc _94d5bd96_1eac_4fc5_b933_46e1ad384e3e
    boolean_tr auto         Exchange_If_Equals(volatile integer_8_tr auto& atom, integer_8_tr auto& snapshot, to_integer_tr auto with);     ///< @copydoc _a7202b5d_807f_48f5_bd33_eda99d40bed7
    boolean_tr auto         Exchange_If_Equals(volatile integer_16_tr auto& atom, integer_16_tr auto& snapshot, to_integer_tr auto with);   ///< @copydoc _3ac8b80b_0d2b_46e2_9800_b14383eeb9a6
    boolean_tr auto         Exchange_If_Equals(volatile integer_32_tr auto& atom, integer_32_tr auto& snapshot, to_integer_tr auto with);   ///< @copydoc _53d6f485_5987_4ecf_9422_92912eec2709
    boolean_tr auto         Exchange_If_Equals(volatile integer_64_tr auto& atom, integer_64_tr auto& snapshot, to_integer_tr auto with);   ///< @copydoc _745d8457_f0d1_4e79_a5a6_9014206c41c2
    boolean_tr auto         Exchange_If_Equals(volatile float_32_tr auto& atom, float_32_tr auto& snapshot, to_float_tr auto with);         ///< @copydoc _d0f2c440_7414_4a14_b280_88fc0da4b8c6
    boolean_tr auto         Exchange_If_Equals(volatile float_64_tr auto& atom, float_64_tr auto& snapshot, to_float_tr auto with);         ///< @copydoc _78557f24_7a3b_48e5_a010_7af0eb4ccb51
    boolean_tr auto         Exchange_If_Equals(volatile pointer_tr auto& atom, pointer_tr auto& snapshot, pointer_tr auto with);            ///< @copydoc _45614630_d644_4318_96c7_fc5ccefd6675
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
