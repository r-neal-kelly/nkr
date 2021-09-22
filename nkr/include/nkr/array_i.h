/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsics.h"
#include "nkr/macros.h"
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
    concept any_array_tr =
        array_i<array_p>;

    nkr_DEFINE_CONTAINER_TRAITS(array);

}
