/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

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
*   Used to arbitrarily initialize static variables in a thread-safe and efficient manner.
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

    using void_t    = void;
    using bool_t    = bool;

    using u8_t      = uint8_t;
    using u16_t     = uint16_t;
    using u32_t     = uint32_t;
    using u64_t     = uint64_t;

    using s8_t      = int8_t;
    using s16_t     = int16_t;
    using s32_t     = int32_t;
    using s64_t     = int64_t;

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
