/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_4e84ae6c_af8d_49ac_85c6_6edc16080b6a
#define nkr_INCLUDE_GUARD_4e84ae6c_af8d_49ac_85c6_6edc16080b6a

// These must be defined by CMake.
#if !defined(nkr_IS_WINDOWS) && !defined(nkr_IS_LINUX)
    #error "Cannot compile with an unknown operating system."
#endif

#if !defined(nkr_IS_32_BIT) && !defined(nkr_IS_64_BIT)
    #error "Cannot compile with an unknown word size."
#endif

#if !defined(nkr_IS_DEBUG) && !defined(nkr_IS_RELEASE)
    #error "Cannot compile with an unknown build mode."
#endif

#if nkr_IS_WINDOWS
    #define array_ms        array
    #define generic_ms      generic
    #define interface_ms    interface

    #define array           array_
    #define generic         generic_
    #define interface       interface_
#endif

#define nkr_BLANK
#define nkr_COMMA ,

#define nkr_DO_EXTERN_TEMPLATES

#define nkr_ASSERT_THAT(EXPRESSION_p)

#define nkr_CONSTEXPR_INHERITANCE_WRAPPER_DEFINE_CTORS(WRAPPER_p, BASE_p)

#include "nkr/macros_dec_def.h"

#endif
