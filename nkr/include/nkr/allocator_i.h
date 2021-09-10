/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/bool_t.h"
#include "nkr/intrinsics.h"
#include "nkr/pointer_t.h"

namespace nkr {

    template <typename allocator_p>
    concept allocator_i = requires(allocator_p allocator,
                                   pointer_t<typename allocator_p::unit_t> units,
                                   count_t unit_count,
                                   count_t new_unit_count)
    {
        typename allocator_p::unit_t;

        { allocator.Allocate(units, unit_count) }       -> std::same_as<bool_t>;
        { allocator.Reallocate(units, new_unit_count) } -> std::same_as<bool_t>;
        { allocator.Deallocate(units) }                 -> std::same_as<void_t>;
    };

}
