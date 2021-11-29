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

#include "nkr/charcoder/ascii_t.h" // for testing
#include "nkr/string/dynamic_t.h" // for testing

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
        Add(tr2<any_non_const_tg, aggregate_array_ttg, of_any_non_const_tg, unit_p> auto& number_a,
            const tr2<any_tg, array_ttg, of_any_tg, unit_p> auto& number_b)
    {
        using unit_t = unit_p;

        const count_t a_digit_count = number_a.Count();
        const count_t b_digit_count = number_b.Count();
        const count_t min_digit_count = std::min(a_digit_count, b_digit_count);

        bool_t do_carry = false;

        for (index_t idx = 0, end = min_digit_count; idx < end; idx += 1) {
            if (do_carry) {
                if ((number_a[idx] += 1) != 0) {
                    number_a[idx] += number_b[idx];
                    do_carry = number_a[idx] < number_b[idx];
                }
            } else {
                number_a[idx] += number_b[idx];
                do_carry = number_a[idx] < number_b[idx];
            }
        }

        if (a_digit_count > b_digit_count) {
            for (index_t idx = min_digit_count, end = a_digit_count; idx < end && do_carry; idx += 1) {
                do_carry = (number_a[idx] += 1) == 0;
            }
        }

        if (do_carry) {
            maybe_t<allocator_err> err = number_a.Push(unit_t(1));
            if (err) {
                // we could check to see if there is more capacity than count before operating to preserve the state of the data
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
        Left_Shift(tr2<any_non_const_tg, aggregate_array_ttg, of_any_non_const_tg, unit_p> auto& number_a,
                   count_t bit_count)
    {
        using unit_t = unit_p;

        constexpr count_t unit_bit_count = sizeof(unit_t) * 8;

        if (bit_count <= unit_bit_count) {
            unit_t previous_bits = 0;
            unit_t next_bits = 0;
            for (index_t idx = 0, end = number_a.Count(); idx < end; idx += 1) {
                next_bits = number_a[idx] >> (unit_bit_count - bit_count);
                number_a[idx] = (number_a[idx] << bit_count) | previous_bits;
                previous_bits = next_bits;
            }

            maybe_t<allocator_err> err = number_a.Push(next_bits);
            if (err) {
                // we could check to see if there is more capacity than count before operating to preserve the state of the data
                return err;
            }
        } else {
            nkr_ASSERT_THAT(false);
            // not yet implemented
        }

        return allocator_err::NONE;
    }

    template <integer_unsigned_tr unit_p>
    void_t
        Karatsuba_Multiply(tr2<any_tg, array::static_t, of_any_tg, unit_p> auto number_a,
                           tr2<any_tg, array::static_t, of_any_tg, unit_p> auto number_b,
                           tr2<any_tg, aggregate_array_ttg, of_any_tg, unit_p> auto& result,
                           string::dynamic_t<charcoder::ascii_t> tabs = "")
    {
        using unit_t = unit_p;
        using safe_multiply_t = word_t;

        static_assert(sizeof(unit_t) <= sizeof(safe_multiply_t) / 2);

        // we treat the numbers just like any built-in integer
        nkr_ASSERT_THAT(number_a.Count() > 0);
        nkr_ASSERT_THAT(number_a.Count() % 2 == 0 || number_a.Count() == 1);
        nkr_ASSERT_THAT(number_a.Count() == number_b.Count());
        nkr_ASSERT_THAT(result.Count() == 0);
        nkr_ASSERT_THAT(result.Capacity() >= number_a.Count() + number_b.Count());

string::dynamic_t<charcoder::ascii_t> tabs_a = tabs;// temp
tabs_a.Push("    ").Ignore_Error();// temp

        const count_t number_count = number_a.Count();
        if (number_count == 1) {
            const safe_multiply_t a_times_b = number_a[0] * number_b[0];
            result.Push(unit_t(
                a_times_b & std::numeric_limits<unit_t>::max()
            )).Ignore_Error();
            result.Push(unit_t(
                (a_times_b >> sizeof(unit_t) * 8) & std::numeric_limits<unit_t>::max()
            )).Ignore_Error();
        } else {

//printf("%sa:\n", tabs.C_String()());
//for (index_t idx = 0, end = number_a.Count(); idx < end; idx += 1) {
//    printf("%s    a idx: %zu, val: 0x%2.2X\n", tabs.C_String()(), idx, number_a[idx]);
//}
//printf("%sb:\n", tabs.C_String()());
//for (index_t idx = 0, end = number_b.Count(); idx < end; idx += 1) {
//    printf("%s    b idx: %zu, val: 0x%2.2X\n", tabs.C_String()(), idx, number_b[idx]);
//}
//printf("\n");

            const count_t half_number_count = number_count / 2;
            const count_t double_number_count = number_count * 2;

            array::static_t<unit_t> a0(maybe_t<pointer_t<unit_t>>(&number_a[0], half_number_count));
            array::static_t<unit_t> a1(maybe_t<pointer_t<unit_t>>(&number_a[half_number_count], half_number_count));

            array::static_t<unit_t> b0(maybe_t<pointer_t<unit_t>>(&number_b[0], half_number_count));
            array::static_t<unit_t> b1(maybe_t<pointer_t<unit_t>>(&number_b[half_number_count], half_number_count));

//printf("%sdoing c0 = a0 * b0\n", tabs.C_String()()); //
            array::dynamic_t<unit_t> c0(number_count); // return on failure.
            Karatsuba_Multiply<unit_t>(a0, b0, c0, tabs_a);
//printf("%sgot c0:\n", tabs.C_String()());
//for (index_t idx = 0, end = c0.Count(); idx < end; idx += 1) {
//    printf("%s    c0 idx: %zu, val: 0x%2.2X\n", tabs.C_String()(), idx, c0[idx]);
//}
//printf("\n");

//printf("%sdoing c2 = a1 * b1\n", tabs.C_String()()); //
            array::dynamic_t<unit_t> c2(number_count); // return on failure.
            Karatsuba_Multiply<unit_t>(a1, b1, c2, tabs_a);
//printf("%sgot c2:\n", tabs.C_String()());
//for (index_t idx = 0, end = c2.Count(); idx < end; idx += 1) {
//    printf("%s    c2 idx: %zu, val: 0x%2.2X\n", tabs.C_String()(), idx, c2[idx]);
//}
//printf("\n");

//printf("%sdoing c1 = (a0 + a1) * (b0 + b1) - c2 - c1\n", tabs.C_String()()); //
            // we should be able to use the result buffer as the the c1 buffer
            array::dynamic_t<unit_t> c1(double_number_count); // return on failure.
            {
printf("%sdoing a0 + a1\n", tabs.C_String()());
                array::dynamic_t<unit_t> a0_plus_a1(number_count); // return on failure.
                Add<unit_t>(a0, a1, a0_plus_a1).Ignore_Error();
printf("%sgot a0 + a1:\n", tabs.C_String()());
for (index_t idx = 0, end = a0_plus_a1.Count(); idx < end; idx += 1) {
    printf("%s    idx: %zu, val: 0x%2.2X\n", tabs.C_String()(), idx, a0_plus_a1[idx]);
}

printf("%sdoing b0 + b1\n", tabs.C_String()());
                array::dynamic_t<unit_t> b0_plus_b1(number_count); // return on failure.
                Add<unit_t>(b0, b1, b0_plus_b1).Ignore_Error();
printf("%sgot b0 + b1:\n", tabs.C_String()());
for (index_t idx = 0, end = b0_plus_b1.Count(); idx < end; idx += 1) {
    printf("%s    idx: %zu, val: 0x%2.2X\n", tabs.C_String()(), idx, b0_plus_b1[idx]);
}

//printf("%sdoing (a0 + a1) * (b0 + b1)\n", tabs.C_String()());
                Karatsuba_Multiply<unit_t>(array::static_t<unit_t>(a0_plus_a1), array::static_t<unit_t>(b0_plus_b1), c1, tabs_a);
//printf("%sgot (a0 + a1) * (b0 + b1):\n", tabs.C_String()());
//for (index_t idx = 0, end = c1.Count(); idx < end; idx += 1) {
//    printf("%s    idx: %zu, val: 0x%2.2X\n", tabs.C_String()(), idx, c1[idx]);
//}
            }
            {
                array::dynamic_t<unit_t> c1_buffer(double_number_count); // return on failure.
                Subtract<unit_t>(array::static_t<unit_t>(c1), array::static_t<unit_t>(c2), c1_buffer).Ignore_Error();
                Subtract<unit_t>(array::static_t<unit_t>(c1_buffer), array::static_t<unit_t>(c0), c1).Ignore_Error();
                while (c1.Count() < double_number_count) {
                    c1.Push(unit_t(0)).Ignore_Error();
                }
            }
//printf("%sgot c1:\n", tabs.C_String()());
//for (index_t idx = 0, end = c1.Count(); idx < end; idx += 1) {
//    printf("%s    idx: %zu, val: 0x%2.2X\n", tabs.C_String()(), idx, c1[idx]);
//}
//printf("\n");

            for (index_t idx = 0, end = number_count; idx < end; idx += 1) {
                result.Push(c0[idx]).Ignore_Error();
            }
            for (index_t idx = number_count, end = double_number_count; idx < end; idx += 1) {
                result.Push(unit_t(0)).Ignore_Error();
            }

/*printf("before adding:\n");
for (index_t idx = 0, end = result.Count(); idx < end; idx += 1) {
    printf("result idx: %zu, val: 0x%2.2X\n", idx, result[idx]);
}*/

            bool_t do_carry = false;

            for (index_t idx = 0, result_idx = half_number_count, end = double_number_count - half_number_count;
                 idx < end;
                 idx += 1, result_idx += 1) {
                if (do_carry) {
                    if ((result[result_idx] += 1) != 0) {
                        result[result_idx] += c1[idx];
                        do_carry = result[result_idx] < c1[idx];
                    }
                } else {
                    result[result_idx] += c1[idx];
                    do_carry = result[result_idx] < c1[idx];
                }

/*printf("after adding c1 %zu:\n", idx);
for (index_t idx = 0, end = result.Count(); idx < end; idx += 1) {
    printf("result idx: %zu, val: 0x%2.2X\n", idx, result[idx]);
}*/
            }

            do_carry = false;

            for (index_t idx = 0, result_idx = number_count, end = number_count;
                 idx < end;
                 idx += 1, result_idx += 1) {
                if (do_carry) {
                    if ((result[result_idx] += 1) != 0) {
                        result[result_idx] += c2[idx];
                        do_carry = result[result_idx] < c2[idx];
                    }
                } else {
                    result[result_idx] += c2[idx];
                    do_carry = result[result_idx] < c2[idx];
                }

/*printf("after adding c2 %zu:\n", idx);
for (index_t idx = 0, end = result.Count(); idx < end; idx += 1) {
    printf("result idx: %zu, val: 0x%2.2X\n", idx, result[idx]);
}*/
            }

printf("%s---------------\n", tabs.C_String()());
printf("%sstarts at idx: %zu\n", tabs.C_String()(), word_t(0));
for (index_t idx = 0, end = c0.Count(); idx < end; idx += 1) {
    printf("%sc0 idx: %zu, result idx: %zu, val: 0x%2.2X\n", tabs.C_String()(), idx, idx, c0[idx]);
}
printf("\n");
printf("%sstarts at idx: %zu\n", tabs.C_String()(), half_number_count);
for (index_t idx = 0, end = c1.Count(); idx < end; idx += 1) {
    printf("%sc1 idx: %zu, result idx: %zu, val: 0x%2.2X\n", tabs.C_String()(), idx, idx + half_number_count, c1[idx]);
}
printf("\n");
printf("%sstarts at idx: %zu\n", tabs.C_String()(), number_count);
for (index_t idx = 0, end = c2.Count(); idx < end; idx += 1) {
    printf("%sc2 idx: %zu, result idx: %zu, val: 0x%2.2X\n", tabs.C_String()(), idx, idx + number_count, c2[idx]);
}
printf("\n");
for (index_t idx = 0, end = result.Count(); idx < end; idx += 1) {
    printf("%sresult idx: %zu, val: 0x%2.2X\n", tabs.C_String()(), idx, result[idx]);
}
printf("%s---------------\n", tabs.C_String()());
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
