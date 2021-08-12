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
        wprintf(L"should atomically access integers and pointers and return their value");

        bool_t boolean = false;
        nkr_TEST(nkr::os::atomic::Access(boolean) == false);

        u8_t u8 = 8;
        nkr_TEST(nkr::os::atomic::Access(u8) == 8);

        u16_t u16 = 16;
        nkr_TEST(nkr::os::atomic::Access(u16) == 16);

        u32_t u32 = 32;
        nkr_TEST(nkr::os::atomic::Access(u32) == 32);

        u64_t u64 = 64;
        nkr_TEST(nkr::os::atomic::Access(u64) == 64);

        s8_t s8 = -8;
        nkr_TEST(nkr::os::atomic::Access(s8) == -8);

        s16_t s16 = -16;
        nkr_TEST(nkr::os::atomic::Access(s16) == -16);

        s32_t s32 = -32;
        nkr_TEST(nkr::os::atomic::Access(s32) == -32);

        s64_t s64 = -64;
        nkr_TEST(nkr::os::atomic::Access(s64) == -64);

        void_t* void_pointer = &u64;
        nkr_TEST(nkr::os::atomic::Access(void_pointer) == &u64);

        u64_t* u64_pointer = &u64;
        nkr_TEST(nkr::os::atomic::Access(u64_pointer) == &u64);
    }

    void_t Assign()
    {
        wprintf(L"should atomically assign integers and pointers and return their new value");

        bool_t boolean = false;
        nkr_TEST(nkr::os::atomic::Assign(boolean, true) == true);

        u8_t u8 = 8;
        nkr_TEST(nkr::os::atomic::Assign(u8, 1) == 1);

        u16_t u16 = 16;
        nkr_TEST(nkr::os::atomic::Assign(u16, 1) == 1);

        u32_t u32 = 32;
        nkr_TEST(nkr::os::atomic::Assign(u32, 1) == 1);

        u64_t u64 = 64;
        nkr_TEST(nkr::os::atomic::Assign(u64, 1) == 1);

        s8_t s8 = -8;
        nkr_TEST(nkr::os::atomic::Assign(s8, -1) == -1);

        s16_t s16 = -16;
        nkr_TEST(nkr::os::atomic::Assign(s16, -1) == -1);

        s32_t s32 = -32;
        nkr_TEST(nkr::os::atomic::Assign(s32, -1) == -1);

        s64_t s64 = -64;
        nkr_TEST(nkr::os::atomic::Assign(s64, -1) == -1);

        void_t* void_pointer = &u64;
        nkr_TEST(nkr::os::atomic::Assign(void_pointer, &u8) == &u8);

        u64_t* u64_pointer = &u64;
        nkr_TEST(nkr::os::atomic::Assign(u64_pointer, nullptr) == nullptr);
    }

    void_t Exchange_Assign()
    {
        wprintf(L"should atomically assign integers and pointers and return their initial value");

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

        u64_t u64 = 64;
        nkr_TEST(nkr::os::atomic::Exchange_Assign(u64, 1) == 64);
        nkr_TEST(nkr::os::atomic::Access(u64) == 1);

        s8_t s8 = -8;
        nkr_TEST(nkr::os::atomic::Exchange_Assign(s8, -1) == -8);
        nkr_TEST(nkr::os::atomic::Access(s8) == -1);

        s16_t s16 = -16;
        nkr_TEST(nkr::os::atomic::Exchange_Assign(s16, -1) == -16);
        nkr_TEST(nkr::os::atomic::Access(s16) == -1);

        s32_t s32 = -32;
        nkr_TEST(nkr::os::atomic::Exchange_Assign(s32, -1) == -32);
        nkr_TEST(nkr::os::atomic::Access(s32) == -1);

        s64_t s64 = -64;
        nkr_TEST(nkr::os::atomic::Exchange_Assign(s64, -1) == -64);
        nkr_TEST(nkr::os::atomic::Access(s64) == -1);

        void_t* void_pointer = &u64;
        nkr_TEST(nkr::os::atomic::Exchange_Assign(void_pointer, &u8) == &u64);
        nkr_TEST(nkr::os::atomic::Access(void_pointer) == &u8);

        u64_t* u64_pointer = &u64;
        nkr_TEST(nkr::os::atomic::Exchange_Assign(u64_pointer, nullptr) == &u64);
        nkr_TEST(nkr::os::atomic::Access(u64_pointer) == nullptr);
    }

    void_t Exchange_Assign_If_Equals()
    {
        wprintf(L"should atomically assign integers and pointers and return their initial value if they equal target");

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

        u64_t u64 = 64;
        nkr_TEST(nkr::os::atomic::Exchange_Assign_If_Equals(u64, 1, 1) == 64);
        nkr_TEST(nkr::os::atomic::Access(u64) == 64);
        nkr_TEST(nkr::os::atomic::Exchange_Assign_If_Equals(u64, 1, 64) == 64);
        nkr_TEST(nkr::os::atomic::Access(u64) == 1);

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

        s64_t s64 = -64;
        nkr_TEST(nkr::os::atomic::Exchange_Assign_If_Equals(s64, -1, -1) == -64);
        nkr_TEST(nkr::os::atomic::Access(s64) == -64);
        nkr_TEST(nkr::os::atomic::Exchange_Assign_If_Equals(s64, -1, -64) == -64);
        nkr_TEST(nkr::os::atomic::Access(s64) == -1);

        void_t* void_pointer = &u64;
        nkr_TEST(nkr::os::atomic::Exchange_Assign_If_Equals(void_pointer, &u8, &u8) == &u64);
        nkr_TEST(nkr::os::atomic::Access(void_pointer) == &u64);
        nkr_TEST(nkr::os::atomic::Exchange_Assign_If_Equals(void_pointer, &u8, &u64) == &u64);
        nkr_TEST(nkr::os::atomic::Access(void_pointer) == &u8);

        u64_t* u64_pointer = &u64;
        nkr_TEST(nkr::os::atomic::Exchange_Assign_If_Equals(u64_pointer, nullptr, nullptr) == &u64);
        nkr_TEST(nkr::os::atomic::Access(u64_pointer) == &u64);
        nkr_TEST(nkr::os::atomic::Exchange_Assign_If_Equals(u64_pointer, nullptr, &u64) == &u64);
        nkr_TEST(nkr::os::atomic::Access(u64_pointer) == nullptr);
    }

    void_t Add()
    {

    }

    void_t Exchange_Add()
    {
        wprintf(L"should atomically add to integers and pointers and return their initial value");

        char cs[2] = { 'a', 'b' };
        char* p = cs;
        nkr_TEST(*nkr::os::atomic::Exchange_Add(p, 1) == 'a');
        nkr_TEST(*nkr::os::atomic::Access(p) == 'b');
    }

    void_t Subtract()
    {

    }

    void_t Exchange_Subtract()
    {
        wprintf(L"should atomically subtract from integers and pointers and return their initial value");

        char cs[2] = { 'a', 'b' };
        char* p = cs + 1;
        nkr_TEST(*nkr::os::atomic::Exchange_Subtract(p, 1) == 'b');
        nkr_TEST(*nkr::os::atomic::Access(p) == 'a');
    }

    void_t Or()
    {

    }

    void_t Exchange_Or()
    {
        wprintf(L"should atomically OR integers and return their initial value");

        u8_t u8 = 0x0F;
        nkr_TEST(nkr::os::atomic::Exchange_Or(u8, 0xF0) == 0x0F);
        nkr_TEST(nkr::os::atomic::Access(u8) == 0xFF);
    }

    void_t And()
    {

    }

    void_t Exchange_And()
    {
        wprintf(L"should atomically AND integers and return their initial value");

        u8_t u8 = 0x1;
        nkr_TEST(nkr::os::atomic::Exchange_And(u8, 0x3) == 0x1);
        nkr_TEST(nkr::os::atomic::Access(u8) == 0x1);
    }

    void_t Xor()
    {

    }

    void_t Exchange_Xor()
    {
        wprintf(L"should atomically XOR integers and return their initial value");

        u8_t u8 = 0x1;
        nkr_TEST(nkr::os::atomic::Exchange_Xor(u8, 0x3) == 0x1);
        nkr_TEST(nkr::os::atomic::Access(u8) == 0x2);
    }

}}}}
