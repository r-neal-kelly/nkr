/*
    Copyright 2022 r-neal-kelly
*/

#include "nkr/constant_t.h"
#include "nkr/constant/boolean/cpp_t.h"
#include "nkr/tr.h"

#include "doctest.h"

namespace nkr {

    TEST_SUITE("temp")
    {
        static_assert(nkr::TR<
                      t<nkr::constant::boolean::cpp_t<true>>,
                      any_tg, t<nkr::constant::boolean::cpp_tg>
        >() == true);

        static_assert(nkr::TR<
                      t<nkr::constant::boolean::cpp_t<false>>,
                      any_tg, tt<nkr::constant_ttg>
        >() == true);
    }

}
