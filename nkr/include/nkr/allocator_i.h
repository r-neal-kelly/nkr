/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/allocator_err.h"
#include "nkr/bool_t.h"
#include "nkr/intrinsics.h"
#include "nkr/maybe_t.h"
#include "nkr/pointer_t.h"

/// @copydoc _627e5174_65ef_4aee_bb2a_034d9715cb0d
namespace nkr::allocator {};

namespace nkr {

    /// @copydoc _5fe34260_b2c5_442b_aa23_44ddb41cb7b6
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

        { allocator.Min_Unit_Count() }                                      -> is_tr<count_t>;
        { volatile_allocator.Min_Unit_Count() }                             -> is_tr<count_t>;
        { allocator.Max_Unit_Count() }                                      -> is_tr<count_t>;
        { volatile_allocator.Max_Unit_Count() }                             -> is_tr<count_t>;

        { allocator == allocator }                                          -> is_tr<bool_t>;
        { allocator == volatile_allocator }                                 -> is_tr<bool_t>;
        { volatile_allocator == allocator }                                 -> is_tr<bool_t>;
        { allocator != allocator }                                          -> is_tr<bool_t>;
        { allocator != volatile_allocator }                                 -> is_tr<bool_t>;
        { volatile_allocator != allocator }                                 -> is_tr<bool_t>;

        { allocator.Allocate(units, unit_count) }                           -> is_tr<maybe_t<allocator_err>>;
        { volatile_allocator.Allocate(volatile_units, unit_count) }         -> is_tr<maybe_t<allocator_err>>;
        { allocator.Allocate(pointer, unit_count) }                         -> is_tr<maybe_t<allocator_err>>;
        { volatile_allocator.Allocate(volatile_pointer, unit_count) }       -> is_tr<maybe_t<allocator_err>>;

        { allocator.Reallocate(units, new_unit_count) }                     -> is_tr<maybe_t<allocator_err>>;
        { volatile_allocator.Reallocate(volatile_units, new_unit_count) }   -> is_tr<maybe_t<allocator_err>>;
        { allocator.Reallocate(pointer, new_unit_count) }                   -> is_tr<maybe_t<allocator_err>>;
        { volatile_allocator.Reallocate(volatile_pointer, new_unit_count) } -> is_tr<maybe_t<allocator_err>>;

        { allocator.Deallocate(units) }                                     -> is_tr<void_t>;
        { volatile_allocator.Deallocate(volatile_units) }                   -> is_tr<void_t>;
        { allocator.Deallocate(pointer) }                                   -> is_tr<void_t>;
        { volatile_allocator.Deallocate(volatile_pointer) }                 -> is_tr<void_t>;
    };

}
