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

namespace nkr { namespace $allocator_i {

    template <typename allocator_p>
    concept allocator_aliases_i =
        requires()
    {
        typename allocator_p::unit_t;
        typename allocator_p::units_t;
        typename allocator_p::pointer_t;
    };

    template <typename allocator_p>
    concept allocator_static_methods_i =
        requires()
    {
        { allocator_p::Min_Unit_Count() }   -> is_tr<count_t>;
        { allocator_p::Max_Unit_Count() }   -> is_tr<count_t>;
    };

    template <typename allocator_p>
    concept static_allocator_methods_i =
        requires(typename allocator_p::units_t units,
                 volatile typename allocator_p::units_t volatile_units,
                 typename allocator_p::pointer_t pointer,
                 volatile typename allocator_p::pointer_t volatile_pointer,
                 count_t unit_count)
    {
        { allocator_p::Allocate(units, unit_count) }            -> is_tr<maybe_t<allocator_err>>;
        { allocator_p::Allocate(volatile_units, unit_count) }   -> is_tr<maybe_t<allocator_err>>;
        { allocator_p::Allocate(pointer, unit_count) }          -> is_tr<maybe_t<allocator_err>>;
        { allocator_p::Allocate(volatile_pointer, unit_count) } -> is_tr<maybe_t<allocator_err>>;

        { allocator_p::Deallocate(units) }                      -> is_tr<void_t>;
        { allocator_p::Deallocate(volatile_units) }             -> is_tr<void_t>;
        { allocator_p::Deallocate(pointer) }                    -> is_tr<void_t>;
        { allocator_p::Deallocate(volatile_pointer) }           -> is_tr<void_t>;
    };

    template <typename allocator_p>
    concept dynamic_allocator_methods_i =
        requires(std::remove_cv_t<allocator_p> allocator,
                 const std::remove_cv_t<allocator_p> const_allocator,
                 volatile std::remove_cv_t<allocator_p> volatile_allocator,
                 const volatile std::remove_cv_t<allocator_p> const_volatile_allocator,
                 
                 typename allocator_p::units_t units,
                 volatile typename allocator_p::units_t volatile_units,
                 typename allocator_p::pointer_t pointer,
                 volatile typename allocator_p::pointer_t volatile_pointer,
                 count_t unit_count)
    {
        { allocator.Allocate(units, unit_count) }                           -> is_tr<maybe_t<allocator_err>>;
        { const_allocator.Allocate(units, unit_count) }                     -> is_tr<maybe_t<allocator_err>>;
        { volatile_allocator.Allocate(units, unit_count) }                  -> is_tr<maybe_t<allocator_err>>;
        { const_volatile_allocator.Allocate(units, unit_count) }            -> is_tr<maybe_t<allocator_err>>;

        { allocator.Allocate(volatile_units, unit_count) }                  -> is_tr<maybe_t<allocator_err>>;
        { const_allocator.Allocate(volatile_units, unit_count) }            -> is_tr<maybe_t<allocator_err>>;
        { volatile_allocator.Allocate(volatile_units, unit_count) }         -> is_tr<maybe_t<allocator_err>>;
        { const_volatile_allocator.Allocate(volatile_units, unit_count) }   -> is_tr<maybe_t<allocator_err>>;

        { allocator.Allocate(pointer, unit_count) }                         -> is_tr<maybe_t<allocator_err>>;
        { const_allocator.Allocate(pointer, unit_count) }                   -> is_tr<maybe_t<allocator_err>>;
        { volatile_allocator.Allocate(pointer, unit_count) }                -> is_tr<maybe_t<allocator_err>>;
        { const_volatile_allocator.Allocate(pointer, unit_count) }          -> is_tr<maybe_t<allocator_err>>;

        { allocator.Allocate(volatile_pointer, unit_count) }                -> is_tr<maybe_t<allocator_err>>;
        { const_allocator.Allocate(volatile_pointer, unit_count) }          -> is_tr<maybe_t<allocator_err>>;
        { volatile_allocator.Allocate(volatile_pointer, unit_count) }       -> is_tr<maybe_t<allocator_err>>;
        { const_volatile_allocator.Allocate(volatile_pointer, unit_count) } -> is_tr<maybe_t<allocator_err>>;

        { allocator.Deallocate(units) }                                     -> is_tr<void_t>;
        { const_allocator.Deallocate(units) }                               -> is_tr<void_t>;
        { volatile_allocator.Deallocate(units) }                            -> is_tr<void_t>;
        { const_volatile_allocator.Deallocate(units) }                      -> is_tr<void_t>;

        { allocator.Deallocate(volatile_units) }                            -> is_tr<void_t>;
        { const_allocator.Deallocate(volatile_units) }                      -> is_tr<void_t>;
        { volatile_allocator.Deallocate(volatile_units) }                   -> is_tr<void_t>;
        { const_volatile_allocator.Deallocate(volatile_units) }             -> is_tr<void_t>;

        { allocator.Deallocate(pointer) }                                   -> is_tr<void_t>;
        { const_allocator.Deallocate(pointer) }                             -> is_tr<void_t>;
        { volatile_allocator.Deallocate(pointer) }                          -> is_tr<void_t>;
        { const_volatile_allocator.Deallocate(pointer) }                    -> is_tr<void_t>;

        { allocator.Deallocate(volatile_pointer) }                          -> is_tr<void_t>;
        { const_allocator.Deallocate(volatile_pointer) }                    -> is_tr<void_t>;
        { volatile_allocator.Deallocate(volatile_pointer) }                 -> is_tr<void_t>;
        { const_volatile_allocator.Deallocate(volatile_pointer) }           -> is_tr<void_t>;
    };

}}

namespace nkr {

    /// @copydoc _5fe34260_b2c5_442b_aa23_44ddb41cb7b6
    template <typename allocator_p>
    concept allocator_i = requires(typename allocator_p::units_t units,
                                   volatile typename allocator_p::units_t volatile_units,
                                   typename allocator_p::pointer_t pointer,
                                   volatile typename allocator_p::pointer_t volatile_pointer,
                                   count_t unit_count,
                                   count_t new_unit_count)
    {
        typename allocator_p::unit_t;
        typename allocator_p::units_t;
        typename allocator_p::pointer_t;

        { allocator_p::Min_Unit_Count() }                               -> is_tr<count_t>;
        { allocator_p::Max_Unit_Count() }                               -> is_tr<count_t>;

        { allocator_p::Allocate(units, unit_count) }                    -> is_tr<maybe_t<allocator_err>>;
        { allocator_p::Allocate(volatile_units, unit_count) }           -> is_tr<maybe_t<allocator_err>>;
        { allocator_p::Allocate(pointer, unit_count) }                  -> is_tr<maybe_t<allocator_err>>;
        { allocator_p::Allocate(volatile_pointer, unit_count) }         -> is_tr<maybe_t<allocator_err>>;

        { allocator_p::Reallocate(units, new_unit_count) }              -> is_tr<maybe_t<allocator_err>>;
        { allocator_p::Reallocate(volatile_units, new_unit_count) }     -> is_tr<maybe_t<allocator_err>>;
        { allocator_p::Reallocate(pointer, new_unit_count) }            -> is_tr<maybe_t<allocator_err>>;
        { allocator_p::Reallocate(volatile_pointer, new_unit_count) }   -> is_tr<maybe_t<allocator_err>>;

        { allocator_p::Deallocate(units) }                              -> is_tr<void_t>;
        { allocator_p::Deallocate(volatile_units) }                     -> is_tr<void_t>;
        { allocator_p::Deallocate(pointer) }                            -> is_tr<void_t>;
        { allocator_p::Deallocate(volatile_pointer) }                   -> is_tr<void_t>;
    };

}
