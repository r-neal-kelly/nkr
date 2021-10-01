/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/intrinsics.h"
#include "nkr/utils.h"

#include "nkr/allocator/heap_t.h"
#include "nkr/allocator/heap_zeros_t.h"

#include "nkr/array/dynamic_t.h"

#include "doctest.h"

namespace nkr { namespace array {

    TEST_SUITE("dynamic_t<unit_p, allocator_p, grow_rate_p>")
    {
    #define nkr_ALL_PARAMS(QUALIFIER_p, UNIT_p, ALLOCATOR_p, GROW_RATE_p)                               \
        QUALIFIER_p dynamic_t<UNIT_p, ALLOCATOR_p<UNIT_p>, GROW_RATE_p>,                                \
        QUALIFIER_p dynamic_t<const UNIT_p, ALLOCATOR_p<const UNIT_p>, GROW_RATE_p>,                    \
        QUALIFIER_p dynamic_t<volatile UNIT_p, ALLOCATOR_p<volatile UNIT_p>, GROW_RATE_p>,              \
        QUALIFIER_p dynamic_t<const volatile UNIT_p, ALLOCATOR_p<const volatile UNIT_p>, GROW_RATE_p>

    #define nkr_GROW_RATES(QUALIFIER_p, UNIT_p, ALLOCATOR_p)                                \
        nkr_ALL_PARAMS(QUALIFIER_p, UNIT_p, ALLOCATOR_p, math::fraction_t<17 nkr_COMMA 10>)

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
        nkr_UNITS(const volatile)

    #define nkr_ALL     \
        nkr_NON_CONST,  \
        nkr_CONST

        TEST_SUITE("aliases")
        {
            TEST_SUITE("unit_t")
            {
                TEST_CASE_TEMPLATE("should have a unit_t", dynamic_p, nkr_ALL)
                {
                    using unit_t = dynamic_p::unit_t;
                    using writable_unit_t = dynamic_p::writable_unit_t;
                    using pointer_t = dynamic_p::pointer_t;
                    using writable_pointer_t = dynamic_p::writable_pointer_t;
                    using allocator_t = dynamic_p::allocator_t;
                    using grow_rate_t = dynamic_p::grow_rate_t;

                    static_assert(is_tr<unit_t, unit_t>);
                }
            }

            TEST_SUITE("writable_unit_t")
            {
                TEST_CASE_TEMPLATE("should have a writable_unit_t that is non-const", dynamic_p, nkr_ALL)
                {
                    using unit_t = dynamic_p::unit_t;
                    using writable_unit_t = dynamic_p::writable_unit_t;
                    using pointer_t = dynamic_p::pointer_t;
                    using writable_pointer_t = dynamic_p::writable_pointer_t;
                    using allocator_t = dynamic_p::allocator_t;
                    using grow_rate_t = dynamic_p::grow_rate_t;

                    static_assert(is_tr<writable_unit_t, std::remove_const_t<unit_t>>);
                }
            }

            TEST_SUITE("pointer_t")
            {
                TEST_CASE_TEMPLATE("should have a pointer_t with the same unit_t", dynamic_p, nkr_ALL)
                {
                    using unit_t = dynamic_p::unit_t;
                    using writable_unit_t = dynamic_p::writable_unit_t;
                    using pointer_t = dynamic_p::pointer_t;
                    using writable_pointer_t = dynamic_p::writable_pointer_t;
                    using allocator_t = dynamic_p::allocator_t;
                    using grow_rate_t = dynamic_p::grow_rate_t;

                    static_assert(is_tr<pointer_t, nkr::pointer_t<unit_t>>);
                }
            }

            TEST_SUITE("writable_pointer_t")
            {
                TEST_CASE_TEMPLATE("should have a writable_pointer_t that is non-const", dynamic_p, nkr_ALL)
                {
                    using unit_t = dynamic_p::unit_t;
                    using writable_unit_t = dynamic_p::writable_unit_t;
                    using pointer_t = dynamic_p::pointer_t;
                    using writable_pointer_t = dynamic_p::writable_pointer_t;
                    using allocator_t = dynamic_p::allocator_t;
                    using grow_rate_t = dynamic_p::grow_rate_t;

                    static_assert(is_tr<writable_pointer_t, nkr::pointer_t<writable_unit_t>>);
                }
            }

            TEST_SUITE("allocator_t")
            {
                TEST_CASE_TEMPLATE("should have an allocator_t with the same unit_t", dynamic_p, nkr_ALL)
                {
                    using unit_t = dynamic_p::unit_t;
                    using writable_unit_t = dynamic_p::writable_unit_t;
                    using pointer_t = dynamic_p::pointer_t;
                    using writable_pointer_t = dynamic_p::writable_pointer_t;
                    using allocator_t = dynamic_p::allocator_t;
                    using grow_rate_t = dynamic_p::grow_rate_t;

                    static_assert(is_tr<allocator_t::unit_t, unit_t>);
                }
            }

            TEST_SUITE("grow_rate_t")
            {
                TEST_CASE_TEMPLATE("should have a grow_rate_t", dynamic_p, nkr_ALL)
                {
                    using unit_t = dynamic_p::unit_t;
                    using writable_unit_t = dynamic_p::writable_unit_t;
                    using pointer_t = dynamic_p::pointer_t;
                    using writable_pointer_t = dynamic_p::writable_pointer_t;
                    using allocator_t = dynamic_p::allocator_t;
                    using grow_rate_t = dynamic_p::grow_rate_t;

                    static_assert(is_tr<grow_rate_t, grow_rate_t>);
                }
            }
        }

        TEST_SUITE("static methods")
        {
            TEST_SUITE("Grow_Rate()")
            {
                TEST_CASE_TEMPLATE("should equate grow_rate_t::To_Decimal()", dynamic_p, nkr_ALL)
                {
                    using unit_t = dynamic_p::unit_t;
                    using writable_unit_t = dynamic_p::writable_unit_t;
                    using pointer_t = dynamic_p::pointer_t;
                    using writable_pointer_t = dynamic_p::writable_pointer_t;
                    using allocator_t = dynamic_p::allocator_t;
                    using grow_rate_t = dynamic_p::grow_rate_t;

                    CHECK(dynamic_p::Grow_Rate() == grow_rate_t::To_Decimal());
                }
            }
        }

        TEST_SUITE("objects")
        {
            TEST_SUITE("default_ctor()")
            {
                TEST_CASE_TEMPLATE("should have a default pointer and count of 0", dynamic_p, nkr_ALL)
                {
                    using unit_t = dynamic_p::unit_t;
                    using writable_unit_t = dynamic_p::writable_unit_t;
                    using pointer_t = dynamic_p::pointer_t;
                    using writable_pointer_t = dynamic_p::writable_pointer_t;
                    using allocator_t = dynamic_p::allocator_t;
                    using grow_rate_t = dynamic_p::grow_rate_t;

                    dynamic_p dynamic;
                    CHECK(dynamic.Pointer() == pointer_t());
                    CHECK(dynamic.Count() == 0);
                }
            }

            TEST_SUITE("allocator_ctor()")
            {
                TEST_CASE_TEMPLATE("should explicitly and implicitly copy the allocator and default everything else", dynamic_p, nkr_ALL)
                {
                    using unit_t = dynamic_p::unit_t;
                    using writable_unit_t = dynamic_p::writable_unit_t;
                    using pointer_t = dynamic_p::pointer_t;
                    using writable_pointer_t = dynamic_p::writable_pointer_t;
                    using allocator_t = dynamic_p::allocator_t;
                    using grow_rate_t = dynamic_p::grow_rate_t;

                    allocator_t allocator = allocator_t();
                    dynamic_p dynamic(allocator);
                    CHECK(dynamic.Pointer() == pointer_t());
                    CHECK(dynamic.Count() == 0);
                }

                TEST_CASE_TEMPLATE("should explicitly and implicitly copy the allocator and default everything else", dynamic_p, nkr_ALL)
                {
                    using unit_t = dynamic_p::unit_t;
                    using writable_unit_t = dynamic_p::writable_unit_t;
                    using pointer_t = dynamic_p::pointer_t;
                    using writable_pointer_t = dynamic_p::writable_pointer_t;
                    using allocator_t = dynamic_p::allocator_t;
                    using grow_rate_t = dynamic_p::grow_rate_t;

                    allocator_t allocator = allocator_t();
                    dynamic_p dynamic = allocator;
                    CHECK(dynamic.Pointer() == pointer_t());
                    CHECK(dynamic.Count() == 0);
                }

                TEST_CASE_TEMPLATE("should explicitly move the allocator and default everything else", dynamic_p, nkr_ALL)
                {
                    using unit_t = dynamic_p::unit_t;
                    using writable_unit_t = dynamic_p::writable_unit_t;
                    using pointer_t = dynamic_p::pointer_t;
                    using writable_pointer_t = dynamic_p::writable_pointer_t;
                    using allocator_t = dynamic_p::allocator_t;
                    using grow_rate_t = dynamic_p::grow_rate_t;

                    dynamic_p dynamic((allocator_t()));
                    CHECK(dynamic.Pointer() == pointer_t());
                    CHECK(dynamic.Count() == 0);
                }

                TEST_CASE_TEMPLATE("should implicitly move the allocator and default everything else", dynamic_p, nkr_ALL)
                {
                    using unit_t = dynamic_p::unit_t;
                    using writable_unit_t = dynamic_p::writable_unit_t;
                    using pointer_t = dynamic_p::pointer_t;
                    using writable_pointer_t = dynamic_p::writable_pointer_t;
                    using allocator_t = dynamic_p::allocator_t;
                    using grow_rate_t = dynamic_p::grow_rate_t;

                    dynamic_p dynamic = allocator_t();
                    CHECK(dynamic.Pointer() == pointer_t());
                    CHECK(dynamic.Count() == 0);
                }
            }

            TEST_SUITE("capacity_ctor()")
            {
                TEST_CASE_TEMPLATE("should set the capacity and default everything else", dynamic_p, nkr_ALL)
                {
                    using unit_t = dynamic_p::unit_t;
                    using writable_unit_t = dynamic_p::writable_unit_t;
                    using pointer_t = dynamic_p::pointer_t;
                    using writable_pointer_t = dynamic_p::writable_pointer_t;
                    using allocator_t = dynamic_p::allocator_t;
                    using grow_rate_t = dynamic_p::grow_rate_t;

                    count_t capacity = Random<count_t>(1, 16);
                    dynamic_p dynamic(capacity);
                    CHECK(dynamic.Pointer() != nullptr);
                    CHECK(dynamic.Capacity() == capacity);
                    CHECK(dynamic.Count() == 0);
                }

                TEST_CASE_TEMPLATE("should copy an allocator", dynamic_p, nkr_ALL)
                {
                    using unit_t = dynamic_p::unit_t;
                    using writable_unit_t = dynamic_p::writable_unit_t;
                    using pointer_t = dynamic_p::pointer_t;
                    using writable_pointer_t = dynamic_p::writable_pointer_t;
                    using allocator_t = dynamic_p::allocator_t;
                    using grow_rate_t = dynamic_p::grow_rate_t;

                    count_t capacity = Random<count_t>(1, 16);
                    allocator_t allocator;
                    dynamic_p dynamic(capacity, allocator);
                    CHECK(dynamic.Pointer() != nullptr);
                    CHECK(dynamic.Capacity() == capacity);
                    CHECK(dynamic.Count() == 0);
                }

                TEST_CASE_TEMPLATE("should move an allocator", dynamic_p, nkr_ALL)
                {
                    using unit_t = dynamic_p::unit_t;
                    using writable_unit_t = dynamic_p::writable_unit_t;
                    using pointer_t = dynamic_p::pointer_t;
                    using writable_pointer_t = dynamic_p::writable_pointer_t;
                    using allocator_t = dynamic_p::allocator_t;
                    using grow_rate_t = dynamic_p::grow_rate_t;

                    count_t capacity = Random<count_t>(1, 16);
                    allocator_t allocator;
                    dynamic_p dynamic(capacity, nkr::Move(allocator));
                    CHECK(dynamic.Pointer() != nullptr);
                    CHECK(dynamic.Capacity() == capacity);
                    CHECK(dynamic.Count() == 0);
                }
            }

            TEST_SUITE("filler_ctor()")
            {
                TEST_CASE_TEMPLATE("should copy the filler count number of times without changing it", dynamic_p, nkr_ALL)
                {
                    using unit_t = dynamic_p::unit_t;
                    using writable_unit_t = dynamic_p::writable_unit_t;
                    using pointer_t = dynamic_p::pointer_t;
                    using writable_pointer_t = dynamic_p::writable_pointer_t;
                    using allocator_t = dynamic_p::allocator_t;
                    using grow_rate_t = dynamic_p::grow_rate_t;

                    const unit_t filler = Random<unit_t>();
                    count_t count = Random<count_t>(1, 16);
                    dynamic_p dynamic(filler, count);
                    CHECK(dynamic.Pointer() != nullptr);
                    CHECK(dynamic.Capacity() == count);
                    CHECK(dynamic.Count() == count);
                    for (index_t idx = 0, end = dynamic.Count(); idx < end; idx += 1) {
                        CHECK(dynamic[idx] == filler);
                    }
                }

                TEST_CASE_TEMPLATE("should move the filler to the first index and push count - 1 copies of it", dynamic_p, nkr_ALL)
                {
                    using unit_t = dynamic_p::unit_t;
                    using writable_unit_t = dynamic_p::writable_unit_t;
                    using pointer_t = dynamic_p::pointer_t;
                    using writable_pointer_t = dynamic_p::writable_pointer_t;
                    using allocator_t = dynamic_p::allocator_t;
                    using grow_rate_t = dynamic_p::grow_rate_t;

                    writable_unit_t filler = Random<writable_unit_t>();
                    writable_unit_t backup_filler = filler;
                    count_t count = Random<count_t>(1, 16);
                    dynamic_p dynamic(nkr::Move(filler), count);
                    CHECK(dynamic.Pointer() != nullptr);
                    CHECK(dynamic.Capacity() == count);
                    CHECK(dynamic.Count() == count);
                    for (index_t idx = 0, end = dynamic.Count(); idx < end; idx += 1) {
                        CHECK(dynamic[idx] == backup_filler);
                    }
                    CHECK(filler == none_t());
                }

                TEST_CASE_TEMPLATE("should copy an allocator", dynamic_p, nkr_ALL)
                {
                    using unit_t = dynamic_p::unit_t;
                    using writable_unit_t = dynamic_p::writable_unit_t;
                    using pointer_t = dynamic_p::pointer_t;
                    using writable_pointer_t = dynamic_p::writable_pointer_t;
                    using allocator_t = dynamic_p::allocator_t;
                    using grow_rate_t = dynamic_p::grow_rate_t;

                    unit_t filler = Random<unit_t>();
                    count_t count = Random<count_t>(1, 16);
                    allocator_t allocator;
                    dynamic_p dynamic(filler, count, allocator);
                    CHECK(dynamic.Pointer() != nullptr);
                    CHECK(dynamic.Capacity() == count);
                    CHECK(dynamic.Count() == count);
                    for (index_t idx = 0, end = dynamic.Count(); idx < end; idx += 1) {
                        CHECK(dynamic[idx] == filler);
                    }
                }

                TEST_CASE_TEMPLATE("should move an allocator", dynamic_p, nkr_ALL)
                {
                    using unit_t = dynamic_p::unit_t;
                    using writable_unit_t = dynamic_p::writable_unit_t;
                    using pointer_t = dynamic_p::pointer_t;
                    using writable_pointer_t = dynamic_p::writable_pointer_t;
                    using allocator_t = dynamic_p::allocator_t;
                    using grow_rate_t = dynamic_p::grow_rate_t;

                    unit_t filler = Random<unit_t>();
                    count_t count = Random<count_t>(1, 16);
                    allocator_t allocator;
                    dynamic_p dynamic(filler, count, nkr::Move(allocator));
                    CHECK(dynamic.Pointer() != nullptr);
                    CHECK(dynamic.Capacity() == count);
                    CHECK(dynamic.Count() == count);
                    for (index_t idx = 0, end = dynamic.Count(); idx < end; idx += 1) {
                        CHECK(dynamic[idx] == filler);
                    }
                }
            }

            TEST_SUITE("array_ctor()")
            {
                TEST_CASE_TEMPLATE("should explicitly or implicitly copy an array without changing it", dynamic_p, nkr_ALL)
                {
                    using unit_t = dynamic_p::unit_t;
                    using writable_unit_t = dynamic_p::writable_unit_t;
                    using pointer_t = dynamic_p::pointer_t;
                    using writable_pointer_t = dynamic_p::writable_pointer_t;
                    using allocator_t = dynamic_p::allocator_t;
                    using grow_rate_t = dynamic_p::grow_rate_t;

                    unit_t array[] = {
                        Random<unit_t>(), Random<unit_t>(), Random<unit_t>(), Random<unit_t>(),
                        Random<unit_t>(), Random<unit_t>(), Random<unit_t>(), Random<unit_t>(),
                        Random<unit_t>(), Random<unit_t>(), Random<unit_t>(), Random<unit_t>(),
                        Random<unit_t>(), Random<unit_t>(), Random<unit_t>(), Random<unit_t>(),
                    };
                    dynamic_p dynamic = array;
                    CHECK(dynamic.Pointer() != nullptr);
                    CHECK(dynamic.Pointer() != array);
                    CHECK(dynamic.Capacity() == sizeof(array) / sizeof(unit_t));
                    CHECK(dynamic.Count() == sizeof(array) / sizeof(unit_t));
                    for (index_t idx = 0, end = dynamic.Count(); idx < end; idx += 1) {
                        CHECK(dynamic[idx] == array[idx]);
                    }
                }

                TEST_CASE_TEMPLATE("should explicitly or implicitly move an array and default the source", dynamic_p, nkr_ALL)
                {
                    using unit_t = dynamic_p::unit_t;
                    using writable_unit_t = dynamic_p::writable_unit_t;
                    using pointer_t = dynamic_p::pointer_t;
                    using writable_pointer_t = dynamic_p::writable_pointer_t;
                    using allocator_t = dynamic_p::allocator_t;
                    using grow_rate_t = dynamic_p::grow_rate_t;

                    writable_unit_t array[] = {
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                    };
                    writable_unit_t backup[] = {
                        array[0], array[1], array[2], array[3],
                        array[4], array[5], array[6], array[7],
                        array[8], array[9], array[10], array[11],
                        array[12], array[13], array[14], array[15],
                    };
                    dynamic_p dynamic = nkr::Move(array);
                    CHECK(dynamic.Pointer() != nullptr);
                    CHECK(dynamic.Pointer() != array);
                    CHECK(dynamic.Capacity() == sizeof(array) / sizeof(unit_t));
                    CHECK(dynamic.Count() == sizeof(array) / sizeof(unit_t));
                    for (index_t idx = 0, end = dynamic.Count(); idx < end; idx += 1) {
                        CHECK(dynamic[idx] == backup[idx]);
                    }
                    for (index_t idx = 0, end = dynamic.Count(); idx < end; idx += 1) {
                        CHECK(array[idx] == none_t());
                    }
                }
            }

            TEST_SUITE("stack_ctor()")
            {
                TEST_CASE_TEMPLATE("should explicitly or implicitly copy a stack without changing it", dynamic_p, nkr_ALL)
                {
                    using unit_t = dynamic_p::unit_t;
                    using writable_unit_t = dynamic_p::writable_unit_t;
                    using pointer_t = dynamic_p::pointer_t;
                    using writable_pointer_t = dynamic_p::writable_pointer_t;
                    using allocator_t = dynamic_p::allocator_t;
                    using grow_rate_t = dynamic_p::grow_rate_t;

                    stack_t<unit_t, 16> stack = {
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                    };
                    dynamic_p dynamic = stack;
                    CHECK(dynamic.Pointer() != nullptr);
                    CHECK(dynamic.Pointer() != stack.Array());
                    CHECK(dynamic.Capacity() == stack.Capacity());
                    CHECK(dynamic.Count() == stack.Count());
                    for (index_t idx = 0, end = dynamic.Count(); idx < end; idx += 1) {
                        CHECK(dynamic[idx] == stack[idx]);
                    }
                }

                TEST_CASE_TEMPLATE("should explicitly or implicitly move a stack and default the source", dynamic_p, nkr_ALL)
                {
                    using unit_t = dynamic_p::unit_t;
                    using writable_unit_t = dynamic_p::writable_unit_t;
                    using pointer_t = dynamic_p::pointer_t;
                    using writable_pointer_t = dynamic_p::writable_pointer_t;
                    using allocator_t = dynamic_p::allocator_t;
                    using grow_rate_t = dynamic_p::grow_rate_t;

                    stack_t<writable_unit_t, 16> stack = {
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                    };
                    const stack_t backup = stack;
                    dynamic_p dynamic = nkr::Move(stack);
                    CHECK(dynamic.Pointer() != nullptr);
                    CHECK(dynamic.Pointer() != stack.Array());
                    CHECK(dynamic.Capacity() == backup.Capacity());
                    CHECK(dynamic.Count() == backup.Count());
                    for (index_t idx = 0, end = dynamic.Count(); idx < end; idx += 1) {
                        CHECK(dynamic[idx] == backup[idx]);
                    }
                    CHECK(stack.Count() == 0);
                    for (index_t idx = 0, end = dynamic.Count(); idx < end; idx += 1) {
                        CHECK(stack.Array()[idx] == none_t());
                    }
                }

                template <typename dynamic_p>
                concept allows_rvalue_with_unwritable_unit_t = requires(dynamic_p& dynamic,
                                                                        stack_t<const typename dynamic_p::unit_t, 1>& stack)
                {
                    new (&dynamic) dynamic_t(nkr::Move(stack));
                };

                TEST_CASE_TEMPLATE("should not allow an rvalue stack with unwritable unit_t", dynamic_p, nkr_ALL)
                {
                    CHECK_FALSE(allows_rvalue_with_unwritable_unit_t<dynamic_p>);
                }
            }

            TEST_SUITE("instant_ctor()")
            {
                TEST_CASE_TEMPLATE("should explicitly or implicitly copy an instant without changing it", dynamic_p, nkr_ALL)
                {
                    using unit_t = dynamic_p::unit_t;
                    using writable_unit_t = dynamic_p::writable_unit_t;
                    using pointer_t = dynamic_p::pointer_t;
                    using writable_pointer_t = dynamic_p::writable_pointer_t;
                    using allocator_t = dynamic_p::allocator_t;
                    using grow_rate_t = dynamic_p::grow_rate_t;

                    instant_t instant = {
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                    };
                    dynamic_p dynamic = instant;
                    CHECK(dynamic.Pointer() != nullptr);
                    CHECK(dynamic.Pointer() != instant.Array());
                    CHECK(dynamic.Capacity() == instant.Capacity());
                    CHECK(dynamic.Count() == instant.Count());
                    for (index_t idx = 0, end = dynamic.Count(); idx < end; idx += 1) {
                        CHECK(dynamic[idx] == instant[idx]);
                    }
                }

                TEST_CASE_TEMPLATE("should explicitly or implicitly move an instant and default the source", dynamic_p, nkr_ALL)
                {
                    using unit_t = dynamic_p::unit_t;
                    using writable_unit_t = dynamic_p::writable_unit_t;
                    using pointer_t = dynamic_p::pointer_t;
                    using writable_pointer_t = dynamic_p::writable_pointer_t;
                    using allocator_t = dynamic_p::allocator_t;
                    using grow_rate_t = dynamic_p::grow_rate_t;

                    instant_t instant = {
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                        Random<writable_unit_t>(), Random<writable_unit_t>(),
                    };
                    stack_t backup = instant;
                    dynamic_p dynamic = nkr::Move(instant);
                    CHECK(dynamic.Pointer() != nullptr);
                    CHECK(dynamic.Pointer() != instant.Array());
                    CHECK(dynamic.Capacity() == backup.Capacity());
                    CHECK(dynamic.Count() == backup.Count());
                    for (index_t idx = 0, end = dynamic.Count(); idx < end; idx += 1) {
                        CHECK(dynamic[idx] == backup[idx]);
                    }
                    CHECK(instant.Count() == 0);
                    for (index_t idx = 0, end = dynamic.Count(); idx < end; idx += 1) {
                        CHECK(instant.Array()[idx] == none_t());
                    }
                }
            }

            TEST_SUITE("copy_ctor()")
            {
                TEST_CASE_TEMPLATE("should explicitly copy each unit and the count of other", dynamic_p, nkr_ALL)
                {
                    using unit_t = dynamic_p::unit_t;
                    using writable_unit_t = dynamic_p::writable_unit_t;
                    using pointer_t = dynamic_p::pointer_t;
                    using writable_pointer_t = dynamic_p::writable_pointer_t;
                    using allocator_t = dynamic_p::allocator_t;
                    using grow_rate_t = dynamic_p::grow_rate_t;

                    count_t count = Random<count_t>(1, 16);
                    std::remove_const_t<dynamic_p> other(count);
                    nkr_ASSERT_THAT(other.Has_Memory());
                    for (index_t idx = 0, end = count; idx < end; idx += 1) {
                        other.Push(Random<std::remove_const_t<unit_t>>()).Ignore_Error();
                    }
                    dynamic_p dynamic(other);
                    CHECK(dynamic.Count() == count);
                    for (index_t idx = 0, end = count; idx < end; idx += 1) {
                        CHECK(dynamic[idx] == other[idx]);
                    }
                }

                TEST_CASE_TEMPLATE("should implicitly copy each unit and the count of other", dynamic_p, nkr_ALL)
                {
                    using unit_t = dynamic_p::unit_t;
                    using writable_unit_t = dynamic_p::writable_unit_t;
                    using pointer_t = dynamic_p::pointer_t;
                    using writable_pointer_t = dynamic_p::writable_pointer_t;
                    using allocator_t = dynamic_p::allocator_t;
                    using grow_rate_t = dynamic_p::grow_rate_t;

                    count_t count = Random<count_t>(1, 16);
                    std::remove_const_t<dynamic_p> other(count);
                    nkr_ASSERT_THAT(other.Has_Memory());
                    for (index_t idx = 0, end = count; idx < end; idx += 1) {
                        other.Push(Random<std::remove_const_t<unit_t>>()).Ignore_Error();
                    }
                    dynamic_p dynamic = other;
                    CHECK(dynamic.Count() == count);
                    for (index_t idx = 0, end = count; idx < end; idx += 1) {
                        CHECK(dynamic[idx] == other[idx]);
                    }
                }

                TEST_CASE_TEMPLATE("should not change the other", dynamic_p, nkr_ALL)
                {
                    using unit_t = dynamic_p::unit_t;
                    using writable_unit_t = dynamic_p::writable_unit_t;
                    using pointer_t = dynamic_p::pointer_t;
                    using writable_pointer_t = dynamic_p::writable_pointer_t;
                    using allocator_t = dynamic_p::allocator_t;
                    using grow_rate_t = dynamic_p::grow_rate_t;

                    count_t count = Random<count_t>(1, 16);
                    std::remove_const_t<dynamic_p> other(count);
                    nkr_ASSERT_THAT(other.Has_Memory());
                    for (index_t idx = 0, end = count; idx < end; idx += 1) {
                        other.Push(Random<std::remove_const_t<unit_t>>()).Ignore_Error();
                    }
                    pointer_t pointer = other.Pointer();
                    dynamic_p dynamic(other);
                    CHECK(other.Pointer() == pointer);
                    CHECK(other.Count() == count);
                }

                TEST_CASE_TEMPLATE("should have a different pointer", dynamic_p, nkr_ALL)
                {
                    using unit_t = dynamic_p::unit_t;
                    using writable_unit_t = dynamic_p::writable_unit_t;
                    using pointer_t = dynamic_p::pointer_t;
                    using writable_pointer_t = dynamic_p::writable_pointer_t;
                    using allocator_t = dynamic_p::allocator_t;
                    using grow_rate_t = dynamic_p::grow_rate_t;

                    count_t count = Random<count_t>(1, 16);
                    std::remove_const_t<dynamic_p> other(count);
                    nkr_ASSERT_THAT(other.Has_Memory());
                    for (index_t idx = 0, end = count; idx < end; idx += 1) {
                        other.Push(Random<std::remove_const_t<unit_t>>()).Ignore_Error();
                    }
                    pointer_t pointer = other.Pointer();
                    dynamic_p dynamic(other);
                    CHECK(dynamic.Pointer() != pointer);
                }
            }

            TEST_SUITE("move_ctor()")
            {
                TEST_CASE_TEMPLATE("should explicitly move the pointer and count of other", dynamic_p, nkr_ALL)
                {
                    using unit_t = dynamic_p::unit_t;
                    using writable_unit_t = dynamic_p::writable_unit_t;
                    using pointer_t = dynamic_p::pointer_t;
                    using writable_pointer_t = dynamic_p::writable_pointer_t;
                    using allocator_t = dynamic_p::allocator_t;
                    using grow_rate_t = dynamic_p::grow_rate_t;

                    count_t count = Random<count_t>(1, 16);
                    std::remove_const_t<dynamic_p> other(count);
                    nkr_ASSERT_THAT(other.Has_Memory());
                    for (index_t idx = 0, end = count; idx < end; idx += 1) {
                        other.Push(Random<std::remove_const_t<unit_t>>()).Ignore_Error();
                    }
                    pointer_t pointer = other.Pointer();
                    dynamic_p dynamic(nkr::Move(other));
                    CHECK(dynamic.Pointer() == pointer);
                    CHECK(dynamic.Count() == count);
                }

                TEST_CASE_TEMPLATE("should implicitly move the count of other", dynamic_p, nkr_ALL)
                {
                    using unit_t = dynamic_p::unit_t;
                    using writable_unit_t = dynamic_p::writable_unit_t;
                    using pointer_t = dynamic_p::pointer_t;
                    using writable_pointer_t = dynamic_p::writable_pointer_t;
                    using allocator_t = dynamic_p::allocator_t;
                    using grow_rate_t = dynamic_p::grow_rate_t;

                    count_t count = Random<count_t>(1, 16);
                    std::remove_const_t<dynamic_p> other(count);
                    nkr_ASSERT_THAT(other.Has_Memory());
                    for (index_t idx = 0, end = count; idx < end; idx += 1) {
                        other.Push(Random<std::remove_const_t<unit_t>>()).Ignore_Error();
                    }
                    pointer_t pointer = other.Pointer();
                    dynamic_p dynamic = nkr::Move(other);
                    CHECK(dynamic.Pointer() == pointer);
                    CHECK(dynamic.Count() == count);
                }

                TEST_CASE_TEMPLATE("should set the other to default values", dynamic_p, nkr_ALL)
                {
                    using unit_t = dynamic_p::unit_t;
                    using writable_unit_t = dynamic_p::writable_unit_t;
                    using pointer_t = dynamic_p::pointer_t;
                    using writable_pointer_t = dynamic_p::writable_pointer_t;
                    using allocator_t = dynamic_p::allocator_t;
                    using grow_rate_t = dynamic_p::grow_rate_t;

                    count_t count = Random<count_t>(1, 16);
                    std::remove_const_t<dynamic_p> other(count);
                    nkr_ASSERT_THAT(other.Has_Memory());
                    for (index_t idx = 0, end = count; idx < end; idx += 1) {
                        other.Push(Random<std::remove_const_t<unit_t>>()).Ignore_Error();
                    }
                    dynamic_p dynamic(nkr::Move(other));
                    CHECK(other.Pointer() == pointer_t());
                    CHECK(other.Count() == 0);
                }
            }

            TEST_SUITE("copy_assignment_ctor()")
            {
                TEST_CASE_TEMPLATE("should copy each unit and the count of other", dynamic_p, nkr_NON_CONST)
                {
                    using unit_t = dynamic_p::unit_t;
                    using writable_unit_t = dynamic_p::writable_unit_t;
                    using pointer_t = dynamic_p::pointer_t;
                    using writable_pointer_t = dynamic_p::writable_pointer_t;
                    using allocator_t = dynamic_p::allocator_t;
                    using grow_rate_t = dynamic_p::grow_rate_t;

                    count_t count = Random<count_t>(1, 16);
                    std::remove_const_t<dynamic_p> other(count);
                    nkr_ASSERT_THAT(other.Has_Memory());
                    for (index_t idx = 0, end = count; idx < end; idx += 1) {
                        other.Push(Random<std::remove_const_t<unit_t>>()).Ignore_Error();
                    }
                    dynamic_p dynamic;
                    dynamic = other;
                    CHECK(dynamic.Count() == count);
                    for (index_t idx = 0, end = count; idx < end; idx += 1) {
                        CHECK(dynamic[idx] == other[idx]);
                    }
                }

                TEST_CASE_TEMPLATE("should return itself after copying other", dynamic_p, nkr_NON_CONST)
                {
                    using unit_t = dynamic_p::unit_t;
                    using writable_unit_t = dynamic_p::writable_unit_t;
                    using pointer_t = dynamic_p::pointer_t;
                    using writable_pointer_t = dynamic_p::writable_pointer_t;
                    using allocator_t = dynamic_p::allocator_t;
                    using grow_rate_t = dynamic_p::grow_rate_t;

                    count_t count = Random<count_t>(1, 16);
                    std::remove_const_t<dynamic_p> other(count);
                    nkr_ASSERT_THAT(other.Has_Memory());
                    for (index_t idx = 0, end = count; idx < end; idx += 1) {
                        other.Push(Random<std::remove_const_t<unit_t>>()).Ignore_Error();
                    }
                    dynamic_p dynamic;
                    CHECK(&(dynamic = other) == &dynamic);
                }

                TEST_CASE_TEMPLATE("should not change the other", dynamic_p, nkr_NON_CONST)
                {
                    using unit_t = dynamic_p::unit_t;
                    using writable_unit_t = dynamic_p::writable_unit_t;
                    using pointer_t = dynamic_p::pointer_t;
                    using writable_pointer_t = dynamic_p::writable_pointer_t;
                    using allocator_t = dynamic_p::allocator_t;
                    using grow_rate_t = dynamic_p::grow_rate_t;

                    count_t count = Random<count_t>(1, 16);
                    std::remove_const_t<dynamic_p> other(count);
                    nkr_ASSERT_THAT(other.Has_Memory());
                    for (index_t idx = 0, end = count; idx < end; idx += 1) {
                        other.Push(Random<std::remove_const_t<unit_t>>()).Ignore_Error();
                    }
                    pointer_t pointer = other.Pointer();
                    dynamic_p dynamic;
                    dynamic = other;
                    CHECK(other.Pointer() == pointer);
                    CHECK(other.Count() == count);
                }

                TEST_CASE_TEMPLATE("should have a different pointer", dynamic_p, nkr_NON_CONST)
                {
                    using unit_t = dynamic_p::unit_t;
                    using writable_unit_t = dynamic_p::writable_unit_t;
                    using pointer_t = dynamic_p::pointer_t;
                    using writable_pointer_t = dynamic_p::writable_pointer_t;
                    using allocator_t = dynamic_p::allocator_t;
                    using grow_rate_t = dynamic_p::grow_rate_t;

                    count_t count = Random<count_t>(1, 16);
                    std::remove_const_t<dynamic_p> other(count);
                    nkr_ASSERT_THAT(other.Has_Memory());
                    for (index_t idx = 0, end = count; idx < end; idx += 1) {
                        other.Push(Random<std::remove_const_t<unit_t>>()).Ignore_Error();
                    }
                    pointer_t pointer = other.Pointer();
                    dynamic_p dynamic;
                    dynamic = other;
                    CHECK(dynamic.Pointer() != pointer);
                }
            }

            TEST_SUITE("move_assignment_ctor()")
            {
                TEST_CASE_TEMPLATE("should move the pointer and count of other", dynamic_p, nkr_NON_CONST)
                {
                    using unit_t = dynamic_p::unit_t;
                    using writable_unit_t = dynamic_p::writable_unit_t;
                    using pointer_t = dynamic_p::pointer_t;
                    using writable_pointer_t = dynamic_p::writable_pointer_t;
                    using allocator_t = dynamic_p::allocator_t;
                    using grow_rate_t = dynamic_p::grow_rate_t;

                    count_t count = Random<count_t>(1, 16);
                    std::remove_const_t<dynamic_p> other(count);
                    nkr_ASSERT_THAT(other.Has_Memory());
                    for (index_t idx = 0, end = count; idx < end; idx += 1) {
                        other.Push(Random<std::remove_const_t<unit_t>>()).Ignore_Error();
                    }
                    pointer_t pointer = other.Pointer();
                    dynamic_p dynamic;
                    dynamic = nkr::Move(other);
                    CHECK(dynamic.Pointer() == pointer);
                    CHECK(dynamic.Count() == count);
                }

                TEST_CASE_TEMPLATE("should return itself after moving other", dynamic_p, nkr_NON_CONST)
                {
                    using unit_t = dynamic_p::unit_t;
                    using writable_unit_t = dynamic_p::writable_unit_t;
                    using pointer_t = dynamic_p::pointer_t;
                    using writable_pointer_t = dynamic_p::writable_pointer_t;
                    using allocator_t = dynamic_p::allocator_t;
                    using grow_rate_t = dynamic_p::grow_rate_t;

                    count_t count = Random<count_t>(1, 16);
                    std::remove_const_t<dynamic_p> other(count);
                    nkr_ASSERT_THAT(other.Has_Memory());
                    for (index_t idx = 0, end = count; idx < end; idx += 1) {
                        other.Push(Random<std::remove_const_t<unit_t>>()).Ignore_Error();
                    }
                    pointer_t pointer = other.Pointer();
                    dynamic_p dynamic;
                    CHECK(&(dynamic = nkr::Move(other)) == &dynamic);
                }

                TEST_CASE_TEMPLATE("should set the other to default values", dynamic_p, nkr_NON_CONST)
                {
                    using unit_t = dynamic_p::unit_t;
                    using writable_unit_t = dynamic_p::writable_unit_t;
                    using pointer_t = dynamic_p::pointer_t;
                    using writable_pointer_t = dynamic_p::writable_pointer_t;
                    using allocator_t = dynamic_p::allocator_t;
                    using grow_rate_t = dynamic_p::grow_rate_t;

                    count_t count = Random<count_t>(1, 16);
                    std::remove_const_t<dynamic_p> other(count);
                    nkr_ASSERT_THAT(other.Has_Memory());
                    for (index_t idx = 0, end = count; idx < end; idx += 1) {
                        other.Push(Random<std::remove_const_t<unit_t>>()).Ignore_Error();
                    }
                    dynamic_p dynamic;
                    dynamic = nkr::Move(other);
                    CHECK(other.Pointer() == pointer_t());
                    CHECK(other.Count() == 0);
                }
            }

            TEST_SUITE("dtor()")
            {
                TEST_CASE_TEMPLATE("should set its values to defaults", dynamic_p, nkr_ALL)
                {
                    using unit_t = dynamic_p::unit_t;
                    using writable_unit_t = dynamic_p::writable_unit_t;
                    using pointer_t = dynamic_p::pointer_t;
                    using writable_pointer_t = dynamic_p::writable_pointer_t;
                    using allocator_t = dynamic_p::allocator_t;
                    using grow_rate_t = dynamic_p::grow_rate_t;

                    count_t count = Random<count_t>(1, 16);
                    std::remove_const_t<dynamic_p> other(count);
                    nkr_ASSERT_THAT(other.Has_Memory());
                    for (index_t idx = 0, end = count; idx < end; idx += 1) {
                        other.Push(Random<std::remove_const_t<unit_t>>()).Ignore_Error();
                    }
                    dynamic_p dynamic(other);
                    dynamic.~dynamic_p();
                    CHECK(dynamic.Pointer() == pointer_t());
                    CHECK(dynamic.Count() == 0);
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

    /*TEST_CASE("temp")
    {
        r64_t our_time = os::time::Test_In_Microseconds(
            16,
            []()
            {
                dynamic_t<index_t, allocator::heap_t<index_t>, math::fraction_t<17, 10>> dynamic;
                for (index_t idx = 0, end = 1024; idx < end; idx += 1) {
                    dynamic.Push(Random<index_t>());
                }
            }
        );
        r64_t cpp_time = os::time::Test_In_Microseconds(
            16,
            []()
            {
                std::vector<index_t> vector;
                for (index_t idx = 0, end = 1024; idx < end; idx += 1) {
                    vector.push_back(Random<index_t>());
                }
            }
        );
        r64_t stack_time = os::time::Test_In_Microseconds(
            16,
            []()
            {
                stack_t<index_t, 1024> stack;
                for (index_t idx = 0, end = stack.Capacity(); idx < end; idx += 1) {
                    stack.Push(Random<index_t>());
                }
            }
        );
        printf("our_time: %g\n", our_time);
        printf("cpp_time: %g\n", cpp_time);
        printf("stack_time: %g\n", stack_time);
    }*/

}}
