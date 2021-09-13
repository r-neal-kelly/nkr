/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/allocator_heap_t.h"
#include "nkr/allocator_heap_zeros_t.h"
#include "nkr/array_dynamic_t.h"

#include "intrinsics.h"

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
            TEST_SUITE("self_t")
            {
                TEST_CASE_TEMPLATE("should equal itself", tuple_p, types)
                {
                    using unit_p = std::tuple_element_t<0, tuple_p>;
                    using allocator_p = std::tuple_element_t<1, tuple_p>;
                    using grow_rate_p = std::tuple_element_t<2, tuple_p>;
                    using array_dynamic_p = array_dynamic_t<unit_p, allocator_p, grow_rate_p>;

                    static_assert(std::same_as<array_dynamic_p::self_t, array_dynamic_p>);
                }
            }

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
    }

}
