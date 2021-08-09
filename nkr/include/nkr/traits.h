/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsic.h"

namespace nkr { namespace trait {

    template <typename type>
    concept sized       = sizeof(type) > 0;

    template <typename type>
    concept integral    = std::is_integral<type>::value;

}}
