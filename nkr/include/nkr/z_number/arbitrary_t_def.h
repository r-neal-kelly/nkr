/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/z_math.h"

#include "nkr/z_array/dynamic_t.h"

#include "nkr/z_number/arbitrary_t.h"

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
            for (index_t idx = min_count, end = max_count; idx < end; idx += 1) {
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
            for (index_t idx = min_count, end = max_count; idx < end; idx += 1) {
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
    count_t
        Add(const tr2<any_tg, array_ttg, of_any_tg, unit_p> auto& number_a,
            const tr2<any_tg, array_ttg, of_any_tg, unit_p> auto& number_b,
            tr2<any_tg, non_aggregate_array_ttg, of_any_tg, unit_p> auto& result)
    {
        using unit_t = unit_p;

        nkr_ASSERT_THAT(number_a.Count() > 0);
        nkr_ASSERT_THAT(number_b.Count() > 0);

        const count_t number_a_count = number_a.Count();
        const count_t number_b_count = number_b.Count();
        const count_t min_count = std::min(number_a_count, number_b_count);
        const count_t max_count = std::max(number_a_count, number_b_count);

        nkr_ASSERT_THAT(result.Count() >= max_count + 1);

        bool_t do_carry = false;

        for (index_t idx = 0, end = min_count; idx < end; idx += 1) {
            const unit_t number_a_unit = number_a[idx];
            const unit_t number_b_unit = number_b[idx];
            if (do_carry) {
                if (unit_t(number_a_unit + 1) == 0) {
                    result[idx] = number_b_unit;
                } else {
                    const unit_t number_c_unit = number_a_unit + 1 + number_b_unit;
                    do_carry = number_c_unit < number_b_unit;
                    result[idx] = number_c_unit;
                }
            } else {
                const unit_t number_c_unit = number_a_unit + number_b_unit;
                do_carry = number_c_unit < number_b_unit;
                result[idx] = number_c_unit;
            }
        }

        if (number_a_count > number_b_count) {
            for (index_t idx = min_count, end = max_count; idx < end; idx += 1) {
                const unit_t number_a_unit = number_a[idx];
                if (do_carry) {
                    const unit_t number_c_unit = number_a_unit + 1;
                    do_carry = number_c_unit == 0;
                    result[idx] = number_c_unit;
                } else {
                    result[idx] = number_a_unit;
                }
            }
        } else if (number_b_count > number_a_count) {
            for (index_t idx = min_count, end = max_count; idx < end; idx += 1) {
                const unit_t number_b_unit = number_b[idx];
                if (do_carry) {
                    const unit_t number_c_unit = number_b_unit + 1;
                    do_carry = number_c_unit == 0;
                    result[idx] = number_c_unit;
                } else {
                    result[idx] = number_b_unit;
                }
            }
        }

        if (do_carry) {
            result[max_count] = 1;

            return max_count + 1;
        } else {
            for (index_t idx = max_count, end = 1; idx > end;) {
                idx -= 1;
                if (result[idx] != 0) {
                    return idx + 1;
                }
            }

            return 1;
        }
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
        Karatsuba_Multiply(const tr2<any_tg, array::high_pad_ttg, of_any_tg, unit_p> auto& number_a,
                           const tr2<any_tg, array::high_pad_ttg, of_any_tg, unit_p> auto& number_b,
                           tr2<any_non_const_tg, non_aggregate_array_ttg, of_any_non_const_tg, unit_p> auto& result,
                           tr2<any_non_const_tg, aggregate_array_ttg, of_any_non_const_tg, unit_p> auto& buffer)
    {
        using unit_t = unit_p;
        using safe_multiply_t = word_t;

        static_assert(sizeof(unit_t) <= sizeof(safe_multiply_t) / 2);

        nkr_ASSERT_THAT(number_a.Count() > 0);
        nkr_ASSERT_THAT(number_a.Count() == number_b.Count());

        const count_t unit_count = number_a.Count();
        if (unit_count == 1) {
            // this section is why we require that the two operands be of the same number of digits,
            // else we need an arbitrary tradition multiplication function because one of the operands
            // may have a huge number of digits more than the other, and that can't be done as simply as this.
            // however, if we ever do implement that, we would be able to use word_t as units, but I doubt it
            // would be any more performant than just using a half word with this quicker algorithm.
            const safe_multiply_t a_times_b = number_a[0] * number_b[0];
            if (a_times_b > std::numeric_limits<unit_t>::max()) {
                result.Count(2);
                result[0] = a_times_b & std::numeric_limits<unit_t>::max();
                result[1] = (a_times_b >> sizeof(unit_t) * 8) & std::numeric_limits<unit_t>::max();
            } else {
                result.Count(1);
                result[0] = unit_t(a_times_b);
            }
        } else {
            const count_t low_unit_count = unit_count / 2;
            const count_t high_unit_count = unit_count - low_unit_count;

            const auto a = number_a.Split(low_unit_count);
            const auto b = number_b.Split(low_unit_count);

            // c1 = (a0 + a1) * (b0 + b1)
            array::static_t<unit_t> c1(maybe_t<pointer_t<unit_t>>(&result[low_unit_count], result.Count() - low_unit_count));
            {
                // if we do this before getting c0 and c2, we'll need less memory overall
                // because this will be released whereas the c0 and c2 must stay till the end.
                // this is useful even when we start to provide this function its own memory pool also.
                nkr_ASSERT_THAT(buffer.Count() + unit_count * 2 <= buffer.Capacity());

                buffer.Count(buffer.Count() + unit_count).Ignore_Error();
                array::static_t<unit_t> a0_plus_a1(maybe_t<pointer_t<unit_t>>(&buffer[buffer.Count() - unit_count], unit_count));
                a0_plus_a1.Count(Add<unit_t>(a[0], a[1], a0_plus_a1));

                buffer.Count(buffer.Count() + unit_count).Ignore_Error();
                array::static_t<unit_t> b0_plus_b1(maybe_t<pointer_t<unit_t>>(&buffer[buffer.Count() - unit_count], unit_count));
                b0_plus_b1.Count(Add<unit_t>(b[0], b[1], b0_plus_b1));

                count_t padded_unit_count = std::max(a0_plus_a1.Count(), b0_plus_b1.Count());
                array::high_pad_t<unit_t> a0_plus_a1_pad(a0_plus_a1, padded_unit_count, unit_t(0));
                array::high_pad_t<unit_t> b0_plus_b1_pad(b0_plus_b1, padded_unit_count, unit_t(0));

                Karatsuba_Multiply<unit_t>(a0_plus_a1_pad, b0_plus_b1_pad, c1, buffer);

                buffer.Count(buffer.Count() - unit_count * 2).Ignore_Error();
            }

            nkr_ASSERT_THAT(buffer.Count() + unit_count * 2 <= buffer.Capacity());

            // c0 = a0 * b0
            const count_t c0_capacity = low_unit_count * 2;
            buffer.Count(buffer.Count() + c0_capacity).Ignore_Error();
            array::static_t<unit_t> c0(maybe_t<pointer_t<unit_t>>(&buffer[buffer.Count() - c0_capacity], c0_capacity));
            if (a[0].Non_Extra_Unit_Count() > 0 && b[0].Non_Extra_Unit_Count() > 0) {
                Karatsuba_Multiply<unit_t>(a[0], b[0], c0, buffer);
            } else {
                c0.Count(1);
                c0[0] = 0;
            }

            // c2 = a1 * b1
            const count_t c2_capacity = high_unit_count * 2;
            buffer.Count(buffer.Count() + c2_capacity).Ignore_Error();
            array::static_t<unit_t> c2(maybe_t<pointer_t<unit_t>>(&buffer[buffer.Count() - c2_capacity], c2_capacity));
            if (a[1].Non_Extra_Unit_Count() > 0 && b[1].Non_Extra_Unit_Count() > 0) {
                Karatsuba_Multiply<unit_t>(a[1], b[1], c2, buffer);
            } else {
                c2.Count(1);
                c2[0] = 0;
            }

            // c1 = c1 - c2 - c0
            Subtract_In_Place<unit_t>(c1, c2);
            Subtract_In_Place<unit_t>(c1, c0);

            // b = std::numeric_limits<unit_t>::max() + 1
            // m2 = low_unit_count
            // result = (c2 x b ^ (m2 x 2)) + (c1 x b ^ m2) + c0

            // result = c1 x b ^ m2
            result.Count(low_unit_count * 2 + c2.Count());
            for (index_t idx = 0, end = low_unit_count; idx < end; idx += 1) {
                result[idx] = 0;
            }
            for (index_t idx = low_unit_count + c1.Count(), end = result.Count(); idx < end; idx += 1) {
                result[idx] = 0;
            }

            // result += c0
            Add_In_Place<unit_t>(result, c0);

            // result += c2 x b ^ (m2 x 2)
            {
                bool_t do_carry = false;

                // we could create a static_t of the result at the right position then add in place
                for (index_t c2_idx = 0, result_idx = low_unit_count * 2, end = c2.Count(); c2_idx < end; c2_idx += 1, result_idx += 1) {
                    if (do_carry) {
                        if ((result[result_idx] += 1) == 0) {
                            result[result_idx] = c2[c2_idx];
                        } else {
                            result[result_idx] += c2[c2_idx];
                            do_carry = result[result_idx] < c2[c2_idx];
                        }
                    } else {
                        result[result_idx] += c2[c2_idx];
                        do_carry = result[result_idx] < c2[c2_idx];
                    }
                }
            }

            // this might only be necessary because we elide the mutliplication of high_pads sometimes, but I'm not sure
            count_t final_result_count = result.Count();
            for (index_t end = 0; final_result_count > end;) {
                final_result_count -= 1;
                if (result[final_result_count] != 0) {
                    break;
                }
            }
            result.Count(final_result_count + 1);

            buffer.Count(buffer.Count() - unit_count * 2).Ignore_Error();
        }
    }

    inline constexpr count_t
        Multiply_Buffer_Capacity(count_t number_unit_count)
    {
        if (number_unit_count > 1) {
            count_t capacity = number_unit_count;

            for (count_t counter = math::Is_Odd(number_unit_count) ? number_unit_count + 1 : number_unit_count; counter > 2; ) {
                counter = counter / 2 + 1;
                capacity += counter;
            }

            return capacity * 2 + 4;
        } else {
            return 0;
        }
    }

    template <integer_unsigned_tr unit_p>
    inline maybe_t<allocator_err>
        Multiply(const tr2<any_tg, pointable_array_ttg, of_any_tg, unit_p> auto& number_a,
                 const tr2<any_tg, pointable_array_ttg, of_any_tg, unit_p> auto& number_b,
                 tr2<any_tg, aggregate_array_ttg, of_any_tg, unit_p> auto& result,
                 tr2<any_non_const_tg, aggregate_array_ttg, of_any_non_const_tg, unit_p> auto& buffer)
    {
        using unit_t = unit_p;
        using qualified_unit_a_t = std::remove_reference_t<decltype(number_a[0])>;
        using qualified_unit_b_t = std::remove_reference_t<decltype(number_b[0])>;
        using safe_multiply_t = word_t;

        static_assert(sizeof(unit_t) <= sizeof(safe_multiply_t) / 2);

        nkr_ASSERT_THAT(number_a.Count() > 0);
        nkr_ASSERT_THAT(number_b.Count() > 0);

        // for these high_pad arrays, we'll need to make sure we get the fully qualified accessed unit_t of the numbers.
        // we're already covering const, but they may be volatile as well.
        const count_t padded_count = std::max(number_a.Count(), number_b.Count());
        array::high_pad_t<qualified_unit_a_t> number_a_pad(number_a, padded_count, qualified_unit_a_t(0));
        array::high_pad_t<qualified_unit_b_t> number_b_pad(number_b, padded_count, qualified_unit_b_t(0));

        maybe_t<allocator_err> err = result.Count(padded_count * 2);
        if (err) {
            return err;
        } else {
            maybe_t<allocator_err> err = buffer.Reserve(Multiply_Buffer_Capacity(padded_count));
            if (err) {
                return err;
            } else {
                array::static_t<unit_t> static_result(maybe_t<pointer_t<unit_t>>(&result[0], result.Count()));
                buffer.Count(0).Ignore_Error();
                Karatsuba_Multiply<unit_t>(number_a_pad, number_b_pad, static_result, buffer);
                nkr_ASSERT_THAT(static_result.Count() <= result.Count());
                result.Count(static_result.Count()).Ignore_Error();

                // we could do the same thing here that we do in Subtract, where we discount the high_pad zeros.

                return allocator_err::NONE;
            }
        }
    }

}}
