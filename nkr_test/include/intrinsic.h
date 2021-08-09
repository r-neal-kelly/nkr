/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include <cassert>
#include <cstdio>
#include <cstdlib>

#include "nkr/intrinsic.h"

#define NKR_TEST_METHOD(METHOD_)        \
{                                       \
    wprintf(L"    " L#METHOD_ L": ");   \
    METHOD_();                          \
    wprintf(L"... ok!\n");              \
}

#define NKR_TEST(EXPRESSION_)                                       \
{                                                                   \
    if (!(EXPRESSION_)) {                                           \
        wprintf(L"\n\nfailed test: " L#EXPRESSION_ L"\n");          \
        wprintf(L"in file '%s' on line %i", __FILEW__, __LINE__);   \
        wchar_t unused = std::getwc(stdin);                         \
        std::exit(1);                                               \
    }                                                               \
}

namespace nkr { namespace test {



}}
