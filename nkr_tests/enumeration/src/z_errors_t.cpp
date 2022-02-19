/*
    Copyright 2022 r-neal-kelly
*/

#include "nkr/z_intrinsics.h"
#include "nkr/z_macros.h"
#include "nkr/z_maybe_t.h"

#include "nkr/z_enumeration/errors_t.h"

#include "doctest.h"

namespace nkr { namespace enumeration {

    class test_err :
        public errors_t<signed_word_t>
    {
    private:
        using base_t    = errors_t<signed_word_t>;

    public:
        enum : value_t
        {
            NONE = 0,
            ERROR_A,
            ERROR_B,
        };

    public:
        nkr_DEFINE_INHERITANCE_WRAPPER_CTORS_AND_DTOR(test_err, base_t);
    };

    TEST_CASE("temp")
    {
        CHECK(test_err::NONE == 0);

        test_err error(test_err::ERROR_A);
        CHECK(error == test_err::ERROR_A);

        maybe_t<test_err> err;
        CHECK(!err);
    }

}}
