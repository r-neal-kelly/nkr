/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

/**
* @defgroup _d1cd4369_e0f4_4062_8f58_611395da215e namespaces
*/

    /**
    * @class doc_nkr
    * @private
    * 
    * @brief
    *   With the exception of "nkr_" prefixed macros, all other nkr entities are defined in this namespace.
    */

/**
* @defgroup intrinsics intrinsics
*
* @brief
*   Types and macros that are available whenever you include any nkr header.
*
* @details
*   Intrinsic types are mostly helpful aliases of standard C++ types. The style of the library dictates that each type and class must have the `_t` postfix and so there are a few complementary redefinitions. However other intrinsics exist for efficiency, semantics, or both. Some help to clarify the intention of the code they appear in and some are platform dependent, but using them in the correct context can alleviate the need to use macro switches.
*/

    /**
    * @defgroup intrinsic_hints hints
    * @ingroup intrinsics
    *
    * @brief
    *   Platform dependent definitions used by macro switches.
    *
    * @details
    *   Currently Windows x64 and x86 are the only platforms that have definitions, but I'm planning on taking a look at implementing functionality for Linux. These documents are compiled with the Windows x64 branch active.
    *
    * @hideinitializer
    */

        /**
        * @class doc_nkr_nkr_IS_WINDOWS
        * @private
        */

        /**
        * @class doc_nkr_nkr_IS_LINUX
        * @private
        */

        /**
        * @class doc_nkr_nkr_IS_32_BIT
        * @private
        */

        /**
        * @class doc_nkr_nkr_IS_64_BIT
        * @private
        */

    /**
    * @defgroup intrinsics_primitives primitives
    * @ingroup intrinsics
    *
    * @brief
    *   Primitive types aliased for consistency.
    * 
    * @details
    *   Honestly, I can't stand my IDE having one color for user-defined types and another for intrinsic built-ins types.
    */

        // void_t
        /**
        * @class _dbb0c2f2_8907_4cee_8bdd_463eea2421c8
        * @private
        */

        // std_bool_t
        /**
        * @class _cf3346a3_232d_4218_9a27_facf99329980
        * @private
        * 
        * @brief
        *   Relegated to the std namespace in favor of nkr::bool_t.
        * 
        * @details
        *   The library only uses this primitive type for transient expressions and not in any data oriented way. There is no standard size for `bool` and although it is often defined with a space efficient size, such as nkr::u8_t, it is rarely a processor efficient size, which would be nkr::word_t. The library makes far wider use of nkr::bool_t, which is the same size as nkr::word_t.
        */

    /**
    * @defgroup intrinsics_integers integers
    * @ingroup intrinsics
    *
    * @brief
    *   Convenient integer types.
    *
    * @todo
    *   Add an example showing why the _t comes in useful when using integers. Also explain the u and s.
    */

        /**
        * @class doc_nkr_u8_t
        * @private
        */

        /**
        * @class doc_nkr_u16_t
        * @private
        */

        /**
        * @class doc_nkr_u32_t
        * @private
        */

        /**
        * @class doc_nkr_u64_t
        * @private
        */

        /**
        * @class doc_nkr_s8_t
        * @private
        */

        /**
        * @class doc_nkr_s16_t
        * @private
        */

        /**
        * @class doc_nkr_s32_t
        * @private
        */

        /**
        * @class doc_nkr_s64_t
        * @private
        */

    /**
    * @defgroup _17e74a8d_e977_4d08_a090_f4bb1bcf7673 characters
    * @ingroup intrinsics
    *
    * @brief
    *   Convenient character types, which are essentially integers.
    */

        // c8_t
        /**
        * @class _a878a755_773f_49d9_93c2_6567797188f1
        * @private
        */

        // c16_t
        /**
        * @class _22b18aae_67b8_49e5_855c_eb4117780773
        * @private
        */

        // c32_t
        /**
        * @class _70d1ce0d_2bb5_4a6e_ba42_c6c5fdfa5cb7
        * @private
        */

    /**
    * @defgroup _d3bf5147_2b5f_4bd4_bf99_76cf5b9932af reals
    * @ingroup intrinsics
    *
    * @brief
    *   Convenient real number types.
    */

        // r32_t
        /**
        * @class _2ad13e3a_26a3_4526_b482_a1f643d2cb99
        * @private
        */

        // r64_t
        /**
        * @class _a5fce9b9_cb18_4f58_acaf_79d2386f6bae
        * @private
        */

        // real_t
        /**
        * @class _78f7692b_f26c_44ec_b165_394190b9d273
        * @private
        * 
        * @brief
        *   Matches the nkr::word_t of the machine by selecting r32_t for 32-bit or r64_t for 64-bit.
        */

    /**
    * @defgroup intrinsics_contextuals contextuals
    * @ingroup intrinsics
    *
    * @brief
    *   Efficient context based types.
    *
    * @details
    *   These types are most commonly used on the stack, making them transitory and often only cached in small numbers. Most of them equate to the size of nkr::word_t, which has the same size as the processor's natural word. This is important when it comes to execution efficiency because the processor has to spend more time reading a variable that does not equate to its word size. Others are necessarily different sizes depending on their context.
    */

        /**
        * @class doc_nkr_word_t
        * @private
        *
        * @brief
        *   The largest natural type available, the processor's word.
        */

        // unsigned_word_t
        /**
        * @class _c815a2ce_97a5_4e93_812d_cfc107560a30
        * @private
        */

        // signed_word_t
        /**
        * @class _9007e224_d505_4ee2_8234_354e1044df0f
        * @private
        */

        /**
        * @class doc_nkr_byte_t
        * @private
        * 
        * @brief
        *   The smallest natural type available.
        */

        /**
        * @class doc_nkr_size_t
        * @private
        *
        * @brief
        *   Used for byte counts exclusively.
        */

        /**
        * @class doc_nkr_count_t
        * @private
        *
        * @brief
        *   Used for unit counts of any arbitrary type.
        */

        /**
        * @class doc_nkr_index_t
        * @private
        *
        * @brief
        *   Used for unit indices of any arbitrary array of types.
        */

        /**
        * @class doc_nkr_address_t
        * @private
        *
        * @brief
        *   Used for literal pointer math.
        */

/**
* @defgroup _7752ee81_def2_4386_b164_bc31f29ce7b8 interfaces
* 
* @brief
*   The various structs, types, and concepts with the "_i" postfix.
*/

// Common Notes

// Inheritance wrapper
/**
* @class _f66dddf5_07cc_4240_b2e2_39253f780892
* @private
* 
* @note
*   Inherits all constructors, the destructor, and all assignment operators in addition to all other members of the base class. Also defines copy and move constructors for the base to ensure that base objects can construct a new instance of this type with the `=` operator.
* 
* @par
*/

// Inheritnace wrapper base ctors
/**
* @class _3699f848_5687_47d1_92fc_7d4faf6b47a6
* @private
* 
* @note
*   This ensures that the base can construct this wrapper even with the `=` operator. This is distinct from `operator =` which can be inherited but only comes into play after an object is constructed.
* 
* @par
*/

// Handling the concept specialization bug
/**
* @class _e245fac0_078f_4cf6_852c_a42932c2ffff
* @private
* 
* @note
*   See @ref _16d56f49_95ba_456e_a026_706c054cb133 for why we use inheritance to define this specialization.
* 
* @par
*/

// Returning auto for operator &()
/**
* @class _2217847b_e23e_4253_bb7f_04ece0d5099a
* @private
* 
* @note
*   Returns auto to ensure that we don't break any `operator &` chain.
* 
* @par
*/

// Warning about using a usually private value
/**
* @class _cba26a61_2c51_4e87_90c7_26cb873a083d
* @private
* 
* @warning
*   You should only access this if you know what you're doing. Otherwise, you should use the methods, casts, and operators defined for the class.
*/

// Warning about using a usually private value through cast
/**
* @class _80a093e0_e0e5_4e31_ae14_915759c06011
* @private
* 
* @details
*   Use this only if you need to change the value directly. This is provided so that `reinterpret_cast` need not be used, which in the event that the footprint for this type changes, could potentially end up breaking code. There are legitimate uses for this, such as with nkr::atomic_t, which must treat the underlying type for what it is. Use with care.
*/
