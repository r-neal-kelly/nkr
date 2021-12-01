/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsics.h"
#include "nkr/math.h"
#include "nkr/traits.h"

#include "nkr/allocator_err.h"

#include "nkr/array/dynamic_t.h"
#include "nkr/array/stack_t.h"
#include "nkr/array/static_t.h"

#include "nkr/hasher_i.h"

namespace nkr { namespace hasher {

    class fnv1a_32_t
    {
    public:
    };

    class fnv1a_64_t
    {
    public:
    };

    class fnv1a_128_t
    {
    public:
    };

    // etc

#if defined(nkr_IS_64_BIT)
    using fnv1a_t = fnv1a_64_t;
#elif defined(nkr_IS_32_BIT)
    using fnv1a_t = fnv1a_32_t;
#endif

}}
