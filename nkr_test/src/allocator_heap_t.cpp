/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/allocator_heap_t.h"

#include "intrinsics.h"

namespace nkr { namespace allocator {

    TEST_SUITE("heap_t<unit_p>")
    {
    #define types   \
        std_bool_t, \
        bool_t,     \
        u8_t,       \
        s8_t,       \
        u16_t,      \
        s16_t,      \
        u32_t,      \
        s32_t,      \
        u64_t,      \
        s64_t,      \
        r32_t,      \
        r64_t

    #define volatiles           \
        volatile std_bool_t,    \
        volatile bool_t,        \
        volatile u8_t,          \
        volatile s8_t,          \
        volatile u16_t,         \
        volatile s16_t,         \
        volatile u32_t,         \
        volatile s32_t,         \
        volatile u64_t,         \
        volatile s64_t,         \
        volatile r32_t,         \
        volatile r64_t

        TEST_SUITE("aliases")
        {
            TEST_SUITE("unit_t")
            {
                TEST_CASE_TEMPLATE("should equal unit_p", unit_p, types, volatiles)
                {
                    static_assert(std::same_as<heap_t<unit_p>::unit_t, unit_p>);
                }
            }

            TEST_SUITE("units_t")
            {
                TEST_CASE_TEMPLATE("should equal unit_p*", unit_p, types, volatiles)
                {
                    static_assert(std::same_as<heap_t<unit_p>::units_t, unit_p*>);
                }
            }
        }

        TEST_SUITE("static functions")
        {
            TEST_SUITE("Min_Unit_Count()")
            {
                TEST_CASE_TEMPLATE("should be 1", unit_p, types, volatiles)
                {
                    static_assert(heap_t<unit_p>::Min_Unit_Count() == 1);
                }
            }

            TEST_SUITE("Max_Unit_Count()")
            {
                TEST_CASE_TEMPLATE("should be count_t max() / unit_t size", unit_p, types, volatiles)
                {
                    static_assert(heap_t<unit_p>::Max_Unit_Count() == std::numeric_limits<count_t>::max() / sizeof(unit_p));
                }
            }
        }

        TEST_SUITE("methods")
        {
            TEST_SUITE("Allocate(units_t)")
            {
                TEST_CASE_TEMPLATE("should set units to non-nullptr if successful", unit_p, types, volatiles)
                {
                    using heap_t = heap_t<unit_p>;
                    using unit_t = heap_t::unit_t;
                    using units_t = heap_t::units_t;

                    heap_t allocator;
                    units_t units = nullptr;
                    count_t unit_count = Random<count_t>(1, 16);
                    allocator.Allocate(units, unit_count);
                    CHECK(units != nullptr);

                    allocator.Deallocate(units);
                }

                TEST_CASE_TEMPLATE("should set units to nullptr if unsuccessful", unit_p, types, volatiles)
                {
                    using heap_t = heap_t<unit_p>;
                    using unit_t = heap_t::unit_t;
                    using units_t = heap_t::units_t;

                    heap_t allocator;
                    units_t units = Random<units_t>();
                    count_t unit_count = heap_t::Max_Unit_Count();
                    allocator.Allocate(units, unit_count);
                    CHECK(units == nullptr);

                    allocator.Deallocate(units);
                }

                TEST_CASE_TEMPLATE("should return true when successful", unit_p, types, volatiles)
                {
                    using heap_t = heap_t<unit_p>;
                    using unit_t = heap_t::unit_t;
                    using units_t = heap_t::units_t;

                    heap_t allocator;
                    units_t units;
                    count_t unit_count = Random<count_t>(1, 16);
                    CHECK(allocator.Allocate(units, unit_count) == true);

                    allocator.Deallocate(units);
                }

                TEST_CASE_TEMPLATE("should return false when unsuccessful", unit_p, types, volatiles)
                {
                    using heap_t = heap_t<unit_p>;
                    using unit_t = heap_t::unit_t;
                    using units_t = heap_t::units_t;

                    heap_t allocator;
                    units_t units;
                    count_t unit_count = heap_t::Max_Unit_Count();
                    CHECK(allocator.Allocate(units, unit_count) == false);

                    allocator.Deallocate(units);
                }
            }

            TEST_SUITE("Allocate(pointer_t)")
            {
                TEST_CASE_TEMPLATE("should set pointer's units to non-nullptr if successful", unit_p, types, volatiles)
                {
                    using heap_t = heap_t<unit_p>;
                    using unit_t = heap_t::unit_t;
                    using units_t = heap_t::units_t;

                    heap_t allocator;
                    pointer_t<unit_t> units;
                    count_t unit_count = Random<count_t>(1, 16);
                    allocator.Allocate(units, unit_count);
                    CHECK(units.units != nullptr);

                    allocator.Deallocate(units);
                }

                TEST_CASE_TEMPLATE("should set pointer's unit_count to unit_count if successful", unit_p, types, volatiles)
                {
                    using heap_t = heap_t<unit_p>;
                    using unit_t = heap_t::unit_t;
                    using units_t = heap_t::units_t;

                    heap_t allocator;
                    pointer_t<unit_t> units;
                    count_t unit_count = Random<count_t>(1, 16);
                    allocator.Allocate(units, unit_count);
                    CHECK(units.unit_count == unit_count);

                    allocator.Deallocate(units);
                }

                TEST_CASE_TEMPLATE("should set pointer's units to nullptr if unsuccessful", unit_p, types, volatiles)
                {
                    using heap_t = heap_t<unit_p>;
                    using unit_t = heap_t::unit_t;
                    using units_t = heap_t::units_t;

                    heap_t allocator;
                    pointer_t<unit_t> units = Random<units_t>();
                    count_t unit_count = heap_t::Max_Unit_Count();
                    allocator.Allocate(units, unit_count);
                    CHECK(units.units == nullptr);

                    allocator.Deallocate(units);
                }

                TEST_CASE_TEMPLATE("should set pointer's unit_count to 0 if unsuccessful", unit_p, types, volatiles)
                {
                    using heap_t = heap_t<unit_p>;
                    using unit_t = heap_t::unit_t;
                    using units_t = heap_t::units_t;

                    heap_t allocator;
                    pointer_t<unit_t> units = Random<units_t>();
                    count_t unit_count = heap_t::Max_Unit_Count();
                    allocator.Allocate(units, unit_count);
                    CHECK(units.unit_count == 0);

                    allocator.Deallocate(units);
                }

                TEST_CASE_TEMPLATE("should return true when successful", unit_p, types, volatiles)
                {
                    using heap_t = heap_t<unit_p>;
                    using unit_t = heap_t::unit_t;
                    using units_t = heap_t::units_t;

                    heap_t allocator;
                    pointer_t<unit_t> units;
                    count_t unit_count = Random<count_t>(1, 16);
                    CHECK(allocator.Allocate(units, unit_count) == true);

                    allocator.Deallocate(units);
                }

                TEST_CASE_TEMPLATE("should return false when unsuccessful", unit_p, types, volatiles)
                {
                    using heap_t = heap_t<unit_p>;
                    using unit_t = heap_t::unit_t;
                    using units_t = heap_t::units_t;

                    heap_t allocator;
                    pointer_t<unit_t> units;
                    count_t unit_count = heap_t::Max_Unit_Count();
                    CHECK(allocator.Allocate(units, unit_count) == false);

                    allocator.Deallocate(units);
                }
            }

            TEST_SUITE("Reallocate(units_t)")
            {
                TEST_CASE_TEMPLATE("should keep units as non-nullptr if successful", unit_p, types, volatiles)
                {
                    using heap_t = heap_t<unit_p>;
                    using unit_t = heap_t::unit_t;
                    using units_t = heap_t::units_t;

                    heap_t allocator;
                    units_t units = nullptr;
                    count_t unit_count = Random<count_t>(1, 16);
                    allocator.Allocate(units, unit_count);
                    count_t new_unit_count = Random<count_t>(17, 32);
                    allocator.Reallocate(units, new_unit_count);
                    CHECK(units != nullptr);

                    allocator.Deallocate(units);
                }

                TEST_CASE_TEMPLATE("should keep units as non-nullptr if unsuccessful", unit_p, types, volatiles)
                {
                    using heap_t = heap_t<unit_p>;
                    using unit_t = heap_t::unit_t;
                    using units_t = heap_t::units_t;

                    heap_t allocator;
                    units_t units = nullptr;
                    count_t unit_count = Random<count_t>(1, 16);
                    allocator.Allocate(units, unit_count);
                    count_t new_unit_count = heap_t::Max_Unit_Count();
                    allocator.Reallocate(units, new_unit_count);
                    CHECK(units != nullptr);

                    allocator.Deallocate(units);
                }

                TEST_CASE_TEMPLATE("should return true when successful", unit_p, types, volatiles)
                {
                    using heap_t = heap_t<unit_p>;
                    using unit_t = heap_t::unit_t;
                    using units_t = heap_t::units_t;

                    heap_t allocator;
                    units_t units = nullptr;
                    count_t unit_count = Random<count_t>(1, 16);
                    allocator.Allocate(units, unit_count);
                    count_t new_unit_count = Random<count_t>(17, 32);
                    CHECK(allocator.Reallocate(units, new_unit_count) == true);

                    allocator.Deallocate(units);
                }

                TEST_CASE_TEMPLATE("should return false when unsuccessful", unit_p, types, volatiles)
                {
                    using heap_t = heap_t<unit_p>;
                    using unit_t = heap_t::unit_t;
                    using units_t = heap_t::units_t;

                    heap_t allocator;
                    units_t units = nullptr;
                    count_t unit_count = Random<count_t>(1, 16);
                    allocator.Allocate(units, unit_count);
                    count_t new_unit_count = heap_t::Max_Unit_Count();
                    CHECK(allocator.Reallocate(units, new_unit_count) == false);

                    allocator.Deallocate(units);
                }
            }

            TEST_SUITE("Reallocate(pointer_t)")
            {
                TEST_CASE_TEMPLATE("should keep pointer's units as non-nullptr if successful", unit_p, types, volatiles)
                {
                    using heap_t = heap_t<unit_p>;
                    using unit_t = heap_t::unit_t;
                    using units_t = heap_t::units_t;

                    heap_t allocator;
                    pointer_t<unit_t> units;
                    count_t unit_count = Random<count_t>(1, 16);
                    allocator.Allocate(units, unit_count);
                    count_t new_unit_count = Random<count_t>(17, 32);
                    allocator.Reallocate(units, new_unit_count);
                    CHECK(units.units != nullptr);

                    allocator.Deallocate(units);
                }

                TEST_CASE_TEMPLATE("should set pointer's unit_count to new_unit_count if successful", unit_p, types, volatiles)
                {
                    using heap_t = heap_t<unit_p>;
                    using unit_t = heap_t::unit_t;
                    using units_t = heap_t::units_t;

                    heap_t allocator;
                    pointer_t<unit_t> units;
                    count_t unit_count = Random<count_t>(1, 16);
                    allocator.Allocate(units, unit_count);
                    count_t new_unit_count = Random<count_t>(17, 32);
                    allocator.Reallocate(units, new_unit_count);
                    CHECK(units.unit_count == new_unit_count);

                    allocator.Deallocate(units);
                }

                TEST_CASE_TEMPLATE("should keep pointer's units as non-nullptr if unsuccessful", unit_p, types, volatiles)
                {
                    using heap_t = heap_t<unit_p>;
                    using unit_t = heap_t::unit_t;
                    using units_t = heap_t::units_t;

                    heap_t allocator;
                    pointer_t<unit_t> units;
                    count_t unit_count = Random<count_t>(1, 16);
                    allocator.Allocate(units, unit_count);
                    count_t new_unit_count = heap_t::Max_Unit_Count();
                    allocator.Reallocate(units, new_unit_count);
                    CHECK(units.units != nullptr);

                    allocator.Deallocate(units);
                }

                TEST_CASE_TEMPLATE("should keep pointer's unit_count as unit_count if unsuccessful", unit_p, types, volatiles)
                {
                    using heap_t = heap_t<unit_p>;
                    using unit_t = heap_t::unit_t;
                    using units_t = heap_t::units_t;

                    heap_t allocator;
                    pointer_t<unit_t> units;
                    count_t unit_count = Random<count_t>(1, 16);
                    allocator.Allocate(units, unit_count);
                    count_t new_unit_count = heap_t::Max_Unit_Count();
                    allocator.Reallocate(units, new_unit_count);
                    CHECK(units.unit_count == unit_count);

                    allocator.Deallocate(units);
                }

                TEST_CASE_TEMPLATE("should return true when successful", unit_p, types, volatiles)
                {
                    using heap_t = heap_t<unit_p>;
                    using unit_t = heap_t::unit_t;
                    using units_t = heap_t::units_t;

                    heap_t allocator;
                    pointer_t<unit_t> units;
                    count_t unit_count = Random<count_t>(1, 16);
                    allocator.Allocate(units, unit_count);
                    count_t new_unit_count = Random<count_t>(17, 32);
                    CHECK(allocator.Reallocate(units, new_unit_count) == true);

                    allocator.Deallocate(units);
                }

                TEST_CASE_TEMPLATE("should return false when unsuccessful", unit_p, types, volatiles)
                {
                    using heap_t = heap_t<unit_p>;
                    using unit_t = heap_t::unit_t;
                    using units_t = heap_t::units_t;

                    heap_t allocator;
                    pointer_t<unit_t> units;
                    count_t unit_count = Random<count_t>(1, 16);
                    allocator.Allocate(units, unit_count);
                    count_t new_unit_count = heap_t::Max_Unit_Count();
                    CHECK(allocator.Reallocate(units, new_unit_count) == false);

                    allocator.Deallocate(units);
                }
            }

            TEST_SUITE("Deallocate(units_t)")
            {
                TEST_CASE_TEMPLATE("should set units to nullptr", unit_p, types, volatiles)
                {
                    using heap_t = heap_t<unit_p>;
                    using unit_t = heap_t::unit_t;
                    using units_t = heap_t::units_t;

                    heap_t allocator;
                    units_t units = nullptr;
                    count_t unit_count = Random<count_t>(1, 16);
                    allocator.Allocate(units, unit_count);
                    allocator.Deallocate(units);
                    CHECK(units == nullptr);
                }

                TEST_CASE_TEMPLATE("should keep units as nullptr if already nullptr", unit_p, types, volatiles)
                {
                    using heap_t = heap_t<unit_p>;
                    using unit_t = heap_t::unit_t;
                    using units_t = heap_t::units_t;

                    heap_t allocator;
                    units_t units = nullptr;
                    allocator.Deallocate(units);
                    CHECK(units == nullptr);
                }
            }

            TEST_SUITE("Deallocate(pointer_t)")
            {
                TEST_CASE_TEMPLATE("should set pointer's units to nullptr", unit_p, types, volatiles)
                {
                    using heap_t = heap_t<unit_p>;
                    using unit_t = heap_t::unit_t;
                    using units_t = heap_t::units_t;

                    heap_t allocator;
                    pointer_t<unit_t> units = nullptr;
                    count_t unit_count = Random<count_t>(1, 16);
                    allocator.Allocate(units, unit_count);
                    allocator.Deallocate(units);
                    CHECK(units.units == nullptr);
                }

                TEST_CASE_TEMPLATE("should set pointer's unit_count to 0", unit_p, types, volatiles)
                {
                    using heap_t = heap_t<unit_p>;
                    using unit_t = heap_t::unit_t;
                    using units_t = heap_t::units_t;

                    heap_t allocator;
                    pointer_t<unit_t> units = nullptr;
                    count_t unit_count = Random<count_t>(1, 16);
                    allocator.Allocate(units, unit_count);
                    allocator.Deallocate(units);
                    CHECK(units.unit_count == 0);
                }

                TEST_CASE_TEMPLATE("should keep pointer's units as nullptr if already nullptr", unit_p, types, volatiles)
                {
                    using heap_t = heap_t<unit_p>;
                    using unit_t = heap_t::unit_t;
                    using units_t = heap_t::units_t;

                    heap_t allocator;
                    pointer_t<unit_t> units = nullptr;
                    allocator.Deallocate(units);
                    CHECK(units.units == nullptr);
                }

                TEST_CASE_TEMPLATE("should keep pointer's unit_count as 0 if already nullptr", unit_p, types, volatiles)
                {
                    using heap_t = heap_t<unit_p>;
                    using unit_t = heap_t::unit_t;
                    using units_t = heap_t::units_t;

                    heap_t allocator;
                    pointer_t<unit_t> units = nullptr;
                    allocator.Deallocate(units);
                    CHECK(units.unit_count == 0);
                }
            }
        }

    #undef types
    #undef consts
    #undef volatiles
    #undef volatile_consts
    }

}}
