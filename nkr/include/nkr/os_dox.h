/*
    Copyright 2021 r-neal-kelly
*/

// nkr::os
/**
* @class _ae5b9a84_c87b_4c0a_b714_4933761921d7
* @private
*
* @brief
*   Short for "Operating System", this contains several wrappers for otherwise platform specific functionality.
*/

    // nkr::os::atomic
    /**
    * @class _a6ff4022_7389_4e35_b146_066ce313290e
    * @private
    *
    * @brief
    *   Functions that provide atomic access, assignment, and exchange of variables.
    * 
    * @details
    *   These functions can be used in a threaded environment to safely read and write to various integers, booleans, and pointers. They are far more resource friendly than locks and should be used in their place as frequently as possible.
    * 
    *   There are three primary sets of these functions, each differing in whether they write to the atomic or simply read from it, and what value they return after a write. Furthermore within each set there are subsets that allow for either a read or write to be combined with a integral operator, all done in one atomic operation. Each subset consists of various overloads to provide atomics not only for booleans and integers, but for real numbers and pointers as well.
    * 
    * @note
    *   Any 64-bit functionality only works when compiling for 64-bit processors. This is because the nkr::word_t of the machine is the maximum number of bits that can be used atomically.
    * @par
    * 
    * @note
    *   In the description for each function is an expression that equates semantically but not literally. Even though there are sometimes several operations in some of the expressions, each function is still atomically thread-safe.
    * @par
    * 
    * @note
    *   Without exception, every right-hand operand is statically cast to the left-hand sides underlying type, which conforms to operating system functions which may or may not be available. Either way, the pattern remains consistent.
    * @par
    */

        // Access
        /**
        * @class _ebc609cf_5026_47e9_87e7_c8ea9ecc71a9
        * @private
        * 
        * @brief
        *   These return a copy of the atomic value without changing the original. You can combine this with other operators like you would any other variable.
        */

            // Access()
            /**
            * @class _7c65ec60_0408_4a55_8cb6_e01ed4e45aa8
            * @private
            * 
            * @brief
            *   Equivalent to `(atom)`
            * 
            * @snippet "./src/os.cpp" _86910968_68e4_4a84_9b9c_8ac16a0ac95d
            * @snippet "./src/os.cpp" _b9ee057a_7e73_4016_9503_c3920c6252d0
            */

        // Assign
        /**
        * @class _d42247f7_a7b1_442f_beef_c88857ee5682
        * @private
        *
        * @brief
        *   These return a copy of the atomic value after changing the original.
        */

            // Assign()
            /**
            * @class _fab7ff12_4852_456f_ad51_fc9ec8b5fb4f
            * @private
            *
            * @brief
            *   Equivalent to `(atom = with)`
            * 
            * @snippet "./src/os.cpp" _cff5cad0_8935_47e7_9e98_0598518c3222
            * @snippet "./src/os.cpp" _e5b23352_d0a7_4639_9b3d_4e330b3276b5
            * @snippet "./src/os.cpp" _c043156a_7642_423b_89d0_413a386ad1b4
            */

            // Assign_Add()
            /**
            * @class _ae07793f_9604_443c_901c_718a00cc093c
            * @private
            *
            * @brief
            *   Equivalent to `(atom += with)` and `(++atom)`
            * 
            * @snippet "./src/os.cpp" _c04ef484_20f3_4fc0_be4b_2d8b40dff6d5
            * @snippet "./src/os.cpp" _096ae2c4_1600_4049_ac92_d988d50936ec
            * @snippet "./src/os.cpp" _4150d822_2671_4307_9086_beb5c310d5ac
            */

            // Assign_Add(type_pointer_tr)
            /**
            * @class _cbe72d03_f920_4d4d_a53c_68537d91e06e
            * @private
            * 
            * @copydoc _ae07793f_9604_443c_901c_718a00cc093c
            * 
            * @snippet "./src/os.cpp" _dd52b045_aa56_4134_b7ff_6e00c13f892d
            * @snippet "./src/os.cpp" _462ab46f_5031_49e9_98a7_2ca50e3b17d3
            */

            // Assign_Subtract()
            /**
            * @class _61dc311f_27ca_49a9_950a_9f3c9171b715
            * @private
            *
            * @brief
            *   Equivalent to `(atom -= with)` and `(--atom)`
            * 
            * @snippet "./src/os.cpp" _548cda9b_cb3a_4cd3_954b_d69352ef3264
            * @snippet "./src/os.cpp" _f2794a9e_5c10_4ff4_a912_7ace768cddc0
            * @snippet "./src/os.cpp" _599ff640_2ddf_4edb_9a4e_e94242d25215
            */

            // Assign_Subtract(type_pointer_tr)
            /**
            * @class _165233f2_0ca5_45bf_9b4d_c09253b1700c
            * @private
            * 
            * @copydoc _61dc311f_27ca_49a9_950a_9f3c9171b715
            * 
            * @snippet "./src/os.cpp" _5b2fdcbb_2d09_4209_ad38_336f6ff3f0c3
            * @snippet "./src/os.cpp" _e396ac45_f9d6_433c_8a11_addfb4d85587
            */

            // Assign_Multiply()
            /**
            * @class _db2ab814_83b3_42b5_9c32_44dfe8126b9d
            * @private
            *
            * @brief
            *   Equivalent to `(atom *= with)`
            * 
            * @snippet "./src/os.cpp" _95ff1c60_a59e_44f6_8f24_edffeb74ca2c
            * @snippet "./src/os.cpp" _b4e15d76_ef69_4edd_a524_b50ca5cb6821
            * @snippet "./src/os.cpp" _37851c52_0ed4_4b15_a024_657fa6449913
            */

            // Assign_Divide()
            /**
            * @class _388e4f09_010e_4578_8cc7_2255da0a4b4c
            * @private
            *
            * @brief
            *   Equivalent to `(atom /= with)`
            * 
            * @snippet "./src/os.cpp" _88dfcc83_1a76_4d84_8196_b4a5582ac05a
            * @snippet "./src/os.cpp" _8880d6ac_53f3_4f80_9f8e_2141566a5dfb
            * @snippet "./src/os.cpp" _16308dc7_620e_43b4_8682_95947cce466b
            */

            // Assign_Modulus()
            /**
            * @class _76252e5c_09e8_446b_82dc_295f1dc684d2
            * @private
            *
            * @brief
            *   Equivalent to `(atom %= with)`
            * 
            * @snippet "./src/os.cpp" _f08cbcd4_5eb9_4df6_a8eb_43a5ab642f1f
            * @snippet "./src/os.cpp" _83b37b61_a830_4c1a_a280_4d947b25f183
            */

            // Assign_Or()
            /**
            * @class _3f60e4fa_e39f_4e59_b88c_610282e72227
            * @private
            *
            * @brief
            *   Equivalent to `(atom |= with)`
            * 
            * @snippet "./src/os.cpp" _f5a67175_71e4_4e40_875d_0b649b258584
            * @snippet "./src/os.cpp" _72fe08fb_efd6_41ad_b45d_1e13fa595118
            */

            // Assign_And()
            /**
            * @class _50094866_0d5e_4d6e_8003_080350799b02
            * @private
            *
            * @brief
            *   Equivalent to `(atom &= with)`
            * 
            * @snippet "./src/os.cpp" _8abe8ccb_90fd_4ae8_971f_a31fa3b61318
            * @snippet "./src/os.cpp" _8b6d9f33_1845_4a13_999c_219390bfad89
            */

            // Assign_Xor()
            /**
            * @class _f6c4cd5b_7f03_477b_968b_b65a1d79c37b
            * @private
            *
            * @brief
            *   Equivalent to `(atom ^= with)`
            * 
            * @snippet "./src/os.cpp" _6a119048_abc7_41e9_8eed_756ba39191c5
            * @snippet "./src/os.cpp" _a88aea13_e8e8_4f55_a568_b48bfb7c666b
            */

            // Assign_Left_Shift()
            /**
            * @class _1988a49f_e149_41e5_acf1_5ee55d64e7a9
            * @private
            *
            * @brief
            *   Equivalent to `(atom <<= with)`
            * 
            * @snippet "./src/os.cpp" _d34f4b0d_94d7_4cee_8275_2986169ee4bb
            * @snippet "./src/os.cpp" _7293a041_ac89_40d6_851c_2fcc5fa87cfc
            */

            // Assign_Right_Shift()
            /**
            * @class _33d2bc67_7ea7_4519_83e6_0145d0c4c10d
            * @private
            *
            * @brief
            *   Equivalent to `(atom >>= with)`
            * 
            * @snippet "./src/os.cpp" _35470cf4_9526_436e_9e4d_1260a7f5da36
            * @snippet "./src/os.cpp" _fac50b5b_9154_4619_a9f6_e9a8932be1d6
            */

        // Exchange
        /**
        * @class _73d8454a_28bc_4509_b695_6bd373d375f2
        * @private
        *
        * @brief
        *   These return a copy of the original value before operating upon it.
        * 
        * @details
        *   Many of these functions could actually be combined together into a simpler set amounting to the same functionality. However doing it this way allows for optimizations that otherwise would be missed. Some of these functions have direct operating system calls they can use while others are implemented using the Exchange_If_Equals functions. An implementor of the library can make use of this assortment of funcitons to add optimizations that even the operating system and compiler are missing by talking directly to the processor.
        * 
        * In any case, even the functions that are implemented with the Exchange_If_Equals functions are way faster than using other locking techniques and so everything in here is a good alternative if you can design your program to use them, either directly or through the nkr::atomic_T interface.
        */

            // Exchange()
            /**
            * @class _d3109948_6d58_465c_9c35_1b3bc078193b
            * @private
            *
            * @brief
            *   Equivalent to `(original = atom, atom = with, original)`
            * 
            * @snippet "./src/os.cpp" _bfb8a372_e1f9_4422_97e1_e6ba09bf5447
            * @snippet "./src/os.cpp" _ad652bfb_c5e7_4f7c_a44a_96bc9926770a
            * @snippet "./src/os.cpp" _6ff73bc8_9314_4d30_9ff1_f6075f14a765
            */

            // Exchange_Add()
            /**
            * @class _1636a842_cd0e_4a20_a69b_08777cf45e13
            * @private
            *
            * @brief
            *   Equivalent to `(original = atom, atom += with, original)` and `(atom++)`
            * 
            * @snippet "./src/os.cpp" _49848ac8_c1b4_4943_a696_01ad844ba232
            * @snippet "./src/os.cpp" _63e6d632_7ff2_4ef9_81d7_99ba01619d4c
            * @snippet "./src/os.cpp" _658a6304_5262_4da9_81ff_3a20dfb2416b
            */

            // Exchange_Add(type_pointer_tr)
            /**
            * @class _cc0888ae_0348_4464_8425_d59c2563a3b9
            * @private
            * 
            * @copydoc _1636a842_cd0e_4a20_a69b_08777cf45e13
            * 
            * @snippet "./src/os.cpp" _2ba66e6c_3839_4110_8317_6ff0d84e56bc
            * @snippet "./src/os.cpp" _e68df812_6fdb_4279_a4e5_276d1e532426
            */

            // Exchange_Subtract()
            /**
            * @class _be5c47cb_bbce_4c8f_b1c9_f6f5564b1727
            * @private
            *
            * @brief
            *   Equivalent to `(original = atom, atom -= with, original)` and `(atom--)`
            * 
            * @snippet "./src/os.cpp" _5af84e35_a73e_447e_a291_11cad13fc45a
            * @snippet "./src/os.cpp" _14b2395b_d7eb_4d35_ab27_d2483b376004
            * @snippet "./src/os.cpp" _83dfbe1a_86a9_42b8_bb6b_b4ad5b264a4a
            */

            // Exchange_Subtract(type_pointer_tr)
            /**
            * @class _4160b14b_f8e3_4e5b_8340_b8e9285d1caa
            * @private
            * 
            * @copydoc _be5c47cb_bbce_4c8f_b1c9_f6f5564b1727
            * 
            * @snippet "./src/os.cpp" _8834bbe1_d6e2_4813_b90f_2536b00eba99
            * @snippet "./src/os.cpp" _536ea92e_bc98_402d_b22f_3ae2a338f694
            */

            // Exchange_Multiply()
            /**
            * @class _9b10e14c_d868_4740_b2dd_40ee361019f0
            * @private
            *
            * @brief
            *   Equivalent to `(original = atom, atom *= with, original)`
            * 
            * @snippet "./src/os.cpp" _5ae68f89_6432_4aac_a8c7_977f268bb34d
            * @snippet "./src/os.cpp" _58db82c9_bce0_4cc6_990b_644fbce87a59
            * @snippet "./src/os.cpp" _91df7f02_eabd_40c6_8255_cd4c64e92e82
            */

            // Exchange_Divide()
            /**
            * @class _0c2871ea_dbfa_4075_bee1_84f0017ec54c
            * @private
            *
            * @brief
            *   Equivalent to `(original = atom, atom /= with, original)`
            * 
            * @snippet "./src/os.cpp" _fae67eda_9402_4e49_9607_e3184dbd2b38
            * @snippet "./src/os.cpp" _c3947eeb_8969_4edb_8130_49d6ff2ac2fd
            * @snippet "./src/os.cpp" _1cc9dcb3_26b4_4499_8cd5_8db780bdca8c
            */

            // Exchange_Modulus()
            /**
            * @class _75c6f727_7922_4ce2_8650_5c94e52b180e
            * @private
            *
            * @brief
            *   Equivalent to `(original = atom, atom %= with, original)`
            * 
            * @snippet "./src/os.cpp" _e5451fea_cc5f_4ebc_b5d5_8b08c3a111da
            * @snippet "./src/os.cpp" _9c67480d_25d1_41ad_8030_63335bf8ea23
            */

            // Exchange_Or()
            /**
            * @class _67e27237_78f0_4fe0_b667_15076d266dbc
            * @private
            *
            * @brief
            *   Equivalent to `(original = atom, atom |= with, original)`
            * 
            * @snippet "./src/os.cpp" _b174d2e7_5cb0_407a_8657_991c0f444ba4
            * @snippet "./src/os.cpp" _7f93e7c5_8e50_44fa_8b7d_459a5b7a349a
            */

            // Exchange_And()
            /**
            * @class _43f052df_aa5c_4c1d_be58_1059147ba0c1
            * @private
            *
            * @brief
            *   Equivalent to `(original = atom, atom &= with, original)`
            * 
            * @snippet "./src/os.cpp" _f22797a7_89bc_4b21_bb54_4821a254fef8
            * @snippet "./src/os.cpp" _032da151_3782_47dc_a9fe_9bfa1ead41ca
            */

            // Exchange_Xor()
            /**
            * @class _46e8118f_a77b_41c8_9f75_d1953aad71d8
            * @private
            *
            * @brief
            *   Equivalent to `(original = atom, atom ^= with, original)`
            * 
            * @snippet "./src/os.cpp" _8aff4d56_ead1_4706_8a83_7ffe39b94dea
            * @snippet "./src/os.cpp" _b5a97fce_b8a8_46de_a777_b6b40b4094b2
            */

            // Exchange_Left_Shift()
            /**
            * @class _a5e26340_6895_4258_ab06_7f6968cd5830
            * @private
            *
            * @brief
            *   Equivalent to `(original = atom, atom <<= with, original)`
            * 
            * @snippet "./src/os.cpp" _50e9921e_8412_4549_b13a_b999679ad0be
            * @snippet "./src/os.cpp" _36e6f4c1_7bf0_4e1f_abeb_95fd6c7f4a6a
            */

            // Exchange_Right_Shift()
            /**
            * @class _37998d5d_eb21_4e93_83bf_ef1bfb1152c7
            * @private
            *
            * @brief
            *   Equivalent to `(original = atom, atom >>= with, original)`
            * 
            * @snippet "./src/os.cpp" _6e658448_1e1f_4055_9f66_e194035f5573
            * @snippet "./src/os.cpp" _db165fe2_b8b4_4056_aabd_a62cad104e6a
            */

            // Exchange_If_Equals()
            /**
            * @class _58b2d01f_9868_4a75_a3c8_da7371ab555e
            * @private
            *
            * @brief
            *   Equivalent to `(atom == snapshot ? (atom = with, true) : (snapshot = atom, false))`
            * 
            * @snippet "./src/os.cpp" _034843e4_e0d0_4f52_8f78_c3f56925da13
            * @snippet "./src/os.cpp" _0be1610a_27fa_4ad6_90b8_13a3fc51a126
            * @snippet "./src/os.cpp" _03edfad8_0c53_4b7c_b3e6_6e718f150abb
            * @snippet "./src/os.cpp" _8fa4472e_33c7_4135_a485_5ce05496cdf1
            * @snippet "./src/os.cpp" _55c80c7e_e54b_43fc_bc79_de6b25a4dfa8
            * @snippet "./src/os.cpp" _449b38fb_4737_41b7_80b0_3ab13221ffcc
            */

    // nkr::os::endian
    /**
    * @class _652312c1_72a2_4b36_88ab_aee6adf8e9c9
    * @private
    *
    * @brief
    *   Functions that provide various information and solutions regarding endianness.
    */

        // Info
        /**
        * @class _026b191f_2e76_4010_9760_e1215a647d9c
        * @private
        *
        * @brief
        *   Attain info regarding the endianness of the current processor you're running on.
        *
        * @details
        *   This is a thread-safe and efficient way of determining whether or not a computer is processing data in big or little endian. This is important to know when dealing with data that may have been written by or is intended to be read by another computer that has a different endianness than the one you are operating on. There are times when you need to know if you should swap your compound integer types to a different endianness or not.
        * 
        * @note
        *   The first time either of these functions are called they will be slightly inefficient, however any sucessive calls will be lightning fast.
        */

            // Is_Big()
            /**
            * @class _9d5ef4e6_ff8f_4d63_9fdc_0c0422259d90
            * @private
            * 
            * @snippet "./src/os.cpp" _2367da3d_58c3_4a8f_98c4_c9d8c809cb25
            */

            // Is_Little()
            /**
            * @class _884ae9eb_da64_4306_aab9_50aeb3f85298
            * @private
            * 
            * @snippet "./src/os.cpp" _e5a7621e_6b04_42ef_b8d2_94d576abb57e
            */

        // Swap
        /**
        * @class _b5b179fb_1f64_485e_9510_80260e3a6c33
        * @private
        *
        * @brief
        *   Invert the order of bytes in a multi-byte number.
        * 
        * @details
        *   These are useful when you are dealing with data that was either written by or will be read by a processor that has a different endianness than the one your program is executing on.
        *
        * @note
        *   There is no nkr::integer_8_tr variant because a byte or a stream of bytes cannot have a different endianness but is read and written the same on both kinds of computers.
        * @par
        * 
        * @note
        *   You need to be careful when trying to swap literal numbers as shown in the following example:
        * @par
        * 
        * @snippet "./src/os.cpp" _8204605f_3b41_4633_8865_89d336420022
        */

            // Swap(integer_16_tr)
            /**
            * @class _857ce8b6_02ca_48e5_9d19_4a7581b8e4c6
            * @private
            * 
            * @snippet "./src/os.cpp" _6bc67519_2af0_4999_a15c_ad085acb68e4
            * @snippet "./src/os.cpp" _962de4de_8f29_4f35_9ffb_123ac19b3cf8
            */

            // Swap(integer_32_tr)
            /**
            * @class _02c0499c_c8c8_43b9_8afc_96545310eb3a
            * @private
            * 
            * @snippet "./src/os.cpp" _d480540a_cabf_45d6_b3dc_0882dca2569b
            * @snippet "./src/os.cpp" _59caf647_91bb_4926_b0d0_401183e97ded
            */

            // Swap(integer_64_tr)
            /**
            * @class _eabf9a88_080f_445d_88ab_b0dae4a55316
            * @private
            * 
            * @snippet "./src/os.cpp" _52a0d032_dab3_4a2e_a06a_67bc56f297f4
            * @snippet "./src/os.cpp" _70f7b676_8069_4eec_93bf_007c172f1e39
            */

    // nkr::os::heap
    /**
    * @class _a6c4699b_8fe4_4664_ac57_062765decc2b
    * @private
    *
    * @brief
    *   Functions that interface with memory located on the heap. Primarily, this is an extension of the standard C library Allocation methods `malloc`, `realloc`, `free`, `calloc` and a handful of OS specific extensions, such as a function to reallocate zero-initialized memory where available.
    */

        // Allocation
        /**
        * @class _30c0ffe4_d85f_45e5_ab29_bd3f18629cb9
        * @private
        *
        * @brief
        *   Borrow a certain amount of memory from the heap. Use it, expand it, and give it back.
        */

            // Allocate()
            /**
            * @class _52a0d839_49c8_4d77_93b1_353137fecd3b
            * @private
            *
            * @brief
            *   Gives you memory to use until you deallocate it or your program exits.
            * 
            * @param units
            *   is a type pointer that may or may not be set to the allocated memory. Asserts if given anything but a nullptr, which may help stop you from making a memory leak.
            * 
            * @param unit_count
            *   is the number of units (objects) that space will be allocated for. No objects are constructed. If the unit_count is zero, units remains a nullptr and no error is returned. Asserts if unit_count is greater than the max number of units that can be allocated, which equates to the maximum number of bytes that can fit in a nkr::count_t divided by the size of the type.
            *
            * @returns
            *   nkr::allocator_err::NONE if it succeeds.
            * 
            * @returns
            *   nkr::allocator_err::OUT_OF_MEMORY if it fails.
            * 
            * @details
            *   There are a few limitations to the number of bytes you can allocate depending on:
            * 
            *   1. how much ram is physically in the computer
            *   2. how much space the operating system has left to give
            *   3. the settings that your compiler operates with
            *   4. what the natural word size of the processor is
            * 
            *   At most the largest number of bytes you will be able to allocate is the max number that can fit in an nkr::count_t (an alias of nkr::word_t). If you are running on a 32 bit processor you will only be able to allocate one byte shy of 4gb, which is no where near the amount of memory you can allocate on a 64 bit processor. Furthermore, limitations may come into play depending on the operating system, which may significantly decrease that amount even further.
            * 
            * @snippet "./src/os.cpp" _a06ecc73_e7ac_43b2_b231_059675458c15
            */

            // Reallocate()
            /**
            * @class _06fa627b_ba42_4b70_b0dd_66146e6d863a
            * @private
            *
            * @brief
            *   Gives you more memory without loosing any of the previously allocated memory.
            *
            * @param units
            *   should be a pointer set by nkr::os::heap::Allocate or nkr::os::heap::Reallocate, with the exception of `nullptr`, which is also allowed. When successful, it will be set to a new pointer if necessary, or else it will be left unchanged. When given a nullptr this functions exactly like nkr::os::heap::Allocate.
            *
            * @param new_unit_count
            *   is the total number of units (objects) that may be allocated after this function returns, that is the previous total allocated units plus however many more you require, and thus it should be the total size you want the memory to be. If new_unit_count equals zero and units is not nullptr, it acts exactly like nkr::os::heap::Deallocate. If new_unit_count equals zero and units is nullptr, it returns without error.
            *
            * @returns
            *   nkr::allocator_err::NONE if it succeeds.
            *
            * @returns
            *   nkr::allocator_err::OUT_OF_MEMORY if it fails. Does not alter units.
            *
            * @details
            *   This will allocate more memory for you if the new count is greater than the previously allocated count. It will shrink the amount of memory if the new count is less than the previously allocated count. See nkr::os::heap::Allocate for more details about allocation generally.
            * 
            * @snippet "./src/os.cpp" _3c97398a_6fe6_4b47_81a2_18efd5ab72d5
            */

            // Deallocate()
            /**
            * @class _de0237bf_9b0a_47fc_a5ab_99f21504f570
            * @private
            *
            * @brief
            *   Takes back memory you no longer need so it can be reused later.
            *
            * @param units
            *   should be a pointer set by nkr::os::heap::Allocate or nkr::os::heap::Reallocate. It will be set to `nullptr` after deallocation. If it is already `nullptr`, the function returns as if it was already successful.
            *
            * @details
            *   When using these functions, memory will never be deallocated automatically for you like it is in some higher level types. You will have to manually deallocate every pointer you allocate through these functions, or else you may unexpectedly run out of memory. Regardless, the operating system will deallocate everything that has not already been deallocated by you when your program exits.
            * 
            * @snippet "./src/os.cpp" _09113b05_5f70_459c_9827_f53c58816243
            */

        // Zero-Initialized Allocation
        /**
        * @class _eca47636_431b_4d2a_a102_679075b3cf17
        * @private
        *
        * @brief
        *   A variant of regular allocation, the difference being that all the values in your memory will be initialized to zero.
        */

            // Allocate_Zeros()
            /**
            * @class _9c5a7296_5644_47bf_bd3f_ff7de3518ce9
            * @private
            *
            * @brief
            *   Gives you zero-initialized memory to use until your program exits.
            *
            * @param units
            *   is a type pointer that may or may not be set to the allocated memory. Asserts if given anything but a nullptr, which may help stop you from making a memory leak.
            * 
            * @param unit_count
            *   is the number of units (objects) that space will be allocated for. No objects are constructed. If the unit_count is zero, units remains a nullptr and no error is returned. Asserts if unit_count is greater than the max number of units that can be allocated, which equates to the maximum number of bytes that can fit in a nkr::count_t divided by the size of the type.
            *
            * @returns
            *   nkr::allocator_err::NONE if it succeeds.
            * 
            * @returns
            *   nkr::allocator_err::OUT_OF_MEMORY if it fails.
            *
            * @details
            *   This uses an efficient operating system dependent algorithm to avoid zeroing out all values during runtime if possible. Normally the os will keep pages of zero initialized bytes ready for allocation and it will only need to initialize them on the occasion that it doesn't have any of those pages readily available. Please see nkr::os::heap::Allocate for more details about allocation generally.
            *
            * @note
            *   The returned pointer can be used with nkr::os::heap::Reallocate to allocate more memory but without it being zero-intialized, and nkr::os::heap::Deallocate to free the memory. Both of these are currently frowned upon because they may not work in future updates or on certain operating systems.
            * @par
            * 
            * @snippet "./src/os.cpp" _fc02c748_8572_4062_b2b1_8cfaa78bc002
            */

            // Reallocate_Zeros()
            /**
            * @class _7d7887a0_3e2d_4502_af8c_d409aae73f0b
            * @private
            * 
            * @brief
            *   Gives you more zero-initialized memory without loosing any of the previously allocated memory.
            *
            * @param units
            *   should be a pointer set by nkr::os::heap::Allocate_Zeros or nkr::os::heap::Reallocate_Zeros, with the exception of `nullptr`, which is also allowed. When successful, it will be set to a new pointer if necessary, or else it will be left unchanged. When given a nullptr this functions exactly like nkr::os::heap::Allocate_Zeros.
            *
            * @param new_unit_count
            *   is the total number of units (objects) that may be allocated after this function returns, that is the previous total allocated units plus however many more you require, and thus it should be the total size you want the memory to be. If new_unit_count equals zero and units is not nullptr, it acts exactly like nkr::os::heap::Deallocate_Zeros. If new_unit_count equals zero and units is nullptr, it returns without error.
            *
            * @returns
            *   nkr::allocator_err::NONE if it succeeds.
            *
            * @returns
            *   nkr::allocator_err::OUT_OF_MEMORY if it fails. Does not alter units.
            *
            * @details
            *   Please see nkr::os::heap::Reallocate for more details.
            * 
            * @snippet "./src/os.cpp" _831dc6ca_17bd_4515_9fd9_48f36c1014da
            */

            // Deallocate_Zeros()
            /**
            * @class _04d9a3fe_30b3_4ae2_bbc4_2a3cfc4768d6
            * @private
            * 
            * @brief
            *   Takes back memory you no longer need so it can be reused later.
            *
            * @param units
            *   should be a pointer set by nkr::os::heap::Allocate_Zeros or nkr::os::heap::Reallocate_Zeros. It will be set to `nullptr` after deallocation. If it is already `nullptr`, the function returns as if it was already successful.
            *
            * @details
            *   Please see nkr::os::heap::Deallocate for more details.
            * 
            * @note
            *   This does not zero the memory.
            * @par
            * 
            * @snippet "./src/os.cpp" _6c279b29_119d_4ca0_8c6a_552cb9ea6431
            */
