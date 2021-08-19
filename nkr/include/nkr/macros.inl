/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/macros.h"

namespace nkr {

    #undef nkr_M
    #undef nkr_W

    #undef nkr_P
    #undef nkr_b

    #undef nkr_INITIALIZE_STATIC_SAFELY

    #define nkr_M   \
        (

    #define nkr_W   \
        )

    #define nkr_P   \
        do {

    #define nkr_b       \
        } while(false)

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

}
