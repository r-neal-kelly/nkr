/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include <concepts>

#include "nkr/intrinsic.h"
#include "nkr/pointer_t.h"

namespace nkr {

    template <typename allocator>
    concept allocator_i = requires(allocator instance,
                                   pointer_t<typename allocator::unit_t> &units,
                                   count_t unit_count)
    {
        typename allocator::unit_t;

        { instance.allocate(units, unit_count) }    -> std::same_as<bool_t>;
        { instance.reallocate(units, unit_count) }  -> std::same_as<bool_t>;
        { instance.deallocate(units) }              -> std::same_as<void_t>;
    };

}
