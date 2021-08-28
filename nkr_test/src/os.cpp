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
                bool_t boolean = false;
                bool_t access = nkr::os::atomic::Access(boolean);
                CHECK(nkr::os::atomic::Access(boolean) == access);
                CHECK(nkr::os::atomic::Access(boolean) == false);
            }
            TEST_CASE("std_bool_t")
            {
                std_bool_t boolean = false;
                std_bool_t access = nkr::os::atomic::Access(boolean);
                CHECK(nkr::os::atomic::Access(boolean) == access);
                CHECK(nkr::os::atomic::Access(boolean) == false);
            }
            TEST_CASE("u8_t")
            {
                u8_t u8 = 8;
                u8_t access = nkr::os::atomic::Access(u8);
                CHECK(nkr::os::atomic::Access(u8) == access);
                CHECK(nkr::os::atomic::Access(u8) == 8);
            }
            TEST_CASE("u16_t")
            {
                u16_t u16 = 16;
                u16_t access = nkr::os::atomic::Access(u16);
                CHECK(nkr::os::atomic::Access(u16) == access);
                CHECK(nkr::os::atomic::Access(u16) == 16);
            }
            TEST_CASE("u32_t")
            {
                u32_t u32 = 32;
                u32_t access = nkr::os::atomic::Access(u32);
                CHECK(nkr::os::atomic::Access(u32) == access);
                CHECK(nkr::os::atomic::Access(u32) == 32);
            }
            TEST_CASE("u64_t")
            {
            #if defined(nkr_IS_64_BIT)
                u64_t u64 = 64;
                u64_t access = nkr::os::atomic::Access(u64);
                CHECK(nkr::os::atomic::Access(u64) == access);
                CHECK(nkr::os::atomic::Access(u64) == 64);
            #endif
            }
            TEST_CASE("s8_t")
            {
                s8_t s8 = -8;
                s8_t access = nkr::os::atomic::Access(s8);
                CHECK(nkr::os::atomic::Access(s8) == access);
                CHECK(nkr::os::atomic::Access(s8) == -8);
            }
            TEST_CASE("s16_t")
            {
                s16_t s16 = -16;
                s16_t access = nkr::os::atomic::Access(s16);
                CHECK(nkr::os::atomic::Access(s16) == access);
                CHECK(nkr::os::atomic::Access(s16) == -16);
            }
            TEST_CASE("s32_t")
            {
                s32_t s32 = -32;
                s32_t access = nkr::os::atomic::Access(s32);
                CHECK(nkr::os::atomic::Access(s32) == access);
                CHECK(nkr::os::atomic::Access(s32) == -32);
            }
            TEST_CASE("s64_t")
            {
            #if defined(nkr_IS_64_BIT)
                s64_t s64 = -64;
                s64_t access = nkr::os::atomic::Access(s64);
                CHECK(nkr::os::atomic::Access(s64) == access);
                CHECK(nkr::os::atomic::Access(s64) == -64);
            #endif
            }
            TEST_CASE("f32_t")
            {
                f32_t f32 = 3.2f;
                f32_t access = nkr::os::atomic::Access(f32);
                CHECK(nkr::os::atomic::Access(f32) == access);
                CHECK(nkr::os::atomic::Access(f32) == 3.2f);
            }
            TEST_CASE("f64_t")
            {
            #if defined(nkr_IS_64_BIT)
                f64_t f64 = 6.4;
                f64_t access = nkr::os::atomic::Access(f64);
                CHECK(nkr::os::atomic::Access(f64) == access);
                CHECK(nkr::os::atomic::Access(f64) == 6.4);
            #endif
            }
            TEST_CASE("void_t*")
            {
                void_t* void_pointer = nullptr;
                void_t* access = nkr::os::atomic::Access(void_pointer);
                CHECK(nkr::os::atomic::Access(void_pointer) == access);
                CHECK(nkr::os::atomic::Access(void_pointer) == nullptr);
            }
            TEST_CASE("bool_t*")
            {
                bool_t boolean = false;
                bool_t* boolean_pointer = &boolean;
                bool_t* access = nkr::os::atomic::Access(boolean_pointer);
                CHECK(nkr::os::atomic::Access(boolean_pointer) == access);
                CHECK(nkr::os::atomic::Access(boolean_pointer) == &boolean);
            }
        }
    }

    TEST_SUITE("Access_Add")
    {
        TEST_SUITE("should return added values without changing the original")
        {
            TEST_CASE("u8_t")
            {
                u8_t u8 = 8;
                CHECK(nkr::os::atomic::Access_Add(u8, 1) == 9);
                CHECK(u8 == 8);
            }
            TEST_CASE("u16_t")
            {
                u16_t u16 = 16;
                CHECK(nkr::os::atomic::Access_Add(u16, 1) == 17);
                CHECK(u16 == 16);
            }
            TEST_CASE("u32_t")
            {
                u32_t u32 = 32;
                CHECK(nkr::os::atomic::Access_Add(u32, 1) == 33);
                CHECK(u32 == 32);
            }
            TEST_CASE("u64_t")
            {
            #if defined(nkr_IS_64_BIT)
                u64_t u64 = 64;
                CHECK(nkr::os::atomic::Access_Add(u64, 1) == 65);
                CHECK(u64 == 64);
            #endif
            }
            TEST_CASE("s8_t")
            {
                s8_t s8 = -8;
                CHECK(nkr::os::atomic::Access_Add(s8, -1) == -9);
                CHECK(s8 == -8);
            }
            TEST_CASE("s16_t")
            {
                s16_t s16 = -16;
                CHECK(nkr::os::atomic::Access_Add(s16, -1) == -17);
                CHECK(s16 == -16);
            }
            TEST_CASE("s32_t")
            {
                s32_t s32 = -32;
                CHECK(nkr::os::atomic::Access_Add(s32, -1) == -33);
                CHECK(s32 == -32);
            }
            TEST_CASE("s64_t")
            {
            #if defined(nkr_IS_64_BIT)
                s64_t s64 = -64;
                CHECK(nkr::os::atomic::Access_Add(s64, -1) == -65);
                CHECK(s64 == -64);
            #endif
            }
            TEST_CASE("f32_t")
            {
                f32_t f32 = 3.2f;
                CHECK(nkr::os::atomic::Access_Add(f32, 0.1f) == 3.2f + 0.1f);
                CHECK(f32 == 3.2f);
            }
            TEST_CASE("f64_t")
            {
            #if defined(nkr_IS_64_BIT)
                f64_t f64 = 6.4;
                CHECK(nkr::os::atomic::Access_Add(f64, 0.1) == 6.4 + 0.1);
                CHECK(f64 == 6.4);
            #endif
            }
            TEST_CASE("bool_t*")
            {
                bool_t booleans[2] = { true, true };
                bool_t* boolean_pointer = booleans;
                CHECK(nkr::os::atomic::Access_Add(boolean_pointer, 1) == booleans + 1);
                CHECK(boolean_pointer == booleans + 0);
            }
        }
    }

    TEST_SUITE("Access_Subtract")
    {
        TEST_SUITE("should return subtracted values without changing the original")
        {
            TEST_CASE("u8_t")
            {
                u8_t u8 = 8;
                CHECK(nkr::os::atomic::Access_Subtract(u8, 1) == 7);
                CHECK(u8 == 8);
            }
            TEST_CASE("u16_t")
            {
                u16_t u16 = 16;
                CHECK(nkr::os::atomic::Access_Subtract(u16, 1) == 15);
                CHECK(u16 == 16);
            }
            TEST_CASE("u32_t")
            {
                u32_t u32 = 32;
                CHECK(nkr::os::atomic::Access_Subtract(u32, 1) == 31);
                CHECK(u32 == 32);
            }
            TEST_CASE("u64_t")
            {
            #if defined(nkr_IS_64_BIT)
                u64_t u64 = 64;
                CHECK(nkr::os::atomic::Access_Subtract(u64, 1) == 63);
                CHECK(u64 == 64);
            #endif
            }
            TEST_CASE("s8_t")
            {
                s8_t s8 = -8;
                CHECK(nkr::os::atomic::Access_Subtract(s8, -1) == -7);
                CHECK(s8 == -8);
            }
            TEST_CASE("s16_t")
            {
                s16_t s16 = -16;
                CHECK(nkr::os::atomic::Access_Subtract(s16, -1) == -15);
                CHECK(s16 == -16);
            }
            TEST_CASE("s32_t")
            {
                s32_t s32 = -32;
                CHECK(nkr::os::atomic::Access_Subtract(s32, -1) == -31);
                CHECK(s32 == -32);
            }
            TEST_CASE("s64_t")
            {
            #if defined(nkr_IS_64_BIT)
                s64_t s64 = -64;
                CHECK(nkr::os::atomic::Access_Subtract(s64, -1) == -63);
                CHECK(s64 == -64);
            #endif
            }
            TEST_CASE("f32_t")
            {
                f32_t f32 = 3.2f;
                CHECK(nkr::os::atomic::Access_Subtract(f32, 0.1f) == 3.2f - 0.1f);
                CHECK(f32 == 3.2f);
            }
            TEST_CASE("f64_t")
            {
            #if defined(nkr_IS_64_BIT)
                f64_t f64 = 6.4;
                CHECK(nkr::os::atomic::Access_Subtract(f64, 0.1) == 6.4 - 0.1);
                CHECK(f64 == 6.4);
            #endif
            }
            TEST_CASE("bool_t*")
            {
                bool_t booleans[2] = { true, true };
                bool_t* boolean_pointer = booleans + 1;
                CHECK(nkr::os::atomic::Access_Subtract(boolean_pointer, 1) == booleans + 0);
                CHECK(boolean_pointer == booleans + 1);
            }
        }
    }

    TEST_SUITE("Access_Multiply()")
    {
        TEST_SUITE("should value * operand without changing its original value")
        {
            TEST_CASE("u8_t")
            {
                u8_t u8 = 8;
                CHECK(nkr::os::atomic::Access_Multiply(u8, 2) == 16);
                CHECK(nkr::os::atomic::Access(u8) == 8);
            }
            TEST_CASE("u16_t")
            {
                u16_t u16 = 16;
                CHECK(nkr::os::atomic::Access_Multiply(u16, 2) == 32);
                CHECK(nkr::os::atomic::Access(u16) == 16);
            }
            TEST_CASE("u32_t")
            {
                u32_t u32 = 32;
                CHECK(nkr::os::atomic::Access_Multiply(u32, 2) == 64);
                CHECK(nkr::os::atomic::Access(u32) == 32);
            }
            TEST_CASE("u64_t")
            {
            #if defined(nkr_IS_64_BIT)
                u64_t u64 = 64;
                CHECK(nkr::os::atomic::Access_Multiply(u64, 2) == 128);
                CHECK(nkr::os::atomic::Access(u64) == 64);
            #endif
            }
            TEST_CASE("s8_t")
            {
                s8_t s8 = -8;
                CHECK(nkr::os::atomic::Access_Multiply(s8, 2) == -16);
                CHECK(nkr::os::atomic::Access(s8) == -8);
            }
            TEST_CASE("s16_t")
            {
                s16_t s16 = -16;
                CHECK(nkr::os::atomic::Access_Multiply(s16, 2) == -32);
                CHECK(nkr::os::atomic::Access(s16) == -16);
            }
            TEST_CASE("s32_t")
            {
                s32_t s32 = -32;
                CHECK(nkr::os::atomic::Access_Multiply(s32, 2) == -64);
                CHECK(nkr::os::atomic::Access(s32) == -32);
            }
            TEST_CASE("s64_t")
            {
            #if defined(nkr_IS_64_BIT)
                s64_t s64 = -64;
                CHECK(nkr::os::atomic::Access_Multiply(s64, 2) == -128);
                CHECK(nkr::os::atomic::Access(s64) == -64);
            #endif
            }
            TEST_CASE("f32_t")
            {
                f32_t f32 = 3.2f;
                CHECK(nkr::os::atomic::Access_Multiply(f32, 0.1f) == 3.2f * 0.1f);
                CHECK(nkr::os::atomic::Access(f32) == 3.2f);
            }
            TEST_CASE("f64_t")
            {
            #if defined(nkr_IS_64_BIT)
                f64_t f64 = 6.4;
                CHECK(nkr::os::atomic::Access_Multiply(f64, 0.1) == 6.4 * 0.1);
                CHECK(nkr::os::atomic::Access(f64) == 6.4);
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
                u8_t u8 = 8;
                CHECK(nkr::os::atomic::Access_Divide(u8, 2) == 4);
                CHECK(nkr::os::atomic::Access(u8) == 8);
            }
            TEST_CASE("u16_t")
            {
                u16_t u16 = 16;
                CHECK(nkr::os::atomic::Access_Divide(u16, 2) == 8);
                CHECK(nkr::os::atomic::Access(u16) == 16);
            }
            TEST_CASE("u32_t")
            {
                u32_t u32 = 32;
                CHECK(nkr::os::atomic::Access_Divide(u32, 2) == 16);
                CHECK(nkr::os::atomic::Access(u32) == 32);
            }
            TEST_CASE("u64_t")
            {
            #if defined(nkr_IS_64_BIT)
                u64_t u64 = 64;
                CHECK(nkr::os::atomic::Access_Divide(u64, 2) == 32);
                CHECK(nkr::os::atomic::Access(u64) == 64);
            #endif
            }
            TEST_CASE("s8_t")
            {
                s8_t s8 = -8;
                CHECK(nkr::os::atomic::Access_Divide(s8, 2) == -4);
                CHECK(nkr::os::atomic::Access(s8) == -8);
            }
            TEST_CASE("s16_t")
            {
                s16_t s16 = -16;
                CHECK(nkr::os::atomic::Access_Divide(s16, 2) == -8);
                CHECK(nkr::os::atomic::Access(s16) == -16);
            }
            TEST_CASE("s32_t")
            {
                s32_t s32 = -32;
                CHECK(nkr::os::atomic::Access_Divide(s32, 2) == -16);
                CHECK(nkr::os::atomic::Access(s32) == -32);
            }
            TEST_CASE("s64_t")
            {
            #if defined(nkr_IS_64_BIT)
                s64_t s64 = -64;
                CHECK(nkr::os::atomic::Access_Divide(s64, 2) == -32);
                CHECK(nkr::os::atomic::Access(s64) == -64);
            #endif
            }
            TEST_CASE("f32_t")
            {
                f32_t f32 = 3.2f;
                CHECK(nkr::os::atomic::Access_Divide(f32, 0.1f) == 3.2f / 0.1f);
                CHECK(nkr::os::atomic::Access(f32) == 3.2f);
            }
            TEST_CASE("f64_t")
            {
            #if defined(nkr_IS_64_BIT)
                f64_t f64 = 6.4;
                CHECK(nkr::os::atomic::Access_Divide(f64, 0.1) == 6.4 / 0.1);
                CHECK(nkr::os::atomic::Access(f64) == 6.4);
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
                u8_t u8 = 8;
                CHECK(nkr::os::atomic::Access_Modulus(u8, 3) == 2);
                CHECK(nkr::os::atomic::Access(u8) == 8);
            }
            TEST_CASE("u16_t")
            {
                u16_t u16 = 16;
                CHECK(nkr::os::atomic::Access_Modulus(u16, 3) == 1);
                CHECK(nkr::os::atomic::Access(u16) == 16);
            }
            TEST_CASE("u32_t")
            {
                u32_t u32 = 32;
                CHECK(nkr::os::atomic::Access_Modulus(u32, 3) == 2);
                CHECK(nkr::os::atomic::Access(u32) == 32);
            }
            TEST_CASE("u64_t")
            {
            #if defined(nkr_IS_64_BIT)
                u64_t u64 = 64;
                CHECK(nkr::os::atomic::Access_Modulus(u64, 3) == 1);
                CHECK(nkr::os::atomic::Access(u64) == 64);
            #endif
            }
            TEST_CASE("s8_t")
            {
                s8_t s8 = -8;
                CHECK(nkr::os::atomic::Access_Modulus(s8, 3) == -2);
                CHECK(nkr::os::atomic::Access(s8) == -8);
            }
            TEST_CASE("s16_t")
            {
                s16_t s16 = -16;
                CHECK(nkr::os::atomic::Access_Modulus(s16, 3) == -1);
                CHECK(nkr::os::atomic::Access(s16) == -16);
            }
            TEST_CASE("s32_t")
            {
                s32_t s32 = -32;
                CHECK(nkr::os::atomic::Access_Modulus(s32, 3) == -2);
                CHECK(nkr::os::atomic::Access(s32) == -32);
            }
            TEST_CASE("s64_t")
            {
            #if defined(nkr_IS_64_BIT)
                s64_t s64 = -64;
                CHECK(nkr::os::atomic::Access_Modulus(s64, 3) == -1);
                CHECK(nkr::os::atomic::Access(s64) == -64);
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
                u8_t u8 = 0x0F;
                CHECK(nkr::os::atomic::Access_Or(u8, 0xF0) == 0xFF);
                CHECK(u8 == 0x0F);
            }
            TEST_CASE("u16_t")
            {
                u16_t u16 = 0x00FF;
                CHECK(nkr::os::atomic::Access_Or(u16, 0xFF00) == 0xFFFF);
                CHECK(u16 == 0x00FF);
            }
            TEST_CASE("u32_t")
            {
                u32_t u32 = 0x0000FFFF;
                CHECK(nkr::os::atomic::Access_Or(u32, 0xFFFF0000) == 0xFFFFFFFF);
                CHECK(u32 == 0x0000FFFF);
            }
            TEST_CASE("u64_t")
            {
            #if defined(nkr_IS_64_BIT)
                u64_t u64 = 0x00000000FFFFFFFF;
                CHECK(nkr::os::atomic::Access_Or(u64, 0xFFFFFFFF00000000) == 0xFFFFFFFFFFFFFFFF);
                CHECK(u64 == 0x00000000FFFFFFFF);
            #endif
            }
            TEST_CASE("s8_t")
            {
                s8_t s8 = 0x0F;
                CHECK(nkr::os::atomic::Access_Or(s8, 0x70) == 0x7F);
                CHECK(s8 == 0x0F);
            }
            TEST_CASE("s16_t")
            {
                s16_t s16 = 0x00FF;
                CHECK(nkr::os::atomic::Access_Or(s16, 0x7F00) == 0x7FFF);
                CHECK(s16 == 0x00FF);
            }
            TEST_CASE("s32_t")
            {
                s32_t s32 = 0x0000FFFF;
                CHECK(nkr::os::atomic::Access_Or(s32, 0x7FFF0000) == 0x7FFFFFFF);
                CHECK(s32 == 0x0000FFFF);
            }
            TEST_CASE("s64_t")
            {
            #if defined(nkr_IS_64_BIT)
                s64_t s64 = 0x00000000FFFFFFFF;
                CHECK(nkr::os::atomic::Access_Or(s64, 0x7FFFFFFF00000000) == 0x7FFFFFFFFFFFFFFF);
                CHECK(s64 == 0x00000000FFFFFFFF);
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
                u8_t u8 = 0x0F;
                CHECK(nkr::os::atomic::Access_And(u8, 0xF0) == 0x0);
                CHECK(u8 == 0x0F);
            }
            TEST_CASE("u16_t")
            {
                u16_t u16 = 0x00FF;
                CHECK(nkr::os::atomic::Access_And(u16, 0xFF00) == 0x0);
                CHECK(u16 == 0x00FF);
            }
            TEST_CASE("u32_t")
            {
                u32_t u32 = 0x0000FFFF;
                CHECK(nkr::os::atomic::Access_And(u32, 0xFFFF0000) == 0x0);
                CHECK(u32 == 0x0000FFFF);
            }
            TEST_CASE("u64_t")
            {
            #if defined(nkr_IS_64_BIT)
                u64_t u64 = 0x00000000FFFFFFFF;
                CHECK(nkr::os::atomic::Access_And(u64, 0xFFFFFFFF00000000) == 0x0);
                CHECK(u64 == 0x00000000FFFFFFFF);
            #endif
            }
            TEST_CASE("s8_t")
            {
                s8_t s8 = 0x0F;
                CHECK(nkr::os::atomic::Access_And(s8, 0x70) == 0x0);
                CHECK(s8 == 0x0F);
            }
            TEST_CASE("s16_t")
            {
                s16_t s16 = 0x00FF;
                CHECK(nkr::os::atomic::Access_And(s16, 0x7F00) == 0x0);
                CHECK(s16 == 0x00FF);
            }
            TEST_CASE("s32_t")
            {
                s32_t s32 = 0x0000FFFF;
                CHECK(nkr::os::atomic::Access_And(s32, 0x7FFF0000) == 0x0);
                CHECK(s32 == 0x0000FFFF);
            }
            TEST_CASE("s64_t")
            {
            #if defined(nkr_IS_64_BIT)
                s64_t s64 = 0x00000000FFFFFFFF;
                CHECK(nkr::os::atomic::Access_And(s64, 0x7FFFFFFF00000000) == 0x0);
                CHECK(s64 == 0x00000000FFFFFFFF);
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
                u8_t u8 = 0xFF;
                CHECK(nkr::os::atomic::Access_Xor(u8, 0x01) == 0xFE);
                CHECK(u8 == 0xFF);
            }
            TEST_CASE("u16_t")
            {
                u16_t u16 = 0xFFFF;
                CHECK(nkr::os::atomic::Access_Xor(u16, 0x0001) == 0xFFFE);
                CHECK(u16 == 0xFFFF);
            }
            TEST_CASE("u32_t")
            {
                u32_t u32 = 0xFFFFFFFF;
                CHECK(nkr::os::atomic::Access_Xor(u32, 0x00000001) == 0xFFFFFFFE);
                CHECK(u32 == 0xFFFFFFFF);
            }
            TEST_CASE("u64_t")
            {
            #if defined(nkr_IS_64_BIT)
                u64_t u64 = 0xFFFFFFFFFFFFFFFF;
                CHECK(nkr::os::atomic::Access_Xor(u64, 0x0000000000000001) == 0xFFFFFFFFFFFFFFFE);
                CHECK(u64 == 0xFFFFFFFFFFFFFFFF);
            #endif
            }
            TEST_CASE("s8_t")
            {
                s8_t s8 = 0x7F;
                CHECK(nkr::os::atomic::Access_Xor(s8, 0x01) == 0x7E);
                CHECK(s8 == 0x7F);
            }
            TEST_CASE("s16_t")
            {
                s16_t s16 = 0x7FFF;
                CHECK(nkr::os::atomic::Access_Xor(s16, 0x0001) == 0x7FFE);
                CHECK(s16 == 0x7FFF);
            }
            TEST_CASE("s32_t")
            {
                s32_t s32 = 0x7FFFFFFF;
                CHECK(nkr::os::atomic::Access_Xor(s32, 0x00000001) == 0x7FFFFFFE);
                CHECK(s32 == 0x7FFFFFFF);
            }
            TEST_CASE("s64_t")
            {
            #if defined(nkr_IS_64_BIT)
                s64_t s64 = 0x7FFFFFFFFFFFFFFF;
                CHECK(nkr::os::atomic::Access_Xor(s64, 0x0000000000000001) == 0x7FFFFFFFFFFFFFFE);
                CHECK(s64 == 0x7FFFFFFFFFFFFFFF);
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
                u8_t u8 = 0x0F;
                CHECK(nkr::os::atomic::Access_Left_Shift(u8, 4) == 0xF0);
                CHECK(nkr::os::atomic::Access(u8) == 0x0F);
            }
            TEST_CASE("u16_t")
            {
                u16_t u16 = 0x00FF;
                CHECK(nkr::os::atomic::Access_Left_Shift(u16, 8) == 0xFF00);
                CHECK(nkr::os::atomic::Access(u16) == 0x00FF);
            }
            TEST_CASE("u32_t")
            {
                u32_t u32 = 0x0000FFFF;
                CHECK(nkr::os::atomic::Access_Left_Shift(u32, 16) == 0xFFFF0000);
                CHECK(nkr::os::atomic::Access(u32) == 0x0000FFFF);
            }
            TEST_CASE("u64_t")
            {
            #if defined(nkr_IS_64_BIT)
                u64_t u64 = 0x00000000FFFFFFFF;
                CHECK(nkr::os::atomic::Access_Left_Shift(u64, 32) == 0xFFFFFFFF00000000);
                CHECK(nkr::os::atomic::Access(u64) == 0x00000000FFFFFFFF);
            #endif
            }
            TEST_CASE("s8_t")
            {
                s8_t s8 = 0x07;
                CHECK(nkr::os::atomic::Access_Left_Shift(s8, 4) == 0x70);
                CHECK(nkr::os::atomic::Access(s8) == 0x07);
            }
            TEST_CASE("s16_t")
            {
                s16_t s16 = 0x007F;
                CHECK(nkr::os::atomic::Access_Left_Shift(s16, 8) == 0x7F00);
                CHECK(nkr::os::atomic::Access(s16) == 0x007F);
            }
            TEST_CASE("s32_t")
            {
                s32_t s32 = 0x00007FFF;
                CHECK(nkr::os::atomic::Access_Left_Shift(s32, 16) == 0x7FFF0000);
                CHECK(nkr::os::atomic::Access(s32) == 0x00007FFF);
            }
            TEST_CASE("s64_t")
            {
            #if defined(nkr_IS_64_BIT)
                s64_t s64 = 0x000000007FFFFFFF;
                CHECK(nkr::os::atomic::Access_Left_Shift(s64, 32) == 0x7FFFFFFF00000000);
                CHECK(nkr::os::atomic::Access(s64) == 0x000000007FFFFFFF);
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
                u8_t u8 = 0xF0;
                CHECK(nkr::os::atomic::Access_Right_Shift(u8, 4) == 0x0F);
                CHECK(nkr::os::atomic::Access(u8) == 0xF0);
            }
            TEST_CASE("u16_t")
            {
                u16_t u16 = 0xFF00;
                CHECK(nkr::os::atomic::Access_Right_Shift(u16, 8) == 0x00FF);
                CHECK(nkr::os::atomic::Access(u16) == 0xFF00);
            }
            TEST_CASE("u32_t")
            {
                u32_t u32 = 0xFFFF0000;
                CHECK(nkr::os::atomic::Access_Right_Shift(u32, 16) == 0x0000FFFF);
                CHECK(nkr::os::atomic::Access(u32) == 0xFFFF0000);
            }
            TEST_CASE("u64_t")
            {
            #if defined(nkr_IS_64_BIT)
                u64_t u64 = 0xFFFFFFFF00000000;
                CHECK(nkr::os::atomic::Access_Right_Shift(u64, 32) == 0x00000000FFFFFFFF);
                CHECK(nkr::os::atomic::Access(u64) == 0xFFFFFFFF00000000);
            #endif
            }
            TEST_CASE("s8_t")
            {
                s8_t s8 = 0x70;
                CHECK(nkr::os::atomic::Access_Right_Shift(s8, 4) == 0x07);
                CHECK(nkr::os::atomic::Access(s8) == 0x70);
            }
            TEST_CASE("s16_t")
            {
                s16_t s16 = 0x7F00;
                CHECK(nkr::os::atomic::Access_Right_Shift(s16, 8) == 0x007F);
                CHECK(nkr::os::atomic::Access(s16) == 0x7F00);
            }
            TEST_CASE("s32_t")
            {
                s32_t s32 = 0x7FFF0000;
                CHECK(nkr::os::atomic::Access_Right_Shift(s32, 16) == 0x00007FFF);
                CHECK(nkr::os::atomic::Access(s32) == 0x7FFF0000);
            }
            TEST_CASE("s64_t")
            {
            #if defined(nkr_IS_64_BIT)
                s64_t s64 = 0x7FFFFFFF00000000;
                CHECK(nkr::os::atomic::Access_Right_Shift(s64, 32) == 0x000000007FFFFFFF);
                CHECK(nkr::os::atomic::Access(s64) == 0x7FFFFFFF00000000);
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
                bool_t boolean = false;
                CHECK(nkr::os::atomic::Assign(boolean, true) == true);
                CHECK(boolean == true);
            }
            TEST_CASE("std_bool_t")
            {
                std_bool_t boolean = false;
                CHECK(nkr::os::atomic::Assign(boolean, true) == true);
                CHECK(boolean == true);
            }
            TEST_CASE("u8_t")
            {
                u8_t u8 = 8;
                CHECK(nkr::os::atomic::Assign(u8, 1) == 1);
                CHECK(u8 == 1);
            }
            TEST_CASE("u16_t")
            {
                u16_t u16 = 16;
                CHECK(nkr::os::atomic::Assign(u16, 1) == 1);
                CHECK(u16 == 1);
            }
            TEST_CASE("u32_t")
            {
                u32_t u32 = 32;
                CHECK(nkr::os::atomic::Assign(u32, 1) == 1);
                CHECK(u32 == 1);
            }
            TEST_CASE("u64_t")
            {
            #if defined(nkr_IS_64_BIT)
                u64_t u64 = 64;
                CHECK(nkr::os::atomic::Assign(u64, 1) == 1);
                CHECK(u64 == 1);
            #endif
            }
            TEST_CASE("s8_t")
            {
                s8_t s8 = -8;
                CHECK(nkr::os::atomic::Assign(s8, -1) == -1);
                CHECK(s8 == -1);
            }
            TEST_CASE("s16_t")
            {
                s16_t s16 = -16;
                CHECK(nkr::os::atomic::Assign(s16, -1) == -1);
                CHECK(s16 == -1);
            }
            TEST_CASE("s32_t")
            {
                s32_t s32 = -32;
                CHECK(nkr::os::atomic::Assign(s32, -1) == -1);
                CHECK(s32 == -1);
            }
            TEST_CASE("s64_t")
            {
            #if defined(nkr_IS_64_BIT)
                s64_t s64 = -64;
                CHECK(nkr::os::atomic::Assign(s64, -1) == -1);
                CHECK(s64 == -1);
            #endif
            }
            TEST_CASE("f32_t")
            {
                f32_t f32 = 3.2f;
                CHECK(nkr::os::atomic::Assign(f32, 1.0f) == 1.0f);
                CHECK(f32 == 1.0f);
            }
            TEST_CASE("f64_t")
            {
            #if defined(nkr_IS_64_BIT)
                f64_t f64 = 6.4;
                CHECK(nkr::os::atomic::Assign(f64, 1.0) == 1.0);
                CHECK(f64 == 1.0);
            #endif
            }
            TEST_CASE("void_t*")
            {
                bool_t boolean = false;
                void_t* void_pointer = nullptr;
                CHECK(nkr::os::atomic::Assign(void_pointer, &boolean) == &boolean);
                CHECK(void_pointer == &boolean);
            }
            TEST_CASE("bool_t*")
            {
                bool_t boolean = false;
                bool_t* boolean_pointer = &boolean;
                CHECK(nkr::os::atomic::Assign(boolean_pointer, nullptr) == nullptr);
                CHECK(boolean_pointer == nullptr);
            }
        }
    }

    TEST_SUITE("Assign_Add")
    {
        TEST_SUITE("should atomically add to integers and pointers and return the new value")
        {
            TEST_CASE("u8_t")
            {
                u8_t u8 = 8;
                CHECK(nkr::os::atomic::Assign_Add(u8, 1) == 9);
                CHECK(u8 == 9);
            }
            TEST_CASE("u16_t")
            {
                u16_t u16 = 16;
                CHECK(nkr::os::atomic::Assign_Add(u16, 1) == 17);
                CHECK(u16 == 17);
            }
            TEST_CASE("u32_t")
            {
                u32_t u32 = 32;
                CHECK(nkr::os::atomic::Assign_Add(u32, 1) == 33);
                CHECK(u32 == 33);
            }
            TEST_CASE("u64_t")
            {
            #if defined(nkr_IS_64_BIT)
                u64_t u64 = 64;
                CHECK(nkr::os::atomic::Assign_Add(u64, 1) == 65);
                CHECK(u64 == 65);
            #endif
            }
            TEST_CASE("s8_t")
            {
                s8_t s8 = -8;
                CHECK(nkr::os::atomic::Assign_Add(s8, -1) == -9);
                CHECK(s8 == -9);
            }
            TEST_CASE("s16_t")
            {
                s16_t s16 = -16;
                CHECK(nkr::os::atomic::Assign_Add(s16, -1) == -17);
                CHECK(s16 == -17);
            }
            TEST_CASE("s32_t")
            {
                s32_t s32 = -32;
                CHECK(nkr::os::atomic::Assign_Add(s32, -1) == -33);
                CHECK(s32 == -33);
            }
            TEST_CASE("s64_t")
            {
            #if defined(nkr_IS_64_BIT)
                s64_t s64 = -64;
                CHECK(nkr::os::atomic::Assign_Add(s64, -1) == -65);
                CHECK(s64 == -65);
            #endif
            }
            TEST_CASE("f32_t")
            {
                f32_t f32 = 3.2f;
                CHECK(nkr::os::atomic::Assign_Add(f32, 0.1f) == 3.2f + 0.1f);
                CHECK(f32 == 3.2f + 0.1f);
            }
            TEST_CASE("f64_t")
            {
            #if defined(nkr_IS_64_BIT)
                f64_t f64 = 6.4;
                CHECK(nkr::os::atomic::Assign_Add(f64, 0.1) == 6.4 + 0.1);
                CHECK(f64 == 6.4 + 0.1);
            #endif
            }
            TEST_CASE("bool_t*")
            {
                bool_t booleans[2] = { true, true };
                bool_t* boolean_pointer = booleans;
                CHECK(nkr::os::atomic::Assign_Add(boolean_pointer, 1) == booleans + 1);
                CHECK(nkr::os::atomic::Assign_Add(boolean_pointer, -1) == booleans + 0);
            }
        }
        TEST_CASE("should be able to increment a variable atomically without data loss"
                  * doctest::no_breaks(true))
        {
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
        }
    }

    TEST_SUITE("Assign_Subtract")
    {
        TEST_SUITE("should atomically subtract from integers and pointers and return the new value")
        {
            TEST_CASE("u8_t")
            {
                u8_t u8 = 8;
                CHECK(nkr::os::atomic::Assign_Subtract(u8, 1) == 7);
                CHECK(u8 == 7);
            }
            TEST_CASE("u16_t")
            {
                u16_t u16 = 16;
                CHECK(nkr::os::atomic::Assign_Subtract(u16, 1) == 15);
                CHECK(u16 == 15);
            }
            TEST_CASE("u32_t")
            {
                u32_t u32 = 32;
                CHECK(nkr::os::atomic::Assign_Subtract(u32, 1) == 31);
                CHECK(u32 == 31);
            }
            TEST_CASE("u64_t")
            {
            #if defined(nkr_IS_64_BIT)
                u64_t u64 = 64;
                CHECK(nkr::os::atomic::Assign_Subtract(u64, 1) == 63);
                CHECK(u64 == 63);
            #endif
            }
            TEST_CASE("s8_t")
            {
                s8_t s8 = -8;
                CHECK(nkr::os::atomic::Assign_Subtract(s8, -1) == -7);
                CHECK(s8 == -7);
            }
            TEST_CASE("s16_t")
            {
                s16_t s16 = -16;
                CHECK(nkr::os::atomic::Assign_Subtract(s16, -1) == -15);
                CHECK(s16 == -15);
            }
            TEST_CASE("s32_t")
            {
                s32_t s32 = -32;
                CHECK(nkr::os::atomic::Assign_Subtract(s32, -1) == -31);
                CHECK(s32 == -31);
            }
            TEST_CASE("s64_t")
            {
            #if defined(nkr_IS_64_BIT)
                s64_t s64 = -64;
                CHECK(nkr::os::atomic::Assign_Subtract(s64, -1) == -63);
                CHECK(s64 == -63);
            #endif
            }
            TEST_CASE("f32_t")
            {
                f32_t f32 = 3.2f;
                CHECK(nkr::os::atomic::Assign_Subtract(f32, 0.1f) == 3.2f - 0.1f);
                CHECK(f32 == 3.2f - 0.1f);
            }
            TEST_CASE("f64_t")
            {
            #if defined(nkr_IS_64_BIT)
                f64_t f64 = 6.4;
                CHECK(nkr::os::atomic::Assign_Subtract(f64, 0.1) == 6.4 - 0.1);
                CHECK(f64 == 6.4 - 0.1);
            #endif
            }
            TEST_CASE("bool_t*")
            {
                bool_t booleans[2] = { true, true };
                bool_t* boolean_pointer = booleans + 1;
                CHECK(nkr::os::atomic::Assign_Subtract(boolean_pointer, 1) == booleans + 0);
                CHECK(nkr::os::atomic::Assign_Subtract(boolean_pointer, -1) == booleans + 1);
            }
        }
        TEST_CASE("should be able to decrement a variable atomically without data loss"
                  * doctest::no_breaks(true))
        {
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
        }
    }

    TEST_SUITE("Assign_Multiply()")
    {
        TEST_SUITE("should value * operand and change its original value")
        {
            TEST_CASE("u8_t")
            {
                u8_t u8 = 8;
                CHECK(nkr::os::atomic::Assign_Multiply(u8, 2) == 16);
                CHECK(nkr::os::atomic::Access(u8) == 16);
            }
            TEST_CASE("u16_t")
            {
                u16_t u16 = 16;
                CHECK(nkr::os::atomic::Assign_Multiply(u16, 2) == 32);
                CHECK(nkr::os::atomic::Access(u16) == 32);
            }
            TEST_CASE("u32_t")
            {
                u32_t u32 = 32;
                CHECK(nkr::os::atomic::Assign_Multiply(u32, 2) == 64);
                CHECK(nkr::os::atomic::Access(u32) == 64);
            }
            TEST_CASE("u64_t")
            {
            #if defined(nkr_IS_64_BIT)
                u64_t u64 = 64;
                CHECK(nkr::os::atomic::Assign_Multiply(u64, 2) == 128);
                CHECK(nkr::os::atomic::Access(u64) == 128);
            #endif
            }
            TEST_CASE("s8_t")
            {
                s8_t s8 = -8;
                CHECK(nkr::os::atomic::Assign_Multiply(s8, 2) == -16);
                CHECK(nkr::os::atomic::Access(s8) == -16);
            }
            TEST_CASE("s16_t")
            {
                s16_t s16 = -16;
                CHECK(nkr::os::atomic::Assign_Multiply(s16, 2) == -32);
                CHECK(nkr::os::atomic::Access(s16) == -32);
            }
            TEST_CASE("s32_t")
            {
                s32_t s32 = -32;
                CHECK(nkr::os::atomic::Assign_Multiply(s32, 2) == -64);
                CHECK(nkr::os::atomic::Access(s32) == -64);
            }
            TEST_CASE("s64_t")
            {
            #if defined(nkr_IS_64_BIT)
                s64_t s64 = -64;
                CHECK(nkr::os::atomic::Assign_Multiply(s64, 2) == -128);
                CHECK(nkr::os::atomic::Access(s64) == -128);
            #endif
            }
            TEST_CASE("f32_t")
            {
                f32_t f32 = 3.2f;
                CHECK(nkr::os::atomic::Assign_Multiply(f32, 0.1f) == 3.2f * 0.1f);
                CHECK(nkr::os::atomic::Access(f32) == 3.2f * 0.1f);
            }
            TEST_CASE("f64_t")
            {
            #if defined(nkr_IS_64_BIT)
                f64_t f64 = 6.4;
                CHECK(nkr::os::atomic::Assign_Multiply(f64, 0.1) == 6.4 * 0.1);
                CHECK(nkr::os::atomic::Access(f64) == 6.4 * 0.1);
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
                u8_t u8 = 8;
                CHECK(nkr::os::atomic::Assign_Divide(u8, 2) == 4);
                CHECK(nkr::os::atomic::Access(u8) == 4);
            }
            TEST_CASE("u16_t")
            {
                u16_t u16 = 16;
                CHECK(nkr::os::atomic::Assign_Divide(u16, 2) == 8);
                CHECK(nkr::os::atomic::Access(u16) == 8);
            }
            TEST_CASE("u32_t")
            {
                u32_t u32 = 32;
                CHECK(nkr::os::atomic::Assign_Divide(u32, 2) == 16);
                CHECK(nkr::os::atomic::Access(u32) == 16);
            }
            TEST_CASE("u64_t")
            {
            #if defined(nkr_IS_64_BIT)
                u64_t u64 = 64;
                CHECK(nkr::os::atomic::Assign_Divide(u64, 2) == 32);
                CHECK(nkr::os::atomic::Access(u64) == 32);
            #endif
            }
            TEST_CASE("s8_t")
            {
                s8_t s8 = -8;
                CHECK(nkr::os::atomic::Assign_Divide(s8, 2) == -4);
                CHECK(nkr::os::atomic::Access(s8) == -4);
            }
            TEST_CASE("s16_t")
            {
                s16_t s16 = -16;
                CHECK(nkr::os::atomic::Assign_Divide(s16, 2) == -8);
                CHECK(nkr::os::atomic::Access(s16) == -8);
            }
            TEST_CASE("s32_t")
            {
                s32_t s32 = -32;
                CHECK(nkr::os::atomic::Assign_Divide(s32, 2) == -16);
                CHECK(nkr::os::atomic::Access(s32) == -16);
            }
            TEST_CASE("s64_t")
            {
            #if defined(nkr_IS_64_BIT)
                s64_t s64 = -64;
                CHECK(nkr::os::atomic::Assign_Divide(s64, 2) == -32);
                CHECK(nkr::os::atomic::Access(s64) == -32);
            #endif
            }
            TEST_CASE("f32_t")
            {
                f32_t f32 = 3.2f;
                CHECK(nkr::os::atomic::Assign_Divide(f32, 0.1f) == 3.2f / 0.1f);
                CHECK(nkr::os::atomic::Access(f32) == 3.2f / 0.1f);
            }
            TEST_CASE("f64_t")
            {
            #if defined(nkr_IS_64_BIT)
                f64_t f64 = 6.4;
                CHECK(nkr::os::atomic::Assign_Divide(f64, 0.1) == 6.4 / 0.1);
                CHECK(nkr::os::atomic::Access(f64) == 6.4 / 0.1);
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
                u8_t u8 = 8;
                CHECK(nkr::os::atomic::Assign_Modulus(u8, 3) == 2);
                CHECK(nkr::os::atomic::Access(u8) == 2);
            }
            TEST_CASE("u16_t")
            {
                u16_t u16 = 16;
                CHECK(nkr::os::atomic::Assign_Modulus(u16, 3) == 1);
                CHECK(nkr::os::atomic::Access(u16) == 1);
            }
            TEST_CASE("u32_t")
            {
                u32_t u32 = 32;
                CHECK(nkr::os::atomic::Assign_Modulus(u32, 3) == 2);
                CHECK(nkr::os::atomic::Access(u32) == 2);
            }
            TEST_CASE("u64_t")
            {
            #if defined(nkr_IS_64_BIT)
                u64_t u64 = 64;
                CHECK(nkr::os::atomic::Assign_Modulus(u64, 3) == 1);
                CHECK(nkr::os::atomic::Access(u64) == 1);
            #endif
            }
            TEST_CASE("s8_t")
            {
                s8_t s8 = -8;
                CHECK(nkr::os::atomic::Assign_Modulus(s8, 3) == -2);
                CHECK(nkr::os::atomic::Access(s8) == -2);
            }
            TEST_CASE("s16_t")
            {
                s16_t s16 = -16;
                CHECK(nkr::os::atomic::Assign_Modulus(s16, 3) == -1);
                CHECK(nkr::os::atomic::Access(s16) == -1);
            }
            TEST_CASE("s32_t")
            {
                s32_t s32 = -32;
                CHECK(nkr::os::atomic::Assign_Modulus(s32, 3) == -2);
                CHECK(nkr::os::atomic::Access(s32) == -2);
            }
            TEST_CASE("s64_t")
            {
            #if defined(nkr_IS_64_BIT)
                s64_t s64 = -64;
                CHECK(nkr::os::atomic::Assign_Modulus(s64, 3) == -1);
                CHECK(nkr::os::atomic::Access(s64) == -1);
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
                u8_t u8 = 0x0F;
                CHECK(nkr::os::atomic::Assign_Or(u8, 0xF0) == 0xFF);
                CHECK(u8 == 0xFF);
            }
            TEST_CASE("u16_t")
            {
                u16_t u16 = 0x00FF;
                CHECK(nkr::os::atomic::Assign_Or(u16, 0xFF00) == 0xFFFF);
                CHECK(u16 == 0xFFFF);
            }
            TEST_CASE("u32_t")
            {
                u32_t u32 = 0x0000FFFF;
                CHECK(nkr::os::atomic::Assign_Or(u32, 0xFFFF0000) == 0xFFFFFFFF);
                CHECK(u32 == 0xFFFFFFFF);
            }
            TEST_CASE("u64_t")
            {
            #if defined(nkr_IS_64_BIT)
                u64_t u64 = 0x00000000FFFFFFFF;
                CHECK(nkr::os::atomic::Assign_Or(u64, 0xFFFFFFFF00000000) == 0xFFFFFFFFFFFFFFFF);
                CHECK(u64 == 0xFFFFFFFFFFFFFFFF);
            #endif
            }
            TEST_CASE("s8_t")
            {
                s8_t s8 = 0x0F;
                CHECK(nkr::os::atomic::Assign_Or(s8, 0x70) == 0x7F);
                CHECK(s8 == 0x7F);
            }
            TEST_CASE("s16_t")
            {
                s16_t s16 = 0x00FF;
                CHECK(nkr::os::atomic::Assign_Or(s16, 0x7F00) == 0x7FFF);
                CHECK(s16 == 0x7FFF);
            }
            TEST_CASE("s32_t")
            {
                s32_t s32 = 0x0000FFFF;
                CHECK(nkr::os::atomic::Assign_Or(s32, 0x7FFF0000) == 0x7FFFFFFF);
                CHECK(s32 == 0x7FFFFFFF);
            }
            TEST_CASE("s64_t")
            {
            #if defined(nkr_IS_64_BIT)
                s64_t s64 = 0x00000000FFFFFFFF;
                CHECK(nkr::os::atomic::Assign_Or(s64, 0x7FFFFFFF00000000) == 0x7FFFFFFFFFFFFFFF);
                CHECK(s64 == 0x7FFFFFFFFFFFFFFF);
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
                u8_t u8 = 0x0F;
                CHECK(nkr::os::atomic::Assign_And(u8, 0xF0) == 0x0);
                CHECK(u8 == 0x0);
            }
            TEST_CASE("u16_t")
            {
                u16_t u16 = 0x00FF;
                CHECK(nkr::os::atomic::Assign_And(u16, 0xFF00) == 0x0);
                CHECK(u16 == 0x0);
            }
            TEST_CASE("u32_t")
            {
                u32_t u32 = 0x0000FFFF;
                CHECK(nkr::os::atomic::Assign_And(u32, 0xFFFF0000) == 0x0);
                CHECK(u32 == 0x0);
            }
            TEST_CASE("u64_t")
            {
            #if defined(nkr_IS_64_BIT)
                u64_t u64 = 0x00000000FFFFFFFF;
                CHECK(nkr::os::atomic::Assign_And(u64, 0xFFFFFFFF00000000) == 0x0);
                CHECK(u64 == 0x0);
            #endif
            }
            TEST_CASE("s8_t")
            {
                s8_t s8 = 0x0F;
                CHECK(nkr::os::atomic::Assign_And(s8, 0x70) == 0x0);
                CHECK(s8 == 0x0);
            }
            TEST_CASE("s16_t")
            {
                s16_t s16 = 0x00FF;
                CHECK(nkr::os::atomic::Assign_And(s16, 0x7F00) == 0x0);
                CHECK(s16 == 0x0);
            }
            TEST_CASE("s32_t")
            {
                s32_t s32 = 0x0000FFFF;
                CHECK(nkr::os::atomic::Assign_And(s32, 0x7FFF0000) == 0x0);
                CHECK(s32 == 0x0);
            }
            TEST_CASE("s64_t")
            {
            #if defined(nkr_IS_64_BIT)
                s64_t s64 = 0x00000000FFFFFFFF;
                CHECK(nkr::os::atomic::Assign_And(s64, 0x7FFFFFFF00000000) == 0x0);
                CHECK(s64 == 0x0);
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
                u8_t u8 = 0xFF;
                CHECK(nkr::os::atomic::Assign_Xor(u8, 0x01) == 0xFE);
                CHECK(u8 == 0xFE);
            }
            TEST_CASE("u16_t")
            {
                u16_t u16 = 0xFFFF;
                CHECK(nkr::os::atomic::Assign_Xor(u16, 0x0001) == 0xFFFE);
                CHECK(u16 == 0xFFFE);
            }
            TEST_CASE("u32_t")
            {
                u32_t u32 = 0xFFFFFFFF;
                CHECK(nkr::os::atomic::Assign_Xor(u32, 0x00000001) == 0xFFFFFFFE);
                CHECK(u32 == 0xFFFFFFFE);
            }
            TEST_CASE("u64_t")
            {
            #if defined(nkr_IS_64_BIT)
                u64_t u64 = 0xFFFFFFFFFFFFFFFF;
                CHECK(nkr::os::atomic::Assign_Xor(u64, 0x0000000000000001) == 0xFFFFFFFFFFFFFFFE);
                CHECK(u64 == 0xFFFFFFFFFFFFFFFE);
            #endif
            }
            TEST_CASE("s8_t")
            {
                s8_t s8 = 0x7F;
                CHECK(nkr::os::atomic::Assign_Xor(s8, 0x01) == 0x7E);
                CHECK(s8 == 0x7E);
            }
            TEST_CASE("s16_t")
            {
                s16_t s16 = 0x7FFF;
                CHECK(nkr::os::atomic::Assign_Xor(s16, 0x0001) == 0x7FFE);
                CHECK(s16 == 0x7FFE);
            }
            TEST_CASE("s32_t")
            {
                s32_t s32 = 0x7FFFFFFF;
                CHECK(nkr::os::atomic::Assign_Xor(s32, 0x00000001) == 0x7FFFFFFE);
                CHECK(s32 == 0x7FFFFFFE);
            }
            TEST_CASE("s64_t")
            {
            #if defined(nkr_IS_64_BIT)
                s64_t s64 = 0x7FFFFFFFFFFFFFFF;
                CHECK(nkr::os::atomic::Assign_Xor(s64, 0x0000000000000001) == 0x7FFFFFFFFFFFFFFE);
                CHECK(s64 == 0x7FFFFFFFFFFFFFFE);
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
                u8_t u8 = 0x0F;
                CHECK(nkr::os::atomic::Assign_Left_Shift(u8, 4) == 0xF0);
                CHECK(nkr::os::atomic::Access(u8) == 0xF0);
            }
            TEST_CASE("u16_t")
            {
                u16_t u16 = 0x00FF;
                CHECK(nkr::os::atomic::Assign_Left_Shift(u16, 8) == 0xFF00);
                CHECK(nkr::os::atomic::Access(u16) == 0xFF00);
            }
            TEST_CASE("u32_t")
            {
                u32_t u32 = 0x0000FFFF;
                CHECK(nkr::os::atomic::Assign_Left_Shift(u32, 16) == 0xFFFF0000);
                CHECK(nkr::os::atomic::Access(u32) == 0xFFFF0000);
            }
            TEST_CASE("u64_t")
            {
            #if defined(nkr_IS_64_BIT)
                u64_t u64 = 0x00000000FFFFFFFF;
                CHECK(nkr::os::atomic::Assign_Left_Shift(u64, 32) == 0xFFFFFFFF00000000);
                CHECK(nkr::os::atomic::Access(u64) == 0xFFFFFFFF00000000);
            #endif
            }
            TEST_CASE("s8_t")
            {
                s8_t s8 = 0x07;
                CHECK(nkr::os::atomic::Assign_Left_Shift(s8, 4) == 0x70);
                CHECK(nkr::os::atomic::Access(s8) == 0x70);
            }
            TEST_CASE("s16_t")
            {
                s16_t s16 = 0x007F;
                CHECK(nkr::os::atomic::Assign_Left_Shift(s16, 8) == 0x7F00);
                CHECK(nkr::os::atomic::Access(s16) == 0x7F00);
            }
            TEST_CASE("s32_t")
            {
                s32_t s32 = 0x00007FFF;
                CHECK(nkr::os::atomic::Assign_Left_Shift(s32, 16) == 0x7FFF0000);
                CHECK(nkr::os::atomic::Access(s32) == 0x7FFF0000);
            }
            TEST_CASE("s64_t")
            {
            #if defined(nkr_IS_64_BIT)
                s64_t s64 = 0x000000007FFFFFFF;
                CHECK(nkr::os::atomic::Assign_Left_Shift(s64, 32) == 0x7FFFFFFF00000000);
                CHECK(nkr::os::atomic::Access(s64) == 0x7FFFFFFF00000000);
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
                u8_t u8 = 0xF0;
                CHECK(nkr::os::atomic::Assign_Right_Shift(u8, 4) == 0x0F);
                CHECK(nkr::os::atomic::Access(u8) == 0x0F);
            }
            TEST_CASE("u16_t")
            {
                u16_t u16 = 0xFF00;
                CHECK(nkr::os::atomic::Assign_Right_Shift(u16, 8) == 0x00FF);
                CHECK(nkr::os::atomic::Access(u16) == 0x00FF);
            }
            TEST_CASE("u32_t")
            {
                u32_t u32 = 0xFFFF0000;
                CHECK(nkr::os::atomic::Assign_Right_Shift(u32, 16) == 0x0000FFFF);
                CHECK(nkr::os::atomic::Access(u32) == 0x0000FFFF);
            }
            TEST_CASE("u64_t")
            {
            #if defined(nkr_IS_64_BIT)
                u64_t u64 = 0xFFFFFFFF00000000;
                CHECK(nkr::os::atomic::Assign_Right_Shift(u64, 32) == 0x00000000FFFFFFFF);
                CHECK(nkr::os::atomic::Access(u64) == 0x00000000FFFFFFFF);
            #endif
            }
            TEST_CASE("s8_t")
            {
                s8_t s8 = 0x70;
                CHECK(nkr::os::atomic::Assign_Right_Shift(s8, 4) == 0x07);
                CHECK(nkr::os::atomic::Access(s8) == 0x07);
            }
            TEST_CASE("s16_t")
            {
                s16_t s16 = 0x7F00;
                CHECK(nkr::os::atomic::Assign_Right_Shift(s16, 8) == 0x007F);
                CHECK(nkr::os::atomic::Access(s16) == 0x007F);
            }
            TEST_CASE("s32_t")
            {
                s32_t s32 = 0x7FFF0000;
                CHECK(nkr::os::atomic::Assign_Right_Shift(s32, 16) == 0x00007FFF);
                CHECK(nkr::os::atomic::Access(s32) == 0x00007FFF);
            }
            TEST_CASE("s64_t")
            {
            #if defined(nkr_IS_64_BIT)
                s64_t s64 = 0x7FFFFFFF00000000;
                CHECK(nkr::os::atomic::Assign_Right_Shift(s64, 32) == 0x000000007FFFFFFF);
                CHECK(nkr::os::atomic::Access(s64) == 0x000000007FFFFFFF);
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
                bool_t boolean = false;
                CHECK(nkr::os::atomic::Exchange(boolean, true) == false);
                CHECK(nkr::os::atomic::Access(boolean) == true);
            }
            TEST_CASE("std_bool_t")
            {
                std_bool_t boolean = false;
                CHECK(nkr::os::atomic::Exchange(boolean, true) == false);
                CHECK(nkr::os::atomic::Access(boolean) == true);
            }
            TEST_CASE("u8_t")
            {
                u8_t u8 = 8;
                CHECK(nkr::os::atomic::Exchange(u8, 1) == 8);
                CHECK(nkr::os::atomic::Access(u8) == 1);
            }
            TEST_CASE("u16_t")
            {
                u16_t u16 = 16;
                CHECK(nkr::os::atomic::Exchange(u16, 1) == 16);
                CHECK(nkr::os::atomic::Access(u16) == 1);
            }
            TEST_CASE("u32_t")
            {
                u32_t u32 = 32;
                CHECK(nkr::os::atomic::Exchange(u32, 1) == 32);
                CHECK(nkr::os::atomic::Access(u32) == 1);
            }
            TEST_CASE("u64_t")
            {
            #if defined(nkr_IS_64_BIT)
                u64_t u64 = 64;
                CHECK(nkr::os::atomic::Exchange(u64, 1) == 64);
                CHECK(nkr::os::atomic::Access(u64) == 1);
            #endif
            }
            TEST_CASE("s8_t")
            {
                s8_t s8 = -8;
                CHECK(nkr::os::atomic::Exchange(s8, -1) == -8);
                CHECK(nkr::os::atomic::Access(s8) == -1);
            }
            TEST_CASE("s16_t")
            {
                s16_t s16 = -16;
                CHECK(nkr::os::atomic::Exchange(s16, -1) == -16);
                CHECK(nkr::os::atomic::Access(s16) == -1);
            }
            TEST_CASE("s32_t")
            {
                s32_t s32 = -32;
                CHECK(nkr::os::atomic::Exchange(s32, -1) == -32);
                CHECK(nkr::os::atomic::Access(s32) == -1);
            }
            TEST_CASE("s64_t")
            {
            #if defined(nkr_IS_64_BIT)
                s64_t s64 = -64;
                CHECK(nkr::os::atomic::Exchange(s64, -1) == -64);
                CHECK(nkr::os::atomic::Access(s64) == -1);
            #endif
            }
            TEST_CASE("f32_t")
            {
                f32_t f32 = 3.2f;
                CHECK(nkr::os::atomic::Exchange(f32, -3.2f) == 3.2f);
                CHECK(nkr::os::atomic::Access(f32) == -3.2f);
            }
            TEST_CASE("f64_t")
            {
            #if defined(nkr_IS_64_BIT)
                f64_t f64 = 6.4;
                CHECK(nkr::os::atomic::Exchange(f64, -6.4) == 6.4);
                CHECK(nkr::os::atomic::Access(f64) == -6.4);
            #endif
            }
            TEST_CASE("void_t*")
            {
                bool_t boolean = false;
                void_t* void_pointer = nullptr;
                CHECK(nkr::os::atomic::Exchange(void_pointer, &boolean) == nullptr);
                CHECK(nkr::os::atomic::Access(void_pointer) == &boolean);
            }
            TEST_CASE("bool_t*")
            {
                bool_t boolean = false;
                bool_t* boolean_pointer = &boolean;
                CHECK(nkr::os::atomic::Exchange(boolean_pointer, nullptr) == &boolean);
                CHECK(nkr::os::atomic::Access(boolean_pointer) == nullptr);
            }
        }
    }

    TEST_SUITE("Exchange_Add")
    {
        TEST_SUITE("should atomically add to integers and pointers and return the initial value")
        {
            TEST_CASE("u8_t")
            {
                u8_t u8 = 8;
                CHECK(nkr::os::atomic::Exchange_Add(u8, 1) == 8);
                CHECK(nkr::os::atomic::Access(u8) == 9);
            }
            TEST_CASE("u16_t")
            {
                u16_t u16 = 16;
                CHECK(nkr::os::atomic::Exchange_Add(u16, 1) == 16);
                CHECK(nkr::os::atomic::Access(u16) == 17);
            }
            TEST_CASE("u32_t")
            {
                u32_t u32 = 32;
                CHECK(nkr::os::atomic::Exchange_Add(u32, 1) == 32);
                CHECK(nkr::os::atomic::Access(u32) == 33);
            }
            TEST_CASE("u64_t")
            {
            #if defined(nkr_IS_64_BIT)
                u64_t u64 = 64;
                CHECK(nkr::os::atomic::Exchange_Add(u64, 1) == 64);
                CHECK(nkr::os::atomic::Access(u64) == 65);
            #endif
            }
            TEST_CASE("s8_t")
            {
                s8_t s8 = -8;
                CHECK(nkr::os::atomic::Exchange_Add(s8, -1) == -8);
                CHECK(nkr::os::atomic::Access(s8) == -9);
            }
            TEST_CASE("s16_t")
            {
                s16_t s16 = -16;
                CHECK(nkr::os::atomic::Exchange_Add(s16, -1) == -16);
                CHECK(nkr::os::atomic::Access(s16) == -17);
            }
            TEST_CASE("s32_t")
            {
                s32_t s32 = -32;
                CHECK(nkr::os::atomic::Exchange_Add(s32, -1) == -32);
                CHECK(nkr::os::atomic::Access(s32) == -33);
            }
            TEST_CASE("s64_t")
            {
            #if defined(nkr_IS_64_BIT)
                s64_t s64 = -64;
                CHECK(nkr::os::atomic::Exchange_Add(s64, -1) == -64);
                CHECK(nkr::os::atomic::Access(s64) == -65);
            #endif
            }
            TEST_CASE("f32_t")
            {
                f32_t f32 = 3.2f;
                CHECK(nkr::os::atomic::Exchange_Add(f32, 0.1f) == 3.2f);
                CHECK(nkr::os::atomic::Access(f32) == 3.2f + 0.1f);
            }
            TEST_CASE("f64_t")
            {
            #if defined(nkr_IS_64_BIT)
                f64_t f64 = 6.4;
                CHECK(nkr::os::atomic::Exchange_Add(f64, 0.1) == 6.4);
                CHECK(nkr::os::atomic::Access(f64) == 6.4 + 0.1);
            #endif
            }
            TEST_CASE("bool_t*")
            {
                bool_t booleans[2] = { true, true };
                bool_t* boolean_pointer = booleans;
                CHECK(nkr::os::atomic::Exchange_Add(boolean_pointer, 1) == booleans + 0);
                CHECK(nkr::os::atomic::Access(boolean_pointer) == booleans + 1);
                CHECK(nkr::os::atomic::Exchange_Add(boolean_pointer, -1) == booleans + 1);
                CHECK(nkr::os::atomic::Access(boolean_pointer) == booleans + 0);
            }
        }
    }

    TEST_SUITE("Exchange_Subtract")
    {
        TEST_SUITE("should atomically subtract from integers and pointers and return the initial value")
        {
            TEST_CASE("u8_t")
            {
                u8_t u8 = 8;
                CHECK(nkr::os::atomic::Exchange_Subtract(u8, 1) == 8);
                CHECK(nkr::os::atomic::Access(u8) == 7);
            }
            TEST_CASE("u16_t")
            {
                u16_t u16 = 16;
                CHECK(nkr::os::atomic::Exchange_Subtract(u16, 1) == 16);
                CHECK(nkr::os::atomic::Access(u16) == 15);
            }
            TEST_CASE("u32_t")
            {
                u32_t u32 = 32;
                CHECK(nkr::os::atomic::Exchange_Subtract(u32, 1) == 32);
                CHECK(nkr::os::atomic::Access(u32) == 31);
            }
            TEST_CASE("u64_t")
            {
            #if defined(nkr_IS_64_BIT)
                u64_t u64 = 64;
                CHECK(nkr::os::atomic::Exchange_Subtract(u64, 1) == 64);
                CHECK(nkr::os::atomic::Access(u64) == 63);
            #endif
            }
            TEST_CASE("s8_t")
            {
                s8_t s8 = -8;
                CHECK(nkr::os::atomic::Exchange_Subtract(s8, -1) == -8);
                CHECK(nkr::os::atomic::Access(s8) == -7);
            }
            TEST_CASE("s16_t")
            {
                s16_t s16 = -16;
                CHECK(nkr::os::atomic::Exchange_Subtract(s16, -1) == -16);
                CHECK(nkr::os::atomic::Access(s16) == -15);
            }
            TEST_CASE("s32_t")
            {
                s32_t s32 = -32;
                CHECK(nkr::os::atomic::Exchange_Subtract(s32, -1) == -32);
                CHECK(nkr::os::atomic::Access(s32) == -31);
            }
            TEST_CASE("s64_t")
            {
            #if defined(nkr_IS_64_BIT)
                s64_t s64 = -64;
                CHECK(nkr::os::atomic::Exchange_Subtract(s64, -1) == -64);
                CHECK(nkr::os::atomic::Access(s64) == -63);
            #endif
            }
            TEST_CASE("f32_t")
            {
                f32_t f32 = 3.2f;
                CHECK(nkr::os::atomic::Exchange_Subtract(f32, 0.1f) == 3.2f);
                CHECK(nkr::os::atomic::Access(f32) == 3.2f - 0.1f);
            }
            TEST_CASE("f64_t")
            {
            #if defined(nkr_IS_64_BIT)
                f64_t f64 = 6.4;
                CHECK(nkr::os::atomic::Exchange_Subtract(f64, 0.1) == 6.4);
                CHECK(nkr::os::atomic::Access(f64) == 6.4 - 0.1);
            #endif
            }
            TEST_CASE("bool_t*")
            {
                bool_t booleans[2] = { true, true };
                bool_t* boolean_pointer = booleans + 1;
                CHECK(nkr::os::atomic::Exchange_Subtract(boolean_pointer, 1) == booleans + 1);
                CHECK(nkr::os::atomic::Access(boolean_pointer) == booleans + 0);
                CHECK(nkr::os::atomic::Exchange_Subtract(boolean_pointer, -1) == booleans + 0);
                CHECK(nkr::os::atomic::Access(boolean_pointer) == booleans + 1);
            }
        }
    }

    TEST_SUITE("Exchange_Multiply()")
    {
        TEST_SUITE("should multiply its value with the operand and return the initial value")
        {
            TEST_CASE("u8_t")
            {
                u8_t u8 = 8;
                CHECK(nkr::os::atomic::Exchange_Multiply(u8, 2) == 8);
                CHECK(nkr::os::atomic::Access(u8) == 16);
            }
            TEST_CASE("u16_t")
            {
                u16_t u16 = 16;
                CHECK(nkr::os::atomic::Exchange_Multiply(u16, 2) == 16);
                CHECK(nkr::os::atomic::Access(u16) == 32);
            }
            TEST_CASE("u32_t")
            {
                u32_t u32 = 32;
                CHECK(nkr::os::atomic::Exchange_Multiply(u32, 2) == 32);
                CHECK(nkr::os::atomic::Access(u32) == 64);
            }
            TEST_CASE("u64_t")
            {
            #if defined(nkr_IS_64_BIT)
                u64_t u64 = 64;
                CHECK(nkr::os::atomic::Exchange_Multiply(u64, 2) == 64);
                CHECK(nkr::os::atomic::Access(u64) == 128);
            #endif
            }
            TEST_CASE("s8_t")
            {
                s8_t s8 = -8;
                CHECK(nkr::os::atomic::Exchange_Multiply(s8, 2) == -8);
                CHECK(nkr::os::atomic::Access(s8) == -16);
            }
            TEST_CASE("s16_t")
            {
                s16_t s16 = -16;
                CHECK(nkr::os::atomic::Exchange_Multiply(s16, 2) == -16);
                CHECK(nkr::os::atomic::Access(s16) == -32);
            }
            TEST_CASE("s32_t")
            {
                s32_t s32 = -32;
                CHECK(nkr::os::atomic::Exchange_Multiply(s32, 2) == -32);
                CHECK(nkr::os::atomic::Access(s32) == -64);
            }
            TEST_CASE("s64_t")
            {
            #if defined(nkr_IS_64_BIT)
                s64_t s64 = -64;
                CHECK(nkr::os::atomic::Exchange_Multiply(s64, 2) == -64);
                CHECK(nkr::os::atomic::Access(s64) == -128);
            #endif
            }
            TEST_CASE("f32_t")
            {
                f32_t f32 = 3.2f;
                CHECK(nkr::os::atomic::Exchange_Multiply(f32, 0.1f) == 3.2f);
                CHECK(nkr::os::atomic::Access(f32) == 3.2f * 0.1f);
            }
            TEST_CASE("f64_t")
            {
            #if defined(nkr_IS_64_BIT)
                f64_t f64 = 6.4;
                CHECK(nkr::os::atomic::Exchange_Multiply(f64, 0.1) == 6.4);
                CHECK(nkr::os::atomic::Access(f64) == 6.4 * 0.1);
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
                u8_t u8 = 8;
                CHECK(nkr::os::atomic::Exchange_Divide(u8, 2) == 8);
                CHECK(nkr::os::atomic::Access(u8) == 4);
            }
            TEST_CASE("u16_t")
            {
                u16_t u16 = 16;
                CHECK(nkr::os::atomic::Exchange_Divide(u16, 2) == 16);
                CHECK(nkr::os::atomic::Access(u16) == 8);
            }
            TEST_CASE("u32_t")
            {
                u32_t u32 = 32;
                CHECK(nkr::os::atomic::Exchange_Divide(u32, 2) == 32);
                CHECK(nkr::os::atomic::Access(u32) == 16);
            }
            TEST_CASE("u64_t")
            {
            #if defined(nkr_IS_64_BIT)
                u64_t u64 = 64;
                CHECK(nkr::os::atomic::Exchange_Divide(u64, 2) == 64);
                CHECK(nkr::os::atomic::Access(u64) == 32);
            #endif
            }
            TEST_CASE("s8_t")
            {
                s8_t s8 = -8;
                CHECK(nkr::os::atomic::Exchange_Divide(s8, 2) == -8);
                CHECK(nkr::os::atomic::Access(s8) == -4);
            }
            TEST_CASE("s16_t")
            {
                s16_t s16 = -16;
                CHECK(nkr::os::atomic::Exchange_Divide(s16, 2) == -16);
                CHECK(nkr::os::atomic::Access(s16) == -8);
            }
            TEST_CASE("s32_t")
            {
                s32_t s32 = -32;
                CHECK(nkr::os::atomic::Exchange_Divide(s32, 2) == -32);
                CHECK(nkr::os::atomic::Access(s32) == -16);
            }
            TEST_CASE("s64_t")
            {
            #if defined(nkr_IS_64_BIT)
                s64_t s64 = -64;
                CHECK(nkr::os::atomic::Exchange_Divide(s64, 2) == -64);
                CHECK(nkr::os::atomic::Access(s64) == -32);
            #endif
            }
            TEST_CASE("f32_t")
            {
                f32_t f32 = 3.2f;
                CHECK(nkr::os::atomic::Exchange_Divide(f32, 0.1f) == 3.2f);
                CHECK(nkr::os::atomic::Access(f32) == 3.2f / 0.1f);
            }
            TEST_CASE("f64_t")
            {
            #if defined(nkr_IS_64_BIT)
                f64_t f64 = 6.4;
                CHECK(nkr::os::atomic::Exchange_Divide(f64, 0.1) == 6.4);
                CHECK(nkr::os::atomic::Access(f64) == 6.4 / 0.1);
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
                u8_t u8 = 8;
                CHECK(nkr::os::atomic::Exchange_Modulus(u8, 3) == 8);
                CHECK(nkr::os::atomic::Access(u8) == 2);
            }
            TEST_CASE("u16_t")
            {
                u16_t u16 = 16;
                CHECK(nkr::os::atomic::Exchange_Modulus(u16, 3) == 16);
                CHECK(nkr::os::atomic::Access(u16) == 1);
            }
            TEST_CASE("u32_t")
            {
                u32_t u32 = 32;
                CHECK(nkr::os::atomic::Exchange_Modulus(u32, 3) == 32);
                CHECK(nkr::os::atomic::Access(u32) == 2);
            }
            TEST_CASE("u64_t")
            {
            #if defined(nkr_IS_64_BIT)
                u64_t u64 = 64;
                CHECK(nkr::os::atomic::Exchange_Modulus(u64, 3) == 64);
                CHECK(nkr::os::atomic::Access(u64) == 1);
            #endif
            }
            TEST_CASE("s8_t")
            {
                s8_t s8 = -8;
                CHECK(nkr::os::atomic::Exchange_Modulus(s8, 3) == -8);
                CHECK(nkr::os::atomic::Access(s8) == -2);
            }
            TEST_CASE("s16_t")
            {
                s16_t s16 = -16;
                CHECK(nkr::os::atomic::Exchange_Modulus(s16, 3) == -16);
                CHECK(nkr::os::atomic::Access(s16) == -1);
            }
            TEST_CASE("s32_t")
            {
                s32_t s32 = -32;
                CHECK(nkr::os::atomic::Exchange_Modulus(s32, 3) == -32);
                CHECK(nkr::os::atomic::Access(s32) == -2);
            }
            TEST_CASE("s64_t")
            {
            #if defined(nkr_IS_64_BIT)
                s64_t s64 = -64;
                CHECK(nkr::os::atomic::Exchange_Modulus(s64, 3) == -64);
                CHECK(nkr::os::atomic::Access(s64) == -1);
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
                u8_t u8 = 0x0F;
                CHECK(nkr::os::atomic::Exchange_Or(u8, 0xF0) == 0x0F);
                CHECK(nkr::os::atomic::Access(u8) == 0xFF);
            }
            TEST_CASE("u16_t")
            {
                u16_t u16 = 0x00FF;
                CHECK(nkr::os::atomic::Exchange_Or(u16, 0xFF00) == 0x00FF);
                CHECK(nkr::os::atomic::Access(u16) == 0xFFFF);
            }
            TEST_CASE("u32_t")
            {
                u32_t u32 = 0x0000FFFF;
                CHECK(nkr::os::atomic::Exchange_Or(u32, 0xFFFF0000) == 0x0000FFFF);
                CHECK(nkr::os::atomic::Access(u32) == 0xFFFFFFFF);
            }
            TEST_CASE("u64_t")
            {
            #if defined(nkr_IS_64_BIT)
                u64_t u64 = 0x00000000FFFFFFFF;
                CHECK(nkr::os::atomic::Exchange_Or(u64, 0xFFFFFFFF00000000) == 0x00000000FFFFFFFF);
                CHECK(nkr::os::atomic::Access(u64) == 0xFFFFFFFFFFFFFFFF);
            #endif
            }
            TEST_CASE("s8_t")
            {
                s8_t s8 = 0x0F;
                CHECK(nkr::os::atomic::Exchange_Or(s8, 0x70) == 0x0F);
                CHECK(nkr::os::atomic::Access(s8) == 0x7F);
            }
            TEST_CASE("s16_t")
            {
                s16_t s16 = 0x00FF;
                CHECK(nkr::os::atomic::Exchange_Or(s16, 0x7F00) == 0x00FF);
                CHECK(nkr::os::atomic::Access(s16) == 0x7FFF);
            }
            TEST_CASE("s32_t")
            {
                s32_t s32 = 0x0000FFFF;
                CHECK(nkr::os::atomic::Exchange_Or(s32, 0x7FFF0000) == 0x0000FFFF);
                CHECK(nkr::os::atomic::Access(s32) == 0x7FFFFFFF);
            }
            TEST_CASE("s64_t")
            {
            #if defined(nkr_IS_64_BIT)
                s64_t s64 = 0x00000000FFFFFFFF;
                CHECK(nkr::os::atomic::Exchange_Or(s64, 0x7FFFFFFF00000000) == 0x00000000FFFFFFFF);
                CHECK(nkr::os::atomic::Access(s64) == 0x7FFFFFFFFFFFFFFF);
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
                u8_t u8 = 0x0F;
                CHECK(nkr::os::atomic::Exchange_And(u8, 0xF0) == 0x0F);
                CHECK(nkr::os::atomic::Access(u8) == 0x0);
            }
            TEST_CASE("u16_t")
            {
                u16_t u16 = 0x00FF;
                CHECK(nkr::os::atomic::Exchange_And(u16, 0xFF00) == 0x00FF);
                CHECK(nkr::os::atomic::Access(u16) == 0x0);
            }
            TEST_CASE("u32_t")
            {
                u32_t u32 = 0x0000FFFF;
                CHECK(nkr::os::atomic::Exchange_And(u32, 0xFFFF0000) == 0x0000FFFF);
                CHECK(nkr::os::atomic::Access(u32) == 0x0);
            }
            TEST_CASE("u64_t")
            {
            #if defined(nkr_IS_64_BIT)
                u64_t u64 = 0x00000000FFFFFFFF;
                CHECK(nkr::os::atomic::Exchange_And(u64, 0xFFFFFFFF00000000) == 0x00000000FFFFFFFF);
                CHECK(nkr::os::atomic::Access(u64) == 0x0);
            #endif
            }
            TEST_CASE("s8_t")
            {
                s8_t s8 = 0x0F;
                CHECK(nkr::os::atomic::Exchange_And(s8, 0x70) == 0x0F);
                CHECK(nkr::os::atomic::Access(s8) == 0x0);
            }
            TEST_CASE("s16_t")
            {
                s16_t s16 = 0x00FF;
                CHECK(nkr::os::atomic::Exchange_And(s16, 0x7F00) == 0x00FF);
                CHECK(nkr::os::atomic::Access(s16) == 0x0);
            }
            TEST_CASE("s32_t")
            {
                s32_t s32 = 0x0000FFFF;
                CHECK(nkr::os::atomic::Exchange_And(s32, 0x7FFF0000) == 0x0000FFFF);
                CHECK(nkr::os::atomic::Access(s32) == 0x0);
            }
            TEST_CASE("s64_t")
            {
            #if defined(nkr_IS_64_BIT)
                s64_t s64 = 0x00000000FFFFFFFF;
                CHECK(nkr::os::atomic::Exchange_And(s64, 0x7FFFFFFF00000000) == 0x00000000FFFFFFFF);
                CHECK(nkr::os::atomic::Access(s64) == 0x0);
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
                u8_t u8 = 0xFF;
                CHECK(nkr::os::atomic::Exchange_Xor(u8, 0x01) == 0xFF);
                CHECK(nkr::os::atomic::Access(u8) == 0xFE);
            }
            TEST_CASE("u16_t")
            {
                u16_t u16 = 0xFFFF;
                CHECK(nkr::os::atomic::Exchange_Xor(u16, 0x0001) == 0xFFFF);
                CHECK(nkr::os::atomic::Access(u16) == 0xFFFE);
            }
            TEST_CASE("u32_t")
            {
                u32_t u32 = 0xFFFFFFFF;
                CHECK(nkr::os::atomic::Exchange_Xor(u32, 0x00000001) == 0xFFFFFFFF);
                CHECK(nkr::os::atomic::Access(u32) == 0xFFFFFFFE);
            }
            TEST_CASE("u64_t")
            {
            #if defined(nkr_IS_64_BIT)
                u64_t u64 = 0xFFFFFFFFFFFFFFFF;
                CHECK(nkr::os::atomic::Exchange_Xor(u64, 0x0000000000000001) == 0xFFFFFFFFFFFFFFFF);
                CHECK(nkr::os::atomic::Access(u64) == 0xFFFFFFFFFFFFFFFE);
            #endif
            }
            TEST_CASE("s8_t")
            {
                s8_t s8 = 0x7F;
                CHECK(nkr::os::atomic::Exchange_Xor(s8, 0x01) == 0x7F);
                CHECK(nkr::os::atomic::Access(s8) == 0x7E);
            }
            TEST_CASE("s16_t")
            {
                s16_t s16 = 0x7FFF;
                CHECK(nkr::os::atomic::Exchange_Xor(s16, 0x0001) == 0x7FFF);
                CHECK(nkr::os::atomic::Access(s16) == 0x7FFE);
            }
            TEST_CASE("s32_t")
            {
                s32_t s32 = 0x7FFFFFFF;
                CHECK(nkr::os::atomic::Exchange_Xor(s32, 0x00000001) == 0x7FFFFFFF);
                CHECK(nkr::os::atomic::Access(s32) == 0x7FFFFFFE);
            }
            TEST_CASE("s64_t")
            {
            #if defined(nkr_IS_64_BIT)
                s64_t s64 = 0x7FFFFFFFFFFFFFFF;
                CHECK(nkr::os::atomic::Exchange_Xor(s64, 0x0000000000000001) == 0x7FFFFFFFFFFFFFFF);
                CHECK(nkr::os::atomic::Access(s64) == 0x7FFFFFFFFFFFFFFE);
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
                u8_t u8 = 0x0F;
                CHECK(nkr::os::atomic::Exchange_Left_Shift(u8, 4) == 0x0F);
                CHECK(nkr::os::atomic::Access(u8) == 0xF0);
            }
            TEST_CASE("u16_t")
            {
                u16_t u16 = 0x00FF;
                CHECK(nkr::os::atomic::Exchange_Left_Shift(u16, 8) == 0x00FF);
                CHECK(nkr::os::atomic::Access(u16) == 0xFF00);
            }
            TEST_CASE("u32_t")
            {
                u32_t u32 = 0x0000FFFF;
                CHECK(nkr::os::atomic::Exchange_Left_Shift(u32, 16) == 0x0000FFFF);
                CHECK(nkr::os::atomic::Access(u32) == 0xFFFF0000);
            }
            TEST_CASE("u64_t")
            {
            #if defined(nkr_IS_64_BIT)
                u64_t u64 = 0x00000000FFFFFFFF;
                CHECK(nkr::os::atomic::Exchange_Left_Shift(u64, 32) == 0x00000000FFFFFFFF);
                CHECK(nkr::os::atomic::Access(u64) == 0xFFFFFFFF00000000);
            #endif
            }
            TEST_CASE("s8_t")
            {
                s8_t s8 = 0x07;
                CHECK(nkr::os::atomic::Exchange_Left_Shift(s8, 4) == 0x07);
                CHECK(nkr::os::atomic::Access(s8) == 0x70);
            }
            TEST_CASE("s16_t")
            {
                s16_t s16 = 0x007F;
                CHECK(nkr::os::atomic::Exchange_Left_Shift(s16, 8) == 0x007F);
                CHECK(nkr::os::atomic::Access(s16) == 0x7F00);
            }
            TEST_CASE("s32_t")
            {
                s32_t s32 = 0x00007FFF;
                CHECK(nkr::os::atomic::Exchange_Left_Shift(s32, 16) == 0x00007FFF);
                CHECK(nkr::os::atomic::Access(s32) == 0x7FFF0000);
            }
            TEST_CASE("s64_t")
            {
            #if defined(nkr_IS_64_BIT)
                s64_t s64 = 0x000000007FFFFFFF;
                CHECK(nkr::os::atomic::Exchange_Left_Shift(s64, 32) == 0x000000007FFFFFFF);
                CHECK(nkr::os::atomic::Access(s64) == 0x7FFFFFFF00000000);
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
                u8_t u8 = 0xF0;
                CHECK(nkr::os::atomic::Exchange_Right_Shift(u8, 4) == 0xF0);
                CHECK(nkr::os::atomic::Access(u8) == 0x0F);
            }
            TEST_CASE("u16_t")
            {
                u16_t u16 = 0xFF00;
                CHECK(nkr::os::atomic::Exchange_Right_Shift(u16, 8) == 0xFF00);
                CHECK(nkr::os::atomic::Access(u16) == 0x00FF);
            }
            TEST_CASE("u32_t")
            {
                u32_t u32 = 0xFFFF0000;
                CHECK(nkr::os::atomic::Exchange_Right_Shift(u32, 16) == 0xFFFF0000);
                CHECK(nkr::os::atomic::Access(u32) == 0x0000FFFF);
            }
            TEST_CASE("u64_t")
            {
            #if defined(nkr_IS_64_BIT)
                u64_t u64 = 0xFFFFFFFF00000000;
                CHECK(nkr::os::atomic::Exchange_Right_Shift(u64, 32) == 0xFFFFFFFF00000000);
                CHECK(nkr::os::atomic::Access(u64) == 0x00000000FFFFFFFF);
            #endif
            }
            TEST_CASE("s8_t")
            {
                s8_t s8 = 0x70;
                CHECK(nkr::os::atomic::Exchange_Right_Shift(s8, 4) == 0x70);
                CHECK(nkr::os::atomic::Access(s8) == 0x07);
            }
            TEST_CASE("s16_t")
            {
                s16_t s16 = 0x7F00;
                CHECK(nkr::os::atomic::Exchange_Right_Shift(s16, 8) == 0x7F00);
                CHECK(nkr::os::atomic::Access(s16) == 0x007F);
            }
            TEST_CASE("s32_t")
            {
                s32_t s32 = 0x7FFF0000;
                CHECK(nkr::os::atomic::Exchange_Right_Shift(s32, 16) == 0x7FFF0000);
                CHECK(nkr::os::atomic::Access(s32) == 0x00007FFF);
            }
            TEST_CASE("s64_t")
            {
            #if defined(nkr_IS_64_BIT)
                s64_t s64 = 0x7FFFFFFF00000000;
                CHECK(nkr::os::atomic::Exchange_Right_Shift(s64, 32) == 0x7FFFFFFF00000000);
                CHECK(nkr::os::atomic::Access(s64) == 0x000000007FFFFFFF);
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
                bool_t boolean = false;
                bool_t snapshot = true;

                CHECK(nkr::os::atomic::Exchange_If_Equals(boolean, snapshot, true) == false);
                CHECK(nkr::os::atomic::Access(boolean) == false);
                CHECK(snapshot == false);

                CHECK(nkr::os::atomic::Exchange_If_Equals(boolean, snapshot, true) == true);
                CHECK(nkr::os::atomic::Access(boolean) == true);
                CHECK(snapshot == false);
            }
            TEST_CASE("std_bool_t")
            {
                std_bool_t boolean = false;
                std_bool_t snapshot = true;

                CHECK(nkr::os::atomic::Exchange_If_Equals(boolean, snapshot, true) == false);
                CHECK(nkr::os::atomic::Access(boolean) == false);
                CHECK(snapshot == false);

                CHECK(nkr::os::atomic::Exchange_If_Equals(boolean, snapshot, true) == true);
                CHECK(nkr::os::atomic::Access(boolean) == true);
                CHECK(snapshot == false);
            }
            TEST_CASE("u8_t")
            {
                u8_t u8 = 8;
                u8_t snapshot = 1;

                CHECK(nkr::os::atomic::Exchange_If_Equals(u8, snapshot, 1) == false);
                CHECK(nkr::os::atomic::Access(u8) == 8);
                CHECK(snapshot == 8);

                CHECK(nkr::os::atomic::Exchange_If_Equals(u8, snapshot, 1) == true);
                CHECK(nkr::os::atomic::Access(u8) == 1);
                CHECK(snapshot == 8);
            }
            TEST_CASE("u16_t")
            {
                u16_t u16 = 16;
                u16_t snapshot = 1;

                CHECK(nkr::os::atomic::Exchange_If_Equals(u16, snapshot, 1) == false);
                CHECK(nkr::os::atomic::Access(u16) == 16);
                CHECK(snapshot == 16);

                CHECK(nkr::os::atomic::Exchange_If_Equals(u16, snapshot, 1) == true);
                CHECK(nkr::os::atomic::Access(u16) == 1);
                CHECK(snapshot == 16);
            }
            TEST_CASE("u32_t")
            {
                u32_t u32 = 32;
                u32_t snapshot = 1;

                CHECK(nkr::os::atomic::Exchange_If_Equals(u32, snapshot, 1) == false);
                CHECK(nkr::os::atomic::Access(u32) == 32);
                CHECK(snapshot == 32);

                CHECK(nkr::os::atomic::Exchange_If_Equals(u32, snapshot, 1) == true);
                CHECK(nkr::os::atomic::Access(u32) == 1);
                CHECK(snapshot == 32);
            }
            TEST_CASE("u64_t")
            {
            #if defined(nkr_IS_64_BIT)
                u64_t u64 = 64;
                u64_t snapshot = 1;

                CHECK(nkr::os::atomic::Exchange_If_Equals(u64, snapshot, 1) == false);
                CHECK(nkr::os::atomic::Access(u64) == 64);
                CHECK(snapshot == 64);

                CHECK(nkr::os::atomic::Exchange_If_Equals(u64, snapshot, 1) == true);
                CHECK(nkr::os::atomic::Access(u64) == 1);
                CHECK(snapshot == 64);
            #endif
            }
            TEST_CASE("s8_t")
            {
                s8_t s8 = -8;
                s8_t snapshot = -1;

                CHECK(nkr::os::atomic::Exchange_If_Equals(s8, snapshot, -1) == false);
                CHECK(nkr::os::atomic::Access(s8) == -8);
                CHECK(snapshot == -8);

                CHECK(nkr::os::atomic::Exchange_If_Equals(s8, snapshot, -1) == true);
                CHECK(nkr::os::atomic::Access(s8) == -1);
                CHECK(snapshot == -8);
            }
            TEST_CASE("s16_t")
            {
                s16_t s16 = -16;
                s16_t snapshot = -1;

                CHECK(nkr::os::atomic::Exchange_If_Equals(s16, snapshot, -1) == false);
                CHECK(nkr::os::atomic::Access(s16) == -16);
                CHECK(snapshot == -16);

                CHECK(nkr::os::atomic::Exchange_If_Equals(s16, snapshot, -1) == true);
                CHECK(nkr::os::atomic::Access(s16) == -1);
                CHECK(snapshot == -16);
            }
            TEST_CASE("s32_t")
            {
                s32_t s32 = -32;
                s32_t snapshot = -1;

                CHECK(nkr::os::atomic::Exchange_If_Equals(s32, snapshot, -1) == false);
                CHECK(nkr::os::atomic::Access(s32) == -32);
                CHECK(snapshot == -32);

                CHECK(nkr::os::atomic::Exchange_If_Equals(s32, snapshot, -1) == true);
                CHECK(nkr::os::atomic::Access(s32) == -1);
                CHECK(snapshot == -32);
            }
            TEST_CASE("s64_t")
            {
            #if defined(nkr_IS_64_BIT)
                s64_t s64 = -64;
                s64_t snapshot = -1;

                CHECK(nkr::os::atomic::Exchange_If_Equals(s64, snapshot, -1) == false);
                CHECK(nkr::os::atomic::Access(s64) == -64);
                CHECK(snapshot == -64);

                CHECK(nkr::os::atomic::Exchange_If_Equals(s64, snapshot, -1) == true);
                CHECK(nkr::os::atomic::Access(s64) == -1);
                CHECK(snapshot == -64);
            #endif
            }
            TEST_CASE("f32_t")
            {
                f32_t f32 = 3.2f;
                f32_t snapshot = 1.0f;

                CHECK(nkr::os::atomic::Exchange_If_Equals(f32, snapshot, 1.0f) == false);
                CHECK(nkr::os::atomic::Access(f32) == 3.2f);
                CHECK(snapshot == 3.2f);

                CHECK(nkr::os::atomic::Exchange_If_Equals(f32, snapshot, 1.0f) == true);
                CHECK(nkr::os::atomic::Access(f32) == 1.0f);
                CHECK(snapshot == 3.2f);
            }
            TEST_CASE("f64_t")
            {
            #if defined(nkr_IS_64_BIT)
                f64_t f64 = 6.4;
                f64_t snapshot = 1.0;

                CHECK(nkr::os::atomic::Exchange_If_Equals(f64, snapshot, 1.0) == false);
                CHECK(nkr::os::atomic::Access(f64) == 6.4);
                CHECK(snapshot == 6.4);

                CHECK(nkr::os::atomic::Exchange_If_Equals(f64, snapshot, 1.0) == true);
                CHECK(nkr::os::atomic::Access(f64) == 1.0);
                CHECK(snapshot == 6.4);
            #endif
            }
            TEST_CASE("void_t*")
            {
                bool_t boolean;
                void_t* void_pointer = nullptr;
                void_t* snapshot = &boolean;

                CHECK(nkr::os::atomic::Exchange_If_Equals(void_pointer, snapshot, &boolean) == false);
                CHECK(nkr::os::atomic::Access(void_pointer) == nullptr);
                CHECK(snapshot == nullptr);

                CHECK(nkr::os::atomic::Exchange_If_Equals(void_pointer, snapshot, &boolean) == true);
                CHECK(nkr::os::atomic::Access(void_pointer) == &boolean);
                CHECK(snapshot == nullptr);
            }
            TEST_CASE("bool_t*")
            {
                bool_t boolean;
                bool_t* boolean_pointer = nullptr;
                bool_t* snapshot = &boolean;

                CHECK(nkr::os::atomic::Exchange_If_Equals(boolean_pointer, snapshot, &boolean) == false);
                CHECK(nkr::os::atomic::Access(boolean_pointer) == nullptr);
                CHECK(snapshot == nullptr);

                CHECK(nkr::os::atomic::Exchange_If_Equals(boolean_pointer, snapshot, &boolean) == true);
                CHECK(nkr::os::atomic::Access(boolean_pointer) == &boolean);
                CHECK(snapshot == nullptr);
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
        #if defined(nkr_IS_WINDOWS)
            CHECK(nkr::os::endian::Is_Big() == false);
        #else
            CHECK(nkr::os::endian::Is_Big() == true);
        #endif
        }
    }

    TEST_SUITE("Is_Little")
    {
        TEST_CASE("should in a thread-safe manner efficiently determine if the runtime is in little endian"
                  * doctest::may_fail(true)
                  * doctest::no_breaks(true))
        {
        #if defined(nkr_IS_WINDOWS)
            CHECK(nkr::os::endian::Is_Little() == true);
        #else
            CHECK(nkr::os::endian::Is_Little() == false);
        #endif
        }
    }

    TEST_SUITE("Swap")
    {
        TEST_SUITE("should swap the bytes of 16 bit, 32 bit, and 64 bit numbers")
        {
            TEST_CASE("u16_t")
            {
                u16_t u16 = 0x0102;
                CHECK(nkr::os::endian::Swap(u16) == 0x0201);
            }
            TEST_CASE("u32_t")
            {
                u32_t u32 = 0x01020304;
                CHECK(nkr::os::endian::Swap(u32) == 0x04030201);
            }
            TEST_CASE("u64_t")
            {
                u64_t u64 = 0x0102030405060708;
                CHECK(nkr::os::endian::Swap(u64) == 0x0807060504030201);
            }
            TEST_CASE("s16_t")
            {
                s16_t s16 = 0x0102;
                CHECK(nkr::os::endian::Swap(s16) == 0x0201);
            }
            TEST_CASE("s32_t")
            {
                s32_t s32 = 0x01020304;
                CHECK(nkr::os::endian::Swap(s32) == 0x04030201);
            }
            TEST_CASE("s64_t")
            {
                s64_t s64 = 0x0102030405060708;
                CHECK(nkr::os::endian::Swap(s64) == 0x0807060504030201);
            }
            TEST_CASE("built-in int literal")
            {
                CHECK(nkr::os::endian::Swap(0x0102) != 0x0201);
                CHECK(nkr::os::endian::Swap(0x0102) == 0x02010000);
                CHECK(nkr::os::endian::Swap(static_cast<u16_t>(0x0102)) == 0x0201);

                CHECK(nkr::os::endian::Swap(0x01020304) == 0x04030201);
                CHECK(nkr::os::endian::Swap(0x0102030405060708) == 0x0807060504030201);
            }
        }
    }

}}}

namespace nkr { namespace os { namespace heap {

    TEST_SUITE("Allocate")
    {
        TEST_CASE("should allocate heap memory, set pointer, and return true, or set nullptr and return false")
        {
            word_t* words = nullptr;
            CHECK(os::heap::Allocate(words, 0xFF));
            CHECK(words != nullptr);

            word_t* too_many = nullptr;
            CHECK(os::heap::Allocate(too_many, std::numeric_limits<count_t>::max()) == false);
            CHECK(too_many == nullptr);

            os::heap::Deallocate(words);
        }
    }

    TEST_SUITE("Reallocate")
    {
        TEST_CASE("should reallocate heap memory, set pointer, and return true, else leave pointer and return false")
        {
            word_t* words = nullptr;
            os::heap::Allocate(words, 0xFF);
            CHECK(os::heap::Reallocate(words, 0x100) == true);
            CHECK(words != nullptr);

            word_t* backup = words;
            CHECK(os::heap::Reallocate(words, std::numeric_limits<count_t>::max()) == false);
            CHECK(words == backup);

            os::heap::Deallocate(words);
        }
    }

    TEST_SUITE("Deallocate")
    {
        TEST_CASE("should deallocate heap memory and set pointer to nullptr, or if pointer is nullptr, silently fail")
        {
            word_t* words = nullptr;
            os::heap::Allocate(words, 0xFF);
            os::heap::Deallocate(words);
            CHECK(words == nullptr);

            os::heap::Deallocate(words);
            CHECK(words == nullptr);
        }
    }

    TEST_SUITE("Allocate_Zeros")
    {
        TEST_CASE("should allocate heap memory, set pointer, set memory to zero, and return true, or set nullptr and return false")
        {
            word_t* words = nullptr;
            CHECK(os::heap::Allocate_Zeros(words, 0xFF));
            CHECK(words != nullptr);
            for (index_t idx = 0, end = 0xFF; idx < end; idx += 1) {
                WARN(words[idx] == 0);
            }

            word_t* too_many = nullptr;
            CHECK(os::heap::Allocate_Zeros(too_many, std::numeric_limits<count_t>::max()) == false);
            CHECK(too_many == nullptr);

            os::heap::Deallocate_Zeros(words);
        }
    }

    TEST_SUITE("Reallocate_Zeros")
    {
        TEST_CASE("should reallocate heap memory, set pointer, set memory to zero, and return true, else leave pointer and return false")
        {
            word_t* words = nullptr;
            os::heap::Allocate_Zeros(words, 0xFF);
            CHECK(os::heap::Reallocate_Zeros(words, 0x100) == true);
            CHECK(words != nullptr);
            for (index_t idx = 0, end = 0x100; idx < end; idx += 1) {
                WARN(words[idx] == 0);
            }

            word_t* backup = words;
            CHECK(os::heap::Reallocate_Zeros(words, std::numeric_limits<count_t>::max()) == false);
            CHECK(words == backup);

            os::heap::Deallocate_Zeros(words);
        }
    }

    TEST_SUITE("Deallocate_Zeros")
    {
        TEST_CASE("should deallocate heap memory and set pointer to nullptr, or if pointer is nullptr, silently fail")
        {
            word_t* words = nullptr;
            os::heap::Allocate_Zeros(words, 0xFF);
            os::heap::Deallocate_Zeros(words);
            CHECK(words == nullptr);

            os::heap::Deallocate_Zeros(words);
            CHECK(words == nullptr);
        }
    }

}}}
