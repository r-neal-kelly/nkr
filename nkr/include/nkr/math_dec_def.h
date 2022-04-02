/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_05703b88_5fdf_4d1b_9de8_6f3cbcdf3436
#define nkr_INCLUDE_GUARD_05703b88_5fdf_4d1b_9de8_6f3cbcdf3436

#include "nkr/math_dec.h"

namespace nkr { namespace math {

    inline constexpr auto
        Absolute(nkr::generic::positive_tr auto positive_integer)
        noexcept
    {
        return positive_integer;
    }

    inline constexpr auto
        Absolute(nkr::generic::negatable_tr auto negatable_integer)
        noexcept
    {
        using negatable_t = decltype(negatable_integer);
        using positive_t = nkr::cpp::relative_integer_t<negatable_t>;

        return negatable_integer < 0 ?
            positive_t(negatable_t(-1) - negatable_integer) + 1 :
            positive_t(negatable_integer);
    }

    inline constexpr nkr::boolean::cpp_t
        Is_Odd(nkr::generic::built_in::number::integer_tr auto integer)
        noexcept
    {
        return (integer & 1) == 1;
    }

    inline constexpr nkr::boolean::cpp_t
        Is_Even(nkr::generic::built_in::number::integer_tr auto integer)
        noexcept
    {
        return (integer & 1) == 0;
    }

    inline constexpr nkr::boolean::cpp_t
        Is_Power_Of_2(nkr::generic::positive_tr auto positive_integer)
        noexcept
    {
        return positive_integer != 0 && (positive_integer & (positive_integer - 1)) == 0;
    }

    inline constexpr nkr::boolean::cpp_t
        Is_Power_Of_2(nkr::generic::negatable_tr auto negatable_integer)
        noexcept
    {
        return Is_Power_Of_2(Absolute(negatable_integer));
    }

    inline constexpr nkr::positive::integer_t
        Round_To_Power_Of_2(nkr::generic::positive_tr auto positive_integer)
        noexcept
    {
        using positive_t = decltype(positive_integer);

        static_assert(sizeof(positive_t) <= sizeof(nkr::positive::integer_t));

        constexpr nkr::positive::count_t bit_count = sizeof(positive_t) * nkr::cpp::Byte_Bit_Count();

        nkr::positive::integer_t result = positive_integer;
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
            [] <nkr::boolean::cpp_t _ = false>() { static_assert(_, "unimplemented type"); }();
        }
        result += 1;
        result += (result == 0);

        return result;
    }

    template <nkr::generic::built_in::number_tr number_p>
    inline constexpr nkr::boolean::cpp_t
        Will_Overflow_Add(number_p lhs, number_p rhs)
        noexcept
    {
        return
            (lhs > 0 && rhs > nkr::cpp::Default_Max<number_p>() - lhs) ||
            (lhs < 0 && rhs < nkr::cpp::Default_Min<number_p>() - lhs);
    }

    template <nkr::generic::built_in::number_tr number_p>
    inline constexpr nkr::boolean::cpp_t
        Will_Overflow_Subtract(number_p lhs, number_p rhs)
        noexcept
    {
        return
            (lhs > 0 && rhs < nkr::cpp::Default_Max<number_p>() - lhs) ||
            (lhs < 0 && rhs > nkr::cpp::Default_Min<number_p>() - lhs);
    }

    template <nkr::generic::built_in::number_tr number_p>
    inline constexpr nkr::boolean::cpp_t
        Will_Overflow_Multiply(number_p lhs, number_p rhs)
        noexcept
    {
        return
            lhs != 0 &&
            ((lhs == nkr::cpp::Default_Min<number_p>() && rhs == -1) ||
             (lhs == -1 && rhs == nkr::cpp::Default_Min<number_p>()) ||
             (rhs > nkr::cpp::Default_Max<number_p>() / lhs) ||
             (rhs < nkr::cpp::Default_Min<number_p>() / lhs));
    }

    template <nkr::generic::built_in::number_tr number_p>
    inline constexpr nkr::boolean::cpp_t
        Will_Overflow_Divide(number_p lhs, number_p rhs)
        noexcept
    {
        return
            (lhs == nkr::cpp::Default_Min<number_p>() && rhs == -1);
    }

}}

#endif
