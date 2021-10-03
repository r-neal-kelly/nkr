/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

/////////////////////////////////////////////////////////////////////////////// Docs
// heap_zeros_t
/**
* @class _9ed461b6_85ad_4d8b_a9f0_2dda17493f3a
* @private
* 
* @brief
*   A wrapper for the nkr::os::heap allocator similar to nkr::allocator::heap_t except that it additionally zero-initializes memory during allocation and reallocation.
* 
* @copydoc _68c297e4_e2e3_4002_a52f_29edf775aa83
*/

    // aliases
    /**
    * @class _105f3971_d302_4b0d_84e2_255bc40106e4
    * @private
    */

        // unit_t
        /**
        * @class _2eea32f9_12d5_49c9_8dd7_88ad04f76c2f
        * @private
        */

        // units_t
        /**
        * @class _777776f2_6fd5_432d_9a52_9dcafc41114a
        * @private
        */

        // pointer_t
        /**
        * @class _b3f6bc08_befb_4809_b834_a95cc5822e65
        * @private
        */

    // static functions
    /**
    * @class _97cee72c_8d09_4b00_b71e_12167666c774
    * @private
    */

        // Min_Unit_Count()
        /**
        * @class _2733158c_4527_4730_b96d_71633b9dcc7e
        * @private
        */

        // Max_Unit_Count()
        /**
        * @class _6985e2eb_c95b_4dfb_9a12_ac58e1759c07
        * @private
        */

    // friends
    /**
    * @class _9cec351a_06bc_4963_bcfa_f04eec68ad0c
    * @private
    */

        // operator ==()
        /**
        * @class _b293e326_07c6_4d55_88ae_0df2609ea4ac
        * @private
        */

        // operator !=()
        /**
        * @class _c69fa1a6_4ce8_476d_aeb3_55de07e9eec5
        * @private
        */

    // objects
    /**
    * @class _db7a0f47_4799_4207_bf0e_2304a225ce78
    * @private
    */

        // default_ctor()
        /**
        * @class _8221efd2_f2a0_41d1_adb8_6b496bfce46e
        * @private
        */

        // copy_ctor()
        /**
        * @class _9d1d0678_861d_4714_aa68_01d231df8814
        * @private
        */

        // copy_volatile_ctor()
        /**
        * @class _3b1b6bf4_f26c_4884_abf7_c3405de9fa44
        * @private
        */

        // move_ctor()
        /**
        * @class _1924a0ce_e6e0_47a5_bd2b_3f4201d4cf46
        * @private
        */

        // move_volatile_ctor()
        /**
        * @class _817212c4_cb85_4a0a_8f46_b85da743b270
        * @private
        */

        // copy_assignment_ctor()
        /**
        * @class _3ba77c5d_06d2_4266_80ba_e1e38234a761
        * @private
        */

        // volatile_copy_assignment_ctor()
        /**
        * @class _d924b3d5_9170_425e_94b9_bf941a6fc61b
        * @private
        */

        // copy_volatile_assignment_ctor()
        /**
        * @class _4c4d31c0_8a3d_4dd4_89cb_fa690012091d
        * @private
        */

        // volatile_copy_volatile_assignment_ctor()
        /**
        * @class _b9b767c1_3021_479e_905e_5774631d80df
        * @private
        */

        // move_assignment_ctor()
        /**
        * @class _a3ab8033_f3a8_4203_a309_2455ba032954
        * @private
        */

        // volatile_move_assignment_ctor()
        /**
        * @class _9e177763_dd02_4d3e_a45b_f1b9e25a5e2b
        * @private
        */

        // move_volatile_assignment_ctor()
        /**
        * @class _c7d05983_50e9_4f48_8069_34028a118042
        * @private
        */

        // volatile_move_volatile_assignment_ctor()
        /**
        * @class _e7400c29_88f7_44fa_811b_6e072bef6193
        * @private
        */

        // dtor()
        /**
        * @class _71f33510_0167_444f_94c1_98964626275f
        * @private
        */

    // methods
    /**
    * @class _0d318fcd_846e_4498_a0f5_6cd5f76d9e89
    * @private
    */

        // const Allocate(units_t)
        /**
        * @class _9be86f6c_8114_453a_8dc6_31e4ec38ac06
        * @private
        */

        // const volatile Allocate(units_t)
        /**
        * @class _e05b1798_8e90_4b76_929c_a720f3c08e97
        * @private
        */

        // const Allocate(pointer_t)
        /**
        * @class _a4ade59f_0458_4747_895b_f498fb33b8ab
        * @private
        */

        // const volatile Allocate(pointer_t)
        /**
        * @class _2e6609e3_6c75_4834_bf34_f05b0d49a965
        * @private
        */

        // const Reallocate(units_t)
        /**
        * @class _daaa50b9_d86f_4b06_95ac_7a06790526d5
        * @private
        */

        // const volatile Reallocate(units_t)
        /**
        * @class _c8a45565_1648_4140_abdc_19c38bebfe9f
        * @private
        */

        // const Reallocate(pointer_t)
        /**
        * @class _b2db59c8_c954_43c3_b292_496d8a8e6184
        * @private
        */

        // const volatile Reallocate(pointer_t)
        /**
        * @class _ad6e5660_6f11_434a_8bbc_4310cd419dab
        * @private
        */

        // const Deallocate(units_t)
        /**
        * @class _1ceb289c_99eb_41d6_a6f1_3c6503dbe0ef
        * @private
        */

        // const volatile Deallocate(units_t)
        /**
        * @class _20755a8c_2f56_48b8_9bd9_c3d3e59f6412
        * @private
        */

        // const Deallocate(pointer_t)
        /**
        * @class _df9976c6_21ba_4064_ba40_b966f83b7805
        * @private
        */

        // const volatile Deallocate(pointer_t)
        /**
        * @class _8c2a6b84_9814_4c4b_a863_7d7bd5b3f10a
        * @private
        */
