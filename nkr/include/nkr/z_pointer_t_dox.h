/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

/////////////////////////////////////////////////////////////////////////////// Notes
// Unit Functionality
/**
* @class _0dbc7113_d4d4_4ec8_bb81_53f931e49943
* @private
*
* @note
*   This is a convenience for when you want to treat the pointer_t as if it is a pointer to a single unit. Underneath the hood, there is no difference as it's merely a syntactical option.
*
* @par
*/

// Units Functionality
/**
* @class _4f00c181_94ec_49b5_a488_dd4de436e58d
* @private
* 
* @note
*   This is a convenience for when you want to treat the pointer_t as if it is a pointer to an array of units. Underneath the hood, there is no difference as it's merely a syntactical option.
* 
* @par
*/

// Does not deallocate
/**
* @class _63ccc436_1f2c_47a9_aa3e_86a9ca48b06b
* @private
* 
* @note
*   This will not deallocate the pointer. If the pointer needs to be deallocated it must be done before it is destroyed.
* 
* @par
*/

/////////////////////////////////////////////////////////////////////////////// Shared Briefs
// defaulting
/**
* @class _698817e2_16a3_4c95_aa40_32b4ad798fd5
* @private
* 
* @brief
*   Pointer is set to nullptr and unit count to zero.
*/

// copy assignment
/**
* @class _d1335627_f8fc_4621_81bf_9a74aba072e6
* @private
* 
* @brief
*   Copies other pointer without changing it.
*/

// move assignment
/**
* @class _d3785193_ba05_4807_9ca4_e02ecd3d2276
* @private
* 
* @brief
*   Moves the other pointer and leaves it with nullptr and a unit count of zero.
*/

/////////////////////////////////////////////////////////////////////////////// Shared Docs
// unit_t
/**
* @class _91f3b401_936a_4163_9c83_cefc3f28a167
* @private
*
* @brief
*   The type of the underlying data that the pointer points to.
*/

// units_t
/**
* @class _2f9a1113_dd23_4073_9637_5d0accc99f52
* @private
*
* @brief
*   The type of the raw underlying pointer.
*/

// Comparison
/**
* @class _1d33c46b_90b6_4519_aca0_c045fef8e3ec
* @private
* 
* @brief
*   Allows any `unqualified`, `const`, `volatile`, and/or `const volatile` object to be compared to any other.
*/

// default_ctor()
/**
* @class _7ffbe668_7434_4c6d_b056_d98c27149da9
* @private
* 
* @copydoc _698817e2_16a3_4c95_aa40_32b4ad798fd5
*/

// unit_ctor()
/**
* @class _13c63ea2_f6f3_4df0_9777_6fea5f16ed97
* @private
*
* @brief
*   Assigns any pointer that will statically convert to the unit_t.
*
* @copydoc _0dbc7113_d4d4_4ec8_bb81_53f931e49943
*/

// units_ctor()
/**
* @class _4bb5922a_17c8_4e5f_a28e_39120c4a10ae
* @private
* 
* @brief
*   Assigns any pointer that will statically convert to the units_t as well as the unit count.
*
* @copydoc _4f00c181_94ec_49b5_a488_dd4de436e58d
*/

// copy_ctor()
/**
* @class _24851f01_dc34_4dfc_9b54_73fd3526ccea
* @private
* 
* @copydoc _d1335627_f8fc_4621_81bf_9a74aba072e6
*/

// copy_volatile_ctor()
/**
* @class _91bf8714_b84f_4c27_9f65_aba46df54181
* @private
* 
* @copydoc _d1335627_f8fc_4621_81bf_9a74aba072e6
*/

// move_ctor()
/**
* @class _6805ea8c_29f8_48aa_a4a0_e881e7a36584
* @private
* 
* @copydoc _d3785193_ba05_4807_9ca4_e02ecd3d2276
* 
* @copydoc _63ccc436_1f2c_47a9_aa3e_86a9ca48b06b
*/

// move_volatile_ctor()
/**
* @class _7eab6f65_d3bb_4ddd_a1d9_02a71b4b5fad
* @private
* 
* @copydoc _d3785193_ba05_4807_9ca4_e02ecd3d2276
* 
* @copydoc _63ccc436_1f2c_47a9_aa3e_86a9ca48b06b
*/

// copy_assignment_ctor()
/**
* @class _6c02217e_8406_4fc9_ac1f_1d4c713a3064
* @private
* 
* @copydoc _d1335627_f8fc_4621_81bf_9a74aba072e6
*/

// volatile_copy_assignment_ctor()
/**
* @class _7a54639a_4b6e_4aa3_a134_cc0085253cae
* @private
* 
* @copydoc _d1335627_f8fc_4621_81bf_9a74aba072e6
*/

// copy_volatile_assignment_ctor()
/**
* @class _753b5956_3cca_4da1_a756_6829783b5d43
* @private
* 
* @copydoc _d1335627_f8fc_4621_81bf_9a74aba072e6
*/

// volatile_copy_volatile_assignment_ctor()
/**
* @class _30137478_9e8f_4f49_b169_89884d5a20e2
* @private
* 
* @copydoc _d1335627_f8fc_4621_81bf_9a74aba072e6
*/

// move_assignment_ctor()
/**
* @class _99f8dfb4_07c9_431c_9b0f_e46b92474510
* @private
* 
* @copydoc _d3785193_ba05_4807_9ca4_e02ecd3d2276
* 
* @copydoc _63ccc436_1f2c_47a9_aa3e_86a9ca48b06b
*/

// volatile_move_assignment_ctor()
/**
* @class _29857971_6f50_4825_8ab4_86f20ba6563e
* @private
* 
* @copydoc _d3785193_ba05_4807_9ca4_e02ecd3d2276
* 
* @copydoc _63ccc436_1f2c_47a9_aa3e_86a9ca48b06b
*/

// move_volatile_assignment_ctor()
/**
* @class _bf302079_d926_421d_a1e9_e5e087dbdf44
* @private
* 
* @copydoc _d3785193_ba05_4807_9ca4_e02ecd3d2276
*
* @copydoc _63ccc436_1f2c_47a9_aa3e_86a9ca48b06b
* @copydoc _8e1e5754_1178_4a81_a815_bc87771b148b
*/

// volatile_move_volatile_assignment_ctor()
/**
* @class _7558247f_2800_488a_99c4_deac9d1d0ed5
* @private
* 
* @copydoc _d3785193_ba05_4807_9ca4_e02ecd3d2276
*
* @copydoc _63ccc436_1f2c_47a9_aa3e_86a9ca48b06b
* @copydoc _8e1e5754_1178_4a81_a815_bc87771b148b
*/

// dtor()
/**
* @class _947c7490_f953_40e2_9c1a_790fca699e4f
* @private
* 
* @copydoc _698817e2_16a3_4c95_aa40_32b4ad798fd5
* 
* @copydoc _63ccc436_1f2c_47a9_aa3e_86a9ca48b06b
*/

/////////////////////////////////////////////////////////////////////////////// Docs
// nkr::pointer_t$
/**
* @class _a5a2b1f5_e0b0_474a_949d_8fdcbaf67557
* @private
* 
* @brief
*   Contains specializations for nkr::pointer_t.
*/

    // any_type_sp
    /**
    * @class _4cac11ea_20bf_436b_a218_bd7a024c25ea
    * @private
    * 
    * @brief
    *   A specialization for nkr::pointer_t through nkr::pointer_t<any_type_p>. Accepts any type that has a size.
    * 
    * @details
    *   Unlike nkr::pointer_t$::any_non_type_sp, this specialization defines several more operators with which to operate upon both the underlying pointer and its unit count simultaneously.
    */

        // aliases
        /**
        * @class _b6a07638_8d8e_4493_873e_104d772023af
        * @private
        */

            // unit_t
            /**
            * @class _92ae84ae_55d6_4911_9515_ed7941008d49
            * @private
            * 
            * @copydoc _91f3b401_936a_4163_9c83_cefc3f28a167
            */

            // units_t
            /**
            * @class _bc1f6288_e979_4e82_8524_675eee13c515
            * @private
            * 
            * @copydoc _2f9a1113_dd23_4073_9637_5d0accc99f52
            */

        // object data
        /**
        * @class _6ca35d80_e800_4856_a4b3_c43655537937
        * @private
        */

            // units
            /**
            * @class _3df94cc1_43a4_4d35_ad6f_7a6ffd33d851
            * @private
            */

            // unit_count
            /**
            * @class _d2cf83c1_3e63_4a1a_85c8_351691f0c60d
            * @private
            */

        // objects
        /**
        * @class _376ea0b2_78b0_4f2c_9c24_93a6c9f000e0
        * @private
        */

            // default_ctor()
            /**
            * @class _1c8568bf_0ac5_435c_bb5a_05593d20d914
            * @private
            * 
            * @copydoc _7ffbe668_7434_4c6d_b056_d98c27149da9
            */

            // unit_ctor()
            /**
            * @class _dc28512c_2132_41d1_949d_65f941159534
            * @private
            * 
            * @copydoc _13c63ea2_f6f3_4df0_9777_6fea5f16ed97
            */

            // units_ctor()
            /**
            * @class _7215773f_344a_4e4f_87c7_31e12bfc8843
            * @private
            * 
            * @copydoc _4bb5922a_17c8_4e5f_a28e_39120c4a10ae
            */

            // copy_ctor()
            /**
            * @class _c0da811c_a80b_4636_8071_cd7f5d11462f
            * @private
            * 
            * @copydoc _24851f01_dc34_4dfc_9b54_73fd3526ccea
            */

            // copy_volatile_ctor()
            /**
            * @class _8b1b5b55_1e66_4bc9_bad3_ebfef7468786
            * @private
            * 
            * @copydoc _91bf8714_b84f_4c27_9f65_aba46df54181
            */

            // move_ctor()
            /**
            * @class _bc93001b_b60a_457d_b315_8559c20f4d53
            * @private
            * 
            * @copydoc _6805ea8c_29f8_48aa_a4a0_e881e7a36584
            */

            // move_volatile_ctor()
            /**
            * @class _c2685632_397f_4514_bf75_117ab75e291a
            * @private
            * 
            * @copydoc _7eab6f65_d3bb_4ddd_a1d9_02a71b4b5fad
            */

            // copy_assignment_ctor()
            /**
            * @class _a3311c87_1524_41ed_b4f1_4b63052493bf
            * @private
            * 
            * @copydoc _6c02217e_8406_4fc9_ac1f_1d4c713a3064
            */

            // volatile_copy_assignment_ctor()
            /**
            * @class _d261c23f_1c7b_47c5_bccd_c9ff79f12e0a
            * @private
            * 
            * @copydoc _7a54639a_4b6e_4aa3_a134_cc0085253cae
            */

            // copy_volatile_assignment_ctor()
            /**
            * @class _93ebbc4c_1ae8_4983_a94b_75bb30a7c441
            * @private
            * 
            * @copydoc _753b5956_3cca_4da1_a756_6829783b5d43
            */

            // volatile_copy_volatile_assignment_ctor()
            /**
            * @class _5b59fd59_d903_4976_8aec_e53a797779ec
            * @private
            * 
            * @copydoc _30137478_9e8f_4f49_b169_89884d5a20e2
            */

            // move_assignment_ctor()
            /**
            * @class _54b20bdf_ad18_4306_9560_f7ad819ab2e9
            * @private
            * 
            * @copydoc _99f8dfb4_07c9_431c_9b0f_e46b92474510
            */

            // volatile_move_assignment_ctor()
            /**
            * @class _7e14f1c8_db41_4153_9771_cd20947f5b4f
            * @private
            * 
            * @copydoc _29857971_6f50_4825_8ab4_86f20ba6563e
            */

            // move_volatile_assignment_ctor()
            /**
            * @class _63ada161_3f30_4c27_955a_6195ed353eb3
            * @private
            * 
            * @copydoc _bf302079_d926_421d_a1e9_e5e087dbdf44
            */

            // volatile_move_volatile_assignment_ctor()
            /**
            * @class _8578437a_9ec0_4990_af69_2826b21f3172
            * @private
            * 
            * @copydoc _7558247f_2800_488a_99c4_deac9d1d0ed5
            */

            // dtor()
            /**
            * @class _1fc3694a_7961_45fc_9b96_37103fdef1fb
            * @private
            * 
            * @copydoc _947c7490_f953_40e2_9c1a_790fca699e4f
            */

        // methods
        /**
        * @class _23c3de4b_21be_4c49_ae51_b102451aa700
        * @private
        */

            // Unit()
            /**
            * @class _1c56eb69_0069_411b_806f_8d3b9613d720
            * @private
            * 
            * @copydoc _0dbc7113_d4d4_4ec8_bb81_53f931e49943
            */

            // const Unit()
            /**
            * @class _f50fe904_78fe_43df_ba73_fc9f10d459f8
            * @private
            * 
            * @copydoc _0dbc7113_d4d4_4ec8_bb81_53f931e49943
            */

            // volatile Unit()
            /**
            * @class _0518f8f0_eb02_40df_ae0f_60b0b405bfa3
            * @private
            * 
            * @copydoc _0dbc7113_d4d4_4ec8_bb81_53f931e49943
            */

            // const volatile Unit()
            /**
            * @class _27cedfc3_54d9_4160_bf8f_7a05ccb87db5
            * @private
            * 
            * @copydoc _0dbc7113_d4d4_4ec8_bb81_53f931e49943
            */

            // Units()
            /**
            * @class _c5f9a133_b082_481e_a84c_fd6ff15b31f6
            * @private
            * 
            * @copydoc _4f00c181_94ec_49b5_a488_dd4de436e58d
            */

            // const Units()
            /**
            * @class _33ec7f42_c7c0_4441_a79c_9e00a8ef1eaa
            * @private
            * 
            * @copydoc _4f00c181_94ec_49b5_a488_dd4de436e58d
            */

            // volatile Units()
            /**
            * @class _19a5031d_a013_4ab1_b915_88ac00e7b4eb
            * @private
            * 
            * @copydoc _4f00c181_94ec_49b5_a488_dd4de436e58d
            */

            // const volatile Units()
            /**
            * @class _6273d5f2_da05_45ee_b68b_589de1976d86
            * @private
            * 
            * @copydoc _4f00c181_94ec_49b5_a488_dd4de436e58d
            */

            // Unit_Count()
            /**
            * @class _4c60b492_a7b6_4d36_ae20_409b21d874ef
            * @private
            */

            // const Unit_Count()
            /**
            * @class _88cce35b_220e_41c0_b2e7_5fee257e382b
            * @private
            */

            // volatile Unit_Count()
            /**
            * @class _40f0b4d2_91fd_4ec8_bfb2_d7ae757295d3
            * @private
            */

            // const volatile Unit_Count()
            /**
            * @class _51e49569_904a_4b32_b9ae_9c7c7c266f2b
            * @private
            */

        // casts
        /**
        * @class _012ca2f7_33c3_49d5_99d5_f5411110a033
        * @private
        */

            // units_t&()
            /**
            * @class _ceba70a6_b9fe_4f2d_ae6c_d629708ed612
            * @private
            */

            // const units_t&()
            /**
            * @class _bc287b82_44ec_4926_9154_f9729a9c1fe7
            * @private
            */

            // volatile units_t&()
            /**
            * @class _0e6d4d71_ef0b_4953_9e6a_038b6678c2c2
            * @private
            */

            // const volatile units_t&()
            /**
            * @class _83809130_e0a4_48cd_9ead_4a8680a75f13
            * @private
            */

        // operators
        /**
        * @class _59cb3501_f53e_44e8_a2c3_fe845a0b24f9
        * @private
        */

            // ()()
            /**
            * @class _771c7948_77bc_41a4_aa5f_87f64cb5975c
            * @private
            */

            // const ()()
            /**
            * @class _15b2305d_9b5c_4ad8_983e_3a32dfeb0da7
            * @private
            */

            // volatile ()()
            /**
            * @class _4a4ac859_4ad6_4c53_b207_cb0b04369ffd
            * @private
            */

            // const volatile ()()
            /**
            * @class _0a406e7b_2822_4dde_bc55_8489736ced1b
            * @private
            */

            // ()(unit)
            /**
            * @class _c9e40e89_acad_4920_a54f_7e01b977320b
            * @private
            * 
            * @copydoc _0dbc7113_d4d4_4ec8_bb81_53f931e49943
            */

            // volatile ()(unit)
            /**
            * @class _6bb1d878_92ab_4719_9210_8c2f817efed8
            * @private
            * 
            * @copydoc _0dbc7113_d4d4_4ec8_bb81_53f931e49943
            */

            // ()(units, unit_count)
            /**
            * @class _a09d2106_04e4_470e_9221_b659b01e229d
            * @private
            * 
            * @copydoc _4f00c181_94ec_49b5_a488_dd4de436e58d
            */

            // volatile ()(units, unit_count)
            /**
            * @class _5a6f9877_fc1c_489a_b024_b32b051ec5e9
            * @private
            * 
            * @copydoc _4f00c181_94ec_49b5_a488_dd4de436e58d
            */

            // const +(amount)
            /**
            * @class _e301f083_3d5e_42da_8e77_3acaa1e9aa09
            * @private
            */

            // const volatile +(amount)
            /**
            * @class _1ed17124_582f_4376_8398_88733a32b921
            * @private
            */

            // const -(amount)
            /**
            * @class _875e34d4_d560_49f3_b210_a6df9d88ef06
            * @private
            */

            // const volatile -(amount)
            /**
            * @class _67adb21c_e639_4e3b_9c26_0afdf2bb0bef
            * @private
            */

            // +=(amount)
            /**
            * @class _1b2dca97_2fa5_4f2c_b11e_3b14e0e98206
            * @private
            */

            // volatile +=(amount)
            /**
            * @class _f67c4d55_7d0c_4f2e_81d5_4f6555082e17
            * @private
            */

            // -=(amount)
            /**
            * @class _42369c67_1da6_4d9e_ac47_117f6970bfb4
            * @private
            */

            // volatile -=(amount)
            /**
            * @class _7af64f3d_3d85_4408_84ea_518d108a105c
            * @private
            */

            // ++()
            /**
            * @class _f1737231_af90_4c9c_b95b_ec5eb2e7f450
            * @private
            */

            // volatile ++()
            /**
            * @class _eb9350f0_32aa_46a5_993f_55ebdb9a34cf
            * @private
            */

            // ++(int)
            /**
            * @class _2f97eb81_3d20_45aa_bdc0_8a3d47d356a8
            * @private
            */

            // volatile ++(int)
            /**
            * @class _ecbb4360_3af0_471f_b94d_0e34603c4e41
            * @private
            */

            // --()
            /**
            * @class _5e3fc904_5f6c_448b_a2aa_ab2ac055b7fb
            * @private
            */

            // volatile --()
            /**
            * @class _5f902ac6_965c_4947_ba12_8f0387fa5237
            * @private
            */

            // --(int)
            /**
            * @class _bfcdc54e_f98d_4156_844e_e039627cb986
            * @private
            */

            // volatile --(int)
            /**
            * @class _68c72174_ae0a_4086_8eae_c1780d1b2234
            * @private
            */

            // const ->()
            /**
            * @class _ecb3f076_6b07_4ebe_a1c1_e519c52ae5d4
            * @private
            */

            // const volatile ->()
            /**
            * @class _f0c4692a_f3a4_4f06_8743_8929b7ba5304
            * @private
            */

            // const *()
            /**
            * @class _0d908434_2b38_4c9b_825e_9c1d6601bbc2
            * @private
            */

            // const volatile *()
            /**
            * @class _4824a700_3433_4c7f_9f6f_9528ccb17c1b
            * @private
            */

            // const [](index)
            /**
            * @class _a138c11a_3a11_44e0_b98b_6bf89bcaea09
            * @private
            */

            // const volatile [](index)
            /**
            * @class _3bf83803_d863_4f44_b227_bb7da6b7225a
            * @private
            */

        // none_t interface
        /**
        * @class _839fa066_8b16_4951_a6d7_1fa27efb1a6a
        * @private
        */

            // none_ctor()
            /**
            * @class _9d5cf4be_18c1_4f02_b0a5_ac4b05160414
            * @private
            */

            // =(none_t)()
            /**
            * @class _17a283ad_7c14_497b_ab48_21b2395c7b88
            * @private
            */

            // volatile =(none_t)()
            /**
            * @class _7e5ffc67_94ec_46e7_8046_25b0b689b6d6
            * @private
            */

            // const ==(none_t)()
            /**
            * @class _de6fa37c_fa49_47e0_81b9_188f7f4d3212
            * @private
            */

            // const volatile ==(none_t)()
            /**
            * @class _9c596a46_a3af_434b_9ea3_30cedd7b5473
            * @private
            */

            // const !=(none_t)()
            /**
            * @class _559f619a_aa33_40ac_8c52_f4daaeff5c59
            * @private
            */

            // const volatile !=(none_t)()
            /**
            * @class _96405476_0e1b_4233_8c8a_3bde316329f0
            * @private
            */

    // any_non_type_sp
    /**
    * @class _4c92f1e4_18e6_4f53_84aa_79861d6edfc3
    * @private
    * 
    * @brief
    *   A specialization for nkr::pointer_t through nkr::pointer_t<any_non_type_p>. Accepts any type that does not have a size, in particular the void_t.
    * 
    * @details
    *   Unlike nkr::pointer_t$::any_type_sp, because the underlying pointer has no size only a handful of operators have been defined.
    */

        // aliases
        /**
        * @class _6d178bfd_8931_4666_a9f5_ddb184bed5c2
        * @private
        */

            // unit_t
            /**
            * @class _a1bd28d4_dd52_4df5_a8c4_71c23084b858
            * @private
            * 
            * @copydoc _91f3b401_936a_4163_9c83_cefc3f28a167
            */

            // units_t
            /**
            * @class _48d29ef7_5d22_41f3_8d75_01b8509d2d36
            * @private
            * 
            * @copydoc _2f9a1113_dd23_4073_9637_5d0accc99f52
            */

        // object data
        /**
        * @class _e9a447d1_530b_44a4_ad80_d9700c7b718d
        * @private
        */

            // units
            /**
            * @class _ee3b9730_4ef5_4423_8d50_2e1c4dd568d9
            * @private
            */

            // unit_count
            /**
            * @class _8349cb90_8bd1_4c28_9268_6a10c96395a1
            * @private
            */

        // objects
        /**
        * @class _1dd1de0b_2b60_4cc7_a0b9_9404515162ca
        * @private
        */

            // default_ctor()
            /**
            * @class _fd4cb9f3_981d_4428_b08f_b84844264664
            * @private
            * 
            * @copydoc _7ffbe668_7434_4c6d_b056_d98c27149da9
            */

            // unit_ctor()
            /**
            * @class _f92563fb_d82f_40df_a9bc_ea3cf1d9f8cc
            * @private
            * 
            * @copydoc _13c63ea2_f6f3_4df0_9777_6fea5f16ed97
            */

            // units_ctor()
            /**
            * @class _7305c030_e245_4ca6_be99_f51e7db9aea8
            * @private
            * 
            * @copydoc _4bb5922a_17c8_4e5f_a28e_39120c4a10ae
            */

            // copy_ctor()
            /**
            * @class _97bf1598_b159_4b71_94d0_3b3a37dae639
            * @private
            * 
            * @copydoc _24851f01_dc34_4dfc_9b54_73fd3526ccea
            */

            // copy_volatile_ctor()
            /**
            * @class _f3f461da_c78f_4060_862b_6b1e07356dc3
            * @private
            * 
            * @copydoc _91bf8714_b84f_4c27_9f65_aba46df54181
            */

            // move_ctor()
            /**
            * @class _00ebd123_400e_4aa9_b7a7_7ca0932fcf7a
            * @private
            * 
            * @copydoc _6805ea8c_29f8_48aa_a4a0_e881e7a36584
            */

            // move_volatile_ctor()
            /**
            * @class _a89d0874_ed05_451d_b9a1_d1badaa4b084
            * @private
            * 
            * @copydoc _7eab6f65_d3bb_4ddd_a1d9_02a71b4b5fad
            */

            // copy_assignment_ctor()
            /**
            * @class _96b931a4_ba96_4679_91d1_1ed8bec9396c
            * @private
            * 
            * @copydoc _6c02217e_8406_4fc9_ac1f_1d4c713a3064
            */

            // volatile_copy_assignment_ctor()
            /**
            * @class _9231978e_46d8_4e62_a169_010b10d84ad6
            * @private
            * 
            * @copydoc _7a54639a_4b6e_4aa3_a134_cc0085253cae
            */

            // copy_volatile_assignment_ctor()
            /**
            * @class _4c157309_a133_4160_8fa8_843920acc7b3
            * @private
            * 
            * @copydoc _753b5956_3cca_4da1_a756_6829783b5d43
            */

            // volatile_copy_volatile_assignment_ctor()
            /**
            * @class _e2f10a34_b38e_450b_8013_2e1fe76752f2
            * @private
            * 
            * @copydoc _30137478_9e8f_4f49_b169_89884d5a20e2
            */

            // move_assignment_ctor()
            /**
            * @class _f0477023_82a3_4048_9313_62387fdff537
            * @private
            * 
            * @copydoc _99f8dfb4_07c9_431c_9b0f_e46b92474510
            */

            // volatile_move_assignment_ctor()
            /**
            * @class _5da75588_c326_4cdf_b75d_a76ef69babfc
            * @private
            * 
            * @copydoc _29857971_6f50_4825_8ab4_86f20ba6563e
            */

            // move_volatile_assignment_ctor()
            /**
            * @class _1b70321c_f92a_45d7_aba4_aa2d61cb621b
            * @private
            * 
            * @copydoc _bf302079_d926_421d_a1e9_e5e087dbdf44
            */

            // volatile_move_volatile_assignment_ctor()
            /**
            * @class _ca3664b2_a4d2_428a_a135_49e51f8fd63a
            * @private
            * 
            * @copydoc _7558247f_2800_488a_99c4_deac9d1d0ed5
            */

            // dtor()
            /**
            * @class _459bbcf9_2eae_4ac5_a795_192dede69071
            * @private
            * 
            * @copydoc _947c7490_f953_40e2_9c1a_790fca699e4f
            */

        // methods
        /**
        * @class _22e54a53_78bc_4bed_be09_e3f9ffb503ee
        * @private
        */

            // Unit()
            /**
            * @class _a43c8247_1d23_43a7_8876_590f55f25d72
            * @private
            * 
            * @copydoc _0dbc7113_d4d4_4ec8_bb81_53f931e49943
            */

            // const Unit()
            /**
            * @class _509d6dcd_295f_4b06_9a65_1ebd6094fa7f
            * @private
            * 
            * @copydoc _0dbc7113_d4d4_4ec8_bb81_53f931e49943
            */

            // volatile Unit()
            /**
            * @class _12c45eff_16d4_437a_9513_440ef7ebb9a0
            * @private
            * 
            * @copydoc _0dbc7113_d4d4_4ec8_bb81_53f931e49943
            */

            // const volatile Unit()
            /**
            * @class _a1d6665b_1eea_43f6_91da_d1213ee7e047
            * @private
            * 
            * @copydoc _0dbc7113_d4d4_4ec8_bb81_53f931e49943
            */

            // Units()
            /**
            * @class _f68ef888_8644_4395_a175_62d32fa0eace
            * @private
            * 
            * @copydoc _4f00c181_94ec_49b5_a488_dd4de436e58d
            */

            // const Units()
            /**
            * @class _434d2816_c402_4cee_bf83_48944a14d932
            * @private
            * 
            * @copydoc _4f00c181_94ec_49b5_a488_dd4de436e58d
            */

            // volatile Units()
            /**
            * @class _262e6f48_f738_4fc0_b093_de8245d684e8
            * @private
            * 
            * @copydoc _4f00c181_94ec_49b5_a488_dd4de436e58d
            */

            // const volatile Units()
            /**
            * @class _953b5ac5_1ed5_424b_b8f0_88f421ad4bfe
            * @private
            * 
            * @copydoc _4f00c181_94ec_49b5_a488_dd4de436e58d
            */

            // Unit_Count()
            /**
            * @class _547d6e2e_7505_4f5d_9087_28060695980c
            * @private
            */

            // const Unit_Count()
            /**
            * @class _b2ea1c73_095f_4e58_b6e0_abfb43f29860
            * @private
            */

            // volatile Unit_Count()
            /**
            * @class _ba0df937_e384_437c_8fe8_d92be3989e99
            * @private
            */

            // const volatile Unit_Count()
            /**
            * @class _f05031e8_c9f4_4ea5_ace7_454373e81e36
            * @private
            */

        // casts
        /**
        * @class _6ba21839_d029_4444_a388_e963e6cf432f
        * @private
        */

            // units_t&()
            /**
            * @class _6586aca8_e591_4822_a9fc_f2de2c0b834d
            * @private
            */

            // const units_t&()
            /**
            * @class _f1be559d_58a5_4d6a_8dea_6b80e0ee1065
            * @private
            */

            // volatile units_t&()
            /**
            * @class _7b5233ee_8c56_453f_a431_4dbf83879f4e
            * @private
            */

            // const volatile units_t&()
            /**
            * @class _7e1cb906_3aad_4960_89fd_981cb8e4830a
            * @private
            */

        // operators
        /**
        * @class _fe6b1e12_7a52_4c6c_a924_9cf46a10c3ca
        * @private
        */

            // ()()
            /**
            * @class _4b79370c_f362_45f9_9d37_b731f316025d
            * @private
            */

            // const ()()
            /**
            * @class _bbf32227_c0fc_4838_894e_6a906cefdf0e
            * @private
            */

            // volatile ()()
            /**
            * @class _a491545e_894b_432c_9317_1fc2afe6d66d
            * @private
            */

            // const volatile ()()
            /**
            * @class _be62344a_26ad_486c_b424_610bfc35ec80
            * @private
            */

            // ()(unit)
            /**
            * @class _aaf4fd00_88d2_4dde_8bde_526c30eaf395
            * @private
            * 
            * @copydoc _0dbc7113_d4d4_4ec8_bb81_53f931e49943
            */

            // volatile ()(unit)
            /**
            * @class _d9232d93_f804_4769_a277_4fb9e488f865
            * @private
            * 
            * @copydoc _0dbc7113_d4d4_4ec8_bb81_53f931e49943
            */

            // ()(units, unit_count)
            /**
            * @class _533c931e_e282_44b8_8737_12a14ba71e6f
            * @private
            * 
            * @copydoc _4f00c181_94ec_49b5_a488_dd4de436e58d
            */

            // volatile ()(units, unit_count)
            /**
            * @class _7768ca0a_8a99_41d2_9f01_623d7d889d5e
            * @private
            * 
            * @copydoc _4f00c181_94ec_49b5_a488_dd4de436e58d
            */

        // none_t interface
        /**
        * @class _2862d75a_5b99_4855_aa88_475d95f59e46
        * @private
        */

            // none_ctor()
            /**
            * @class _eb685f00_492e_4754_a81e_99599e24ddb0
            * @private
            */

            // =(none_t)()
            /**
            * @class _28b31b9e_9fb9_4ae1_a8b4_6e960c7f83c4
            * @private
            */

            // volatile =(none_t)()
            /**
            * @class _d88af58e_246d_4232_9f71_c77678a0c641
            * @private
            */

            // const ==(none_t)()
            /**
            * @class _db3bfe56_5f15_4002_81c8_b5d3e54bd300
            * @private
            */

            // const volatile ==(none_t)()
            /**
            * @class _fa1b4d58_e708_427a_a61b_25d80d660d41
            * @private
            */

            // const !=(none_t)()
            /**
            * @class _2afca332_ab8d_4ae4_b89b_3afcbe8370c4
            * @private
            */

            // const volatile !=(none_t)()
            /**
            * @class _5ca204d1_cae9_4cf7_8ae2_6e452d788063
            * @private
            */

// pointer_t<unit_p>
/**
* @class _e370da3e_9474_437e_843e_e14b8ccf6a1c
* @private
* 
* @brief
*   A fat pointer that stores a pointer to any unit_t and a unit count indicating the size of memory being pointed to.
* 
* @details
*   This type is primarly used to avoid read violations which happen when indexing beyond the last unit of memory being pointed to. It's a great building block for other types that need to manage their own memory through pointers or for functions and types that need to iterate a pointer. It's even useful for simply allocating memory through any of the various allocators in the nkr::allocator namespace.
* 
*   Additionally, this class provides methods which alter both the pointer and the number of units as you increment or decrement the object. It also plays things safe and defaults the pointer's data on construction and destruction, which can help track down bugs when trying to access data that has for example, been deallocated. Allows you to work with the underlying pointer easily by providing the expected methods and operators.
* 
* @par Specializations
*   - pointer_t<any_type_p> (wrapper for pointer_t$::any_type_sp)
*   - pointer_t<any_non_type_p> (wrapper for pointer_t$::any_non_type_sp)
* 
* @copydoc _bce7ac69_38d5_4477_a659_c8cf291f1173
*/

// pointer_t<any_type_p>
/**
* @class _7598e667_809c_4a66_99a0_4a061980c7f9
* @private
* 
* @brief
*   A specialization of nkr::pointer_t and a wrapper for nkr::pointer_t$::any_type_sp.
* 
* @copydoc _f66dddf5_07cc_4240_b2e2_39253f780892
* @copydoc _e245fac0_078f_4cf6_852c_a42932c2ffff
*/

// pointer_t<any_non_type_p>
/**
* @class _f850063c_8453_4b64_959a_562c8cf9037b
* @private
* 
* @brief
*   A specialization of nkr::pointer_t and a wrapper for nkr::pointer_t$::any_non_type_sp.
* 
* @copydoc _f66dddf5_07cc_4240_b2e2_39253f780892
* @copydoc _e245fac0_078f_4cf6_852c_a42932c2ffff
*/
