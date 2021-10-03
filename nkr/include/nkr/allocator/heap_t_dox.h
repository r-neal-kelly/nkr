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

        // Allocate(units_t)
        /**
        * @class _a1cd4e17_bb03_4c42_85be_fe91bb3b21f3
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

        // Allocate(pointer_t)
        /**
        * @class _1c1a3ee2_5ae4_4be1_89a0_ab555f37660d
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

        // Reallocate(units_t)
        /**
        * @class _cd380e7e_2493_42d7_837e_5f993f5c0676
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

        // Reallocate(pointer_t)
        /**
        * @class _931cb620_74fd_423d_8294_0ecb4bd0f550
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

        // Deallocate(units_t)
        /**
        * @class _fe8a3e78_0335_4de8_8283_c6a7a2a2322b
        * @private
        * 
        * @brief
        *   A wrapper for nkr::os::heap::Deallocate.
        * 
        * @param units
        *   should be a non const pointer that this function can write nullptr to after deallocating. The qualification of the unit_t itself does not matter. If given nullptr it will return without issue. See nkr::os::heap::Deallocate for more information.
        */

        // Deallocate(pointer_t)
        /**
        * @class _f9a2828e_5083_4628_afe9_35d66bd17d69
        * @private
        * 
        * @brief
        *   A wrapper for nkr::os::heap::Deallocate, but it can handle a nkr::pointer_t.
        * 
        * @param units
        *   should be a non const pointer that this function can write nullptr to after deallocating. The qualification of the unit_t itself does not matter. If given nullptr it will return without issue. See nkr::os::heap::Deallocate for more information.
        */
