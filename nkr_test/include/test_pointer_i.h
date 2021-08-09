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
        void_t  unit_size() const;
        void_t  max_unit_count() const;

    public:
        void_t  constructor_default() const;
        void_t  constructor_unit_pointer() const;
        void_t  constructor_units_and_unit_count() const;
        void_t  constructor_copy() const;
        void_t  constructor_move() const;
        void_t  assigner_copy() const;
        void_t  assigner_move() const;
        void_t  destructor() const;

    public:
        void_t  operator_bool_t() const;
        void_t  operator_const_bool_t() const;

        void_t  operator_units_t_ref() const;
        void_t  operator_const_units_t_ref() const;

        void_t  operator_count_t_ref() const;
        void_t  operator_const_count_t_ref() const;

    public:
        void_t  operator_logical_not() const;

        void_t  operator_invoke() const;
        void_t  operator_invoke_const() const;

        void_t  operator_access_const() const;
        void_t  operator_dereference_const() const;
        void_t  operator_subscript_const() const;

        void_t  operator_increment_pre() const;
        void_t  operator_increment_post() const;
        void_t  operator_decrement_pre() const;
        void_t  operator_decrement_post() const;

        void_t  operator_add_assign() const;
        void_t  operator_subtract_assign() const;

        void_t  operator_add() const;
        void_t  operator_subtract() const;

    public:
        void_t  raw() const;
        void_t  raw_const() const;

        void_t  count() const;
        void_t  count_const() const;

        void_t  address() const;
    };

}}
