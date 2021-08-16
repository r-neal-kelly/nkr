/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

/**
* @file
* @brief
*   Contains types and macros made availabe whenever you include any nkr header.
* @details
*   The types are mostly aliases of C++ types. The style of the library dictates
*   that each type and class must have the `_t` postfix and so we alias some
*   otherwise unchanged types. Some of these intrinsics exist soley for semantic
*   reasons, to help clarify their purpose in context. They are all platform
*   independent, so using them can decrease the need for any macro switches in
*   your code.
*/

#include <cassert>
#include <concepts>
#include <cstdint>
#include <limits>
#include <memory>
#include <utility>

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
#elif 0
    #define nkr_IS_MAC
#else
    #error "Cannot compile with this architecture."
#endif

#define nkr_M   \
    do {
#define nkr_W   \
    } while(false);

/**
* @brief
*   Arbitrarily initialize static variables in a thread-safe and efficient manner.
* @param INITIALIZER_p
*   A function or lambda that initializes static data.
* @return
*   nkr::void_t
* @par Requires
*   ```cpp
*   #include <mutex>
*   #include "nkr/os.h"
*   ```
* @todo
*   Use the snippet command to include an example of this macro.
* @details
*   In C++11 and later, static objects are intialized in a thread-safe manner through their
*   constructors. However, not all data is subject to being defined in a class, and hence
*   this macro acts as an on-the-fly constructor for arbitrary static data declared and
*   defined at your discretion.
* 
*   It uses an atomic nkr::bool_t to flag initialization so that more expensive thread-safe
*   components are elided after execution of your initializer.
* @hideinitializer
*/
#define nkr_INITIALIZE_STATIC_SAFELY(INITIALIZER_p)     \
nkr_M                                                   \
    static volatile bool_t is_initialized = false;      \
    if (os::atomic::Access(is_initialized) == false) {  \
        static std::mutex lock;                         \
        std::lock_guard<std::mutex> locker(lock);       \
        if (!is_initialized) {                          \
            INITIALIZER_p();                            \
            is_initialized = true;                      \
        }                                               \
    }                                                   \
nkr_W

namespace nkr {

    /**
    * @name primitives
    * @brief
    *   Aliased in order to have a consistent naming scheme.
    * @{
    */
    using void_t    = void;
    using bool_t    = bool;
    /**
    * @}
    */

    /**
    * @name unsigned integers
    * @brief
    *   Convenient aliases for unsigned integers.
    * @todo
    *   Add an example showing why the _t comes in useful when using integers
    * @{
    */
    using u8_t      = uint8_t;
    using u16_t     = uint16_t;
    using u32_t     = uint32_t;
    using u64_t     = uint64_t;
    /**
    * @}
    */

    /**
    * @name signed integers
    * @brief
    *   Convenient aliases for signed integers
    * @todo
    *   Add an example showing why the _t comes in useful when using integers
    * @{
    */
    using s8_t      = int8_t;
    using s16_t     = int16_t;
    using s32_t     = int32_t;
    using s64_t     = int64_t;
    /**
    * @}
    */

    using byte_t    = u8_t;
#if defined(nkr_IS_32_BIT)
    using word_t    = u32_t;
#elif defined(nkr_IS_64_BIT)
    using word_t    = u64_t;
#endif

    using size_t    = word_t;
    using count_t   = word_t;
    using index_t   = word_t;
    using address_t = uintptr_t;

}
