/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/fors.h"

#include "intrinsics.h"

namespace nkr {

    template <boolean_tr boolean_p>
    inline boolean_p Random(real_t probability_for_true = 0.5)
    {
        std::lock_guard<std::mutex> locker(random_lock);
        return std::bernoulli_distribution(probability_for_true)(random_generator);
    }

    template <integer_tr integer_p>
    inline integer_p Random(integer_p from_inclusive = std::numeric_limits<integer_p>::lowest(),
                            integer_p to_inclusive = std::numeric_limits<integer_p>::max())
    {
        if constexpr (sizeof(integer_p) > sizeof(word_t)) {
            std::lock_guard<std::mutex> locker(random_lock);
            return static_cast<integer_p>(std::uniform_int_distribution<integer_p>(
                static_cast<integer_p>(from_inclusive),
                static_cast<integer_p>(to_inclusive))(random_generator));
        } else {
            using word_t = word_for_t<integer_p>;

            std::lock_guard<std::mutex> locker(random_lock);
            return static_cast<integer_p>(std::uniform_int_distribution<word_t>(
                static_cast<word_t>(from_inclusive),
                static_cast<word_t>(to_inclusive))(random_generator));
        }
    }

    template <real_tr real_p>
    inline real_p Random(real_p from_inclusive = std::numeric_limits<real_p>::lowest(),
                         real_p to_inclusive = std::numeric_limits<real_p>::max())
    {
        bool_t do_negative = false;
        if (from_inclusive < 0.0) {
            real_p abs_from_inclusive = abs(from_inclusive);
            real_p abs_to_inclusive = abs(to_inclusive);
            if (to_inclusive > 0.0) {
                if (abs_from_inclusive > abs_to_inclusive) {
                    do_negative = !Random<bool_t>(abs_to_inclusive / abs_from_inclusive / 2);
                } else {
                    do_negative = Random<bool_t>(abs_from_inclusive / abs_to_inclusive / 2);
                }
                if (do_negative) {
                    from_inclusive = 0.0;
                    to_inclusive = abs_from_inclusive;
                } else {
                    from_inclusive = 0.0;
                    to_inclusive = abs_to_inclusive;
                }
            } else {
                do_negative = true;
                from_inclusive = abs_to_inclusive;
                to_inclusive = abs_from_inclusive;
            }
        }

        std::lock_guard<std::mutex> locker(random_lock);
        if (do_negative) {
            return -std::uniform_real_distribution<real_p>(from_inclusive, to_inclusive)(random_generator);
        } else {
            return std::uniform_real_distribution<real_p>(from_inclusive, to_inclusive)(random_generator);
        }
    }

    template <real_tr real_p, integer_tr integer_p>
    inline real_p Random(integer_p from_inclusive, integer_p to_inclusive)
    {
        return Random<real_p>(static_cast<real_p>(from_inclusive), static_cast<real_p>(to_inclusive));
    }

}