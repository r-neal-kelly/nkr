/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/atomic_t.h"
#include "nkr/intrinsics.h"
#include "nkr/macros.h"

#include "nkr/enum/flags_t.h"

#include "doctest.h"

namespace nkr {

    class test_flags_e :
        public enum_flags_t<u8_t>
    {
    public:
        enum : value_t
        {
            FLAG_0 = Define<0>(),
            FLAG_1 = Define<1>(),
            FLAG_2 = Define<2>(),
            FLAG_3 = Define<3>(),
            FLAG_4 = Define<4>(),
            FLAG_5 = Define<5>(),
            FLAG_6 = Define<6>(),
            FLAG_7 = Define<7>(),
        };

    public:
        nkr_DEFINE_INHERITANCE_WRAPPER_CTORS_AND_DTOR(test_flags_e, base_enum_t);
    };

    TEST_CASE("temp")
    {
        test_flags_e test_flags = test_flags_e::FLAG_6;
        CHECK(test_flags.Is_Flagged(test_flags_e::FLAG_6));
        test_flags.Flag(test_flags_e::FLAG_7);
        CHECK(test_flags.Is_Flagged(test_flags_e::FLAG_7));

        $enum_flags_t::any_sp<u8_t, u8_t> a;
        $enum_flags_t::any_sp<u8_t, u8_t> volatile_a;

        enum_flags_t<u8_t> b;
        volatile enum_flags_t<u8_t> volatile_b;

        test_flags_e c;
        volatile test_flags_e volatile_c;

        a = nkr::Move(a);
        a = nkr::Move(volatile_a);
        volatile_a = nkr::Move(a);
        volatile_a = nkr::Move(volatile_a);
        a = 0;
        a = { 0 };
        volatile_a = 0;
        volatile_a = { 0 };

        b = nkr::Move(a);
        b = nkr::Move(b);
        b = nkr::Move(volatile_a);
        b = nkr::Move(volatile_b);
        volatile_b = nkr::Move(a);
        volatile_b = nkr::Move(b);
        volatile_b = nkr::Move(volatile_a);
        volatile_b = nkr::Move(volatile_b);
        b = 0;
        b = { 0 };
        volatile_b = 0;
        volatile_b = { 0 };

        c = nkr::Move(a);
        c = nkr::Move(b);
        c = nkr::Move(c);
        c = nkr::Move(volatile_a);
        c = nkr::Move(volatile_b);
        c = nkr::Move(volatile_c);
        volatile_c = nkr::Move(a);
        volatile_c = nkr::Move(b);
        volatile_c = nkr::Move(c);
        volatile_c = nkr::Move(volatile_a);
        volatile_c = nkr::Move(volatile_b);
        volatile_c = nkr::Move(volatile_c);
        c = 0;
        c = { 0 };
        volatile_c = 0;
        volatile_c = { 0 };

        a = a = 0;
        b = b = 0;
        c = c = 0;
    }

}
