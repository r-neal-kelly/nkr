/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/atomic_t.h"
#include "nkr/intrinsics.h"
#include "nkr/macros.h"

#include "nkr/enumeration/flags_t.h"

#include "doctest.h"

namespace nkr {

    class test_flags_e :
        public enumeration::flags_t<u8_t>
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
        nkr_DEFINE_INHERITANCE_WRAPPER_CTORS_AND_DTOR(test_flags_e, enumeration_base_t);
    };

}
