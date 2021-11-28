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
    void_t
        Karatsuba_Multiply(tr2<any_tg, array::static_t, of_any_tg, unit_p> auto number_a,
                           tr2<any_tg, array::static_t, of_any_tg, unit_p> auto number_b,
                           tr2<any_tg, aggregate_array_ttg, of_any_tg, unit_p> auto& result)
    {
        using unit_t = unit_p;

        constexpr count_t half_bit_count = sizeof(unit_t) * 4;
        constexpr unit_t right_bit_mask = std::numeric_limits<unit_t>::max() >> half_bit_count;
        constexpr unit_t left_bit_mask = std::numeric_limits<unit_t>::max() << half_bit_count;

        // we treat the numbers just like any built-in integer
        nkr_ASSERT_THAT(number_a.Count() > 0);
        nkr_ASSERT_THAT(number_a.Count() % 2 == 0 || number_a.Count() == 1);
        nkr_ASSERT_THAT(number_a.Count() == number_b.Count());
        nkr_ASSERT_THAT(result.Capacity() >= number_a.Count() + number_b.Count());

        const count_t number_count = number_a.Count();
        if (number_count == 1) {
            const unit_t a = number_a[0];
            const unit_t a0 = a & right_bit_mask;
            const unit_t a1 = a >> half_bit_count;

            const unit_t b = number_b[0];
            const unit_t b0 = b & right_bit_mask;
            const unit_t b1 = b >> half_bit_count;

            const unit_t c0 = a0 * b0;
            const unit_t c2 = a1 * b1;
            const unit_t c1 = (a0 + a1) * (b0 + b1) - c2 - c0;

            result.Push(unit_t(
                (((c1 & right_bit_mask) << half_bit_count) + (c0 & left_bit_mask)) | (c0 & right_bit_mask)
            )).Ignore_Error();
            result.Push(unit_t(
                (c2 & left_bit_mask) | (((c2 & right_bit_mask) << half_bit_count) + (c1 & left_bit_mask))
            )).Ignore_Error();
        } else {
            const count_t half_number_count = number_count / 2;

            array::static_t<unit_t> a0(maybe_t<pointer_t<unit_t>>(&number_a[0], half_number_count));
            array::static_t<unit_t> a1(maybe_t<pointer_t<unit_t>>(&number_a[half_number_count], half_number_count));

            array::static_t<unit_t> b0(maybe_t<pointer_t<unit_t>>(&number_b[0], half_number_count));
            array::static_t<unit_t> b1(maybe_t<pointer_t<unit_t>>(&number_b[half_number_count], half_number_count));

            array::dynamic_t<unit_t> c0(number_count); // return on failure.
            Karatsuba_Multiply<unit_t>(a0, b0, c0);

            array::dynamic_t<unit_t> c2(number_count); // return on failure.
            Karatsuba_Multiply<unit_t>(a1, b1, c2);

            array::dynamic_t<unit_t> c1(number_count * 2); // return on failure.
            {
                array::dynamic_t<unit_t> a0_plus_a1(number_count); // return on failure.
                Add<unit_t>(a0, a1, a0_plus_a1).Ignore_Error();
                array::dynamic_t<unit_t> b0_plus_b1(number_count); // return on failure.
                Add<unit_t>(b0, b1, b0_plus_b1).Ignore_Error();
                Karatsuba_Multiply<unit_t>(array::static_t<unit_t>(a0_plus_a1), array::static_t<unit_t>(b0_plus_b1), c1);
            }
            {
                array::dynamic_t<unit_t> c1_buffer(number_count * 2); // return on failure.
                Subtract<unit_t>(array::static_t<unit_t>(c1), array::static_t<unit_t>(c2), c1_buffer).Ignore_Error();
                Subtract<unit_t>(array::static_t<unit_t>(c1_buffer), array::static_t<unit_t>(c0), c1).Ignore_Error();
                while (c1.Count() < number_count * 2) {
                    c1.Push(unit_t(0)).Ignore_Error();
                }
            }

            for (index_t idx = 0, end = c0.Count(); idx < end; idx += 1) {
                result.Push(c0[idx]).Ignore_Error();
            }
            for (index_t idx = 0, end = c1.Count(); idx < end; idx += 1) {
                result.Push(c1[idx]).Ignore_Error();
            }
            for (index_t idx = 0, end = c2.Count(); idx < end; idx += 1) {
                result.Push(c2[idx]).Ignore_Error();
            }
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
