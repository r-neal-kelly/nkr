/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/z_fors.h"
#include "nkr/z_utils_dec.h"

namespace nkr {

    inline constexpr auto
        Move(built_in_tr auto& value)
        noexcept
    {
        auto old = static_cast<std::remove_reference_t<decltype(value)>&&>(value);
        value = static_cast<std::remove_cvref_t<decltype(value)>>(0);

        return old;
    }

    inline constexpr auto&&
        Move(const built_in_tr auto& value)
        noexcept
    {
        return static_cast<std::remove_reference_t<decltype(value)>&&>(value);
    }

    inline constexpr auto&&
        Move(built_in_tr auto&& value)
        noexcept
    {
        return static_cast<std::remove_reference_t<decltype(value)>&&>(value);
    }

    inline constexpr auto&&
        Move(const built_in_tr auto&& value)
        noexcept
    {
        return static_cast<std::remove_reference_t<decltype(value)>&&>(value);
    }

    inline constexpr auto&&
        Move(user_defined_tr auto& value)
        noexcept
    {
        return static_cast<std::remove_reference_t<decltype(value)>&&>(value);
    }

    inline constexpr auto&&
        Move(user_defined_tr auto&& value)
        noexcept
    {
        return static_cast<std::remove_reference_t<decltype(value)>&&>(value);
    }

    inline constexpr auto
        Exchange(any_type_tr auto& value, any_type_tr auto& with)
        noexcept
    {
        using value_t = std::remove_reference_t<decltype(value)>;
        using with_t = std::remove_reference_t<decltype(with)>;

        value_t old = static_cast<value_t&&>(value);
        value = with;

        return old;
    }

    inline constexpr auto
        Exchange(any_type_tr auto& value, any_non_const_tr auto&& with)
        noexcept
    {
        using value_t = std::remove_reference_t<decltype(value)>;
        using with_t = std::remove_reference_t<decltype(with)>;

        value_t old = static_cast<value_t&&>(value);
        value = static_cast<with_t&&>(with);

        return old;
    }

    inline count_t
        C_String_Unit_Count(const any_integer_tr auto* c_string)
    {
        nkr_ASSERT_THAT(c_string != nullptr);

        count_t count = 0;
        while (*c_string != 0) {
            count += 1;
            c_string += 1;
        }

        return count + 1;
    }

    inline count_t
        C_String_Unit_Length(const any_integer_tr auto* c_string)
    {
        nkr_ASSERT_THAT(c_string != nullptr);

        count_t count = 0;
        while (*c_string != 0) {
            count += 1;
            c_string += 1;
        }

        return count;
    }

    template <boolean_tr boolean_p>
    inline boolean_p
        Random(real_t probability_for_true = 0.5)
    {
        nkr_ASSERT_THAT(probability_for_true >= 0.0);
        nkr_ASSERT_THAT(probability_for_true <= 1.0);

        std::lock_guard<std::mutex> locker(random_lock);
        return std::bernoulli_distribution(probability_for_true)(random_generator);
    }

    template <integer_tr integer_p>
    inline integer_p
        Random(std::remove_cv_t<integer_p> from_inclusive = std::numeric_limits<std::remove_cv_t<integer_p>>::lowest(),
               std::remove_cv_t<integer_p> to_inclusive = std::numeric_limits<std::remove_cv_t<integer_p>>::max())
    {
        using integer_pp = std::remove_cv_t<integer_p>;

        if constexpr (sizeof(integer_pp) > sizeof(word_t)) {
            std::lock_guard<std::mutex> locker(random_lock);
            return static_cast<integer_pp>(std::uniform_int_distribution<integer_pp>(
                static_cast<integer_pp>(from_inclusive),
                static_cast<integer_pp>(to_inclusive))(random_generator));
        } else {
            using word_t = word_for_t<integer_pp>;

            std::lock_guard<std::mutex> locker(random_lock);
            return static_cast<integer_pp>(std::uniform_int_distribution<word_t>(
                static_cast<word_t>(from_inclusive),
                static_cast<word_t>(to_inclusive))(random_generator));
        }
    }

    template <integer_tr integer_p, real_tr real_p>
    inline integer_p
        Random(real_p from_inclusive, real_p to_inclusive)
    {
        return Random<integer_p>(static_cast<integer_p>(from_inclusive), static_cast<integer_p>(to_inclusive));
    }

    template <real_tr real_p>
    inline real_p
        Random(std::remove_cv_t<real_p> from_inclusive = std::numeric_limits<std::remove_cv_t<real_p>>::lowest(),
               std::remove_cv_t<real_p> to_inclusive = std::numeric_limits<std::remove_cv_t<real_p>>::max())
    {
        using real_pp = std::remove_cv_t<real_p>;

        // we want a proportional chance of getting a negative number. if from is -10 and to is 10
        // then it should return either 50% of the time. if from is -10 and to is 20, then negative
        // should be returned 25% of the time and positive 75% of the time.
        bool_t do_negative = false;
        if (from_inclusive < 0.0) {
            real_pp abs_from_inclusive = abs(from_inclusive);
            real_pp abs_to_inclusive = abs(to_inclusive);
            if (to_inclusive > 0.0) {
                if (abs_from_inclusive > abs_to_inclusive) {
                    do_negative = !Random<bool_t>(real_t(abs_to_inclusive / abs_from_inclusive / 2));
                } else {
                    do_negative = Random<bool_t>(real_t(abs_from_inclusive / abs_to_inclusive / 2));
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
            return -std::uniform_real_distribution<real_pp>(from_inclusive, to_inclusive)(random_generator);
        } else {
            return std::uniform_real_distribution<real_pp>(from_inclusive, to_inclusive)(random_generator);
        }
    }

    template <real_tr real_p, integer_tr integer_p>
    inline real_p
        Random(integer_p from_inclusive, integer_p to_inclusive)
    {
        return Random<real_p>(static_cast<real_p>(from_inclusive), static_cast<real_p>(to_inclusive));
    }

    template <c_pointer_tr c_pointer_p>
    inline c_pointer_p
        Random()
    {
        return reinterpret_cast<std::remove_cv_t<c_pointer_p>>(Random<address_t>());
    }

}
