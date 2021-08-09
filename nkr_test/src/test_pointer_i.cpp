/*
    Copyright 2021 r-neal-kelly
*/

#include "test_pointer_i.h"

namespace nkr { namespace test {

    test_pointer_i::test_pointer_i()
    {
        wprintf(L"test_pointer_i\n");

        NKR_TEST_METHOD(unit_size);
        NKR_TEST_METHOD(max_unit_count);
        wprintf(L"\n");

        NKR_TEST_METHOD(constructor_default);
        NKR_TEST_METHOD(constructor_unit_pointer);
        NKR_TEST_METHOD(constructor_units_and_unit_count);
        NKR_TEST_METHOD(constructor_copy);
        NKR_TEST_METHOD(constructor_move);
        NKR_TEST_METHOD(assigner_copy);
        NKR_TEST_METHOD(assigner_move);
        NKR_TEST_METHOD(destructor);
        wprintf(L"\n");

        NKR_TEST_METHOD(operator_bool_t);
        NKR_TEST_METHOD(operator_const_bool_t);
        wprintf(L"\n");

        NKR_TEST_METHOD(operator_units_t_ref);
        NKR_TEST_METHOD(operator_const_units_t_ref);
        wprintf(L"\n");

        NKR_TEST_METHOD(operator_count_t_ref);
        NKR_TEST_METHOD(operator_const_count_t_ref);
        wprintf(L"\n");

        NKR_TEST_METHOD(operator_logical_not);
        wprintf(L"\n");

        NKR_TEST_METHOD(operator_invoke);
        NKR_TEST_METHOD(operator_invoke_const);
        wprintf(L"\n");

        NKR_TEST_METHOD(operator_access_const);
        NKR_TEST_METHOD(operator_dereference_const);
        NKR_TEST_METHOD(operator_subscript_const);
        wprintf(L"\n");

        NKR_TEST_METHOD(operator_increment_pre);
        NKR_TEST_METHOD(operator_increment_post);
        NKR_TEST_METHOD(operator_decrement_pre);
        NKR_TEST_METHOD(operator_decrement_post);
        wprintf(L"\n");

        NKR_TEST_METHOD(operator_increment_assign);
        NKR_TEST_METHOD(operator_decrement_assign);
        wprintf(L"\n");

        NKR_TEST_METHOD(address);
        wprintf(L"\n");
    }

    test_pointer_i::~test_pointer_i()
    {
    }

    void_t test_pointer_i::unit_size() const
    {
        wprintf(L"should have the same size as unit");

        NKR_TEST(pointer_i<word_t>::UNIT_SIZE == sizeof(word_t));
    }

    void_t test_pointer_i::max_unit_count() const
    {
        wprintf(L"should have a max_unit_count matching the max of count_t");
        
        NKR_TEST(pointer_i<word_t>::MAX_UNIT_COUNT == std::numeric_limits<count_t>::max());
    }

    void_t test_pointer_i::constructor_default() const
    {
        wprintf(L"should set units to nullptr and unit_count to 0");

        pointer_i<word_t> pointer;
        NKR_TEST(pointer.units == nullptr);
        NKR_TEST(pointer.unit_count == 0);
    }

    void_t test_pointer_i::constructor_unit_pointer() const
    {
        wprintf(L"should set units to unit_pointer and unit_count to 1");
        
        word_t word = 0;
        pointer_i<word_t> pointer(&word);
        NKR_TEST(pointer.units == &word);
        NKR_TEST(pointer.unit_count == 1);
    }

    void_t test_pointer_i::constructor_units_and_unit_count() const
    {
        wprintf(L"should set units and unit_count");

        word_t word = 0;
        pointer_i<word_t> pointer(&word, 1);
        NKR_TEST(pointer.units == &word);
        NKR_TEST(pointer.unit_count == 1);
    }

    void_t test_pointer_i::constructor_copy() const
    {
        wprintf(L"should copy units and unit_count without changing original");

        word_t word = 0;
        pointer_i<word_t> pointer_1(&word, 1);
        pointer_i<word_t> pointer_2(pointer_1);
        NKR_TEST(pointer_1.units == &word);
        NKR_TEST(pointer_1.unit_count == 1);
        NKR_TEST(pointer_2.units == &word);
        NKR_TEST(pointer_2.unit_count == 1);
    }

    void_t test_pointer_i::constructor_move() const
    {
        wprintf(L"should move units and unit_count and default original");

        word_t word = 0;
        pointer_i<word_t> pointer_1(&word, 1);
        pointer_i<word_t> pointer_2(std::move(pointer_1));
        NKR_TEST(pointer_1.units == nullptr);
        NKR_TEST(pointer_1.unit_count == 0);
        NKR_TEST(pointer_2.units == &word);
        NKR_TEST(pointer_2.unit_count == 1);
    }

    void_t test_pointer_i::assigner_copy() const
    {
        wprintf(L"should copy units and unit_count without changing original");

        word_t word = 0;
        pointer_i<word_t> pointer_1(&word, 1);
        pointer_i<word_t> pointer_2 = pointer_1;
        NKR_TEST(pointer_1.units == &word);
        NKR_TEST(pointer_1.unit_count == 1);
        NKR_TEST(pointer_2.units == &word);
        NKR_TEST(pointer_2.unit_count == 1);
    }

    void_t test_pointer_i::assigner_move() const
    {
        wprintf(L"should move units and unit_count and default original");

        word_t word = 0;
        pointer_i<word_t> pointer_1(&word, 1);
        pointer_i<word_t> pointer_2 = std::move(pointer_1);
        NKR_TEST(pointer_1.units == nullptr);
        NKR_TEST(pointer_1.unit_count == 0);
        NKR_TEST(pointer_2.units == &word);
        NKR_TEST(pointer_2.unit_count == 1);
    }

    void_t test_pointer_i::destructor() const
    {
        wprintf(L"should set units to nullptr and unit_count to 0");

        word_t word = 0;
        pointer_i<word_t> pointer(&word, 1);
        const pointer_i<word_t> const_pointer(&word, 1);
        pointer.~pointer_i();
        const_pointer.~pointer_i();
        NKR_TEST(pointer.units == nullptr);
        NKR_TEST(pointer.unit_count == 0);
        NKR_TEST(const_pointer.units == nullptr);
        NKR_TEST(const_pointer.unit_count == 0);
    }

    void_t test_pointer_i::operator_bool_t() const
    {
        wprintf(L"should convert to true if units != nullptr");

        word_t word = 0;
        pointer_i<word_t> pointer(&word, 1);
        NKR_TEST(static_cast<bool_t>(pointer) == true);
        NKR_TEST(pointer);

        pointer.units = nullptr;
        NKR_TEST(static_cast<bool_t>(pointer) == false);

        pointer.units = &word;
        pointer.unit_count = 0;
        NKR_TEST(static_cast<bool_t>(pointer) == true);

        pointer.units = &word;
        pointer.unit_count = 1;
        pointer.~pointer_i();
        NKR_TEST(static_cast<bool_t>(pointer) == false);
    }

    void_t test_pointer_i::operator_const_bool_t() const
    {
        wprintf(L"should convert to true if units != nullptr");

        word_t word = 0;
        const pointer_i<word_t> pointer(&word, 1);
        NKR_TEST(static_cast<bool_t>(pointer) == true);
        NKR_TEST(pointer);

        pointer.~pointer_i();
        NKR_TEST(static_cast<bool_t>(pointer) == false);
    }

    void_t test_pointer_i::operator_units_t_ref() const
    {
        wprintf(L"should convert to units_t& and should be assignable");

        word_t word_1 = 0;
        pointer_i<word_t> pointer(&word_1, 1);
        NKR_TEST(static_cast<pointer_i<word_t>::units_t&>(pointer) == &word_1);

        pointer_i<word_t>::units_t& units_1 = pointer;
        NKR_TEST(units_1 == &word_1);

        word_t word_2 = 0;
        static_cast<pointer_i<word_t>::units_t&>(pointer) = &word_2;
        NKR_TEST(static_cast<pointer_i<word_t>::units_t&>(pointer) == &word_2);

        pointer_i<word_t>::units_t& units_2 = pointer;
        NKR_TEST(units_2 == &word_2);
    }

    void_t test_pointer_i::operator_const_units_t_ref() const
    {
        wprintf(L"should convert to const units_t&");

        word_t word = 0;
        const pointer_i<word_t> pointer(&word, 1);
        NKR_TEST(static_cast<const pointer_i<word_t>::units_t&>(pointer) == &word);

        const pointer_i<word_t>::units_t& units = pointer;
        NKR_TEST(units == &word);
    }

    void_t test_pointer_i::operator_count_t_ref() const
    {
        wprintf(L"should convert to count_t& and should be assignable");

        word_t word = 0;
        pointer_i<word_t> pointer(&word, 1);
        NKR_TEST(static_cast<count_t&>(pointer) == 1);

        count_t& unit_count_1 = pointer;
        NKR_TEST(unit_count_1 == 1);

        static_cast<count_t&>(pointer) = 2;
        NKR_TEST(static_cast<count_t&>(pointer) == 2);

        count_t& unit_count_2 = pointer;
        NKR_TEST(unit_count_2 == 2);
    }

    void_t test_pointer_i::operator_const_count_t_ref() const
    {
        wprintf(L"should convert to const count_t&");

        word_t word = 0;
        const pointer_i<word_t> pointer(&word, 1);
        NKR_TEST(static_cast<const count_t&>(pointer) == 1);

        const count_t& unit_count = pointer;
        NKR_TEST(unit_count == 1);
    }

    void_t test_pointer_i::operator_logical_not() const
    {
        wprintf(L"should convert to true if units == nullptr");

        word_t word = 0;
        pointer_i<word_t> pointer(&word, 1);
        NKR_TEST(!pointer == false);

        pointer.units = nullptr;
        NKR_TEST(!pointer == true);

        pointer.units = &word;
        pointer.unit_count = 0;
        NKR_TEST(!pointer == false);

        pointer.units = &word;
        pointer.unit_count = 1;
        pointer.~pointer_i();
        NKR_TEST(!pointer == true);
    }

    void_t test_pointer_i::operator_invoke() const
    {
        wprintf(L"should return units_t& and should be assignable");

        word_t word_1 = 0;
        pointer_i<word_t> pointer(&word_1, 1);
        pointer_i<word_t>::units_t& units = pointer();
        NKR_TEST(units == &word_1);
        NKR_TEST(&units == &pointer.units);

        word_t word_2 = 0;
        pointer() = &word_2;
        NKR_TEST(pointer.units == &word_2);
    }

    void_t test_pointer_i::operator_invoke_const() const
    {
        wprintf(L"should return const units_t&");

        word_t word = 0;
        const pointer_i<word_t> pointer(&word, 1);
        const pointer_i<word_t>::units_t& units = pointer();
        NKR_TEST(units == &word);
        NKR_TEST(&units == &pointer.units);
    }

    void_t test_pointer_i::operator_access_const() const
    {
        wprintf(L"should access const units_t&, making the members of first unit_t& assignable");

        word_t word_1 = 0;
        pointer_i<word_t> pointer(&word_1, 1);
        const pointer_i<pointer_i<word_t>> pointer_pointer_1(&pointer, 1);
        NKR_TEST(pointer_pointer_1->units == &word_1);
        NKR_TEST(pointer_pointer_1->unit_count == 1);

        word_t word_2 = 0;
        pointer_pointer_1->units = &word_2;
        pointer_pointer_1->unit_count = 2;
        NKR_TEST(pointer.units == &word_2);
        NKR_TEST(pointer.unit_count == 2);
        NKR_TEST((&pointer_pointer_1)->units == &pointer);

        const pointer_i<const pointer_i<word_t>> pointer_pointer_2(&pointer, 1);
        NKR_TEST(pointer_pointer_2->units == &word_2);
        NKR_TEST(pointer_pointer_2->unit_count == 2);
    }

    void_t test_pointer_i::operator_dereference_const() const
    {
        wprintf(L"should dereference const units_t& and return the first unit_t&");

        word_t word_1 = 0;
        pointer_i<word_t> pointer(&word_1, 1);
        *pointer = 1;
        NKR_TEST(word_1 == 1);
    }

    void_t test_pointer_i::operator_subscript_const() const
    {
        wprintf(L"should subscript const units_t& and return the unit_t& at the given index");

        word_t words[4];
        words[0] = 0;
        words[1] = 1;
        words[2] = 2;
        words[3] = 3;
        pointer_i<word_t> pointer(words, 4);
        for (index_t idx = 0, end = 4; idx < end; idx += 1) {
            NKR_TEST(pointer[idx] == words[idx]);
            pointer[idx] += 1;
            NKR_TEST(words[idx] == idx + 1);
        }
    }

    void_t test_pointer_i::operator_increment_pre() const
    {
        wprintf(L"should increment the units and decrement the unit_count. returns resultant pointer_i");

        word_t words[4];
        words[0] = 100;
        words[1] = 100;
        words[2] = 100;
        words[3] = 100;
        pointer_i<word_t> pointer(words, 4);
        --pointer;
        while (++pointer >= 1) {
            NKR_TEST(*pointer == 100);
        }
    }

    void_t test_pointer_i::operator_increment_post() const
    {
        wprintf(L"should increment the units and decrement the unit_count. returns initial pointer_i");

        word_t words[4];
        words[0] = 100;
        words[1] = 100;
        words[2] = 100;
        words[3] = 100;
        pointer_i<word_t> pointer(words, 4);
        --pointer;
        while (pointer++ > 1) {
            NKR_TEST(*pointer == 100);
        }
    }

    void_t test_pointer_i::operator_decrement_pre() const
    {
        wprintf(L"should decrement the units and increment the unit_count. returns resultant pointer_i");

        word_t words[4];
        words[0] = 100;
        words[1] = 100;
        words[2] = 100;
        words[3] = 100;
        pointer_i<word_t> pointer(words + 4, 0);
        while (--pointer <= 4) {
            NKR_TEST(*pointer == 100);
        }
    }

    void_t test_pointer_i::operator_decrement_post() const
    {
        wprintf(L"should decrement the units and increment the unit_count. returns initial pointer_i");

        word_t words[4];
        words[0] = 100;
        words[1] = 100;
        words[2] = 100;
        words[3] = 100;
        pointer_i<word_t> pointer(words + 4, 0);
        while (pointer-- < 4) {
            NKR_TEST(*pointer == 100);
        }
    }

    void_t test_pointer_i::operator_increment_assign() const
    {
        wprintf(L"should increment units and decrement unit_count by count. returns itself");

        word_t words[4];
        words[0] = 0;
        words[1] = 1;
        words[2] = 2;
        words[3] = 3;
        NKR_TEST(*(pointer_i(words, 4) += 0) == 0);
        NKR_TEST(*(pointer_i(words, 4) += 1) == 1);
        NKR_TEST(*(pointer_i(words, 4) += 2) == 2);
        NKR_TEST(*(pointer_i(words, 4) += 3) == 3);

        pointer_i pointer(words - 1, 5);
        NKR_TEST(*(pointer += 1) == 0);
        NKR_TEST(*(pointer += 1) == 1);
        NKR_TEST(*(pointer += 1) == 2);
        NKR_TEST(*(pointer += 1) == 3);
    }

    void_t test_pointer_i::operator_decrement_assign() const
    {
        wprintf(L"should decrement units and increment unit_count by count. returns itself");

        word_t words[4];
        words[0] = 0;
        words[1] = 1;
        words[2] = 2;
        words[3] = 3;
        NKR_TEST(*(pointer_i(words + 4, 0) -= 1) == 3);
        NKR_TEST(*(pointer_i(words + 4, 0) -= 2) == 2);
        NKR_TEST(*(pointer_i(words + 4, 0) -= 3) == 1);
        NKR_TEST(*(pointer_i(words + 4, 0) -= 4) == 0);

        pointer_i pointer(words + 4, 0);
        NKR_TEST(*(pointer -= 1) == 3);
        NKR_TEST(*(pointer -= 1) == 2);
        NKR_TEST(*(pointer -= 1) == 1);
        NKR_TEST(*(pointer -= 1) == 0);
    }

    void_t test_pointer_i::address() const
    {
        wprintf(L"should return a cast of units_t to address_t");

        word_t word = 0;
        pointer_i<word_t> pointer = &word;
        NKR_TEST(pointer.address() == reinterpret_cast<address_t>(&word));
    }

}}
