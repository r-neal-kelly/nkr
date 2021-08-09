/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/pointer_i.h"

#include "intrinsic.h"

namespace nkr { namespace test {

    class test_pointer_i
    {
    public:
        test_pointer_i();
        test_pointer_i(const test_pointer_i& other)                 = delete;
        test_pointer_i(test_pointer_i&& other) noexcept             = delete;
        test_pointer_i& operator =(const test_pointer_i& other)     = delete;
        test_pointer_i& operator =(test_pointer_i&& other) noexcept = delete;
        ~test_pointer_i();

    public:
        void_t  unit_size();

    public:
        void_t  constructor_default();
        void_t  constructor_unit_reference();
        void_t  constructor_unit_pointer();
        void_t  constructor_units_and_unit_count();
        void_t  constructor_copy();
        void_t  constructor_move();
        void_t  assigner_copy();
        void_t  assigner_move();
        void_t  destructor();

    public:
        void_t  operator_bool_t();
        void_t  operator_const_bool_t();

        void_t  operator_units_t_ref();
        void_t  operator_const_units_t_ref();

        void_t  operator_count_t_ref();
        void_t  operator_const_count_t_ref();

    public:
        void_t  operator_logical_not();

        void_t  operator_invoke();
        void_t  operator_invoke_const();

        void_t  operator_access_const();
        void_t  operator_dereference_const();
        void_t  operator_subscript_const();
    };

}}
