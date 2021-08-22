/*
    Copyright 2021 r-neal-kelly
*/

/*
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
        nkr_TEST_FUNCTION($default::$method::Access_Add);
        nkr_TEST_FUNCTION($default::$method::Access_Subtract);
        nkr_TEST_FUNCTION($default::$method::Access_Or);
        nkr_TEST_FUNCTION($default::$method::Access_And);
        nkr_TEST_FUNCTION($default::$method::Access_Xor);
        wprintf(L"\n");

        nkr_TEST_FUNCTION($default::$method::Assign);
        nkr_TEST_FUNCTION($default::$method::Assign_Add);
        nkr_TEST_FUNCTION($default::$method::Assign_Subtract);
        nkr_TEST_FUNCTION($default::$method::Assign_Or);
        nkr_TEST_FUNCTION($default::$method::Assign_And);
        nkr_TEST_FUNCTION($default::$method::Assign_Xor);
        wprintf(L"\n");

        nkr_TEST_FUNCTION($default::$method::Exchange);
        nkr_TEST_FUNCTION($default::$method::Exchange_If_Equals);
        nkr_TEST_FUNCTION($default::$method::Exchange_Add);
        nkr_TEST_FUNCTION($default::$method::Exchange_Subtract);
        nkr_TEST_FUNCTION($default::$method::Exchange_Or);
        nkr_TEST_FUNCTION($default::$method::Exchange_And);
        nkr_TEST_FUNCTION($default::$method::Exchange_Xor);
        wprintf(L"\n");

        nkr_TEST_FUNCTION($default::$cast::Value_t);
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
        wprintf(L"\n");

        nkr_TEST_FUNCTION($bool_t::$method::Assign);
        wprintf(L"\n");

        nkr_TEST_FUNCTION($bool_t::$method::Exchange);
        nkr_TEST_FUNCTION($bool_t::$method::Exchange_If_Equals);
        wprintf(L"\n");

        nkr_TEST_FUNCTION($bool_t::$cast::Value_t);
        wprintf(L"\n");

        nkr_TEST_FUNCTION($bool_t::$operator::Invoke);
        wprintf(L"\n");

        nkr_TEST_FUNCTION($bool_t::$operator::Assign);
        wprintf(L"\n");

        nkr_TEST_FUNCTION($pointer::$object::Constructor_Default);
        nkr_TEST_FUNCTION($pointer::$object::Constructor_Value_Pointer);
        nkr_TEST_FUNCTION($pointer::$object::Constructor_Copy);
        nkr_TEST_FUNCTION($pointer::$object::Constructor_Move);
        nkr_TEST_FUNCTION($pointer::$object::Assigner_Copy);
        nkr_TEST_FUNCTION($pointer::$object::Assigner_Move);
        nkr_TEST_FUNCTION($pointer::$object::Destructor);
        wprintf(L"\n");

        nkr_TEST_FUNCTION($pointer::$method::Access);
        nkr_TEST_FUNCTION($pointer::$method::Access_Add);
        nkr_TEST_FUNCTION($pointer::$method::Access_Subtract);
        wprintf(L"\n");

        nkr_TEST_FUNCTION($pointer::$method::Assign);
        nkr_TEST_FUNCTION($pointer::$method::Assign_Add);
        nkr_TEST_FUNCTION($pointer::$method::Assign_Subtract);
        wprintf(L"\n");

        nkr_TEST_FUNCTION($pointer::$method::Exchange);
        nkr_TEST_FUNCTION($pointer::$method::Exchange_If_Equals);
        nkr_TEST_FUNCTION($pointer::$method::Exchange_Add);
        nkr_TEST_FUNCTION($pointer::$method::Exchange_Subtract);
        wprintf(L"\n");

        nkr_TEST_FUNCTION($pointer::$cast::Value_t_Pointer);
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

        nkr_TEST_FUNCTION($void_pointer::$object::Constructor_Default);
        nkr_TEST_FUNCTION($void_pointer::$object::Constructor_Value_Pointer);
        nkr_TEST_FUNCTION($void_pointer::$object::Constructor_Copy);
        nkr_TEST_FUNCTION($void_pointer::$object::Constructor_Move);
        nkr_TEST_FUNCTION($void_pointer::$object::Assigner_Copy);
        nkr_TEST_FUNCTION($void_pointer::$object::Assigner_Move);
        nkr_TEST_FUNCTION($void_pointer::$object::Destructor);
        wprintf(L"\n");

        nkr_TEST_FUNCTION($void_pointer::$method::Access);
        wprintf(L"\n");

        nkr_TEST_FUNCTION($void_pointer::$method::Assign);
        wprintf(L"\n");

        nkr_TEST_FUNCTION($void_pointer::$method::Exchange);
        nkr_TEST_FUNCTION($void_pointer::$method::Exchange_If_Equals);
        wprintf(L"\n");

        nkr_TEST_FUNCTION($void_pointer::$cast::Value_t_Pointer);
        wprintf(L"\n");

        nkr_TEST_FUNCTION($void_pointer::$operator::Invoke);
        wprintf(L"\n");

        nkr_TEST_FUNCTION($void_pointer::$operator::Assign);
        wprintf(L"\n");
    }

}}

namespace nkr { namespace test_atomic_t { namespace $default { namespace $object {

    void_t Constructor_Default()
    {
        wprintf(L"should set value to 0");

        atomic_t<word_t> word;
        nkr_TEST(word == 0);
    }

    void_t Constructor_Value()
    {
        wprintf(L"should set value to value");

        atomic_t<word_t> word(1);
        nkr_TEST(word == 1);
    }

    void_t Constructor_Copy()
    {
        wprintf(L"should copy value from other");

        atomic_t<word_t> other(1);
        atomic_t<word_t> word(other);
        nkr_TEST(other == 1);
        nkr_TEST(word == 1);
    }

    void_t Constructor_Move()
    {
        wprintf(L"should copy value from other and set other's value to 0");

        atomic_t<word_t> other(1);
        atomic_t<word_t> word(std::move(other));
        nkr_TEST(other == 0);
        nkr_TEST(word == 1);
    }

    void_t Assigner_Copy()
    {
        wprintf(L"should copy value from other");

        atomic_t<word_t> other(1);
        atomic_t<word_t> word = other;
        nkr_TEST(other == 1);
        nkr_TEST(word == 1);
    }

    void_t Assigner_Move()
    {
        wprintf(L"should copy value from other and set other's value to 0");

        atomic_t<word_t> other(1);
        atomic_t<word_t> word = std::move(other);
        nkr_TEST(other == 0);
        nkr_TEST(word == 1);
    }

    void_t Destructor()
    {
        wprintf(L"should set value to 0");

        atomic_t<word_t> word(1);
        word.~atomic_t();
        nkr_TEST(word == 0);
    }

}}}}

namespace nkr { namespace test_atomic_t { namespace $default { namespace $method {

    void_t Access()
    {
        wprintf(L"should return value");

        const atomic_t<word_t> word(1);
        nkr_TEST(word.Access() == 1);
    }

    void_t Access_Add()
    {
        wprintf(L"should return added value without changing its value");

        const atomic_t<word_t> word(1);
        nkr_TEST(word.Access_Add(1) == 2);
        nkr_TEST(word == 1);
    }

    void_t Access_Subtract()
    {
        wprintf(L"should return subtracted value without changing its value");

        const atomic_t<word_t> word(1);
        nkr_TEST(word.Access_Subtract(1) == 0);
        nkr_TEST(word == 1);
    }

    void_t Access_Or()
    {
        wprintf(L"should return or'd value without changing its value");

        const atomic_t<word_t> word(0x0F);
        nkr_TEST(word.Access_Or(0xF0) == 0xFF);
        nkr_TEST(word == 0x0F);
    }

    void_t Access_And()
    {
        wprintf(L"should return and'd value without changing its value");

        const atomic_t<word_t> word(0x0F);
        nkr_TEST(word.Access_And(0xF0) == 0x00);
        nkr_TEST(word == 0x0F);
    }

    void_t Access_Xor()
    {
        wprintf(L"should return xor'd value without changing its value");

        const atomic_t<word_t> word(0xFF);
        nkr_TEST(word.Access_Xor(0x01) == 0xFE);
        nkr_TEST(word == 0xFF);
    }

    void_t Assign()
    {
        wprintf(L"should set value and return the new value");

        atomic_t<word_t> word(1);
        nkr_TEST(word.Assign(0) == 0);
        nkr_TEST(word == 0);
    }

    void_t Assign_Add()
    {
        wprintf(L"should set added value and return the new value");

        atomic_t<word_t> word(1);
        nkr_TEST(word.Assign_Add(1) == 2);
        nkr_TEST(word == 2);
    }

    void_t Assign_Subtract()
    {
        wprintf(L"should set subtracted value and return the new value");

        atomic_t<word_t> word(1);
        nkr_TEST(word.Assign_Subtract(1) == 0);
        nkr_TEST(word == 0);
    }

    void_t Assign_Or()
    {
        wprintf(L"should set or'd value and return the new value");

        atomic_t<word_t> word(0x0F);
        nkr_TEST(word.Assign_Or(0xF0) == 0xFF);
        nkr_TEST(word == 0xFF);
    }

    void_t Assign_And()
    {
        wprintf(L"should set and'd value and return the new value");

        atomic_t<word_t> word(0x0F);
        nkr_TEST(word.Assign_And(0xF0) == 0x00);
        nkr_TEST(word == 0x00);
    }

    void_t Assign_Xor()
    {
        wprintf(L"should set xor'd value and return the new value");

        atomic_t<word_t> word(0xFF);
        nkr_TEST(word.Assign_Xor(0x01) == 0xFE);
        nkr_TEST(word == 0xFE);
    }

    void_t Exchange()
    {
        wprintf(L"should set value and return the old value");

        atomic_t<word_t> word(1);
        nkr_TEST(word.Exchange(0) == 1);
        nkr_TEST(word == 0);
    }

    void_t Exchange_If_Equals()
    {
        wprintf(L"should set value if old value equals target and return the old value");

        atomic_t<word_t> word(1);
        nkr_TEST(word.Exchange_If_Equals(0, 0) == 1);
        nkr_TEST(word == 1);
        nkr_TEST(word.Exchange_If_Equals(0, 1) == 1);
        nkr_TEST(word == 0);
    }

    void_t Exchange_Add()
    {
        wprintf(L"should set added value and return the old value");

        atomic_t<word_t> word(1);
        nkr_TEST(word.Exchange_Add(1) == 1);
        nkr_TEST(word == 2);
    }

    void_t Exchange_Subtract()
    {
        wprintf(L"should set subtracted value and return the old value");

        atomic_t<word_t> word(1);
        nkr_TEST(word.Exchange_Subtract(1) == 1);
        nkr_TEST(word == 0);
    }

    void_t Exchange_Or()
    {
        wprintf(L"should set or'd value and return the old value");

        atomic_t<word_t> word(0x0F);
        nkr_TEST(word.Exchange_Or(0xF0) == 0x0F);
        nkr_TEST(word == 0xFF);
    }

    void_t Exchange_And()
    {
        wprintf(L"should set and'd value and return the old value");

        atomic_t<word_t> word(0x0F);
        nkr_TEST(word.Exchange_And(0xF0) == 0x0F);
        nkr_TEST(word == 0x00);
    }

    void_t Exchange_Xor()
    {
        wprintf(L"should set xor'd value and return the old value");

        atomic_t<word_t> word(0xFF);
        nkr_TEST(word.Exchange_Xor(0x01) == 0xFF);
        nkr_TEST(word == 0xFE);
    }

}}}}

namespace nkr { namespace test_atomic_t { namespace $default { namespace $cast {

    void_t Value_t()
    {
        wprintf(L"should cast to its value_t");

        atomic_t<word_t> word(1);
        nkr_TEST(static_cast<atomic_t<word_t>::value_t>(word) == 1);
        nkr_TEST(word == 1);
        nkr_TEST(static_cast<bool_t>(word) == true);
        nkr_TEST(!word == false);

        word = 0;
        nkr_TEST(word == 0);
        nkr_TEST(static_cast<bool_t>(word) == false);
        nkr_TEST(!word == true);
    }

}}}}

namespace nkr { namespace test_atomic_t { namespace $default { namespace $operator {

    void_t Invoke()
    {
        wprintf(L"should return its value");

        atomic_t<word_t> word(1);
        nkr_TEST(word() == 1);
    }

    void_t Assign()
    {
        wprintf(L"should set its value to other");

        atomic_t<word_t> word(0);
        word = 1;
        nkr_TEST(word == 1);
    }

    void_t Add()
    {
        wprintf(L"should return the result of value + other without changing value");

        atomic_t<word_t> word(1);
        nkr_TEST(word + 1 == 2);
        nkr_TEST(word == 1);
    }

    void_t Subtract()
    {
        wprintf(L"should return the result of value - other without changing value");

        atomic_t<word_t> word(1);
        nkr_TEST(word - 1 == 0);
        nkr_TEST(word == 1);
    }

    void_t Add_Assign()
    {
        wprintf(L"should set value to value + other");

        atomic_t<word_t> word(1);
        nkr_TEST((word += 1) == 2);
        nkr_TEST(word == 2);
    }

    void_t Subtract_Assign()
    {
        wprintf(L"should set value to value - other");

        atomic_t<word_t> word(1);
        nkr_TEST((word -= 1) == 0);
        nkr_TEST(word == 0);
    }

    void_t Increment_Pre()
    {
        wprintf(L"should increment value and return the new value");

        atomic_t<word_t> word(1);
        nkr_TEST(++word == 2);
        nkr_TEST(word == 2);
    }

    void_t Increment_Post()
    {
        wprintf(L"should increment value and return the initial value");

        atomic_t<word_t> word(1);
        nkr_TEST(word++ == 1);
        nkr_TEST(word == 2);
    }

    void_t Decrement_Pre()
    {
        wprintf(L"should decrement value and return the new value");

        atomic_t<word_t> word(1);
        nkr_TEST(--word == 0);
        nkr_TEST(word == 0);
    }

    void_t Decrement_Post()
    {
        wprintf(L"should decrement value and return the initial value");

        atomic_t<word_t> word(1);
        nkr_TEST(word-- == 1);
        nkr_TEST(word == 0);
    }

    void_t Bitwise_Not()
    {
        wprintf(L"should return ~value without changing value");

        atomic_t<u8_t> u8(0x0F);
        nkr_TEST(~u8 == 0xF0);
        nkr_TEST(u8 == 0x0F);
    }

    void_t Bitwise_Or()
    {
        wprintf(L"should return value | other without changing value");

        atomic_t<u8_t> u8(0x0F);
        nkr_TEST((u8 | 0xF0) == 0xFF);
        nkr_TEST(u8 == 0x0F);
    }

    void_t Bitwise_And()
    {
        wprintf(L"should return value & other without changing value");

        atomic_t<u8_t> u8(0x0F);
        nkr_TEST((u8 & 0xF0) == 0x0);
        nkr_TEST(u8 == 0x0F);
    }

    void_t Bitwise_Xor()
    {
        wprintf(L"should return value ^ other without changing value");

        atomic_t<u8_t> u8(0xFF);
        nkr_TEST((u8 ^ 0x01) == 0xFE);
        nkr_TEST(u8 == 0xFF);
    }

    void_t Bitwise_Or_Assign()
    {
        wprintf(L"should set value |= other");

        atomic_t<u8_t> u8(0x0F);
        nkr_TEST((u8 |= 0xF0) == 0xFF);
        nkr_TEST(u8 == 0xFF);
    }

    void_t Bitwise_And_Assign()
    {
        wprintf(L"should set value &= other");

        atomic_t<u8_t> u8(0x0F);
        nkr_TEST((u8 &= 0xF0) == 0x0);
        nkr_TEST(u8 == 0x0);
    }

    void_t Bitwise_Xor_Assign()
    {
        wprintf(L"should set value ^= other");

        atomic_t<u8_t> u8(0xFF);
        nkr_TEST((u8 ^= 0x01) == 0xFE);
        nkr_TEST(u8 == 0xFE);
    }

}}}}

namespace nkr { namespace test_atomic_t { namespace $bool_t { namespace $object {

    void_t Constructor_Default()
    {
        wprintf(L"should set value to false");

        atomic_t<bool_t> boolean;
        nkr_TEST(boolean == false);
    }

    void_t Constructor_Value()
    {
        wprintf(L"should set value to value");

        atomic_t<bool_t> boolean(true);
        nkr_TEST(boolean == true);
    }

    void_t Constructor_Copy()
    {
        wprintf(L"should copy value from other");

        atomic_t<bool_t> other(true);
        atomic_t<bool_t> boolean(other);
        nkr_TEST(other == true);
        nkr_TEST(boolean == true);
    }

    void_t Constructor_Move()
    {
        wprintf(L"should copy value from other and set other's value to false");

        atomic_t<bool_t> other(true);
        atomic_t<bool_t> boolean(std::move(other));
        nkr_TEST(other == false);
        nkr_TEST(boolean == true);
    }

    void_t Assigner_Copy()
    {
        wprintf(L"should copy value from other");

        atomic_t<bool_t> other(true);
        atomic_t<bool_t> boolean = other;
        nkr_TEST(other == true);
        nkr_TEST(boolean == true);
    }

    void_t Assigner_Move()
    {
        wprintf(L"should copy value from other and set other's value to false");

        atomic_t<bool_t> other(true);
        atomic_t<bool_t> boolean = std::move(other);
        nkr_TEST(other == false);
        nkr_TEST(boolean == true);
    }

    void_t Destructor()
    {
        wprintf(L"should set value to false");

        atomic_t<bool_t> boolean(true);
        boolean.~atomic_t();
        nkr_TEST(boolean == false);
    }

}}}}

namespace nkr { namespace test_atomic_t { namespace $bool_t { namespace $method {

    void_t Access()
    {
        wprintf(L"should return value");

        const atomic_t<bool_t> boolean(true);
        nkr_TEST(boolean.Access() == true);
    }

    void_t Assign()
    {
        wprintf(L"should set value and return the new value");

        atomic_t<bool_t> boolean(true);
        nkr_TEST(boolean.Assign(false) == false);
        nkr_TEST(boolean == false);
    }

    void_t Exchange()
    {
        wprintf(L"should set value and return the old value");

        atomic_t<bool_t> boolean(true);
        nkr_TEST(boolean.Exchange(false) == true);
        nkr_TEST(boolean == false);
    }

    void_t Exchange_If_Equals()
    {
        wprintf(L"should set value if old value equals target and return the old value");

        atomic_t<bool_t> boolean(true);
        nkr_TEST(boolean.Exchange_If_Equals(false, false) == true);
        nkr_TEST(boolean == true);
        nkr_TEST(boolean.Exchange_If_Equals(false, true) == true);
        nkr_TEST(boolean == false);
    }

}}}}

namespace nkr { namespace test_atomic_t { namespace $bool_t { namespace $cast {

    void_t Value_t()
    {
        wprintf(L"should cast to its value_t");

        atomic_t<bool_t> boolean(true);
        nkr_TEST(static_cast<atomic_t<bool_t>::value_t>(boolean) == true);
        nkr_TEST(boolean == true);
        nkr_TEST(static_cast<bool_t>(boolean) == true);
        nkr_TEST(!boolean == false);

        boolean = false;
        nkr_TEST(boolean == false);
        nkr_TEST(static_cast<bool_t>(boolean) == false);
        nkr_TEST(!boolean == true);
    }

}}}}

namespace nkr { namespace test_atomic_t { namespace $bool_t { namespace $operator {

    void_t Invoke()
    {
        wprintf(L"should return its value");

        atomic_t<bool_t> boolean(true);
        nkr_TEST(boolean() == true);
    }

    void_t Assign()
    {
        wprintf(L"should set its value to other");

        atomic_t<bool_t> boolean(false);
        boolean = true;
        nkr_TEST(boolean == true);
    }

}}}}

namespace nkr { namespace test_atomic_t { namespace $pointer { namespace $object {

    void_t Constructor_Default()
    {
        wprintf(L"should set value to nullptr");

        atomic_t<word_t*> pointer;
        nkr_TEST(pointer == nullptr);
    }

    void_t Constructor_Value_Pointer()
    {
        wprintf(L"should set value to value");

        word_t word = 1;
        atomic_t<word_t*> pointer(&word);
        nkr_TEST(pointer == &word);
    }

    void_t Constructor_Copy()
    {
        wprintf(L"should copy value from other");

        word_t word = 1;
        atomic_t<word_t*> pointer_1(&word);
        atomic_t<word_t*> pointer_2(pointer_1);
        nkr_TEST(pointer_1 == &word);
        nkr_TEST(pointer_2 == &word);
    }

    void_t Constructor_Move()
    {
        wprintf(L"should copy value from other and set other's value to nullptr");

        word_t word = 1;
        atomic_t<word_t*> pointer_1(&word);
        atomic_t<word_t*> pointer_2(std::move(pointer_1));
        nkr_TEST(pointer_1 == nullptr);
        nkr_TEST(pointer_2 == &word);
    }

    void_t Assigner_Copy()
    {
        wprintf(L"should copy value from other");

        word_t word = 1;
        atomic_t<word_t*> pointer_1(&word);
        atomic_t<word_t*> pointer_2 = pointer_1;
        nkr_TEST(pointer_1 == &word);
        nkr_TEST(pointer_2 == &word);
    }

    void_t Assigner_Move()
    {
        wprintf(L"should copy value from other and set other's value to nullptr");

        word_t word = 1;
        atomic_t<word_t*> pointer_1(&word);
        atomic_t<word_t*> pointer_2 = std::move(pointer_1);
        nkr_TEST(pointer_1 == nullptr);
        nkr_TEST(pointer_2 == &word);
    }

    void_t Destructor()
    {
        wprintf(L"should set value to nullptr");

        word_t word = 1;
        atomic_t<word_t*> pointer(&word);
        pointer.~atomic_t();
        nkr_TEST(pointer == nullptr);
    }

}}}}

namespace nkr { namespace test_atomic_t { namespace $pointer { namespace $method {

    void_t Access()
    {
        wprintf(L"should return value");

        word_t word = 1;
        const atomic_t<word_t*> pointer(&word);
        nkr_TEST(pointer.Access() == &word);
    }

    void_t Access_Add()
    {
        wprintf(L"should return added value without changing its value");

        word_t words[2] = { 0, 1 };
        const atomic_t<word_t*> pointer(words + 0);
        nkr_TEST(pointer.Access_Add(1) == words + 1);
        nkr_TEST(pointer == words + 0);
    }

    void_t Access_Subtract()
    {
        wprintf(L"should return subtracted value without changing its value");

        word_t words[2] = { 0, 1 };
        const atomic_t<word_t*> pointer(words + 1);
        nkr_TEST(pointer.Access_Subtract(1) == words + 0);
        nkr_TEST(pointer == words + 1);
    }

    void_t Assign()
    {
        wprintf(L"should set value and return the new value");

        word_t word = 1;
        atomic_t<word_t*> pointer(&word);
        nkr_TEST(pointer.Assign(nullptr) == nullptr);
        nkr_TEST(pointer == nullptr);
    }

    void_t Assign_Add()
    {
        wprintf(L"should set added value and return the new value");

        word_t words[2] = { 0, 1 };
        atomic_t<word_t*> pointer(words + 0);
        nkr_TEST(pointer.Assign_Add(1) == words + 1);
        nkr_TEST(pointer == words + 1);
    }

    void_t Assign_Subtract()
    {
        wprintf(L"should set subtracted value and return the new value");

        word_t words[2] = { 0, 1 };
        atomic_t<word_t*> pointer(words + 1);
        nkr_TEST(pointer.Assign_Subtract(1) == words + 0);
        nkr_TEST(pointer == words + 0);
    }

    void_t Exchange()
    {
        wprintf(L"should set value and return the old value");

        word_t word = 1;
        atomic_t<word_t*> pointer(&word);
        nkr_TEST(pointer.Exchange(nullptr) == &word);
        nkr_TEST(pointer == nullptr);
    }

    void_t Exchange_If_Equals()
    {
        wprintf(L"should set value if old value equals target and return the old value");

        word_t word = 1;
        atomic_t<word_t*> pointer(&word);
        nkr_TEST(pointer.Exchange_If_Equals(nullptr, nullptr) == &word);
        nkr_TEST(pointer == &word);
        nkr_TEST(pointer.Exchange_If_Equals(nullptr, &word) == &word);
        nkr_TEST(pointer == nullptr);
    }

    void_t Exchange_Add()
    {
        wprintf(L"should set added value and return the old value");

        word_t words[2] = { 0, 1 };
        atomic_t<word_t*> pointer(words + 0);
        nkr_TEST(pointer.Exchange_Add(1) == words + 0);
        nkr_TEST(pointer == words + 1);
    }

    void_t Exchange_Subtract()
    {
        wprintf(L"should set subtracted value and return the old value");

        word_t words[2] = { 0, 1 };
        atomic_t<word_t*> pointer(words + 1);
        nkr_TEST(pointer.Exchange_Subtract(1) == words + 1);
        nkr_TEST(pointer == words + 0);
    }

}}}}

namespace nkr { namespace test_atomic_t { namespace $pointer { namespace $cast {

    void_t Value_t_Pointer()
    {
        wprintf(L"should cast to its value_t*");

        word_t word = 1;
        atomic_t<word_t*> pointer(&word);
        nkr_TEST(static_cast<atomic_t<word_t*>::value_t>(pointer) == &word);
        nkr_TEST(pointer == &word);
        nkr_TEST(static_cast<bool_t>(pointer) == true);
        nkr_TEST(!pointer == false);

        pointer = nullptr;
        nkr_TEST(pointer == nullptr);
        nkr_TEST(static_cast<bool_t>(pointer) == false);
        nkr_TEST(!pointer == true);
    }

}}}}

namespace nkr { namespace test_atomic_t { namespace $pointer { namespace $operator {

    void_t Invoke()
    {
        wprintf(L"should return value");

        word_t word = 1;
        atomic_t<word_t*> pointer(&word);
        nkr_TEST(pointer() == &word);
    }

    void_t Assign()
    {
        wprintf(L"should set value to other");

        word_t word_1 = 1;
        word_t word_2 = 2;
        atomic_t<word_t*> pointer(&word_1);
        pointer = &word_2;
        nkr_TEST(pointer == &word_2);
    }

    void_t Add()
    {
        wprintf(L"should return value + other without changing value");

        word_t words[2] = { 0, 1 };
        atomic_t<word_t*> pointer(words + 0);
        nkr_TEST(pointer + 1 == words + 1);
        nkr_TEST(pointer == words + 0);
    }

    void_t Subtract()
    {
        wprintf(L"should return value - other without changing value");

        word_t words[2] = { 0, 1 };
        atomic_t<word_t*> pointer(words + 1);
        nkr_TEST(pointer - 1 == words + 0);
        nkr_TEST(pointer == words + 1);
    }

    void_t Add_Assign()
    {
        wprintf(L"should set value to value + other and return the new value");

        word_t words[2] = { 0, 1 };
        atomic_t<word_t*> pointer(words + 0);
        nkr_TEST((pointer += 1) == words + 1);
        nkr_TEST(pointer == words + 1);
    }

    void_t Subtract_Assign()
    {
        wprintf(L"should set value to value - other and return the new value");

        word_t words[2] = { 0, 1 };
        atomic_t<word_t*> pointer(words + 1);
        nkr_TEST((pointer -= 1) == words + 0);
        nkr_TEST(pointer == words + 0);
    }

    void_t Increment_Pre()
    {
        wprintf(L"should increment value and return the new value");

        word_t words[2] = { 0, 1 };
        atomic_t<word_t*> pointer(words + 0);
        nkr_TEST(++pointer == words + 1);
        nkr_TEST(pointer == words + 1);
    }

    void_t Increment_Post()
    {
        wprintf(L"should increment value and return the old value");

        word_t words[2] = { 0, 1 };
        atomic_t<word_t*> pointer(words + 0);
        nkr_TEST(pointer++ == words + 0);
        nkr_TEST(pointer == words + 1);
    }

    void_t Decrement_Pre()
    {
        wprintf(L"should decrement value and return the new value");

        word_t words[2] = { 0, 1 };
        atomic_t<word_t*> pointer(words + 1);
        nkr_TEST(--pointer == words + 0);
        nkr_TEST(pointer == words + 0);
    }

    void_t Decrement_Post()
    {
        wprintf(L"should decrement value and return the old value");

        word_t words[2] = { 0, 1 };
        atomic_t<word_t*> pointer(words + 1);
        nkr_TEST(pointer-- == words + 1);
        nkr_TEST(pointer == words + 0);
    }

    void_t Access()
    {
        wprintf(L"should -> the first object of value");

        struct { const word_t word = 1; } word;
        atomic_t pointer(&word);
        nkr_TEST(pointer->word == 1);
    }

    void_t Dereference()
    {
        wprintf(L"should . the first object of value");

        struct { const word_t word = 1; } word;
        atomic_t pointer(&word);
        nkr_TEST((*pointer).word == 1);
    }

    void_t Subscript()
    {
        wprintf(L"should [] the indexed object of value");

        word_t words[2] = { 0, 1 };
        atomic_t pointer(words);
        nkr_TEST(pointer[1] == 1);
    }

}}}}

namespace nkr { namespace test_atomic_t { namespace $void_pointer { namespace $object {

    void_t Constructor_Default()
    {
        wprintf(L"should set value to nullptr");

        atomic_t<void_t*> pointer;
        nkr_TEST(pointer == nullptr);
    }

    void_t Constructor_Value_Pointer()
    {
        wprintf(L"should set value to value");

        word_t word = 1;
        atomic_t<void_t*> pointer(&word);
        nkr_TEST(pointer == &word);
    }

    void_t Constructor_Copy()
    {
        wprintf(L"should copy value from other");

        word_t word = 1;
        atomic_t<void_t*> pointer_1(&word);
        atomic_t<void_t*> pointer_2(pointer_1);
        nkr_TEST(pointer_1 == &word);
        nkr_TEST(pointer_2 == &word);
    }

    void_t Constructor_Move()
    {
        wprintf(L"should copy value from other and set other's value to nullptr");

        word_t word = 1;
        atomic_t<void_t*> pointer_1(&word);
        atomic_t<void_t*> pointer_2(std::move(pointer_1));
        nkr_TEST(pointer_1 == nullptr);
        nkr_TEST(pointer_2 == &word);
    }

    void_t Assigner_Copy()
    {
        wprintf(L"should copy value from other");

        word_t word = 1;
        atomic_t<void_t*> pointer_1(&word);
        atomic_t<void_t*> pointer_2 = pointer_1;
        nkr_TEST(pointer_1 == &word);
        nkr_TEST(pointer_2 == &word);
    }

    void_t Assigner_Move()
    {
        wprintf(L"should copy value from other and set other's value to nullptr");

        word_t word = 1;
        atomic_t<void_t*> pointer_1(&word);
        atomic_t<void_t*> pointer_2 = std::move(pointer_1);
        nkr_TEST(pointer_1 == nullptr);
        nkr_TEST(pointer_2 == &word);
    }

    void_t Destructor()
    {
        wprintf(L"should set value to nullptr");

        word_t word = 1;
        atomic_t<void_t*> pointer(&word);
        pointer.~atomic_t();
        nkr_TEST(pointer == nullptr);
    }

}}}}

namespace nkr { namespace test_atomic_t { namespace $void_pointer { namespace $method {

    void_t Access()
    {
        wprintf(L"should return value");

        word_t word = 1;
        const atomic_t<void_t*> pointer(&word);
        nkr_TEST(pointer.Access() == &word);
    }

    void_t Assign()
    {
        wprintf(L"should set value and return the new value");

        word_t word = 1;
        atomic_t<void_t*> pointer(&word);
        nkr_TEST(pointer.Assign(nullptr) == nullptr);
        nkr_TEST(pointer == nullptr);
    }

    void_t Exchange()
    {
        wprintf(L"should set value and return the old value");

        word_t word = 1;
        atomic_t<void_t*> pointer(&word);
        nkr_TEST(pointer.Exchange(nullptr) == &word);
        nkr_TEST(pointer == nullptr);
    }

    void_t Exchange_If_Equals()
    {
        wprintf(L"should set value if old value equals target and return the old value");

        word_t word = 1;
        atomic_t<void_t*> pointer(&word);
        nkr_TEST(pointer.Exchange_If_Equals(nullptr, nullptr) == &word);
        nkr_TEST(pointer == &word);
        nkr_TEST(pointer.Exchange_If_Equals(nullptr, &word) == &word);
        nkr_TEST(pointer == nullptr);
    }

}}}}

namespace nkr { namespace test_atomic_t { namespace $void_pointer { namespace $cast {

    void_t Value_t_Pointer()
    {
        wprintf(L"should cast to its value_t*");

        word_t word = 1;
        atomic_t<void_t*> pointer(&word);
        nkr_TEST(static_cast<atomic_t<void_t*>::value_t>(pointer) == &word);
        nkr_TEST(pointer == &word);
        nkr_TEST(static_cast<bool_t>(pointer) == true);
        nkr_TEST(!pointer == false);

        pointer = nullptr;
        nkr_TEST(pointer == nullptr);
        nkr_TEST(static_cast<bool_t>(pointer) == false);
        nkr_TEST(!pointer == true);
    }

}}}}

namespace nkr { namespace test_atomic_t { namespace $void_pointer { namespace $operator {

    void_t Invoke()
    {
        wprintf(L"should return value");

        word_t word = 1;
        atomic_t<void_t*> pointer(&word);
        nkr_TEST(pointer() == &word);
    }

    void_t Assign()
    {
        wprintf(L"should set value to other");

        word_t word_1 = 1;
        word_t word_2 = 2;
        atomic_t<void_t*> pointer(&word_1);
        pointer = &word_2;
        nkr_TEST(pointer == &word_2);
    }

}}}}
*/
