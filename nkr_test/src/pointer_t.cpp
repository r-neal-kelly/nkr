/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/bool_t.h"
#include "nkr/pointer_t.h"

#include "intrinsics.h"

namespace nkr {

    TEST_SUITE("pointer_t<unit_p>")
    {
    #define types   \
        void_t,     \
        bool_t,     \
        std_bool_t, \
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

    #define consts          \
        const void_t,       \
        const bool_t,       \
        const std_bool_t,   \
        const u8_t,         \
        const s8_t,         \
        const u16_t,        \
        const s16_t,        \
        const u32_t,        \
        const s32_t,        \
        const u64_t,        \
        const s64_t,        \
        const r32_t,        \
        const r64_t

    #define volatiles           \
        volatile void_t,        \
        volatile bool_t,        \
        volatile std_bool_t,    \
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

    #define volatile_consts         \
        volatile const void_t,      \
        volatile const bool_t,      \
        volatile const std_bool_t,  \
        volatile const u8_t,        \
        volatile const s8_t,        \
        volatile const u16_t,       \
        volatile const s16_t,       \
        volatile const u32_t,       \
        volatile const s32_t,       \
        volatile const u64_t,       \
        volatile const s64_t,       \
        volatile const r32_t,       \
        volatile const r64_t

        TEST_SUITE("aliases")
        {
            TEST_SUITE("unit_t")
            {
                TEST_CASE_TEMPLATE("should equal unit_p", unit_p, types, consts, volatiles, volatile_consts)
                {
                    static_assert(std::same_as<pointer_t<unit_p>::unit_t, unit_p>);
                }
            }
        }

        TEST_SUITE("object data")
        {
            TEST_SUITE("units")
            {
                TEST_CASE_TEMPLATE("should be a unit_p*", unit_p, types, consts, volatiles, volatile_consts)
                {
                    static_assert(std::same_as<decltype(pointer_t<unit_p>::units), unit_p*>);
                }
            }

            TEST_SUITE("unit_count")
            {
                TEST_CASE_TEMPLATE("should be a count_t", unit_p, types, consts, volatiles, volatile_consts)
                {
                    static_assert(std::same_as<decltype(pointer_t<unit_p>::unit_count), count_t>);
                }
            }
        }

        TEST_SUITE("objects")
        {
            TEST_SUITE("default_ctor()")
            {
                TEST_CASE_TEMPLATE("should set units to nullptr", unit_p, types, consts, volatiles, volatile_consts)
                {
                    pointer_t<unit_p> pointer;
                    CHECK(pointer.Units() == nullptr);
                }

                TEST_CASE_TEMPLATE("should set unit_count to 0", unit_p, types, consts, volatiles, volatile_consts)
                {
                    pointer_t<unit_p> pointer;
                    CHECK(pointer.Unit_Count() == 0);
                }
            }

            TEST_SUITE("unit_ctor()")
            {
                TEST_CASE_TEMPLATE("should explicitly set passed unit", unit_p, types, consts, volatiles, volatile_consts)
                {
                    unit_p* unit = Random<unit_p*>();
                    pointer_t<unit_p> pointer(unit);
                    CHECK(pointer.Units() == unit);
                }

                TEST_CASE_TEMPLATE("should implicitly set passed unit", unit_p, types, consts, volatiles, volatile_consts)
                {
                    unit_p* unit = Random<unit_p*>();
                    pointer_t<unit_p> pointer = unit;
                    CHECK(pointer.Units() == unit);
                }

                TEST_CASE("should convert and set passed unit")
                {
                    struct base_t {};
                    struct derived_t : base_t {};

                    derived_t* unit = Random<derived_t*>();
                    pointer_t<base_t> pointer(unit);
                    CHECK(pointer.Units() == static_cast<base_t*>(unit));
                }

                TEST_CASE_TEMPLATE("should set unit_count to 0 if passed nullptr", unit_p, types, consts, volatiles, volatile_consts)
                {
                    pointer_t<unit_p> pointer(nullptr);
                    CHECK(pointer.Unit_Count() == 0);
                }

                TEST_CASE_TEMPLATE("should set unit_count to 1 if passed non-nullptr", unit_p, types, consts, volatiles, volatile_consts)
                {
                    unit_p* unit;
                    do {
                        unit = Random<unit_p*>();
                    } while (unit == nullptr);
                    pointer_t<unit_p> pointer(unit);
                    CHECK(pointer.Unit_Count() == 1);
                }
            }

            TEST_SUITE("units_ctor()")
            {
                TEST_CASE_TEMPLATE("should explicitly set passed units and unit_count", unit_p, types, consts, volatiles, volatile_consts)
                {
                    unit_p* units;
                    do {
                        units = Random<unit_p*>();
                    } while (units == nullptr);
                    count_t unit_count;
                    do {
                        unit_count = Random<count_t>();
                    } while (unit_count == 0);
                    pointer_t<unit_p> pointer(units, unit_count);
                    CHECK(pointer.Units() == units);
                    CHECK(pointer.Unit_Count() == unit_count);
                }

                TEST_CASE_TEMPLATE("should implicitly set passed units and unit_count", unit_p, types, consts, volatiles, volatile_consts)
                {
                    unit_p* units;
                    do {
                        units = Random<unit_p*>();
                    } while (units == nullptr);
                    count_t unit_count;
                    do {
                        unit_count = Random<count_t>();
                    } while (unit_count == 0);
                    pointer_t<unit_p> pointer = { units, unit_count };
                    CHECK(pointer.Units() == units);
                    CHECK(pointer.Unit_Count() == unit_count);
                }

                TEST_CASE("should convert and set passed units")
                {
                    struct base_t {};
                    struct derived_t : base_t {};

                    derived_t* units;
                    do {
                        units = Random<derived_t*>();
                    } while (units == nullptr);
                    count_t unit_count;
                    do {
                        unit_count = Random<count_t>();
                    } while (unit_count == 0);
                    pointer_t<base_t> pointer(units, unit_count);
                    CHECK(pointer.Units() == static_cast<base_t*>(units));
                    CHECK(pointer.Unit_Count() == unit_count);
                }

                TEST_CASE_TEMPLATE("should allow a nullptr units and a 0 unit_count", unit_p, types, consts, volatiles, volatile_consts)
                {
                    pointer_t<unit_p> pointer(nullptr, 0);
                    CHECK(pointer.Units() == nullptr);
                    CHECK(pointer.Unit_Count() == 0);
                }
            }

            TEST_SUITE("copy_ctor()")
            {
                TEST_CASE_TEMPLATE("should explicitly copy the units and unit_count of other", unit_p, types, consts, volatiles, volatile_consts)
                {
                    unit_p* unit = Random<unit_p*>();
                    const pointer_t<unit_p> other(unit);
                    pointer_t<unit_p> pointer(other);
                    CHECK(pointer.Units() == unit);
                    CHECK(pointer.Unit_Count() == 1);
                }

                TEST_CASE_TEMPLATE("should implicitly copy the units and unit_count of other", unit_p, types, consts, volatiles, volatile_consts)
                {
                    unit_p* unit = Random<unit_p*>();
                    const pointer_t<unit_p> other(unit);
                    pointer_t<unit_p> pointer = other;
                    CHECK(pointer.Units() == unit);
                    CHECK(pointer.Unit_Count() == 1);
                }

                TEST_CASE_TEMPLATE("should not alter the units or unit_count of other", unit_p, types, consts, volatiles, volatile_consts)
                {
                    unit_p* unit = Random<unit_p*>();
                    const pointer_t<unit_p> other(unit);
                    pointer_t<unit_p> pointer(other);
                    CHECK(other.Units() == unit);
                    CHECK(other.Unit_Count() == 1);
                }
            }

            TEST_SUITE("move_ctor()")
            {
                TEST_CASE_TEMPLATE("should explicitly move the units and unit_count of other", unit_p, types, consts, volatiles, volatile_consts)
                {
                    unit_p* unit = Random<unit_p*>();
                    pointer_t<unit_p> other(unit);
                    pointer_t<unit_p> pointer(std::move(other));
                    CHECK(pointer.Units() == unit);
                    CHECK(pointer.Unit_Count() == 1);
                }

                TEST_CASE_TEMPLATE("should implicitly move the units and unit_count of other", unit_p, types, consts, volatiles, volatile_consts)
                {
                    unit_p* unit = Random<unit_p*>();
                    pointer_t<unit_p> other(unit);
                    pointer_t<unit_p> pointer = std::move(other);
                    CHECK(pointer.Units() == unit);
                    CHECK(pointer.Unit_Count() == 1);
                }

                TEST_CASE_TEMPLATE("should set the units and unit_count of other to the defaults", unit_p, types, consts, volatiles, volatile_consts)
                {
                    unit_p* unit = Random<unit_p*>();
                    pointer_t<unit_p> other(unit);
                    pointer_t<unit_p> pointer(std::move(other));
                    CHECK(other.Units() == nullptr);
                    CHECK(other.Unit_Count() == 0);
                }
            }

            TEST_SUITE("unit_assignment_ctor()")
            {
                TEST_CASE_TEMPLATE("should set passed unit", unit_p, types, consts, volatiles, volatile_consts)
                {
                    unit_p* unit = Random<unit_p*>();
                    pointer_t<unit_p> pointer;
                    pointer = unit;
                    CHECK(pointer.Units() == unit);
                }

                TEST_CASE_TEMPLATE("should return itself", unit_p, types, consts, volatiles, volatile_consts)
                {
                    unit_p* unit = Random<unit_p*>();
                    pointer_t<unit_p> pointer;
                    CHECK(&(pointer = unit) == &pointer);
                }

                TEST_CASE("should convert and set passed unit")
                {
                    struct base_t {};
                    struct derived_t : base_t {};

                    derived_t* unit = Random<derived_t*>();
                    pointer_t<base_t> pointer;
                    pointer = unit;
                    CHECK(pointer.Units() == static_cast<base_t*>(unit));
                }

                TEST_CASE_TEMPLATE("should set unit_count to 0 if passed nullptr", unit_p, types, consts, volatiles, volatile_consts)
                {
                    pointer_t<unit_p> pointer;
                    pointer = nullptr;
                    CHECK(pointer.Unit_Count() == 0);
                }

                TEST_CASE_TEMPLATE("should set unit_count to 1 if passed non-nullptr", unit_p, types, consts, volatiles, volatile_consts)
                {
                    unit_p* unit;
                    do {
                        unit = Random<unit_p*>();
                    } while (unit == nullptr);
                    pointer_t<unit_p> pointer;
                    pointer = unit;
                    CHECK(pointer.Unit_Count() == 1);
                }
            }

            TEST_SUITE("copy_assignment_ctor()")
            {
                TEST_CASE_TEMPLATE("should copy the units and unit_count of other", unit_p, types, consts, volatiles, volatile_consts)
                {
                    unit_p* unit = Random<unit_p*>();
                    const pointer_t<unit_p> other(unit);
                    pointer_t<unit_p> pointer;
                    pointer = other;
                    CHECK(pointer.Units() == unit);
                    CHECK(pointer.Unit_Count() == 1);
                }

                TEST_CASE_TEMPLATE("should return itself", unit_p, types, consts, volatiles, volatile_consts)
                {
                    unit_p* unit = Random<unit_p*>();
                    const pointer_t<unit_p> other(unit);
                    pointer_t<unit_p> pointer;
                    CHECK(&(pointer = other) == &pointer);
                }

                TEST_CASE_TEMPLATE("should not alter the units or unit_count of other", unit_p, types, consts, volatiles, volatile_consts)
                {
                    unit_p* unit = Random<unit_p*>();
                    const pointer_t<unit_p> other(unit);
                    pointer_t<unit_p> pointer;
                    pointer = other;
                    CHECK(other.Units() == unit);
                    CHECK(other.Unit_Count() == 1);
                }
            }

            TEST_SUITE("move_assignment_ctor()")
            {
                TEST_CASE_TEMPLATE("should move the units and unit_count of other", unit_p, types, consts, volatiles, volatile_consts)
                {
                    unit_p* unit = Random<unit_p*>();
                    pointer_t<unit_p> other(unit);
                    pointer_t<unit_p> pointer;
                    pointer = std::move(other);
                    CHECK(pointer.Units() == unit);
                    CHECK(pointer.Unit_Count() == 1);
                }

                TEST_CASE_TEMPLATE("should return itself", unit_p, types, consts, volatiles, volatile_consts)
                {
                    unit_p* unit = Random<unit_p*>();
                    pointer_t<unit_p> other(unit);
                    pointer_t<unit_p> pointer;
                    CHECK(&(pointer = std::move(other)) == &pointer);
                }

                TEST_CASE_TEMPLATE("should set the units and unit_count of other to the defaults", unit_p, types, consts, volatiles, volatile_consts)
                {
                    unit_p* unit = Random<unit_p*>();
                    pointer_t<unit_p> other(unit);
                    pointer_t<unit_p> pointer;
                    pointer = std::move(other);
                    CHECK(other.Units() == nullptr);
                    CHECK(other.Unit_Count() == 0);
                }
            }

            TEST_SUITE("dtor()")
            {
                TEST_CASE_TEMPLATE("should set the units and unit_count to the defaults", unit_p, types, consts, volatiles, volatile_consts)
                {
                    unit_p* units;
                    do {
                        units = Random<unit_p*>();
                    } while (units == nullptr);
                    count_t unit_count;
                    do {
                        unit_count = Random<count_t>();
                    } while (unit_count == 0);
                    pointer_t<unit_p> pointer(units, unit_count);
                    pointer.~pointer_t();
                    CHECK(pointer.Units() == nullptr);
                    CHECK(pointer.Unit_Count() == 0);
                }
            }
        }

        TEST_SUITE("methods")
        {
            TEST_SUITE("Units()")
            {
                TEST_CASE_TEMPLATE("should return the units", unit_p, types, consts, volatiles, volatile_consts)
                {
                    unit_p* unit = Random<unit_p*>();
                    pointer_t<unit_p> pointer(unit);
                    CHECK(pointer.Units() == unit);
                }

                TEST_CASE_TEMPLATE("should not change the units", unit_p, types, consts, volatiles, volatile_consts)
                {
                    unit_p* unit = Random<unit_p*>();
                    pointer_t<unit_p> pointer(unit);
                    pointer.Units();
                    CHECK(pointer.Units() == unit);
                }
            }

            TEST_SUITE("Unit_Count()")
            {
                TEST_CASE_TEMPLATE("should return the unit_count", unit_p, types, consts, volatiles, volatile_consts)
                {
                    unit_p* unit = Random<unit_p*>();
                    pointer_t<unit_p> pointer(unit);
                    CHECK(pointer.Unit_Count() == 1);
                }

                TEST_CASE_TEMPLATE("should not change the unit_count", unit_p, types, consts, volatiles, volatile_consts)
                {
                    unit_p* unit = Random<unit_p*>();
                    pointer_t<unit_p> pointer(unit);
                    pointer.Unit_Count();
                    CHECK(pointer.Unit_Count() == 1);
                }
            }
        }

        TEST_SUITE("casts")
        {
            TEST_SUITE("unit_t*()")
            {
                TEST_CASE_TEMPLATE("should explicitly return a copy of the units", unit_p, types, consts, volatiles, volatile_consts)
                {
                    unit_p* unit = Random<unit_p*>();
                    const pointer_t<unit_p> pointer(unit);
                    unit_p* cast = static_cast<unit_p*>(pointer);
                    CHECK(cast == unit);
                }

                TEST_CASE_TEMPLATE("should implicitly return a copy of the units", unit_p, types, consts, volatiles, volatile_consts)
                {
                    unit_p* unit = Random<unit_p*>();
                    const pointer_t<unit_p> pointer(unit);
                    unit_p* cast = pointer;
                    CHECK(cast == unit);
                }

                TEST_CASE_TEMPLATE("should not change the units", unit_p, types, consts, volatiles, volatile_consts)
                {
                    unit_p* unit = Random<unit_p*>();
                    const pointer_t<unit_p> pointer(unit);
                    unit_p* cast = static_cast<unit_p*>(pointer);
                    CHECK(pointer.Units() == unit);
                }

                TEST_CASE_TEMPLATE("should implicitly allow for logical operators", unit_p, types, consts, volatiles, volatile_consts)
                {
                    unit_p* unit;
                    do {
                        unit = Random<unit_p*>();
                    } while (unit == nullptr);
                    const pointer_t<unit_p> pointer(unit);
                    CHECK(pointer);
                    CHECK(!!pointer);
                    CHECK(pointer || false);
                    CHECK(pointer && true);
                    CHECK(pointer ? true : false);
                }

                TEST_CASE_TEMPLATE("should implicitly allow for comparison operators", unit_p, types, consts, volatiles, volatile_consts)
                {
                    unit_p* unit = Random<unit_p*>();
                    const pointer_t<unit_p> pointer(unit);
                    CHECK(pointer == unit);
                    CHECK_FALSE(pointer != unit);
                    CHECK_FALSE(pointer < unit);
                    CHECK_FALSE(pointer > unit);
                    CHECK(pointer <= unit);
                    CHECK(pointer >= unit);
                    CHECK((pointer <=> unit == 0));
                }
            }
        }

        TEST_SUITE("operators")
        {
            TEST_SUITE("()()")
            {

            }

            TEST_SUITE("()(unit_t*)")
            {

            }

            TEST_SUITE("()(unit_t*, count_t)")
            {

            }

            TEST_SUITE("+()")
            {

            }

            TEST_SUITE("-()")
            {

            }

            TEST_SUITE("+=()")
            {

            }

            TEST_SUITE("-=()")
            {

            }

            TEST_SUITE("++()")
            {

            }

            TEST_SUITE("++(int)")
            {

            }

            TEST_SUITE("--()")
            {

            }

            TEST_SUITE("--(int)")
            {

            }

            TEST_SUITE("->()")
            {

            }

            TEST_SUITE("*()")
            {

            }

            TEST_SUITE("[]()")
            {

            }
        }

    #undef types
    #undef consts
    #undef volatiles
    #undef volatile_consts
    }

}
