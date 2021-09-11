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
                                   typename allocator_p::units_t units,
                                   pointer_t<typename allocator_p::unit_t> pointer,
                                   count_t unit_count,
                                   count_t new_unit_count)
    {
        typename allocator_p::unit_t;
        typename allocator_p::units_t;

        allocator_p::MIN_UNIT_COUNT;
        allocator_p::MAX_UNIT_COUNT;

        { allocator.Allocate(units, unit_count) }           -> std::same_as<bool_t>;
        { allocator.Allocate(pointer, unit_count) }         -> std::same_as<bool_t>;

        { allocator.Reallocate(units, new_unit_count) }     -> std::same_as<bool_t>;
        { allocator.Reallocate(pointer, new_unit_count) }   -> std::same_as<bool_t>;

        { allocator.Deallocate(units) }                     -> std::same_as<void_t>;
        { allocator.Deallocate(pointer) }                   -> std::same_as<void_t>;
    };

}
