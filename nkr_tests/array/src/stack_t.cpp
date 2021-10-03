/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/intrinsics.h"
#include "nkr/utils.h"

#include "nkr/array/stack_t.h"

#include "doctest.h"

namespace nkr { namespace array {

    TEST_SUITE("stack_t<unit_p, capacity_p>")
    {
    #define nkr_ALL_PARAMS(QUALIFIER_p, UNIT_p, CAPACITY_p)             \
        QUALIFIER_p stack_t<UNIT_p, CAPACITY_p>,                  \
        QUALIFIER_p stack_t<const UNIT_p, CAPACITY_p>,            \
        QUALIFIER_p stack_t<volatile UNIT_p, CAPACITY_p>,         \
        QUALIFIER_p stack_t<const volatile UNIT_p, CAPACITY_p>

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
        nkr_UNITS(const volatile)

    #define nkr_ALL     \
        nkr_NON_CONST,  \
        nkr_CONST

        TEST_SUITE("aliases")
        {
            TEST_SUITE("unit_t")
            {
                TEST_CASE_TEMPLATE("should have a unit_t", stack_p, nkr_ALL)
                {
                    using unit_t = stack_p::unit_t;
                    using writable_unit_t = stack_p::writable_unit_t;
                    using array_t = stack_p::array_t;
                    using writable_array_t = stack_p::writable_array_t;

                    static_assert(is_tr<unit_t, unit_t>);
                }
            }

            TEST_SUITE("writable_unit_t")
            {
                TEST_CASE_TEMPLATE("should have a writable_unit_t that is non-const", stack_p, nkr_ALL)
                {
                    using unit_t = stack_p::unit_t;
                    using writable_unit_t = stack_p::writable_unit_t;
                    using array_t = stack_p::array_t;
                    using writable_array_t = stack_p::writable_array_t;

                    static_assert(is_tr<writable_unit_t, std::remove_const_t<unit_t>>);
                }
            }

            TEST_SUITE("array_t")
            {
                TEST_CASE_TEMPLATE("should have an array_t of unit_t[Capacity()]", stack_p, nkr_ALL)
                {
                    using unit_t = stack_p::unit_t;
                    using writable_unit_t = stack_p::writable_unit_t;
                    using array_t = stack_p::array_t;
                    using writable_array_t = stack_p::writable_array_t;

                    static_assert(is_tr<array_t, unit_t[stack_p::Capacity()]>);
                }
            }

            TEST_SUITE("writable_array_t")
            {
                TEST_CASE_TEMPLATE("should have an writable_array_t of writable_unit_t[Capacity()]", stack_p, nkr_ALL)
                {
                    using unit_t = stack_p::unit_t;
                    using writable_unit_t = stack_p::writable_unit_t;
                    using array_t = stack_p::array_t;
                    using writable_array_t = stack_p::writable_array_t;

                    static_assert(is_tr<writable_array_t, writable_unit_t[stack_p::Capacity()]>);
                }
            }
        }

        TEST_SUITE("static methods")
        {
            TEST_SUITE("Capacity()")
            {
                TEST_CASE_TEMPLATE("should return the unit_count of the underlying array_t", stack_p, nkr_ALL)
                {
                    using unit_t = stack_p::unit_t;
                    using writable_unit_t = stack_p::writable_unit_t;
                    using array_t = stack_p::array_t;
                    using writable_array_t = stack_p::writable_array_t;

                    CHECK(stack_p::Capacity() == sizeof(array_t) / sizeof(unit_t));
                }
            }
        }

        TEST_SUITE("objects")
        {
            TEST_SUITE("default_ctor()")
            {
                TEST_CASE_TEMPLATE("should have a count of 0", stack_p, nkr_ALL)
                {
                    using unit_t = stack_p::unit_t;
                    using writable_unit_t = stack_p::writable_unit_t;
                    using array_t = stack_p::array_t;
                    using writable_array_t = stack_p::writable_array_t;

                    stack_p stack;
                    CHECK(stack.Count() == 0);
                }
            }

            TEST_SUITE("copy_initializer_list_ctor()")
            {
                TEST_CASE_TEMPLATE("should copy arguments, set count, and not change the source", stack_p, nkr_ALL)
                {
                    using unit_t = stack_p::unit_t;
                    using writable_unit_t = stack_p::writable_unit_t;
                    using array_t = stack_p::array_t;
                    using writable_array_t = stack_p::writable_array_t;

                    array_t array = {
                        Random<unit_t>(), Random<unit_t>(), Random<unit_t>(), Random<unit_t>(),
                        Random<unit_t>(), Random<unit_t>(), Random<unit_t>(), Random<unit_t>(),
                        Random<unit_t>(), Random<unit_t>(), Random<unit_t>(), Random<unit_t>(),
                        Random<unit_t>(), Random<unit_t>(), Random<unit_t>(), Random<unit_t>(),
                    };
                    stack_p stack = {
                        array[0], array[1], array[2], array[3],
                        array[4], array[5], array[6], array[7],
                        array[8], array[9], array[10], array[11],
                        array[12], array[13], array[14], array[15],
                    };
                    CHECK(stack.Count() == 16);
                    for (index_t idx = 0, end = stack.Count(); idx < end; idx += 1) {
                        CHECK(stack[idx] == array[idx]);
                    }
                }

                TEST_CASE_TEMPLATE("should only copy upto the argument count, even if it has more capacity", stack_p, nkr_ALL)
                {
                    using unit_t = stack_p::unit_t;
                    using writable_unit_t = stack_p::writable_unit_t;
                    using array_t = stack_p::array_t;
                    using writable_array_t = stack_p::writable_array_t;

                    array_t array = {
                        Random<unit_t>(), Random<unit_t>(), Random<unit_t>(), Random<unit_t>(),
                        Random<unit_t>(), Random<unit_t>(), Random<unit_t>(), Random<unit_t>(),
                    };
                    stack_p stack = {
                        array[0], array[1], array[2], array[3],
                        array[4], array[5], array[6], array[7],
                    };
                    CHECK(stack.Count() == 8);
                    CHECK(stack.Count() < stack.Capacity());
                    for (index_t idx = 0, end = stack.Count(); idx < end; idx += 1) {
                        CHECK(stack[idx] == array[idx]);
                    }
                }
            }

            TEST_SUITE("move_initializer_list_ctor()")
            {
                TEST_CASE_TEMPLATE("should move arguments, set count, and default the source", stack_p, nkr_ALL)
                {
                    using unit_t = stack_p::unit_t;
                    using writable_unit_t = stack_p::writable_unit_t;
                    using array_t = stack_p::array_t;
                    using writable_array_t = stack_p::writable_array_t;

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
                    stack_p stack = {
                        nkr::Move(array[0]), nkr::Move(array[1]),
                        nkr::Move(array[2]), nkr::Move(array[3]),
                        nkr::Move(array[4]), nkr::Move(array[5]),
                        nkr::Move(array[6]), nkr::Move(array[7]),
                        nkr::Move(array[8]), nkr::Move(array[9]),
                        nkr::Move(array[10]), nkr::Move(array[11]),
                        nkr::Move(array[12]), nkr::Move(array[13]),
                        nkr::Move(array[14]), nkr::Move(array[15]),
                    };
                    CHECK(stack.Count() == 16);
                    for (index_t idx = 0, end = stack.Count(); idx < end; idx += 1) {
                        CHECK(stack[idx] == backup[idx]);
                    }
                    for (index_t idx = 0, end = sizeof(array) / sizeof(writable_unit_t); idx < end; idx += 1) {
                        CHECK(array[idx] == none_t());
                    }
                }

                TEST_CASE_TEMPLATE("should only copy upto the argument count, even if it has more capacity", stack_p, nkr_ALL)
                {
                    using unit_t = stack_p::unit_t;
                    using writable_unit_t = stack_p::writable_unit_t;
                    using array_t = stack_p::array_t;
                    using writable_array_t = stack_p::writable_array_t;

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
                    stack_p stack = {
                        nkr::Move(array[0]), nkr::Move(array[1]),
                        nkr::Move(array[2]), nkr::Move(array[3]),
                        nkr::Move(array[4]), nkr::Move(array[5]),
                        nkr::Move(array[6]), nkr::Move(array[7]),
                    };
                    CHECK(stack.Count() == 8);
                    for (index_t idx = 0, end = stack.Count(); idx < end; idx += 1) {
                        CHECK(stack[idx] == backup[idx]);
                    }
                    for (index_t idx = 0, end = sizeof(array) / sizeof(writable_unit_t); idx < end; idx += 1) {
                        CHECK(array[idx] == none_t());
                    }
                }
            }

            TEST_SUITE("copy_ctor()")
            {
                TEST_CASE_TEMPLATE("should explicitly or implicitly copy each unit and the count of other", stack_p, nkr_ALL)
                {
                    using unit_t = stack_p::unit_t;
                    using writable_unit_t = stack_p::writable_unit_t;
                    using array_t = stack_p::array_t;
                    using writable_array_t = stack_p::writable_array_t;

                    count_t count = Random<count_t>(1, 16);
                    std::remove_const_t<stack_p> other;
                    for (index_t idx = 0, end = count; idx < end; idx += 1) {
                        other.Push(Random<writable_unit_t>()).Ignore_Error();
                    }
                    stack_p stack = other;
                    CHECK(stack.Count() == other.Count());
                    for (index_t idx = 0, end = stack.Count(); idx < end; idx += 1) {
                        CHECK(stack[idx] == other[idx]);
                    }
                }

                TEST_CASE_TEMPLATE("should not change the other", stack_p, nkr_ALL)
                {
                    using unit_t = stack_p::unit_t;
                    using writable_unit_t = stack_p::writable_unit_t;
                    using array_t = stack_p::array_t;
                    using writable_array_t = stack_p::writable_array_t;

                    count_t count = Random<count_t>(1, 16);
                    std::remove_const_t<stack_p> other;
                    std::remove_const_t<stack_p> backup;
                    for (index_t idx = 0, end = count; idx < end; idx += 1) {
                        unit_t random = Random<unit_t>();
                        other.Push(random).Ignore_Error();
                        backup.Push(random).Ignore_Error();
                    }
                    stack_p stack = other;
                    CHECK(other.Count() == backup.Count());
                    for (index_t idx = 0, end = other.Count(); idx < end; idx += 1) {
                        CHECK(other[idx] == backup[idx]);
                    }
                }
            }

            TEST_SUITE("move_ctor()")
            {
                TEST_CASE_TEMPLATE("should explicitly or implicitly move each unit and count of other", stack_p, nkr_ALL)
                {
                    using unit_t = stack_p::unit_t;
                    using writable_unit_t = stack_p::writable_unit_t;
                    using array_t = stack_p::array_t;
                    using writable_array_t = stack_p::writable_array_t;

                    count_t count = Random<count_t>(1, 16);
                    std::remove_const_t<stack_p> other;
                    std::remove_const_t<stack_p> backup;
                    for (index_t idx = 0, end = count; idx < end; idx += 1) {
                        unit_t random = Random<unit_t>();
                        other.Push(random).Ignore_Error();
                        backup.Push(random).Ignore_Error();
                    }
                    stack_p stack = nkr::Move(other);
                    CHECK(stack.Count() == backup.Count());
                    for (index_t idx = 0, end = stack.Count(); idx < end; idx += 1) {
                        CHECK(stack[idx] == backup[idx]);
                    }
                }

                TEST_CASE_TEMPLATE("should set the other to have none values", stack_p, nkr_ALL)
                {
                    using unit_t = stack_p::unit_t;
                    using writable_unit_t = stack_p::writable_unit_t;
                    using array_t = stack_p::array_t;
                    using writable_array_t = stack_p::writable_array_t;

                    count_t count = Random<count_t>(1, 16);
                    std::remove_const_t<stack_p> other;
                    for (index_t idx = 0, end = count; idx < end; idx += 1) {
                        other.Push(Random<writable_unit_t>()).Ignore_Error();
                    }
                    stack_p stack = nkr::Move(other);
                    CHECK(other.Count() == 0);
                    for (index_t idx = 0, end = stack.Count(); idx < end; idx += 1) {
                        CHECK(other.Array()[idx] == none_t());
                    }
                }
            }

            TEST_SUITE("copy_assignment_ctor()")
            {
                TEST_CASE_TEMPLATE("should copy each unit and the count of other", stack_p, nkr_NON_CONST)
                {
                    using unit_t = stack_p::unit_t;
                    using writable_unit_t = stack_p::writable_unit_t;
                    using array_t = stack_p::array_t;
                    using writable_array_t = stack_p::writable_array_t;

                    count_t count = Random<count_t>(1, 16);
                    std::remove_const_t<stack_p> other;
                    for (index_t idx = 0, end = count; idx < end; idx += 1) {
                        other.Push(Random<writable_unit_t>()).Ignore_Error();
                    }
                    stack_p stack;
                    stack = other;
                    CHECK(stack.Count() == other.Count());
                    for (index_t idx = 0, end = stack.Count(); idx < end; idx += 1) {
                        CHECK(stack[idx] == other[idx]);
                    }
                }

                TEST_CASE_TEMPLATE("should not change the other", stack_p, nkr_NON_CONST)
                {
                    using unit_t = stack_p::unit_t;
                    using writable_unit_t = stack_p::writable_unit_t;
                    using array_t = stack_p::array_t;
                    using writable_array_t = stack_p::writable_array_t;

                    count_t count = Random<count_t>(1, 16);
                    std::remove_const_t<stack_p> other;
                    std::remove_const_t<stack_p> backup;
                    for (index_t idx = 0, end = count; idx < end; idx += 1) {
                        unit_t random = Random<unit_t>();
                        other.Push(random).Ignore_Error();
                        backup.Push(random).Ignore_Error();
                    }
                    stack_p stack;
                    stack = other;
                    CHECK(other.Count() == backup.Count());
                    for (index_t idx = 0, end = other.Count(); idx < end; idx += 1) {
                        CHECK(other[idx] == backup[idx]);
                    }
                }

                TEST_CASE_TEMPLATE("should return itself", stack_p, nkr_NON_CONST)
                {
                    using unit_t = stack_p::unit_t;
                    using writable_unit_t = stack_p::writable_unit_t;
                    using array_t = stack_p::array_t;
                    using writable_array_t = stack_p::writable_array_t;

                    count_t count = Random<count_t>(1, 16);
                    std::remove_const_t<stack_p> other;
                    for (index_t idx = 0, end = count; idx < end; idx += 1) {
                        other.Push(Random<writable_unit_t>()).Ignore_Error();
                    }
                    stack_p stack;
                    CHECK(&(stack = other) == &stack);
                }
            }

            TEST_SUITE("move_assignment_ctor()")
            {
                TEST_CASE_TEMPLATE("should move each unit and count of other", stack_p, nkr_NON_CONST)
                {
                    using unit_t = stack_p::unit_t;
                    using writable_unit_t = stack_p::writable_unit_t;
                    using array_t = stack_p::array_t;
                    using writable_array_t = stack_p::writable_array_t;

                    count_t count = Random<count_t>(1, 16);
                    std::remove_const_t<stack_p> other;
                    std::remove_const_t<stack_p> backup;
                    for (index_t idx = 0, end = count; idx < end; idx += 1) {
                        unit_t random = Random<unit_t>();
                        other.Push(random).Ignore_Error();
                        backup.Push(random).Ignore_Error();
                    }
                    stack_p stack;
                    stack = nkr::Move(other);
                    CHECK(stack.Count() == backup.Count());
                    for (index_t idx = 0, end = stack.Count(); idx < end; idx += 1) {
                        CHECK(stack[idx] == backup[idx]);
                    }
                }

                TEST_CASE_TEMPLATE("should set the other to have none values", stack_p, nkr_NON_CONST)
                {
                    using unit_t = stack_p::unit_t;
                    using writable_unit_t = stack_p::writable_unit_t;
                    using array_t = stack_p::array_t;
                    using writable_array_t = stack_p::writable_array_t;

                    count_t count = Random<count_t>(1, 16);
                    std::remove_const_t<stack_p> other;
                    for (index_t idx = 0, end = count; idx < end; idx += 1) {
                        other.Push(Random<writable_unit_t>()).Ignore_Error();
                    }
                    stack_p stack;
                    stack = nkr::Move(other);
                    CHECK(other.Count() == 0);
                    for (index_t idx = 0, end = stack.Count(); idx < end; idx += 1) {
                        CHECK(other.Array()[idx] == none_t());
                    }
                }

                TEST_CASE_TEMPLATE("should return itself", stack_p, nkr_NON_CONST)
                {
                    using unit_t = stack_p::unit_t;
                    using writable_unit_t = stack_p::writable_unit_t;
                    using array_t = stack_p::array_t;
                    using writable_array_t = stack_p::writable_array_t;

                    count_t count = Random<count_t>(1, 16);
                    std::remove_const_t<stack_p> other;
                    std::remove_const_t<stack_p> backup;
                    for (index_t idx = 0, end = count; idx < end; idx += 1) {
                        unit_t random = Random<unit_t>();
                        other.Push(random).Ignore_Error();
                        backup.Push(random).Ignore_Error();
                    }
                    stack_p stack;
                    CHECK(&(stack = nkr::Move(other)) == &stack);
                }

                TEST_CASE_TEMPLATE("should work with the copy_initializer_list_ctor()", stack_p, nkr_NON_CONST)
                {
                    using unit_t = stack_p::unit_t;
                    using writable_unit_t = stack_p::writable_unit_t;
                    using array_t = stack_p::array_t;
                    using writable_array_t = stack_p::writable_array_t;

                    array_t array = {
                        Random<unit_t>(), Random<unit_t>(), Random<unit_t>(), Random<unit_t>(),
                        Random<unit_t>(), Random<unit_t>(), Random<unit_t>(), Random<unit_t>(),
                        Random<unit_t>(), Random<unit_t>(), Random<unit_t>(), Random<unit_t>(),
                        Random<unit_t>(), Random<unit_t>(), Random<unit_t>(), Random<unit_t>(),
                    };
                    stack_p stack;
                    stack = {
                        array[0], array[1], array[2], array[3],
                        array[4], array[5], array[6], array[7],
                        array[8], array[9], array[10], array[11],
                        array[12], array[13], array[14], array[15],
                    };
                    CHECK(stack.Count() == 16);
                    for (index_t idx = 0, end = stack.Count(); idx < end; idx += 1) {
                        CHECK(stack[idx] == array[idx]);
                    }
                }

                TEST_CASE_TEMPLATE("should work with the move_initializer_list_ctor()", stack_p, nkr_NON_CONST)
                {
                    using unit_t = stack_p::unit_t;
                    using writable_unit_t = stack_p::writable_unit_t;
                    using array_t = stack_p::array_t;
                    using writable_array_t = stack_p::writable_array_t;

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
                    stack_p stack;
                    stack = {
                        nkr::Move(array[0]), nkr::Move(array[1]),
                        nkr::Move(array[2]), nkr::Move(array[3]),
                        nkr::Move(array[4]), nkr::Move(array[5]),
                        nkr::Move(array[6]), nkr::Move(array[7]),
                        nkr::Move(array[8]), nkr::Move(array[9]),
                        nkr::Move(array[10]), nkr::Move(array[11]),
                        nkr::Move(array[12]), nkr::Move(array[13]),
                        nkr::Move(array[14]), nkr::Move(array[15]),
                    };
                    CHECK(stack.Count() == 16);
                    for (index_t idx = 0, end = stack.Count(); idx < end; idx += 1) {
                        CHECK(stack[idx] == backup[idx]);
                    }
                    for (index_t idx = 0, end = sizeof(array) / sizeof(writable_unit_t); idx < end; idx += 1) {
                        CHECK(array[idx] == none_t());
                    }
                }
            }

            TEST_SUITE("dtor()")
            {
                TEST_CASE_TEMPLATE("should set its values to default", stack_p, nkr_ALL)
                {
                    using unit_t = stack_p::unit_t;
                    using writable_unit_t = stack_p::writable_unit_t;
                    using array_t = stack_p::array_t;
                    using writable_array_t = stack_p::writable_array_t;

                    count_t count = Random<count_t>(1, 16);
                    std::remove_const_t<stack_p> other;
                    for (index_t idx = 0, end = count; idx < end; idx += 1) {
                        other.Push(Random<writable_unit_t>()).Ignore_Error();
                    }
                    stack_p stack = other;
                    stack.~stack_p();
                    CHECK(stack.Count() == none_t());
                    for (index_t idx = 0, end = other.Count(); idx < end; idx += 1) {
                        CHECK(stack.Array()[idx] == none_t());
                    }
                }
            }
        }

        TEST_SUITE("methods")
        {
            TEST_SUITE("Array()")
            {
                TEST_CASE_TEMPLATE("should retun the unit_t[Capacity()] array with each unit", stack_p, nkr_ALL)
                {
                    using unit_t = stack_p::unit_t;
                    using writable_unit_t = stack_p::writable_unit_t;
                    using array_t = stack_p::array_t;
                    using writable_array_t = stack_p::writable_array_t;

                    array_t array = {
                        Random<unit_t>(), Random<unit_t>(), Random<unit_t>(), Random<unit_t>(),
                        Random<unit_t>(), Random<unit_t>(), Random<unit_t>(), Random<unit_t>(),
                        Random<unit_t>(), Random<unit_t>(), Random<unit_t>(), Random<unit_t>(),
                        Random<unit_t>(), Random<unit_t>(), Random<unit_t>(), Random<unit_t>(),
                    };
                    stack_p stack = {
                        array[0], array[1], array[2], array[3],
                        array[4], array[5], array[6], array[7],
                        array[8], array[9], array[10], array[11],
                        array[12], array[13], array[14], array[15],
                    };
                    CHECK(sizeof(stack.Array()) == sizeof(array));
                    for (index_t idx = 0, end = stack.Count(); idx < end; idx += 1) {
                        CHECK(stack.Array()[idx] == array[idx]);
                    }
                }

                TEST_CASE_TEMPLATE("should be able to alter non-const units", stack_p, nkr_NON_CONST)
                {
                    using unit_t = stack_p::unit_t;
                    using writable_unit_t = stack_p::writable_unit_t;
                    using array_t = stack_p::array_t;
                    using writable_array_t = stack_p::writable_array_t;

                    if constexpr (any_non_const_tr<unit_t>) {
                        array_t array = {
                            Random<unit_t>(), Random<unit_t>(), Random<unit_t>(), Random<unit_t>(),
                            Random<unit_t>(), Random<unit_t>(), Random<unit_t>(), Random<unit_t>(),
                            Random<unit_t>(), Random<unit_t>(), Random<unit_t>(), Random<unit_t>(),
                            Random<unit_t>(), Random<unit_t>(), Random<unit_t>(), Random<unit_t>(),
                        };
                        stack_p stack = {
                            array[0], array[1], array[2], array[3],
                            array[4], array[5], array[6], array[7],
                            array[8], array[9], array[10], array[11],
                            array[12], array[13], array[14], array[15],
                        };
                        for (index_t idx = 0, end = stack.Count(); idx < end; idx += 1) {
                            writable_unit_t random;
                            do {
                                random = Random<writable_unit_t>();
                            } while (random == array[idx]);
                            stack.Array()[idx] = random;
                            CHECK(stack.Array()[idx] != array[idx]);
                        }
                    }
                }
            }

            TEST_SUITE("Count()")
            {
                TEST_CASE_TEMPLATE("should return the current count", stack_p, nkr_ALL)
                {
                    using unit_t = stack_p::unit_t;
                    using writable_unit_t = stack_p::writable_unit_t;
                    using array_t = stack_p::array_t;
                    using writable_array_t = stack_p::writable_array_t;

                    if constexpr (any_non_const_tr<stack_p>) {
                        stack_p stack;
                        for (index_t idx = 0, end = stack.Capacity(); idx < end; idx += 1) {
                            CHECK(stack.Count() == idx);
                            stack.Push(Random<writable_unit_t>()).Ignore_Error();
                        }
                        CHECK(stack.Count() == stack.Capacity());
                    } else {
                        stack_p stack = {
                            Random<writable_unit_t>(), Random<writable_unit_t>(),
                            Random<writable_unit_t>(), Random<writable_unit_t>(),
                            Random<writable_unit_t>(), Random<writable_unit_t>(),
                            Random<writable_unit_t>(), Random<writable_unit_t>(),
                        };
                        CHECK(stack.Count() == 8);
                    }
                }
            }

            TEST_SUITE("At()")
            {
                TEST_CASE_TEMPLATE("should return unit_t& at the specified index", stack_p, nkr_ALL)
                {
                    using unit_t = stack_p::unit_t;
                    using writable_unit_t = stack_p::writable_unit_t;
                    using array_t = stack_p::array_t;
                    using writable_array_t = stack_p::writable_array_t;

                    array_t array = {
                        Random<unit_t>(), Random<unit_t>(), Random<unit_t>(), Random<unit_t>(),
                        Random<unit_t>(), Random<unit_t>(), Random<unit_t>(), Random<unit_t>(),
                        Random<unit_t>(), Random<unit_t>(), Random<unit_t>(), Random<unit_t>(),
                        Random<unit_t>(), Random<unit_t>(), Random<unit_t>(), Random<unit_t>(),
                    };
                    stack_p stack = {
                        array[0], array[1], array[2], array[3],
                        array[4], array[5], array[6], array[7],
                        array[8], array[9], array[10], array[11],
                        array[12], array[13], array[14], array[15],
                    };
                    for (index_t idx = 0, end = stack.Count(); idx < end; idx += 1) {
                        CHECK(stack.At(idx) == array[idx]);
                    }
                }

                TEST_CASE_TEMPLATE("should be able to alter non-const units", stack_p, nkr_NON_CONST)
                {
                    using unit_t = stack_p::unit_t;
                    using writable_unit_t = stack_p::writable_unit_t;
                    using array_t = stack_p::array_t;
                    using writable_array_t = stack_p::writable_array_t;

                    if constexpr (any_non_const_tr<unit_t>) {
                        array_t array = {
                            Random<unit_t>(), Random<unit_t>(), Random<unit_t>(), Random<unit_t>(),
                            Random<unit_t>(), Random<unit_t>(), Random<unit_t>(), Random<unit_t>(),
                            Random<unit_t>(), Random<unit_t>(), Random<unit_t>(), Random<unit_t>(),
                            Random<unit_t>(), Random<unit_t>(), Random<unit_t>(), Random<unit_t>(),
                        };
                        stack_p stack = {
                            array[0], array[1], array[2], array[3],
                            array[4], array[5], array[6], array[7],
                            array[8], array[9], array[10], array[11],
                            array[12], array[13], array[14], array[15],
                        };
                        for (index_t idx = 0, end = stack.Count(); idx < end; idx += 1) {
                            unit_t random;
                            do {
                                random = Random<unit_t>();
                            } while (random == array[idx]);
                            stack.At(idx) = random;
                            CHECK(stack.At(idx) != array[idx]);
                        }
                    }
                }
            }

            TEST_SUITE("Push()")
            {
                TEST_CASE_TEMPLATE("should copy a unit into the array", stack_p, nkr_NON_CONST)
                {
                    using unit_t = stack_p::unit_t;
                    using writable_unit_t = stack_p::writable_unit_t;
                    using array_t = stack_p::array_t;
                    using writable_array_t = stack_p::writable_array_t;

                    array_t array = {
                        Random<unit_t>(), Random<unit_t>(), Random<unit_t>(), Random<unit_t>(),
                        Random<unit_t>(), Random<unit_t>(), Random<unit_t>(), Random<unit_t>(),
                        Random<unit_t>(), Random<unit_t>(), Random<unit_t>(), Random<unit_t>(),
                        Random<unit_t>(), Random<unit_t>(), Random<unit_t>(), Random<unit_t>(),
                    };
                    stack_p stack;
                    for (index_t idx = 0, end = sizeof(array) / sizeof(unit_t); idx < end; idx += 1) {
                        stack.Push(array[idx]).Ignore_Error();
                        CHECK(stack[idx] == array[idx]);
                    }
                    CHECK(stack.Count() == sizeof(array) / sizeof(unit_t));
                }

                TEST_CASE_TEMPLATE("should copy multiple units into the array", stack_p, nkr_NON_CONST)
                {
                    using unit_t = stack_p::unit_t;
                    using writable_unit_t = stack_p::writable_unit_t;
                    using array_t = stack_p::array_t;
                    using writable_array_t = stack_p::writable_array_t;

                    array_t array = {
                        Random<unit_t>(), Random<unit_t>(), Random<unit_t>(), Random<unit_t>(),
                        Random<unit_t>(), Random<unit_t>(), Random<unit_t>(), Random<unit_t>(),
                        Random<unit_t>(), Random<unit_t>(), Random<unit_t>(), Random<unit_t>(),
                        Random<unit_t>(), Random<unit_t>(), Random<unit_t>(), Random<unit_t>(),
                    };
                    stack_p stack;
                    stack.Push(
                        array[0], array[1], array[2], array[3],
                        array[4], array[5], array[6], array[7],
                        array[8], array[9], array[10], array[11],
                        array[12], array[13], array[14], array[15]
                    ).Ignore_Error();
                    CHECK(stack.Count() == sizeof(array) / sizeof(unit_t));
                    for (index_t idx = 0, end = stack.Count(); idx < end; idx += 1) {
                        CHECK(stack[idx] == array[idx]);
                    }
                }

                TEST_CASE_TEMPLATE("should move a writable unit into the array", stack_p, nkr_NON_CONST)
                {
                    using unit_t = stack_p::unit_t;
                    using writable_unit_t = stack_p::writable_unit_t;
                    using array_t = stack_p::array_t;
                    using writable_array_t = stack_p::writable_array_t;

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
                    stack_p stack;
                    for (index_t idx = 0, end = sizeof(array) / sizeof(unit_t); idx < end; idx += 1) {
                        stack.Push(nkr::Move(array[idx])).Ignore_Error();
                        CHECK(stack[idx] == backup[idx]);
                    }
                    CHECK(stack.Count() == sizeof(backup) / sizeof(unit_t));
                    for (index_t idx = 0, end = sizeof(array) / sizeof(writable_unit_t); idx < end; idx += 1) {
                        CHECK(array[idx] == none_t());
                    }
                }

                TEST_CASE_TEMPLATE("should move multiple writable units into the array", stack_p, nkr_NON_CONST)
                {
                    using unit_t = stack_p::unit_t;
                    using writable_unit_t = stack_p::writable_unit_t;
                    using array_t = stack_p::array_t;
                    using writable_array_t = stack_p::writable_array_t;

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
                    stack_p stack;
                    stack.Push(
                        nkr::Move(array[0]), nkr::Move(array[1]),
                        nkr::Move(array[2]), nkr::Move(array[3]),
                        nkr::Move(array[4]), nkr::Move(array[5]),
                        nkr::Move(array[6]), nkr::Move(array[7]),
                        nkr::Move(array[8]), nkr::Move(array[9]),
                        nkr::Move(array[10]), nkr::Move(array[11]),
                        nkr::Move(array[12]), nkr::Move(array[13]),
                        nkr::Move(array[14]), nkr::Move(array[15])
                    ).Ignore_Error();
                    CHECK(stack.Count() == sizeof(backup) / sizeof(writable_unit_t));
                    for (index_t idx = 0, end = stack.Count(); idx < end; idx += 1) {
                        CHECK(stack[idx] == backup[idx]);
                    }
                    for (index_t idx = 0, end = sizeof(array) / sizeof(writable_unit_t); idx < end; idx += 1) {
                        CHECK(array[idx] == none_t());
                    }
                }
            }

            TEST_SUITE("Pop()")
            {
                TEST_CASE_TEMPLATE("should move the last unit out of the array and return it by value", stack_p, nkr_NON_CONST)
                {
                    using unit_t = stack_p::unit_t;
                    using writable_unit_t = stack_p::writable_unit_t;
                    using array_t = stack_p::array_t;
                    using writable_array_t = stack_p::writable_array_t;

                    array_t array = {
                        Random<unit_t>(), Random<unit_t>(), Random<unit_t>(), Random<unit_t>(),
                        Random<unit_t>(), Random<unit_t>(), Random<unit_t>(), Random<unit_t>(),
                        Random<unit_t>(), Random<unit_t>(), Random<unit_t>(), Random<unit_t>(),
                        Random<unit_t>(), Random<unit_t>(), Random<unit_t>(), Random<unit_t>(),
                    };
                    stack_p stack = {
                        array[0], array[1], array[2], array[3],
                        array[4], array[5], array[6], array[7],
                        array[8], array[9], array[10], array[11],
                        array[12], array[13], array[14], array[15],
                    };
                    CHECK(stack.Count() == sizeof(array) / sizeof(unit_t));
                    while (stack.Count() > 0) {
                        unit_t value = stack.Pop();
                        CHECK(array[stack.Count()] == value);
                    }
                    CHECK(stack.Count() == 0);
                }
            }

            TEST_SUITE("Copy_To()")
            {
                TEST_CASE_TEMPLATE("should copy each of its units to another array without changing them", stack_p, nkr_NON_CONST)
                {
                    using unit_t = stack_p::unit_t;
                    using writable_unit_t = stack_p::writable_unit_t;
                    using array_t = stack_p::array_t;
                    using writable_array_t = stack_p::writable_array_t;

                    const stack_p stack = {
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                    };
                    stack_p other;
                    stack.Copy_To(other).Ignore_Error();
                    CHECK(other.Count() == stack.Count());
                    for (index_t idx = 0, end = other.Count(); idx < end; idx += 1) {
                        CHECK(other[idx] == stack[idx]);
                    }
                }

                TEST_CASE_TEMPLATE("should copy each of its units to itself", stack_p, nkr_NON_CONST)
                {
                    using unit_t = stack_p::unit_t;
                    using writable_unit_t = stack_p::writable_unit_t;
                    using array_t = stack_p::array_t;
                    using writable_array_t = stack_p::writable_array_t;

                    stack_p stack = {
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                    };
                    stack.Copy_To(stack).Ignore_Error();
                    CHECK(stack.Count() == stack.Capacity());
                    for (index_t idx = 0, end = 8; idx < end; idx += 1) {
                        CHECK(stack[idx] == stack[idx + 8]);
                    }
                }

                TEST_CASE_TEMPLATE("should not remove any units from other array", stack_p, nkr_NON_CONST)
                {
                    using unit_t = stack_p::unit_t;
                    using writable_unit_t = stack_p::writable_unit_t;
                    using array_t = stack_p::array_t;
                    using writable_array_t = stack_p::writable_array_t;

                    const stack_p stack = {
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                    };
                    stack_p other = {
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                    };
                    stack.Copy_To(other).Ignore_Error();
                    CHECK(other.Count() == stack.Count() + 8);
                    for (index_t idx = 8, end = other.Count(); idx < end; idx += 1) {
                        CHECK(other[idx] == stack[idx - 8]);
                    }
                }
            }

            TEST_SUITE("Copy_From()")
            {
                TEST_CASE_TEMPLATE("should copy each unit from another array without changing them", stack_p, nkr_NON_CONST)
                {
                    using unit_t = stack_p::unit_t;
                    using writable_unit_t = stack_p::writable_unit_t;
                    using array_t = stack_p::array_t;
                    using writable_array_t = stack_p::writable_array_t;

                    const stack_p other = {
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                    };
                    stack_p stack;
                    stack.Copy_From(other).Ignore_Error();
                    CHECK(stack.Count() == other.Count());
                    for (index_t idx = 0, end = stack.Count(); idx < end; idx += 1) {
                        CHECK(stack[idx] == other[idx]);
                    }
                }

                TEST_CASE_TEMPLATE("should copy each of its units from itself", stack_p, nkr_NON_CONST)
                {
                    using unit_t = stack_p::unit_t;
                    using writable_unit_t = stack_p::writable_unit_t;
                    using array_t = stack_p::array_t;
                    using writable_array_t = stack_p::writable_array_t;

                    stack_p stack = {
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                    };
                    stack.Copy_From(stack).Ignore_Error();
                    CHECK(stack.Count() == stack.Capacity());
                    for (index_t idx = 0, end = 8; idx < end; idx += 1) {
                        CHECK(stack[idx] == stack[idx + 8]);
                    }
                }

                TEST_CASE_TEMPLATE("should not remove any of its own units", stack_p, nkr_NON_CONST)
                {
                    using unit_t = stack_p::unit_t;
                    using writable_unit_t = stack_p::writable_unit_t;
                    using array_t = stack_p::array_t;
                    using writable_array_t = stack_p::writable_array_t;

                    const stack_p other = {
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                    };
                    stack_p stack = {
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                    };
                    stack.Copy_From(other).Ignore_Error();
                    CHECK(stack.Count() == other.Count() + 8);
                    for (index_t idx = 8, end = stack.Count(); idx < end; idx += 1) {
                        CHECK(stack[idx] == other[idx - 8]);
                    }
                }
            }

            TEST_SUITE("Move_To()")
            {
                TEST_CASE_TEMPLATE("should move each of its units to another array", stack_p, nkr_NON_CONST)
                {
                    using unit_t = stack_p::unit_t;
                    using writable_unit_t = stack_p::writable_unit_t;
                    using array_t = stack_p::array_t;
                    using writable_array_t = stack_p::writable_array_t;

                    if constexpr (any_non_const_tr<unit_t>) {
                        stack_p stack = {
                            Random<writable_unit_t>(), Random<writable_unit_t>(),
                            Random<writable_unit_t>(), Random<writable_unit_t>(),
                            Random<writable_unit_t>(), Random<writable_unit_t>(),
                            Random<writable_unit_t>(), Random<writable_unit_t>(),
                            Random<writable_unit_t>(), Random<writable_unit_t>(),
                            Random<writable_unit_t>(), Random<writable_unit_t>(),
                            Random<writable_unit_t>(), Random<writable_unit_t>(),
                            Random<writable_unit_t>(), Random<writable_unit_t>(),
                        };
                        stack_p backup = stack;
                        stack_p other;
                        stack.Move_To(other).Ignore_Error();
                        CHECK(stack.Count() == 0);
                        CHECK(other.Count() == backup.Count());
                        for (index_t idx = 0, end = other.Count(); idx < end; idx += 1) {
                            CHECK(other[idx] == backup[idx]);
                        }
                    }
                }

                TEST_CASE_TEMPLATE("should return without error when moving to itself", stack_p, nkr_NON_CONST)
                {
                    using unit_t = stack_p::unit_t;
                    using writable_unit_t = stack_p::writable_unit_t;
                    using array_t = stack_p::array_t;
                    using writable_array_t = stack_p::writable_array_t;

                    if constexpr (any_non_const_tr<unit_t>) {
                        stack_p stack = {
                            Random<writable_unit_t>(), Random<writable_unit_t>(),
                            Random<writable_unit_t>(), Random<writable_unit_t>(),
                            Random<writable_unit_t>(), Random<writable_unit_t>(),
                            Random<writable_unit_t>(), Random<writable_unit_t>(),
                            Random<writable_unit_t>(), Random<writable_unit_t>(),
                            Random<writable_unit_t>(), Random<writable_unit_t>(),
                            Random<writable_unit_t>(), Random<writable_unit_t>(),
                            Random<writable_unit_t>(), Random<writable_unit_t>(),
                        };
                        stack_p backup = stack;
                        stack.Move_To(stack).Ignore_Error();
                        CHECK(stack.Count() == backup.Count());
                        for (index_t idx = 0, end = stack.Count(); idx < end; idx += 1) {
                            CHECK(stack[idx] == backup[idx]);
                        }
                    }
                }

                TEST_CASE_TEMPLATE("should not remove any units from other array", stack_p, nkr_NON_CONST)
                {
                    using unit_t = stack_p::unit_t;
                    using writable_unit_t = stack_p::writable_unit_t;
                    using array_t = stack_p::array_t;
                    using writable_array_t = stack_p::writable_array_t;

                    if constexpr (any_non_const_tr<unit_t>) {
                        stack_p stack = {
                            Random<writable_unit_t>(), Random<writable_unit_t>(),
                            Random<writable_unit_t>(), Random<writable_unit_t>(),
                            Random<writable_unit_t>(), Random<writable_unit_t>(),
                            Random<writable_unit_t>(), Random<writable_unit_t>(),
                        };
                        stack_p backup = stack;
                        stack_p other = {
                            Random<writable_unit_t>(), Random<writable_unit_t>(),
                            Random<writable_unit_t>(), Random<writable_unit_t>(),
                            Random<writable_unit_t>(), Random<writable_unit_t>(),
                            Random<writable_unit_t>(), Random<writable_unit_t>(),
                        };
                        stack.Move_To(other).Ignore_Error();
                        CHECK(stack.Count() == 0);
                        CHECK(other.Count() == backup.Count() + 8);
                        for (index_t idx = 8, end = other.Count(); idx < end; idx += 1) {
                            CHECK(other[idx] == backup[idx - 8]);
                        }
                    }
                }
            }

            TEST_SUITE("Move_From()")
            {
                TEST_CASE_TEMPLATE("should move each unit from another array", stack_p, nkr_NON_CONST)
                {
                    using unit_t = stack_p::unit_t;
                    using writable_unit_t = stack_p::writable_unit_t;
                    using array_t = stack_p::array_t;
                    using writable_array_t = stack_p::writable_array_t;

                    if constexpr (any_non_const_tr<unit_t>) {
                        stack_p other = {
                            Random<writable_unit_t>(), Random<writable_unit_t>(),
                            Random<writable_unit_t>(), Random<writable_unit_t>(),
                            Random<writable_unit_t>(), Random<writable_unit_t>(),
                            Random<writable_unit_t>(), Random<writable_unit_t>(),
                            Random<writable_unit_t>(), Random<writable_unit_t>(),
                            Random<writable_unit_t>(), Random<writable_unit_t>(),
                            Random<writable_unit_t>(), Random<writable_unit_t>(),
                            Random<writable_unit_t>(), Random<writable_unit_t>(),
                        };
                        stack_p backup = other;
                        stack_p stack;
                        stack.Move_From(other).Ignore_Error();
                        CHECK(other.Count() == 0);
                        CHECK(stack.Count() == backup.Count());
                        for (index_t idx = 0, end = stack.Count(); idx < end; idx += 1) {
                            CHECK(stack[idx] == backup[idx]);
                        }
                    }
                }

                TEST_CASE_TEMPLATE("should return without error when moving from itself", stack_p, nkr_NON_CONST)
                {
                    using unit_t = stack_p::unit_t;
                    using writable_unit_t = stack_p::writable_unit_t;
                    using array_t = stack_p::array_t;
                    using writable_array_t = stack_p::writable_array_t;

                    if constexpr (any_non_const_tr<unit_t>) {
                        stack_p stack = {
                            Random<writable_unit_t>(), Random<writable_unit_t>(),
                            Random<writable_unit_t>(), Random<writable_unit_t>(),
                            Random<writable_unit_t>(), Random<writable_unit_t>(),
                            Random<writable_unit_t>(), Random<writable_unit_t>(),
                            Random<writable_unit_t>(), Random<writable_unit_t>(),
                            Random<writable_unit_t>(), Random<writable_unit_t>(),
                            Random<writable_unit_t>(), Random<writable_unit_t>(),
                            Random<writable_unit_t>(), Random<writable_unit_t>(),
                        };
                        stack_p backup = stack;
                        stack.Move_From(stack).Ignore_Error();
                        CHECK(stack.Count() == backup.Count());
                        for (index_t idx = 0, end = stack.Count(); idx < end; idx += 1) {
                            CHECK(stack[idx] == backup[idx]);
                        }
                    }
                }

                TEST_CASE_TEMPLATE("should not remove any of its own units", stack_p, nkr_NON_CONST)
                {
                    using unit_t = stack_p::unit_t;
                    using writable_unit_t = stack_p::writable_unit_t;
                    using array_t = stack_p::array_t;
                    using writable_array_t = stack_p::writable_array_t;

                    if constexpr (any_non_const_tr<unit_t>) {
                        stack_p other = {
                            Random<writable_unit_t>(), Random<writable_unit_t>(),
                            Random<writable_unit_t>(), Random<writable_unit_t>(),
                            Random<writable_unit_t>(), Random<writable_unit_t>(),
                            Random<writable_unit_t>(), Random<writable_unit_t>(),
                        };
                        stack_p backup = other;
                        stack_p stack = {
                            Random<writable_unit_t>(), Random<writable_unit_t>(),
                            Random<writable_unit_t>(), Random<writable_unit_t>(),
                            Random<writable_unit_t>(), Random<writable_unit_t>(),
                            Random<writable_unit_t>(), Random<writable_unit_t>(),
                        };
                        stack.Move_From(other).Ignore_Error();
                        CHECK(other.Count() == 0);
                        CHECK(stack.Count() == backup.Count() + 8);
                        for (index_t idx = 8, end = stack.Count(); idx < end; idx += 1) {
                            CHECK(stack[idx] == backup[idx - 8]);
                        }
                    }
                }
            }

            TEST_SUITE("Is_Clear()")
            {
                TEST_CASE_TEMPLATE("should return true when there are no units in the array", stack_p, nkr_ALL)
                {
                    using unit_t = stack_p::unit_t;
                    using writable_unit_t = stack_p::writable_unit_t;
                    using array_t = stack_p::array_t;
                    using writable_array_t = stack_p::writable_array_t;

                    stack_p stack;
                    CHECK(stack.Is_Clear() == true);
                }

                TEST_CASE_TEMPLATE("should return false when there are units in the array", stack_p, nkr_ALL)
                {
                    using unit_t = stack_p::unit_t;
                    using writable_unit_t = stack_p::writable_unit_t;
                    using array_t = stack_p::array_t;
                    using writable_array_t = stack_p::writable_array_t;

                    stack_p stack = { Random<writable_unit_t>() };
                    CHECK(stack.Is_Clear() == false);
                }
            }

            TEST_SUITE("Clear()")
            {
                TEST_CASE_TEMPLATE("should call the destructor of each unit and remove it from the array", stack_p, nkr_NON_CONST)
                {
                    using unit_t = stack_p::unit_t;
                    using writable_unit_t = stack_p::writable_unit_t;
                    using array_t = stack_p::array_t;
                    using writable_array_t = stack_p::writable_array_t;

                    stack_p stack = {
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                    };
                    stack.Clear();
                    CHECK(stack.Count() == 0);
                    for (index_t idx = 0, end = stack.Capacity(); idx < end; idx += 1) {
                        CHECK(stack.Array()[idx] == none_t());
                    }
                }
            }
        }

        TEST_SUITE("operators")
        {
            TEST_SUITE("[]()")
            {
                TEST_CASE_TEMPLATE("should return unit_t& at the specified index", stack_p, nkr_ALL)
                {
                    using unit_t = stack_p::unit_t;
                    using writable_unit_t = stack_p::writable_unit_t;
                    using array_t = stack_p::array_t;
                    using writable_array_t = stack_p::writable_array_t;

                    array_t array = {
                        Random<unit_t>(), Random<unit_t>(), Random<unit_t>(), Random<unit_t>(),
                        Random<unit_t>(), Random<unit_t>(), Random<unit_t>(), Random<unit_t>(),
                        Random<unit_t>(), Random<unit_t>(), Random<unit_t>(), Random<unit_t>(),
                        Random<unit_t>(), Random<unit_t>(), Random<unit_t>(), Random<unit_t>(),
                    };
                    stack_p stack = {
                        array[0], array[1], array[2], array[3],
                        array[4], array[5], array[6], array[7],
                        array[8], array[9], array[10], array[11],
                        array[12], array[13], array[14], array[15],
                    };
                    for (index_t idx = 0, end = stack.Count(); idx < end; idx += 1) {
                        CHECK(stack[idx] == array[idx]);
                    }
                }

                TEST_CASE_TEMPLATE("should be able to alter non-const units", stack_p, nkr_NON_CONST)
                {
                    using unit_t = stack_p::unit_t;
                    using writable_unit_t = stack_p::writable_unit_t;
                    using array_t = stack_p::array_t;
                    using writable_array_t = stack_p::writable_array_t;

                    if constexpr (any_non_const_tr<unit_t>) {
                        array_t array = {
                            Random<unit_t>(), Random<unit_t>(), Random<unit_t>(), Random<unit_t>(),
                            Random<unit_t>(), Random<unit_t>(), Random<unit_t>(), Random<unit_t>(),
                            Random<unit_t>(), Random<unit_t>(), Random<unit_t>(), Random<unit_t>(),
                            Random<unit_t>(), Random<unit_t>(), Random<unit_t>(), Random<unit_t>(),
                        };
                        stack_p stack = {
                            array[0], array[1], array[2], array[3],
                            array[4], array[5], array[6], array[7],
                            array[8], array[9], array[10], array[11],
                            array[12], array[13], array[14], array[15],
                        };
                        for (index_t idx = 0, end = stack.Count(); idx < end; idx += 1) {
                            unit_t random;
                            do {
                                random = Random<unit_t>();
                            } while (random == array[idx]);
                            stack[idx] = random;
                            CHECK(stack[idx] != array[idx]);
                        }
                    }
                }
            }
        }
    }

}}
