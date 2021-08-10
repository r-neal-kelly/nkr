/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsic.h"

namespace nkr {

    template <typename type>
    concept sized_tr    = sizeof(type) > 0;

    template <typename type>
    concept integral_tr = std::is_integral<type>::value;

}
