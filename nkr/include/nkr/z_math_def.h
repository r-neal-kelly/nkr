/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include <cmath>

#include "nkr/z_fors.h"
#include "nkr/z_math_dec.h"

namespace nkr { namespace math { namespace $fraction_t {

    template <auto NUMERATOR_p, auto DENOMINATOR_p>
    inline constexpr typename integer_sp<NUMERATOR_p, DENOMINATOR_p>::numerator_t
        integer_sp<NUMERATOR_p, DENOMINATOR_p>::Numerator()
    {
        return NUMERATOR_p;
    }

    template <auto NUMERATOR_p, auto DENOMINATOR_p>
    inline constexpr typename integer_sp<NUMERATOR_p, DENOMINATOR_p>::denominator_t
        integer_sp<NUMERATOR_p, DENOMINATOR_p>::Denominator()
    {
        return DENOMINATOR_p;
    }

    template <auto NUMERATOR_p, auto DENOMINATOR_p>
    inline constexpr real_t
        integer_sp<NUMERATOR_p, DENOMINATOR_p>::To_Decimal()
    {
        static_assert(Denominator() >= 0, "denominator must be > 0");

        return static_cast<real_t>(Numerator()) / static_cast<real_t>(Denominator());
    }

}}}

namespace nkr { namespace math {

    inline constexpr auto
        Absolute(integer_unsigned_tr auto unsigned_integer)
    {
        return unsigned_integer;
    }

    inline constexpr auto
        Absolute(integer_signed_tr auto signed_integer)
    {
        using sint_t = decltype(signed_integer);
        using uint_t = integer_unsigned_for_t<sint_t>;

        return signed_integer < 0 ? uint_t(sint_t(-1) - signed_integer) + 1 : uint_t(signed_integer);
    }

    inline constexpr c_bool_t
        Is_Even(integer_tr auto integer)
    {
        return (integer & 1) == 0;
    }

    inline constexpr c_bool_t
        Is_Odd(integer_tr auto integer)
    {
        return (integer & 1) == 1;
    }

    inline constexpr c_bool_t
        Is_Power_Of_2(integer_unsigned_tr auto unsigned_integer)
    {
        return unsigned_integer != 0 && (unsigned_integer & (unsigned_integer - 1)) == 0;
    }

    inline constexpr c_bool_t
        Is_Power_Of_2(integer_signed_tr auto signed_integer)
    {
        return Is_Power_Of_2(Absolute(signed_integer));
    }

    inline constexpr unsigned_word_t
        Round_To_Power_Of_2(integer_unsigned_tr auto unsigned_integer)
    {
        using integer_t = decltype(unsigned_integer);

        static_assert(sizeof(integer_t) <= sizeof(unsigned_word_t));

        constexpr count_t bit_count = sizeof(decltype(unsigned_integer)) * 8;

        unsigned_word_t result = unsigned_integer;
        result -= 1;
        if constexpr (bit_count > 1) {
            result |= result >> 1;
        }
        if constexpr (bit_count > 2) {
            result |= result >> 2;
        }
        if constexpr (bit_count > 4) {
            result |= result >> 4;
        }
        if constexpr (bit_count > 8) {
            result |= result >> 8;
        }
        if constexpr (bit_count > 16) {
            result |= result >> 16;
        }
        if constexpr (bit_count > 32) {
            result |= result >> 32;
        }
        if constexpr (bit_count > 64) {
            result |= result >> 64;
        }
        if constexpr (bit_count > 128) {
            [] <bool _ = false>() { static_assert(_, "unimplemented type"); }();
        }
        result += 1;
        result += (result == 0);

        return result;
    }

    template <number_tr number_p>
    inline bool_t
        Will_Overflow_Add(number_p lhs, number_p rhs)
    {
        return
            (lhs > 0 && rhs > std::numeric_limits<number_p>::max() - lhs) ||
            (lhs < 0 && rhs < std::numeric_limits<number_p>::lowest() - lhs);
    }

    template <number_tr number_p>
    inline bool_t
        Will_Overflow_Subtract(number_p lhs, number_p rhs)
    {
        return
            (lhs > 0 && rhs < std::numeric_limits<number_p>::max() - lhs) ||
            (lhs < 0 && rhs > std::numeric_limits<number_p>::lowest() - lhs);
    }

    template <number_tr number_p>
    inline bool_t
        Will_Overflow_Multiply(number_p lhs, number_p rhs)
    {
        return
            lhs != 0 &&
            ((lhs == std::numeric_limits<number_p>::lowest() && rhs == -1) ||
             (lhs == -1 && rhs == std::numeric_limits<number_p>::lowest()) ||
             (rhs > std::numeric_limits<number_p>::max() / lhs) ||
             (rhs < std::numeric_limits<number_p>::lowest() / lhs));
    }

    template <number_tr number_p>
    inline bool_t
        Will_Overflow_Divide(number_p lhs, number_p rhs)
    {
        return
            (lhs == std::numeric_limits<number_p>::lowest() && rhs == -1);
    }

}}
