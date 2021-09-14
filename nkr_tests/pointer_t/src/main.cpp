/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/intrinsics.h"
#include "nkr/pointer_t.h"
#include "nkr/random.h"

#include "doctest.h"

namespace nkr {

    TEST_SUITE("pointer_t<unit_p>")
    {
    #define types   \
        void_t,     \
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

    #define consts          \
        const void_t,       \
        const std_bool_t,   \
        const bool_t,       \
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

    #define volatile_consts         \
        volatile const void_t,      \
        volatile const std_bool_t,  \
        volatile const bool_t,      \
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

            TEST_SUITE("units_t")
            {
                TEST_CASE_TEMPLATE("should equal unit_p*", unit_p, types, consts, volatiles, volatile_consts)
                {
                    static_assert(std::same_as<pointer_t<unit_p>::units_t, unit_p*>);
                }
            }
        }

        TEST_SUITE("static operators")
        {
            TEST_SUITE("==()")
            {
                TEST_CASE_TEMPLATE("should return true if units and unit_count are the same as other", unit_p, types, consts, volatiles, volatile_consts)
                {
                    unit_p* units = Random<unit_p*>();
                    count_t unit_count = Random<count_t>();
                    pointer_t<unit_p> other(units, unit_count);
                    pointer_t<unit_p> pointer(units, unit_count);
                    CHECK_TRUE(pointer == other);
                }

                TEST_CASE_TEMPLATE("should return false if units is different from other", unit_p, types, consts, volatiles, volatile_consts)
                {
                    unit_p* units;
                    do {
                        units = Random<unit_p*>();
                    } while (units == nullptr);
                    count_t unit_count = Random<count_t>();
                    pointer_t<unit_p> other(nullptr, unit_count);
                    pointer_t<unit_p> pointer(units, unit_count);
                    CHECK_FALSE(pointer == other);
                }

                TEST_CASE_TEMPLATE("should return false if unit_count is different from other", unit_p, types, consts, volatiles, volatile_consts)
                {
                    unit_p* units = Random<unit_p*>();
                    count_t unit_count;
                    do {
                        unit_count = Random<count_t>();
                    } while (unit_count == 0);
                    pointer_t<unit_p> other(units, 0);
                    pointer_t<unit_p> pointer(units, unit_count);
                    CHECK_FALSE(pointer == other);
                }

                TEST_CASE_TEMPLATE("should work with any combination of qualified types", unit_p, types, consts, volatiles, volatile_consts)
                {
                    pointer_t<unit_p> a;
                    volatile pointer_t<unit_p> b;
                    volatile const pointer_t<unit_p> c;
                    pointer_t<unit_p>& d = a;
                    volatile pointer_t<unit_p>& e = b;
                    volatile const pointer_t<unit_p>& f = c;

                    CHECK_TRUE(a == b);
                    CHECK_TRUE(a == c);
                    CHECK_TRUE(a == d);
                    CHECK_TRUE(a == e);
                    CHECK_TRUE(a == f);

                    CHECK_TRUE(b == a);
                    CHECK_TRUE(b == c);
                    CHECK_TRUE(b == d);
                    CHECK_TRUE(b == e);
                    CHECK_TRUE(b == f);

                    CHECK_TRUE(c == a);
                    CHECK_TRUE(c == b);
                    CHECK_TRUE(c == d);
                    CHECK_TRUE(c == e);
                    CHECK_TRUE(c == f);

                    CHECK_TRUE(d == a);
                    CHECK_TRUE(d == b);
                    CHECK_TRUE(d == c);
                    CHECK_TRUE(d == e);
                    CHECK_TRUE(d == f);

                    CHECK_TRUE(e == a);
                    CHECK_TRUE(e == b);
                    CHECK_TRUE(e == c);
                    CHECK_TRUE(e == d);
                    CHECK_TRUE(e == f);

                    CHECK_TRUE(f == a);
                    CHECK_TRUE(f == b);
                    CHECK_TRUE(f == c);
                    CHECK_TRUE(f == d);
                    CHECK_TRUE(f == e);

                    CHECK_TRUE(a == pointer_t<unit_p>());
                    CHECK_TRUE(b == pointer_t<unit_p>());
                    CHECK_TRUE(c == pointer_t<unit_p>());
                    CHECK_TRUE(d == pointer_t<unit_p>());
                    CHECK_TRUE(e == pointer_t<unit_p>());
                    CHECK_TRUE(f == pointer_t<unit_p>());

                    CHECK_TRUE(pointer_t<unit_p>() == a);
                    CHECK_TRUE(pointer_t<unit_p>() == b);
                    CHECK_TRUE(pointer_t<unit_p>() == c);
                    CHECK_TRUE(pointer_t<unit_p>() == d);
                    CHECK_TRUE(pointer_t<unit_p>() == e);
                    CHECK_TRUE(pointer_t<unit_p>() == f);
                }
            }

            TEST_SUITE("!=()")
            {
                TEST_CASE_TEMPLATE("should return false if units and unit_count are the same as other", unit_p, types, consts, volatiles, volatile_consts)
                {
                    unit_p* units = Random<unit_p*>();
                    count_t unit_count = Random<count_t>();
                    pointer_t<unit_p> other(units, unit_count);
                    pointer_t<unit_p> pointer(units, unit_count);
                    CHECK_FALSE(pointer != other);
                }

                TEST_CASE_TEMPLATE("should return true if units is different from other", unit_p, types, consts, volatiles, volatile_consts)
                {
                    unit_p* units;
                    do {
                        units = Random<unit_p*>();
                    } while (units == nullptr);
                    count_t unit_count = Random<count_t>();
                    pointer_t<unit_p> other(nullptr, unit_count);
                    pointer_t<unit_p> pointer(units, unit_count);
                    CHECK_TRUE(pointer != other);
                }

                TEST_CASE_TEMPLATE("should return true if unit_count is different from other", unit_p, types, consts, volatiles, volatile_consts)
                {
                    unit_p* units = Random<unit_p*>();
                    count_t unit_count;
                    do {
                        unit_count = Random<count_t>();
                    } while (unit_count == 0);
                    pointer_t<unit_p> other(units, 0);
                    pointer_t<unit_p> pointer(units, unit_count);
                    CHECK_TRUE(pointer != other);
                }

                TEST_CASE_TEMPLATE("should work with any combination of qualified types", unit_p, types, consts, volatiles, volatile_consts)
                {
                    pointer_t<unit_p> a;
                    volatile pointer_t<unit_p> b;
                    volatile const pointer_t<unit_p> c;
                    pointer_t<unit_p>& d = a;
                    volatile pointer_t<unit_p>& e = b;
                    volatile const pointer_t<unit_p>& f = c;

                    CHECK_FALSE(a != b);
                    CHECK_FALSE(a != c);
                    CHECK_FALSE(a != d);
                    CHECK_FALSE(a != e);
                    CHECK_FALSE(a != f);

                    CHECK_FALSE(b != a);
                    CHECK_FALSE(b != c);
                    CHECK_FALSE(b != d);
                    CHECK_FALSE(b != e);
                    CHECK_FALSE(b != f);

                    CHECK_FALSE(c != a);
                    CHECK_FALSE(c != b);
                    CHECK_FALSE(c != d);
                    CHECK_FALSE(c != e);
                    CHECK_FALSE(c != f);

                    CHECK_FALSE(d != a);
                    CHECK_FALSE(d != b);
                    CHECK_FALSE(d != c);
                    CHECK_FALSE(d != e);
                    CHECK_FALSE(d != f);

                    CHECK_FALSE(e != a);
                    CHECK_FALSE(e != b);
                    CHECK_FALSE(e != c);
                    CHECK_FALSE(e != d);
                    CHECK_FALSE(e != f);

                    CHECK_FALSE(f != a);
                    CHECK_FALSE(f != b);
                    CHECK_FALSE(f != c);
                    CHECK_FALSE(f != d);
                    CHECK_FALSE(f != e);

                    CHECK_FALSE(a != pointer_t<unit_p>());
                    CHECK_FALSE(b != pointer_t<unit_p>());
                    CHECK_FALSE(c != pointer_t<unit_p>());
                    CHECK_FALSE(d != pointer_t<unit_p>());
                    CHECK_FALSE(e != pointer_t<unit_p>());
                    CHECK_FALSE(f != pointer_t<unit_p>());

                    CHECK_FALSE(pointer_t<unit_p>() != a);
                    CHECK_FALSE(pointer_t<unit_p>() != b);
                    CHECK_FALSE(pointer_t<unit_p>() != c);
                    CHECK_FALSE(pointer_t<unit_p>() != d);
                    CHECK_FALSE(pointer_t<unit_p>() != e);
                    CHECK_FALSE(pointer_t<unit_p>() != f);
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
                    CHECK(pointer.units == nullptr);
                }

                TEST_CASE_TEMPLATE("should set unit_count to 0", unit_p, types, consts, volatiles, volatile_consts)
                {
                    pointer_t<unit_p> pointer;
                    CHECK(pointer.unit_count == 0);
                }
            }

            TEST_SUITE("unit_ctor()")
            {
                TEST_CASE_TEMPLATE("should explicitly set passed unit", unit_p, types, consts, volatiles, volatile_consts)
                {
                    unit_p* unit = Random<unit_p*>();
                    pointer_t<unit_p> pointer(unit);
                    CHECK(pointer.units == unit);
                }

                TEST_CASE_TEMPLATE("should implicitly set passed unit", unit_p, types, consts, volatiles, volatile_consts)
                {
                    unit_p* unit = Random<unit_p*>();
                    pointer_t<unit_p> pointer = unit;
                    CHECK(pointer.units == unit);
                }

                TEST_CASE("should convert and set passed unit")
                {
                    struct base_t {};
                    struct derived_t : base_t {};

                    derived_t* unit = Random<derived_t*>();
                    pointer_t<base_t> pointer(unit);
                    CHECK(pointer.units == static_cast<base_t*>(unit));
                }

                TEST_CASE_TEMPLATE("should set unit_count to 0 if passed nullptr", unit_p, types, consts, volatiles, volatile_consts)
                {
                    pointer_t<unit_p> pointer(nullptr);
                    CHECK(pointer.unit_count == 0);
                }

                TEST_CASE_TEMPLATE("should set unit_count to 1 if passed non-nullptr", unit_p, types, consts, volatiles, volatile_consts)
                {
                    unit_p* unit;
                    do {
                        unit = Random<unit_p*>();
                    } while (unit == nullptr);
                    pointer_t<unit_p> pointer(unit);
                    CHECK(pointer.unit_count == 1);
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
                    CHECK(pointer.units == units);
                    CHECK(pointer.unit_count == unit_count);
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
                    CHECK(pointer.units == units);
                    CHECK(pointer.unit_count == unit_count);
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
                    CHECK(pointer.units == static_cast<base_t*>(units));
                    CHECK(pointer.unit_count == unit_count);
                }

                TEST_CASE_TEMPLATE("should allow a nullptr units and a 0 unit_count", unit_p, types, consts, volatiles, volatile_consts)
                {
                    pointer_t<unit_p> pointer(nullptr, 0);
                    CHECK(pointer.units == nullptr);
                    CHECK(pointer.unit_count == 0);
                }
            }

            TEST_SUITE("copy_ctor()")
            {
                TEST_CASE_TEMPLATE("should explicitly copy the units and unit_count of other", unit_p, types, consts, volatiles, volatile_consts)
                {
                    unit_p* unit = Random<unit_p*>();
                    const pointer_t<unit_p> other(unit);
                    pointer_t<unit_p> pointer(other);
                    CHECK(pointer.units == unit);
                    CHECK(pointer.unit_count == 1);
                }

                TEST_CASE_TEMPLATE("should implicitly copy the units and unit_count of other", unit_p, types, consts, volatiles, volatile_consts)
                {
                    unit_p* unit = Random<unit_p*>();
                    const pointer_t<unit_p> other(unit);
                    pointer_t<unit_p> pointer = other;
                    CHECK(pointer.units == unit);
                    CHECK(pointer.unit_count == 1);
                }

                TEST_CASE_TEMPLATE("should not alter the units or unit_count of other", unit_p, types, consts, volatiles, volatile_consts)
                {
                    unit_p* unit = Random<unit_p*>();
                    const pointer_t<unit_p> other(unit);
                    pointer_t<unit_p> pointer(other);
                    CHECK(other.units == unit);
                    CHECK(other.unit_count == 1);
                }

                TEST_CASE_TEMPLATE("should explicitly copy the units and unit_count of volatile other", unit_p, types, consts, volatiles, volatile_consts)
                {
                    unit_p* unit = Random<unit_p*>();
                    volatile const pointer_t<unit_p> other(unit);
                    pointer_t<unit_p> pointer(other);
                    CHECK(pointer.units == unit);
                    CHECK(pointer.unit_count == 1);
                }

                TEST_CASE_TEMPLATE("should implicitly copy the units and unit_count of volatile other", unit_p, types, consts, volatiles, volatile_consts)
                {
                    unit_p* unit = Random<unit_p*>();
                    volatile const pointer_t<unit_p> other(unit);
                    pointer_t<unit_p> pointer = other;
                    CHECK(pointer.units == unit);
                    CHECK(pointer.unit_count == 1);
                }

                TEST_CASE_TEMPLATE("should not alter the units or unit_count of volatile other", unit_p, types, consts, volatiles, volatile_consts)
                {
                    unit_p* unit = Random<unit_p*>();
                    volatile const pointer_t<unit_p> other(unit);
                    pointer_t<unit_p> pointer(other);
                    CHECK(other.units == unit);
                    CHECK(other.unit_count == 1);
                }
            }

            TEST_SUITE("move_ctor()")
            {
                TEST_CASE_TEMPLATE("should explicitly move the units and unit_count of other", unit_p, types, consts, volatiles, volatile_consts)
                {
                    unit_p* unit = Random<unit_p*>();
                    pointer_t<unit_p> other(unit);
                    pointer_t<unit_p> pointer(std::move(other));
                    CHECK(pointer.units == unit);
                    CHECK(pointer.unit_count == 1);
                }

                TEST_CASE_TEMPLATE("should implicitly move the units and unit_count of other", unit_p, types, consts, volatiles, volatile_consts)
                {
                    unit_p* unit = Random<unit_p*>();
                    pointer_t<unit_p> other(unit);
                    pointer_t<unit_p> pointer = std::move(other);
                    CHECK(pointer.units == unit);
                    CHECK(pointer.unit_count == 1);
                }

                TEST_CASE_TEMPLATE("should set the units and unit_count of other to the defaults", unit_p, types, consts, volatiles, volatile_consts)
                {
                    unit_p* unit = Random<unit_p*>();
                    pointer_t<unit_p> other(unit);
                    pointer_t<unit_p> pointer(std::move(other));
                    CHECK(other.units == nullptr);
                    CHECK(other.unit_count == 0);
                }

                TEST_CASE_TEMPLATE("should explicitly move the units and unit_count of volatile other", unit_p, types, consts, volatiles, volatile_consts)
                {
                    unit_p* unit = Random<unit_p*>();
                    volatile pointer_t<unit_p> other(unit);
                    pointer_t<unit_p> pointer(std::move(other));
                    CHECK(pointer.units == unit);
                    CHECK(pointer.unit_count == 1);
                }

                TEST_CASE_TEMPLATE("should implicitly move the units and unit_count of volatile other", unit_p, types, consts, volatiles, volatile_consts)
                {
                    unit_p* unit = Random<unit_p*>();
                    volatile pointer_t<unit_p> other(unit);
                    pointer_t<unit_p> pointer = std::move(other);
                    CHECK(pointer.units == unit);
                    CHECK(pointer.unit_count == 1);
                }

                TEST_CASE_TEMPLATE("should set the units and unit_count of volatile other to the defaults", unit_p, types, consts, volatiles, volatile_consts)
                {
                    unit_p* unit = Random<unit_p*>();
                    volatile pointer_t<unit_p> other(unit);
                    pointer_t<unit_p> pointer(std::move(other));
                    CHECK(other.units == nullptr);
                    CHECK(other.unit_count == 0);
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
                    CHECK(pointer.units == unit);
                    CHECK(pointer.unit_count == 1);
                }

                TEST_CASE_TEMPLATE("should return itself after copying other", unit_p, types, consts, volatiles, volatile_consts)
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
                    CHECK(other.units == unit);
                    CHECK(other.unit_count == 1);
                }

                TEST_CASE_TEMPLATE("should copy the units and unit_count of volatile other", unit_p, types, consts, volatiles, volatile_consts)
                {
                    unit_p* unit = Random<unit_p*>();
                    volatile const pointer_t<unit_p> other(unit);
                    pointer_t<unit_p> pointer;
                    pointer = other;
                    CHECK(pointer.units == unit);
                    CHECK(pointer.unit_count == 1);
                }

                TEST_CASE_TEMPLATE("should return itself after copying volatile other", unit_p, types, consts, volatiles, volatile_consts)
                {
                    unit_p* unit = Random<unit_p*>();
                    volatile const pointer_t<unit_p> other(unit);
                    pointer_t<unit_p> pointer;
                    CHECK(&(pointer = other) == &pointer);
                }

                TEST_CASE_TEMPLATE("should not alter the units or unit_count of volatile other", unit_p, types, consts, volatiles, volatile_consts)
                {
                    unit_p* unit = Random<unit_p*>();
                    volatile const pointer_t<unit_p> other(unit);
                    pointer_t<unit_p> pointer;
                    pointer = other;
                    CHECK(other.units == unit);
                    CHECK(other.unit_count == 1);
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
                    CHECK(pointer.units == unit);
                    CHECK(pointer.unit_count == 1);
                }

                TEST_CASE_TEMPLATE("should return itself after moving other", unit_p, types, consts, volatiles, volatile_consts)
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
                    CHECK(other.units == nullptr);
                    CHECK(other.unit_count == 0);
                }

                TEST_CASE_TEMPLATE("should move the units and unit_count of volatile other", unit_p, types, consts, volatiles, volatile_consts)
                {
                    unit_p* unit = Random<unit_p*>();
                    volatile pointer_t<unit_p> other(unit);
                    pointer_t<unit_p> pointer;
                    pointer = std::move(other);
                    CHECK(pointer.units == unit);
                    CHECK(pointer.unit_count == 1);
                }

                TEST_CASE_TEMPLATE("should return itself after moving volatile other", unit_p, types, consts, volatiles, volatile_consts)
                {
                    unit_p* unit = Random<unit_p*>();
                    volatile pointer_t<unit_p> other(unit);
                    pointer_t<unit_p> pointer;
                    CHECK(&(pointer = std::move(other)) == &pointer);
                }

                TEST_CASE_TEMPLATE("should set the units and unit_count of volatile other to the defaults", unit_p, types, consts, volatiles, volatile_consts)
                {
                    unit_p* unit = Random<unit_p*>();
                    volatile pointer_t<unit_p> other(unit);
                    pointer_t<unit_p> pointer;
                    pointer = std::move(other);
                    CHECK(other.units == nullptr);
                    CHECK(other.unit_count == 0);
                }

                TEST_CASE_TEMPLATE("should implicitly work with the unit_ctor()", unit_p, types, consts, volatiles, volatile_consts)
                {
                    unit_p* unit = Random<unit_p*>();
                    pointer_t<unit_p> pointer;
                    pointer = unit;
                    CHECK(pointer.units == unit);
                    CHECK(pointer.unit_count == 1);
                }

                TEST_CASE_TEMPLATE("should implicitly work with the units_ctor()", unit_p, types, consts, volatiles, volatile_consts)
                {
                    unit_p* units;
                    do {
                        units = Random<unit_p*>();
                    } while (units == nullptr);
                    count_t unit_count;
                    do {
                        unit_count = Random<count_t>();
                    } while (unit_count == 0);
                    pointer_t<unit_p> pointer;
                    pointer = { units, unit_count };
                    CHECK(pointer.units == units);
                    CHECK(pointer.unit_count == unit_count);
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
                    CHECK(pointer.units == nullptr);
                    CHECK(pointer.unit_count == 0);
                }
            }
        }

        TEST_SUITE("casts")
        {
            TEST_SUITE("units_t()")
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
                    CHECK(pointer.units == unit);
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

            TEST_SUITE("count_t()")
            {
                TEST_CASE_TEMPLATE("should explicitly return a copy of the unit_count", unit_p, types, consts, volatiles, volatile_consts)
                {
                    unit_p* unit = Random<unit_p*>();
                    count_t unit_count = Random<count_t>();
                    const pointer_t<unit_p> pointer(unit, unit_count);
                    count_t cast = static_cast<count_t>(pointer);
                    CHECK(cast == unit_count);
                }

                TEST_CASE_TEMPLATE("should not change the unit_count", unit_p, types, consts, volatiles, volatile_consts)
                {
                    unit_p* unit = Random<unit_p*>();
                    count_t unit_count = Random<count_t>();
                    const pointer_t<unit_p> pointer(unit, unit_count);
                    count_t cast = static_cast<count_t>(pointer);
                    CHECK(pointer.unit_count == unit_count);
                }
            }
        }

        TEST_SUITE("operators")
        {
            TEST_SUITE("()()")
            {
                TEST_CASE_TEMPLATE("should return the units", unit_p, types, consts, volatiles, volatile_consts)
                {
                    unit_p* unit = Random<unit_p*>();
                    pointer_t<unit_p> pointer(unit);
                    CHECK(pointer() == unit);
                }

                TEST_CASE_TEMPLATE("should not change the units", unit_p, types, consts, volatiles, volatile_consts)
                {
                    unit_p* unit = Random<unit_p*>();
                    pointer_t<unit_p> pointer(unit);
                    pointer();
                    CHECK(pointer() == unit);
                }
            }

            TEST_SUITE("()(unit_t*)")
            {
                TEST_CASE_TEMPLATE("should set passed unit", unit_p, types, consts, volatiles, volatile_consts)
                {
                    unit_p* unit = Random<unit_p*>();
                    pointer_t<unit_p> pointer;
                    pointer(unit);
                    CHECK(pointer.units == unit);
                }

                TEST_CASE("should convert and set passed unit")
                {
                    struct base_t {};
                    struct derived_t : base_t {};

                    derived_t* unit = Random<derived_t*>();
                    pointer_t<base_t> pointer;
                    pointer(unit);
                    CHECK(pointer.units == static_cast<base_t*>(unit));
                }

                TEST_CASE_TEMPLATE("should set unit_count to 0 if passed nullptr", unit_p, types, consts, volatiles, volatile_consts)
                {
                    pointer_t<unit_p> pointer;
                    pointer(nullptr);
                    CHECK(pointer.unit_count == 0);
                }

                TEST_CASE_TEMPLATE("should set unit_count to 1 if passed non-nullptr", unit_p, types, consts, volatiles, volatile_consts)
                {
                    unit_p* unit;
                    do {
                        unit = Random<unit_p*>();
                    } while (unit == nullptr);
                    pointer_t<unit_p> pointer;
                    pointer(unit);
                    CHECK(pointer.unit_count == 1);
                }

                TEST_CASE_TEMPLATE("should return itself", unit_p, types, consts, volatiles, volatile_consts)
                {
                    unit_p* unit = Random<unit_p*>();
                    pointer_t<unit_p> pointer;
                    CHECK(&pointer(unit) == &pointer);
                }
            }

            TEST_SUITE("()(units_t, count_t)")
            {
                TEST_CASE_TEMPLATE("should set passed units and unit_count", unit_p, types, consts, volatiles, volatile_consts)
                {
                    unit_p* units;
                    do {
                        units = Random<unit_p*>();
                    } while (units == nullptr);
                    count_t unit_count;
                    do {
                        unit_count = Random<count_t>();
                    } while (unit_count == 0);
                    pointer_t<unit_p> pointer;
                    pointer(units, unit_count);
                    CHECK(pointer.units == units);
                    CHECK(pointer.unit_count == unit_count);
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
                    pointer_t<base_t> pointer;
                    pointer(units, unit_count);
                    CHECK(pointer.units == static_cast<base_t*>(units));
                    CHECK(pointer.unit_count == unit_count);
                }

                TEST_CASE_TEMPLATE("should allow a nullptr units and a 0 unit_count", unit_p, types, consts, volatiles, volatile_consts)
                {
                    pointer_t<unit_p> pointer;
                    pointer(nullptr, 0);
                    CHECK(pointer.units == nullptr);
                    CHECK(pointer.unit_count == 0);
                }

                TEST_CASE_TEMPLATE("should return itself", unit_p, types, consts, volatiles, volatile_consts)
                {
                    unit_p* units;
                    do {
                        units = Random<unit_p*>();
                    } while (units == nullptr);
                    count_t unit_count;
                    do {
                        unit_count = Random<count_t>();
                    } while (unit_count == 0);
                    pointer_t<unit_p> pointer;
                    CHECK(&pointer(units, unit_count) == &pointer);
                }
            }

            TEST_SUITE("+()")
            {
                TEST_CASE_TEMPLATE("should return a new instance with units + amount and unit_count - amount", unit_p, types, consts, volatiles, volatile_consts)
                {
                    if constexpr (type_tr<unit_p>) {
                        unit_p* units;
                        do {
                            units = Random<unit_p*>();
                        } while (units == nullptr);
                        count_t unit_count = Random<count_t>(0x1, 0xFFFF);
                        count_t amount = Random<count_t>(0, unit_count);
                        pointer_t<unit_p> pointer_a(units, unit_count);
                        pointer_t<unit_p> pointer_b = pointer_a + amount;
                        CHECK(pointer_b.units == units + amount);
                        CHECK(pointer_b.unit_count == unit_count - amount);
                    }
                }

                TEST_CASE_TEMPLATE("should not change its value", unit_p, types, consts, volatiles, volatile_consts)
                {
                    if constexpr (type_tr<unit_p>) {
                        unit_p* units;
                        do {
                            units = Random<unit_p*>();
                        } while (units == nullptr);
                        count_t unit_count = Random<count_t>(0x1, 0xFFFF);
                        count_t amount = Random<count_t>(0, unit_count);
                        pointer_t<unit_p> pointer_a(units, unit_count);
                        pointer_t<unit_p> pointer_b = pointer_a + amount;
                        CHECK(pointer_a.units == units);
                        CHECK(pointer_a.unit_count == unit_count);
                    }
                }

                TEST_CASE_TEMPLATE("should work with any integer", unit_p, types, consts, volatiles, volatile_consts)
                {
                    if constexpr (type_tr<unit_p>) {
                        unit_p* units;
                        do {
                            units = Random<unit_p*>();
                        } while (units == nullptr);
                        count_t unit_count = Random<count_t>(0x1, 0xFFFF);
                        s8_t amount = Random<s8_t>(0, std::numeric_limits<s8_t>::max());
                        pointer_t<unit_p> pointer_a(units, unit_count);
                        pointer_t<unit_p> pointer_b = pointer_a + amount;
                        CHECK(pointer_b.units == units + amount);
                        CHECK(pointer_b.unit_count == unit_count - amount);
                    }
                }
            }

            TEST_SUITE("-()")
            {
                TEST_CASE_TEMPLATE("should return a new instance with units - amount and unit_count + amount", unit_p, types, consts, volatiles, volatile_consts)
                {
                    if constexpr (type_tr<unit_p>) {
                        unit_p* units;
                        do {
                            units = Random<unit_p*>();
                        } while (units == nullptr);
                        count_t unit_count = Random<count_t>(0x1, 0xFFFF);
                        count_t amount = Random<count_t>(0, unit_count);
                        pointer_t<unit_p> pointer_a(units, unit_count);
                        pointer_t<unit_p> pointer_b = pointer_a - amount;
                        CHECK(pointer_b.units == units - amount);
                        CHECK(pointer_b.unit_count == unit_count + amount);
                    }
                }

                TEST_CASE_TEMPLATE("should not change its value", unit_p, types, consts, volatiles, volatile_consts)
                {
                    if constexpr (type_tr<unit_p>) {
                        unit_p* units;
                        do {
                            units = Random<unit_p*>();
                        } while (units == nullptr);
                        count_t unit_count = Random<count_t>(0x1, 0xFFFF);
                        count_t amount = Random<count_t>(0, unit_count);
                        pointer_t<unit_p> pointer_a(units, unit_count);
                        pointer_t<unit_p> pointer_b = pointer_a - amount;
                        CHECK(pointer_a.units == units);
                        CHECK(pointer_a.unit_count == unit_count);
                    }
                }

                TEST_CASE_TEMPLATE("should work with any integer", unit_p, types, consts, volatiles, volatile_consts)
                {
                    if constexpr (type_tr<unit_p>) {
                        unit_p* units;
                        do {
                            units = Random<unit_p*>();
                        } while (units == nullptr);
                        count_t unit_count = Random<count_t>(0x1, 0xFFFF);
                        s8_t amount = Random<s8_t>(0, std::numeric_limits<s8_t>::max());
                        pointer_t<unit_p> pointer_a(units, unit_count);
                        pointer_t<unit_p> pointer_b = pointer_a - amount;
                        CHECK(pointer_b.units == units - amount);
                        CHECK(pointer_b.unit_count == unit_count + amount);
                    }
                }
            }

            TEST_SUITE("+=()")
            {
                TEST_CASE_TEMPLATE("should set units += amount and unit_count -= amount", unit_p, types, consts, volatiles, volatile_consts)
                {
                    if constexpr (type_tr<unit_p>) {
                        unit_p* units;
                        do {
                            units = Random<unit_p*>();
                        } while (units == nullptr);
                        count_t unit_count = Random<count_t>(0x1, 0xFFFF);
                        count_t amount = Random<count_t>(0, unit_count);
                        pointer_t<unit_p> pointer(units, unit_count);
                        pointer += amount;
                        CHECK(pointer.units == (units += amount));
                        CHECK(pointer.unit_count == (unit_count -= amount));
                    }
                }

                TEST_CASE_TEMPLATE("should return itself", unit_p, types, consts, volatiles, volatile_consts)
                {
                    if constexpr (type_tr<unit_p>) {
                        unit_p* units;
                        do {
                            units = Random<unit_p*>();
                        } while (units == nullptr);
                        count_t unit_count = Random<count_t>(0x1, 0xFFFF);
                        count_t amount = Random<count_t>(0, unit_count);
                        pointer_t<unit_p> pointer(units, unit_count);
                        CHECK(&(pointer += amount) == &pointer);
                    }
                }

                TEST_CASE_TEMPLATE("should work with any integer", unit_p, types, consts, volatiles, volatile_consts)
                {
                    if constexpr (type_tr<unit_p>) {
                        unit_p* units;
                        do {
                            units = Random<unit_p*>();
                        } while (units == nullptr);
                        count_t unit_count = Random<count_t>(0x1, 0xFFFF);
                        s8_t amount = Random<s8_t>(0, std::numeric_limits<s8_t>::max());
                        pointer_t<unit_p> pointer(units, unit_count);
                        pointer += amount;
                        CHECK(pointer.units == (units += amount));
                        CHECK(pointer.unit_count == (unit_count -= amount));
                    }
                }
            }

            TEST_SUITE("-=()")
            {
                TEST_CASE_TEMPLATE("should set units -= amount and unit_count += amount", unit_p, types, consts, volatiles, volatile_consts)
                {
                    if constexpr (type_tr<unit_p>) {
                        unit_p* units;
                        do {
                            units = Random<unit_p*>();
                        } while (units == nullptr);
                        count_t unit_count = Random<count_t>(0x1, 0xFFFF);
                        count_t amount = Random<count_t>(0, unit_count);
                        pointer_t<unit_p> pointer(units, unit_count);
                        pointer -= amount;
                        CHECK(pointer.units == (units -= amount));
                        CHECK(pointer.unit_count == (unit_count += amount));
                    }
                }

                TEST_CASE_TEMPLATE("should return itself", unit_p, types, consts, volatiles, volatile_consts)
                {
                    if constexpr (type_tr<unit_p>) {
                        unit_p* units;
                        do {
                            units = Random<unit_p*>();
                        } while (units == nullptr);
                        count_t unit_count = Random<count_t>(0x1, 0xFFFF);
                        count_t amount = Random<count_t>(0, unit_count);
                        pointer_t<unit_p> pointer(units, unit_count);
                        CHECK(&(pointer -= amount) == &pointer);
                    }
                }

                TEST_CASE_TEMPLATE("should work with any integer", unit_p, types, consts, volatiles, volatile_consts)
                {
                    if constexpr (type_tr<unit_p>) {
                        unit_p* units;
                        do {
                            units = Random<unit_p*>();
                        } while (units == nullptr);
                        count_t unit_count = Random<count_t>(0x1, 0xFFFF);
                        s8_t amount = Random<s8_t>(0, std::numeric_limits<s8_t>::max());
                        pointer_t<unit_p> pointer(units, unit_count);
                        pointer -= amount;
                        CHECK(pointer.units == (units -= amount));
                        CHECK(pointer.unit_count == (unit_count += amount));
                    }
                }
            }

            TEST_SUITE("++()")
            {
                TEST_CASE_TEMPLATE("should set units += 1 and unit_count -= 1", unit_p, types, consts, volatiles, volatile_consts)
                {
                    if constexpr (type_tr<unit_p>) {
                        unit_p* units;
                        do {
                            units = Random<unit_p*>();
                        } while (units == nullptr);
                        count_t unit_count = Random<count_t>(0x1, 0xFFFF);
                        pointer_t<unit_p> pointer(units, unit_count);
                        ++pointer;
                        CHECK(pointer.units == (units += 1));
                        CHECK(pointer.unit_count == (unit_count -= 1));
                    }
                }

                TEST_CASE_TEMPLATE("should return itself with the new value", unit_p, types, consts, volatiles, volatile_consts)
                {
                    if constexpr (type_tr<unit_p>) {
                        unit_p* units;
                        do {
                            units = Random<unit_p*>();
                        } while (units == nullptr);
                        count_t unit_count = Random<count_t>(0x1, 0xFFFF);
                        pointer_t<unit_p> pointer(units, unit_count);
                        CHECK((++pointer).units == (units += 1));
                    }
                }
            }

            TEST_SUITE("++(int)")
            {
                TEST_CASE_TEMPLATE("should set units += 1 and unit_count -= 1", unit_p, types, consts, volatiles, volatile_consts)
                {
                    if constexpr (type_tr<unit_p>) {
                        unit_p* units;
                        do {
                            units = Random<unit_p*>();
                        } while (units == nullptr);
                        count_t unit_count = Random<count_t>(0x1, 0xFFFF);
                        pointer_t<unit_p> pointer(units, unit_count);
                        pointer++;
                        CHECK(pointer.units == (units += 1));
                        CHECK(pointer.unit_count == (unit_count -= 1));
                    }
                }

                TEST_CASE_TEMPLATE("should return a copy of the old pointer", unit_p, types, consts, volatiles, volatile_consts)
                {
                    if constexpr (type_tr<unit_p>) {
                        unit_p* units;
                        do {
                            units = Random<unit_p*>();
                        } while (units == nullptr);
                        count_t unit_count = Random<count_t>(0x1, 0xFFFF);
                        pointer_t<unit_p> pointer(units, unit_count);
                        CHECK((pointer++).units == units);
                    }
                }
            }

            TEST_SUITE("--()")
            {
                TEST_CASE_TEMPLATE("should set units -= 1 and unit_count += 1", unit_p, types, consts, volatiles, volatile_consts)
                {
                    if constexpr (type_tr<unit_p>) {
                        unit_p* units;
                        do {
                            units = Random<unit_p*>();
                        } while (units == nullptr);
                        count_t unit_count = Random<count_t>(0x1, 0xFFFF);
                        pointer_t<unit_p> pointer(units, unit_count);
                        --pointer;
                        CHECK(pointer.units == (units -= 1));
                        CHECK(pointer.unit_count == (unit_count += 1));
                    }
                }

                TEST_CASE_TEMPLATE("should return itself with the new value", unit_p, types, consts, volatiles, volatile_consts)
                {
                    if constexpr (type_tr<unit_p>) {
                        unit_p* units;
                        do {
                            units = Random<unit_p*>();
                        } while (units == nullptr);
                        count_t unit_count = Random<count_t>(0x1, 0xFFFF);
                        pointer_t<unit_p> pointer(units, unit_count);
                        CHECK((--pointer).units == (units -= 1));
                    }
                }
            }

            TEST_SUITE("--(int)")
            {
                TEST_CASE_TEMPLATE("should set units -= 1 and unit_count += 1", unit_p, types, consts, volatiles, volatile_consts)
                {
                    if constexpr (type_tr<unit_p>) {
                        unit_p* units;
                        do {
                            units = Random<unit_p*>();
                        } while (units == nullptr);
                        count_t unit_count = Random<count_t>(0x1, 0xFFFF);
                        pointer_t<unit_p> pointer(units, unit_count);
                        pointer--;
                        CHECK(pointer.units == (units -= 1));
                        CHECK(pointer.unit_count == (unit_count += 1));
                    }
                }

                TEST_CASE_TEMPLATE("should return a copy of the old pointer", unit_p, types, consts, volatiles, volatile_consts)
                {
                    if constexpr (type_tr<unit_p>) {
                        unit_p* units;
                        do {
                            units = Random<unit_p*>();
                        } while (units == nullptr);
                        count_t unit_count = Random<count_t>(0x1, 0xFFFF);
                        pointer_t<unit_p> pointer(units, unit_count);
                        CHECK((pointer--).units == units);
                    }
                }
            }

            TEST_SUITE("->()")
            {
                TEST_CASE_TEMPLATE("should be able to access the first unit's values", unit_p, types, consts, volatiles, volatile_consts)
                {
                    if constexpr (type_tr<unit_p>) {
                        unit_p* random = Random<unit_p*>();
                        struct wrap_t { unit_p* random; } wrap(random);
                        const pointer_t<wrap_t> pointer(&wrap);
                        CHECK(pointer->random == random);
                    }
                }

                TEST_CASE_TEMPLATE("should be able to assign the first unit's values", unit_p, types, consts, volatiles, volatile_consts)
                {
                    if constexpr (type_tr<unit_p>) {
                        unit_p* random_a = Random<unit_p*>();
                        unit_p* random_b = Random<unit_p*>();
                        struct wrap_t { unit_p* value; } wrap(random_a);
                        const pointer_t<wrap_t> pointer(&wrap);
                        pointer->value = random_b;
                        CHECK(wrap.value == random_b);
                    }
                }

                TEST_CASE_TEMPLATE("should not change the units", unit_p, types, consts, volatiles, volatile_consts)
                {
                    if constexpr (type_tr<unit_p>) {
                        unit_p* random_a = Random<unit_p*>();
                        unit_p* random_b = Random<unit_p*>();
                        struct wrap_t { unit_p* value; } wrap(random_a);
                        const pointer_t<wrap_t> pointer(&wrap);
                        pointer->value = random_b;
                        CHECK(pointer.units == &wrap);
                    }
                }
            }

            TEST_SUITE("*()")
            {
                TEST_CASE_TEMPLATE("should be able to access the first unit's value", unit_p, types, consts, volatiles, volatile_consts)
                {
                    if constexpr (type_tr<unit_p>) {
                        unit_p random = Random<unit_p>();
                        const pointer_t<unit_p> pointer(&random);
                        CHECK(*pointer == random);
                    }
                }

                TEST_CASE_TEMPLATE("should be able to assign the first unit's value", unit_p, types, volatiles)
                {
                    if constexpr (type_tr<unit_p>) {
                        unit_p random_a = Random<unit_p>();
                        unit_p random_b = Random<unit_p>();
                        const pointer_t<unit_p> pointer(&random_a);
                        *pointer = random_b;
                        CHECK(random_a == random_b);
                    }
                }

                TEST_CASE_TEMPLATE("should not change the units", unit_p, types, volatiles)
                {
                    if constexpr (type_tr<unit_p>) {
                        unit_p random_a = Random<unit_p>();
                        unit_p random_b = Random<unit_p>();
                        const pointer_t<unit_p> pointer(&random_a);
                        *pointer = random_b;
                        CHECK(pointer.units == &random_a);
                    }
                }
            }

            TEST_SUITE("[]()")
            {
                TEST_CASE_TEMPLATE("should be able to access the indexed unit's value", unit_p, types, consts, volatiles, volatile_consts)
                {
                    if constexpr (type_tr<unit_p>) {
                        std::remove_const_t<unit_p> randoms[16];
                        for (index_t idx = 0, end = 16; idx < end; idx += 1) {
                            randoms[idx] = Random<std::remove_const_t<unit_p>>();
                        }
                        const pointer_t<unit_p> pointer(randoms, sizeof(randoms));
                        index_t index = Random<index_t>(0, 15);
                        CHECK(pointer[index] == randoms[index]);
                    }
                }

                TEST_CASE_TEMPLATE("should be able to assign the indexed unit's value", unit_p, types, volatiles)
                {
                    if constexpr (type_tr<unit_p>) {
                        unit_p randoms[16];
                        for (index_t idx = 0, end = 16; idx < end; idx += 1) {
                            randoms[idx] = Random<unit_p>();
                        }
                        const pointer_t<unit_p> pointer(randoms, sizeof(randoms));
                        index_t index = Random<index_t>(0, 15);
                        unit_p random = Random<unit_p>();
                        pointer[index] = random;
                        CHECK(randoms[index] == random);
                    }
                }

                TEST_CASE_TEMPLATE("should not change the units", unit_p, types, volatiles)
                {
                    if constexpr (type_tr<unit_p>) {
                        unit_p randoms[16];
                        for (index_t idx = 0, end = 16; idx < end; idx += 1) {
                            randoms[idx] = Random<unit_p>();
                        }
                        const pointer_t<unit_p> pointer(randoms, sizeof(randoms));
                        index_t index = Random<index_t>(0, 15);
                        unit_p random = Random<unit_p>();
                        pointer[index] = random;
                        CHECK(pointer.units == randoms);
                    }
                }
            }
        }

    #undef types
    #undef consts
    #undef volatiles
    #undef volatile_consts
    }

}
