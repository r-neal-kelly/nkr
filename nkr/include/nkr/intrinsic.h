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

/// @ingroup namespaces
/// @copydoc doc_nkr
namespace nkr {

    /// @ingroup intrinsics_macros_hints
    /// @{
#if _WIN64 || _WIN32
    #define nkr_IS_WINDOWS      ///< @copydoc doc_nkr_nkr_IS_WINDOWS
    #if _WIN64
        #define nkr_IS_64_BIT   ///< @copydoc doc_nkr_nkr_IS_64_BIT
    #elif _WIN32
        #define nkr_IS_32_BIT   ///< @copydoc doc_nkr_nkr_IS_32_BIT
    #else
        #error "Cannot compile with this version of windows."
    #endif
#elif 0
    #define nkr_IS_LINUX        ///< @copydoc doc_nkr_nkr_IS_LINUX
#else
    #error "Cannot compile with this architecture."
#endif
    /// @}
    

    /// @ingroup intrinsics_macros_braces
    /// @{
    #define nkr_M   ///< @copydoc doc_nkr_nkr_M
    #define nkr_W   ///< @copydoc doc_nkr_nkr_W

    #define nkr_P   ///< @copydoc doc_nkr_nkr_P
    #define nkr_b   ///< @copydoc doc_nkr_nkr_b
    /// @}


    // We may move this to a dedicated header with other macro procedures.
    // We would change the group name to just "macros_procedures" then.
    /// @ingroup intrinsics_macros_procedures
    /// @{
    #define nkr_INITIALIZE_STATIC_SAFELY(INITIALIZER_p) ///< @copydoc doc_nkr_nkr_INITIALIZE_STATIC_SAFELY
    /// @}


    /// @ingroup intrinsics_primitives
    /// @{
    using void_t    = void; ///< @copydoc doc_nkr_void_t
    using bool_t    = bool; ///< @copydoc doc_nkr_bool_t
    /// @}


    /// @ingroup intrinsics_integers
    /// @{
    using u8_t  = std::uint8_t;     ///< @copydoc doc_nkr_u8_t
    using u16_t = std::uint16_t;    ///< @copydoc doc_nkr_u16_t
    using u32_t = std::uint32_t;    ///< @copydoc doc_nkr_u32_t
    using u64_t = std::uint64_t;    ///< @copydoc doc_nkr_u64_t
    using s8_t  = std::int8_t;      ///< @copydoc doc_nkr_s8_t
    using s16_t = std::int16_t;     ///< @copydoc doc_nkr_s16_t
    using s32_t = std::int32_t;     ///< @copydoc doc_nkr_s32_t
    using s64_t = std::int64_t;     ///< @copydoc doc_nkr_s64_t
    /// @}
    

    /// @ingroup intrinsics_contextuals
    /// @{
    using byte_t    = u8_t;             ///< @copydoc doc_nkr_byte_t
    using word_t    = std::size_t;      ///< @copydoc doc_nkr_word_t
    using size_t    = word_t;           ///< @copydoc doc_nkr_size_t
    using count_t   = word_t;           ///< @copydoc doc_nkr_count_t
    using index_t   = word_t;           ///< @copydoc doc_nkr_index_t
    using address_t = std::uintptr_t;   ///< @copydoc doc_nkr_address_t
    /// @}

}

#include "nkr/intrinsic.inl"
