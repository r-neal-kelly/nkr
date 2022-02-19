/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/z_allocator_err.h"
#include "nkr/z_bool_t.h"
#include "nkr/z_intrinsics.h"
#include "nkr/z_maybe_t.h"
#include "nkr/z_pointer_t.h"

/*
    Requirements (WIP):
        - an allocator can either be static or dynamic.
        - a static allocator only has static methods and must have no constructors. (how do we implement the ctors for types using the allocator? maybe we can allow ctors on the static allocators and simply use a static method to get the default instantiated allocator, that way it's easier to make types using either allocator archetype. we may ever require the same method for dynamic types, except that they can return the dynamic_allocator_t() default ctor'd object)
        - a dynamic allocator only has dynamic methods and must have constructors.

        - a static allocator is assumed to have units that are neither const or volatile qualified, and thus can supply any qualification.
        - a dynamic allocator is only required to supply units of the same qualification as itself, that is non-qualified or volatile.
        - a const dynamic allocator cannot supply any units, however it may be used for other purposes.

        - types that take a static allocator cannot store it as an object in its footprint. thus static allocators need to be created elsewhere.
        - types that take a dynamic allocator must store the object in its footrpint. thus dynamic allocators need to provide constructors.

        - there are two primary methods, Allocate and Deallocate. Allocate should essentially behave as realloc and Deallocate as free.

        - Allocate should return without error when given nullptr and a unit_count of zero.
        - Allocate should assert when given a non-zero and invalid unit_count, one that is outside the range of its Min_Allocatable_Unit_Count() and Max_Allocatable_Unit_Count().
        - Allocate should allocate memory when given nullptr and a valid unit_count above zero, or return allocator_err::OUT_OF_MEMORY. It should set the pointer to non-nullptr.
        - Allocate should assert when given an invalid non-nullptr, a pointer that it did not allocate.
        - Allocate should deallocate when given a valid non-nullptr and a unit_count of zero. It should set the pointer to nullptr.
        - Allocate should grow memory when given a valid non-nullptr and a valid unit_count bigger than previously allocated, or return allocator_err::OUT_OF_MEMORY. It may change the pointer to another pointer as long as all the data from the previous pointer is moved.
        - Allocate should shrink memory and return without error when given a valid non-nullptr and a valid unit_count smaller than previously allocated. It may never change the pointer.
        - Allocate should return without error when given a valid non-nullptr and a unit_count that is the same as previously allocated. It shouldn't make any changes to its own state or the pointer.

        - Deallocate should return without asserting when given nullptr.
        - Deallocate should assert when given an invalid non-nullptr, a pointer that it did not allocate.
        - Deallocate should deallocate a valid non-nullptr. It should set the pointer to nullptr.
*/

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
    } &&
        !any_const_tr<typename allocator_p::unit_t> &&
        !any_volatile_tr<typename allocator_p::unit_t>;

    template <typename allocator_p>
    concept allocator_static_methods_i =
        requires()
    {
        { allocator_p::Min_Allocatable_Unit_Count() }   -> is_tr<count_t>;
        { allocator_p::Max_Allocatable_Unit_Count() }   -> is_tr<count_t>;
    };

    template <typename allocator_p>
    concept static_allocator_static_methods_i =
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
        { allocator.Allocate(volatile_units, unit_count) }                  -> is_tr<maybe_t<allocator_err>>;
        { volatile_allocator.Allocate(volatile_units, unit_count) }         -> is_tr<maybe_t<allocator_err>>;

        { allocator.Allocate(pointer, unit_count) }                         -> is_tr<maybe_t<allocator_err>>;
        { allocator.Allocate(volatile_pointer, unit_count) }                -> is_tr<maybe_t<allocator_err>>;
        { volatile_allocator.Allocate(volatile_pointer, unit_count) }       -> is_tr<maybe_t<allocator_err>>;

        { allocator.Deallocate(units) }                                     -> is_tr<void_t>;
        { allocator.Deallocate(volatile_units) }                            -> is_tr<void_t>;
        { volatile_allocator.Deallocate(volatile_units) }                   -> is_tr<void_t>;

        { allocator.Deallocate(pointer) }                                   -> is_tr<void_t>;
        { allocator.Deallocate(volatile_pointer) }                          -> is_tr<void_t>;
        { volatile_allocator.Deallocate(volatile_pointer) }                 -> is_tr<void_t>;
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
