/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsics.h"
#include "nkr/traits.h"
#include "nkr/utils.h"

namespace nkr {

    template <typename array_p>
    concept array_i = requires(std::remove_const_t<array_p> array,
                               std::add_const_t<array_p> const_array,
                               count_t count,
                               typename array_p::unit_t& lvalue_unit,
                               typename array_p::writable_unit_t&& rvalue_unit)
    {
        count = const_array.Count();

        array.Push(lvalue_unit);
        array.Push(nkr::Move(rvalue_unit));
    };

    template <typename array_p, typename unit_p>
    concept array_of_tr =
        array_i<array_p> &&
        same_as_tr<typename array_p::unit_t, unit_p>;

    template <typename array_p, typename unit_p>
    concept writable_array_of_tr =
        writable_tr<array_p> &&
        array_of_tr<array_p, unit_p>;

    template <typename array_p, typename unit_p>
    concept unwritable_array_of_tr =
        unwritable_tr<array_p> &&
        array_of_tr<array_p, unit_p>;

    template <typename array_p, typename unit_p>
    concept array_of_any_tr =
        array_i<array_p> &&
        same_as_any_tr<typename array_p::unit_t, unit_p>;

    template <typename array_p, typename unit_p>
    concept non_array_of_any_tr =
        !array_of_any_tr<array_p, unit_p>;

    template <typename array_p, typename unit_p>
    concept writable_array_of_any_tr =
        writable_tr<array_p> &&
        array_of_any_tr<array_p, unit_p>;

    template <typename array_p, typename unit_p>
    concept non_writable_array_of_any_tr =
        !writable_array_of_any_tr<array_p, unit_p>;

    template <typename array_p, typename unit_p>
    concept unwritable_array_of_any_tr =
        unwritable_tr<array_p> &&
        array_of_any_tr<array_p, unit_p>;

    template <typename array_p, typename unit_p>
    concept array_of_any_writable_tr =
        array_i<array_p> &&
        same_as_any_writable_tr<typename array_p::unit_t, unit_p>;

    template <typename array_p, typename unit_p>
    concept writable_array_of_any_writable_tr =
        writable_tr<array_p> &&
        array_of_any_writable_tr<array_p, unit_p>;

    template <typename array_p, typename unit_p>
    concept non_writable_array_of_any_writable_tr =
        !writable_array_of_any_writable_tr<array_p, unit_p>;

    template <typename array_p, typename unit_p>
    concept unwritable_array_of_any_writable_tr =
        unwritable_tr<array_p> &&
        array_of_any_writable_tr<array_p, unit_p>;

    template <typename array_p, typename unit_p>
    concept array_of_any_unwritable_tr =
        array_i<array_p> &&
        array_of_any_unwritable_tr<typename array_p::unit_t, unit_p>;

    template <typename array_p, typename unit_p>
    concept writable_array_of_any_unwritable_tr =
        writable_tr<array_p> &&
        array_of_any_unwritable_tr<array_p, unit_p>;

    template <typename array_p, typename unit_p>
    concept unwritable_array_of_any_unwritable_tr =
        unwritable_tr<array_p> &&
        array_of_any_unwritable_tr<array_p, unit_p>;

}
