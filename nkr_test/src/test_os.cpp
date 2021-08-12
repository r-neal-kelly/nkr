/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "test_os.h"

namespace nkr { namespace test { namespace os {

    void_t Execute()
    {
        wprintf(L"os\n");

        nkr_TEST_FUNCTION(atomic::Access);
        wprintf(L"\n");

        nkr_TEST_FUNCTION(atomic::Assign);
        nkr_TEST_FUNCTION(atomic::Exchange_Assign);
        nkr_TEST_FUNCTION(atomic::Exchange_Assign_If_Equals);
        wprintf(L"\n");

        nkr_TEST_FUNCTION(atomic::Add);
        nkr_TEST_FUNCTION(atomic::Exchange_Add);
        wprintf(L"\n");

        nkr_TEST_FUNCTION(atomic::Subtract);
        nkr_TEST_FUNCTION(atomic::Exchange_Subtract);
        wprintf(L"\n");

        nkr_TEST_FUNCTION(atomic::Or);
        nkr_TEST_FUNCTION(atomic::Exchange_Or);
        wprintf(L"\n");

        nkr_TEST_FUNCTION(atomic::And);
        nkr_TEST_FUNCTION(atomic::Exchange_And);
        wprintf(L"\n");

        nkr_TEST_FUNCTION(atomic::Xor);
        nkr_TEST_FUNCTION(atomic::Exchange_Xor);
        wprintf(L"\n");
    }

}}}

namespace nkr { namespace test { namespace os { namespace atomic {

    void_t Access()
    {
        wprintf(L"should atomically access integers and pointers and return the value");

        bool_t boolean = false;
        nkr_TEST(nkr::os::atomic::Access(boolean) == false);

        u8_t u8 = 8;
        nkr_TEST(nkr::os::atomic::Access(u8) == 8);

        u16_t u16 = 16;
        nkr_TEST(nkr::os::atomic::Access(u16) == 16);

        u32_t u32 = 32;
        nkr_TEST(nkr::os::atomic::Access(u32) == 32);

    #if defined(nkr_IS_64_BIT)
        u64_t u64 = 64;
        nkr_TEST(nkr::os::atomic::Access(u64) == 64);
    #endif

        s8_t s8 = -8;
        nkr_TEST(nkr::os::atomic::Access(s8) == -8);

        s16_t s16 = -16;
        nkr_TEST(nkr::os::atomic::Access(s16) == -16);

        s32_t s32 = -32;
        nkr_TEST(nkr::os::atomic::Access(s32) == -32);

    #if defined(nkr_IS_64_BIT)
        s64_t s64 = -64;
        nkr_TEST(nkr::os::atomic::Access(s64) == -64);
    #endif

        void_t* void_pointer = nullptr;
        nkr_TEST(nkr::os::atomic::Access(void_pointer) == nullptr);

        bool_t* boolean_pointer = &boolean;
        nkr_TEST(nkr::os::atomic::Access(boolean_pointer) == &boolean);
    }

    void_t Assign()
    {
        wprintf(L"should atomically assign integers and pointers and return the new value");

        bool_t boolean = false;
        nkr_TEST(nkr::os::atomic::Assign(boolean, true) == true);

        u8_t u8 = 8;
        nkr_TEST(nkr::os::atomic::Assign(u8, 1) == 1);

        u16_t u16 = 16;
        nkr_TEST(nkr::os::atomic::Assign(u16, 1) == 1);

        u32_t u32 = 32;
        nkr_TEST(nkr::os::atomic::Assign(u32, 1) == 1);

    #if defined(nkr_IS_64_BIT)
        u64_t u64 = 64;
        nkr_TEST(nkr::os::atomic::Assign(u64, 1) == 1);
    #endif

        s8_t s8 = -8;
        nkr_TEST(nkr::os::atomic::Assign(s8, -1) == -1);

        s16_t s16 = -16;
        nkr_TEST(nkr::os::atomic::Assign(s16, -1) == -1);

        s32_t s32 = -32;
        nkr_TEST(nkr::os::atomic::Assign(s32, -1) == -1);

    #if defined(nkr_IS_64_BIT)
        s64_t s64 = -64;
        nkr_TEST(nkr::os::atomic::Assign(s64, -1) == -1);
    #endif

        void_t* void_pointer = nullptr;
        nkr_TEST(nkr::os::atomic::Assign(void_pointer, &boolean) == &boolean);

        bool_t* boolean_pointer = &boolean;
        nkr_TEST(nkr::os::atomic::Assign(boolean_pointer, nullptr) == nullptr);
    }

    void_t Exchange_Assign()
    {
        wprintf(L"should atomically assign integers and pointers and return the initial value");

        bool_t boolean = false;
        nkr_TEST(nkr::os::atomic::Exchange_Assign(boolean, true) == false);
        nkr_TEST(nkr::os::atomic::Access(boolean) == true);

        u8_t u8 = 8;
        nkr_TEST(nkr::os::atomic::Exchange_Assign(u8, 1) == 8);
        nkr_TEST(nkr::os::atomic::Access(u8) == 1);

        u16_t u16 = 16;
        nkr_TEST(nkr::os::atomic::Exchange_Assign(u16, 1) == 16);
        nkr_TEST(nkr::os::atomic::Access(u16) == 1);

        u32_t u32 = 32;
        nkr_TEST(nkr::os::atomic::Exchange_Assign(u32, 1) == 32);
        nkr_TEST(nkr::os::atomic::Access(u32) == 1);

    #if defined(nkr_IS_64_BIT)
        u64_t u64 = 64;
        nkr_TEST(nkr::os::atomic::Exchange_Assign(u64, 1) == 64);
        nkr_TEST(nkr::os::atomic::Access(u64) == 1);
    #endif

        s8_t s8 = -8;
        nkr_TEST(nkr::os::atomic::Exchange_Assign(s8, -1) == -8);
        nkr_TEST(nkr::os::atomic::Access(s8) == -1);

        s16_t s16 = -16;
        nkr_TEST(nkr::os::atomic::Exchange_Assign(s16, -1) == -16);
        nkr_TEST(nkr::os::atomic::Access(s16) == -1);

        s32_t s32 = -32;
        nkr_TEST(nkr::os::atomic::Exchange_Assign(s32, -1) == -32);
        nkr_TEST(nkr::os::atomic::Access(s32) == -1);

    #if defined(nkr_IS_64_BIT)
        s64_t s64 = -64;
        nkr_TEST(nkr::os::atomic::Exchange_Assign(s64, -1) == -64);
        nkr_TEST(nkr::os::atomic::Access(s64) == -1);
    #endif

        void_t* void_pointer = nullptr;
        nkr_TEST(nkr::os::atomic::Exchange_Assign(void_pointer, &boolean) == nullptr);
        nkr_TEST(nkr::os::atomic::Access(void_pointer) == &boolean);

        bool_t* boolean_pointer = &boolean;
        nkr_TEST(nkr::os::atomic::Exchange_Assign(boolean_pointer, nullptr) == &boolean);
        nkr_TEST(nkr::os::atomic::Access(boolean_pointer) == nullptr);
    }

    void_t Exchange_Assign_If_Equals()
    {
        wprintf(L"should atomically assign integers and pointers if they equal target and return the initial value");

        bool_t boolean = false;
        nkr_TEST(nkr::os::atomic::Exchange_Assign_If_Equals(boolean, true, true) == false);
        nkr_TEST(nkr::os::atomic::Access(boolean) == false);
        nkr_TEST(nkr::os::atomic::Exchange_Assign_If_Equals(boolean, true, false) == false);
        nkr_TEST(nkr::os::atomic::Access(boolean) == true);

        u8_t u8 = 8;
        nkr_TEST(nkr::os::atomic::Exchange_Assign_If_Equals(u8, 1, 1) == 8);
        nkr_TEST(nkr::os::atomic::Access(u8) == 8);
        nkr_TEST(nkr::os::atomic::Exchange_Assign_If_Equals(u8, 1, 8) == 8);
        nkr_TEST(nkr::os::atomic::Access(u8) == 1);

        u16_t u16 = 16;
        nkr_TEST(nkr::os::atomic::Exchange_Assign_If_Equals(u16, 1, 1) == 16);
        nkr_TEST(nkr::os::atomic::Access(u16) == 16);
        nkr_TEST(nkr::os::atomic::Exchange_Assign_If_Equals(u16, 1, 16) == 16);
        nkr_TEST(nkr::os::atomic::Access(u16) == 1);

        u32_t u32 = 32;
        nkr_TEST(nkr::os::atomic::Exchange_Assign_If_Equals(u32, 1, 1) == 32);
        nkr_TEST(nkr::os::atomic::Access(u32) == 32);
        nkr_TEST(nkr::os::atomic::Exchange_Assign_If_Equals(u32, 1, 32) == 32);
        nkr_TEST(nkr::os::atomic::Access(u32) == 1);

    #if defined(nkr_IS_64_BIT)
        u64_t u64 = 64;
        nkr_TEST(nkr::os::atomic::Exchange_Assign_If_Equals(u64, 1, 1) == 64);
        nkr_TEST(nkr::os::atomic::Access(u64) == 64);
        nkr_TEST(nkr::os::atomic::Exchange_Assign_If_Equals(u64, 1, 64) == 64);
        nkr_TEST(nkr::os::atomic::Access(u64) == 1);
    #endif

        s8_t s8 = -8;
        nkr_TEST(nkr::os::atomic::Exchange_Assign_If_Equals(s8, -1, -1) == -8);
        nkr_TEST(nkr::os::atomic::Access(s8) == -8);
        nkr_TEST(nkr::os::atomic::Exchange_Assign_If_Equals(s8, -1, -8) == -8);
        nkr_TEST(nkr::os::atomic::Access(s8) == -1);

        s16_t s16 = -16;
        nkr_TEST(nkr::os::atomic::Exchange_Assign_If_Equals(s16, -1, -1) == -16);
        nkr_TEST(nkr::os::atomic::Access(s16) == -16);
        nkr_TEST(nkr::os::atomic::Exchange_Assign_If_Equals(s16, -1, -16) == -16);
        nkr_TEST(nkr::os::atomic::Access(s16) == -1);

        s32_t s32 = -32;
        nkr_TEST(nkr::os::atomic::Exchange_Assign_If_Equals(s32, -1, -1) == -32);
        nkr_TEST(nkr::os::atomic::Access(s32) == -32);
        nkr_TEST(nkr::os::atomic::Exchange_Assign_If_Equals(s32, -1, -32) == -32);
        nkr_TEST(nkr::os::atomic::Access(s32) == -1);

    #if defined(nkr_IS_64_BIT)
        s64_t s64 = -64;
        nkr_TEST(nkr::os::atomic::Exchange_Assign_If_Equals(s64, -1, -1) == -64);
        nkr_TEST(nkr::os::atomic::Access(s64) == -64);
        nkr_TEST(nkr::os::atomic::Exchange_Assign_If_Equals(s64, -1, -64) == -64);
        nkr_TEST(nkr::os::atomic::Access(s64) == -1);
    #endif

        void_t* void_pointer = nullptr;
        nkr_TEST(nkr::os::atomic::Exchange_Assign_If_Equals(void_pointer, &boolean, &boolean) == nullptr);
        nkr_TEST(nkr::os::atomic::Access(void_pointer) == nullptr);
        nkr_TEST(nkr::os::atomic::Exchange_Assign_If_Equals(void_pointer, &boolean, nullptr) == nullptr);
        nkr_TEST(nkr::os::atomic::Access(void_pointer) == &boolean);

        bool_t* boolean_pointer = &boolean;
        nkr_TEST(nkr::os::atomic::Exchange_Assign_If_Equals(boolean_pointer, nullptr, nullptr) == &boolean);
        nkr_TEST(nkr::os::atomic::Access(boolean_pointer) == &boolean);
        nkr_TEST(nkr::os::atomic::Exchange_Assign_If_Equals(boolean_pointer, nullptr, &boolean) == &boolean);
        nkr_TEST(nkr::os::atomic::Access(boolean_pointer) == nullptr);
    }

    void_t Add()
    {
        wprintf(L"should atomically add to integers and pointers and return the new value");

        u8_t u8 = 8;
        nkr_TEST(nkr::os::atomic::Add(u8, 1) == 9);

        u16_t u16 = 16;
        nkr_TEST(nkr::os::atomic::Add(u16, 1) == 17);

        u32_t u32 = 32;
        nkr_TEST(nkr::os::atomic::Add(u32, 1) == 33);

    #if defined(nkr_IS_64_BIT)
        u64_t u64 = 64;
        nkr_TEST(nkr::os::atomic::Add(u64, 1) == 65);
    #endif

        s8_t s8 = -8;
        nkr_TEST(nkr::os::atomic::Add(s8, -1) == -9);

        s16_t s16 = -16;
        nkr_TEST(nkr::os::atomic::Add(s16, -1) == -17);

        s32_t s32 = -32;
        nkr_TEST(nkr::os::atomic::Add(s32, -1) == -33);

    #if defined(nkr_IS_64_BIT)
        s64_t s64 = -64;
        nkr_TEST(nkr::os::atomic::Add(s64, -1) == -65);
    #endif

        bool_t booleans[2] = { true, true };
        bool_t* boolean_pointer = booleans;
        nkr_TEST(nkr::os::atomic::Add(boolean_pointer, 1) == booleans + 1);
        nkr_TEST(nkr::os::atomic::Add(boolean_pointer, -1) == booleans + 0);
    }

    void_t Exchange_Add()
    {
        wprintf(L"should atomically add to integers and pointers and return the initial value");

        u8_t u8 = 8;
        nkr_TEST(nkr::os::atomic::Exchange_Add(u8, 1) == 8);
        nkr_TEST(nkr::os::atomic::Access(u8) == 9);

        u16_t u16 = 16;
        nkr_TEST(nkr::os::atomic::Exchange_Add(u16, 1) == 16);
        nkr_TEST(nkr::os::atomic::Access(u16) == 17);

        u32_t u32 = 32;
        nkr_TEST(nkr::os::atomic::Exchange_Add(u32, 1) == 32);
        nkr_TEST(nkr::os::atomic::Access(u32) == 33);

    #if defined(nkr_IS_64_BIT)
        u64_t u64 = 64;
        nkr_TEST(nkr::os::atomic::Exchange_Add(u64, 1) == 64);
        nkr_TEST(nkr::os::atomic::Access(u64) == 65);
    #endif

        s8_t s8 = -8;
        nkr_TEST(nkr::os::atomic::Exchange_Add(s8, -1) == -8);
        nkr_TEST(nkr::os::atomic::Access(s8) == -9);

        s16_t s16 = -16;
        nkr_TEST(nkr::os::atomic::Exchange_Add(s16, -1) == -16);
        nkr_TEST(nkr::os::atomic::Access(s16) == -17);

        s32_t s32 = -32;
        nkr_TEST(nkr::os::atomic::Exchange_Add(s32, -1) == -32);
        nkr_TEST(nkr::os::atomic::Access(s32) == -33);

    #if defined(nkr_IS_64_BIT)
        s64_t s64 = -64;
        nkr_TEST(nkr::os::atomic::Exchange_Add(s64, -1) == -64);
        nkr_TEST(nkr::os::atomic::Access(s64) == -65);
    #endif

        bool_t booleans[2] = { true, true };
        bool_t* boolean_pointer = booleans;
        nkr_TEST(nkr::os::atomic::Exchange_Add(boolean_pointer, 1) == booleans + 0);
        nkr_TEST(nkr::os::atomic::Access(boolean_pointer) == booleans + 1);
        nkr_TEST(nkr::os::atomic::Exchange_Add(boolean_pointer, -1) == booleans + 1);
        nkr_TEST(nkr::os::atomic::Access(boolean_pointer) == booleans + 0);
    }

    void_t Subtract()
    {
        wprintf(L"should atomically subtract from integers and pointers and return the new value");

        u8_t u8 = 8;
        nkr_TEST(nkr::os::atomic::Subtract(u8, 1) == 7);

        u16_t u16 = 16;
        nkr_TEST(nkr::os::atomic::Subtract(u16, 1) == 15);

        u32_t u32 = 32;
        nkr_TEST(nkr::os::atomic::Subtract(u32, 1) == 31);

    #if defined(nkr_IS_64_BIT)
        u64_t u64 = 64;
        nkr_TEST(nkr::os::atomic::Subtract(u64, 1) == 63);
    #endif

        s8_t s8 = -8;
        nkr_TEST(nkr::os::atomic::Subtract(s8, -1) == -7);

        s16_t s16 = -16;
        nkr_TEST(nkr::os::atomic::Subtract(s16, -1) == -15);

        s32_t s32 = -32;
        nkr_TEST(nkr::os::atomic::Subtract(s32, -1) == -31);

    #if defined(nkr_IS_64_BIT)
        s64_t s64 = -64;
        nkr_TEST(nkr::os::atomic::Subtract(s64, -1) == -63);
    #endif

        bool_t booleans[2] = { true, true };
        bool_t* boolean_pointer = booleans + 1;
        nkr_TEST(nkr::os::atomic::Subtract(boolean_pointer, 1) == booleans + 0);
        nkr_TEST(nkr::os::atomic::Subtract(boolean_pointer, -1) == booleans + 1);
    }

    void_t Exchange_Subtract()
    {
        wprintf(L"should atomically subtract from integers and pointers and return the initial value");

        u8_t u8 = 8;
        nkr_TEST(nkr::os::atomic::Exchange_Subtract(u8, 1) == 8);
        nkr_TEST(nkr::os::atomic::Access(u8) == 7);

        u16_t u16 = 16;
        nkr_TEST(nkr::os::atomic::Exchange_Subtract(u16, 1) == 16);
        nkr_TEST(nkr::os::atomic::Access(u16) == 15);

        u32_t u32 = 32;
        nkr_TEST(nkr::os::atomic::Exchange_Subtract(u32, 1) == 32);
        nkr_TEST(nkr::os::atomic::Access(u32) == 31);

    #if defined(nkr_IS_64_BIT)
        u64_t u64 = 64;
        nkr_TEST(nkr::os::atomic::Exchange_Subtract(u64, 1) == 64);
        nkr_TEST(nkr::os::atomic::Access(u64) == 63);
    #endif

        s8_t s8 = -8;
        nkr_TEST(nkr::os::atomic::Exchange_Subtract(s8, -1) == -8);
        nkr_TEST(nkr::os::atomic::Access(s8) == -7);

        s16_t s16 = -16;
        nkr_TEST(nkr::os::atomic::Exchange_Subtract(s16, -1) == -16);
        nkr_TEST(nkr::os::atomic::Access(s16) == -15);

        s32_t s32 = -32;
        nkr_TEST(nkr::os::atomic::Exchange_Subtract(s32, -1) == -32);
        nkr_TEST(nkr::os::atomic::Access(s32) == -31);

    #if defined(nkr_IS_64_BIT)
        s64_t s64 = -64;
        nkr_TEST(nkr::os::atomic::Exchange_Subtract(s64, -1) == -64);
        nkr_TEST(nkr::os::atomic::Access(s64) == -63);
    #endif

        bool_t booleans[2] = { true, true };
        bool_t* boolean_pointer = booleans +1;
        nkr_TEST(nkr::os::atomic::Exchange_Subtract(boolean_pointer, 1) == booleans + 1);
        nkr_TEST(nkr::os::atomic::Access(boolean_pointer) == booleans + 0);
        nkr_TEST(nkr::os::atomic::Exchange_Subtract(boolean_pointer, -1) == booleans + 0);
        nkr_TEST(nkr::os::atomic::Access(boolean_pointer) == booleans + 1);
    }

    void_t Or()
    {

    }

    void_t Exchange_Or()
    {

    }

    void_t And()
    {

    }

    void_t Exchange_And()
    {

    }

    void_t Xor()
    {

    }

    void_t Exchange_Xor()
    {

    }

}}}}
