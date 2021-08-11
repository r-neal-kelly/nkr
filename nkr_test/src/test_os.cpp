/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "test_os.h"

namespace nkr { namespace test { namespace os {

    void_t Execute()
    {
        wprintf(L"os\n");

        nkr_TEST_FUNCTION(atomic::Exchange_Assign);
        wprintf(L"\n");

        nkr_TEST_FUNCTION(atomic::Exchange_Add);
        wprintf(L"\n");

        nkr_TEST_FUNCTION(atomic::Exchange_Subtract);
        wprintf(L"\n");

        nkr_TEST_FUNCTION(atomic::Exchange_Or);
        wprintf(L"\n");

        nkr_TEST_FUNCTION(atomic::Exchange_And);
        wprintf(L"\n");

        nkr_TEST_FUNCTION(atomic::Exchange_Xor);
        wprintf(L"\n");
    }

}}}

namespace nkr { namespace test { namespace os { namespace atomic {

    void_t Exchange_Assign()
    {
        wprintf(L"should atomically assign integers and pointers and return the initial value");

        bool_t boolean = false;
        nkr_TEST(nkr::os::atomic::Exchange_Assign(boolean, true) == false);
        nkr_TEST(nkr::os::atomic::Access(boolean) == true);
    }

    void_t Exchange_Add()
    {
        wprintf(L"should atomically add to integers and pointers and return the initial value");

        char cs[2] = { 'a', 'b' };
        char* p = cs;
        nkr_TEST(*nkr::os::atomic::Exchange_Add(p, 1) == 'a');
        nkr_TEST(*nkr::os::atomic::Access(p) == 'b');
    }

    void_t Exchange_Subtract()
    {
        wprintf(L"should atomically subtract from integers and pointers and return the initial value");

        char cs[2] = { 'a', 'b' };
        char* p = cs + 1;
        nkr_TEST(*nkr::os::atomic::Exchange_Subtract(p, 1) == 'b');
        nkr_TEST(*nkr::os::atomic::Access(p) == 'a');
    }

    void_t Exchange_Or()
    {
        wprintf(L"should atomically OR integers and return the initial value");

        u8_t u8 = 0x0F;
        nkr_TEST(nkr::os::atomic::Exchange_Or(u8, 0xF0) == 0x0F);
        nkr_TEST(nkr::os::atomic::Access(u8) == 0xFF);
    }

    void_t Exchange_And()
    {
        wprintf(L"should atomically AND integers and return the initial value");

        u8_t u8 = 0x1;
        nkr_TEST(nkr::os::atomic::Exchange_And(u8, 0x3) == 0x1);
        nkr_TEST(nkr::os::atomic::Access(u8) == 0x1);
    }

    void_t Exchange_Xor()
    {
        wprintf(L"should atomically XOR integers and return the initial value");

        u8_t u8 = 0x1;
        nkr_TEST(nkr::os::atomic::Exchange_Xor(u8, 0x3) == 0x1);
        nkr_TEST(nkr::os::atomic::Access(u8) == 0x2);
    }

}}}}
