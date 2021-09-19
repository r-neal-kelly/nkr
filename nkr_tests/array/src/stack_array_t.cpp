/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/intrinsics.h"
#include "nkr/random.h"
#include "nkr/utils.h"

#include "nkr/array/stack_t.h"

#include "doctest.h"

namespace nkr {

    TEST_SUITE("stack_array_t<unit_p, capacity_p>")
    {
    #define nkr_ALL_PARAMS(QUALIFIER_p, UNIT_p, CAPACITY_p)             \
        QUALIFIER_p stack_array_t<UNIT_p, CAPACITY_p>,                  \
        QUALIFIER_p stack_array_t<const UNIT_p, CAPACITY_p>,            \
        QUALIFIER_p stack_array_t<volatile UNIT_p, CAPACITY_p>,         \
        QUALIFIER_p stack_array_t<volatile const UNIT_p, CAPACITY_p>

    #define nkr_CAPACITIES(QUALIFIER_p, UNIT_p) \
        nkr_ALL_PARAMS(QUALIFIER_p, UNIT_p, 16)

    #define nkr_UNITS(QUALIFIER_p)                  \
        nkr_CAPACITIES(QUALIFIER_p, std_bool_t),    \
        nkr_CAPACITIES(QUALIFIER_p, bool_t),        \
        nkr_CAPACITIES(QUALIFIER_p, void_t*)

    #define nkr_UNQUALIFIED     \
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
                TEST_CASE_TEMPLATE("should have a unit_t", stack_array_p, nkr_ALL)
                {
                    using unit_t = stack_array_p::unit_t;
                    using writable_unit_t = stack_array_p::writable_unit_t;
                    using array_t = stack_array_p::array_t;
                    using writable_array_t = stack_array_p::writable_array_t;

                    static_assert(same_as_tr<unit_t, unit_t>);
                }
            }

            TEST_SUITE("writable_unit_t")
            {
                TEST_CASE_TEMPLATE("should have a writable_unit_t that is non-const", stack_array_p, nkr_ALL)
                {
                    using unit_t = stack_array_p::unit_t;
                    using writable_unit_t = stack_array_p::writable_unit_t;
                    using array_t = stack_array_p::array_t;
                    using writable_array_t = stack_array_p::writable_array_t;

                    static_assert(same_as_tr<writable_unit_t, std::remove_const_t<unit_t>>);
                }
            }

            TEST_SUITE("array_t")
            {
                TEST_CASE_TEMPLATE("should have an array_t of unit_t[Capacity()]", stack_array_p, nkr_ALL)
                {
                    using unit_t = stack_array_p::unit_t;
                    using writable_unit_t = stack_array_p::writable_unit_t;
                    using array_t = stack_array_p::array_t;
                    using writable_array_t = stack_array_p::writable_array_t;

                    static_assert(same_as_tr<array_t, unit_t[stack_array_p::Capacity()]>);
                }
            }

            TEST_SUITE("writable_array_t")
            {
                TEST_CASE_TEMPLATE("should have an writable_array_t of writable_unit_t[Capacity()]", stack_array_p, nkr_ALL)
                {
                    using unit_t = stack_array_p::unit_t;
                    using writable_unit_t = stack_array_p::writable_unit_t;
                    using array_t = stack_array_p::array_t;
                    using writable_array_t = stack_array_p::writable_array_t;

                    static_assert(same_as_tr<writable_array_t, writable_unit_t[stack_array_p::Capacity()]>);
                }
            }
        }

        TEST_SUITE("static methods")
        {
            TEST_SUITE("Capacity()")
            {
                TEST_CASE_TEMPLATE("should return the unit_count of the underlying array_t", stack_array_p, nkr_ALL)
                {
                    using unit_t = stack_array_p::unit_t;
                    using writable_unit_t = stack_array_p::writable_unit_t;
                    using array_t = stack_array_p::array_t;
                    using writable_array_t = stack_array_p::writable_array_t;

                    CHECK(stack_array_p::Capacity() == sizeof(array_t) / sizeof(unit_t));
                }
            }
        }

        TEST_SUITE("objects")
        {
            TEST_SUITE("default_ctor()")
            {
                TEST_CASE_TEMPLATE("should have a count of 0", stack_array_p, nkr_ALL)
                {
                    using unit_t = stack_array_p::unit_t;
                    using writable_unit_t = stack_array_p::writable_unit_t;
                    using array_t = stack_array_p::array_t;
                    using writable_array_t = stack_array_p::writable_array_t;

                    stack_array_p stack_array;
                    CHECK(stack_array.Count() == 0);
                }
            }

            TEST_SUITE("copy_initializer_list_ctor()")
            {
                TEST_CASE_TEMPLATE("should copy arguments, set count, and not change the source", stack_array_p, nkr_ALL)
                {
                    using unit_t = stack_array_p::unit_t;
                    using writable_unit_t = stack_array_p::writable_unit_t;
                    using array_t = stack_array_p::array_t;
                    using writable_array_t = stack_array_p::writable_array_t;

                    array_t array = {
                        Random<unit_t>(), Random<unit_t>(), Random<unit_t>(), Random<unit_t>(),
                        Random<unit_t>(), Random<unit_t>(), Random<unit_t>(), Random<unit_t>(),
                        Random<unit_t>(), Random<unit_t>(), Random<unit_t>(), Random<unit_t>(),
                        Random<unit_t>(), Random<unit_t>(), Random<unit_t>(), Random<unit_t>(),
                    };
                    stack_array_p stack_array = {
                        array[0], array[1], array[2], array[3],
                        array[4], array[5], array[6], array[7],
                        array[8], array[9], array[10], array[11],
                        array[12], array[13], array[14], array[15],
                    };
                    CHECK(stack_array.Count() == 16);
                    for (index_t idx = 0, end = stack_array.Count(); idx < end; idx += 1) {
                        CHECK(stack_array[idx] == array[idx]);
                    }
                }

                TEST_CASE_TEMPLATE("should only copy upto the argument count, even if it has more capacity", stack_array_p, nkr_ALL)
                {
                    using unit_t = stack_array_p::unit_t;
                    using writable_unit_t = stack_array_p::writable_unit_t;
                    using array_t = stack_array_p::array_t;
                    using writable_array_t = stack_array_p::writable_array_t;

                    array_t array = {
                        Random<unit_t>(), Random<unit_t>(), Random<unit_t>(), Random<unit_t>(),
                        Random<unit_t>(), Random<unit_t>(), Random<unit_t>(), Random<unit_t>(),
                    };
                    stack_array_p stack_array = {
                        array[0], array[1], array[2], array[3],
                        array[4], array[5], array[6], array[7],
                    };
                    CHECK(stack_array.Count() == 8);
                    CHECK(stack_array.Count() < stack_array.Capacity());
                    for (index_t idx = 0, end = stack_array.Count(); idx < end; idx += 1) {
                        CHECK(stack_array[idx] == array[idx]);
                    }
                }
            }

            TEST_SUITE("move_initializer_list_ctor()")
            {
                TEST_CASE_TEMPLATE("should move arguments, set count, and default the source", stack_array_p, nkr_ALL)
                {
                    using unit_t = stack_array_p::unit_t;
                    using writable_unit_t = stack_array_p::writable_unit_t;
                    using array_t = stack_array_p::array_t;
                    using writable_array_t = stack_array_p::writable_array_t;

                    writable_array_t array = {
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                    };
                    writable_array_t backup = {
                        array[0], array[1],
                        array[2], array[3],
                        array[4], array[5],
                        array[6], array[7],
                        array[8], array[9],
                        array[10], array[11],
                        array[12], array[13],
                        array[14], array[15],
                    };
                    stack_array_p stack_array = {
                        nkr::Move(array[0]), nkr::Move(array[1]),
                        nkr::Move(array[2]), nkr::Move(array[3]),
                        nkr::Move(array[4]), nkr::Move(array[5]),
                        nkr::Move(array[6]), nkr::Move(array[7]),
                        nkr::Move(array[8]), nkr::Move(array[9]),
                        nkr::Move(array[10]), nkr::Move(array[11]),
                        nkr::Move(array[12]), nkr::Move(array[13]),
                        nkr::Move(array[14]), nkr::Move(array[15]),
                    };
                    CHECK(stack_array.Count() == 16);
                    for (index_t idx = 0, end = stack_array.Count(); idx < end; idx += 1) {
                        CHECK(stack_array[idx] == backup[idx]);
                    }
                    for (index_t idx = 0, end = sizeof(array) / sizeof(writable_unit_t); idx < end; idx += 1) {
                        CHECK(array[idx] == none_t());
                    }
                }

                TEST_CASE_TEMPLATE("should only copy upto the argument count, even if it has more capacity", stack_array_p, nkr_ALL)
                {
                    using unit_t = stack_array_p::unit_t;
                    using writable_unit_t = stack_array_p::writable_unit_t;
                    using array_t = stack_array_p::array_t;
                    using writable_array_t = stack_array_p::writable_array_t;

                    writable_array_t array = {
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                    };
                    writable_array_t backup = {
                        array[0], array[1],
                        array[2], array[3],
                        array[4], array[5],
                        array[6], array[7],
                    };
                    stack_array_p stack_array = {
                        nkr::Move(array[0]), nkr::Move(array[1]),
                        nkr::Move(array[2]), nkr::Move(array[3]),
                        nkr::Move(array[4]), nkr::Move(array[5]),
                        nkr::Move(array[6]), nkr::Move(array[7]),
                    };
                    CHECK(stack_array.Count() == 8);
                    for (index_t idx = 0, end = stack_array.Count(); idx < end; idx += 1) {
                        CHECK(stack_array[idx] == backup[idx]);
                    }
                    for (index_t idx = 0, end = sizeof(array) / sizeof(writable_unit_t); idx < end; idx += 1) {
                        CHECK(array[idx] == none_t());
                    }
                }
            }

            TEST_SUITE("copy_ctor()")
            {
                TEST_CASE_TEMPLATE("should explicitly or implicitly copy each unit and the count of other", stack_array_p, nkr_ALL)
                {
                    using unit_t = stack_array_p::unit_t;
                    using writable_unit_t = stack_array_p::writable_unit_t;
                    using array_t = stack_array_p::array_t;
                    using writable_array_t = stack_array_p::writable_array_t;

                    count_t count = Random<count_t>(1, 16);
                    std::remove_const_t<stack_array_p> other;
                    for (index_t idx = 0, end = count; idx < end; idx += 1) {
                        other.Push(Random<writable_unit_t>());
                    }
                    stack_array_p stack_array = other;
                    CHECK(stack_array.Count() == other.Count());
                    for (index_t idx = 0, end = stack_array.Count(); idx < end; idx += 1) {
                        CHECK(stack_array[idx] == other[idx]);
                    }
                }

                TEST_CASE_TEMPLATE("should not change the other", stack_array_p, nkr_ALL)
                {
                    using unit_t = stack_array_p::unit_t;
                    using writable_unit_t = stack_array_p::writable_unit_t;
                    using array_t = stack_array_p::array_t;
                    using writable_array_t = stack_array_p::writable_array_t;

                    count_t count = Random<count_t>(1, 16);
                    std::remove_const_t<stack_array_p> other;
                    std::remove_const_t<stack_array_p> backup;
                    for (index_t idx = 0, end = count; idx < end; idx += 1) {
                        unit_t random = Random<unit_t>();
                        other.Push(random);
                        backup.Push(random);
                    }
                    stack_array_p stack_array = other;
                    CHECK(other.Count() == backup.Count());
                    for (index_t idx = 0, end = other.Count(); idx < end; idx += 1) {
                        CHECK(other[idx] == backup[idx]);
                    }
                }
            }

            TEST_SUITE("move_ctor()")
            {
                TEST_CASE_TEMPLATE("should explicitly or implicitly move each unit and count of other", stack_array_p, nkr_ALL)
                {
                    using unit_t = stack_array_p::unit_t;
                    using writable_unit_t = stack_array_p::writable_unit_t;
                    using array_t = stack_array_p::array_t;
                    using writable_array_t = stack_array_p::writable_array_t;

                    count_t count = Random<count_t>(1, 16);
                    std::remove_const_t<stack_array_p> other;
                    std::remove_const_t<stack_array_p> backup;
                    for (index_t idx = 0, end = count; idx < end; idx += 1) {
                        unit_t random = Random<unit_t>();
                        other.Push(random);
                        backup.Push(random);
                    }
                    stack_array_p stack_array = nkr::Move(other);
                    CHECK(stack_array.Count() == backup.Count());
                    for (index_t idx = 0, end = stack_array.Count(); idx < end; idx += 1) {
                        CHECK(stack_array[idx] == backup[idx]);
                    }
                }

                TEST_CASE_TEMPLATE("should set the other to have none values", stack_array_p, nkr_ALL)
                {
                    using unit_t = stack_array_p::unit_t;
                    using writable_unit_t = stack_array_p::writable_unit_t;
                    using array_t = stack_array_p::array_t;
                    using writable_array_t = stack_array_p::writable_array_t;

                    count_t count = Random<count_t>(1, 16);
                    std::remove_const_t<stack_array_p> other;
                    for (index_t idx = 0, end = count; idx < end; idx += 1) {
                        other.Push(Random<writable_unit_t>());
                    }
                    stack_array_p stack_array = nkr::Move(other);
                    CHECK(other.Count() == 0);
                    for (index_t idx = 0, end = stack_array.Count(); idx < end; idx += 1) {
                        CHECK(other.Array()[idx] == none_t());
                    }
                }
            }

            TEST_SUITE("copy_assignment_ctor()")
            {
                TEST_CASE_TEMPLATE("should copy each unit and the count of other", stack_array_p, nkr_NON_CONST)
                {
                    using unit_t = stack_array_p::unit_t;
                    using writable_unit_t = stack_array_p::writable_unit_t;
                    using array_t = stack_array_p::array_t;
                    using writable_array_t = stack_array_p::writable_array_t;

                    count_t count = Random<count_t>(1, 16);
                    std::remove_const_t<stack_array_p> other;
                    for (index_t idx = 0, end = count; idx < end; idx += 1) {
                        other.Push(Random<writable_unit_t>());
                    }
                    stack_array_p stack_array;
                    stack_array = other;
                    CHECK(stack_array.Count() == other.Count());
                    for (index_t idx = 0, end = stack_array.Count(); idx < end; idx += 1) {
                        CHECK(stack_array[idx] == other[idx]);
                    }
                }

                TEST_CASE_TEMPLATE("should not change the other", stack_array_p, nkr_NON_CONST)
                {
                    using unit_t = stack_array_p::unit_t;
                    using writable_unit_t = stack_array_p::writable_unit_t;
                    using array_t = stack_array_p::array_t;
                    using writable_array_t = stack_array_p::writable_array_t;

                    count_t count = Random<count_t>(1, 16);
                    std::remove_const_t<stack_array_p> other;
                    std::remove_const_t<stack_array_p> backup;
                    for (index_t idx = 0, end = count; idx < end; idx += 1) {
                        unit_t random = Random<unit_t>();
                        other.Push(random);
                        backup.Push(random);
                    }
                    stack_array_p stack_array;
                    stack_array = other;
                    CHECK(other.Count() == backup.Count());
                    for (index_t idx = 0, end = other.Count(); idx < end; idx += 1) {
                        CHECK(other[idx] == backup[idx]);
                    }
                }

                TEST_CASE_TEMPLATE("should return itself", stack_array_p, nkr_NON_CONST)
                {
                    using unit_t = stack_array_p::unit_t;
                    using writable_unit_t = stack_array_p::writable_unit_t;
                    using array_t = stack_array_p::array_t;
                    using writable_array_t = stack_array_p::writable_array_t;

                    count_t count = Random<count_t>(1, 16);
                    std::remove_const_t<stack_array_p> other;
                    for (index_t idx = 0, end = count; idx < end; idx += 1) {
                        other.Push(Random<writable_unit_t>());
                    }
                    stack_array_p stack_array;
                    CHECK(&(stack_array = other) == &stack_array);
                }
            }

            TEST_SUITE("move_assignment_ctor()")
            {
                TEST_CASE_TEMPLATE("should move each unit and count of other", stack_array_p, nkr_NON_CONST)
                {
                    using unit_t = stack_array_p::unit_t;
                    using writable_unit_t = stack_array_p::writable_unit_t;
                    using array_t = stack_array_p::array_t;
                    using writable_array_t = stack_array_p::writable_array_t;

                    count_t count = Random<count_t>(1, 16);
                    std::remove_const_t<stack_array_p> other;
                    std::remove_const_t<stack_array_p> backup;
                    for (index_t idx = 0, end = count; idx < end; idx += 1) {
                        unit_t random = Random<unit_t>();
                        other.Push(random);
                        backup.Push(random);
                    }
                    stack_array_p stack_array;
                    stack_array = nkr::Move(other);
                    CHECK(stack_array.Count() == backup.Count());
                    for (index_t idx = 0, end = stack_array.Count(); idx < end; idx += 1) {
                        CHECK(stack_array[idx] == backup[idx]);
                    }
                }

                TEST_CASE_TEMPLATE("should set the other to have none values", stack_array_p, nkr_NON_CONST)
                {
                    using unit_t = stack_array_p::unit_t;
                    using writable_unit_t = stack_array_p::writable_unit_t;
                    using array_t = stack_array_p::array_t;
                    using writable_array_t = stack_array_p::writable_array_t;

                    count_t count = Random<count_t>(1, 16);
                    std::remove_const_t<stack_array_p> other;
                    for (index_t idx = 0, end = count; idx < end; idx += 1) {
                        other.Push(Random<writable_unit_t>());
                    }
                    stack_array_p stack_array;
                    stack_array = nkr::Move(other);
                    CHECK(other.Count() == 0);
                    for (index_t idx = 0, end = stack_array.Count(); idx < end; idx += 1) {
                        CHECK(other.Array()[idx] == none_t());
                    }
                }

                TEST_CASE_TEMPLATE("should return itself", stack_array_p, nkr_NON_CONST)
                {
                    using unit_t = stack_array_p::unit_t;
                    using writable_unit_t = stack_array_p::writable_unit_t;
                    using array_t = stack_array_p::array_t;
                    using writable_array_t = stack_array_p::writable_array_t;

                    count_t count = Random<count_t>(1, 16);
                    std::remove_const_t<stack_array_p> other;
                    std::remove_const_t<stack_array_p> backup;
                    for (index_t idx = 0, end = count; idx < end; idx += 1) {
                        unit_t random = Random<unit_t>();
                        other.Push(random);
                        backup.Push(random);
                    }
                    stack_array_p stack_array;
                    CHECK(&(stack_array = nkr::Move(other)) == &stack_array);
                }
            }

            TEST_SUITE("dtor()")
            {
                TEST_CASE_TEMPLATE("should set its values to default", stack_array_p, nkr_ALL)
                {
                    using unit_t = stack_array_p::unit_t;
                    using writable_unit_t = stack_array_p::writable_unit_t;
                    using array_t = stack_array_p::array_t;
                    using writable_array_t = stack_array_p::writable_array_t;

                    count_t count = Random<count_t>(1, 16);
                    std::remove_const_t<stack_array_p> other;
                    for (index_t idx = 0, end = count; idx < end; idx += 1) {
                        other.Push(Random<writable_unit_t>());
                    }
                    stack_array_p stack_array = other;
                    stack_array.~stack_array_p();
                    CHECK(stack_array.Count() == none_t());
                    for (index_t idx = 0, end = other.Count(); idx < end; idx += 1) {
                        CHECK(stack_array.Array()[idx] == none_t());
                    }
                }
            }
        }
    }

}
