/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/atomic_t.h"

#include "intrinsics.h"

namespace nkr {

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
            TEST_CASE("[]() should [] the indexed object of value")
            {
                /// [_79ec7297_c9db_4756_a956_b9e4020bb643]
                word_t words[2] = { 0, 1 };
                auto pointer(words);
                CHECK(pointer[1] == 1);
                /// [_79ec7297_c9db_4756_a956_b9e4020bb643]
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
