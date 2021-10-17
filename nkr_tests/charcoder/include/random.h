/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsics.h"
#include "nkr/traits.h"
#include "nkr/utils.h"

#include "nkr/charcoder_i.h"
#include "nkr/charcoder/ascii_t.h"
#include "nkr/charcoder/utf_8_t.h"
#include "nkr/charcoder/utf_16_t.h"
#include "nkr/charcoder/utf_32_t.h"

#include "nkr/string/stack_t.h"

namespace nkr {

    template <count_t point_count_p, charcoder_i charcoder_p>
    auto Random_Stack_String()
    {
        if constexpr (is_tr<charcoder_p, charcoder::utf_8_t>) {
            static_assert(false, "under development");
        } else if constexpr (is_tr<charcoder_p, charcoder::utf_16_be_t>) {
            static_assert(false, "under development");
        } else if constexpr (is_tr<charcoder_p, charcoder::utf_16_le_t>) {
            static_assert(false, "under development");
        } else if constexpr (is_tr<charcoder_p, charcoder::utf_32_be_t>) {
            static_assert(false, "under development");
        } else if constexpr (is_tr<charcoder_p, charcoder::utf_32_le_t>) {
            static_assert(false, "under development");
        } else {
            string::stack_t<point_count_p* charcoder_p::Max_Unit_Count(), charcoder_p> string;
            nkr_ASSERT_THAT(string.Has_Terminus());

            for (index_t idx = 0, end = point_count_p - 1; idx < end; idx += 1) {
                string.Push(nkr::Random<string::point_t>(1, charcoder_p::Last_Point())).Ignore_Error();
            }

            return string;
        }
    }

    template <count_t point_count_p, charcoder_i charcoder_p>
    auto Random_Stack_String_With_Errors()
    {
        if constexpr (is_tr<charcoder_p, charcoder::utf_8_t>) {
            static_assert(false, "under development");
        } else if constexpr (is_tr<charcoder_p, charcoder::utf_16_be_t>) {
            static_assert(false, "under development");
        } else if constexpr (is_tr<charcoder_p, charcoder::utf_16_le_t>) {
            static_assert(false, "under development");
        } else if constexpr (is_tr<charcoder_p, charcoder::utf_32_be_t>) {
            static_assert(false, "under development");
        } else if constexpr (is_tr<charcoder_p, charcoder::utf_32_le_t>) {
            static_assert(false, "under development");
        } else {
            string::stack_t<point_count_p* charcoder_p::Max_Unit_Count(), charcoder_p> string;
            nkr_ASSERT_THAT(string.Has_Terminus());

            for (index_t idx = 0, end = point_count_p - 1; idx < end; idx += 1) {
                string.Push(nkr::Random<string::point_t>(1)).Ignore_Error();
            }

            return string;
        }
    }

}
