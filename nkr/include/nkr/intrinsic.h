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

    /// @ingroup intrinsics_macros_procedures
    /// @{
    #define nkr_INITIALIZE_STATIC_SAFELY(INITIALIZER_p) ///< @copydoc doc_nkr_nkr_INITIALIZE_STATIC_SAFELY
    /// @}

    /**
    * @defgroup intrinsics_primitives primitives
    * @ingroup intrinsics
    * 
    * @brief
    *   Primitive types aliased for consistency.
    */
    /** @{ **/
    using void_t    = void;
    using bool_t    = bool;
    /** @} **/

    /**
    * @defgroup intrinsics_integers integers
    * @ingroup intrinsics
    * 
    * @brief
    *   Convenient integer types.
    * 
    * @todo
    *   Add an example showing why the _t comes in useful when using integers. Also explain the u and s.
    */
    /** @{ **/
    using u8_t      = std::uint8_t;
    using u16_t     = std::uint16_t;
    using u32_t     = std::uint32_t;
    using u64_t     = std::uint64_t;
    using s8_t      = std::int8_t;
    using s16_t     = std::int16_t;
    using s32_t     = std::int32_t;
    using s64_t     = std::int64_t;
    /** @} **/

    /**
    * @defgroup intrinsics_contextuals contextuals
    * @ingroup intrinsics
    * 
    * @brief
    *   Efficient context based types.
    * 
    * @details
    *   These types are most commonly used on the stack, making them transitory and often only cached in small numbers. Most of them equate to the size of nkr::word_t, which has the same size as the processor's natural word. This is important when it comes to execution efficiency because the processor has to spend more time reading a variable that does not equate to its word size. Others are necessarily different sizes depending on their context.
    */
    /** @{ **/
    using byte_t    = u8_t;             ///< The smallest natural type available.
    using word_t    = std::size_t;      ///< The largest natural type available, the processor's word.
    using size_t    = word_t;           ///< Used for byte counts exclusively.
    using count_t   = word_t;           ///< Used for unit counts of any arbitrary type.
    using index_t   = word_t;           ///< Used for unit indices of any arbitrary array of types.
    using address_t = std::uintptr_t;   ///< Used for literal pointer math.
    /** @} **/

#if defined(nkr_IS_32_BIT)
    static_assert(sizeof(std::size_t) == sizeof(u32_t), "You need to manually set word_t to u32_t.");
#elif defined(nkr_IS_64_BIT)
    static_assert(sizeof(std::size_t) == sizeof(u64_t), "You need to manually set word_t to u64_t.");
#endif

}

#include "nkr/intrinsic.inl"
