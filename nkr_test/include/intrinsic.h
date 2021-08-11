/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include <cassert>
#include <cstdio>
#include <cstdlib>

#include "nkr/intrinsic.h"

#define nkr_TEST_METHOD(METHOD_p)       \
{                                       \
    wprintf(L"    " L#METHOD_p L": ");  \
    METHOD_p();                         \
    wprintf(L"... ok!\n");              \
}

#define nkr_TEST_FUNCTION nkr_TEST_METHOD

#define nkr_TEST(EXPRESSION_p)                                      \
{                                                                   \
    if (!(EXPRESSION_p)) {                                          \
        wprintf(L"\n\nfailed test: " L#EXPRESSION_p L"\n");         \
        wprintf(L"in file '%s' on line %i", __FILEW__, __LINE__);   \
        wchar_t unused = std::getwc(stdin);                         \
        std::exit(1);                                               \
    }                                                               \
}

namespace nkr { namespace test {



}}
