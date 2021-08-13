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

#define nkr_M do {
#define nkr_W } while(false);

#define nkr_INITIALIZE_STATIC_SAFELY(INITIALIZER_p)     \
nkr_M                                                   \
    static volatile bool_t is_initialized = false;      \
    if (os::atomic::Access(is_initialized) == false) {  \
        static std::mutex lock;                         \
        std::lock_guard<std::mutex> locker(lock);       \
        if (!is_initialized) {                          \
            INITIALIZER_p();                            \
            os::atomic::Assign(is_initialized, true);   \
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
