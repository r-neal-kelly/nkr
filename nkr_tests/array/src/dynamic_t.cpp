/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/allocator_heap_t.h"
#include "nkr/allocator_heap_zeros_t.h"
#include "nkr/array_dynamic_t.h"
#include "nkr/intrinsics.h"
#include "nkr/random.h"

#include "doctest.h"

namespace nkr {

    TEST_SUITE("array_dynamic_t<unit_p, allocator_p, grow_rate_p>")
    {
    #define nkr_ALL_PARAMS(QUALIFIER_p, UNIT_p, ALLOCATOR_p, GROW_RATE_p)                                   \
        QUALIFIER_p array_dynamic_t<UNIT_p, ALLOCATOR_p<UNIT_p>, GROW_RATE_p>,                              \
        QUALIFIER_p array_dynamic_t<const UNIT_p, ALLOCATOR_p<const UNIT_p>, GROW_RATE_p>,                  \
        QUALIFIER_p array_dynamic_t<volatile UNIT_p, ALLOCATOR_p<volatile UNIT_p>, GROW_RATE_p>,            \
        QUALIFIER_p array_dynamic_t<volatile const UNIT_p, ALLOCATOR_p<volatile const UNIT_p>, GROW_RATE_p>

    #define nkr_GROW_RATES(QUALIFIER_p, UNIT_p, ALLOCATOR_p)                                    \
        nkr_ALL_PARAMS(QUALIFIER_p, UNIT_p, ALLOCATOR_p, math::fraction_t<17 nkr_COMMA 10>),    \
        nkr_ALL_PARAMS(QUALIFIER_p, UNIT_p, ALLOCATOR_p, math::fraction_t<2 nkr_COMMA 1>)

    #define nkr_ALLOCATORS(QUALIFIER_p, UNIT_p)                         \
        nkr_GROW_RATES(QUALIFIER_p, UNIT_p, allocator::heap_t),         \
        nkr_GROW_RATES(QUALIFIER_p, UNIT_p, allocator::heap_zeros_t)

    #define nkr_UNITS(QUALIFIER_p)                  \
        nkr_ALLOCATORS(QUALIFIER_p, std_bool_t),    \
        nkr_ALLOCATORS(QUALIFIER_p, bool_t)

    #define nkr_REGULAR         \
        nkr_UNITS(nkr_BLANK)

    #define nkr_NON_CONST       \
        nkr_UNITS(nkr_BLANK),   \
        nkr_UNITS(volatile)

    #define nkr_CONST               \
        nkr_UNITS(const),           \
        nkr_UNITS(volatile const)

    #define nkr_ALL     \
        nkr_NON_CONST,  \
        nkr_CONST

        TEST_SUITE("aliases")
        {
            TEST_SUITE("unit_t")
            {
                TEST_CASE_TEMPLATE("should have a unit_t", array_dynamic_p, nkr_ALL)
                {
                    using unit_t = array_dynamic_p::unit_t;
                    using pointer_t = array_dynamic_p::pointer_t;
                    using allocator_t = array_dynamic_p::allocator_t;
                    using grow_rate_t = array_dynamic_p::grow_rate_t;

                    static_assert(std::same_as<unit_t, unit_t>);
                }
            }

            TEST_SUITE("pointer_t")
            {
                TEST_CASE_TEMPLATE("should have a pointer_t with the same unit_t", array_dynamic_p, nkr_ALL)
                {
                    using unit_t = array_dynamic_p::unit_t;
                    using pointer_t = array_dynamic_p::pointer_t;
                    using allocator_t = array_dynamic_p::allocator_t;
                    using grow_rate_t = array_dynamic_p::grow_rate_t;

                    static_assert(std::same_as<pointer_t::unit_t, unit_t>);
                }
            }

            TEST_SUITE("allocator_t")
            {
                TEST_CASE_TEMPLATE("should have an allocator_t with the same unit_t", array_dynamic_p, nkr_ALL)
                {
                    using unit_t = array_dynamic_p::unit_t;
                    using pointer_t = array_dynamic_p::pointer_t;
                    using allocator_t = array_dynamic_p::allocator_t;
                    using grow_rate_t = array_dynamic_p::grow_rate_t;

                    static_assert(std::same_as<allocator_t::unit_t, unit_t>);
                }
            }

            TEST_SUITE("grow_rate_t")
            {
                TEST_CASE_TEMPLATE("should have a grow_rate_t", array_dynamic_p, nkr_ALL)
                {
                    using unit_t = array_dynamic_p::unit_t;
                    using pointer_t = array_dynamic_p::pointer_t;
                    using allocator_t = array_dynamic_p::allocator_t;
                    using grow_rate_t = array_dynamic_p::grow_rate_t;

                    static_assert(std::same_as<grow_rate_t, grow_rate_t>);
                }
            }
        }

        TEST_SUITE("static functions")
        {
            TEST_SUITE("Grow_Rate()")
            {
                TEST_CASE_TEMPLATE("should equate grow_rate_t::To_Decimal()", array_dynamic_p, nkr_ALL)
                {
                    using unit_t = array_dynamic_p::unit_t;
                    using pointer_t = array_dynamic_p::pointer_t;
                    using allocator_t = array_dynamic_p::allocator_t;
                    using grow_rate_t = array_dynamic_p::grow_rate_t;

                    CHECK(array_dynamic_p::Grow_Rate() == grow_rate_t::To_Decimal());
                }
            }
        }

        TEST_SUITE("objects")
        {
            TEST_SUITE("default_ctor()")
            {
                TEST_CASE_TEMPLATE("should have a default pointer", array_dynamic_p, nkr_ALL)
                {
                    using unit_t = array_dynamic_p::unit_t;
                    using pointer_t = array_dynamic_p::pointer_t;
                    using allocator_t = array_dynamic_p::allocator_t;
                    using grow_rate_t = array_dynamic_p::grow_rate_t;

                    array_dynamic_p array_dynamic;
                    CHECK(array_dynamic.Pointer() == pointer_t());
                }

                TEST_CASE_TEMPLATE("should have a count of 0", array_dynamic_p, nkr_ALL)
                {
                    using unit_t = array_dynamic_p::unit_t;
                    using pointer_t = array_dynamic_p::pointer_t;
                    using allocator_t = array_dynamic_p::allocator_t;
                    using grow_rate_t = array_dynamic_p::grow_rate_t;

                    array_dynamic_p array_dynamic;
                    CHECK(array_dynamic.Count() == 0);
                }
            }

            TEST_SUITE("copy_ctor()")
            {
                TEST_CASE_TEMPLATE("should explicitly copy each unit and the count of other", array_dynamic_p, nkr_ALL)
                {
                    using unit_t = array_dynamic_p::unit_t;
                    using pointer_t = array_dynamic_p::pointer_t;
                    using allocator_t = array_dynamic_p::allocator_t;
                    using grow_rate_t = array_dynamic_p::grow_rate_t;

                    count_t count = Random<count_t>(1, 16);
                    std::remove_const_t<array_dynamic_p> other;
                    for (index_t idx = 0, end = count; idx < end; idx += 1) {
                        other.Push(Random<std::remove_const_t<unit_t>>());
                    }
                    array_dynamic_p array_dynamic(other);
                    CHECK(array_dynamic.Count() == count);
                    for (index_t idx = 0, end = count; idx < end; idx += 1) {
                        CHECK(array_dynamic[idx] == other[idx]);
                    }
                }

                TEST_CASE_TEMPLATE("should implicitly copy each unit and the count of other", array_dynamic_p, nkr_ALL)
                {
                    using unit_t = array_dynamic_p::unit_t;
                    using pointer_t = array_dynamic_p::pointer_t;
                    using allocator_t = array_dynamic_p::allocator_t;
                    using grow_rate_t = array_dynamic_p::grow_rate_t;

                    count_t count = Random<count_t>(1, 16);
                    std::remove_const_t<array_dynamic_p> other;
                    for (index_t idx = 0, end = count; idx < end; idx += 1) {
                        other.Push(Random<std::remove_const_t<unit_t>>());
                    }
                    array_dynamic_p array_dynamic = other;
                    CHECK(array_dynamic.Count() == count);
                    for (index_t idx = 0, end = count; idx < end; idx += 1) {
                        CHECK(array_dynamic[idx] == other[idx]);
                    }
                }

                TEST_CASE_TEMPLATE("should not change the other", array_dynamic_p, nkr_ALL)
                {
                    using unit_t = array_dynamic_p::unit_t;
                    using pointer_t = array_dynamic_p::pointer_t;
                    using allocator_t = array_dynamic_p::allocator_t;
                    using grow_rate_t = array_dynamic_p::grow_rate_t;

                    count_t count = Random<count_t>(1, 16);
                    std::remove_const_t<array_dynamic_p> other;
                    for (index_t idx = 0, end = count; idx < end; idx += 1) {
                        other.Push(Random<std::remove_const_t<unit_t>>());
                    }
                    pointer_t pointer = other.Pointer();
                    array_dynamic_p array_dynamic(other);
                    CHECK(other.Pointer() == pointer);
                    CHECK(other.Count() == count);
                }

                TEST_CASE_TEMPLATE("should have a different pointer", array_dynamic_p, nkr_ALL)
                {
                    using unit_t = array_dynamic_p::unit_t;
                    using pointer_t = array_dynamic_p::pointer_t;
                    using allocator_t = array_dynamic_p::allocator_t;
                    using grow_rate_t = array_dynamic_p::grow_rate_t;

                    count_t count = Random<count_t>(1, 16);
                    std::remove_const_t<array_dynamic_p> other;
                    for (index_t idx = 0, end = count; idx < end; idx += 1) {
                        other.Push(Random<std::remove_const_t<unit_t>>());
                    }
                    pointer_t pointer = other.Pointer();
                    array_dynamic_p array_dynamic(other);
                    CHECK(array_dynamic.Pointer() != pointer);
                }
            }

            TEST_SUITE("move_ctor()")
            {
                TEST_CASE_TEMPLATE("should explicitly move the pointer and count of other", array_dynamic_p, nkr_ALL)
                {
                    using unit_t = array_dynamic_p::unit_t;
                    using pointer_t = array_dynamic_p::pointer_t;
                    using allocator_t = array_dynamic_p::allocator_t;
                    using grow_rate_t = array_dynamic_p::grow_rate_t;

                    count_t count = Random<count_t>(1, 16);
                    std::remove_const_t<array_dynamic_p> other;
                    for (index_t idx = 0, end = count; idx < end; idx += 1) {
                        other.Push(Random<std::remove_const_t<unit_t>>());
                    }
                    pointer_t pointer = other.Pointer();
                    array_dynamic_p array_dynamic(std::move(other));
                    CHECK(array_dynamic.Pointer() == pointer);
                    CHECK(array_dynamic.Count() == count);
                }

                TEST_CASE_TEMPLATE("should implicitly move the count of other", array_dynamic_p, nkr_ALL)
                {
                    using unit_t = array_dynamic_p::unit_t;
                    using pointer_t = array_dynamic_p::pointer_t;
                    using allocator_t = array_dynamic_p::allocator_t;
                    using grow_rate_t = array_dynamic_p::grow_rate_t;

                    count_t count = Random<count_t>(1, 16);
                    std::remove_const_t<array_dynamic_p> other;
                    for (index_t idx = 0, end = count; idx < end; idx += 1) {
                        other.Push(Random<std::remove_const_t<unit_t>>());
                    }
                    pointer_t pointer = other.Pointer();
                    array_dynamic_p array_dynamic = std::move(other);
                    CHECK(array_dynamic.Pointer() == pointer);
                    CHECK(array_dynamic.Count() == count);
                }

                TEST_CASE_TEMPLATE("should set the other to default values", array_dynamic_p, nkr_ALL)
                {
                    using unit_t = array_dynamic_p::unit_t;
                    using pointer_t = array_dynamic_p::pointer_t;
                    using allocator_t = array_dynamic_p::allocator_t;
                    using grow_rate_t = array_dynamic_p::grow_rate_t;

                    count_t count = Random<count_t>(1, 16);
                    std::remove_const_t<array_dynamic_p> other;
                    for (index_t idx = 0, end = count; idx < end; idx += 1) {
                        other.Push(Random<std::remove_const_t<unit_t>>());
                    }
                    array_dynamic_p array_dynamic(std::move(other));
                    CHECK(other.Pointer() == pointer_t());
                    CHECK(other.Count() == 0);
                }
            }
        }

        TEST_SUITE("methods")
        {

        }

        TEST_SUITE("operators")
        {

        }
    }

    TEST_CASE("temp")
    {
        array_dynamic_t<int, allocator::heap_t<int>, math::fraction_t<17, 10>> array_dynamic;
        CHECK(array_dynamic.Grow_Rate() == static_cast<real_t>(1.7));
        CHECK(array_dynamic.Capacity(16));
        array_dynamic.Push(8);
        array_dynamic.Push(16);
        array_dynamic.Push(32);
        array_dynamic.Push(64);
        CHECK(array_dynamic.At(0) == 8);
        CHECK(array_dynamic.At(1) == 16);
        CHECK(array_dynamic.At(2) == 32);
        CHECK(array_dynamic.At(3) == 64);
        while (array_dynamic.Count() > 0) {
            array_dynamic.Pop();
        }
        array_dynamic.Fit();
        CHECK(array_dynamic.Capacity() == 0);
        CHECK(array_dynamic.Pointer() == nullptr);

        r64_t our_time = os::time::Test_In_Microseconds(
            16,
            []()
            {
                array_dynamic_t<index_t, allocator::heap_t<index_t>, math::fraction_t<17, 10>> array_dynamic;
                for (index_t idx = 0, end = 1024; idx < end; idx += 1) {
                    array_dynamic.Push(idx);
                }
            }
        );
        r64_t cpp_time = os::time::Test_In_Microseconds(
            16,
            []()
            {
                std::vector<index_t> vector;
                for (index_t idx = 0, end = 1024; idx < end; idx += 1) {
                    vector.push_back(idx);
                }
            }
        );
        printf("our_time: %g\n", our_time);
        printf("cpp_time: %g\n", cpp_time);
    }

}
