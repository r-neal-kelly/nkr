/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#if _WIN64 || _WIN32
    #define nkr_IS_WINDOWS

    #if _WIN64
        #define nkr_IS_64_BIT
    #elif _WIN32
        #define nkr_IS_32_BIT
    #else
        #error "Cannot compile with this version of windows."
    #endif

    #if _DEBUG
        #define nkr_IS_DEBUG
    #else
        #define nkr_IS_RELEASE
    #endif

    #define array_ms        array
    #define generic_ms      generic
    #define interface_ms    interface

    #define array           array_
    #define generic         generic_
    #define interface       interface_
#elif 0
    #define nkr_IS_LINUX
#else
    #error "Cannot compile with this architecture."
#endif

#define nkr_BLANK
#define nkr_COMMA ,

#define nkr_DO_EXTERN_TEMPLATES

#define nkr_ASSERT_THAT(EXPRESSION_p)

#define nkr_CONSTEXPR_INHERITANCE_WRAPPER_DEFINE_CTORS(WRAPPER_p, BASE_p)

#include "nkr/macros_dec_def.h"
