/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsics.h"

namespace nkr {

    /// @ingroup macros_braces
    /// @{
    #define nkr_M   ///< @copydoc doc_nkr_nkr_M
    #define nkr_W   ///< @copydoc doc_nkr_nkr_W

    #define nkr_P   ///< @copydoc doc_nkr_nkr_P
    #define nkr_b   ///< @copydoc doc_nkr_nkr_b
    /// @}
    

    /// @ingroup macros_procedures
    /// @{
    #define nkr_INITIALIZE_STATIC_SAFELY(INITIALIZER_p) ///< @copydoc doc_nkr_nkr_INITIALIZE_STATIC_SAFELY
    /// @}

    /// @{
    #define nkr_DEFINE_INHERITANCE_WRAPPER_CTORS_AND_DTOR(WRAPPER_p, BASE_p)
    #define nkr_DEFINE_INHERITANCE_WRAPPER_BASE_ACCESSORS(ACCESSOR_NAME_p, BASE_p)

    #define nkr_DEFINE_NOT_TRAIT_WITH_1_PARAM(TRAIT_p, PARAM_1_p)
    #define nkr_DEFINE_NOT_TRAIT_WITH_2_PARAMS(TRAIT_p, PARAM_1_p, PARAM_2_p)
    #define nkr_DEFINE_CONTAINER_TRAITS(CONTAINER_NAME_p)
    /// @}

}

#include "nkr/macros.inl"
