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
                TEST_CASE_TEMPLATE("should have a default pointer and count of 0", dynamic_array_p, nkr_ALL)
                {
                    using unit_t = dynamic_array_p::unit_t;
                    using writable_unit_t = dynamic_array_p::writable_unit_t;
                    using pointer_t = dynamic_array_p::pointer_t;
                    using writable_pointer_t = dynamic_array_p::writable_pointer_t;
                    using allocator_t = dynamic_array_p::allocator_t;
                    using grow_rate_t = dynamic_array_p::grow_rate_t;

                    dynamic_array_p dynamic_array;
                    CHECK(dynamic_array.Pointer() == pointer_t());
                    CHECK(dynamic_array.Count() == 0);
                }
            }

            TEST_SUITE("allocator_ctor()")
            {
                TEST_CASE_TEMPLATE("should explicitly and implicitly copy the allocator and default everything else", dynamic_array_p, nkr_ALL)
                {
                    using unit_t = dynamic_array_p::unit_t;
                    using writable_unit_t = dynamic_array_p::writable_unit_t;
                    using pointer_t = dynamic_array_p::pointer_t;
                    using writable_pointer_t = dynamic_array_p::writable_pointer_t;
                    using allocator_t = dynamic_array_p::allocator_t;
                    using grow_rate_t = dynamic_array_p::grow_rate_t;

                    allocator_t allocator = allocator_t();
                    dynamic_array_p dynamic_array(allocator);
                    CHECK(dynamic_array.Pointer() == pointer_t());
                    CHECK(dynamic_array.Count() == 0);
                }

                TEST_CASE_TEMPLATE("should explicitly and implicitly copy the allocator and default everything else", dynamic_array_p, nkr_ALL)
                {
                    using unit_t = dynamic_array_p::unit_t;
                    using writable_unit_t = dynamic_array_p::writable_unit_t;
                    using pointer_t = dynamic_array_p::pointer_t;
                    using writable_pointer_t = dynamic_array_p::writable_pointer_t;
                    using allocator_t = dynamic_array_p::allocator_t;
                    using grow_rate_t = dynamic_array_p::grow_rate_t;

                    allocator_t allocator = allocator_t();
                    dynamic_array_p dynamic_array = allocator;
                    CHECK(dynamic_array.Pointer() == pointer_t());
                    CHECK(dynamic_array.Count() == 0);
                }

                TEST_CASE_TEMPLATE("should explicitly move the allocator and default everything else", dynamic_array_p, nkr_ALL)
                {
                    using unit_t = dynamic_array_p::unit_t;
                    using writable_unit_t = dynamic_array_p::writable_unit_t;
                    using pointer_t = dynamic_array_p::pointer_t;
                    using writable_pointer_t = dynamic_array_p::writable_pointer_t;
                    using allocator_t = dynamic_array_p::allocator_t;
                    using grow_rate_t = dynamic_array_p::grow_rate_t;

                    dynamic_array_p dynamic_array((allocator_t()));
                    CHECK(dynamic_array.Pointer() == pointer_t());
                    CHECK(dynamic_array.Count() == 0);
                }

                TEST_CASE_TEMPLATE("should implicitly move the allocator and default everything else", dynamic_array_p, nkr_ALL)
                {
                    using unit_t = dynamic_array_p::unit_t;
                    using writable_unit_t = dynamic_array_p::writable_unit_t;
                    using pointer_t = dynamic_array_p::pointer_t;
                    using writable_pointer_t = dynamic_array_p::writable_pointer_t;
                    using allocator_t = dynamic_array_p::allocator_t;
                    using grow_rate_t = dynamic_array_p::grow_rate_t;

                    dynamic_array_p dynamic_array = allocator_t();
                    CHECK(dynamic_array.Pointer() == pointer_t());
                    CHECK(dynamic_array.Count() == 0);
                }
            }

            TEST_SUITE("capacity_ctor()")
            {
                TEST_CASE_TEMPLATE("should set the capacity and default everything else", dynamic_array_p, nkr_ALL)
                {
                    using unit_t = dynamic_array_p::unit_t;
                    using writable_unit_t = dynamic_array_p::writable_unit_t;
                    using pointer_t = dynamic_array_p::pointer_t;
                    using writable_pointer_t = dynamic_array_p::writable_pointer_t;
                    using allocator_t = dynamic_array_p::allocator_t;
                    using grow_rate_t = dynamic_array_p::grow_rate_t;

                    count_t capacity = Random<count_t>(1, 16);
                    dynamic_array_p dynamic_array(capacity);
                    CHECK(dynamic_array.Pointer() != nullptr);
                    CHECK(dynamic_array.Capacity() == capacity);
                    CHECK(dynamic_array.Count() == 0);
                }

                TEST_CASE_TEMPLATE("should copy an allocator", dynamic_array_p, nkr_ALL)
                {
                    using unit_t = dynamic_array_p::unit_t;
                    using writable_unit_t = dynamic_array_p::writable_unit_t;
                    using pointer_t = dynamic_array_p::pointer_t;
                    using writable_pointer_t = dynamic_array_p::writable_pointer_t;
                    using allocator_t = dynamic_array_p::allocator_t;
                    using grow_rate_t = dynamic_array_p::grow_rate_t;

                    count_t capacity = Random<count_t>(1, 16);
                    allocator_t allocator;
                    dynamic_array_p dynamic_array(capacity, allocator);
                    CHECK(dynamic_array.Pointer() != nullptr);
                    CHECK(dynamic_array.Capacity() == capacity);
                    CHECK(dynamic_array.Count() == 0);
                }

                TEST_CASE_TEMPLATE("should move an allocator", dynamic_array_p, nkr_ALL)
                {
                    using unit_t = dynamic_array_p::unit_t;
                    using writable_unit_t = dynamic_array_p::writable_unit_t;
                    using pointer_t = dynamic_array_p::pointer_t;
                    using writable_pointer_t = dynamic_array_p::writable_pointer_t;
                    using allocator_t = dynamic_array_p::allocator_t;
                    using grow_rate_t = dynamic_array_p::grow_rate_t;

                    count_t capacity = Random<count_t>(1, 16);
                    allocator_t allocator;
                    dynamic_array_p dynamic_array(capacity, std::move(allocator));
                    CHECK(dynamic_array.Pointer() != nullptr);
                    CHECK(dynamic_array.Capacity() == capacity);
                    CHECK(dynamic_array.Count() == 0);
                }
            }

            TEST_SUITE("filler_ctor()")
            {
                TEST_CASE_TEMPLATE("should copy the filler count number of times without changing it", dynamic_array_p, nkr_ALL)
                {
                    using unit_t = dynamic_array_p::unit_t;
                    using writable_unit_t = dynamic_array_p::writable_unit_t;
                    using pointer_t = dynamic_array_p::pointer_t;
                    using writable_pointer_t = dynamic_array_p::writable_pointer_t;
                    using allocator_t = dynamic_array_p::allocator_t;
                    using grow_rate_t = dynamic_array_p::grow_rate_t;

                    const unit_t filler = Random<unit_t>();
                    count_t count = Random<count_t>(1, 16);
                    dynamic_array_p dynamic_array(filler, count);
                    CHECK(dynamic_array.Pointer() != nullptr);
                    CHECK(dynamic_array.Capacity() == count);
                    CHECK(dynamic_array.Count() == count);
                    for (index_t idx = 0, end = dynamic_array.Count(); idx < end; idx += 1) {
                        CHECK(dynamic_array[idx] == filler);
                    }
                }

                TEST_CASE_TEMPLATE("should move the filler to the first index and push count - 1 copies of it", dynamic_array_p, nkr_ALL)
                {
                    using unit_t = dynamic_array_p::unit_t;
                    using writable_unit_t = dynamic_array_p::writable_unit_t;
                    using pointer_t = dynamic_array_p::pointer_t;
                    using writable_pointer_t = dynamic_array_p::writable_pointer_t;
                    using allocator_t = dynamic_array_p::allocator_t;
                    using grow_rate_t = dynamic_array_p::grow_rate_t;

                    writable_unit_t filler = Random<writable_unit_t>();
                    writable_unit_t backup_filler = filler;
                    count_t count = Random<count_t>(1, 16);
                    dynamic_array_p dynamic_array(std::move(filler), count);
                    CHECK(dynamic_array.Pointer() != nullptr);
                    CHECK(dynamic_array.Capacity() == count);
                    CHECK(dynamic_array.Count() == count);
                    for (index_t idx = 0, end = dynamic_array.Count(); idx < end; idx += 1) {
                        CHECK(dynamic_array[idx] == backup_filler);
                    }
                    CHECK(filler == none_t());
                }

                TEST_CASE_TEMPLATE("should copy an allocator", dynamic_array_p, nkr_ALL)
                {
                    using unit_t = dynamic_array_p::unit_t;
                    using writable_unit_t = dynamic_array_p::writable_unit_t;
                    using pointer_t = dynamic_array_p::pointer_t;
                    using writable_pointer_t = dynamic_array_p::writable_pointer_t;
                    using allocator_t = dynamic_array_p::allocator_t;
                    using grow_rate_t = dynamic_array_p::grow_rate_t;

                    unit_t filler = Random<unit_t>();
                    count_t count = Random<count_t>(1, 16);
                    allocator_t allocator;
                    dynamic_array_p dynamic_array(filler, count, allocator);
                    CHECK(dynamic_array.Pointer() != nullptr);
                    CHECK(dynamic_array.Capacity() == count);
                    CHECK(dynamic_array.Count() == count);
                    for (index_t idx = 0, end = dynamic_array.Count(); idx < end; idx += 1) {
                        CHECK(dynamic_array[idx] == filler);
                    }
                }

                TEST_CASE_TEMPLATE("should move an allocator", dynamic_array_p, nkr_ALL)
                {
                    using unit_t = dynamic_array_p::unit_t;
                    using writable_unit_t = dynamic_array_p::writable_unit_t;
                    using pointer_t = dynamic_array_p::pointer_t;
                    using writable_pointer_t = dynamic_array_p::writable_pointer_t;
                    using allocator_t = dynamic_array_p::allocator_t;
                    using grow_rate_t = dynamic_array_p::grow_rate_t;

                    unit_t filler = Random<unit_t>();
                    count_t count = Random<count_t>(1, 16);
                    allocator_t allocator;
                    dynamic_array_p dynamic_array(filler, count, std::move(allocator));
                    CHECK(dynamic_array.Pointer() != nullptr);
                    CHECK(dynamic_array.Capacity() == count);
                    CHECK(dynamic_array.Count() == count);
                    for (index_t idx = 0, end = dynamic_array.Count(); idx < end; idx += 1) {
                        CHECK(dynamic_array[idx] == filler);
                    }
                }
            }

            TEST_SUITE("array_ctor()")
            {
                TEST_CASE_TEMPLATE("should explicitly or implicitly copy an array without changing it", dynamic_array_p, nkr_ALL)
                {
                    using unit_t = dynamic_array_p::unit_t;
                    using writable_unit_t = dynamic_array_p::writable_unit_t;
                    using pointer_t = dynamic_array_p::pointer_t;
                    using writable_pointer_t = dynamic_array_p::writable_pointer_t;
                    using allocator_t = dynamic_array_p::allocator_t;
                    using grow_rate_t = dynamic_array_p::grow_rate_t;

                    unit_t array[] = {
                        Random<unit_t>(), Random<unit_t>(), Random<unit_t>(), Random<unit_t>(),
                        Random<unit_t>(), Random<unit_t>(), Random<unit_t>(), Random<unit_t>(),
                        Random<unit_t>(), Random<unit_t>(), Random<unit_t>(), Random<unit_t>(),
                        Random<unit_t>(), Random<unit_t>(), Random<unit_t>(), Random<unit_t>(),
                    };
                    dynamic_array_p dynamic_array = array;
                    CHECK(dynamic_array.Pointer() != nullptr);
                    CHECK(dynamic_array.Pointer() != array);
                    CHECK(dynamic_array.Capacity() == sizeof(array) / sizeof(unit_t));
                    CHECK(dynamic_array.Count() == sizeof(array) / sizeof(unit_t));
                    for (index_t idx = 0, end = dynamic_array.Count(); idx < end; idx += 1) {
                        CHECK(dynamic_array[idx] == array[idx]);
                    }
                }

                TEST_CASE_TEMPLATE("should explicitly or implicitly move and array and default the source", dynamic_array_p, nkr_ALL)
                {
                    using unit_t = dynamic_array_p::unit_t;
                    using writable_unit_t = dynamic_array_p::writable_unit_t;
                    using pointer_t = dynamic_array_p::pointer_t;
                    using writable_pointer_t = dynamic_array_p::writable_pointer_t;
                    using allocator_t = dynamic_array_p::allocator_t;
                    using grow_rate_t = dynamic_array_p::grow_rate_t;

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
                    dynamic_array_p dynamic_array = std::move(array);
                    CHECK(dynamic_array.Pointer() != nullptr);
                    CHECK(dynamic_array.Pointer() != array);
                    CHECK(dynamic_array.Capacity() == sizeof(array) / sizeof(unit_t));
                    CHECK(dynamic_array.Count() == sizeof(array) / sizeof(unit_t));
                    for (index_t idx = 0, end = dynamic_array.Count(); idx < end; idx += 1) {
                        CHECK(dynamic_array[idx] == backup[idx]);
                    }
                    for (index_t idx = 0, end = dynamic_array.Count(); idx < end; idx += 1) {
                        CHECK(array[idx] == none_t());
                    }
                }
            }

            TEST_SUITE("instant_array_ctor()")
            {

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
