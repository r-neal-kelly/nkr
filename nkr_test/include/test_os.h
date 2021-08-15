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
    void_t  Exchange();
    void_t  Exchange_If_Equals();

    void_t  Assign_Add();
    void_t  Exchange_Add();

    void_t  Assign_Subtract();
    void_t  Exchange_Subtract();

    void_t  Assign_Or();
    void_t  Exchange_Or();

    void_t  Assign_And();
    void_t  Exchange_And();

    void_t  Assign_Xor();
    void_t  Exchange_Xor();

}}}

namespace nkr { namespace test_os { namespace endian {

    void_t  Is_Big();
    void_t  Is_Little();

    void_t  Swap();

}}}

namespace nkr { namespace test_os { namespace heap {

    void_t  Allocate();
    void_t  Reallocate();
    void_t  Deallocate();

    void_t  Callocate();
    void_t  Recallocate();
    void_t  Decallocate();

}}}
