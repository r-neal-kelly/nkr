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
        TEST_SUITE("label labels")
        {
            TEST_SUITE("tag_lb")
            {
                // [_a56cef09_b052_434e_9d00_99b1fb4a6baf]
                TEST_CASE("should satisfy the appropriate generic type tag")
                {
                    static_assert(nkr::generic::tag_tr<nkr::constant_tg>);
                    static_assert(nkr::generic::tag_tr<const nkr::constant_tg>);
                    static_assert(nkr::generic::tag_tr<volatile nkr::constant_tg>);
                    static_assert(nkr::generic::tag_tr<const volatile nkr::constant_tg>);
                }
                // [_a56cef09_b052_434e_9d00_99b1fb4a6baf]
            }

            TEST_SUITE("type_lb")
            {
                // [_18f1d1f0_6477_425a_831a_7549d5b1335d]
                TEST_CASE("should satisfy the appropriate generic type tag")
                {
                    static_assert(nkr::generic::tag::type_tr<nkr::constant_tg>);
                    static_assert(nkr::generic::tag::type_tr<const nkr::constant_tg>);
                    static_assert(nkr::generic::tag::type_tr<volatile nkr::constant_tg>);
                    static_assert(nkr::generic::tag::type_tr<const volatile nkr::constant_tg>);
                }
                // [_18f1d1f0_6477_425a_831a_7549d5b1335d]
            }

            TEST_SUITE("identity_lb")
            {
                // [_bee91228_cb6b_42f5_b11e_c6dc9c716b2f]
                TEST_CASE("should satisfy the appropriate generic type tag")
                {
                    static_assert(nkr::generic::tag::identity_tr<nkr::constant_tg>);
                    static_assert(nkr::generic::tag::identity_tr<const nkr::constant_tg>);
                    static_assert(nkr::generic::tag::identity_tr<volatile nkr::constant_tg>);
                    static_assert(nkr::generic::tag::identity_tr<const volatile nkr::constant_tg>);
                }
                // [_bee91228_cb6b_42f5_b11e_c6dc9c716b2f]
            }
        }

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
        TEST_CASE_TEMPLATE("each should satisfy the following type traits",
                           tag_p,
                           nkr::constant_tg,
                           const nkr::constant_tg,
                           volatile nkr::constant_tg,
                           const volatile nkr::constant_tg)
        {
            static_assert(nkr::generic::tag_tr<tag_p>);
            static_assert(nkr::generic::tag::type_tr<tag_p>);
            static_assert(nkr::generic::tag::identity_tr<tag_p>);
        }
        // [_a75ee664_019d_4764_a2fc_947dc3d384e7]
    }

    TEST_SUITE("nkr::constant_ttg")
    {
        TEST_SUITE("label labels")
        {
            TEST_SUITE("tag_lb")
            {
                // [_bba6e116_37df_4f5d_a98c_dda7aac7c45d]
                TEST_CASE("should satisfy the appropriate generic template tag and generic type tag")
                {
                    static_assert(nkr::generic::tag_ttr<nkr::constant_ttg>);

                    static_assert(nkr::generic::tag_tr<nkr::constant_ttg<>>);
                    static_assert(nkr::generic::tag_tr<const nkr::constant_ttg<>>);
                    static_assert(nkr::generic::tag_tr<volatile nkr::constant_ttg<>>);
                    static_assert(nkr::generic::tag_tr<const volatile nkr::constant_ttg<>>);
                }
                // [_bba6e116_37df_4f5d_a98c_dda7aac7c45d]
            }

            TEST_SUITE("template_lb")
            {
                // [_65846497_ba0c_41be_9534_c2e46baf01d2]
                TEST_CASE("should satisfy the appropriate generic template tag and generic type tag")
                {
                    static_assert(nkr::generic::tag::template_ttr<nkr::constant_ttg>);

                    static_assert(nkr::generic::tag::template_tr<nkr::constant_ttg<>>);
                    static_assert(nkr::generic::tag::template_tr<const nkr::constant_ttg<>>);
                    static_assert(nkr::generic::tag::template_tr<volatile nkr::constant_ttg<>>);
                    static_assert(nkr::generic::tag::template_tr<const volatile nkr::constant_ttg<>>);
                }
                // [_65846497_ba0c_41be_9534_c2e46baf01d2]
            }

            TEST_SUITE("identity_lb")
            {
                // [_0c11ab3d_1046_4492_8bcf_cda94bbc48a9]
                TEST_CASE("should satisfy the appropriate generic template tag and generic type tag")
                {
                    static_assert(nkr::generic::tag::identity_ttr<nkr::constant_ttg>);

                    static_assert(nkr::generic::tag::identity_tr<nkr::constant_ttg<>>);
                    static_assert(nkr::generic::tag::identity_tr<const nkr::constant_ttg<>>);
                    static_assert(nkr::generic::tag::identity_tr<volatile nkr::constant_ttg<>>);
                    static_assert(nkr::generic::tag::identity_tr<const volatile nkr::constant_ttg<>>);
                }
                // [_0c11ab3d_1046_4492_8bcf_cda94bbc48a9]
            }
        }

        // [_1f16a7a9_ef47_4a1c_8755_3b0d4f953087]
        TEST_CASE("should satisfy the following template traits")
        {
            static_assert(nkr::generic::tag_ttr<nkr::constant_ttg>);
            static_assert(nkr::generic::tag::template_ttr<nkr::constant_ttg>);
            static_assert(nkr::generic::tag::identity_ttr<nkr::constant_ttg>);
        }
        // [_1f16a7a9_ef47_4a1c_8755_3b0d4f953087]

        // [_61c47f9b_a744_4135_96a8_74caa38a4b63]
        TEST_CASE_TEMPLATE("each should satisfy the following type traits",
                           tag_p,
                           nkr::constant_ttg<>,
                           const nkr::constant_ttg<>,
                           volatile nkr::constant_ttg<>,
                           const volatile nkr::constant_ttg<>)
        {
            static_assert(nkr::generic::tag_tr<tag_p>);
            static_assert(nkr::generic::tag::template_tr<tag_p>);
            static_assert(nkr::generic::tag::identity_tr<tag_p>);
        }
        // [_61c47f9b_a744_4135_96a8_74caa38a4b63]
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
