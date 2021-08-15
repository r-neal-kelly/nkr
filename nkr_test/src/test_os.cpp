/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "test_os.h"

namespace nkr { namespace test_os {

    void_t Execute()
    {
        wprintf(L"os\n");

        nkr_TEST_FUNCTION(atomic::Access);
        nkr_TEST_FUNCTION(atomic::Assign);
        nkr_TEST_FUNCTION(atomic::Exchange);
        nkr_TEST_FUNCTION(atomic::Exchange_If_Equals);
        wprintf(L"\n");

        nkr_TEST_FUNCTION(atomic::Assign_Add);
        nkr_TEST_FUNCTION(atomic::Exchange_Add);
        wprintf(L"\n");

        nkr_TEST_FUNCTION(atomic::Assign_Subtract);
        nkr_TEST_FUNCTION(atomic::Exchange_Subtract);
        wprintf(L"\n");

        nkr_TEST_FUNCTION(atomic::Assign_Or);
        nkr_TEST_FUNCTION(atomic::Exchange_Or);
        wprintf(L"\n");

        nkr_TEST_FUNCTION(atomic::Assign_And);
        nkr_TEST_FUNCTION(atomic::Exchange_And);
        wprintf(L"\n");

        nkr_TEST_FUNCTION(atomic::Assign_Xor);
        nkr_TEST_FUNCTION(atomic::Exchange_Xor);
        wprintf(L"\n");

        nkr_TEST_FUNCTION(endian::Is_Big);
        nkr_TEST_FUNCTION(endian::Is_Little);
        wprintf(L"\n");

        nkr_TEST_FUNCTION(endian::Swap);
        wprintf(L"\n");

        nkr_TEST_FUNCTION(heap::Allocate);
        nkr_TEST_FUNCTION(heap::Reallocate);
        nkr_TEST_FUNCTION(heap::Deallocate);
        wprintf(L"\n");

        nkr_TEST_FUNCTION(heap::Callocate);
        nkr_TEST_FUNCTION(heap::Recallocate);
        nkr_TEST_FUNCTION(heap::Decallocate);
        wprintf(L"\n");
    }

}}

namespace nkr { namespace test_os { namespace atomic {

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

    void_t Exchange()
    {
        wprintf(L"should atomically assign integers and pointers and return the initial value");

        bool_t boolean = false;
        nkr_TEST(nkr::os::atomic::Exchange(boolean, true) == false);
        nkr_TEST(nkr::os::atomic::Access(boolean) == true);

        u8_t u8 = 8;
        nkr_TEST(nkr::os::atomic::Exchange(u8, 1) == 8);
        nkr_TEST(nkr::os::atomic::Access(u8) == 1);

        u16_t u16 = 16;
        nkr_TEST(nkr::os::atomic::Exchange(u16, 1) == 16);
        nkr_TEST(nkr::os::atomic::Access(u16) == 1);

        u32_t u32 = 32;
        nkr_TEST(nkr::os::atomic::Exchange(u32, 1) == 32);
        nkr_TEST(nkr::os::atomic::Access(u32) == 1);

    #if defined(nkr_IS_64_BIT)
        u64_t u64 = 64;
        nkr_TEST(nkr::os::atomic::Exchange(u64, 1) == 64);
        nkr_TEST(nkr::os::atomic::Access(u64) == 1);
    #endif

        s8_t s8 = -8;
        nkr_TEST(nkr::os::atomic::Exchange(s8, -1) == -8);
        nkr_TEST(nkr::os::atomic::Access(s8) == -1);

        s16_t s16 = -16;
        nkr_TEST(nkr::os::atomic::Exchange(s16, -1) == -16);
        nkr_TEST(nkr::os::atomic::Access(s16) == -1);

        s32_t s32 = -32;
        nkr_TEST(nkr::os::atomic::Exchange(s32, -1) == -32);
        nkr_TEST(nkr::os::atomic::Access(s32) == -1);

    #if defined(nkr_IS_64_BIT)
        s64_t s64 = -64;
        nkr_TEST(nkr::os::atomic::Exchange(s64, -1) == -64);
        nkr_TEST(nkr::os::atomic::Access(s64) == -1);
    #endif

        void_t* void_pointer = nullptr;
        nkr_TEST(nkr::os::atomic::Exchange(void_pointer, &boolean) == nullptr);
        nkr_TEST(nkr::os::atomic::Access(void_pointer) == &boolean);

        bool_t* boolean_pointer = &boolean;
        nkr_TEST(nkr::os::atomic::Exchange(boolean_pointer, nullptr) == &boolean);
        nkr_TEST(nkr::os::atomic::Access(boolean_pointer) == nullptr);
    }

    void_t Exchange_If_Equals()
    {
        wprintf(L"should atomically assign integers and pointers if they equal target and return the initial value");

        bool_t boolean = false;
        nkr_TEST(nkr::os::atomic::Exchange_If_Equals(boolean, true, true) == false);
        nkr_TEST(nkr::os::atomic::Access(boolean) == false);
        nkr_TEST(nkr::os::atomic::Exchange_If_Equals(boolean, true, false) == false);
        nkr_TEST(nkr::os::atomic::Access(boolean) == true);

        u8_t u8 = 8;
        nkr_TEST(nkr::os::atomic::Exchange_If_Equals(u8, 1, 1) == 8);
        nkr_TEST(nkr::os::atomic::Access(u8) == 8);
        nkr_TEST(nkr::os::atomic::Exchange_If_Equals(u8, 1, 8) == 8);
        nkr_TEST(nkr::os::atomic::Access(u8) == 1);

        u16_t u16 = 16;
        nkr_TEST(nkr::os::atomic::Exchange_If_Equals(u16, 1, 1) == 16);
        nkr_TEST(nkr::os::atomic::Access(u16) == 16);
        nkr_TEST(nkr::os::atomic::Exchange_If_Equals(u16, 1, 16) == 16);
        nkr_TEST(nkr::os::atomic::Access(u16) == 1);

        u32_t u32 = 32;
        nkr_TEST(nkr::os::atomic::Exchange_If_Equals(u32, 1, 1) == 32);
        nkr_TEST(nkr::os::atomic::Access(u32) == 32);
        nkr_TEST(nkr::os::atomic::Exchange_If_Equals(u32, 1, 32) == 32);
        nkr_TEST(nkr::os::atomic::Access(u32) == 1);

    #if defined(nkr_IS_64_BIT)
        u64_t u64 = 64;
        nkr_TEST(nkr::os::atomic::Exchange_If_Equals(u64, 1, 1) == 64);
        nkr_TEST(nkr::os::atomic::Access(u64) == 64);
        nkr_TEST(nkr::os::atomic::Exchange_If_Equals(u64, 1, 64) == 64);
        nkr_TEST(nkr::os::atomic::Access(u64) == 1);
    #endif

        s8_t s8 = -8;
        nkr_TEST(nkr::os::atomic::Exchange_If_Equals(s8, -1, -1) == -8);
        nkr_TEST(nkr::os::atomic::Access(s8) == -8);
        nkr_TEST(nkr::os::atomic::Exchange_If_Equals(s8, -1, -8) == -8);
        nkr_TEST(nkr::os::atomic::Access(s8) == -1);

        s16_t s16 = -16;
        nkr_TEST(nkr::os::atomic::Exchange_If_Equals(s16, -1, -1) == -16);
        nkr_TEST(nkr::os::atomic::Access(s16) == -16);
        nkr_TEST(nkr::os::atomic::Exchange_If_Equals(s16, -1, -16) == -16);
        nkr_TEST(nkr::os::atomic::Access(s16) == -1);

        s32_t s32 = -32;
        nkr_TEST(nkr::os::atomic::Exchange_If_Equals(s32, -1, -1) == -32);
        nkr_TEST(nkr::os::atomic::Access(s32) == -32);
        nkr_TEST(nkr::os::atomic::Exchange_If_Equals(s32, -1, -32) == -32);
        nkr_TEST(nkr::os::atomic::Access(s32) == -1);

    #if defined(nkr_IS_64_BIT)
        s64_t s64 = -64;
        nkr_TEST(nkr::os::atomic::Exchange_If_Equals(s64, -1, -1) == -64);
        nkr_TEST(nkr::os::atomic::Access(s64) == -64);
        nkr_TEST(nkr::os::atomic::Exchange_If_Equals(s64, -1, -64) == -64);
        nkr_TEST(nkr::os::atomic::Access(s64) == -1);
    #endif

        void_t* void_pointer = nullptr;
        nkr_TEST(nkr::os::atomic::Exchange_If_Equals(void_pointer, &boolean, &boolean) == nullptr);
        nkr_TEST(nkr::os::atomic::Access(void_pointer) == nullptr);
        nkr_TEST(nkr::os::atomic::Exchange_If_Equals(void_pointer, &boolean, nullptr) == nullptr);
        nkr_TEST(nkr::os::atomic::Access(void_pointer) == &boolean);

        bool_t* boolean_pointer = &boolean;
        nkr_TEST(nkr::os::atomic::Exchange_If_Equals(boolean_pointer, nullptr, nullptr) == &boolean);
        nkr_TEST(nkr::os::atomic::Access(boolean_pointer) == &boolean);
        nkr_TEST(nkr::os::atomic::Exchange_If_Equals(boolean_pointer, nullptr, &boolean) == &boolean);
        nkr_TEST(nkr::os::atomic::Access(boolean_pointer) == nullptr);
    }

    void_t Assign_Add()
    {
        wprintf(L"should atomically add to integers and pointers and return the new value");

        u8_t u8 = 8;
        nkr_TEST(nkr::os::atomic::Assign_Add(u8, 1) == 9);

        u16_t u16 = 16;
        nkr_TEST(nkr::os::atomic::Assign_Add(u16, 1) == 17);

        u32_t u32 = 32;
        nkr_TEST(nkr::os::atomic::Assign_Add(u32, 1) == 33);

    #if defined(nkr_IS_64_BIT)
        u64_t u64 = 64;
        nkr_TEST(nkr::os::atomic::Assign_Add(u64, 1) == 65);
    #endif

        s8_t s8 = -8;
        nkr_TEST(nkr::os::atomic::Assign_Add(s8, -1) == -9);

        s16_t s16 = -16;
        nkr_TEST(nkr::os::atomic::Assign_Add(s16, -1) == -17);

        s32_t s32 = -32;
        nkr_TEST(nkr::os::atomic::Assign_Add(s32, -1) == -33);

    #if defined(nkr_IS_64_BIT)
        s64_t s64 = -64;
        nkr_TEST(nkr::os::atomic::Assign_Add(s64, -1) == -65);
    #endif

        bool_t booleans[2] = { true, true };
        bool_t* boolean_pointer = booleans;
        nkr_TEST(nkr::os::atomic::Assign_Add(boolean_pointer, 1) == booleans + 1);
        nkr_TEST(nkr::os::atomic::Assign_Add(boolean_pointer, -1) == booleans + 0);
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

    void_t Assign_Subtract()
    {
        wprintf(L"should atomically subtract from integers and pointers and return the new value");

        u8_t u8 = 8;
        nkr_TEST(nkr::os::atomic::Assign_Subtract(u8, 1) == 7);

        u16_t u16 = 16;
        nkr_TEST(nkr::os::atomic::Assign_Subtract(u16, 1) == 15);

        u32_t u32 = 32;
        nkr_TEST(nkr::os::atomic::Assign_Subtract(u32, 1) == 31);

    #if defined(nkr_IS_64_BIT)
        u64_t u64 = 64;
        nkr_TEST(nkr::os::atomic::Assign_Subtract(u64, 1) == 63);
    #endif

        s8_t s8 = -8;
        nkr_TEST(nkr::os::atomic::Assign_Subtract(s8, -1) == -7);

        s16_t s16 = -16;
        nkr_TEST(nkr::os::atomic::Assign_Subtract(s16, -1) == -15);

        s32_t s32 = -32;
        nkr_TEST(nkr::os::atomic::Assign_Subtract(s32, -1) == -31);

    #if defined(nkr_IS_64_BIT)
        s64_t s64 = -64;
        nkr_TEST(nkr::os::atomic::Assign_Subtract(s64, -1) == -63);
    #endif

        bool_t booleans[2] = { true, true };
        bool_t* boolean_pointer = booleans + 1;
        nkr_TEST(nkr::os::atomic::Assign_Subtract(boolean_pointer, 1) == booleans + 0);
        nkr_TEST(nkr::os::atomic::Assign_Subtract(boolean_pointer, -1) == booleans + 1);
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

    void_t Assign_Or()
    {
        wprintf(L"should atomically OR integers and return the new value");

        u8_t u8 = 0x0F;
        nkr_TEST(nkr::os::atomic::Assign_Or(u8, 0xF0) == 0xFF);

        u16_t u16 = 0x00FF;
        nkr_TEST(nkr::os::atomic::Assign_Or(u16, 0xFF00) == 0xFFFF);

        u32_t u32 = 0x0000FFFF;
        nkr_TEST(nkr::os::atomic::Assign_Or(u32, 0xFFFF0000) == 0xFFFFFFFF);

    #if defined(nkr_IS_64_BIT)
        u64_t u64 = 0x00000000FFFFFFFF;
        nkr_TEST(nkr::os::atomic::Assign_Or(u64, 0xFFFFFFFF00000000) == 0xFFFFFFFFFFFFFFFF);
    #endif

        s8_t s8 = 0x0F;
        nkr_TEST(nkr::os::atomic::Assign_Or(s8, 0x70) == 0x7F);

        s16_t s16 = 0x00FF;
        nkr_TEST(nkr::os::atomic::Assign_Or(s16, 0x7F00) == 0x7FFF);

        s32_t s32 = 0x0000FFFF;
        nkr_TEST(nkr::os::atomic::Assign_Or(s32, 0x7FFF0000) == 0x7FFFFFFF);

    #if defined(nkr_IS_64_BIT)
        s64_t s64 = 0x00000000FFFFFFFF;
        nkr_TEST(nkr::os::atomic::Assign_Or(s64, 0x7FFFFFFF00000000) == 0x7FFFFFFFFFFFFFFF);
    #endif
    }

    void_t Exchange_Or()
    {
        wprintf(L"should atomically OR integers and return the initial value");

        u8_t u8 = 0x0F;
        nkr_TEST(nkr::os::atomic::Exchange_Or(u8, 0xF0) == 0x0F);
        nkr_TEST(nkr::os::atomic::Access(u8) == 0xFF);

        u16_t u16 = 0x00FF;
        nkr_TEST(nkr::os::atomic::Exchange_Or(u16, 0xFF00) == 0x00FF);
        nkr_TEST(nkr::os::atomic::Access(u16) == 0xFFFF);

        u32_t u32 = 0x0000FFFF;
        nkr_TEST(nkr::os::atomic::Exchange_Or(u32, 0xFFFF0000) == 0x0000FFFF);
        nkr_TEST(nkr::os::atomic::Access(u32) == 0xFFFFFFFF);

    #if defined(nkr_IS_64_BIT)
        u64_t u64 = 0x00000000FFFFFFFF;
        nkr_TEST(nkr::os::atomic::Exchange_Or(u64, 0xFFFFFFFF00000000) == 0x00000000FFFFFFFF);
        nkr_TEST(nkr::os::atomic::Access(u64) == 0xFFFFFFFFFFFFFFFF);
    #endif

        s8_t s8 = 0x0F;
        nkr_TEST(nkr::os::atomic::Exchange_Or(s8, 0x70) == 0x0F);
        nkr_TEST(nkr::os::atomic::Access(s8) == 0x7F);

        s16_t s16 = 0x00FF;
        nkr_TEST(nkr::os::atomic::Exchange_Or(s16, 0x7F00) == 0x00FF);
        nkr_TEST(nkr::os::atomic::Access(s16) == 0x7FFF);

        s32_t s32 = 0x0000FFFF;
        nkr_TEST(nkr::os::atomic::Exchange_Or(s32, 0x7FFF0000) == 0x0000FFFF);
        nkr_TEST(nkr::os::atomic::Access(s32) == 0x7FFFFFFF);

    #if defined(nkr_IS_64_BIT)
        s64_t s64 = 0x00000000FFFFFFFF;
        nkr_TEST(nkr::os::atomic::Exchange_Or(s64, 0x7FFFFFFF00000000) == 0x00000000FFFFFFFF);
        nkr_TEST(nkr::os::atomic::Access(s64) == 0x7FFFFFFFFFFFFFFF);
    #endif
    }

    void_t Assign_And()
    {
        wprintf(L"should atomically AND integers and return the new value");

        u8_t u8 = 0x0F;
        nkr_TEST(nkr::os::atomic::Assign_And(u8, 0xF0) == 0x0);

        u16_t u16 = 0x00FF;
        nkr_TEST(nkr::os::atomic::Assign_And(u16, 0xFF00) == 0x0);

        u32_t u32 = 0x0000FFFF;
        nkr_TEST(nkr::os::atomic::Assign_And(u32, 0xFFFF0000) == 0x0);

    #if defined(nkr_IS_64_BIT)
        u64_t u64 = 0x00000000FFFFFFFF;
        nkr_TEST(nkr::os::atomic::Assign_And(u64, 0xFFFFFFFF00000000) == 0x0);
    #endif

        s8_t s8 = 0x0F;
        nkr_TEST(nkr::os::atomic::Assign_And(s8, 0x70) == 0x0);

        s16_t s16 = 0x00FF;
        nkr_TEST(nkr::os::atomic::Assign_And(s16, 0x7F00) == 0x0);

        s32_t s32 = 0x0000FFFF;
        nkr_TEST(nkr::os::atomic::Assign_And(s32, 0x7FFF0000) == 0x0);

    #if defined(nkr_IS_64_BIT)
        s64_t s64 = 0x00000000FFFFFFFF;
        nkr_TEST(nkr::os::atomic::Assign_And(s64, 0x7FFFFFFF00000000) == 0x0);
    #endif
    }

    void_t Exchange_And()
    {
        wprintf(L"should atomically AND integers and return the initial value");

        u8_t u8 = 0x0F;
        nkr_TEST(nkr::os::atomic::Exchange_And(u8, 0xF0) == 0x0F);
        nkr_TEST(nkr::os::atomic::Access(u8) == 0x0);

        u16_t u16 = 0x00FF;
        nkr_TEST(nkr::os::atomic::Exchange_And(u16, 0xFF00) == 0x00FF);
        nkr_TEST(nkr::os::atomic::Access(u16) == 0x0);

        u32_t u32 = 0x0000FFFF;
        nkr_TEST(nkr::os::atomic::Exchange_And(u32, 0xFFFF0000) == 0x0000FFFF);
        nkr_TEST(nkr::os::atomic::Access(u32) == 0x0);

    #if defined(nkr_IS_64_BIT)
        u64_t u64 = 0x00000000FFFFFFFF;
        nkr_TEST(nkr::os::atomic::Exchange_And(u64, 0xFFFFFFFF00000000) == 0x00000000FFFFFFFF);
        nkr_TEST(nkr::os::atomic::Access(u64) == 0x0);
    #endif

        s8_t s8 = 0x0F;
        nkr_TEST(nkr::os::atomic::Exchange_And(s8, 0x70) == 0x0F);
        nkr_TEST(nkr::os::atomic::Access(s8) == 0x0);

        s16_t s16 = 0x00FF;
        nkr_TEST(nkr::os::atomic::Exchange_And(s16, 0x7F00) == 0x00FF);
        nkr_TEST(nkr::os::atomic::Access(s16) == 0x0);

        s32_t s32 = 0x0000FFFF;
        nkr_TEST(nkr::os::atomic::Exchange_And(s32, 0x7FFF0000) == 0x0000FFFF);
        nkr_TEST(nkr::os::atomic::Access(s32) == 0x0);

    #if defined(nkr_IS_64_BIT)
        s64_t s64 = 0x00000000FFFFFFFF;
        nkr_TEST(nkr::os::atomic::Exchange_And(s64, 0x7FFFFFFF00000000) == 0x00000000FFFFFFFF);
        nkr_TEST(nkr::os::atomic::Access(s64) == 0x0);
    #endif
    }

    void_t Assign_Xor()
    {
        wprintf(L"should atomically XOR integers and return the new value");

        u8_t u8 = 0xFF;
        nkr_TEST(nkr::os::atomic::Assign_Xor(u8, 0x01) == 0xFE);

        u16_t u16 = 0xFFFF;
        nkr_TEST(nkr::os::atomic::Assign_Xor(u16, 0x0001) == 0xFFFE);

        u32_t u32 = 0xFFFFFFFF;
        nkr_TEST(nkr::os::atomic::Assign_Xor(u32, 0x00000001) == 0xFFFFFFFE);

    #if defined(nkr_IS_64_BIT)
        u64_t u64 = 0xFFFFFFFFFFFFFFFF;
        nkr_TEST(nkr::os::atomic::Assign_Xor(u64, 0x0000000000000001) == 0xFFFFFFFFFFFFFFFE);
    #endif

        s8_t s8 = 0x7F;
        nkr_TEST(nkr::os::atomic::Assign_Xor(s8, 0x01) == 0x7E);

        s16_t s16 = 0x7FFF;
        nkr_TEST(nkr::os::atomic::Assign_Xor(s16, 0x0001) == 0x7FFE);

        s32_t s32 = 0x7FFFFFFF;
        nkr_TEST(nkr::os::atomic::Assign_Xor(s32, 0x00000001) == 0x7FFFFFFE);

    #if defined(nkr_IS_64_BIT)
        s64_t s64 = 0x7FFFFFFFFFFFFFFF;
        nkr_TEST(nkr::os::atomic::Assign_Xor(s64, 0x0000000000000001) == 0x7FFFFFFFFFFFFFFE);
    #endif
    }

    void_t Exchange_Xor()
    {
        wprintf(L"should atomically XOR integers and return the initial value");

        u8_t u8 = 0xFF;
        nkr_TEST(nkr::os::atomic::Exchange_Xor(u8, 0x01) == 0xFF);
        nkr_TEST(nkr::os::atomic::Access(u8) == 0xFE);

        u16_t u16 = 0xFFFF;
        nkr_TEST(nkr::os::atomic::Exchange_Xor(u16, 0x0001) == 0xFFFF);
        nkr_TEST(nkr::os::atomic::Access(u16) == 0xFFFE);

        u32_t u32 = 0xFFFFFFFF;
        nkr_TEST(nkr::os::atomic::Exchange_Xor(u32, 0x00000001) == 0xFFFFFFFF);
        nkr_TEST(nkr::os::atomic::Access(u32) == 0xFFFFFFFE);

    #if defined(nkr_IS_64_BIT)
        u64_t u64 = 0xFFFFFFFFFFFFFFFF;
        nkr_TEST(nkr::os::atomic::Exchange_Xor(u64, 0x0000000000000001) == 0xFFFFFFFFFFFFFFFF);
        nkr_TEST(nkr::os::atomic::Access(u64) == 0xFFFFFFFFFFFFFFFE);
    #endif

        s8_t s8 = 0x7F;
        nkr_TEST(nkr::os::atomic::Exchange_Xor(s8, 0x01) == 0x7F);
        nkr_TEST(nkr::os::atomic::Access(s8) == 0x7E);

        s16_t s16 = 0x7FFF;
        nkr_TEST(nkr::os::atomic::Exchange_Xor(s16, 0x0001) == 0x7FFF);
        nkr_TEST(nkr::os::atomic::Access(s16) == 0x7FFE);

        s32_t s32 = 0x7FFFFFFF;
        nkr_TEST(nkr::os::atomic::Exchange_Xor(s32, 0x00000001) == 0x7FFFFFFF);
        nkr_TEST(nkr::os::atomic::Access(s32) == 0x7FFFFFFE);

    #if defined(nkr_IS_64_BIT)
        s64_t s64 = 0x7FFFFFFFFFFFFFFF;
        nkr_TEST(nkr::os::atomic::Exchange_Xor(s64, 0x0000000000000001) == 0x7FFFFFFFFFFFFFFF);
        nkr_TEST(nkr::os::atomic::Access(s64) == 0x7FFFFFFFFFFFFFFE);
    #endif
    }

}}}

namespace nkr { namespace test_os { namespace endian {

    void_t Is_Big()
    {
        wprintf(L"should in a thread-safe manner efficiently determine if the runtime is in big endian");

        wprintf(L": %s", nkr::os::endian::Is_Big() ? L"is big" : L"isn't big");
    }

    void_t Is_Little()
    {
        wprintf(L"should in a thread-safe manner efficiently determine if the runtime is in little endian");

        wprintf(L": %s", nkr::os::endian::Is_Little() ? L"is little" : L"isn't little");
    }

    void_t Swap()
    {
        wprintf(L"should swap the bytes of i16_tr, i32_tr, and i64_tr");

        u16_t u16 = 0x0102;
        nkr_TEST(nkr::os::endian::Swap(u16) == 0x0201);

        u32_t u32 = 0x01020304;
        nkr_TEST(nkr::os::endian::Swap(u32) == 0x04030201);

        u64_t u64 = 0x0102030405060708;
        nkr_TEST(nkr::os::endian::Swap(u64) == 0x0807060504030201);

        s16_t s16 = 0x0102;
        nkr_TEST(nkr::os::endian::Swap(s16) == 0x0201);

        s32_t s32 = 0x01020304;
        nkr_TEST(nkr::os::endian::Swap(s32) == 0x04030201);

        s64_t s64 = 0x0102030405060708;
        nkr_TEST(nkr::os::endian::Swap(s64) == 0x0807060504030201);

        nkr_TEST(nkr::os::endian::Swap(0x0102) == 0x02010000);
        nkr_TEST(nkr::os::endian::Swap(0x01020304) == 0x04030201);
        nkr_TEST(nkr::os::endian::Swap(0x0102030405060708) == 0x0807060504030201);
    }

}}}

namespace nkr { namespace test_os { namespace heap {

    void_t Allocate()
    {
        //wprintf(L"should allocate a pointer to have the byte_count on the heap");
    }

    void_t Reallocate()
    {
        //wprintf(L"should reallocate the pointer to have the new_byte_count on the heap");
    }

    void_t Deallocate()
    {
        //wprintf(L"should deallocate the pointer");
    }

    void_t Callocate()
    {
        //wprintf(L"should allocate a pointer to have the byte_count on the heap and set all data to 0");
    }

    void_t Recallocate()
    {
        //wprintf(L"should reallocate the pointer to have the new_byte_count on the heap and set all data to 0");
    }

    void_t Decallocate()
    {
        //wprintf(L"should deallocate the pointer");
    }

}}}
