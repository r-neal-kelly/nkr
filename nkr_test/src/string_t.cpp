/*
    Copyright 2021 r-neal-kelly
*/

#include "string_t.h"

namespace nkr { namespace test {

    test_string_t::test_string_t()
    {
        wprintf(L"test_string_t\n");

        NKR_TEST_METHOD(unit_size);

        wprintf(L"\n");
    }

    void_t test_string_t::unit_size()
    {
        wprintf(L"should have the same unit_size as its charcoder");

        NKR_TEST(string_t<>::unit_size() == string_t<>::charcoder_t::UNIT_SIZE);
    }

}}
