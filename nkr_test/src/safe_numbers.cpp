/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/safe_numbers.h"

#include "intrinsics.h"

namespace nkr {

    TEST_SUITE("safe_p8_t")
    {
        TEST_SUITE("operators")
        {
            TEST_SUITE("+(convertible_tr<value_t>)")
            {
                TEST_CASE_TEMPLATE("temp", positive_p, sp8_t, sp16_t, sp32_t, sp64_t)
                {
                    CHECK(positive_p(-1) == positive_p::MAX);
                    CHECK(positive_p(static_cast<count_t>(positive_p::MAX) + 1) == 0);

                    CHECK(positive_p(0) + -1 == positive_p::MAX);
                    CHECK(positive_p(0) + -2 == positive_p::MAX - 1);
                    CHECK(positive_p(positive_p::MAX) + 1 == 0);
                    CHECK(positive_p(positive_p::MAX) + 2 == 1);

                    CHECK(positive_p(0) - 1 == positive_p::MAX);
                    CHECK(positive_p(0) - 2 == positive_p::MAX - 1);
                    CHECK(positive_p(positive_p::MAX) - -1 == 0);
                    CHECK(positive_p(positive_p::MAX) - -2 == 1);

                    CHECK((positive_p(0) += -1) == positive_p::MAX);
                }

                TEST_CASE_TEMPLATE("temp", negative_p, sn8_t)
                {
                    CHECK(negative_p(1) == negative_p::MIN);

                    CHECK(negative_p(0) + 1 == negative_p::MIN);
                    CHECK(negative_p(0) + 2 == negative_p::MIN + 1);
                    CHECK(negative_p(negative_p::MIN) - 1 == 0);
                    CHECK(negative_p(negative_p::MIN) - 2 == -1);

                    CHECK((negative_p(0) += 1) == negative_p::MIN);
                }
            }
        }
    }

}
