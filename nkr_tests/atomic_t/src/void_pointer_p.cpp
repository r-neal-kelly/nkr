/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/atomic_t.h"
#include "nkr/intrinsics.h"
#include "nkr/random.h"

#include "doctest.h"

namespace nkr {

    TEST_SUITE("atomic_t<void_t*>")
    {
        TEST_SUITE("aliases")
        {
            TEST_SUITE("value_t")
            {
                /// [_29ece5d9_f58b_4dcc_8d1b_0b58447ad4b8]
                TEST_CASE("should equal the passed in type")
                {
                    static_assert(is_tr<atomic_t<void_t*>::value_t, void_t*>);
                }
                /// [_29ece5d9_f58b_4dcc_8d1b_0b58447ad4b8]
            }

            TEST_SUITE("units_t")
            {
                /// [_575ddcbe_77bb_4096_9044_b9cbdc8b19ae]
                TEST_CASE("should equal the pointer type being represented")
                {
                    static_assert(is_tr<atomic_t<void_t*>::units_t, void_t*>);
                }
                /// [_575ddcbe_77bb_4096_9044_b9cbdc8b19ae]
            }

            TEST_SUITE("unit_t")
            {
                /// [_1156a952_7f99_4e80_a410_33eb95b807e9]
                TEST_CASE("should equal the type being pointed to")
                {
                    static_assert(is_tr<atomic_t<void_t*>::unit_t, std::remove_pointer_t<void_t*>>);
                }
                /// [_1156a952_7f99_4e80_a410_33eb95b807e9]
            }
        }

        TEST_SUITE("static data")
        {
            TEST_SUITE("DEFAULT_VALUE")
            {
                /// [_0f79f049_7dcc_47fc_bfcb_9fc47ebf8ec6]
                TEST_CASE("should equal the default value of value_t")
                {
                    CHECK(atomic_t<void_t*>::DEFAULT_VALUE == atomic_t<void_t*>::value_t());
                }
                /// [_0f79f049_7dcc_47fc_bfcb_9fc47ebf8ec6]

                /// [_35441b57_93ae_4bd1_b173_dcf1fb479db2]
                TEST_CASE("should equal nullptr")
                {
                    CHECK(atomic_t<void_t*>::DEFAULT_VALUE == nullptr);
                }
                /// [_35441b57_93ae_4bd1_b173_dcf1fb479db2]
            }
        }

        TEST_SUITE("object data")
        {
            TEST_SUITE("value")
            {
                /// [_1a8ce10a_a464_42e8_a58f_cbe4030491ed]
                TEST_CASE("should be a volatile value_t")
                {
                    using value_t = atomic_t<void_t*>::value_t;

                    static_assert(std::is_same_v<decltype(atomic_t<void_t*>::value), volatile value_t>);
                }
                /// [_1a8ce10a_a464_42e8_a58f_cbe4030491ed]
            }
        }

        TEST_SUITE("objects")
        {
            TEST_SUITE("default_ctor()")
            {
                /// [_d07ba599_f6bc_4519_8667_89fb1db99ff2]
                TEST_CASE("should set value to the default")
                {
                    atomic_t<void_t*> atom;
                    CHECK(atom == atomic_t<void_t*>::DEFAULT_VALUE);
                }
                /// [_d07ba599_f6bc_4519_8667_89fb1db99ff2]
            }

            TEST_SUITE("value_ctor()")
            {
                /// [_eb062cfb_6cac_4f4c_8509_13f4b97c230f]
                TEST_CASE("should explicitly set passed value")
                {
                    void_t* random = Random<void_t*>();
                    atomic_t<void_t*> atom(random);
                    CHECK(atom == random);
                }
                /// [_eb062cfb_6cac_4f4c_8509_13f4b97c230f]

                /// [_0cac81bc_d48b_4863_8a08_6b23add3c2fb]
                TEST_CASE("should implicitly set passed value")
                {
                    void_t* random = Random<void_t*>();
                    atomic_t<void_t*> atom = random;
                    CHECK(atom == random);
                }
                /// [_0cac81bc_d48b_4863_8a08_6b23add3c2fb]

                /// [_bd2caa2c_467f_42bb_9034_b3843a14b290]
                TEST_CASE("should convert other types and set passed value")
                {
                    word_t* random = Random<word_t*>();
                    atomic_t<void_t*> atom(random);
                    CHECK(atom == static_cast<void_t*>(random));
                }
                /// [_bd2caa2c_467f_42bb_9034_b3843a14b290]
            }

            TEST_SUITE("copy_ctor()")
            {
                /// [_f91b4ffd_8ca4_4ab9_a4f1_cdb5c02ae8a4]
                TEST_CASE("should explicitly copy the value of other")
                {
                    void_t* random = Random<void_t*>();
                    const atomic_t<void_t*> other(random);
                    atomic_t<void_t*> atom(other);
                    CHECK(atom == random);
                }
                /// [_f91b4ffd_8ca4_4ab9_a4f1_cdb5c02ae8a4]

                /// [_38a2f0d1_7896_4af1_9575_994935aec780]
                TEST_CASE("should implicitly copy the value of other")
                {
                    void_t* random = Random<void_t*>();
                    const atomic_t<void_t*> other(random);
                    atomic_t<void_t*> atom = other;
                    CHECK(atom == random);
                }
                /// [_38a2f0d1_7896_4af1_9575_994935aec780]

                /// [_e7e204af_8dfc_4ae2_9070_128105bb1b12]
                TEST_CASE("should not alter the value of other")
                {
                    void_t* random = Random<void_t*>();
                    const atomic_t<void_t*> other(random);
                    atomic_t<void_t*> atom(other);
                    CHECK(other == random);
                }
                /// [_e7e204af_8dfc_4ae2_9070_128105bb1b12]
            }

            TEST_SUITE("move_ctor()")
            {
                /// [_f2733e43_459e_41ac_862c_bc9b0d947a31]
                TEST_CASE("should explicitly move the value of other")
                {
                    void_t* random = Random<void_t*>();
                    atomic_t<void_t*> other(random);
                    atomic_t<void_t*> atom(std::move(other));
                    CHECK(atom == random);
                }
                /// [_f2733e43_459e_41ac_862c_bc9b0d947a31]

                /// [_c2aed2f8_7838_424c_ba34_c500cee9488f]
                TEST_CASE("should implicitly move the value of other")
                {
                    void_t* random = Random<void_t*>();
                    atomic_t<void_t*> other(random);
                    atomic_t<void_t*> atom = std::move(other);
                    CHECK(atom == random);
                }
                /// [_c2aed2f8_7838_424c_ba34_c500cee9488f]

                /// [_e3a3417b_73d1_4479_b2e8_d3c1b832ecd3]
                TEST_CASE("should set the value of other to the default")
                {
                    void_t* random = Random<void_t*>();
                    atomic_t<void_t*> other(random);
                    atomic_t<void_t*> atom(std::move(other));
                    CHECK(other == atomic_t<void_t*>::DEFAULT_VALUE);
                }
                /// [_e3a3417b_73d1_4479_b2e8_d3c1b832ecd3]
            }

            TEST_SUITE("value_assignment_ctor()")
            {
                /// [_95bc585d_6a98_4fae_be57_b0a992d82b17]
                TEST_CASE("should set passed value")
                {
                    void_t* random = Random<void_t*>();
                    atomic_t<void_t*> atom;
                    atom = random;
                    CHECK(atom == random);
                }
                /// [_95bc585d_6a98_4fae_be57_b0a992d82b17]

                /// [_bdb9d07d_8edc_48a5_92a9_40da992b18b5]
                TEST_CASE("should return itself")
                {
                    void_t* random = Random<void_t*>();
                    atomic_t<void_t*> atom;
                    CHECK(&(atom = random) == &atom);
                }
                /// [_bdb9d07d_8edc_48a5_92a9_40da992b18b5]

                /// [_4a13bf27_0553_46a9_a260_ed4faed3f66c]
                TEST_CASE("should convert other types and set passed value")
                {
                    word_t* random = Random<word_t*>();
                    atomic_t<void_t*> atom;
                    atom = random;
                    CHECK(atom == static_cast<void_t*>(random));
                }
                /// [_4a13bf27_0553_46a9_a260_ed4faed3f66c]
            }

            TEST_SUITE("copy_assignment_ctor()")
            {
                /// [_afb4e117_8d7b_4f92_baf6_1f0e7e56234f]
                TEST_CASE("should copy the value of other")
                {
                    void_t* random = Random<void_t*>();
                    const atomic_t<void_t*> other(random);
                    atomic_t<void_t*> atom;
                    atom = other;
                    CHECK(atom == random);
                }
                /// [_afb4e117_8d7b_4f92_baf6_1f0e7e56234f]

                /// [_ed7c5f9c_0e31_4ff6_8845_a5826f0cf8af]
                TEST_CASE("should return itself")
                {
                    void_t* random = Random<void_t*>();
                    const atomic_t<void_t*> other(random);
                    atomic_t<void_t*> atom;
                    CHECK(&(atom = other) == &atom);
                }
                /// [_ed7c5f9c_0e31_4ff6_8845_a5826f0cf8af]

                /// [_6c68d832_cd7f_4b1d_87d2_2c54ed427659]
                TEST_CASE("should not alter the value of other")
                {
                    void_t* random = Random<void_t*>();
                    const atomic_t<void_t*> other(random);
                    atomic_t<void_t*> atom;
                    atom = other;
                    CHECK(other == random);
                }
                /// [_6c68d832_cd7f_4b1d_87d2_2c54ed427659]
            }

            TEST_SUITE("move_assignment_ctor()")
            {
                /// [_2f1f0715_ec21_4a00_8619_6308e8af10e7]
                TEST_CASE("should move the value of other")
                {
                    void_t* random = Random<void_t*>();
                    atomic_t<void_t*> other(random);
                    atomic_t<void_t*> atom;
                    atom = std::move(other);
                    CHECK(atom == random);
                }
                /// [_2f1f0715_ec21_4a00_8619_6308e8af10e7]

                /// [_71359e72_420d_4b0d_b96b_4cc06e3f6073]
                TEST_CASE("should return itself")
                {
                    void_t* random = Random<void_t*>();
                    atomic_t<void_t*> other(random);
                    atomic_t<void_t*> atom;
                    CHECK(&(atom = std::move(other)) == &atom);
                }
                /// [_71359e72_420d_4b0d_b96b_4cc06e3f6073]

                /// [_f7f03cad_0853_4929_92b2_df8b10577eb7]
                TEST_CASE("should set the value of other to the default")
                {
                    void_t* random = Random<void_t*>();
                    atomic_t<void_t*> other(random);
                    atomic_t<void_t*> atom;
                    atom = std::move(other);
                    CHECK(other == atomic_t<void_t*>::DEFAULT_VALUE);
                }
                /// [_f7f03cad_0853_4929_92b2_df8b10577eb7]
            }

            TEST_SUITE("dtor()")
            {
                /// [_e99e4d2f_1b11_4b07_8bc3_3d775b0b601d]
                TEST_CASE("should set its value to the default")
                {
                    void_t* random = Random<void_t*>();
                    atomic_t<void_t*> atom(random);
                    atom.~atomic_t();
                    CHECK(atom == atomic_t<void_t*>::DEFAULT_VALUE);
                }
                /// [_e99e4d2f_1b11_4b07_8bc3_3d775b0b601d]
            }
        }

        TEST_SUITE("methods")
        {
            TEST_SUITE("Access()")
            {
                /// [_0da174cf_d1c0_4f50_bd1d_5b14f13d54b2]
                TEST_CASE("should return its value")
                {
                    void_t* random = Random<void_t*>();
                    const atomic_t<void_t*> atom(random);
                    CHECK(atom.Access() == random);
                }
                /// [_0da174cf_d1c0_4f50_bd1d_5b14f13d54b2]

                /// [_1a8969aa_d41d_47af_9a07_7e74588b4617]
                TEST_CASE("should not change its value")
                {
                    void_t* random = Random<void_t*>();
                    const atomic_t<void_t*> atom(random);
                    atom.Access();
                    CHECK(atom == random);
                }
                /// [_1a8969aa_d41d_47af_9a07_7e74588b4617]
            }

            TEST_SUITE("Assign()")
            {
                /// [_ed925f01_ecd8_4569_9ec0_bb3eb87e4cee]
                TEST_CASE("should set its value to the passed value")
                {
                    void_t* random_a = Random<void_t*>();
                    void_t* random_b = Random<void_t*>();
                    atomic_t<void_t*> atom(random_a);
                    atom.Assign(random_b);
                    CHECK(atom == random_b);
                }
                /// [_ed925f01_ecd8_4569_9ec0_bb3eb87e4cee]

                /// [_24aa3917_1765_4bfb_8f8c_1eec15eb950c]
                TEST_CASE("should return itself")
                {
                    void_t* random_a = Random<void_t*>();
                    void_t* random_b = Random<void_t*>();
                    atomic_t<void_t*> atom(random_a);
                    CHECK(&atom.Assign(random_b) == &atom);
                }
                /// [_24aa3917_1765_4bfb_8f8c_1eec15eb950c]

                /// [_0cdcf966_7077_48a9_a2a5_1b77e4229b45]
                TEST_CASE("should work with types convertible to its value_t")
                {
                    void_t* random_a = Random<void_t*>();
                    word_t* random_b = Random<word_t*>();
                    atomic_t<void_t*> atom(random_a);
                    atom.Assign(random_b);
                    CHECK(atom == static_cast<void_t*>(random_b));
                }
                /// [_0cdcf966_7077_48a9_a2a5_1b77e4229b45]
            }

            TEST_SUITE("Exchange()")
            {
                /// [_b955d5d7_e7d0_465a_b59d_fdcee261a8dc]
                TEST_CASE("should set its value to the passed value")
                {
                    void_t* random_a = Random<void_t*>();
                    void_t* random_b = Random<void_t*>();
                    atomic_t<void_t*> atom(random_a);
                    atom.Exchange(random_b);
                    CHECK(atom == random_b);
                }
                /// [_b955d5d7_e7d0_465a_b59d_fdcee261a8dc]

                /// [_7bc01114_74a6_4a02_91d4_d995f82e19f0]
                TEST_CASE("should return its old value")
                {
                    void_t* random_a = Random<void_t*>();
                    void_t* random_b = Random<void_t*>();
                    atomic_t<void_t*> atom(random_a);
                    CHECK(atom.Exchange(random_b) == random_a);
                }
                /// [_7bc01114_74a6_4a02_91d4_d995f82e19f0]

                /// [_e2854392_9fb8_4411_a36f_74f769da1067]
                TEST_CASE("should work with types convertible to its value_t")
                {
                    void_t* random_a = Random<void_t*>();
                    word_t* random_b = Random<word_t*>();
                    atomic_t<void_t*> atom(random_a);
                    atom.Exchange(random_b);
                    CHECK(atom == static_cast<void_t*>(random_b));
                }
                /// [_e2854392_9fb8_4411_a36f_74f769da1067]
            }

            TEST_SUITE("Exchange_If_Equals()")
            {
                /// [_0fa0157d_f829_445a_bbde_f13d9dc40e0b]
                TEST_CASE("should set its value to the passed value if its value equals the snapshot")
                {
                    void_t* random_a = Random<void_t*>();
                    void_t* random_b = Random<void_t*>();
                    atomic_t<void_t*> atom(random_a);
                    void_t* snapshot = atom;
                    atom.Exchange_If_Equals(snapshot, random_b);
                    CHECK(atom == random_b);
                }
                /// [_0fa0157d_f829_445a_bbde_f13d9dc40e0b]

                /// [_106ff784_4cbb_4286_872b_43a0303494f3]
                TEST_CASE("should return true if it set the new value")
                {
                    void_t* random_a = Random<void_t*>();
                    void_t* random_b = Random<void_t*>();
                    atomic_t<void_t*> atom(random_a);
                    void_t* snapshot = atom;
                    CHECK(atom.Exchange_If_Equals(snapshot, random_b) == true);
                }
                /// [_106ff784_4cbb_4286_872b_43a0303494f3]

                /// [_b365aebd_64e4_47fb_b75b_dd2db715eff9]
                TEST_CASE("should return false if it did not set the new value")
                {
                    void_t* random_a = Random<void_t*>();
                    void_t* random_b;
                    do {
                        random_b = Random<void_t*>();
                    } while (random_b == random_a);
                    atomic_t<void_t*> atom(random_a);
                    void_t* snapshot = atom;
                    atom = random_b;
                    CHECK(atom.Exchange_If_Equals(snapshot, nullptr) == false);
                }
                /// [_b365aebd_64e4_47fb_b75b_dd2db715eff9]

                /// [_819e1d79_cec6_4386_a0f3_212485912860]
                TEST_CASE("should leave snapshot with its old value if it succeeded")
                {
                    void_t* random_a = Random<void_t*>();
                    void_t* random_b = Random<void_t*>();
                    atomic_t<void_t*> atom(random_a);
                    void_t* snapshot = atom;
                    atom.Exchange_If_Equals(snapshot, random_b);
                    CHECK(snapshot == random_a);
                }
                /// [_819e1d79_cec6_4386_a0f3_212485912860]

                /// [_ee8ffc54_708c_4ce6_8c6a_9e8e5e4be289]
                TEST_CASE("should update snapshot to its current value if it failed")
                {
                    void_t* random_a = Random<void_t*>();
                    void_t* random_b;
                    do {
                        random_b = Random<void_t*>();
                    } while (random_b == random_a);
                    atomic_t<void_t*> atom(random_a);
                    void_t* snapshot = atom;
                    atom = random_b;
                    atom.Exchange_If_Equals(snapshot, nullptr);
                    CHECK(snapshot == random_b);
                }
                /// [_ee8ffc54_708c_4ce6_8c6a_9e8e5e4be289]

                /// [_f8f29d95_d082_4fc8_9684_e946b4846620]
                TEST_CASE("should work with types convertible to its value_t")
                {
                    void_t* random_a = Random<void_t*>();
                    word_t* random_b = Random<word_t*>();
                    atomic_t<void_t*> atom(random_a);
                    void_t* snapshot = atom;
                    atom.Exchange_If_Equals(snapshot, random_b);
                    CHECK(atom == static_cast<void_t*>(random_b));
                }
                /// [_f8f29d95_d082_4fc8_9684_e946b4846620]
            }
        }

        TEST_SUITE("casts")
        {
            TEST_SUITE("value_t()")
            {
                /// [_2bdab148_3be8_4b43_8e48_ca7e0c09c5fd]
                TEST_CASE("should explicitly return a copy of its value")
                {
                    void_t* random = Random<void_t*>();
                    const atomic_t<void_t*> atom(random);
                    CHECK(static_cast<void_t*>(atom) == random);
                }
                /// [_2bdab148_3be8_4b43_8e48_ca7e0c09c5fd]

                /// [_a6cb15aa_39f7_4b0a_ad27_2e4a6f2b82e1]
                TEST_CASE("should implicitly return a copy of its value")
                {
                    void_t* random = Random<void_t*>();
                    const atomic_t<void_t*> atom(random);
                    void_t* value = atom;
                    CHECK(value == random);
                }
                /// [_a6cb15aa_39f7_4b0a_ad27_2e4a6f2b82e1]

                /// [_c870234c_89f2_4d02_9b99_3d3c0d9d0567]
                TEST_CASE("should not change its value")
                {
                    void_t* random = Random<void_t*>();
                    const atomic_t<void_t*> atom(random);
                    void_t* value = atom;
                    CHECK(atom == random);
                }
                /// [_c870234c_89f2_4d02_9b99_3d3c0d9d0567]

                /// [_96dad9b8_a068_49ba_9244_994105874561]
                TEST_CASE("should implicitly allow for logical operators")
                {
                    void_t* random;
                    do {
                        random = Random<void_t*>();
                    } while (random == nullptr);
                    const atomic_t<void_t*> atom(random);
                    CHECK(atom);
                    CHECK(!!atom);
                    CHECK(atom || false);
                    CHECK(atom && true);
                    CHECK(atom ? true : false);
                }
                /// [_96dad9b8_a068_49ba_9244_994105874561]

                /// [_fd690b21_aa70_43d0_9dbd_67fb502e8d5f]
                TEST_CASE("should implicitly allow for comparison operators")
                {
                    void_t* random = Random<void_t*>();
                    const atomic_t<void_t*> atom(random);
                    CHECK(atom == random);
                    CHECK_FALSE(atom != random);
                    CHECK_FALSE(atom < random);
                    CHECK_FALSE(atom > random);
                    CHECK(atom <= random);
                    CHECK(atom >= random);
                    CHECK((atom <=> random == 0));
                }
                /// [_fd690b21_aa70_43d0_9dbd_67fb502e8d5f]
            }
        }

        TEST_SUITE("operators")
        {
            TEST_SUITE("()()")
            {
                /// [_4540bb5a_efe9_43c7_a114_ab7e4c515e1d]
                TEST_CASE("should return a copy of its value")
                {
                    void_t* random = Random<void_t*>();
                    const atomic_t<void_t*> atom(random);
                    CHECK(atom() == random);
                }
                /// [_4540bb5a_efe9_43c7_a114_ab7e4c515e1d]

                /// [_a820f8ee_28cd_47b9_a7f4_5d844c89d9bc]
                TEST_CASE("should not change its value")
                {
                    void_t* random = Random<void_t*>();
                    const atomic_t<void_t*> atom(random);
                    void_t* value = atom();
                    CHECK(atom == random);
                }
                /// [_a820f8ee_28cd_47b9_a7f4_5d844c89d9bc]
            }
        }

        TEST_SUITE("none_t interface")
        {
            TEST_SUITE("none_ctor()")
            {
                /// [_a3b9d5ad_0125_40da_8039_eec9faf180bf]
                TEST_CASE("should explicitly set its value to the default value")
                {
                    atomic_t<void_t*> atom((none_t()));
                    CHECK(atom == atomic_t<void_t*>::DEFAULT_VALUE);
                }
                /// [_a3b9d5ad_0125_40da_8039_eec9faf180bf]

                /// [_cf36eda0_38e5_480c_8b82_f872c883da88]
                TEST_CASE("should implicitly set its value to the default value")
                {
                    atomic_t<void_t*> atom = none_t();
                    CHECK(atom == atomic_t<void_t*>::DEFAULT_VALUE);
                }
                /// [_cf36eda0_38e5_480c_8b82_f872c883da88]
            }

            TEST_SUITE("=(none_t)")
            {
                /// [_1e1000e5_1163_4d7d_9392_cb2c1c6c0453]
                TEST_CASE("should set its value to the default value")
                {
                    void_t* random = Random<void_t*>();
                    atomic_t<void_t*> atom(random);
                    atom = none_t();
                    CHECK(atom == atomic_t<void_t*>::DEFAULT_VALUE);
                }
                /// [_1e1000e5_1163_4d7d_9392_cb2c1c6c0453]

                /// [_862c7aca_94cf_4d43_b114_511832f9b3c2]
                TEST_CASE("should evaluate as false after being set to none")
                {
                    void_t* random = Random<void_t*>();
                    atomic_t<void_t*> atom(random);
                    atom = none_t();
                    CHECK(static_cast<bool_t>(atom) == false);
                }
                /// [_862c7aca_94cf_4d43_b114_511832f9b3c2]

                /// [_775d8d71_9b69_4cd4_972f_cf4753b5fc2a]
                TEST_CASE("should return itself")
                {
                    void_t* random = Random<void_t*>();
                    atomic_t<void_t*> atom(random);
                    CHECK(&(atom = none_t()) == &atom);
                }
                /// [_775d8d71_9b69_4cd4_972f_cf4753b5fc2a]
            }

            TEST_SUITE("==(none_t)")
            {
                /// [_b4dc0c6d_7ec8_440a_b3f2_4bceec666f0c]
                TEST_CASE("should return true when default constructed")
                {
                    const atomic_t<void_t*> atom;
                    CHECK(atom == none_t());
                }
                /// [_b4dc0c6d_7ec8_440a_b3f2_4bceec666f0c]

                /// [_df4ed3bb_41ce_40d1_99ad_a1633ffa0e12]
                TEST_CASE("should return true if its value is nullptr")
                {
                    const atomic_t<void_t*> atom(nullptr);
                    CHECK(atom == none_t());
                }
                /// [_df4ed3bb_41ce_40d1_99ad_a1633ffa0e12]

                /// [_4da1d3d0_c5a5_4181_a26d_eab4b4b2186d]
                TEST_CASE("should not change its value")
                {
                    void_t* random = Random<void_t*>();
                    const atomic_t<void_t*> atom(random);
                    atom == none_t();
                    CHECK(atom == random);
                }
                /// [_4da1d3d0_c5a5_4181_a26d_eab4b4b2186d]
            }

            TEST_SUITE("!=(none_t)")
            {
                /// [_c0e4fefa_9025_4245_b9a6_9d1840fabda7]
                TEST_CASE("should return false when default constructed")
                {
                    const atomic_t<void_t*> atom;
                    CHECK_FALSE(atom != none_t());
                }
                /// [_c0e4fefa_9025_4245_b9a6_9d1840fabda7]

                /// [_fa46bf6d_7404_469f_90f4_4d2202ca1569]
                TEST_CASE("should return false if its value is nullptr")
                {
                    const atomic_t<void_t*> atom(nullptr);
                    CHECK_FALSE(atom != none_t());
                }
                /// [_fa46bf6d_7404_469f_90f4_4d2202ca1569]

                /// [_ea3017a1_53eb_4e91_ab85_45399d7079c5]
                TEST_CASE("should not change its value")
                {
                    void_t* random = Random<void_t*>();
                    const atomic_t<void_t*> atom(random);
                    atom != none_t();
                    CHECK(atom == random);
                }
                /// [_ea3017a1_53eb_4e91_ab85_45399d7079c5]
            }
        }
    }

}
