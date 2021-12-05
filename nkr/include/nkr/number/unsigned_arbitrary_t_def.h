/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/math.h"

#include "nkr/array/dynamic_t.h"

#include "nkr/number/unsigned_arbitrary_t.h"

namespace nkr { namespace number {

    template <integer_unsigned_tr unit_p>
    inline maybe_t<allocator_err>
        Add(const tr2<any_tg, array_ttg, of_any_tg, unit_p> auto& number_a,
            const tr2<any_tg, array_ttg, of_any_tg, unit_p> auto& number_b,
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
                if (unit_t(number_a_unit + 1) == 0) {
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
    inline void_t
        Add_In_Place(tr2<any_non_const_tg, array_ttg, of_any_non_const_tg, unit_p> auto& number_a,
                     const tr2<any_tg, array_ttg, of_any_tg, unit_p> auto& number_b)
    {
        using unit_t = unit_p;

        const count_t a_digit_count = number_a.Count();
        const count_t b_digit_count = number_b.Count();
        const count_t min_digit_count = std::min(a_digit_count, b_digit_count);

        bool_t do_carry = false;

        for (index_t idx = 0, end = min_digit_count; idx < end; idx += 1) {
            if (do_carry) {
                if ((number_a[idx] += 1) == 0) {
                    number_a[idx] = number_b[idx];
                } else {
                    number_a[idx] += number_b[idx];
                    do_carry = number_a[idx] < number_b[idx];
                }
            } else {
                number_a[idx] += number_b[idx];
                do_carry = number_a[idx] < number_b[idx];
            }
        }

        if (do_carry && a_digit_count > b_digit_count) {
            for (index_t idx = min_digit_count, end = a_digit_count; idx < end && (number_a[idx] += 1) == 0; idx += 1) {
            }
        }
    }

    template <integer_unsigned_tr unit_p>
    inline maybe_t<allocator_err>
        Subtract(const tr2<any_tg, array_ttg, of_any_tg, unit_p> auto& number_a,
                 const tr2<any_tg, array_ttg, of_any_tg, unit_p> auto& number_b,
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
                if (unit_t(number_a_unit + 1) == 0) {
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
                    if (unit_t(number_a_unit + 1) == 0) {
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

        // I don't know if I really want this to happen.
        for (count_t count = result.Count(); count > 1 && result[count - 1] == 0; count -= 1) {
            result.Pop();
        }

        return allocator_err::NONE;
    }

    template <integer_unsigned_tr unit_p>
    inline void_t
        Subtract_In_Place(tr2<any_non_const_tg, array_ttg, of_any_non_const_tg, unit_p> auto& number_a,
                          const tr2<any_tg, array_ttg, of_any_tg, unit_p> auto& number_b)
    {
        using unit_t = unit_p;

        const count_t a_digit_count = number_a.Count();
        const count_t b_digit_count = number_b.Count();
        const count_t min_digit_count = std::min(a_digit_count, b_digit_count);

        bool_t do_carry = false;

        for (index_t idx = 0, end = min_digit_count; idx < end; idx += 1) {
            unit_t b_digit = ~number_b[idx];
            if (do_carry) {
                if ((number_a[idx] += 1) == 0) {
                    number_a[idx] = b_digit;
                } else {
                    number_a[idx] += b_digit;
                    do_carry = number_a[idx] < b_digit;
                }
            } else {
                number_a[idx] += b_digit;
                do_carry = number_a[idx] < b_digit;
            }
        }

        for (index_t idx = min_digit_count, end = a_digit_count; idx < end; idx += 1) {
            unit_t b_digit = unit_t(~0);
            if (do_carry) {
                if ((number_a[idx] += 1) == 0) {
                    number_a[idx] = b_digit;
                } else {
                    number_a[idx] += b_digit;
                    do_carry = number_a[idx] < b_digit;
                }
            } else {
                number_a[idx] += b_digit;
                do_carry = number_a[idx] < b_digit;
            }
        }

        for (index_t idx = 0, end = a_digit_count; idx < end && (number_a[idx] += 1) == 0; idx += 1) {
        }
    }

    //template <integer_unsigned_tr unit_p>
    //inline maybe_t<allocator_err>
    //    Left_Shift(tr2<any_non_const_tg, aggregate_array_ttg, of_any_non_const_tg, unit_p> auto& number_a,
    //               count_t bit_count)
    //{
    //    using unit_t = unit_p;

    //    constexpr count_t unit_bit_count = sizeof(unit_t) * 8;

    //    if (bit_count <= unit_bit_count) {
    //        unit_t previous_bits = 0;
    //        unit_t next_bits = 0;
    //        for (index_t idx = 0, end = number_a.Count(); idx < end; idx += 1) {
    //            next_bits = number_a[idx] >> (unit_bit_count - bit_count);
    //            number_a[idx] = (number_a[idx] << bit_count) | previous_bits;
    //            previous_bits = next_bits;
    //        }

    //        maybe_t<allocator_err> err = number_a.Push(next_bits);
    //        if (err) {
    //            // we could check to see if there is more capacity than count before operating to preserve the state of the data
    //            return err;
    //        }
    //    } else {
    //        nkr_ASSERT_THAT(false);
    //        // not yet implemented
    //    }

    //    return allocator_err::NONE;
    //}
    
    template <integer_unsigned_tr unit_p>
    inline void_t
        Private_Karatsuba_Multiply(const tr2<any_tg, array::high_pad_ttg, of_any_tg, unit_p> auto& number_a,
                                   const tr2<any_tg, array::high_pad_ttg, of_any_tg, unit_p> auto& number_b,
                                   tr2<any_tg, aggregate_array_ttg, of_any_tg, unit_p> auto& result)
    {
        using unit_t = unit_p;
        using safe_multiply_t = word_t;

        static_assert(sizeof(unit_t) <= sizeof(safe_multiply_t) / 2);

        nkr_ASSERT_THAT(number_a.Count() > 0);
        nkr_ASSERT_THAT(number_a.Count() == number_b.Count());
        nkr_ASSERT_THAT(result.Count() == 0); // we want this to be the Capacity count, because we're going to end up using static arrays for the result. We'll set zeros appropiately of course
        nkr_ASSERT_THAT(result.Capacity() >= number_a.Count() + number_b.Count());

        const count_t unit_count = number_a.Count();
        if (unit_count == 1) {
            // this section is why we require that the two operands be of the same number of digits,
            // else we need an arbitrary tradition multiplication function because one of the operands
            // may have a huge number of digits more than the other, and that can't be done as simply as this.
            // however, if we ever do implement that, we would be able to use word_t as units, however I doubt it
            // would be any more performant at that point than just using a half word with this quicker algorithm.
            const safe_multiply_t a_times_b = number_a[0] * number_b[0];
            result.Push(unit_t(
                a_times_b & std::numeric_limits<unit_t>::max()
            )).Ignore_Error();
            result.Push(unit_t(
                (a_times_b >> sizeof(unit_t) * 8) & std::numeric_limits<unit_t>::max()
            )).Ignore_Error();
        } else {
            const count_t low_unit_count = unit_count / 2;
            const count_t high_unit_count = unit_count - low_unit_count;
            const count_t double_unit_count = unit_count * 2;

            const auto a = number_a.Split(low_unit_count);
            const auto b = number_b.Split(low_unit_count);

            // something else we can do is allocate in one block all the allocations in this recursion and use static arrays
            // for the result. This would mean we need to preallocate the result size and fill it with zeros of course.
            // this can be extended to a function that calls this function and preallocates all necessary space before hand,
            // parceling out the static arrays as we go. essentially a special purpose memory pool that can't allocate anything
            // but the next spot in the array
            // essentially a stack

            // I think it's (total memory per recursion in this if bracket) * (total-digit-count / 2 - 1)
            // (4 * unit_count) * (top_unit_count / 2 - 1)
            // (4 * unit_count) * (top_unit_count / 2 - 1) * 2 ---- because of the third recursion
            // that way we don't have to worry about allocation failures except to assert that it shouldn't happen.
            // we can return very early if there is a memory pool allocation, before we even call this function

            // c1 = (a0 + a1) * (b0 + b1);
            auto& c1 = result;
            {
                // if we multiply the _plus_'s before calc'ing c0 and c2, we'll need less memory overall
                // because the plus memory will be released whereas the c0 and c2 must stay till the end.
                // this is useful even when we start to provide this function its own memory pool also.
                array::dynamic_t<unit_t> a0_plus_a1(unit_count);
                nkr_ASSERT_THAT(a0_plus_a1.Capacity() >= unit_count);
                Add<unit_t>(a[0], a[1], a0_plus_a1).Ignore_Error();

                array::dynamic_t<unit_t> b0_plus_b1(unit_count);
                nkr_ASSERT_THAT(b0_plus_b1.Capacity() >= unit_count);
                Add<unit_t>(b[0], b[1], b0_plus_b1).Ignore_Error();

                count_t padded_count = std::max(a0_plus_a1.Count(), b0_plus_b1.Count());
                array::high_pad_t<unit_t> a0_plus_a1_pad(a0_plus_a1, padded_count, unit_t(0));
                array::high_pad_t<unit_t> b0_plus_b1_pad(b0_plus_b1, padded_count, unit_t(0));

                // because we only need one more digit than half the unit count to get the result here,
                // it would be nice if we could point to the half unit count index of this double count sized array,
                // that way we don't actually have to shift later, which will save a lot of time for large arrays.
                // that would mean we should be passing an result array that already has all the units zeroed out,
                // which also is slow. better to write the zeros at the beginning of the array after getting result back,
                // but that would mean we couldn't reuse the buffer later below because it won't be big enough unless we increase
                // the require count from double_unit_count to double_unit_count + half_unit_count.
                // hence a trade off between memory and processing. better to save on memory in this case I think, so this is simpler.
                // wait. the end result here is always half_unit_count + 1. that means it can do the calc in that space, right?
                // that would mean we just have to make sure we don't go past the end in the next section.

                // we should be able to utiliize the same pointer with two dynamic array wrappers. need a new ctor for it.

                Private_Karatsuba_Multiply<unit_t>(a0_plus_a1_pad, b0_plus_b1_pad, c1);
                while (c1.Count() < double_unit_count) {
                    c1.Push(unit_t(0)).Ignore_Error();
                }
            }

            // c0 = a0 * b0;
            array::dynamic_t<unit_t> c0;
            if (a[0].Non_Extra_Unit_Count() > 0 && b[0].Non_Extra_Unit_Count() > 0) {
                c0.Capacity(low_unit_count * 2);
                nkr_ASSERT_THAT(c0.Capacity() >= low_unit_count * 2);
                Private_Karatsuba_Multiply<unit_t>(a[0], b[0], c0);
            } else {
                c0.Capacity(1);
                nkr_ASSERT_THAT(c0.Capacity() >= 1);
                c0.Push(unit_t(0)).Ignore_Error();
            }

            // c2 = a1 * b1;
            array::dynamic_t<unit_t> c2;
            if (a[1].Non_Extra_Unit_Count() > 0 && b[1].Non_Extra_Unit_Count() > 0) {
                c2.Capacity(high_unit_count * 2);
                nkr_ASSERT_THAT(c2.Capacity() >= high_unit_count * 2);
                Private_Karatsuba_Multiply<unit_t>(a[1], b[1], c2);
            } else {
                c2.Capacity(1);
                nkr_ASSERT_THAT(c2.Capacity() >= 1);
                c2.Push(unit_t(0)).Ignore_Error();
            }

            // c1 = c1 - c2 - c0;
            Subtract_In_Place<unit_t>(c1, c2);
            Subtract_In_Place<unit_t>(c1, c0);

            // b = std::numeric_limits<unit_t>::max() + 1; (a single 'digit' in our array)
            // m2 = low_unit_count;
            // result = (c2 x b ^ (m2 x 2)) + (c1 x b ^ m2) + c0;

            // result = c1 x b ^ m2;
            {
                // I want to avoid doing this by simply pointing to the low_unit_count index to start a write on the above multiply.
                for (index_t idx = double_unit_count - 1, end = low_unit_count; idx >= end; idx -= 1) {
                    c1[idx] = c1[idx - low_unit_count];
                }
                for (index_t idx = 0, end = low_unit_count; idx < end; idx += 1) {
                    c1[idx] = unit_t(0);
                }
            }

            // result += c0;
            Add_In_Place<unit_t>(c1, c0);

            // result += c2 x b ^ (m2 x 2);
            {
                bool_t do_carry = false;

                // might be nice to have an array:right_pad_static
                for (index_t c2_idx = 0, c1_idx = low_unit_count * 2, end = c2.Count(); c2_idx < end; c2_idx += 1, c1_idx += 1) {
                    if (do_carry) {
                        if ((c1[c1_idx] += 1) == 0) {
                            c1[c1_idx] = c2[c2_idx];
                        } else {
                            c1[c1_idx] += c2[c2_idx];
                            do_carry = c1[c1_idx] < c2[c2_idx];
                        }
                    } else {
                        c1[c1_idx] += c2[c2_idx];
                        do_carry = c1[c1_idx] < c2[c2_idx];
                    }
                }
            }
        }
    }

    template <integer_unsigned_tr unit_p>
    inline maybe_t<allocator_err>
        Karatsuba_Multiply(const tr2<any_tg, pointable_array_ttg, of_any_tg, unit_p> auto& number_a,
                           const tr2<any_tg, pointable_array_ttg, of_any_tg, unit_p> auto& number_b,
                           tr2<any_tg, aggregate_array_ttg, of_any_tg, unit_p> auto& result)
    {
        using unit_t = unit_p;
        using safe_multiply_t = word_t;

        static_assert(sizeof(unit_t) <= sizeof(safe_multiply_t) / 2);

        nkr_ASSERT_THAT(number_a.Count() > 0);
        nkr_ASSERT_THAT(number_b.Count() > 0);

        const count_t padded_count = std::max(number_a.Count(), number_b.Count());
        array::high_pad_t<const unit_t> number_a_pad(number_a, padded_count, unit_t(0));
        array::high_pad_t<const unit_t> number_b_pad(number_b, padded_count, unit_t(0));

        maybe_t<allocator_err> err = result.Capacity(number_a_pad.Count() + number_b_pad.Count());
        if (err) {
            return err;
        } else {
            result.Clear();

            if (padded_count > 1) {
                count_t capacity = padded_count;
                count_t counter = padded_count;
                if (math::Is_Odd(counter)) {
                    counter += 1;
                }
                while (counter > 2) {
                    counter = counter / 2 + 1;
                    capacity += counter;
                }
                capacity = capacity * 2 + 4;

                Private_Karatsuba_Multiply<unit_t>(number_a_pad, number_b_pad, result);
            } else {
                Private_Karatsuba_Multiply<unit_t>(number_a_pad, number_b_pad, result);
            }

            return allocator_err::NONE;
        }
    }

}}
