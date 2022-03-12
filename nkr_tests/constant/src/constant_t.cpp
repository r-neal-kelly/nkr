/*
    Copyright 2022 r-neal-kelly
*/

#include "nkr/built_in/forward.h"
#include "nkr/constant_t.h"
#include "nkr/generic/implementing/interface/template_tr.h"
#include "nkr/generic/implementing/interface/type_tr.h"
#include "nkr/generic/tag_tr.h"
#include "nkr/generic/tag/identity_tr.h"
#include "nkr/generic/tag/template_tr.h"
#include "nkr/generic/tag/type_tr.h"
#include "nkr/tr.h"
#include "nkr/tuple/types_t.h"

#include "doctest.h"

namespace nkr {

    TEST_SUITE("nkr::constant_tg")
    {
        // [_a75ee664_019d_4764_a2fc_947dc3d384e7]
        TEST_CASE_TEMPLATE("all qualifications should satisfy the following generic type traits",
                           type_tag_p,

                           nkr::constant_tg,
                           const nkr::constant_tg,
                           volatile nkr::constant_tg,
                           const volatile nkr::constant_tg)
        {
            static_assert(nkr::generic::tag_tr<type_tag_p>);
            static_assert(nkr::generic::tag::type_tr<type_tag_p>);
            static_assert(nkr::generic::tag::identity_tr<type_tag_p>);
        }
        // [_a75ee664_019d_4764_a2fc_947dc3d384e7]

        // [_d7f5b641_e756_4d14_be2e_6511ef9f0110]
        TEST_CASE("should work within a nkr::TR expression in the place of any instantiation of its primary entity")
        {
            using subject_ts = nkr::ts<
                nkr::AND_tg,

                nkr::constant_t<bool, false>,
                nkr::constant_t<bool, true>,

                nkr::constant_t<int, 0>,
                nkr::constant_t<int, 1>
            >;

            static_assert(nkr::TR<
                          subject_ts,
                          nkr::just_tg, nkr::t<nkr::constant_tg>
            >() == true);

            static_assert(nkr::TR<
                          const subject_ts,
                          nkr::just_tg, nkr::t<const nkr::constant_tg>
            >() == true);

            static_assert(nkr::TR<
                          volatile subject_ts,
                          nkr::just_tg, nkr::t<volatile nkr::constant_tg>
            >() == true);

            static_assert(nkr::TR<
                          const volatile subject_ts,
                          nkr::just_tg, nkr::t<const volatile nkr::constant_tg>
            >() == true);
        }
        // [_d7f5b641_e756_4d14_be2e_6511ef9f0110]

        TEST_SUITE("label labels")
        {
            TEST_SUITE("tag_lb")
            {
                // [_a56cef09_b052_434e_9d00_99b1fb4a6baf]
                TEST_CASE("should allow its outer type to satisfy the appropriate generic type tag")
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
                TEST_CASE("should allow its outer type to satisfy the appropriate generic type tag")
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
                TEST_CASE("should allow its outer type to satisfy the appropriate generic type tag")
                {
                    static_assert(nkr::generic::tag::identity_tr<nkr::constant_tg>);
                    static_assert(nkr::generic::tag::identity_tr<const nkr::constant_tg>);
                    static_assert(nkr::generic::tag::identity_tr<volatile nkr::constant_tg>);
                    static_assert(nkr::generic::tag::identity_tr<const volatile nkr::constant_tg>);
                }
                // [_bee91228_cb6b_42f5_b11e_c6dc9c716b2f]
            }
        }
    }

    TEST_SUITE("nkr::constant_ttg")
    {
        // [_1f16a7a9_ef47_4a1c_8755_3b0d4f953087]
        TEST_CASE("should satisfy the following generic template traits")
        {
            static_assert(nkr::generic::tag_ttr<nkr::constant_ttg>);
            static_assert(nkr::generic::tag::template_ttr<nkr::constant_ttg>);
            static_assert(nkr::generic::tag::identity_ttr<nkr::constant_ttg>);
        }
        // [_1f16a7a9_ef47_4a1c_8755_3b0d4f953087]

        // [_61c47f9b_a744_4135_96a8_74caa38a4b63]
        TEST_CASE_TEMPLATE("each qualification of any instantiated type should satisfy the following generic type traits",
                           instantiated_type_tag_p,

                           nkr::constant_ttg<>,
                           const nkr::constant_ttg<>,
                           volatile nkr::constant_ttg<>,
                           const volatile nkr::constant_ttg<>)
        {
            static_assert(nkr::generic::tag_tr<instantiated_type_tag_p>);
            static_assert(nkr::generic::tag::template_tr<instantiated_type_tag_p>);
            static_assert(nkr::generic::tag::identity_tr<instantiated_type_tag_p>);
        }
        // [_61c47f9b_a744_4135_96a8_74caa38a4b63]

        TEST_SUITE("label labels")
        {
            TEST_SUITE("tag_lb")
            {
                // [_0ea2e923_3526_4842_8d0a_df32fe816a10]
                TEST_CASE("should allow its outer template to satisfy the appropriate generic template tag")
                {
                    static_assert(nkr::generic::tag_ttr<nkr::constant_ttg>);
                }
                // [_0ea2e923_3526_4842_8d0a_df32fe816a10]

                // [_bba6e116_37df_4f5d_a98c_dda7aac7c45d]
                TEST_CASE("should allow its instantiated outer type to satisfy the appropriate generic type tag")
                {
                    static_assert(nkr::generic::tag_tr<nkr::constant_ttg<>>);
                    static_assert(nkr::generic::tag_tr<const nkr::constant_ttg<>>);
                    static_assert(nkr::generic::tag_tr<volatile nkr::constant_ttg<>>);
                    static_assert(nkr::generic::tag_tr<const volatile nkr::constant_ttg<>>);
                }
                // [_bba6e116_37df_4f5d_a98c_dda7aac7c45d]
            }

            TEST_SUITE("template_lb")
            {
                // [_29beed5a_a3f3_4b23_aedd_38e86ec36819]
                TEST_CASE("should allow its outer template to satisfy the appropriate generic template tag")
                {
                    static_assert(nkr::generic::tag::template_ttr<nkr::constant_ttg>);
                }
                // [_29beed5a_a3f3_4b23_aedd_38e86ec36819]

                // [_65846497_ba0c_41be_9534_c2e46baf01d2]
                TEST_CASE("should allow its instantiated outer type to satisfy the appropriate generic type tag")
                {
                    static_assert(nkr::generic::tag::template_tr<nkr::constant_ttg<>>);
                    static_assert(nkr::generic::tag::template_tr<const nkr::constant_ttg<>>);
                    static_assert(nkr::generic::tag::template_tr<volatile nkr::constant_ttg<>>);
                    static_assert(nkr::generic::tag::template_tr<const volatile nkr::constant_ttg<>>);
                }
                // [_65846497_ba0c_41be_9534_c2e46baf01d2]
            }

            TEST_SUITE("identity_lb")
            {
                // [_2050293a_1fb1_4f94_bfc4_23ef2b32f123]
                TEST_CASE("should allow its outer template to satisfy the appropriate generic template tag")
                {
                    static_assert(nkr::generic::tag::identity_ttr<nkr::constant_ttg>);
                }
                // [_2050293a_1fb1_4f94_bfc4_23ef2b32f123]

                // [_0c11ab3d_1046_4492_8bcf_cda94bbc48a9]
                TEST_CASE("should allow its instantiated outer type to satisfy the appropriate generic type tag")
                {
                    static_assert(nkr::generic::tag::identity_tr<nkr::constant_ttg<>>);
                    static_assert(nkr::generic::tag::identity_tr<const nkr::constant_ttg<>>);
                    static_assert(nkr::generic::tag::identity_tr<volatile nkr::constant_ttg<>>);
                    static_assert(nkr::generic::tag::identity_tr<const volatile nkr::constant_ttg<>>);
                }
                // [_0c11ab3d_1046_4492_8bcf_cda94bbc48a9]
            }
        }
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

            static_assert(nkr::generic::implementing::interface::type_tr<nkr::constant_t<bool, false>>);
            static_assert(nkr::generic::implementing::interface::type_tr<nkr::constant_tg>);

            // unlike most template identities, nkr::constant_t can only satisfy nkr::interface::template_i with its template tag
            // because it necessarily takes a template value argument
            static_assert(nkr::generic::implementing::interface::template_ttr<nkr::constant_ttg>);
        }
    }

}
