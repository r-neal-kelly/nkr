/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include <thread>

#include "nkr/bool_t.h"
#include "nkr/os.h"

#include "intrinsics.h"

namespace nkr { namespace os { namespace atomic {

    TEST_SUITE("Access")
    {
        TEST_SUITE("should return value without changing it")
        {
            TEST_CASE("bool_t")
            {
                /// [_3238c9b6_810a_4359_9efa_89f92fd365ef]
                bool_t boolean = false;
                bool_t access = nkr::os::atomic::Access(boolean);
                CHECK(nkr::os::atomic::Access(boolean) == access);
                CHECK(nkr::os::atomic::Access(boolean) == false);
                /// [_3238c9b6_810a_4359_9efa_89f92fd365ef]
            }
            TEST_CASE("std_bool_t")
            {
                /// [_c8da39aa_8f8f_4011_a481_167533351c72]
                std_bool_t boolean = false;
                std_bool_t access = nkr::os::atomic::Access(boolean);
                CHECK(nkr::os::atomic::Access(boolean) == access);
                CHECK(nkr::os::atomic::Access(boolean) == false);
                /// [_c8da39aa_8f8f_4011_a481_167533351c72]
            }
            TEST_CASE("u8_t")
            {
                /// [_08f69e89_8a87_46ac_b2be_acd825b948f5]
                u8_t u8 = 8;
                u8_t access = nkr::os::atomic::Access(u8);
                CHECK(nkr::os::atomic::Access(u8) == access);
                CHECK(nkr::os::atomic::Access(u8) == 8);
                /// [_08f69e89_8a87_46ac_b2be_acd825b948f5]
            }
            TEST_CASE("s8_t")
            {
                /// [_29ed1245_2598_46ef_9bfe_0b73ca7e55b7]
                s8_t s8 = -8;
                s8_t access = nkr::os::atomic::Access(s8);
                CHECK(nkr::os::atomic::Access(s8) == access);
                CHECK(nkr::os::atomic::Access(s8) == -8);
                /// [_29ed1245_2598_46ef_9bfe_0b73ca7e55b7]
            }
            TEST_CASE("u16_t")
            {
                /// [_7e52c0a5_32cb_4b12_ac9f_b5cb49240274]
                u16_t u16 = 16;
                u16_t access = nkr::os::atomic::Access(u16);
                CHECK(nkr::os::atomic::Access(u16) == access);
                CHECK(nkr::os::atomic::Access(u16) == 16);
                /// [_7e52c0a5_32cb_4b12_ac9f_b5cb49240274]
            }
            TEST_CASE("s16_t")
            {
                /// [_35425ec6_018f_4119_b5f9_13803165ea8c]
                s16_t s16 = -16;
                s16_t access = nkr::os::atomic::Access(s16);
                CHECK(nkr::os::atomic::Access(s16) == access);
                CHECK(nkr::os::atomic::Access(s16) == -16);
                /// [_35425ec6_018f_4119_b5f9_13803165ea8c]
            }
            TEST_CASE("u32_t")
            {
                /// [_04ee7397_965b_4041_be9e_708a89f62a5a]
                u32_t u32 = 32;
                u32_t access = nkr::os::atomic::Access(u32);
                CHECK(nkr::os::atomic::Access(u32) == access);
                CHECK(nkr::os::atomic::Access(u32) == 32);
                /// [_04ee7397_965b_4041_be9e_708a89f62a5a]
            }
            TEST_CASE("s32_t")
            {
                /// [_42820a17_fd2b_4ee4_8a56_7b3f7d1c8693]
                s32_t s32 = -32;
                s32_t access = nkr::os::atomic::Access(s32);
                CHECK(nkr::os::atomic::Access(s32) == access);
                CHECK(nkr::os::atomic::Access(s32) == -32);
                /// [_42820a17_fd2b_4ee4_8a56_7b3f7d1c8693]
            }
            TEST_CASE("u64_t")
            {
            #if defined(nkr_IS_64_BIT)
                /// [_34ad7375_d81b_4dd7_9b71_0414d9c0f5c5]
                u64_t u64 = 64;
                u64_t access = nkr::os::atomic::Access(u64);
                CHECK(nkr::os::atomic::Access(u64) == access);
                CHECK(nkr::os::atomic::Access(u64) == 64);
                /// [_34ad7375_d81b_4dd7_9b71_0414d9c0f5c5]
            #endif
            }
            TEST_CASE("s64_t")
            {
            #if defined(nkr_IS_64_BIT)
                /// [_c2dbe569_37b0_4573_8745_031b9ed85df7]
                s64_t s64 = -64;
                s64_t access = nkr::os::atomic::Access(s64);
                CHECK(nkr::os::atomic::Access(s64) == access);
                CHECK(nkr::os::atomic::Access(s64) == -64);
                /// [_c2dbe569_37b0_4573_8745_031b9ed85df7]
            #endif
            }
            TEST_CASE("f32_t")
            {
                /// [_20fdaaf3_07c1_4089_9a24_4e397b0a69d3]
                f32_t f32 = 3.2f;
                f32_t access = nkr::os::atomic::Access(f32);
                CHECK(nkr::os::atomic::Access(f32) == access);
                CHECK(nkr::os::atomic::Access(f32) == 3.2f);
                /// [_20fdaaf3_07c1_4089_9a24_4e397b0a69d3]
            }
            TEST_CASE("f64_t")
            {
            #if defined(nkr_IS_64_BIT)
                /// [_47df9d0d_8512_484e_9b3c_f2d595a3446a]
                f64_t f64 = 6.4;
                f64_t access = nkr::os::atomic::Access(f64);
                CHECK(nkr::os::atomic::Access(f64) == access);
                CHECK(nkr::os::atomic::Access(f64) == 6.4);
                /// [_47df9d0d_8512_484e_9b3c_f2d595a3446a]
            #endif
            }
            TEST_CASE("void_t*")
            {
                /// [_4e3e00da_6965_4bb2_a0c6_657b6431c27c]
                void_t* void_pointer = nullptr;
                void_t* access = nkr::os::atomic::Access(void_pointer);
                CHECK(nkr::os::atomic::Access(void_pointer) == access);
                CHECK(nkr::os::atomic::Access(void_pointer) == nullptr);
                /// [_4e3e00da_6965_4bb2_a0c6_657b6431c27c]
            }
            TEST_CASE("bool_t*")
            {
                /// [_a9d44556_1f4a_4e9c_bfe7_04e92348429f]
                bool_t boolean = false;
                bool_t* boolean_pointer = &boolean;
                bool_t* access = nkr::os::atomic::Access(boolean_pointer);
                CHECK(nkr::os::atomic::Access(boolean_pointer) == access);
                CHECK(nkr::os::atomic::Access(boolean_pointer) == &boolean);
                /// [_a9d44556_1f4a_4e9c_bfe7_04e92348429f]
            }
        }
    }

    TEST_SUITE("Access_Add")
    {
        TEST_SUITE("should return added values without changing the original")
        {
            TEST_CASE("u8_t")
            {
                /// [_36c74dfe_b932_45ed_a151_b69ed535576a]
                u8_t u8 = 8;
                CHECK(nkr::os::atomic::Access_Add(u8, 1) == 9);
                CHECK(u8 == 8);
                /// [_36c74dfe_b932_45ed_a151_b69ed535576a]
            }
            TEST_CASE("s8_t")
            {
                /// [_d4206571_4483_45a1_9248_71c92cce98c0]
                s8_t s8 = -8;
                CHECK(nkr::os::atomic::Access_Add(s8, -1) == -9);
                CHECK(s8 == -8);
                /// [_d4206571_4483_45a1_9248_71c92cce98c0]
            }
            TEST_CASE("u16_t")
            {
                /// [_6e51bfcd_68ac_476e_9e4b_babe914acc01]
                u16_t u16 = 16;
                CHECK(nkr::os::atomic::Access_Add(u16, 1) == 17);
                CHECK(u16 == 16);
                /// [_6e51bfcd_68ac_476e_9e4b_babe914acc01]
            }
            TEST_CASE("s16_t")
            {
                /// [_e3defcc3_bb05_4701_8df9_740b697fcd3b]
                s16_t s16 = -16;
                CHECK(nkr::os::atomic::Access_Add(s16, -1) == -17);
                CHECK(s16 == -16);
                /// [_e3defcc3_bb05_4701_8df9_740b697fcd3b]
            }
            TEST_CASE("u32_t")
            {
                /// [_5f2fbf98_28e5_4465_80eb_91a397fda017]
                u32_t u32 = 32;
                CHECK(nkr::os::atomic::Access_Add(u32, 1) == 33);
                CHECK(u32 == 32);
                /// [_5f2fbf98_28e5_4465_80eb_91a397fda017]
            }
            TEST_CASE("s32_t")
            {
                /// [_c0a531a5_240d_4247_ac2a_b50f22da6e97]
                s32_t s32 = -32;
                CHECK(nkr::os::atomic::Access_Add(s32, -1) == -33);
                CHECK(s32 == -32);
                /// [_c0a531a5_240d_4247_ac2a_b50f22da6e97]
            }
            TEST_CASE("u64_t")
            {
            #if defined(nkr_IS_64_BIT)
                /// [_e2b48d79_b0a9_4b7a_a783_39c50522ec30]
                u64_t u64 = 64;
                CHECK(nkr::os::atomic::Access_Add(u64, 1) == 65);
                CHECK(u64 == 64);
                /// [_e2b48d79_b0a9_4b7a_a783_39c50522ec30]
            #endif
            }
            TEST_CASE("s64_t")
            {
            #if defined(nkr_IS_64_BIT)
                /// [_089fa26d_70c1_479e_8e8e_bfaa75d70540]
                s64_t s64 = -64;
                CHECK(nkr::os::atomic::Access_Add(s64, -1) == -65);
                CHECK(s64 == -64);
                /// [_089fa26d_70c1_479e_8e8e_bfaa75d70540]
            #endif
            }
            TEST_CASE("f32_t")
            {
                /// [_6e3f5a0f_d32f_426e_a815_99cbab82c138]
                f32_t f32 = 3.2f;
                CHECK(nkr::os::atomic::Access_Add(f32, 0.1f) == 3.2f + 0.1f);
                CHECK(f32 == 3.2f);
                /// [_6e3f5a0f_d32f_426e_a815_99cbab82c138]
            }
            TEST_CASE("f64_t")
            {
            #if defined(nkr_IS_64_BIT)
                /// [_a8fbd7c4_02d9_47a2_9750_cba9ce0f4f6f]
                f64_t f64 = 6.4;
                CHECK(nkr::os::atomic::Access_Add(f64, 0.1) == 6.4 + 0.1);
                CHECK(f64 == 6.4);
                /// [_a8fbd7c4_02d9_47a2_9750_cba9ce0f4f6f]
            #endif
            }
            TEST_CASE("bool_t*")
            {
                /// [_8942a2b0_a61d_4279_bd24_ebd5d64e3bc2]
                bool_t booleans[2] = { true, true };
                bool_t* boolean_pointer = booleans;
                CHECK(nkr::os::atomic::Access_Add(boolean_pointer, 1) == booleans + 1);
                CHECK(boolean_pointer == booleans + 0);
                /// [_8942a2b0_a61d_4279_bd24_ebd5d64e3bc2]
            }
        }
    }

    TEST_SUITE("Access_Subtract")
    {
        TEST_SUITE("should return subtracted values without changing the original")
        {
            TEST_CASE("u8_t")
            {
                /// [_b616821a_2b20_4f12_9580_a86cfcca3373]
                u8_t u8 = 8;
                CHECK(nkr::os::atomic::Access_Subtract(u8, 1) == 7);
                CHECK(u8 == 8);
                /// [_b616821a_2b20_4f12_9580_a86cfcca3373]
            }
            TEST_CASE("s8_t")
            {
                /// [_d1afa205_483a_40a6_ad20_9c9547fb01e2]
                s8_t s8 = -8;
                CHECK(nkr::os::atomic::Access_Subtract(s8, -1) == -7);
                CHECK(s8 == -8);
                /// [_d1afa205_483a_40a6_ad20_9c9547fb01e2]
            }
            TEST_CASE("u16_t")
            {
                /// [_cc65b320_1a0a_4f4b_8fb4_eadad44f9f39]
                u16_t u16 = 16;
                CHECK(nkr::os::atomic::Access_Subtract(u16, 1) == 15);
                CHECK(u16 == 16);
                /// [_cc65b320_1a0a_4f4b_8fb4_eadad44f9f39]
            }
            TEST_CASE("s16_t")
            {
                /// [_45167bc8_3d4a_414b_b0b1_90b9e5c544f1]
                s16_t s16 = -16;
                CHECK(nkr::os::atomic::Access_Subtract(s16, -1) == -15);
                CHECK(s16 == -16);
                /// [_45167bc8_3d4a_414b_b0b1_90b9e5c544f1]
            }
            TEST_CASE("u32_t")
            {
                /// [_389090dd_7dfa_4c6c_9d52_cdcc1039d336]
                u32_t u32 = 32;
                CHECK(nkr::os::atomic::Access_Subtract(u32, 1) == 31);
                CHECK(u32 == 32);
                /// [_389090dd_7dfa_4c6c_9d52_cdcc1039d336]
            }
            TEST_CASE("s32_t")
            {
                /// [_9a215228_aed5_4de2_830e_1ede68581cf1]
                s32_t s32 = -32;
                CHECK(nkr::os::atomic::Access_Subtract(s32, -1) == -31);
                CHECK(s32 == -32);
                /// [_9a215228_aed5_4de2_830e_1ede68581cf1]
            }
            TEST_CASE("u64_t")
            {
            #if defined(nkr_IS_64_BIT)
                /// [_d5189f8d_7d2c_4f02_9578_11fb36ebf4b4]
                u64_t u64 = 64;
                CHECK(nkr::os::atomic::Access_Subtract(u64, 1) == 63);
                CHECK(u64 == 64);
                /// [_d5189f8d_7d2c_4f02_9578_11fb36ebf4b4]
            #endif
            }
            TEST_CASE("s64_t")
            {
            #if defined(nkr_IS_64_BIT)
                /// [_5dc71bd5_4d2b_48a5_818b_baa86032959f]
                s64_t s64 = -64;
                CHECK(nkr::os::atomic::Access_Subtract(s64, -1) == -63);
                CHECK(s64 == -64);
                /// [_5dc71bd5_4d2b_48a5_818b_baa86032959f]
            #endif
            }
            TEST_CASE("f32_t")
            {
                /// [_dd66dcb3_3f16_42e2_a745_66010d680ac3]
                f32_t f32 = 3.2f;
                CHECK(nkr::os::atomic::Access_Subtract(f32, 0.1f) == 3.2f - 0.1f);
                CHECK(f32 == 3.2f);
                /// [_dd66dcb3_3f16_42e2_a745_66010d680ac3]
            }
            TEST_CASE("f64_t")
            {
            #if defined(nkr_IS_64_BIT)
                /// [_b5c8672e_f1c0_4707_9fff_1c86557fe11a]
                f64_t f64 = 6.4;
                CHECK(nkr::os::atomic::Access_Subtract(f64, 0.1) == 6.4 - 0.1);
                CHECK(f64 == 6.4);
                /// [_b5c8672e_f1c0_4707_9fff_1c86557fe11a]
            #endif
            }
            TEST_CASE("bool_t*")
            {
                /// [_cdbd7b3e_2160_4862_9da9_4795df53b57e]
                bool_t booleans[2] = { true, true };
                bool_t* boolean_pointer = booleans + 1;
                CHECK(nkr::os::atomic::Access_Subtract(boolean_pointer, 1) == booleans + 0);
                CHECK(boolean_pointer == booleans + 1);
                /// [_cdbd7b3e_2160_4862_9da9_4795df53b57e]
            }
        }
    }

    TEST_SUITE("Access_Multiply()")
    {
        TEST_SUITE("should value * operand without changing its original value")
        {
            TEST_CASE("u8_t")
            {
                /// [_b64d7ad3_fd09_4140_9cf7_3827b52b021e]
                u8_t u8 = 8;
                CHECK(nkr::os::atomic::Access_Multiply(u8, 2) == 16);
                CHECK(nkr::os::atomic::Access(u8) == 8);
                /// [_b64d7ad3_fd09_4140_9cf7_3827b52b021e]
            }
            TEST_CASE("s8_t")
            {
                /// [_50599139_8d1b_4ecb_96b7_c468a34f9168]
                s8_t s8 = -8;
                CHECK(nkr::os::atomic::Access_Multiply(s8, 2) == -16);
                CHECK(nkr::os::atomic::Access(s8) == -8);
                /// [_50599139_8d1b_4ecb_96b7_c468a34f9168]
            }
            TEST_CASE("u16_t")
            {
                /// [_ae5fd631_7134_49c4_8d3b_869bfc88e65c]
                u16_t u16 = 16;
                CHECK(nkr::os::atomic::Access_Multiply(u16, 2) == 32);
                CHECK(nkr::os::atomic::Access(u16) == 16);
                /// [_ae5fd631_7134_49c4_8d3b_869bfc88e65c]
            }
            TEST_CASE("s16_t")
            {
                /// [_15875252_7ec0_4dc3_af55_6f162c5396d0]
                s16_t s16 = -16;
                CHECK(nkr::os::atomic::Access_Multiply(s16, 2) == -32);
                CHECK(nkr::os::atomic::Access(s16) == -16);
                /// [_15875252_7ec0_4dc3_af55_6f162c5396d0]
            }
            TEST_CASE("u32_t")
            {
                /// [_8d36a7a4_5792_4fa6_98d9_7602c7300b03]
                u32_t u32 = 32;
                CHECK(nkr::os::atomic::Access_Multiply(u32, 2) == 64);
                CHECK(nkr::os::atomic::Access(u32) == 32);
                /// [_8d36a7a4_5792_4fa6_98d9_7602c7300b03]
            }
            TEST_CASE("s32_t")
            {
                /// [_ed305888_4919_4814_87ee_56eef0eeab44]
                s32_t s32 = -32;
                CHECK(nkr::os::atomic::Access_Multiply(s32, 2) == -64);
                CHECK(nkr::os::atomic::Access(s32) == -32);
                /// [_ed305888_4919_4814_87ee_56eef0eeab44]
            }
            TEST_CASE("u64_t")
            {
            #if defined(nkr_IS_64_BIT)
                /// [_99324fff_7f7e_4df8_9a2f_45527089b829]
                u64_t u64 = 64;
                CHECK(nkr::os::atomic::Access_Multiply(u64, 2) == 128);
                CHECK(nkr::os::atomic::Access(u64) == 64);
                /// [_99324fff_7f7e_4df8_9a2f_45527089b829]
            #endif
            }
            TEST_CASE("s64_t")
            {
            #if defined(nkr_IS_64_BIT)
                /// [_b7600ccc_fe86_4d06_ac74_31027989c3c5]
                s64_t s64 = -64;
                CHECK(nkr::os::atomic::Access_Multiply(s64, 2) == -128);
                CHECK(nkr::os::atomic::Access(s64) == -64);
                /// [_b7600ccc_fe86_4d06_ac74_31027989c3c5]
            #endif
            }
            TEST_CASE("f32_t")
            {
                /// [_d248006b_9512_4cf8_9b5c_80dc49d4e47b]
                f32_t f32 = 3.2f;
                CHECK(nkr::os::atomic::Access_Multiply(f32, 0.1f) == 3.2f * 0.1f);
                CHECK(nkr::os::atomic::Access(f32) == 3.2f);
                /// [_d248006b_9512_4cf8_9b5c_80dc49d4e47b]
            }
            TEST_CASE("f64_t")
            {
            #if defined(nkr_IS_64_BIT)
                /// [_20a330a8_742c_469c_83dd_639ccf054600]
                f64_t f64 = 6.4;
                CHECK(nkr::os::atomic::Access_Multiply(f64, 0.1) == 6.4 * 0.1);
                CHECK(nkr::os::atomic::Access(f64) == 6.4);
                /// [_20a330a8_742c_469c_83dd_639ccf054600]
            #endif
            }
        }
    }

    TEST_SUITE("Access_Divide()")
    {
        TEST_SUITE("should value / operand without changing the original value")
        {
            TEST_CASE("u8_t")
            {
                /// [_9920fa6e_f2f1_4438_a1be_127a62c9db73]
                u8_t u8 = 8;
                CHECK(nkr::os::atomic::Access_Divide(u8, 2) == 4);
                CHECK(nkr::os::atomic::Access(u8) == 8);
                /// [_9920fa6e_f2f1_4438_a1be_127a62c9db73]
            }
            TEST_CASE("s8_t")
            {
                /// [_ce5717be_77df_4713_83c1_278c2492df6e]
                s8_t s8 = -8;
                CHECK(nkr::os::atomic::Access_Divide(s8, 2) == -4);
                CHECK(nkr::os::atomic::Access(s8) == -8);
                /// [_ce5717be_77df_4713_83c1_278c2492df6e]
            }
            TEST_CASE("u16_t")
            {
                /// [_ee64d3c3_aab4_48dc_acec_2ea1c0baba96]
                u16_t u16 = 16;
                CHECK(nkr::os::atomic::Access_Divide(u16, 2) == 8);
                CHECK(nkr::os::atomic::Access(u16) == 16);
                /// [_ee64d3c3_aab4_48dc_acec_2ea1c0baba96]
            }
            TEST_CASE("s16_t")
            {
                /// [_b555876b_c263_4312_bb81_60cd251099df]
                s16_t s16 = -16;
                CHECK(nkr::os::atomic::Access_Divide(s16, 2) == -8);
                CHECK(nkr::os::atomic::Access(s16) == -16);
                /// [_b555876b_c263_4312_bb81_60cd251099df]
            }
            TEST_CASE("u32_t")
            {
                /// [_ae7bc9f1_6bf9_4a8c_a89a_fe898b665f4e]
                u32_t u32 = 32;
                CHECK(nkr::os::atomic::Access_Divide(u32, 2) == 16);
                CHECK(nkr::os::atomic::Access(u32) == 32);
                /// [_ae7bc9f1_6bf9_4a8c_a89a_fe898b665f4e]
            }
            TEST_CASE("s32_t")
            {
                /// [_55149295_f534_4763_bca5_9f92f5787150]
                s32_t s32 = -32;
                CHECK(nkr::os::atomic::Access_Divide(s32, 2) == -16);
                CHECK(nkr::os::atomic::Access(s32) == -32);
                /// [_55149295_f534_4763_bca5_9f92f5787150]
            }
            TEST_CASE("u64_t")
            {
            #if defined(nkr_IS_64_BIT)
                /// [_0c9490a7_0dac_4027_a5ed_c698465851f3]
                u64_t u64 = 64;
                CHECK(nkr::os::atomic::Access_Divide(u64, 2) == 32);
                CHECK(nkr::os::atomic::Access(u64) == 64);
                /// [_0c9490a7_0dac_4027_a5ed_c698465851f3]
            #endif
            }
            TEST_CASE("s64_t")
            {
            #if defined(nkr_IS_64_BIT)
                /// [_844bc762_1168_4f79_bb35_79444617d12b]
                s64_t s64 = -64;
                CHECK(nkr::os::atomic::Access_Divide(s64, 2) == -32);
                CHECK(nkr::os::atomic::Access(s64) == -64);
                /// [_844bc762_1168_4f79_bb35_79444617d12b]
            #endif
            }
            TEST_CASE("f32_t")
            {
                /// [_a12d9b59_aad0_4b05_8e46_350ed28bc418]
                f32_t f32 = 3.2f;
                CHECK(nkr::os::atomic::Access_Divide(f32, 0.1f) == 3.2f / 0.1f);
                CHECK(nkr::os::atomic::Access(f32) == 3.2f);
                /// [_a12d9b59_aad0_4b05_8e46_350ed28bc418]
            }
            TEST_CASE("f64_t")
            {
            #if defined(nkr_IS_64_BIT)
                /// [_0725562e_aeee_4b3e_8f8e_09413e4a99d7]
                f64_t f64 = 6.4;
                CHECK(nkr::os::atomic::Access_Divide(f64, 0.1) == 6.4 / 0.1);
                CHECK(nkr::os::atomic::Access(f64) == 6.4);
                /// [_0725562e_aeee_4b3e_8f8e_09413e4a99d7]
            #endif
            }
        }
    }

    TEST_SUITE("Access_Modulus()")
    {
        TEST_SUITE("should value % operand without changing the original value")
        {
            TEST_CASE("u8_t")
            {
                /// [_4b38422d_163c_4940_897f_8ec9d45fdc66]
                u8_t u8 = 8;
                CHECK(nkr::os::atomic::Access_Modulus(u8, 3) == 2);
                CHECK(nkr::os::atomic::Access(u8) == 8);
                /// [_4b38422d_163c_4940_897f_8ec9d45fdc66]
            }
            TEST_CASE("s8_t")
            {
                /// [_b3878173_baba_441f_b2cf_a7e8851f9314]
                s8_t s8 = -8;
                CHECK(nkr::os::atomic::Access_Modulus(s8, 3) == -2);
                CHECK(nkr::os::atomic::Access(s8) == -8);
                /// [_b3878173_baba_441f_b2cf_a7e8851f9314]
            }
            TEST_CASE("u16_t")
            {
                /// [_b5f9ff3f_e311_4785_a2ff_5a8bc4b7580a]
                u16_t u16 = 16;
                CHECK(nkr::os::atomic::Access_Modulus(u16, 3) == 1);
                CHECK(nkr::os::atomic::Access(u16) == 16);
                /// [_b5f9ff3f_e311_4785_a2ff_5a8bc4b7580a]
            }
            TEST_CASE("s16_t")
            {
                /// [_cc045edb_cf1d_439e_b287_bd8ed67014fa]
                s16_t s16 = -16;
                CHECK(nkr::os::atomic::Access_Modulus(s16, 3) == -1);
                CHECK(nkr::os::atomic::Access(s16) == -16);
                /// [_cc045edb_cf1d_439e_b287_bd8ed67014fa]
            }
            TEST_CASE("u32_t")
            {
                /// [_09f41b80_0168_4dbd_8d51_01d096d3bf4e]
                u32_t u32 = 32;
                CHECK(nkr::os::atomic::Access_Modulus(u32, 3) == 2);
                CHECK(nkr::os::atomic::Access(u32) == 32);
                /// [_09f41b80_0168_4dbd_8d51_01d096d3bf4e]
            }
            TEST_CASE("s32_t")
            {
                /// [_1c1a9beb_7764_4d54_8d6e_3447a1aa2644]
                s32_t s32 = -32;
                CHECK(nkr::os::atomic::Access_Modulus(s32, 3) == -2);
                CHECK(nkr::os::atomic::Access(s32) == -32);
                /// [_1c1a9beb_7764_4d54_8d6e_3447a1aa2644]
            }
            TEST_CASE("u64_t")
            {
            #if defined(nkr_IS_64_BIT)
                /// [_025ef7d1_6711_4e39_b0a6_c5275b4ff5a1]
                u64_t u64 = 64;
                CHECK(nkr::os::atomic::Access_Modulus(u64, 3) == 1);
                CHECK(nkr::os::atomic::Access(u64) == 64);
                /// [_025ef7d1_6711_4e39_b0a6_c5275b4ff5a1]
            #endif
            }
            TEST_CASE("s64_t")
            {
            #if defined(nkr_IS_64_BIT)
                /// [_e65e47e3_e69f_49ae_a492_5198a35e383f]
                s64_t s64 = -64;
                CHECK(nkr::os::atomic::Access_Modulus(s64, 3) == -1);
                CHECK(nkr::os::atomic::Access(s64) == -64);
                /// [_e65e47e3_e69f_49ae_a492_5198a35e383f]
            #endif
            }
        }
    }

    TEST_SUITE("Access_Or")
    {
        TEST_SUITE("should return or'd values without changing the original")
        {
            TEST_CASE("u8_t")
            {
                /// [_53e60fed_10a8_4a95_ab7a_8aa339b76df0]
                u8_t u8 = 0x0F;
                CHECK(nkr::os::atomic::Access_Or(u8, 0xF0) == 0xFF);
                CHECK(u8 == 0x0F);
                /// [_53e60fed_10a8_4a95_ab7a_8aa339b76df0]
            }
            TEST_CASE("s8_t")
            {
                /// [_1378a2c9_110b_49a6_bc6d_fd375c71f97e]
                s8_t s8 = 0x0F;
                CHECK(nkr::os::atomic::Access_Or(s8, 0x70) == 0x7F);
                CHECK(s8 == 0x0F);
                /// [_1378a2c9_110b_49a6_bc6d_fd375c71f97e]
            }
            TEST_CASE("u16_t")
            {
                /// [_90eb3de0_08a6_44fa_a743_5b0d0d6d18d5]
                u16_t u16 = 0x00FF;
                CHECK(nkr::os::atomic::Access_Or(u16, 0xFF00) == 0xFFFF);
                CHECK(u16 == 0x00FF);
                /// [_90eb3de0_08a6_44fa_a743_5b0d0d6d18d5]
            }
            TEST_CASE("s16_t")
            {
                /// [_5fe94205_39ad_426e_bbf5_39e3eea8a922]
                s16_t s16 = 0x00FF;
                CHECK(nkr::os::atomic::Access_Or(s16, 0x7F00) == 0x7FFF);
                CHECK(s16 == 0x00FF);
                /// [_5fe94205_39ad_426e_bbf5_39e3eea8a922]
            }
            TEST_CASE("u32_t")
            {
                /// [_a8c0cacb_893c_4285_b3b9_a023b94b54c3]
                u32_t u32 = 0x0000FFFF;
                CHECK(nkr::os::atomic::Access_Or(u32, 0xFFFF0000) == 0xFFFFFFFF);
                CHECK(u32 == 0x0000FFFF);
                /// [_a8c0cacb_893c_4285_b3b9_a023b94b54c3]
            }
            TEST_CASE("s32_t")
            {
                /// [_57b01025_2383_4428_ab00_923f3647a8e5]
                s32_t s32 = 0x0000FFFF;
                CHECK(nkr::os::atomic::Access_Or(s32, 0x7FFF0000) == 0x7FFFFFFF);
                CHECK(s32 == 0x0000FFFF);
                /// [_57b01025_2383_4428_ab00_923f3647a8e5]
            }
            TEST_CASE("u64_t")
            {
            #if defined(nkr_IS_64_BIT)
                /// [_af20e40f_564d_483d_ae76_d338f05d8e76]
                u64_t u64 = 0x00000000FFFFFFFF;
                CHECK(nkr::os::atomic::Access_Or(u64, 0xFFFFFFFF00000000) == 0xFFFFFFFFFFFFFFFF);
                CHECK(u64 == 0x00000000FFFFFFFF);
                /// [_af20e40f_564d_483d_ae76_d338f05d8e76]
            #endif
            }
            TEST_CASE("s64_t")
            {
            #if defined(nkr_IS_64_BIT)
                /// [_7ddda1a7_acab_4945_af6e_5294762757d2]
                s64_t s64 = 0x00000000FFFFFFFF;
                CHECK(nkr::os::atomic::Access_Or(s64, 0x7FFFFFFF00000000) == 0x7FFFFFFFFFFFFFFF);
                CHECK(s64 == 0x00000000FFFFFFFF);
                /// [_7ddda1a7_acab_4945_af6e_5294762757d2]
            #endif
            }
        }
    }

    TEST_SUITE("Access_And")
    {
        TEST_SUITE("should return and'd values without changing the original")
        {
            TEST_CASE("u8_t")
            {
                /// [_016a942e_b8fa_4169_adf7_6d7052d12a14]
                u8_t u8 = 0x0F;
                CHECK(nkr::os::atomic::Access_And(u8, 0xF0) == 0x0);
                CHECK(u8 == 0x0F);
                /// [_016a942e_b8fa_4169_adf7_6d7052d12a14]
            }
            TEST_CASE("s8_t")
            {
                /// [_edfed814_791a_48f3_bf63_f1f6d9ca6639]
                s8_t s8 = 0x0F;
                CHECK(nkr::os::atomic::Access_And(s8, 0x70) == 0x0);
                CHECK(s8 == 0x0F);
                /// [_edfed814_791a_48f3_bf63_f1f6d9ca6639]
            }
            TEST_CASE("u16_t")
            {
                /// [_881a2d33_d8d7_4f94_8b14_b9f4e29c60ab]
                u16_t u16 = 0x00FF;
                CHECK(nkr::os::atomic::Access_And(u16, 0xFF00) == 0x0);
                CHECK(u16 == 0x00FF);
                /// [_881a2d33_d8d7_4f94_8b14_b9f4e29c60ab]
            }
            TEST_CASE("s16_t")
            {
                /// [_ae373a06_d8ef_44b8_8cfa_262bf8dcb15e]
                s16_t s16 = 0x00FF;
                CHECK(nkr::os::atomic::Access_And(s16, 0x7F00) == 0x0);
                CHECK(s16 == 0x00FF);
                /// [_ae373a06_d8ef_44b8_8cfa_262bf8dcb15e]
            }
            TEST_CASE("u32_t")
            {
                /// [_6a5d7014_aeb6_424e_bcf3_cdb171ffcd84]
                u32_t u32 = 0x0000FFFF;
                CHECK(nkr::os::atomic::Access_And(u32, 0xFFFF0000) == 0x0);
                CHECK(u32 == 0x0000FFFF);
                /// [_6a5d7014_aeb6_424e_bcf3_cdb171ffcd84]
            }
            TEST_CASE("s32_t")
            {
                /// [_6baaa251_42e8_490a_bcb9_14112de0b765]
                s32_t s32 = 0x0000FFFF;
                CHECK(nkr::os::atomic::Access_And(s32, 0x7FFF0000) == 0x0);
                CHECK(s32 == 0x0000FFFF);
                /// [_6baaa251_42e8_490a_bcb9_14112de0b765]
            }
            TEST_CASE("u64_t")
            {
            #if defined(nkr_IS_64_BIT)
                /// [_1d9b81af_ff11_4e46_a9db_4b2718017ba4]
                u64_t u64 = 0x00000000FFFFFFFF;
                CHECK(nkr::os::atomic::Access_And(u64, 0xFFFFFFFF00000000) == 0x0);
                CHECK(u64 == 0x00000000FFFFFFFF);
                /// [_1d9b81af_ff11_4e46_a9db_4b2718017ba4]
            #endif
            }
            TEST_CASE("s64_t")
            {
            #if defined(nkr_IS_64_BIT)
                /// [_39faf4e8_0dc7_4ee0_90c6_27a19d91b2cf]
                s64_t s64 = 0x00000000FFFFFFFF;
                CHECK(nkr::os::atomic::Access_And(s64, 0x7FFFFFFF00000000) == 0x0);
                CHECK(s64 == 0x00000000FFFFFFFF);
                /// [_39faf4e8_0dc7_4ee0_90c6_27a19d91b2cf]
            #endif
            }
        }
    }

    TEST_SUITE("Access_Xor")
    {
        TEST_SUITE("should return xor'd values without changing the original")
        {
            TEST_CASE("u8_t")
            {
                /// [_feb8a6e7_3452_4759_ba12_a4ca2a0923d3]
                u8_t u8 = 0xFF;
                CHECK(nkr::os::atomic::Access_Xor(u8, 0x01) == 0xFE);
                CHECK(u8 == 0xFF);
                /// [_feb8a6e7_3452_4759_ba12_a4ca2a0923d3]
            }
            TEST_CASE("s8_t")
            {
                /// [_b0a39c1d_5b76_42e0_9376_95b02ef02ed1]
                s8_t s8 = 0x7F;
                CHECK(nkr::os::atomic::Access_Xor(s8, 0x01) == 0x7E);
                CHECK(s8 == 0x7F);
                /// [_b0a39c1d_5b76_42e0_9376_95b02ef02ed1]
            }
            TEST_CASE("u16_t")
            {
                /// [_a5c77c49_2a6c_4e9d_a083_4a5ba702b9ce]
                u16_t u16 = 0xFFFF;
                CHECK(nkr::os::atomic::Access_Xor(u16, 0x0001) == 0xFFFE);
                CHECK(u16 == 0xFFFF);
                /// [_a5c77c49_2a6c_4e9d_a083_4a5ba702b9ce]
            }
            TEST_CASE("s16_t")
            {
                /// [_e1476be6_f2d2_4c10_a69d_2f515acaa182]
                s16_t s16 = 0x7FFF;
                CHECK(nkr::os::atomic::Access_Xor(s16, 0x0001) == 0x7FFE);
                CHECK(s16 == 0x7FFF);
                /// [_e1476be6_f2d2_4c10_a69d_2f515acaa182]
            }
            TEST_CASE("u32_t")
            {
                /// [_3ed68d6a_3605_4a25_98db_6bc100721599]
                u32_t u32 = 0xFFFFFFFF;
                CHECK(nkr::os::atomic::Access_Xor(u32, 0x00000001) == 0xFFFFFFFE);
                CHECK(u32 == 0xFFFFFFFF);
                /// [_3ed68d6a_3605_4a25_98db_6bc100721599]
            }
            TEST_CASE("s32_t")
            {
                /// [_496055d6_fc13_4b6a_bcf0_b69d64373e88]
                s32_t s32 = 0x7FFFFFFF;
                CHECK(nkr::os::atomic::Access_Xor(s32, 0x00000001) == 0x7FFFFFFE);
                CHECK(s32 == 0x7FFFFFFF);
                /// [_496055d6_fc13_4b6a_bcf0_b69d64373e88]
            }
            TEST_CASE("u64_t")
            {
            #if defined(nkr_IS_64_BIT)
                /// [_6eb51993_ff53_4d84_b915_7ff08acb45a3]
                u64_t u64 = 0xFFFFFFFFFFFFFFFF;
                CHECK(nkr::os::atomic::Access_Xor(u64, 0x0000000000000001) == 0xFFFFFFFFFFFFFFFE);
                CHECK(u64 == 0xFFFFFFFFFFFFFFFF);
                /// [_6eb51993_ff53_4d84_b915_7ff08acb45a3]
            #endif
            }
            TEST_CASE("s64_t")
            {
            #if defined(nkr_IS_64_BIT)
                /// [_afbe8e53_cdc4_4126_971b_af1850c8f270]
                s64_t s64 = 0x7FFFFFFFFFFFFFFF;
                CHECK(nkr::os::atomic::Access_Xor(s64, 0x0000000000000001) == 0x7FFFFFFFFFFFFFFE);
                CHECK(s64 == 0x7FFFFFFFFFFFFFFF);
                /// [_afbe8e53_cdc4_4126_971b_af1850c8f270]
            #endif
            }
        }
    }

    TEST_SUITE("Access_Left_Shift()")
    {
        TEST_SUITE("should return value << operator without changing the value")
        {
            TEST_CASE("u8_t")
            {
                /// [_07a23b19_7a23_49b2_95ca_12ddd74b1045]
                u8_t u8 = 0x0F;
                CHECK(nkr::os::atomic::Access_Left_Shift(u8, 4) == 0xF0);
                CHECK(nkr::os::atomic::Access(u8) == 0x0F);
                /// [_07a23b19_7a23_49b2_95ca_12ddd74b1045]
            }
            TEST_CASE("s8_t")
            {
                /// [_e58b0864_38ac_4056_9c7b_ad063d06d04c]
                s8_t s8 = 0x07;
                CHECK(nkr::os::atomic::Access_Left_Shift(s8, 4) == 0x70);
                CHECK(nkr::os::atomic::Access(s8) == 0x07);
                /// [_e58b0864_38ac_4056_9c7b_ad063d06d04c]
            }
            TEST_CASE("u16_t")
            {
                /// [_b40dda34_9c68_4504_b53e_db2ac9213946]
                u16_t u16 = 0x00FF;
                CHECK(nkr::os::atomic::Access_Left_Shift(u16, 8) == 0xFF00);
                CHECK(nkr::os::atomic::Access(u16) == 0x00FF);
                /// [_b40dda34_9c68_4504_b53e_db2ac9213946]
            }
            TEST_CASE("s16_t")
            {
                /// [_775230f0_9b80_4bfd_9393_a197c19eda8d]
                s16_t s16 = 0x007F;
                CHECK(nkr::os::atomic::Access_Left_Shift(s16, 8) == 0x7F00);
                CHECK(nkr::os::atomic::Access(s16) == 0x007F);
                /// [_775230f0_9b80_4bfd_9393_a197c19eda8d]
            }
            TEST_CASE("u32_t")
            {
                /// [_95a0458c_e66e_45d5_ae67_2f60d1ea9352]
                u32_t u32 = 0x0000FFFF;
                CHECK(nkr::os::atomic::Access_Left_Shift(u32, 16) == 0xFFFF0000);
                CHECK(nkr::os::atomic::Access(u32) == 0x0000FFFF);
                /// [_95a0458c_e66e_45d5_ae67_2f60d1ea9352]
            }
            TEST_CASE("s32_t")
            {
                /// [_47b4153f_8568_46dc_9c70_6b65e7cd2a49]
                s32_t s32 = 0x00007FFF;
                CHECK(nkr::os::atomic::Access_Left_Shift(s32, 16) == 0x7FFF0000);
                CHECK(nkr::os::atomic::Access(s32) == 0x00007FFF);
                /// [_47b4153f_8568_46dc_9c70_6b65e7cd2a49]
            }
            TEST_CASE("u64_t")
            {
            #if defined(nkr_IS_64_BIT)
                /// [_138ec2f4_d634_4711_b95e_b4133914c840]
                u64_t u64 = 0x00000000FFFFFFFF;
                CHECK(nkr::os::atomic::Access_Left_Shift(u64, 32) == 0xFFFFFFFF00000000);
                CHECK(nkr::os::atomic::Access(u64) == 0x00000000FFFFFFFF);
                /// [_138ec2f4_d634_4711_b95e_b4133914c840]
            #endif
            }
            TEST_CASE("s64_t")
            {
            #if defined(nkr_IS_64_BIT)
                /// [_ea91ce70_f3f1_4b56_9604_deab0cce0ae6]
                s64_t s64 = 0x000000007FFFFFFF;
                CHECK(nkr::os::atomic::Access_Left_Shift(s64, 32) == 0x7FFFFFFF00000000);
                CHECK(nkr::os::atomic::Access(s64) == 0x000000007FFFFFFF);
                /// [_ea91ce70_f3f1_4b56_9604_deab0cce0ae6]
            #endif
            }
        }
    }

    TEST_SUITE("Access_Right_Shift()")
    {
        TEST_SUITE("should return value >> operator without changing the value")
        {
            TEST_CASE("u8_t")
            {
                /// [_e6e541a5_cda2_4d05_9938_d21899578f7d]
                u8_t u8 = 0xF0;
                CHECK(nkr::os::atomic::Access_Right_Shift(u8, 4) == 0x0F);
                CHECK(nkr::os::atomic::Access(u8) == 0xF0);
                /// [_e6e541a5_cda2_4d05_9938_d21899578f7d]
            }
            TEST_CASE("s8_t")
            {
                /// [_5a24855a_e1a0_43c8_a469_4a907fc403bb]
                s8_t s8 = 0x70;
                CHECK(nkr::os::atomic::Access_Right_Shift(s8, 4) == 0x07);
                CHECK(nkr::os::atomic::Access(s8) == 0x70);
                /// [_5a24855a_e1a0_43c8_a469_4a907fc403bb]
            }
            TEST_CASE("u16_t")
            {
                /// [_a21b6657_9ba8_49e8_afe4_d8d9407c1b68]
                u16_t u16 = 0xFF00;
                CHECK(nkr::os::atomic::Access_Right_Shift(u16, 8) == 0x00FF);
                CHECK(nkr::os::atomic::Access(u16) == 0xFF00);
                /// [_a21b6657_9ba8_49e8_afe4_d8d9407c1b68]
            }
            TEST_CASE("s16_t")
            {
                /// [_201d8b75_8903_444a_86fb_ddf184c19769]
                s16_t s16 = 0x7F00;
                CHECK(nkr::os::atomic::Access_Right_Shift(s16, 8) == 0x007F);
                CHECK(nkr::os::atomic::Access(s16) == 0x7F00);
                /// [_201d8b75_8903_444a_86fb_ddf184c19769]
            }
            TEST_CASE("u32_t")
            {
                /// [_5516a628_28a0_4869_b74a_828b9eb176a9]
                u32_t u32 = 0xFFFF0000;
                CHECK(nkr::os::atomic::Access_Right_Shift(u32, 16) == 0x0000FFFF);
                CHECK(nkr::os::atomic::Access(u32) == 0xFFFF0000);
                /// [_5516a628_28a0_4869_b74a_828b9eb176a9]
            }
            TEST_CASE("s32_t")
            {
                /// [_6f59ce2d_6ae4_4cdf_8cab_94cef9f61ce5]
                s32_t s32 = 0x7FFF0000;
                CHECK(nkr::os::atomic::Access_Right_Shift(s32, 16) == 0x00007FFF);
                CHECK(nkr::os::atomic::Access(s32) == 0x7FFF0000);
                /// [_6f59ce2d_6ae4_4cdf_8cab_94cef9f61ce5]
            }
            TEST_CASE("u64_t")
            {
            #if defined(nkr_IS_64_BIT)
                /// [_ac4038af_7785_478e_ab95_12bf77a48e3c]
                u64_t u64 = 0xFFFFFFFF00000000;
                CHECK(nkr::os::atomic::Access_Right_Shift(u64, 32) == 0x00000000FFFFFFFF);
                CHECK(nkr::os::atomic::Access(u64) == 0xFFFFFFFF00000000);
                /// [_ac4038af_7785_478e_ab95_12bf77a48e3c]
            #endif
            }
            TEST_CASE("s64_t")
            {
            #if defined(nkr_IS_64_BIT)
                /// [_cfe24f82_1509_46b8_b308_1313c9192c94]
                s64_t s64 = 0x7FFFFFFF00000000;
                CHECK(nkr::os::atomic::Access_Right_Shift(s64, 32) == 0x000000007FFFFFFF);
                CHECK(nkr::os::atomic::Access(s64) == 0x7FFFFFFF00000000);
                /// [_cfe24f82_1509_46b8_b308_1313c9192c94]
            #endif
            }
        }
    }

    TEST_SUITE("Assign")
    {
        TEST_SUITE("should atomically assign integers and pointers and return the new value")
        {
            TEST_CASE("bool_t")
            {
                /// [_0d25bd55_1cd6_4bef_8511_d18bb0e8c047]
                bool_t boolean = false;
                CHECK(nkr::os::atomic::Assign(boolean, true) == true);
                CHECK(boolean == true);
                /// [_0d25bd55_1cd6_4bef_8511_d18bb0e8c047]
            }
            TEST_CASE("std_bool_t")
            {
                /// [_07f84e18_ff17_4b98_ad2a_00aeb01150fb]
                std_bool_t boolean = false;
                CHECK(nkr::os::atomic::Assign(boolean, true) == true);
                CHECK(boolean == true);
                /// [_07f84e18_ff17_4b98_ad2a_00aeb01150fb]
            }
            TEST_CASE("u8_t")
            {
                /// [_dd1916f4_9e7d_4426_93a1_9ef5772d71eb]
                u8_t u8 = 8;
                CHECK(nkr::os::atomic::Assign(u8, 1) == 1);
                CHECK(u8 == 1);
                /// [_dd1916f4_9e7d_4426_93a1_9ef5772d71eb]
            }
            TEST_CASE("s8_t")
            {
                /// [_911cb23a_8c5f_427b_bffa_728885a7828c]
                s8_t s8 = -8;
                CHECK(nkr::os::atomic::Assign(s8, -1) == -1);
                CHECK(s8 == -1);
                /// [_911cb23a_8c5f_427b_bffa_728885a7828c]
            }
            TEST_CASE("u16_t")
            {
                /// [_4df4a57e_71d5_40ba_891c_85cc30afd79d]
                u16_t u16 = 16;
                CHECK(nkr::os::atomic::Assign(u16, 1) == 1);
                CHECK(u16 == 1);
                /// [_4df4a57e_71d5_40ba_891c_85cc30afd79d]
            }
            TEST_CASE("s16_t")
            {
                /// [_99221dcc_16cb_47f0_98d1_04d3a2d3f6fe]
                s16_t s16 = -16;
                CHECK(nkr::os::atomic::Assign(s16, -1) == -1);
                CHECK(s16 == -1);
                /// [_99221dcc_16cb_47f0_98d1_04d3a2d3f6fe]
            }
            TEST_CASE("u32_t")
            {
                /// [_c49e3692_999a_4de7_838e_b4d4bd3363ad]
                u32_t u32 = 32;
                CHECK(nkr::os::atomic::Assign(u32, 1) == 1);
                CHECK(u32 == 1);
                /// [_c49e3692_999a_4de7_838e_b4d4bd3363ad]
            }
            TEST_CASE("s32_t")
            {
                /// [_03c4270f_4445_432e_9564_400c524bfa56]
                s32_t s32 = -32;
                CHECK(nkr::os::atomic::Assign(s32, -1) == -1);
                CHECK(s32 == -1);
                /// [_03c4270f_4445_432e_9564_400c524bfa56]
            }
            TEST_CASE("u64_t")
            {
            #if defined(nkr_IS_64_BIT)
                /// [_5135301b_cf7d_4673_b579_febd189ab1eb]
                u64_t u64 = 64;
                CHECK(nkr::os::atomic::Assign(u64, 1) == 1);
                CHECK(u64 == 1);
                /// [_5135301b_cf7d_4673_b579_febd189ab1eb]
            #endif
            }
            TEST_CASE("s64_t")
            {
            #if defined(nkr_IS_64_BIT)
                /// [_df7134a8_a8dc_4ebe_9402_24293478f845]
                s64_t s64 = -64;
                CHECK(nkr::os::atomic::Assign(s64, -1) == -1);
                CHECK(s64 == -1);
                /// [_df7134a8_a8dc_4ebe_9402_24293478f845]
            #endif
            }
            TEST_CASE("f32_t")
            {
                /// [_f157cc7f_e2c4_43fc_ace7_46fdb1f780f6]
                f32_t f32 = 3.2f;
                CHECK(nkr::os::atomic::Assign(f32, 1.0f) == 1.0f);
                CHECK(f32 == 1.0f);
                /// [_f157cc7f_e2c4_43fc_ace7_46fdb1f780f6]
            }
            TEST_CASE("f64_t")
            {
            #if defined(nkr_IS_64_BIT)
                /// [_c34e8028_14a0_4d3f_b4eb_168b0325d9c2]
                f64_t f64 = 6.4;
                CHECK(nkr::os::atomic::Assign(f64, 1.0) == 1.0);
                CHECK(f64 == 1.0);
                /// [_c34e8028_14a0_4d3f_b4eb_168b0325d9c2]
            #endif
            }
            TEST_CASE("void_t*")
            {
                /// [_3dee9075_2eda_4ffc_87d5_ca9f68dd6860]
                bool_t boolean = false;
                void_t* void_pointer = nullptr;
                CHECK(nkr::os::atomic::Assign(void_pointer, &boolean) == &boolean);
                CHECK(void_pointer == &boolean);
                /// [_3dee9075_2eda_4ffc_87d5_ca9f68dd6860]
            }
            TEST_CASE("bool_t*")
            {
                /// [_ba439f68_0118_468d_b63e_07b2e8d92733]
                bool_t boolean = false;
                bool_t* boolean_pointer = &boolean;
                CHECK(nkr::os::atomic::Assign(boolean_pointer, nullptr) == nullptr);
                CHECK(boolean_pointer == nullptr);
                /// [_ba439f68_0118_468d_b63e_07b2e8d92733]
            }
        }
    }

    TEST_SUITE("Assign_Add")
    {
        TEST_SUITE("should atomically add to integers and pointers and return the new value")
        {
            TEST_CASE("u8_t")
            {
                /// [_37a16541_dabf_4437_ae5a_a2d3c08c22f6]
                u8_t u8 = 8;
                CHECK(nkr::os::atomic::Assign_Add(u8, 1) == 9);
                CHECK(u8 == 9);
                /// [_37a16541_dabf_4437_ae5a_a2d3c08c22f6]
            }
            TEST_CASE("s8_t")
            {
                /// [_fa5ad084_fec4_486f_a586_c24356eb0b36]
                s8_t s8 = -8;
                CHECK(nkr::os::atomic::Assign_Add(s8, -1) == -9);
                CHECK(s8 == -9);
                /// [_fa5ad084_fec4_486f_a586_c24356eb0b36]
            }
            TEST_CASE("u16_t")
            {
                /// [_e5727ad0_7977_405a_9c5c_9bc18cc9f4e9]
                u16_t u16 = 16;
                CHECK(nkr::os::atomic::Assign_Add(u16, 1) == 17);
                CHECK(u16 == 17);
                /// [_e5727ad0_7977_405a_9c5c_9bc18cc9f4e9]
            }
            TEST_CASE("s16_t")
            {
                /// [_156cbd25_57ce_445a_b3f2_8d304b707d11]
                s16_t s16 = -16;
                CHECK(nkr::os::atomic::Assign_Add(s16, -1) == -17);
                CHECK(s16 == -17);
                /// [_156cbd25_57ce_445a_b3f2_8d304b707d11]
            }
            TEST_CASE("u32_t")
            {
                /// [_125ba687_8a5b_4cc6_975f_c9a74d237336]
                u32_t u32 = 32;
                CHECK(nkr::os::atomic::Assign_Add(u32, 1) == 33);
                CHECK(u32 == 33);
                /// [_125ba687_8a5b_4cc6_975f_c9a74d237336]
            }
            TEST_CASE("s32_t")
            {
                /// [_5c205cbf_32d2_4d05_b493_f1de4f4daf21]
                s32_t s32 = -32;
                CHECK(nkr::os::atomic::Assign_Add(s32, -1) == -33);
                CHECK(s32 == -33);
                /// [_5c205cbf_32d2_4d05_b493_f1de4f4daf21]
            }
            TEST_CASE("u64_t")
            {
            #if defined(nkr_IS_64_BIT)
                /// [_33248ef7_2b84_4a85_9b1c_cc8d282b7a37]
                u64_t u64 = 64;
                CHECK(nkr::os::atomic::Assign_Add(u64, 1) == 65);
                CHECK(u64 == 65);
                /// [_33248ef7_2b84_4a85_9b1c_cc8d282b7a37]
            #endif
            }
            TEST_CASE("s64_t")
            {
            #if defined(nkr_IS_64_BIT)
                /// [_ce36072a_53ba_4967_b759_fd0eb6b81940]
                s64_t s64 = -64;
                CHECK(nkr::os::atomic::Assign_Add(s64, -1) == -65);
                CHECK(s64 == -65);
                /// [_ce36072a_53ba_4967_b759_fd0eb6b81940]
            #endif
            }
            TEST_CASE("f32_t")
            {
                /// [_f3394ec8_1307_46a2_8394_aa0ee3baaa77]
                f32_t f32 = 3.2f;
                CHECK(nkr::os::atomic::Assign_Add(f32, 0.1f) == 3.2f + 0.1f);
                CHECK(f32 == 3.2f + 0.1f);
                /// [_f3394ec8_1307_46a2_8394_aa0ee3baaa77]
            }
            TEST_CASE("f64_t")
            {
            #if defined(nkr_IS_64_BIT)
                /// [_835a4125_b92c_4d89_940a_1467d425e68f]
                f64_t f64 = 6.4;
                CHECK(nkr::os::atomic::Assign_Add(f64, 0.1) == 6.4 + 0.1);
                CHECK(f64 == 6.4 + 0.1);
                /// [_835a4125_b92c_4d89_940a_1467d425e68f]
            #endif
            }
            TEST_CASE("bool_t*")
            {
                /// [_611ac2c6_4f53_4b55_937e_8b1cebea5a35]
                bool_t booleans[2] = { true, true };
                bool_t* boolean_pointer = booleans;
                CHECK(nkr::os::atomic::Assign_Add(boolean_pointer, 1) == booleans + 1);
                CHECK(nkr::os::atomic::Assign_Add(boolean_pointer, -1) == booleans + 0);
                /// [_611ac2c6_4f53_4b55_937e_8b1cebea5a35]
            }
        }
        TEST_CASE("should be able to increment a variable atomically without data loss"
                  * doctest::no_breaks(true))
        {
            /// [_e284b8bf_6a1e_4e0a_9601_e7ab38bfbf3c]
            const u8_t thread_count = 64;
            std::vector<std::thread> threads;
            threads.reserve(thread_count);

            word_t atomic_counter = 0;
            for (index_t idx = 0, end = thread_count; idx < end; idx += 1) {
                threads.push_back(std::thread(
                    [&atomic_counter]() -> void_t
                    {
                        word_t micro_seconds = 0;
                        {
                            std::lock_guard<std::mutex> locker(random_lock);
                            micro_seconds = std::uniform_int_distribution<word_t>(1, 5)(random_generator);
                        }
                        std::this_thread::sleep_for(std::chrono::microseconds(micro_seconds));
                        nkr::os::atomic::Assign_Add(atomic_counter, 7);
                    }
                ));
            }
            for (index_t idx = 0, end = thread_count; idx < end; idx += 1) {
                threads[idx].join();
            }

            CHECK(atomic_counter == thread_count * 7);
            /// [_e284b8bf_6a1e_4e0a_9601_e7ab38bfbf3c]
        }
    }

    TEST_SUITE("Assign_Subtract")
    {
        TEST_SUITE("should atomically subtract from integers and pointers and return the new value")
        {
            TEST_CASE("u8_t")
            {
                /// [_1cbfb9f2_1ccf_4a1b_9a2a_bf51a9244b85]
                u8_t u8 = 8;
                CHECK(nkr::os::atomic::Assign_Subtract(u8, 1) == 7);
                CHECK(u8 == 7);
                /// [_1cbfb9f2_1ccf_4a1b_9a2a_bf51a9244b85]
            }
            TEST_CASE("s8_t")
            {
                /// [_d145a164_78e1_4d94_8dcc_90105514d856]
                s8_t s8 = -8;
                CHECK(nkr::os::atomic::Assign_Subtract(s8, -1) == -7);
                CHECK(s8 == -7);
                /// [_d145a164_78e1_4d94_8dcc_90105514d856]
            }
            TEST_CASE("u16_t")
            {
                /// [_6dafab42_b7f6_49b1_9f21_c6bff3789494]
                u16_t u16 = 16;
                CHECK(nkr::os::atomic::Assign_Subtract(u16, 1) == 15);
                CHECK(u16 == 15);
                /// [_6dafab42_b7f6_49b1_9f21_c6bff3789494]
            }
            TEST_CASE("s16_t")
            {
                /// [_1b93be68_18e6_4ee9_9141_41a4c4251672]
                s16_t s16 = -16;
                CHECK(nkr::os::atomic::Assign_Subtract(s16, -1) == -15);
                CHECK(s16 == -15);
                /// [_1b93be68_18e6_4ee9_9141_41a4c4251672]
            }
            TEST_CASE("u32_t")
            {
                /// [_54e7cd59_7826_4ad0_b548_8d7b1a7b5343]
                u32_t u32 = 32;
                CHECK(nkr::os::atomic::Assign_Subtract(u32, 1) == 31);
                CHECK(u32 == 31);
                /// [_54e7cd59_7826_4ad0_b548_8d7b1a7b5343]
            }
            TEST_CASE("s32_t")
            {
                /// [_a7de8993_0c1a_4268_b80e_521b6ab23d7f]
                s32_t s32 = -32;
                CHECK(nkr::os::atomic::Assign_Subtract(s32, -1) == -31);
                CHECK(s32 == -31);
                /// [_a7de8993_0c1a_4268_b80e_521b6ab23d7f]
            }
            TEST_CASE("u64_t")
            {
            #if defined(nkr_IS_64_BIT)
                /// [_66b2a24d_2b58_46f1_98e5_9d3a50be608f]
                u64_t u64 = 64;
                CHECK(nkr::os::atomic::Assign_Subtract(u64, 1) == 63);
                CHECK(u64 == 63);
                /// [_66b2a24d_2b58_46f1_98e5_9d3a50be608f]
            #endif
            }
            TEST_CASE("s64_t")
            {
            #if defined(nkr_IS_64_BIT)
                /// [_cb450edc_fdc2_43e6_96ea_64f6562fa97a]
                s64_t s64 = -64;
                CHECK(nkr::os::atomic::Assign_Subtract(s64, -1) == -63);
                CHECK(s64 == -63);
                /// [_cb450edc_fdc2_43e6_96ea_64f6562fa97a]
            #endif
            }
            TEST_CASE("f32_t")
            {
                /// [_27f73182_bfc7_4552_b539_8e3ded554740]
                f32_t f32 = 3.2f;
                CHECK(nkr::os::atomic::Assign_Subtract(f32, 0.1f) == 3.2f - 0.1f);
                CHECK(f32 == 3.2f - 0.1f);
                /// [_27f73182_bfc7_4552_b539_8e3ded554740]
            }
            TEST_CASE("f64_t")
            {
            #if defined(nkr_IS_64_BIT)
                /// [_bd6605e6_3104_4249_8a1f_73477ce78806]
                f64_t f64 = 6.4;
                CHECK(nkr::os::atomic::Assign_Subtract(f64, 0.1) == 6.4 - 0.1);
                CHECK(f64 == 6.4 - 0.1);
                /// [_bd6605e6_3104_4249_8a1f_73477ce78806]
            #endif
            }
            TEST_CASE("bool_t*")
            {
                /// [_60a12b01_ce35_4373_a70f_4ed735555759]
                bool_t booleans[2] = { true, true };
                bool_t* boolean_pointer = booleans + 1;
                CHECK(nkr::os::atomic::Assign_Subtract(boolean_pointer, 1) == booleans + 0);
                CHECK(nkr::os::atomic::Assign_Subtract(boolean_pointer, -1) == booleans + 1);
                /// [_60a12b01_ce35_4373_a70f_4ed735555759]
            }
        }
        TEST_CASE("should be able to decrement a variable atomically without data loss"
                  * doctest::no_breaks(true))
        {
            /// [_c8e349da_46dd_4881_9c7b_71443df3c2c6]
            const u8_t thread_count = 64;
            std::vector<std::thread> threads;
            threads.reserve(thread_count);

            word_t atomic_counter = thread_count * 7;
            for (index_t idx = 0, end = thread_count; idx < end; idx += 1) {
                threads.push_back(std::thread(
                    [&atomic_counter]() -> void_t
                    {
                        word_t micro_seconds = 0;
                        {
                            std::lock_guard<std::mutex> locker(random_lock);
                            micro_seconds = std::uniform_int_distribution<word_t>(1, 5)(random_generator);
                        }
                        std::this_thread::sleep_for(std::chrono::microseconds(micro_seconds));
                        nkr::os::atomic::Assign_Subtract(atomic_counter, 7);
                    }
                ));
            }
            for (index_t idx = 0, end = thread_count; idx < end; idx += 1) {
                threads[idx].join();
            }

            CHECK(atomic_counter == 0);
            /// [_c8e349da_46dd_4881_9c7b_71443df3c2c6]
        }
    }

    TEST_SUITE("Assign_Multiply()")
    {
        TEST_SUITE("should value * operand and change its original value")
        {
            TEST_CASE("u8_t")
            {
                /// [_8bca48a2_1a73_445c_89a4_050151c77487]
                u8_t u8 = 8;
                CHECK(nkr::os::atomic::Assign_Multiply(u8, 2) == 16);
                CHECK(nkr::os::atomic::Access(u8) == 16);
                /// [_8bca48a2_1a73_445c_89a4_050151c77487]
            }
            TEST_CASE("s8_t")
            {
                /// [_cbaf11af_cc8b_4d0c_883c_ba30409d9115]
                s8_t s8 = -8;
                CHECK(nkr::os::atomic::Assign_Multiply(s8, 2) == -16);
                CHECK(nkr::os::atomic::Access(s8) == -16);
                /// [_cbaf11af_cc8b_4d0c_883c_ba30409d9115]
            }
            TEST_CASE("u16_t")
            {
                /// [_f02a4361_7103_4492_83b6_fc92b94c4f51]
                u16_t u16 = 16;
                CHECK(nkr::os::atomic::Assign_Multiply(u16, 2) == 32);
                CHECK(nkr::os::atomic::Access(u16) == 32);
                /// [_f02a4361_7103_4492_83b6_fc92b94c4f51]
            }
            TEST_CASE("s16_t")
            {
                /// [_6648e27f_1f2f_42a3_9e81_8def9c666356]
                s16_t s16 = -16;
                CHECK(nkr::os::atomic::Assign_Multiply(s16, 2) == -32);
                CHECK(nkr::os::atomic::Access(s16) == -32);
                /// [_6648e27f_1f2f_42a3_9e81_8def9c666356]
            }
            TEST_CASE("u32_t")
            {
                /// [_4db05041_5d44_4d2f_953a_389dc6453941]
                u32_t u32 = 32;
                CHECK(nkr::os::atomic::Assign_Multiply(u32, 2) == 64);
                CHECK(nkr::os::atomic::Access(u32) == 64);
                /// [_4db05041_5d44_4d2f_953a_389dc6453941]
            }
            TEST_CASE("s32_t")
            {
                /// [_b11772c4_3403_4bbd_bbdc_52d26ddcc007]
                s32_t s32 = -32;
                CHECK(nkr::os::atomic::Assign_Multiply(s32, 2) == -64);
                CHECK(nkr::os::atomic::Access(s32) == -64);
                /// [_b11772c4_3403_4bbd_bbdc_52d26ddcc007]
            }
            TEST_CASE("u64_t")
            {
            #if defined(nkr_IS_64_BIT)
                /// [_3800f477_6506_4555_973e_94bc7d518d98]
                u64_t u64 = 64;
                CHECK(nkr::os::atomic::Assign_Multiply(u64, 2) == 128);
                CHECK(nkr::os::atomic::Access(u64) == 128);
                /// [_3800f477_6506_4555_973e_94bc7d518d98]
            #endif
            }
            TEST_CASE("s64_t")
            {
            #if defined(nkr_IS_64_BIT)
                /// [_38326c66_a188_4fb3_8d25_fb6de631b5fa]
                s64_t s64 = -64;
                CHECK(nkr::os::atomic::Assign_Multiply(s64, 2) == -128);
                CHECK(nkr::os::atomic::Access(s64) == -128);
                /// [_38326c66_a188_4fb3_8d25_fb6de631b5fa]
            #endif
            }
            TEST_CASE("f32_t")
            {
                /// [_36c0f2b7_8902_4ad4_9097_4755fceb08aa]
                f32_t f32 = 3.2f;
                CHECK(nkr::os::atomic::Assign_Multiply(f32, 0.1f) == 3.2f * 0.1f);
                CHECK(nkr::os::atomic::Access(f32) == 3.2f * 0.1f);
                /// [_36c0f2b7_8902_4ad4_9097_4755fceb08aa]
            }
            TEST_CASE("f64_t")
            {
            #if defined(nkr_IS_64_BIT)
                /// [_421aeec1_cf2b_4f03_b90b_c6787779f060]
                f64_t f64 = 6.4;
                CHECK(nkr::os::atomic::Assign_Multiply(f64, 0.1) == 6.4 * 0.1);
                CHECK(nkr::os::atomic::Access(f64) == 6.4 * 0.1);
                /// [_421aeec1_cf2b_4f03_b90b_c6787779f060]
            #endif
            }
        }
    }

    TEST_SUITE("Assign_Divide()")
    {
        TEST_SUITE("should value / operand and change the original value")
        {
            TEST_CASE("u8_t")
            {
                /// [_f0cf857c_3ac3_49c6_9a20_1546fc68cc42]
                u8_t u8 = 8;
                CHECK(nkr::os::atomic::Assign_Divide(u8, 2) == 4);
                CHECK(nkr::os::atomic::Access(u8) == 4);
                /// [_f0cf857c_3ac3_49c6_9a20_1546fc68cc42]
            }
            TEST_CASE("s8_t")
            {
                /// [_f936549f_ed46_45af_bc24_b3d7a57d1981]
                s8_t s8 = -8;
                CHECK(nkr::os::atomic::Assign_Divide(s8, 2) == -4);
                CHECK(nkr::os::atomic::Access(s8) == -4);
                /// [_f936549f_ed46_45af_bc24_b3d7a57d1981]
            }
            TEST_CASE("u16_t")
            {
                /// [_5044553b_a912_4c45_bc98_668d2d7bf1a2]
                u16_t u16 = 16;
                CHECK(nkr::os::atomic::Assign_Divide(u16, 2) == 8);
                CHECK(nkr::os::atomic::Access(u16) == 8);
                /// [_5044553b_a912_4c45_bc98_668d2d7bf1a2]
            }
            TEST_CASE("s16_t")
            {
                /// [_a18c3b5b_7cd2_4eae_937f_57bafa5802d1]
                s16_t s16 = -16;
                CHECK(nkr::os::atomic::Assign_Divide(s16, 2) == -8);
                CHECK(nkr::os::atomic::Access(s16) == -8);
                /// [_a18c3b5b_7cd2_4eae_937f_57bafa5802d1]
            }
            TEST_CASE("u32_t")
            {
                /// [_c322519b_4ec7_4948_8f3a_23605ac22756]
                u32_t u32 = 32;
                CHECK(nkr::os::atomic::Assign_Divide(u32, 2) == 16);
                CHECK(nkr::os::atomic::Access(u32) == 16);
                /// [_c322519b_4ec7_4948_8f3a_23605ac22756]
            }
            TEST_CASE("s32_t")
            {
                /// [_afaece74_1c7d_40a6_8b92_706cd5b8db24]
                s32_t s32 = -32;
                CHECK(nkr::os::atomic::Assign_Divide(s32, 2) == -16);
                CHECK(nkr::os::atomic::Access(s32) == -16);
                /// [_afaece74_1c7d_40a6_8b92_706cd5b8db24]
            }
            TEST_CASE("u64_t")
            {
            #if defined(nkr_IS_64_BIT)
                /// [_e2f68a83_4818_4ec3_9e24_c0f7708b9976]
                u64_t u64 = 64;
                CHECK(nkr::os::atomic::Assign_Divide(u64, 2) == 32);
                CHECK(nkr::os::atomic::Access(u64) == 32);
                /// [_e2f68a83_4818_4ec3_9e24_c0f7708b9976]
            #endif
            }
            TEST_CASE("s64_t")
            {
            #if defined(nkr_IS_64_BIT)
                /// [_a6d9520a_30f4_431f_b0ae_b7f85cbf9041]
                s64_t s64 = -64;
                CHECK(nkr::os::atomic::Assign_Divide(s64, 2) == -32);
                CHECK(nkr::os::atomic::Access(s64) == -32);
                /// [_a6d9520a_30f4_431f_b0ae_b7f85cbf9041]
            #endif
            }
            TEST_CASE("f32_t")
            {
                /// [_dc683ec7_75f7_48ff_9d0b_3b1c25350a41]
                f32_t f32 = 3.2f;
                CHECK(nkr::os::atomic::Assign_Divide(f32, 0.1f) == 3.2f / 0.1f);
                CHECK(nkr::os::atomic::Access(f32) == 3.2f / 0.1f);
                /// [_dc683ec7_75f7_48ff_9d0b_3b1c25350a41]
            }
            TEST_CASE("f64_t")
            {
            #if defined(nkr_IS_64_BIT)
                /// [_2b78214c_3480_4abd_8171_123e676261d6]
                f64_t f64 = 6.4;
                CHECK(nkr::os::atomic::Assign_Divide(f64, 0.1) == 6.4 / 0.1);
                CHECK(nkr::os::atomic::Access(f64) == 6.4 / 0.1);
                /// [_2b78214c_3480_4abd_8171_123e676261d6]
            #endif
            }
        }
    }

    TEST_SUITE("Assign_Modulus()")
    {
        TEST_SUITE("should value % operand and change the original value")
        {
            TEST_CASE("u8_t")
            {
                /// [_bc274577_2161_44f2_96f3_3c7f5260a29e]
                u8_t u8 = 8;
                CHECK(nkr::os::atomic::Assign_Modulus(u8, 3) == 2);
                CHECK(nkr::os::atomic::Access(u8) == 2);
                /// [_bc274577_2161_44f2_96f3_3c7f5260a29e]
            }
            TEST_CASE("s8_t")
            {
                /// [_09a95d9e_4847_4f58_95a8_6396ff3a0ab1]
                s8_t s8 = -8;
                CHECK(nkr::os::atomic::Assign_Modulus(s8, 3) == -2);
                CHECK(nkr::os::atomic::Access(s8) == -2);
                /// [_09a95d9e_4847_4f58_95a8_6396ff3a0ab1]
            }
            TEST_CASE("u16_t")
            {
                /// [_e25f536a_fcd5_4413_8fd6_b47baa107b6d]
                u16_t u16 = 16;
                CHECK(nkr::os::atomic::Assign_Modulus(u16, 3) == 1);
                CHECK(nkr::os::atomic::Access(u16) == 1);
                /// [_e25f536a_fcd5_4413_8fd6_b47baa107b6d]
            }
            TEST_CASE("s16_t")
            {
                /// [_4ded43f9_9df8_454d_b5b4_35315881d54a]
                s16_t s16 = -16;
                CHECK(nkr::os::atomic::Assign_Modulus(s16, 3) == -1);
                CHECK(nkr::os::atomic::Access(s16) == -1);
                /// [_4ded43f9_9df8_454d_b5b4_35315881d54a]
            }
            TEST_CASE("u32_t")
            {
                /// [_317da99a_2b06_46c1_9a37_069ea37e604c]
                u32_t u32 = 32;
                CHECK(nkr::os::atomic::Assign_Modulus(u32, 3) == 2);
                CHECK(nkr::os::atomic::Access(u32) == 2);
                /// [_317da99a_2b06_46c1_9a37_069ea37e604c]
            }
            TEST_CASE("s32_t")
            {
                /// [_4249b8b9_936a_4127_a7c8_7bfb23acbb08]
                s32_t s32 = -32;
                CHECK(nkr::os::atomic::Assign_Modulus(s32, 3) == -2);
                CHECK(nkr::os::atomic::Access(s32) == -2);
                /// [_4249b8b9_936a_4127_a7c8_7bfb23acbb08]
            }
            TEST_CASE("u64_t")
            {
            #if defined(nkr_IS_64_BIT)
                /// [_aa058824_a6ca_40fd_b830_25a00e34fcf9]
                u64_t u64 = 64;
                CHECK(nkr::os::atomic::Assign_Modulus(u64, 3) == 1);
                CHECK(nkr::os::atomic::Access(u64) == 1);
                /// [_aa058824_a6ca_40fd_b830_25a00e34fcf9]
            #endif
            }
            TEST_CASE("s64_t")
            {
            #if defined(nkr_IS_64_BIT)
                /// [_3aa20522_3a5b_48ba_962e_ab97c053e89d]
                s64_t s64 = -64;
                CHECK(nkr::os::atomic::Assign_Modulus(s64, 3) == -1);
                CHECK(nkr::os::atomic::Access(s64) == -1);
                /// [_3aa20522_3a5b_48ba_962e_ab97c053e89d]
            #endif
            }
        }
    }

    TEST_SUITE("Assign_Or")
    {
        TEST_SUITE("should atomically OR integers and return the new value")
        {
            TEST_CASE("u8_t")
            {
                /// [_0c091082_f16a_4191_b4df_47c16a226b29]
                u8_t u8 = 0x0F;
                CHECK(nkr::os::atomic::Assign_Or(u8, 0xF0) == 0xFF);
                CHECK(u8 == 0xFF);
                /// [_0c091082_f16a_4191_b4df_47c16a226b29]
            }
            TEST_CASE("s8_t")
            {
                /// [_52b2ca48_5b7e_416d_b114_a33a9fd80729]
                s8_t s8 = 0x0F;
                CHECK(nkr::os::atomic::Assign_Or(s8, 0x70) == 0x7F);
                CHECK(s8 == 0x7F);
                /// [_52b2ca48_5b7e_416d_b114_a33a9fd80729]
            }
            TEST_CASE("u16_t")
            {
                /// [_8d732dc3_39b8_4aeb_a702_bfb6319f8e81]
                u16_t u16 = 0x00FF;
                CHECK(nkr::os::atomic::Assign_Or(u16, 0xFF00) == 0xFFFF);
                CHECK(u16 == 0xFFFF);
                /// [_8d732dc3_39b8_4aeb_a702_bfb6319f8e81]
            }
            TEST_CASE("s16_t")
            {
                /// [_9a368038_17ac_486f_a691_8a9b81b62a77]
                s16_t s16 = 0x00FF;
                CHECK(nkr::os::atomic::Assign_Or(s16, 0x7F00) == 0x7FFF);
                CHECK(s16 == 0x7FFF);
                /// [_9a368038_17ac_486f_a691_8a9b81b62a77]
            }
            TEST_CASE("u32_t")
            {
                /// [_01f510ab_80e8_4341_bcbb_5c07ba15ef54]
                u32_t u32 = 0x0000FFFF;
                CHECK(nkr::os::atomic::Assign_Or(u32, 0xFFFF0000) == 0xFFFFFFFF);
                CHECK(u32 == 0xFFFFFFFF);
                /// [_01f510ab_80e8_4341_bcbb_5c07ba15ef54]
            }
            TEST_CASE("s32_t")
            {
                /// [_6792a80d_bebc_47d5_8428_84a51dbce102]
                s32_t s32 = 0x0000FFFF;
                CHECK(nkr::os::atomic::Assign_Or(s32, 0x7FFF0000) == 0x7FFFFFFF);
                CHECK(s32 == 0x7FFFFFFF);
                /// [_6792a80d_bebc_47d5_8428_84a51dbce102]
            }
            TEST_CASE("u64_t")
            {
            #if defined(nkr_IS_64_BIT)
                /// [_f9d87c0b_2f20_4842_9f6d_0f960ce3ab37]
                u64_t u64 = 0x00000000FFFFFFFF;
                CHECK(nkr::os::atomic::Assign_Or(u64, 0xFFFFFFFF00000000) == 0xFFFFFFFFFFFFFFFF);
                CHECK(u64 == 0xFFFFFFFFFFFFFFFF);
                /// [_f9d87c0b_2f20_4842_9f6d_0f960ce3ab37]
            #endif
            }
            TEST_CASE("s64_t")
            {
            #if defined(nkr_IS_64_BIT)
                /// [_780dbae3_f5cd_4225_aca9_cfe5beb365b1]
                s64_t s64 = 0x00000000FFFFFFFF;
                CHECK(nkr::os::atomic::Assign_Or(s64, 0x7FFFFFFF00000000) == 0x7FFFFFFFFFFFFFFF);
                CHECK(s64 == 0x7FFFFFFFFFFFFFFF);
                /// [_780dbae3_f5cd_4225_aca9_cfe5beb365b1]
            #endif
            }
        }
    }

    TEST_SUITE("Assign_And")
    {
        TEST_SUITE("should atomically AND integers and return the new value")
        {
            TEST_CASE("u8_t")
            {
                /// [_dfaf4e53_bff6_41fe_9bb3_dba77d644596]
                u8_t u8 = 0x0F;
                CHECK(nkr::os::atomic::Assign_And(u8, 0xF0) == 0x0);
                CHECK(u8 == 0x0);
                /// [_dfaf4e53_bff6_41fe_9bb3_dba77d644596]
            }
            TEST_CASE("s8_t")
            {
                /// [_7370ea21_e07a_43d5_9b97_a87a12ac06f6]
                s8_t s8 = 0x0F;
                CHECK(nkr::os::atomic::Assign_And(s8, 0x70) == 0x0);
                CHECK(s8 == 0x0);
                /// [_7370ea21_e07a_43d5_9b97_a87a12ac06f6]
            }
            TEST_CASE("u16_t")
            {
                /// [_4bfb5b89_83fb_487e_a0c1_865c2533809c]
                u16_t u16 = 0x00FF;
                CHECK(nkr::os::atomic::Assign_And(u16, 0xFF00) == 0x0);
                CHECK(u16 == 0x0);
                /// [_4bfb5b89_83fb_487e_a0c1_865c2533809c]
            }
            TEST_CASE("s16_t")
            {
                /// [_c0f4c5bb_8faf_4904_84a9_6c4dcb7ea603]
                s16_t s16 = 0x00FF;
                CHECK(nkr::os::atomic::Assign_And(s16, 0x7F00) == 0x0);
                CHECK(s16 == 0x0);
                /// [_c0f4c5bb_8faf_4904_84a9_6c4dcb7ea603]
            }
            TEST_CASE("u32_t")
            {
                /// [_140184e1_4abd_4130_babe_8f5df1ca526e]
                u32_t u32 = 0x0000FFFF;
                CHECK(nkr::os::atomic::Assign_And(u32, 0xFFFF0000) == 0x0);
                CHECK(u32 == 0x0);
                /// [_140184e1_4abd_4130_babe_8f5df1ca526e]
            }
            TEST_CASE("s32_t")
            {
                /// [_a455ba0f_aa8b_4757_8df7_2fd97bfe1716]
                s32_t s32 = 0x0000FFFF;
                CHECK(nkr::os::atomic::Assign_And(s32, 0x7FFF0000) == 0x0);
                CHECK(s32 == 0x0);
                /// [_a455ba0f_aa8b_4757_8df7_2fd97bfe1716]
            }
            TEST_CASE("u64_t")
            {
            #if defined(nkr_IS_64_BIT)
                /// [_3ea87c9b_9f77_4856_818b_8b1dbbbd9abb]
                u64_t u64 = 0x00000000FFFFFFFF;
                CHECK(nkr::os::atomic::Assign_And(u64, 0xFFFFFFFF00000000) == 0x0);
                CHECK(u64 == 0x0);
                /// [_3ea87c9b_9f77_4856_818b_8b1dbbbd9abb]
            #endif
            }
            TEST_CASE("s64_t")
            {
            #if defined(nkr_IS_64_BIT)
                /// [_e2a9bb20_c214_4ed0_ab84_9c02be6467d0]
                s64_t s64 = 0x00000000FFFFFFFF;
                CHECK(nkr::os::atomic::Assign_And(s64, 0x7FFFFFFF00000000) == 0x0);
                CHECK(s64 == 0x0);
                /// [_e2a9bb20_c214_4ed0_ab84_9c02be6467d0]
            #endif
            }
        }
    }

    TEST_SUITE("Assign_Xor")
    {
        TEST_SUITE("should atomically XOR integers and return the new value")
        {
            TEST_CASE("u8_t")
            {
                /// [_eb406fdb_035c_44ce_92fd_1cf5e3c4eb6d]
                u8_t u8 = 0xFF;
                CHECK(nkr::os::atomic::Assign_Xor(u8, 0x01) == 0xFE);
                CHECK(u8 == 0xFE);
                /// [_eb406fdb_035c_44ce_92fd_1cf5e3c4eb6d]
            }
            TEST_CASE("s8_t")
            {
                /// [_63f6f17b_8ddf_4372_95c2_7003f20c3187]
                s8_t s8 = 0x7F;
                CHECK(nkr::os::atomic::Assign_Xor(s8, 0x01) == 0x7E);
                CHECK(s8 == 0x7E);
                /// [_63f6f17b_8ddf_4372_95c2_7003f20c3187]
            }
            TEST_CASE("u16_t")
            {
                /// [_cc214ce6_144e_4eb2_bc81_87af69d0aff9]
                u16_t u16 = 0xFFFF;
                CHECK(nkr::os::atomic::Assign_Xor(u16, 0x0001) == 0xFFFE);
                CHECK(u16 == 0xFFFE);
                /// [_cc214ce6_144e_4eb2_bc81_87af69d0aff9]
            }
            TEST_CASE("s16_t")
            {
                /// [_7486f2e0_fb47_46f0_b8ff_949c1809ea38]
                s16_t s16 = 0x7FFF;
                CHECK(nkr::os::atomic::Assign_Xor(s16, 0x0001) == 0x7FFE);
                CHECK(s16 == 0x7FFE);
                /// [_7486f2e0_fb47_46f0_b8ff_949c1809ea38]
            }
            TEST_CASE("u32_t")
            {
                /// [_95a04b10_e89d_4938_891d_75073476a3aa]
                u32_t u32 = 0xFFFFFFFF;
                CHECK(nkr::os::atomic::Assign_Xor(u32, 0x00000001) == 0xFFFFFFFE);
                CHECK(u32 == 0xFFFFFFFE);
                /// [_95a04b10_e89d_4938_891d_75073476a3aa]
            }
            TEST_CASE("s32_t")
            {
                /// [_5e50cd9e_e47e_4964_aaf9_098b07569185]
                s32_t s32 = 0x7FFFFFFF;
                CHECK(nkr::os::atomic::Assign_Xor(s32, 0x00000001) == 0x7FFFFFFE);
                CHECK(s32 == 0x7FFFFFFE);
                /// [_5e50cd9e_e47e_4964_aaf9_098b07569185]
            }
            TEST_CASE("u64_t")
            {
            #if defined(nkr_IS_64_BIT)
                /// [_3fef8807_197b_42c5_bda1_ea4f9c8b4436]
                u64_t u64 = 0xFFFFFFFFFFFFFFFF;
                CHECK(nkr::os::atomic::Assign_Xor(u64, 0x0000000000000001) == 0xFFFFFFFFFFFFFFFE);
                CHECK(u64 == 0xFFFFFFFFFFFFFFFE);
                /// [_3fef8807_197b_42c5_bda1_ea4f9c8b4436]
            #endif
            }
            TEST_CASE("s64_t")
            {
            #if defined(nkr_IS_64_BIT)
                /// [_f017cb1a_db20_4aac_bf79_1e8784e4113d]
                s64_t s64 = 0x7FFFFFFFFFFFFFFF;
                CHECK(nkr::os::atomic::Assign_Xor(s64, 0x0000000000000001) == 0x7FFFFFFFFFFFFFFE);
                CHECK(s64 == 0x7FFFFFFFFFFFFFFE);
                /// [_f017cb1a_db20_4aac_bf79_1e8784e4113d]
            #endif
            }
        }
    }

    TEST_SUITE("Assign_Left_Shift()")
    {
        TEST_SUITE("should return value << operator and change the value")
        {
            TEST_CASE("u8_t")
            {
                /// [_1a005cee_5206_4b43_8859_eda42b154535]
                u8_t u8 = 0x0F;
                CHECK(nkr::os::atomic::Assign_Left_Shift(u8, 4) == 0xF0);
                CHECK(nkr::os::atomic::Access(u8) == 0xF0);
                /// [_1a005cee_5206_4b43_8859_eda42b154535]
            }
            TEST_CASE("s8_t")
            {
                /// [_52fc19ab_c81e_4c0a_9e6a_fc5f991f6b58]
                s8_t s8 = 0x07;
                CHECK(nkr::os::atomic::Assign_Left_Shift(s8, 4) == 0x70);
                CHECK(nkr::os::atomic::Access(s8) == 0x70);
                /// [_52fc19ab_c81e_4c0a_9e6a_fc5f991f6b58]
            }
            TEST_CASE("u16_t")
            {
                /// [_0ee1c4a5_6446_4b45_92d5_b8f732124d3d]
                u16_t u16 = 0x00FF;
                CHECK(nkr::os::atomic::Assign_Left_Shift(u16, 8) == 0xFF00);
                CHECK(nkr::os::atomic::Access(u16) == 0xFF00);
                /// [_0ee1c4a5_6446_4b45_92d5_b8f732124d3d]
            }
            TEST_CASE("s16_t")
            {
                /// [_0ed7cb6f_1341_485b_be50_9c7829f270dc]
                s16_t s16 = 0x007F;
                CHECK(nkr::os::atomic::Assign_Left_Shift(s16, 8) == 0x7F00);
                CHECK(nkr::os::atomic::Access(s16) == 0x7F00);
                /// [_0ed7cb6f_1341_485b_be50_9c7829f270dc]
            }
            TEST_CASE("u32_t")
            {
                /// [_380f0fd7_96e7_455d_a59e_b387bc9be53c]
                u32_t u32 = 0x0000FFFF;
                CHECK(nkr::os::atomic::Assign_Left_Shift(u32, 16) == 0xFFFF0000);
                CHECK(nkr::os::atomic::Access(u32) == 0xFFFF0000);
                /// [_380f0fd7_96e7_455d_a59e_b387bc9be53c]
            }
            TEST_CASE("s32_t")
            {
                /// [_7f8337cc_7c72_4034_b375_59865eb1d509]
                s32_t s32 = 0x00007FFF;
                CHECK(nkr::os::atomic::Assign_Left_Shift(s32, 16) == 0x7FFF0000);
                CHECK(nkr::os::atomic::Access(s32) == 0x7FFF0000);
                /// [_7f8337cc_7c72_4034_b375_59865eb1d509]
            }
            TEST_CASE("u64_t")
            {
            #if defined(nkr_IS_64_BIT)
                /// [_2096c670_8a5e_4029_9fff_f3f05f41cc8c]
                u64_t u64 = 0x00000000FFFFFFFF;
                CHECK(nkr::os::atomic::Assign_Left_Shift(u64, 32) == 0xFFFFFFFF00000000);
                CHECK(nkr::os::atomic::Access(u64) == 0xFFFFFFFF00000000);
                /// [_2096c670_8a5e_4029_9fff_f3f05f41cc8c]
            #endif
            }
            TEST_CASE("s64_t")
            {
            #if defined(nkr_IS_64_BIT)
                /// [_cc34697a_eed6_4fbf_94f6_85db83431b33]
                s64_t s64 = 0x000000007FFFFFFF;
                CHECK(nkr::os::atomic::Assign_Left_Shift(s64, 32) == 0x7FFFFFFF00000000);
                CHECK(nkr::os::atomic::Access(s64) == 0x7FFFFFFF00000000);
                /// [_cc34697a_eed6_4fbf_94f6_85db83431b33]
            #endif
            }
        }
    }

    TEST_SUITE("Assign_Right_Shift()")
    {
        TEST_SUITE("should return value >> operator and change the value")
        {
            TEST_CASE("u8_t")
            {
                /// [_b3b8bd2e_dd4a_4946_951e_9c4260f44967]
                u8_t u8 = 0xF0;
                CHECK(nkr::os::atomic::Assign_Right_Shift(u8, 4) == 0x0F);
                CHECK(nkr::os::atomic::Access(u8) == 0x0F);
                /// [_b3b8bd2e_dd4a_4946_951e_9c4260f44967]
            }
            TEST_CASE("s8_t")
            {
                /// [_8fed06e0_51df_47ba_a084_f3e2ee7496bc]
                s8_t s8 = 0x70;
                CHECK(nkr::os::atomic::Assign_Right_Shift(s8, 4) == 0x07);
                CHECK(nkr::os::atomic::Access(s8) == 0x07);
                /// [_8fed06e0_51df_47ba_a084_f3e2ee7496bc]
            }
            TEST_CASE("u16_t")
            {
                /// [_25ebab4b_9cf5_4a82_98e0_ef4653587b68]
                u16_t u16 = 0xFF00;
                CHECK(nkr::os::atomic::Assign_Right_Shift(u16, 8) == 0x00FF);
                CHECK(nkr::os::atomic::Access(u16) == 0x00FF);
                /// [_25ebab4b_9cf5_4a82_98e0_ef4653587b68]
            }
            TEST_CASE("s16_t")
            {
                /// [_fc404bcc_5c9f_42d3_b5f0_97f17fabb7b2]
                s16_t s16 = 0x7F00;
                CHECK(nkr::os::atomic::Assign_Right_Shift(s16, 8) == 0x007F);
                CHECK(nkr::os::atomic::Access(s16) == 0x007F);
                /// [_fc404bcc_5c9f_42d3_b5f0_97f17fabb7b2]
            }
            TEST_CASE("u32_t")
            {
                /// [_9dc82ff0_4a80_4d76_bfc2_7580c2c45b7f]
                u32_t u32 = 0xFFFF0000;
                CHECK(nkr::os::atomic::Assign_Right_Shift(u32, 16) == 0x0000FFFF);
                CHECK(nkr::os::atomic::Access(u32) == 0x0000FFFF);
                /// [_9dc82ff0_4a80_4d76_bfc2_7580c2c45b7f]
            }
            TEST_CASE("s32_t")
            {
                /// [_1adb7e43_533b_41a3_820b_1f518e198d31]
                s32_t s32 = 0x7FFF0000;
                CHECK(nkr::os::atomic::Assign_Right_Shift(s32, 16) == 0x00007FFF);
                CHECK(nkr::os::atomic::Access(s32) == 0x00007FFF);
                /// [_1adb7e43_533b_41a3_820b_1f518e198d31]
            }
            TEST_CASE("u64_t")
            {
            #if defined(nkr_IS_64_BIT)
                /// [_8f7b2f70_64c0_4a83_8b4a_032a87600110]
                u64_t u64 = 0xFFFFFFFF00000000;
                CHECK(nkr::os::atomic::Assign_Right_Shift(u64, 32) == 0x00000000FFFFFFFF);
                CHECK(nkr::os::atomic::Access(u64) == 0x00000000FFFFFFFF);
                /// [_8f7b2f70_64c0_4a83_8b4a_032a87600110]
            #endif
            }
            TEST_CASE("s64_t")
            {
            #if defined(nkr_IS_64_BIT)
                /// [_da286c4c_7bba_419c_a97d_502c5846c60b]
                s64_t s64 = 0x7FFFFFFF00000000;
                CHECK(nkr::os::atomic::Assign_Right_Shift(s64, 32) == 0x000000007FFFFFFF);
                CHECK(nkr::os::atomic::Access(s64) == 0x000000007FFFFFFF);
                /// [_da286c4c_7bba_419c_a97d_502c5846c60b]
            #endif
            }
        }
    }

    TEST_SUITE("Exchange")
    {
        TEST_SUITE("should atomically assign integers and pointers and return the initial value")
        {
            TEST_CASE("bool_t")
            {
                /// [_a7c419d6_98aa_4ffc_98ab_68d4e73a7d48]
                bool_t boolean = false;
                CHECK(nkr::os::atomic::Exchange(boolean, true) == false);
                CHECK(nkr::os::atomic::Access(boolean) == true);
                /// [_a7c419d6_98aa_4ffc_98ab_68d4e73a7d48]
            }
            TEST_CASE("std_bool_t")
            {
                /// [_f41bfb76_1282_402a_8cc6_8ab579f5218e]
                std_bool_t boolean = false;
                CHECK(nkr::os::atomic::Exchange(boolean, true) == false);
                CHECK(nkr::os::atomic::Access(boolean) == true);
                /// [_f41bfb76_1282_402a_8cc6_8ab579f5218e]
            }
            TEST_CASE("u8_t")
            {
                /// [_5d7a6387_6b1c_4703_8ae2_c8a9247a08b1]
                u8_t u8 = 8;
                CHECK(nkr::os::atomic::Exchange(u8, 1) == 8);
                CHECK(nkr::os::atomic::Access(u8) == 1);
                /// [_5d7a6387_6b1c_4703_8ae2_c8a9247a08b1]
            }
            TEST_CASE("s8_t")
            {
                /// [_73aa5ca4_f6cb_43b9_b121_6fcd9adbf79a]
                s8_t s8 = -8;
                CHECK(nkr::os::atomic::Exchange(s8, -1) == -8);
                CHECK(nkr::os::atomic::Access(s8) == -1);
                /// [_73aa5ca4_f6cb_43b9_b121_6fcd9adbf79a]
            }
            TEST_CASE("u16_t")
            {
                /// [_9d097f54_43d3_4c69_a6ac_4cc11d524cba]
                u16_t u16 = 16;
                CHECK(nkr::os::atomic::Exchange(u16, 1) == 16);
                CHECK(nkr::os::atomic::Access(u16) == 1);
                /// [_9d097f54_43d3_4c69_a6ac_4cc11d524cba]
            }
            TEST_CASE("s16_t")
            {
                /// [_c068b9cd_7d78_4b0e_9c84_c8bec41e589a]
                s16_t s16 = -16;
                CHECK(nkr::os::atomic::Exchange(s16, -1) == -16);
                CHECK(nkr::os::atomic::Access(s16) == -1);
                /// [_c068b9cd_7d78_4b0e_9c84_c8bec41e589a]
            }
            TEST_CASE("u32_t")
            {
                /// [_9e1e63d7_c87e_4fab_a4a1_58f18113b758]
                u32_t u32 = 32;
                CHECK(nkr::os::atomic::Exchange(u32, 1) == 32);
                CHECK(nkr::os::atomic::Access(u32) == 1);
                /// [_9e1e63d7_c87e_4fab_a4a1_58f18113b758]
            }
            TEST_CASE("s32_t")
            {
                /// [_c397b47e_e733_43af_bfe8_e6c6627d0ad1]
                s32_t s32 = -32;
                CHECK(nkr::os::atomic::Exchange(s32, -1) == -32);
                CHECK(nkr::os::atomic::Access(s32) == -1);
                /// [_c397b47e_e733_43af_bfe8_e6c6627d0ad1]
            }
            TEST_CASE("u64_t")
            {
            #if defined(nkr_IS_64_BIT)
                /// [_9cb98866_0340_4b51_b223_c7423516dacd]
                u64_t u64 = 64;
                CHECK(nkr::os::atomic::Exchange(u64, 1) == 64);
                CHECK(nkr::os::atomic::Access(u64) == 1);
                /// [_9cb98866_0340_4b51_b223_c7423516dacd]
            #endif
            }
            TEST_CASE("s64_t")
            {
            #if defined(nkr_IS_64_BIT)
                /// [_1d45c35f_0596_46f6_b585_31de82f7da16]
                s64_t s64 = -64;
                CHECK(nkr::os::atomic::Exchange(s64, -1) == -64);
                CHECK(nkr::os::atomic::Access(s64) == -1);
                /// [_1d45c35f_0596_46f6_b585_31de82f7da16]
            #endif
            }
            TEST_CASE("f32_t")
            {
                /// [_16994b0a_fada_4042_83cb_9236e766d99c]
                f32_t f32 = 3.2f;
                CHECK(nkr::os::atomic::Exchange(f32, -3.2f) == 3.2f);
                CHECK(nkr::os::atomic::Access(f32) == -3.2f);
                /// [_16994b0a_fada_4042_83cb_9236e766d99c]
            }
            TEST_CASE("f64_t")
            {
            #if defined(nkr_IS_64_BIT)
                /// [_2c26bdeb_db83_4fdd_9678_b9c005a4b8ca]
                f64_t f64 = 6.4;
                CHECK(nkr::os::atomic::Exchange(f64, -6.4) == 6.4);
                CHECK(nkr::os::atomic::Access(f64) == -6.4);
                /// [_2c26bdeb_db83_4fdd_9678_b9c005a4b8ca]
            #endif
            }
            TEST_CASE("void_t*")
            {
                /// [_080b46f9_4ba2_42cc_8933_7354d9aa4f9f]
                bool_t boolean = false;
                void_t* void_pointer = nullptr;
                CHECK(nkr::os::atomic::Exchange(void_pointer, &boolean) == nullptr);
                CHECK(nkr::os::atomic::Access(void_pointer) == &boolean);
                /// [_080b46f9_4ba2_42cc_8933_7354d9aa4f9f]
            }
            TEST_CASE("bool_t*")
            {
                /// [_24e60c17_b0bd_42e9_9197_7fd8d1e40e7d]
                bool_t boolean = false;
                bool_t* boolean_pointer = &boolean;
                CHECK(nkr::os::atomic::Exchange(boolean_pointer, nullptr) == &boolean);
                CHECK(nkr::os::atomic::Access(boolean_pointer) == nullptr);
                /// [_24e60c17_b0bd_42e9_9197_7fd8d1e40e7d]
            }
        }
    }

    TEST_SUITE("Exchange_Add")
    {
        TEST_SUITE("should atomically add to integers and pointers and return the initial value")
        {
            TEST_CASE("u8_t")
            {
                /// [_10d21753_6d97_451b_85c8_eca8d63637db]
                u8_t u8 = 8;
                CHECK(nkr::os::atomic::Exchange_Add(u8, 1) == 8);
                CHECK(nkr::os::atomic::Access(u8) == 9);
                /// [_10d21753_6d97_451b_85c8_eca8d63637db]
            }
            TEST_CASE("s8_t")
            {
                /// [_ef19cacd_3ac4_4fe0_b0e5_a374975720e1]
                s8_t s8 = -8;
                CHECK(nkr::os::atomic::Exchange_Add(s8, -1) == -8);
                CHECK(nkr::os::atomic::Access(s8) == -9);
                /// [_ef19cacd_3ac4_4fe0_b0e5_a374975720e1]
            }
            TEST_CASE("u16_t")
            {
                /// [_b5fc4003_cb0c_41d4_beb2_23c3c636dfc6]
                u16_t u16 = 16;
                CHECK(nkr::os::atomic::Exchange_Add(u16, 1) == 16);
                CHECK(nkr::os::atomic::Access(u16) == 17);
                /// [_b5fc4003_cb0c_41d4_beb2_23c3c636dfc6]
            }
            TEST_CASE("s16_t")
            {
                /// [_466c7087_2aa2_48d0_87fe_43ff3a9e914c]
                s16_t s16 = -16;
                CHECK(nkr::os::atomic::Exchange_Add(s16, -1) == -16);
                CHECK(nkr::os::atomic::Access(s16) == -17);
                /// [_466c7087_2aa2_48d0_87fe_43ff3a9e914c]
            }
            TEST_CASE("u32_t")
            {
                /// [_2d4b79b3_0d75_4b7f_81c0_d38e83b69d14]
                u32_t u32 = 32;
                CHECK(nkr::os::atomic::Exchange_Add(u32, 1) == 32);
                CHECK(nkr::os::atomic::Access(u32) == 33);
                /// [_2d4b79b3_0d75_4b7f_81c0_d38e83b69d14]
            }
            TEST_CASE("s32_t")
            {
                /// [_708eb7d4_8be3_4272_b67b_6c77789cc2d6]
                s32_t s32 = -32;
                CHECK(nkr::os::atomic::Exchange_Add(s32, -1) == -32);
                CHECK(nkr::os::atomic::Access(s32) == -33);
                /// [_708eb7d4_8be3_4272_b67b_6c77789cc2d6]
            }
            TEST_CASE("u64_t")
            {
            #if defined(nkr_IS_64_BIT)
                /// [_3d91d064_5f90_49e2_9e3d_1f89a09312f0]
                u64_t u64 = 64;
                CHECK(nkr::os::atomic::Exchange_Add(u64, 1) == 64);
                CHECK(nkr::os::atomic::Access(u64) == 65);
                /// [_3d91d064_5f90_49e2_9e3d_1f89a09312f0]
            #endif
            }
            TEST_CASE("s64_t")
            {
            #if defined(nkr_IS_64_BIT)
                /// [_2f84130b_a6b9_4715_845a_f1a53e0457f6]
                s64_t s64 = -64;
                CHECK(nkr::os::atomic::Exchange_Add(s64, -1) == -64);
                CHECK(nkr::os::atomic::Access(s64) == -65);
                /// [_2f84130b_a6b9_4715_845a_f1a53e0457f6]
            #endif
            }
            TEST_CASE("f32_t")
            {
                /// [_8451cd60_f17d_4c6f_9bfe_7bc37d879bce]
                f32_t f32 = 3.2f;
                CHECK(nkr::os::atomic::Exchange_Add(f32, 0.1f) == 3.2f);
                CHECK(nkr::os::atomic::Access(f32) == 3.2f + 0.1f);
                /// [_8451cd60_f17d_4c6f_9bfe_7bc37d879bce]
            }
            TEST_CASE("f64_t")
            {
            #if defined(nkr_IS_64_BIT)
                /// [_92398c40_af25_4bd4_a2e9_be7aaf159b62]
                f64_t f64 = 6.4;
                CHECK(nkr::os::atomic::Exchange_Add(f64, 0.1) == 6.4);
                CHECK(nkr::os::atomic::Access(f64) == 6.4 + 0.1);
                /// [_92398c40_af25_4bd4_a2e9_be7aaf159b62]
            #endif
            }
            TEST_CASE("bool_t*")
            {
                /// [_4d9f5f22_f8aa_4316_bd0d_f8739139bd4e]
                bool_t booleans[2] = { true, true };
                bool_t* boolean_pointer = booleans;
                CHECK(nkr::os::atomic::Exchange_Add(boolean_pointer, 1) == booleans + 0);
                CHECK(nkr::os::atomic::Access(boolean_pointer) == booleans + 1);
                CHECK(nkr::os::atomic::Exchange_Add(boolean_pointer, -1) == booleans + 1);
                CHECK(nkr::os::atomic::Access(boolean_pointer) == booleans + 0);
                /// [_4d9f5f22_f8aa_4316_bd0d_f8739139bd4e]
            }
        }
    }

    TEST_SUITE("Exchange_Subtract")
    {
        TEST_SUITE("should atomically subtract from integers and pointers and return the initial value")
        {
            TEST_CASE("u8_t")
            {
                /// [_20744002_f37b_4c23_92aa_8b62069ad732]
                u8_t u8 = 8;
                CHECK(nkr::os::atomic::Exchange_Subtract(u8, 1) == 8);
                CHECK(nkr::os::atomic::Access(u8) == 7);
                /// [_20744002_f37b_4c23_92aa_8b62069ad732]
            }
            TEST_CASE("s8_t")
            {
                /// [_e8507f13_5b14_45c9_b80f_0141c2d060a9]
                s8_t s8 = -8;
                CHECK(nkr::os::atomic::Exchange_Subtract(s8, -1) == -8);
                CHECK(nkr::os::atomic::Access(s8) == -7);
                /// [_e8507f13_5b14_45c9_b80f_0141c2d060a9]
            }
            TEST_CASE("u16_t")
            {
                /// [_50a6d11d_7811_42d6_8be0_e3aeb7f1b4fd]
                u16_t u16 = 16;
                CHECK(nkr::os::atomic::Exchange_Subtract(u16, 1) == 16);
                CHECK(nkr::os::atomic::Access(u16) == 15);
                /// [_50a6d11d_7811_42d6_8be0_e3aeb7f1b4fd]
            }
            TEST_CASE("s16_t")
            {
                /// [_a3ca2726_2c3c_49a0_b941_544ff20d6af3]
                s16_t s16 = -16;
                CHECK(nkr::os::atomic::Exchange_Subtract(s16, -1) == -16);
                CHECK(nkr::os::atomic::Access(s16) == -15);
                /// [_a3ca2726_2c3c_49a0_b941_544ff20d6af3]
            }
            TEST_CASE("u32_t")
            {
                /// [_96bb38d9_2aac_4139_80de_164ed9e33a30]
                u32_t u32 = 32;
                CHECK(nkr::os::atomic::Exchange_Subtract(u32, 1) == 32);
                CHECK(nkr::os::atomic::Access(u32) == 31);
                /// [_96bb38d9_2aac_4139_80de_164ed9e33a30]
            }
            TEST_CASE("s32_t")
            {
                /// [_f3d0c80d_5c11_49c6_aaec_770d978e2d0d]
                s32_t s32 = -32;
                CHECK(nkr::os::atomic::Exchange_Subtract(s32, -1) == -32);
                CHECK(nkr::os::atomic::Access(s32) == -31);
                /// [_f3d0c80d_5c11_49c6_aaec_770d978e2d0d]
            }
            TEST_CASE("u64_t")
            {
            #if defined(nkr_IS_64_BIT)
                /// [_afa92ac1_a5a3_403b_a99a_a3982df4c2f6]
                u64_t u64 = 64;
                CHECK(nkr::os::atomic::Exchange_Subtract(u64, 1) == 64);
                CHECK(nkr::os::atomic::Access(u64) == 63);
                /// [_afa92ac1_a5a3_403b_a99a_a3982df4c2f6]
            #endif
            }
            TEST_CASE("s64_t")
            {
            #if defined(nkr_IS_64_BIT)
                /// [_104e19d6_03ce_49d2_8854_02c41c5d924b]
                s64_t s64 = -64;
                CHECK(nkr::os::atomic::Exchange_Subtract(s64, -1) == -64);
                CHECK(nkr::os::atomic::Access(s64) == -63);
                /// [_104e19d6_03ce_49d2_8854_02c41c5d924b]
            #endif
            }
            TEST_CASE("f32_t")
            {
                /// [_9236c949_c671_4805_9716_dc6215f54a61]
                f32_t f32 = 3.2f;
                CHECK(nkr::os::atomic::Exchange_Subtract(f32, 0.1f) == 3.2f);
                CHECK(nkr::os::atomic::Access(f32) == 3.2f - 0.1f);
                /// [_9236c949_c671_4805_9716_dc6215f54a61]
            }
            TEST_CASE("f64_t")
            {
            #if defined(nkr_IS_64_BIT)
                /// [_a2c0a2b8_463a_4501_a164_3dfd614054d6]
                f64_t f64 = 6.4;
                CHECK(nkr::os::atomic::Exchange_Subtract(f64, 0.1) == 6.4);
                CHECK(nkr::os::atomic::Access(f64) == 6.4 - 0.1);
                /// [_a2c0a2b8_463a_4501_a164_3dfd614054d6]
            #endif
            }
            TEST_CASE("bool_t*")
            {
                /// [_8055b945_5e3d_4f07_96aa_f29e46a91dc2]
                bool_t booleans[2] = { true, true };
                bool_t* boolean_pointer = booleans + 1;
                CHECK(nkr::os::atomic::Exchange_Subtract(boolean_pointer, 1) == booleans + 1);
                CHECK(nkr::os::atomic::Access(boolean_pointer) == booleans + 0);
                CHECK(nkr::os::atomic::Exchange_Subtract(boolean_pointer, -1) == booleans + 0);
                CHECK(nkr::os::atomic::Access(boolean_pointer) == booleans + 1);
                /// [_8055b945_5e3d_4f07_96aa_f29e46a91dc2]
            }
        }
    }

    TEST_SUITE("Exchange_Multiply()")
    {
        TEST_SUITE("should multiply its value with the operand and return the initial value")
        {
            TEST_CASE("u8_t")
            {
                /// [_3e5d0dd4_d95d_43bc_9336_2dd33dfb82ec]
                u8_t u8 = 8;
                CHECK(nkr::os::atomic::Exchange_Multiply(u8, 2) == 8);
                CHECK(nkr::os::atomic::Access(u8) == 16);
                /// [_3e5d0dd4_d95d_43bc_9336_2dd33dfb82ec]
            }
            TEST_CASE("s8_t")
            {
                /// [_36b9dd3e_9f32_4747_af50_f4d387febd23]
                s8_t s8 = -8;
                CHECK(nkr::os::atomic::Exchange_Multiply(s8, 2) == -8);
                CHECK(nkr::os::atomic::Access(s8) == -16);
                /// [_36b9dd3e_9f32_4747_af50_f4d387febd23]
            }
            TEST_CASE("u16_t")
            {
                /// [_a4c080f1_f51e_4ca4_b1cb_380e20e99b09]
                u16_t u16 = 16;
                CHECK(nkr::os::atomic::Exchange_Multiply(u16, 2) == 16);
                CHECK(nkr::os::atomic::Access(u16) == 32);
                /// [_a4c080f1_f51e_4ca4_b1cb_380e20e99b09]
            }
            TEST_CASE("s16_t")
            {
                /// [_4a5be7a2_ce91_432e_a9b9_5bfb41ebb91b]
                s16_t s16 = -16;
                CHECK(nkr::os::atomic::Exchange_Multiply(s16, 2) == -16);
                CHECK(nkr::os::atomic::Access(s16) == -32);
                /// [_4a5be7a2_ce91_432e_a9b9_5bfb41ebb91b]
            }
            TEST_CASE("u32_t")
            {
                /// [_c62ea543_cfed_4c26_a020_8d70c7428869]
                u32_t u32 = 32;
                CHECK(nkr::os::atomic::Exchange_Multiply(u32, 2) == 32);
                CHECK(nkr::os::atomic::Access(u32) == 64);
                /// [_c62ea543_cfed_4c26_a020_8d70c7428869]
            }
            TEST_CASE("s32_t")
            {
                /// [_dd7a4689_f747_4383_b64f_3147fb6b5d4b]
                s32_t s32 = -32;
                CHECK(nkr::os::atomic::Exchange_Multiply(s32, 2) == -32);
                CHECK(nkr::os::atomic::Access(s32) == -64);
                /// [_dd7a4689_f747_4383_b64f_3147fb6b5d4b]
            }
            TEST_CASE("u64_t")
            {
            #if defined(nkr_IS_64_BIT)
                /// [_2f13adf0_8f79_4bab_bd15_e74b7c30d545]
                u64_t u64 = 64;
                CHECK(nkr::os::atomic::Exchange_Multiply(u64, 2) == 64);
                CHECK(nkr::os::atomic::Access(u64) == 128);
                /// [_2f13adf0_8f79_4bab_bd15_e74b7c30d545]
            #endif
            }
            TEST_CASE("s64_t")
            {
            #if defined(nkr_IS_64_BIT)
                /// [_e06eac77_d60d_4947_b1de_0f3a492a9177]
                s64_t s64 = -64;
                CHECK(nkr::os::atomic::Exchange_Multiply(s64, 2) == -64);
                CHECK(nkr::os::atomic::Access(s64) == -128);
                /// [_e06eac77_d60d_4947_b1de_0f3a492a9177]
            #endif
            }
            TEST_CASE("f32_t")
            {
                /// [_6a607416_5e12_4891_88cb_8b611edb025e]
                f32_t f32 = 3.2f;
                CHECK(nkr::os::atomic::Exchange_Multiply(f32, 0.1f) == 3.2f);
                CHECK(nkr::os::atomic::Access(f32) == 3.2f * 0.1f);
                /// [_6a607416_5e12_4891_88cb_8b611edb025e]
            }
            TEST_CASE("f64_t")
            {
            #if defined(nkr_IS_64_BIT)
                /// [_0293a39d_61b3_42d0_8505_de2a51a16610]
                f64_t f64 = 6.4;
                CHECK(nkr::os::atomic::Exchange_Multiply(f64, 0.1) == 6.4);
                CHECK(nkr::os::atomic::Access(f64) == 6.4 * 0.1);
                /// [_0293a39d_61b3_42d0_8505_de2a51a16610]
            #endif
            }
        }
    }

    TEST_SUITE("Exchange_Divide()")
    {
        TEST_SUITE("should divide its value with the operand and return the initial value")
        {
            TEST_CASE("u8_t")
            {
                /// [_086630af_beb2_4715_b450_62375ad55c20]
                u8_t u8 = 8;
                CHECK(nkr::os::atomic::Exchange_Divide(u8, 2) == 8);
                CHECK(nkr::os::atomic::Access(u8) == 4);
                /// [_086630af_beb2_4715_b450_62375ad55c20]
            }
            TEST_CASE("s8_t")
            {
                /// [_7011bbe9_f7d6_469c_ac39_9c6542ce687f]
                s8_t s8 = -8;
                CHECK(nkr::os::atomic::Exchange_Divide(s8, 2) == -8);
                CHECK(nkr::os::atomic::Access(s8) == -4);
                /// [_7011bbe9_f7d6_469c_ac39_9c6542ce687f]
            }
            TEST_CASE("u16_t")
            {
                /// [_10f93ea7_eb65_4ea0_9dfa_3dcf0ce90e57]
                u16_t u16 = 16;
                CHECK(nkr::os::atomic::Exchange_Divide(u16, 2) == 16);
                CHECK(nkr::os::atomic::Access(u16) == 8);
                /// [_10f93ea7_eb65_4ea0_9dfa_3dcf0ce90e57]
            }
            TEST_CASE("s16_t")
            {
                /// [_e9ee8377_56ee_437b_8a20_317198975130]
                s16_t s16 = -16;
                CHECK(nkr::os::atomic::Exchange_Divide(s16, 2) == -16);
                CHECK(nkr::os::atomic::Access(s16) == -8);
                /// [_e9ee8377_56ee_437b_8a20_317198975130]
            }
            TEST_CASE("u32_t")
            {
                /// [_a5b01859_e34b_4453_b4d4_d6ffb14f670f]
                u32_t u32 = 32;
                CHECK(nkr::os::atomic::Exchange_Divide(u32, 2) == 32);
                CHECK(nkr::os::atomic::Access(u32) == 16);
                /// [_a5b01859_e34b_4453_b4d4_d6ffb14f670f]
            }
            TEST_CASE("s32_t")
            {
                /// [_112b74c0_d2cf_41c8_a3ce_2c44e6d1ad3f]
                s32_t s32 = -32;
                CHECK(nkr::os::atomic::Exchange_Divide(s32, 2) == -32);
                CHECK(nkr::os::atomic::Access(s32) == -16);
                /// [_112b74c0_d2cf_41c8_a3ce_2c44e6d1ad3f]
            }
            TEST_CASE("u64_t")
            {
            #if defined(nkr_IS_64_BIT)
                /// [_651c6c3f_07ee_44f6_b231_a5820c06a213]
                u64_t u64 = 64;
                CHECK(nkr::os::atomic::Exchange_Divide(u64, 2) == 64);
                CHECK(nkr::os::atomic::Access(u64) == 32);
                /// [_651c6c3f_07ee_44f6_b231_a5820c06a213]
            #endif
            }
            TEST_CASE("s64_t")
            {
            #if defined(nkr_IS_64_BIT)
                /// [_e4ab402d_2c9e_4fff_99c2_9971b69dbc00]
                s64_t s64 = -64;
                CHECK(nkr::os::atomic::Exchange_Divide(s64, 2) == -64);
                CHECK(nkr::os::atomic::Access(s64) == -32);
                /// [_e4ab402d_2c9e_4fff_99c2_9971b69dbc00]
            #endif
            }
            TEST_CASE("f32_t")
            {
                /// [_5c93b156_7668_4fe7_be0b_a0d4600f0933]
                f32_t f32 = 3.2f;
                CHECK(nkr::os::atomic::Exchange_Divide(f32, 0.1f) == 3.2f);
                CHECK(nkr::os::atomic::Access(f32) == 3.2f / 0.1f);
                /// [_5c93b156_7668_4fe7_be0b_a0d4600f0933]
            }
            TEST_CASE("f64_t")
            {
            #if defined(nkr_IS_64_BIT)
                /// [_26028451_e507_4c96_8e49_e269edc87895]
                f64_t f64 = 6.4;
                CHECK(nkr::os::atomic::Exchange_Divide(f64, 0.1) == 6.4);
                CHECK(nkr::os::atomic::Access(f64) == 6.4 / 0.1);
                /// [_26028451_e507_4c96_8e49_e269edc87895]
            #endif
            }
        }
    }

    TEST_SUITE("Exchange_Modulus()")
    {
        TEST_SUITE("should mod its value with the operand and return the initial value")
        {
            TEST_CASE("u8_t")
            {
                /// [_74a97eb0_3db6_4588_a82b_0e0348363eb7]
                u8_t u8 = 8;
                CHECK(nkr::os::atomic::Exchange_Modulus(u8, 3) == 8);
                CHECK(nkr::os::atomic::Access(u8) == 2);
                /// [_74a97eb0_3db6_4588_a82b_0e0348363eb7]
            }
            TEST_CASE("s8_t")
            {
                /// [_16d52186_e3f0_4358_b1fb_37f56f5aad4f]
                s8_t s8 = -8;
                CHECK(nkr::os::atomic::Exchange_Modulus(s8, 3) == -8);
                CHECK(nkr::os::atomic::Access(s8) == -2);
                /// [_16d52186_e3f0_4358_b1fb_37f56f5aad4f]
            }
            TEST_CASE("u16_t")
            {
                /// [_a410f542_64c0_4b05_9fa4_869ff1e45e9e]
                u16_t u16 = 16;
                CHECK(nkr::os::atomic::Exchange_Modulus(u16, 3) == 16);
                CHECK(nkr::os::atomic::Access(u16) == 1);
                /// [_a410f542_64c0_4b05_9fa4_869ff1e45e9e]
            }
            TEST_CASE("s16_t")
            {
                /// [_ef494fef_b6fc_4118_a1bf_6fcfea5ef5dd]
                s16_t s16 = -16;
                CHECK(nkr::os::atomic::Exchange_Modulus(s16, 3) == -16);
                CHECK(nkr::os::atomic::Access(s16) == -1);
                /// [_ef494fef_b6fc_4118_a1bf_6fcfea5ef5dd]
            }
            TEST_CASE("u32_t")
            {
                /// [_4f53a2db_e75e_4801_8c34_c073b57ab42a]
                u32_t u32 = 32;
                CHECK(nkr::os::atomic::Exchange_Modulus(u32, 3) == 32);
                CHECK(nkr::os::atomic::Access(u32) == 2);
                /// [_4f53a2db_e75e_4801_8c34_c073b57ab42a]
            }
            TEST_CASE("s32_t")
            {
                /// [_00d5fef9_eedf_45f8_bd2a_653c3774aa03]
                s32_t s32 = -32;
                CHECK(nkr::os::atomic::Exchange_Modulus(s32, 3) == -32);
                CHECK(nkr::os::atomic::Access(s32) == -2);
                /// [_00d5fef9_eedf_45f8_bd2a_653c3774aa03]
            }
            TEST_CASE("u64_t")
            {
            #if defined(nkr_IS_64_BIT)
                /// [_dfd120c3_eb4e_4003_941c_038bde8a54b2]
                u64_t u64 = 64;
                CHECK(nkr::os::atomic::Exchange_Modulus(u64, 3) == 64);
                CHECK(nkr::os::atomic::Access(u64) == 1);
                /// [_dfd120c3_eb4e_4003_941c_038bde8a54b2]
            #endif
            }
            TEST_CASE("s64_t")
            {
            #if defined(nkr_IS_64_BIT)
                /// [_75c0b0b7_52af_4844_b584_f84f4b92bbb2]
                s64_t s64 = -64;
                CHECK(nkr::os::atomic::Exchange_Modulus(s64, 3) == -64);
                CHECK(nkr::os::atomic::Access(s64) == -1);
                /// [_75c0b0b7_52af_4844_b584_f84f4b92bbb2]
            #endif
            }
        }
    }

    TEST_SUITE("Exchange_Or")
    {
        TEST_SUITE("should atomically OR integers and return the initial value")
        {
            TEST_CASE("u8_t")
            {
                /// [_66aef5a6_f5e6_4083_8206_e7d11d8a70c4]
                u8_t u8 = 0x0F;
                CHECK(nkr::os::atomic::Exchange_Or(u8, 0xF0) == 0x0F);
                CHECK(nkr::os::atomic::Access(u8) == 0xFF);
                /// [_66aef5a6_f5e6_4083_8206_e7d11d8a70c4]
            }
            TEST_CASE("s8_t")
            {
                /// [_3ffc3377_7042_4ad7_b8fd_670f7a2222c1]
                s8_t s8 = 0x0F;
                CHECK(nkr::os::atomic::Exchange_Or(s8, 0x70) == 0x0F);
                CHECK(nkr::os::atomic::Access(s8) == 0x7F);
                /// [_3ffc3377_7042_4ad7_b8fd_670f7a2222c1]
            }
            TEST_CASE("u16_t")
            {
                /// [_a0873447_ed6d_48cb_be69_34f1ff6bfe29]
                u16_t u16 = 0x00FF;
                CHECK(nkr::os::atomic::Exchange_Or(u16, 0xFF00) == 0x00FF);
                CHECK(nkr::os::atomic::Access(u16) == 0xFFFF);
                /// [_a0873447_ed6d_48cb_be69_34f1ff6bfe29]
            }
            TEST_CASE("s16_t")
            {
                /// [_f9686492_24f7_4a1a_b9ee_4a3d11ef0968]
                s16_t s16 = 0x00FF;
                CHECK(nkr::os::atomic::Exchange_Or(s16, 0x7F00) == 0x00FF);
                CHECK(nkr::os::atomic::Access(s16) == 0x7FFF);
                /// [_f9686492_24f7_4a1a_b9ee_4a3d11ef0968]
            }
            TEST_CASE("u32_t")
            {
                /// [_d9af0eb8_f744_4bda_ad81_00370e1b061d]
                u32_t u32 = 0x0000FFFF;
                CHECK(nkr::os::atomic::Exchange_Or(u32, 0xFFFF0000) == 0x0000FFFF);
                CHECK(nkr::os::atomic::Access(u32) == 0xFFFFFFFF);
                /// [_d9af0eb8_f744_4bda_ad81_00370e1b061d]
            }
            TEST_CASE("s32_t")
            {
                /// [_6f5e84bb_9a95_4bac_84d7_7ffea4cf7099]
                s32_t s32 = 0x0000FFFF;
                CHECK(nkr::os::atomic::Exchange_Or(s32, 0x7FFF0000) == 0x0000FFFF);
                CHECK(nkr::os::atomic::Access(s32) == 0x7FFFFFFF);
                /// [_6f5e84bb_9a95_4bac_84d7_7ffea4cf7099]
            }
            TEST_CASE("u64_t")
            {
            #if defined(nkr_IS_64_BIT)
                /// [_ea1353e4_cea9_49d2_b6a0_2eb2f8980ca5]
                u64_t u64 = 0x00000000FFFFFFFF;
                CHECK(nkr::os::atomic::Exchange_Or(u64, 0xFFFFFFFF00000000) == 0x00000000FFFFFFFF);
                CHECK(nkr::os::atomic::Access(u64) == 0xFFFFFFFFFFFFFFFF);
                /// [_ea1353e4_cea9_49d2_b6a0_2eb2f8980ca5]
            #endif
            }
            TEST_CASE("s64_t")
            {
            #if defined(nkr_IS_64_BIT)
                /// [_ae831b2d_accd_4d93_a6ed_89587397f04f]
                s64_t s64 = 0x00000000FFFFFFFF;
                CHECK(nkr::os::atomic::Exchange_Or(s64, 0x7FFFFFFF00000000) == 0x00000000FFFFFFFF);
                CHECK(nkr::os::atomic::Access(s64) == 0x7FFFFFFFFFFFFFFF);
                /// [_ae831b2d_accd_4d93_a6ed_89587397f04f]
            #endif
            }
        }
    }

    TEST_SUITE("Exchange_And")
    {
        TEST_SUITE("should atomically AND integers and return the initial value")
        {
            TEST_CASE("u8_t")
            {
                /// [_28d42020_0adf_4b0c_a7b5_d3f80a8d9e67]
                u8_t u8 = 0x0F;
                CHECK(nkr::os::atomic::Exchange_And(u8, 0xF0) == 0x0F);
                CHECK(nkr::os::atomic::Access(u8) == 0x0);
                /// [_28d42020_0adf_4b0c_a7b5_d3f80a8d9e67]
            }
            TEST_CASE("s8_t")
            {
                /// [_691bc500_ab39_414e_a249_e52621ef48f3]
                s8_t s8 = 0x0F;
                CHECK(nkr::os::atomic::Exchange_And(s8, 0x70) == 0x0F);
                CHECK(nkr::os::atomic::Access(s8) == 0x0);
                /// [_691bc500_ab39_414e_a249_e52621ef48f3]
            }
            TEST_CASE("u16_t")
            {
                /// [_4e1053fa_d240_4949_b99c_ca16e9f26205]
                u16_t u16 = 0x00FF;
                CHECK(nkr::os::atomic::Exchange_And(u16, 0xFF00) == 0x00FF);
                CHECK(nkr::os::atomic::Access(u16) == 0x0);
                /// [_4e1053fa_d240_4949_b99c_ca16e9f26205]
            }
            TEST_CASE("s16_t")
            {
                /// [_2a6631f2_5b71_471a_afb8_33734c0b6f8f]
                s16_t s16 = 0x00FF;
                CHECK(nkr::os::atomic::Exchange_And(s16, 0x7F00) == 0x00FF);
                CHECK(nkr::os::atomic::Access(s16) == 0x0);
                /// [_2a6631f2_5b71_471a_afb8_33734c0b6f8f]
            }
            TEST_CASE("u32_t")
            {
                /// [_90a104bf_b73e_418d_917f_3fa41344c1ff]
                u32_t u32 = 0x0000FFFF;
                CHECK(nkr::os::atomic::Exchange_And(u32, 0xFFFF0000) == 0x0000FFFF);
                CHECK(nkr::os::atomic::Access(u32) == 0x0);
                /// [_90a104bf_b73e_418d_917f_3fa41344c1ff]
            }
            TEST_CASE("s32_t")
            {
                /// [_4218b236_9ffe_45a6_9c67_66697e64fc0a]
                s32_t s32 = 0x0000FFFF;
                CHECK(nkr::os::atomic::Exchange_And(s32, 0x7FFF0000) == 0x0000FFFF);
                CHECK(nkr::os::atomic::Access(s32) == 0x0);
                /// [_4218b236_9ffe_45a6_9c67_66697e64fc0a]
            }
            TEST_CASE("u64_t")
            {
            #if defined(nkr_IS_64_BIT)
                /// [_78421883_c7d1_42fb_a27c_b596566e1aa9]
                u64_t u64 = 0x00000000FFFFFFFF;
                CHECK(nkr::os::atomic::Exchange_And(u64, 0xFFFFFFFF00000000) == 0x00000000FFFFFFFF);
                CHECK(nkr::os::atomic::Access(u64) == 0x0);
                /// [_78421883_c7d1_42fb_a27c_b596566e1aa9]
            #endif
            }
            TEST_CASE("s64_t")
            {
            #if defined(nkr_IS_64_BIT)
                /// [_cddbfeca_f6ba_4767_b23d_2eba37c0ff54]
                s64_t s64 = 0x00000000FFFFFFFF;
                CHECK(nkr::os::atomic::Exchange_And(s64, 0x7FFFFFFF00000000) == 0x00000000FFFFFFFF);
                CHECK(nkr::os::atomic::Access(s64) == 0x0);
                /// [_cddbfeca_f6ba_4767_b23d_2eba37c0ff54]
            #endif
            }
        }
    }

    TEST_SUITE("Exchange_Xor")
    {
        TEST_SUITE("should atomically XOR integers and return the initial value")
        {
            TEST_CASE("u8_t")
            {
                /// [_e861defb_5da2_4010_9b16_07d9f4d8a61b]
                u8_t u8 = 0xFF;
                CHECK(nkr::os::atomic::Exchange_Xor(u8, 0x01) == 0xFF);
                CHECK(nkr::os::atomic::Access(u8) == 0xFE);
                /// [_e861defb_5da2_4010_9b16_07d9f4d8a61b]
            }
            TEST_CASE("s8_t")
            {
                /// [_b37ffc08_5d33_4b2a_8e5f_3d9f9777b2c7]
                s8_t s8 = 0x7F;
                CHECK(nkr::os::atomic::Exchange_Xor(s8, 0x01) == 0x7F);
                CHECK(nkr::os::atomic::Access(s8) == 0x7E);
                /// [_b37ffc08_5d33_4b2a_8e5f_3d9f9777b2c7]
            }
            TEST_CASE("u16_t")
            {
                /// [_e3f851b5_2eb2_4f74_989d_50befdd9d328]
                u16_t u16 = 0xFFFF;
                CHECK(nkr::os::atomic::Exchange_Xor(u16, 0x0001) == 0xFFFF);
                CHECK(nkr::os::atomic::Access(u16) == 0xFFFE);
                /// [_e3f851b5_2eb2_4f74_989d_50befdd9d328]
            }
            TEST_CASE("s16_t")
            {
                /// [_aa6eed46_ee66_4512_ae86_5608ed651e67]
                s16_t s16 = 0x7FFF;
                CHECK(nkr::os::atomic::Exchange_Xor(s16, 0x0001) == 0x7FFF);
                CHECK(nkr::os::atomic::Access(s16) == 0x7FFE);
                /// [_aa6eed46_ee66_4512_ae86_5608ed651e67]
            }
            TEST_CASE("u32_t")
            {
                /// [_d64496f5_4e49_4a59_819d_f683e46c735b]
                u32_t u32 = 0xFFFFFFFF;
                CHECK(nkr::os::atomic::Exchange_Xor(u32, 0x00000001) == 0xFFFFFFFF);
                CHECK(nkr::os::atomic::Access(u32) == 0xFFFFFFFE);
                /// [_d64496f5_4e49_4a59_819d_f683e46c735b]
            }
            TEST_CASE("s32_t")
            {
                /// [_4f8deefd_b3cd_4bb6_9663_e0f3c58a65b7]
                s32_t s32 = 0x7FFFFFFF;
                CHECK(nkr::os::atomic::Exchange_Xor(s32, 0x00000001) == 0x7FFFFFFF);
                CHECK(nkr::os::atomic::Access(s32) == 0x7FFFFFFE);
                /// [_4f8deefd_b3cd_4bb6_9663_e0f3c58a65b7]
            }
            TEST_CASE("u64_t")
            {
            #if defined(nkr_IS_64_BIT)
                /// [_5100f20e_6424_4cde_9eda_e3bd10806afc]
                u64_t u64 = 0xFFFFFFFFFFFFFFFF;
                CHECK(nkr::os::atomic::Exchange_Xor(u64, 0x0000000000000001) == 0xFFFFFFFFFFFFFFFF);
                CHECK(nkr::os::atomic::Access(u64) == 0xFFFFFFFFFFFFFFFE);
                /// [_5100f20e_6424_4cde_9eda_e3bd10806afc]
            #endif
            }
            TEST_CASE("s64_t")
            {
            #if defined(nkr_IS_64_BIT)
                /// [_10dde961_946a_4e8d_bd1a_443efa243d78]
                s64_t s64 = 0x7FFFFFFFFFFFFFFF;
                CHECK(nkr::os::atomic::Exchange_Xor(s64, 0x0000000000000001) == 0x7FFFFFFFFFFFFFFF);
                CHECK(nkr::os::atomic::Access(s64) == 0x7FFFFFFFFFFFFFFE);
                /// [_10dde961_946a_4e8d_bd1a_443efa243d78]
            #endif
            }
        }
    }

    TEST_SUITE("Exchange_Left_Shift()")
    {
        TEST_SUITE("should <<= the operand and return its previous value")
        {
            TEST_CASE("u8_t")
            {
                /// [_16bb22e1_6a89_42ab_95a1_f0a36ffc639c]
                u8_t u8 = 0x0F;
                CHECK(nkr::os::atomic::Exchange_Left_Shift(u8, 4) == 0x0F);
                CHECK(nkr::os::atomic::Access(u8) == 0xF0);
                /// [_16bb22e1_6a89_42ab_95a1_f0a36ffc639c]
            }
            TEST_CASE("s8_t")
            {
                /// [_e60d11c8_7e9d_456f_aea9_a5113bdab34f]
                s8_t s8 = 0x07;
                CHECK(nkr::os::atomic::Exchange_Left_Shift(s8, 4) == 0x07);
                CHECK(nkr::os::atomic::Access(s8) == 0x70);
                /// [_e60d11c8_7e9d_456f_aea9_a5113bdab34f]
            }
            TEST_CASE("u16_t")
            {
                /// [_be7fa2c8_dbb2_48d3_b44d_646f0bb2c936]
                u16_t u16 = 0x00FF;
                CHECK(nkr::os::atomic::Exchange_Left_Shift(u16, 8) == 0x00FF);
                CHECK(nkr::os::atomic::Access(u16) == 0xFF00);
                /// [_be7fa2c8_dbb2_48d3_b44d_646f0bb2c936]
            }
            TEST_CASE("s16_t")
            {
                /// [_74199800_357d_4c25_a54c_7f39623694c9]
                s16_t s16 = 0x007F;
                CHECK(nkr::os::atomic::Exchange_Left_Shift(s16, 8) == 0x007F);
                CHECK(nkr::os::atomic::Access(s16) == 0x7F00);
                /// [_74199800_357d_4c25_a54c_7f39623694c9]
            }
            TEST_CASE("u32_t")
            {
                /// [_76ac7ea6_24cd_4fc1_a7d4_c3bffd9cb098]
                u32_t u32 = 0x0000FFFF;
                CHECK(nkr::os::atomic::Exchange_Left_Shift(u32, 16) == 0x0000FFFF);
                CHECK(nkr::os::atomic::Access(u32) == 0xFFFF0000);
                /// [_76ac7ea6_24cd_4fc1_a7d4_c3bffd9cb098]
            }
            TEST_CASE("s32_t")
            {
                /// [_081d235f_78f5_48dd_af1e_5a32ff495969]
                s32_t s32 = 0x00007FFF;
                CHECK(nkr::os::atomic::Exchange_Left_Shift(s32, 16) == 0x00007FFF);
                CHECK(nkr::os::atomic::Access(s32) == 0x7FFF0000);
                /// [_081d235f_78f5_48dd_af1e_5a32ff495969]
            }
            TEST_CASE("u64_t")
            {
            #if defined(nkr_IS_64_BIT)
                /// [_1b149791_cfde_4397_ab31_5629cd034367]
                u64_t u64 = 0x00000000FFFFFFFF;
                CHECK(nkr::os::atomic::Exchange_Left_Shift(u64, 32) == 0x00000000FFFFFFFF);
                CHECK(nkr::os::atomic::Access(u64) == 0xFFFFFFFF00000000);
                /// [_1b149791_cfde_4397_ab31_5629cd034367]
            #endif
            }
            TEST_CASE("s64_t")
            {
            #if defined(nkr_IS_64_BIT)
                /// [_80b40cd3_5820_4fc9_81b0_66b266db6c57]
                s64_t s64 = 0x000000007FFFFFFF;
                CHECK(nkr::os::atomic::Exchange_Left_Shift(s64, 32) == 0x000000007FFFFFFF);
                CHECK(nkr::os::atomic::Access(s64) == 0x7FFFFFFF00000000);
                /// [_80b40cd3_5820_4fc9_81b0_66b266db6c57]
            #endif
            }
        }
    }

    TEST_SUITE("Exchange_Right_Shift()")
    {
        TEST_SUITE("should >>= the operand and return its previous value")
        {
            TEST_CASE("u8_t")
            {
                /// [_ea66a1d1_9a54_446c_8f60_890e419c5d61]
                u8_t u8 = 0xF0;
                CHECK(nkr::os::atomic::Exchange_Right_Shift(u8, 4) == 0xF0);
                CHECK(nkr::os::atomic::Access(u8) == 0x0F);
                /// [_ea66a1d1_9a54_446c_8f60_890e419c5d61]
            }
            TEST_CASE("s8_t")
            {
                /// [_e7fd5f43_7e9d_491a_a1a3_cb982c04f72a]
                s8_t s8 = 0x70;
                CHECK(nkr::os::atomic::Exchange_Right_Shift(s8, 4) == 0x70);
                CHECK(nkr::os::atomic::Access(s8) == 0x07);
                /// [_e7fd5f43_7e9d_491a_a1a3_cb982c04f72a]
            }
            TEST_CASE("u16_t")
            {
                /// [_74a06a93_87f7_4cb6_9094_e53acdc96204]
                u16_t u16 = 0xFF00;
                CHECK(nkr::os::atomic::Exchange_Right_Shift(u16, 8) == 0xFF00);
                CHECK(nkr::os::atomic::Access(u16) == 0x00FF);
                /// [_74a06a93_87f7_4cb6_9094_e53acdc96204]
            }
            TEST_CASE("s16_t")
            {
                /// [_e3709987_c00e_4169_98bc_ba7182845767]
                s16_t s16 = 0x7F00;
                CHECK(nkr::os::atomic::Exchange_Right_Shift(s16, 8) == 0x7F00);
                CHECK(nkr::os::atomic::Access(s16) == 0x007F);
                /// [_e3709987_c00e_4169_98bc_ba7182845767]
            }
            TEST_CASE("u32_t")
            {
                /// [_14c24569_8bdd_478b_b347_a6c80d9f18cf]
                u32_t u32 = 0xFFFF0000;
                CHECK(nkr::os::atomic::Exchange_Right_Shift(u32, 16) == 0xFFFF0000);
                CHECK(nkr::os::atomic::Access(u32) == 0x0000FFFF);
                /// [_14c24569_8bdd_478b_b347_a6c80d9f18cf]
            }
            TEST_CASE("s32_t")
            {
                /// [_2630bda0_f86d_45f6_a2b4_15e1e4437fb5]
                s32_t s32 = 0x7FFF0000;
                CHECK(nkr::os::atomic::Exchange_Right_Shift(s32, 16) == 0x7FFF0000);
                CHECK(nkr::os::atomic::Access(s32) == 0x00007FFF);
                /// [_2630bda0_f86d_45f6_a2b4_15e1e4437fb5]
            }
            TEST_CASE("u64_t")
            {
            #if defined(nkr_IS_64_BIT)
                /// [_ccf5ce13_58b6_4b08_8b4a_c3af8c5a8e3c]
                u64_t u64 = 0xFFFFFFFF00000000;
                CHECK(nkr::os::atomic::Exchange_Right_Shift(u64, 32) == 0xFFFFFFFF00000000);
                CHECK(nkr::os::atomic::Access(u64) == 0x00000000FFFFFFFF);
                /// [_ccf5ce13_58b6_4b08_8b4a_c3af8c5a8e3c]
            #endif
            }
            TEST_CASE("s64_t")
            {
            #if defined(nkr_IS_64_BIT)
                /// [_cdb2ff5c_2ed3_48bb_b844_8b017ac501a2]
                s64_t s64 = 0x7FFFFFFF00000000;
                CHECK(nkr::os::atomic::Exchange_Right_Shift(s64, 32) == 0x7FFFFFFF00000000);
                CHECK(nkr::os::atomic::Access(s64) == 0x000000007FFFFFFF);
                /// [_cdb2ff5c_2ed3_48bb_b844_8b017ac501a2]
            #endif
            }
        }
    }

    TEST_SUITE("Exchange_If_Equals")
    {
        TEST_SUITE("should set value if the current value matches the snapshot, returning true, else updates snapshot and returns false")
        {
            TEST_CASE("bool_t")
            {
                /// [_23825beb_911e_45fa_84f9_9a45cdea3886]
                bool_t boolean = true;
                bool_t snapshot = false;

                CHECK(nkr::os::atomic::Exchange_If_Equals(boolean, snapshot, false) == false);
                CHECK(nkr::os::atomic::Access(boolean) == true);
                CHECK(snapshot == true);

                CHECK(nkr::os::atomic::Exchange_If_Equals(boolean, snapshot, false) == true);
                CHECK(nkr::os::atomic::Access(boolean) == false);
                CHECK(snapshot == true);

                snapshot = nkr::os::atomic::Access(boolean);
                while (!nkr::os::atomic::Exchange_If_Equals(boolean, snapshot, !snapshot));
                CHECK(nkr::os::atomic::Access(boolean) == true);
                CHECK(snapshot == false);
                /// [_23825beb_911e_45fa_84f9_9a45cdea3886]
            }
            TEST_CASE("std_bool_t")
            {
                /// [_93f61882_adbb_4dab_b3ac_bf58f659cf6b]
                std_bool_t boolean = true;
                std_bool_t snapshot = false;

                CHECK(nkr::os::atomic::Exchange_If_Equals(boolean, snapshot, false) == false);
                CHECK(nkr::os::atomic::Access(boolean) == true);
                CHECK(snapshot == true);

                CHECK(nkr::os::atomic::Exchange_If_Equals(boolean, snapshot, false) == true);
                CHECK(nkr::os::atomic::Access(boolean) == false);
                CHECK(snapshot == true);

                snapshot = nkr::os::atomic::Access(boolean);
                while (!nkr::os::atomic::Exchange_If_Equals(boolean, snapshot, !snapshot));
                CHECK(nkr::os::atomic::Access(boolean) == true);
                CHECK(snapshot == false);
                /// [_93f61882_adbb_4dab_b3ac_bf58f659cf6b]
            }
            TEST_CASE("u8_t")
            {
                /// [_399e6626_cc7e_4b56_9e82_5bc1129a55c0]
                u8_t u8 = 8;
                u8_t snapshot = 0;

                CHECK(nkr::os::atomic::Exchange_If_Equals(u8, snapshot, 0) == false);
                CHECK(nkr::os::atomic::Access(u8) == 8);
                CHECK(snapshot == 8);

                CHECK(nkr::os::atomic::Exchange_If_Equals(u8, snapshot, 0) == true);
                CHECK(nkr::os::atomic::Access(u8) == 0);
                CHECK(snapshot == 8);

                snapshot = nkr::os::atomic::Access(u8);
                while (!nkr::os::atomic::Exchange_If_Equals(u8, snapshot, snapshot + 8));
                CHECK(nkr::os::atomic::Access(u8) == 8);
                CHECK(snapshot == 0);
                /// [_399e6626_cc7e_4b56_9e82_5bc1129a55c0]
            }
            TEST_CASE("s8_t")
            {
                /// [_85c66fbc_ea73_4038_9da9_f4feabe6647e]
                s8_t s8 = -8;
                s8_t snapshot = 0;

                CHECK(nkr::os::atomic::Exchange_If_Equals(s8, snapshot, 0) == false);
                CHECK(nkr::os::atomic::Access(s8) == -8);
                CHECK(snapshot == -8);

                CHECK(nkr::os::atomic::Exchange_If_Equals(s8, snapshot, 0) == true);
                CHECK(nkr::os::atomic::Access(s8) == 0);
                CHECK(snapshot == -8);

                snapshot = nkr::os::atomic::Access(s8);
                while (!nkr::os::atomic::Exchange_If_Equals(s8, snapshot, snapshot + -8));
                CHECK(nkr::os::atomic::Access(s8) == -8);
                CHECK(snapshot == 0);
                /// [_85c66fbc_ea73_4038_9da9_f4feabe6647e]
            }
            TEST_CASE("u16_t")
            {
                /// [_80570e89_2b9a_4d22_a58a_c8fee4c6cfee]
                u16_t u16 = 16;
                u16_t snapshot = 0;

                CHECK(nkr::os::atomic::Exchange_If_Equals(u16, snapshot, 0) == false);
                CHECK(nkr::os::atomic::Access(u16) == 16);
                CHECK(snapshot == 16);

                CHECK(nkr::os::atomic::Exchange_If_Equals(u16, snapshot, 0) == true);
                CHECK(nkr::os::atomic::Access(u16) == 0);
                CHECK(snapshot == 16);

                snapshot = nkr::os::atomic::Access(u16);
                while (!nkr::os::atomic::Exchange_If_Equals(u16, snapshot, snapshot + 16));
                CHECK(nkr::os::atomic::Access(u16) == 16);
                CHECK(snapshot == 0);
                /// [_80570e89_2b9a_4d22_a58a_c8fee4c6cfee]
            }
            TEST_CASE("s16_t")
            {
                /// [_ff7b26a3_c10c_4325_a6a1_19cdd09c039a]
                s16_t s16 = -16;
                s16_t snapshot = 0;

                CHECK(nkr::os::atomic::Exchange_If_Equals(s16, snapshot, 0) == false);
                CHECK(nkr::os::atomic::Access(s16) == -16);
                CHECK(snapshot == -16);

                CHECK(nkr::os::atomic::Exchange_If_Equals(s16, snapshot, 0) == true);
                CHECK(nkr::os::atomic::Access(s16) == 0);
                CHECK(snapshot == -16);

                snapshot = nkr::os::atomic::Access(s16);
                while (!nkr::os::atomic::Exchange_If_Equals(s16, snapshot, snapshot + -16));
                CHECK(nkr::os::atomic::Access(s16) == -16);
                CHECK(snapshot == 0);
                /// [_ff7b26a3_c10c_4325_a6a1_19cdd09c039a]
            }
            TEST_CASE("u32_t")
            {
                /// [_7b4b030c_3c96_4b00_9065_36aedf0b4eee]
                u32_t u32 = 32;
                u32_t snapshot = 0;

                CHECK(nkr::os::atomic::Exchange_If_Equals(u32, snapshot, 0) == false);
                CHECK(nkr::os::atomic::Access(u32) == 32);
                CHECK(snapshot == 32);

                CHECK(nkr::os::atomic::Exchange_If_Equals(u32, snapshot, 0) == true);
                CHECK(nkr::os::atomic::Access(u32) == 0);
                CHECK(snapshot == 32);

                snapshot = nkr::os::atomic::Access(u32);
                while (!nkr::os::atomic::Exchange_If_Equals(u32, snapshot, snapshot + 32));
                CHECK(nkr::os::atomic::Access(u32) == 32);
                CHECK(snapshot == 0);
                /// [_7b4b030c_3c96_4b00_9065_36aedf0b4eee]
            }
            TEST_CASE("s32_t")
            {
                /// [_1efa26a1_be41_4cac_8570_5b3ec4751334]
                s32_t s32 = -32;
                s32_t snapshot = 0;

                CHECK(nkr::os::atomic::Exchange_If_Equals(s32, snapshot, 0) == false);
                CHECK(nkr::os::atomic::Access(s32) == -32);
                CHECK(snapshot == -32);

                CHECK(nkr::os::atomic::Exchange_If_Equals(s32, snapshot, 0) == true);
                CHECK(nkr::os::atomic::Access(s32) == 0);
                CHECK(snapshot == -32);

                snapshot = nkr::os::atomic::Access(s32);
                while (!nkr::os::atomic::Exchange_If_Equals(s32, snapshot, snapshot + -32));
                CHECK(nkr::os::atomic::Access(s32) == -32);
                CHECK(snapshot == 0);
                /// [_1efa26a1_be41_4cac_8570_5b3ec4751334]
            }
            TEST_CASE("u64_t")
            {
            #if defined(nkr_IS_64_BIT)
                /// [_8871fc7e_cdc5_40f5_934f_7df0b27067fd]
                u64_t u64 = 64;
                u64_t snapshot = 0;

                CHECK(nkr::os::atomic::Exchange_If_Equals(u64, snapshot, 0) == false);
                CHECK(nkr::os::atomic::Access(u64) == 64);
                CHECK(snapshot == 64);

                CHECK(nkr::os::atomic::Exchange_If_Equals(u64, snapshot, 0) == true);
                CHECK(nkr::os::atomic::Access(u64) == 0);
                CHECK(snapshot == 64);

                snapshot = nkr::os::atomic::Access(u64);
                while (!nkr::os::atomic::Exchange_If_Equals(u64, snapshot, snapshot + 64));
                CHECK(nkr::os::atomic::Access(u64) == 64);
                CHECK(snapshot == 0);
                /// [_8871fc7e_cdc5_40f5_934f_7df0b27067fd]
            #endif
            }
            TEST_CASE("s64_t")
            {
            #if defined(nkr_IS_64_BIT)
                /// [_d274b52b_2baf_4b2c_aa4c_c7a63201d1c8]
                s64_t s64 = -64;
                s64_t snapshot = 0;

                CHECK(nkr::os::atomic::Exchange_If_Equals(s64, snapshot, 0) == false);
                CHECK(nkr::os::atomic::Access(s64) == -64);
                CHECK(snapshot == -64);

                CHECK(nkr::os::atomic::Exchange_If_Equals(s64, snapshot, 0) == true);
                CHECK(nkr::os::atomic::Access(s64) == 0);
                CHECK(snapshot == -64);

                snapshot = nkr::os::atomic::Access(s64);
                while (!nkr::os::atomic::Exchange_If_Equals(s64, snapshot, snapshot + -64));
                CHECK(nkr::os::atomic::Access(s64) == -64);
                CHECK(snapshot == 0);
                /// [_d274b52b_2baf_4b2c_aa4c_c7a63201d1c8]
            #endif
            }
            TEST_CASE("f32_t")
            {
                /// [_053a47aa_c48a_4777_967f_a06cd12d1926]
                f32_t f32 = 3.2f;
                f32_t snapshot = 0.0f;

                CHECK(nkr::os::atomic::Exchange_If_Equals(f32, snapshot, 0.0f) == false);
                CHECK(nkr::os::atomic::Access(f32) == 3.2f);
                CHECK(snapshot == 3.2f);

                CHECK(nkr::os::atomic::Exchange_If_Equals(f32, snapshot, 0.0f) == true);
                CHECK(nkr::os::atomic::Access(f32) == 0.0f);
                CHECK(snapshot == 3.2f);

                snapshot = nkr::os::atomic::Access(f32);
                while (!nkr::os::atomic::Exchange_If_Equals(f32, snapshot, snapshot + 3.2f));
                CHECK(nkr::os::atomic::Access(f32) == 3.2f);
                CHECK(snapshot == 0);
                /// [_053a47aa_c48a_4777_967f_a06cd12d1926]
            }
            TEST_CASE("f64_t")
            {
            #if defined(nkr_IS_64_BIT)
                /// [_7903378e_2ad0_43a7_a3aa_b515e179137a]
                f64_t f64 = 6.4;
                f64_t snapshot = 0.0;

                CHECK(nkr::os::atomic::Exchange_If_Equals(f64, snapshot, 0.0) == false);
                CHECK(nkr::os::atomic::Access(f64) == 6.4);
                CHECK(snapshot == 6.4);

                CHECK(nkr::os::atomic::Exchange_If_Equals(f64, snapshot, 0.0) == true);
                CHECK(nkr::os::atomic::Access(f64) == 0.0);
                CHECK(snapshot == 6.4);

                snapshot = nkr::os::atomic::Access(f64);
                while (!nkr::os::atomic::Exchange_If_Equals(f64, snapshot, snapshot + 6.4));
                CHECK(nkr::os::atomic::Access(f64) == 6.4);
                CHECK(snapshot == 0);
                /// [_7903378e_2ad0_43a7_a3aa_b515e179137a]
            #endif
            }
            TEST_CASE("void_t*")
            {
                /// [_ecd1c05f_bcb2_4c47_b920_7c64fb0baabc]
                bool_t boolean;
                void_t* void_pointer = &boolean;
                void_t* snapshot = nullptr;

                CHECK(nkr::os::atomic::Exchange_If_Equals(void_pointer, snapshot, nullptr) == false);
                CHECK(nkr::os::atomic::Access(void_pointer) == &boolean);
                CHECK(snapshot == &boolean);

                CHECK(nkr::os::atomic::Exchange_If_Equals(void_pointer, snapshot, nullptr) == true);
                CHECK(nkr::os::atomic::Access(void_pointer) == nullptr);
                CHECK(snapshot == &boolean);

                snapshot = nkr::os::atomic::Access(void_pointer);
                while (!nkr::os::atomic::Exchange_If_Equals(void_pointer, snapshot, &boolean));
                CHECK(nkr::os::atomic::Access(void_pointer) == &boolean);
                CHECK(snapshot == nullptr);
                /// [_ecd1c05f_bcb2_4c47_b920_7c64fb0baabc]
            }
            TEST_CASE("bool_t*")
            {
                /// [_4c0b3876_9c0a_40d4_b960_862bb86b0be1]
                bool_t boolean;
                bool_t* boolean_pointer = &boolean;
                bool_t* snapshot = nullptr;

                CHECK(nkr::os::atomic::Exchange_If_Equals(boolean_pointer, snapshot, nullptr) == false);
                CHECK(nkr::os::atomic::Access(boolean_pointer) == &boolean);
                CHECK(snapshot == &boolean);

                CHECK(nkr::os::atomic::Exchange_If_Equals(boolean_pointer, snapshot, nullptr) == true);
                CHECK(nkr::os::atomic::Access(boolean_pointer) == nullptr);
                CHECK(snapshot == &boolean);

                snapshot = nkr::os::atomic::Access(boolean_pointer);
                while (!nkr::os::atomic::Exchange_If_Equals(boolean_pointer, snapshot, &boolean));
                CHECK(nkr::os::atomic::Access(boolean_pointer) == &boolean);
                CHECK(snapshot == nullptr);
                /// [_4c0b3876_9c0a_40d4_b960_862bb86b0be1]
            }
        }
    }

}}}

namespace nkr { namespace os { namespace endian {

    TEST_SUITE("Is_Big")
    {
        TEST_CASE("should in a thread-safe manner efficiently determine if the runtime is in big endian"
                  * doctest::may_fail(true)
                  * doctest::no_breaks(true))
        {
            /// [_2367da3d_58c3_4a8f_98c4_c9d8c809cb25]
        #if defined(nkr_IS_WINDOWS)
            CHECK(nkr::os::endian::Is_Big() == false);
        #else
            CHECK(nkr::os::endian::Is_Big() == true);
        #endif
            /// [_2367da3d_58c3_4a8f_98c4_c9d8c809cb25]
        }
    }

    TEST_SUITE("Is_Little")
    {
        TEST_CASE("should in a thread-safe manner efficiently determine if the runtime is in little endian"
                  * doctest::may_fail(true)
                  * doctest::no_breaks(true))
        {
            /// [_e5a7621e_6b04_42ef_b8d2_94d576abb57e]
        #if defined(nkr_IS_WINDOWS)
            CHECK(nkr::os::endian::Is_Little() == true);
        #else
            CHECK(nkr::os::endian::Is_Little() == false);
        #endif
            /// [_e5a7621e_6b04_42ef_b8d2_94d576abb57e]
        }
    }

    TEST_SUITE("Swap")
    {
        TEST_SUITE("should swap the bytes of 16 bit, 32 bit, and 64 bit numbers")
        {
            TEST_CASE("s32_t literal")
            {
                /// [_8204605f_3b41_4633_8865_89d336420022]
                CHECK(nkr::os::endian::Swap(0x0102) != 0x0201);
                CHECK(nkr::os::endian::Swap(0x0102) == 0x02010000);
                CHECK(nkr::os::endian::Swap(static_cast<u16_t>(0x0102)) == 0x0201);

                CHECK(nkr::os::endian::Swap(0x01020304) == 0x04030201);
                CHECK(nkr::os::endian::Swap(0x0102030405060708) == 0x0807060504030201);
                /// [_8204605f_3b41_4633_8865_89d336420022]
            }
            TEST_CASE("u16_t")
            {
                /// [_6bc67519_2af0_4999_a15c_ad085acb68e4]
                u16_t u16 = 0x0102;
                CHECK(nkr::os::endian::Swap(u16) == 0x0201);
                /// [_6bc67519_2af0_4999_a15c_ad085acb68e4]
            }
            TEST_CASE("s16_t")
            {
                /// [_962de4de_8f29_4f35_9ffb_123ac19b3cf8]
                s16_t s16 = 0x0102;
                CHECK(nkr::os::endian::Swap(s16) == 0x0201);
                /// [_962de4de_8f29_4f35_9ffb_123ac19b3cf8]
            }
            TEST_CASE("u32_t")
            {
                /// [_d480540a_cabf_45d6_b3dc_0882dca2569b]
                u32_t u32 = 0x01020304;
                CHECK(nkr::os::endian::Swap(u32) == 0x04030201);
                /// [_d480540a_cabf_45d6_b3dc_0882dca2569b]
            }
            TEST_CASE("s32_t")
            {
                /// [_59caf647_91bb_4926_b0d0_401183e97ded]
                s32_t s32 = 0x01020304;
                CHECK(nkr::os::endian::Swap(s32) == 0x04030201);
                /// [_59caf647_91bb_4926_b0d0_401183e97ded]
            }
            TEST_CASE("u64_t")
            {
                /// [_52a0d032_dab3_4a2e_a06a_67bc56f297f4]
                u64_t u64 = 0x0102030405060708;
                CHECK(nkr::os::endian::Swap(u64) == 0x0807060504030201);
                /// [_52a0d032_dab3_4a2e_a06a_67bc56f297f4]
            }
            TEST_CASE("s64_t")
            {
                /// [_70f7b676_8069_4eec_93bf_007c172f1e39]
                s64_t s64 = 0x0102030405060708;
                CHECK(nkr::os::endian::Swap(s64) == 0x0807060504030201);
                /// [_70f7b676_8069_4eec_93bf_007c172f1e39]
            }
        }
    }

}}}

namespace nkr { namespace os { namespace heap {

    TEST_SUITE("Allocate")
    {
        TEST_CASE("should allocate heap memory, set pointer, and return true, or set nullptr and return false")
        {
            /// [_a06ecc73_e7ac_43b2_b231_059675458c15]
            word_t* words = nullptr;
            CHECK(os::heap::Allocate(words, 0xFF));
            CHECK(words != nullptr);

            word_t* too_many = nullptr;
            CHECK(os::heap::Allocate(too_many, std::numeric_limits<count_t>::max() / sizeof(word_t)) == false);
            CHECK(too_many == nullptr);

            os::heap::Deallocate(words);
            /// [_a06ecc73_e7ac_43b2_b231_059675458c15]
        }
    }

    TEST_SUITE("Reallocate")
    {
        TEST_CASE("should reallocate heap memory, set pointer, and return true, else leave pointer and return false")
        {
            /// [_3c97398a_6fe6_4b47_81a2_18efd5ab72d5]
            word_t* words = nullptr;
            os::heap::Allocate(words, 0xFF);
            CHECK(os::heap::Reallocate(words, 0x100) == true);
            CHECK(words != nullptr);

            word_t* backup = words;
            CHECK(os::heap::Reallocate(words, std::numeric_limits<count_t>::max() / sizeof(word_t)) == false);
            CHECK(words == backup);

            os::heap::Deallocate(words);
            /// [_3c97398a_6fe6_4b47_81a2_18efd5ab72d5]
        }
    }

    TEST_SUITE("Deallocate")
    {
        TEST_CASE("should deallocate heap memory and set pointer to nullptr, or if pointer is nullptr, silently fail")
        {
            /// [_09113b05_5f70_459c_9827_f53c58816243]
            word_t* words = nullptr;
            os::heap::Allocate(words, 0xFF);
            os::heap::Deallocate(words);
            CHECK(words == nullptr);

            os::heap::Deallocate(words);
            CHECK(words == nullptr);
            /// [_09113b05_5f70_459c_9827_f53c58816243]
        }
    }

    TEST_SUITE("Allocate_Zeros")
    {
        TEST_CASE("should allocate heap memory, set pointer, set memory to zero, and return true, or set nullptr and return false")
        {
            /// [_fc02c748_8572_4062_b2b1_8cfaa78bc002]
            word_t* words = nullptr;
            CHECK(os::heap::Allocate_Zeros(words, 0xFF));
            CHECK(words != nullptr);
            for (index_t idx = 0, end = 0xFF; idx < end; idx += 1) {
                WARN(words[idx] == 0);
            }

            word_t* too_many = nullptr;
            CHECK(os::heap::Allocate_Zeros(too_many, std::numeric_limits<count_t>::max() / sizeof(word_t)) == false);
            CHECK(too_many == nullptr);

            os::heap::Deallocate_Zeros(words);
            /// [_fc02c748_8572_4062_b2b1_8cfaa78bc002]
        }
    }

    TEST_SUITE("Reallocate_Zeros")
    {
        TEST_CASE("should reallocate heap memory, set pointer, set memory to zero, and return true, else leave pointer and return false")
        {
            /// [_831dc6ca_17bd_4515_9fd9_48f36c1014da]
            word_t* words = nullptr;
            os::heap::Allocate_Zeros(words, 0xFF);
            CHECK(os::heap::Reallocate_Zeros(words, 0x100) == true);
            CHECK(words != nullptr);
            for (index_t idx = 0, end = 0x100; idx < end; idx += 1) {
                WARN(words[idx] == 0);
            }

            word_t* backup = words;
            CHECK(os::heap::Reallocate_Zeros(words, std::numeric_limits<count_t>::max() / sizeof(word_t)) == false);
            CHECK(words == backup);

            os::heap::Deallocate_Zeros(words);
            /// [_831dc6ca_17bd_4515_9fd9_48f36c1014da]
        }
    }

    TEST_SUITE("Deallocate_Zeros")
    {
        TEST_CASE("should deallocate heap memory and set pointer to nullptr, or if pointer is nullptr, silently fail")
        {
            /// [_6c279b29_119d_4ca0_8c6a_552cb9ea6431]
            word_t* words = nullptr;
            os::heap::Allocate_Zeros(words, 0xFF);
            os::heap::Deallocate_Zeros(words);
            CHECK(words == nullptr);

            os::heap::Deallocate_Zeros(words);
            CHECK(words == nullptr);
            /// [_6c279b29_119d_4ca0_8c6a_552cb9ea6431]
        }
    }

}}}
