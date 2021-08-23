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

            TEST_CASE("Exchange_If_Equals() should set value if old value equals target and return the old value")
            {
                /// [_4200a847_b748_4f13_ae03_35c01d38af4b]
                atomic_t<bool_t> boolean(true);
                CHECK(boolean.Exchange_If_Equals(false, false) == true);
                CHECK(boolean == true);
                CHECK(boolean.Exchange_If_Equals(false, true) == true);
                CHECK(boolean == false);
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
        TEST_SUITE("objects")
        {
            TEST_CASE("default ctor() should set value to 0")
            {
                /// [_0298459b_30c7_4419_8b76_6622a7bb2c8d]
                atomic_t<word_t> word;
                CHECK(word == 0);
                /// [_0298459b_30c7_4419_8b76_6622a7bb2c8d]
            }

            TEST_CASE("value ctor() should set value to value")
            {
                /// [_425597b2_62fc_4a77_b872_8be9424221fe]
                atomic_t<word_t> word(1);
                CHECK(word == 1);
                /// [_425597b2_62fc_4a77_b872_8be9424221fe]
            }

            TEST_CASE("copy ctor() should copy value from other")
            {
                /// [_5c070153_8529_46e5_b952_8c2cf67c6036]
                atomic_t<word_t> other(1);
                atomic_t<word_t> word(other);
                CHECK(other == 1);
                CHECK(word == 1);
                /// [_5c070153_8529_46e5_b952_8c2cf67c6036]
            }

            TEST_CASE("move ctor() should copy value from other and set other's value to 0")
            {
                /// [_07a59a46_c898_4b85_ac6d_c1698c47f325]
                atomic_t<word_t> other(1);
                atomic_t<word_t> word(std::move(other));
                CHECK(other == 0);
                CHECK(word == 1);
                /// [_07a59a46_c898_4b85_ac6d_c1698c47f325]
            }

            TEST_CASE("copy assignment ctor() should copy value from other")
            {
                /// [_472c190e_8206_4293_b0af_850e9592b41c]
                atomic_t<word_t> other(1);
                atomic_t<word_t> word = other;
                CHECK(other == 1);
                CHECK(word == 1);
                /// [_472c190e_8206_4293_b0af_850e9592b41c]
            }

            TEST_CASE("move assignment ctor() should copy value from other and set other's value to 0")
            {
                /// [_ec9aefe8_321e_4d0b_b86f_8ed453e30f26]
                atomic_t<word_t> other(1);
                atomic_t<word_t> word = std::move(other);
                CHECK(other == 0);
                CHECK(word == 1);
                /// [_ec9aefe8_321e_4d0b_b86f_8ed453e30f26]
            }

            TEST_CASE("dtor() should set value to 0")
            {
                /// [_a9df6b8d_a04a_4ad9_a0ac_70755085d285]
                atomic_t<word_t> word(1);
                word.~atomic_t();
                CHECK(word == 0);
                /// [_a9df6b8d_a04a_4ad9_a0ac_70755085d285]
            }
        }

        TEST_SUITE("methods")
        {
            TEST_CASE("Access() should return value")
            {
                /// [_adfed710_462f_47b5_a8f6_06a5d804f627]
                const atomic_t<word_t> word(1);
                CHECK(word.Access() == 1);
                /// [_adfed710_462f_47b5_a8f6_06a5d804f627]
            }

            TEST_CASE("Access_Add() should return added value without changing its value")
            {
                /// [_46f1402b_959d_420a_bae4_ca259ff9d9e1]
                const atomic_t<word_t> word(1);
                CHECK(word.Access_Add(1) == 2);
                CHECK(word == 1);
                /// [_46f1402b_959d_420a_bae4_ca259ff9d9e1]
            }

            TEST_CASE("Access_Subtract() should return subtracted value without changing its value")
            {
                /// [_dccb8ff3_04bf_4a9a_8ee6_f391db782849]
                const atomic_t<word_t> word(1);
                CHECK(word.Access_Subtract(1) == 0);
                CHECK(word == 1);
                /// [_dccb8ff3_04bf_4a9a_8ee6_f391db782849]
            }

            TEST_CASE("Access_Or() should return or'd value without changing its value")
            {
                /// [_211b88b8_561b_41a0_8ff0_ba876a2383f7]
                const atomic_t<word_t> word(0x0F);
                CHECK(word.Access_Or(0xF0) == 0xFF);
                CHECK(word == 0x0F);
                /// [_211b88b8_561b_41a0_8ff0_ba876a2383f7]
            }

            TEST_CASE("Access_And() should return and'd value without changing its value")
            {
                /// [_523d0483_8274_42de_9e1e_eca1c2d6f70d]
                const atomic_t<word_t> word(0x0F);
                CHECK(word.Access_And(0xF0) == 0x00);
                CHECK(word == 0x0F);
                /// [_523d0483_8274_42de_9e1e_eca1c2d6f70d]
            }

            TEST_CASE("Access_Xor() should return xor'd value without changing its value")
            {
                /// [_00b6b746_dba9_47e9_9f72_4ad0cd27bbbb]
                const atomic_t<word_t> word(0xFF);
                CHECK(word.Access_Xor(0x01) == 0xFE);
                CHECK(word == 0xFF);
                /// [_00b6b746_dba9_47e9_9f72_4ad0cd27bbbb]
            }

            TEST_CASE("Assign() should set value and return the new value")
            {
                /// [_3c93c3f0_2be5_458c_80db_75a8daedc74d]
                atomic_t<word_t> word(1);
                CHECK(word.Assign(0) == 0);
                CHECK(word == 0);
                /// [_3c93c3f0_2be5_458c_80db_75a8daedc74d]
            }

            TEST_CASE("Assign_Add() should set added value and return the new value")
            {
                /// [_a57f19cb_38ff_41a0_b8b2_128b0dad7126]
                atomic_t<word_t> word(1);
                CHECK(word.Assign_Add(1) == 2);
                CHECK(word == 2);
                /// [_a57f19cb_38ff_41a0_b8b2_128b0dad7126]
            }

            TEST_CASE("Assign_Subtract() should set subtracted value and return the new value")
            {
                /// [_0fdf0919_b494_4069_9480_566020bfe783]
                atomic_t<word_t> word(1);
                CHECK(word.Assign_Subtract(1) == 0);
                CHECK(word == 0);
                /// [_0fdf0919_b494_4069_9480_566020bfe783]
            }

            TEST_CASE("Assign_Or() should set or'd value and return the new value")
            {
                /// [_c673f677_da1e_49e6_b779_f74b7fa25226]
                atomic_t<word_t> word(0x0F);
                CHECK(word.Assign_Or(0xF0) == 0xFF);
                CHECK(word == 0xFF);
                /// [_c673f677_da1e_49e6_b779_f74b7fa25226]
            }

            TEST_CASE("Assign_And() should set and'd value and return the new value")
            {
                /// [_0639d0e5_ec27_43b8_804f_4a20e409b521]
                atomic_t<word_t> word(0x0F);
                CHECK(word.Assign_And(0xF0) == 0x00);
                CHECK(word == 0x00);
                /// [_0639d0e5_ec27_43b8_804f_4a20e409b521]
            }

            TEST_CASE("Assign_Xor() should set xor'd value and return the new value")
            {
                /// [_714f2de4_3986_43f4_909c_6a2bf8f9f0e6]
                atomic_t<word_t> word(0xFF);
                CHECK(word.Assign_Xor(0x01) == 0xFE);
                CHECK(word == 0xFE);
                /// [_714f2de4_3986_43f4_909c_6a2bf8f9f0e6]
            }

            TEST_CASE("Exchange() should set value and return the old value")
            {
                /// [_594aca2c_64c3_499c_ba8c_6862c4aefa7c]
                atomic_t<word_t> word(1);
                CHECK(word.Exchange(0) == 1);
                CHECK(word == 0);
                /// [_594aca2c_64c3_499c_ba8c_6862c4aefa7c]
            }

            TEST_CASE("Exchange_If_Equals() should set value if old value equals target and return the old value")
            {
                /// [_d12decaa_a991_4c99_8eeb_4615e60f73bc]
                atomic_t<word_t> word(1);
                CHECK(word.Exchange_If_Equals(0, 0) == 1);
                CHECK(word == 1);
                CHECK(word.Exchange_If_Equals(0, 1) == 1);
                CHECK(word == 0);
                /// [_d12decaa_a991_4c99_8eeb_4615e60f73bc]
            }

            TEST_CASE("Exchange_Add() should set added value and return the old value")
            {
                /// [_fbcd609d_09ba_4cd3_9595_bf5cdcb4638d]
                atomic_t<word_t> word(1);
                CHECK(word.Exchange_Add(1) == 1);
                CHECK(word == 2);
                /// [_fbcd609d_09ba_4cd3_9595_bf5cdcb4638d]
            }

            TEST_CASE("Exchange_Subtract() should set subtracted value and return the old value")
            {
                /// [_ad01e70e_bd46_4aff_8074_31638d6f60fe]
                atomic_t<word_t> word(1);
                CHECK(word.Exchange_Subtract(1) == 1);
                CHECK(word == 0);
                /// [_ad01e70e_bd46_4aff_8074_31638d6f60fe]
            }

            TEST_CASE("Exchange_Or() should set or'd value and return the old value")
            {
                /// [_4be0459d_b5e7_4d60_8695_bd9277898e05]
                atomic_t<word_t> word(0x0F);
                CHECK(word.Exchange_Or(0xF0) == 0x0F);
                CHECK(word == 0xFF);
                /// [_4be0459d_b5e7_4d60_8695_bd9277898e05]
            }

            TEST_CASE("Exchange_And() should set and'd value and return the old value")
            {
                /// [_0ece1cfd_2281_4b1e_85a8_00d0a1ec97ff]
                atomic_t<word_t> word(0x0F);
                CHECK(word.Exchange_And(0xF0) == 0x0F);
                CHECK(word == 0x00);
                /// [_0ece1cfd_2281_4b1e_85a8_00d0a1ec97ff]
            }

            TEST_CASE("Exchange_Xor() should set xor'd value and return the old value")
            {
                /// [_8373f8d7_2ac6_405a_968e_ebb7aaa5b88f]
                atomic_t<word_t> word(0xFF);
                CHECK(word.Exchange_Xor(0x01) == 0xFF);
                CHECK(word == 0xFE);
                /// [_8373f8d7_2ac6_405a_968e_ebb7aaa5b88f]
            }
        }

        TEST_SUITE("casts")
        {
            TEST_CASE("value_t() should cast to its value_t")
            {
                /// [_57e9ca8c_6b33_450f_9c49_3c2b26b356c7]
                atomic_t<word_t> word(1);
                CHECK(static_cast<atomic_t<word_t>::value_t>(word) == 1);
                CHECK(word == 1);
                CHECK(static_cast<bool_t>(word) == true);
                CHECK(!word == false);

                word = 0;
                CHECK(word == 0);
                CHECK(static_cast<bool_t>(word) == false);
                CHECK(!word == true);
                /// [_57e9ca8c_6b33_450f_9c49_3c2b26b356c7]
            }
        }

        TEST_SUITE("operators")
        {
            TEST_CASE("()() should return its value")
            {
                /// [_994aab1a_8a70_4833_922e_7d40f7c2677b]
                atomic_t<word_t> word(1);
                CHECK(word() == 1);
                /// [_994aab1a_8a70_4833_922e_7d40f7c2677b]
            }

            TEST_CASE("=() should set its value to other")
            {
                /// [_61d042d0_7e8c_4cd9_a6dd_fd5b307a2fe3]
                atomic_t<word_t> word(0);
                word = 1;
                CHECK(word == 1);
                /// [_61d042d0_7e8c_4cd9_a6dd_fd5b307a2fe3]
            }

            TEST_CASE("+() should return the result of value + other without changing value")
            {
                /// [_69b1e964_4cae_4e08_bfb4_612f7db49e11]
                atomic_t<word_t> word(1);
                CHECK(word + 1 == 2);
                CHECK(word == 1);
                /// [_69b1e964_4cae_4e08_bfb4_612f7db49e11]
            }

            TEST_CASE("-() should return the result of value - other without changing value")
            {
                /// [_17417e1a_54d0_409b_a995_6a3b12186cff]
                atomic_t<word_t> word(1);
                CHECK(word - 1 == 0);
                CHECK(word == 1);
                /// [_17417e1a_54d0_409b_a995_6a3b12186cff]
            }

            TEST_CASE("+=() should set value to value + other")
            {
                /// [_f40394f7_a468_4089_95ce_fdbc31406bb3]
                atomic_t<word_t> word(1);
                CHECK((word += 1) == 2);
                CHECK(word == 2);
                /// [_f40394f7_a468_4089_95ce_fdbc31406bb3]
            }

            TEST_CASE("-=() should set value to value - other")
            {
                /// [_8d6fdd08_f4a0_4e23_b96c_8d1a5ed1ef4b]
                atomic_t<word_t> word(1);
                CHECK((word -= 1) == 0);
                CHECK(word == 0);
                /// [_8d6fdd08_f4a0_4e23_b96c_8d1a5ed1ef4b]
            }

            TEST_CASE("++() should increment value and return the new value")
            {
                /// [_9aef2e48_7c4e_4922_816b_3b3652cc7255]
                atomic_t<word_t> word(1);
                CHECK(++word == 2);
                CHECK(word == 2);
                /// [_9aef2e48_7c4e_4922_816b_3b3652cc7255]
            }

            TEST_CASE("++(int) should increment value and return the initial value")
            {
                /// [_8127f3b7_cf0d_44f4_8186_c06a0fe2e1cf]
                atomic_t<word_t> word(1);
                CHECK(word++ == 1);
                CHECK(word == 2);
                /// [_8127f3b7_cf0d_44f4_8186_c06a0fe2e1cf]
            }

            TEST_CASE("--() should decrement value and return the new value")
            {
                /// [_10424556_071d_41df_bf13_8c560e7e4818]
                atomic_t<word_t> word(1);
                CHECK(--word == 0);
                CHECK(word == 0);
                /// [_10424556_071d_41df_bf13_8c560e7e4818]
            }

            TEST_CASE("--(int) should decrement value and return the initial value")
            {
                /// [_f8c3551b_4056_4767_a871_39f907f5a605]
                atomic_t<word_t> word(1);
                CHECK(word-- == 1);
                CHECK(word == 0);
                /// [_f8c3551b_4056_4767_a871_39f907f5a605]
            }

            TEST_CASE("~() should return ~value without changing value")
            {
                /// [_0ef480f9_2e50_44ae_906e_06290ae4b02c]
                atomic_t<u8_t> u8(0x0F);
                CHECK(~u8 == 0xF0);
                CHECK(u8 == 0x0F);
                /// [_0ef480f9_2e50_44ae_906e_06290ae4b02c]
            }

            TEST_CASE("|() should return value | other without changing value")
            {
                /// [_79a5a894_6d6e_4096_9d1f_b0ef474c4623]
                atomic_t<u8_t> u8(0x0F);
                CHECK((u8 | 0xF0) == 0xFF);
                CHECK(u8 == 0x0F);
                /// [_79a5a894_6d6e_4096_9d1f_b0ef474c4623]
            }

            TEST_CASE("&() should return value & other without changing value")
            {
                /// [_4b8cfb03_f1db_409f_98c0_af859a7df034]
                atomic_t<u8_t> u8(0x0F);
                CHECK((u8 & 0xF0) == 0x0);
                CHECK(u8 == 0x0F);
                /// [_4b8cfb03_f1db_409f_98c0_af859a7df034]
            }

            TEST_CASE("^() should return value ^ other without changing value")
            {
                /// [_58735e13_a335_4d94_be28_3772ed3b8c32]
                atomic_t<u8_t> u8(0xFF);
                CHECK((u8 ^ 0x01) == 0xFE);
                CHECK(u8 == 0xFF);
                /// [_58735e13_a335_4d94_be28_3772ed3b8c32]
            }

            TEST_CASE("|=() should set value |= other")
            {
                /// [_91137373_aa0b_4493_9960_68f8d421ae18]
                atomic_t<u8_t> u8(0x0F);
                CHECK((u8 |= 0xF0) == 0xFF);
                CHECK(u8 == 0xFF);
                /// [_91137373_aa0b_4493_9960_68f8d421ae18]
            }

            TEST_CASE("&=() should set value &= other")
            {
                /// [_988587e7_6e13_4a79_8adb_907c88761d3f]
                atomic_t<u8_t> u8(0x0F);
                CHECK((u8 &= 0xF0) == 0x0);
                CHECK(u8 == 0x0);
                /// [_988587e7_6e13_4a79_8adb_907c88761d3f]
            }

            TEST_CASE("^=() should set value ^= other")
            {
                /// [_02a3d15d_9185_444b_b751_1d4231542c29]
                atomic_t<u8_t> u8(0xFF);
                CHECK((u8 ^= 0x01) == 0xFE);
                CHECK(u8 == 0xFE);
                /// [_02a3d15d_9185_444b_b751_1d4231542c29]
            }
        }

        TEST_SUITE("none_t interface")
        {
            TEST_CASE("=(none_t) should set its value to the default value and return itself")
            {
                /// [_5cd9bae8_73e2_4656_8987_bdd39472257b]
                atomic_t<word_t> word(1);
                CHECK(word != atomic_t<word_t>::DEFAULT_VALUE);
                CHECK(&(word = none_t()) == &word);
                CHECK(word == atomic_t<word_t>::DEFAULT_VALUE);
                /// [_5cd9bae8_73e2_4656_8987_bdd39472257b]
            }

            TEST_CASE("==(none_t) should return true if the value is the default, else false")
            {
                /// [_234da0e9_f786_4f96_bac8_8c770ee445f1]
                atomic_t<word_t> word(1);
                CHECK(!(word == none_t()));
                word = none_t();
                CHECK((word == none_t()));
                /// [_234da0e9_f786_4f96_bac8_8c770ee445f1]
            }

            TEST_CASE("!=(none_t) should return true if the value is not the default, else false")
            {
                /// [_33e7ab8b_f658_430a_ad5b_05f722975e85]
                atomic_t<word_t> word(1);
                CHECK((word != none_t()));
                word = none_t();
                CHECK(!(word != none_t()));
                /// [_33e7ab8b_f658_430a_ad5b_05f722975e85]
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

            TEST_CASE("Exchange_If_Equals() should set value if old value equals target and return the old value")
            {
                /// [_42437d1a_4adb_47e7_ae54_8614e79adcfd]
                word_t word = 1;
                atomic_t<word_t*> pointer(&word);
                CHECK(pointer.Exchange_If_Equals(nullptr, nullptr) == &word);
                CHECK(pointer == &word);
                CHECK(pointer.Exchange_If_Equals(nullptr, &word) == &word);
                CHECK(pointer == nullptr);
                /// [_42437d1a_4adb_47e7_ae54_8614e79adcfd]
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

            TEST_CASE("Exchange_If_Equals() should set value if old value equals target and return the old value")
            {
                /// [_bbf28d7d_3852_4066_b9f5_6acaf2b45d09]
                word_t word = 1;
                atomic_t<void_t*> pointer(&word);
                CHECK(pointer.Exchange_If_Equals(nullptr, nullptr) == &word);
                CHECK(pointer == &word);
                CHECK(pointer.Exchange_If_Equals(nullptr, &word) == &word);
                CHECK(pointer == nullptr);
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
