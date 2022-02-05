/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/array/cpp_t.h"
#include "nkr/constant/positive/count_t.h"
#include "nkr/constant/positive/index_t.h"
#include "nkr/cpp.h"
#include "nkr/pointer/cpp_t.h"
#include "nkr/tuple/templates_t.h"

#include "doctest.h"

namespace nkr {

    TEST_SUITE("nkr::tuple::templates_t")
    {
        TEST_SUITE("aliases")
        {
            TEST_SUITE("at_t")
            {
                TEST_CASE("should return the tuple at the provided index")
                {
                    using templates_t = nkr::tuple::templates_t<nkr::pointer::cpp_t, nkr::array::cpp_t>;

                    static_assert(templates_t::Count() == 2);

                    static_assert(nkr::pointer::cpp_ttr<templates_t::template at_t<nkr::constant::positive::index_t<0>>::template head_t>);
                    static_assert(nkr::array::cpp_ttr<templates_t::template at_t<nkr::constant::positive::index_t<1>>::template head_t>);
                }
            }

            TEST_SUITE("take_t")
            {
                TEST_CASE("should take the given count of templates from the front of the tuple")
                {
                    using templates_t = nkr::tuple::templates_t<nkr::pointer::cpp_t, nkr::array::cpp_t, nkr::pointer::cpp_t, nkr::array::cpp_t>;
                    using taken_t = templates_t::template take_t<nkr::constant::positive::count_t<2>>;

                    static_assert(templates_t::Count() == 4);
                    static_assert(taken_t::Count() == 2);

                    static_assert(nkr::pointer::cpp_ttr<taken_t::template at_t<nkr::constant::positive::index_t<0>>::template head_t>);
                    static_assert(nkr::array::cpp_ttr<taken_t::template at_t<nkr::constant::positive::index_t<1>>::template head_t>);
                }
            }

            TEST_SUITE("into_t")
            {
                TEST_CASE("should take a given template and apply all of its templates as arguments")
                {
                    using templates_t = nkr::tuple::templates_t<nkr::pointer::cpp_t, nkr::array::cpp_t>;
                    using into_t = templates_t::template into_t<templates_t::template push_back_t>;

                    static_assert(templates_t::Count() == 2);
                    static_assert(into_t::Count() == 4);

                    static_assert(nkr::pointer::cpp_ttr<into_t::template at_t<nkr::constant::positive::index_t<0>>::template head_t>);
                    static_assert(nkr::array::cpp_ttr<into_t::template at_t<nkr::constant::positive::index_t<1>>::template head_t>);
                    static_assert(nkr::pointer::cpp_ttr<into_t::template at_t<nkr::constant::positive::index_t<2>>::template head_t>);
                    static_assert(nkr::array::cpp_ttr<into_t::template at_t<nkr::constant::positive::index_t<3>>::template head_t>);
                }
            }
        }
    }

}
