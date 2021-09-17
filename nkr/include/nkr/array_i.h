/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsics.h"

namespace nkr {

    template <typename type_p, typename unit_p>
    concept push_copy_i = requires(type_p instance, unit_p unit)
    {
        instance.Push(unit);
    };

    template <typename type_p, typename unit_p>
    concept push_move_i = requires(type_p instance, unit_p unit)
    {
        instance.Push(std::move(unit));
    };

}
