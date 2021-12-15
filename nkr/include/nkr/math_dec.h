/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/bool_t.h"
#include "nkr/intrinsics.h"
#include "nkr/traits.h"

namespace nkr { namespace math { namespace $fraction_t {

    template <auto NUMERATOR_p, auto DENOMINATOR_p>
    class integer_sp
    {
    public:
        using numerator_t   = decltype(NUMERATOR_p);
        using denominator_t = decltype(DENOMINATOR_p);

    public:
        static constexpr numerator_t    Numerator();
        static constexpr denominator_t  Denominator();

        static constexpr real_t         To_Decimal();
    };

}}}

namespace nkr { namespace math {

    template <typename fraction_p>
    concept fraction_i = requires()
    {
        typename fraction_p::numerator_t;
        typename fraction_p::denominator_t;

        fraction_p::Numerator();
        fraction_p::Denominator();
        fraction_p::To_Decimal();
    };

    template <integer_tr auto NUMERATOR_p, integer_tr auto DENOMINATOR_p>
    class fraction_t :
        public $fraction_t::integer_sp<NUMERATOR_p, DENOMINATOR_p>
    {
    };
    static_assert(fraction_i<fraction_t<1, 1>>);

}}

namespace nkr { namespace math {

    constexpr auto              Absolute(integer_unsigned_tr auto unsigned_integer);
    constexpr auto              Absolute(integer_signed_tr auto signed_integer);

    constexpr c_bool_t          Is_Even(integer_tr auto integer);
    constexpr c_bool_t          Is_Odd(integer_tr auto integer);

    constexpr c_bool_t          Is_Power_Of_2(integer_unsigned_tr auto unsigned_integer);
    constexpr c_bool_t          Is_Power_Of_2(integer_signed_tr auto signed_integer);

    constexpr unsigned_word_t   Round_To_Power_Of_2(integer_unsigned_tr auto unsigned_integer);

    template <number_tr number_p>
    bool_t                      Will_Overflow_Add(number_p lhs, number_p rhs);
    template <number_tr number_p>
    bool_t                      Will_Overflow_Subtract(number_p lhs, number_p rhs);
    template <number_tr number_p>
    bool_t                      Will_Overflow_Multiply(number_p lhs, number_p rhs);
    template <number_tr number_p>
    bool_t                      Will_Overflow_Divide(number_p lhs, number_p rhs);

}}
