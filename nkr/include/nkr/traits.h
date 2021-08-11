/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsic.h"

namespace nkr {

    template <typename type_p>
    concept bool_tr =
        std::same_as<type_p, bool_t> &&
        (sizeof(type_p) == sizeof(u8_t));

    template <typename type_p>
    concept integral_tr =
        std::is_integral<type_p>::value;

    template <typename type_p>
    concept integral_unsigned_tr =
        std::is_integral<type_p>::value &&
        std::is_unsigned<type_p>::value;

    template <typename type_p>
    concept integral_signed_tr =
        std::is_integral<type_p>::value &&
        std::is_signed<type_p>::value;

    template <typename type_p>
    concept integral_8_bit_tr =
        std::is_integral<type_p>::value &&
        (sizeof(type_p) == sizeof(u8_t));

    template <typename type_p>
    concept integral_16_bit_tr =
        std::is_integral<type_p>::value &&
        (sizeof(type_p) == sizeof(u16_t));

    template <typename type_p>
    concept integral_32_bit_tr =
        std::is_integral<type_p>::value &&
        (sizeof(type_p) == sizeof(u32_t));

    template <typename type_p>
    concept integral_64_bit_tr =
        std::is_integral<type_p>::value &&
        (sizeof(type_p) == sizeof(u64_t));

    template <typename type_p>
    concept pointer_tr =
        std::is_pointer<type_p>::value;

    template <typename type_p>
    concept sized_tr
        = sizeof(type_p) > 0;

    template <typename type_p>
    concept addable_tr
        = requires(type_p instance) { instance + 1; };

    template <typename type_p>
    concept subtractable_tr
        = requires(type_p instance) { instance - 1; };

}
