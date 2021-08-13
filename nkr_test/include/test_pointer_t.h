/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/pointer_t.h"

#include "intrinsic.h"

namespace nkr { namespace test_pointer_t {

    void_t  Execute();

}}

namespace nkr { namespace test_pointer_t { namespace $static {

    void_t  Unit_Size();
    void_t  Max_Unit_Count();

}}}

namespace nkr { namespace test_pointer_t { namespace $object {

    void_t  Constructor_Default();
    void_t  Constructor_Unit_Pointer();
    void_t  Constructor_Units_And_Unit_Count();
    void_t  Constructor_Copy();
    void_t  Constructor_Move();
    void_t  Assigner_Copy();
    void_t  Assigner_Move();
    void_t  Destructor();

}}}

namespace nkr { namespace test_pointer_t { namespace $method {

    void_t  Units();
    void_t  Units_Const();

    void_t  Unit_Count();
    void_t  Unit_Count_Const();

    void_t  Address();

}}}

namespace nkr { namespace test_pointer_t { namespace $cast {

    void_t  Bool_t();
    void_t  Const_Bool_t();

    void_t  Units_t_Ref();
    void_t  Const_Units_t_Ref();

}}}

namespace nkr { namespace test_pointer_t { namespace $operator {

    void_t  Logical_Not();

    void_t  Invoke();
    void_t  Invoke_Const();

    void_t  Access_Const();
    void_t  Dereference_Const();
    void_t  Subscript_Const();

    void_t  Increment_Pre();
    void_t  Increment_Post();
    void_t  Decrement_Pre();
    void_t  Decrement_Post();

    void_t  Add_Assign();
    void_t  Subtract_Assign();

    void_t  Add();
    void_t  Subtract();

}}}
