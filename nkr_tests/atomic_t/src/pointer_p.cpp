/*
    Copyright 2022 r-neal-kelly
*/

#include "nkr/z_atomic_t.h"
#include "nkr/z_intrinsics.h"
#include "nkr/z_utils.h"

#include "doctest.h"

namespace nkr {

    TEST_SUITE("atomic_t<c_pointer_tr c_pointer_p>")
    {
    #define _               \
        word_t*, real_t*

        TEST_SUITE("aliases")
        {
            TEST_SUITE("value_t")
            {
                /// [_7dbd1a6e_e5ba_41ff_bd34_6b313f79ba66]
                TEST_CASE_TEMPLATE("should equal the passed in type", c_pointer_p, _)
                {
                    static_assert(is_tr<atomic_t<c_pointer_p>::value_t, c_pointer_p>);
                }
                /// [_7dbd1a6e_e5ba_41ff_bd34_6b313f79ba66]
            }

            TEST_SUITE("units_t")
            {
                /// [_0a6532a4_670b_431a_b6e9_61562d590a3e]
                TEST_CASE_TEMPLATE("should equal the pointer type being represented", c_pointer_p, _)
                {
                    static_assert(is_tr<atomic_t<c_pointer_p>::units_t, c_pointer_p>);
                }
                /// [_0a6532a4_670b_431a_b6e9_61562d590a3e]
            }

            TEST_SUITE("unit_t")
            {
                /// [_e7db6edc_c3ac_4009_80fb_49fab24918e2]
                TEST_CASE_TEMPLATE("should equal the type being pointed to", c_pointer_p, _)
                {
                    static_assert(is_tr<atomic_t<c_pointer_p>::unit_t, std::remove_pointer_t<c_pointer_p>>);
                }
                /// [_e7db6edc_c3ac_4009_80fb_49fab24918e2]
            }
        }

        TEST_SUITE("static data")
        {
            TEST_SUITE("DEFAULT_VALUE")
            {
                /// [_5615f3b4_1016_406d_8683_aa9312596d0e]
                TEST_CASE_TEMPLATE("should equal the default value of value_t", c_pointer_p, _)
                {
                    CHECK(atomic_t<c_pointer_p>::DEFAULT_VALUE == atomic_t<c_pointer_p>::value_t());
                }
                /// [_5615f3b4_1016_406d_8683_aa9312596d0e]

                /// [_078d1e9c_0542_4512_ade5_75d9f00d73c9]
                TEST_CASE_TEMPLATE("should equal nullptr", c_pointer_p, _)
                {
                    CHECK(atomic_t<c_pointer_p>::DEFAULT_VALUE == nullptr);
                }
                /// [_078d1e9c_0542_4512_ade5_75d9f00d73c9]
            }
        }

        TEST_SUITE("object data")
        {
            TEST_SUITE("value")
            {
                /// [_455eabe1_8fa8_4f26_8d1b_47be1f24b008]
                TEST_CASE_TEMPLATE("should be a volatile value_t", c_pointer_p, _)
                {
                    static_assert(is_tr<decltype(atomic_t<c_pointer_p>::value), volatile c_pointer_p>);
                }
                /// [_455eabe1_8fa8_4f26_8d1b_47be1f24b008]
            }
        }

        TEST_SUITE("objects")
        {
            TEST_SUITE("default_ctor()")
            {
                /// [_478e7823_9cec_48b0_a0e9_48e29f05c2b1]
                TEST_CASE_TEMPLATE("should set value to the default", c_pointer_p, _)
                {
                    atomic_t<c_pointer_p> atom;
                    CHECK(atom == atomic_t<c_pointer_p>::DEFAULT_VALUE);
                }
                /// [_478e7823_9cec_48b0_a0e9_48e29f05c2b1]
            }

            TEST_SUITE("value_ctor()")
            {
                /// [_17da5208_ec8f_4c4c_bebf_fab8372ea154]
                TEST_CASE_TEMPLATE("should explicitly set passed value", c_pointer_p, _)
                {
                    c_pointer_p random = Random<c_pointer_p>();
                    atomic_t<c_pointer_p> atom(random);
                    CHECK(atom == random);
                }
                /// [_17da5208_ec8f_4c4c_bebf_fab8372ea154]

                /// [_c35b796b_3cee_4cab_9d77_57aac9a566cf]
                TEST_CASE_TEMPLATE("should implicitly set passed value", c_pointer_p, _)
                {
                    c_pointer_p random = Random<c_pointer_p>();
                    atomic_t<c_pointer_p> atom = random;
                    CHECK(atom == random);
                }
                /// [_c35b796b_3cee_4cab_9d77_57aac9a566cf]

                /// [_1080c8b3_e791_45d3_a10e_54de1da04901]
                TEST_CASE("should convert other types and set passed value")
                {
                    struct base_t {};
                    struct derived_t : base_t {};

                    derived_t* random = Random<derived_t*>();
                    atomic_t<base_t*> atom(random);
                    CHECK(atom == static_cast<base_t*>(random));
                }
                /// [_1080c8b3_e791_45d3_a10e_54de1da04901]

                /// [_283e6e4d_f791_4f05_b5dd_0a034642e21e]
                template <typename atomic_p, typename value_p>
                concept value_ctor_tr = requires(atomic_p atomic, value_p value)
                {
                    atomic_p(value);
                };
                TEST_CASE_TEMPLATE("should not allow void pointer", c_pointer_p, _)
                {
                    CHECK(value_ctor_tr<atomic_t<c_pointer_p>, void_t*> == false);
                }
                /// [_283e6e4d_f791_4f05_b5dd_0a034642e21e]

                /// [_2675abeb_0779_4a89_bcc8_14e1d2b6971a]
                TEST_CASE_TEMPLATE("should allow a casted void pointer", c_pointer_p, _)
                {
                    void_t* random = Random<void_t*>();
                    atomic_t<c_pointer_p> atom(static_cast<c_pointer_p>(random));
                    CHECK(atom == static_cast<c_pointer_p>(random));
                }
                /// [_2675abeb_0779_4a89_bcc8_14e1d2b6971a]
            }

            TEST_SUITE("copy_ctor()")
            {
                /// [_52fa64b3_2b7b_49d2_9bbe_e71bc8e9ef64]
                TEST_CASE_TEMPLATE("should explicitly copy the value of other", c_pointer_p, _)
                {
                    c_pointer_p random = Random<c_pointer_p>();
                    const atomic_t<c_pointer_p> other(random);
                    atomic_t<c_pointer_p> atom(other);
                    CHECK(atom == random);
                }
                /// [_52fa64b3_2b7b_49d2_9bbe_e71bc8e9ef64]

                /// [_30c3b6bf_d2c3_41b6_8429_8be42d7c9bff]
                TEST_CASE_TEMPLATE("should implicitly copy the value of other", c_pointer_p, _)
                {
                    c_pointer_p random = Random<c_pointer_p>();
                    const atomic_t<c_pointer_p> other(random);
                    atomic_t<c_pointer_p> atom = other;
                    CHECK(atom == random);
                }
                /// [_30c3b6bf_d2c3_41b6_8429_8be42d7c9bff]

                /// [_f93108f8_f200_4bd0_901c_b59328e2b80e]
                TEST_CASE_TEMPLATE("should not alter the value of other", c_pointer_p, _)
                {
                    c_pointer_p random = Random<c_pointer_p>();
                    const atomic_t<c_pointer_p> other(random);
                    atomic_t<c_pointer_p> atom(other);
                    CHECK(other == random);
                }
                /// [_f93108f8_f200_4bd0_901c_b59328e2b80e]
            }

            TEST_SUITE("move_ctor()")
            {
                /// [_e77a7632_6523_4447_a978_eece943f325c]
                TEST_CASE_TEMPLATE("should explicitly move the value of other", c_pointer_p, _)
                {
                    c_pointer_p random = Random<c_pointer_p>();
                    atomic_t<c_pointer_p> other(random);
                    atomic_t<c_pointer_p> atom(nkr::Move(other));
                    CHECK(atom == random);
                }
                /// [_e77a7632_6523_4447_a978_eece943f325c]

                /// [_fa3fd931_65a1_4f21_bc7e_350620a59ea2]
                TEST_CASE_TEMPLATE("should implicitly move the value of other", c_pointer_p, _)
                {
                    c_pointer_p random = Random<c_pointer_p>();
                    atomic_t<c_pointer_p> other(random);
                    atomic_t<c_pointer_p> atom = nkr::Move(other);
                    CHECK(atom == random);
                }
                /// [_fa3fd931_65a1_4f21_bc7e_350620a59ea2]

                /// [_dd0396a4_76f9_4ff8_b3b9_ab3062999125]
                TEST_CASE_TEMPLATE("should set the value of other to the default", c_pointer_p, _)
                {
                    c_pointer_p random = Random<c_pointer_p>();
                    atomic_t<c_pointer_p> other(random);
                    atomic_t<c_pointer_p> atom(nkr::Move(other));
                    CHECK(other == atomic_t<c_pointer_p>::DEFAULT_VALUE);
                }
                /// [_dd0396a4_76f9_4ff8_b3b9_ab3062999125]
            }

            TEST_SUITE("value_assignment_ctor()")
            {
                /// [_cfeb5a7c_8ac5_4e4d_a3c0_4d57f51dbb11]
                TEST_CASE_TEMPLATE("should set passed value", c_pointer_p, _)
                {
                    c_pointer_p random = Random<c_pointer_p>();
                    atomic_t<c_pointer_p> atom;
                    atom = random;
                    CHECK(atom == random);
                }
                /// [_cfeb5a7c_8ac5_4e4d_a3c0_4d57f51dbb11]

                /// [_4662daba_292f_44f8_976c_8f5f159e0c55]
                TEST_CASE_TEMPLATE("should return itself", c_pointer_p, _)
                {
                    c_pointer_p random = Random<c_pointer_p>();
                    atomic_t<c_pointer_p> atom;
                    CHECK(&(atom = random) == &atom);
                }
                /// [_4662daba_292f_44f8_976c_8f5f159e0c55]

                /// [_d5dfb18d_d900_43b3_941d_32bb32385885]
                TEST_CASE("should convert other types and set passed value")
                {
                    struct base_t {};
                    struct derived_t : base_t {};

                    derived_t* random = Random<derived_t*>();
                    atomic_t<base_t*> atom;
                    atom = random;
                    CHECK(atom == static_cast<base_t*>(random));
                }
                /// [_d5dfb18d_d900_43b3_941d_32bb32385885]

                /// [_419a8090_5a40_4357_9218_f44f6c0ae011]
                template <typename atomic_p, typename value_p>
                concept value_assignment_ctor_tr = requires(atomic_p atomic, value_p value)
                {
                    atomic = value;
                };
                TEST_CASE_TEMPLATE("should not allow void pointer", c_pointer_p, _)
                {
                    CHECK(value_assignment_ctor_tr<atomic_t<c_pointer_p>, void_t*> == false);
                }
                /// [_419a8090_5a40_4357_9218_f44f6c0ae011]

                /// [_604f9c2f_b897_4d44_b34e_8e13ce1a02f7]
                TEST_CASE_TEMPLATE("should allow a casted void pointer", c_pointer_p, _)
                {
                    void_t* random = Random<void_t*>();
                    atomic_t<c_pointer_p> atom;
                    atom = static_cast<c_pointer_p>(random);
                    CHECK(atom == static_cast<c_pointer_p>(random));
                }
                /// [_604f9c2f_b897_4d44_b34e_8e13ce1a02f7]
            }

            TEST_SUITE("copy_assignment_ctor()")
            {
                /// [_e160fe2e_1b3d_4414_900d_0d51a42e6e84]
                TEST_CASE_TEMPLATE("should copy the value of other", c_pointer_p, _)
                {
                    c_pointer_p random = Random<c_pointer_p>();
                    const atomic_t<c_pointer_p> other(random);
                    atomic_t<c_pointer_p> atom;
                    atom = other;
                    CHECK(atom == random);
                }
                /// [_e160fe2e_1b3d_4414_900d_0d51a42e6e84]

                /// [_2f5f6733_64e0_4c50_8d5d_5e1380f3190a]
                TEST_CASE_TEMPLATE("should return itself", c_pointer_p, _)
                {
                    c_pointer_p random = Random<c_pointer_p>();
                    const atomic_t<c_pointer_p> other(random);
                    atomic_t<c_pointer_p> atom;
                    CHECK(&(atom = other) == &atom);
                }
                /// [_2f5f6733_64e0_4c50_8d5d_5e1380f3190a]

                /// [_27743802_36f1_4268_b4a4_0ee18543de69]
                TEST_CASE_TEMPLATE("should not alter the value of other", c_pointer_p, _)
                {
                    c_pointer_p random = Random<c_pointer_p>();
                    const atomic_t<c_pointer_p> other(random);
                    atomic_t<c_pointer_p> atom;
                    atom = other;
                    CHECK(other == random);
                }
                /// [_27743802_36f1_4268_b4a4_0ee18543de69]
            }

            TEST_SUITE("move_assignment_ctor()")
            {
                /// [_405d7d48_3c59_4e98_a944_8414f0cf689c]
                TEST_CASE_TEMPLATE("should move the value of other", c_pointer_p, _)
                {
                    c_pointer_p random = Random<c_pointer_p>();
                    atomic_t<c_pointer_p> other(random);
                    atomic_t<c_pointer_p> atom;
                    atom = nkr::Move(other);
                    CHECK(atom == random);
                }
                /// [_405d7d48_3c59_4e98_a944_8414f0cf689c]

                /// [_7205ba82_274a_4876_8f69_3119ec058be4]
                TEST_CASE_TEMPLATE("should return itself", c_pointer_p, _)
                {
                    c_pointer_p random = Random<c_pointer_p>();
                    atomic_t<c_pointer_p> other(random);
                    atomic_t<c_pointer_p> atom;
                    CHECK(&(atom = nkr::Move(other)) == &atom);
                }
                /// [_7205ba82_274a_4876_8f69_3119ec058be4]

                /// [_0dcc3a12_2360_4398_a023_1782d27710f5]
                TEST_CASE_TEMPLATE("should set the value of other to the default", c_pointer_p, _)
                {
                    c_pointer_p random = Random<c_pointer_p>();
                    atomic_t<c_pointer_p> other(random);
                    atomic_t<c_pointer_p> atom;
                    atom = nkr::Move(other);
                    CHECK(other == atomic_t<c_pointer_p>::DEFAULT_VALUE);
                }
                /// [_0dcc3a12_2360_4398_a023_1782d27710f5]
            }

            TEST_SUITE("dtor()")
            {
                /// [_8166246b_aec6_431f_bf83_37a4a6369884]
                TEST_CASE_TEMPLATE("should set its value to the default", c_pointer_p, _)
                {
                    c_pointer_p random = Random<c_pointer_p>();
                    atomic_t<c_pointer_p> atom(random);
                    atom.~atomic_t();
                    CHECK(atom == atomic_t<c_pointer_p>::DEFAULT_VALUE);
                }
                /// [_8166246b_aec6_431f_bf83_37a4a6369884]
            }
        }

        TEST_SUITE("methods")
        {
            TEST_SUITE("Access()")
            {
                /// [_3e84679c_3f6e_4da4_8a70_5ff162ce626f]
                TEST_CASE_TEMPLATE("should return its value", c_pointer_p, _)
                {
                    c_pointer_p random = Random<c_pointer_p>();
                    const atomic_t<c_pointer_p> atom(random);
                    CHECK(atom.Access() == random);
                }
                /// [_3e84679c_3f6e_4da4_8a70_5ff162ce626f]

                /// [_bbdb8a97_83ec_461f_95ed_06df063b8587]
                TEST_CASE_TEMPLATE("should not change its value", c_pointer_p, _)
                {
                    c_pointer_p random = Random<c_pointer_p>();
                    const atomic_t<c_pointer_p> atom(random);
                    atom.Access();
                    CHECK(atom == random);
                }
                /// [_bbdb8a97_83ec_461f_95ed_06df063b8587]
            }

            TEST_SUITE("Assign()")
            {
                /// [_a5dba8d0_be71_4233_8961_db3a3ce0e68f]
                TEST_CASE_TEMPLATE("should set its value to the passed value", c_pointer_p, _)
                {
                    c_pointer_p random_a = Random<c_pointer_p>();
                    c_pointer_p random_b = Random<c_pointer_p>();
                    atomic_t<c_pointer_p> atom(random_a);
                    atom.Assign(random_b);
                    CHECK(atom == random_b);
                }
                /// [_a5dba8d0_be71_4233_8961_db3a3ce0e68f]

                /// [_2ba4b32d_f0ab_40a2_83ca_f9426b07f465]
                TEST_CASE_TEMPLATE("should return the new value", c_pointer_p, _)
                {
                    c_pointer_p random_a = Random<c_pointer_p>();
                    c_pointer_p random_b = Random<c_pointer_p>();
                    atomic_t<c_pointer_p> atom(random_a);
                    CHECK(atom.Assign(random_b) == random_b);
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
                template <typename atomic_p, typename value_p>
                concept assign_tr = requires(atomic_p atomic, value_p value)
                {
                    atomic.Assign(value);
                };
                TEST_CASE_TEMPLATE("should not allow void pointer", c_pointer_p, _)
                {
                    CHECK(assign_tr<atomic_t<c_pointer_p>, void_t*> == false);
                }
                /// [_4dd28985_f259_46cc_959f_dae795a8cd25]

                /// [_d5b65810_577c_4c3a_be35_b683bc4977ed]
                TEST_CASE_TEMPLATE("should allow a casted void pointer", c_pointer_p, _)
                {
                    c_pointer_p random_a = Random<c_pointer_p>();
                    void_t* random_b = Random<void_t*>();
                    atomic_t<c_pointer_p> atom(random_a);
                    atom.Assign(static_cast<c_pointer_p>(random_b));
                    CHECK(atom == static_cast<c_pointer_p>(random_b));
                }
                /// [_d5b65810_577c_4c3a_be35_b683bc4977ed]
            }

            TEST_SUITE("Assign_Add()")
            {
                /// [_d6c7e655_adff_40c3_a80e_1b35b549bc89]
                TEST_CASE_TEMPLATE("should set its value to value + passed value", c_pointer_p, _)
                {
                    c_pointer_p random_a = Random<c_pointer_p>();
                    word_t random_b = Random<word_t>();
                    atomic_t<c_pointer_p> atom(random_a);
                    atom.Assign_Add(random_b);
                    CHECK(atom == (random_a += random_b));
                }
                /// [_d6c7e655_adff_40c3_a80e_1b35b549bc89]

                /// [_5f5c1fe9_dab4_482a_9a1f_1a22f18dc13e]
                TEST_CASE_TEMPLATE("should return the new value", c_pointer_p, _)
                {
                    c_pointer_p random_a = Random<c_pointer_p>();
                    word_t random_b = Random<word_t>();
                    atomic_t<c_pointer_p> atom(random_a);
                    CHECK(atom.Assign_Add(random_b) == c_pointer_p(random_a + random_b));
                }
                /// [_5f5c1fe9_dab4_482a_9a1f_1a22f18dc13e]
            }

            TEST_SUITE("Assign_Subtract()")
            {
                /// [_32c7f550_1845_4949_9d0d_b31ca54bcbe3]
                TEST_CASE_TEMPLATE("should set its value to value - passed value", c_pointer_p, _)
                {
                    c_pointer_p random_a = Random<c_pointer_p>();
                    word_t random_b = Random<word_t>();
                    atomic_t<c_pointer_p> atom(random_a);
                    atom.Assign_Subtract(random_b);
                    CHECK(atom == (random_a -= random_b));
                }
                /// [_32c7f550_1845_4949_9d0d_b31ca54bcbe3]

                /// [_970432e1_4d91_4253_9d13_2f98e9067528]
                TEST_CASE_TEMPLATE("should return the new value", c_pointer_p, _)
                {
                    c_pointer_p random_a = Random<c_pointer_p>();
                    word_t random_b = Random<word_t>();
                    atomic_t<c_pointer_p> atom(random_a);
                    CHECK(atom.Assign_Subtract(random_b) == c_pointer_p(random_a - random_b));
                }
                /// [_970432e1_4d91_4253_9d13_2f98e9067528]
            }

            TEST_SUITE("Exchange()")
            {
                /// [_2fa2b458_a22c_4b94_b0be_3cad5fd617cf]
                TEST_CASE_TEMPLATE("should set its value to the passed value", c_pointer_p, _)
                {
                    c_pointer_p random_a = Random<c_pointer_p>();
                    c_pointer_p random_b = Random<c_pointer_p>();
                    atomic_t<c_pointer_p> atom(random_a);
                    atom.Exchange(random_b);
                    CHECK(atom == random_b);
                }
                /// [_2fa2b458_a22c_4b94_b0be_3cad5fd617cf]

                /// [_f84aa797_58ba_442f_a5d2_72c7aea3cae2]
                TEST_CASE_TEMPLATE("should return its old value", c_pointer_p, _)
                {
                    c_pointer_p random_a = Random<c_pointer_p>();
                    c_pointer_p random_b = Random<c_pointer_p>();
                    atomic_t<c_pointer_p> atom(random_a);
                    CHECK(atom.Exchange(random_b) == random_a);
                }
                /// [_f84aa797_58ba_442f_a5d2_72c7aea3cae2]

                /// [_93171fb3_1359_475d_9c10_b73c7b7404a4]
                TEST_CASE("should work with types convertible to its value_t")
                {
                    struct base_t {};
                    struct derived_t : base_t {};

                    base_t* random_a = Random<base_t*>();
                    derived_t* random_b = Random<derived_t*>();
                    atomic_t<base_t*> atom(random_a);
                    atom.Exchange(random_b);
                    CHECK(atom == static_cast<base_t*>(random_b));
                }
                /// [_93171fb3_1359_475d_9c10_b73c7b7404a4]

                /// [_9dcd6df0_15ff_456c_8805_5375a4b5b1d1]
                template <typename atomic_p, typename value_p>
                concept exchange_tr = requires(atomic_p atomic, value_p value)
                {
                    atomic.Exchange(value);
                };
                TEST_CASE_TEMPLATE("should not allow void pointer", c_pointer_p, _)
                {
                    CHECK(exchange_tr<atomic_t<c_pointer_p>, void_t*> == false);
                }
                /// [_9dcd6df0_15ff_456c_8805_5375a4b5b1d1]

                /// [_6333ece0_38ff_496b_971f_89be584d0dde]
                TEST_CASE_TEMPLATE("should allow a casted void pointer", c_pointer_p, _)
                {
                    c_pointer_p random_a = Random<c_pointer_p>();
                    void_t* random_b = Random<void_t*>();
                    atomic_t<c_pointer_p> atom(random_a);
                    atom.Exchange(static_cast<c_pointer_p>(random_b));
                    CHECK(atom == static_cast<c_pointer_p>(random_b));
                }
                /// [_6333ece0_38ff_496b_971f_89be584d0dde]
            }

            TEST_SUITE("Exchange_Add()")
            {
                /// [_03df1ec7_d1e7_421e_bf48_eea800605876]
                TEST_CASE_TEMPLATE("should set its value to value + passed value", c_pointer_p, _)
                {
                    c_pointer_p random_a = Random<c_pointer_p>();
                    word_t random_b = Random<word_t>();
                    atomic_t<c_pointer_p> atom(random_a);
                    atom.Exchange_Add(random_b);
                    CHECK(atom == (random_a += random_b));
                }
                /// [_03df1ec7_d1e7_421e_bf48_eea800605876]

                /// [_bea69843_63cb_43d1_80f0_045f8eede76f]
                TEST_CASE_TEMPLATE("should return its old value", c_pointer_p, _)
                {
                    c_pointer_p random_a = Random<c_pointer_p>();
                    word_t random_b = Random<word_t>();
                    atomic_t<c_pointer_p> atom(random_a);
                    CHECK(atom.Exchange_Add(random_b) == random_a);
                }
                /// [_bea69843_63cb_43d1_80f0_045f8eede76f]
            }

            TEST_SUITE("Exchange_Subtract()")
            {
                /// [_53fb4ea4_77ae_4172_a907_420916df2f12]
                TEST_CASE_TEMPLATE("should set its value to value - passed value", c_pointer_p, _)
                {
                    c_pointer_p random_a = Random<c_pointer_p>();
                    word_t random_b = Random<word_t>();
                    atomic_t<c_pointer_p> atom(random_a);
                    atom.Exchange_Subtract(random_b);
                    CHECK(atom == (random_a -= random_b));
                }
                /// [_53fb4ea4_77ae_4172_a907_420916df2f12]

                /// [_25507e90_c54e_431c_aa34_ab4c99b85126]
                TEST_CASE_TEMPLATE("should return its old value", c_pointer_p, _)
                {
                    c_pointer_p random_a = Random<c_pointer_p>();
                    word_t random_b = Random<word_t>();
                    atomic_t<c_pointer_p> atom(random_a);
                    CHECK(atom.Exchange_Subtract(random_b) == random_a);
                }
                /// [_25507e90_c54e_431c_aa34_ab4c99b85126]
            }

            TEST_SUITE("Exchange_If_Equals()")
            {
                /// [_c9199e5c_74f9_4694_b22e_860ec27f59e5]
                TEST_CASE_TEMPLATE("should set its value to the passed value if its value equals the snapshot", c_pointer_p, _)
                {
                    c_pointer_p random_a = Random<c_pointer_p>();
                    c_pointer_p random_b = Random<c_pointer_p>();
                    atomic_t<c_pointer_p> atom(random_a);
                    c_pointer_p snapshot = atom;
                    atom.Exchange_If_Equals(snapshot, random_b);
                    CHECK(atom == random_b);
                }
                /// [_c9199e5c_74f9_4694_b22e_860ec27f59e5]

                /// [_39b3db65_d3e1_4333_a380_c17f64881d92]
                TEST_CASE_TEMPLATE("should return true if it set the new value", c_pointer_p, _)
                {
                    c_pointer_p random_a = Random<c_pointer_p>();
                    c_pointer_p random_b = Random<c_pointer_p>();
                    atomic_t<c_pointer_p> atom(random_a);
                    c_pointer_p snapshot = atom;
                    CHECK(atom.Exchange_If_Equals(snapshot, random_b) == true);
                }
                /// [_39b3db65_d3e1_4333_a380_c17f64881d92]

                /// [_0c527050_0e9e_424c_9dae_ed9767d4795d]
                TEST_CASE_TEMPLATE("should return false if it did not set the new value", c_pointer_p, _)
                {
                    c_pointer_p random_a = Random<c_pointer_p>();
                    c_pointer_p random_b;
                    do {
                        random_b = Random<c_pointer_p>();
                    } while (random_b == random_a);
                    atomic_t<c_pointer_p> atom(random_a);
                    c_pointer_p snapshot = atom;
                    atom = random_b;
                    CHECK(atom.Exchange_If_Equals(snapshot, nullptr) == false);
                }
                /// [_0c527050_0e9e_424c_9dae_ed9767d4795d]

                /// [_065fa476_40d9_444d_8756_f2c9e99e025f]
                TEST_CASE_TEMPLATE("should leave snapshot with its old value if it succeeded", c_pointer_p, _)
                {
                    c_pointer_p random_a = Random<c_pointer_p>();
                    c_pointer_p random_b = Random<c_pointer_p>();
                    atomic_t<c_pointer_p> atom(random_a);
                    c_pointer_p snapshot = atom;
                    atom.Exchange_If_Equals(snapshot, random_b);
                    CHECK(snapshot == random_a);
                }
                /// [_065fa476_40d9_444d_8756_f2c9e99e025f]

                /// [_ffd6ee57_6ad8_413c_933d_5922e0c3dfb9]
                TEST_CASE_TEMPLATE("should update snapshot to its current value if it failed", c_pointer_p, _)
                {
                    c_pointer_p random_a = Random<c_pointer_p>();
                    c_pointer_p random_b;
                    do {
                        random_b = Random<c_pointer_p>();
                    } while (random_b == random_a);
                    atomic_t<c_pointer_p> atom(random_a);
                    c_pointer_p snapshot = atom;
                    atom = random_b;
                    atom.Exchange_If_Equals(snapshot, nullptr);
                    CHECK(snapshot == random_b);
                }
                /// [_ffd6ee57_6ad8_413c_933d_5922e0c3dfb9]

                /// [_21f27f07_771c_4926_9b71_0d9c3ab49645]
                TEST_CASE("should work with types convertible to its value_t")
                {
                    struct base_t {};
                    struct derived_t : base_t {};

                    base_t* random_a = Random<base_t*>();
                    derived_t* random_b = Random<derived_t*>();
                    atomic_t<base_t*> atom(random_a);
                    base_t* snapshot = atom;
                    atom.Exchange_If_Equals(snapshot, random_b);
                    CHECK(atom == static_cast<base_t*>(random_b));
                }
                /// [_21f27f07_771c_4926_9b71_0d9c3ab49645]

                /// [_e58c0fd3_0ec4_4a10_aeba_6ab44df306b0]
                template <typename atomic_p, typename value_p>
                concept exchange_if_equals_tr = requires(atomic_p atomic,
                                                         typename atomic_p::value_t snapshot,
                                                         value_p value)
                {
                    atomic.Exchange_If_Equals(snapshot, value);
                };
                TEST_CASE_TEMPLATE("should not allow void pointer", c_pointer_p, _)
                {
                    CHECK(exchange_if_equals_tr<atomic_t<c_pointer_p>, void_t*> == false);
                }
                /// [_e58c0fd3_0ec4_4a10_aeba_6ab44df306b0]

                /// [_b9d0a7ab_5ed6_4f12_b4ff_31823533b805]
                TEST_CASE_TEMPLATE("should allow a casted void pointer", c_pointer_p, _)
                {
                    c_pointer_p random_a = Random<c_pointer_p>();
                    void_t* random_b = Random<void_t*>();
                    atomic_t<c_pointer_p> atom(random_a);
                    c_pointer_p snapshot = atom;
                    atom.Exchange_If_Equals(snapshot, static_cast<c_pointer_p>(random_b));
                    CHECK(atom == static_cast<c_pointer_p>(random_b));
                }
                /// [_b9d0a7ab_5ed6_4f12_b4ff_31823533b805]

                /// [_dd3710e6_d1f2_4925_987b_a62b091eb2b0]
                TEST_CASE_TEMPLATE("should allow you to atomically change its value safely with a custom algorithm", c_pointer_p, _)
                {
                    typename atomic_t<c_pointer_p>::unit_t unit;
                    atomic_t<c_pointer_p> atom(&unit);
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
                                c_pointer_p snapshot = atom;
                                while (!atom.Exchange_If_Equals(snapshot, snapshot + delta));
                            }
                        ));
                        decrementors.push_back(std::thread(
                            [&]() -> void_t
                            {
                                std::this_thread::sleep_for(
                                    std::chrono::microseconds(Random<count_t>(1, 5))
                                );
                                c_pointer_p snapshot = atom;
                                while (!atom.Exchange_If_Equals(snapshot, snapshot - delta));
                            }
                        ));
                    }
                    for (index_t idx = 0, end = threads_per; idx < end; idx += 1) {
                        incrementors[idx].join();
                        decrementors[idx].join();
                    }

                    CHECK(atom == &unit);
                }
                /// [_dd3710e6_d1f2_4925_987b_a62b091eb2b0]
            }
        }

        TEST_SUITE("casts")
        {
            TEST_SUITE("value_t()")
            {
                /// [_4dce474d_ac4f_4721_a5fc_abecc537cbf9]
                TEST_CASE_TEMPLATE("should explicitly return a copy of its value", c_pointer_p, _)
                {
                    c_pointer_p random = Random<c_pointer_p>();
                    const atomic_t<c_pointer_p> atom(random);
                    CHECK(static_cast<c_pointer_p>(atom) == random);
                }
                /// [_4dce474d_ac4f_4721_a5fc_abecc537cbf9]

                /// [_1a305a11_e7eb_4081_a5a8_e432ea50b9d9]
                TEST_CASE_TEMPLATE("should implicitly return a copy of its value", c_pointer_p, _)
                {
                    c_pointer_p random = Random<c_pointer_p>();
                    const atomic_t<c_pointer_p> atom(random);
                    c_pointer_p value = atom;
                    CHECK(value == random);
                }
                /// [_1a305a11_e7eb_4081_a5a8_e432ea50b9d9]

                /// [_df261ad7_4e58_4f39_82e4_ea2c59272819]
                TEST_CASE_TEMPLATE("should not change its value", c_pointer_p, _)
                {
                    c_pointer_p random = Random<c_pointer_p>();
                    const atomic_t<c_pointer_p> atom(random);
                    c_pointer_p value = atom;
                    CHECK(atom == random);
                }
                /// [_df261ad7_4e58_4f39_82e4_ea2c59272819]

                /// [_06dbb3d9_5894_4605_8641_6bd752f9c782]
                TEST_CASE_TEMPLATE("should implicitly allow for arithmetic operators", c_pointer_p, _)
                {
                    c_pointer_p random_a = Random<c_pointer_p>();
                    word_t random_b = Random<word_t>();
                    const atomic_t<c_pointer_p> atom(random_a);
                    CHECK((atom + random_b) == (random_a + random_b));
                    CHECK((atom - random_b) == (random_a - random_b));
                }
                /// [_06dbb3d9_5894_4605_8641_6bd752f9c782]

                /// [_7f24c559_320d_46d3_a45c_625129a38663]
                TEST_CASE_TEMPLATE("should implicitly allow for logical operators", c_pointer_p, _)
                {
                    c_pointer_p random;
                    do {
                        random = Random<c_pointer_p>();
                    } while (random == nullptr);
                    const atomic_t<c_pointer_p> atom(random);
                    CHECK(atom);
                    CHECK(!!atom);
                    CHECK(atom || false);
                    CHECK(atom && true);
                    CHECK(atom ? true : false);
                }
                /// [_7f24c559_320d_46d3_a45c_625129a38663]

                /// [_ba6c7bcb_a826_4fe1_bd09_2a9bb9541f50]
                TEST_CASE_TEMPLATE("should implicitly allow for comparison operators", c_pointer_p, _)
                {
                    c_pointer_p random = Random<c_pointer_p>();
                    const atomic_t<c_pointer_p> atom(random);
                    CHECK(atom == random);
                    CHECK_FALSE(atom != random);
                    CHECK_FALSE(atom < random);
                    CHECK_FALSE(atom > random);
                    CHECK(atom <= random);
                    CHECK(atom >= random);
                    CHECK((atom <=> random == 0));
                }
                /// [_ba6c7bcb_a826_4fe1_bd09_2a9bb9541f50]
            }
        }

        TEST_SUITE("operators")
        {
            TEST_SUITE("()()")
            {
                /// [_33d5b04b_b5b6_4710_b083_044534ddf67c]
                TEST_CASE_TEMPLATE("should return a copy of its value", c_pointer_p, _)
                {
                    c_pointer_p random = Random<c_pointer_p>();
                    const atomic_t<c_pointer_p> atom(random);
                    CHECK(atom() == random);
                }
                /// [_33d5b04b_b5b6_4710_b083_044534ddf67c]

                /// [_4445ebf2_9581_4c81_a0ab_f2a848c4b30c]
                TEST_CASE_TEMPLATE("should not change its value", c_pointer_p, _)
                {
                    c_pointer_p random = Random<c_pointer_p>();
                    const atomic_t<c_pointer_p> atom(random);
                    c_pointer_p value = atom();
                    CHECK(atom == random);
                }
                /// [_4445ebf2_9581_4c81_a0ab_f2a848c4b30c]
            }

            TEST_SUITE("+=()")
            {
                /// [_552f17e6_f0b0_4115_9009_e427abb2c831]
                TEST_CASE_TEMPLATE("should set its value to value + passed value", c_pointer_p, _)
                {
                    c_pointer_p random_a = Random<c_pointer_p>();
                    word_t random_b = Random<word_t>();
                    atomic_t<c_pointer_p> atom(random_a);
                    atom += random_b;
                    CHECK(atom == (random_a += random_b));
                }
                /// [_552f17e6_f0b0_4115_9009_e427abb2c831]

                /// [_d5c9ce80_6b42_46a8_8fe3_aa77c24d87a0]
                TEST_CASE_TEMPLATE("should return the new value", c_pointer_p, _)
                {
                    c_pointer_p random_a = Random<c_pointer_p>();
                    word_t random_b = Random<word_t>();
                    atomic_t<c_pointer_p> atom(random_a);
                    CHECK((atom += random_b) == c_pointer_p(random_a += random_b));
                }
                /// [_d5c9ce80_6b42_46a8_8fe3_aa77c24d87a0]
            }

            TEST_SUITE("-=()")
            {
                /// [_d207364c_c304_4dd2_92d4_74d0a02091eb]
                TEST_CASE_TEMPLATE("should set its value to value - passed value", c_pointer_p, _)
                {
                    c_pointer_p random_a = Random<c_pointer_p>();
                    word_t random_b = Random<word_t>();
                    atomic_t<c_pointer_p> atom(random_a);
                    atom -= random_b;
                    CHECK(atom == (random_a -= random_b));
                }
                /// [_d207364c_c304_4dd2_92d4_74d0a02091eb]

                /// [_eed6fe54_8e60_4acc_bdc8_419b3ec4bdac]
                TEST_CASE_TEMPLATE("should return the new value", c_pointer_p, _)
                {
                    c_pointer_p random_a = Random<c_pointer_p>();
                    word_t random_b = Random<word_t>();
                    atomic_t<c_pointer_p> atom(random_a);
                    CHECK((atom -= random_b) == c_pointer_p(random_a -= random_b));
                }
                /// [_eed6fe54_8e60_4acc_bdc8_419b3ec4bdac]
            }

            TEST_SUITE("++()")
            {
                /// [_bd616d99_2e42_4cc8_9df3_ba5c40b16233]
                TEST_CASE_TEMPLATE("should set its value to value + 1", c_pointer_p, _)
                {
                    c_pointer_p random = Random<c_pointer_p>();
                    atomic_t<c_pointer_p> atom(random);
                    ++atom;
                    CHECK(atom == (random += 1));
                }
                /// [_bd616d99_2e42_4cc8_9df3_ba5c40b16233]

                /// [_c5e5d4d4_e90d_4fe1_8705_df3dab86ad33]
                TEST_CASE_TEMPLATE("should return the new value", c_pointer_p, _)
                {
                    c_pointer_p random = Random<c_pointer_p>();
                    atomic_t<c_pointer_p> atom(random);
                    CHECK((++atom) == c_pointer_p(++random));
                }
                /// [_c5e5d4d4_e90d_4fe1_8705_df3dab86ad33]
            }

            TEST_SUITE("++(int)")
            {
                /// [_95614eca_1112_41c1_a884_53560f16f900]
                TEST_CASE_TEMPLATE("should set its value to value + 1", c_pointer_p, _)
                {
                    c_pointer_p random = Random<c_pointer_p>();
                    atomic_t<c_pointer_p> atom(random);
                    atom++;
                    CHECK(atom == (random += 1));
                }
                /// [_95614eca_1112_41c1_a884_53560f16f900]

                /// [_131e60fd_1364_4781_b8a8_737448ca1412]
                TEST_CASE_TEMPLATE("should return its old value", c_pointer_p, _)
                {
                    c_pointer_p random = Random<c_pointer_p>();
                    atomic_t<c_pointer_p> atom(random);
                    CHECK(atom++ == random);
                }
                /// [_131e60fd_1364_4781_b8a8_737448ca1412]
            }

            TEST_SUITE("--()")
            {
                /// [_19bda1d1_2e7d_47c2_8b7a_5b686254fde6]
                TEST_CASE_TEMPLATE("should set its value to value - 1", c_pointer_p, _)
                {
                    c_pointer_p random = Random<c_pointer_p>();
                    atomic_t<c_pointer_p> atom(random);
                    --atom;
                    CHECK(atom == (random -= 1));
                }
                /// [_19bda1d1_2e7d_47c2_8b7a_5b686254fde6]

                /// [_050adc8f_0f21_4dde_bdaa_9f5e4a984ead]
                TEST_CASE_TEMPLATE("should return the new value", c_pointer_p, _)
                {
                    c_pointer_p random = Random<c_pointer_p>();
                    atomic_t<c_pointer_p> atom(random);
                    CHECK((--atom) == c_pointer_p(--random));
                }
                /// [_050adc8f_0f21_4dde_bdaa_9f5e4a984ead]
            }

            TEST_SUITE("--(int)")
            {
                /// [_f6f195e1_9243_472b_bc97_47c1d94632c4]
                TEST_CASE_TEMPLATE("should set its value to value - 1", c_pointer_p, _)
                {
                    c_pointer_p random = Random<c_pointer_p>();
                    atomic_t<c_pointer_p> atom(random);
                    atom--;
                    CHECK(atom == (random -= 1));
                }
                /// [_f6f195e1_9243_472b_bc97_47c1d94632c4]

                /// [_f0f2e042_c6e8_4e11_a427_75c83df3c3ef]
                TEST_CASE_TEMPLATE("should return its old value", c_pointer_p, _)
                {
                    c_pointer_p random = Random<c_pointer_p>();
                    atomic_t<c_pointer_p> atom(random);
                    CHECK(atom-- == random);
                }
                /// [_f0f2e042_c6e8_4e11_a427_75c83df3c3ef]
            }

            TEST_SUITE("->()")
            {
                /// [_0cd55105_4d01_462e_a5fe_bcb2bcea5516]
                TEST_CASE_TEMPLATE("should be able to access its value's values", c_pointer_p, _)
                {
                    using unit_t = atomic_t<c_pointer_p>::unit_t;

                    unit_t random = Random<unit_t>();
                    struct wrap_t { unit_t value; } wrap(random);
                    const atomic_t<wrap_t*> atom(&wrap);
                    CHECK(atom->value == random);
                }
                /// [_0cd55105_4d01_462e_a5fe_bcb2bcea5516]

                /// [_047bed10_4ae3_46c2_864a_6e22389c8f92]
                TEST_CASE_TEMPLATE("should be able to assign its value's values", c_pointer_p, _)
                {
                    using unit_t = atomic_t<c_pointer_p>::unit_t;

                    unit_t random_a = Random<unit_t>();
                    unit_t random_b = Random<unit_t>();
                    struct wrap_t { unit_t value; } wrap(random_a);
                    const atomic_t<wrap_t*> atom(&wrap);
                    atom->value = random_b;
                    CHECK(wrap.value == random_b);
                }
                /// [_047bed10_4ae3_46c2_864a_6e22389c8f92]

                /// [_44c3bfc9_9d08_4831_81a2_4c5cd5f51a2d]
                TEST_CASE_TEMPLATE("should not change its own value", c_pointer_p, _)
                {
                    using unit_t = atomic_t<c_pointer_p>::unit_t;

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
                TEST_CASE_TEMPLATE("should be able to access its value's value", c_pointer_p, _)
                {
                    using unit_t = atomic_t<c_pointer_p>::unit_t;

                    unit_t random = Random<unit_t>();
                    const atomic_t<c_pointer_p> atom(&random);
                    CHECK(*atom == random);
                }
                /// [_5742204e_627d_4598_acb6_cc5ff6a1b163]

                /// [_ef5aefb7_c5cb_4863_9812_10b3a72bdd71]
                TEST_CASE_TEMPLATE("should be able to assign its value's value", c_pointer_p, _)
                {
                    using unit_t = atomic_t<c_pointer_p>::unit_t;

                    unit_t random_a = Random<unit_t>();
                    unit_t random_b = Random<unit_t>();
                    const atomic_t<c_pointer_p> atom(&random_a);
                    *atom = random_b;
                    CHECK(random_a == random_b);
                }
                /// [_ef5aefb7_c5cb_4863_9812_10b3a72bdd71]

                /// [_5b66e0f4_7661_4602_aa86_1de0039cc1c3]
                TEST_CASE_TEMPLATE("should not change its own value", c_pointer_p, _)
                {
                    using unit_t = atomic_t<c_pointer_p>::unit_t;

                    unit_t random_a = Random<unit_t>();
                    unit_t random_b = Random<unit_t>();
                    const atomic_t<c_pointer_p> atom(&random_a);
                    *atom = random_b;
                    CHECK(atom == &random_a);
                }
                /// [_5b66e0f4_7661_4602_aa86_1de0039cc1c3]
            }

            TEST_SUITE("[]()")
            {
                /// [_61a845a4_7c90_4d1e_817f_74fa09b23659]
                TEST_CASE_TEMPLATE("should be able to access its values' values", c_pointer_p, _)
                {
                    using unit_t = atomic_t<c_pointer_p>::unit_t;

                    unit_t randoms[16];
                    for (index_t idx = 0, end = 16; idx < end; idx += 1) {
                        randoms[idx] = Random<unit_t>();
                    }
                    const atomic_t<c_pointer_p> atom(randoms);
                    index_t index = Random<index_t>(0, 15);
                    CHECK(atom[index] == randoms[index]);
                }
                /// [_61a845a4_7c90_4d1e_817f_74fa09b23659]

                /// [_e1d47c27_8b19_4dde_8dda_1909d5b6174a]
                TEST_CASE_TEMPLATE("should be able to assign its values' values", c_pointer_p, _)
                {
                    using unit_t = atomic_t<c_pointer_p>::unit_t;

                    unit_t randoms[16];
                    for (index_t idx = 0, end = 16; idx < end; idx += 1) {
                        randoms[idx] = Random<unit_t>();
                    }
                    const atomic_t<c_pointer_p> atom(randoms);
                    index_t index = Random<index_t>(0, 15);
                    unit_t random = Random<unit_t>();
                    atom[index] = random;
                    CHECK(randoms[index] == random);
                }
                /// [_e1d47c27_8b19_4dde_8dda_1909d5b6174a]

                /// [_46f33f5a_5ee8_4f5d_920c_c4d2e462bc49]
                TEST_CASE_TEMPLATE("should not change its own values", c_pointer_p, _)
                {
                    using unit_t = atomic_t<c_pointer_p>::unit_t;

                    unit_t randoms[16];
                    for (index_t idx = 0, end = 16; idx < end; idx += 1) {
                        randoms[idx] = Random<unit_t>();
                    }
                    const atomic_t<c_pointer_p> atom(randoms);
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
                TEST_CASE_TEMPLATE("should explicitly set its value to the default value", c_pointer_p, _)
                {
                    atomic_t<c_pointer_p> atom((none_t()));
                    CHECK(atom == atomic_t<c_pointer_p>::DEFAULT_VALUE);
                }
                /// [_714d230d_baa3_46bd_975f_882f3fd94fcd]

                /// [_50f7eb64_7df4_4804_93a3_c606d582436e]
                TEST_CASE_TEMPLATE("should implicitly set its value to the default value", c_pointer_p, _)
                {
                    atomic_t<c_pointer_p> atom = none_t();
                    CHECK(atom == atomic_t<c_pointer_p>::DEFAULT_VALUE);
                }
                /// [_50f7eb64_7df4_4804_93a3_c606d582436e]
            }

            TEST_SUITE("=(none_t)")
            {
                /// [_f791564a_ab02_4dae_a826_21b4861afabb]
                TEST_CASE_TEMPLATE("should set its value to the default value", c_pointer_p, _)
                {
                    c_pointer_p random = Random<c_pointer_p>();
                    atomic_t<c_pointer_p> atom(random);
                    atom = none_t();
                    CHECK(atom == atomic_t<c_pointer_p>::DEFAULT_VALUE);
                }
                /// [_f791564a_ab02_4dae_a826_21b4861afabb]

                /// [_07a6853a_24d8_4615_a3ac_ea843b23723a]
                TEST_CASE_TEMPLATE("should evaluate as false after being set to none", c_pointer_p, _)
                {
                    c_pointer_p random = Random<c_pointer_p>();
                    atomic_t<c_pointer_p> atom(random);
                    atom = none_t();
                    CHECK(static_cast<bool_t>(atom) == false);
                }
                /// [_07a6853a_24d8_4615_a3ac_ea843b23723a]

                /// [_6334f264_e99d_4833_9325_206dc2020c25]
                TEST_CASE_TEMPLATE("should return itself", c_pointer_p, _)
                {
                    c_pointer_p random = Random<c_pointer_p>();
                    atomic_t<c_pointer_p> atom(random);
                    CHECK(&(atom = none_t()) == &atom);
                }
                /// [_6334f264_e99d_4833_9325_206dc2020c25]
            }

            TEST_SUITE("==(none_t)")
            {
                /// [_99ed6aa2_edce_4a09_a02e_20b4813e6d7a]
                TEST_CASE_TEMPLATE("should return true when default constructed", c_pointer_p, _)
                {
                    const atomic_t<c_pointer_p> atom;
                    CHECK(atom == none_t());
                }
                /// [_99ed6aa2_edce_4a09_a02e_20b4813e6d7a]

                /// [_caa2e675_361c_434d_a212_0f883a1bb91d]
                TEST_CASE_TEMPLATE("should return true if its value is nullptr", c_pointer_p, _)
                {
                    const atomic_t<c_pointer_p> atom(nullptr);
                    CHECK(atom == none_t());
                }
                /// [_caa2e675_361c_434d_a212_0f883a1bb91d]

                /// [_aab25727_80d3_4bd3_8e9e_03d7112f9943]
                TEST_CASE_TEMPLATE("should not change its value", c_pointer_p, _)
                {
                    c_pointer_p random = Random<c_pointer_p>();
                    const atomic_t<c_pointer_p> atom(random);
                    atom == none_t();
                    CHECK(atom == random);
                }
                /// [_aab25727_80d3_4bd3_8e9e_03d7112f9943]
            }

            TEST_SUITE("!=(none_t)")
            {
                /// [_f5814f4b_dfbe_4c43_a6c1_33e322e87ff6]
                TEST_CASE_TEMPLATE("should return false when default constructed", c_pointer_p, _)
                {
                    const atomic_t<c_pointer_p> atom;
                    CHECK_FALSE(atom != none_t());
                }
                /// [_f5814f4b_dfbe_4c43_a6c1_33e322e87ff6]

                /// [_dc378d95_3f12_4b56_8b86_a06734b5a21d]
                TEST_CASE_TEMPLATE("should return false if its value is nullptr", c_pointer_p, _)
                {
                    const atomic_t<c_pointer_p> atom(nullptr);
                    CHECK_FALSE(atom != none_t());
                }
                /// [_dc378d95_3f12_4b56_8b86_a06734b5a21d]

                /// [_608904fe_120e_4339_8a49_1bd6d4c93cda]
                TEST_CASE_TEMPLATE("should not change its value", c_pointer_p, _)
                {
                    c_pointer_p random = Random<c_pointer_p>();
                    const atomic_t<c_pointer_p> atom(random);
                    atom != none_t();
                    CHECK(atom == random);
                }
                /// [_608904fe_120e_4339_8a49_1bd6d4c93cda]
            }
        }

    #undef _
    }

}
