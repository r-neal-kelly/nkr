/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsic.h"

namespace nkr {

    template <typename type>
    concept sized_t = sizeof(type) > 0;

}
