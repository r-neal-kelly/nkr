/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/intrinsics.h"

#include "doctest.h"

namespace nkr {

    TEST_SUITE("cpp tmpl")
    {
        TEST_SUITE("cpp::is_of_template_tmpl")
        {
            template <typename type_p>
            class a_t
            {
            public:
            };

            template <typename type_p>
            class b_t
            {
            public:
            };

            static_assert(cpp::is_of_template_tmpl<a_t<positive::integer_t>, a_t>::value);
            static_assert(!cpp::is_of_template_tmpl<a_t<positive::integer_t>, b_t>::value);
            static_assert(!cpp::is_of_template_tmpl<b_t<positive::integer_t>, a_t>::value);
            static_assert(cpp::is_of_template_tmpl<b_t<positive::integer_t>, b_t>::value);
        }
    }

}
