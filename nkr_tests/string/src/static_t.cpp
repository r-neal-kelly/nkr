/*
    Copyright 2022 r-neal-kelly
*/

#include "nkr/z_intrinsics.h"

#include "nkr/z_string/stack_t.h"
#include "nkr/z_string/static_t.h"

#include "doctest.h"

namespace nkr { namespace string {

    TEST_SUITE("static_t<charcoder_p>")
    {
        TEST_CASE("should be able to work with a substring, and thus without the need of a terminus")
        {
            using qualified_charcoder_t = charcoder::utf_8_t;

            auto source = Random<stack_t<qualified_charcoder_t>, 64>();
            for (index_t idx = 0, end = 128; idx < end; idx += 1) {
                index_t from_point_index = Random<index_t>(0, source.Point_Length());
                index_t point_count = Random<index_t>(0, source.Point_Count() - from_point_index);
                static_t<qualified_charcoder_t> string(source, from_point_index, point_count);

                auto source_itr = source.At(from_point_index);
                auto itr = string.At_First();
                for (; !itr.Is_At_Terminus(); ++itr, ++source_itr) {
                    CHECK(itr.Point() == source_itr.Point());
                }
            }
        }
    }

}}
