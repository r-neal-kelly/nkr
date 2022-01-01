/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/z_intrinsics.h"
#include "nkr/z_macros.h"

#include "nkr/z_enumeration/types_t.h"

#include "doctest.h"

namespace nkr { namespace enumeration {

    class temp_e :
        public enumeration::types_t<int>
    {
    public:
        using base_t    = types_t<int>;

    public:
        enum : value_t
        {
            A,
            B,
            C,
        };

    public:
        nkr_DEFINE_INHERITANCE_WRAPPER_CTORS_AND_DTOR(temp_e, base_t);
    };

    TEST_CASE("temp")
    {
        enumeration::types_t<int> types;
        static_assert(enumeration::types_t<int>::NONE == -1);
    }

}}
