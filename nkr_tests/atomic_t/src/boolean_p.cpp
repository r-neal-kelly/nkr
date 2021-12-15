/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/atomic_t.h"
#include "nkr/intrinsics.h"
#include "nkr/utils.h"

#include "doctest.h"

namespace nkr {

    TEST_SUITE("atomic_t<boolean_tr boolean_p>")
    {
    #define _               \
        bool_t, c_bool_t

        TEST_SUITE("bases")
        {
            TEST_SUITE("bool_deleted_operators_t")
            {
                /// [_2d1971b2_b6b3_469d_9dab_8654706a233a]
                TEST_CASE_TEMPLATE("should have no unwanted operators", boolean_p, _)
                {
                    CHECK(has_bool_deleted_operator_tr<atomic_t<boolean_p>> == false);
                }
                /// [_2d1971b2_b6b3_469d_9dab_8654706a233a]
            }
        }

        TEST_SUITE("aliases")
        {
            TEST_SUITE("value_t")
            {
                /// [_1759dcaf_066e_4b11_b18b_294d3b88ff6d]
                TEST_CASE_TEMPLATE("should equal the passed in type", boolean_p, _)
                {
                    static_assert(is_tr<atomic_t<boolean_p>::value_t, boolean_p>);
                }
                /// [_1759dcaf_066e_4b11_b18b_294d3b88ff6d]
            }
        }

        TEST_SUITE("static data")
        {
            TEST_SUITE("DEFAULT_VALUE")
            {
                /// [_3c574cf8_06a2_4305_8d63_76bcf586eeed]
                TEST_CASE_TEMPLATE("should equal the default value of value_t", boolean_p, _)
                {
                    CHECK(atomic_t<boolean_p>::DEFAULT_VALUE == atomic_t<boolean_p>::value_t());
                }
                /// [_3c574cf8_06a2_4305_8d63_76bcf586eeed]

                /// [_196d084d_d553_43bc_bd76_617903f70495]
                TEST_CASE_TEMPLATE("should equal false", boolean_p, _)
                {
                    CHECK(atomic_t<boolean_p>::DEFAULT_VALUE == false);
                }
                /// [_196d084d_d553_43bc_bd76_617903f70495]
            }
        }

        TEST_SUITE("object data")
        {
            TEST_SUITE("value")
            {
                /// [_424711d2_5319_4b78_85a0_e3d6f4927510]
                TEST_CASE_TEMPLATE("should be a volatile value_t", boolean_p, _)
                {
                    static_assert(is_tr<decltype(atomic_t<boolean_p>::value), volatile boolean_p>);
                }
                /// [_424711d2_5319_4b78_85a0_e3d6f4927510]
            }
        }

        TEST_SUITE("objects")
        {
            TEST_SUITE("default_ctor()")
            {
                /// [_5feb52e1_3500_4943_838a_965319fcd4fd]
                TEST_CASE_TEMPLATE("should set value to the default", boolean_p, _)
                {
                    atomic_t<boolean_p> atom;
                    CHECK(atom == atomic_t<boolean_p>::DEFAULT_VALUE);
                }
                /// [_5feb52e1_3500_4943_838a_965319fcd4fd]
            }

            TEST_SUITE("value_ctor()")
            {
                /// [_709876c6_6522_45c9_b3de_3b8bcd997dcd]
                TEST_CASE_TEMPLATE("should explicitly set passed value", boolean_p, _)
                {
                    boolean_p random = Random<boolean_p>();
                    atomic_t<boolean_p> atom(random);
                    CHECK(atom == random);
                }
                /// [_709876c6_6522_45c9_b3de_3b8bcd997dcd]

                /// [_10e6860c_66d3_47e2_8178_bd913bc7f839]
                TEST_CASE_TEMPLATE("should implicitly set passed value", boolean_p, _)
                {
                    boolean_p random = Random<boolean_p>();
                    atomic_t<boolean_p> atom = random;
                    CHECK(atom == random);
                }
                /// [_10e6860c_66d3_47e2_8178_bd913bc7f839]

                /// [_f0e19280_dd98_4b75_bf72_050f906dbc10]
                TEST_CASE_TEMPLATE("should convert other types and set passed value", boolean_p, _)
                {
                    word_t random = Random<word_t>();
                    atomic_t<boolean_p> atom(random);
                    CHECK(atom == static_cast<boolean_p>(random));
                }
                /// [_f0e19280_dd98_4b75_bf72_050f906dbc10]
            }

            TEST_SUITE("copy_ctor()")
            {
                /// [_fa5a2f83_fabe_4070_ae17_d7e5f20728ce]
                TEST_CASE_TEMPLATE("should explicitly copy the value of other", boolean_p, _)
                {
                    boolean_p random = Random<boolean_p>();
                    const atomic_t<boolean_p> other(random);
                    atomic_t<boolean_p> atom(other);
                    CHECK(atom == random);
                }
                /// [_fa5a2f83_fabe_4070_ae17_d7e5f20728ce]

                /// [_37b15a52_28a2_4e8a_927c_0c3b68e90696]
                TEST_CASE_TEMPLATE("should implicitly copy the value of other", boolean_p, _)
                {
                    boolean_p random = Random<boolean_p>();
                    const atomic_t<boolean_p> other(random);
                    atomic_t<boolean_p> atom = other;
                    CHECK(atom == random);
                }
                /// [_37b15a52_28a2_4e8a_927c_0c3b68e90696]

                /// [_61d40544_3160_4784_bdfc_a571d1e0d159]
                TEST_CASE_TEMPLATE("should not alter the value of other", boolean_p, _)
                {
                    boolean_p random = Random<boolean_p>();
                    const atomic_t<boolean_p> other(random);
                    atomic_t<boolean_p> atom(other);
                    CHECK(other == random);
                }
                /// [_61d40544_3160_4784_bdfc_a571d1e0d159]
            }

            TEST_SUITE("move_ctor()")
            {
                /// [_058e2373_0770_4779_8121_a285dd5ec20b]
                TEST_CASE_TEMPLATE("should explicitly move the value of other", boolean_p, _)
                {
                    boolean_p random = Random<boolean_p>();
                    atomic_t<boolean_p> other(random);
                    atomic_t<boolean_p> atom(nkr::Move(other));
                    CHECK(atom == random);
                }
                /// [_058e2373_0770_4779_8121_a285dd5ec20b]

                /// [_126072fd_aad9_40b6_914d_1972c77f1405]
                TEST_CASE_TEMPLATE("should implicitly move the value of other", boolean_p, _)
                {
                    boolean_p random = Random<boolean_p>();
                    atomic_t<boolean_p> other(random);
                    atomic_t<boolean_p> atom = nkr::Move(other);
                    CHECK(atom == random);
                }
                /// [_126072fd_aad9_40b6_914d_1972c77f1405]

                /// [_9002eaf6_3a96_411b_858a_09f20ca48445]
                TEST_CASE_TEMPLATE("should set the value of other to the default", boolean_p, _)
                {
                    boolean_p random = Random<boolean_p>();
                    atomic_t<boolean_p> other(random);
                    atomic_t<boolean_p> atom(nkr::Move(other));
                    CHECK(other == atomic_t<boolean_p>::DEFAULT_VALUE);
                }
                /// [_9002eaf6_3a96_411b_858a_09f20ca48445]
            }

            TEST_SUITE("value_assignment_ctor()")
            {
                /// [_a24433b9_3d9f_4a7a_a574_fc779332d278]
                TEST_CASE_TEMPLATE("should set passed value", boolean_p, _)
                {
                    boolean_p random = Random<boolean_p>();
                    atomic_t<boolean_p> atom;
                    atom = random;
                    CHECK(atom == random);
                }
                /// [_a24433b9_3d9f_4a7a_a574_fc779332d278]

                /// [_ed95825c_4552_48d1_b5f7_4a12d62b473a]
                TEST_CASE_TEMPLATE("should return itself", boolean_p, _)
                {
                    boolean_p random = Random<boolean_p>();
                    atomic_t<boolean_p> atom;
                    CHECK(&(atom = random) == &atom);
                }
                /// [_ed95825c_4552_48d1_b5f7_4a12d62b473a]

                /// [_77aec4fc_6fdd_4dfd_81a4_1edcea184f73]
                TEST_CASE_TEMPLATE("should convert other types and set passed value", boolean_p, _)
                {
                    word_t random = Random<word_t>();
                    atomic_t<boolean_p> atom;
                    atom = random;
                    CHECK(atom == static_cast<boolean_p>(random));
                }
                /// [_77aec4fc_6fdd_4dfd_81a4_1edcea184f73]
            }

            TEST_SUITE("copy_assignment_ctor()")
            {
                /// [_4267a075_2d1a_4aed_b149_3e94d0db9b00]
                TEST_CASE_TEMPLATE("should copy the value of other", boolean_p, _)
                {
                    boolean_p random = Random<boolean_p>();
                    const atomic_t<boolean_p> other(random);
                    atomic_t<boolean_p> atom;
                    atom = other;
                    CHECK(atom == random);
                }
                /// [_4267a075_2d1a_4aed_b149_3e94d0db9b00]

                /// [_3a9ecfe2_0f60_4735_9812_bcaf283ab555]
                TEST_CASE_TEMPLATE("should return itself", boolean_p, _)
                {
                    boolean_p random = Random<boolean_p>();
                    const atomic_t<boolean_p> other(random);
                    atomic_t<boolean_p> atom;
                    CHECK(&(atom = other) == &atom);
                }
                /// [_3a9ecfe2_0f60_4735_9812_bcaf283ab555]

                /// [_33336292_ab12_4b6d_9c38_d331d2bb17bc]
                TEST_CASE_TEMPLATE("should not alter the value of other", boolean_p, _)
                {
                    boolean_p random = Random<boolean_p>();
                    const atomic_t<boolean_p> other(random);
                    atomic_t<boolean_p> atom;
                    atom = other;
                    CHECK(other == random);
                }
                /// [_33336292_ab12_4b6d_9c38_d331d2bb17bc]
            }

            TEST_SUITE("move_assignment_ctor()")
            {
                /// [_9126fa91_1613_4c39_aa73_0383e6b594e3]
                TEST_CASE_TEMPLATE("should move the value of other", boolean_p, _)
                {
                    boolean_p random = Random<boolean_p>();
                    atomic_t<boolean_p> other(random);
                    atomic_t<boolean_p> atom;
                    atom = nkr::Move(other);
                    CHECK(atom == random);
                }
                /// [_9126fa91_1613_4c39_aa73_0383e6b594e3]

                /// [_669d3937_13ea_47c6_b239_4d76976572e5]
                TEST_CASE_TEMPLATE("should return itself", boolean_p, _)
                {
                    boolean_p random = Random<boolean_p>();
                    atomic_t<boolean_p> other(random);
                    atomic_t<boolean_p> atom;
                    CHECK(&(atom = nkr::Move(other)) == &atom);
                }
                /// [_669d3937_13ea_47c6_b239_4d76976572e5]

                /// [_88a7e1bc_ae69_4890_aa29_9f8189297093]
                TEST_CASE_TEMPLATE("should set the value of other to the default", boolean_p, _)
                {
                    boolean_p random = Random<boolean_p>();
                    atomic_t<boolean_p> other(random);
                    atomic_t<boolean_p> atom;
                    atom = nkr::Move(other);
                    CHECK(other == atomic_t<boolean_p>::DEFAULT_VALUE);
                }
                /// [_88a7e1bc_ae69_4890_aa29_9f8189297093]
            }

            TEST_SUITE("dtor()")
            {
                /// [_c71c4f3b_b2ee_40f0_b750_124fbd7c5c52]
                TEST_CASE_TEMPLATE("should set its value to the default", boolean_p, _)
                {
                    boolean_p random = Random<boolean_p>();
                    atomic_t<boolean_p> atom(random);
                    atom.~atomic_t();
                    CHECK(atom == atomic_t<boolean_p>::DEFAULT_VALUE);
                }
                /// [_c71c4f3b_b2ee_40f0_b750_124fbd7c5c52]
            }
        }

        TEST_SUITE("methods")
        {
            TEST_SUITE("Access()")
            {
                /// [_3cf51411_c7e9_410b_9a0f_6d87a962b29d]
                TEST_CASE_TEMPLATE("should return its value", boolean_p, _)
                {
                    boolean_p random = Random<boolean_p>();
                    const atomic_t<boolean_p> atom(random);
                    CHECK(atom.Access() == random);
                }
                /// [_3cf51411_c7e9_410b_9a0f_6d87a962b29d]

                /// [_c80bcc87_40ab_4ce5_871f_08f3517b640e]
                TEST_CASE_TEMPLATE("should not change its value", boolean_p, _)
                {
                    boolean_p random = Random<boolean_p>();
                    const atomic_t<boolean_p> atom(random);
                    atom.Access();
                    CHECK(atom == random);
                }
                /// [_c80bcc87_40ab_4ce5_871f_08f3517b640e]
            }

            TEST_SUITE("Assign()")
            {
                /// [_20335514_31fd_467d_a7d0_cad170e33b6b]
                TEST_CASE_TEMPLATE("should set its value to the passed value", boolean_p, _)
                {
                    boolean_p random_a = Random<boolean_p>();
                    boolean_p random_b = Random<boolean_p>();
                    atomic_t<boolean_p> atom(random_a);
                    atom.Assign(random_b);
                    CHECK(atom == random_b);
                }
                /// [_20335514_31fd_467d_a7d0_cad170e33b6b]

                /// [_448d3d5b_3cf4_45b8_9223_72de45840db9]
                TEST_CASE_TEMPLATE("should return the new value", boolean_p, _)
                {
                    boolean_p random_a = Random<boolean_p>();
                    boolean_p random_b = Random<boolean_p>();
                    atomic_t<boolean_p> atom(random_a);
                    CHECK(atom.Assign(random_b) == random_b);
                }
                /// [_448d3d5b_3cf4_45b8_9223_72de45840db9]

                /// [_11fea6c1_9596_4281_8fe8_0f7c0ec27338]
                TEST_CASE_TEMPLATE("should work with types convertible to its value_t", boolean_p, _)
                {
                    boolean_p random_a = Random<boolean_p>();
                    word_t random_b = Random<word_t>();
                    atomic_t<boolean_p> atom(random_a);
                    atom.Assign(random_b);
                    CHECK(atom == static_cast<boolean_p>(random_b));
                }
                /// [_11fea6c1_9596_4281_8fe8_0f7c0ec27338]
            }

            TEST_SUITE("Exchange()")
            {
                /// [_9e3909af_6374_4ca4_81de_17f134d4e10f]
                TEST_CASE_TEMPLATE("should set its value to the passed value", boolean_p, _)
                {
                    boolean_p random_a = Random<boolean_p>();
                    boolean_p random_b = Random<boolean_p>();
                    atomic_t<boolean_p> atom(random_a);
                    atom.Exchange(random_b);
                    CHECK(atom == random_b);
                }
                /// [_9e3909af_6374_4ca4_81de_17f134d4e10f]

                /// [_6c2ef00f_36d7_411f_95cd_e8ec20f937bc]
                TEST_CASE_TEMPLATE("should return its old value", boolean_p, _)
                {
                    boolean_p random_a = Random<boolean_p>();
                    boolean_p random_b = Random<boolean_p>();
                    atomic_t<boolean_p> atom(random_a);
                    CHECK(atom.Exchange(random_b) == random_a);
                }
                /// [_6c2ef00f_36d7_411f_95cd_e8ec20f937bc]

                /// [_ea66d530_0cc2_49b8_abb3_2b1e40a8088c]
                TEST_CASE_TEMPLATE("should work with types convertible to its value_t", boolean_p, _)
                {
                    boolean_p random_a = Random<boolean_p>();
                    word_t random_b = Random<word_t>();
                    atomic_t<boolean_p> atom(random_a);
                    atom.Exchange(random_b);
                    CHECK(atom == static_cast<boolean_p>(random_b));
                }
                /// [_ea66d530_0cc2_49b8_abb3_2b1e40a8088c]
            }

            TEST_SUITE("Exchange_If_Equals()")
            {
                /// [_3c54cae1_a208_4fbb_8e0b_7360a98e5639]
                TEST_CASE_TEMPLATE("should set its value to the passed value if its value equals the snapshot", boolean_p, _)
                {
                    boolean_p random = Random<boolean_p>();
                    atomic_t<boolean_p> atom(random);
                    boolean_p snapshot = atom;
                    atom.Exchange_If_Equals(snapshot, !random);
                    CHECK(atom == static_cast<boolean_p>(!random));
                }
                /// [_3c54cae1_a208_4fbb_8e0b_7360a98e5639]

                /// [_e34dbaa9_0a76_4d71_8868_a0b1e130d9ee]
                TEST_CASE_TEMPLATE("should return true if it set the new value", boolean_p, _)
                {
                    boolean_p random = Random<boolean_p>();
                    atomic_t<boolean_p> atom(random);
                    boolean_p snapshot = atom;
                    CHECK(atom.Exchange_If_Equals(snapshot, !random) == true);
                }
                /// [_e34dbaa9_0a76_4d71_8868_a0b1e130d9ee]

                /// [_690725a9_0be2_41c4_87c6_dea6f3048a6a]
                TEST_CASE_TEMPLATE("should return false if it did not set the new value", boolean_p, _)
                {
                    boolean_p random = Random<boolean_p>();
                    atomic_t<boolean_p> atom(random);
                    boolean_p snapshot = atom;
                    atom = !random;
                    CHECK(atom.Exchange_If_Equals(snapshot, !random) == false);
                }
                /// [_690725a9_0be2_41c4_87c6_dea6f3048a6a]

                /// [_fe16376b_7163_4f9c_9899_c619642b87de]
                TEST_CASE_TEMPLATE("should leave snapshot with its old value if it succeeded", boolean_p, _)
                {
                    boolean_p random = Random<boolean_p>();
                    atomic_t<boolean_p> atom(random);
                    boolean_p snapshot = atom;
                    atom.Exchange_If_Equals(snapshot, !random);
                    CHECK(snapshot == random);
                }
                /// [_fe16376b_7163_4f9c_9899_c619642b87de]

                /// [_400f9dd8_999d_47b3_ad0a_081f65f23bdc]
                TEST_CASE_TEMPLATE("should update snapshot to its current value if it failed", boolean_p, _)
                {
                    boolean_p random = Random<boolean_p>();
                    atomic_t<boolean_p> atom(random);
                    boolean_p snapshot = atom;
                    atom = !random;
                    atom.Exchange_If_Equals(snapshot, !random);
                    CHECK(snapshot == static_cast<boolean_p>(!random));
                }
                /// [_400f9dd8_999d_47b3_ad0a_081f65f23bdc]

                /// [_60a5c29d_857c_451d_9f0a_c65b36241245]
                TEST_CASE_TEMPLATE("should work with types convertible to its value_t", boolean_p, _)
                {
                    word_t random = Random<word_t>();
                    atomic_t<boolean_p> atom(random);
                    boolean_p snapshot = atom;
                    atom.Exchange_If_Equals(snapshot, !random);
                    CHECK(atom == static_cast<boolean_p>(!random));
                }
                /// [_60a5c29d_857c_451d_9f0a_c65b36241245]
            }
        }

        TEST_SUITE("casts")
        {
            TEST_SUITE("c_bool_t()")
            {
                /// [_b9e6feaf_cbb9_49a8_b569_0719512a3f88]
                TEST_CASE_TEMPLATE("should explicitly return a copy of its value", boolean_p, _)
                {
                    boolean_p random = Random<boolean_p>();
                    const atomic_t<boolean_p> atom(random);
                    CHECK(static_cast<boolean_p>(atom) == random);
                }
                /// [_b9e6feaf_cbb9_49a8_b569_0719512a3f88]

                /// [_fcd49251_a792_4e12_8add_25957705de25]
                TEST_CASE_TEMPLATE("should implicitly return a copy of its value", boolean_p, _)
                {
                    boolean_p random = Random<boolean_p>();
                    const atomic_t<boolean_p> atom(random);
                    boolean_p value = atom;
                    CHECK(value == random);
                }
                /// [_fcd49251_a792_4e12_8add_25957705de25]

                /// [_76be7c19_8689_470c_84f6_feba11f4c644]
                TEST_CASE_TEMPLATE("should not change its value", boolean_p, _)
                {
                    boolean_p random = Random<boolean_p>();
                    const atomic_t<boolean_p> atom(random);
                    boolean_p value = atom;
                    CHECK(atom == random);
                }
                /// [_76be7c19_8689_470c_84f6_feba11f4c644]

                /// [_ccd55da4_4f5b_48c0_a5f9_470e6581943c]
                TEST_CASE_TEMPLATE("should implicitly allow for logical operators", boolean_p, _)
                {
                    const atomic_t<boolean_p> atom(true);
                    CHECK(atom);
                    CHECK(!!atom);
                    CHECK(atom || false);
                    CHECK(atom && true);
                    CHECK(atom ? true : false);
                }
                /// [_ccd55da4_4f5b_48c0_a5f9_470e6581943c]

                /// [_5115bff0_02e6_4d4d_8380_1d76a26242b0]
                TEST_CASE_TEMPLATE("should implicitly allow for comparison operators", boolean_p, _)
                {
                    boolean_p random = Random<boolean_p>();
                    const atomic_t<boolean_p> atom(random);
                    CHECK(atom == random);
                    CHECK_FALSE(atom != random);
                }
                /// [_5115bff0_02e6_4d4d_8380_1d76a26242b0]
            }
        }

        TEST_SUITE("operators")
        {
            TEST_SUITE("()()")
            {
                /// [_6faaa046_e0b6_4878_9da7_fdc8ff8ac17e]
                TEST_CASE_TEMPLATE("should return a copy of its value", boolean_p, _)
                {
                    boolean_p random = Random<boolean_p>();
                    const atomic_t<boolean_p> atom(random);
                    CHECK(atom() == random);
                }
                /// [_6faaa046_e0b6_4878_9da7_fdc8ff8ac17e]

                /// [_0c2caefd_2b3b_451c_8a89_fc0473760d3b]
                TEST_CASE_TEMPLATE("should not change its value", boolean_p, _)
                {
                    boolean_p random = Random<boolean_p>();
                    const atomic_t<boolean_p> atom(random);
                    boolean_p value = atom();
                    CHECK(atom == random);
                }
                /// [_0c2caefd_2b3b_451c_8a89_fc0473760d3b]
            }
        }

        TEST_SUITE("none_t interface")
        {
            TEST_SUITE("none_ctor()")
            {
                /// [_dcfe5035_ed73_4c45_9240_49d5d0bbea4f]
                TEST_CASE_TEMPLATE("should explicitly set its value to the default value", boolean_p, _)
                {
                    atomic_t<boolean_p> atom((none_t()));
                    CHECK(atom == atomic_t<boolean_p>::DEFAULT_VALUE);
                }
                /// [_dcfe5035_ed73_4c45_9240_49d5d0bbea4f]

                /// [_13953f4c_f4bb_4c4f_bfb8_7074564c1a23]
                TEST_CASE_TEMPLATE("should implicitly set its value to the default value", boolean_p, _)
                {
                    atomic_t<boolean_p> atom = none_t();
                    CHECK(atom == atomic_t<boolean_p>::DEFAULT_VALUE);
                }
                /// [_13953f4c_f4bb_4c4f_bfb8_7074564c1a23]
            }

            TEST_SUITE("=(none_t)")
            {
                /// [_0c74c8bd_a710_4357_8810_2611434b1324]
                TEST_CASE_TEMPLATE("should set its value to the default value", boolean_p, _)
                {
                    boolean_p random = Random<boolean_p>();
                    atomic_t<boolean_p> atom(random);
                    atom = none_t();
                    CHECK(atom == atomic_t<boolean_p>::DEFAULT_VALUE);
                }
                /// [_0c74c8bd_a710_4357_8810_2611434b1324]

                /// [_ed5f8dac_3c07_4eb3_a100_dbc6380060f2]
                TEST_CASE_TEMPLATE("should evaluate as false after being set to none", boolean_p, _)
                {
                    boolean_p random = Random<boolean_p>();
                    atomic_t<boolean_p> atom(random);
                    atom = none_t();
                    CHECK(static_cast<bool_t>(atom) == false);
                }
                /// [_ed5f8dac_3c07_4eb3_a100_dbc6380060f2]

                /// [_5b81fe4b_7a68_4b91_a03d_a678146c2121]
                TEST_CASE_TEMPLATE("should return itself", boolean_p, _)
                {
                    boolean_p random = Random<boolean_p>();
                    atomic_t<boolean_p> atom(random);
                    CHECK(&(atom = none_t()) == &atom);
                }
                /// [_5b81fe4b_7a68_4b91_a03d_a678146c2121]
            }

            TEST_SUITE("==(none_t)")
            {
                /// [_c4f6a770_7550_4723_b054_d55fcc0900b3]
                TEST_CASE_TEMPLATE("should return true when default constructed", boolean_p, _)
                {
                    const atomic_t<boolean_p> atom;
                    CHECK(atom == none_t());
                }
                /// [_c4f6a770_7550_4723_b054_d55fcc0900b3]

                /// [_7bb264b3_fe13_4a43_aa58_0f96d5951cf1]
                TEST_CASE_TEMPLATE("should return true if its value is false", boolean_p, _)
                {
                    const atomic_t<boolean_p> atom(false);
                    CHECK(atom == none_t());
                }
                /// [_7bb264b3_fe13_4a43_aa58_0f96d5951cf1]

                /// [_c484d5fe_cbd6_4ab9_a45e_699d33702bd4]
                TEST_CASE_TEMPLATE("should not change its value", boolean_p, _)
                {
                    boolean_p random = Random<boolean_p>();
                    const atomic_t<boolean_p> atom(random);
                    atom == none_t();
                    CHECK(atom == random);
                }
                /// [_c484d5fe_cbd6_4ab9_a45e_699d33702bd4]
            }

            TEST_SUITE("!=(none_t)")
            {
                /// [_dd75f349_e5c2_459b_9db8_f753036da6eb]
                TEST_CASE_TEMPLATE("should return false when default constructed", boolean_p, _)
                {
                    const atomic_t<boolean_p> atom;
                    CHECK_FALSE(atom != none_t());
                }
                /// [_dd75f349_e5c2_459b_9db8_f753036da6eb]

                /// [_3e86a4da_18b7_4d20_b455_f4b8d0e7e77e]
                TEST_CASE_TEMPLATE("should return false if its value is false", boolean_p, _)
                {
                    const atomic_t<boolean_p> atom(false);
                    CHECK_FALSE(atom != none_t());
                }
                /// [_3e86a4da_18b7_4d20_b455_f4b8d0e7e77e]

                /// [_c7419f69_e9e6_4cab_8551_2e4d241a5263]
                TEST_CASE_TEMPLATE("should not change its value", boolean_p, _)
                {
                    boolean_p random = Random<boolean_p>();
                    const atomic_t<boolean_p> atom(random);
                    atom != none_t();
                    CHECK(atom == random);
                }
                /// [_c7419f69_e9e6_4cab_8551_2e4d241a5263]
            }
        }

    #undef _
    }

}
