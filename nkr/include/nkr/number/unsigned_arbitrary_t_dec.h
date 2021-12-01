/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsics.h"
#include "nkr/maybe_t.h"
#include "nkr/traits.h"

#include "nkr/allocator_err.h"

#include "nkr/array_i.h"
#include "nkr/array/static_t.h"

namespace nkr { namespace number {

    // these are temporarily loose

    template <integer_unsigned_tr unit_p>
    maybe_t<allocator_err>  Add(tr2<any_tg, array::static_t, of_any_tg, unit_p> auto number_a,
                                tr2<any_tg, array::static_t, of_any_tg, unit_p> auto number_b,
                                tr2<any_tg, aggregate_array_ttg, of_any_tg, unit_p> auto& result);
    template <integer_unsigned_tr unit_p>
    void_t                  Add_In_Place(tr2<any_non_const_tg, array_ttg, of_any_non_const_tg, unit_p> auto& number_a,
                                         const tr2<any_tg, array_ttg, of_any_tg, unit_p> auto& number_b);

    template <integer_unsigned_tr unit_p>
    maybe_t<allocator_err>  Subtract(tr2<any_tg, array::static_t, of_any_tg, unit_p> auto number_a,
                                     tr2<any_tg, array::static_t, of_any_tg, unit_p> auto number_b,
                                     tr2<any_tg, aggregate_array_ttg, of_any_tg, unit_p> auto& result);

    template <integer_unsigned_tr unit_p>
    void_t                  Subtract_In_Place(tr2<any_non_const_tg, array_ttg, of_any_non_const_tg, unit_p> auto& number_a,
                                              const tr2<any_tg, array_ttg, of_any_tg, unit_p> auto& number_b);

    template <integer_unsigned_tr unit_p>
    void_t                  Karatsuba_Multiply(tr2<any_tg, array::static_t, of_any_tg, unit_p> auto number_a,
                                               tr2<any_tg, array::static_t, of_any_tg, unit_p> auto number_b,
                                               tr2<any_tg, aggregate_array_ttg, of_any_tg, unit_p> auto& result);

    template <integer_unsigned_tr unit_p>
    class unsigned_arbitrary_t
    {
    public:
        using unit_t    = unit_p;

    public:
        // I want the ctor to take an array of numbers in reverse I think, so it's easier to read static data?
        // but interally it will always be in little endian, least significant byte first
    };

    // for the above type when we have say a *= method, it will be allowed to grow its internal array, including for += and -=.
    // we do have in-place functions above that allow for the integer to overflow, however I'm not sure how to best reveal that
    // functionality in the type. We'll do the above because it seems unlikely we'll develop and overflow mult method, just too hard.
    // instead we'll grow the internal array by the necessary amount and return on failure else calc.

}}
