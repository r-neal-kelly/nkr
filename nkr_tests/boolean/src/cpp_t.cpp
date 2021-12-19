/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/tr.h"

#include "nkr/boolean/cpp_t.h"

#include "nkr/trait/boolean_tr.h"
#include "nkr/trait/boolean/impure_tr.h"
#include "nkr/trait/boolean/pure_tr.h"

#include "doctest.h"

namespace nkr { namespace boolean {

    boolean::cpp_t Test(tr1<any_tg, trait::boolean::impure_tg> auto b)
    {
        return b;
    }

    TEST_CASE("temp")
    {
        CHECK(Test(true) == true);
    }

    boolean::cpp_t Test_2(tr1<any_to_tg, boolean::cpp_t> auto b)
    {
        return b;
    }

    boolean::cpp_t Test_3(tr1<not_any_to_tg, boolean::cpp_t> auto b)
    {
        return true;
    }

    struct test_1_t
    {
        boolean::cpp_t b = true;

        operator boolean::cpp_t()
        {
            return b;
        }
    };
    static_assert(cpp::to_tr<test_1_t, boolean::cpp_t>);

    struct test_2_t
    {
        boolean::cpp_t b = true;
    };
    static_assert(!cpp::to_tr<test_2_t, boolean::cpp_t>);

    TEST_CASE("temp")
    {
        CHECK(Test_2(test_1_t()));
        CHECK(Test_3(test_2_t()));
    }

}}
