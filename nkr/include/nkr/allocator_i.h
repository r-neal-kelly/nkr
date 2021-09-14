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
                                   volatile allocator_p volatile_allocator,
                                   typename allocator_p::units_t units,
                                   volatile typename allocator_p::units_t volatile_units,
                                   typename allocator_p::pointer_t pointer,
                                   volatile typename allocator_p::pointer_t volatile_pointer,
                                   count_t unit_count,
                                   count_t new_unit_count)
    {
        typename allocator_p::unit_t;
        typename allocator_p::units_t;
        typename allocator_p::pointer_t;

        { allocator.Min_Unit_Count() }                                      -> std::same_as<count_t>;
        { volatile_allocator.Min_Unit_Count() }                             -> std::same_as<count_t>;
        { allocator.Max_Unit_Count() }                                      -> std::same_as<count_t>;
        { volatile_allocator.Max_Unit_Count() }                             -> std::same_as<count_t>;

        { allocator == allocator }                                          -> std::same_as<bool_t>;
        { allocator == volatile_allocator }                                 -> std::same_as<bool_t>;
        { volatile_allocator == allocator }                                 -> std::same_as<bool_t>;
        { allocator != allocator }                                          -> std::same_as<bool_t>;
        { allocator != volatile_allocator }                                 -> std::same_as<bool_t>;
        { volatile_allocator != allocator }                                 -> std::same_as<bool_t>;

        { allocator.Allocate(units, unit_count) }                           -> std::same_as<bool_t>;
        { volatile_allocator.Allocate(volatile_units, unit_count) }         -> std::same_as<bool_t>;
        { allocator.Allocate(pointer, unit_count) }                         -> std::same_as<bool_t>;
        { volatile_allocator.Allocate(volatile_pointer, unit_count) }       -> std::same_as<bool_t>;

        { allocator.Reallocate(units, new_unit_count) }                     -> std::same_as<bool_t>;
        { volatile_allocator.Reallocate(volatile_units, new_unit_count) }   -> std::same_as<bool_t>;
        { allocator.Reallocate(pointer, new_unit_count) }                   -> std::same_as<bool_t>;
        { volatile_allocator.Reallocate(volatile_pointer, new_unit_count) } -> std::same_as<bool_t>;

        { allocator.Deallocate(units) }                                     -> std::same_as<void_t>;
        { volatile_allocator.Deallocate(volatile_units) }                   -> std::same_as<void_t>;
        { allocator.Deallocate(pointer) }                                   -> std::same_as<void_t>;
        { volatile_allocator.Deallocate(volatile_pointer) }                 -> std::same_as<void_t>;
    };

}
