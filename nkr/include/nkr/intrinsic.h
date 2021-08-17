/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include <cassert>
#include <cerrno>
#include <cstdint>

#include <concepts>
#include <limits>
#include <memory>
#include <utility>

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
* @defgroup intrinsics_macros macros
* @ingroup intrinsics
* 
* @brief
*   Namespaced macros that provide solutions otherwise difficult to achieve.
* 
* @todo
*   Provide details
*/

/**
* @defgroup intrinsics_macros_hints hints
* @ingroup intrinsics_macros
*
* @brief
*   Platform dependent definitions for macro switches.
*
* @details
*   Currently Windows x64 and x86 are the only platforms that have definitions, but I'm planning on taking a look at implementing functionality for Linux. These documents are compiled with the Windows x64 branch active.
*
* @todo
*   Give an example, also compare with functional macros.
* 
* @hideinitializer
*/
/** @{ **/
#if _WIN64 || _WIN32
    #define nkr_IS_WINDOWS
    #if _WIN64
        #define nkr_IS_64_BIT
    #elif _WIN32
        #define nkr_IS_32_BIT
    #else
        #error "Cannot compile with this version of windows."
    #endif
#elif 0
    #define nkr_IS_LINUX
#else
    #error "Cannot compile with this architecture."
#endif
/** @} **/

/**
* @defgroup intrinsics_macros_braces braces
* @ingroup intrinsics_macros
* 
* @brief
*   Symbols used to delimit a macro's body.
* 
* @details
*   The one set is used for functional macros which return values and the other set for procedural macros which simply alter state without returning any values. These are only useful when you're defining a macro, otherwise you should not need to use them.
* 
* @todo
*   Give an example.
* 
* @hideinitializer
*/
/** @{ **/
/// The opening brace for functional macros.
#define nkr_M   \
    (

/// The closing brace for functional macros.
#define nkr_W   \
    )

/// The opening brace for procedural macros.
#define nkr_P   \
    do {

/// The closing brace for procedural macros.
#define nkr_b   \
    } while(false)
/** @} **/

/**
* @ingroup intrinsics_macros
*
* @brief
*   Uses an arbitrary initializer to ready static variables in a thread-safe and efficient manner.
* 
* @par Macro Type
*   Procedural
*
* @param INITIALIZER_p
*   A function or lambda that initializes static data.
* 
* @par Requires
*   ```cpp
*   #include <mutex>
*   #include "nkr/os.h"
*   ```
*
* @todo
*   Use the snippet command to include an example of this macro. Also this should be put in a proceduarl group
*
* @details
*   In C++11 and later, static objects are intialized in a thread-safe manner through their constructors. However, not all data is subject to being defined in a class, and hence this macro acts as an on-the-fly constructor for arbitrary static data declared and defined at your discretion.
*
*   It uses an atomic nkr::bool_t to flag initialization so that more expensive thread-safe components are elided after execution of your initializer.
*
* @hideinitializer
*/
#define nkr_INITIALIZE_STATIC_SAFELY(INITIALIZER_p)     \
nkr_P                                                   \
    static volatile bool_t is_initialized = false;      \
    if (os::atomic::Access(is_initialized) == false) {  \
        static std::mutex lock;                         \
        std::lock_guard<std::mutex> locker(lock);       \
        if (!is_initialized) {                          \
            INITIALIZER_p();                            \
            is_initialized = true;                      \
        }                                               \
    }                                                   \
nkr_b

/**
* @brief
*   With the exception of intrinsic macros, all other nkr entities are defined in this namespace.
*/
namespace nkr {

    /**
    * @defgroup intrinsics_primitives primitives
    * @ingroup intrinsics
    * 
    * @brief
    *   Primitive types aliased for consistency.
    */
    /** @{ **/
    using void_t    = void;
    using bool_t    = bool;
    /** @} **/

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
    /** @{ **/
    using u8_t      = std::uint8_t;
    using u16_t     = std::uint16_t;
    using u32_t     = std::uint32_t;
    using u64_t     = std::uint64_t;
    using s8_t      = std::int8_t;
    using s16_t     = std::int16_t;
    using s32_t     = std::int32_t;
    using s64_t     = std::int64_t;
    /** @} **/

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
    /** @{ **/
    using byte_t    = u8_t;             ///< The smallest natural type available.
    using word_t    = std::size_t;      ///< The largest natural type available, the processor's word.
    using size_t    = word_t;           ///< Used for byte counts exclusively.
    using count_t   = word_t;           ///< Used for unit counts of any arbitrary type.
    using index_t   = word_t;           ///< Used for unit indices of any arbitrary array of types.
    using address_t = std::uintptr_t;   ///< Used for literal pointer math.
    /** @} **/

#if defined(nkr_IS_32_BIT)
    static_assert(sizeof(std::size_t) == sizeof(u32_t), "You need to manually set word_t to u32_t.");
#elif defined(nkr_IS_64_BIT)
    static_assert(sizeof(std::size_t) == sizeof(u64_t), "You need to manually set word_t to u64_t.");
#endif

}
