/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/intrinsics.h"
#include "nkr/pointer_t.h"
#include "nkr/utils.h"

#include "doctest.h"

namespace nkr {

    TEST_SUITE("pointer_t<unit_p>")
    {
    #define nkr_UNIT(QUALIFIER_p, UNIT_p)               \
        QUALIFIER_p pointer_t<UNIT_p>,                  \
        QUALIFIER_p pointer_t<volatile UNIT_p>,         \
        QUALIFIER_p pointer_t<const UNIT_p>,            \
        QUALIFIER_p pointer_t<const volatile UNIT_p>

    #define nkr_UNITS(QUALIFIER_p)          \
        nkr_UNIT(QUALIFIER_p, void_t),      \
        nkr_UNIT(QUALIFIER_p, std_bool_t),  \
        nkr_UNIT(QUALIFIER_p, bool_t),      \
        nkr_UNIT(QUALIFIER_p, word_t),      \
        nkr_UNIT(QUALIFIER_p, real_t),      \
        nkr_UNIT(QUALIFIER_p, void_t*)

    #define nkr_REGULAR         \
        nkr_UNITS(nkr_BLANK)

    #define nkr_NON_CONST       \
        nkr_UNITS(nkr_BLANK),   \
        nkr_UNITS(volatile)

    #define nkr_CONST               \
        nkr_UNITS(const),           \
        nkr_UNITS(const volatile)

    #define nkr_ALL     \
        nkr_NON_CONST,  \
        nkr_CONST

        TEST_SUITE("aliases")
        {
            TEST_SUITE("unit_t")
            {
                TEST_CASE_TEMPLATE("should have a unit_t", pointer_p, nkr_ALL)
                {
                    using unit_t = pointer_p::unit_t;
                    using units_t = pointer_p::units_t;

                    static_assert(is_tr<unit_t, unit_t>);
                }
            }

            TEST_SUITE("units_t")
            {
                TEST_CASE_TEMPLATE("should have a units_t that equals unit_t*", pointer_p, nkr_ALL)
                {
                    using unit_t = pointer_p::unit_t;
                    using units_t = pointer_p::units_t;

                    static_assert(is_tr<units_t, unit_t*>);
                }
            }
        }

        TEST_SUITE("static operators")
        {
            TEST_SUITE("==()")
            {
                TEST_CASE_TEMPLATE("should return true if units and unit_count are the same as other", pointer_p, nkr_ALL)
                {
                    using unit_t = pointer_p::unit_t;
                    using units_t = pointer_p::units_t;

                    units_t units = Random<units_t>();
                    count_t unit_count = Random<count_t>();
                    pointer_p other(units, unit_count);
                    pointer_p pointer(units, unit_count);
                    CHECK_TRUE(pointer == other);
                }

                TEST_CASE_TEMPLATE("should return false if units is different from other", pointer_p, nkr_ALL)
                {
                    using unit_t = pointer_p::unit_t;
                    using units_t = pointer_p::units_t;

                    units_t units;
                    do {
                        units = Random<units_t>();
                    } while (units == nullptr);
                    count_t unit_count = Random<count_t>();
                    pointer_p other(nullptr, unit_count);
                    pointer_p pointer(units, unit_count);
                    CHECK_FALSE(pointer == other);
                }

                TEST_CASE_TEMPLATE("should return false if unit_count is different from other", pointer_p, nkr_ALL)
                {
                    using unit_t = pointer_p::unit_t;
                    using units_t = pointer_p::units_t;

                    units_t units = Random<units_t>();
                    count_t unit_count;
                    do {
                        unit_count = Random<count_t>();
                    } while (unit_count == 0);
                    pointer_p other(units, 0);
                    pointer_p pointer(units, unit_count);
                    CHECK_FALSE(pointer == other);
                }

                TEST_CASE_TEMPLATE("should work with any combination of qualified types", pointer_p, nkr_REGULAR)
                {
                    using unit_t = pointer_p::unit_t;
                    using units_t = pointer_p::units_t;

                    pointer_t<unit_t> a;
                    volatile pointer_t<unit_t> b;
                    const volatile pointer_t<unit_t> c;
                    pointer_t<unit_t>& d = a;
                    volatile pointer_t<unit_t>& e = b;
                    const volatile pointer_t<unit_t>& f = c;

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

                    CHECK_TRUE(a == pointer_t<unit_t>());
                    CHECK_TRUE(b == pointer_t<unit_t>());
                    CHECK_TRUE(c == pointer_t<unit_t>());
                    CHECK_TRUE(d == pointer_t<unit_t>());
                    CHECK_TRUE(e == pointer_t<unit_t>());
                    CHECK_TRUE(f == pointer_t<unit_t>());

                    CHECK_TRUE(pointer_t<unit_t>() == a);
                    CHECK_TRUE(pointer_t<unit_t>() == b);
                    CHECK_TRUE(pointer_t<unit_t>() == c);
                    CHECK_TRUE(pointer_t<unit_t>() == d);
                    CHECK_TRUE(pointer_t<unit_t>() == e);
                    CHECK_TRUE(pointer_t<unit_t>() == f);
                }
            }

            TEST_SUITE("!=()")
            {
                TEST_CASE_TEMPLATE("should return false if units and unit_count are the same as other", pointer_p, nkr_ALL)
                {
                    using unit_t = pointer_p::unit_t;
                    using units_t = pointer_p::units_t;

                    units_t units = Random<units_t>();
                    count_t unit_count = Random<count_t>();
                    pointer_p other(units, unit_count);
                    pointer_p pointer(units, unit_count);
                    CHECK_FALSE(pointer != other);
                }

                TEST_CASE_TEMPLATE("should return true if units is different from other", pointer_p, nkr_ALL)
                {
                    using unit_t = pointer_p::unit_t;
                    using units_t = pointer_p::units_t;

                    units_t units;
                    do {
                        units = Random<units_t>();
                    } while (units == nullptr);
                    count_t unit_count = Random<count_t>();
                    pointer_p other(nullptr, unit_count);
                    pointer_p pointer(units, unit_count);
                    CHECK_TRUE(pointer != other);
                }

                TEST_CASE_TEMPLATE("should return true if unit_count is different from other", pointer_p, nkr_ALL)
                {
                    using unit_t = pointer_p::unit_t;
                    using units_t = pointer_p::units_t;

                    units_t units = Random<units_t>();
                    count_t unit_count;
                    do {
                        unit_count = Random<count_t>();
                    } while (unit_count == 0);
                    pointer_p other(units, 0);
                    pointer_p pointer(units, unit_count);
                    CHECK_TRUE(pointer != other);
                }

                TEST_CASE_TEMPLATE("should work with any combination of qualified types", pointer_p, nkr_REGULAR)
                {
                    using unit_t = pointer_p::unit_t;
                    using units_t = pointer_p::units_t;

                    pointer_t<unit_t> a;
                    volatile pointer_t<unit_t> b;
                    const volatile pointer_t<unit_t> c;
                    pointer_t<unit_t>& d = a;
                    volatile pointer_t<unit_t>& e = b;
                    const volatile pointer_t<unit_t>& f = c;

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

                    CHECK_FALSE(a != pointer_t<unit_t>());
                    CHECK_FALSE(b != pointer_t<unit_t>());
                    CHECK_FALSE(c != pointer_t<unit_t>());
                    CHECK_FALSE(d != pointer_t<unit_t>());
                    CHECK_FALSE(e != pointer_t<unit_t>());
                    CHECK_FALSE(f != pointer_t<unit_t>());

                    CHECK_FALSE(pointer_t<unit_t>() != a);
                    CHECK_FALSE(pointer_t<unit_t>() != b);
                    CHECK_FALSE(pointer_t<unit_t>() != c);
                    CHECK_FALSE(pointer_t<unit_t>() != d);
                    CHECK_FALSE(pointer_t<unit_t>() != e);
                    CHECK_FALSE(pointer_t<unit_t>() != f);
                }
            }
        }

        TEST_SUITE("object data")
        {
            TEST_SUITE("units")
            {
                TEST_CASE_TEMPLATE("should be a units_t", pointer_p, nkr_ALL)
                {
                    using unit_t = pointer_p::unit_t;
                    using units_t = pointer_p::units_t;

                    static_assert(is_tr<decltype(pointer_p::units), units_t>);
                }
            }

            TEST_SUITE("unit_count")
            {
                TEST_CASE_TEMPLATE("should be a count_t", pointer_p, nkr_ALL)
                {
                    using unit_t = pointer_p::unit_t;
                    using units_t = pointer_p::units_t;

                    static_assert(is_tr<decltype(pointer_p::unit_count), count_t>);
                }
            }
        }

        TEST_SUITE("objects")
        {
            TEST_SUITE("default_ctor()")
            {
                TEST_CASE_TEMPLATE("should set units to nullptr", pointer_p, nkr_ALL)
                {
                    using unit_t = pointer_p::unit_t;
                    using units_t = pointer_p::units_t;

                    pointer_p pointer;
                    CHECK(pointer.Units() == nullptr);
                }

                TEST_CASE_TEMPLATE("should set unit_count to 0", pointer_p, nkr_ALL)
                {
                    using unit_t = pointer_p::unit_t;
                    using units_t = pointer_p::units_t;

                    pointer_p pointer;
                    CHECK(pointer.Unit_Count() == 0);
                }
            }

            TEST_SUITE("unit_ctor()")
            {
                TEST_CASE_TEMPLATE("should explicitly set passed unit", pointer_p, nkr_ALL)
                {
                    using unit_t = pointer_p::unit_t;
                    using units_t = pointer_p::units_t;

                    unit_t* unit = Random<unit_t*>();
                    pointer_p pointer(unit);
                    CHECK(pointer.Unit() == unit);
                }

                TEST_CASE_TEMPLATE("should implicitly set passed unit", pointer_p, nkr_ALL)
                {
                    using unit_t = pointer_p::unit_t;
                    using units_t = pointer_p::units_t;

                    unit_t* unit = Random<unit_t*>();
                    pointer_p pointer = unit;
                    CHECK(pointer.Unit() == unit);
                }

                TEST_CASE("should convert and set passed unit")
                {
                    struct base_t {};
                    struct derived_t : base_t {};

                    derived_t* unit = Random<derived_t*>();
                    pointer_t<base_t> pointer(unit);
                    CHECK(pointer.Unit() == static_cast<base_t*>(unit));
                }

                TEST_CASE_TEMPLATE("should set unit_count to 0 if passed nullptr", pointer_p, nkr_ALL)
                {
                    using unit_t = pointer_p::unit_t;
                    using units_t = pointer_p::units_t;

                    pointer_p pointer(nullptr);
                    CHECK(pointer.Unit_Count() == 0);
                }

                TEST_CASE_TEMPLATE("should set unit_count to 1 if passed non-nullptr", pointer_p, nkr_ALL)
                {
                    using unit_t = pointer_p::unit_t;
                    using units_t = pointer_p::units_t;

                    unit_t* unit;
                    do {
                        unit = Random<unit_t*>();
                    } while (unit == nullptr);
                    pointer_p pointer(unit);
                    CHECK(pointer.Unit_Count() == 1);
                }
            }

            TEST_SUITE("units_ctor()")
            {
                TEST_CASE_TEMPLATE("should explicitly set passed units and unit_count", pointer_p, nkr_ALL)
                {
                    using unit_t = pointer_p::unit_t;
                    using units_t = pointer_p::units_t;

                    units_t units;
                    do {
                        units = Random<units_t>();
                    } while (units == nullptr);
                    count_t unit_count;
                    do {
                        unit_count = Random<count_t>();
                    } while (unit_count == 0);
                    pointer_p pointer(units, unit_count);
                    CHECK(pointer.Units() == units);
                    CHECK(pointer.Unit_Count() == unit_count);
                }

                TEST_CASE_TEMPLATE("should implicitly set passed units and unit_count", pointer_p, nkr_ALL)
                {
                    using unit_t = pointer_p::unit_t;
                    using units_t = pointer_p::units_t;

                    units_t units;
                    do {
                        units = Random<units_t>();
                    } while (units == nullptr);
                    count_t unit_count;
                    do {
                        unit_count = Random<count_t>();
                    } while (unit_count == 0);
                    pointer_p pointer = { units, unit_count };
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

                TEST_CASE_TEMPLATE("should allow a nullptr units and a 0 unit_count", pointer_p, nkr_ALL)
                {
                    using unit_t = pointer_p::unit_t;
                    using units_t = pointer_p::units_t;

                    pointer_p pointer(nullptr, 0);
                    CHECK(pointer.Units() == nullptr);
                    CHECK(pointer.Unit_Count() == 0);
                }
            }

            TEST_SUITE("copy_ctor()")
            {
                TEST_CASE_TEMPLATE("should explicitly copy the units and unit_count of other", pointer_p, nkr_ALL)
                {
                    using unit_t = pointer_p::unit_t;
                    using units_t = pointer_p::units_t;

                    unit_t* unit = Random<unit_t*>();
                    pointer_p other(unit);
                    pointer_p pointer(other);
                    CHECK(pointer.Unit() == unit);
                    CHECK(pointer.Unit_Count() == 1);
                }

                TEST_CASE_TEMPLATE("should implicitly copy the units and unit_count of other", pointer_p, nkr_ALL)
                {
                    using unit_t = pointer_p::unit_t;
                    using units_t = pointer_p::units_t;

                    unit_t* unit = Random<unit_t*>();
                    pointer_p other(unit);
                    pointer_p pointer = other;
                    CHECK(pointer.Unit() == unit);
                    CHECK(pointer.Unit_Count() == 1);
                }

                TEST_CASE_TEMPLATE("should not alter the units or unit_count of other", pointer_p, nkr_ALL)
                {
                    using unit_t = pointer_p::unit_t;
                    using units_t = pointer_p::units_t;

                    unit_t* unit = Random<unit_t*>();
                    pointer_p other(unit);
                    pointer_p pointer(other);
                    CHECK(other.Unit() == unit);
                    CHECK(other.Unit_Count() == 1);
                }
            }

            TEST_SUITE("move_ctor()")
            {
                TEST_CASE_TEMPLATE("should explicitly move the units and unit_count of other", pointer_p, nkr_NON_CONST)
                {
                    using unit_t = pointer_p::unit_t;
                    using units_t = pointer_p::units_t;

                    unit_t* unit = Random<unit_t*>();
                    pointer_p other(unit);
                    pointer_p pointer(nkr::Move(other));
                    CHECK(pointer.Unit() == unit);
                    CHECK(pointer.Unit_Count() == 1);
                }

                TEST_CASE_TEMPLATE("should implicitly move the units and unit_count of other", pointer_p, nkr_NON_CONST)
                {
                    using unit_t = pointer_p::unit_t;
                    using units_t = pointer_p::units_t;

                    unit_t* unit = Random<unit_t*>();
                    pointer_p other(unit);
                    pointer_p pointer = nkr::Move(other);
                    CHECK(pointer.Unit() == unit);
                    CHECK(pointer.Unit_Count() == 1);
                }

                TEST_CASE_TEMPLATE("should set the units and unit_count of other to the defaults", pointer_p, nkr_NON_CONST)
                {
                    using unit_t = pointer_p::unit_t;
                    using units_t = pointer_p::units_t;

                    unit_t* unit = Random<unit_t*>();
                    pointer_p other(unit);
                    pointer_p pointer(nkr::Move(other));
                    CHECK(other.Units() == nullptr);
                    CHECK(other.Unit_Count() == 0);
                }
            }

            TEST_SUITE("copy_assignment_ctor()")
            {
                TEST_CASE_TEMPLATE("should copy the units and unit_count of other", pointer_p, nkr_NON_CONST)
                {
                    using unit_t = pointer_p::unit_t;
                    using units_t = pointer_p::units_t;

                    unit_t* unit = Random<unit_t*>();
                    const pointer_p other(unit);
                    pointer_p pointer;
                    pointer = other;
                    CHECK(pointer.Unit() == unit);
                    CHECK(pointer.Unit_Count() == 1);
                }

                TEST_CASE_TEMPLATE("should return itself after copying other", pointer_p, nkr_NON_CONST)
                {
                    using unit_t = pointer_p::unit_t;
                    using units_t = pointer_p::units_t;

                    unit_t* unit = Random<unit_t*>();
                    const pointer_p other(unit);
                    pointer_p pointer;
                    CHECK(&(pointer = other) == &pointer);
                }

                TEST_CASE_TEMPLATE("should not alter the units or unit_count of other", pointer_p, nkr_NON_CONST)
                {
                    using unit_t = pointer_p::unit_t;
                    using units_t = pointer_p::units_t;

                    unit_t* unit = Random<unit_t*>();
                    const pointer_p other(unit);
                    pointer_p pointer;
                    pointer = other;
                    CHECK(other.Unit() == unit);
                    CHECK(other.Unit_Count() == 1);
                }
            }

            TEST_SUITE("move_assignment_ctor()")
            {
                TEST_CASE_TEMPLATE("should move the units and unit_count of other", pointer_p, nkr_NON_CONST)
                {
                    using unit_t = pointer_p::unit_t;
                    using units_t = pointer_p::units_t;

                    unit_t* unit = Random<unit_t*>();
                    pointer_p other(unit);
                    pointer_p pointer;
                    pointer = nkr::Move(other);
                    CHECK(pointer.Unit() == unit);
                    CHECK(pointer.Unit_Count() == 1);
                }

                TEST_CASE_TEMPLATE("should return itself after moving other", pointer_p, nkr_NON_CONST)
                {
                    using unit_t = pointer_p::unit_t;
                    using units_t = pointer_p::units_t;

                    unit_t* unit = Random<unit_t*>();
                    pointer_p other(unit);
                    pointer_p pointer;
                    CHECK((&(pointer = nkr::Move(other)) == &pointer));
                }

                TEST_CASE_TEMPLATE("should set the units and unit_count of other to the defaults", pointer_p, nkr_NON_CONST)
                {
                    using unit_t = pointer_p::unit_t;
                    using units_t = pointer_p::units_t;

                    unit_t* unit = Random<unit_t*>();
                    pointer_p other(unit);
                    pointer_p pointer;
                    pointer = nkr::Move(other);
                    CHECK(other.Units() == nullptr);
                    CHECK(other.Unit_Count() == 0);
                }

                TEST_CASE_TEMPLATE("should implicitly work with the unit_ctor()", pointer_p, nkr_NON_CONST)
                {
                    using unit_t = pointer_p::unit_t;
                    using units_t = pointer_p::units_t;

                    unit_t* unit = Random<unit_t*>();
                    pointer_p pointer;
                    pointer = unit;
                    CHECK(pointer.Unit() == unit);
                    CHECK(pointer.Unit_Count() == 1);
                }

                TEST_CASE_TEMPLATE("should implicitly work with the units_ctor()", pointer_p, nkr_NON_CONST)
                {
                    using unit_t = pointer_p::unit_t;
                    using units_t = pointer_p::units_t;

                    unit_t* units;
                    do {
                        units = Random<unit_t*>();
                    } while (units == nullptr);
                    count_t unit_count;
                    do {
                        unit_count = Random<count_t>();
                    } while (unit_count == 0);
                    pointer_p pointer;
                    pointer = { units, unit_count };
                    CHECK(pointer.Units() == units);
                    CHECK(pointer.Unit_Count() == unit_count);
                }
            }

            TEST_SUITE("dtor()")
            {
                TEST_CASE_TEMPLATE("should set the units and unit_count to the defaults", pointer_p, nkr_ALL)
                {
                    using unit_t = pointer_p::unit_t;
                    using units_t = pointer_p::units_t;

                    unit_t* units;
                    do {
                        units = Random<unit_t*>();
                    } while (units == nullptr);
                    count_t unit_count;
                    do {
                        unit_count = Random<count_t>();
                    } while (unit_count == 0);
                    pointer_p pointer(units, unit_count);
                    pointer.~pointer_t();
                    CHECK(pointer.Units() == nullptr);
                    CHECK(pointer.Unit_Count() == 0);
                }
            }
        }

        TEST_SUITE("methods")
        {
            TEST_SUITE("Unit()")
            {
                TEST_CASE_TEMPLATE("should return the unit", pointer_p, nkr_ALL)
                {
                    using unit_t = pointer_p::unit_t;
                    using units_t = pointer_p::units_t;

                    unit_t* unit = Random<unit_t*>();
                    pointer_p pointer(unit);
                    CHECK(pointer.Unit() == unit);
                }

                TEST_CASE_TEMPLATE("should allow assignment to the unit", pointer_p, nkr_NON_CONST)
                {
                    using unit_t = pointer_p::unit_t;
                    using units_t = pointer_p::units_t;

                    unit_t* unit_a = Random<unit_t*>();
                    unit_t* unit_b = Random<unit_t*>();
                    pointer_p pointer(unit_a);
                    pointer.Unit() = unit_b;
                    CHECK(pointer.Unit() == unit_b);
                }
            }

            TEST_SUITE("Units()")
            {
                TEST_CASE_TEMPLATE("should return the units", pointer_p, nkr_ALL)
                {
                    using unit_t = pointer_p::unit_t;
                    using units_t = pointer_p::units_t;

                    units_t units = Random<units_t>();
                    count_t count = Random<count_t>();
                    pointer_p pointer(units, count);
                    CHECK(pointer.Units() == units);
                }

                TEST_CASE_TEMPLATE("should allow assignment to the units", pointer_p, nkr_NON_CONST)
                {
                    using unit_t = pointer_p::unit_t;
                    using units_t = pointer_p::units_t;

                    units_t units_a = Random<units_t>();
                    units_t units_b = Random<units_t>();
                    count_t count = Random<count_t>();
                    pointer_p pointer(units_a, count);
                    pointer.Units() = units_b;
                    CHECK(pointer.Units() == units_b);
                }
            }

            TEST_SUITE("Unit_Count()")
            {
                TEST_CASE_TEMPLATE("should return the unit_count", pointer_p, nkr_ALL)
                {
                    using unit_t = pointer_p::unit_t;
                    using units_t = pointer_p::units_t;

                    units_t units = Random<units_t>();
                    count_t count = Random<count_t>();
                    pointer_p pointer(units, count);
                    CHECK(pointer.Unit_Count() == count);
                }

                TEST_CASE_TEMPLATE("should allow assignment to the unit_count", pointer_p, nkr_NON_CONST)
                {
                    using unit_t = pointer_p::unit_t;
                    using units_t = pointer_p::units_t;

                    units_t units = Random<units_t>();
                    count_t count_a = Random<count_t>();
                    count_t count_b = Random<count_t>();
                    pointer_p pointer(units, count_a);
                    pointer.Unit_Count() = count_b;
                    CHECK(pointer.Unit_Count() == count_b);
                }
            }
        }

        TEST_SUITE("casts")
        {
            TEST_SUITE("units_t()")
            {
                TEST_CASE_TEMPLATE("should explicitly return a reference to the units", pointer_p, nkr_ALL)
                {
                    using unit_t = pointer_p::unit_t;
                    using units_t = pointer_p::units_t;

                    unit_t* unit = Random<unit_t*>();
                    pointer_p pointer(unit);
                    if constexpr (just_const_volatile_tr<pointer_p>) {
                        const volatile units_t cast = static_cast<const volatile units_t&>(pointer);
                        CHECK(cast == unit);
                    } else if constexpr (just_volatile_tr<pointer_p>) {
                        volatile units_t cast = static_cast<volatile units_t&>(pointer);
                        CHECK(cast == unit);
                    } else if constexpr (just_const_tr<pointer_p>) {
                        const units_t cast = static_cast<const units_t&>(pointer);
                        CHECK(cast == unit);
                    } else {
                        units_t cast = static_cast<units_t&>(pointer);
                        CHECK(cast == unit);
                    }
                }

                TEST_CASE_TEMPLATE("should implicitly return a reference to the units", pointer_p, nkr_ALL)
                {
                    using unit_t = pointer_p::unit_t;
                    using units_t = pointer_p::units_t;

                    unit_t* unit = Random<unit_t*>();
                    pointer_p pointer(unit);
                    if constexpr (just_const_volatile_tr<pointer_p>) {
                        const volatile units_t cast = pointer;
                        CHECK(cast == unit);
                    } else if constexpr (just_volatile_tr<pointer_p>) {
                        volatile units_t cast = pointer;
                        CHECK(cast == unit);
                    } else if constexpr (just_const_tr<pointer_p>) {
                        const units_t cast = pointer;
                        CHECK(cast == unit);
                    } else {
                        units_t cast = pointer;
                        CHECK(cast == unit);
                    }
                }

                TEST_CASE_TEMPLATE("should allow assignment to the units", pointer_p, nkr_NON_CONST)
                {
                    using unit_t = pointer_p::unit_t;
                    using units_t = pointer_p::units_t;

                    unit_t* unit_a = Random<unit_t*>();
                    unit_t* unit_b = Random<unit_t*>();
                    pointer_p pointer(unit_a);
                    if constexpr (any_volatile_tr<pointer_p>) {
                        static_cast<volatile units_t&>(pointer) = unit_b;
                        CHECK(pointer.Unit() == unit_b);
                    } else {
                        static_cast<units_t&>(pointer) = unit_b;
                        CHECK(pointer.Unit() == unit_b);
                    }
                }

                TEST_CASE_TEMPLATE("should implicitly allow for logical operators", pointer_p, nkr_ALL)
                {
                    using unit_t = pointer_p::unit_t;
                    using units_t = pointer_p::units_t;

                    unit_t* unit;
                    do {
                        unit = Random<unit_t*>();
                    } while (unit == nullptr);
                    pointer_p pointer(unit);
                    CHECK(pointer);
                    CHECK(!!pointer);
                    CHECK(pointer || false);
                    CHECK(pointer && true);
                    CHECK(pointer ? true : false);
                }

                TEST_CASE_TEMPLATE("should implicitly allow for comparison operators", pointer_p, nkr_ALL)
                {
                    using unit_t = pointer_p::unit_t;
                    using units_t = pointer_p::units_t;

                    unit_t* unit = Random<unit_t*>();
                    pointer_p pointer(unit);
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
                TEST_CASE_TEMPLATE("should return the units", pointer_p, nkr_ALL)
                {
                    using unit_t = pointer_p::unit_t;
                    using units_t = pointer_p::units_t;

                    unit_t* unit = Random<unit_t*>();
                    pointer_p pointer(unit);
                    CHECK(pointer() == unit);
                }

                TEST_CASE_TEMPLATE("should allow assignment to the units", pointer_p, nkr_NON_CONST)
                {
                    using unit_t = pointer_p::unit_t;
                    using units_t = pointer_p::units_t;

                    unit_t* unit_a = Random<unit_t*>();
                    unit_t* unit_b = Random<unit_t*>();
                    pointer_p pointer(unit_a);
                    pointer() = unit_b;
                    CHECK(pointer.Unit() == unit_b);
                }
            }

            TEST_SUITE("()(unit_t*)")
            {
                TEST_CASE_TEMPLATE("should set passed unit", pointer_p, nkr_NON_CONST)
                {
                    using unit_t = pointer_p::unit_t;
                    using units_t = pointer_p::units_t;

                    unit_t* unit = Random<unit_t*>();
                    pointer_p pointer;
                    pointer(unit);
                    CHECK(pointer.Unit() == unit);
                }

                TEST_CASE("should convert and set passed unit")
                {
                    struct base_t {};
                    struct derived_t : base_t {};

                    derived_t* unit = Random<derived_t*>();
                    pointer_t<base_t> pointer;
                    pointer(unit);
                    CHECK(pointer.Unit() == static_cast<base_t*>(unit));
                }

                TEST_CASE_TEMPLATE("should set unit_count to 0 if passed nullptr", pointer_p, nkr_NON_CONST)
                {
                    using unit_t = pointer_p::unit_t;
                    using units_t = pointer_p::units_t;

                    pointer_p pointer;
                    pointer(nullptr);
                    CHECK(pointer.Unit_Count() == 0);
                }

                TEST_CASE_TEMPLATE("should set unit_count to 1 if passed non-nullptr", pointer_p, nkr_NON_CONST)
                {
                    using unit_t = pointer_p::unit_t;
                    using units_t = pointer_p::units_t;

                    unit_t* unit;
                    do {
                        unit = Random<unit_t*>();
                    } while (unit == nullptr);
                    pointer_p pointer;
                    pointer(unit);
                    CHECK(pointer.Unit_Count() == 1);
                }

                TEST_CASE_TEMPLATE("should return itself", pointer_p, nkr_NON_CONST)
                {
                    using unit_t = pointer_p::unit_t;
                    using units_t = pointer_p::units_t;

                    unit_t* unit = Random<unit_t*>();
                    pointer_p pointer;
                    CHECK(&pointer(unit) == &pointer);
                }
            }

            TEST_SUITE("()(units_t, count_t)")
            {
                TEST_CASE_TEMPLATE("should set passed units and unit_count", pointer_p, nkr_NON_CONST)
                {
                    using unit_t = pointer_p::unit_t;
                    using units_t = pointer_p::units_t;

                    unit_t* units;
                    do {
                        units = Random<unit_t*>();
                    } while (units == nullptr);
                    count_t unit_count;
                    do {
                        unit_count = Random<count_t>();
                    } while (unit_count == 0);
                    pointer_p pointer;
                    pointer(units, unit_count);
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
                    pointer_t<base_t> pointer;
                    pointer(units, unit_count);
                    CHECK(pointer.Units() == static_cast<base_t*>(units));
                    CHECK(pointer.Unit_Count() == unit_count);
                }

                TEST_CASE_TEMPLATE("should allow a nullptr units and a 0 unit_count", pointer_p, nkr_NON_CONST)
                {
                    using unit_t = pointer_p::unit_t;
                    using units_t = pointer_p::units_t;

                    pointer_p pointer;
                    pointer(nullptr, 0);
                    CHECK(pointer.Units() == nullptr);
                    CHECK(pointer.Unit_Count() == 0);
                }

                TEST_CASE_TEMPLATE("should return itself", pointer_p, nkr_NON_CONST)
                {
                    using unit_t = pointer_p::unit_t;
                    using units_t = pointer_p::units_t;

                    unit_t* units;
                    do {
                        units = Random<unit_t*>();
                    } while (units == nullptr);
                    count_t unit_count;
                    do {
                        unit_count = Random<count_t>();
                    } while (unit_count == 0);
                    pointer_p pointer;
                    CHECK(&pointer(units, unit_count) == &pointer);
                }
            }

            TEST_SUITE("+()")
            {
                TEST_CASE_TEMPLATE("should return a new instance with units + amount and unit_count - amount", pointer_p, nkr_ALL)
                {
                    using unit_t = pointer_p::unit_t;
                    using units_t = pointer_p::units_t;

                    if constexpr (any_type_tr<unit_t>) {
                        units_t units;
                        do {
                            units = Random<units_t>();
                        } while (units == nullptr);
                        count_t unit_count = Random<count_t>(0x1, 0xFFFF);
                        count_t amount = Random<count_t>(0, unit_count);
                        pointer_p pointer_a(units, unit_count);
                        pointer_p pointer_b = pointer_a + amount;
                        CHECK(pointer_b.Units() == units + amount);
                        CHECK(pointer_b.Unit_Count() == unit_count - amount);
                    }
                }

                TEST_CASE_TEMPLATE("should not change its value", pointer_p, nkr_ALL)
                {
                    using unit_t = pointer_p::unit_t;
                    using units_t = pointer_p::units_t;

                    if constexpr (any_type_tr<unit_t>) {
                        units_t units;
                        do {
                            units = Random<units_t>();
                        } while (units == nullptr);
                        count_t unit_count = Random<count_t>(0x1, 0xFFFF);
                        count_t amount = Random<count_t>(0, unit_count);
                        pointer_p pointer_a(units, unit_count);
                        pointer_p pointer_b = pointer_a + amount;
                        CHECK(pointer_a.Units() == units);
                        CHECK(pointer_a.Unit_Count() == unit_count);
                    }
                }

                TEST_CASE_TEMPLATE("should work with any integer", pointer_p, nkr_ALL)
                {
                    using unit_t = pointer_p::unit_t;
                    using units_t = pointer_p::units_t;

                    if constexpr (any_type_tr<unit_t>) {
                        units_t units;
                        do {
                            units = Random<units_t>();
                        } while (units == nullptr);
                        count_t unit_count = Random<count_t>(0x1, 0xFFFF);
                        s8_t amount = Random<s8_t>(0, std::numeric_limits<s8_t>::max());
                        pointer_p pointer_a(units, unit_count);
                        pointer_p pointer_b = pointer_a + amount;
                        CHECK(pointer_b.Units() == units + amount);
                        CHECK(pointer_b.Unit_Count() == unit_count - amount);
                    }
                }
            }

            TEST_SUITE("-()")
            {
                TEST_CASE_TEMPLATE("should return a new instance with units - amount and unit_count + amount", pointer_p, nkr_ALL)
                {
                    using unit_t = pointer_p::unit_t;
                    using units_t = pointer_p::units_t;

                    if constexpr (any_type_tr<unit_t>) {
                        units_t units;
                        do {
                            units = Random<units_t>();
                        } while (units == nullptr);
                        count_t unit_count = Random<count_t>(0x1, 0xFFFF);
                        count_t amount = Random<count_t>(0, unit_count);
                        pointer_p pointer_a(units, unit_count);
                        pointer_p pointer_b = pointer_a - amount;
                        CHECK(pointer_b.Units() == units - amount);
                        CHECK(pointer_b.Unit_Count() == unit_count + amount);
                    }
                }

                TEST_CASE_TEMPLATE("should not change its value", pointer_p, nkr_ALL)
                {
                    using unit_t = pointer_p::unit_t;
                    using units_t = pointer_p::units_t;

                    if constexpr (any_type_tr<unit_t>) {
                        units_t units;
                        do {
                            units = Random<units_t>();
                        } while (units == nullptr);
                        count_t unit_count = Random<count_t>(0x1, 0xFFFF);
                        count_t amount = Random<count_t>(0, unit_count);
                        pointer_p pointer_a(units, unit_count);
                        pointer_p pointer_b = pointer_a - amount;
                        CHECK(pointer_a.Units() == units);
                        CHECK(pointer_a.Unit_Count() == unit_count);
                    }
                }

                TEST_CASE_TEMPLATE("should work with any integer", pointer_p, nkr_ALL)
                {
                    using unit_t = pointer_p::unit_t;
                    using units_t = pointer_p::units_t;

                    if constexpr (any_type_tr<unit_t>) {
                        units_t units;
                        do {
                            units = Random<units_t>();
                        } while (units == nullptr);
                        count_t unit_count = Random<count_t>(0x1, 0xFFFF);
                        s8_t amount = Random<s8_t>(0, std::numeric_limits<s8_t>::max());
                        pointer_p pointer_a(units, unit_count);
                        pointer_p pointer_b = pointer_a - amount;
                        CHECK(pointer_b.Units() == units - amount);
                        CHECK(pointer_b.Unit_Count() == unit_count + amount);
                    }
                }
            }

            TEST_SUITE("+=()")
            {
                TEST_CASE_TEMPLATE("should set units += amount and unit_count -= amount", pointer_p, nkr_NON_CONST)
                {
                    using unit_t = pointer_p::unit_t;
                    using units_t = pointer_p::units_t;

                    if constexpr (any_type_tr<unit_t>) {
                        units_t units;
                        do {
                            units = Random<units_t>();
                        } while (units == nullptr);
                        count_t unit_count = Random<count_t>(0x1, 0xFFFF);
                        count_t amount = Random<count_t>(0, unit_count);
                        pointer_p pointer(units, unit_count);
                        pointer += amount;
                        CHECK(pointer.Units() == (units += amount));
                        CHECK(pointer.Unit_Count() == (unit_count -= amount));
                    }
                }

                TEST_CASE_TEMPLATE("should return itself", pointer_p, nkr_NON_CONST)
                {
                    using unit_t = pointer_p::unit_t;
                    using units_t = pointer_p::units_t;

                    if constexpr (any_type_tr<unit_t>) {
                        units_t units;
                        do {
                            units = Random<units_t>();
                        } while (units == nullptr);
                        count_t unit_count = Random<count_t>(0x1, 0xFFFF);
                        count_t amount = Random<count_t>(0, unit_count);
                        pointer_p pointer(units, unit_count);
                        CHECK(&(pointer += amount) == &pointer);
                    }
                }

                TEST_CASE_TEMPLATE("should work with any integer", pointer_p, nkr_NON_CONST)
                {
                    using unit_t = pointer_p::unit_t;
                    using units_t = pointer_p::units_t;

                    if constexpr (any_type_tr<unit_t>) {
                        units_t units;
                        do {
                            units = Random<units_t>();
                        } while (units == nullptr);
                        count_t unit_count = Random<count_t>(0x1, 0xFFFF);
                        s8_t amount = Random<s8_t>(0, std::numeric_limits<s8_t>::max());
                        pointer_p pointer(units, unit_count);
                        pointer += amount;
                        CHECK(pointer.Units() == (units += amount));
                        CHECK(pointer.Unit_Count() == (unit_count -= amount));
                    }
                }
            }

            TEST_SUITE("-=()")
            {
                TEST_CASE_TEMPLATE("should set units -= amount and unit_count += amount", pointer_p, nkr_NON_CONST)
                {
                    using unit_t = pointer_p::unit_t;
                    using units_t = pointer_p::units_t;

                    if constexpr (any_type_tr<unit_t>) {
                        units_t units;
                        do {
                            units = Random<units_t>();
                        } while (units == nullptr);
                        count_t unit_count = Random<count_t>(0x1, 0xFFFF);
                        count_t amount = Random<count_t>(0, unit_count);
                        pointer_p pointer(units, unit_count);
                        pointer -= amount;
                        CHECK(pointer.Units() == (units -= amount));
                        CHECK(pointer.Unit_Count() == (unit_count += amount));
                    }
                }

                TEST_CASE_TEMPLATE("should return itself", pointer_p, nkr_NON_CONST)
                {
                    using unit_t = pointer_p::unit_t;
                    using units_t = pointer_p::units_t;

                    if constexpr (any_type_tr<unit_t>) {
                        units_t units;
                        do {
                            units = Random<units_t>();
                        } while (units == nullptr);
                        count_t unit_count = Random<count_t>(0x1, 0xFFFF);
                        count_t amount = Random<count_t>(0, unit_count);
                        pointer_p pointer(units, unit_count);
                        CHECK(&(pointer -= amount) == &pointer);
                    }
                }

                TEST_CASE_TEMPLATE("should work with any integer", pointer_p, nkr_NON_CONST)
                {
                    using unit_t = pointer_p::unit_t;
                    using units_t = pointer_p::units_t;

                    if constexpr (any_type_tr<unit_t>) {
                        units_t units;
                        do {
                            units = Random<units_t>();
                        } while (units == nullptr);
                        count_t unit_count = Random<count_t>(0x1, 0xFFFF);
                        s8_t amount = Random<s8_t>(0, std::numeric_limits<s8_t>::max());
                        pointer_p pointer(units, unit_count);
                        pointer -= amount;
                        CHECK(pointer.Units() == (units -= amount));
                        CHECK(pointer.Unit_Count() == (unit_count += amount));
                    }
                }
            }

            TEST_SUITE("++()")
            {
                TEST_CASE_TEMPLATE("should set units += 1 and unit_count -= 1", pointer_p, nkr_NON_CONST)
                {
                    using unit_t = pointer_p::unit_t;
                    using units_t = pointer_p::units_t;

                    if constexpr (any_type_tr<unit_t>) {
                        units_t units;
                        do {
                            units = Random<units_t>();
                        } while (units == nullptr);
                        count_t unit_count = Random<count_t>(0x1, 0xFFFF);
                        pointer_p pointer(units, unit_count);
                        ++pointer;
                        CHECK(pointer.Units() == (units += 1));
                        CHECK(pointer.Unit_Count() == (unit_count -= 1));
                    }
                }

                TEST_CASE_TEMPLATE("should return itself with the new value", pointer_p, nkr_NON_CONST)
                {
                    using unit_t = pointer_p::unit_t;
                    using units_t = pointer_p::units_t;

                    if constexpr (any_type_tr<unit_t>) {
                        units_t units;
                        do {
                            units = Random<units_t>();
                        } while (units == nullptr);
                        count_t unit_count = Random<count_t>(0x1, 0xFFFF);
                        pointer_p pointer(units, unit_count);
                        CHECK((++pointer).Units() == (units += 1));
                    }
                }
            }

            TEST_SUITE("++(int)")
            {
                TEST_CASE_TEMPLATE("should set units += 1 and unit_count -= 1", pointer_p, nkr_NON_CONST)
                {
                    using unit_t = pointer_p::unit_t;
                    using units_t = pointer_p::units_t;

                    if constexpr (any_type_tr<unit_t>) {
                        units_t units;
                        do {
                            units = Random<units_t>();
                        } while (units == nullptr);
                        count_t unit_count = Random<count_t>(0x1, 0xFFFF);
                        pointer_p pointer(units, unit_count);
                        pointer++;
                        CHECK(pointer.Units() == (units += 1));
                        CHECK(pointer.Unit_Count() == (unit_count -= 1));
                    }
                }

                TEST_CASE_TEMPLATE("should return a copy of the old pointer", pointer_p, nkr_NON_CONST)
                {
                    using unit_t = pointer_p::unit_t;
                    using units_t = pointer_p::units_t;

                    if constexpr (any_type_tr<unit_t>) {
                        units_t units;
                        do {
                            units = Random<units_t>();
                        } while (units == nullptr);
                        count_t unit_count = Random<count_t>(0x1, 0xFFFF);
                        pointer_p pointer(units, unit_count);
                        CHECK((pointer++).Units() == units);
                    }
                }
            }

            TEST_SUITE("--()")
            {
                TEST_CASE_TEMPLATE("should set units -= 1 and unit_count += 1", pointer_p, nkr_NON_CONST)
                {
                    using unit_t = pointer_p::unit_t;
                    using units_t = pointer_p::units_t;

                    if constexpr (any_type_tr<unit_t>) {
                        units_t units;
                        do {
                            units = Random<units_t>();
                        } while (units == nullptr);
                        count_t unit_count = Random<count_t>(0x1, 0xFFFF);
                        pointer_p pointer(units, unit_count);
                        --pointer;
                        CHECK(pointer.Units() == (units -= 1));
                        CHECK(pointer.Unit_Count() == (unit_count += 1));
                    }
                }

                TEST_CASE_TEMPLATE("should return itself with the new value", pointer_p, nkr_NON_CONST)
                {
                    using unit_t = pointer_p::unit_t;
                    using units_t = pointer_p::units_t;

                    if constexpr (any_type_tr<unit_t>) {
                        units_t units;
                        do {
                            units = Random<units_t>();
                        } while (units == nullptr);
                        count_t unit_count = Random<count_t>(0x1, 0xFFFF);
                        pointer_p pointer(units, unit_count);
                        CHECK((--pointer).Units() == (units -= 1));
                    }
                }
            }

            TEST_SUITE("--(int)")
            {
                TEST_CASE_TEMPLATE("should set units -= 1 and unit_count += 1", pointer_p, nkr_NON_CONST)
                {
                    using unit_t = pointer_p::unit_t;
                    using units_t = pointer_p::units_t;

                    if constexpr (any_type_tr<unit_t>) {
                        units_t units;
                        do {
                            units = Random<units_t>();
                        } while (units == nullptr);
                        count_t unit_count = Random<count_t>(0x1, 0xFFFF);
                        pointer_p pointer(units, unit_count);
                        pointer--;
                        CHECK(pointer.Units() == (units -= 1));
                        CHECK(pointer.Unit_Count() == (unit_count += 1));
                    }
                }

                TEST_CASE_TEMPLATE("should return a copy of the old pointer", pointer_p, nkr_NON_CONST)
                {
                    using unit_t = pointer_p::unit_t;
                    using units_t = pointer_p::units_t;

                    if constexpr (any_type_tr<unit_t>) {
                        units_t units;
                        do {
                            units = Random<units_t>();
                        } while (units == nullptr);
                        count_t unit_count = Random<count_t>(0x1, 0xFFFF);
                        pointer_p pointer(units, unit_count);
                        CHECK((pointer--).Units() == units);
                    }
                }
            }

            TEST_SUITE("->()")
            {
                TEST_CASE_TEMPLATE("should be able to access the first unit's values", pointer_p, nkr_REGULAR)
                {
                    using unit_t = pointer_p::unit_t;
                    using units_t = pointer_p::units_t;

                    if constexpr (any_type_tr<unit_t>) {
                        unit_t* random = Random<unit_t*>();
                        struct wrap_t { unit_t* random; } wrap(random);
                        const pointer_t<wrap_t> pointer(&wrap);
                        CHECK(pointer->random == random);
                    }
                }

                TEST_CASE_TEMPLATE("should be able to assign the first unit's values", pointer_p, nkr_REGULAR)
                {
                    using unit_t = pointer_p::unit_t;
                    using units_t = pointer_p::units_t;

                    if constexpr (any_type_tr<unit_t>) {
                        unit_t* random_a = Random<unit_t*>();
                        unit_t* random_b = Random<unit_t*>();
                        struct wrap_t { unit_t* random; } wrap(random_a);
                        const pointer_t<wrap_t> pointer(&wrap);
                        pointer->random = random_b;
                        CHECK(wrap.random == random_b);
                    }
                }

                TEST_CASE_TEMPLATE("should not change the units when assigning", pointer_p, nkr_REGULAR)
                {
                    using unit_t = pointer_p::unit_t;
                    using units_t = pointer_p::units_t;

                    if constexpr (any_type_tr<unit_t>) {
                        unit_t* random_a = Random<unit_t*>();
                        unit_t* random_b = Random<unit_t*>();
                        struct wrap_t { unit_t* random; } wrap(random_a);
                        const pointer_t<wrap_t> pointer(&wrap);
                        pointer->random = random_b;
                        CHECK(pointer.Units() == &wrap);
                    }
                }
            }

            TEST_SUITE("*()")
            {
                TEST_CASE_TEMPLATE("should be able to access the first unit's value", pointer_p, nkr_ALL)
                {
                    using unit_t = pointer_p::unit_t;
                    using units_t = pointer_p::units_t;

                    if constexpr (any_type_tr<unit_t>) {
                        unit_t random = Random<unit_t>();
                        pointer_p pointer(&random);
                        CHECK(*pointer == random);
                    }
                }

                TEST_CASE_TEMPLATE("should be able to assign the first unit's value", pointer_p, nkr_ALL)
                {
                    using unit_t = pointer_p::unit_t;
                    using units_t = pointer_p::units_t;

                    if constexpr (any_type_tr<unit_t> && any_non_const_tr<unit_t>) {
                        unit_t random_a = Random<unit_t>();
                        unit_t random_b = Random<unit_t>();
                        pointer_p pointer(&random_a);
                        *pointer = random_b;
                        CHECK(random_a == random_b);
                    }
                }

                TEST_CASE_TEMPLATE("should not change the units when assigning", pointer_p, nkr_ALL)
                {
                    using unit_t = pointer_p::unit_t;
                    using units_t = pointer_p::units_t;

                    if constexpr (any_type_tr<unit_t> && any_non_const_tr<unit_t>) {
                        unit_t random_a = Random<unit_t>();
                        unit_t random_b = Random<unit_t>();
                        pointer_p pointer(&random_a);
                        *pointer = random_b;
                        CHECK(pointer.Units() == &random_a);
                    }
                }
            }

            TEST_SUITE("[]()")
            {
                TEST_CASE_TEMPLATE("should be able to access the indexed unit's value", pointer_p, nkr_ALL)
                {
                    using unit_t = pointer_p::unit_t;
                    using units_t = pointer_p::units_t;

                    if constexpr (any_type_tr<unit_t>) {
                        std::remove_const_t<unit_t> randoms[16];
                        for (index_t idx = 0, end = 16; idx < end; idx += 1) {
                            randoms[idx] = Random<std::remove_const_t<unit_t>>();
                        }
                        pointer_p pointer(randoms, sizeof(randoms) / sizeof(unit_t));
                        index_t index = Random<index_t>(0, 15);
                        CHECK(pointer[index] == randoms[index]);
                    }
                }

                TEST_CASE_TEMPLATE("should be able to assign the indexed unit's value", pointer_p, nkr_ALL)
                {
                    using unit_t = pointer_p::unit_t;
                    using units_t = pointer_p::units_t;

                    if constexpr (any_type_tr<unit_t> && any_non_const_tr<unit_t>) {
                        unit_t randoms[16];
                        for (index_t idx = 0, end = 16; idx < end; idx += 1) {
                            randoms[idx] = Random<unit_t>();
                        }
                        pointer_p pointer(randoms, sizeof(randoms) / sizeof(unit_t));
                        index_t index = Random<index_t>(0, 15);
                        unit_t random = Random<unit_t>();
                        pointer[index] = random;
                        CHECK(randoms[index] == random);
                    }
                }

                TEST_CASE_TEMPLATE("should not change the units when assigning", pointer_p, nkr_ALL)
                {
                    using unit_t = pointer_p::unit_t;
                    using units_t = pointer_p::units_t;

                    if constexpr (any_type_tr<unit_t> && any_non_const_tr<unit_t>) {
                        unit_t randoms[16];
                        for (index_t idx = 0, end = 16; idx < end; idx += 1) {
                            randoms[idx] = Random<unit_t>();
                        }
                        pointer_p pointer(randoms, sizeof(randoms) / sizeof(unit_t));
                        index_t index = Random<index_t>(0, 15);
                        unit_t random = Random<unit_t>();
                        pointer[index] = random;
                        CHECK(pointer.Units() == randoms);
                    }
                }
            }
        }
    }

}
