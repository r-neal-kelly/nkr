/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsics.h"
#include "nkr/macros.h"
#include "nkr/maybe_t.h"
#include "nkr/traits.h"
#include "nkr/utils.h"

#include "nkr/allocator_err.h"

namespace nkr { namespace $array_i {

    template <typename array_p>
    concept aliases_i =
        requires()
    {
        typename array_p::unit_t;
    };

    template <typename array_p>
    concept unaddable_methods_i =
        requires(std::remove_cv_t<array_p> array,
                 const std::remove_cv_t<array_p> const_array,
                 volatile std::remove_cv_t<array_p> volatile_array,
                 const volatile std::remove_cv_t<array_p> const_volatile_array)
    {
        { array.Count() }                   -> is_tr<count_t>;
        { const_array.Count() }             -> is_tr<count_t>;
        { volatile_array.Count() }          -> is_tr<count_t>;
        { const_volatile_array.Count() }    -> is_tr<count_t>;
    };

    template <typename array_p>
    concept addable_methods_i =
        requires(std::remove_cv_t<array_p> array,
                 const std::remove_cv_t<array_p> const_array,
                 volatile std::remove_cv_t<array_p> volatile_array,
                 const volatile std::remove_cv_t<array_p> const_volatile_array,

                 count_t new_capacity,

                 typename array_p::unit_t & lvalue_unit,
                 typename array_p::writable_unit_t && rvalue_unit)
    {
        { array.Capacity() }                            -> is_tr<count_t>;
        { const_array.Capacity() }                      -> is_tr<count_t>;
        { volatile_array.Capacity() }                   -> is_tr<count_t>;
        { const_volatile_array.Capacity() }             -> is_tr<count_t>;
        { array.Capacity(new_capacity) }                -> is_tr<maybe_t<allocator_err>>;
        { volatile_array.Capacity(new_capacity) }       -> is_tr<maybe_t<allocator_err>>;

        { array.Push(lvalue_unit) }                     -> is_tr<maybe_t<allocator_err>>;
        { volatile_array.Push(lvalue_unit) }            -> is_tr<maybe_t<allocator_err>>;

        { array.Push(nkr::Move(rvalue_unit)) }          -> is_tr<maybe_t<allocator_err>>;
        { volatile_array.Push(nkr::Move(rvalue_unit)) } -> is_tr<maybe_t<allocator_err>>;

        // maybe add and remove instead of push pop. remove(index_t) can be an overload
    };

}}

namespace nkr {

    template <typename array_p>
    concept unaddable_array_i =
        $array_i::aliases_i<array_p> &&
        $array_i::unaddable_methods_i<array_p> &&
        !$array_i::addable_methods_i<array_p>;

    template <typename array_p>
    concept addable_array_i =
        $array_i::aliases_i<array_p> &&
        $array_i::unaddable_methods_i<array_p> &&
        $array_i::addable_methods_i<array_p>;

    template <typename array_p>
    concept array_i =
        unaddable_array_i<array_p> ||
        addable_array_i<array_p>;

    template <typename array_p>
    concept any_array_tr =
        array_i<array_p>;

    nkr_DEFINE_CONTAINER_TRAITS(array, unit_t);

}
