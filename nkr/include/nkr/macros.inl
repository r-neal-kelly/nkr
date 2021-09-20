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

    #undef nkr_DEFINE_INHERITANCE_WRAPPER_CTORS_AND_DTOR
    #undef nkr_DEFINE_INHERITANCE_WRAPPER_BASE_ACCESSORS

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

    #define nkr_DEFINE_INHERITANCE_WRAPPER_CTORS_AND_DTOR(WRAPPER_p, BASE_p)                                \
        WRAPPER_p() = default;                                                                              \
                                                                                                            \
        WRAPPER_p(const WRAPPER_p& other) = default;                                                        \
                                                                                                            \
        WRAPPER_p(volatile const WRAPPER_p& other) :                                                        \
            BASE_p(static_cast<volatile const BASE_p&>(other))                                              \
        {                                                                                                   \
        }                                                                                                   \
                                                                                                            \
        WRAPPER_p(WRAPPER_p&& other) noexcept = default;                                                    \
                                                                                                            \
        WRAPPER_p(volatile WRAPPER_p&& other) noexcept :                                                    \
            BASE_p(static_cast<volatile BASE_p&&>(std::move(other)))                                        \
        {                                                                                                   \
        }                                                                                                   \
                                                                                                            \
        WRAPPER_p& operator =(const WRAPPER_p& other) = default;                                            \
                                                                                                            \
        volatile WRAPPER_p& operator =(volatile const WRAPPER_p& other) volatile                            \
        {                                                                                                   \
            BASE_p::operator =(static_cast<volatile const BASE_p&>(other));                                 \
            return *this;                                                                                   \
        }                                                                                                   \
                                                                                                            \
        auto& operator =(is_tr<WRAPPER_p> auto&& other) noexcept                                            \
        {                                                                                                   \
            BASE_p::operator =(static_cast<BASE_p&&>(std::move(other)));                                    \
            return *this;                                                                                   \
        }                                                                                                   \
                                                                                                            \
        volatile auto& operator =(volatile is_tr<volatile WRAPPER_p> auto&& other) volatile noexcept        \
        {                                                                                                   \
            BASE_p::operator =(static_cast<volatile BASE_p&&>(std::move(other)));                           \
            return *this;                                                                                   \
        }                                                                                                   \
                                                                                                            \
        ~WRAPPER_p() = default;

    #define nkr_DEFINE_INHERITANCE_WRAPPER_BASE_ACCESSORS(ACCESSOR_NAME_p, BASE_p)  \
        BASE_p& ACCESSOR_NAME_p()                                                   \
        {                                                                           \
            return *static_cast<BASE_p*>(this);                                     \
        }                                                                           \
                                                                                    \
        const BASE_p& ACCESSOR_NAME_p() const                                       \
        {                                                                           \
            return *static_cast<const BASE_p*>(this);                               \
        }                                                                           \
                                                                                    \
        volatile BASE_p& ACCESSOR_NAME_p() volatile                                 \
        {                                                                           \
            return *static_cast<volatile BASE_p*>(this);                            \
        }                                                                           \
                                                                                    \
        volatile const BASE_p& ACCESSOR_NAME_p() volatile const                     \
        {                                                                           \
            return *static_cast<volatile const BASE_p*>(this);                      \
        }

}
