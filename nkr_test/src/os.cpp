/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include <thread>

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
        TEST_SUITE("should return added values without changing the value")
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
            TEST_CASE("bool_t*")
            {
                bool_t booleans[2] = { true, true };
                bool_t* boolean_pointer = booleans;
                CHECK(nkr::os::atomic::Access_Add(boolean_pointer, 1) == booleans + 1);
                CHECK(boolean_pointer == booleans + 0);
            }
        }
    }

    TEST_CASE("Access_Subtract")
    {
        SUBCASE("should return subtracted values without changing the old value")
        {
            u8_t u8 = 8;
            CHECK(nkr::os::atomic::Access_Subtract(u8, 1) == 7);
            CHECK(u8 == 8);

            u16_t u16 = 16;
            CHECK(nkr::os::atomic::Access_Subtract(u16, 1) == 15);
            CHECK(u16 == 16);

            u32_t u32 = 32;
            CHECK(nkr::os::atomic::Access_Subtract(u32, 1) == 31);
            CHECK(u32 == 32);

        #if defined(nkr_IS_64_BIT)
            u64_t u64 = 64;
            CHECK(nkr::os::atomic::Access_Subtract(u64, 1) == 63);
            CHECK(u64 == 64);
        #endif

            s8_t s8 = -8;
            CHECK(nkr::os::atomic::Access_Subtract(s8, -1) == -7);
            CHECK(s8 == -8);

            s16_t s16 = -16;
            CHECK(nkr::os::atomic::Access_Subtract(s16, -1) == -15);
            CHECK(s16 == -16);

            s32_t s32 = -32;
            CHECK(nkr::os::atomic::Access_Subtract(s32, -1) == -31);
            CHECK(s32 == -32);

        #if defined(nkr_IS_64_BIT)
            s64_t s64 = -64;
            CHECK(nkr::os::atomic::Access_Subtract(s64, -1) == -63);
            CHECK(s64 == -64);
        #endif

            bool_t booleans[2] = { true, true };
            bool_t* boolean_pointer = booleans + 1;
            CHECK(nkr::os::atomic::Access_Subtract(boolean_pointer, 1) == booleans + 0);
            CHECK(boolean_pointer == booleans + 1);
        }
    }

    TEST_CASE("Access_Or")
    {
        SUBCASE("should return or'd values without changing the old value")
        {
            u8_t u8 = 0x0F;
            CHECK(nkr::os::atomic::Access_Or(u8, 0xF0) == 0xFF);
            CHECK(u8 == 0x0F);

            u16_t u16 = 0x00FF;
            CHECK(nkr::os::atomic::Access_Or(u16, 0xFF00) == 0xFFFF);
            CHECK(u16 == 0x00FF);

            u32_t u32 = 0x0000FFFF;
            CHECK(nkr::os::atomic::Access_Or(u32, 0xFFFF0000) == 0xFFFFFFFF);
            CHECK(u32 == 0x0000FFFF);

        #if defined(nkr_IS_64_BIT)
            u64_t u64 = 0x00000000FFFFFFFF;
            CHECK(nkr::os::atomic::Access_Or(u64, 0xFFFFFFFF00000000) == 0xFFFFFFFFFFFFFFFF);
            CHECK(u64 == 0x00000000FFFFFFFF);
        #endif

            s8_t s8 = 0x0F;
            CHECK(nkr::os::atomic::Access_Or(s8, 0x70) == 0x7F);
            CHECK(s8 == 0x0F);

            s16_t s16 = 0x00FF;
            CHECK(nkr::os::atomic::Access_Or(s16, 0x7F00) == 0x7FFF);
            CHECK(s16 == 0x00FF);

            s32_t s32 = 0x0000FFFF;
            CHECK(nkr::os::atomic::Access_Or(s32, 0x7FFF0000) == 0x7FFFFFFF);
            CHECK(s32 == 0x0000FFFF);

        #if defined(nkr_IS_64_BIT)
            s64_t s64 = 0x00000000FFFFFFFF;
            CHECK(nkr::os::atomic::Access_Or(s64, 0x7FFFFFFF00000000) == 0x7FFFFFFFFFFFFFFF);
            CHECK(s64 == 0x00000000FFFFFFFF);
        #endif
        }
    }

    TEST_CASE("Access_And")
    {
        SUBCASE("should return and'd values without changing the old value")
        {
            u8_t u8 = 0x0F;
            CHECK(nkr::os::atomic::Access_And(u8, 0xF0) == 0x0);
            CHECK(u8 == 0x0F);

            u16_t u16 = 0x00FF;
            CHECK(nkr::os::atomic::Access_And(u16, 0xFF00) == 0x0);
            CHECK(u16 == 0x00FF);

            u32_t u32 = 0x0000FFFF;
            CHECK(nkr::os::atomic::Access_And(u32, 0xFFFF0000) == 0x0);
            CHECK(u32 == 0x0000FFFF);

        #if defined(nkr_IS_64_BIT)
            u64_t u64 = 0x00000000FFFFFFFF;
            CHECK(nkr::os::atomic::Access_And(u64, 0xFFFFFFFF00000000) == 0x0);
            CHECK(u64 == 0x00000000FFFFFFFF);
        #endif

            s8_t s8 = 0x0F;
            CHECK(nkr::os::atomic::Access_And(s8, 0x70) == 0x0);
            CHECK(s8 == 0x0F);

            s16_t s16 = 0x00FF;
            CHECK(nkr::os::atomic::Access_And(s16, 0x7F00) == 0x0);
            CHECK(s16 == 0x00FF);

            s32_t s32 = 0x0000FFFF;
            CHECK(nkr::os::atomic::Access_And(s32, 0x7FFF0000) == 0x0);
            CHECK(s32 == 0x0000FFFF);

        #if defined(nkr_IS_64_BIT)
            s64_t s64 = 0x00000000FFFFFFFF;
            CHECK(nkr::os::atomic::Access_And(s64, 0x7FFFFFFF00000000) == 0x0);
            CHECK(s64 == 0x00000000FFFFFFFF);
        #endif
        }
    }

    TEST_CASE("Access_Xor")
    {
        SUBCASE("should return xor'd values without changing the old value")
        {
            u8_t u8 = 0xFF;
            CHECK(nkr::os::atomic::Access_Xor(u8, 0x01) == 0xFE);
            CHECK(u8 == 0xFF);

            u16_t u16 = 0xFFFF;
            CHECK(nkr::os::atomic::Access_Xor(u16, 0x0001) == 0xFFFE);
            CHECK(u16 == 0xFFFF);

            u32_t u32 = 0xFFFFFFFF;
            CHECK(nkr::os::atomic::Access_Xor(u32, 0x00000001) == 0xFFFFFFFE);
            CHECK(u32 == 0xFFFFFFFF);

        #if defined(nkr_IS_64_BIT)
            u64_t u64 = 0xFFFFFFFFFFFFFFFF;
            CHECK(nkr::os::atomic::Access_Xor(u64, 0x0000000000000001) == 0xFFFFFFFFFFFFFFFE);
            CHECK(u64 == 0xFFFFFFFFFFFFFFFF);
        #endif

            s8_t s8 = 0x7F;
            CHECK(nkr::os::atomic::Access_Xor(s8, 0x01) == 0x7E);
            CHECK(s8 == 0x7F);

            s16_t s16 = 0x7FFF;
            CHECK(nkr::os::atomic::Access_Xor(s16, 0x0001) == 0x7FFE);
            CHECK(s16 == 0x7FFF);

            s32_t s32 = 0x7FFFFFFF;
            CHECK(nkr::os::atomic::Access_Xor(s32, 0x00000001) == 0x7FFFFFFE);
            CHECK(s32 == 0x7FFFFFFF);

        #if defined(nkr_IS_64_BIT)
            s64_t s64 = 0x7FFFFFFFFFFFFFFF;
            CHECK(nkr::os::atomic::Access_Xor(s64, 0x0000000000000001) == 0x7FFFFFFFFFFFFFFE);
            CHECK(s64 == 0x7FFFFFFFFFFFFFFF);
        #endif
        }
    }

    TEST_CASE("Assign")
    {
        SUBCASE("should atomically assign integers and pointers and return the new value")
        {
            bool_t boolean = false;
            CHECK(nkr::os::atomic::Assign(boolean, true) == true);

            u8_t u8 = 8;
            CHECK(nkr::os::atomic::Assign(u8, 1) == 1);

            u16_t u16 = 16;
            CHECK(nkr::os::atomic::Assign(u16, 1) == 1);

            u32_t u32 = 32;
            CHECK(nkr::os::atomic::Assign(u32, 1) == 1);

        #if defined(nkr_IS_64_BIT)
            u64_t u64 = 64;
            CHECK(nkr::os::atomic::Assign(u64, 1) == 1);
        #endif

            s8_t s8 = -8;
            CHECK(nkr::os::atomic::Assign(s8, -1) == -1);

            s16_t s16 = -16;
            CHECK(nkr::os::atomic::Assign(s16, -1) == -1);

            s32_t s32 = -32;
            CHECK(nkr::os::atomic::Assign(s32, -1) == -1);

        #if defined(nkr_IS_64_BIT)
            s64_t s64 = -64;
            CHECK(nkr::os::atomic::Assign(s64, -1) == -1);
        #endif

            void_t* void_pointer = nullptr;
            CHECK(nkr::os::atomic::Assign(void_pointer, &boolean) == &boolean);

            bool_t* boolean_pointer = &boolean;
            CHECK(nkr::os::atomic::Assign(boolean_pointer, nullptr) == nullptr);
        }
    }

    TEST_CASE("Assign_Add")
    {
        SUBCASE("should atomically add to integers and pointers and return the new value")
        {
            u8_t u8 = 8;
            CHECK(nkr::os::atomic::Assign_Add(u8, 1) == 9);

            u16_t u16 = 16;
            CHECK(nkr::os::atomic::Assign_Add(u16, 1) == 17);

            u32_t u32 = 32;
            CHECK(nkr::os::atomic::Assign_Add(u32, 1) == 33);

        #if defined(nkr_IS_64_BIT)
            u64_t u64 = 64;
            CHECK(nkr::os::atomic::Assign_Add(u64, 1) == 65);
        #endif

            s8_t s8 = -8;
            CHECK(nkr::os::atomic::Assign_Add(s8, -1) == -9);

            s16_t s16 = -16;
            CHECK(nkr::os::atomic::Assign_Add(s16, -1) == -17);

            s32_t s32 = -32;
            CHECK(nkr::os::atomic::Assign_Add(s32, -1) == -33);

        #if defined(nkr_IS_64_BIT)
            s64_t s64 = -64;
            CHECK(nkr::os::atomic::Assign_Add(s64, -1) == -65);
        #endif

            bool_t booleans[2] = { true, true };
            bool_t* boolean_pointer = booleans;
            CHECK(nkr::os::atomic::Assign_Add(boolean_pointer, 1) == booleans + 1);
            CHECK(nkr::os::atomic::Assign_Add(boolean_pointer, -1) == booleans + 0);
        }
    }

    TEST_CASE("Assign_Subtract")
    {
        SUBCASE("should atomically subtract from integers and pointers and return the new value")
        {
            u8_t u8 = 8;
            CHECK(nkr::os::atomic::Assign_Subtract(u8, 1) == 7);

            u16_t u16 = 16;
            CHECK(nkr::os::atomic::Assign_Subtract(u16, 1) == 15);

            u32_t u32 = 32;
            CHECK(nkr::os::atomic::Assign_Subtract(u32, 1) == 31);

        #if defined(nkr_IS_64_BIT)
            u64_t u64 = 64;
            CHECK(nkr::os::atomic::Assign_Subtract(u64, 1) == 63);
        #endif

            s8_t s8 = -8;
            CHECK(nkr::os::atomic::Assign_Subtract(s8, -1) == -7);

            s16_t s16 = -16;
            CHECK(nkr::os::atomic::Assign_Subtract(s16, -1) == -15);

            s32_t s32 = -32;
            CHECK(nkr::os::atomic::Assign_Subtract(s32, -1) == -31);

        #if defined(nkr_IS_64_BIT)
            s64_t s64 = -64;
            CHECK(nkr::os::atomic::Assign_Subtract(s64, -1) == -63);
        #endif

            bool_t booleans[2] = { true, true };
            bool_t* boolean_pointer = booleans + 1;
            CHECK(nkr::os::atomic::Assign_Subtract(boolean_pointer, 1) == booleans + 0);
            CHECK(nkr::os::atomic::Assign_Subtract(boolean_pointer, -1) == booleans + 1);
        }
    }

    TEST_CASE("Assign_Or")
    {
        SUBCASE("should atomically OR integers and return the new value")
        {
            u8_t u8 = 0x0F;
            CHECK(nkr::os::atomic::Assign_Or(u8, 0xF0) == 0xFF);

            u16_t u16 = 0x00FF;
            CHECK(nkr::os::atomic::Assign_Or(u16, 0xFF00) == 0xFFFF);

            u32_t u32 = 0x0000FFFF;
            CHECK(nkr::os::atomic::Assign_Or(u32, 0xFFFF0000) == 0xFFFFFFFF);

        #if defined(nkr_IS_64_BIT)
            u64_t u64 = 0x00000000FFFFFFFF;
            CHECK(nkr::os::atomic::Assign_Or(u64, 0xFFFFFFFF00000000) == 0xFFFFFFFFFFFFFFFF);
        #endif

            s8_t s8 = 0x0F;
            CHECK(nkr::os::atomic::Assign_Or(s8, 0x70) == 0x7F);

            s16_t s16 = 0x00FF;
            CHECK(nkr::os::atomic::Assign_Or(s16, 0x7F00) == 0x7FFF);

            s32_t s32 = 0x0000FFFF;
            CHECK(nkr::os::atomic::Assign_Or(s32, 0x7FFF0000) == 0x7FFFFFFF);

        #if defined(nkr_IS_64_BIT)
            s64_t s64 = 0x00000000FFFFFFFF;
            CHECK(nkr::os::atomic::Assign_Or(s64, 0x7FFFFFFF00000000) == 0x7FFFFFFFFFFFFFFF);
        #endif
        }
    }

    TEST_CASE("Assign_And")
    {
        SUBCASE("should atomically AND integers and return the new value")
        {
            u8_t u8 = 0x0F;
            CHECK(nkr::os::atomic::Assign_And(u8, 0xF0) == 0x0);

            u16_t u16 = 0x00FF;
            CHECK(nkr::os::atomic::Assign_And(u16, 0xFF00) == 0x0);

            u32_t u32 = 0x0000FFFF;
            CHECK(nkr::os::atomic::Assign_And(u32, 0xFFFF0000) == 0x0);

        #if defined(nkr_IS_64_BIT)
            u64_t u64 = 0x00000000FFFFFFFF;
            CHECK(nkr::os::atomic::Assign_And(u64, 0xFFFFFFFF00000000) == 0x0);
        #endif

            s8_t s8 = 0x0F;
            CHECK(nkr::os::atomic::Assign_And(s8, 0x70) == 0x0);

            s16_t s16 = 0x00FF;
            CHECK(nkr::os::atomic::Assign_And(s16, 0x7F00) == 0x0);

            s32_t s32 = 0x0000FFFF;
            CHECK(nkr::os::atomic::Assign_And(s32, 0x7FFF0000) == 0x0);

        #if defined(nkr_IS_64_BIT)
            s64_t s64 = 0x00000000FFFFFFFF;
            CHECK(nkr::os::atomic::Assign_And(s64, 0x7FFFFFFF00000000) == 0x0);
        #endif
        }
    }

    TEST_CASE("Assign_Xor")
    {
        SUBCASE("should atomically XOR integers and return the new value")
        {
            u8_t u8 = 0xFF;
            CHECK(nkr::os::atomic::Assign_Xor(u8, 0x01) == 0xFE);

            u16_t u16 = 0xFFFF;
            CHECK(nkr::os::atomic::Assign_Xor(u16, 0x0001) == 0xFFFE);

            u32_t u32 = 0xFFFFFFFF;
            CHECK(nkr::os::atomic::Assign_Xor(u32, 0x00000001) == 0xFFFFFFFE);

        #if defined(nkr_IS_64_BIT)
            u64_t u64 = 0xFFFFFFFFFFFFFFFF;
            CHECK(nkr::os::atomic::Assign_Xor(u64, 0x0000000000000001) == 0xFFFFFFFFFFFFFFFE);
        #endif

            s8_t s8 = 0x7F;
            CHECK(nkr::os::atomic::Assign_Xor(s8, 0x01) == 0x7E);

            s16_t s16 = 0x7FFF;
            CHECK(nkr::os::atomic::Assign_Xor(s16, 0x0001) == 0x7FFE);

            s32_t s32 = 0x7FFFFFFF;
            CHECK(nkr::os::atomic::Assign_Xor(s32, 0x00000001) == 0x7FFFFFFE);

        #if defined(nkr_IS_64_BIT)
            s64_t s64 = 0x7FFFFFFFFFFFFFFF;
            CHECK(nkr::os::atomic::Assign_Xor(s64, 0x0000000000000001) == 0x7FFFFFFFFFFFFFFE);
        #endif
        }
    }

    TEST_CASE("Exchange")
    {
        SUBCASE("should atomically assign integers and pointers and return the initial value")
        {
            bool_t boolean = false;
            CHECK(nkr::os::atomic::Exchange(boolean, true) == false);
            CHECK(nkr::os::atomic::Access(boolean) == true);

            u8_t u8 = 8;
            CHECK(nkr::os::atomic::Exchange(u8, 1) == 8);
            CHECK(nkr::os::atomic::Access(u8) == 1);

            u16_t u16 = 16;
            CHECK(nkr::os::atomic::Exchange(u16, 1) == 16);
            CHECK(nkr::os::atomic::Access(u16) == 1);

            u32_t u32 = 32;
            CHECK(nkr::os::atomic::Exchange(u32, 1) == 32);
            CHECK(nkr::os::atomic::Access(u32) == 1);

        #if defined(nkr_IS_64_BIT)
            u64_t u64 = 64;
            CHECK(nkr::os::atomic::Exchange(u64, 1) == 64);
            CHECK(nkr::os::atomic::Access(u64) == 1);
        #endif

            s8_t s8 = -8;
            CHECK(nkr::os::atomic::Exchange(s8, -1) == -8);
            CHECK(nkr::os::atomic::Access(s8) == -1);

            s16_t s16 = -16;
            CHECK(nkr::os::atomic::Exchange(s16, -1) == -16);
            CHECK(nkr::os::atomic::Access(s16) == -1);

            s32_t s32 = -32;
            CHECK(nkr::os::atomic::Exchange(s32, -1) == -32);
            CHECK(nkr::os::atomic::Access(s32) == -1);

        #if defined(nkr_IS_64_BIT)
            s64_t s64 = -64;
            CHECK(nkr::os::atomic::Exchange(s64, -1) == -64);
            CHECK(nkr::os::atomic::Access(s64) == -1);
        #endif

            void_t* void_pointer = nullptr;
            CHECK(nkr::os::atomic::Exchange(void_pointer, &boolean) == nullptr);
            CHECK(nkr::os::atomic::Access(void_pointer) == &boolean);

            bool_t* boolean_pointer = &boolean;
            CHECK(nkr::os::atomic::Exchange(boolean_pointer, nullptr) == &boolean);
            CHECK(nkr::os::atomic::Access(boolean_pointer) == nullptr);
        }
    }

    TEST_CASE("Exchange_If_Equals")
    {
        SUBCASE("should atomically assign integers and pointers if they equal target and return the initial value")
        {
            bool_t boolean = false;
            CHECK(nkr::os::atomic::Exchange_If_Equals(boolean, true, true) == false);
            CHECK(nkr::os::atomic::Access(boolean) == false);
            CHECK(nkr::os::atomic::Exchange_If_Equals(boolean, true, false) == false);
            CHECK(nkr::os::atomic::Access(boolean) == true);

            u8_t u8 = 8;
            CHECK(nkr::os::atomic::Exchange_If_Equals(u8, 1, 1) == 8);
            CHECK(nkr::os::atomic::Access(u8) == 8);
            CHECK(nkr::os::atomic::Exchange_If_Equals(u8, 1, 8) == 8);
            CHECK(nkr::os::atomic::Access(u8) == 1);

            u16_t u16 = 16;
            CHECK(nkr::os::atomic::Exchange_If_Equals(u16, 1, 1) == 16);
            CHECK(nkr::os::atomic::Access(u16) == 16);
            CHECK(nkr::os::atomic::Exchange_If_Equals(u16, 1, 16) == 16);
            CHECK(nkr::os::atomic::Access(u16) == 1);

            u32_t u32 = 32;
            CHECK(nkr::os::atomic::Exchange_If_Equals(u32, 1, 1) == 32);
            CHECK(nkr::os::atomic::Access(u32) == 32);
            CHECK(nkr::os::atomic::Exchange_If_Equals(u32, 1, 32) == 32);
            CHECK(nkr::os::atomic::Access(u32) == 1);

        #if defined(nkr_IS_64_BIT)
            u64_t u64 = 64;
            CHECK(nkr::os::atomic::Exchange_If_Equals(u64, 1, 1) == 64);
            CHECK(nkr::os::atomic::Access(u64) == 64);
            CHECK(nkr::os::atomic::Exchange_If_Equals(u64, 1, 64) == 64);
            CHECK(nkr::os::atomic::Access(u64) == 1);
        #endif

            s8_t s8 = -8;
            CHECK(nkr::os::atomic::Exchange_If_Equals(s8, -1, -1) == -8);
            CHECK(nkr::os::atomic::Access(s8) == -8);
            CHECK(nkr::os::atomic::Exchange_If_Equals(s8, -1, -8) == -8);
            CHECK(nkr::os::atomic::Access(s8) == -1);

            s16_t s16 = -16;
            CHECK(nkr::os::atomic::Exchange_If_Equals(s16, -1, -1) == -16);
            CHECK(nkr::os::atomic::Access(s16) == -16);
            CHECK(nkr::os::atomic::Exchange_If_Equals(s16, -1, -16) == -16);
            CHECK(nkr::os::atomic::Access(s16) == -1);

            s32_t s32 = -32;
            CHECK(nkr::os::atomic::Exchange_If_Equals(s32, -1, -1) == -32);
            CHECK(nkr::os::atomic::Access(s32) == -32);
            CHECK(nkr::os::atomic::Exchange_If_Equals(s32, -1, -32) == -32);
            CHECK(nkr::os::atomic::Access(s32) == -1);

        #if defined(nkr_IS_64_BIT)
            s64_t s64 = -64;
            CHECK(nkr::os::atomic::Exchange_If_Equals(s64, -1, -1) == -64);
            CHECK(nkr::os::atomic::Access(s64) == -64);
            CHECK(nkr::os::atomic::Exchange_If_Equals(s64, -1, -64) == -64);
            CHECK(nkr::os::atomic::Access(s64) == -1);
        #endif

            void_t* void_pointer = nullptr;
            CHECK(nkr::os::atomic::Exchange_If_Equals(void_pointer, &boolean, &boolean) == nullptr);
            CHECK(nkr::os::atomic::Access(void_pointer) == nullptr);
            CHECK(nkr::os::atomic::Exchange_If_Equals(void_pointer, &boolean, nullptr) == nullptr);
            CHECK(nkr::os::atomic::Access(void_pointer) == &boolean);

            bool_t* boolean_pointer = &boolean;
            CHECK(nkr::os::atomic::Exchange_If_Equals(boolean_pointer, nullptr, nullptr) == &boolean);
            CHECK(nkr::os::atomic::Access(boolean_pointer) == &boolean);
            CHECK(nkr::os::atomic::Exchange_If_Equals(boolean_pointer, nullptr, &boolean) == &boolean);
            CHECK(nkr::os::atomic::Access(boolean_pointer) == nullptr);
        }
    }

    TEST_CASE("Exchange_Add")
    {
        SUBCASE("should atomically add to integers and pointers and return the initial value")
        {
            u8_t u8 = 8;
            CHECK(nkr::os::atomic::Exchange_Add(u8, 1) == 8);
            CHECK(nkr::os::atomic::Access(u8) == 9);

            u16_t u16 = 16;
            CHECK(nkr::os::atomic::Exchange_Add(u16, 1) == 16);
            CHECK(nkr::os::atomic::Access(u16) == 17);

            u32_t u32 = 32;
            CHECK(nkr::os::atomic::Exchange_Add(u32, 1) == 32);
            CHECK(nkr::os::atomic::Access(u32) == 33);

        #if defined(nkr_IS_64_BIT)
            u64_t u64 = 64;
            CHECK(nkr::os::atomic::Exchange_Add(u64, 1) == 64);
            CHECK(nkr::os::atomic::Access(u64) == 65);
        #endif

            s8_t s8 = -8;
            CHECK(nkr::os::atomic::Exchange_Add(s8, -1) == -8);
            CHECK(nkr::os::atomic::Access(s8) == -9);

            s16_t s16 = -16;
            CHECK(nkr::os::atomic::Exchange_Add(s16, -1) == -16);
            CHECK(nkr::os::atomic::Access(s16) == -17);

            s32_t s32 = -32;
            CHECK(nkr::os::atomic::Exchange_Add(s32, -1) == -32);
            CHECK(nkr::os::atomic::Access(s32) == -33);

        #if defined(nkr_IS_64_BIT)
            s64_t s64 = -64;
            CHECK(nkr::os::atomic::Exchange_Add(s64, -1) == -64);
            CHECK(nkr::os::atomic::Access(s64) == -65);
        #endif

            bool_t booleans[2] = { true, true };
            bool_t* boolean_pointer = booleans;
            CHECK(nkr::os::atomic::Exchange_Add(boolean_pointer, 1) == booleans + 0);
            CHECK(nkr::os::atomic::Access(boolean_pointer) == booleans + 1);
            CHECK(nkr::os::atomic::Exchange_Add(boolean_pointer, -1) == booleans + 1);
            CHECK(nkr::os::atomic::Access(boolean_pointer) == booleans + 0);
        }
    }

    TEST_CASE("Exchange_Subtract")
    {
        SUBCASE("should atomically subtract from integers and pointers and return the initial value")
        {
            u8_t u8 = 8;
            CHECK(nkr::os::atomic::Exchange_Subtract(u8, 1) == 8);
            CHECK(nkr::os::atomic::Access(u8) == 7);

            u16_t u16 = 16;
            CHECK(nkr::os::atomic::Exchange_Subtract(u16, 1) == 16);
            CHECK(nkr::os::atomic::Access(u16) == 15);

            u32_t u32 = 32;
            CHECK(nkr::os::atomic::Exchange_Subtract(u32, 1) == 32);
            CHECK(nkr::os::atomic::Access(u32) == 31);

        #if defined(nkr_IS_64_BIT)
            u64_t u64 = 64;
            CHECK(nkr::os::atomic::Exchange_Subtract(u64, 1) == 64);
            CHECK(nkr::os::atomic::Access(u64) == 63);
        #endif

            s8_t s8 = -8;
            CHECK(nkr::os::atomic::Exchange_Subtract(s8, -1) == -8);
            CHECK(nkr::os::atomic::Access(s8) == -7);

            s16_t s16 = -16;
            CHECK(nkr::os::atomic::Exchange_Subtract(s16, -1) == -16);
            CHECK(nkr::os::atomic::Access(s16) == -15);

            s32_t s32 = -32;
            CHECK(nkr::os::atomic::Exchange_Subtract(s32, -1) == -32);
            CHECK(nkr::os::atomic::Access(s32) == -31);

        #if defined(nkr_IS_64_BIT)
            s64_t s64 = -64;
            CHECK(nkr::os::atomic::Exchange_Subtract(s64, -1) == -64);
            CHECK(nkr::os::atomic::Access(s64) == -63);
        #endif

            bool_t booleans[2] = { true, true };
            bool_t* boolean_pointer = booleans + 1;
            CHECK(nkr::os::atomic::Exchange_Subtract(boolean_pointer, 1) == booleans + 1);
            CHECK(nkr::os::atomic::Access(boolean_pointer) == booleans + 0);
            CHECK(nkr::os::atomic::Exchange_Subtract(boolean_pointer, -1) == booleans + 0);
            CHECK(nkr::os::atomic::Access(boolean_pointer) == booleans + 1);
        }
    }

    TEST_CASE("Exchange_Or")
    {
        SUBCASE("should atomically OR integers and return the initial value")
        {
            u8_t u8 = 0x0F;
            CHECK(nkr::os::atomic::Exchange_Or(u8, 0xF0) == 0x0F);
            CHECK(nkr::os::atomic::Access(u8) == 0xFF);

            u16_t u16 = 0x00FF;
            CHECK(nkr::os::atomic::Exchange_Or(u16, 0xFF00) == 0x00FF);
            CHECK(nkr::os::atomic::Access(u16) == 0xFFFF);

            u32_t u32 = 0x0000FFFF;
            CHECK(nkr::os::atomic::Exchange_Or(u32, 0xFFFF0000) == 0x0000FFFF);
            CHECK(nkr::os::atomic::Access(u32) == 0xFFFFFFFF);

        #if defined(nkr_IS_64_BIT)
            u64_t u64 = 0x00000000FFFFFFFF;
            CHECK(nkr::os::atomic::Exchange_Or(u64, 0xFFFFFFFF00000000) == 0x00000000FFFFFFFF);
            CHECK(nkr::os::atomic::Access(u64) == 0xFFFFFFFFFFFFFFFF);
        #endif

            s8_t s8 = 0x0F;
            CHECK(nkr::os::atomic::Exchange_Or(s8, 0x70) == 0x0F);
            CHECK(nkr::os::atomic::Access(s8) == 0x7F);

            s16_t s16 = 0x00FF;
            CHECK(nkr::os::atomic::Exchange_Or(s16, 0x7F00) == 0x00FF);
            CHECK(nkr::os::atomic::Access(s16) == 0x7FFF);

            s32_t s32 = 0x0000FFFF;
            CHECK(nkr::os::atomic::Exchange_Or(s32, 0x7FFF0000) == 0x0000FFFF);
            CHECK(nkr::os::atomic::Access(s32) == 0x7FFFFFFF);

        #if defined(nkr_IS_64_BIT)
            s64_t s64 = 0x00000000FFFFFFFF;
            CHECK(nkr::os::atomic::Exchange_Or(s64, 0x7FFFFFFF00000000) == 0x00000000FFFFFFFF);
            CHECK(nkr::os::atomic::Access(s64) == 0x7FFFFFFFFFFFFFFF);
        #endif
        }
    }

    TEST_CASE("Exchange_And")
    {
        SUBCASE("should atomically AND integers and return the initial value")
        {
            u8_t u8 = 0x0F;
            CHECK(nkr::os::atomic::Exchange_And(u8, 0xF0) == 0x0F);
            CHECK(nkr::os::atomic::Access(u8) == 0x0);

            u16_t u16 = 0x00FF;
            CHECK(nkr::os::atomic::Exchange_And(u16, 0xFF00) == 0x00FF);
            CHECK(nkr::os::atomic::Access(u16) == 0x0);

            u32_t u32 = 0x0000FFFF;
            CHECK(nkr::os::atomic::Exchange_And(u32, 0xFFFF0000) == 0x0000FFFF);
            CHECK(nkr::os::atomic::Access(u32) == 0x0);

        #if defined(nkr_IS_64_BIT)
            u64_t u64 = 0x00000000FFFFFFFF;
            CHECK(nkr::os::atomic::Exchange_And(u64, 0xFFFFFFFF00000000) == 0x00000000FFFFFFFF);
            CHECK(nkr::os::atomic::Access(u64) == 0x0);
        #endif

            s8_t s8 = 0x0F;
            CHECK(nkr::os::atomic::Exchange_And(s8, 0x70) == 0x0F);
            CHECK(nkr::os::atomic::Access(s8) == 0x0);

            s16_t s16 = 0x00FF;
            CHECK(nkr::os::atomic::Exchange_And(s16, 0x7F00) == 0x00FF);
            CHECK(nkr::os::atomic::Access(s16) == 0x0);

            s32_t s32 = 0x0000FFFF;
            CHECK(nkr::os::atomic::Exchange_And(s32, 0x7FFF0000) == 0x0000FFFF);
            CHECK(nkr::os::atomic::Access(s32) == 0x0);

        #if defined(nkr_IS_64_BIT)
            s64_t s64 = 0x00000000FFFFFFFF;
            CHECK(nkr::os::atomic::Exchange_And(s64, 0x7FFFFFFF00000000) == 0x00000000FFFFFFFF);
            CHECK(nkr::os::atomic::Access(s64) == 0x0);
        #endif
        }
    }

    TEST_CASE("Exchange_Xor")
    {
        SUBCASE("should atomically XOR integers and return the initial value")
        {
            u8_t u8 = 0xFF;
            CHECK(nkr::os::atomic::Exchange_Xor(u8, 0x01) == 0xFF);
            CHECK(nkr::os::atomic::Access(u8) == 0xFE);

            u16_t u16 = 0xFFFF;
            CHECK(nkr::os::atomic::Exchange_Xor(u16, 0x0001) == 0xFFFF);
            CHECK(nkr::os::atomic::Access(u16) == 0xFFFE);

            u32_t u32 = 0xFFFFFFFF;
            CHECK(nkr::os::atomic::Exchange_Xor(u32, 0x00000001) == 0xFFFFFFFF);
            CHECK(nkr::os::atomic::Access(u32) == 0xFFFFFFFE);

        #if defined(nkr_IS_64_BIT)
            u64_t u64 = 0xFFFFFFFFFFFFFFFF;
            CHECK(nkr::os::atomic::Exchange_Xor(u64, 0x0000000000000001) == 0xFFFFFFFFFFFFFFFF);
            CHECK(nkr::os::atomic::Access(u64) == 0xFFFFFFFFFFFFFFFE);
        #endif

            s8_t s8 = 0x7F;
            CHECK(nkr::os::atomic::Exchange_Xor(s8, 0x01) == 0x7F);
            CHECK(nkr::os::atomic::Access(s8) == 0x7E);

            s16_t s16 = 0x7FFF;
            CHECK(nkr::os::atomic::Exchange_Xor(s16, 0x0001) == 0x7FFF);
            CHECK(nkr::os::atomic::Access(s16) == 0x7FFE);

            s32_t s32 = 0x7FFFFFFF;
            CHECK(nkr::os::atomic::Exchange_Xor(s32, 0x00000001) == 0x7FFFFFFF);
            CHECK(nkr::os::atomic::Access(s32) == 0x7FFFFFFE);

        #if defined(nkr_IS_64_BIT)
            s64_t s64 = 0x7FFFFFFFFFFFFFFF;
            CHECK(nkr::os::atomic::Exchange_Xor(s64, 0x0000000000000001) == 0x7FFFFFFFFFFFFFFF);
            CHECK(nkr::os::atomic::Access(s64) == 0x7FFFFFFFFFFFFFFE);
        #endif
        }
    }

}}}

namespace nkr { namespace os { namespace endian {

    TEST_CASE("Is_Big"
              * doctest::may_fail(true)
              * doctest::no_breaks(true))
    {
        SUBCASE("should in a thread-safe manner efficiently determine if the runtime is in big endian")
        {
        #if defined(nkr_IS_WINDOWS)
            CHECK(nkr::os::endian::Is_Big() == false);
        #else
            CHECK(nkr::os::endian::Is_Big() == true);
        #endif
        }
    }

    TEST_CASE("Is_Little"
              * doctest::may_fail(true)
              * doctest::no_breaks(true))
    {
        SUBCASE("should in a thread-safe manner efficiently determine if the runtime is in little endian")
        {
        #if defined(nkr_IS_WINDOWS)
            CHECK(nkr::os::endian::Is_Little() == true);
        #else
            CHECK(nkr::os::endian::Is_Little() == false);
        #endif
        }
    }

    TEST_CASE("Swap")
    {
        SUBCASE("should swap the bytes of i16_tr, i32_tr, and i64_tr")
        {
            u16_t u16 = 0x0102;
            CHECK(nkr::os::endian::Swap(u16) == 0x0201);

            u32_t u32 = 0x01020304;
            CHECK(nkr::os::endian::Swap(u32) == 0x04030201);

            u64_t u64 = 0x0102030405060708;
            CHECK(nkr::os::endian::Swap(u64) == 0x0807060504030201);

            s16_t s16 = 0x0102;
            CHECK(nkr::os::endian::Swap(s16) == 0x0201);

            s32_t s32 = 0x01020304;
            CHECK(nkr::os::endian::Swap(s32) == 0x04030201);

            s64_t s64 = 0x0102030405060708;
            CHECK(nkr::os::endian::Swap(s64) == 0x0807060504030201);

            CHECK(nkr::os::endian::Swap(0x0102) == 0x02010000);
            CHECK(nkr::os::endian::Swap(0x01020304) == 0x04030201);
            CHECK(nkr::os::endian::Swap(0x0102030405060708) == 0x0807060504030201);

            CHECK(nkr::os::endian::Swap(static_cast<u16_t>(0x0102)) == 0x0201);
        }
    }

}}}

namespace nkr { namespace os { namespace heap {

    TEST_CASE("Allocate")
    {
        SUBCASE("should allocate heap memory or return nullptr if it can't")
        {
            byte_t* bytes = os::heap::Allocate(0xFF);
            CHECK(bytes != nullptr);

            wprintf(L"%s", bytes[0xFF - 1] == 1 ? L"\u0001" : L"\u0000");
            CHECK(true);

            byte_t* too_much = os::heap::Allocate(std::numeric_limits<count_t>::max());
            CHECK(too_much == nullptr);

            os::heap::Deallocate(bytes);
        }
    }

    TEST_CASE("Reallocate")
    {
        SUBCASE("should reallocate heap memory, set bytes, and return true, else leave bytes and return false")
        {
            byte_t* bytes = os::heap::Allocate(0xFF);
            CHECK(os::heap::Reallocate(bytes, 0xFFFF) == true);

            wprintf(L"%s", bytes[0xFFFF - 1] == 1 ? L"\u0001" : L"\u0000");
            CHECK(true);

            byte_t* bytes_backup = bytes;
            CHECK(os::heap::Reallocate(bytes, std::numeric_limits<count_t>::max()) == false);
            CHECK(bytes == bytes_backup);

            os::heap::Deallocate(bytes);
        }
    }

    TEST_CASE("Deallocate")
    {
        SUBCASE("should deallocate heap memory and set bytes to nullptr")
        {
            byte_t* bytes = os::heap::Allocate(0xFF);
            CHECK(bytes != nullptr);

            os::heap::Deallocate(bytes);
            CHECK(bytes == nullptr);
        }
    }

    TEST_CASE("Allocate_Zeros")
    {
        SUBCASE("should allocate heap memory and set to zero or return nullptr if it can't")
        {
            byte_t* bytes = os::heap::Allocate_Zeros(0xFF);
            CHECK(bytes != nullptr);
            for (index_t idx = 0, end = 0xFF; idx < end; idx += 1) {
                CHECK(bytes[idx] == 0);
            }

            byte_t* too_much = os::heap::Allocate_Zeros(std::numeric_limits<count_t>::max());
            CHECK(too_much == nullptr);

            os::heap::Deallocate_Zeros(bytes);
        }
    }

    TEST_CASE("Reallocate_Zeros")
    {
        SUBCASE("should reallocate heap memory, set to zero, set bytes, and return true, else leave bytes and return false")
        {
            byte_t* bytes = os::heap::Allocate_Zeros(0xFF);
            CHECK(os::heap::Reallocate_Zeros(bytes, 0xFFFF) == true);
            for (index_t idx = 0, end = 0xFFFF; idx < end; idx += 1) {
                CHECK(bytes[idx] == 0);
            }

            byte_t* bytes_backup = bytes;
            CHECK(os::heap::Reallocate_Zeros(bytes, std::numeric_limits<count_t>::max()) == false);
            CHECK(bytes == bytes_backup);

            os::heap::Deallocate_Zeros(bytes);
        }
    }

    TEST_CASE("Deallocate_Zeros")
    {
        SUBCASE("should deallocate heap memory and set bytes to nullptr")
        {
            byte_t* bytes = os::heap::Allocate_Zeros(0xFF);
            CHECK(bytes != nullptr);

            os::heap::Deallocate_Zeros(bytes);
            CHECK(bytes == nullptr);
        }
    }

}}}
