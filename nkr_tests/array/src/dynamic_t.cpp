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
    #define types                                                                               \
        std::tuple<std_bool_t, allocator::heap_t<std_bool_t>, math::fraction_t<17, 10>>,        \
        std::tuple<std_bool_t, allocator::heap_zeros_t<std_bool_t>, math::fraction_t<17, 10>>,  \
        std::tuple<std_bool_t, allocator::heap_t<std_bool_t>, math::fraction_t<2, 1>>,          \
        std::tuple<std_bool_t, allocator::heap_zeros_t<std_bool_t>, math::fraction_t<2, 1>>,    \
                                                                                                \
        std::tuple<bool_t, allocator::heap_t<bool_t>, math::fraction_t<17, 10>>,                \
        std::tuple<bool_t, allocator::heap_zeros_t<bool_t>, math::fraction_t<17, 10>>,          \
        std::tuple<bool_t, allocator::heap_t<bool_t>, math::fraction_t<2, 1>>,                  \
        std::tuple<bool_t, allocator::heap_zeros_t<bool_t>, math::fraction_t<2, 1>>

        TEST_SUITE("aliases")
        {
            TEST_SUITE("unit_t")
            {
                TEST_CASE_TEMPLATE("should equal unit_p", tuple_p, types)
                {
                    using unit_p = std::tuple_element_t<0, tuple_p>;
                    using allocator_p = std::tuple_element_t<1, tuple_p>;
                    using grow_rate_p = std::tuple_element_t<2, tuple_p>;
                    using array_dynamic_p = array_dynamic_t<unit_p, allocator_p, grow_rate_p>;

                    static_assert(std::same_as<array_dynamic_p::unit_t, unit_p>);
                }
            }

            TEST_SUITE("pointer_t")
            {
                TEST_CASE_TEMPLATE("should equal pointer_t<unit_p>", tuple_p, types)
                {
                    using unit_p = std::tuple_element_t<0, tuple_p>;
                    using allocator_p = std::tuple_element_t<1, tuple_p>;
                    using grow_rate_p = std::tuple_element_t<2, tuple_p>;
                    using array_dynamic_p = array_dynamic_t<unit_p, allocator_p, grow_rate_p>;

                    static_assert(std::same_as<array_dynamic_p::pointer_t, pointer_t<unit_p>>);
                }
            }

            TEST_SUITE("allocator_t")
            {
                TEST_CASE_TEMPLATE("should equal allocator_p", tuple_p, types)
                {
                    using unit_p = std::tuple_element_t<0, tuple_p>;
                    using allocator_p = std::tuple_element_t<1, tuple_p>;
                    using grow_rate_p = std::tuple_element_t<2, tuple_p>;
                    using array_dynamic_p = array_dynamic_t<unit_p, allocator_p, grow_rate_p>;

                    static_assert(std::same_as<array_dynamic_p::allocator_t, allocator_p>);
                }
            }

            TEST_SUITE("grow_rate_t")
            {
                TEST_CASE_TEMPLATE("should equal grow_rate_p", tuple_p, types)
                {
                    using unit_p = std::tuple_element_t<0, tuple_p>;
                    using allocator_p = std::tuple_element_t<1, tuple_p>;
                    using grow_rate_p = std::tuple_element_t<2, tuple_p>;
                    using array_dynamic_p = array_dynamic_t<unit_p, allocator_p, grow_rate_p>;

                    static_assert(std::same_as<array_dynamic_p::grow_rate_t, grow_rate_p>);
                }
            }
        }

        TEST_SUITE("static functions")
        {
            TEST_SUITE("Grow_Rate()")
            {
                TEST_CASE_TEMPLATE("should equate grow_rate_p::To_Decimal()", tuple_p, types)
                {
                    using unit_p = std::tuple_element_t<0, tuple_p>;
                    using allocator_p = std::tuple_element_t<1, tuple_p>;
                    using grow_rate_p = std::tuple_element_t<2, tuple_p>;
                    using array_dynamic_p = array_dynamic_t<unit_p, allocator_p, grow_rate_p>;

                    CHECK(array_dynamic_p::Grow_Rate() == grow_rate_p::To_Decimal());
                }
            }
        }

        TEST_SUITE("object data")
        {
            TEST_SUITE("units")
            {
                TEST_CASE_TEMPLATE("should be a pointer_t<unit_p>", tuple_p, types)
                {
                    using unit_p = std::tuple_element_t<0, tuple_p>;
                    using allocator_p = std::tuple_element_t<1, tuple_p>;
                    using grow_rate_p = std::tuple_element_t<2, tuple_p>;
                    using array_dynamic_p = array_dynamic_t<unit_p, allocator_p, grow_rate_p>;

                    static_assert(std::same_as<decltype(array_dynamic_p::units), pointer_t<unit_p>>);
                }
            }

            TEST_SUITE("unit_count")
            {
                TEST_CASE_TEMPLATE("should be a count_t", tuple_p, types)
                {
                    using unit_p = std::tuple_element_t<0, tuple_p>;
                    using allocator_p = std::tuple_element_t<1, tuple_p>;
                    using grow_rate_p = std::tuple_element_t<2, tuple_p>;
                    using array_dynamic_p = array_dynamic_t<unit_p, allocator_p, grow_rate_p>;

                    static_assert(std::same_as<decltype(array_dynamic_p::unit_count), count_t>);
                }
            }

            TEST_SUITE("allocator")
            {
                TEST_CASE_TEMPLATE("should be a allocator_p", tuple_p, types)
                {
                    using unit_p = std::tuple_element_t<0, tuple_p>;
                    using allocator_p = std::tuple_element_t<1, tuple_p>;
                    using grow_rate_p = std::tuple_element_t<2, tuple_p>;
                    using array_dynamic_p = array_dynamic_t<unit_p, allocator_p, grow_rate_p>;

                    static_assert(std::same_as<decltype(array_dynamic_p::allocator), allocator_p>);
                }
            }
        }

        TEST_SUITE("objects")
        {
            TEST_SUITE("default_ctor()")
            {
                TEST_CASE_TEMPLATE("should have a default pointer", tuple_p, types)
                {
                    using unit_p = std::tuple_element_t<0, tuple_p>;
                    using allocator_p = std::tuple_element_t<1, tuple_p>;
                    using grow_rate_p = std::tuple_element_t<2, tuple_p>;
                    using array_dynamic_p = array_dynamic_t<unit_p, allocator_p, grow_rate_p>;
                    using pointer_t = array_dynamic_p::pointer_t;

                    array_dynamic_p array_dynamic;
                    CHECK(array_dynamic.Pointer() == pointer_t());
                }

                TEST_CASE_TEMPLATE("should have a count of 0", tuple_p, types)
                {
                    using unit_p = std::tuple_element_t<0, tuple_p>;
                    using allocator_p = std::tuple_element_t<1, tuple_p>;
                    using grow_rate_p = std::tuple_element_t<2, tuple_p>;
                    using array_dynamic_p = array_dynamic_t<unit_p, allocator_p, grow_rate_p>;
                    using pointer_t = array_dynamic_p::pointer_t;

                    array_dynamic_p array_dynamic;
                    CHECK(array_dynamic.Count() == 0);
                }
            }

            TEST_SUITE("copy_ctor()")
            {
                TEST_CASE_TEMPLATE("should explicitly copy each unit and the count of other", tuple_p, types)
                {
                    using unit_p = std::tuple_element_t<0, tuple_p>;
                    using allocator_p = std::tuple_element_t<1, tuple_p>;
                    using grow_rate_p = std::tuple_element_t<2, tuple_p>;
                    using array_dynamic_p = array_dynamic_t<unit_p, allocator_p, grow_rate_p>;
                    using pointer_t = array_dynamic_p::pointer_t;

                    count_t count = Random<count_t>(1, 16);
                    array_dynamic_p other;
                    for (index_t idx = 0, end = count; idx < end; idx += 1) {
                        other.Push(Random<unit_p>());
                    }
                    array_dynamic_p array_dynamic(other);
                    CHECK(array_dynamic.Count() == count);
                    for (index_t idx = 0, end = count; idx < end; idx += 1) {
                        CHECK(array_dynamic[idx] == other[idx]);
                    }
                }

                TEST_CASE_TEMPLATE("should implicitly copy each unit and the count of other", tuple_p, types)
                {
                    using unit_p = std::tuple_element_t<0, tuple_p>;
                    using allocator_p = std::tuple_element_t<1, tuple_p>;
                    using grow_rate_p = std::tuple_element_t<2, tuple_p>;
                    using array_dynamic_p = array_dynamic_t<unit_p, allocator_p, grow_rate_p>;
                    using pointer_t = array_dynamic_p::pointer_t;

                    count_t count = Random<count_t>(1, 16);
                    array_dynamic_p other;
                    for (index_t idx = 0, end = count; idx < end; idx += 1) {
                        other.Push(Random<unit_p>());
                    }
                    array_dynamic_p array_dynamic = other;
                    CHECK(array_dynamic.Count() == count);
                    for (index_t idx = 0, end = count; idx < end; idx += 1) {
                        CHECK(array_dynamic[idx] == other[idx]);
                    }
                }

                TEST_CASE_TEMPLATE("should not change the other", tuple_p, types)
                {
                    using unit_p = std::tuple_element_t<0, tuple_p>;
                    using allocator_p = std::tuple_element_t<1, tuple_p>;
                    using grow_rate_p = std::tuple_element_t<2, tuple_p>;
                    using array_dynamic_p = array_dynamic_t<unit_p, allocator_p, grow_rate_p>;
                    using pointer_t = array_dynamic_p::pointer_t;

                    count_t count = Random<count_t>(1, 16);
                    array_dynamic_p other;
                    for (index_t idx = 0, end = count; idx < end; idx += 1) {
                        other.Push(Random<unit_p>());
                    }
                    pointer_t pointer = other.Pointer();
                    array_dynamic_p array_dynamic(other);
                    CHECK(other.Pointer() == pointer);
                    CHECK(other.Count() == count);
                }

                TEST_CASE_TEMPLATE("should have a different pointer", tuple_p, types)
                {
                    using unit_p = std::tuple_element_t<0, tuple_p>;
                    using allocator_p = std::tuple_element_t<1, tuple_p>;
                    using grow_rate_p = std::tuple_element_t<2, tuple_p>;
                    using array_dynamic_p = array_dynamic_t<unit_p, allocator_p, grow_rate_p>;
                    using pointer_t = array_dynamic_p::pointer_t;

                    count_t count = Random<count_t>(1, 16);
                    array_dynamic_p other;
                    for (index_t idx = 0, end = count; idx < end; idx += 1) {
                        other.Push(Random<unit_p>());
                    }
                    pointer_t pointer = other.Pointer();
                    array_dynamic_p array_dynamic(other);
                    CHECK(array_dynamic.Pointer() != pointer);
                }

                TEST_CASE_TEMPLATE("should work with volatile other", tuple_p, types)
                {
                    using unit_p = std::tuple_element_t<0, tuple_p>;
                    using allocator_p = std::tuple_element_t<1, tuple_p>;
                    using grow_rate_p = std::tuple_element_t<2, tuple_p>;
                    using array_dynamic_p = array_dynamic_t<unit_p, allocator_p, grow_rate_p>;
                    using pointer_t = array_dynamic_p::pointer_t;

                    count_t count = Random<count_t>(1, 16);
                    volatile array_dynamic_p other;
                    for (index_t idx = 0, end = count; idx < end; idx += 1) {
                        other.Push(Random<unit_p>());
                    }
                    array_dynamic_p array_dynamic(other);
                    CHECK(array_dynamic.Count() == count);
                    for (index_t idx = 0, end = count; idx < end; idx += 1) {
                        CHECK(array_dynamic[idx] == other[idx]);
                    }
                }
            }

            TEST_SUITE("move_ctor()")
            {
                TEST_CASE_TEMPLATE("should explicitly move the pointer and count of other", tuple_p, types)
                {
                    using unit_p = std::tuple_element_t<0, tuple_p>;
                    using allocator_p = std::tuple_element_t<1, tuple_p>;
                    using grow_rate_p = std::tuple_element_t<2, tuple_p>;
                    using array_dynamic_p = array_dynamic_t<unit_p, allocator_p, grow_rate_p>;
                    using pointer_t = array_dynamic_p::pointer_t;

                    count_t count = Random<count_t>(1, 16);
                    array_dynamic_p other;
                    for (index_t idx = 0, end = count; idx < end; idx += 1) {
                        other.Push(Random<unit_p>());
                    }
                    pointer_t pointer = other.Pointer();
                    array_dynamic_p array_dynamic(std::move(other));
                    CHECK(array_dynamic.Pointer() == pointer);
                    CHECK(array_dynamic.Count() == count);
                }

                TEST_CASE_TEMPLATE("should implicitly move the count of other", tuple_p, types)
                {
                    using unit_p = std::tuple_element_t<0, tuple_p>;
                    using allocator_p = std::tuple_element_t<1, tuple_p>;
                    using grow_rate_p = std::tuple_element_t<2, tuple_p>;
                    using array_dynamic_p = array_dynamic_t<unit_p, allocator_p, grow_rate_p>;
                    using pointer_t = array_dynamic_p::pointer_t;

                    count_t count = Random<count_t>(1, 16);
                    array_dynamic_p other;
                    for (index_t idx = 0, end = count; idx < end; idx += 1) {
                        other.Push(Random<unit_p>());
                    }
                    pointer_t pointer = other.Pointer();
                    array_dynamic_p array_dynamic = std::move(other);
                    CHECK(array_dynamic.Pointer() == pointer);
                    CHECK(array_dynamic.Count() == count);
                }

                TEST_CASE_TEMPLATE("should set the other to default values", tuple_p, types)
                {
                    using unit_p = std::tuple_element_t<0, tuple_p>;
                    using allocator_p = std::tuple_element_t<1, tuple_p>;
                    using grow_rate_p = std::tuple_element_t<2, tuple_p>;
                    using array_dynamic_p = array_dynamic_t<unit_p, allocator_p, grow_rate_p>;
                    using pointer_t = array_dynamic_p::pointer_t;

                    count_t count = Random<count_t>(1, 16);
                    array_dynamic_p other;
                    for (index_t idx = 0, end = count; idx < end; idx += 1) {
                        other.Push(Random<unit_p>());
                    }
                    array_dynamic_p array_dynamic(std::move(other));
                    CHECK(other.Pointer() == pointer_t());
                    CHECK(other.Count() == 0);
                }

                TEST_CASE_TEMPLATE("should work with volatile other", tuple_p, types)
                {
                    using unit_p = std::tuple_element_t<0, tuple_p>;
                    using allocator_p = std::tuple_element_t<1, tuple_p>;
                    using grow_rate_p = std::tuple_element_t<2, tuple_p>;
                    using array_dynamic_p = array_dynamic_t<unit_p, allocator_p, grow_rate_p>;
                    using pointer_t = array_dynamic_p::pointer_t;

                    count_t count = Random<count_t>(1, 16);
                    volatile array_dynamic_p other;
                    for (index_t idx = 0, end = count; idx < end; idx += 1) {
                        other.Push(Random<unit_p>());
                    }
                    pointer_t pointer = other.Pointer();
                    array_dynamic_p array_dynamic(std::move(other));
                    CHECK(array_dynamic.Pointer() == pointer);
                    CHECK(array_dynamic.Count() == count);
                }
            }
        }

        TEST_SUITE("methods")
        {

        }

        TEST_SUITE("operators")
        {

        }

    #undef types
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
