/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/os.h"

#include "intrinsic.h"

namespace nkr { namespace test_os {

    void_t  Execute();

}}

namespace nkr { namespace test_os { namespace atomic {

    void_t  Access();

    void_t  Assign();
    void_t  Exchange_Assign();
    void_t  Exchange_Assign_If_Equals();

    void_t  Add();
    void_t  Exchange_Add();

    void_t  Subtract();
    void_t  Exchange_Subtract();

    void_t  Or();
    void_t  Exchange_Or();

    void_t  And();
    void_t  Exchange_And();

    void_t  Xor();
    void_t  Exchange_Xor();

}}}

namespace nkr { namespace test_os { namespace endian {

    void_t  Is_Big();
    void_t  Is_Little();

}}}
