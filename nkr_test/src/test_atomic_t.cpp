/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/atomic_t.h"

#include "test_atomic_t.h"

namespace nkr { namespace test_atomic_t {

    void_t Execute()
    {
        wprintf(L"atomic_t\n");

        nkr_TEST_FUNCTION($default::$object::Constructor_Default);
        nkr_TEST_FUNCTION($default::$object::Constructor_Value);
        nkr_TEST_FUNCTION($default::$object::Constructor_Copy);
        nkr_TEST_FUNCTION($default::$object::Constructor_Move);
        nkr_TEST_FUNCTION($default::$object::Assigner_Copy);
        nkr_TEST_FUNCTION($default::$object::Assigner_Move);
        nkr_TEST_FUNCTION($default::$object::Destructor);
        wprintf(L"\n");

        nkr_TEST_FUNCTION($default::$method::Access);
        nkr_TEST_FUNCTION($default::$method::Exchange);
        wprintf(L"\n");

        nkr_TEST_FUNCTION($default::$cast::Bool_t);
        nkr_TEST_FUNCTION($default::$cast::Value_t);
        wprintf(L"\n");

        nkr_TEST_FUNCTION($default::$operator::Logical_Not);
        wprintf(L"\n");

        nkr_TEST_FUNCTION($default::$operator::Invoke);
        wprintf(L"\n");

        nkr_TEST_FUNCTION($default::$operator::Assign);
        wprintf(L"\n");

        nkr_TEST_FUNCTION($default::$operator::Add);
        nkr_TEST_FUNCTION($default::$operator::Subtract);
        nkr_TEST_FUNCTION($default::$operator::Add_Assign);
        nkr_TEST_FUNCTION($default::$operator::Subtract_Assign);
        nkr_TEST_FUNCTION($default::$operator::Increment_Pre);
        nkr_TEST_FUNCTION($default::$operator::Increment_Post);
        nkr_TEST_FUNCTION($default::$operator::Decrement_Pre);
        nkr_TEST_FUNCTION($default::$operator::Decrement_Post);
        wprintf(L"\n");

        nkr_TEST_FUNCTION($default::$operator::Bitwise_Not);
        nkr_TEST_FUNCTION($default::$operator::Bitwise_Or);
        nkr_TEST_FUNCTION($default::$operator::Bitwise_And);
        nkr_TEST_FUNCTION($default::$operator::Bitwise_Xor);
        nkr_TEST_FUNCTION($default::$operator::Bitwise_Or_Assign);
        nkr_TEST_FUNCTION($default::$operator::Bitwise_And_Assign);
        nkr_TEST_FUNCTION($default::$operator::Bitwise_Xor_Assign);
        wprintf(L"\n");

        nkr_TEST_FUNCTION($bool_t::$object::Constructor_Default);
        nkr_TEST_FUNCTION($bool_t::$object::Constructor_Value);
        nkr_TEST_FUNCTION($bool_t::$object::Constructor_Copy);
        nkr_TEST_FUNCTION($bool_t::$object::Constructor_Move);
        nkr_TEST_FUNCTION($bool_t::$object::Assigner_Copy);
        nkr_TEST_FUNCTION($bool_t::$object::Assigner_Move);
        nkr_TEST_FUNCTION($bool_t::$object::Destructor);
        wprintf(L"\n");

        nkr_TEST_FUNCTION($bool_t::$method::Access);
        nkr_TEST_FUNCTION($bool_t::$method::Exchange);
        wprintf(L"\n");

        nkr_TEST_FUNCTION($bool_t::$cast::Value_t);
        wprintf(L"\n");

        nkr_TEST_FUNCTION($bool_t::$operator::Logical_Not);
        wprintf(L"\n");

        nkr_TEST_FUNCTION($bool_t::$operator::Invoke);
        wprintf(L"\n");

        nkr_TEST_FUNCTION($bool_t::$operator::Assign);
        wprintf(L"\n");

        nkr_TEST_FUNCTION($pointer::$object::Constructor_Default);
        nkr_TEST_FUNCTION($pointer::$object::Constructor_Values);
        nkr_TEST_FUNCTION($pointer::$object::Constructor_Copy);
        nkr_TEST_FUNCTION($pointer::$object::Constructor_Move);
        nkr_TEST_FUNCTION($pointer::$object::Assigner_Copy);
        nkr_TEST_FUNCTION($pointer::$object::Assigner_Move);
        nkr_TEST_FUNCTION($pointer::$object::Destructor);
        wprintf(L"\n");

        nkr_TEST_FUNCTION($pointer::$method::Access);
        nkr_TEST_FUNCTION($pointer::$method::Exchange);
        wprintf(L"\n");

        nkr_TEST_FUNCTION($pointer::$cast::Bool_t);
        nkr_TEST_FUNCTION($pointer::$cast::Values_t);
        wprintf(L"\n");

        nkr_TEST_FUNCTION($pointer::$operator::Logical_Not);
        wprintf(L"\n");

        nkr_TEST_FUNCTION($pointer::$operator::Invoke);
        wprintf(L"\n");

        nkr_TEST_FUNCTION($pointer::$operator::Assign);
        wprintf(L"\n");

        nkr_TEST_FUNCTION($pointer::$operator::Add);
        nkr_TEST_FUNCTION($pointer::$operator::Subtract);
        nkr_TEST_FUNCTION($pointer::$operator::Add_Assign);
        nkr_TEST_FUNCTION($pointer::$operator::Subtract_Assign);
        nkr_TEST_FUNCTION($pointer::$operator::Increment_Pre);
        nkr_TEST_FUNCTION($pointer::$operator::Increment_Post);
        nkr_TEST_FUNCTION($pointer::$operator::Decrement_Pre);
        nkr_TEST_FUNCTION($pointer::$operator::Decrement_Post);
        wprintf(L"\n");

        nkr_TEST_FUNCTION($pointer::$operator::Access);
        nkr_TEST_FUNCTION($pointer::$operator::Dereference);
        nkr_TEST_FUNCTION($pointer::$operator::Subscript);
        wprintf(L"\n");
    }

}}

namespace nkr { namespace test_atomic_t { namespace $default { namespace $object {

    void_t Constructor_Default()
    {
    }

    void_t Constructor_Value()
    {
    }

    void_t Constructor_Copy()
    {
    }

    void_t Constructor_Move()
    {
    }

    void_t Assigner_Copy()
    {
    }

    void_t Assigner_Move()
    {
    }

    void_t Destructor()
    {
    }

}}}}

namespace nkr { namespace test_atomic_t { namespace $default { namespace $method {

    void_t Access()
    {
    }

    void_t Exchange()
    {
    }

}}}}

namespace nkr { namespace test_atomic_t { namespace $default { namespace $cast {

    void_t Bool_t()
    {
    }

    void_t Value_t()
    {
    }

}}}}

namespace nkr { namespace test_atomic_t { namespace $default { namespace $operator {

    void_t Logical_Not()
    {
    }

    void_t Invoke()
    {
    }

    void_t Assign()
    {
    }

    void_t Add()
    {
    }

    void_t Subtract()
    {
    }

    void_t Add_Assign()
    {
    }

    void_t Subtract_Assign()
    {
    }

    void_t Increment_Pre()
    {
    }

    void_t Increment_Post()
    {
    }

    void_t Decrement_Pre()
    {
    }

    void_t Decrement_Post()
    {
    }

    void_t Bitwise_Not()
    {
    }

    void_t Bitwise_Or()
    {
    }

    void_t Bitwise_And()
    {
    }

    void_t Bitwise_Xor()
    {
    }

    void_t Bitwise_Or_Assign()
    {
    }

    void_t Bitwise_And_Assign()
    {
    }

    void_t Bitwise_Xor_Assign()
    {
    }

}}}}

namespace nkr { namespace test_atomic_t { namespace $bool_t { namespace $object {

    void_t Constructor_Default()
    {
    }

    void_t Constructor_Value()
    {
    }

    void_t Constructor_Copy()
    {
    }

    void_t Constructor_Move()
    {
    }

    void_t Assigner_Copy()
    {
    }

    void_t Assigner_Move()
    {
    }

    void_t Destructor()
    {
    }

}}}}

namespace nkr { namespace test_atomic_t { namespace $bool_t { namespace $method {

    void_t Access()
    {
    }

    void_t Exchange()
    {
    }

}}}}

namespace nkr { namespace test_atomic_t { namespace $bool_t { namespace $cast {

    void_t Value_t()
    {
    }

}}}}

namespace nkr { namespace test_atomic_t { namespace $bool_t { namespace $operator {

    void_t Logical_Not()
    {
    }

    void_t Invoke()
    {
    }

    void_t Assign()
    {
    }

}}}}

namespace nkr { namespace test_atomic_t { namespace $pointer { namespace $object {

    void_t Constructor_Default()
    {
    }

    void_t Constructor_Values()
    {
    }

    void_t Constructor_Copy()
    {
    }

    void_t Constructor_Move()
    {
    }

    void_t Assigner_Copy()
    {
    }

    void_t Assigner_Move()
    {
    }

    void_t Destructor()
    {
    }

}}}}

namespace nkr { namespace test_atomic_t { namespace $pointer { namespace $method {

    void_t Access()
    {
    }

    void_t Exchange()
    {
    }

}}}}

namespace nkr { namespace test_atomic_t { namespace $pointer { namespace $cast {

    void_t Bool_t()
    {
    }

    void_t Values_t()
    {
    }

}}}}

namespace nkr { namespace test_atomic_t { namespace $pointer { namespace $operator {

    void_t Logical_Not()
    {
    }

    void_t Invoke()
    {
    }

    void_t Assign()
    {
    }

    void_t Add()
    {
    }

    void_t Subtract()
    {
    }

    void_t Add_Assign()
    {
    }

    void_t Subtract_Assign()
    {
    }

    void_t Increment_Pre()
    {
    }

    void_t Increment_Post()
    {
    }

    void_t Decrement_Pre()
    {
    }

    void_t Decrement_Post()
    {
    }

    void_t Access()
    {
    }

    void_t Dereference()
    {
    }

    void_t Subscript()
    {
    }

}}}}
