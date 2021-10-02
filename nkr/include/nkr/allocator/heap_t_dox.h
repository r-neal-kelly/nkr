/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

/////////////////////////////////////////////////////////////////////////////// Docs
// heap_t
/**
* @class _b755f31e_b7ac_41ef_8835_c78b953b5de4
* @private
* 
* @brief
*   A wrapper for the nkr::os::heap allocator, often used by other types around the library as their default allocator.
* 
* @copydoc _68c297e4_e2e3_4002_a52f_29edf775aa83
*/

    // aliases
    /**
    * @class _8b3d52c2_1232_4297_8978_c9a842ee8e96
    * @private
    */

        // unit_t
        /**
        * @class _baa9a29c_b2a6_4310_bb01_be33343423b0
        * @private
        * 
        * @brief
        *   The underlying type which space will be allocated for.
        */

        // units_t
        /**
        * @class _d395167f_1ed2_4c91_bfb4_eb4090f818a9
        * @private
        * 
        * @brief
        *   The standard C pointer of unit_t which works with this allocator.
        */

        // pointer_t
        /**
        * @class _b897f43c_b3e5_4b4f_b5fc_e2d18c22d294
        * @private
        * 
        * @brief
        *   The pointer_t which works with this allocator.
        */

    // static functions
    /**
    * @class _e981621a_045f_4df5_b5db_81f1b32c5af7
    * @private
    */

        // Min_Unit_Count()
        /**
        * @class _dd4ec220_c0a0_40ac_9c9c_e53c46d59f18
        * @private
        * 
        * @brief
        *   Not used by this particular allocator. Always equals to 0.
        */

        // Max_Unit_Count()
        /**
        * @class _78c258f0_e7fe_476b_b06f_5e56cb6259a0
        * @private
        * 
        * @brief
        *   This is the maximum number of objects which space can be allocated for.
        * 
        * @details
        *   This limitation exists due to the size of the word_t of the machine and the physical limits of memory address space. Very improbable to reach with a 64-bit processor but 32-bit is a different story, with limitations of just under 4 gigabytes of allocatable space. For convenience, the unit_t is the basis of the metric rather than bytes.
        */

    // friends
    /**
    * @class _badab020_8220_44a0_9663_cb16dfac0e9b
    * @private
    */

        // operator ==()
        /**
        * @class _eb1c1043_8f5c_4867_89c9_021726b8e08f
        * @private
        * 
        * @brief
        *   Compares any qualified or unqualifed version of the type.
        */

        // operator !=()
        /**
        * @class _666c4bd5_d39e_47a9_93bb_2f283c39f3a5
        * @private
        * 
        * @brief
        *   Compares any qualified or unqualifed version of the type.
        */

    // objects
    /**
    * @class _14f4e31c_1660_4507_9ee2_1dbcfd5f4047
    * @private
    * 
    * @brief
    *   Because this is a static allocator and it doesn't need its own memory footprint, all of these are simply here to fulfill the nkr::allocator_i and do not do anything.
    */

        // default_ctor()
        /**
        * @class _72bb8488_2e92_4c3b_a911_ad1b21aaf99a
        * @private
        */

        // copy_ctor()
        /**
        * @class _96a83762_dfba_470b_b386_f1db4b6eadee
        * @private
        */

        // copy_volatile_ctor()
        /**
        * @class _828c6c9c_474b_43de_aca6_d25e3ef8fbfe
        * @private
        */

        // move_ctor()
        /**
        * @class _c5f44802_9d14_42e1_ab68_169226dc8849
        * @private
        */

        // move_volatile_ctor()
        /**
        * @class _150cf0da_1e36_499c_84bb_46fcffbf13d5
        * @private
        */

        // copy_assignment_ctor()
        /**
        * @class _b510eae7_0066_414f_9f31_bdf31ad9de23
        * @private
        */

        // volatile_copy_assignment_ctor()
        /**
        * @class _6ab2bd34_0053_41cb_b9e6_5fd68c266b33
        * @private
        */

        // copy_volatile_assignment_ctor()
        /**
        * @class _e94eb433_6630_4054_bc68_d35c23d5c232
        * @private
        */

        // volatile_copy_volatile_assignment_ctor()
        /**
        * @class _f26fe407_c8a4_4afc_93df_4ff085a75981
        * @private
        */

        // move_assignment_ctor()
        /**
        * @class _b52e44e0_52f7_4d81_8295_97247f58eb28
        * @private
        */

        // volatile_move_assignment_ctor()
        /**
        * @class _a3722f4c_acc2_49ab_acd4_ece68183e095
        * @private
        */

        // move_volatile_assignment_ctor()
        /**
        * @class _9b58de38_ab92_4cfb_a0b3_1b2bc3f32cb6
        * @private
        * 
        * @copydoc _8e1e5754_1178_4a81_a815_bc87771b148b
        */

        // volatile_move_volatile_assignment_ctor()
        /**
        * @class _94af172e_120d_44b5_80c6_e6b4dc30a742
        * @private
        * 
        * @copydoc _8e1e5754_1178_4a81_a815_bc87771b148b
        */

        // dtor()
        /**
        * @class _59244c8e_73d5_4e11_a2f7_58a3db2ef3bb
        * @private
        */

    // methods
    /**
    * @class _b3eebf07_c7e1_4ce6_824d_012253f28371
    * @private
    */

        //////////////////////////////////////////////////////////// Allocate(units_t) Details
        /**
        * @class _bd3d50a0_69a8_4e94_b563_a18b0cc29200
        * @private
        * 
        * @brief
        *   A wrapper for nkr::os::heap::Allocate.
        * 
        * @param units
        *   should be a non const pointer that this function can write a new address to. The qualification of the unit_t itself does not matter. Must be equal to none_t or it will assert. See nkr::os::heap::Allocate for more information.
        * 
        * @param unit_count
        *   is the number of unit_t objects for which to allocate space. If this number is more than nkr::allocator::heap_t::Max_Unit_Count, it will assert. See nkr::os::heap::Allocate for more information.
        * 
        * @returns
        *   a moved nkr::allocator_err::NONE if it succeeds.
        * 
        * @returns
        *   a moved nkr::allocator_err::OUT_OF_MEMORY if it fails.
        */
        
        // const Allocate(units_t)
        /**
        * @class _a1cd4e17_bb03_4c42_85be_fe91bb3b21f3
        * @private
        * 
        * @copydoc _bd3d50a0_69a8_4e94_b563_a18b0cc29200
        */

        // const volatile Allocate(units_t)
        /**
        * @class _bd5b60f3_b822_4f35_ab98_b5ff98ad8779
        * @private
        * 
        * @copydoc _bd3d50a0_69a8_4e94_b563_a18b0cc29200
        */

        //////////////////////////////////////////////////////////// Allocate(pointer_t) Details
        /**
        * @class _03faac45_b05d_4a80_83ad_a4767f5e15da
        * @private
        * 
        * @brief
        *   A wrapper for nkr::os::heap::Allocate, but it can handle a nkr::pointer_t.
        * 
        * @param units
        *   should be a non const nkr::pointer_t that this function can write a new address and unit count to. The qualification of the unit_t itself does not matter. Must be equal to none_t or it will assert. See nkr::os::heap::Allocate for more information.
        * 
        * @param unit_count
        *   is the number of unit_t objects for which to allocate space. If this number is more than nkr::allocator::heap_t::Max_Unit_Count, it will assert. See nkr::os::heap::Allocate for more information.
        * 
        * @returns
        *   a moved nkr::allocator_err::NONE if it succeeds.
        * 
        * @returns
        *   a moved nkr::allocator_err::OUT_OF_MEMORY if it fails.
        */

        // const Allocate(pointer_t)
        /**
        * @class _1c1a3ee2_5ae4_4be1_89a0_ab555f37660d
        * @private
        * 
        * @copydoc _03faac45_b05d_4a80_83ad_a4767f5e15da
        */

        // const volatile Allocate(pointer_t)
        /**
        * @class _3a4d96a3_16d5_4515_8c81_2a61096c75da
        * @private
        * 
        * @copydoc _03faac45_b05d_4a80_83ad_a4767f5e15da
        */

        //////////////////////////////////////////////////////////// Reallocate(units_t) Details
        /**
        * @class _84a0dc6d_eab4_4c41_afbe_e56046d5e318
        * @private
        * 
        * @brief
        *   A wrapper for nkr::os::heap::Reallocate.
        * 
        * @param units
        *   should be a non const pointer that this function can write a new address to. The qualification of the unit_t itself does not matter. You can also use this function to allocate by passing a nullptr. See nkr::os::heap::Reallocate for more information.
        * 
        * @param new_unit_count
        *   is the number of unit_t objects for which to allocate space. You can also use this function to deallocate by passing a zero count. If this number is more than nkr::allocator::heap_t::Max_Unit_Count, it will assert. See nkr::os::heap::Reallocate for more information.
        * 
        * @returns
        *   nkr::allocator_err::NONE if it succeeds.
        * 
        * @returns
        *   nkr::allocator_err::OUT_OF_MEMORY if it fails.
        */

        // const Reallocate(units_t)
        /**
        * @class _cd380e7e_2493_42d7_837e_5f993f5c0676
        * @private
        * 
        * @copydoc _84a0dc6d_eab4_4c41_afbe_e56046d5e318
        */

        // const volatile Reallocate(units_t)
        /**
        * @class _4c81b585_1a41_42ea_9b16_b3867e517b31
        * @private
        * 
        * @copydoc _84a0dc6d_eab4_4c41_afbe_e56046d5e318
        */

        //////////////////////////////////////////////////////////// Reallocate(pointer_t) Details
        /**
        * @class _cc9d55d1_c5df_47b7_8043_14604aa7b1cc
        * @private
        * 
        * @brief
        *   A wrapper for nkr::os::heap::Reallocate, but it can handle a nkr::pointer_t.
        * 
        * @param units
        *   should be a non const pointer that this function can write a new address to. The qualification of the unit_t itself does not matter. You can also use this function to allocate by passing a nullptr. See nkr::os::heap::Reallocate for more information.
        * 
        * @param new_unit_count
        *   is the number of unit_t objects for which to allocate space. You can also use this function to deallocate by passing a zero count. If this number is more than nkr::allocator::heap_t::Max_Unit_Count, it will assert. See nkr::os::heap::Reallocate for more information.
        * 
        * @returns
        *   nkr::allocator_err::NONE if it succeeds.
        * 
        * @returns
        *   nkr::allocator_err::OUT_OF_MEMORY if it fails.
        */

        // const Reallocate(pointer_t)
        /**
        * @class _931cb620_74fd_423d_8294_0ecb4bd0f550
        * @private
        * 
        * @copydoc _cc9d55d1_c5df_47b7_8043_14604aa7b1cc
        */

        // const volatile Reallocate(pointer_t)
        /**
        * @class _89101faa_a287_42a8_b946_6c9585b51cb2
        * @private
        * 
        * @copydoc _cc9d55d1_c5df_47b7_8043_14604aa7b1cc
        */

        //////////////////////////////////////////////////////////// Deallocate(units_t) Details
        /**
        * @class _f84fa58c_65e3_42cf_a65e_db536e24b4dd
        * @private
        * 
        * @brief
        *   A wrapper for nkr::os::heap::Deallocate.
        * 
        * @param units
        *   should be a non const pointer that this function can write nullptr to after deallocating. The qualification of the unit_t itself does not matter. If given nullptr it will return without issue. See nkr::os::heap::Deallocate for more information.
        */

        // const Deallocate(units_t)
        /**
        * @class _fe8a3e78_0335_4de8_8283_c6a7a2a2322b
        * @private
        * 
        * @copydoc _f84fa58c_65e3_42cf_a65e_db536e24b4dd
        */

        // const volatile Deallocate(units_t)
        /**
        * @class _ff19cbdc_d4d9_4c50_b9db_493f833701b2
        * @private
        * 
        * @copydoc _f84fa58c_65e3_42cf_a65e_db536e24b4dd
        */

        //////////////////////////////////////////////////////////// Deallocate(units_t) Details
        /**
        * @class _b79f3dbf_0539_495c_a245_35895bca640a
        * @private
        * 
        * @brief
        *   A wrapper for nkr::os::heap::Deallocate, but it can handle a nkr::pointer_t.
        * 
        * @param units
        *   should be a non const pointer that this function can write nullptr to after deallocating. The qualification of the unit_t itself does not matter. If given nullptr it will return without issue. See nkr::os::heap::Deallocate for more information.
        */

        // const Deallocate(pointer_t)
        /**
        * @class _f9a2828e_5083_4628_afe9_35d66bd17d69
        * @private
        * 
        * @copydoc _b79f3dbf_0539_495c_a245_35895bca640a
        */

        // const volatile Deallocate(pointer_t)
        /**
        * @class _7fb233cf_5433_47e9_8cd8_9fbe593b9e3a
        * @private
        * 
        * @copydoc _b79f3dbf_0539_495c_a245_35895bca640a
        */
