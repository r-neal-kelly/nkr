/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/atomic_t.h"
#include "nkr/enum_flags_t.h"
#include "nkr/intrinsics.h"
#include "nkr/macros.h"

#include "doctest.h"

namespace nkr {

    // need to fill out the assignment ops on atomic_t to get it to work with this.

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
    }

}
