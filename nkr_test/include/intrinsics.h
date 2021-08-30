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
    boolean_p           Random(float_t probability_for_true);
    template <integer_unsigned_tr integer_unsigned_p>
    integer_unsigned_p  Random(integer_unsigned_p from_inclusive, integer_unsigned_p to_inclusive);
    template <float_tr float_p>
    float_p             Random(float_p from_inclusive, float_p to_inclusive);

    template <boolean_tr boolean_p>
    inline boolean_p Random(float_t probability_for_true = 0.5)
    {
        std::lock_guard<std::mutex> locker(random_lock);
        return std::bernoulli_distribution(probability_for_true)(random_generator);
    }

    template <integer_unsigned_tr integer_unsigned_p>
    inline integer_unsigned_p Random(integer_unsigned_p from_inclusive = 0,
                                     integer_unsigned_p to_inclusive = std::numeric_limits<integer_unsigned_p>::max())
    {
        std::lock_guard<std::mutex> locker(random_lock);
        return std::uniform_int_distribution<integer_unsigned_p>(from_inclusive, to_inclusive)(random_generator);
    }

    template <float_tr float_p>
    inline float_p Random(float_p from_inclusive = -std::numeric_limits<float_p>::max(),
                          float_p to_inclusive = std::numeric_limits<float_p>::max())
    {
        bool_t do_negative;
        if (from_inclusive < 0.0) {
            if (to_inclusive > 0.0) {
                do_negative = Random<bool_t>();
                if (do_negative) {
                    to_inclusive = abs(from_inclusive);
                    from_inclusive = 0.0;
                } else {
                    from_inclusive = 0.0;
                }
            } else {
                do_negative = true;
                float_t temp = to_inclusive;
                to_inclusive = abs(from_inclusive);
                from_inclusive = abs(temp);
            }
        } else {
            do_negative = false;
        }

        std::lock_guard<std::mutex> locker(random_lock);
        if (do_negative) {
            return -std::uniform_real_distribution<float_p>(from_inclusive, to_inclusive)(random_generator);
        } else {
            return std::uniform_real_distribution<float_p>(from_inclusive, to_inclusive)(random_generator);
        }
    }

}
