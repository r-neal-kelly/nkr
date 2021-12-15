/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

// nkr::$maybe_t
/**
* @class _c8a34890_b904_42a7_a88c_ada39529db42
* @private
*
* @brief
*   Contains all nkr::maybe_t specializations, kept separately from the actual interface.
* 
* @copydoc _e245fac0_078f_4cf6_852c_a42932c2ffff
*/

    // nkr::$maybe_t::$built_in_sp
    /**
    * @class _1145e7f5_3595_468d_8aca_2c1336bdc5b8
    * @private
    *
    * @brief
    *   Contains all built-in specializations for nkr::maybe_t, kept separately from the actual interface.
    * 
    * @details
    *   Built-in types need a class wrapper to behave in the same manner that a user-defined type does. This allows us to define an implementation of nkr::none_i and for all nkr::maybe_t objects to behave in the same manner.
    * 
    * @copydoc _e245fac0_078f_4cf6_852c_a42932c2ffff
    */

        // any_sp
        /**
        * @class _0d45c64a_558d_4bd7_baa2_6f521f6656d5
        * @private
        *
        * @brief
        *   The default nkr::maybe_t specialization for built-in types.
        * 
        * @details
        *   This works with nkr::std_bool_t and integers. Real numbers and pointers each have their own specialization of this template.
        */

            // aliases
            /**
            * @class _1acc637c_5d07_41c7_9a7c_996d963c2a59
            * @private
            */

                // value_t
                /**
                * @class _6d9bde0e_f973_4668_a07d_05729f4af0f6
                * @private
                */

            // object data
            /**
            * @class _a132ddc6_1af5_4637_9b5d_3114ee912dff
            * @private
            */

                // value
                /**
                * @class _acce0e58_343c_4481_a91a_7db997eb42b4
                * @private
                */

            // objects
            /**
            * @class _1fcb90e5_b65a_4312_ac7f_9951456b3425
            * @private
            */

                // default_ctor()
                /**
                * @class _d18299ac_6d7e_4560_88ff_e53f4bb77069
                * @private
                * @snippet "./src/maybe_t.cpp" _3947e943_7bb5_4461_8fb6_7c52bae80b6c
                */

                // value_ctor()
                /**
                * @class _aa14e4f4_23ce_4d01_a6be_c12342adf7e7
                * @private
                * @snippet "./src/maybe_t.cpp" _b2f13fd4_de97_43a6_9592_933c225f64b3
                */

                // copy_ctor()
                /**
                * @class _b8bf31fb_a852_4c94_aa33_f6dc791a7a9f
                * @private
                * @snippet "./src/maybe_t.cpp" _e886a1de_1282_4231_9772_a2554ff0b93e
                */

                // move_ctor()
                /**
                * @class _72a66390_63d7_4076_966f_c4a6c6d94c0a
                * @private
                * @snippet "./src/maybe_t.cpp" _c08944e9_0848_4e7a_b121_821a82f89118
                */

                // copy_assignment_ctor()
                /**
                * @class _6693684a_9d8b_45e3_9196_3e20af210319
                * @private
                * @snippet "./src/maybe_t.cpp" _45d04972_08a7_492c_90a1_3936d1ed7bcb
                */

                // move_assignment_ctor()
                /**
                * @class _003d4488_8885_414a_b34c_e6beb6c1019a
                * @private
                * @snippet "./src/maybe_t.cpp" _71ee8a31_68ef_4cc1_8906_9cb9e5d7fa45
                */

                // dtor()
                /**
                * @class _8befff79_9dcc_4bd8_91e6_a3cddab84821
                * @private
                * @snippet "./src/maybe_t.cpp" _b76161ed_4157_4d10_9297_7acc4df805d4
                */

            // casts
            /**
            * @class _c2859fff_ae85_4e8e_8b1a_c9228bb961b4
            * @private
            */

                // value_t&()
                /**
                * @class _2a09a3db_f1fb_41ff_bb7d_83c4d2193bd5
                * @private
                * @snippet "./src/maybe_t.cpp" _862b58a5_fbb6_43cc_a7cd_54ca4f580b37
                */

                // const value_t&()
                /**
                * @class _508d5690_a07a_42b9_b255_435e786ec73a
                * @private
                * @snippet "./src/maybe_t.cpp" _f755ffdd_dead_4f09_9348_643b5f6b089e
                */

            // operators
            /**
            * @class _b2f6d1e6_2a05_4d53_b01f_45f46cefe7c3
            * @private
            */

                // ()()
                /**
                * @class _0a0d6fe6_f1dc_4a12_8678_185933cbf587
                * @private
                * @snippet "./src/maybe_t.cpp" _43216f39_12c8_4163_8c44_e23e9b8a26d5
                */

                // ()() const
                /**
                * @class _b0a0511e_f1e4_4c6a_a9f4_487e27a55d9f
                * @private
                * @snippet "./src/maybe_t.cpp" _4ae71520_60de_44f6_91e3_ad72a54234ea
                */

            // none_t interface
            /**
            * @class _1dfe08c1_275f_46e1_af39_240c6b354178
            * @private
            */

                // none_ctor()
                /**
                * @class _3c6a0391_99dd_46ef_aebd_c6cd2a474a2b
                * @private
                */

                // =(none_t)
                /**
                * @class _8a90b1f2_c65f_4ad3_8d73_d985f67d6293
                * @private
                * @snippet "./src/maybe_t.cpp" _07804510_9e9d_4297_bf1e_53cc951ccde9
                */

                // ==(none_t)
                /**
                * @class _ba6bc412_5d93_402c_aa70_359a0fe73cce
                * @private
                * @snippet "./src/maybe_t.cpp" _db6ed293_bce8_433f_adb1_26371f0faef5
                */

                // !=(none_t)
                /**
                * @class _f148b5f5_a869_429b_afcd_5f391558954a
                * @private
                * @snippet "./src/maybe_t.cpp" _d1852cf1_429a_44f9_83fe_e5cceeee5af6
                */

        // real_sp
        /**
        * @class _38ebec22_bbe8_4dca_a3dd_e0d3ce7f680f
        * @private
        *
        * @brief
        *   The nkr::maybe_t specialization for built-in real numbers.
        * 
        * @details
        *   This inherits the default specialization nkr::$maybe_t::$built_in_sp::any_sp and additionally defines the increment and decrement operators, because at least in the MS compiler they do not work even with implicit `operator value_t&()`.
        */

            // aliases
            /**
            * @class _bb2c1a35_af7a_4084_ad9d_59a969254b54
            * @private
            */

                // value_t
                /**
                * @class _6337ae7b_7866_4d54_8259_2228811679c6
                * @private
                */

            // operators
            /**
            * @class _21a14be3_cb6c_4bbe_831d_6da25cb18a1d
            * @private
            */

                // ++()
                /**
                * @class _45465f70_1de8_47e3_a10d_586e5c4636cc
                * @private
                */

                // ++(int)
                /**
                * @class _cc4463c5_573f_4fda_8971_f19e7a91d744
                * @private
                */

                // --()
                /**
                * @class _08e887d6_7157_460f_b91e_13073571bb06
                * @private
                */

                // --(int)
                /**
                * @class _47619a94_f70e_422d_bc75_a57a426c325f
                * @private
                */

        // c_pointer_sp
        /**
        * @class _853d9bea_a9d0_40eb_81c1_aa874fcbdfb1
        * @private
        *
        * @brief
        *   The nkr::maybe_t specialization for built-in pointers.
        *
        * @details
        *   This inherits the default specialization nkr::$maybe_t::$built_in_sp::any_sp and additionally defines `operator ->()`, because at least in the MS compiler it does not work even with implicit `operator value_t&()`.
        */

            // aliases
            /**
            * @class _9f86f607_6972_4326_b817_4a06a53d154d
            * @private
            */

                // value_t
                /**
                * @class _febf525c_e1d2_43d7_93f2_8cc96a495097
                * @private
                */

            // operators
            /**
            * @class _73f0a437_cda0_4e5d_91e0_8e4563970b36
            * @private
            */

                // ->()
                /**
                * @class _203f8176_57e2_42f5_9ef2_850f3151f3a9
                * @private
                */

    // built_in_sp<any_p>
    /**
    * @class _476cf1d5_7332_4bfc_acfb_d3a5e3802c6f
    * @private
    * 
    * @copydoc _f66dddf5_07cc_4240_b2e2_39253f780892
    * @copydoc _e245fac0_078f_4cf6_852c_a42932c2ffff
    */

        // objects
        /**
        * @class _f4d38cc3_7d9e_402c_8ddb_0917ce83dc55
        * @private
        */

    // built_in_sp<real_p>
    /**
    * @class _54610ffc_35de_47f2_9b0a_03da52782104
    * @private
    * 
    * @copydoc _f66dddf5_07cc_4240_b2e2_39253f780892
    * @copydoc _e245fac0_078f_4cf6_852c_a42932c2ffff
    */

        // objects
        /**
        * @class _5b844485_95be_4c1a_a964_62ddfce97452
        * @private
        */

    // built_in_sp<c_pointer_p>
    /**
    * @class _eb401275_a224_48ec_ab23_6d0c82b83d8a
    * @private
    * 
    * @copydoc _f66dddf5_07cc_4240_b2e2_39253f780892
    * @copydoc _e245fac0_078f_4cf6_852c_a42932c2ffff
    */

        // objects
        /**
        * @class _04720ddf_c679_4933_bf4f_f0da04fe53f8
        * @private
        */

    // user_defined_sp
    /**
    * @class _870ca0b2_c146_47a9_838f_140187d046e9
    * @private
    *
    * @brief
    *   A nkr::maybe_t specialization for user-defined types, including types defined in this library.
    * 
    * @copydoc _f66dddf5_07cc_4240_b2e2_39253f780892
    */

        // aliases
        /**
        * @class _9582d918_063d_484b_be3a_28b753f1e85b
        * @private
        */

            // value_t
            /**
            * @class _6cc07b8c_e756_474e_886d_be8bbee3392e
            * @private
            */

        // objects
        /**
        * @class _bace7444_fb65_41c3_affb_6fd3c6dee6a1
        * @private
        */

        // operators
        /**
        * @class _923f1cf1_39a3_4bdb_87a2_0378c0de9bf4
        * @private
        */

            // ()()
            /**
            * @class _c0521baf_74a7_4a40_9cd7_f474802ebfbe
            * @private
            */

            // ()() const
            /**
            * @class _110607cd_bdbe_488b_8c8a_15a03e07523b
            * @private
            */

// maybe_t<invalid_p>
/**
* @class _1f11b26a_7bf8_462e_a657_b37f6313bff3
* @private
*
* @brief
*   Wraps a type whose object may have a value.
* 
* @details
*   This template is an in-code tag for an object which may or may not have a value. In other words, it may equate to nkr::none_t. This is opposed to nkr::some_t which indicates that an object has some value.
* 
*   This is used as a space efficient means of ensuring that any other interface is being fulfilled properly, including functions and other types. This is opposed to nkr::option_t, which adds a nkr::bool_t to its footprint to indicate nothing.
* 
*   This is the default template for nkr::maybe_t, which invalidates types not matching any specialization.
* 
* @par Specializations
*   - nkr::maybe_t<built_in_p>
*   - nkr::maybe_t<user_defined_p>
*/

    // objects
    /**
    * @class _dbabc9c5_cd8c_484e_9c15_b2a1b9a189a6
    * @private
    */

        // default_ctor()
        /**
        * @class _b38b11f9_98b1_45b5_8242_7d1da0aa4949
        * @private
        */

        // copy_ctor()
        /**
        * @class _4ad91ffe_91d1_4aab_b371_2e45fced4bb0
        * @private
        */

        // move_ctor()
        /**
        * @class _783181a7_0ea9_467e_8c37_c0cee4b8cd77
        * @private
        */

        // copy_assignment_ctor()
        /**
        * @class _2fffa10c_fa78_4309_8ce7_0c9dfef9d911
        * @private
        */

        // move_assignment_ctor()
        /**
        * @class _b57f9ee7_7133_4f1d_b8aa_e93038b42189
        * @private
        */

        // dtor()
        /**
        * @class _60fcb0e7_0dbe_4f97_a940_a31508f6363f
        * @private
        */

// maybe_t<built_in_p>
/**
* @class _b0155c57_e98a_479c_b659_c2e869035bec
* @private
* 
* @brief
*   A wrapper for nkr::$maybe_t::built_in_sp.
* 
* @copydoc _f66dddf5_07cc_4240_b2e2_39253f780892
* @copydoc _e245fac0_078f_4cf6_852c_a42932c2ffff
*/

    // objects
    /**
    * @class _26036428_887b_4bb1_a423_e576810532b5
    * @private
    */

// maybe_t<user_defined_p>
/**
* @class _28243913_2a03_428d_95ac_cbabc3cb3baa
* @private
* 
* @brief
*   A wrapper for nkr::$maybe_t::user_defined_sp.
* 
* @copydoc _f66dddf5_07cc_4240_b2e2_39253f780892
* @copydoc _e245fac0_078f_4cf6_852c_a42932c2ffff
*/

    // objects
    /**
    * @class _6f6b3ac8_c46b_4c2c_87c1_5cd210808876
    * @private
    */
