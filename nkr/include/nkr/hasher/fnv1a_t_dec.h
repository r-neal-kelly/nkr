/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsics.h"
#include "nkr/math.h"
#include "nkr/traits.h"

#include "nkr/allocator_err.h"

#include "nkr/array/dynamic_t.h"
#include "nkr/array/stack_t.h"
#include "nkr/array/static_t.h"

#include "nkr/hasher_i.h"

// not sure where to put this yet because if we put it in math, math will need to reference arrays which could lead to some circular includes if we're not careful
namespace nkr {

    // the numbers must be from the least significant unit unto the most significant unit

    template <integer_unsigned_tr unit_p>
    maybe_t<allocator_err>
        Add(tr2<any_tg, array::static_t, of_any_tg, unit_p> auto number_a,
            tr2<any_tg, array::static_t, of_any_tg, unit_p> auto number_b,
            tr2<any_tg, aggregate_array_ttg, of_any_tg, unit_p> auto& result)
    {
        using unit_t = unit_p;

        nkr_ASSERT_THAT(number_a.Count() > 0);
        nkr_ASSERT_THAT(number_b.Count() > 0);

        const count_t number_a_count = number_a.Count();
        const count_t number_b_count = number_b.Count();
        const count_t min_count = std::min(number_a_count, number_b_count);
        const count_t max_count = std::max(number_a_count, number_b_count);

        bool_t do_carry = false;

        result.Clear();
        if (result.Capacity() < max_count) {
            maybe_t<allocator_err> err = result.Capacity(max_count);
            if (err) {
                return err;
            }
        }

        for (index_t idx = 0, end = min_count; idx < end; idx += 1) {
            const unit_t number_a_unit = number_a[idx];
            const unit_t number_b_unit = number_b[idx];
            if (do_carry) {
                if (number_a_unit + 1 == 0) {
                    result.Push(number_b_unit).Ignore_Error();
                } else {
                    const unit_t number_c_unit = number_a_unit + 1 + number_b_unit;
                    do_carry = number_c_unit < number_b_unit;
                    result.Push(number_c_unit).Ignore_Error();
                }
            } else {
                const unit_t number_c_unit = number_a_unit + number_b_unit;
                do_carry = number_c_unit < number_b_unit;
                result.Push(number_c_unit).Ignore_Error();
            }
        }

        if (number_a_count > number_b_count) {
            for (index_t idx = min_count, end = number_a_count; idx < end; idx += 1) {
                const unit_t number_a_unit = number_a[idx];
                if (do_carry) {
                    const unit_t number_c_unit = number_a_unit + 1;
                    do_carry = number_c_unit == 0;
                    result.Push(number_c_unit).Ignore_Error();
                } else {
                    result.Push(number_a_unit).Ignore_Error();
                }
            }
        } else if (number_b_count > number_a_count) {
            for (index_t idx = min_count, end = number_b_count; idx < end; idx += 1) {
                const unit_t number_b_unit = number_b[idx];
                if (do_carry) {
                    const unit_t number_c_unit = number_b_unit + 1;
                    do_carry = number_c_unit == 0;
                    result.Push(number_c_unit).Ignore_Error();
                } else {
                    result.Push(number_b_unit).Ignore_Error();
                }
            }
        }

        if (do_carry) {
            maybe_t<allocator_err> err = result.Push(unit_t(1));
            if (err) {
                result.Clear();
                return err;
            }
        }

        return allocator_err::NONE;
    }

    template <integer_unsigned_tr unit_p>
    maybe_t<allocator_err>
        Subtract(tr2<any_tg, array::static_t, of_any_tg, unit_p> auto number_a,
                 tr2<any_tg, array::static_t, of_any_tg, unit_p> auto number_b,
                 tr2<any_tg, aggregate_array_ttg, of_any_tg, unit_p> auto& result)
    {
        using unit_t = unit_p;

        nkr_ASSERT_THAT(number_a.Count() > 0);
        nkr_ASSERT_THAT(number_b.Count() > 0);

        const count_t number_a_count = number_a.Count();
        const count_t number_b_count = number_b.Count();
        const count_t min_count = std::min(number_a_count, number_b_count);
        const count_t max_count = std::max(number_a_count, number_b_count);

        bool_t do_carry = false;

        result.Clear();
        if (result.Capacity() < max_count) {
            maybe_t<allocator_err> err = result.Capacity(max_count);
            if (err) {
                return err;
            }
        }

        for (index_t idx = 0, end = min_count; idx < end; idx += 1) {
            const unit_t number_a_unit = number_a[idx];
            const unit_t number_b_unit = ~number_b[idx];
            if (do_carry) {
                if (number_a_unit + 1 == 0) {
                    result.Push(number_b_unit).Ignore_Error();
                } else {
                    const unit_t number_c_unit = number_a_unit + 1 + number_b_unit;
                    do_carry = number_c_unit < number_b_unit;
                    result.Push(number_c_unit).Ignore_Error();
                }
            } else {
                const unit_t number_c_unit = number_a_unit + number_b_unit;
                do_carry = number_c_unit < number_b_unit;
                result.Push(number_c_unit).Ignore_Error();
            }
        }

        if (number_a_count > number_b_count) {
            for (index_t idx = min_count, end = number_a_count; idx < end; idx += 1) {
                const unit_t number_a_unit = number_a[idx];
                const unit_t number_b_unit = ~0;
                if (do_carry) {
                    if (number_a_unit + 1 == 0) {
                        result.Push(number_b_unit).Ignore_Error();
                    } else {
                        const unit_t number_c_unit = number_a_unit + 1 + number_b_unit;
                        result.Push(number_c_unit).Ignore_Error();
                    }
                } else {
                    const unit_t number_c_unit = number_a_unit + number_b_unit;
                    do_carry = number_c_unit < number_b_unit;
                    result.Push(number_c_unit).Ignore_Error();
                }
            }
        } else if (number_b_count > number_a_count) {
            for (index_t idx = min_count, end = number_b_count; idx < end; idx += 1) {
                const unit_t number_b_unit = ~number_b[idx];
                if (do_carry) {
                    const unit_t number_c_unit = number_b_unit + 1;
                    do_carry = number_c_unit == 0;
                    result.Push(number_c_unit).Ignore_Error();
                } else {
                    result.Push(number_b_unit).Ignore_Error();
                }
            }
        }

        for (index_t idx = 0, end = result.Count(); idx < end && (result[idx] += 1) == 0; idx += 1) {
        }

        for (count_t count = result.Count(); count > 1 && result[count - 1] == 0; count -= 1) {
            result.Pop();
        }

        return allocator_err::NONE;
    }

    template <integer_unsigned_tr unit_p>
    maybe_t<allocator_err>
        Karatsuba_Multiply(tr2<any_tg, array::static_t, of_any_tg, unit_p> auto number_a,
                           tr2<any_tg, array::static_t, of_any_tg, unit_p> auto number_b,
                           tr2<any_tg, aggregate_array_ttg, of_any_tg, unit_p> auto& result)
    {
        // W.I.P. I'm still trying to understand how to implement this, although I'm getting closer now that I've realized that
        // I'll need both an add and subtract for arbitrary point to make this work.

        // I feel certain that we can use some array:stack_t's as buffers and only a handful of them to save on memory.
        // we essentially need to push the first element of our equation into the result buffer, recurse, and then push the last.
        // doing that pattern should come up with the correct result with only using one buffer.

        // now we also need more buffers, for example to add to bigger numbers. but because we have the full length of the original
        // numbers up front, we can surely calculate that buffer once and just reuse it seeing how this recursion is of course done
        // serially.

        nkr_ASSERT_THAT(number_a.Count() > 0);
        nkr_ASSERT_THAT(number_b.Count() > 0);
        nkr_ASSERT_THAT(result.Count() == 0); // must be cleared before this code recurses

        nkr_ASSERT_THAT(number_a.Count() == number_b.Count()); // temp until we add the mechanism to pad the lower digit number with zeros.

        if (number_a.Count() == 1 && number_b.Count() == 1) {
            // don't forget you can pad zeros
        } else {
            array::dynamic_ttg<u8_t> result;

            count_t m = std::min(number_a.Count(), number_b.Count()) / 2;

            // so we need two buffers for the results of two additions. each buffer simply needs to have the same size as the original numbers,
            // because we are halving each number's digits before adding, so that's plenty of room.

            // we need one buffer twice the size of the original number's for the actual multiply. I think we need something other than the result
            // buffer? I think it can be done with stack_arrays though, and they get progressively smaller by half

            // so I think the subtraction section can use the same buffers that we add the two numbers together.
        }
    }

}

namespace nkr { namespace hasher {

    class fnv1a_32_t
    {
    public:
    };

    class fnv1a_64_t
    {
    public:
    };

    class fnv1a_128_t
    {
    public:
    };

    // etc

#if defined(nkr_IS_64_BIT)
    using fnv1a_t = fnv1a_64_t;
#elif defined(nkr_IS_32_BIT)
    using fnv1a_t = fnv1a_32_t;
#endif

}}
