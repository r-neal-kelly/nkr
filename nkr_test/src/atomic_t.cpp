/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/atomic_t.h"

#include "intrinsics.h"

namespace nkr {

    TEST_SUITE("atomic_t<bool_t>")
    {
        TEST_SUITE("objects")
        {
            TEST_CASE("default ctor() should set value to false")
            {
                atomic_t<bool_t> boolean;
                CHECK(boolean == false);
            }

            TEST_CASE("value ctor() should set value to value")
            {
                atomic_t<bool_t> boolean(true);
                CHECK(boolean == true);
            }

            TEST_CASE("copy ctor() should copy value from other")
            {
                atomic_t<bool_t> other(true);
                atomic_t<bool_t> boolean(other);
                CHECK(other == true);
                CHECK(boolean == true);
            }

            TEST_CASE("move ctor() should copy value from other and set other's value to false")
            {
                atomic_t<bool_t> other(true);
                atomic_t<bool_t> boolean(std::move(other));
                CHECK(other == false);
                CHECK(boolean == true);
            }

            TEST_CASE("copy assignment ctor() should copy value from other")
            {
                atomic_t<bool_t> other(true);
                atomic_t<bool_t> boolean = other;
                CHECK(other == true);
                CHECK(boolean == true);
            }

            TEST_CASE("move assignment ctor() should copy value from other and set other's value to false")
            {
                atomic_t<bool_t> other(true);
                atomic_t<bool_t> boolean = std::move(other);
                CHECK(other == false);
                CHECK(boolean == true);
            }

            TEST_CASE("dtor() should set value to false")
            {
                atomic_t<bool_t> boolean(true);
                boolean.~atomic_t();
                CHECK(boolean == false);
            }
        }

        TEST_SUITE("methods")
        {
            TEST_CASE("Access() should return value")
            {
                const atomic_t<bool_t> boolean(true);
                CHECK(boolean.Access() == true);
            }

            TEST_CASE("Assign() should set value and return the new value")
            {
                atomic_t<bool_t> boolean(true);
                CHECK(boolean.Assign(false) == false);
                CHECK(boolean == false);
            }

            TEST_CASE("Exchange() should set value and return the old value")
            {
                atomic_t<bool_t> boolean(true);
                CHECK(boolean.Exchange(false) == true);
                CHECK(boolean == false);
            }

            TEST_CASE("Exchange_If_Equals() should set value if old value equals target and return the old value")
            {
                atomic_t<bool_t> boolean(true);
                CHECK(boolean.Exchange_If_Equals(false, false) == true);
                CHECK(boolean == true);
                CHECK(boolean.Exchange_If_Equals(false, true) == true);
                CHECK(boolean == false);
            }
        }

        TEST_SUITE("casts")
        {
            TEST_CASE("value_t() should cast to its value_t")
            {
                atomic_t<bool_t> boolean(true);
                CHECK(static_cast<atomic_t<bool_t>::value_t>(boolean) == true);
                CHECK(boolean == true);
                CHECK(static_cast<bool_t>(boolean) == true);
                CHECK(!boolean == false);

                boolean = false;
                CHECK(boolean == false);
                CHECK(static_cast<bool_t>(boolean) == false);
                CHECK(!boolean == true);
            }
        }

        TEST_SUITE("operators")
        {
            TEST_CASE("()() should return its value")
            {
                atomic_t<bool_t> boolean(true);
                CHECK(boolean() == true);
            }

            TEST_CASE("=() should set its value to other")
            {
                atomic_t<bool_t> boolean(false);
                boolean = true;
                CHECK(boolean == true);
            }
        }
    }

    TEST_SUITE("atomic_t<integer_tr integer_p>")
    {
        TEST_SUITE("objects")
        {
            TEST_CASE("default ctor() should set value to 0")
            {
                atomic_t<word_t> word;
                CHECK(word == 0);
            }

            TEST_CASE("value ctor() should set value to value")
            {
                atomic_t<word_t> word(1);
                CHECK(word == 1);
            }

            TEST_CASE("copy ctor() should copy value from other")
            {
                atomic_t<word_t> other(1);
                atomic_t<word_t> word(other);
                CHECK(other == 1);
                CHECK(word == 1);
            }

            TEST_CASE("move ctor() should copy value from other and set other's value to 0")
            {
                atomic_t<word_t> other(1);
                atomic_t<word_t> word(std::move(other));
                CHECK(other == 0);
                CHECK(word == 1);
            }

            TEST_CASE("copy assignment ctor() should copy value from other")
            {
                atomic_t<word_t> other(1);
                atomic_t<word_t> word = other;
                CHECK(other == 1);
                CHECK(word == 1);
            }

            TEST_CASE("move assignment ctor() should copy value from other and set other's value to 0")
            {
                atomic_t<word_t> other(1);
                atomic_t<word_t> word = std::move(other);
                CHECK(other == 0);
                CHECK(word == 1);
            }

            TEST_CASE("dtor() should set value to 0")
            {
                atomic_t<word_t> word(1);
                word.~atomic_t();
                CHECK(word == 0);
            }
        }

        TEST_SUITE("methods")
        {
            TEST_CASE("Access() should return value")
            {
                const atomic_t<word_t> word(1);
                CHECK(word.Access() == 1);
            }

            TEST_CASE("Access_Add() should return added value without changing its value")
            {
                const atomic_t<word_t> word(1);
                CHECK(word.Access_Add(1) == 2);
                CHECK(word == 1);
            }

            TEST_CASE("Access_Subtract() should return subtracted value without changing its value")
            {
                const atomic_t<word_t> word(1);
                CHECK(word.Access_Subtract(1) == 0);
                CHECK(word == 1);
            }

            TEST_CASE("Access_Or() should return or'd value without changing its value")
            {
                const atomic_t<word_t> word(0x0F);
                CHECK(word.Access_Or(0xF0) == 0xFF);
                CHECK(word == 0x0F);
            }

            TEST_CASE("Access_And() should return and'd value without changing its value")
            {
                const atomic_t<word_t> word(0x0F);
                CHECK(word.Access_And(0xF0) == 0x00);
                CHECK(word == 0x0F);
            }

            TEST_CASE("Access_Xor() should return xor'd value without changing its value")
            {
                const atomic_t<word_t> word(0xFF);
                CHECK(word.Access_Xor(0x01) == 0xFE);
                CHECK(word == 0xFF);
            }

            TEST_CASE("Assign() should set value and return the new value")
            {
                atomic_t<word_t> word(1);
                CHECK(word.Assign(0) == 0);
                CHECK(word == 0);
            }

            TEST_CASE("Assign_Add() should set added value and return the new value")
            {
                atomic_t<word_t> word(1);
                CHECK(word.Assign_Add(1) == 2);
                CHECK(word == 2);
            }

            TEST_CASE("Assign_Subtract() should set subtracted value and return the new value")
            {
                atomic_t<word_t> word(1);
                CHECK(word.Assign_Subtract(1) == 0);
                CHECK(word == 0);
            }

            TEST_CASE("Assign_Or() should set or'd value and return the new value")
            {
                atomic_t<word_t> word(0x0F);
                CHECK(word.Assign_Or(0xF0) == 0xFF);
                CHECK(word == 0xFF);
            }

            TEST_CASE("Assign_And() should set and'd value and return the new value")
            {
                atomic_t<word_t> word(0x0F);
                CHECK(word.Assign_And(0xF0) == 0x00);
                CHECK(word == 0x00);
            }

            TEST_CASE("Assign_Xor() should set xor'd value and return the new value")
            {
                atomic_t<word_t> word(0xFF);
                CHECK(word.Assign_Xor(0x01) == 0xFE);
                CHECK(word == 0xFE);
            }

            TEST_CASE("Exchange() should set value and return the old value")
            {
                atomic_t<word_t> word(1);
                CHECK(word.Exchange(0) == 1);
                CHECK(word == 0);
            }

            TEST_CASE("Exchange_If_Equals() should set value if old value equals target and return the old value")
            {
                atomic_t<word_t> word(1);
                CHECK(word.Exchange_If_Equals(0, 0) == 1);
                CHECK(word == 1);
                CHECK(word.Exchange_If_Equals(0, 1) == 1);
                CHECK(word == 0);
            }

            TEST_CASE("Exchange_Add() should set added value and return the old value")
            {
                atomic_t<word_t> word(1);
                CHECK(word.Exchange_Add(1) == 1);
                CHECK(word == 2);
            }

            TEST_CASE("Exchange_Subtract() should set subtracted value and return the old value")
            {
                atomic_t<word_t> word(1);
                CHECK(word.Exchange_Subtract(1) == 1);
                CHECK(word == 0);
            }

            TEST_CASE("Exchange_Or() should set or'd value and return the old value")
            {
                atomic_t<word_t> word(0x0F);
                CHECK(word.Exchange_Or(0xF0) == 0x0F);
                CHECK(word == 0xFF);
            }

            TEST_CASE("Exchange_And() should set and'd value and return the old value")
            {
                atomic_t<word_t> word(0x0F);
                CHECK(word.Exchange_And(0xF0) == 0x0F);
                CHECK(word == 0x00);
            }

            TEST_CASE("Exchange_Xor() should set xor'd value and return the old value")
            {
                atomic_t<word_t> word(0xFF);
                CHECK(word.Exchange_Xor(0x01) == 0xFF);
                CHECK(word == 0xFE);
            }
        }

        TEST_SUITE("casts")
        {
            TEST_CASE("value_t() should cast to its value_t")
            {
                atomic_t<word_t> word(1);
                CHECK(static_cast<atomic_t<word_t>::value_t>(word) == 1);
                CHECK(word == 1);
                CHECK(static_cast<bool_t>(word) == true);
                CHECK(!word == false);

                word = 0;
                CHECK(word == 0);
                CHECK(static_cast<bool_t>(word) == false);
                CHECK(!word == true);
            }
        }

        TEST_SUITE("operators")
        {
            TEST_CASE("()() should return its value")
            {
                atomic_t<word_t> word(1);
                CHECK(word() == 1);
            }

            TEST_CASE("=() should set its value to other")
            {
                atomic_t<word_t> word(0);
                word = 1;
                CHECK(word == 1);
            }

            TEST_CASE("+() should return the result of value + other without changing value")
            {
                atomic_t<word_t> word(1);
                CHECK(word + 1 == 2);
                CHECK(word == 1);
            }

            TEST_CASE("-() should return the result of value - other without changing value")
            {
                atomic_t<word_t> word(1);
                CHECK(word - 1 == 0);
                CHECK(word == 1);
            }

            TEST_CASE("+=() should set value to value + other")
            {
                atomic_t<word_t> word(1);
                CHECK((word += 1) == 2);
                CHECK(word == 2);
            }

            TEST_CASE("-=() should set value to value - other")
            {
                atomic_t<word_t> word(1);
                CHECK((word -= 1) == 0);
                CHECK(word == 0);
            }

            TEST_CASE("++() should increment value and return the new value")
            {
                atomic_t<word_t> word(1);
                CHECK(++word == 2);
                CHECK(word == 2);
            }

            TEST_CASE("++(int) should increment value and return the initial value")
            {
                atomic_t<word_t> word(1);
                CHECK(word++ == 1);
                CHECK(word == 2);
            }

            TEST_CASE("--() should decrement value and return the new value")
            {
                atomic_t<word_t> word(1);
                CHECK(--word == 0);
                CHECK(word == 0);
            }

            TEST_CASE("--(int) should decrement value and return the initial value")
            {
                atomic_t<word_t> word(1);
                CHECK(word-- == 1);
                CHECK(word == 0);
            }

            TEST_CASE("~() should return ~value without changing value")
            {
                atomic_t<u8_t> u8(0x0F);
                CHECK(~u8 == 0xF0);
                CHECK(u8 == 0x0F);
            }

            TEST_CASE("|() should return value | other without changing value")
            {
                atomic_t<u8_t> u8(0x0F);
                CHECK((u8 | 0xF0) == 0xFF);
                CHECK(u8 == 0x0F);
            }

            TEST_CASE("&() should return value & other without changing value")
            {
                atomic_t<u8_t> u8(0x0F);
                CHECK((u8 & 0xF0) == 0x0);
                CHECK(u8 == 0x0F);
            }

            TEST_CASE("^() should return value ^ other without changing value")
            {
                atomic_t<u8_t> u8(0xFF);
                CHECK((u8 ^ 0x01) == 0xFE);
                CHECK(u8 == 0xFF);
            }

            TEST_CASE("|=() should set value |= other")
            {
                atomic_t<u8_t> u8(0x0F);
                CHECK((u8 |= 0xF0) == 0xFF);
                CHECK(u8 == 0xFF);
            }

            TEST_CASE("&=() should set value &= other")
            {
                atomic_t<u8_t> u8(0x0F);
                CHECK((u8 &= 0xF0) == 0x0);
                CHECK(u8 == 0x0);
            }

            TEST_CASE("^=() should set value ^= other")
            {
                atomic_t<u8_t> u8(0xFF);
                CHECK((u8 ^= 0x01) == 0xFE);
                CHECK(u8 == 0xFE);
            }
        }

        TEST_SUITE("none_t interface")
        {
            TEST_CASE("=(none_t) should set its value to the default value and return itself")
            {
                atomic_t<word_t> word(1);
                CHECK(word != atomic_t<word_t>::DEFAULT_VALUE);
                CHECK(&(word = none_t()) == &word);
                CHECK(word == atomic_t<word_t>::DEFAULT_VALUE);
            }

            TEST_CASE("==(none_t) should return true if the value is the default, else false")
            {
                atomic_t<word_t> word(1);
                CHECK(!(word == none_t()));
                word = none_t();
                CHECK((word == none_t()));
            }

            TEST_CASE("!=(none_t) should return true if the value is not the default, else false")
            {
                atomic_t<word_t> word(1);
                CHECK((word != none_t()));
                word = none_t();
                CHECK(!(word != none_t()));
            }
        }
    }

    TEST_SUITE("atomic_t<pointer_tr pointer_p>")
    {
        TEST_SUITE("objects")
        {
            TEST_CASE("default ctor() should set value to nullptr")
            {
                atomic_t<word_t*> pointer;
                CHECK(pointer == nullptr);
            }

            TEST_CASE("value ctor() should set value to value")
            {
                word_t word = 1;
                atomic_t<word_t*> pointer(&word);
                CHECK(pointer == &word);
            }

            TEST_CASE("copy ctor() should copy value from other")
            {
                word_t word = 1;
                atomic_t<word_t*> pointer_1(&word);
                atomic_t<word_t*> pointer_2(pointer_1);
                CHECK(pointer_1 == &word);
                CHECK(pointer_2 == &word);
            }

            TEST_CASE("move ctor() should copy value from other and set other's value to nullptr")
            {
                word_t word = 1;
                atomic_t<word_t*> pointer_1(&word);
                atomic_t<word_t*> pointer_2(std::move(pointer_1));
                CHECK(pointer_1 == nullptr);
                CHECK(pointer_2 == &word);
            }

            TEST_CASE("copy assignment ctor() should copy value from other")
            {
                word_t word = 1;
                atomic_t<word_t*> pointer_1(&word);
                atomic_t<word_t*> pointer_2 = pointer_1;
                CHECK(pointer_1 == &word);
                CHECK(pointer_2 == &word);
            }

            TEST_CASE("move assignment ctor() should copy value from other and set other's value to nullptr")
            {
                word_t word = 1;
                atomic_t<word_t*> pointer_1(&word);
                atomic_t<word_t*> pointer_2 = std::move(pointer_1);
                CHECK(pointer_1 == nullptr);
                CHECK(pointer_2 == &word);
            }

            TEST_CASE("dtor() should set value to nullptr")
            {
                word_t word = 1;
                atomic_t<word_t*> pointer(&word);
                pointer.~atomic_t();
                CHECK(pointer == nullptr);
            }
        }

        TEST_SUITE("methods")
        {
            TEST_CASE("Access() should return value")
            {
                word_t word = 1;
                const atomic_t<word_t*> pointer(&word);
                CHECK(pointer.Access() == &word);
            }

            TEST_CASE("Access_Add() should return added value without changing its value")
            {
                word_t words[2] = { 0, 1 };
                const atomic_t<word_t*> pointer(words + 0);
                CHECK(pointer.Access_Add(1) == words + 1);
                CHECK(pointer == words + 0);
            }

            TEST_CASE("Access_Subtract() should return subtracted value without changing its value")
            {
                word_t words[2] = { 0, 1 };
                const atomic_t<word_t*> pointer(words + 1);
                CHECK(pointer.Access_Subtract(1) == words + 0);
                CHECK(pointer == words + 1);
            }

            TEST_CASE("Assign() should set value and return the new value")
            {
                word_t word = 1;
                atomic_t<word_t*> pointer(&word);
                CHECK(pointer.Assign(nullptr) == nullptr);
                CHECK(pointer == nullptr);
            }

            TEST_CASE("Assign_Add() should set added value and return the new value")
            {
                word_t words[2] = { 0, 1 };
                atomic_t<word_t*> pointer(words + 0);
                CHECK(pointer.Assign_Add(1) == words + 1);
                CHECK(pointer == words + 1);
            }

            TEST_CASE("Assign_Subtract() should set subtracted value and return the new value")
            {
                word_t words[2] = { 0, 1 };
                atomic_t<word_t*> pointer(words + 1);
                CHECK(pointer.Assign_Subtract(1) == words + 0);
                CHECK(pointer == words + 0);
            }

            TEST_CASE("Exchange() should set value and return the old value")
            {
                word_t word = 1;
                atomic_t<word_t*> pointer(&word);
                CHECK(pointer.Exchange(nullptr) == &word);
                CHECK(pointer == nullptr);
            }

            TEST_CASE("Exchange_If_Equals() should set value if old value equals target and return the old value")
            {
                word_t word = 1;
                atomic_t<word_t*> pointer(&word);
                CHECK(pointer.Exchange_If_Equals(nullptr, nullptr) == &word);
                CHECK(pointer == &word);
                CHECK(pointer.Exchange_If_Equals(nullptr, &word) == &word);
                CHECK(pointer == nullptr);
            }

            TEST_CASE("Exchange_Add() should set added value and return the old value")
            {
                word_t words[2] = { 0, 1 };
                atomic_t<word_t*> pointer(words + 0);
                CHECK(pointer.Exchange_Add(1) == words + 0);
                CHECK(pointer == words + 1);
            }

            TEST_CASE("Exchange_Subtract() should set subtracted value and return the old value")
            {
                word_t words[2] = { 0, 1 };
                atomic_t<word_t*> pointer(words + 1);
                CHECK(pointer.Exchange_Subtract(1) == words + 1);
                CHECK(pointer == words + 0);
            }
        }

        TEST_SUITE("casts")
        {
            TEST_CASE("value_t() should cast to its value_t")
            {
                word_t word = 1;
                atomic_t<word_t*> pointer(&word);
                CHECK(static_cast<atomic_t<word_t*>::value_t>(pointer) == &word);
                CHECK(pointer == &word);
                CHECK(static_cast<bool_t>(pointer) == true);
                CHECK(!pointer == false);

                pointer = nullptr;
                CHECK(pointer == nullptr);
                CHECK(static_cast<bool_t>(pointer) == false);
                CHECK(!pointer == true);
            }
        }

        TEST_SUITE("operators")
        {
            TEST_CASE("()() should return value")
            {
                word_t word = 1;
                atomic_t<word_t*> pointer(&word);
                CHECK(pointer() == &word);
            }

            TEST_CASE("=() should set value to other")
            {
                word_t word_1 = 1;
                word_t word_2 = 2;
                atomic_t<word_t*> pointer(&word_1);
                pointer = &word_2;
                CHECK(pointer == &word_2);
            }

            TEST_CASE("+() should return value + other without changing value")
            {
                word_t words[2] = { 0, 1 };
                atomic_t<word_t*> pointer(words + 0);
                CHECK(pointer + 1 == words + 1);
                CHECK(pointer == words + 0);
            }

            TEST_CASE("-() should return value - other without changing value")
            {
                word_t words[2] = { 0, 1 };
                atomic_t<word_t*> pointer(words + 1);
                CHECK(pointer - 1 == words + 0);
                CHECK(pointer == words + 1);
            }

            TEST_CASE("+=() should set value to value + other and return the new value")
            {
                word_t words[2] = { 0, 1 };
                atomic_t<word_t*> pointer(words + 0);
                CHECK((pointer += 1) == words + 1);
                CHECK(pointer == words + 1);
            }

            TEST_CASE("-=() should set value to value - other and return the new value")
            {
                word_t words[2] = { 0, 1 };
                atomic_t<word_t*> pointer(words + 1);
                CHECK((pointer -= 1) == words + 0);
                CHECK(pointer == words + 0);
            }

            TEST_CASE("++() should increment value and return the new value")
            {
                word_t words[2] = { 0, 1 };
                atomic_t<word_t*> pointer(words + 0);
                CHECK(++pointer == words + 1);
                CHECK(pointer == words + 1);
            }

            TEST_CASE("++(int) should increment value and return the old value")
            {
                word_t words[2] = { 0, 1 };
                atomic_t<word_t*> pointer(words + 0);
                CHECK(pointer++ == words + 0);
                CHECK(pointer == words + 1);
            }

            TEST_CASE("--() should decrement value and return the new value")
            {
                word_t words[2] = { 0, 1 };
                atomic_t<word_t*> pointer(words + 1);
                CHECK(--pointer == words + 0);
                CHECK(pointer == words + 0);
            }

            TEST_CASE("--(int) should decrement value and return the old value")
            {
                word_t words[2] = { 0, 1 };
                atomic_t<word_t*> pointer(words + 1);
                CHECK(pointer-- == words + 1);
                CHECK(pointer == words + 0);
            }

            TEST_CASE("->() should -> the first object of value")
            {
                struct { const word_t word = 1; } word;
                auto pointer(&word);
                CHECK(pointer->word == 1);
            }

            TEST_CASE("*() should return a reference to the first object of value")
            {
                struct { const word_t word = 1; } word;
                auto pointer(&word);
                CHECK((*pointer).word == 1);
            }

            TEST_CASE("[]() should [] the indexed object of value")
            {
                word_t words[2] = { 0, 1 };
                auto pointer(words);
                CHECK(pointer[1] == 1);
            }
        }
    }

    TEST_SUITE("atomic_t<void_t*>")
    {
        TEST_SUITE("objects")
        {
            TEST_CASE("default ctor() should set value to nullptr")
            {
                atomic_t<void_t*> pointer;
                CHECK(pointer == nullptr);
            }

            TEST_CASE("value ctor() should set value to value")
            {
                word_t word = 1;
                atomic_t<void_t*> pointer(&word);
                CHECK(pointer == &word);
            }

            TEST_CASE("copy ctor() should copy value from other")
            {
                word_t word = 1;
                atomic_t<void_t*> pointer_1(&word);
                atomic_t<void_t*> pointer_2(pointer_1);
                CHECK(pointer_1 == &word);
                CHECK(pointer_2 == &word);
            }

            TEST_CASE("move ctor() should copy value from other and set other's value to nullptr")
            {
                word_t word = 1;
                atomic_t<void_t*> pointer_1(&word);
                atomic_t<void_t*> pointer_2(std::move(pointer_1));
                CHECK(pointer_1 == nullptr);
                CHECK(pointer_2 == &word);
            }

            TEST_CASE("copy assignment ctor() should copy value from other")
            {
                word_t word = 1;
                atomic_t<void_t*> pointer_1(&word);
                atomic_t<void_t*> pointer_2 = pointer_1;
                CHECK(pointer_1 == &word);
                CHECK(pointer_2 == &word);
            }

            TEST_CASE("move assignment ctor() should copy value from other and set other's value to nullptr")
            {
                word_t word = 1;
                atomic_t<void_t*> pointer_1(&word);
                atomic_t<void_t*> pointer_2 = std::move(pointer_1);
                CHECK(pointer_1 == nullptr);
                CHECK(pointer_2 == &word);
            }

            TEST_CASE("dtor should set value to nullptr")
            {
                word_t word = 1;
                atomic_t<void_t*> pointer(&word);
                pointer.~atomic_t();
                CHECK(pointer == nullptr);
            }
        }

        TEST_SUITE("methods")
        {
            TEST_CASE("Access() should return value")
            {
                word_t word = 1;
                const atomic_t<void_t*> pointer(&word);
                CHECK(pointer.Access() == &word);
            }

            TEST_CASE("Assign() should set value and return the new value")
            {
                word_t word = 1;
                atomic_t<void_t*> pointer(&word);
                CHECK(pointer.Assign(nullptr) == nullptr);
                CHECK(pointer == nullptr);
            }

            TEST_CASE("Exchange() should set value and return the old value")
            {
                word_t word = 1;
                atomic_t<void_t*> pointer(&word);
                CHECK(pointer.Exchange(nullptr) == &word);
                CHECK(pointer == nullptr);
            }

            TEST_CASE("Exchange_If_Equals() should set value if old value equals target and return the old value")
            {
                word_t word = 1;
                atomic_t<void_t*> pointer(&word);
                CHECK(pointer.Exchange_If_Equals(nullptr, nullptr) == &word);
                CHECK(pointer == &word);
                CHECK(pointer.Exchange_If_Equals(nullptr, &word) == &word);
                CHECK(pointer == nullptr);
            }
        }

        TEST_SUITE("casts")
        {
            TEST_CASE("value_t() should cast to its value_t")
            {
                word_t word = 1;
                atomic_t<void_t*> pointer(&word);
                CHECK(static_cast<atomic_t<void_t*>::value_t>(pointer) == &word);
                CHECK(pointer == &word);
                CHECK(static_cast<bool_t>(pointer) == true);
                CHECK(!pointer == false);

                pointer = nullptr;
                CHECK(pointer == nullptr);
                CHECK(static_cast<bool_t>(pointer) == false);
                CHECK(!pointer == true);
            }
        }

        TEST_SUITE("operators")
        {
            TEST_CASE("()() should return value")
            {
                word_t word = 1;
                atomic_t<void_t*> pointer(&word);
                CHECK(pointer() == &word);
            }

            TEST_CASE("=() should set value to other")
            {
                word_t word_1 = 1;
                word_t word_2 = 2;
                atomic_t<void_t*> pointer(&word_1);
                pointer = &word_2;
                CHECK(pointer == &word_2);
            }
        }
    }

}
