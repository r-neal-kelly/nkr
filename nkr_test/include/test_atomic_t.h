/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "intrinsic.h"

namespace nkr { namespace test_atomic_t {

    void_t  Execute();

}}

namespace nkr { namespace test_atomic_t { namespace $default { namespace $object {

    void_t  Constructor_Default();
    void_t  Constructor_Value();
    void_t  Constructor_Copy();
    void_t  Constructor_Move();
    void_t  Assigner_Copy();
    void_t  Assigner_Move();
    void_t  Destructor();

}}}}

namespace nkr { namespace test_atomic_t { namespace $default { namespace $method {

    void_t  Access();

    void_t  Assign();
    void_t  Exchange_Assign();
    void_t  Exchange_Assign_If_Equals();

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

}}}}

namespace nkr { namespace test_atomic_t { namespace $default { namespace $cast {

    void_t  Value_t();

}}}}

namespace nkr { namespace test_atomic_t { namespace $default { namespace $operator {

    void_t  Invoke();

    void_t  Assign();

    void_t  Add();
    void_t  Subtract();
    void_t  Add_Assign();
    void_t  Subtract_Assign();
    void_t  Increment_Pre();
    void_t  Increment_Post();
    void_t  Decrement_Pre();
    void_t  Decrement_Post();

    void_t  Bitwise_Not();
    void_t  Bitwise_Or();
    void_t  Bitwise_And();
    void_t  Bitwise_Xor();
    void_t  Bitwise_Or_Assign();
    void_t  Bitwise_And_Assign();
    void_t  Bitwise_Xor_Assign();

}}}}

namespace nkr { namespace test_atomic_t { namespace $bool_t { namespace $object {

    void_t  Constructor_Default();
    void_t  Constructor_Value();
    void_t  Constructor_Copy();
    void_t  Constructor_Move();
    void_t  Assigner_Copy();
    void_t  Assigner_Move();
    void_t  Destructor();

}}}}

namespace nkr { namespace test_atomic_t { namespace $bool_t { namespace $method {

    void_t  Access();

    void_t  Assign();
    void_t  Exchange_Assign();
    void_t  Exchange_Assign_If_Equals();

}}}}

namespace nkr { namespace test_atomic_t { namespace $bool_t { namespace $cast {

    void_t  Value_t();

}}}}

namespace nkr { namespace test_atomic_t { namespace $bool_t { namespace $operator {

    void_t  Invoke();

    void_t  Assign();

}}}}

namespace nkr { namespace test_atomic_t { namespace $pointer { namespace $object {

    void_t  Constructor_Default();
    void_t  Constructor_Value_Pointer();
    void_t  Constructor_Copy();
    void_t  Constructor_Move();
    void_t  Assigner_Copy();
    void_t  Assigner_Move();
    void_t  Destructor();

}}}}

namespace nkr { namespace test_atomic_t { namespace $pointer { namespace $method {

    void_t  Access();

    void_t  Assign();
    void_t  Exchange_Assign();
    void_t  Exchange_Assign_If_Equals();

    void_t  Assign_Add();
    void_t  Exchange_Add();
    void_t  Assign_Subtract();
    void_t  Exchange_Subtract();

}}}}

namespace nkr { namespace test_atomic_t { namespace $pointer { namespace $cast {

    void_t  Value_t_Pointer();

}}}}

namespace nkr { namespace test_atomic_t { namespace $pointer { namespace $operator {

    void_t  Invoke();

    void_t  Assign();

    void_t  Add();
    void_t  Subtract();
    void_t  Add_Assign();
    void_t  Subtract_Assign();
    void_t  Increment_Pre();
    void_t  Increment_Post();
    void_t  Decrement_Pre();
    void_t  Decrement_Post();

    void_t  Access();
    void_t  Dereference();
    void_t  Subscript();

}}}}

namespace nkr { namespace test_atomic_t { namespace $void_pointer { namespace $object {

    void_t  Constructor_Default();
    void_t  Constructor_Value_Pointer();
    void_t  Constructor_Copy();
    void_t  Constructor_Move();
    void_t  Assigner_Copy();
    void_t  Assigner_Move();
    void_t  Destructor();

}}}}

namespace nkr { namespace test_atomic_t { namespace $void_pointer { namespace $method {

    void_t  Access();

    void_t  Assign();
    void_t  Exchange_Assign();
    void_t  Exchange_Assign_If_Equals();

}}}}

namespace nkr { namespace test_atomic_t { namespace $void_pointer { namespace $cast {

    void_t  Value_t_Pointer();

}}}}

namespace nkr { namespace test_atomic_t { namespace $void_pointer { namespace $operator {

    void_t  Invoke();

    void_t  Assign();

}}}}
