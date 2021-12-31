/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/atomic_t.h"
#include "nkr/intrinsics.h"
#include "nkr/macros.h"

#include "nkr/z_enumeration/flags_t.h"

#include "doctest.h"

namespace nkr {

    class flags_e :
        public enumeration::flags_t<u8_t>
    {
    public:
        using base_t    = enumeration::flags_t<u8_t>;

    public:
        enum : value_t
        {
            FLAG_0  = Value(0),
            FLAG_1  = Value(1),
            FLAG_2  = Value(2),
            FLAG_3  = Value(3),
            FLAG_4  = Value(4),
            FLAG_5  = Value(5),
            FLAG_6  = Value(6),
            FLAG_7  = Value(7),
        };

    public:
        nkr_DEFINE_INHERITANCE_WRAPPER_CTORS_AND_DTOR(flags_e, base_t);
    };

    TEST_CASE("temp")
    {
        static_assert(flags_e::Index(0x01) == 0);
        static_assert(flags_e::Index(0x02) == 1);
        static_assert(flags_e::Index(0x04) == 2);
        static_assert(flags_e::Index(0x08) == 3);
        static_assert(flags_e::Index(0x10) == 4);
        static_assert(flags_e::Index(0x20) == 5);
        static_assert(flags_e::Index(0x40) == 6);
        static_assert(flags_e::Index(0x80) == 7);

        constexpr index_t index = flags_e::Index(0x40);
        static_assert(index == 6);
    }

}
