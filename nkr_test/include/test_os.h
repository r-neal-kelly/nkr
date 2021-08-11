/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/os.h"

#include "intrinsic.h"

namespace nkr { namespace test { namespace os {

    void_t  Execute();

}}}

namespace nkr { namespace test { namespace os { namespace atomic {

    void_t  Exchange_Assign();

    void_t  Exchange_Add();

    void_t  Exchange_Subtract();

    void_t  Exchange_Or();

    void_t  Exchange_And();

    void_t  Exchange_Xor();

}}}}
