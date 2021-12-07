/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsics.h"
#include "nkr/maybe_t.h"
#include "nkr/traits.h"

#include "nkr/allocator_err.h"

#include "nkr/array_i.h"
#include "nkr/array/high_pad_t.h"
#include "nkr/array/static_t.h"

namespace nkr { namespace number {

    // these are temporarily loose or will somehow go in the math namespace once we can properly forward declare array types.

    template <integer_unsigned_tr unit_p>
    maybe_t<allocator_err>  Add(const tr2<any_tg, array_ttg, of_any_tg, unit_p> auto& number_a,
                                const tr2<any_tg, array_ttg, of_any_tg, unit_p> auto& number_b,
                                tr2<any_tg, aggregate_array_ttg, of_any_tg, unit_p> auto& result);

    template <integer_unsigned_tr unit_p>
    count_t                 Add(const tr2<any_tg, array_ttg, of_any_tg, unit_p> auto& number_a,
                                const tr2<any_tg, array_ttg, of_any_tg, unit_p> auto& number_b,
                                tr2<any_tg, non_aggregate_array_ttg, of_any_tg, unit_p> auto& result);

    template <integer_unsigned_tr unit_p>
    void_t                  Add_In_Place(tr2<any_non_const_tg, array_ttg, of_any_non_const_tg, unit_p> auto& number_a,
                                         const tr2<any_tg, array_ttg, of_any_tg, unit_p> auto& number_b);

    template <integer_unsigned_tr unit_p>
    maybe_t<allocator_err>  Subtract(const tr2<any_tg, array_ttg, of_any_tg, unit_p> auto& number_a,
                                     const tr2<any_tg, array_ttg, of_any_tg, unit_p> auto& number_b,
                                     tr2<any_tg, aggregate_array_ttg, of_any_tg, unit_p> auto& result);

    template <integer_unsigned_tr unit_p>
    void_t                  Subtract_In_Place(tr2<any_non_const_tg, array_ttg, of_any_non_const_tg, unit_p> auto& number_a,
                                              const tr2<any_tg, array_ttg, of_any_tg, unit_p> auto& number_b);

    template <integer_unsigned_tr unit_p>
    maybe_t<allocator_err>  Multiply(const tr2<any_tg, pointable_array_ttg, of_any_tg, unit_p> auto& number_a,
                                     const tr2<any_tg, pointable_array_ttg, of_any_tg, unit_p> auto& number_b,
                                     tr2<any_tg, aggregate_array_ttg, of_any_tg, unit_p> auto& result,
                                     tr2<any_non_const_tg, aggregate_array_ttg, of_any_non_const_tg, unit_p> auto& buffer);

}}

namespace nkr { namespace number {

    template <integer_unsigned_tr unit_p, count_t capacity_p = array::Default_Unit_Count()>
    class stack_arbitrary_t
    {
    public:
        using unit_t    = unit_p;
        using array_t   = array::stack_t<unit_t, capacity_p>;

    private:
        using safe_multiply_unit_t  = word_t;

    public:
        static_assert(sizeof(unit_t) <= sizeof(safe_multiply_unit_t) / 2);

    public:
        static constexpr count_t    Capacity();

    protected:
        array_t                 number;
        maybe_t<allocator_err>  err;        // the idea here is to assert in every method that this == NONE, except the has error method, which clears it

    public:
        // I want the ctor to take an array of numbers in reverse I think, so it's easier to read static data?
        // but interally it will always be in little endian, least significant unit first

    public:
        template <typename other_p>
        stack_arbitrary_t<unit_t, Capacity() + other_p::Capacity()> Add();
        stack_arbitrary_t&  Add_Equals();

    public:
        //stack_arbitrary_t   operator +();
        //stack_arbitrary_t&  operator +=();
    };

    // for the above type when we have say a *= method, it will be allowed to grow its internal array, including for += and -=.
    // we do have in-place functions above that allow for the integer to overflow, however I'm not sure how to best reveal that
    // functionality in the type. We'll do the above because it seems unlikely we'll develop an overflow mult method, just too hard.
    // instead we'll grow the internal array by the necessary amount and return on failure else calc.

    template <integer_unsigned_tr unit_p> // we need to be able to pass in the allocator and grow_rate
    class dynamic_arbitrary_t
    {
    public:
    };

    // we can have an arbitrary_t that selects the right sub type based on a passed in array, but I want to keep these separate until we see
    // that it wouldn't be super convulted to combine them.

    // also, we could just use the dynamic array and let the passed in allocator type deal with this. we really need to reinvigorate our allocator
    // system to allow the allocator to be in the type's footprint. we can of course have specialization for static allocators so that there is
    // no need to put it on the footprint and just have the constexpr switch in the places where it's used in the array def

}}
