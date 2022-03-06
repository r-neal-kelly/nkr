/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include <cstddef>
#include <cstdint>

#include "nkr/macros_dec.h"

/// @copydoc _54e0fcc6_0af9_4a88_b5fd_830d997bb327
namespace nkr {};

namespace nkr {

    /// @copydoc _9730e15e_a0a8_4b22_b55b_771a4ea09486
    namespace boolean   {};

    /// @copydoc _f94a7a61_bc8b_467c_ad48_177ebf2a6288
    namespace negatable {};

    /// @copydoc _ae416188_7c4b_42b5_8a3d_05060328e8cb
    namespace none      {};

    /// @copydoc _e03a80e9_3550_4f45_94b2_afe505b344f1
    namespace positive  {};

}

namespace nkr { namespace none {

    using   type_t      = void;
    using   pointer_t   = std::nullptr_t;

}}

namespace nkr { namespace boolean {

    using   cpp_t   = bool;

}}

namespace nkr { namespace positive {

    using   integer_8_t     = std::uint8_t;
    using   integer_16_t    = std::uint16_t;
    using   integer_32_t    = std::uint32_t;
    using   integer_64_t    = std::uint64_t;
    using   integer_min_t   = integer_8_t;
    using   integer_max_t   = integer_64_t;
#if defined(nkr_IS_64_BIT)
    using   integer_t       = integer_64_t;
#elif defined(nkr_IS_32_BIT)
    using   integer_t       = integer_32_t;
#endif

    using   byte_t          = integer_8_t;
    using   word_t          = integer_t;

    using   size_t          = integer_t;
    using   count_t         = integer_t;
    using   index_t         = integer_t;

}}

namespace nkr { namespace negatable {

    using   integer_8_t     = std::int8_t;
    using   integer_16_t    = std::int16_t;
    using   integer_32_t    = std::int32_t;
    using   integer_64_t    = std::int64_t;
    using   integer_min_t   = integer_8_t;
    using   integer_max_t   = integer_64_t;
#if defined(nkr_IS_64_BIT)
    using   integer_t       = integer_64_t;
#elif defined(nkr_IS_32_BIT)
    using   integer_t       = integer_32_t;
#endif

    using   real_32_t       = float;
    using   real_64_t       = double;
    using   real_min_t      = real_32_t;
    using   real_max_t      = real_64_t;
#if defined(nkr_IS_64_BIT)
    using   real_t          = real_64_t;
#elif defined(nkr_IS_32_BIT)
    using   real_t          = real_32_t;
#endif

    using   byte_t          = integer_8_t;
    using   word_t          = integer_t;

    using   size_t          = integer_t;
    using   count_t         = integer_t;
    using   index_t         = integer_t;

}}

namespace nkr {

    static_assert(sizeof(nkr::positive::integer_8_t) == 1,
                  "nkr::positive::integer_8_t must have a size of 1 bytes.");
    static_assert(sizeof(nkr::positive::integer_16_t) == 2,
                  "nkr::positive::integer_16_t must have a size of 1 bytes.");
    static_assert(sizeof(nkr::positive::integer_32_t) == 4,
                  "nkr::positive::integer_32_t must have a size of 1 bytes.");
    static_assert(sizeof(nkr::positive::integer_64_t) == 8,
                  "nkr::positive::integer_64_t must have a size of 1 bytes.");

    static_assert(sizeof(nkr::negatable::integer_8_t) == 1,
                  "nkr::negatable::integer_8_t must have a size of 1 bytes.");
    static_assert(sizeof(nkr::negatable::integer_16_t) == 2,
                  "nkr::negatable::integer_16_t must have a size of 1 bytes.");
    static_assert(sizeof(nkr::negatable::integer_32_t) == 4,
                  "nkr::negatable::integer_32_t must have a size of 1 bytes.");
    static_assert(sizeof(nkr::negatable::integer_64_t) == 8,
                  "nkr::negatable::integer_64_t must have a size of 1 bytes.");

    static_assert(sizeof(nkr::negatable::real_32_t) == 4,
                  "nkr::negatable::real_32_t must have a size of 4 bytes.");
    static_assert(sizeof(nkr::negatable::real_64_t) == 8,
                  "nkr::negatable::real_64_t must have a size of 8 bytes.");

    static_assert(sizeof(nkr::none::pointer_t) == sizeof(nkr::positive::word_t),
                  "nkr::none::pointeR_t must have the same byte size as that of nkr::positive::word_t.");
    static_assert(sizeof(nkr::none::type_t*) == sizeof(nkr::positive::word_t),
                  "nkr::none::type_t* must have the same byte size as that of nkr::positive::word_t.");

}

#include "nkr/built_in/forward_dec_def.h"
