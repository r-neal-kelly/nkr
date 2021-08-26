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

    /// @ingroup intrinsic_hints
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
    
    /// @ingroup intrinsics_primitives
    /// @{
    using void_t    = void; ///< @copydoc doc_nkr_void_t
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
    
    /// @ingroup _17e74a8d_e977_4d08_a090_f4bb1bcf7673
    /// @{
    using c8_t  = char8_t;  ///< @copydoc _a878a755_773f_49d9_93c2_6567797188f1
    using c16_t = char16_t; ///< @copydoc _22b18aae_67b8_49e5_855c_eb4117780773
    using c32_t = char32_t; ///< @copydoc _70d1ce0d_2bb5_4a6e_ba42_c6c5fdfa5cb7
    /// @}
    
    /// @ingroup _d3bf5147_2b5f_4bd4_bf99_76cf5b9932af
    /// @{
    using f32_t = float;    ///< @copydoc _2ad13e3a_26a3_4526_b482_a1f643d2cb99
    using f64_t = double;   ///< @copydoc _a5fce9b9_cb18_4f58_acaf_79d2386f6bae
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

#include "nkr/intrinsics.inl"
