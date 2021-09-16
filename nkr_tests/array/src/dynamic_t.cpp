/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/allocator_heap_t.h"
#include "nkr/allocator_heap_zeros_t.h"
#include "nkr/dynamic_array_t.h"
#include "nkr/intrinsics.h"
#include "nkr/random.h"

#include "doctest.h"

namespace nkr {

    TEST_SUITE("dynamic_array_t<unit_p, allocator_p, grow_rate_p>")
    {
    #define nkr_ALL_PARAMS(QUALIFIER_p, UNIT_p, ALLOCATOR_p, GROW_RATE_p)                                   \
        QUALIFIER_p dynamic_array_t<UNIT_p, ALLOCATOR_p<UNIT_p>, GROW_RATE_p>,                              \
        QUALIFIER_p dynamic_array_t<const UNIT_p, ALLOCATOR_p<const UNIT_p>, GROW_RATE_p>,                  \
        QUALIFIER_p dynamic_array_t<volatile UNIT_p, ALLOCATOR_p<volatile UNIT_p>, GROW_RATE_p>,            \
        QUALIFIER_p dynamic_array_t<volatile const UNIT_p, ALLOCATOR_p<volatile const UNIT_p>, GROW_RATE_p>

    #define nkr_GROW_RATES(QUALIFIER_p, UNIT_p, ALLOCATOR_p)                                    \
        nkr_ALL_PARAMS(QUALIFIER_p, UNIT_p, ALLOCATOR_p, math::fraction_t<1 nkr_COMMA 1>),      \
        nkr_ALL_PARAMS(QUALIFIER_p, UNIT_p, ALLOCATOR_p, math::fraction_t<17 nkr_COMMA 10>),    \
        nkr_ALL_PARAMS(QUALIFIER_p, UNIT_p, ALLOCATOR_p, math::fraction_t<2 nkr_COMMA 1>)

    #define nkr_ALLOCATORS(QUALIFIER_p, UNIT_p)                         \
        nkr_GROW_RATES(QUALIFIER_p, UNIT_p, allocator::heap_t),         \
        nkr_GROW_RATES(QUALIFIER_p, UNIT_p, allocator::heap_zeros_t)

    #define nkr_UNITS(QUALIFIER_p)                  \
        nkr_ALLOCATORS(QUALIFIER_p, std_bool_t),    \
        nkr_ALLOCATORS(QUALIFIER_p, bool_t),        \
        nkr_ALLOCATORS(QUALIFIER_p, void_t*)

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
                TEST_CASE_TEMPLATE("should have a unit_t", dynamic_array_p, nkr_ALL)
                {
                    using unit_t = dynamic_array_p::unit_t;
                    using writable_unit_t = dynamic_array_p::writable_unit_t;
                    using pointer_t = dynamic_array_p::pointer_t;
                    using writable_pointer_t = dynamic_array_p::writable_pointer_t;
                    using allocator_t = dynamic_array_p::allocator_t;
                    using grow_rate_t = dynamic_array_p::grow_rate_t;

                    static_assert(std::same_as<unit_t, unit_t>);
                }
            }

            TEST_SUITE("writable_unit_t")
            {
                TEST_CASE_TEMPLATE("should have a writable_unit_t that is non-const", dynamic_array_p, nkr_ALL)
                {
                    using unit_t = dynamic_array_p::unit_t;
                    using writable_unit_t = dynamic_array_p::writable_unit_t;
                    using pointer_t = dynamic_array_p::pointer_t;
                    using writable_pointer_t = dynamic_array_p::writable_pointer_t;
                    using allocator_t = dynamic_array_p::allocator_t;
                    using grow_rate_t = dynamic_array_p::grow_rate_t;

                    static_assert(std::same_as<writable_unit_t, std::remove_const_t<unit_t>>);
                }
            }

            TEST_SUITE("pointer_t")
            {
                TEST_CASE_TEMPLATE("should have a pointer_t with the same unit_t", dynamic_array_p, nkr_ALL)
                {
                    using unit_t = dynamic_array_p::unit_t;
                    using writable_unit_t = dynamic_array_p::writable_unit_t;
                    using pointer_t = dynamic_array_p::pointer_t;
                    using writable_pointer_t = dynamic_array_p::writable_pointer_t;
                    using allocator_t = dynamic_array_p::allocator_t;
                    using grow_rate_t = dynamic_array_p::grow_rate_t;

                    static_assert(std::same_as<pointer_t, nkr::pointer_t<unit_t>>);
                }
            }

            TEST_SUITE("writable_pointer_t")
            {
                TEST_CASE_TEMPLATE("should have a writable_pointer_t that is non-const", dynamic_array_p, nkr_ALL)
                {
                    using unit_t = dynamic_array_p::unit_t;
                    using writable_unit_t = dynamic_array_p::writable_unit_t;
                    using pointer_t = dynamic_array_p::pointer_t;
                    using writable_pointer_t = dynamic_array_p::writable_pointer_t;
                    using allocator_t = dynamic_array_p::allocator_t;
                    using grow_rate_t = dynamic_array_p::grow_rate_t;

                    static_assert(std::same_as<writable_pointer_t, nkr::pointer_t<writable_unit_t>>);
                }
            }

            TEST_SUITE("allocator_t")
            {
                TEST_CASE_TEMPLATE("should have an allocator_t with the same unit_t", dynamic_array_p, nkr_ALL)
                {
                    using unit_t = dynamic_array_p::unit_t;
                    using writable_unit_t = dynamic_array_p::writable_unit_t;
                    using pointer_t = dynamic_array_p::pointer_t;
                    using writable_pointer_t = dynamic_array_p::writable_pointer_t;
                    using allocator_t = dynamic_array_p::allocator_t;
                    using grow_rate_t = dynamic_array_p::grow_rate_t;

                    static_assert(std::same_as<allocator_t::unit_t, unit_t>);
                }
            }

            TEST_SUITE("grow_rate_t")
            {
                TEST_CASE_TEMPLATE("should have a grow_rate_t", dynamic_array_p, nkr_ALL)
                {
                    using unit_t = dynamic_array_p::unit_t;
                    using writable_unit_t = dynamic_array_p::writable_unit_t;
                    using pointer_t = dynamic_array_p::pointer_t;
                    using writable_pointer_t = dynamic_array_p::writable_pointer_t;
                    using allocator_t = dynamic_array_p::allocator_t;
                    using grow_rate_t = dynamic_array_p::grow_rate_t;

                    static_assert(std::same_as<grow_rate_t, grow_rate_t>);
                }
            }
        }

        TEST_SUITE("static functions")
        {
            TEST_SUITE("Grow_Rate()")
            {
                TEST_CASE_TEMPLATE("should equate grow_rate_t::To_Decimal()", dynamic_array_p, nkr_ALL)
                {
                    using unit_t = dynamic_array_p::unit_t;
                    using writable_unit_t = dynamic_array_p::writable_unit_t;
                    using pointer_t = dynamic_array_p::pointer_t;
                    using writable_pointer_t = dynamic_array_p::writable_pointer_t;
                    using allocator_t = dynamic_array_p::allocator_t;
                    using grow_rate_t = dynamic_array_p::grow_rate_t;

                    CHECK(dynamic_array_p::Grow_Rate() == grow_rate_t::To_Decimal());
                }
            }
        }

        TEST_SUITE("objects")
        {
            TEST_SUITE("default_ctor()")
            {
                TEST_CASE_TEMPLATE("should have a default pointer", dynamic_array_p, nkr_ALL)
                {
                    using unit_t = dynamic_array_p::unit_t;
                    using writable_unit_t = dynamic_array_p::writable_unit_t;
                    using pointer_t = dynamic_array_p::pointer_t;
                    using writable_pointer_t = dynamic_array_p::writable_pointer_t;
                    using allocator_t = dynamic_array_p::allocator_t;
                    using grow_rate_t = dynamic_array_p::grow_rate_t;

                    dynamic_array_p dynamic_array;
                    CHECK(dynamic_array.Pointer() == pointer_t());
                }

                TEST_CASE_TEMPLATE("should have a count of 0", dynamic_array_p, nkr_ALL)
                {
                    using unit_t = dynamic_array_p::unit_t;
                    using writable_unit_t = dynamic_array_p::writable_unit_t;
                    using pointer_t = dynamic_array_p::pointer_t;
                    using writable_pointer_t = dynamic_array_p::writable_pointer_t;
                    using allocator_t = dynamic_array_p::allocator_t;
                    using grow_rate_t = dynamic_array_p::grow_rate_t;

                    dynamic_array_p dynamic_array;
                    CHECK(dynamic_array.Count() == 0);
                }
            }

            TEST_SUITE("copy_ctor()")
            {
                TEST_CASE_TEMPLATE("should explicitly copy each unit and the count of other", dynamic_array_p, nkr_ALL)
                {
                    using unit_t = dynamic_array_p::unit_t;
                    using writable_unit_t = dynamic_array_p::writable_unit_t;
                    using pointer_t = dynamic_array_p::pointer_t;
                    using writable_pointer_t = dynamic_array_p::writable_pointer_t;
                    using allocator_t = dynamic_array_p::allocator_t;
                    using grow_rate_t = dynamic_array_p::grow_rate_t;

                    count_t count = Random<count_t>(1, 16);
                    std::remove_const_t<dynamic_array_p> other;
                    for (index_t idx = 0, end = count; idx < end; idx += 1) {
                        other.Push(Random<std::remove_const_t<unit_t>>());
                    }
                    dynamic_array_p dynamic_array(other);
                    CHECK(dynamic_array.Count() == count);
                    for (index_t idx = 0, end = count; idx < end; idx += 1) {
                        CHECK(dynamic_array[idx] == other[idx]);
                    }
                }

                TEST_CASE_TEMPLATE("should implicitly copy each unit and the count of other", dynamic_array_p, nkr_ALL)
                {
                    using unit_t = dynamic_array_p::unit_t;
                    using writable_unit_t = dynamic_array_p::writable_unit_t;
                    using pointer_t = dynamic_array_p::pointer_t;
                    using writable_pointer_t = dynamic_array_p::writable_pointer_t;
                    using allocator_t = dynamic_array_p::allocator_t;
                    using grow_rate_t = dynamic_array_p::grow_rate_t;

                    count_t count = Random<count_t>(1, 16);
                    std::remove_const_t<dynamic_array_p> other;
                    for (index_t idx = 0, end = count; idx < end; idx += 1) {
                        other.Push(Random<std::remove_const_t<unit_t>>());
                    }
                    dynamic_array_p dynamic_array = other;
                    CHECK(dynamic_array.Count() == count);
                    for (index_t idx = 0, end = count; idx < end; idx += 1) {
                        CHECK(dynamic_array[idx] == other[idx]);
                    }
                }

                TEST_CASE_TEMPLATE("should not change the other", dynamic_array_p, nkr_ALL)
                {
                    using unit_t = dynamic_array_p::unit_t;
                    using writable_unit_t = dynamic_array_p::writable_unit_t;
                    using pointer_t = dynamic_array_p::pointer_t;
                    using writable_pointer_t = dynamic_array_p::writable_pointer_t;
                    using allocator_t = dynamic_array_p::allocator_t;
                    using grow_rate_t = dynamic_array_p::grow_rate_t;

                    count_t count = Random<count_t>(1, 16);
                    std::remove_const_t<dynamic_array_p> other;
                    for (index_t idx = 0, end = count; idx < end; idx += 1) {
                        other.Push(Random<std::remove_const_t<unit_t>>());
                    }
                    pointer_t pointer = other.Pointer();
                    dynamic_array_p dynamic_array(other);
                    CHECK(other.Pointer() == pointer);
                    CHECK(other.Count() == count);
                }

                TEST_CASE_TEMPLATE("should have a different pointer", dynamic_array_p, nkr_ALL)
                {
                    using unit_t = dynamic_array_p::unit_t;
                    using writable_unit_t = dynamic_array_p::writable_unit_t;
                    using pointer_t = dynamic_array_p::pointer_t;
                    using writable_pointer_t = dynamic_array_p::writable_pointer_t;
                    using allocator_t = dynamic_array_p::allocator_t;
                    using grow_rate_t = dynamic_array_p::grow_rate_t;

                    count_t count = Random<count_t>(1, 16);
                    std::remove_const_t<dynamic_array_p> other;
                    for (index_t idx = 0, end = count; idx < end; idx += 1) {
                        other.Push(Random<std::remove_const_t<unit_t>>());
                    }
                    pointer_t pointer = other.Pointer();
                    dynamic_array_p dynamic_array(other);
                    CHECK(dynamic_array.Pointer() != pointer);
                }
            }

            TEST_SUITE("move_ctor()")
            {
                TEST_CASE_TEMPLATE("should explicitly move the pointer and count of other", dynamic_array_p, nkr_ALL)
                {
                    using unit_t = dynamic_array_p::unit_t;
                    using writable_unit_t = dynamic_array_p::writable_unit_t;
                    using pointer_t = dynamic_array_p::pointer_t;
                    using writable_pointer_t = dynamic_array_p::writable_pointer_t;
                    using allocator_t = dynamic_array_p::allocator_t;
                    using grow_rate_t = dynamic_array_p::grow_rate_t;

                    count_t count = Random<count_t>(1, 16);
                    std::remove_const_t<dynamic_array_p> other;
                    for (index_t idx = 0, end = count; idx < end; idx += 1) {
                        other.Push(Random<std::remove_const_t<unit_t>>());
                    }
                    pointer_t pointer = other.Pointer();
                    dynamic_array_p dynamic_array(std::move(other));
                    CHECK(dynamic_array.Pointer() == pointer);
                    CHECK(dynamic_array.Count() == count);
                }

                TEST_CASE_TEMPLATE("should implicitly move the count of other", dynamic_array_p, nkr_ALL)
                {
                    using unit_t = dynamic_array_p::unit_t;
                    using writable_unit_t = dynamic_array_p::writable_unit_t;
                    using pointer_t = dynamic_array_p::pointer_t;
                    using writable_pointer_t = dynamic_array_p::writable_pointer_t;
                    using allocator_t = dynamic_array_p::allocator_t;
                    using grow_rate_t = dynamic_array_p::grow_rate_t;

                    count_t count = Random<count_t>(1, 16);
                    std::remove_const_t<dynamic_array_p> other;
                    for (index_t idx = 0, end = count; idx < end; idx += 1) {
                        other.Push(Random<std::remove_const_t<unit_t>>());
                    }
                    pointer_t pointer = other.Pointer();
                    dynamic_array_p dynamic_array = std::move(other);
                    CHECK(dynamic_array.Pointer() == pointer);
                    CHECK(dynamic_array.Count() == count);
                }

                TEST_CASE_TEMPLATE("should set the other to default values", dynamic_array_p, nkr_ALL)
                {
                    using unit_t = dynamic_array_p::unit_t;
                    using writable_unit_t = dynamic_array_p::writable_unit_t;
                    using pointer_t = dynamic_array_p::pointer_t;
                    using writable_pointer_t = dynamic_array_p::writable_pointer_t;
                    using allocator_t = dynamic_array_p::allocator_t;
                    using grow_rate_t = dynamic_array_p::grow_rate_t;

                    count_t count = Random<count_t>(1, 16);
                    std::remove_const_t<dynamic_array_p> other;
                    for (index_t idx = 0, end = count; idx < end; idx += 1) {
                        other.Push(Random<std::remove_const_t<unit_t>>());
                    }
                    dynamic_array_p dynamic_array(std::move(other));
                    CHECK(other.Pointer() == pointer_t());
                    CHECK(other.Count() == 0);
                }
            }

            TEST_SUITE("copy_assignment_ctor()")
            {
                TEST_CASE_TEMPLATE("should copy each unit and the count of other", dynamic_array_p, nkr_NON_CONST)
                {
                    using unit_t = dynamic_array_p::unit_t;
                    using writable_unit_t = dynamic_array_p::writable_unit_t;
                    using pointer_t = dynamic_array_p::pointer_t;
                    using writable_pointer_t = dynamic_array_p::writable_pointer_t;
                    using allocator_t = dynamic_array_p::allocator_t;
                    using grow_rate_t = dynamic_array_p::grow_rate_t;

                    count_t count = Random<count_t>(1, 16);
                    std::remove_const_t<dynamic_array_p> other;
                    for (index_t idx = 0, end = count; idx < end; idx += 1) {
                        other.Push(Random<std::remove_const_t<unit_t>>());
                    }
                    dynamic_array_p dynamic_array;
                    dynamic_array = other;
                    CHECK(dynamic_array.Count() == count);
                    for (index_t idx = 0, end = count; idx < end; idx += 1) {
                        CHECK(dynamic_array[idx] == other[idx]);
                    }
                }

                TEST_CASE_TEMPLATE("should return itself after copying other", dynamic_array_p, nkr_NON_CONST)
                {
                    using unit_t = dynamic_array_p::unit_t;
                    using writable_unit_t = dynamic_array_p::writable_unit_t;
                    using pointer_t = dynamic_array_p::pointer_t;
                    using writable_pointer_t = dynamic_array_p::writable_pointer_t;
                    using allocator_t = dynamic_array_p::allocator_t;
                    using grow_rate_t = dynamic_array_p::grow_rate_t;

                    count_t count = Random<count_t>(1, 16);
                    std::remove_const_t<dynamic_array_p> other;
                    for (index_t idx = 0, end = count; idx < end; idx += 1) {
                        other.Push(Random<std::remove_const_t<unit_t>>());
                    }
                    dynamic_array_p dynamic_array;
                    CHECK(&(dynamic_array = other) == &dynamic_array);
                }

                TEST_CASE_TEMPLATE("should not change the other", dynamic_array_p, nkr_NON_CONST)
                {
                    using unit_t = dynamic_array_p::unit_t;
                    using writable_unit_t = dynamic_array_p::writable_unit_t;
                    using pointer_t = dynamic_array_p::pointer_t;
                    using writable_pointer_t = dynamic_array_p::writable_pointer_t;
                    using allocator_t = dynamic_array_p::allocator_t;
                    using grow_rate_t = dynamic_array_p::grow_rate_t;

                    count_t count = Random<count_t>(1, 16);
                    std::remove_const_t<dynamic_array_p> other;
                    for (index_t idx = 0, end = count; idx < end; idx += 1) {
                        other.Push(Random<std::remove_const_t<unit_t>>());
                    }
                    pointer_t pointer = other.Pointer();
                    dynamic_array_p dynamic_array;
                    dynamic_array = other;
                    CHECK(other.Pointer() == pointer);
                    CHECK(other.Count() == count);
                }

                TEST_CASE_TEMPLATE("should have a different pointer", dynamic_array_p, nkr_NON_CONST)
                {
                    using unit_t = dynamic_array_p::unit_t;
                    using writable_unit_t = dynamic_array_p::writable_unit_t;
                    using pointer_t = dynamic_array_p::pointer_t;
                    using writable_pointer_t = dynamic_array_p::writable_pointer_t;
                    using allocator_t = dynamic_array_p::allocator_t;
                    using grow_rate_t = dynamic_array_p::grow_rate_t;

                    count_t count = Random<count_t>(1, 16);
                    std::remove_const_t<dynamic_array_p> other;
                    for (index_t idx = 0, end = count; idx < end; idx += 1) {
                        other.Push(Random<std::remove_const_t<unit_t>>());
                    }
                    pointer_t pointer = other.Pointer();
                    dynamic_array_p dynamic_array;
                    dynamic_array = other;
                    CHECK(dynamic_array.Pointer() != pointer);
                }
            }

            TEST_SUITE("move_assignment_ctor()")
            {
                TEST_CASE_TEMPLATE("should move the pointer and count of other", dynamic_array_p, nkr_NON_CONST)
                {
                    using unit_t = dynamic_array_p::unit_t;
                    using writable_unit_t = dynamic_array_p::writable_unit_t;
                    using pointer_t = dynamic_array_p::pointer_t;
                    using writable_pointer_t = dynamic_array_p::writable_pointer_t;
                    using allocator_t = dynamic_array_p::allocator_t;
                    using grow_rate_t = dynamic_array_p::grow_rate_t;

                    count_t count = Random<count_t>(1, 16);
                    std::remove_const_t<dynamic_array_p> other;
                    for (index_t idx = 0, end = count; idx < end; idx += 1) {
                        other.Push(Random<std::remove_const_t<unit_t>>());
                    }
                    pointer_t pointer = other.Pointer();
                    dynamic_array_p dynamic_array;
                    dynamic_array = std::move(other);
                    CHECK(dynamic_array.Pointer() == pointer);
                    CHECK(dynamic_array.Count() == count);
                }

                TEST_CASE_TEMPLATE("should return itself after moving other", dynamic_array_p, nkr_NON_CONST)
                {
                    using unit_t = dynamic_array_p::unit_t;
                    using writable_unit_t = dynamic_array_p::writable_unit_t;
                    using pointer_t = dynamic_array_p::pointer_t;
                    using writable_pointer_t = dynamic_array_p::writable_pointer_t;
                    using allocator_t = dynamic_array_p::allocator_t;
                    using grow_rate_t = dynamic_array_p::grow_rate_t;

                    count_t count = Random<count_t>(1, 16);
                    std::remove_const_t<dynamic_array_p> other;
                    for (index_t idx = 0, end = count; idx < end; idx += 1) {
                        other.Push(Random<std::remove_const_t<unit_t>>());
                    }
                    pointer_t pointer = other.Pointer();
                    dynamic_array_p dynamic_array;
                    CHECK(&(dynamic_array = std::move(other)) == &dynamic_array);
                }

                TEST_CASE_TEMPLATE("should set the other to default values", dynamic_array_p, nkr_NON_CONST)
                {
                    using unit_t = dynamic_array_p::unit_t;
                    using writable_unit_t = dynamic_array_p::writable_unit_t;
                    using pointer_t = dynamic_array_p::pointer_t;
                    using writable_pointer_t = dynamic_array_p::writable_pointer_t;
                    using allocator_t = dynamic_array_p::allocator_t;
                    using grow_rate_t = dynamic_array_p::grow_rate_t;

                    count_t count = Random<count_t>(1, 16);
                    std::remove_const_t<dynamic_array_p> other;
                    for (index_t idx = 0, end = count; idx < end; idx += 1) {
                        other.Push(Random<std::remove_const_t<unit_t>>());
                    }
                    dynamic_array_p dynamic_array;
                    dynamic_array = std::move(other);
                    CHECK(other.Pointer() == pointer_t());
                    CHECK(other.Count() == 0);
                }
            }

            TEST_SUITE("dtor()")
            {
                TEST_CASE_TEMPLATE("should set its values to defaults", dynamic_array_p, nkr_ALL)
                {
                    using unit_t = dynamic_array_p::unit_t;
                    using writable_unit_t = dynamic_array_p::writable_unit_t;
                    using pointer_t = dynamic_array_p::pointer_t;
                    using writable_pointer_t = dynamic_array_p::writable_pointer_t;
                    using allocator_t = dynamic_array_p::allocator_t;
                    using grow_rate_t = dynamic_array_p::grow_rate_t;

                    count_t count = Random<count_t>(1, 16);
                    std::remove_const_t<dynamic_array_p> other;
                    for (index_t idx = 0, end = count; idx < end; idx += 1) {
                        other.Push(Random<std::remove_const_t<unit_t>>());
                    }
                    dynamic_array_p dynamic_array(other);
                    dynamic_array.~dynamic_array_p();
                    CHECK(dynamic_array.Pointer() == pointer_t());
                    CHECK(dynamic_array.Count() == 0);
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
        int test[4] = { 0, 1, 2, 3 };
        dynamic_array_t<int> array(test);
        CHECK(array.Count() == 4);

        dynamic_array_t<int, allocator::heap_t<int>, math::fraction_t<17, 10>> dynamic_array;
        CHECK(dynamic_array.Grow_Rate() == static_cast<real_t>(1.7));
        CHECK(dynamic_array.Capacity(16));
        dynamic_array.Push(8);
        dynamic_array.Push(16);
        dynamic_array.Push(32);
        dynamic_array.Push(64);
        CHECK(dynamic_array.At(0) == 8);
        CHECK(dynamic_array.At(1) == 16);
        CHECK(dynamic_array.At(2) == 32);
        CHECK(dynamic_array.At(3) == 64);
        while (dynamic_array.Count() > 0) {
            dynamic_array.Pop();
        }
        dynamic_array.Fit();
        CHECK(dynamic_array.Capacity() == 0);
        CHECK(dynamic_array.Pointer() == nullptr);

        r64_t our_time = os::time::Test_In_Microseconds(
            16,
            []()
            {
                dynamic_array_t<index_t, allocator::heap_t<index_t>, math::fraction_t<17, 10>> dynamic_array;
                for (index_t idx = 0, end = 1024; idx < end; idx += 1) {
                    dynamic_array.Push(idx);
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
