/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/z_bool_t.h"
#include "nkr/z_intrinsics.h"
#include "nkr/z_utils.h"

#include "doctest.h"

namespace nkr {

    TEST_SUITE("Random")
    {
        constexpr count_t RANDOM_ITERATION_COUNT = 256;

        TEST_SUITE("Random<integer_p>")
        {
        #define _                                                           \
            u8_t, s8_t, u16_t, s16_t, u32_t, s32_t, u64_t, s64_t, word_t

            TEST_CASE_TEMPLATE("should return different numbers", integer_p, _)
            {
                integer_p original = 0;
                integer_p result = 0;
                for (index_t idx = 0, end = RANDOM_ITERATION_COUNT; idx < end; idx += 1) {
                    result = Random<integer_p>();
                    if (result != original) {
                        break;
                    }
                }
                CHECK(result != original);
            }

            TEST_CASE("should by default return both positive and negative numbers for signed integers")
            {
                bool_t got_positive = false;
                bool_t got_negative = false;

                for (index_t idx = 0, end = RANDOM_ITERATION_COUNT; idx < end; idx += 1) {
                    s32_t random = Random<s32_t>();
                    if (random > 0) {
                        got_positive = true;
                    } else if (random < 0) {
                        got_negative = true;
                    }
                }

                CHECK(got_positive && got_negative);
            }

            TEST_CASE("should be capable of only returning positive numbers for signed integers")
            {
                bool_t got_positive = false;
                bool_t got_negative = false;

                for (index_t idx = 0, end = RANDOM_ITERATION_COUNT; idx < end; idx += 1) {
                    s32_t random = Random<s32_t>(0, std::numeric_limits<s32_t>::max());
                    if (random > 0) {
                        got_positive = true;
                    } else if (random < 0) {
                        got_negative = true;
                    }
                }

                CHECK(got_positive && !got_negative);
            }

            TEST_CASE("should be capable of only returning negative numbers for signed integers")
            {
                bool_t got_positive = false;
                bool_t got_negative = false;

                for (index_t idx = 0, end = RANDOM_ITERATION_COUNT; idx < end; idx += 1) {
                    s32_t random = Random<s32_t>(std::numeric_limits<s32_t>::lowest(), 0);
                    if (random > 0) {
                        got_positive = true;
                    } else if (random < 0) {
                        got_negative = true;
                    }
                }

                CHECK(!got_positive && got_negative);
            }

        #undef _
        }

        TEST_SUITE("Random<real_p>")
        {
            TEST_CASE("should by default return both positive and negative numbers")
            {
                bool_t got_positive = false;
                bool_t got_negative = false;

                for (index_t idx = 0, end = RANDOM_ITERATION_COUNT; idx < end; idx += 1) {
                    real_t random = Random<real_t>();
                    if (random > 0.0) {
                        got_positive = true;
                    } else if (random < 0.0) {
                        got_negative = true;
                    }
                }

                CHECK(got_positive && got_negative);
            }

            TEST_CASE("should be capable of only returning positive numbers")
            {
                bool_t got_positive = false;
                bool_t got_negative = false;

                for (index_t idx = 0, end = RANDOM_ITERATION_COUNT; idx < end; idx += 1) {
                    real_t random = Random<real_t>(0.0, std::numeric_limits<real_t>::max());
                    if (random > 0.0) {
                        got_positive = true;
                    } else if (random < 0.0) {
                        got_negative = true;
                    }
                }

                CHECK(got_positive && !got_negative);
            }

            TEST_CASE("should be capable of only returning negative numbers")
            {
                bool_t got_positive = false;
                bool_t got_negative = false;

                for (index_t idx = 0, end = RANDOM_ITERATION_COUNT; idx < end; idx += 1) {
                    real_t random = Random<real_t>(std::numeric_limits<real_t>::lowest(), 0.0);
                    if (random > 0.0) {
                        got_positive = true;
                    } else if (random < 0.0) {
                        got_negative = true;
                    }
                }

                CHECK(!got_positive && got_negative);
            }

            TEST_CASE("should proportionally distribute the probability of getting a negative or positive number")
            {
                count_t positive_count = 0;
                count_t negative_count = 0;

                for (index_t idx = 0, end = RANDOM_ITERATION_COUNT; idx < end; idx += 1) {
                    real_t random = Random<real_t>(-1.0, 2.0);
                    if (random > 0.0) {
                        positive_count += 1;
                    } else if (random < 0.0) {
                        negative_count += 1;
                    }
                }

                CHECK(positive_count > negative_count);
            }

            TEST_CASE("should only return numbers from the given range")
            {
                for (index_t idx = 0, end = RANDOM_ITERATION_COUNT; idx < end; idx += 1) {
                    real_t from = Random<real_t>(std::numeric_limits<real_t>::lowest(), 0.0);
                    real_t to = Random<real_t>(0.0, std::numeric_limits<real_t>::max());
                    real_t random = Random<real_t>(from, to);
                    CHECK(random >= from);
                    CHECK(random <= to);
                }
            }
        }
    }

}
