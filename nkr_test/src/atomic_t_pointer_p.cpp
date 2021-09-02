/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/atomic_t.h"

#include "intrinsics.h"

namespace nkr {

    TEST_SUITE("atomic_t<pointer_tr pointer_p>")
    {
    #define _               \
        word_t*, real_t*

        TEST_SUITE("aliases")
        {

        }

        TEST_SUITE("static data")
        {

        }

        TEST_SUITE("object data")
        {

        }

        TEST_SUITE("objects")
        {

        }

        TEST_SUITE("methods")
        {
            TEST_SUITE("Access()")
            {
                /// [_3e84679c_3f6e_4da4_8a70_5ff162ce626f]
                TEST_CASE_TEMPLATE("should return its value", pointer_p, _)
                {
                    pointer_p random = Random<pointer_p>();
                    const atomic_t<pointer_p> atom(random);
                    CHECK(atom.Access() == random);
                }
                /// [_3e84679c_3f6e_4da4_8a70_5ff162ce626f]

                /// [_bbdb8a97_83ec_461f_95ed_06df063b8587]
                TEST_CASE_TEMPLATE("should not change its value", pointer_p, _)
                {
                    pointer_p random = Random<pointer_p>();
                    const atomic_t<pointer_p> atom(random);
                    atom.Access();
                    CHECK(atom == random);
                }
                /// [_bbdb8a97_83ec_461f_95ed_06df063b8587]
            }

            TEST_SUITE("Assign()")
            {
                /// [_a5dba8d0_be71_4233_8961_db3a3ce0e68f]
                TEST_CASE_TEMPLATE("should set its value to the passed value", pointer_p, _)
                {
                    pointer_p random_a = Random<pointer_p>();
                    pointer_p random_b = Random<pointer_p>();
                    atomic_t<pointer_p> atom(random_a);
                    atom.Assign(random_b);
                    CHECK(atom == random_b);
                }
                /// [_a5dba8d0_be71_4233_8961_db3a3ce0e68f]

                /// [_2ba4b32d_f0ab_40a2_83ca_f9426b07f465]
                TEST_CASE_TEMPLATE("should return itself", pointer_p, _)
                {
                    pointer_p random_a = Random<pointer_p>();
                    pointer_p random_b = Random<pointer_p>();
                    atomic_t<pointer_p> atom(random_a);
                    CHECK(&atom.Assign(random_b) == &atom);
                }
                /// [_2ba4b32d_f0ab_40a2_83ca_f9426b07f465]
                
                /// [_a4faf5b5_526f_411d_b14d_2531437acdc4]
                TEST_CASE("should work with types convertible to its value_t")
                {
                    struct base_t {};
                    struct derived_t : base_t {};

                    base_t* random_a = Random<base_t*>();
                    derived_t* random_b = Random<derived_t*>();
                    atomic_t<base_t*> atom(random_a);
                    atom.Assign(random_b);
                    CHECK(atom == static_cast<base_t*>(random_b));
                }
                /// [_a4faf5b5_526f_411d_b14d_2531437acdc4]

                /// [_4dd28985_f259_46cc_959f_dae795a8cd25]
                template <typename atomic_p, typename value_t>
                concept assign_tr = requires(atomic_p atomic, value_t value)
                {
                    atomic.Assign(value);
                };
                TEST_CASE_TEMPLATE("should not work with void pointer", pointer_p, _)
                {
                    CHECK(assign_tr<atomic_t<pointer_p>, void_t*> == false);
                }
                /// [_4dd28985_f259_46cc_959f_dae795a8cd25]
            }

            TEST_SUITE("")
            {

            }

            TEST_SUITE("")
            {

            }

            TEST_SUITE("")
            {

            }

            TEST_SUITE("")
            {

            }

            TEST_SUITE("")
            {

            }

            TEST_SUITE("")
            {

            }
        }

        TEST_SUITE("casts")
        {
            TEST_SUITE("value_t()")
            {
                /// [_4dce474d_ac4f_4721_a5fc_abecc537cbf9]
                TEST_CASE_TEMPLATE("should explicitly return a copy of its value", pointer_p, _)
                {
                    pointer_p random = Random<pointer_p>();
                    const atomic_t<pointer_p> atom(random);
                    CHECK(static_cast<pointer_p>(atom) == random);
                }
                /// [_4dce474d_ac4f_4721_a5fc_abecc537cbf9]

                /// [_1a305a11_e7eb_4081_a5a8_e432ea50b9d9]
                TEST_CASE_TEMPLATE("should implicitly return a copy of its value", pointer_p, _)
                {
                    pointer_p random = Random<pointer_p>();
                    const atomic_t<pointer_p> atom(random);
                    pointer_p value = atom;
                    CHECK(value == random);
                }
                /// [_1a305a11_e7eb_4081_a5a8_e432ea50b9d9]

                /// [_df261ad7_4e58_4f39_82e4_ea2c59272819]
                TEST_CASE_TEMPLATE("should not change its value", pointer_p, _)
                {
                    pointer_p random = Random<pointer_p>();
                    const atomic_t<pointer_p> atom(random);
                    pointer_p value = atom;
                    CHECK(atom == random);
                }
                /// [_df261ad7_4e58_4f39_82e4_ea2c59272819]

                /// [_06dbb3d9_5894_4605_8641_6bd752f9c782]
                TEST_CASE_TEMPLATE("should implicitly allow for arithmetic operators", pointer_p, _)
                {
                    pointer_p random_a = Random<pointer_p>();
                    word_t random_b = Random<word_t>();
                    const atomic_t<pointer_p> atom(random_a);
                    CHECK((atom + random_b) == (random_a + random_b));
                    CHECK((atom - random_b) == (random_a - random_b));
                }
                /// [_06dbb3d9_5894_4605_8641_6bd752f9c782]

                /// [_7f24c559_320d_46d3_a45c_625129a38663]
                TEST_CASE_TEMPLATE("should implicitly allow for logical operators", pointer_p, _)
                {
                    pointer_p random;
                    do {
                        random = Random<pointer_p>();
                    } while (random == nullptr);
                    const atomic_t<pointer_p> atom(random);
                    CHECK(atom);
                    CHECK(!!atom);
                    CHECK(atom || false);
                    CHECK(atom && true);
                    CHECK(atom ? true : false);
                }
                /// [_7f24c559_320d_46d3_a45c_625129a38663]

                /// [_ba6c7bcb_a826_4fe1_bd09_2a9bb9541f50]
                TEST_CASE_TEMPLATE("should implicitly allow for comparison operators", pointer_p, _)
                {
                    pointer_p random = Random<pointer_p>();
                    const atomic_t<pointer_p> atom(random);
                    CHECK(atom == random);
                    CHECK_FALSE(atom != random);
                    CHECK_FALSE(atom < random);
                    CHECK_FALSE(atom > random);
                    CHECK(atom <= random);
                    CHECK(atom >= random);
                    CHECK(atom <=> random == 0);
                }
                /// [_ba6c7bcb_a826_4fe1_bd09_2a9bb9541f50]
            }
        }

        TEST_SUITE("operators")
        {
            TEST_SUITE("()()")
            {
                /// [_33d5b04b_b5b6_4710_b083_044534ddf67c]
                TEST_CASE_TEMPLATE("should return a copy of its value", pointer_p, _)
                {
                    pointer_p random = Random<pointer_p>();
                    const atomic_t<pointer_p> atom(random);
                    CHECK(atom() == random);
                }
                /// [_33d5b04b_b5b6_4710_b083_044534ddf67c]

                /// [_4445ebf2_9581_4c81_a0ab_f2a848c4b30c]
                TEST_CASE_TEMPLATE("should not change its value", pointer_p, _)
                {
                    pointer_p random = Random<pointer_p>();
                    const atomic_t<pointer_p> atom(random);
                    pointer_p value = atom();
                    CHECK(atom == random);
                }
                /// [_4445ebf2_9581_4c81_a0ab_f2a848c4b30c]
            }

            TEST_SUITE("+=()")
            {
                /// [_552f17e6_f0b0_4115_9009_e427abb2c831]
                TEST_CASE_TEMPLATE("should set its value to value + passed value", pointer_p, _)
                {
                    pointer_p random_a = Random<pointer_p>();
                    word_t random_b = Random<word_t>();
                    atomic_t<pointer_p> atom(random_a);
                    atom += random_b;
                    CHECK(atom == (random_a += random_b));
                }
                /// [_552f17e6_f0b0_4115_9009_e427abb2c831]

                /// [_d5c9ce80_6b42_46a8_8fe3_aa77c24d87a0]
                TEST_CASE_TEMPLATE("should return itself", pointer_p, _)
                {
                    pointer_p random_a = Random<pointer_p>();
                    word_t random_b = Random<word_t>();
                    atomic_t<pointer_p> atom(random_a);
                    CHECK(&(atom += random_b) == &atom);
                }
                /// [_d5c9ce80_6b42_46a8_8fe3_aa77c24d87a0]
            }

            TEST_SUITE("-=()")
            {
                /// [_d207364c_c304_4dd2_92d4_74d0a02091eb]
                TEST_CASE_TEMPLATE("should set its value to value - passed value", pointer_p, _)
                {
                    pointer_p random_a = Random<pointer_p>();
                    word_t random_b = Random<word_t>();
                    atomic_t<pointer_p> atom(random_a);
                    atom -= random_b;
                    CHECK(atom == (random_a -= random_b));
                }
                /// [_d207364c_c304_4dd2_92d4_74d0a02091eb]

                /// [_eed6fe54_8e60_4acc_bdc8_419b3ec4bdac]
                TEST_CASE_TEMPLATE("should return itself", pointer_p, _)
                {
                    pointer_p random_a = Random<pointer_p>();
                    word_t random_b = Random<word_t>();
                    atomic_t<pointer_p> atom(random_a);
                    CHECK(&(atom -= random_b) == &atom);
                }
                /// [_eed6fe54_8e60_4acc_bdc8_419b3ec4bdac]
            }

            TEST_SUITE("++()")
            {
                /// [_bd616d99_2e42_4cc8_9df3_ba5c40b16233]
                TEST_CASE_TEMPLATE("should set its value to value + 1", pointer_p, _)
                {
                    pointer_p random = Random<pointer_p>();
                    atomic_t<pointer_p> atom(random);
                    ++atom;
                    CHECK(atom == (random += 1));
                }
                /// [_bd616d99_2e42_4cc8_9df3_ba5c40b16233]

                /// [_c5e5d4d4_e90d_4fe1_8705_df3dab86ad33]
                TEST_CASE_TEMPLATE("should return itself", pointer_p, _)
                {
                    pointer_p random = Random<pointer_p>();
                    atomic_t<pointer_p> atom(random);
                    CHECK(&(++atom) == &atom);
                }
                /// [_c5e5d4d4_e90d_4fe1_8705_df3dab86ad33]
            }

            TEST_SUITE("++(int)")
            {
                /// [_95614eca_1112_41c1_a884_53560f16f900]
                TEST_CASE_TEMPLATE("should set its value to value + 1", pointer_p, _)
                {
                    pointer_p random = Random<pointer_p>();
                    atomic_t<pointer_p> atom(random);
                    atom++;
                    CHECK(atom == (random += 1));
                }
                /// [_95614eca_1112_41c1_a884_53560f16f900]

                /// [_131e60fd_1364_4781_b8a8_737448ca1412]
                TEST_CASE_TEMPLATE("should return its old value", pointer_p, _)
                {
                    pointer_p random = Random<pointer_p>();
                    atomic_t<pointer_p> atom(random);
                    CHECK(atom++ == random);
                }
                /// [_131e60fd_1364_4781_b8a8_737448ca1412]
            }

            TEST_SUITE("--()")
            {
                /// [_19bda1d1_2e7d_47c2_8b7a_5b686254fde6]
                TEST_CASE_TEMPLATE("should set its value to value - 1", pointer_p, _)
                {
                    pointer_p random = Random<pointer_p>();
                    atomic_t<pointer_p> atom(random);
                    --atom;
                    CHECK(atom == (random -= 1));
                }
                /// [_19bda1d1_2e7d_47c2_8b7a_5b686254fde6]

                /// [_050adc8f_0f21_4dde_bdaa_9f5e4a984ead]
                TEST_CASE_TEMPLATE("should return itself", pointer_p, _)
                {
                    pointer_p random = Random<pointer_p>();
                    atomic_t<pointer_p> atom(random);
                    CHECK(&(--atom) == &atom);
                }
                /// [_050adc8f_0f21_4dde_bdaa_9f5e4a984ead]
            }

            TEST_SUITE("--(int)")
            {
                /// [_f6f195e1_9243_472b_bc97_47c1d94632c4]
                TEST_CASE_TEMPLATE("should set its value to value - 1", pointer_p, _)
                {
                    pointer_p random = Random<pointer_p>();
                    atomic_t<pointer_p> atom(random);
                    atom--;
                    CHECK(atom == (random -= 1));
                }
                /// [_f6f195e1_9243_472b_bc97_47c1d94632c4]

                /// [_f0f2e042_c6e8_4e11_a427_75c83df3c3ef]
                TEST_CASE_TEMPLATE("should return its old value", pointer_p, _)
                {
                    pointer_p random = Random<pointer_p>();
                    atomic_t<pointer_p> atom(random);
                    CHECK(atom-- == random);
                }
                /// [_f0f2e042_c6e8_4e11_a427_75c83df3c3ef]
            }

            TEST_SUITE("->()")
            {
                /// [_0cd55105_4d01_462e_a5fe_bcb2bcea5516]
                TEST_CASE_TEMPLATE("should be able to access its value's values", pointer_p, _)
                {
                    using unit_t = atomic_t<pointer_p>::unit_t;

                    unit_t random = Random<unit_t>();
                    struct wrap_t { unit_t value; } wrap(random);
                    const atomic_t<wrap_t*> atom(&wrap);
                    CHECK(atom->value == random);
                }
                /// [_0cd55105_4d01_462e_a5fe_bcb2bcea5516]

                /// [_047bed10_4ae3_46c2_864a_6e22389c8f92]
                TEST_CASE_TEMPLATE("should be able to assign its value's values", pointer_p, _)
                {
                    using unit_t = atomic_t<pointer_p>::unit_t;

                    unit_t random_a = Random<unit_t>();
                    unit_t random_b = Random<unit_t>();
                    struct wrap_t { unit_t value; } wrap(random_a);
                    const atomic_t<wrap_t*> atom(&wrap);
                    atom->value = random_b;
                    CHECK(wrap.value == random_b);
                }
                /// [_047bed10_4ae3_46c2_864a_6e22389c8f92]

                /// [_44c3bfc9_9d08_4831_81a2_4c5cd5f51a2d]
                TEST_CASE_TEMPLATE("should not change its own value", pointer_p, _)
                {
                    using unit_t = atomic_t<pointer_p>::unit_t;

                    unit_t random_a = Random<unit_t>();
                    unit_t random_b = Random<unit_t>();
                    struct wrap_t { unit_t value; } wrap(random_a);
                    const atomic_t<wrap_t*> atom(&wrap);
                    atom->value = random_b;
                    CHECK(atom == &wrap);
                }
                /// [_44c3bfc9_9d08_4831_81a2_4c5cd5f51a2d]
            }

            TEST_SUITE("*()")
            {
                /// [_5742204e_627d_4598_acb6_cc5ff6a1b163]
                TEST_CASE_TEMPLATE("should be able to access its value's value", pointer_p, _)
                {
                    using unit_t = atomic_t<pointer_p>::unit_t;

                    unit_t random = Random<unit_t>();
                    const atomic_t<pointer_p> atom(&random);
                    CHECK(*atom == random);
                }
                /// [_5742204e_627d_4598_acb6_cc5ff6a1b163]

                /// [_ef5aefb7_c5cb_4863_9812_10b3a72bdd71]
                TEST_CASE_TEMPLATE("should be able to assign its value's value", pointer_p, _)
                {
                    using unit_t = atomic_t<pointer_p>::unit_t;

                    unit_t random_a = Random<unit_t>();
                    unit_t random_b = Random<unit_t>();
                    const atomic_t<pointer_p> atom(&random_a);
                    *atom = random_b;
                    CHECK(random_a == random_b);
                }
                /// [_ef5aefb7_c5cb_4863_9812_10b3a72bdd71]

                /// [_5b66e0f4_7661_4602_aa86_1de0039cc1c3]
                TEST_CASE_TEMPLATE("should not change its own value", pointer_p, _)
                {
                    using unit_t = atomic_t<pointer_p>::unit_t;

                    unit_t random_a = Random<unit_t>();
                    unit_t random_b = Random<unit_t>();
                    const atomic_t<pointer_p> atom(&random_a);
                    *atom = random_b;
                    CHECK(atom == &random_a);
                }
                /// [_5b66e0f4_7661_4602_aa86_1de0039cc1c3]
            }

            TEST_SUITE("[]()")
            {
                /// [_61a845a4_7c90_4d1e_817f_74fa09b23659]
                TEST_CASE_TEMPLATE("should be able to access its values' values", pointer_p, _)
                {
                    using unit_t = atomic_t<pointer_p>::unit_t;

                    unit_t randoms[16];
                    for (index_t idx = 0, end = 16; idx < end; idx += 1) {
                        randoms[idx] = Random<unit_t>();
                    }
                    const atomic_t<pointer_p> atom(randoms);
                    index_t index = Random<index_t>(0, 15);
                    CHECK(atom[index] == randoms[index]);
                }
                /// [_61a845a4_7c90_4d1e_817f_74fa09b23659]
                
                /// [_e1d47c27_8b19_4dde_8dda_1909d5b6174a]
                TEST_CASE_TEMPLATE("should be able to assign its values' values", pointer_p, _)
                {
                    using unit_t = atomic_t<pointer_p>::unit_t;

                    unit_t randoms[16];
                    for (index_t idx = 0, end = 16; idx < end; idx += 1) {
                        randoms[idx] = Random<unit_t>();
                    }
                    const atomic_t<pointer_p> atom(randoms);
                    index_t index = Random<index_t>(0, 15);
                    unit_t random = Random<unit_t>();
                    atom[index] = random;
                    CHECK(randoms[index] == random);
                }
                /// [_e1d47c27_8b19_4dde_8dda_1909d5b6174a]

                /// [_46f33f5a_5ee8_4f5d_920c_c4d2e462bc49]
                TEST_CASE_TEMPLATE("should not change its own values", pointer_p, _)
                {
                    using unit_t = atomic_t<pointer_p>::unit_t;

                    unit_t randoms[16];
                    for (index_t idx = 0, end = 16; idx < end; idx += 1) {
                        randoms[idx] = Random<unit_t>();
                    }
                    const atomic_t<pointer_p> atom(randoms);
                    index_t index = Random<index_t>(0, 15);
                    unit_t random = Random<unit_t>();
                    atom[index] = random;
                    CHECK(atom == randoms);
                }
                /// [_46f33f5a_5ee8_4f5d_920c_c4d2e462bc49]
            }
        }

        TEST_SUITE("none_t interface")
        {
            TEST_SUITE("none_ctor()")
            {
                /// [_714d230d_baa3_46bd_975f_882f3fd94fcd]
                TEST_CASE_TEMPLATE("should explicitly set its value to the default value", pointer_p, _)
                {
                    atomic_t<pointer_p> atom((none_t()));
                    CHECK(atom == atomic_t<pointer_p>::DEFAULT_VALUE);
                }
                /// [_714d230d_baa3_46bd_975f_882f3fd94fcd]

                /// [_50f7eb64_7df4_4804_93a3_c606d582436e]
                TEST_CASE_TEMPLATE("should implicitly set its value to the default value", pointer_p, _)
                {
                    atomic_t<pointer_p> atom = none_t();
                    CHECK(atom == atomic_t<pointer_p>::DEFAULT_VALUE);
                }
                /// [_50f7eb64_7df4_4804_93a3_c606d582436e]
            }

            TEST_SUITE("=(none_t)")
            {
                /// [_f791564a_ab02_4dae_a826_21b4861afabb]
                TEST_CASE_TEMPLATE("should set its value to the default value", pointer_p, _)
                {
                    pointer_p random = Random<pointer_p>();
                    atomic_t<pointer_p> atom(random);
                    atom = none_t();
                    CHECK(atom == atomic_t<pointer_p>::DEFAULT_VALUE);
                }
                /// [_f791564a_ab02_4dae_a826_21b4861afabb]

                /// [_07a6853a_24d8_4615_a3ac_ea843b23723a]
                TEST_CASE_TEMPLATE("should evaluate as false after being set to none", pointer_p, _)
                {
                    pointer_p random = Random<pointer_p>();
                    atomic_t<pointer_p> atom(random);
                    atom = none_t();
                    CHECK(static_cast<bool_t>(atom) == false);
                }
                /// [_07a6853a_24d8_4615_a3ac_ea843b23723a]

                /// [_6334f264_e99d_4833_9325_206dc2020c25]
                TEST_CASE_TEMPLATE("should return itself", pointer_p, _)
                {
                    pointer_p random = Random<pointer_p>();
                    atomic_t<pointer_p> atom(random);
                    CHECK(&(atom = none_t()) == &atom);
                }
                /// [_6334f264_e99d_4833_9325_206dc2020c25]
            }

            TEST_SUITE("==(none_t)")
            {
                /// [_99ed6aa2_edce_4a09_a02e_20b4813e6d7a]
                TEST_CASE_TEMPLATE("should return true when default constructed", pointer_p, _)
                {
                    const atomic_t<pointer_p> atom;
                    CHECK(atom == none_t());
                }
                /// [_99ed6aa2_edce_4a09_a02e_20b4813e6d7a]

                /// [_caa2e675_361c_434d_a212_0f883a1bb91d]
                TEST_CASE_TEMPLATE("should return true if its value is nullptr", pointer_p, _)
                {
                    const atomic_t<pointer_p> atom(nullptr);
                    CHECK(atom == none_t());
                }
                /// [_caa2e675_361c_434d_a212_0f883a1bb91d]

                /// [_aab25727_80d3_4bd3_8e9e_03d7112f9943]
                TEST_CASE_TEMPLATE("should not change its value", pointer_p, _)
                {
                    pointer_p random = Random<pointer_p>();
                    const atomic_t<pointer_p> atom(random);
                    atom == none_t();
                    CHECK(atom == random);
                }
                /// [_aab25727_80d3_4bd3_8e9e_03d7112f9943]
            }

            TEST_SUITE("!=(none_t)")
            {
                /// [_f5814f4b_dfbe_4c43_a6c1_33e322e87ff6]
                TEST_CASE_TEMPLATE("should return false when default constructed", pointer_p, _)
                {
                    const atomic_t<pointer_p> atom;
                    CHECK_FALSE(atom != none_t());
                }
                /// [_f5814f4b_dfbe_4c43_a6c1_33e322e87ff6]

                /// [_dc378d95_3f12_4b56_8b86_a06734b5a21d]
                TEST_CASE_TEMPLATE("should return false if its value is nullptr", pointer_p, _)
                {
                    const atomic_t<pointer_p> atom(nullptr);
                    CHECK_FALSE(atom != none_t());
                }
                /// [_dc378d95_3f12_4b56_8b86_a06734b5a21d]

                /// [_608904fe_120e_4339_8a49_1bd6d4c93cda]
                TEST_CASE_TEMPLATE("should not change its value", pointer_p, _)
                {
                    pointer_p random = Random<pointer_p>();
                    const atomic_t<pointer_p> atom(random);
                    atom != none_t();
                    CHECK(atom == random);
                }
                /// [_608904fe_120e_4339_8a49_1bd6d4c93cda]
            }
        }

    #undef _
    }

}
