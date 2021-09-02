/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/atomic_t.h"

#include "intrinsics.h"

namespace nkr {

    TEST_SUITE("atomic_t<integer_tr integer_p>")
    {
    #if defined(nkr_IS_64_BIT)

    #define _                                                   \
        u8_t, s8_t, u16_t, s16_t, u32_t, s32_t, u64_t, s64_t,   \
        c8_t, c16_t, c32_t,                                     \
        word_t

    #elif defined(nkr_IS_32_BIT)

    #define _                                   \
        u8_t, s8_t, u16_t, s16_t, u32_t, s32_t, \
        c8_t, c16_t, c32_t,                     \
        word_t

    #endif

        TEST_SUITE("aliases")
        {
            TEST_SUITE("value_t")
            {
                /// [_06294f3b_7dac_4f59_895a_2fd7f9b33932]
                TEST_CASE_TEMPLATE("should equal the passed in type", integer_p, _)
                {
                    static_assert(std::same_as<atomic_t<integer_p>::value_t, integer_p>);
                }
                /// [_06294f3b_7dac_4f59_895a_2fd7f9b33932]
            }
        }

        TEST_SUITE("static data")
        {
            TEST_SUITE("DEFAULT_VALUE")
            {
                /// [_69784cd6_a92d_46c7_ac93_9e8df556d8af]
                TEST_CASE_TEMPLATE("should equal the default value of value_t", integer_p, _)
                {
                    CHECK(atomic_t<integer_p>::DEFAULT_VALUE == atomic_t<integer_p>::value_t());
                }
                /// [_69784cd6_a92d_46c7_ac93_9e8df556d8af]

                /// [_81cab430_3f81_4688_bc15_44aac4e05e71]
                TEST_CASE_TEMPLATE("should equal 0", integer_p, _)
                {
                    CHECK(atomic_t<integer_p>::DEFAULT_VALUE == 0);
                }
                /// [_81cab430_3f81_4688_bc15_44aac4e05e71]
            }
        }

        TEST_SUITE("object data")
        {
            TEST_SUITE("value")
            {
                /// [_ad87d67f_1180_4b90_89bd_4556539c78fb]
                TEST_CASE_TEMPLATE("should be a volatile value_t", integer_p, _)
                {
                    static_assert(std::same_as<decltype(atomic_t<integer_p>::value), volatile integer_p>);
                }
                /// [_ad87d67f_1180_4b90_89bd_4556539c78fb]
            }
        }

        TEST_SUITE("objects")
        {
            TEST_SUITE("default_ctor()")
            {
                /// [_0cc6f622_d075_4f7f_a418_c7530c5410c4]
                TEST_CASE_TEMPLATE("should set value to the default", integer_p, _)
                {
                    atomic_t<integer_p> atom;
                    CHECK(atom == atomic_t<integer_p>::DEFAULT_VALUE);
                }
                /// [_0cc6f622_d075_4f7f_a418_c7530c5410c4]
            }

            TEST_SUITE("value_ctor()")
            {
                /// [_12f75ab2_b36e_4723_aa99_759ecf55564e]
                TEST_CASE_TEMPLATE("should explicitly set passed value", integer_p, _)
                {
                    integer_p random = Random<integer_p>();
                    atomic_t<integer_p> atom(random);
                    CHECK(atom == random);
                }
                /// [_12f75ab2_b36e_4723_aa99_759ecf55564e]

                /// [_5d7de716_427e_4e8d_9d44_e4e35c2ab2d7]
                TEST_CASE_TEMPLATE("should implicitly set passed value", integer_p, _)
                {
                    integer_p random = Random<integer_p>();
                    atomic_t<integer_p> atom = random;
                    CHECK(atom == random);
                }
                /// [_5d7de716_427e_4e8d_9d44_e4e35c2ab2d7]

                /// [_d665b2b2_b8c7_440e_8879_1d41f877e864]
                TEST_CASE_TEMPLATE("should convert other types and set passed value", integer_p, _)
                {
                    real_t random = Random<real_t>();
                    atomic_t<integer_p> atom(random);
                    CHECK(atom == static_cast<integer_p>(random));
                }
                /// [_d665b2b2_b8c7_440e_8879_1d41f877e864]
            }

            TEST_SUITE("copy_ctor()")
            {
                /// [_317191ae_4dd4_4f4b_9558_2b9e24e48bed]
                TEST_CASE_TEMPLATE("should explicitly copy the value of other", integer_p, _)
                {
                    integer_p random = Random<integer_p>();
                    const atomic_t<integer_p> other(random);
                    atomic_t<integer_p> atom(other);
                    CHECK(atom == random);
                }
                /// [_317191ae_4dd4_4f4b_9558_2b9e24e48bed]

                /// [_01d7552a_4ce6_4d9b_bafa_dd734a99be89]
                TEST_CASE_TEMPLATE("should implicitly copy the value of other", integer_p, _)
                {
                    integer_p random = Random<integer_p>();
                    const atomic_t<integer_p> other(random);
                    atomic_t<integer_p> atom = other;
                    CHECK(atom == random);
                }
                /// [_01d7552a_4ce6_4d9b_bafa_dd734a99be89]

                /// [_ceeed0fb_6ea8_4fdc_b435_ecc0bf6f6469]
                TEST_CASE_TEMPLATE("should not alter the value of other", integer_p, _)
                {
                    integer_p random = Random<integer_p>();
                    const atomic_t<integer_p> other(random);
                    atomic_t<integer_p> atom(other);
                    CHECK(other == random);
                }
                /// [_ceeed0fb_6ea8_4fdc_b435_ecc0bf6f6469]
            }

            TEST_SUITE("move_ctor()")
            {
                /// [_df38cfbc_868b_4f2c_828f_3aa70a944d78]
                TEST_CASE_TEMPLATE("should explicitly move the value of other", integer_p, _)
                {
                    integer_p random = Random<integer_p>();
                    atomic_t<integer_p> other(random);
                    atomic_t<integer_p> atom(std::move(other));
                    CHECK(atom == random);
                }
                /// [_df38cfbc_868b_4f2c_828f_3aa70a944d78]

                /// [_8edb3262_6441_43a6_9694_69b85f2481e9]
                TEST_CASE_TEMPLATE("should implicitly move the value of other", integer_p, _)
                {
                    integer_p random = Random<integer_p>();
                    atomic_t<integer_p> other(random);
                    atomic_t<integer_p> atom = std::move(other);
                    CHECK(atom == random);
                }
                /// [_8edb3262_6441_43a6_9694_69b85f2481e9]

                /// [_39b27c0d_e3eb_499d_9f6c_4b0ce03570f3]
                TEST_CASE_TEMPLATE("should set the value of other to the default", integer_p, _)
                {
                    integer_p random = Random<integer_p>();
                    atomic_t<integer_p> other(random);
                    atomic_t<integer_p> atom(std::move(other));
                    CHECK(other == atomic_t<integer_p>::DEFAULT_VALUE);
                }
                /// [_39b27c0d_e3eb_499d_9f6c_4b0ce03570f3]
            }

            TEST_SUITE("value_assignment_ctor()")
            {
                /// [_eb04d06c_bba0_4a7b_9c9c_668f8eb20941]
                TEST_CASE_TEMPLATE("should set passed value", integer_p, _)
                {
                    integer_p random = Random<integer_p>();
                    atomic_t<integer_p> atom;
                    atom = random;
                    CHECK(atom == random);
                }
                /// [_eb04d06c_bba0_4a7b_9c9c_668f8eb20941]

                /// [_6c8eb792_04d6_4354_8e8e_fa95357b91c2]
                TEST_CASE_TEMPLATE("should return itself", integer_p, _)
                {
                    integer_p random = Random<integer_p>();
                    atomic_t<integer_p> atom;
                    CHECK(&(atom = random) == &atom);
                }
                /// [_6c8eb792_04d6_4354_8e8e_fa95357b91c2]

                /// [_7802404a_ac0d_492a_8279_e8b757c10ccb]
                TEST_CASE_TEMPLATE("should convert other types and set passed value", integer_p, _)
                {
                    real_t random = Random<real_t>();
                    atomic_t<integer_p> atom;
                    atom = random;
                    CHECK(atom == static_cast<integer_p>(random));
                }
                /// [_7802404a_ac0d_492a_8279_e8b757c10ccb]
            }

            TEST_SUITE("copy_assignment_ctor()")
            {
                /// [_4e89bf27_7384_4a77_9212_e4e1917c2f51]
                TEST_CASE_TEMPLATE("should copy the value of other", integer_p, _)
                {
                    integer_p random = Random<integer_p>();
                    const atomic_t<integer_p> other(random);
                    atomic_t<integer_p> atom;
                    atom = other;
                    CHECK(atom == random);
                }
                /// [_4e89bf27_7384_4a77_9212_e4e1917c2f51]

                /// [_421b5566_42fb_4e0e_b53a_0345a8045840]
                TEST_CASE_TEMPLATE("should return itself", integer_p, _)
                {
                    integer_p random = Random<integer_p>();
                    const atomic_t<integer_p> other(random);
                    atomic_t<integer_p> atom;
                    CHECK(&(atom = other) == &atom);
                }
                /// [_421b5566_42fb_4e0e_b53a_0345a8045840]

                /// [_ae82e469_75e4_41dd_81f8_89f160e7af6d]
                TEST_CASE_TEMPLATE("should not alter the value of other", integer_p, _)
                {
                    integer_p random = Random<integer_p>();
                    const atomic_t<integer_p> other(random);
                    atomic_t<integer_p> atom;
                    atom = other;
                    CHECK(other == random);
                }
                /// [_ae82e469_75e4_41dd_81f8_89f160e7af6d]
            }

            TEST_SUITE("move_assignment_ctor()")
            {
                /// [_10fa738b_55bf_4081_b795_dbe866f86a5d]
                TEST_CASE_TEMPLATE("should move the value of other", integer_p, _)
                {
                    integer_p random = Random<integer_p>();
                    atomic_t<integer_p> other(random);
                    atomic_t<integer_p> atom;
                    atom = std::move(other);
                    CHECK(atom == random);
                }
                /// [_10fa738b_55bf_4081_b795_dbe866f86a5d]

                /// [_339b80e7_b5fb_4deb_a5e6_0b5099243dcb]
                TEST_CASE_TEMPLATE("should return itself", integer_p, _)
                {
                    integer_p random = Random<integer_p>();
                    atomic_t<integer_p> other(random);
                    atomic_t<integer_p> atom;
                    CHECK(&(atom = std::move(other)) == &atom);
                }
                /// [_339b80e7_b5fb_4deb_a5e6_0b5099243dcb]

                /// [_0d97f08b_3ca7_4129_b8e0_a0bf4d8f0d8a]
                TEST_CASE_TEMPLATE("should set the value of other to the default", integer_p, _)
                {
                    integer_p random = Random<integer_p>();
                    atomic_t<integer_p> other(random);
                    atomic_t<integer_p> atom;
                    atom = std::move(other);
                    CHECK(other == atomic_t<integer_p>::DEFAULT_VALUE);
                }
                /// [_0d97f08b_3ca7_4129_b8e0_a0bf4d8f0d8a]
            }

            TEST_SUITE("dtor()")
            {
                /// [_7eb50a4b_2db8_4eb8_9cf7_ffb5dd49c945]
                TEST_CASE_TEMPLATE("should set its value to the default", integer_p, _)
                {
                    integer_p random = Random<integer_p>();
                    atomic_t<integer_p> atom(random);
                    atom.~atomic_t();
                    CHECK(atom == atomic_t<integer_p>::DEFAULT_VALUE);
                }
                /// [_7eb50a4b_2db8_4eb8_9cf7_ffb5dd49c945]
            }
        }

        TEST_SUITE("methods")
        {
            TEST_SUITE("Access()")
            {
                /// [_0c77f4c0_b0b6_48dc_9af8_b71787783304]
                TEST_CASE_TEMPLATE("should return its value", integer_p, _)
                {
                    integer_p random = Random<integer_p>();
                    const atomic_t<integer_p> atom(random);
                    CHECK(atom.Access() == random);
                }
                /// [_0c77f4c0_b0b6_48dc_9af8_b71787783304]

                /// [_328b710c_cf6c_4623_b801_47c10841ee1a]
                TEST_CASE_TEMPLATE("should not change its value", integer_p, _)
                {
                    integer_p random = Random<integer_p>();
                    const atomic_t<integer_p> atom(random);
                    atom.Access();
                    CHECK(atom == random);
                }
                /// [_328b710c_cf6c_4623_b801_47c10841ee1a]
            }

            TEST_SUITE("Assign()")
            {
                /// [_462b7d6b_c8a5_4dee_ae70_ccc0dcd03aab]
                TEST_CASE_TEMPLATE("should set its value to the passed value", integer_p, _)
                {
                    integer_p random_a = Random<integer_p>();
                    integer_p random_b = Random<integer_p>();
                    atomic_t<integer_p> atom(random_a);
                    atom.Assign(random_b);
                    CHECK(atom == random_b);
                }
                /// [_462b7d6b_c8a5_4dee_ae70_ccc0dcd03aab]

                /// [_53ccc85e_aed3_48c4_814d_e8ce4dfaf2fb]
                TEST_CASE_TEMPLATE("should return itself", integer_p, _)
                {
                    integer_p random_a = Random<integer_p>();
                    integer_p random_b = Random<integer_p>();
                    atomic_t<integer_p> atom(random_a);
                    CHECK(&atom.Assign(random_b) == &atom);
                }
                /// [_53ccc85e_aed3_48c4_814d_e8ce4dfaf2fb]

                /// [_b737076b_33d1_4607_a438_fd545b2dc4c4]
                TEST_CASE_TEMPLATE("should work with types convertible to its value_t", integer_p, _)
                {
                    integer_p random_a = Random<integer_p>();
                    real_t random_b = Random<real_t>();
                    atomic_t<integer_p> atom(random_a);
                    atom.Assign(random_b);
                    CHECK(atom == static_cast<integer_p>(random_b));
                }
                /// [_b737076b_33d1_4607_a438_fd545b2dc4c4]
            }

            TEST_SUITE("Assign_Add()")
            {
                /// [_850f475f_e992_4702_89ee_75951b846355]
                TEST_CASE_TEMPLATE("should set its value to value + passed value", integer_p, _)
                {
                    integer_p random_a = Random<integer_p>();
                    integer_p random_b = Random<integer_p>();
                    atomic_t<integer_p> atom(random_a);
                    atom.Assign_Add(random_b);
                    CHECK(atom == (random_a += random_b));
                }
                /// [_850f475f_e992_4702_89ee_75951b846355]

                /// [_2e6b7143_0393_4868_b3a6_63fe75892a7c]
                TEST_CASE_TEMPLATE("should return itself", integer_p, _)
                {
                    integer_p random_a = Random<integer_p>();
                    integer_p random_b = Random<integer_p>();
                    atomic_t<integer_p> atom(random_a);
                    CHECK(&atom.Assign_Add(random_b) == &atom);
                }
                /// [_2e6b7143_0393_4868_b3a6_63fe75892a7c]

                /// [_8b9b37a2_b8cd_4eb4_b5af_9cf98dc590f3]
                TEST_CASE_TEMPLATE("should work with types convertible to its value_t", integer_p, _)
                {
                    integer_p random_a = Random<integer_p>();
                    real_t random_b = Random<real_t>();
                    atomic_t<integer_p> atom(random_a);
                    atom.Assign_Add(random_b);
                    CHECK(atom == (random_a += static_cast<integer_p>(random_b)));
                }
                /// [_8b9b37a2_b8cd_4eb4_b5af_9cf98dc590f3]
            }

            TEST_SUITE("Assign_Subtract()")
            {
                /// [_769826f2_dc35_4c34_81ec_563705f5b8b1]
                TEST_CASE_TEMPLATE("should set its value to value - passed value", integer_p, _)
                {
                    integer_p random_a = Random<integer_p>();
                    integer_p random_b = Random<integer_p>();
                    atomic_t<integer_p> atom(random_a);
                    atom.Assign_Subtract(random_b);
                    CHECK(atom == (random_a -= random_b));
                }
                /// [_769826f2_dc35_4c34_81ec_563705f5b8b1]

                /// [_1f0cb070_88ea_4cde_a856_8c9277868147]
                TEST_CASE_TEMPLATE("should return itself", integer_p, _)
                {
                    integer_p random_a = Random<integer_p>();
                    integer_p random_b = Random<integer_p>();
                    atomic_t<integer_p> atom(random_a);
                    CHECK(&atom.Assign_Subtract(random_b) == &atom);
                }
                /// [_1f0cb070_88ea_4cde_a856_8c9277868147]

                /// [_26ec2716_3685_47b5_95f5_fcce7d62aaa8]
                TEST_CASE_TEMPLATE("should work with types convertible to its value_t", integer_p, _)
                {
                    integer_p random_a = Random<integer_p>();
                    real_t random_b = Random<real_t>();
                    atomic_t<integer_p> atom(random_a);
                    atom.Assign_Subtract(random_b);
                    CHECK(atom == (random_a -= static_cast<integer_p>(random_b)));
                }
                /// [_26ec2716_3685_47b5_95f5_fcce7d62aaa8]
            }

            TEST_SUITE("Assign_Multiply()")
            {
                /// [_01a7f689_bf5e_4e92_893c_2a6fe003a102]
                TEST_CASE_TEMPLATE("should set its value to value * passed value", integer_p, _)
                {
                    integer_p random_a = Random<integer_p>();
                    integer_p random_b = Random<integer_p>();
                    atomic_t<integer_p> atom(random_a);
                    atom.Assign_Multiply(random_b);
                    CHECK(atom == (random_a *= random_b));
                }
                /// [_01a7f689_bf5e_4e92_893c_2a6fe003a102]

                /// [_244d0aa1_9f9c_49d8_bdb7_6589fbd70695]
                TEST_CASE_TEMPLATE("should return itself", integer_p, _)
                {
                    integer_p random_a = Random<integer_p>();
                    integer_p random_b = Random<integer_p>();
                    atomic_t<integer_p> atom(random_a);
                    CHECK(&atom.Assign_Multiply(random_b) == &atom);
                }
                /// [_244d0aa1_9f9c_49d8_bdb7_6589fbd70695]

                /// [_b98ac85e_1709_4efc_9b05_b7725d2dbd02]
                TEST_CASE_TEMPLATE("should work with types convertible to its value_t", integer_p, _)
                {
                    integer_p random_a = Random<integer_p>();
                    real_t random_b = Random<real_t>();
                    atomic_t<integer_p> atom(random_a);
                    atom.Assign_Multiply(random_b);
                    CHECK(atom == (random_a *= static_cast<integer_p>(random_b)));
                }
                /// [_b98ac85e_1709_4efc_9b05_b7725d2dbd02]
            }

            TEST_SUITE("Assign_Divide()")
            {
                /// [_fc6e49a0_93b5_4648_bb14_55f6323d5357]
                TEST_CASE_TEMPLATE("should set its value to value / passed value", integer_p, _)
                {
                    integer_p random_a = Random<integer_p>();
                    integer_p random_b;
                    do {
                        random_b = Random<integer_p>();
                    } while (random_b == 0);
                    atomic_t<integer_p> atom(random_a);
                    atom.Assign_Divide(random_b);
                    CHECK(atom == (random_a /= random_b));
                }
                /// [_fc6e49a0_93b5_4648_bb14_55f6323d5357]

                /// [_7f22e857_b490_48ea_b2bb_fec159826aef]
                TEST_CASE_TEMPLATE("should return itself", integer_p, _)
                {
                    integer_p random_a = Random<integer_p>();
                    integer_p random_b;
                    do {
                        random_b = Random<integer_p>();
                    } while (random_b == 0);
                    atomic_t<integer_p> atom(random_a);
                    CHECK(&atom.Assign_Divide(random_b) == &atom);
                }
                /// [_7f22e857_b490_48ea_b2bb_fec159826aef]

                /// [_dd6760e6_c4da_4758_84ea_c7f4cce12231]
                TEST_CASE_TEMPLATE("should work with types convertible to its value_t", integer_p, _)
                {
                    integer_p random_a = Random<integer_p>();
                    real_t random_b;
                    do {
                        random_b = Random<real_t>(std::numeric_limits<integer_p>::lowest(),
                                                  std::numeric_limits<integer_p>::max());
                    } while (static_cast<integer_p>(random_b) == 0);
                    atomic_t<integer_p> atom(random_a);
                    atom.Assign_Divide(random_b);
                    CHECK(atom == (random_a /= static_cast<integer_p>(random_b)));
                }
                /// [_dd6760e6_c4da_4758_84ea_c7f4cce12231]
            }

            TEST_SUITE("Assign_Modulus()")
            {
                /// [_6ee19c91_0635_4d43_89b2_c53eb92470a4]
                TEST_CASE_TEMPLATE("should set its value to value % passed value", integer_p, _)
                {
                    integer_p random_a = Random<integer_p>();
                    integer_p random_b;
                    do {
                        random_b = Random<integer_p>();
                    } while (random_b == 0);
                    atomic_t<integer_p> atom(random_a);
                    atom.Assign_Modulus(random_b);
                    CHECK(atom == (random_a %= random_b));
                }
                /// [_6ee19c91_0635_4d43_89b2_c53eb92470a4]

                /// [_7938c7d7_4b45_428e_adc2_2b5c42ee0dfc]
                TEST_CASE_TEMPLATE("should return itself", integer_p, _)
                {
                    integer_p random_a = Random<integer_p>();
                    integer_p random_b;
                    do {
                        random_b = Random<integer_p>();
                    } while (random_b == 0);
                    atomic_t<integer_p> atom(random_a);
                    CHECK(&atom.Assign_Modulus(random_b) == &atom);
                }
                /// [_7938c7d7_4b45_428e_adc2_2b5c42ee0dfc]
            }

            TEST_SUITE("Assign_Or()")
            {
                /// [_494f5f48_3736_4c51_a3d5_6c6ca2e1ab2e]
                TEST_CASE_TEMPLATE("should set its value to value | passed value", integer_p, _)
                {
                    integer_p random_a = Random<integer_p>();
                    integer_p random_b = Random<integer_p>();
                    atomic_t<integer_p> atom(random_a);
                    atom.Assign_Or(random_b);
                    CHECK(atom == (random_a |= random_b));
                }
                /// [_494f5f48_3736_4c51_a3d5_6c6ca2e1ab2e]

                /// [_6e8e5794_2d91_4b50_8112_7783016d1138]
                TEST_CASE_TEMPLATE("should return itself", integer_p, _)
                {
                    integer_p random_a = Random<integer_p>();
                    integer_p random_b = Random<integer_p>();
                    atomic_t<integer_p> atom(random_a);
                    CHECK(&atom.Assign_Or(random_b) == &atom);
                }
                /// [_6e8e5794_2d91_4b50_8112_7783016d1138]
            }

            TEST_SUITE("Assign_And()")
            {
                /// [_e74154f8_434f_479b_be32_931202e4875e]
                TEST_CASE_TEMPLATE("should set its value to value & passed value", integer_p, _)
                {
                    integer_p random_a = Random<integer_p>();
                    integer_p random_b = Random<integer_p>();
                    atomic_t<integer_p> atom(random_a);
                    atom.Assign_And(random_b);
                    CHECK(atom == (random_a &= random_b));
                }
                /// [_e74154f8_434f_479b_be32_931202e4875e]

                /// [_6b977656_4615_4d89_9760_ed48cd612758]
                TEST_CASE_TEMPLATE("should return itself", integer_p, _)
                {
                    integer_p random_a = Random<integer_p>();
                    integer_p random_b = Random<integer_p>();
                    atomic_t<integer_p> atom(random_a);
                    CHECK(&atom.Assign_And(random_b) == &atom);
                }
                /// [_6b977656_4615_4d89_9760_ed48cd612758]
            }

            TEST_SUITE("Assign_Xor()")
            {
                /// [_0985ca53_d5d9_4a0b_b2bf_dc77d7461a51]
                TEST_CASE_TEMPLATE("should set its value to value ^ passed value", integer_p, _)
                {
                    integer_p random_a = Random<integer_p>();
                    integer_p random_b = Random<integer_p>();
                    atomic_t<integer_p> atom(random_a);
                    atom.Assign_Xor(random_b);
                    CHECK(atom == (random_a ^= random_b));
                }
                /// [_0985ca53_d5d9_4a0b_b2bf_dc77d7461a51]

                /// [_e26dea4c_bf26_4b2c_b439_e1a704795176]
                TEST_CASE_TEMPLATE("should return itself", integer_p, _)
                {
                    integer_p random_a = Random<integer_p>();
                    integer_p random_b = Random<integer_p>();
                    atomic_t<integer_p> atom(random_a);
                    CHECK(&atom.Assign_Xor(random_b) == &atom);
                }
                /// [_e26dea4c_bf26_4b2c_b439_e1a704795176]
            }

            TEST_SUITE("Assign_Left_Shift()")
            {
                /// [_70d051d2_d135_4efc_860c_ce4768ba4d3b]
                TEST_CASE_TEMPLATE("should set its value to value << passed value", integer_p, _)
                {
                    integer_p random_a = Random<integer_p>();
                    integer_p random_b = Random<integer_p>();
                    atomic_t<integer_p> atom(random_a);
                    atom.Assign_Left_Shift(random_b);
                    CHECK(atom == (random_a <<= random_b));
                }
                /// [_70d051d2_d135_4efc_860c_ce4768ba4d3b]

                /// [_37a2fae1_e932_4a07_964e_108aae375c29]
                TEST_CASE_TEMPLATE("should return itself", integer_p, _)
                {
                    integer_p random_a = Random<integer_p>();
                    integer_p random_b = Random<integer_p>();
                    atomic_t<integer_p> atom(random_a);
                    CHECK(&atom.Assign_Left_Shift(random_b) == &atom);
                }
                /// [_37a2fae1_e932_4a07_964e_108aae375c29]
            }

            TEST_SUITE("Assign_Right_Shift()")
            {
                /// [_1f5fb835_81e7_44cb_a500_708a9c1889eb]
                TEST_CASE_TEMPLATE("should set its value to value >> passed value", integer_p, _)
                {
                    integer_p random_a = Random<integer_p>();
                    integer_p random_b = Random<integer_p>();
                    atomic_t<integer_p> atom(random_a);
                    atom.Assign_Right_Shift(random_b);
                    CHECK(atom == (random_a >>= random_b));
                }
                /// [_1f5fb835_81e7_44cb_a500_708a9c1889eb]

                /// [_a7890a7b_d625_4b46_a6b9_052b92fdd21b]
                TEST_CASE_TEMPLATE("should return itself", integer_p, _)
                {
                    integer_p random_a = Random<integer_p>();
                    integer_p random_b = Random<integer_p>();
                    atomic_t<integer_p> atom(random_a);
                    CHECK(&atom.Assign_Right_Shift(random_b) == &atom);
                }
                /// [_a7890a7b_d625_4b46_a6b9_052b92fdd21b]
            }

            TEST_SUITE("Exchange()")
            {
                /// [_207240f1_e8bf_423f_bd84_8797ca6102be]
                TEST_CASE_TEMPLATE("should set its value to the passed value", integer_p, _)
                {
                    integer_p random_a = Random<integer_p>();
                    integer_p random_b = Random<integer_p>();
                    atomic_t<integer_p> atom(random_a);
                    atom.Exchange(random_b);
                    CHECK(atom == random_b);
                }
                /// [_207240f1_e8bf_423f_bd84_8797ca6102be]

                /// [_72ad10c1_8d71_43af_a089_58a129c4d31c]
                TEST_CASE_TEMPLATE("should return its old value", integer_p, _)
                {
                    integer_p random_a = Random<integer_p>();
                    integer_p random_b = Random<integer_p>();
                    atomic_t<integer_p> atom(random_a);
                    CHECK(atom.Exchange(random_b) == random_a);
                }
                /// [_72ad10c1_8d71_43af_a089_58a129c4d31c]

                /// [_44995f58_9d6e_4163_a843_421fa4ba6ba8]
                TEST_CASE_TEMPLATE("should work with types convertible to its value_t", integer_p, _)
                {
                    integer_p random_a = Random<integer_p>();
                    real_t random_b = Random<real_t>();
                    atomic_t<integer_p> atom(random_a);
                    atom.Exchange(random_b);
                    CHECK(atom == static_cast<integer_p>(random_b));
                }
                /// [_44995f58_9d6e_4163_a843_421fa4ba6ba8]
            }

            TEST_SUITE("Exchange_Add()")
            {
                /// [_7eba1ca0_52c7_46ec_ad1f_dad8fa36f0d3]
                TEST_CASE_TEMPLATE("should set its value to value + passed value", integer_p, _)
                {
                    integer_p random_a = Random<integer_p>();
                    integer_p random_b = Random<integer_p>();
                    atomic_t<integer_p> atom(random_a);
                    atom.Exchange_Add(random_b);
                    CHECK(atom == (random_a += random_b));
                }
                /// [_7eba1ca0_52c7_46ec_ad1f_dad8fa36f0d3]

                /// [_11019e66_55e5_4069_bc29_15756234a5cf]
                TEST_CASE_TEMPLATE("should return its old value", integer_p, _)
                {
                    integer_p random_a = Random<integer_p>();
                    integer_p random_b = Random<integer_p>();
                    atomic_t<integer_p> atom(random_a);
                    CHECK(atom.Exchange_Add(random_b) == random_a);
                }
                /// [_11019e66_55e5_4069_bc29_15756234a5cf]

                /// [_457a33f9_1f90_4f93_af47_d9961fc23aed]
                TEST_CASE_TEMPLATE("should work with types convertible to its value_t", integer_p, _)
                {
                    integer_p random_a = Random<integer_p>();
                    real_t random_b = Random<real_t>();
                    atomic_t<integer_p> atom(random_a);
                    atom.Exchange_Add(random_b);
                    CHECK(atom == (random_a += static_cast<integer_p>(random_b)));
                }
                /// [_457a33f9_1f90_4f93_af47_d9961fc23aed]
            }

            TEST_SUITE("Exchange_Subtract()")
            {
                /// [_996e8ea4_bc4b_4a4f_8956_ced2fb2c803f]
                TEST_CASE_TEMPLATE("should set its value to value - passed value", integer_p, _)
                {
                    integer_p random_a = Random<integer_p>();
                    integer_p random_b = Random<integer_p>();
                    atomic_t<integer_p> atom(random_a);
                    atom.Exchange_Subtract(random_b);
                    CHECK(atom == (random_a -= random_b));
                }
                /// [_996e8ea4_bc4b_4a4f_8956_ced2fb2c803f]

                /// [_cdbc6b7a_847c_4f56_8574_e9ba47025f38]
                TEST_CASE_TEMPLATE("should return its old value", integer_p, _)
                {
                    integer_p random_a = Random<integer_p>();
                    integer_p random_b = Random<integer_p>();
                    atomic_t<integer_p> atom(random_a);
                    CHECK(atom.Exchange_Subtract(random_b) == random_a);
                }
                /// [_cdbc6b7a_847c_4f56_8574_e9ba47025f38]

                /// [_d53d0482_2ef4_4bca_964f_ed6c0757a158]
                TEST_CASE_TEMPLATE("should work with types convertible to its value_t", integer_p, _)
                {
                    integer_p random_a = Random<integer_p>();
                    real_t random_b = Random<real_t>();
                    atomic_t<integer_p> atom(random_a);
                    atom.Exchange_Subtract(random_b);
                    CHECK(atom == (random_a -= static_cast<integer_p>(random_b)));
                }
                /// [_d53d0482_2ef4_4bca_964f_ed6c0757a158]
            }

            TEST_SUITE("Exchange_Multiply()")
            {
                /// [_ef9175c9_36b3_4ed7_85d8_24b632f585c4]
                TEST_CASE_TEMPLATE("should set its value to value * passed value", integer_p, _)
                {
                    integer_p random_a = Random<integer_p>();
                    integer_p random_b = Random<integer_p>();
                    atomic_t<integer_p> atom(random_a);
                    atom.Exchange_Multiply(random_b);
                    CHECK(atom == (random_a *= random_b));
                }
                /// [_ef9175c9_36b3_4ed7_85d8_24b632f585c4]

                /// [_0c25835a_9e55_468b_a809_c9fee298cc86]
                TEST_CASE_TEMPLATE("should return its old value", integer_p, _)
                {
                    integer_p random_a = Random<integer_p>();
                    integer_p random_b = Random<integer_p>();
                    atomic_t<integer_p> atom(random_a);
                    CHECK(atom.Exchange_Multiply(random_b) == random_a);
                }
                /// [_0c25835a_9e55_468b_a809_c9fee298cc86]

                /// [_b316d6c0_c5c2_42b6_8406_e82e5e259b56]
                TEST_CASE_TEMPLATE("should work with types convertible to its value_t", integer_p, _)
                {
                    integer_p random_a = Random<integer_p>();
                    real_t random_b = Random<real_t>();
                    atomic_t<integer_p> atom(random_a);
                    atom.Exchange_Multiply(random_b);
                    CHECK(atom == (random_a *= static_cast<integer_p>(random_b)));
                }
                /// [_b316d6c0_c5c2_42b6_8406_e82e5e259b56]
            }

            TEST_SUITE("Exchange_Divide()")
            {
                /// [_0309f242_d7f1_4cb6_9638_e810f3f05d86]
                TEST_CASE_TEMPLATE("should set its value to value / passed value", integer_p, _)
                {
                    integer_p random_a = Random<integer_p>();
                    integer_p random_b;
                    do {
                        random_b = Random<integer_p>();
                    } while (random_b == 0);
                    atomic_t<integer_p> atom(random_a);
                    atom.Exchange_Divide(random_b);
                    CHECK(atom == (random_a /= random_b));
                }
                /// [_0309f242_d7f1_4cb6_9638_e810f3f05d86]

                /// [_c6e82e8e_8a06_40ab_8616_d9295431031e]
                TEST_CASE_TEMPLATE("should return its old value", integer_p, _)
                {
                    integer_p random_a = Random<integer_p>();
                    integer_p random_b;
                    do {
                        random_b = Random<integer_p>();
                    } while (random_b == 0);
                    atomic_t<integer_p> atom(random_a);
                    CHECK(atom.Exchange_Divide(random_b) == random_a);
                }
                /// [_c6e82e8e_8a06_40ab_8616_d9295431031e]

                /// [_c0d10509_de94_406c_913c_9af27486d73e]
                TEST_CASE_TEMPLATE("should work with types convertible to its value_t", integer_p, _)
                {
                    integer_p random_a = Random<integer_p>();
                    real_t random_b;
                    do {
                        random_b = Random<real_t>(std::numeric_limits<integer_p>::lowest(),
                                                  std::numeric_limits<integer_p>::max());
                    } while (static_cast<integer_p>(random_b) == 0);
                    atomic_t<integer_p> atom(random_a);
                    atom.Exchange_Divide(random_b);
                    CHECK(atom == (random_a /= static_cast<integer_p>(random_b)));
                }
                /// [_c0d10509_de94_406c_913c_9af27486d73e]
            }

            TEST_SUITE("Exchange_Modulus()")
            {
                /// [_445a293a_6b8d_46ac_a283_1d166dcfd3c3]
                TEST_CASE_TEMPLATE("should set its value to value % passed value", integer_p, _)
                {
                    integer_p random_a = Random<integer_p>();
                    integer_p random_b;
                    do {
                        random_b = Random<integer_p>();
                    } while (random_b == 0);
                    atomic_t<integer_p> atom(random_a);
                    atom.Exchange_Modulus(random_b);
                    CHECK(atom == (random_a %= random_b));
                }
                /// [_445a293a_6b8d_46ac_a283_1d166dcfd3c3]

                /// [_af092393_dede_4cbf_bb49_e731a7f0ba9f]
                TEST_CASE_TEMPLATE("should return its old value", integer_p, _)
                {
                    integer_p random_a = Random<integer_p>();
                    integer_p random_b;
                    do {
                        random_b = Random<integer_p>();
                    } while (random_b == 0);
                    atomic_t<integer_p> atom(random_a);
                    CHECK(atom.Exchange_Modulus(random_b) == random_a);
                }
                /// [_af092393_dede_4cbf_bb49_e731a7f0ba9f]
            }

            TEST_SUITE("Exchange_Or()")
            {
                /// [_65837db9_ca87_4a26_9ccf_eaa7c67dedef]
                TEST_CASE_TEMPLATE("should set its value to value | passed value", integer_p, _)
                {
                    integer_p random_a = Random<integer_p>();
                    integer_p random_b = Random<integer_p>();
                    atomic_t<integer_p> atom(random_a);
                    atom.Exchange_Or(random_b);
                    CHECK(atom == (random_a |= random_b));
                }
                /// [_65837db9_ca87_4a26_9ccf_eaa7c67dedef]

                /// [_fd5bfebd_6c23_4e61_9e3c_1e3019108bfe]
                TEST_CASE_TEMPLATE("should return its old value", integer_p, _)
                {
                    integer_p random_a = Random<integer_p>();
                    integer_p random_b = Random<integer_p>();
                    atomic_t<integer_p> atom(random_a);
                    CHECK(atom.Exchange_Or(random_b) == random_a);
                }
                /// [_fd5bfebd_6c23_4e61_9e3c_1e3019108bfe]
            }

            TEST_SUITE("Exchange_And()")
            {
                /// [_0bd91085_3a95_4b2a_bd09_70a4d9fd0951]
                TEST_CASE_TEMPLATE("should set its value to value & passed value", integer_p, _)
                {
                    integer_p random_a = Random<integer_p>();
                    integer_p random_b = Random<integer_p>();
                    atomic_t<integer_p> atom(random_a);
                    atom.Exchange_And(random_b);
                    CHECK(atom == (random_a &= random_b));
                }
                /// [_0bd91085_3a95_4b2a_bd09_70a4d9fd0951]

                /// [_c570b099_8c50_49c0_9ba3_afc86df17880]
                TEST_CASE_TEMPLATE("should return its old value", integer_p, _)
                {
                    integer_p random_a = Random<integer_p>();
                    integer_p random_b = Random<integer_p>();
                    atomic_t<integer_p> atom(random_a);
                    CHECK(atom.Exchange_And(random_b) == random_a);
                }
                /// [_c570b099_8c50_49c0_9ba3_afc86df17880]
            }

            TEST_SUITE("Exchange_Xor()")
            {
                /// [_32dce8de_1f00_4775_a8e7_ca3277ef1b0d]
                TEST_CASE_TEMPLATE("should set its value to value ^ passed value", integer_p, _)
                {
                    integer_p random_a = Random<integer_p>();
                    integer_p random_b = Random<integer_p>();
                    atomic_t<integer_p> atom(random_a);
                    atom.Exchange_Xor(random_b);
                    CHECK(atom == (random_a ^= random_b));
                }
                /// [_32dce8de_1f00_4775_a8e7_ca3277ef1b0d]

                /// [_527a5e96_e6bf_46e8_ba45_51d1884c168a]
                TEST_CASE_TEMPLATE("should return its old value", integer_p, _)
                {
                    integer_p random_a = Random<integer_p>();
                    integer_p random_b = Random<integer_p>();
                    atomic_t<integer_p> atom(random_a);
                    CHECK(atom.Exchange_Xor(random_b) == random_a);
                }
                /// [_527a5e96_e6bf_46e8_ba45_51d1884c168a]
            }

            TEST_SUITE("Exchange_Left_Shift()")
            {
                /// [_14a0da5a_8be8_4deb_8241_65d9202dc6b8]
                TEST_CASE_TEMPLATE("should set its value to value << passed value", integer_p, _)
                {
                    integer_p random_a = Random<integer_p>();
                    integer_p random_b = Random<integer_p>();
                    atomic_t<integer_p> atom(random_a);
                    atom.Exchange_Left_Shift(random_b);
                    CHECK(atom == (random_a <<= random_b));
                }
                /// [_14a0da5a_8be8_4deb_8241_65d9202dc6b8]

                /// [_80e8d5b2_48a7_4596_a8a5_c7402aec563a]
                TEST_CASE_TEMPLATE("should return its old value", integer_p, _)
                {
                    integer_p random_a = Random<integer_p>();
                    integer_p random_b = Random<integer_p>();
                    atomic_t<integer_p> atom(random_a);
                    CHECK(atom.Exchange_Left_Shift(random_b) == random_a);
                }
                /// [_80e8d5b2_48a7_4596_a8a5_c7402aec563a]
            }

            TEST_SUITE("Exchange_Right_Shift()")
            {
                /// [_63952b7c_06a0_437e_95c7_dec0e35fdf18]
                TEST_CASE_TEMPLATE("should set its value to value >> passed value", integer_p, _)
                {
                    integer_p random_a = Random<integer_p>();
                    integer_p random_b = Random<integer_p>();
                    atomic_t<integer_p> atom(random_a);
                    atom.Exchange_Right_Shift(random_b);
                    CHECK(atom == (random_a >>= random_b));
                }
                /// [_63952b7c_06a0_437e_95c7_dec0e35fdf18]

                /// [_9449f384_ab1f_428d_b075_a6cd21c5998a]
                TEST_CASE_TEMPLATE("should return its old value", integer_p, _)
                {
                    integer_p random_a = Random<integer_p>();
                    integer_p random_b = Random<integer_p>();
                    atomic_t<integer_p> atom(random_a);
                    CHECK(atom.Exchange_Right_Shift(random_b) == random_a);
                }
                /// [_9449f384_ab1f_428d_b075_a6cd21c5998a]
            }

            TEST_SUITE("Exchange_If_Equals()")
            {
                /// [_ceab5104_740f_4e44_8f44_22b59f41ff69]
                TEST_CASE_TEMPLATE("should set its value to the passed value if its value equals the snapshot", integer_p, _)
                {
                    integer_p random_a = Random<integer_p>();
                    integer_p random_b = Random<integer_p>();
                    atomic_t<integer_p> atom(random_a);
                    integer_p snapshot = atom;
                    atom.Exchange_If_Equals(snapshot, snapshot + random_b);
                    CHECK(atom == static_cast<integer_p>(random_a + random_b));
                }
                /// [_ceab5104_740f_4e44_8f44_22b59f41ff69]

                /// [_7d4bbd2c_111c_450a_8106_cd19d0db6bb1]
                TEST_CASE_TEMPLATE("should return true if it set the new value", integer_p, _)
                {
                    integer_p random_a = Random<integer_p>();
                    integer_p random_b = Random<integer_p>();
                    atomic_t<integer_p> atom(random_a);
                    integer_p snapshot = atom;
                    CHECK(atom.Exchange_If_Equals(snapshot, snapshot + random_b) == true);
                }
                /// [_7d4bbd2c_111c_450a_8106_cd19d0db6bb1]

                /// [_03aeb622_cad5_40b1_a1c4_71730801b851]
                TEST_CASE_TEMPLATE("should return false if it did not set the new value", integer_p, _)
                {
                    integer_p random_a = Random<integer_p>();
                    integer_p random_b = Random<integer_p>();
                    atomic_t<integer_p> atom(random_a);
                    integer_p snapshot = atom;
                    atom = random_a + random_b;
                    CHECK(atom.Exchange_If_Equals(snapshot, snapshot + random_b) == false);
                }
                /// [_03aeb622_cad5_40b1_a1c4_71730801b851]

                /// [_90fd8858_f9d3_4935_8ecb_a9ac261c997b]
                TEST_CASE_TEMPLATE("should leave snapshot with its old value if it succeeded", integer_p, _)
                {
                    integer_p random_a = Random<integer_p>();
                    integer_p random_b = Random<integer_p>();
                    atomic_t<integer_p> atom(random_a);
                    integer_p snapshot = atom;
                    atom.Exchange_If_Equals(snapshot, snapshot + random_b);
                    CHECK(snapshot == random_a);
                }
                /// [_90fd8858_f9d3_4935_8ecb_a9ac261c997b]

                /// [_84d94884_6634_45f0_8990_a8d7e5a80766]
                TEST_CASE_TEMPLATE("should update snapshot to its current value if it failed", integer_p, _)
                {
                    integer_p random_a = Random<integer_p>();
                    integer_p random_b = Random<integer_p>();
                    atomic_t<integer_p> atom(random_a);
                    integer_p snapshot = atom;
                    atom = random_a + random_b;
                    atom.Exchange_If_Equals(snapshot, snapshot + random_b);
                    CHECK(snapshot == static_cast<integer_p>(random_a + random_b));
                }
                /// [_84d94884_6634_45f0_8990_a8d7e5a80766]

                /// [_2f5f73ae_78d9_40d3_bbc7_aeeb4fea167b]
                TEST_CASE_TEMPLATE("should work with types convertible to its value_t", integer_p, _)
                {
                    integer_p random_a = Random<integer_p>();
                    real_t random_b = Random<real_t>();
                    atomic_t<integer_p> atom(random_a);
                    integer_p snapshot = atom;
                    atom.Exchange_If_Equals(snapshot, random_b);
                    CHECK(atom == static_cast<integer_p>(random_b));
                }
                /// [_2f5f73ae_78d9_40d3_bbc7_aeeb4fea167b]

                /// [_22ac03a2_ea9a_4606_9d3e_1cd1a55dd211]
                TEST_CASE_TEMPLATE("should allow you to atomically change its value safely with a custom algorithm", integer_p, _)
                {
                    atomic_t<integer_p> atom;
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
                                integer_p snapshot = atom;
                                while (!atom.Exchange_If_Equals(snapshot, snapshot + delta));
                            }
                        ));
                        decrementors.push_back(std::thread(
                            [&]() -> void_t
                            {
                                std::this_thread::sleep_for(
                                    std::chrono::microseconds(Random<count_t>(1, 5))
                                );
                                integer_p snapshot = atom;
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
                /// [_22ac03a2_ea9a_4606_9d3e_1cd1a55dd211]
            }
        }

        TEST_SUITE("casts")
        {
            TEST_SUITE("value_t()")
            {
                /// [_15f1561c_2888_4203_b493_63d2d130d72d]
                TEST_CASE_TEMPLATE("should explicitly return a copy of its value", integer_p, _)
                {
                    integer_p random = Random<integer_p>();
                    const atomic_t<integer_p> atom(random);
                    CHECK(static_cast<integer_p>(atom) == random);
                }
                /// [_15f1561c_2888_4203_b493_63d2d130d72d]

                /// [_7f9f0c97_2cdb_4b12_8a24_7b3632298a1f]
                TEST_CASE_TEMPLATE("should implicitly return a copy of its value", integer_p, _)
                {
                    integer_p random = Random<integer_p>();
                    const atomic_t<integer_p> atom(random);
                    integer_p value = atom;
                    CHECK(value == random);
                }
                /// [_7f9f0c97_2cdb_4b12_8a24_7b3632298a1f]

                /// [_48dfab43_7e02_4168_85dd_70d79bd7b297]
                TEST_CASE_TEMPLATE("should not change its value", integer_p, _)
                {
                    integer_p random = Random<integer_p>();
                    const atomic_t<integer_p> atom(random);
                    integer_p value = atom;
                    CHECK(atom == random);
                }
                /// [_48dfab43_7e02_4168_85dd_70d79bd7b297]

                /// [_4556d7de_1819_44d1_854e_20884a0f1a77]
                TEST_CASE_TEMPLATE("should implicitly allow for arithmetic operators", integer_p, _)
                {
                    integer_p random_a = Random<integer_p>();
                    integer_p random_b;
                    do {
                        random_b = Random<integer_p>();
                    } while (random_b == 0);
                    const atomic_t<integer_p> atom(random_a);
                    CHECK(+atom == +random_a);
                    if constexpr (integer_signed_tr<integer_p>) {
                        CHECK(-atom == -random_a);
                    }
                    CHECK((atom + random_b) == (random_a + random_b));
                    CHECK((atom - random_b) == (random_a - random_b));
                    CHECK((atom * random_b) == (random_a * random_b));
                    CHECK((atom / random_b) == (random_a / random_b));
                    CHECK((atom % random_b) == (random_a % random_b));
                }
                /// [_4556d7de_1819_44d1_854e_20884a0f1a77]

                /// [_9f4c8c8f_14dd_43cc_961d_c1d229c50bc3]
                TEST_CASE_TEMPLATE("should implicitly allow for bitwise operators", integer_p, _)
                {
                    integer_p random_a = Random<integer_p>();
                    integer_p random_b = Random<integer_p>();
                    const atomic_t<integer_p> atom(random_a);
                    CHECK(~atom == ~random_a);
                    CHECK((atom | random_b) == (random_a | random_b));
                    CHECK((atom & random_b) == (random_a & random_b));
                    CHECK((atom ^ random_b) == (random_a ^ random_b));
                    CHECK((atom << random_b) == (random_a << random_b));
                    CHECK((atom >> random_b) == (random_a >> random_b));
                }
                /// [_9f4c8c8f_14dd_43cc_961d_c1d229c50bc3]

                /// [_843f62f2_a274_4fb0_a17a_fa4b853fb4c2]
                TEST_CASE_TEMPLATE("should implicitly allow for logical operators", integer_p, _)
                {
                    integer_p random;
                    do {
                        random = Random<integer_p>();
                    } while (random == 0);
                    const atomic_t<integer_p> atom(random);
                    CHECK(atom);
                    CHECK(!!atom);
                    CHECK(atom || false);
                    CHECK(atom && true);
                    CHECK(atom ? true : false);
                }
                /// [_843f62f2_a274_4fb0_a17a_fa4b853fb4c2]

                /// [_5e48110e_487f_4ee3_b026_36f014f3b9d2]
                TEST_CASE_TEMPLATE("should implicitly allow for comparison operators", integer_p, _)
                {
                    integer_p random = Random<integer_p>();
                    const atomic_t<integer_p> atom(random);
                    CHECK(atom == random);
                    CHECK_FALSE(atom != random);
                    CHECK_FALSE(atom < random);
                    CHECK_FALSE(atom > random);
                    CHECK(atom <= random);
                    CHECK(atom >= random);
                    CHECK(atom <=> random == 0);
                }
                /// [_5e48110e_487f_4ee3_b026_36f014f3b9d2]
            }
        }

        TEST_SUITE("operators")
        {
            TEST_SUITE("()()")
            {
                /// [_94a23714_3bbf_4222_bd55_bbfcc68bf9e6]
                TEST_CASE_TEMPLATE("should return a copy of its value", integer_p, _)
                {
                    integer_p random = Random<integer_p>();
                    const atomic_t<integer_p> atom(random);
                    CHECK(atom() == random);
                }
                /// [_94a23714_3bbf_4222_bd55_bbfcc68bf9e6]

                /// [_10db8e3a_00e7_4c3d_a3b3_ab95db9c5846]
                TEST_CASE_TEMPLATE("should not change its value", integer_p, _)
                {
                    integer_p random = Random<integer_p>();
                    const atomic_t<integer_p> atom(random);
                    integer_p value = atom();
                    CHECK(atom == random);
                }
                /// [_10db8e3a_00e7_4c3d_a3b3_ab95db9c5846]
            }

            TEST_SUITE("+=()")
            {
                /// [_3bc7cbc1_a80d_41a3_92ff_ab39e2ddf0ab]
                TEST_CASE_TEMPLATE("should set its value to value + passed value", integer_p, _)
                {
                    integer_p random_a = Random<integer_p>();
                    integer_p random_b = Random<integer_p>();
                    atomic_t<integer_p> atom(random_a);
                    atom += random_b;
                    CHECK(atom == (random_a += random_b));
                }
                /// [_3bc7cbc1_a80d_41a3_92ff_ab39e2ddf0ab]

                /// [_85454b3e_106a_4e15_bc02_36587b2234dd]
                TEST_CASE_TEMPLATE("should return itself", integer_p, _)
                {
                    integer_p random_a = Random<integer_p>();
                    integer_p random_b = Random<integer_p>();
                    atomic_t<integer_p> atom(random_a);
                    CHECK(&(atom += random_b) == &atom);
                }
                /// [_85454b3e_106a_4e15_bc02_36587b2234dd]

                /// [_178f7dfa_1fd5_4c0d_b116_32dceff97856]
                TEST_CASE_TEMPLATE("should work with types convertible to its value_t", integer_p, _)
                {
                    integer_p random_a = Random<integer_p>();
                    real_t random_b = Random<real_t>();
                    atomic_t<integer_p> atom(random_a);
                    atom += random_b;
                    CHECK(atom == (random_a += static_cast<integer_p>(random_b)));
                }
                /// [_178f7dfa_1fd5_4c0d_b116_32dceff97856]
            }

            TEST_SUITE("-=()")
            {
                /// [_6b7bb56b_bbf8_4088_a135_f8e5275187bc]
                TEST_CASE_TEMPLATE("should set its value to value - passed value", integer_p, _)
                {
                    integer_p random_a = Random<integer_p>();
                    integer_p random_b = Random<integer_p>();
                    atomic_t<integer_p> atom(random_a);
                    atom -= random_b;
                    CHECK(atom == (random_a -= random_b));
                }
                /// [_6b7bb56b_bbf8_4088_a135_f8e5275187bc]

                /// [_22def221_d510_4b3f_b462_3eea759ef816]
                TEST_CASE_TEMPLATE("should return itself", integer_p, _)
                {
                    integer_p random_a = Random<integer_p>();
                    integer_p random_b = Random<integer_p>();
                    atomic_t<integer_p> atom(random_a);
                    CHECK(&(atom -= random_b) == &atom);
                }
                /// [_22def221_d510_4b3f_b462_3eea759ef816]

                /// [_36c853e7_6e7f_4f55_9ba5_2dd6481dce80]
                TEST_CASE_TEMPLATE("should work with types convertible to its value_t", integer_p, _)
                {
                    integer_p random_a = Random<integer_p>();
                    real_t random_b = Random<real_t>();
                    atomic_t<integer_p> atom(random_a);
                    atom -= random_b;
                    CHECK(atom == (random_a -= static_cast<integer_p>(random_b)));
                }
                /// [_36c853e7_6e7f_4f55_9ba5_2dd6481dce80]
            }

            TEST_SUITE("*=()")
            {
                /// [_8f85ea2e_1025_4789_a379_6b6c408b5f71]
                TEST_CASE_TEMPLATE("should set its value to value * passed value", integer_p, _)
                {
                    integer_p random_a = Random<integer_p>();
                    integer_p random_b = Random<integer_p>();
                    atomic_t<integer_p> atom(random_a);
                    atom *= random_b;
                    CHECK(atom == (random_a *= random_b));
                }
                /// [_8f85ea2e_1025_4789_a379_6b6c408b5f71]

                /// [_040cd689_01ff_4731_853e_88efaa46c5eb]
                TEST_CASE_TEMPLATE("should return itself", integer_p, _)
                {
                    integer_p random_a = Random<integer_p>();
                    integer_p random_b = Random<integer_p>();
                    atomic_t<integer_p> atom(random_a);
                    CHECK(&(atom *= random_b) == &atom);
                }
                /// [_040cd689_01ff_4731_853e_88efaa46c5eb]

                /// [_b0a13506_36d2_4718_a336_4c01e50bc714]
                TEST_CASE_TEMPLATE("should work with types convertible to its value_t", integer_p, _)
                {
                    integer_p random_a = Random<integer_p>();
                    real_t random_b = Random<real_t>();
                    atomic_t<integer_p> atom(random_a);
                    atom *= random_b;
                    CHECK(atom == (random_a *= static_cast<integer_p>(random_b)));
                }
                /// [_b0a13506_36d2_4718_a336_4c01e50bc714]
            }

            TEST_SUITE("/=()")
            {
                /// [_01d8f79c_e4bf_47db_b87a_13f79ad1464e]
                TEST_CASE_TEMPLATE("should set its value to value / passed value", integer_p, _)
                {
                    integer_p random_a = Random<integer_p>();
                    integer_p random_b;
                    do {
                        random_b = Random<integer_p>();
                    } while (random_b == 0);
                    atomic_t<integer_p> atom(random_a);
                    atom /= random_b;
                    CHECK(atom == (random_a /= random_b));
                }
                /// [_01d8f79c_e4bf_47db_b87a_13f79ad1464e]

                /// [_17d85d03_3e46_4b65_8226_696aa1f9d48b]
                TEST_CASE_TEMPLATE("should return itself", integer_p, _)
                {
                    integer_p random_a = Random<integer_p>();
                    integer_p random_b;
                    do {
                        random_b = Random<integer_p>();
                    } while (random_b == 0);
                    atomic_t<integer_p> atom(random_a);
                    CHECK(&(atom /= random_b) == &atom);
                }
                /// [_17d85d03_3e46_4b65_8226_696aa1f9d48b]

                /// [_56ffdd82_fd0b_43a2_868a_463a4401f029]
                TEST_CASE_TEMPLATE("should work with types convertible to its value_t", integer_p, _)
                {
                    integer_p random_a = Random<integer_p>();
                    real_t random_b;
                    do {
                        random_b = Random<real_t>(std::numeric_limits<integer_p>::lowest(),
                                                  std::numeric_limits<integer_p>::max());
                    } while (static_cast<integer_p>(random_b) == 0);
                    atomic_t<integer_p> atom(random_a);
                    atom /= random_b;
                    CHECK(atom == (random_a /= static_cast<integer_p>(random_b)));
                }
                /// [_56ffdd82_fd0b_43a2_868a_463a4401f029]
            }

            TEST_SUITE("%=()")
            {
                /// [_aeb1e694_f9fd_4707_8686_33c8855253d5]
                TEST_CASE_TEMPLATE("should set its value to value % passed value", integer_p, _)
                {
                    integer_p random_a = Random<integer_p>();
                    integer_p random_b;
                    do {
                        random_b = Random<integer_p>();
                    } while (random_b == 0);
                    atomic_t<integer_p> atom(random_a);
                    atom %= random_b;
                    CHECK(atom == (random_a %= random_b));
                }
                /// [_aeb1e694_f9fd_4707_8686_33c8855253d5]

                /// [_2834d744_2c14_4f3b_8ad6_6503536cf990]
                TEST_CASE_TEMPLATE("should return itself", integer_p, _)
                {
                    integer_p random_a = Random<integer_p>();
                    integer_p random_b;
                    do {
                        random_b = Random<integer_p>();
                    } while (random_b == 0);
                    atomic_t<integer_p> atom(random_a);
                    CHECK(&(atom %= random_b) == &atom);
                }
                /// [_2834d744_2c14_4f3b_8ad6_6503536cf990]
            }

            TEST_SUITE("|=()")
            {
                /// [_6cd16c72_5b92_471f_945d_f2aed858532c]
                TEST_CASE_TEMPLATE("should set its value to value | passed value", integer_p, _)
                {
                    integer_p random_a = Random<integer_p>();
                    integer_p random_b = Random<integer_p>();
                    atomic_t<integer_p> atom(random_a);
                    atom |= random_b;
                    CHECK(atom == (random_a |= random_b));
                }
                /// [_6cd16c72_5b92_471f_945d_f2aed858532c]

                /// [_e70ff06d_bf2c_4da0_a5f0_8cc68319a6a5]
                TEST_CASE_TEMPLATE("should return itself", integer_p, _)
                {
                    integer_p random_a = Random<integer_p>();
                    integer_p random_b = Random<integer_p>();
                    atomic_t<integer_p> atom(random_a);
                    CHECK(&(atom |= random_b) == &atom);
                }
                /// [_e70ff06d_bf2c_4da0_a5f0_8cc68319a6a5]
            }

            TEST_SUITE("&=()")
            {
                /// [_06cdfcfd_62a3_4442_b6d8_fd9ca3a9af8e]
                TEST_CASE_TEMPLATE("should set its value to value & passed value", integer_p, _)
                {
                    integer_p random_a = Random<integer_p>();
                    integer_p random_b = Random<integer_p>();
                    atomic_t<integer_p> atom(random_a);
                    atom &= random_b;
                    CHECK(atom == (random_a &= random_b));
                }
                /// [_06cdfcfd_62a3_4442_b6d8_fd9ca3a9af8e]

                /// [_c55162a7_2c7c_4e7c_97f4_92ef8f4483a5]
                TEST_CASE_TEMPLATE("should return itself", integer_p, _)
                {
                    integer_p random_a = Random<integer_p>();
                    integer_p random_b = Random<integer_p>();
                    atomic_t<integer_p> atom(random_a);
                    CHECK(&(atom &= random_b) == &atom);
                }
                /// [_c55162a7_2c7c_4e7c_97f4_92ef8f4483a5]
            }

            TEST_SUITE("^=()")
            {
                /// [_b78b363b_e21a_4f27_a0d9_fa83a3bda86c]
                TEST_CASE_TEMPLATE("should set its value to value ^ passed value", integer_p, _)
                {
                    integer_p random_a = Random<integer_p>();
                    integer_p random_b = Random<integer_p>();
                    atomic_t<integer_p> atom(random_a);
                    atom ^= random_b;
                    CHECK(atom == (random_a ^= random_b));
                }
                /// [_b78b363b_e21a_4f27_a0d9_fa83a3bda86c]

                /// [_c14ff81d_2486_4e45_b1be_e47c3805333f]
                TEST_CASE_TEMPLATE("should return itself", integer_p, _)
                {
                    integer_p random_a = Random<integer_p>();
                    integer_p random_b = Random<integer_p>();
                    atomic_t<integer_p> atom(random_a);
                    CHECK(&(atom ^= random_b) == &atom);
                }
                /// [_c14ff81d_2486_4e45_b1be_e47c3805333f]
            }

            TEST_SUITE("<<=()")
            {
                /// [_00f72b33_e5d1_4eef_982b_e35fa4246a6b]
                TEST_CASE_TEMPLATE("should set its value to value << passed value", integer_p, _)
                {
                    integer_p random_a = Random<integer_p>();
                    integer_p random_b = Random<integer_p>();
                    atomic_t<integer_p> atom(random_a);
                    atom <<= random_b;
                    CHECK(atom == (random_a <<= random_b));
                }
                /// [_00f72b33_e5d1_4eef_982b_e35fa4246a6b]

                /// [_3686c835_89ae_47f7_8f54_6c85d959e8de]
                TEST_CASE_TEMPLATE("should return itself", integer_p, _)
                {
                    integer_p random_a = Random<integer_p>();
                    integer_p random_b = Random<integer_p>();
                    atomic_t<integer_p> atom(random_a);
                    CHECK(&(atom <<= random_b) == &atom);
                }
                /// [_3686c835_89ae_47f7_8f54_6c85d959e8de]
            }

            TEST_SUITE(">>=()")
            {
                /// [_98811442_5cca_4d8f_ba9d_722c11f2a694]
                TEST_CASE_TEMPLATE("should set its value to value >> passed value", integer_p, _)
                {
                    integer_p random_a = Random<integer_p>();
                    integer_p random_b = Random<integer_p>();
                    atomic_t<integer_p> atom(random_a);
                    atom >>= random_b;
                    CHECK(atom == (random_a >>= random_b));
                }
                /// [_98811442_5cca_4d8f_ba9d_722c11f2a694]

                /// [_8e89b2a7_8897_4892_9684_4f90a38c4113]
                TEST_CASE_TEMPLATE("should return itself", integer_p, _)
                {
                    integer_p random_a = Random<integer_p>();
                    integer_p random_b = Random<integer_p>();
                    atomic_t<integer_p> atom(random_a);
                    CHECK(&(atom >>= random_b) == &atom);
                }
                /// [_8e89b2a7_8897_4892_9684_4f90a38c4113]
            }

            TEST_SUITE("++()")
            {
                /// [_cb9f4aed_9aeb_4897_bc54_3ee3f27b27ef]
                TEST_CASE_TEMPLATE("should set its value to value + 1", integer_p, _)
                {
                    integer_p random = Random<integer_p>();
                    atomic_t<integer_p> atom(random);
                    ++atom;
                    CHECK(atom == (random += 1));
                }
                /// [_cb9f4aed_9aeb_4897_bc54_3ee3f27b27ef]

                /// [_9fd0cad2_0392_4026_b4b4_591605459477]
                TEST_CASE_TEMPLATE("should return itself", integer_p, _)
                {
                    integer_p random = Random<integer_p>();
                    atomic_t<integer_p> atom(random);
                    CHECK(&(++atom) == &atom);
                }
                /// [_9fd0cad2_0392_4026_b4b4_591605459477]
            }

            TEST_SUITE("++(int)")
            {
                /// [_d0f274a9_d47f_408b_bf08_3176738e2f4f]
                TEST_CASE_TEMPLATE("should set its value to value + 1", integer_p, _)
                {
                    integer_p random = Random<integer_p>();
                    atomic_t<integer_p> atom(random);
                    atom++;
                    CHECK(atom == (random += 1));
                }
                /// [_d0f274a9_d47f_408b_bf08_3176738e2f4f]

                /// [_204d87e1_da21_414b_bb35_023bf23db1fb]
                TEST_CASE_TEMPLATE("should return its old value", integer_p, _)
                {
                    integer_p random = Random<integer_p>();
                    atomic_t<integer_p> atom(random);
                    CHECK(atom++ == random);
                }
                /// [_204d87e1_da21_414b_bb35_023bf23db1fb]
            }

            TEST_SUITE("--()")
            {
                /// [_98acc80e_1a9e_455f_8d97_733f3189aedf]
                TEST_CASE_TEMPLATE("should set its value to value - 1", integer_p, _)
                {
                    integer_p random = Random<integer_p>();
                    atomic_t<integer_p> atom(random);
                    --atom;
                    CHECK(atom == (random -= 1));
                }
                /// [_98acc80e_1a9e_455f_8d97_733f3189aedf]

                /// [_b8dce600_3c99_440c_aee4_f9de4ec598c3]
                TEST_CASE_TEMPLATE("should return itself", integer_p, _)
                {
                    integer_p random = Random<integer_p>();
                    atomic_t<integer_p> atom(random);
                    CHECK(&(--atom) == &atom);
                }
                /// [_b8dce600_3c99_440c_aee4_f9de4ec598c3]
            }

            TEST_SUITE("--(int)")
            {
                /// [_d0304055_d61d_4242_b5f5_94dc3248519a]
                TEST_CASE_TEMPLATE("should set its value to value - 1", integer_p, _)
                {
                    integer_p random = Random<integer_p>();
                    atomic_t<integer_p> atom(random);
                    atom--;
                    CHECK(atom == (random -= 1));
                }
                /// [_d0304055_d61d_4242_b5f5_94dc3248519a]

                /// [_35e5d5b0_c2c3_42d7_aedb_830835227973]
                TEST_CASE_TEMPLATE("should return its old value", integer_p, _)
                {
                    integer_p random = Random<integer_p>();
                    atomic_t<integer_p> atom(random);
                    CHECK(atom-- == random);
                }
                /// [_35e5d5b0_c2c3_42d7_aedb_830835227973]
            }
        }

        TEST_SUITE("none_t interface")
        {
            TEST_SUITE("none_ctor()")
            {
                /// [_5db65d8c_40c3_404b_9dd1_551027c58e2e]
                TEST_CASE_TEMPLATE("should explicitly set its value to the default value", integer_p, _)
                {
                    atomic_t<integer_p> atom((none_t()));
                    CHECK(atom == atomic_t<integer_p>::DEFAULT_VALUE);
                }
                /// [_5db65d8c_40c3_404b_9dd1_551027c58e2e]

                /// [_3d39a2e0_f493_4803_9440_22596a1c87b0]
                TEST_CASE_TEMPLATE("should implicitly set its value to the default value", integer_p, _)
                {
                    atomic_t<integer_p> atom = none_t();
                    CHECK(atom == atomic_t<integer_p>::DEFAULT_VALUE);
                }
                /// [_3d39a2e0_f493_4803_9440_22596a1c87b0]
            }

            TEST_SUITE("=(none_t)")
            {
                /// [_c16b07a4_a8d5_4f6a_847c_27997f0c9e79]
                TEST_CASE_TEMPLATE("should set its value to the default value", integer_p, _)
                {
                    integer_p random = Random<integer_p>();
                    atomic_t<integer_p> atom(random);
                    atom = none_t();
                    CHECK(atom == atomic_t<integer_p>::DEFAULT_VALUE);
                }
                /// [_c16b07a4_a8d5_4f6a_847c_27997f0c9e79]

                /// [_300e2a41_fb60_4e74_86c1_37c2a2fe8b6d]
                TEST_CASE_TEMPLATE("should evaluate as false after being set to none", integer_p, _)
                {
                    integer_p random = Random<integer_p>();
                    atomic_t<integer_p> atom(random);
                    atom = none_t();
                    CHECK(static_cast<bool_t>(atom) == false);
                }
                /// [_300e2a41_fb60_4e74_86c1_37c2a2fe8b6d]

                /// [_bdde2efb_2a97_4dbb_b77b_81a5c372b1e2]
                TEST_CASE_TEMPLATE("should return itself", integer_p, _)
                {
                    integer_p random = Random<integer_p>();
                    atomic_t<integer_p> atom(random);
                    CHECK(&(atom = none_t()) == &atom);
                }
                /// [_bdde2efb_2a97_4dbb_b77b_81a5c372b1e2]
            }

            TEST_SUITE("==(none_t)")
            {
                /// [_43bd17fd_64d9_4885_84d4_fcf3f4cc278c]
                TEST_CASE_TEMPLATE("should return true when default constructed", integer_p, _)
                {
                    const atomic_t<integer_p> atom;
                    CHECK(atom == none_t());
                }
                /// [_43bd17fd_64d9_4885_84d4_fcf3f4cc278c]

                /// [_c40ff438_be6d_4a2a_9d07_6e161ef03359]
                TEST_CASE_TEMPLATE("should return true if its value is 0", integer_p, _)
                {
                    const atomic_t<integer_p> atom(0);
                    CHECK(atom == none_t());
                }
                /// [_c40ff438_be6d_4a2a_9d07_6e161ef03359]

                /// [_a0ef3be2_a881_4775_9f04_bcf9b86be598]
                TEST_CASE_TEMPLATE("should return false if its value is above 0", integer_p, _)
                {
                    integer_p random = Random<integer_p>(1, std::numeric_limits<integer_p>::max());
                    const atomic_t<integer_p> atom(random);
                    CHECK_FALSE(atom == none_t());
                }
                /// [_a0ef3be2_a881_4775_9f04_bcf9b86be598]

                /// [_a2dab8c8_a4e1_40f1_ae09_0e1f3a6a5695]
                TEST_CASE_TEMPLATE("should return false if its value is below 0", integer_p, _)
                {
                    if constexpr (integer_signed_tr<integer_p>) {
                        integer_p random = Random<integer_p>(-std::numeric_limits<integer_p>::max(), -1);
                        const atomic_t<integer_p> atom(random);
                        CHECK_FALSE(atom == none_t());
                    }
                }
                /// [_a2dab8c8_a4e1_40f1_ae09_0e1f3a6a5695]

                /// [_e35b005c_0f9a_45f2_ba02_3c7beac38af8]
                TEST_CASE_TEMPLATE("should not change its value", integer_p, _)
                {
                    integer_p random = Random<integer_p>();
                    const atomic_t<integer_p> atom(random);
                    atom == none_t();
                    CHECK(atom == random);
                }
                /// [_e35b005c_0f9a_45f2_ba02_3c7beac38af8]
            }

            TEST_SUITE("!=(none_t)")
            {
                /// [_57e08d9c_0e68_4192_ab2f_d400205d579e]
                TEST_CASE_TEMPLATE("should return false when default constructed", integer_p, _)
                {
                    const atomic_t<integer_p> atom;
                    CHECK_FALSE(atom != none_t());
                }
                /// [_57e08d9c_0e68_4192_ab2f_d400205d579e]

                /// [_fc89b5ff_5e8d_4e4c_af31_b035bd63ab16]
                TEST_CASE_TEMPLATE("should return false if its value is 0", integer_p, _)
                {
                    const atomic_t<integer_p> atom(0);
                    CHECK_FALSE(atom != none_t());
                }
                /// [_fc89b5ff_5e8d_4e4c_af31_b035bd63ab16]

                /// [_42ccaf5a_81de_485b_852b_c44d3a0107a0]
                TEST_CASE_TEMPLATE("should return true if its value is above 0", integer_p, _)
                {
                    integer_p random = Random<integer_p>(1, std::numeric_limits<integer_p>::max());
                    const atomic_t<integer_p> atom(random);
                    CHECK(atom != none_t());
                }
                /// [_42ccaf5a_81de_485b_852b_c44d3a0107a0]

                /// [_d74c418a_9dd5_4b7d_a47b_342db8247e85]
                TEST_CASE_TEMPLATE("should return true if its value is below 0.0", integer_p, _)
                {
                    if constexpr (integer_signed_tr<integer_p>) {
                        integer_p random = Random<integer_p>(-std::numeric_limits<integer_p>::max(), -1);
                        const atomic_t<integer_p> atom(random);
                        CHECK(atom != none_t());
                    }
                }
                /// [_d74c418a_9dd5_4b7d_a47b_342db8247e85]

                /// [_2484fbc5_bdfb_45c1_a7f7_e04512f53b6e]
                TEST_CASE_TEMPLATE("should not change its value", integer_p, _)
                {
                    integer_p random = Random<integer_p>();
                    const atomic_t<integer_p> atom(random);
                    atom != none_t();
                    CHECK(atom == random);
                }
                /// [_2484fbc5_bdfb_45c1_a7f7_e04512f53b6e]
            }
        }

    #undef _
    }

}
