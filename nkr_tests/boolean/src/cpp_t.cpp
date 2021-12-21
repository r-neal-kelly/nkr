/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/tr.h"

#include "nkr/boolean/cpp_t.h"
#include "nkr/boolean/fast_t.h"

#include "nkr/trait/boolean_tr.h"
#include "nkr/trait/boolean/impure_tr.h"
#include "nkr/trait/boolean/pure_tr.h"

#include "doctest.h"

namespace nkr { namespace boolean {

    TEST_CASE("temp")
    {
        CHECK(boolean::cpp_t(true));
        CHECK(boolean::cpp_t(true) == true);
        CHECK(!boolean::cpp_t(false));
        CHECK(boolean::cpp_t(false) != true);

        CHECK(boolean::fast_t(true));
        CHECK((boolean::fast_t(true) == true));
        CHECK(!boolean::fast_t(false));
        CHECK((boolean::fast_t(false) != true));

        CHECK(boolean::cpp_t(boolean::fast_t(true)));
        CHECK(!boolean::cpp_t(boolean::fast_t(false)));
        CHECK(boolean::fast_t(boolean::cpp_t(true)));
        CHECK(!boolean::fast_t(boolean::cpp_t(false)));

        CHECK((boolean::cpp_t(true) == boolean::fast_t(true)));
        CHECK((boolean::fast_t(true) == boolean::cpp_t(true)));
        CHECK((boolean::cpp_t(true) != boolean::fast_t(false)));
        CHECK((boolean::fast_t(true) != boolean::cpp_t(false)));
    }

}}

// temp

#define NOMINMAX

#include <intrin.h>
#include <windows.h>

#include <chrono>

namespace nkr {

    inline cpp::r64_t
        Microseconds()
    {
        LARGE_INTEGER frequency;
        LARGE_INTEGER counter;
        QueryPerformanceFrequency(&frequency);
        QueryPerformanceCounter(&counter);

        return (counter.QuadPart * 1000000.0) / frequency.QuadPart;
    }

    inline cpp::r64_t
        Milliseconds()
    {
        return Microseconds() * 0.001;
    }

    inline cpp::r64_t
        Seconds()
    {
        return Milliseconds() * 0.001;
    }

    template <typename functor_p, typename ...args_p>
    inline cpp::r64_t
        Test_In_Microseconds(count_t trial_count, functor_p functor, args_p... args)
    {
        cpp::r64_t total_time = 0.0;
        for (index_t idx = 0, end = trial_count; idx < end; idx += 1) {
            cpp::r64_t start_time = Microseconds();
            functor(std::forward<args_p>(args)...);
            total_time += Microseconds() - start_time;
        }

        return total_time / trial_count;
    }

    template <typename functor_p, typename ...args_p>
    inline cpp::r64_t
        Test_In_Milliseconds(count_t trial_count, functor_p functor, args_p... args)
    {
        cpp::r64_t total_time = 0.0;
        for (index_t idx = 0, end = trial_count; idx < end; idx += 1) {
            cpp::r64_t start_time = Milliseconds();
            functor(std::forward<args_p>(args)...);
            total_time += Milliseconds() - start_time;
        }

        return total_time / trial_count;
    }

}

namespace nkr { namespace boolean {

    TEST_CASE("temp")
    {
        constexpr cpp::count_t UNIT_COUNT = 2048;

        auto cpp_bool = []() -> void_t
        {
            cpp::bool_t array[UNIT_COUNT];
            for (cpp::index_t idx = 0, end = UNIT_COUNT; idx < end; idx += 1) {
                array[idx] = cpp::word_t(Microseconds()) & 0x1 ? true : false;
            }

            cpp::word_t true_count = 0;
            for (cpp::index_t idx = 0, end = UNIT_COUNT; idx < end; idx += 1) {
                if (array[idx]) {
                    true_count += 1;
                }
            }

            //printf("cpp::bool_t true_count: %zu\n", true_count);
        };

        auto boolean_cpp = []() -> void_t
        {
            boolean::cpp_t array[UNIT_COUNT];
            for (cpp::index_t idx = 0, end = UNIT_COUNT; idx < end; idx += 1) {
                array[idx] = cpp::word_t(Microseconds()) & 0x1 ? true : false;
            }

            cpp::word_t true_count = 0;
            for (cpp::index_t idx = 0, end = UNIT_COUNT; idx < end; idx += 1) {
                if (array[idx]) {
                    true_count += 1;
                }
            }

            //printf("boolean::cpp_t true_count: %zu\n", true_count);
        };

        auto boolean_fast = []() -> void_t
        {
            boolean::fast_t array[UNIT_COUNT];
            for (cpp::index_t idx = 0, end = UNIT_COUNT; idx < end; idx += 1) {
                array[idx] = cpp::word_t(Microseconds()) & 0x1 ? true : false;
            }

            cpp::word_t true_count = 0;
            for (cpp::index_t idx = 0, end = UNIT_COUNT; idx < end; idx += 1) {
                if (array[idx]) {
                    true_count += 1;
                }
            }

            //printf("boolean::fast_t true_count: %zu\n", true_count);
        };

        cpp::r64_t cpp_bool_time = Test_In_Milliseconds(48, cpp_bool);
        cpp::r64_t boolean_cpp_time = Test_In_Milliseconds(48, boolean_cpp);
        cpp::r64_t boolean_fast_time = Test_In_Milliseconds(48, boolean_fast);

        printf("cpp_bool_time: %g\n", cpp_bool_time);
        printf("boolean_cpp_time: %g\n", boolean_cpp_time);
        printf("boolean_fast_time: %g\n", boolean_fast_time);
    }

}}

//
