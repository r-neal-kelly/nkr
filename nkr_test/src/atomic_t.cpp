/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/atomic_t.h"

#include "intrinsics.h"

namespace nkr {

    TEST_SUITE("atomic_t<bool_t>")
    {
        TEST_SUITE("objects")
        {
            TEST_CASE("default ctor() should set value to false")
            {
                /// [_1b7f9314_f2df_4c3d_a71f_6b11a01289aa]
                atomic_t<bool_t> boolean;
                CHECK(boolean == false);
                /// [_1b7f9314_f2df_4c3d_a71f_6b11a01289aa]
            }

            TEST_CASE("value ctor() should set value to value")
            {
                /// [_0f7071d7_0aff_4842_a554_eaadadb202df]
                atomic_t<bool_t> boolean(true);
                CHECK(boolean == true);
                /// [_0f7071d7_0aff_4842_a554_eaadadb202df]
            }

            TEST_CASE("copy ctor() should copy value from other")
            {
                /// [_ac177a18_dcd1_4b71_a355_2f63be4fdd44]
                atomic_t<bool_t> other(true);
                atomic_t<bool_t> boolean(other);
                CHECK(other == true);
                CHECK(boolean == true);
                /// [_ac177a18_dcd1_4b71_a355_2f63be4fdd44]
            }

            TEST_CASE("move ctor() should copy value from other and set other's value to false")
            {
                /// [_86a37734_3190_4a7f_a849_255b846a664b]
                atomic_t<bool_t> other(true);
                atomic_t<bool_t> boolean(std::move(other));
                CHECK(other == false);
                CHECK(boolean == true);
                /// [_86a37734_3190_4a7f_a849_255b846a664b]
            }

            TEST_CASE("copy assignment ctor() should copy value from other")
            {
                /// [_469d47cb_4dfa_41bc_b758_8b95dd1075b3]
                atomic_t<bool_t> other(true);
                atomic_t<bool_t> boolean = other;
                CHECK(other == true);
                CHECK(boolean == true);
                /// [_469d47cb_4dfa_41bc_b758_8b95dd1075b3]
            }

            TEST_CASE("move assignment ctor() should copy value from other and set other's value to false")
            {
                /// [_45a7e9f6_a713_400a_b509_851cfe326025]
                atomic_t<bool_t> other(true);
                atomic_t<bool_t> boolean = std::move(other);
                CHECK(other == false);
                CHECK(boolean == true);
                /// [_45a7e9f6_a713_400a_b509_851cfe326025]
            }

            TEST_CASE("dtor() should set value to false")
            {
                /// [_bd11bcf0_d3f1_4ece_8570_c9e1e64acce2]
                atomic_t<bool_t> boolean(true);
                boolean.~atomic_t();
                CHECK(boolean == false);
                /// [_bd11bcf0_d3f1_4ece_8570_c9e1e64acce2]
            }
        }

        TEST_SUITE("methods")
        {
            TEST_CASE("Access() should return value")
            {
                /// [_6637c576_6ae6_4161_9398_cdb7ed89faa0]
                const atomic_t<bool_t> boolean(true);
                CHECK(boolean.Access() == true);
                /// [_6637c576_6ae6_4161_9398_cdb7ed89faa0]
            }

            TEST_CASE("Assign() should set value and return the new value")
            {
                /// [_0d6cce7d_97ad_4083_8961_ebe7f7a2398a]
                atomic_t<bool_t> boolean(true);
                CHECK(boolean.Assign(false) == false);
                CHECK(boolean == false);
                /// [_0d6cce7d_97ad_4083_8961_ebe7f7a2398a]
            }

            TEST_CASE("Exchange() should set value and return the old value")
            {
                /// [_9e3a67d0_c398_4373_a1d8_f08fe73fc6fc]
                atomic_t<bool_t> boolean(true);
                CHECK(boolean.Exchange(false) == true);
                CHECK(boolean == false);
                /// [_9e3a67d0_c398_4373_a1d8_f08fe73fc6fc]
            }

            TEST_CASE("Exchange_If_Equals() should set value if the current value matches the snapshot, returning true, else updates snapshot and returns false")
            {
                /// [_4200a847_b748_4f13_ae03_35c01d38af4b]
                atomic_t<bool_t> boolean(true);
                bool_t snapshot = false;
                CHECK(boolean.Exchange_If_Equals(snapshot, false) == false);
                CHECK(boolean == true);
                CHECK(snapshot == true);

                CHECK(boolean.Exchange_If_Equals(snapshot, false) == true);
                CHECK(boolean == false);
                CHECK(snapshot == true);
                /// [_4200a847_b748_4f13_ae03_35c01d38af4b]
            }
        }

        TEST_SUITE("casts")
        {
            TEST_CASE("value_t() should cast to its value_t")
            {
                /// [_7f741da3_6a22_4622_886e_f907a4787aa8]
                atomic_t<bool_t> boolean(true);
                CHECK(static_cast<atomic_t<bool_t>::value_t>(boolean) == true);
                CHECK(boolean == true);
                CHECK(static_cast<bool_t>(boolean) == true);
                CHECK(!boolean == false);

                boolean = false;
                CHECK(boolean == false);
                CHECK(static_cast<bool_t>(boolean) == false);
                CHECK(!boolean == true);
                /// [_7f741da3_6a22_4622_886e_f907a4787aa8]
            }
        }

        TEST_SUITE("operators")
        {
            TEST_CASE("()() should return its value")
            {
                /// [_0a7e9f79_1158_417b_92ab_028d00dc5fb3]
                atomic_t<bool_t> boolean(true);
                CHECK(boolean() == true);
                /// [_0a7e9f79_1158_417b_92ab_028d00dc5fb3]
            }

            TEST_CASE("=() should set its value to other")
            {
                /// [_85d24774_81ca_468b_82aa_fe16844abd0e]
                atomic_t<bool_t> boolean(false);
                boolean = true;
                CHECK(boolean == true);
                /// [_85d24774_81ca_468b_82aa_fe16844abd0e]
            }
        }

        TEST_SUITE("none_t interface")
        {
            TEST_CASE("=(none_t) should set its value to the default value and return itself")
            {
                /// [_07e4716e_e09e_4bd4_9886_caebd9bd3411]
                atomic_t<bool_t> boolean(true);
                CHECK(boolean != atomic_t<bool_t>::DEFAULT_VALUE);
                CHECK(&(boolean = none_t()) == &boolean);
                CHECK(boolean == atomic_t<bool_t>::DEFAULT_VALUE);
                /// [_07e4716e_e09e_4bd4_9886_caebd9bd3411]
            }

            TEST_CASE("==(none_t) should return true if the value is the default, else false")
            {
                /// [_857bb29f_6783_42b1_8e90_a2f7f87f1132]
                atomic_t<bool_t> boolean(true);
                CHECK(!(boolean == none_t()));
                boolean = none_t();
                CHECK((boolean == none_t()));
                /// [_857bb29f_6783_42b1_8e90_a2f7f87f1132]
            }

            TEST_CASE("!=(none_t) should return true if the value is not the default, else false")
            {
                /// [_bd97f6b8_bc89_445b_ae0b_d18ea179d643]
                atomic_t<bool_t> boolean(true);
                CHECK((boolean != none_t()));
                boolean = none_t();
                CHECK(!(boolean != none_t()));
                /// [_bd97f6b8_bc89_445b_ae0b_d18ea179d643]
            }
        }
    }

    TEST_SUITE("atomic_t<integer_tr integer_p>")
    {
        TEST_SUITE("aliases")
        {
            TEST_SUITE("value_t")
            {
                /// [_06294f3b_7dac_4f59_895a_2fd7f9b33932]
                TEST_CASE("should equal the passed in type")
                {
                    static_assert(std::same_as<atomic_t<word_t>::value_t, word_t>);
                }
                /// [_06294f3b_7dac_4f59_895a_2fd7f9b33932]
            }
        }

        TEST_SUITE("static data")
        {
            TEST_SUITE("DEFAULT_VALUE")
            {
                /// [_69784cd6_a92d_46c7_ac93_9e8df556d8af]
                TEST_CASE("should equal the default value of value_t")
                {
                    CHECK(atomic_t<word_t>::DEFAULT_VALUE == atomic_t<word_t>::value_t());
                }
                /// [_69784cd6_a92d_46c7_ac93_9e8df556d8af]

                /// [_81cab430_3f81_4688_bc15_44aac4e05e71]
                TEST_CASE("should equal 0")
                {
                    CHECK(atomic_t<word_t>::DEFAULT_VALUE == 0);
                }
                /// [_81cab430_3f81_4688_bc15_44aac4e05e71]
            }
        }

        TEST_SUITE("object data")
        {
            TEST_SUITE("value")
            {
                /// [_ad87d67f_1180_4b90_89bd_4556539c78fb]
                TEST_CASE("should be a volatile value_t")
                {
                    static_assert(std::same_as<decltype(atomic_t<word_t>::value), volatile word_t>);
                }
                /// [_ad87d67f_1180_4b90_89bd_4556539c78fb]
            }
        }

        TEST_SUITE("objects")
        {
            TEST_SUITE("default_ctor()")
            {

            }

            TEST_SUITE("value_ctor()")
            {

            }

            TEST_SUITE("copy_ctor()")
            {

            }

            TEST_SUITE("move_ctor()")
            {

            }

            TEST_SUITE("value_assignment_ctor()")
            {

            }

            TEST_SUITE("copy_assignment_ctor()")
            {

            }

            TEST_SUITE("move_assignment_ctor()")
            {

            }

            TEST_SUITE("dtor()")
            {

            }
        }

        TEST_SUITE("methods")
        {
            TEST_SUITE("Access()")
            {

            }

            TEST_SUITE("Access_Add()")
            {

            }

            TEST_SUITE("Access_Subtract()")
            {

            }

            TEST_SUITE("Access_Multiply()")
            {

            }

            TEST_SUITE("Access_Divide()")
            {

            }

            TEST_SUITE("Access_Modulus()")
            {

            }

            TEST_SUITE("Access_Or()")
            {

            }

            TEST_SUITE("Access_And()")
            {

            }

            TEST_SUITE("Access_Xor()")
            {

            }

            TEST_SUITE("Access_Left_Shift()")
            {

            }

            TEST_SUITE("Access_Right_Shift()")
            {

            }

            TEST_SUITE("Assign()")
            {

            }

            TEST_SUITE("Assign_Add()")
            {

            }

            TEST_SUITE("Assign_Subtract()")
            {

            }

            TEST_SUITE("Assign_Multiply()")
            {

            }

            TEST_SUITE("Assign_Divide()")
            {

            }

            TEST_SUITE("Assign_Modulus()")
            {

            }

            TEST_SUITE("Assign_Or()")
            {

            }

            TEST_SUITE("Assign_And()")
            {

            }

            TEST_SUITE("Assign_Xor()")
            {

            }

            TEST_SUITE("Assign_Left_Shift()")
            {

            }

            TEST_SUITE("Assign_Right_Shift()")
            {

            }

            TEST_SUITE("Exchange()")
            {

            }

            TEST_SUITE("Exchange_Add()")
            {

            }

            TEST_SUITE("Exchange_Subtract()")
            {

            }

            TEST_SUITE("Exchange_Multiply()")
            {

            }

            TEST_SUITE("Exchange_Divide()")
            {

            }

            TEST_SUITE("Exchange_Modulus()")
            {

            }

            TEST_SUITE("Exchange_Or()")
            {

            }

            TEST_SUITE("Exchange_And()")
            {

            }

            TEST_SUITE("Exchange_Xor()")
            {

            }

            TEST_SUITE("Exchange_Left_Shift()")
            {

            }

            TEST_SUITE("Exchange_Right_Shift()")
            {

            }

            TEST_SUITE("Exchange_If_Equals()")
            {

            }
        }

        TEST_SUITE("casts")
        {
            TEST_SUITE("value_t()")
            {

            }
        }

        TEST_SUITE("operators")
        {
            TEST_SUITE("+=()")
            {

            }

            TEST_SUITE("-=()")
            {

            }

            TEST_SUITE("*=()")
            {

            }

            TEST_SUITE("/=()")
            {

            }

            TEST_SUITE("%=()")
            {

            }

            TEST_SUITE("|=()")
            {

            }

            TEST_SUITE("&=()")
            {

            }

            TEST_SUITE("^=()")
            {

            }

            TEST_SUITE("<<=()")
            {

            }

            TEST_SUITE(">>=()")
            {

            }

            TEST_SUITE("++()")
            {

            }

            TEST_SUITE("++(int)")
            {

            }

            TEST_SUITE("--()")
            {

            }

            TEST_SUITE("--(int)")
            {

            }
        }

        TEST_SUITE("none_t interface")
        {
            TEST_SUITE("none_ctor()")
            {

            }

            TEST_SUITE("=(none_t)")
            {

            }

            TEST_SUITE("==(none_t)")
            {

            }

            TEST_SUITE("!=(none_t)")
            {

            }
        }
    }

    TEST_SUITE("atomic_t<float_tr float_p>")
    {
        TEST_SUITE("aliases")
        {
            TEST_SUITE("value_t")
            {
                /// [_83c3dcd9_5930_49a4_817b_3fe1d33a4550]
                TEST_CASE("should equal the passed in type")
                {
                    static_assert(std::same_as<atomic_t<float_t>::value_t, float_t>);
                }
                /// [_83c3dcd9_5930_49a4_817b_3fe1d33a4550]
            }
        }

        TEST_SUITE("static data")
        {
            TEST_SUITE("DEFAULT_VALUE")
            {
                /// [_2761c14b_ad24_4d18_a896_4058e077d6de]
                TEST_CASE("should equal the default value of value_t")
                {
                    CHECK(atomic_t<float_t>::DEFAULT_VALUE == atomic_t<float_t>::value_t());
                }
                /// [_2761c14b_ad24_4d18_a896_4058e077d6de]

                /// [_1a55c887_94c9_41d4_addd_665545b62e49]
                TEST_CASE("should equal 0.0")
                {
                    CHECK(atomic_t<float_t>::DEFAULT_VALUE == 0.0);
                }
                /// [_1a55c887_94c9_41d4_addd_665545b62e49]
            }
        }

        TEST_SUITE("object data")
        {
            TEST_SUITE("value")
            {
                /// [_0e277dd4_8606_49bb_9991_daca43fd7993]
                TEST_CASE("should be a volatile value_t")
                {
                    static_assert(std::same_as<decltype(atomic_t<float_t>::value), volatile float_t>);
                }
                /// [_0e277dd4_8606_49bb_9991_daca43fd7993]
            }
        }

        TEST_SUITE("objects")
        {
            TEST_SUITE("default_ctor()")
            {
                /// [_8274cab7_e07f_42fc_95fb_21159e5d182b]
                TEST_CASE("should set value to the default")
                {
                    atomic_t<float_t> atom;
                    CHECK(atom == atomic_t<float_t>::DEFAULT_VALUE);
                }
                /// [_8274cab7_e07f_42fc_95fb_21159e5d182b]
            }

            TEST_SUITE("value_ctor()")
            {
                /// [_5d612089_148d_4d8c_af54_9402bb4e0c2e]
                TEST_CASE("should explicitly set passed value")
                {
                    float_t random = Random<float_t>();
                    atomic_t<float_t> atom(random);
                    CHECK(atom == random);
                }
                /// [_5d612089_148d_4d8c_af54_9402bb4e0c2e]

                /// [_c082e3b1_a0eb_4a32_a12f_d01051b722d2]
                TEST_CASE("should implicitly set passed value")
                {
                    float_t random = Random<float_t>();
                    atomic_t<float_t> atom = random;
                    CHECK(atom == random);
                }
                /// [_c082e3b1_a0eb_4a32_a12f_d01051b722d2]

                /// [_027ec34c_9368_4ff3_890b_235196c7702e]
                TEST_CASE("should convert other types and set passed value")
                {
                    word_t random = Random<word_t>();
                    atomic_t<float_t> atom(random);
                    CHECK(atom == static_cast<float_t>(random));
                }
                /// [_027ec34c_9368_4ff3_890b_235196c7702e]
            }

            TEST_SUITE("copy_ctor()")
            {
                /// [_c1b86a21_9372_4474_96c1_6641b05fdd80]
                TEST_CASE("should explicitly copy the value of other")
                {
                    float_t random = Random<float_t>();
                    const atomic_t<float_t> other(random);
                    atomic_t<float_t> atom(other);
                    CHECK(atom == random);
                }
                /// [_c1b86a21_9372_4474_96c1_6641b05fdd80]

                /// [_83a52bb2_2362_4c41_908f_575a08582122]
                TEST_CASE("should implicitly copy the value of other")
                {
                    float_t random = Random<float_t>();
                    const atomic_t<float_t> other(random);
                    atomic_t<float_t> atom = other;
                    CHECK(atom == random);
                }
                /// [_83a52bb2_2362_4c41_908f_575a08582122]

                /// [_5d98cfc6_a426_440d_a0b6_d2a0a0a3c4a9]
                TEST_CASE("should not alter the value of other")
                {
                    float_t random = Random<float_t>();
                    const atomic_t<float_t> other(random);
                    atomic_t<float_t> atom(other);
                    CHECK(other == random);
                }
                /// [_5d98cfc6_a426_440d_a0b6_d2a0a0a3c4a9]
            }

            TEST_SUITE("move_ctor()")
            {
                /// [_ad08e960_ce87_457e_9795_e81944307359]
                TEST_CASE("should explicitly move the value of other")
                {
                    float_t random = Random<float_t>();
                    atomic_t<float_t> other(random);
                    atomic_t<float_t> atom(std::move(other));
                    CHECK(atom == random);
                }
                /// [_ad08e960_ce87_457e_9795_e81944307359]

                /// [_83d42476_ed81_4e4c_b548_fc3a10af5fbe]
                TEST_CASE("should implicitly move the value of other")
                {
                    float_t random = Random<float_t>();
                    atomic_t<float_t> other(random);
                    atomic_t<float_t> atom = std::move(other);
                    CHECK(atom == random);
                }
                /// [_83d42476_ed81_4e4c_b548_fc3a10af5fbe]

                /// [_e9f233ed_244c_4a3d_9a83_d09274e9097b]
                TEST_CASE("should set the value of other to the default")
                {
                    float_t random = Random<float_t>();
                    atomic_t<float_t> other(random);
                    atomic_t<float_t> atom(std::move(other));
                    CHECK(other == atomic_t<float_t>::DEFAULT_VALUE);
                }
                /// [_e9f233ed_244c_4a3d_9a83_d09274e9097b]
            }

            TEST_SUITE("value_assignment_ctor()")
            {
                /// [_900b1558_c4f8_49c3_96b1_9056d76555ed]
                TEST_CASE("should set passed value")
                {
                    float_t random = Random<float_t>();
                    atomic_t<float_t> atom;
                    atom = random;
                    CHECK(atom == random);
                }
                /// [_900b1558_c4f8_49c3_96b1_9056d76555ed]

                /// [_cb64aaa3_b39d_43af_9e6e_03298a723992]
                TEST_CASE("should convert other types and set passed value")
                {
                    word_t random = Random<word_t>();
                    atomic_t<float_t> atom;
                    atom = random;
                    CHECK(atom == static_cast<float_t>(random));
                }
                /// [_cb64aaa3_b39d_43af_9e6e_03298a723992]
            }

            TEST_SUITE("copy_assignment_ctor()")
            {
                /// [_de9354d0_a560_4f0c_b154_aee07071b26b]
                TEST_CASE("should copy the value of other")
                {
                    float_t random = Random<float_t>();
                    const atomic_t<float_t> other(random);
                    atomic_t<float_t> atom;
                    atom = other;
                    CHECK(atom == random);
                }
                /// [_de9354d0_a560_4f0c_b154_aee07071b26b]

                /// [_654311ef_5dfb_4631_8204_eb8c37ff8ce2]
                TEST_CASE("should not alter the value of other")
                {
                    float_t random = Random<float_t>();
                    const atomic_t<float_t> other(random);
                    atomic_t<float_t> atom;
                    atom = other;
                    CHECK(other == random);
                }
                /// [_654311ef_5dfb_4631_8204_eb8c37ff8ce2]
            }

            TEST_SUITE("move_assignment_ctor()")
            {
                /// [_d98fa40a_5147_482b_8a01_95809a294e2b]
                TEST_CASE("should move the value of other")
                {
                    float_t random = Random<float_t>();
                    atomic_t<float_t> other(random);
                    atomic_t<float_t> atom;
                    atom = std::move(other);
                    CHECK(atom == random);
                }
                /// [_d98fa40a_5147_482b_8a01_95809a294e2b]

                /// [_0d1b8d2e_33b4_4576_a466_761fb7452efc]
                TEST_CASE("should set the value of other to the default")
                {
                    float_t random = Random<float_t>();
                    atomic_t<float_t> other(random);
                    atomic_t<float_t> atom;
                    atom = std::move(other);
                    CHECK(other == atomic_t<float_t>::DEFAULT_VALUE);
                }
                /// [_0d1b8d2e_33b4_4576_a466_761fb7452efc]
            }

            TEST_SUITE("dtor()")
            {
                /// [_9d5c2d8f_0af5_49f1_ba14_0bcc98d78dd4]
                TEST_CASE("should set its value to the default")
                {
                    float_t random = Random<float_t>();
                    atomic_t<float_t> atom(random);
                    atom.~atomic_t();
                    CHECK(atom == atomic_t<float_t>::DEFAULT_VALUE);
                }
                /// [_9d5c2d8f_0af5_49f1_ba14_0bcc98d78dd4]
            }
        }

        TEST_SUITE("methods")
        {
            TEST_SUITE("Access()")
            {
                /// [_bf5ad36e_5e23_42d0_b32b_d69acd736c5f]
                TEST_CASE("should return its value")
                {
                    float_t random = Random<float_t>();
                    const atomic_t<float_t> atom(random);
                    CHECK(atom.Access() == random);
                }
                /// [_bf5ad36e_5e23_42d0_b32b_d69acd736c5f]

                /// [_4d0ee15d_2612_402d_b95a_351d66897792]
                TEST_CASE("should not change its value")
                {
                    float_t random = Random<float_t>();
                    const atomic_t<float_t> atom(random);
                    atom.Access();
                    CHECK(atom == random);
                }
                /// [_4d0ee15d_2612_402d_b95a_351d66897792]
            }

            TEST_SUITE("Access_Add()")
            {
                /// [_75b5f69b_46bb_4ae7_934e_dd5ae90ec693]
                TEST_CASE("should return its value + passed value")
                {
                    float_t random_a = Random<float_t>();
                    float_t random_b = Random<float_t>();
                    const atomic_t<float_t> atom(random_a);
                    CHECK(atom.Access_Add(random_b) == random_a + random_b);
                }
                /// [_75b5f69b_46bb_4ae7_934e_dd5ae90ec693]

                /// [_747264ec_e7b9_4bc8_92ad_d518758bbd8f]
                TEST_CASE("should not change its value")
                {
                    float_t random_a = Random<float_t>();
                    float_t random_b = Random<float_t>();
                    const atomic_t<float_t> atom(random_a);
                    atom.Access_Add(random_b);
                    CHECK(atom == random_a);
                }
                /// [_747264ec_e7b9_4bc8_92ad_d518758bbd8f]

                /// [_4c7aeade_69e4_41c0_b861_99fcfc19d171]
                TEST_CASE("should work with types convertible to its value_t")
                {
                    float_t random_a = Random<float_t>();
                    word_t random_b = Random<word_t>();
                    const atomic_t<float_t> atom(random_a);
                    CHECK(atom.Access_Add(random_b) == random_a + static_cast<float_t>(random_b));
                }
                /// [_4c7aeade_69e4_41c0_b861_99fcfc19d171]
            }

            TEST_SUITE("Access_Subtract()")
            {
                /// [_b66f77cd_1f70_4b5c_9003_883081f45007]
                TEST_CASE("should return its value - passed value")
                {
                    float_t random_a = Random<float_t>();
                    float_t random_b = Random<float_t>();
                    const atomic_t<float_t> atom(random_a);
                    CHECK(atom.Access_Subtract(random_b) == random_a - random_b);
                }
                /// [_b66f77cd_1f70_4b5c_9003_883081f45007]

                /// [_b01b18ed_eb1d_4d5e_b77a_c0ffa2a27876]
                TEST_CASE("should not change its value")
                {
                    float_t random_a = Random<float_t>();
                    float_t random_b = Random<float_t>();
                    const atomic_t<float_t> atom(random_a);
                    atom.Access_Subtract(random_b);
                    CHECK(atom == random_a);
                }
                /// [_b01b18ed_eb1d_4d5e_b77a_c0ffa2a27876]

                /// [_2c40ef08_3a4b_4c3a_bf7b_245f25a1f0aa]
                TEST_CASE("should work with types convertible to its value_t")
                {
                    float_t random_a = Random<float_t>();
                    word_t random_b = Random<word_t>();
                    const atomic_t<float_t> atom(random_a);
                    CHECK(atom.Access_Subtract(random_b) == random_a - static_cast<float_t>(random_b));
                }
                /// [_2c40ef08_3a4b_4c3a_bf7b_245f25a1f0aa]
            }

            TEST_SUITE("Access_Multiply()")
            {
                /// [_03109072_ce76_4b5e_bd06_3b965cce9977]
                TEST_CASE("should return its value * passed value")
                {
                    float_t random_a = Random<float_t>();
                    float_t random_b = Random<float_t>();
                    const atomic_t<float_t> atom(random_a);
                    CHECK(atom.Access_Multiply(random_b) == random_a * random_b);
                }
                /// [_03109072_ce76_4b5e_bd06_3b965cce9977]

                /// [_d5c45927_aa1b_4d2b_a2df_984efeed9238]
                TEST_CASE("should not change its value")
                {
                    float_t random_a = Random<float_t>();
                    float_t random_b = Random<float_t>();
                    const atomic_t<float_t> atom(random_a);
                    atom.Access_Multiply(random_b);
                    CHECK(atom == random_a);
                }
                /// [_d5c45927_aa1b_4d2b_a2df_984efeed9238]

                /// [_7b4c9867_7a43_478d_9c73_98fc3aaaf663]
                TEST_CASE("should work with types convertible to its value_t")
                {
                    float_t random_a = Random<float_t>();
                    word_t random_b = Random<word_t>();
                    const atomic_t<float_t> atom(random_a);
                    CHECK(atom.Access_Multiply(random_b) == random_a * static_cast<float_t>(random_b));
                }
                /// [_7b4c9867_7a43_478d_9c73_98fc3aaaf663]
            }

            TEST_SUITE("Access_Divide()")
            {
                /// [_078c27a6_296c_460e_96e8_d61f0b47c3e6]
                TEST_CASE("should return its value / passed value")
                {
                    float_t random_a = Random<float_t>();
                    float_t random_b = Random<float_t>();
                    const atomic_t<float_t> atom(random_a);
                    CHECK(atom.Access_Divide(random_b) == random_a / random_b);
                }
                /// [_078c27a6_296c_460e_96e8_d61f0b47c3e6]

                /// [_bf945a6a_a80a_49f3_9d21_c32cab3e4ee3]
                TEST_CASE("should not change its value")
                {
                    float_t random_a = Random<float_t>();
                    float_t random_b = Random<float_t>();
                    const atomic_t<float_t> atom(random_a);
                    atom.Access_Divide(random_b);
                    CHECK(atom == random_a);
                }
                /// [_bf945a6a_a80a_49f3_9d21_c32cab3e4ee3]

                /// [_adcec423_487a_432d_a731_63d32b0fbc02]
                TEST_CASE("should work with types convertible to its value_t")
                {
                    float_t random_a = Random<float_t>();
                    word_t random_b = Random<word_t>();
                    const atomic_t<float_t> atom(random_a);
                    CHECK(atom.Access_Divide(random_b) == random_a / static_cast<float_t>(random_b));
                }
                /// [_adcec423_487a_432d_a731_63d32b0fbc02]
            }

            TEST_SUITE("Assign()")
            {
                /// [_91339173_2c19_4c80_81c2_47a7d0056c79]
                TEST_CASE("should set its value to the passed value")
                {
                    float_t random_a = Random<float_t>();
                    float_t random_b = Random<float_t>();
                    atomic_t<float_t> atom(random_a);
                    atom.Assign(random_b);
                    CHECK(atom == random_b);
                }
                /// [_91339173_2c19_4c80_81c2_47a7d0056c79]

                /// [_cf6d21c8_fe17_4d24_a869_7c2d2f1c638e]
                TEST_CASE("should return its new value")
                {
                    float_t random_a = Random<float_t>();
                    float_t random_b = Random<float_t>();
                    atomic_t<float_t> atom(random_a);
                    CHECK(atom.Assign(random_b) == random_b);
                }
                /// [_cf6d21c8_fe17_4d24_a869_7c2d2f1c638e]

                /// [_71122f83_edff_4e2b_9b04_ef4e2cb70662]
                TEST_CASE("should work with types convertible to its value_t")
                {
                    float_t random_a = Random<float_t>();
                    word_t random_b = Random<word_t>();
                    atomic_t<float_t> atom(random_a);
                    atom.Assign(random_b);
                    CHECK(atom == static_cast<float_t>(random_b));
                }
                /// [_71122f83_edff_4e2b_9b04_ef4e2cb70662]
            }

            TEST_SUITE("Assign_Add()")
            {
                /// [_58095a65_e406_4f9b_b98a_3e3ab286594e]
                TEST_CASE("should set its value to value + passed value")
                {
                    float_t random_a = Random<float_t>();
                    float_t random_b = Random<float_t>();
                    atomic_t<float_t> atom(random_a);
                    atom.Assign_Add(random_b);
                    CHECK(atom == random_a + random_b);
                }
                /// [_58095a65_e406_4f9b_b98a_3e3ab286594e]

                /// [_ce0eb5c3_7cdf_4ff4_ad98_ea61f1304510]
                TEST_CASE("should return its new value")
                {
                    float_t random_a = Random<float_t>();
                    float_t random_b = Random<float_t>();
                    atomic_t<float_t> atom(random_a);
                    CHECK(atom.Assign_Add(random_b) == random_a + random_b);
                }
                /// [_ce0eb5c3_7cdf_4ff4_ad98_ea61f1304510]

                /// [_e6ec20c3_b673_435b_87bd_35ca0599d8d3]
                TEST_CASE("should work with types convertible to its value_t")
                {
                    float_t random_a = Random<float_t>();
                    word_t random_b = Random<word_t>();
                    atomic_t<float_t> atom(random_a);
                    atom.Assign_Add(random_b);
                    CHECK(atom == random_a + static_cast<float_t>(random_b));
                }
                /// [_e6ec20c3_b673_435b_87bd_35ca0599d8d3]
            }

            TEST_SUITE("Assign_Subtract()")
            {
                /// [_05e1e55b_b233_457c_8ae6_41ba0dec76a9]
                TEST_CASE("should set its value to value - passed value")
                {
                    float_t random_a = Random<float_t>();
                    float_t random_b = Random<float_t>();
                    atomic_t<float_t> atom(random_a);
                    atom.Assign_Subtract(random_b);
                    CHECK(atom == random_a - random_b);
                }
                /// [_05e1e55b_b233_457c_8ae6_41ba0dec76a9]

                /// [_ae57b4c4_2b87_4a91_8f5c_63dde775cbec]
                TEST_CASE("should return its new value")
                {
                    float_t random_a = Random<float_t>();
                    float_t random_b = Random<float_t>();
                    atomic_t<float_t> atom(random_a);
                    CHECK(atom.Assign_Subtract(random_b) == random_a - random_b);
                }
                /// [_ae57b4c4_2b87_4a91_8f5c_63dde775cbec]

                /// [_3f9eb643_a685_4738_a90c_c0fa0c3c9bb4]
                TEST_CASE("should work with types convertible to its value_t")
                {
                    float_t random_a = Random<float_t>();
                    word_t random_b = Random<word_t>();
                    atomic_t<float_t> atom(random_a);
                    atom.Assign_Subtract(random_b);
                    CHECK(atom == random_a - static_cast<float_t>(random_b));
                }
                /// [_3f9eb643_a685_4738_a90c_c0fa0c3c9bb4]
            }

            TEST_SUITE("Assign_Multiply()")
            {
                /// [_14c37838_f17b_4552_9944_8b07373150bb]
                TEST_CASE("should set its value to value * passed value")
                {
                    float_t random_a = Random<float_t>();
                    float_t random_b = Random<float_t>();
                    atomic_t<float_t> atom(random_a);
                    atom.Assign_Multiply(random_b);
                    CHECK(atom == random_a * random_b);
                }
                /// [_14c37838_f17b_4552_9944_8b07373150bb]

                /// [_7de9dd2f_3628_4f22_88e3_b9b31f167ead]
                TEST_CASE("should return its new value")
                {
                    float_t random_a = Random<float_t>();
                    float_t random_b = Random<float_t>();
                    atomic_t<float_t> atom(random_a);
                    CHECK(atom.Assign_Multiply(random_b) == random_a * random_b);
                }
                /// [_7de9dd2f_3628_4f22_88e3_b9b31f167ead]

                /// [_430149ff_9d6b_44ae_8240_19677f08a0ee]
                TEST_CASE("should work with types convertible to its value_t")
                {
                    float_t random_a = Random<float_t>();
                    word_t random_b = Random<word_t>();
                    atomic_t<float_t> atom(random_a);
                    atom.Assign_Multiply(random_b);
                    CHECK(atom == random_a * static_cast<float_t>(random_b));
                }
                /// [_430149ff_9d6b_44ae_8240_19677f08a0ee]
            }

            TEST_SUITE("Assign_Divide()")
            {
                /// [_7a64bd27_579a_4ce6_9878_2f924f4d6066]
                TEST_CASE("should set its value to value / passed value")
                {
                    float_t random_a = Random<float_t>();
                    float_t random_b = Random<float_t>();
                    atomic_t<float_t> atom(random_a);
                    atom.Assign_Divide(random_b);
                    CHECK(atom == random_a / random_b);
                }
                /// [_7a64bd27_579a_4ce6_9878_2f924f4d6066]

                /// [_2213006f_a4bb_404c_867b_47ab4950a07e]
                TEST_CASE("should return its new value")
                {
                    float_t random_a = Random<float_t>();
                    float_t random_b = Random<float_t>();
                    atomic_t<float_t> atom(random_a);
                    CHECK(atom.Assign_Divide(random_b) == random_a / random_b);
                }
                /// [_2213006f_a4bb_404c_867b_47ab4950a07e]

                /// [_c6fc7749_f5c7_4191_a4c8_35000b9572cf]
                TEST_CASE("should work with types convertible to its value_t")
                {
                    float_t random_a = Random<float_t>();
                    word_t random_b = Random<word_t>();
                    atomic_t<float_t> atom(random_a);
                    atom.Assign_Divide(random_b);
                    CHECK(atom == random_a / static_cast<float_t>(random_b));
                }
                /// [_c6fc7749_f5c7_4191_a4c8_35000b9572cf]
            }

            TEST_SUITE("Exchange()")
            {
                /// [_c5484de3_220e_4cf8_83ef_f6aa71ab7966]
                TEST_CASE("should set its value to the passed value")
                {
                    float_t random_a = Random<float_t>();
                    float_t random_b = Random<float_t>();
                    atomic_t<float_t> atom(random_a);
                    atom.Exchange(random_b);
                    CHECK(atom == random_b);
                }
                /// [_c5484de3_220e_4cf8_83ef_f6aa71ab7966]

                /// [_1f7ee854_568e_4397_9ce0_1efc7997d398]
                TEST_CASE("should return its old value")
                {
                    float_t random_a = Random<float_t>();
                    float_t random_b = Random<float_t>();
                    atomic_t<float_t> atom(random_a);
                    CHECK(atom.Exchange(random_b) == random_a);
                }
                /// [_1f7ee854_568e_4397_9ce0_1efc7997d398]

                /// [_8742d47f_afc9_405b_bfae_8b48c126013f]
                TEST_CASE("should work with types convertible to its value_t")
                {
                    float_t random_a = Random<float_t>();
                    word_t random_b = Random<word_t>();
                    atomic_t<float_t> atom(random_a);
                    atom.Exchange(random_b);
                    CHECK(atom == static_cast<float_t>(random_b));
                }
                /// [_8742d47f_afc9_405b_bfae_8b48c126013f]
            }

            TEST_SUITE("Exchange_Add()")
            {
                /// [_0f39542d_efb8_4826_92b5_9ee8b4760adc]
                TEST_CASE("should set its value to value + passed value")
                {
                    float_t random_a = Random<float_t>();
                    float_t random_b = Random<float_t>();
                    atomic_t<float_t> atom(random_a);
                    atom.Exchange_Add(random_b);
                    CHECK(atom == random_a + random_b);
                }
                /// [_0f39542d_efb8_4826_92b5_9ee8b4760adc]

                /// [_ad4af424_9bef_4d09_b79c_f4c50e335596]
                TEST_CASE("should return its old value")
                {
                    float_t random_a = Random<float_t>();
                    float_t random_b = Random<float_t>();
                    atomic_t<float_t> atom(random_a);
                    CHECK(atom.Exchange_Add(random_b) == random_a);
                }
                /// [_ad4af424_9bef_4d09_b79c_f4c50e335596]

                /// [_2dc17ea4_bace_4a53_afd9_b57f98dd5ef1]
                TEST_CASE("should work with types convertible to its value_t")
                {
                    float_t random_a = Random<float_t>();
                    word_t random_b = Random<word_t>();
                    atomic_t<float_t> atom(random_a);
                    atom.Exchange_Add(random_b);
                    CHECK(atom == random_a + static_cast<float_t>(random_b));
                }
                /// [_2dc17ea4_bace_4a53_afd9_b57f98dd5ef1]
            }

            TEST_SUITE("Exchange_Subtract()")
            {
                /// [_5ae99b87_cf4c_4138_a417_072cd82a0852]
                TEST_CASE("should set its value to value - passed value")
                {
                    float_t random_a = Random<float_t>();
                    float_t random_b = Random<float_t>();
                    atomic_t<float_t> atom(random_a);
                    atom.Exchange_Subtract(random_b);
                    CHECK(atom == random_a - random_b);
                }
                /// [_5ae99b87_cf4c_4138_a417_072cd82a0852]

                /// [_a26780e5_ccc7_4f2e_9ae7_49744a446e2b]
                TEST_CASE("should return its old value")
                {
                    float_t random_a = Random<float_t>();
                    float_t random_b = Random<float_t>();
                    atomic_t<float_t> atom(random_a);
                    CHECK(atom.Exchange_Subtract(random_b) == random_a);
                }
                /// [_a26780e5_ccc7_4f2e_9ae7_49744a446e2b]

                /// [_e5654cec_247b_4d30_a7eb_a27f57ca8494]
                TEST_CASE("should work with types convertible to its value_t")
                {
                    float_t random_a = Random<float_t>();
                    word_t random_b = Random<word_t>();
                    atomic_t<float_t> atom(random_a);
                    atom.Exchange_Subtract(random_b);
                    CHECK(atom == random_a - static_cast<float_t>(random_b));
                }
                /// [_e5654cec_247b_4d30_a7eb_a27f57ca8494]
            }

            TEST_SUITE("Exchange_Multiply()")
            {
                /// [_7e049a15_3ffb_4acf_8e73_48db74cb9ff4]
                TEST_CASE("should set its value to value * passed value")
                {
                    float_t random_a = Random<float_t>();
                    float_t random_b = Random<float_t>();
                    atomic_t<float_t> atom(random_a);
                    atom.Exchange_Multiply(random_b);
                    CHECK(atom == random_a * random_b);
                }
                /// [_7e049a15_3ffb_4acf_8e73_48db74cb9ff4]

                /// [_9ea5604a_734e_480f_b9b1_efbcfb248800]
                TEST_CASE("should return its old value")
                {
                    float_t random_a = Random<float_t>();
                    float_t random_b = Random<float_t>();
                    atomic_t<float_t> atom(random_a);
                    CHECK(atom.Exchange_Multiply(random_b) == random_a);
                }
                /// [_9ea5604a_734e_480f_b9b1_efbcfb248800]

                /// [_85360ec2_1d49_496f_ac96_e4ce711953aa]
                TEST_CASE("should work with types convertible to its value_t")
                {
                    float_t random_a = Random<float_t>();
                    word_t random_b = Random<word_t>();
                    atomic_t<float_t> atom(random_a);
                    atom.Exchange_Multiply(random_b);
                    CHECK(atom == random_a * static_cast<float_t>(random_b));
                }
                /// [_85360ec2_1d49_496f_ac96_e4ce711953aa]
            }

            TEST_SUITE("Exchange_Divide()")
            {
                /// [_687caad0_6e65_43da_9aab_31e03808bc83]
                TEST_CASE("should set its value to value / passed value")
                {
                    float_t random_a = Random<float_t>();
                    float_t random_b = Random<float_t>();
                    atomic_t<float_t> atom(random_a);
                    atom.Exchange_Divide(random_b);
                    CHECK(atom == random_a / random_b);
                }
                /// [_687caad0_6e65_43da_9aab_31e03808bc83]

                /// [_2bc2cee2_c542_4852_804d_2c6cdd6ec3bb]
                TEST_CASE("should return its old value")
                {
                    float_t random_a = Random<float_t>();
                    float_t random_b = Random<float_t>();
                    atomic_t<float_t> atom(random_a);
                    CHECK(atom.Exchange_Divide(random_b) == random_a);
                }
                /// [_2bc2cee2_c542_4852_804d_2c6cdd6ec3bb]

                /// [_6425f216_5887_4aa8_96f3_84d306491c7f]
                TEST_CASE("should work with types convertible to its value_t")
                {
                    float_t random_a = Random<float_t>();
                    word_t random_b = Random<word_t>();
                    atomic_t<float_t> atom(random_a);
                    atom.Exchange_Divide(random_b);
                    CHECK(atom == random_a / static_cast<float_t>(random_b));
                }
                /// [_6425f216_5887_4aa8_96f3_84d306491c7f]
            }

            TEST_SUITE("Exchange_If_Equals()")
            {
                /// [_870b7a10_e39f_413e_bc41_5696764fbff3]
                TEST_CASE("should set its value to the passed value if its value equals the snapshot")
                {
                    float_t random_a = Random<float_t>();
                    float_t random_b = Random<float_t>();
                    atomic_t<float_t> atom(random_a);
                    float_t snapshot = atom;
                    atom.Exchange_If_Equals(snapshot, snapshot + random_b);
                    CHECK(atom == random_a + random_b);
                }
                /// [_870b7a10_e39f_413e_bc41_5696764fbff3]

                /// [_36a4ffa4_a0bc_430e_b241_514fbdaf36d1]
                TEST_CASE("should return true if it set the new value")
                {
                    float_t random_a = Random<float_t>();
                    float_t random_b = Random<float_t>();
                    atomic_t<float_t> atom(random_a);
                    float_t snapshot = atom;
                    CHECK(atom.Exchange_If_Equals(snapshot, snapshot + random_b) == true);
                }
                /// [_36a4ffa4_a0bc_430e_b241_514fbdaf36d1]

                /// [_afb7c2ad_ecf4_4bd4_9378_eec404ba647f]
                TEST_CASE("should return false if it did not set the new value")
                {
                    float_t random_a = Random<float_t>();
                    float_t random_b = Random<float_t>();
                    atomic_t<float_t> atom(random_a);
                    float_t snapshot = atom;
                    atom = random_a + random_b;
                    CHECK(atom.Exchange_If_Equals(snapshot, snapshot + random_b) == false);
                }
                /// [_afb7c2ad_ecf4_4bd4_9378_eec404ba647f]

                /// [_67ecc477_461b_4a9b_94a6_17d44163e2d8]
                TEST_CASE("should leave snapshot with its old value if it succeeded")
                {
                    float_t random_a = Random<float_t>();
                    float_t random_b = Random<float_t>();
                    atomic_t<float_t> atom(random_a);
                    float_t snapshot = atom;
                    atom.Exchange_If_Equals(snapshot, snapshot + random_b);
                    CHECK(snapshot == random_a);
                }
                /// [_67ecc477_461b_4a9b_94a6_17d44163e2d8]

                /// [_c55b85bd_af65_4c70_a5b3_e3f12b4f8203]
                TEST_CASE("should update snapshot to its current value if it failed")
                {
                    float_t random_a = Random<float_t>();
                    float_t random_b = Random<float_t>();
                    atomic_t<float_t> atom(random_a);
                    float_t snapshot = atom;
                    atom = random_a + random_b;
                    atom.Exchange_If_Equals(snapshot, snapshot + random_b);
                    CHECK(snapshot == random_a + random_b);
                }
                /// [_c55b85bd_af65_4c70_a5b3_e3f12b4f8203]

                /// [_945d71a2_0ec8_4073_9636_e88e0cc4d477]
                TEST_CASE("should work with types convertible to its value_t")
                {
                    float_t random_a = Random<float_t>();
                    word_t random_b = Random<word_t>();
                    atomic_t<float_t> atom(random_a);
                    float_t snapshot = atom;
                    atom.Exchange_If_Equals(snapshot, random_b);
                    CHECK(atom == static_cast<float_t>(random_b));
                }
                /// [_945d71a2_0ec8_4073_9636_e88e0cc4d477]

                /// [_0d98e9bb_0fae_442e_a5f5_deb14dc5ce0d]
                TEST_CASE("should allow you to atomically change its value safely with a custom algorithm")
                {
                    atomic_t<float_t> atom;
                    std::vector<std::thread> incrementors;
                    std::vector<std::thread> decrementors;
                    const count_t delta = Random<count_t>(1, 256);
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
                                float_t snapshot = atom;
                                while (!atom.Exchange_If_Equals(snapshot, snapshot + delta));
                            }
                        ));
                        decrementors.push_back(std::thread(
                            [&]() -> void_t
                            {
                                std::this_thread::sleep_for(
                                    std::chrono::microseconds(Random<count_t>(1, 5))
                                );
                                float_t snapshot = atom;
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
                TEST_CASE("should explicitly return a copy of its value")
                {
                    float_t random = Random<float_t>();
                    const atomic_t<float_t> atom(random);
                    CHECK(static_cast<float_t>(atom) == random);
                }
                /// [_b4dfe423_ace5_4b2b_92fd_fe47b8708ef0]

                /// [_5589ab94_7740_4958_8eae_40ca0e3b10de]
                TEST_CASE("should implicitly return a copy of its value")
                {
                    float_t random = Random<float_t>();
                    const atomic_t<float_t> atom(random);
                    float_t value = atom;
                    CHECK(value == random);
                }
                /// [_5589ab94_7740_4958_8eae_40ca0e3b10de]

                /// [_9026ed05_fe2f_41ef_99d4_c27cba3ba649]
                TEST_CASE("should not change its value")
                {
                    float_t random = Random<float_t>();
                    const atomic_t<float_t> atom(random);
                    float_t value = atom;
                    CHECK(atom == random);
                }
                /// [_9026ed05_fe2f_41ef_99d4_c27cba3ba649]

                /// [_85183e6a_3837_4d8b_bb24_d1def57b6471]
                TEST_CASE("should implicitly allow for arithmetic operators")
                {
                    float_t random_a = Random<float_t>();
                    float_t random_b = Random<float_t>();
                    const atomic_t<float_t> atom(random_a);
                    CHECK(+atom == +random_a);
                    CHECK(-atom == -random_a);
                    CHECK(atom + random_b == random_a + random_b);
                    CHECK(atom - random_b == random_a - random_b);
                    CHECK(atom * random_b == random_a * random_b);
                    CHECK(atom / random_b == random_a / random_b);
                }
                /// [_85183e6a_3837_4d8b_bb24_d1def57b6471]

                /// [_23e193eb_97a6_4126_b4a0_9986b5528d13]
                TEST_CASE("should implicitly allow for logical operators")
                {
                    float_t random = Random<float_t>(1);
                    const atomic_t<float_t> atom(random);
                    CHECK(atom);
                    CHECK(!!atom);
                    CHECK(atom || 0.0);
                    CHECK(atom && 1.0);
                    CHECK(atom ? true : false);
                }
                /// [_23e193eb_97a6_4126_b4a0_9986b5528d13]

                /// [_f0057019_a03e_4dc4_9571_008553300c9e]
                TEST_CASE("should implicitly allow for comparison operators")
                {
                    float_t random = Random<float_t>();
                    const atomic_t<float_t> atom(random);
                    CHECK(atom == random);
                    CHECK_FALSE(atom != random);
                    CHECK_FALSE(atom < random);
                    CHECK_FALSE(atom > random);
                    CHECK(atom <= random);
                    CHECK(atom >= random);
                    CHECK(atom <=> random == 0);
                }
                /// [_f0057019_a03e_4dc4_9571_008553300c9e]
            }
        }

        TEST_SUITE("operators")
        {
            TEST_SUITE("+=()")
            {
                /// [_36fcf8e0_6485_47cb_9bc3_d1b6fdf4f1e0]
                TEST_CASE("should set its value to value + passed value")
                {
                    float_t random_a = Random<float_t>();
                    float_t random_b = Random<float_t>();
                    atomic_t<float_t> atom(random_a);
                    atom += random_b;
                    CHECK(atom == random_a + random_b);
                }
                /// [_36fcf8e0_6485_47cb_9bc3_d1b6fdf4f1e0]

                /// [_3f1df3a2_1a0f_4d40_a6ec_f1e789df66d2]
                TEST_CASE("should return its new value")
                {
                    float_t random_a = Random<float_t>();
                    float_t random_b = Random<float_t>();
                    atomic_t<float_t> atom(random_a);
                    CHECK((atom += random_b) == random_a + random_b);
                }
                /// [_3f1df3a2_1a0f_4d40_a6ec_f1e789df66d2]

                /// [_033e8b36_38cf_43b8_9f3b_11317636ea2b]
                TEST_CASE("should work with types convertible to its value_t")
                {
                    float_t random_a = Random<float_t>();
                    word_t random_b = Random<word_t>();
                    atomic_t<float_t> atom(random_a);
                    atom += random_b;
                    CHECK(atom == random_a + static_cast<float_t>(random_b));
                }
                /// [_033e8b36_38cf_43b8_9f3b_11317636ea2b]
            }

            TEST_SUITE("-=()")
            {
                /// [_bea2f1be_08d8_4cc8_b7c9_b8e428c48c93]
                TEST_CASE("should set its value to value - passed value")
                {
                    float_t random_a = Random<float_t>();
                    float_t random_b = Random<float_t>();
                    atomic_t<float_t> atom(random_a);
                    atom -= random_b;
                    CHECK(atom == random_a - random_b);
                }
                /// [_bea2f1be_08d8_4cc8_b7c9_b8e428c48c93]

                /// [_480031de_bc4f_4bb6_85ed_62024c4dd49d]
                TEST_CASE("should return its new value")
                {
                    float_t random_a = Random<float_t>();
                    float_t random_b = Random<float_t>();
                    atomic_t<float_t> atom(random_a);
                    CHECK((atom -= random_b) == random_a - random_b);
                }
                /// [_480031de_bc4f_4bb6_85ed_62024c4dd49d]

                /// [_2d48712a_c6cd_44e9_a3e6_b0ff8d43da11]
                TEST_CASE("should work with types convertible to its value_t")
                {
                    float_t random_a = Random<float_t>();
                    word_t random_b = Random<word_t>();
                    atomic_t<float_t> atom(random_a);
                    atom -= random_b;
                    CHECK(atom == random_a - static_cast<float_t>(random_b));
                }
                /// [_2d48712a_c6cd_44e9_a3e6_b0ff8d43da11]
            }

            TEST_SUITE("*=()")
            {
                /// [_719f3d8b_3516_49f0_8370_f21719e31fa7]
                TEST_CASE("should set its value to value * passed value")
                {
                    float_t random_a = Random<float_t>();
                    float_t random_b = Random<float_t>();
                    atomic_t<float_t> atom(random_a);
                    atom *= random_b;
                    CHECK(atom == random_a * random_b);
                }
                /// [_719f3d8b_3516_49f0_8370_f21719e31fa7]

                /// [_37627525_bc0f_44ef_9a71_c6f4cf74cd99]
                TEST_CASE("should return its new value")
                {
                    float_t random_a = Random<float_t>();
                    float_t random_b = Random<float_t>();
                    atomic_t<float_t> atom(random_a);
                    CHECK((atom *= random_b) == random_a * random_b);
                }
                /// [_37627525_bc0f_44ef_9a71_c6f4cf74cd99]

                /// [_0abf5cf0_6bd6_47eb_911e_f3220a7d376a]
                TEST_CASE("should work with types convertible to its value_t")
                {
                    float_t random_a = Random<float_t>();
                    word_t random_b = Random<word_t>();
                    atomic_t<float_t> atom(random_a);
                    atom *= random_b;
                    CHECK(atom == random_a * static_cast<float_t>(random_b));
                }
                /// [_0abf5cf0_6bd6_47eb_911e_f3220a7d376a]
            }

            TEST_SUITE("/=()")
            {
                /// [_a99638da_9117_430f_8144_0bb272a66b90]
                TEST_CASE("should set its value to value / passed value")
                {
                    float_t random_a = Random<float_t>();
                    float_t random_b = Random<float_t>();
                    atomic_t<float_t> atom(random_a);
                    atom /= random_b;
                    CHECK(atom == random_a / random_b);
                }
                /// [_a99638da_9117_430f_8144_0bb272a66b90]

                /// [_c60617e0_f780_400d_9e52_d7748bcd2ad1]
                TEST_CASE("should return its new value")
                {
                    float_t random_a = Random<float_t>();
                    float_t random_b = Random<float_t>();
                    atomic_t<float_t> atom(random_a);
                    CHECK((atom /= random_b) == random_a / random_b);
                }
                /// [_c60617e0_f780_400d_9e52_d7748bcd2ad1]

                /// [_14984ffe_35dc_49c2_8e44_ea56be79f86a]
                TEST_CASE("should work with types convertible to its value_t")
                {
                    float_t random_a = Random<float_t>();
                    word_t random_b = Random<word_t>();
                    atomic_t<float_t> atom(random_a);
                    atom /= random_b;
                    CHECK(atom == random_a / static_cast<float_t>(random_b));
                }
                /// [_14984ffe_35dc_49c2_8e44_ea56be79f86a]
            }

            TEST_SUITE("++()")
            {
                /// [_fba6bafe_2370_452f_831b_8d373e47eb86]
                TEST_CASE("should set its value to value + 1")
                {
                    float_t random = Random<float_t>();
                    atomic_t<float_t> atom(random);
                    ++atom;
                    CHECK(atom == random + 1.0);
                }
                /// [_fba6bafe_2370_452f_831b_8d373e47eb86]

                /// [_3e4434f6_a682_4cb2_a893_adb013675a33]
                TEST_CASE("should return its new value")
                {
                    float_t random = Random<float_t>();
                    atomic_t<float_t> atom(random);
                    CHECK(++atom == random + 1.0);
                }
                /// [_3e4434f6_a682_4cb2_a893_adb013675a33]
            }

            TEST_SUITE("++(int)")
            {
                /// [_f727b235_dd16_453f_a2fd_4c21a5b1b8ca]
                TEST_CASE("should set its value to value + 1")
                {
                    float_t random = Random<float_t>();
                    atomic_t<float_t> atom(random);
                    atom++;
                    CHECK(atom == random + 1.0);
                }
                /// [_f727b235_dd16_453f_a2fd_4c21a5b1b8ca]

                /// [_fbfb8066_4122_419c_91ae_517fab12ec9f]
                TEST_CASE("should return its old value")
                {
                    float_t random = Random<float_t>();
                    atomic_t<float_t> atom(random);
                    CHECK(atom++ == random);
                }
                /// [_fbfb8066_4122_419c_91ae_517fab12ec9f]
            }

            TEST_SUITE("--()")
            {
                /// [_fd3b6e86_caef_4e02_8fe1_86506bf36b74]
                TEST_CASE("should set its value to value - 1")
                {
                    float_t random = Random<float_t>();
                    atomic_t<float_t> atom(random);
                    --atom;
                    CHECK(atom == random - 1.0);
                }
                /// [_fd3b6e86_caef_4e02_8fe1_86506bf36b74]

                /// [_ea214d48_d7ee_49c5_b831_5fd951e97052]
                TEST_CASE("should return its new value")
                {
                    float_t random = Random<float_t>();
                    atomic_t<float_t> atom(random);
                    CHECK(--atom == random - 1.0);
                }
                /// [_ea214d48_d7ee_49c5_b831_5fd951e97052]
            }

            TEST_SUITE("--(int)")
            {
                /// [_d9ecdd36_d9d2_4e22_aa91_f0b0e88a83f3]
                TEST_CASE("should set its value to value - 1")
                {
                    float_t random = Random<float_t>();
                    atomic_t<float_t> atom(random);
                    atom--;
                    CHECK(atom == random - 1.0);
                }
                /// [_d9ecdd36_d9d2_4e22_aa91_f0b0e88a83f3]

                /// [_708c82fa_9602_4c7d_84e2_db57ada3144d]
                TEST_CASE("should return its old value")
                {
                    float_t random = Random<float_t>();
                    atomic_t<float_t> atom(random);
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
                TEST_CASE("should explicitly set its value to the default value")
                {
                    atomic_t<float_t> atom((none_t()));
                    CHECK(atom == atomic_t<float_t>::DEFAULT_VALUE);
                }
                /// [_5096780d_a27a_4d1d_86bb_49ffaf63e81a]
                
                /// [_d0625a9a_49b4_4b1e_af82_4335ef71cc0d]
                TEST_CASE("should implicitly set its value to the default value")
                {
                    atomic_t<float_t> atom = none_t();
                    CHECK(atom == atomic_t<float_t>::DEFAULT_VALUE);
                }
                /// [_d0625a9a_49b4_4b1e_af82_4335ef71cc0d]
            }

            TEST_SUITE("=(none_t)")
            {
                /// [_3b681d95_22c6_4bbf_ab2e_edec47011d4a]
                TEST_CASE("should set its value to the default value")
                {
                    float_t random = Random<float_t>();
                    atomic_t<float_t> atom(random);
                    atom = none_t();
                    CHECK(atom == atomic_t<float_t>::DEFAULT_VALUE);
                }
                /// [_3b681d95_22c6_4bbf_ab2e_edec47011d4a]

                /// [_2c9d76ce_d1a7_4eb7_87c8_75662ad513fa]
                TEST_CASE("should evaluate as false after being set to none")
                {
                    float_t random = Random<float_t>(1);
                    atomic_t<float_t> atom(random);
                    atom = none_t();
                    CHECK(static_cast<bool_t>(atom) == false);
                }
                /// [_2c9d76ce_d1a7_4eb7_87c8_75662ad513fa]

                /// [_656651f9_f4dd_4d8e_8e22_d46a834c7fb0]
                TEST_CASE("should return itself")
                {
                    float_t random = Random<float_t>();
                    atomic_t<float_t> atom(random);
                    CHECK(&(atom = none_t()) == &atom);
                }
                /// [_656651f9_f4dd_4d8e_8e22_d46a834c7fb0]
            }

            TEST_SUITE("==(none_t)")
            {
                /// [_a7f5b5f6_3a48_47fe_b6e3_14eec6f383c4]
                TEST_CASE("should return true when default constructed")
                {
                    const atomic_t<float_t> atom;
                    CHECK(atom == none_t());
                }
                /// [_a7f5b5f6_3a48_47fe_b6e3_14eec6f383c4]
                
                /// [_21a37122_b65b_4ed5_a1d0_3252222d1d97]
                TEST_CASE("should return true if its value is 0.0")
                {
                    const atomic_t<float_t> atom(0.0);
                    CHECK(atom == none_t());
                }
                /// [_21a37122_b65b_4ed5_a1d0_3252222d1d97]

                /// [_88f44f84_d138_444f_86da_95f3d34b3d0e]
                TEST_CASE("should return false if its value is above 0.0")
                {
                    float_t random = Random<float_t>(std::numeric_limits<float_t>::epsilon(),
                                                     std::numeric_limits<float_t>::max());
                    const atomic_t<float_t> atom(random);
                    CHECK_FALSE(atom == none_t());
                }
                /// [_88f44f84_d138_444f_86da_95f3d34b3d0e]

                /// [_fb90f59f_18e9_4486_934f_d9804a28a5b4]
                TEST_CASE("should return false if its value is below 0.0")
                {
                    float_t random = Random<float_t>(-std::numeric_limits<float_t>::max(),
                                                     -std::numeric_limits<float_t>::epsilon());
                    const atomic_t<float_t> atom(random);
                    CHECK_FALSE(atom == none_t());
                }
                /// [_fb90f59f_18e9_4486_934f_d9804a28a5b4]

                /// [_e3936d47_de8c_48ff_979c_dd104837e2b6]
                TEST_CASE("should not change its value")
                {
                    float_t random = Random<float_t>();
                    const atomic_t<float_t> atom(random);
                    atom == none_t();
                    CHECK(atom == random);
                }
                /// [_e3936d47_de8c_48ff_979c_dd104837e2b6]
            }

            TEST_SUITE("!=(none_t)")
            {
                /// [_94d14476_999f_451c_94a0_ac2df55f5038]
                TEST_CASE("should return false when default constructed")
                {
                    const atomic_t<float_t> atom;
                    CHECK_FALSE(atom != none_t());
                }
                /// [_94d14476_999f_451c_94a0_ac2df55f5038]
                
                /// [_e867e438_8518_497a_b61a_b642b661c12a]
                TEST_CASE("should return false if its value is 0.0")
                {
                    const atomic_t<float_t> atom(0.0);
                    CHECK_FALSE(atom != none_t());
                }
                /// [_e867e438_8518_497a_b61a_b642b661c12a]

                /// [_5a4f170a_7266_4e56_8323_69d2e0dd2fa3]
                TEST_CASE("should return true if its value is above 0.0")
                {
                    float_t random = Random<float_t>(std::numeric_limits<float_t>::epsilon(),
                                                     std::numeric_limits<float_t>::max());
                    const atomic_t<float_t> atom(random);
                    CHECK(atom != none_t());
                }
                /// [_5a4f170a_7266_4e56_8323_69d2e0dd2fa3]

                /// [_0225938f_b038_40cd_a659_7fbe416f8006]
                TEST_CASE("should return true if its value is below 0.0")
                {
                    float_t random = Random<float_t>(-std::numeric_limits<float_t>::max(),
                                                     -std::numeric_limits<float_t>::epsilon());
                    const atomic_t<float_t> atom(random);
                    CHECK(atom != none_t());
                }
                /// [_0225938f_b038_40cd_a659_7fbe416f8006]

                /// [_bf986b93_2c19_47cb_b49b_1bc1152d2074]
                TEST_CASE("should not change its value")
                {
                    float_t random = Random<float_t>();
                    const atomic_t<float_t> atom(random);
                    atom != none_t();
                    CHECK(atom == random);
                }
                /// [_bf986b93_2c19_47cb_b49b_1bc1152d2074]
            }
        }
    }

    TEST_SUITE("atomic_t<pointer_tr pointer_p>")
    {
        TEST_SUITE("objects")
        {
            TEST_CASE("default ctor() should set value to nullptr")
            {
                /// [_34735ba9_205e_406c_97b8_85265316c393]
                atomic_t<word_t*> pointer;
                CHECK(pointer == nullptr);
                /// [_34735ba9_205e_406c_97b8_85265316c393]
            }

            TEST_CASE("value ctor() should set value to value")
            {
                /// [_cfab849a_1ef0_4434_a781_7dbb2bb6e202]
                word_t word = 1;
                atomic_t<word_t*> pointer(&word);
                CHECK(pointer == &word);
                /// [_cfab849a_1ef0_4434_a781_7dbb2bb6e202]
            }

            TEST_CASE("copy ctor() should copy value from other")
            {
                /// [_e29b63fc_a075_4c0f_84ce_ea3dfd726c04]
                word_t word = 1;
                atomic_t<word_t*> pointer_1(&word);
                atomic_t<word_t*> pointer_2(pointer_1);
                CHECK(pointer_1 == &word);
                CHECK(pointer_2 == &word);
                /// [_e29b63fc_a075_4c0f_84ce_ea3dfd726c04]
            }

            TEST_CASE("move ctor() should copy value from other and set other's value to nullptr")
            {
                /// [_a072ca80_f1fc_4e03_967d_8893196bdbdc]
                word_t word = 1;
                atomic_t<word_t*> pointer_1(&word);
                atomic_t<word_t*> pointer_2(std::move(pointer_1));
                CHECK(pointer_1 == nullptr);
                CHECK(pointer_2 == &word);
                /// [_a072ca80_f1fc_4e03_967d_8893196bdbdc]
            }

            TEST_CASE("copy assignment ctor() should copy value from other")
            {
                /// [_32b4168d_be3e_4476_acd5_110db8b3d575]
                word_t word = 1;
                atomic_t<word_t*> pointer_1(&word);
                atomic_t<word_t*> pointer_2 = pointer_1;
                CHECK(pointer_1 == &word);
                CHECK(pointer_2 == &word);
                /// [_32b4168d_be3e_4476_acd5_110db8b3d575]
            }

            TEST_CASE("move assignment ctor() should copy value from other and set other's value to nullptr")
            {
                /// [_b08f9703_54f3_423b_ae27_c75ae4c6ecbd]
                word_t word = 1;
                atomic_t<word_t*> pointer_1(&word);
                atomic_t<word_t*> pointer_2 = std::move(pointer_1);
                CHECK(pointer_1 == nullptr);
                CHECK(pointer_2 == &word);
                /// [_b08f9703_54f3_423b_ae27_c75ae4c6ecbd]
            }

            TEST_CASE("dtor() should set value to nullptr")
            {
                /// [_2c45c31c_0cbb_4d49_8600_74f79c34d41e]
                word_t word = 1;
                atomic_t<word_t*> pointer(&word);
                pointer.~atomic_t();
                CHECK(pointer == nullptr);
                /// [_2c45c31c_0cbb_4d49_8600_74f79c34d41e]
            }
        }

        TEST_SUITE("methods")
        {
            TEST_CASE("Access() should return value")
            {
                /// [_52138211_e3ac_4a22_aa66_ae2e64fb0b23]
                word_t word = 1;
                const atomic_t<word_t*> pointer(&word);
                CHECK(pointer.Access() == &word);
                /// [_52138211_e3ac_4a22_aa66_ae2e64fb0b23]
            }

            TEST_CASE("Access_Add() should return added value without changing its value")
            {
                /// [_bf09c9a5_cab4_41fe_984d_a0015f61c817]
                word_t words[2] = { 0, 1 };
                const atomic_t<word_t*> pointer(words + 0);
                CHECK(pointer.Access_Add(1) == words + 1);
                CHECK(pointer == words + 0);
                /// [_bf09c9a5_cab4_41fe_984d_a0015f61c817]
            }

            TEST_CASE("Access_Subtract() should return subtracted value without changing its value")
            {
                /// [_a92fc8bb_2c8f_4aa1_a9c6_fd973443247c]
                word_t words[2] = { 0, 1 };
                const atomic_t<word_t*> pointer(words + 1);
                CHECK(pointer.Access_Subtract(1) == words + 0);
                CHECK(pointer == words + 1);
                /// [_a92fc8bb_2c8f_4aa1_a9c6_fd973443247c]
            }

            TEST_CASE("Assign() should set value and return the new value")
            {
                /// [_53723688_15e9_4903_8312_bf4992444bc4]
                word_t word = 1;
                atomic_t<word_t*> pointer(&word);
                CHECK(pointer.Assign(nullptr) == nullptr);
                CHECK(pointer == nullptr);
                /// [_53723688_15e9_4903_8312_bf4992444bc4]
            }

            TEST_CASE("Assign_Add() should set added value and return the new value")
            {
                /// [_73fd27b7_a3a6_46b0_89e1_d3978e4a686e]
                word_t words[2] = { 0, 1 };
                atomic_t<word_t*> pointer(words + 0);
                CHECK(pointer.Assign_Add(1) == words + 1);
                CHECK(pointer == words + 1);
                /// [_73fd27b7_a3a6_46b0_89e1_d3978e4a686e]
            }

            TEST_CASE("Assign_Subtract() should set subtracted value and return the new value")
            {
                /// [_7a835d14_8b2f_4dca_ad0f_d837522f3e3b]
                word_t words[2] = { 0, 1 };
                atomic_t<word_t*> pointer(words + 1);
                CHECK(pointer.Assign_Subtract(1) == words + 0);
                CHECK(pointer == words + 0);
                /// [_7a835d14_8b2f_4dca_ad0f_d837522f3e3b]
            }

            TEST_CASE("Exchange() should set value and return the old value")
            {
                /// [_3d879e49_04af_4747_b82d_05dfeb40427e]
                word_t word = 1;
                atomic_t<word_t*> pointer(&word);
                CHECK(pointer.Exchange(nullptr) == &word);
                CHECK(pointer == nullptr);
                /// [_3d879e49_04af_4747_b82d_05dfeb40427e]
            }

            TEST_CASE("Exchange_Add() should set added value and return the old value")
            {
                /// [_d085e54c_9932_409d_83f9_a9dc8391057c]
                word_t words[2] = { 0, 1 };
                atomic_t<word_t*> pointer(words + 0);
                CHECK(pointer.Exchange_Add(1) == words + 0);
                CHECK(pointer == words + 1);
                /// [_d085e54c_9932_409d_83f9_a9dc8391057c]
            }

            TEST_CASE("Exchange_Subtract() should set subtracted value and return the old value")
            {
                /// [_c347bb0e_96d6_4976_b649_2920f35b4c13]
                word_t words[2] = { 0, 1 };
                atomic_t<word_t*> pointer(words + 1);
                CHECK(pointer.Exchange_Subtract(1) == words + 1);
                CHECK(pointer == words + 0);
                /// [_c347bb0e_96d6_4976_b649_2920f35b4c13]
            }

            TEST_CASE("Exchange_If_Equals() should set value if the current value matches the snapshot, returning true, else updates snapshot and returns false")
            {
                /// [_42437d1a_4adb_47e7_ae54_8614e79adcfd]
                word_t words[2] = { 0, 0 };
                atomic_t<word_t*> pointer(nullptr);
                word_t* snapshot = &words[0];
                CHECK(pointer.Exchange_If_Equals(snapshot, &words[0]) == false);
                CHECK(pointer == nullptr);
                CHECK(snapshot == nullptr);

                CHECK(pointer.Exchange_If_Equals(snapshot, &words[0]) == true);
                CHECK(pointer == &words[0]);
                CHECK(snapshot == nullptr);

                word_t* value = pointer;
                while (!pointer.Exchange_If_Equals(value, value + 1));
                CHECK(value == &words[0]);
                CHECK(pointer == &words[1]);
                /// [_42437d1a_4adb_47e7_ae54_8614e79adcfd]
            }
        }

        TEST_SUITE("casts")
        {
            TEST_CASE("value_t() should cast to its value_t")
            {
                /// [_24b89ce5_2eee_46ba_91e2_4a7a01307fcd]
                word_t word = 1;
                atomic_t<word_t*> pointer(&word);
                CHECK(static_cast<atomic_t<word_t*>::value_t>(pointer) == &word);
                CHECK(pointer == &word);
                CHECK(static_cast<bool_t>(pointer) == true);
                CHECK(!pointer == false);

                pointer = nullptr;
                CHECK(pointer == nullptr);
                CHECK(static_cast<bool_t>(pointer) == false);
                CHECK(!pointer == true);
                /// [_24b89ce5_2eee_46ba_91e2_4a7a01307fcd]
            }
        }

        TEST_SUITE("operators")
        {
            TEST_CASE("()() should return value")
            {
                /// [_9bd6c299_8368_4f38_91de_0a92fc656dd2]
                word_t word = 1;
                atomic_t<word_t*> pointer(&word);
                CHECK(pointer() == &word);
                /// [_9bd6c299_8368_4f38_91de_0a92fc656dd2]
            }

            TEST_CASE("=() should set value to other")
            {
                /// [_67ea8d39_eb18_479d_9cb8_f7f1db47e709]
                word_t word_1 = 1;
                word_t word_2 = 2;
                atomic_t<word_t*> pointer(&word_1);
                pointer = &word_2;
                CHECK(pointer == &word_2);
                /// [_67ea8d39_eb18_479d_9cb8_f7f1db47e709]
            }

            TEST_CASE("+() should return value + other without changing value")
            {
                /// [_305c48e4_ccdc_419b_8e95_2db4d27bbd05]
                word_t words[2] = { 0, 1 };
                atomic_t<word_t*> pointer(words + 0);
                CHECK(pointer + 1 == words + 1);
                CHECK(pointer == words + 0);
                /// [_305c48e4_ccdc_419b_8e95_2db4d27bbd05]
            }

            TEST_CASE("-() should return value - other without changing value")
            {
                /// [_fd57df65_57b2_4239_93e3_fabdab329824]
                word_t words[2] = { 0, 1 };
                atomic_t<word_t*> pointer(words + 1);
                CHECK(pointer - 1 == words + 0);
                CHECK(pointer == words + 1);
                /// [_fd57df65_57b2_4239_93e3_fabdab329824]
            }

            TEST_CASE("+=() should set value to value + other and return the new value")
            {
                /// [_0e70a8ac_8497_49c0_80bd_8a3d03fc8600]
                word_t words[2] = { 0, 1 };
                atomic_t<word_t*> pointer(words + 0);
                CHECK((pointer += 1) == words + 1);
                CHECK(pointer == words + 1);
                /// [_0e70a8ac_8497_49c0_80bd_8a3d03fc8600]
            }

            TEST_CASE("-=() should set value to value - other and return the new value")
            {
                /// [_1176dbfb_b9a3_4713_bae4_009d932212e6]
                word_t words[2] = { 0, 1 };
                atomic_t<word_t*> pointer(words + 1);
                CHECK((pointer -= 1) == words + 0);
                CHECK(pointer == words + 0);
                /// [_1176dbfb_b9a3_4713_bae4_009d932212e6]
            }

            TEST_CASE("++() should increment value and return the new value")
            {
                /// [_778dc597_e493_49c3_87de_627341dae4ea]
                word_t words[2] = { 0, 1 };
                atomic_t<word_t*> pointer(words + 0);
                CHECK(++pointer == words + 1);
                CHECK(pointer == words + 1);
                /// [_778dc597_e493_49c3_87de_627341dae4ea]
            }

            TEST_CASE("++(int) should increment value and return the old value")
            {
                /// [_04f54830_7e48_4205_84e5_e4c42fcf4543]
                word_t words[2] = { 0, 1 };
                atomic_t<word_t*> pointer(words + 0);
                CHECK(pointer++ == words + 0);
                CHECK(pointer == words + 1);
                /// [_04f54830_7e48_4205_84e5_e4c42fcf4543]
            }

            TEST_CASE("--() should decrement value and return the new value")
            {
                /// [_10bdb15c_f795_4638_a796_4bae0d8d8422]
                word_t words[2] = { 0, 1 };
                atomic_t<word_t*> pointer(words + 1);
                CHECK(--pointer == words + 0);
                CHECK(pointer == words + 0);
                /// [_10bdb15c_f795_4638_a796_4bae0d8d8422]
            }

            TEST_CASE("--(int) should decrement value and return the old value")
            {
                /// [_35f80b34_eaff_4353_b4fe_267cbcfe4a72]
                word_t words[2] = { 0, 1 };
                atomic_t<word_t*> pointer(words + 1);
                CHECK(pointer-- == words + 1);
                CHECK(pointer == words + 0);
                /// [_35f80b34_eaff_4353_b4fe_267cbcfe4a72]
            }

            TEST_CASE("->() should -> the first object of value")
            {
                /// [_92b9d911_3e25_4e07_bf2d_9b5588e612d8]
                struct { const word_t word = 1; } word;
                auto pointer(&word);
                CHECK(pointer->word == 1);
                /// [_92b9d911_3e25_4e07_bf2d_9b5588e612d8]
            }

            TEST_CASE("*() should return a reference to the first object of value")
            {
                /// [_36ef42de_a45e_42cc_b304_8d3e56e272fb]
                struct { const word_t word = 1; } word;
                auto pointer(&word);
                CHECK((*pointer).word == 1);
                /// [_36ef42de_a45e_42cc_b304_8d3e56e272fb]
            }

            TEST_CASE("[]() should [] the indexed object of value")
            {
                /// [_79ec7297_c9db_4756_a956_b9e4020bb643]
                word_t words[2] = { 0, 1 };
                auto pointer(words);
                CHECK(pointer[1] == 1);
                /// [_79ec7297_c9db_4756_a956_b9e4020bb643]
            }
        }

        TEST_SUITE("none_t interface")
        {
            TEST_CASE("=(none_t) should set its value to the default value and return itself")
            {
                /// [_ae06cea8_5ae3_47c7_9d05_27940b2c93b8]
                word_t word = 1;
                atomic_t<word_t*> pointer(&word);
                CHECK(pointer != atomic_t<word_t*>::DEFAULT_VALUE);
                CHECK(&(pointer = none_t()) == &pointer);
                CHECK(pointer == atomic_t<word_t*>::DEFAULT_VALUE);
                /// [_ae06cea8_5ae3_47c7_9d05_27940b2c93b8]
            }

            TEST_CASE("==(none_t) should return true if the value is the default, else false")
            {
                /// [_34174792_bb0d_45ce_a0ec_452706c79358]
                word_t word = 1;
                atomic_t<word_t*> pointer(&word);
                CHECK(!(pointer == none_t()));
                pointer = none_t();
                CHECK((pointer == none_t()));
                /// [_34174792_bb0d_45ce_a0ec_452706c79358]
            }

            TEST_CASE("!=(none_t) should return true if the value is not the default, else false")
            {
                /// [_91bd0dbf_21cb_45e0_b426_9b494f528dfd]
                word_t word = 1;
                atomic_t<word_t*> pointer(&word);
                CHECK((pointer != none_t()));
                pointer = none_t();
                CHECK(!(pointer != none_t()));
                /// [_91bd0dbf_21cb_45e0_b426_9b494f528dfd]
            }
        }
    }

    TEST_SUITE("atomic_t<void_t*>")
    {
        TEST_SUITE("objects")
        {
            TEST_CASE("default ctor() should set value to nullptr")
            {
                /// [_aed6529d_b8e0_49c6_bfb4_cf34db674721]
                atomic_t<void_t*> pointer;
                CHECK(pointer == nullptr);
                /// [_aed6529d_b8e0_49c6_bfb4_cf34db674721]
            }

            TEST_CASE("value ctor() should set value to value")
            {
                /// [_ec73d736_8d5d_4e1c_91a4_d291a6ccad8a]
                word_t word = 1;
                atomic_t<void_t*> pointer(&word);
                CHECK(pointer == &word);
                /// [_ec73d736_8d5d_4e1c_91a4_d291a6ccad8a]
            }

            TEST_CASE("copy ctor() should copy value from other")
            {
                /// [_0b6bdb8c_0205_4d33_8c41_aa1070ebdbb3]
                word_t word = 1;
                atomic_t<void_t*> pointer_1(&word);
                atomic_t<void_t*> pointer_2(pointer_1);
                CHECK(pointer_1 == &word);
                CHECK(pointer_2 == &word);
                /// [_0b6bdb8c_0205_4d33_8c41_aa1070ebdbb3]
            }

            TEST_CASE("move ctor() should copy value from other and set other's value to nullptr")
            {
                /// [_714a3f12_1782_4ca3_885c_5450c6a9d27a]
                word_t word = 1;
                atomic_t<void_t*> pointer_1(&word);
                atomic_t<void_t*> pointer_2(std::move(pointer_1));
                CHECK(pointer_1 == nullptr);
                CHECK(pointer_2 == &word);
                /// [_714a3f12_1782_4ca3_885c_5450c6a9d27a]
            }

            TEST_CASE("copy assignment ctor() should copy value from other")
            {
                /// [_085a2407_369a_496d_9d31_6f5e9a861c6b]
                word_t word = 1;
                atomic_t<void_t*> pointer_1(&word);
                atomic_t<void_t*> pointer_2 = pointer_1;
                CHECK(pointer_1 == &word);
                CHECK(pointer_2 == &word);
                /// [_085a2407_369a_496d_9d31_6f5e9a861c6b]
            }

            TEST_CASE("move assignment ctor() should copy value from other and set other's value to nullptr")
            {
                /// [_534ee9dc_d5f0_40e5_a29b_33b8d54e7c18]
                word_t word = 1;
                atomic_t<void_t*> pointer_1(&word);
                atomic_t<void_t*> pointer_2 = std::move(pointer_1);
                CHECK(pointer_1 == nullptr);
                CHECK(pointer_2 == &word);
                /// [_534ee9dc_d5f0_40e5_a29b_33b8d54e7c18]
            }

            TEST_CASE("dtor() should set value to nullptr")
            {
                /// [_9ee3ef9a_2c92_43c2_a4e6_b7de5e033d02]
                word_t word = 1;
                atomic_t<void_t*> pointer(&word);
                pointer.~atomic_t();
                CHECK(pointer == nullptr);
                /// [_9ee3ef9a_2c92_43c2_a4e6_b7de5e033d02]
            }
        }

        TEST_SUITE("methods")
        {
            TEST_CASE("Access() should return value")
            {
                /// [_2ffa2f85_d618_4887_b26d_66dad7ffbe65]
                word_t word = 1;
                const atomic_t<void_t*> pointer(&word);
                CHECK(pointer.Access() == &word);
                /// [_2ffa2f85_d618_4887_b26d_66dad7ffbe65]
            }

            TEST_CASE("Assign() should set value and return the new value")
            {
                /// [_0464137c_20ca_4fa7_b50f_c18553a5789e]
                word_t word = 1;
                atomic_t<void_t*> pointer(&word);
                CHECK(pointer.Assign(nullptr) == nullptr);
                CHECK(pointer == nullptr);
                /// [_0464137c_20ca_4fa7_b50f_c18553a5789e]
            }

            TEST_CASE("Exchange() should set value and return the old value")
            {
                /// [_1224f0e7_8c9c_4a04_ada0_a84e5d7bfa4c]
                word_t word = 1;
                atomic_t<void_t*> pointer(&word);
                CHECK(pointer.Exchange(nullptr) == &word);
                CHECK(pointer == nullptr);
                /// [_1224f0e7_8c9c_4a04_ada0_a84e5d7bfa4c]
            }

            TEST_CASE("Exchange_If_Equals() should set value if the current value matches the snapshot, returning true, else updates snapshot and returns false")
            {
                /// [_bbf28d7d_3852_4066_b9f5_6acaf2b45d09]
                word_t words[2] = { 0, 0 };
                atomic_t<void_t*> void_pointer(nullptr);
                void_t* snapshot = &words[0];
                CHECK(void_pointer.Exchange_If_Equals(snapshot, &words[0]) == false);
                CHECK(void_pointer == nullptr);
                CHECK(snapshot == nullptr);

                CHECK(void_pointer.Exchange_If_Equals(snapshot, &words[0]) == true);
                CHECK(void_pointer == &words[0]);
                CHECK(snapshot == nullptr);

                void_t* value = void_pointer;
                while (!void_pointer.Exchange_If_Equals(value, static_cast<word_t*>(value) + 1));
                CHECK(value == &words[0]);
                CHECK(void_pointer == &words[1]);
                /// [_bbf28d7d_3852_4066_b9f5_6acaf2b45d09]
            }
        }

        TEST_SUITE("casts")
        {
            TEST_CASE("value_t() should cast to its value_t")
            {
                /// [_47674519_0f60_4a85_9b45_8f91d7657721]
                word_t word = 1;
                atomic_t<void_t*> pointer(&word);
                CHECK(static_cast<atomic_t<void_t*>::value_t>(pointer) == &word);
                CHECK(pointer == &word);
                CHECK(static_cast<bool_t>(pointer) == true);
                CHECK(!pointer == false);

                pointer = nullptr;
                CHECK(pointer == nullptr);
                CHECK(static_cast<bool_t>(pointer) == false);
                CHECK(!pointer == true);
                /// [_47674519_0f60_4a85_9b45_8f91d7657721]
            }
        }

        TEST_SUITE("operators")
        {
            TEST_CASE("()() should return value")
            {
                /// [_caa122b9_0299_4e96_922b_8fc783b26d92]
                word_t word = 1;
                atomic_t<void_t*> pointer(&word);
                CHECK(pointer() == &word);
                /// [_caa122b9_0299_4e96_922b_8fc783b26d92]
            }

            TEST_CASE("=() should set value to other")
            {
                /// [_3fce327c_8e2d_47ef_a8c3_221b7a2929f4]
                word_t word_1 = 1;
                word_t word_2 = 2;
                atomic_t<void_t*> pointer(&word_1);
                pointer = &word_2;
                CHECK(pointer == &word_2);
                /// [_3fce327c_8e2d_47ef_a8c3_221b7a2929f4]
            }
        }

        TEST_SUITE("none_t interface")
        {
            TEST_CASE("=(none_t) should set its value to the default value and return itself")
            {
                /// [_353f3c0e_3536_4095_8ec3_11c0ea9af3c3]
                word_t word = 1;
                atomic_t<void_t*> pointer(&word);
                CHECK(pointer != atomic_t<void_t*>::DEFAULT_VALUE);
                CHECK(&(pointer = none_t()) == &pointer);
                CHECK(pointer == atomic_t<void_t*>::DEFAULT_VALUE);
                /// [_353f3c0e_3536_4095_8ec3_11c0ea9af3c3]
            }

            TEST_CASE("==(none_t) should return true if the value is the default, else false")
            {
                /// [_1c1410bd_4407_4492_a2f7_a172bf73cd9e]
                word_t word = 1;
                atomic_t<void_t*> pointer(&word);
                CHECK(!(pointer == none_t()));
                pointer = none_t();
                CHECK((pointer == none_t()));
                /// [_1c1410bd_4407_4492_a2f7_a172bf73cd9e]
            }

            TEST_CASE("!=(none_t) should return true if the value is not the default, else false")
            {
                /// [_23656443_cb4f_43c1_9653_444057dcbc1d]
                word_t word = 1;
                atomic_t<void_t*> pointer(&word);
                CHECK((pointer != none_t()));
                pointer = none_t();
                CHECK(!(pointer != none_t()));
                /// [_23656443_cb4f_43c1_9653_444057dcbc1d]
            }
        }
    }

}
