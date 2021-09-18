/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/intrinsics.h"
#include "nkr/random.h"

#include "nkr/array/stack_t.h"

#include "doctest.h"

namespace nkr {

    TEST_SUITE("stack_array_t<unit_p, capacity_p>")
    {
        class temp_t
        {
        public:
            int data[4];

            temp_t()
            {
                data[0] = Random<int>(1, 4);
                data[1] = Random<int>(1, 4);
                data[2] = Random<int>(1, 4);
                data[3] = Random<int>(1, 4);
            }

            void_t Log()
            {
                printf("%d, %d, %d, %d\n", data[0], data[1], data[2], data[3]);
            }
        };

        TEST_CASE("temp")
        {
            stack_array_t<temp_t, 2> stack_array;
            stack_array.Push(temp_t());
            for (index_t idx = 0, end = stack_array.Capacity(); idx < end; idx += 1) {
                stack_array.Array()[idx].Log();
            }
        }
    }

}
