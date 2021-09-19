/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsics.h"
#include "nkr/traits.h"
#include "nkr/utils.h"

namespace nkr {

    template <typename array_p>
    concept array_i = requires(array_p array,
                               count_t count,
                               typename array_p::unit_t& lvalue_unit,
                               typename array_p::writable_unit_t&& rvalue_unit)
    {
        count = array.Count();

        array.Push(lvalue_unit);
        array.Push(nkr::Move(rvalue_unit));
    };

    template <typename array_p, typename unit_p>
    concept array_of_tr =
        array_i<array_p> &&
        same_as_tr<typename array_p::unit_t, unit_p>;

    template <typename array_p, typename unit_p>
    concept array_of_any_tr =
        array_i<array_p> &&
        same_as_any_tr<typename array_p::unit_t, unit_p>;

    template <typename array_p, typename unit_p>
    concept array_of_any_writable_tr =
        array_i<array_p> &&
        same_as_any_writable_tr<typename array_p::unit_t, unit_p>;

    template <typename array_p, typename unit_p>
    concept array_of_any_unwritable_tr =
        array_i<array_p> &&
        array_of_any_unwritable_tr<typename array_p::unit_t, unit_p>;

}
