/*
    Copyright 2022 r-neal-kelly
*/

#include "nkr/built_in/forward.h"
#include "nkr/constant_t.h"
#include "nkr/generic/tag_tr.h"
#include "nkr/generic/tag/identity_tr.h"
#include "nkr/generic/tag/template_tr.h"
#include "nkr/generic/tag/type_tr.h"
#include "nkr/tuple/types_t.h"

#include "doctest.h"

namespace nkr {

    TEST_SUITE("nkr::constant_tg")
    {
        // [_a75ee664_019d_4764_a2fc_947dc3d384e7]
        TEST_SUITE("")
        {
            using tag_ts = nkr::tuple::types_t<
                nkr::constant_tg,
                const nkr::constant_tg,
                volatile nkr::constant_tg,
                const volatile nkr::constant_tg
            >;

            class iterator_t
            {
            public:
                template <typename tag_p>
                constexpr nkr::boolean::cpp_t
                    operator ()()
                    noexcept
                {
                    return
                        nkr::generic::tag_tr<tag_p> &&
                        nkr::generic::tag::type_tr<tag_p> &&
                        nkr::generic::tag::identity_tr<tag_p>;
                }
            };
            static_assert(tag_ts::AND<iterator_t>());
        }
        // [_a75ee664_019d_4764_a2fc_947dc3d384e7]
    }

    TEST_SUITE("nkr::constant_ttg")
    {
        // [_1f16a7a9_ef47_4a1c_8755_3b0d4f953087]
        TEST_CASE("")
        {
            static_assert(nkr::generic::tag_ttr<nkr::constant_ttg>);
            static_assert(nkr::generic::tag::template_ttr<nkr::constant_ttg>);
            static_assert(nkr::generic::tag::identity_ttr<nkr::constant_ttg>);
        }
        // [_1f16a7a9_ef47_4a1c_8755_3b0d4f953087]
    }

    TEST_SUITE("nkr::constant_t")
    {
        TEST_CASE("temp")
        {
            using false_t = nkr::constant_t<nkr::boolean::cpp_t, false>;
            using true_t = nkr::constant_t<nkr::boolean::cpp_t, true>;

            CHECK(false_t::Value() == false);
            CHECK(true_t::Value() == true);

            CHECK(static_cast<nkr::boolean::cpp_t>(false_t()) == false);
            CHECK(static_cast<nkr::boolean::cpp_t>(true_t()) == true);

            CHECK(false_t()() == false);
            CHECK(true_t()() == true);
        }
    }

}
