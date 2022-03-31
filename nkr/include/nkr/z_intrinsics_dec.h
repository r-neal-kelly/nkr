/*
    Copyright 2022 r-neal-kelly
*/

#ifndef _2bbae1d9_984f_4d7e_a234_eb773bbec200
#define _2bbae1d9_984f_4d7e_a234_eb773bbec200

#include <cassert>
#include <cerrno>
#include <climits>
#include <cstdint>

#include <concepts>
#include <limits>
#include <memory>
#include <utility>

/// @ingroup _d1cd4369_e0f4_4062_8f58_611395da215e
/// @copydoc doc_nkr
namespace nkr {

    /// @ingroup intrinsic_hints
    /// @{
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

    /// @}
    
    /// @ingroup intrinsics_primitives
    /// @{
    using void_t    = void; ///< @copydoc _dbb0c2f2_8907_4cee_8bdd_463eea2421c8
    using c_bool_t  = bool; ///< @copydoc _cf3346a3_232d_4218_9a27_facf99329980
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

    /// @ingroup _d3bf5147_2b5f_4bd4_bf99_76cf5b9932af
    /// @{
    using r32_t     = float;    ///< @copydoc _2ad13e3a_26a3_4526_b482_a1f643d2cb99
    using r64_t     = double;   ///< @copydoc _a5fce9b9_cb18_4f58_acaf_79d2386f6bae
#if defined(nkr_IS_64_BIT)
    using real_t    = r64_t;    ///< @copydoc _78f7692b_f26c_44ec_b165_394190b9d273
#elif defined(nkr_IS_32_BIT)
    using real_t    = r32_t;    ///< @copydoc _78f7692b_f26c_44ec_b165_394190b9d273
#endif
    /// @}

    /// @ingroup intrinsics_contextuals
    /// @{
#if defined(nkr_IS_64_BIT)
    using word_t            = u64_t;            ///< @copydoc doc_nkr_word_t
    using unsigned_word_t   = u64_t;            ///< @copydoc _c815a2ce_97a5_4e93_812d_cfc107560a30
    using signed_word_t     = s64_t;            ///< @copydoc _9007e224_d505_4ee2_8234_354e1044df0f
#elif defined(nkr_IS_32_BIT)
    using word_t            = u32_t;            ///< @copydoc doc_nkr_word_t
    using unsigned_word_t   = u32_t;            ///< @copydoc _c815a2ce_97a5_4e93_812d_cfc107560a30
    using signed_word_t     = s32_t;            ///< @copydoc _9007e224_d505_4ee2_8234_354e1044df0f
#endif

    using byte_t            = u8_t;             ///< @copydoc doc_nkr_byte_t
    using size_t            = word_t;           ///< @copydoc doc_nkr_size_t
    using count_t           = word_t;           ///< @copydoc doc_nkr_count_t
    using index_t           = word_t;           ///< @copydoc doc_nkr_index_t
    using address_t         = std::uintptr_t;   ///< @copydoc doc_nkr_address_t
    using nullptr_t         = std::nullptr_t;
    /// @}

}

#endif
