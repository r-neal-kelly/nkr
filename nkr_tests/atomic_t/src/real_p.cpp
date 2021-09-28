/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/atomic_t.h"
#include "nkr/intrinsics.h"
#include "nkr/utils.h"

#include "doctest.h"

namespace nkr {

    TEST_SUITE("atomic_t<real_tr real_p>")
    {
    #if defined(nkr_IS_64_BIT)

    #define _           \
        r32_t, r64_t,   \
        real_t

    #elif defined(nkr_IS_32_BIT)

    #define _   \
        r32_t,  \
        real_t

    #endif

        TEST_SUITE("aliases")
        {
            TEST_SUITE("value_t")
            {
                /// [_83c3dcd9_5930_49a4_817b_3fe1d33a4550]
                TEST_CASE_TEMPLATE("should equal the passed in type", real_p, _)
                {
                    static_assert(is_tr<atomic_t<real_p>::value_t, real_p>);
                }
                /// [_83c3dcd9_5930_49a4_817b_3fe1d33a4550]
            }
        }

        TEST_SUITE("static data")
        {
            TEST_SUITE("DEFAULT_VALUE")
            {
                /// [_2761c14b_ad24_4d18_a896_4058e077d6de]
                TEST_CASE_TEMPLATE("should equal the default value of value_t", real_p, _)
                {
                    CHECK(atomic_t<real_p>::DEFAULT_VALUE == atomic_t<real_p>::value_t());
                }
                /// [_2761c14b_ad24_4d18_a896_4058e077d6de]

                /// [_1a55c887_94c9_41d4_addd_665545b62e49]
                TEST_CASE_TEMPLATE("should equal 0.0", real_p, _)
                {
                    CHECK(atomic_t<real_p>::DEFAULT_VALUE == 0.0);
                }
                /// [_1a55c887_94c9_41d4_addd_665545b62e49]
            }
        }

        TEST_SUITE("object data")
        {
            TEST_SUITE("value")
            {
                /// [_0e277dd4_8606_49bb_9991_daca43fd7993]
                TEST_CASE_TEMPLATE("should be a volatile value_t", real_p, _)
                {
                    static_assert(is_tr<decltype(atomic_t<real_p>::value), volatile real_p>);
                }
                /// [_0e277dd4_8606_49bb_9991_daca43fd7993]
            }
        }

        TEST_SUITE("objects")
        {
            TEST_SUITE("default_ctor()")
            {
                /// [_8274cab7_e07f_42fc_95fb_21159e5d182b]
                TEST_CASE_TEMPLATE("should set value to the default", real_p, _)
                {
                    atomic_t<real_p> atom;
                    CHECK(atom == atomic_t<real_p>::DEFAULT_VALUE);
                }
                /// [_8274cab7_e07f_42fc_95fb_21159e5d182b]
            }

            TEST_SUITE("value_ctor()")
            {
                /// [_5d612089_148d_4d8c_af54_9402bb4e0c2e]
                TEST_CASE_TEMPLATE("should explicitly set passed value", real_p, _)
                {
                    real_p random = Random<real_p>();
                    atomic_t<real_p> atom(random);
                    CHECK(atom == random);
                }
                /// [_5d612089_148d_4d8c_af54_9402bb4e0c2e]

                /// [_c082e3b1_a0eb_4a32_a12f_d01051b722d2]
                TEST_CASE_TEMPLATE("should implicitly set passed value", real_p, _)
                {
                    real_p random = Random<real_p>();
                    atomic_t<real_p> atom = random;
                    CHECK(atom == random);
                }
                /// [_c082e3b1_a0eb_4a32_a12f_d01051b722d2]

                /// [_027ec34c_9368_4ff3_890b_235196c7702e]
                TEST_CASE_TEMPLATE("should convert other types and set passed value", real_p, _)
                {
                    word_t random = Random<word_t>();
                    atomic_t<real_p> atom(random);
                    CHECK(atom == static_cast<real_p>(random));
                }
                /// [_027ec34c_9368_4ff3_890b_235196c7702e]
            }

            TEST_SUITE("copy_ctor()")
            {
                /// [_c1b86a21_9372_4474_96c1_6641b05fdd80]
                TEST_CASE_TEMPLATE("should explicitly copy the value of other", real_p, _)
                {
                    real_p random = Random<real_p>();
                    const atomic_t<real_p> other(random);
                    atomic_t<real_p> atom(other);
                    CHECK(atom == random);
                }
                /// [_c1b86a21_9372_4474_96c1_6641b05fdd80]

                /// [_83a52bb2_2362_4c41_908f_575a08582122]
                TEST_CASE_TEMPLATE("should implicitly copy the value of other", real_p, _)
                {
                    real_p random = Random<real_p>();
                    const atomic_t<real_p> other(random);
                    atomic_t<real_p> atom = other;
                    CHECK(atom == random);
                }
                /// [_83a52bb2_2362_4c41_908f_575a08582122]

                /// [_5d98cfc6_a426_440d_a0b6_d2a0a0a3c4a9]
                TEST_CASE_TEMPLATE("should not alter the value of other", real_p, _)
                {
                    real_p random = Random<real_p>();
                    const atomic_t<real_p> other(random);
                    atomic_t<real_p> atom(other);
                    CHECK(other == random);
                }
                /// [_5d98cfc6_a426_440d_a0b6_d2a0a0a3c4a9]
            }

            TEST_SUITE("move_ctor()")
            {
                /// [_ad08e960_ce87_457e_9795_e81944307359]
                TEST_CASE_TEMPLATE("should explicitly move the value of other", real_p, _)
                {
                    real_p random = Random<real_p>();
                    atomic_t<real_p> other(random);
                    atomic_t<real_p> atom(nkr::Move(other));
                    CHECK(atom == random);
                }
                /// [_ad08e960_ce87_457e_9795_e81944307359]

                /// [_83d42476_ed81_4e4c_b548_fc3a10af5fbe]
                TEST_CASE_TEMPLATE("should implicitly move the value of other", real_p, _)
                {
                    real_p random = Random<real_p>();
                    atomic_t<real_p> other(random);
                    atomic_t<real_p> atom = nkr::Move(other);
                    CHECK(atom == random);
                }
                /// [_83d42476_ed81_4e4c_b548_fc3a10af5fbe]

                /// [_e9f233ed_244c_4a3d_9a83_d09274e9097b]
                TEST_CASE_TEMPLATE("should set the value of other to the default", real_p, _)
                {
                    real_p random = Random<real_p>();
                    atomic_t<real_p> other(random);
                    atomic_t<real_p> atom(nkr::Move(other));
                    CHECK(other == atomic_t<real_p>::DEFAULT_VALUE);
                }
                /// [_e9f233ed_244c_4a3d_9a83_d09274e9097b]
            }

            TEST_SUITE("value_assignment_ctor()")
            {
                /// [_900b1558_c4f8_49c3_96b1_9056d76555ed]
                TEST_CASE_TEMPLATE("should set passed value", real_p, _)
                {
                    real_p random = Random<real_p>();
                    atomic_t<real_p> atom;
                    atom = random;
                    CHECK(atom == random);
                }
                /// [_900b1558_c4f8_49c3_96b1_9056d76555ed]

                /// [_12f5a276_c270_44de_8374_297242724a5c]
                TEST_CASE_TEMPLATE("should return itself", real_p, _)
                {
                    real_p random = Random<real_p>();
                    atomic_t<real_p> atom;
                    CHECK(&(atom = random) == &atom);
                }
                /// [_12f5a276_c270_44de_8374_297242724a5c]

                /// [_cb64aaa3_b39d_43af_9e6e_03298a723992]
                TEST_CASE_TEMPLATE("should convert other types and set passed value", real_p, _)
                {
                    word_t random = Random<word_t>();
                    atomic_t<real_p> atom;
                    atom = random;
                    CHECK(atom == static_cast<real_p>(random));
                }
                /// [_cb64aaa3_b39d_43af_9e6e_03298a723992]
            }

            TEST_SUITE("copy_assignment_ctor()")
            {
                /// [_de9354d0_a560_4f0c_b154_aee07071b26b]
                TEST_CASE_TEMPLATE("should copy the value of other", real_p, _)
                {
                    real_p random = Random<real_p>();
                    const atomic_t<real_p> other(random);
                    atomic_t<real_p> atom;
                    atom = other;
                    CHECK(atom == random);
                }
                /// [_de9354d0_a560_4f0c_b154_aee07071b26b]

                /// [_bfe07ea7_4f12_4dad_b13a_0afd47f849e7]
                TEST_CASE_TEMPLATE("should return itself", real_p, _)
                {
                    real_p random = Random<real_p>();
                    const atomic_t<real_p> other(random);
                    atomic_t<real_p> atom;
                    CHECK(&(atom = other) == &atom);
                }
                /// [_bfe07ea7_4f12_4dad_b13a_0afd47f849e7]

                /// [_654311ef_5dfb_4631_8204_eb8c37ff8ce2]
                TEST_CASE_TEMPLATE("should not alter the value of other", real_p, _)
                {
                    real_p random = Random<real_p>();
                    const atomic_t<real_p> other(random);
                    atomic_t<real_p> atom;
                    atom = other;
                    CHECK(other == random);
                }
                /// [_654311ef_5dfb_4631_8204_eb8c37ff8ce2]
            }

            TEST_SUITE("move_assignment_ctor()")
            {
                /// [_d98fa40a_5147_482b_8a01_95809a294e2b]
                TEST_CASE_TEMPLATE("should move the value of other", real_p, _)
                {
                    real_p random = Random<real_p>();
                    atomic_t<real_p> other(random);
                    atomic_t<real_p> atom;
                    atom = nkr::Move(other);
                    CHECK(atom == random);
                }
                /// [_d98fa40a_5147_482b_8a01_95809a294e2b]

                /// [_8fe990ca_7ced_419a_a2a6_d10796e8d4a1]
                TEST_CASE_TEMPLATE("should return itself", real_p, _)
                {
                    real_p random = Random<real_p>();
                    atomic_t<real_p> other(random);
                    atomic_t<real_p> atom;
                    CHECK(&(atom = nkr::Move(other)) == &atom);
                }
                /// [_8fe990ca_7ced_419a_a2a6_d10796e8d4a1]

                /// [_0d1b8d2e_33b4_4576_a466_761fb7452efc]
                TEST_CASE_TEMPLATE("should set the value of other to the default", real_p, _)
                {
                    real_p random = Random<real_p>();
                    atomic_t<real_p> other(random);
                    atomic_t<real_p> atom;
                    atom = nkr::Move(other);
                    CHECK(other == atomic_t<real_p>::DEFAULT_VALUE);
                }
                /// [_0d1b8d2e_33b4_4576_a466_761fb7452efc]
            }

            TEST_SUITE("dtor()")
            {
                /// [_9d5c2d8f_0af5_49f1_ba14_0bcc98d78dd4]
                TEST_CASE_TEMPLATE("should set its value to the default", real_p, _)
                {
                    real_p random = Random<real_p>();
                    atomic_t<real_p> atom(random);
                    atom.~atomic_t();
                    CHECK(atom == atomic_t<real_p>::DEFAULT_VALUE);
                }
                /// [_9d5c2d8f_0af5_49f1_ba14_0bcc98d78dd4]
            }
        }

        TEST_SUITE("methods")
        {
            TEST_SUITE("Access()")
            {
                /// [_bf5ad36e_5e23_42d0_b32b_d69acd736c5f]
                TEST_CASE_TEMPLATE("should return its value", real_p, _)
                {
                    real_p random = Random<real_p>();
                    const atomic_t<real_p> atom(random);
                    CHECK(atom.Access() == random);
                }
                /// [_bf5ad36e_5e23_42d0_b32b_d69acd736c5f]

                /// [_4d0ee15d_2612_402d_b95a_351d66897792]
                TEST_CASE_TEMPLATE("should not change its value", real_p, _)
                {
                    real_p random = Random<real_p>();
                    const atomic_t<real_p> atom(random);
                    atom.Access();
                    CHECK(atom == random);
                }
                /// [_4d0ee15d_2612_402d_b95a_351d66897792]
            }

            TEST_SUITE("Assign()")
            {
                /// [_91339173_2c19_4c80_81c2_47a7d0056c79]
                TEST_CASE_TEMPLATE("should set its value to the passed value", real_p, _)
                {
                    real_p random_a = Random<real_p>();
                    real_p random_b = Random<real_p>();
                    atomic_t<real_p> atom(random_a);
                    atom.Assign(random_b);
                    CHECK(atom == random_b);
                }
                /// [_91339173_2c19_4c80_81c2_47a7d0056c79]

                /// [_cf6d21c8_fe17_4d24_a869_7c2d2f1c638e]
                TEST_CASE_TEMPLATE("should return the new value", real_p, _)
                {
                    real_p random_a = Random<real_p>();
                    real_p random_b = Random<real_p>();
                    atomic_t<real_p> atom(random_a);
                    CHECK(atom.Assign(random_b) == random_b);
                }
                /// [_cf6d21c8_fe17_4d24_a869_7c2d2f1c638e]

                /// [_71122f83_edff_4e2b_9b04_ef4e2cb70662]
                TEST_CASE_TEMPLATE("should work with types convertible to its value_t", real_p, _)
                {
                    real_p random_a = Random<real_p>();
                    word_t random_b = Random<word_t>();
                    atomic_t<real_p> atom(random_a);
                    atom.Assign(random_b);
                    CHECK(atom == static_cast<real_p>(random_b));
                }
                /// [_71122f83_edff_4e2b_9b04_ef4e2cb70662]
            }

            TEST_SUITE("Assign_Add()")
            {
                /// [_58095a65_e406_4f9b_b98a_3e3ab286594e]
                TEST_CASE_TEMPLATE("should set its value to value + passed value", real_p, _)
                {
                    real_p random_a = Random<real_p>();
                    real_p random_b = Random<real_p>();
                    atomic_t<real_p> atom(random_a);
                    atom.Assign_Add(random_b);
                    CHECK(atom == (random_a += random_b));
                }
                /// [_58095a65_e406_4f9b_b98a_3e3ab286594e]

                /// [_ce0eb5c3_7cdf_4ff4_ad98_ea61f1304510]
                TEST_CASE_TEMPLATE("should return the new value", real_p, _)
                {
                    real_p random_a = Random<real_p>();
                    real_p random_b = Random<real_p>();
                    atomic_t<real_p> atom(random_a);
                    CHECK(atom.Assign_Add(random_b) == real_p(random_a + random_b));
                }
                /// [_ce0eb5c3_7cdf_4ff4_ad98_ea61f1304510]

                /// [_e6ec20c3_b673_435b_87bd_35ca0599d8d3]
                TEST_CASE_TEMPLATE("should work with types convertible to its value_t", real_p, _)
                {
                    real_p random_a = Random<real_p>();
                    word_t random_b = Random<word_t>();
                    atomic_t<real_p> atom(random_a);
                    atom.Assign_Add(random_b);
                    CHECK(atom == (random_a += static_cast<real_p>(random_b)));
                }
                /// [_e6ec20c3_b673_435b_87bd_35ca0599d8d3]
            }

            TEST_SUITE("Assign_Subtract()")
            {
                /// [_05e1e55b_b233_457c_8ae6_41ba0dec76a9]
                TEST_CASE_TEMPLATE("should set its value to value - passed value", real_p, _)
                {
                    real_p random_a = Random<real_p>();
                    real_p random_b = Random<real_p>();
                    atomic_t<real_p> atom(random_a);
                    atom.Assign_Subtract(random_b);
                    CHECK(atom == (random_a -= random_b));
                }
                /// [_05e1e55b_b233_457c_8ae6_41ba0dec76a9]

                /// [_ae57b4c4_2b87_4a91_8f5c_63dde775cbec]
                TEST_CASE_TEMPLATE("should return the new value", real_p, _)
                {
                    real_p random_a = Random<real_p>();
                    real_p random_b = Random<real_p>();
                    atomic_t<real_p> atom(random_a);
                    CHECK(atom.Assign_Subtract(random_b) == real_p(random_a - random_b));
                }
                /// [_ae57b4c4_2b87_4a91_8f5c_63dde775cbec]

                /// [_3f9eb643_a685_4738_a90c_c0fa0c3c9bb4]
                TEST_CASE_TEMPLATE("should work with types convertible to its value_t", real_p, _)
                {
                    real_p random_a = Random<real_p>();
                    word_t random_b = Random<word_t>();
                    atomic_t<real_p> atom(random_a);
                    atom.Assign_Subtract(random_b);
                    CHECK(atom == (random_a -= static_cast<real_p>(random_b)));
                }
                /// [_3f9eb643_a685_4738_a90c_c0fa0c3c9bb4]
            }

            TEST_SUITE("Assign_Multiply()")
            {
                /// [_14c37838_f17b_4552_9944_8b07373150bb]
                TEST_CASE_TEMPLATE("should set its value to value * passed value", real_p, _)
                {
                    real_p random_a = Random<real_p>();
                    real_p random_b = Random<real_p>();
                    atomic_t<real_p> atom(random_a);
                    atom.Assign_Multiply(random_b);
                    CHECK(atom == (random_a *= random_b));
                }
                /// [_14c37838_f17b_4552_9944_8b07373150bb]

                /// [_7de9dd2f_3628_4f22_88e3_b9b31f167ead]
                TEST_CASE_TEMPLATE("should return the new value", real_p, _)
                {
                    real_p random_a = Random<real_p>();
                    real_p random_b = Random<real_p>();
                    atomic_t<real_p> atom(random_a);
                    CHECK(atom.Assign_Multiply(random_b) == real_p(random_a * random_b));
                }
                /// [_7de9dd2f_3628_4f22_88e3_b9b31f167ead]

                /// [_430149ff_9d6b_44ae_8240_19677f08a0ee]
                TEST_CASE_TEMPLATE("should work with types convertible to its value_t", real_p, _)
                {
                    real_p random_a = Random<real_p>();
                    word_t random_b = Random<word_t>();
                    atomic_t<real_p> atom(random_a);
                    atom.Assign_Multiply(random_b);
                    CHECK(atom == (random_a *= static_cast<real_p>(random_b)));
                }
                /// [_430149ff_9d6b_44ae_8240_19677f08a0ee]
            }

            TEST_SUITE("Assign_Divide()")
            {
                /// [_7a64bd27_579a_4ce6_9878_2f924f4d6066]
                TEST_CASE_TEMPLATE("should set its value to value / passed value", real_p, _)
                {
                    real_p random_a = Random<real_p>();
                    real_p random_b;
                    do {
                        random_b = Random<real_p>();
                    } while (random_b == 0.0);
                    atomic_t<real_p> atom(random_a);
                    atom.Assign_Divide(random_b);
                    CHECK(atom == (random_a /= random_b));
                }
                /// [_7a64bd27_579a_4ce6_9878_2f924f4d6066]

                /// [_2213006f_a4bb_404c_867b_47ab4950a07e]
                TEST_CASE_TEMPLATE("should return the new value", real_p, _)
                {
                    real_p random_a = Random<real_p>();
                    real_p random_b;
                    do {
                        random_b = Random<real_p>();
                    } while (random_b == 0.0);
                    atomic_t<real_p> atom(random_a);
                    CHECK(atom.Assign_Divide(random_b) == real_p(random_a / random_b));
                }
                /// [_2213006f_a4bb_404c_867b_47ab4950a07e]

                /// [_c6fc7749_f5c7_4191_a4c8_35000b9572cf]
                TEST_CASE_TEMPLATE("should work with types convertible to its value_t", real_p, _)
                {
                    real_p random_a = Random<real_p>();
                    word_t random_b;
                    do {
                        random_b = Random<word_t>();
                    } while (random_b == 0);
                    atomic_t<real_p> atom(random_a);
                    atom.Assign_Divide(random_b);
                    CHECK(atom == (random_a /= static_cast<real_p>(random_b)));
                }
                /// [_c6fc7749_f5c7_4191_a4c8_35000b9572cf]
            }

            TEST_SUITE("Exchange()")
            {
                /// [_c5484de3_220e_4cf8_83ef_f6aa71ab7966]
                TEST_CASE_TEMPLATE("should set its value to the passed value", real_p, _)
                {
                    real_p random_a = Random<real_p>();
                    real_p random_b = Random<real_p>();
                    atomic_t<real_p> atom(random_a);
                    atom.Exchange(random_b);
                    CHECK(atom == random_b);
                }
                /// [_c5484de3_220e_4cf8_83ef_f6aa71ab7966]

                /// [_1f7ee854_568e_4397_9ce0_1efc7997d398]
                TEST_CASE_TEMPLATE("should return its old value", real_p, _)
                {
                    real_p random_a = Random<real_p>();
                    real_p random_b = Random<real_p>();
                    atomic_t<real_p> atom(random_a);
                    CHECK(atom.Exchange(random_b) == random_a);
                }
                /// [_1f7ee854_568e_4397_9ce0_1efc7997d398]

                /// [_8742d47f_afc9_405b_bfae_8b48c126013f]
                TEST_CASE_TEMPLATE("should work with types convertible to its value_t", real_p, _)
                {
                    real_p random_a = Random<real_p>();
                    word_t random_b = Random<word_t>();
                    atomic_t<real_p> atom(random_a);
                    atom.Exchange(random_b);
                    CHECK(atom == static_cast<real_p>(random_b));
                }
                /// [_8742d47f_afc9_405b_bfae_8b48c126013f]
            }

            TEST_SUITE("Exchange_Add()")
            {
                /// [_0f39542d_efb8_4826_92b5_9ee8b4760adc]
                TEST_CASE_TEMPLATE("should set its value to value + passed value", real_p, _)
                {
                    real_p random_a = Random<real_p>();
                    real_p random_b = Random<real_p>();
                    atomic_t<real_p> atom(random_a);
                    atom.Exchange_Add(random_b);
                    CHECK(atom == (random_a += random_b));
                }
                /// [_0f39542d_efb8_4826_92b5_9ee8b4760adc]

                /// [_ad4af424_9bef_4d09_b79c_f4c50e335596]
                TEST_CASE_TEMPLATE("should return its old value", real_p, _)
                {
                    real_p random_a = Random<real_p>();
                    real_p random_b = Random<real_p>();
                    atomic_t<real_p> atom(random_a);
                    CHECK(atom.Exchange_Add(random_b) == random_a);
                }
                /// [_ad4af424_9bef_4d09_b79c_f4c50e335596]

                /// [_2dc17ea4_bace_4a53_afd9_b57f98dd5ef1]
                TEST_CASE_TEMPLATE("should work with types convertible to its value_t", real_p, _)
                {
                    real_p random_a = Random<real_p>();
                    word_t random_b = Random<word_t>();
                    atomic_t<real_p> atom(random_a);
                    atom.Exchange_Add(random_b);
                    CHECK(atom == (random_a += static_cast<real_p>(random_b)));
                }
                /// [_2dc17ea4_bace_4a53_afd9_b57f98dd5ef1]
            }

            TEST_SUITE("Exchange_Subtract()")
            {
                /// [_5ae99b87_cf4c_4138_a417_072cd82a0852]
                TEST_CASE_TEMPLATE("should set its value to value - passed value", real_p, _)
                {
                    real_p random_a = Random<real_p>();
                    real_p random_b = Random<real_p>();
                    atomic_t<real_p> atom(random_a);
                    atom.Exchange_Subtract(random_b);
                    CHECK(atom == (random_a -= random_b));
                }
                /// [_5ae99b87_cf4c_4138_a417_072cd82a0852]

                /// [_a26780e5_ccc7_4f2e_9ae7_49744a446e2b]
                TEST_CASE_TEMPLATE("should return its old value", real_p, _)
                {
                    real_p random_a = Random<real_p>();
                    real_p random_b = Random<real_p>();
                    atomic_t<real_p> atom(random_a);
                    CHECK(atom.Exchange_Subtract(random_b) == random_a);
                }
                /// [_a26780e5_ccc7_4f2e_9ae7_49744a446e2b]

                /// [_e5654cec_247b_4d30_a7eb_a27f57ca8494]
                TEST_CASE_TEMPLATE("should work with types convertible to its value_t", real_p, _)
                {
                    real_p random_a = Random<real_p>();
                    word_t random_b = Random<word_t>();
                    atomic_t<real_p> atom(random_a);
                    atom.Exchange_Subtract(random_b);
                    CHECK(atom == (random_a -= static_cast<real_p>(random_b)));
                }
                /// [_e5654cec_247b_4d30_a7eb_a27f57ca8494]
            }

            TEST_SUITE("Exchange_Multiply()")
            {
                /// [_7e049a15_3ffb_4acf_8e73_48db74cb9ff4]
                TEST_CASE_TEMPLATE("should set its value to value * passed value", real_p, _)
                {
                    real_p random_a = Random<real_p>();
                    real_p random_b = Random<real_p>();
                    atomic_t<real_p> atom(random_a);
                    atom.Exchange_Multiply(random_b);
                    CHECK(atom == (random_a *= random_b));
                }
                /// [_7e049a15_3ffb_4acf_8e73_48db74cb9ff4]

                /// [_9ea5604a_734e_480f_b9b1_efbcfb248800]
                TEST_CASE_TEMPLATE("should return its old value", real_p, _)
                {
                    real_p random_a = Random<real_p>();
                    real_p random_b = Random<real_p>();
                    atomic_t<real_p> atom(random_a);
                    CHECK(atom.Exchange_Multiply(random_b) == random_a);
                }
                /// [_9ea5604a_734e_480f_b9b1_efbcfb248800]

                /// [_85360ec2_1d49_496f_ac96_e4ce711953aa]
                TEST_CASE_TEMPLATE("should work with types convertible to its value_t", real_p, _)
                {
                    real_p random_a = Random<real_p>();
                    word_t random_b = Random<word_t>();
                    atomic_t<real_p> atom(random_a);
                    atom.Exchange_Multiply(random_b);
                    CHECK(atom == (random_a *= static_cast<real_p>(random_b)));
                }
                /// [_85360ec2_1d49_496f_ac96_e4ce711953aa]
            }

            TEST_SUITE("Exchange_Divide()")
            {
                /// [_687caad0_6e65_43da_9aab_31e03808bc83]
                TEST_CASE_TEMPLATE("should set its value to value / passed value", real_p, _)
                {
                    real_p random_a = Random<real_p>();
                    real_p random_b;
                    do {
                        random_b = Random<real_p>();
                    } while (random_b == 0.0);
                    atomic_t<real_p> atom(random_a);
                    atom.Exchange_Divide(random_b);
                    CHECK(atom == (random_a /= random_b));
                }
                /// [_687caad0_6e65_43da_9aab_31e03808bc83]

                /// [_2bc2cee2_c542_4852_804d_2c6cdd6ec3bb]
                TEST_CASE_TEMPLATE("should return its old value", real_p, _)
                {
                    real_p random_a = Random<real_p>();
                    real_p random_b;
                    do {
                        random_b = Random<real_p>();
                    } while (random_b == 0.0);
                    atomic_t<real_p> atom(random_a);
                    CHECK(atom.Exchange_Divide(random_b) == random_a);
                }
                /// [_2bc2cee2_c542_4852_804d_2c6cdd6ec3bb]

                /// [_6425f216_5887_4aa8_96f3_84d306491c7f]
                TEST_CASE_TEMPLATE("should work with types convertible to its value_t", real_p, _)
                {
                    real_p random_a = Random<real_p>();
                    word_t random_b;
                    do {
                        random_b = Random<word_t>();
                    } while (random_b == 0);
                    atomic_t<real_p> atom(random_a);
                    atom.Exchange_Divide(random_b);
                    CHECK(atom == (random_a /= static_cast<real_p>(random_b)));
                }
                /// [_6425f216_5887_4aa8_96f3_84d306491c7f]
            }

            TEST_SUITE("Exchange_If_Equals()")
            {
                /// [_870b7a10_e39f_413e_bc41_5696764fbff3]
                TEST_CASE_TEMPLATE("should set its value to the passed value if its value equals the snapshot", real_p, _)
                {
                    real_p random_a = Random<real_p>();
                    real_p random_b = Random<real_p>();
                    atomic_t<real_p> atom(random_a);
                    real_p snapshot = atom;
                    atom.Exchange_If_Equals(snapshot, snapshot + random_b);
                    CHECK(atom == static_cast<real_p>(random_a + random_b));
                }
                /// [_870b7a10_e39f_413e_bc41_5696764fbff3]

                /// [_36a4ffa4_a0bc_430e_b241_514fbdaf36d1]
                TEST_CASE_TEMPLATE("should return true if it set the new value", real_p, _)
                {
                    real_p random_a = Random<real_p>();
                    real_p random_b = Random<real_p>();
                    atomic_t<real_p> atom(random_a);
                    real_p snapshot = atom;
                    CHECK(atom.Exchange_If_Equals(snapshot, snapshot + random_b) == true);
                }
                /// [_36a4ffa4_a0bc_430e_b241_514fbdaf36d1]

                /// [_afb7c2ad_ecf4_4bd4_9378_eec404ba647f]
                TEST_CASE_TEMPLATE("should return false if it did not set the new value", real_p, _)
                {
                    real_p random_a = Random<real_p>();
                    real_p random_b;
                    do {
                        random_b = Random<real_p>();
                    } while (random_b == random_a);
                    atomic_t<real_p> atom(random_a);
                    real_p snapshot = atom;
                    atom = random_b;
                    CHECK(atom.Exchange_If_Equals(snapshot, 0.0) == false);
                }
                /// [_afb7c2ad_ecf4_4bd4_9378_eec404ba647f]

                /// [_67ecc477_461b_4a9b_94a6_17d44163e2d8]
                TEST_CASE_TEMPLATE("should leave snapshot with its old value if it succeeded", real_p, _)
                {
                    real_p random_a = Random<real_p>();
                    real_p random_b = Random<real_p>();
                    atomic_t<real_p> atom(random_a);
                    real_p snapshot = atom;
                    atom.Exchange_If_Equals(snapshot, snapshot + random_b);
                    CHECK(snapshot == random_a);
                }
                /// [_67ecc477_461b_4a9b_94a6_17d44163e2d8]

                /// [_c55b85bd_af65_4c70_a5b3_e3f12b4f8203]
                TEST_CASE_TEMPLATE("should update snapshot to its current value if it failed", real_p, _)
                {
                    real_p random_a = Random<real_p>();
                    real_p random_b;
                    do {
                        random_b = Random<real_p>();
                    } while (random_b == random_a);
                    atomic_t<real_p> atom(random_a);
                    real_p snapshot = atom;
                    atom = random_b;
                    atom.Exchange_If_Equals(snapshot, 0.0);
                    CHECK(snapshot == static_cast<real_p>(random_b));
                }
                /// [_c55b85bd_af65_4c70_a5b3_e3f12b4f8203]

                /// [_945d71a2_0ec8_4073_9636_e88e0cc4d477]
                TEST_CASE_TEMPLATE("should work with types convertible to its value_t", real_p, _)
                {
                    real_p random_a = Random<real_p>();
                    word_t random_b = Random<word_t>();
                    atomic_t<real_p> atom(random_a);
                    real_p snapshot = atom;
                    atom.Exchange_If_Equals(snapshot, random_b);
                    CHECK(atom == static_cast<real_p>(random_b));
                }
                /// [_945d71a2_0ec8_4073_9636_e88e0cc4d477]

                /// [_0d98e9bb_0fae_442e_a5f5_deb14dc5ce0d]
                TEST_CASE_TEMPLATE("should allow you to atomically change its value safely with a custom algorithm", real_p, _)
                {
                    atomic_t<real_p> atom;
                    std::vector<std::thread> incrementors;
                    std::vector<std::thread> decrementors;
                    const count_t delta = Random<count_t>(1, 16);
                    const count_t threads_per = Random<count_t>(16, 64);
                    incrementors.reserve(threads_per);
                    decrementors.reserve(threads_per);

                    for (index_t idx = 0, end = threads_per; idx < end; idx += 1) {
                        incrementors.push_back(std::thread(
                            [&]() -> void_t
                            {
                                std::this_thread::sleep_for(
                                    std::chrono::microseconds(Random<count_t>(1, 5))
                                );
                                real_p snapshot = atom;
                                while (!atom.Exchange_If_Equals(snapshot, snapshot + delta));
                            }
                        ));
                        decrementors.push_back(std::thread(
                            [&]() -> void_t
                            {
                                std::this_thread::sleep_for(
                                    std::chrono::microseconds(Random<count_t>(1, 5))
                                );
                                real_p snapshot = atom;
                                while (!atom.Exchange_If_Equals(snapshot, snapshot - delta));
                            }
                        ));
                    }
                    for (index_t idx = 0, end = threads_per; idx < end; idx += 1) {
                        incrementors[idx].join();
                        decrementors[idx].join();
                    }

                    CHECK(atom == 0.0);
                }
                /// [_0d98e9bb_0fae_442e_a5f5_deb14dc5ce0d]
            }
        }

        TEST_SUITE("casts")
        {
            TEST_SUITE("value_t()")
            {
                /// [_b4dfe423_ace5_4b2b_92fd_fe47b8708ef0]
                TEST_CASE_TEMPLATE("should explicitly return a copy of its value", real_p, _)
                {
                    real_p random = Random<real_p>();
                    const atomic_t<real_p> atom(random);
                    CHECK(static_cast<real_p>(atom) == random);
                }
                /// [_b4dfe423_ace5_4b2b_92fd_fe47b8708ef0]

                /// [_5589ab94_7740_4958_8eae_40ca0e3b10de]
                TEST_CASE_TEMPLATE("should implicitly return a copy of its value", real_p, _)
                {
                    real_p random = Random<real_p>();
                    const atomic_t<real_p> atom(random);
                    real_p value = atom;
                    CHECK(value == random);
                }
                /// [_5589ab94_7740_4958_8eae_40ca0e3b10de]

                /// [_9026ed05_fe2f_41ef_99d4_c27cba3ba649]
                TEST_CASE_TEMPLATE("should not change its value", real_p, _)
                {
                    real_p random = Random<real_p>();
                    const atomic_t<real_p> atom(random);
                    real_p value = atom;
                    CHECK(atom == random);
                }
                /// [_9026ed05_fe2f_41ef_99d4_c27cba3ba649]

                /// [_85183e6a_3837_4d8b_bb24_d1def57b6471]
                TEST_CASE_TEMPLATE("should implicitly allow for arithmetic operators", real_p, _)
                {
                    real_p random_a = Random<real_p>();
                    real_p random_b;
                    do {
                        random_b = Random<real_p>();
                    } while (random_b == 0.0);
                    const atomic_t<real_p> atom(random_a);
                    CHECK(+atom == +random_a);
                    CHECK(-atom == -random_a);
                    CHECK((atom + random_b) == (random_a + random_b));
                    CHECK((atom - random_b) == (random_a - random_b));
                    CHECK((atom * random_b) == (random_a * random_b));
                    CHECK((atom / random_b) == (random_a / random_b));
                }
                /// [_85183e6a_3837_4d8b_bb24_d1def57b6471]

                /// [_23e193eb_97a6_4126_b4a0_9986b5528d13]
                TEST_CASE_TEMPLATE("should implicitly allow for logical operators", real_p, _)
                {
                    real_p random;
                    do {
                        random = Random<real_p>();
                    } while (random == 0.0);
                    const atomic_t<real_p> atom(random);
                    CHECK(atom);
                    CHECK(!!atom);
                    CHECK(atom || false);
                    CHECK(atom && true);
                    CHECK(atom ? true : false);
                }
                /// [_23e193eb_97a6_4126_b4a0_9986b5528d13]

                /// [_f0057019_a03e_4dc4_9571_008553300c9e]
                TEST_CASE_TEMPLATE("should implicitly allow for comparison operators", real_p, _)
                {
                    real_p random = Random<real_p>();
                    const atomic_t<real_p> atom(random);
                    CHECK(atom == random);
                    CHECK_FALSE(atom != random);
                    CHECK_FALSE(atom < random);
                    CHECK_FALSE(atom > random);
                    CHECK(atom <= random);
                    CHECK(atom >= random);
                    CHECK((atom <=> random == 0));
                }
                /// [_f0057019_a03e_4dc4_9571_008553300c9e]
            }
        }

        TEST_SUITE("operators")
        {
            TEST_SUITE("()()")
            {
                /// [_bc8e1d86_1d23_4a2a_a5a9_d067edad0af1]
                TEST_CASE_TEMPLATE("should return a copy of its value", real_p, _)
                {
                    real_p random = Random<real_p>();
                    const atomic_t<real_p> atom(random);
                    CHECK(atom() == random);
                }
                /// [_bc8e1d86_1d23_4a2a_a5a9_d067edad0af1]

                /// [_01b5778a_fc5c_4b21_b46f_50b4d68f1598]
                TEST_CASE_TEMPLATE("should not change its value", real_p, _)
                {
                    real_p random = Random<real_p>();
                    const atomic_t<real_p> atom(random);
                    real_p value = atom();
                    CHECK(atom == random);
                }
                /// [_01b5778a_fc5c_4b21_b46f_50b4d68f1598]
            }

            TEST_SUITE("+=()")
            {
                /// [_36fcf8e0_6485_47cb_9bc3_d1b6fdf4f1e0]
                TEST_CASE_TEMPLATE("should set its value to value + passed value", real_p, _)
                {
                    real_p random_a = Random<real_p>();
                    real_p random_b = Random<real_p>();
                    atomic_t<real_p> atom(random_a);
                    atom += random_b;
                    CHECK(atom == (random_a += random_b));
                }
                /// [_36fcf8e0_6485_47cb_9bc3_d1b6fdf4f1e0]

                /// [_3f1df3a2_1a0f_4d40_a6ec_f1e789df66d2]
                TEST_CASE_TEMPLATE("should return the new value", real_p, _)
                {
                    real_p random_a = Random<real_p>();
                    real_p random_b = Random<real_p>();
                    atomic_t<real_p> atom(random_a);
                    CHECK((atom += random_b) == real_p(random_a += random_b));
                }
                /// [_3f1df3a2_1a0f_4d40_a6ec_f1e789df66d2]

                /// [_033e8b36_38cf_43b8_9f3b_11317636ea2b]
                TEST_CASE_TEMPLATE("should work with types convertible to its value_t", real_p, _)
                {
                    real_p random_a = Random<real_p>();
                    word_t random_b = Random<word_t>();
                    atomic_t<real_p> atom(random_a);
                    atom += random_b;
                    CHECK(atom == (random_a += static_cast<real_p>(random_b)));
                }
                /// [_033e8b36_38cf_43b8_9f3b_11317636ea2b]
            }

            TEST_SUITE("-=()")
            {
                /// [_bea2f1be_08d8_4cc8_b7c9_b8e428c48c93]
                TEST_CASE_TEMPLATE("should set its value to value - passed value", real_p, _)
                {
                    real_p random_a = Random<real_p>();
                    real_p random_b = Random<real_p>();
                    atomic_t<real_p> atom(random_a);
                    atom -= random_b;
                    CHECK(atom == (random_a -= random_b));
                }
                /// [_bea2f1be_08d8_4cc8_b7c9_b8e428c48c93]

                /// [_480031de_bc4f_4bb6_85ed_62024c4dd49d]
                TEST_CASE_TEMPLATE("should return the new value", real_p, _)
                {
                    real_p random_a = Random<real_p>();
                    real_p random_b = Random<real_p>();
                    atomic_t<real_p> atom(random_a);
                    CHECK((atom -= random_b) == real_p(random_a -= random_b));
                }
                /// [_480031de_bc4f_4bb6_85ed_62024c4dd49d]

                /// [_2d48712a_c6cd_44e9_a3e6_b0ff8d43da11]
                TEST_CASE_TEMPLATE("should work with types convertible to its value_t", real_p, _)
                {
                    real_p random_a = Random<real_p>();
                    word_t random_b = Random<word_t>();
                    atomic_t<real_p> atom(random_a);
                    atom -= random_b;
                    CHECK(atom == (random_a -= static_cast<real_p>(random_b)));
                }
                /// [_2d48712a_c6cd_44e9_a3e6_b0ff8d43da11]
            }

            TEST_SUITE("*=()")
            {
                /// [_719f3d8b_3516_49f0_8370_f21719e31fa7]
                TEST_CASE_TEMPLATE("should set its value to value * passed value", real_p, _)
                {
                    real_p random_a = Random<real_p>();
                    real_p random_b = Random<real_p>();
                    atomic_t<real_p> atom(random_a);
                    atom *= random_b;
                    CHECK(atom == (random_a *= random_b));
                }
                /// [_719f3d8b_3516_49f0_8370_f21719e31fa7]

                /// [_37627525_bc0f_44ef_9a71_c6f4cf74cd99]
                TEST_CASE_TEMPLATE("should return the new value", real_p, _)
                {
                    real_p random_a = Random<real_p>();
                    real_p random_b = Random<real_p>();
                    atomic_t<real_p> atom(random_a);
                    CHECK((atom *= random_b) == real_p(random_a *= random_b));
                }
                /// [_37627525_bc0f_44ef_9a71_c6f4cf74cd99]

                /// [_0abf5cf0_6bd6_47eb_911e_f3220a7d376a]
                TEST_CASE_TEMPLATE("should work with types convertible to its value_t", real_p, _)
                {
                    real_p random_a = Random<real_p>();
                    word_t random_b = Random<word_t>();
                    atomic_t<real_p> atom(random_a);
                    atom *= random_b;
                    CHECK(atom == (random_a *= static_cast<real_p>(random_b)));
                }
                /// [_0abf5cf0_6bd6_47eb_911e_f3220a7d376a]
            }

            TEST_SUITE("/=()")
            {
                /// [_a99638da_9117_430f_8144_0bb272a66b90]
                TEST_CASE_TEMPLATE("should set its value to value / passed value", real_p, _)
                {
                    real_p random_a = Random<real_p>();
                    real_p random_b;
                    do {
                        random_b = Random<real_p>();
                    } while (random_b == 0.0);
                    atomic_t<real_p> atom(random_a);
                    atom /= random_b;
                    CHECK(atom == (random_a /= random_b));
                }
                /// [_a99638da_9117_430f_8144_0bb272a66b90]

                /// [_c60617e0_f780_400d_9e52_d7748bcd2ad1]
                TEST_CASE_TEMPLATE("should return the new value", real_p, _)
                {
                    real_p random_a = Random<real_p>();
                    real_p random_b;
                    do {
                        random_b = Random<real_p>();
                    } while (random_b == 0.0);
                    atomic_t<real_p> atom(random_a);
                    CHECK((atom /= random_b) == real_p(random_a /= random_b));
                }
                /// [_c60617e0_f780_400d_9e52_d7748bcd2ad1]

                /// [_14984ffe_35dc_49c2_8e44_ea56be79f86a]
                TEST_CASE_TEMPLATE("should work with types convertible to its value_t", real_p, _)
                {
                    real_p random_a = Random<real_p>();
                    word_t random_b;
                    do {
                        random_b = Random<word_t>();
                    } while (random_b == 0);
                    atomic_t<real_p> atom(random_a);
                    atom /= random_b;
                    CHECK(atom == (random_a /= static_cast<real_p>(random_b)));
                }
                /// [_14984ffe_35dc_49c2_8e44_ea56be79f86a]
            }

            TEST_SUITE("++()")
            {
                /// [_fba6bafe_2370_452f_831b_8d373e47eb86]
                TEST_CASE_TEMPLATE("should set its value to value + 1", real_p, _)
                {
                    real_p random = Random<real_p>();
                    atomic_t<real_p> atom(random);
                    ++atom;
                    CHECK(atom == (random += 1.0));
                }
                /// [_fba6bafe_2370_452f_831b_8d373e47eb86]

                /// [_3e4434f6_a682_4cb2_a893_adb013675a33]
                TEST_CASE_TEMPLATE("should return the new value", real_p, _)
                {
                    real_p random = Random<real_p>();
                    atomic_t<real_p> atom(random);
                    CHECK((++atom) == real_p(++random));
                }
                /// [_3e4434f6_a682_4cb2_a893_adb013675a33]
            }

            TEST_SUITE("++(int)")
            {
                /// [_f727b235_dd16_453f_a2fd_4c21a5b1b8ca]
                TEST_CASE_TEMPLATE("should set its value to value + 1", real_p, _)
                {
                    real_p random = Random<real_p>();
                    atomic_t<real_p> atom(random);
                    atom++;
                    CHECK(atom == (random += 1.0));
                }
                /// [_f727b235_dd16_453f_a2fd_4c21a5b1b8ca]

                /// [_fbfb8066_4122_419c_91ae_517fab12ec9f]
                TEST_CASE_TEMPLATE("should return its old value", real_p, _)
                {
                    real_p random = Random<real_p>();
                    atomic_t<real_p> atom(random);
                    CHECK(atom++ == random);
                }
                /// [_fbfb8066_4122_419c_91ae_517fab12ec9f]
            }

            TEST_SUITE("--()")
            {
                /// [_fd3b6e86_caef_4e02_8fe1_86506bf36b74]
                TEST_CASE_TEMPLATE("should set its value to value - 1", real_p, _)
                {
                    real_p random = Random<real_p>();
                    atomic_t<real_p> atom(random);
                    --atom;
                    CHECK(atom == (random -= 1.0));
                }
                /// [_fd3b6e86_caef_4e02_8fe1_86506bf36b74]

                /// [_ea214d48_d7ee_49c5_b831_5fd951e97052]
                TEST_CASE_TEMPLATE("should return the new value", real_p, _)
                {
                    real_p random = Random<real_p>();
                    atomic_t<real_p> atom(random);
                    CHECK((--atom) == real_p(--random));
                }
                /// [_ea214d48_d7ee_49c5_b831_5fd951e97052]
            }

            TEST_SUITE("--(int)")
            {
                /// [_d9ecdd36_d9d2_4e22_aa91_f0b0e88a83f3]
                TEST_CASE_TEMPLATE("should set its value to value - 1", real_p, _)
                {
                    real_p random = Random<real_p>();
                    atomic_t<real_p> atom(random);
                    atom--;
                    CHECK(atom == (random -= 1.0));
                }
                /// [_d9ecdd36_d9d2_4e22_aa91_f0b0e88a83f3]

                /// [_708c82fa_9602_4c7d_84e2_db57ada3144d]
                TEST_CASE_TEMPLATE("should return its old value", real_p, _)
                {
                    real_p random = Random<real_p>();
                    atomic_t<real_p> atom(random);
                    CHECK(atom-- == random);
                }
                /// [_708c82fa_9602_4c7d_84e2_db57ada3144d]
            }
        }

        TEST_SUITE("none_t interface")
        {
            TEST_SUITE("none_ctor()")
            {
                /// [_5096780d_a27a_4d1d_86bb_49ffaf63e81a]
                TEST_CASE_TEMPLATE("should explicitly set its value to the default value", real_p, _)
                {
                    atomic_t<real_p> atom((none_t()));
                    CHECK(atom == atomic_t<real_p>::DEFAULT_VALUE);
                }
                /// [_5096780d_a27a_4d1d_86bb_49ffaf63e81a]

                /// [_d0625a9a_49b4_4b1e_af82_4335ef71cc0d]
                TEST_CASE_TEMPLATE("should implicitly set its value to the default value", real_p, _)
                {
                    atomic_t<real_p> atom = none_t();
                    CHECK(atom == atomic_t<real_p>::DEFAULT_VALUE);
                }
                /// [_d0625a9a_49b4_4b1e_af82_4335ef71cc0d]
            }

            TEST_SUITE("=(none_t)")
            {
                /// [_3b681d95_22c6_4bbf_ab2e_edec47011d4a]
                TEST_CASE_TEMPLATE("should set its value to the default value", real_p, _)
                {
                    real_p random = Random<real_p>();
                    atomic_t<real_p> atom(random);
                    atom = none_t();
                    CHECK(atom == atomic_t<real_p>::DEFAULT_VALUE);
                }
                /// [_3b681d95_22c6_4bbf_ab2e_edec47011d4a]

                /// [_2c9d76ce_d1a7_4eb7_87c8_75662ad513fa]
                TEST_CASE_TEMPLATE("should evaluate as false after being set to none", real_p, _)
                {
                    real_p random = Random<real_p>();
                    atomic_t<real_p> atom(random);
                    atom = none_t();
                    CHECK(static_cast<bool_t>(atom) == false);
                }
                /// [_2c9d76ce_d1a7_4eb7_87c8_75662ad513fa]

                /// [_656651f9_f4dd_4d8e_8e22_d46a834c7fb0]
                TEST_CASE_TEMPLATE("should return itself", real_p, _)
                {
                    real_p random = Random<real_p>();
                    atomic_t<real_p> atom(random);
                    CHECK(&(atom = none_t()) == &atom);
                }
                /// [_656651f9_f4dd_4d8e_8e22_d46a834c7fb0]
            }

            TEST_SUITE("==(none_t)")
            {
                /// [_a7f5b5f6_3a48_47fe_b6e3_14eec6f383c4]
                TEST_CASE_TEMPLATE("should return true when default constructed", real_p, _)
                {
                    const atomic_t<real_p> atom;
                    CHECK(atom == none_t());
                }
                /// [_a7f5b5f6_3a48_47fe_b6e3_14eec6f383c4]

                /// [_21a37122_b65b_4ed5_a1d0_3252222d1d97]
                TEST_CASE_TEMPLATE("should return true if its value is 0.0", real_p, _)
                {
                    const atomic_t<real_p> atom(0.0);
                    CHECK(atom == none_t());
                }
                /// [_21a37122_b65b_4ed5_a1d0_3252222d1d97]

                /// [_88f44f84_d138_444f_86da_95f3d34b3d0e]
                TEST_CASE_TEMPLATE("should return false if its value is above 0.0", real_p, _)
                {
                    real_p random = Random<real_p>(std::numeric_limits<real_p>::min(),
                                                   std::numeric_limits<real_p>::max());
                    const atomic_t<real_p> atom(random);
                    CHECK_FALSE(atom == none_t());
                }
                /// [_88f44f84_d138_444f_86da_95f3d34b3d0e]

                /// [_fb90f59f_18e9_4486_934f_d9804a28a5b4]
                TEST_CASE_TEMPLATE("should return false if its value is below 0.0", real_p, _)
                {
                    real_p random = Random<real_p>(-std::numeric_limits<real_p>::max(),
                                                   -std::numeric_limits<real_p>::min());
                    const atomic_t<real_p> atom(random);
                    CHECK_FALSE(atom == none_t());
                }
                /// [_fb90f59f_18e9_4486_934f_d9804a28a5b4]

                /// [_e3936d47_de8c_48ff_979c_dd104837e2b6]
                TEST_CASE_TEMPLATE("should not change its value", real_p, _)
                {
                    real_p random = Random<real_p>();
                    const atomic_t<real_p> atom(random);
                    atom == none_t();
                    CHECK(atom == random);
                }
                /// [_e3936d47_de8c_48ff_979c_dd104837e2b6]
            }

            TEST_SUITE("!=(none_t)")
            {
                /// [_94d14476_999f_451c_94a0_ac2df55f5038]
                TEST_CASE_TEMPLATE("should return false when default constructed", real_p, _)
                {
                    const atomic_t<real_p> atom;
                    CHECK_FALSE(atom != none_t());
                }
                /// [_94d14476_999f_451c_94a0_ac2df55f5038]

                /// [_e867e438_8518_497a_b61a_b642b661c12a]
                TEST_CASE_TEMPLATE("should return false if its value is 0.0", real_p, _)
                {
                    const atomic_t<real_p> atom(0.0);
                    CHECK_FALSE(atom != none_t());
                }
                /// [_e867e438_8518_497a_b61a_b642b661c12a]

                /// [_5a4f170a_7266_4e56_8323_69d2e0dd2fa3]
                TEST_CASE_TEMPLATE("should return true if its value is above 0.0", real_p, _)
                {
                    real_p random = Random<real_p>(std::numeric_limits<real_p>::min(),
                                                   std::numeric_limits<real_p>::max());
                    const atomic_t<real_p> atom(random);
                    CHECK(atom != none_t());
                }
                /// [_5a4f170a_7266_4e56_8323_69d2e0dd2fa3]

                /// [_0225938f_b038_40cd_a659_7fbe416f8006]
                TEST_CASE_TEMPLATE("should return true if its value is below 0.0", real_p, _)
                {
                    real_p random = Random<real_p>(-std::numeric_limits<real_p>::max(),
                                                   -std::numeric_limits<real_p>::min());
                    const atomic_t<real_p> atom(random);
                    CHECK(atom != none_t());
                }
                /// [_0225938f_b038_40cd_a659_7fbe416f8006]

                /// [_bf986b93_2c19_47cb_b49b_1bc1152d2074]
                TEST_CASE_TEMPLATE("should not change its value", real_p, _)
                {
                    real_p random = Random<real_p>();
                    const atomic_t<real_p> atom(random);
                    atom != none_t();
                    CHECK(atom == random);
                }
                /// [_bf986b93_2c19_47cb_b49b_1bc1152d2074]
            }
        }

    #undef _
    }

}
