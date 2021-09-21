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

    template <typename array_p>
    concept array_tr =
        array_i<array_p>;

    template <typename array_p, typename unit_p>
    concept array_of_tr =
        array_tr<array_p> &&
        is_tr<typename array_p::unit_t, unit_p>;

    template <typename array_p, typename unit_p>
    concept array_of_const_tr =
        array_tr<array_p> &&
        is_const_tr<typename array_p::unit_t, unit_p>;

    template <typename array_p, typename unit_p>
    concept array_of_non_const_tr =
        array_tr<array_p> &&
        is_non_const_tr<typename array_p::unit_t, unit_p>;

    template <typename array_p, typename unit_p>
    concept array_of_any_tr =
        array_tr<array_p> &&
        is_any_tr<typename array_p::unit_t, unit_p>;

    template <typename array_p, typename unit_p>
    concept array_of_any_const_tr =
        array_tr<array_p> &&
        is_any_const_tr<typename array_p::unit_t, unit_p>;

    template <typename array_p, typename unit_p>
    concept array_of_any_non_const_tr =
        array_tr<array_p> &&
        is_any_non_const_tr<typename array_p::unit_t, unit_p>;

    template <typename array_p>
    concept const_array_tr =
        const_tr<array_p> &&
        array_tr<array_p>;

    template <typename array_p, typename unit_p>
    concept const_array_of_tr =
        const_tr<array_p> &&
        array_of_tr<array_p, unit_p>;

    template <typename array_p, typename unit_p>
    concept const_array_of_const_tr =
        const_tr<array_p> &&
        array_of_const_tr<array_p, unit_p>;

    template <typename array_p, typename unit_p>
    concept const_array_of_non_const_tr =
        const_tr<array_p> &&
        array_of_non_const_tr<array_p, unit_p>;

    template <typename array_p, typename unit_p>
    concept const_array_of_any_tr =
        const_tr<array_p> &&
        array_of_any_tr<array_p, unit_p>;

    template <typename array_p, typename unit_p>
    concept const_array_of_any_const_tr =
        const_tr<array_p> &&
        array_of_any_const_tr<array_p, unit_p>;

    template <typename array_p, typename unit_p>
    concept const_array_of_any_non_const_tr =
        const_tr<array_p> &&
        array_of_any_non_const_tr<array_p, unit_p>;

    template <typename array_p>
    concept non_const_array_tr =
        non_const_tr<array_p> &&
        array_tr<array_p>;

    template <typename array_p, typename unit_p>
    concept non_const_array_of_tr =
        non_const_tr<array_p> &&
        array_of_tr<array_p, unit_p>;

    template <typename array_p, typename unit_p>
    concept non_const_array_of_const_tr =
        non_const_tr<array_p> &&
        array_of_const_tr<array_p, unit_p>;

    template <typename array_p, typename unit_p>
    concept non_const_array_of_non_const_tr =
        non_const_tr<array_p> &&
        array_of_non_const_tr<array_p, unit_p>;

    template <typename array_p, typename unit_p>
    concept non_const_array_of_any_tr =
        non_const_tr<array_p> &&
        array_of_any_tr<array_p, unit_p>;

    template <typename array_p, typename unit_p>
    concept non_const_array_of_any_const_tr =
        non_const_tr<array_p> &&
        array_of_any_const_tr<array_p, unit_p>;

    template <typename array_p, typename unit_p>
    concept non_const_array_of_any_non_const_tr =
        non_const_tr<array_p> &&
        array_of_any_non_const_tr<array_p, unit_p>;

    template <typename array_p>
    concept not_array_tr =
        !array_tr<array_p>;

    template <typename array_p, typename unit_p>
    concept not_array_of_tr =
        !array_of_tr<array_p, unit_p>;

    template <typename array_p, typename unit_p>
    concept not_array_of_const_tr =
        !array_of_const_tr<array_p, unit_p>;

    template <typename array_p, typename unit_p>
    concept not_array_of_non_const_tr =
        !array_of_non_const_tr<array_p, unit_p>;

    template <typename array_p, typename unit_p>
    concept not_array_of_any_tr =
        !array_of_any_tr<array_p, unit_p>;

    template <typename array_p, typename unit_p>
    concept not_array_of_any_const_tr =
        !array_of_any_const_tr<array_p, unit_p>;

    template <typename array_p, typename unit_p>
    concept not_array_of_any_non_const_tr =
        !array_of_any_non_const_tr<array_p, unit_p>;

    template <typename array_p>
    concept not_const_array_tr =
        !const_array_tr<array_p>;

    template <typename array_p, typename unit_p>
    concept not_const_array_of_tr =
        !const_array_of_tr<array_p, unit_p>;

    template <typename array_p, typename unit_p>
    concept not_const_array_of_const_tr =
        !const_array_of_const_tr<array_p, unit_p>;

    template <typename array_p, typename unit_p>
    concept not_const_array_of_non_const_tr =
        !const_array_of_non_const_tr<array_p, unit_p>;

    template <typename array_p, typename unit_p>
    concept not_const_array_of_any_tr =
        !const_array_of_any_tr<array_p, unit_p>;

    template <typename array_p, typename unit_p>
    concept not_const_array_of_any_const_tr =
        !const_array_of_any_const_tr<array_p, unit_p>;

    template <typename array_p, typename unit_p>
    concept not_const_array_of_any_non_const_tr =
        !const_array_of_any_non_const_tr<array_p, unit_p>;

    template <typename array_p>
    concept not_non_const_array_tr =
        !non_const_array_tr<array_p>;

    template <typename array_p, typename unit_p>
    concept not_non_const_array_of_tr =
        !non_const_array_of_tr<array_p, unit_p>;

    template <typename array_p, typename unit_p>
    concept not_non_const_array_of_const_tr =
        !non_const_array_of_const_tr<array_p, unit_p>;

    template <typename array_p, typename unit_p>
    concept not_non_const_array_of_non_const_tr =
        !non_const_array_of_non_const_tr<array_p, unit_p>;

    template <typename array_p, typename unit_p>
    concept not_non_const_array_of_any_tr =
        !non_const_array_of_any_tr<array_p, unit_p>;

    template <typename array_p, typename unit_p>
    concept not_non_const_array_of_any_const_tr =
        !non_const_array_of_any_const_tr<array_p, unit_p>;

    template <typename array_p, typename unit_p>
    concept not_non_const_array_of_any_non_const_tr =
        !non_const_array_of_any_non_const_tr<array_p, unit_p>;

}
