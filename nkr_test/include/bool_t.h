/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "intrinsics.h"

namespace nkr {

    /// [_3e7cd520_dafd_4a17_befe_912aeb32e870]
    template <typename type_p>
    concept has_unwanted_bool_operators_tr =
        requires(type_p instance) { +instance; } ||
        requires(type_p instance) { -instance; } ||

        requires(type_p instance) { instance + 1; } ||
        requires(type_p instance) { instance - 1; } ||
        requires(type_p instance) { instance * 1; } ||
        requires(type_p instance) { instance / 1; } ||
        requires(type_p instance) { instance % 1; } ||

        requires(type_p instance) { ~instance; } ||
        requires(type_p instance) { instance | 1; } ||
        requires(type_p instance) { instance & 1; } ||
        requires(type_p instance) { instance ^ 1; } ||
        requires(type_p instance) { instance << 1; } ||
        requires(type_p instance) { instance >> 1; } ||

        requires(type_p instance) { instance += 1; } ||
        requires(type_p instance) { instance -= 1; } ||
        requires(type_p instance) { instance *= 1; } ||
        requires(type_p instance) { instance /= 1; } ||
        requires(type_p instance) { instance %= 1; } ||

        requires(type_p instance) { instance |= 1; } ||
        requires(type_p instance) { instance &= 1; } ||
        requires(type_p instance) { instance ^= 1; } ||
        requires(type_p instance) { instance <<= 1; } ||
        requires(type_p instance) { instance >>= 1; } ||

        requires(type_p instance) { ++instance; } ||
        requires(type_p instance) { instance++; } ||
        requires(type_p instance) { --instance; } ||
        requires(type_p instance) { instance--; } ||

        requires(type_p instance) { instance < 1; } ||
        requires(type_p instance) { instance > 1; } ||
        requires(type_p instance) { instance <= 1; } ||
        requires(type_p instance) { instance >= 1; } ||
        requires(type_p instance) { instance <=> 1; };
    /// [_3e7cd520_dafd_4a17_befe_912aeb32e870]

}
