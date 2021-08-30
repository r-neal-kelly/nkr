/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include <mutex>
#include <random>

#include "nkr/intrinsics.h"
#include "nkr/traits.h"

#include "doctest.h"

namespace nkr {

    // we'll eventually move this stuff to the library, within a class or something
    extern std::random_device   random_device;
    extern std::mt19937_64      random_generator;
    extern std::mutex           random_lock;

    template <boolean_tr boolean_p>
    boolean_p Random(f64_t probability_for_true = 0.5)
    {
        std::lock_guard<std::mutex> locker(random_lock);
        return std::bernoulli_distribution(probability_for_true)(random_generator);
    }

    template <integer_tr integer_p>
    integer_p Random(integer_p from_inclusive = std::numeric_limits<integer_p>::min(),
                     integer_p to_inclusive = std::numeric_limits<integer_p>::max())
    {
        std::lock_guard<std::mutex> locker(random_lock);
        return std::uniform_int_distribution<integer_p>(from_inclusive, to_inclusive)(random_generator);
    }

    template <float_tr float_p>
    float_p Random(float_p from_inclusive = std::numeric_limits<float_p>::min(),
                   float_p to_inclusive = std::numeric_limits<float_p>::max())
    {
        std::lock_guard<std::mutex> locker(random_lock);
        return std::uniform_real_distribution<float_p>(from_inclusive, to_inclusive)(random_generator);
    }

}
