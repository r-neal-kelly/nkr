/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include <mutex>
#include <random>

#include "nkr/bool_t.h"
#include "nkr/intrinsics.h"
#include "nkr/traits.h"

#include "doctest.h"

namespace nkr {

    // we'll eventually move this stuff to the library, within a class or something
    extern std::random_device   random_device;
    extern std::mt19937_64      random_generator;
    extern std::mutex           random_lock;

    template <boolean_tr boolean_p>
    boolean_p   Random(real_t probability_for_true);
    template <integer_tr integer_p>
    integer_p   Random(integer_p from_inclusive, integer_p to_inclusive);
    template <real_tr real_p>
    real_p      Random(real_p from_inclusive, real_p to_inclusive);
    template <real_tr real_p, integer_tr integer_p>
    real_p      Random(integer_p from_inclusive, integer_p to_inclusive);

}

#include "intrinsics.inl"
