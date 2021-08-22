/*
    Copyright 2021 r-neal-kelly
*/

/*
#include "test_pointer_t.h"

namespace nkr { namespace test_pointer_t {

    void_t Execute()
    {
        wprintf(L"pointer_t\n");

        nkr_TEST_METHOD($static::Unit_Size);
        nkr_TEST_METHOD($static::Max_Unit_Count);
        wprintf(L"\n");

        nkr_TEST_METHOD($object::Constructor_Default);
        nkr_TEST_METHOD($object::Constructor_Unit_Pointer);
        nkr_TEST_METHOD($object::Constructor_Units_And_Unit_Count);
        nkr_TEST_METHOD($object::Constructor_Copy);
        nkr_TEST_METHOD($object::Constructor_Move);
        nkr_TEST_METHOD($object::Assigner_Copy);
        nkr_TEST_METHOD($object::Assigner_Move);
        nkr_TEST_METHOD($object::Destructor);
        wprintf(L"\n");

        nkr_TEST_METHOD($method::Units);
        nkr_TEST_METHOD($method::Units_Const);
        wprintf(L"\n");

        nkr_TEST_METHOD($method::Unit_Count);
        nkr_TEST_METHOD($method::Unit_Count_Const);
        wprintf(L"\n");

        nkr_TEST_METHOD($method::Address);
        wprintf(L"\n");

        nkr_TEST_METHOD($cast::Bool_t);
        nkr_TEST_METHOD($cast::Const_Bool_t);
        wprintf(L"\n");

        nkr_TEST_METHOD($cast::Units_t_Ref);
        nkr_TEST_METHOD($cast::Const_Units_t_Ref);
        wprintf(L"\n");

        nkr_TEST_METHOD($operator::Logical_Not);
        wprintf(L"\n");

        nkr_TEST_METHOD($operator::Invoke);
        nkr_TEST_METHOD($operator::Invoke_Const);
        wprintf(L"\n");

        nkr_TEST_METHOD($operator::Access_Const);
        nkr_TEST_METHOD($operator::Dereference_Const);
        nkr_TEST_METHOD($operator::Subscript_Const);
        wprintf(L"\n");

        nkr_TEST_METHOD($operator::Increment_Pre);
        nkr_TEST_METHOD($operator::Increment_Post);
        nkr_TEST_METHOD($operator::Decrement_Pre);
        nkr_TEST_METHOD($operator::Decrement_Post);
        wprintf(L"\n");

        nkr_TEST_METHOD($operator::Add_Assign);
        nkr_TEST_METHOD($operator::Subtract_Assign);
        wprintf(L"\n");

        nkr_TEST_METHOD($operator::Add);
        nkr_TEST_METHOD($operator::Subtract);
        wprintf(L"\n");
    }

}}

namespace nkr { namespace test_pointer_t { namespace $static {

    void_t Unit_Size()
    {
        wprintf(L"should have the same size as unit");

        nkr_TEST(pointer_t<word_t>::UNIT_SIZE == sizeof(word_t));
    }

    void_t Max_Unit_Count()
    {
        wprintf(L"should have a max_unit_count matching the max of count_t");

        nkr_TEST(pointer_t<word_t>::MAX_UNIT_COUNT == std::numeric_limits<count_t>::max());
    }

}}}

namespace nkr { namespace test_pointer_t { namespace $object {

    void_t Constructor_Default()
    {
        wprintf(L"should set units to nullptr and unit_count to 0");

        pointer_t<word_t> pointer;
        nkr_TEST(pointer.units == nullptr);
        nkr_TEST(pointer.unit_count == 0);
    }

    void_t Constructor_Unit_Pointer()
    {
        wprintf(L"should set units to unit_pointer and unit_count to 1");

        word_t word = 0;
        pointer_t<word_t> pointer(&word);
        nkr_TEST(pointer.units == &word);
        nkr_TEST(pointer.unit_count == 1);
    }

    void_t Constructor_Units_And_Unit_Count()
    {
        wprintf(L"should set units and unit_count");

        word_t word = 0;
        pointer_t<word_t> pointer(&word, 1);
        nkr_TEST(pointer.units == &word);
        nkr_TEST(pointer.unit_count == 1);
    }

    void_t Constructor_Copy()
    {
        wprintf(L"should copy units and unit_count without changing original");

        word_t word = 0;
        pointer_t<word_t> pointer_1(&word, 1);
        pointer_t<word_t> pointer_2(pointer_1);
        nkr_TEST(pointer_1.units == &word);
        nkr_TEST(pointer_1.unit_count == 1);
        nkr_TEST(pointer_2.units == &word);
        nkr_TEST(pointer_2.unit_count == 1);
    }

    void_t Constructor_Move()
    {
        wprintf(L"should move units and unit_count and default original");

        word_t word = 0;
        pointer_t<word_t> pointer_1(&word, 1);
        pointer_t<word_t> pointer_2(std::move(pointer_1));
        nkr_TEST(pointer_1.units == nullptr);
        nkr_TEST(pointer_1.unit_count == 0);
        nkr_TEST(pointer_2.units == &word);
        nkr_TEST(pointer_2.unit_count == 1);
    }

    void_t Assigner_Copy()
    {
        wprintf(L"should copy units and unit_count without changing original");

        word_t word = 0;
        pointer_t<word_t> pointer_1(&word, 1);
        pointer_t<word_t> pointer_2 = pointer_1;
        nkr_TEST(pointer_1.units == &word);
        nkr_TEST(pointer_1.unit_count == 1);
        nkr_TEST(pointer_2.units == &word);
        nkr_TEST(pointer_2.unit_count == 1);
    }

    void_t Assigner_Move()
    {
        wprintf(L"should move units and unit_count and default original");

        word_t word = 0;
        pointer_t<word_t> pointer_1(&word, 1);
        pointer_t<word_t> pointer_2 = std::move(pointer_1);
        nkr_TEST(pointer_1.units == nullptr);
        nkr_TEST(pointer_1.unit_count == 0);
        nkr_TEST(pointer_2.units == &word);
        nkr_TEST(pointer_2.unit_count == 1);
    }

    void_t Destructor()
    {
        wprintf(L"should set units to nullptr and unit_count to 0");

        word_t word = 0;
        pointer_t<word_t> pointer(&word, 1);
        const pointer_t<word_t> const_pointer(&word, 1);
        pointer.~pointer_t();
        const_pointer.~pointer_t();
        nkr_TEST(pointer.units == nullptr);
        nkr_TEST(pointer.unit_count == 0);
        nkr_TEST(const_pointer.units == nullptr);
        nkr_TEST(const_pointer.unit_count == 0);
    }

}}}

namespace nkr { namespace test_pointer_t { namespace $method {

    void_t Units()
    {
        wprintf(L"should return assignable units");

        word_t word_1 = 0;
        pointer_t pointer(&word_1);
        nkr_TEST(pointer.Units() == &word_1);

        word_t word_2 = 1;
        pointer.Units() = &word_2;
        nkr_TEST(pointer.Units() == &word_2);
    }

    void_t Units_Const()
    {
        wprintf(L"should return unassignable units");

        word_t word = 0;
        const pointer_t pointer(&word);
        nkr_TEST(pointer.Units() == &word);
    }

    void_t Unit_Count()
    {
        wprintf(L"should return assignable unit_count");

        word_t word = 0;
        pointer_t pointer(&word);
        nkr_TEST(pointer.Unit_Count() == 1);

        pointer.Unit_Count() = 2;
        nkr_TEST(pointer.Unit_Count() == 2);
    }

    void_t Unit_Count_Const()
    {
        wprintf(L"should return unassignable unit_count");

        word_t word = 0;
        const pointer_t pointer(&word);
        nkr_TEST(pointer.Unit_Count() == 1);
    }

    void_t Address()
    {
        wprintf(L"should return a cast of units_t to address_t");

        word_t word = 0;
        pointer_t<word_t> pointer = &word;
        nkr_TEST(pointer.Address() == reinterpret_cast<address_t>(&word));
    }

}}}

namespace nkr { namespace test_pointer_t { namespace $cast {

    void_t Bool_t()
    {
        wprintf(L"should convert to true if units != nullptr");

        word_t word = 0;
        pointer_t<word_t> pointer(&word, 1);
        nkr_TEST(static_cast<bool_t>(pointer) == true);
        nkr_TEST(pointer);

        pointer.units = nullptr;
        nkr_TEST(static_cast<bool_t>(pointer) == false);

        pointer.units = &word;
        pointer.unit_count = 0;
        nkr_TEST(static_cast<bool_t>(pointer) == true);

        pointer.units = &word;
        pointer.unit_count = 1;
        pointer.~pointer_t();
        nkr_TEST(static_cast<bool_t>(pointer) == false);
    }

    void_t Const_Bool_t()
    {
        wprintf(L"should convert to true if units != nullptr");

        word_t word = 0;
        const pointer_t<word_t> pointer(&word, 1);
        nkr_TEST(static_cast<bool_t>(pointer) == true);
        nkr_TEST(pointer);

        pointer.~pointer_t();
        nkr_TEST(static_cast<bool_t>(pointer) == false);
    }

    void_t Units_t_Ref()
    {
        wprintf(L"should convert to units_t& and should be assignable");

        word_t word_1 = 0;
        pointer_t<word_t> pointer(&word_1, 1);
        nkr_TEST(static_cast<pointer_t<word_t>::units_t&>(pointer) == &word_1);

        pointer_t<word_t>::units_t& units_1 = pointer;
        nkr_TEST(units_1 == &word_1);

        word_t word_2 = 0;
        static_cast<pointer_t<word_t>::units_t&>(pointer) = &word_2;
        nkr_TEST(static_cast<pointer_t<word_t>::units_t&>(pointer) == &word_2);

        pointer_t<word_t>::units_t& units_2 = pointer;
        nkr_TEST(units_2 == &word_2);
    }

    void_t Const_Units_t_Ref()
    {
        wprintf(L"should convert to const units_t&");

        word_t word = 0;
        const pointer_t<word_t> pointer(&word, 1);
        nkr_TEST(static_cast<const pointer_t<word_t>::units_t&>(pointer) == &word);

        const pointer_t<word_t>::units_t& units = pointer;
        nkr_TEST(units == &word);
    }

}}}

namespace nkr { namespace test_pointer_t { namespace $operator {

    void_t Logical_Not()
    {
        wprintf(L"should convert to true if units == nullptr");

        word_t word = 0;
        pointer_t<word_t> pointer(&word, 1);
        nkr_TEST(!pointer == false);

        pointer.units = nullptr;
        nkr_TEST(!pointer == true);

        pointer.units = &word;
        pointer.unit_count = 0;
        nkr_TEST(!pointer == false);

        pointer.units = &word;
        pointer.unit_count = 1;
        pointer.~pointer_t();
        nkr_TEST(!pointer == true);
    }

    void_t Invoke()
    {
        wprintf(L"should return units_t& and should be assignable");

        word_t word_1 = 0;
        pointer_t<word_t> pointer(&word_1, 1);
        pointer_t<word_t>::units_t& units = pointer();
        nkr_TEST(units == &word_1);
        nkr_TEST(&units == &pointer.units);

        word_t word_2 = 0;
        pointer() = &word_2;
        nkr_TEST(pointer.units == &word_2);
    }

    void_t Invoke_Const()
    {
        wprintf(L"should return const units_t&");

        word_t word = 0;
        const pointer_t<word_t> pointer(&word, 1);
        const pointer_t<word_t>::units_t& units = pointer();
        nkr_TEST(units == &word);
        nkr_TEST(&units == &pointer.units);
    }

    void_t Access_Const()
    {
        wprintf(L"should access const units_t&, making the members of first unit_t& assignable");

        word_t word_1 = 0;
        pointer_t<word_t> pointer(&word_1, 1);
        const pointer_t<pointer_t<word_t>> pointer_pointer_1(&pointer, 1);
        nkr_TEST(pointer_pointer_1->units == &word_1);
        nkr_TEST(pointer_pointer_1->unit_count == 1);

        word_t word_2 = 0;
        pointer_pointer_1->units = &word_2;
        pointer_pointer_1->unit_count = 2;
        nkr_TEST(pointer.units == &word_2);
        nkr_TEST(pointer.unit_count == 2);
        nkr_TEST((&pointer_pointer_1)->units == &pointer);

        const pointer_t<const pointer_t<word_t>> pointer_pointer_2(&pointer, 1);
        nkr_TEST(pointer_pointer_2->units == &word_2);
        nkr_TEST(pointer_pointer_2->unit_count == 2);
    }

    void_t Dereference_Const()
    {
        wprintf(L"should dereference const units_t& and return the first unit_t&");

        word_t word_1 = 0;
        pointer_t<word_t> pointer(&word_1, 1);
        *pointer = 1;
        nkr_TEST(word_1 == 1);
    }

    void_t Subscript_Const()
    {
        wprintf(L"should subscript const units_t& and return the unit_t& at the given index");

        word_t words[4] = { 0, 1, 2, 3 };
        pointer_t<word_t> pointer(words, 4);
        for (index_t idx = 0, end = 4; idx < end; idx += 1) {
            nkr_TEST(pointer[idx] == words[idx]);
            pointer[idx] += 1;
            nkr_TEST(words[idx] == idx + 1);
        }
    }

    void_t Increment_Pre()
    {
        wprintf(L"should increment the units and decrement the unit_count. returns itself");

        word_t words[4] = { 100, 100, 100, 100 };
        pointer_t<word_t> pointer(words, 4);
        --pointer;
        while ((++pointer).Unit_Count() >= 1) {
            nkr_TEST(*pointer == 100);
        }
    }

    void_t Increment_Post()
    {
        wprintf(L"should increment the units and decrement the unit_count. returns initial pointer_t");

        word_t words[4] = { 100, 100, 100, 100 };
        pointer_t<word_t> pointer(words, 4);
        --pointer;
        while ((pointer++).Unit_Count() > 1) {
            nkr_TEST(*pointer == 100);
        }
    }

    void_t Decrement_Pre()
    {
        wprintf(L"should decrement the units and increment the unit_count. returns itself");

        word_t words[4] = { 100, 100, 100, 100 };
        pointer_t<word_t> pointer(words + 4, 0);
        while ((--pointer).Unit_Count() <= 4) {
            nkr_TEST(*pointer == 100);
        }
    }

    void_t Decrement_Post()
    {
        wprintf(L"should decrement the units and increment the unit_count. returns initial pointer_t");

        word_t words[4] = { 100, 100, 100, 100 };
        pointer_t<word_t> pointer(words + 4, 0);
        while ((pointer--).Unit_Count() < 4) {
            nkr_TEST(*pointer == 100);
        }
    }

    void_t Add_Assign()
    {
        wprintf(L"should increment units and decrement unit_count by count. returns itself");

        word_t words[4] = { 0, 1, 2, 3 };
        nkr_TEST(*(pointer_t(words, 4) += 0) == 0);
        nkr_TEST(*(pointer_t(words, 4) += 1) == 1);
        nkr_TEST(*(pointer_t(words, 4) += 2) == 2);
        nkr_TEST(*(pointer_t(words, 4) += 3) == 3);

        pointer_t pointer(words - 1, 5);
        nkr_TEST(*(pointer += 1) == 0);
        nkr_TEST(*(pointer += 1) == 1);
        nkr_TEST(*(pointer += 1) == 2);
        nkr_TEST(*(pointer += 1) == 3);
    }

    void_t Subtract_Assign()
    {
        wprintf(L"should decrement units and increment unit_count by count. returns itself");

        word_t words[4] = { 0, 1, 2, 3 };
        nkr_TEST(*(pointer_t(words + 4, 0) -= 1) == 3);
        nkr_TEST(*(pointer_t(words + 4, 0) -= 2) == 2);
        nkr_TEST(*(pointer_t(words + 4, 0) -= 3) == 1);
        nkr_TEST(*(pointer_t(words + 4, 0) -= 4) == 0);

        pointer_t pointer(words + 4, 0);
        nkr_TEST(*(pointer -= 1) == 3);
        nkr_TEST(*(pointer -= 1) == 2);
        nkr_TEST(*(pointer -= 1) == 1);
        nkr_TEST(*(pointer -= 1) == 0);
    }

    void_t Add()
    {
        wprintf(L"should increment units and decrement unit_count by count. returns result");

        word_t words[4] = { 0, 1, 2, 3 };
        pointer_t pointer(words, 4);
        nkr_TEST(*(pointer + 0) == 0);
        nkr_TEST(*(pointer + 1) == 1);
        nkr_TEST(*(pointer + 2) == 2);
        nkr_TEST(*(pointer + 3) == 3);
    }

    void_t Subtract()
    {
        wprintf(L"should decrement units and increment unit_count by count. returns result");

        word_t words[4] = { 0, 1, 2, 3 };
        pointer_t pointer(words + 4, 0);
        nkr_TEST(*(pointer - 1) == 3);
        nkr_TEST(*(pointer - 2) == 2);
        nkr_TEST(*(pointer - 3) == 1);
        nkr_TEST(*(pointer - 4) == 0);
    }

}}}
*/
