/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/bool_t.h"
#include "nkr/intrinsics.h"
#include "nkr/maybe_t.h"

#include "doctest.h"

namespace nkr {

    TEST_SUITE("none_t")
    {
        TEST_SUITE("objects")
        {
            TEST_CASE("default_ctor() should create a simple none_t")
            {
                /// [_320a98e7_654c_4711_b09e_cda91e7704d4]
                auto lambda = [](none_t a, none_t& b) -> bool_t
                {
                    return true;
                };

                none_t none;
                CHECK(lambda(none_t(), none));
                /// [_320a98e7_654c_4711_b09e_cda91e7704d4]
            }

            TEST_CASE("dtor() should destroy a simple none_t")
            {
                /// [_f57bed6f_8d65_4a14_8ed3_6b68d4f18536]
                none_t none;
                none.~none_t();
                /// [_f57bed6f_8d65_4a14_8ed3_6b68d4f18536]
            }
        }
    }

    TEST_SUITE("maybe_t<built_in_p>")
    {
        TEST_SUITE("objects")
        {
            TEST_CASE("default_ctor() should set the value to the default of the built-in")
            {
                /// [_3947e943_7bb5_4461_8fb6_7c52bae80b6c]
                maybe_t<bool_t> boolean;
                CHECK(boolean == false);

                maybe_t<u64_t> integer;
                CHECK(integer == 0);

                maybe_t<c32_t> character;
                CHECK(character == '\0');

                maybe_t<real_t> real;
                CHECK(real == 0.0);

                maybe_t<void_t*> void_pointer;
                CHECK(void_pointer == nullptr);
                /// [_3947e943_7bb5_4461_8fb6_7c52bae80b6c]
            }

            TEST_CASE("value_ctor() should set the value to the value passed in")
            {
                /// [_b2f13fd4_de97_43a6_9592_933c225f64b3]
                maybe_t<bool_t> boolean(true);
                CHECK(boolean == true);

                maybe_t<word_t> integer(1);
                CHECK(integer == 1);

                maybe_t<c32_t> character('a');
                CHECK(character == 'a');

                maybe_t<real_t> real(1.0);
                CHECK(real == 1.0);

                maybe_t<void_t*> void_pointer(&boolean);
                CHECK(void_pointer == &boolean);
                /// [_b2f13fd4_de97_43a6_9592_933c225f64b3]
            }

            TEST_CASE("copy_ctor() should copy other's value without changing it")
            {
                /// [_e886a1de_1282_4231_9772_a2554ff0b93e]
                maybe_t<bool_t> other_boolean(true);
                maybe_t<bool_t> boolean(other_boolean);
                CHECK(other_boolean == true);
                CHECK(boolean == true);

                maybe_t<word_t> other_integer(1);
                maybe_t<word_t> integer(other_integer);
                CHECK(other_integer == 1);
                CHECK(integer == 1);

                maybe_t<c32_t> other_character('a');
                maybe_t<c32_t> character(other_character);
                CHECK(other_character == 'a');
                CHECK(character == 'a');

                maybe_t<real_t> other_real(1.0);
                maybe_t<real_t> real(other_real);
                CHECK(other_real == 1.0);
                CHECK(real == 1.0);

                maybe_t<void_t*> other_void_pointer(&boolean);
                maybe_t<void_t*> void_pointer(other_void_pointer);
                CHECK(other_void_pointer == &boolean);
                CHECK(void_pointer == &boolean);
                /// [_e886a1de_1282_4231_9772_a2554ff0b93e]
            }

            TEST_CASE("move_ctor() should exchange other's value for the default")
            {
                /// [_c08944e9_0848_4e7a_b121_821a82f89118]
                maybe_t<bool_t> other_boolean(true);
                maybe_t<bool_t> boolean(std::move(other_boolean));
                CHECK(other_boolean == false);
                CHECK(boolean == true);

                maybe_t<word_t> other_integer(1);
                maybe_t<word_t> integer(std::move(other_integer));
                CHECK(other_integer == 0);
                CHECK(integer == 1);

                maybe_t<c32_t> other_character('a');
                maybe_t<c32_t> character(std::move(other_character));
                CHECK(other_character == '\0');
                CHECK(character == 'a');

                maybe_t<real_t> other_real(1.0);
                maybe_t<real_t> real(std::move(other_real));
                CHECK(other_real == 0.0);
                CHECK(real == 1.0);

                maybe_t<void_t*> other_void_pointer(&boolean);
                maybe_t<void_t*> void_pointer(std::move(other_void_pointer));
                CHECK(other_void_pointer == nullptr);
                CHECK(void_pointer == &boolean);
                /// [_c08944e9_0848_4e7a_b121_821a82f89118]
            }

            TEST_CASE("value_assignment_ctor() should set value to the rhs value")
            {
                /// [_fcd0d654_7864_4bd9_b798_18a69d737e71]
                maybe_t<bool_t> boolean = true;
                CHECK(boolean == true);
                boolean = false;
                CHECK(boolean == false);

                maybe_t<word_t> integer = 1;
                CHECK(integer == 1);
                integer = 0;
                CHECK(integer == 0);

                maybe_t<c32_t> character = 'a';
                CHECK(character == 'a');
                character = '\0';
                CHECK(character == '\0');

                maybe_t<real_t> real = 1.0;
                CHECK(real == 1.0);
                real = 0.0;
                CHECK(real == 0.0);

                maybe_t<void_t*> void_pointer = &boolean;
                CHECK(void_pointer == &boolean);
                void_pointer = nullptr;
                CHECK(void_pointer == nullptr);
                /// [_fcd0d654_7864_4bd9_b798_18a69d737e71]
            }

            TEST_CASE("copy_assignment_ctor() should copy other's value without changing it")
            {
                /// [_45d04972_08a7_492c_90a1_3936d1ed7bcb]
                maybe_t<bool_t> other_boolean(true);
                maybe_t<bool_t> boolean = other_boolean;
                CHECK(other_boolean == true);
                CHECK(boolean == true);

                maybe_t<word_t> other_integer(1);
                maybe_t<word_t> integer = other_integer;
                CHECK(other_integer == 1);
                CHECK(integer == 1);

                maybe_t<c32_t> other_character('a');
                maybe_t<c32_t> character = other_character;
                CHECK(other_character == 'a');
                CHECK(character == 'a');

                maybe_t<real_t> other_real(1.0);
                maybe_t<real_t> real = other_real;
                CHECK(other_real == 1.0);
                CHECK(real == 1.0);

                maybe_t<void_t*> other_void_pointer(&boolean);
                maybe_t<void_t*> void_pointer = other_void_pointer;
                CHECK(other_void_pointer == &boolean);
                CHECK(void_pointer == &boolean);
                /// [_45d04972_08a7_492c_90a1_3936d1ed7bcb]
            }

            TEST_CASE("move_assignment_ctor() should exchange other's value for the default")
            {
                /// [_71ee8a31_68ef_4cc1_8906_9cb9e5d7fa45]
                maybe_t<bool_t> other_boolean(true);
                maybe_t<bool_t> boolean = std::move(other_boolean);
                CHECK(other_boolean == false);
                CHECK(boolean == true);

                maybe_t<word_t> other_integer(1);
                maybe_t<word_t> integer = std::move(other_integer);
                CHECK(other_integer == 0);
                CHECK(integer == 1);

                maybe_t<c32_t> other_character('a');
                maybe_t<c32_t> character = std::move(other_character);
                CHECK(other_character == '\0');
                CHECK(character == 'a');

                maybe_t<real_t> other_real(1.0);
                maybe_t<real_t> real = std::move(other_real);
                CHECK(other_real == 0.0);
                CHECK(real == 1.0);

                maybe_t<void_t*> other_void_pointer(&boolean);
                maybe_t<void_t*> void_pointer = std::move(other_void_pointer);
                CHECK(other_void_pointer == nullptr);
                CHECK(void_pointer == &boolean);
                /// [_71ee8a31_68ef_4cc1_8906_9cb9e5d7fa45]
            }

            TEST_CASE("dtor() should set its value to default")
            {
                /// [_b76161ed_4157_4d10_9297_7acc4df805d4]
                maybe_t<bool_t> boolean(true);
                boolean.~maybe_t<bool_t>();
                CHECK(boolean == false);

                maybe_t<word_t> integer(1);
                integer.~maybe_t<word_t>();
                CHECK(integer == 0);

                maybe_t<c32_t> character('a');
                character.~maybe_t<c32_t>();
                CHECK(character == '\0');

                maybe_t<real_t> real(1.0);
                real.~maybe_t<real_t>();
                CHECK(real == 0.0);

                maybe_t<void_t*> void_pointer(&boolean);
                void_pointer.~maybe_t<void_t*>();
                CHECK(void_pointer == nullptr);
                /// [_b76161ed_4157_4d10_9297_7acc4df805d4]
            }
        }

        TEST_SUITE("casts")
        {
            TEST_CASE("value_t&() should return the mutable built-in type")
            {
                /// [_862b58a5_fbb6_43cc_a7cd_54ca4f580b37]
                maybe_t<bool_t> boolean = true;
                CHECK(boolean == true);
                CHECK(!boolean == false);
                boolean = false;
                CHECK(boolean == false);
                CHECK(!boolean == true);

                maybe_t<word_t> integer = 1;
                CHECK(integer == 1);
                CHECK(static_cast<bool_t>(integer) == true);
                CHECK(!integer == false);
                integer = 0;
                CHECK(integer == 0);
                CHECK(static_cast<bool_t>(integer) == false);
                CHECK(!integer == true);

                maybe_t<c32_t> character = 'a';
                CHECK(character == 'a');
                CHECK(static_cast<bool_t>(character) == true);
                CHECK(!character == false);
                character = '\0';
                CHECK(character == '\0');
                CHECK(static_cast<bool_t>(character) == false);
                CHECK(!character == true);

                maybe_t<real_t> real = 1.0;
                CHECK(real == 1.0);
                CHECK(static_cast<bool_t>(real) == true);
                CHECK(!real == false);
                real = 0.0;
                CHECK(real == 0.0);
                CHECK(static_cast<bool_t>(real) == false);
                CHECK(!real == true);

                maybe_t<void_t*> void_pointer = &boolean;
                CHECK(void_pointer == &boolean);
                CHECK(static_cast<bool_t>(void_pointer) == true);
                CHECK(!void_pointer == false);
                void_pointer = nullptr;
                CHECK(void_pointer == nullptr);
                CHECK(static_cast<bool_t>(void_pointer) == false);
                CHECK(!void_pointer == true);
                /// [_862b58a5_fbb6_43cc_a7cd_54ca4f580b37]
            }

            TEST_CASE("const value_t&() should return the immutable built-in type")
            {
                /// [_f755ffdd_dead_4f09_9348_643b5f6b089e]
                const maybe_t<bool_t> boolean = true;
                CHECK(boolean == true);
                CHECK(!boolean == false);

                const maybe_t<word_t> integer = 1;
                CHECK(integer == 1);
                CHECK(static_cast<bool_t>(integer) == true);
                CHECK(!integer == false);

                const maybe_t<c32_t> character = 'a';
                CHECK(character == 'a');
                CHECK(static_cast<bool_t>(character) == true);
                CHECK(!character == false);

                const maybe_t<real_t> real = 1.0;
                CHECK(real == 1.0);
                CHECK(static_cast<bool_t>(real) == true);
                CHECK(!real == false);

                const maybe_t<const void_t*> void_pointer = &boolean;
                CHECK(void_pointer == &boolean);
                CHECK(static_cast<bool_t>(void_pointer) == true);
                CHECK(!void_pointer == false);
                /// [_f755ffdd_dead_4f09_9348_643b5f6b089e]
            }

            TEST_CASE("bool_t() should return true if value != none_t() and false if value == none_t()")
            {
                /// [_5b448395_0813_4618_86e4_a2413ac28b1b]
                maybe_t<bool_t> boolean = true;
                CHECK(static_cast<bool_t>(boolean) == true);
                boolean = false;
                CHECK(static_cast<bool_t>(boolean) == false);

                maybe_t<word_t> integer = 1;
                CHECK(static_cast<bool_t>(integer) == true);
                integer = 0;
                CHECK(static_cast<bool_t>(integer) == false);

                maybe_t<c32_t> character = 'a';
                CHECK(static_cast<bool_t>(character) == true);
                character = '\0';
                CHECK(static_cast<bool_t>(character) == false);

                maybe_t<real_t> real = 1.0;
                CHECK(static_cast<bool_t>(real) == true);
                real = 0.0;
                CHECK(static_cast<bool_t>(real) == false);

                maybe_t<void_t*> void_pointer = &boolean;
                CHECK(static_cast<bool_t>(void_pointer) == true);
                void_pointer = nullptr;
                CHECK(static_cast<bool_t>(void_pointer) == false);
                /// [_5b448395_0813_4618_86e4_a2413ac28b1b]
            }
        }

        TEST_SUITE("operators")
        {
            TEST_CASE("()() should return its mutable value")
            {
                /// [_43216f39_12c8_4163_8c44_e23e9b8a26d5]
                maybe_t<bool_t> boolean = true;
                CHECK(boolean() == true);
                boolean() = false;
                CHECK(boolean() == false);

                maybe_t<word_t> integer = 1;
                CHECK(integer() == 1);
                integer() = 0;
                CHECK(integer() == 0);

                maybe_t<c32_t> character = 'a';
                CHECK(character() == 'a');
                character() = '\0';
                CHECK(character() == '\0');

                maybe_t<real_t> real = 1.0;
                CHECK(real() == 1.0);
                real() = 0.0;
                CHECK(real() == 0.0);

                maybe_t<void_t*> void_pointer = &boolean;
                CHECK(void_pointer() == &boolean);
                void_pointer() = nullptr;
                CHECK(void_pointer() == nullptr);
                /// [_43216f39_12c8_4163_8c44_e23e9b8a26d5]
            }

            TEST_CASE("()() const should return its immutable value")
            {
                /// [_4ae71520_60de_44f6_91e3_ad72a54234ea]
                const maybe_t<bool_t> boolean = true;
                CHECK(boolean() == true);

                const maybe_t<word_t> integer = 1;
                CHECK(integer() == 1);

                const maybe_t<c32_t> character = 'a';
                CHECK(character() == 'a');

                const maybe_t<real_t> real = 1.0;
                CHECK(real() == 1.0);

                const maybe_t<const void_t*> void_pointer = &boolean;
                CHECK(void_pointer() == &boolean);
                /// [_4ae71520_60de_44f6_91e3_ad72a54234ea]
            }

            TEST_CASE("!() should return true if value == none_t() and false if value != none_t()")
            {
                /// [_1b43a17a_7465_4cb0_a4a1_0b003631b869]
                maybe_t<bool_t> boolean = true;
                CHECK(!boolean == false);
                boolean = false;
                CHECK(!boolean == true);

                maybe_t<word_t> integer = 1;
                CHECK(!integer == false);
                integer = 0;
                CHECK(!integer == true);

                maybe_t<c32_t> character = 'a';
                CHECK(!character == false);
                character = '\0';
                CHECK(!character == true);

                maybe_t<real_t> real = 1.0;
                CHECK(!real == false);
                real = 0.0;
                CHECK(!real == true);

                maybe_t<void_t*> void_pointer = &boolean;
                CHECK(!void_pointer == false);
                void_pointer = nullptr;
                CHECK(!void_pointer == true);
                /// [_1b43a17a_7465_4cb0_a4a1_0b003631b869]
            }
        }

        TEST_SUITE("none_t interface")
        {
            TEST_CASE("=(none_t) should set its value to the default value and return itself")
            {
                /// [_07804510_9e9d_4297_bf1e_53cc951ccde9]
                maybe_t<bool_t> boolean = true;
                CHECK(boolean != none_t());
                CHECK(&(boolean = none_t()) == &boolean);
                CHECK(boolean == none_t());

                maybe_t<word_t> integer = 1;
                CHECK(integer != none_t());
                CHECK(&(integer = none_t()) == &integer);
                CHECK(integer == none_t());

                maybe_t<c32_t> character = 'a';
                CHECK(character != none_t());
                CHECK(&(character = none_t()) == &character);
                CHECK(character == none_t());

                maybe_t<real_t> real = 1.0;
                CHECK(real != none_t());
                CHECK(&(real = none_t()) == &real);
                CHECK(real == none_t());

                maybe_t<void_t*> void_pointer = &boolean;
                CHECK(void_pointer != none_t());
                CHECK(&(void_pointer = none_t()) == &void_pointer);
                CHECK(void_pointer == none_t());
                /// [_07804510_9e9d_4297_bf1e_53cc951ccde9]
            }

            TEST_CASE("==(none_t) should return true if the value is the default, else false")
            {
                /// [_db6ed293_bce8_433f_adb1_26371f0faef5]
                maybe_t<bool_t> boolean = true;
                CHECK(!(boolean == none_t()));
                boolean = none_t();
                CHECK(boolean == none_t());

                maybe_t<word_t> integer = 1;
                CHECK(!(integer == none_t()));
                integer = none_t();
                CHECK(integer == none_t());

                maybe_t<c32_t> character = 'a';
                CHECK(!(character == none_t()));
                character = none_t();
                CHECK(character == none_t());

                maybe_t<real_t> real = 1.0;
                CHECK(!(real == none_t()));
                real = none_t();
                CHECK(real == none_t());

                maybe_t<void_t*> void_pointer = &boolean;
                CHECK(!(void_pointer == none_t()));
                void_pointer = none_t();
                CHECK(void_pointer == none_t());
                /// [_db6ed293_bce8_433f_adb1_26371f0faef5]
            }

            TEST_CASE("!=(none_t) should return true if the value is not the default, else false")
            {
                /// [_d1852cf1_429a_44f9_83fe_e5cceeee5af6]
                maybe_t<bool_t> boolean = true;
                CHECK(boolean != none_t());
                boolean = none_t();
                CHECK(!(boolean != none_t()));

                maybe_t<word_t> integer = 1;
                CHECK(integer != none_t());
                integer = none_t();
                CHECK(!(integer != none_t()));

                maybe_t<c32_t> character = 'a';
                CHECK(character != none_t());
                character = none_t();
                CHECK(!(character != none_t()));

                maybe_t<real_t> real = 1.0;
                CHECK(real != none_t());
                real = none_t();
                CHECK(!(real != none_t()));

                maybe_t<void_t*> void_pointer = &boolean;
                CHECK(void_pointer != none_t());
                void_pointer = none_t();
                CHECK(!(void_pointer != none_t()));
                /// [_d1852cf1_429a_44f9_83fe_e5cceeee5af6]
            }
        }

        TEST_SUITE("type")
        {
            TEST_SUITE("this type should be able to act like its underlying value")
            {
                TEST_CASE("standard boolean")
                {
                    std_bool_t v = true;
                    std_bool_t boolean = v;
                    maybe_t<std_bool_t> maybe_boolean = v;

                    CHECK((maybe_boolean = v) == (boolean = v));

                    CHECK((maybe_boolean, boolean));
                    CHECK((!!maybe_boolean, !!boolean));
                    CHECK(maybe_boolean && boolean);
                    CHECK(maybe_boolean || boolean);

                    CHECK(maybe_boolean == boolean);
                    CHECK_FALSE(maybe_boolean != boolean);
                    CHECK(maybe_boolean ? maybe_boolean() : boolean);

                    CHECK(&maybe_boolean() != &boolean);
                }

                TEST_CASE("integer")
                {
                    using integer_t = s32_t;
                    constexpr const integer_t v = 16;
                    integer_t integer = v;
                    maybe_t<integer_t> maybe_integer = v;

                    CHECK(+maybe_integer == +integer);
                    CHECK(-maybe_integer == -integer);
                    CHECK(maybe_integer + v == integer + v);
                    CHECK(maybe_integer - v == integer - v);
                    CHECK(maybe_integer * v == integer * v);
                    CHECK(maybe_integer / v == integer / v);
                    CHECK(maybe_integer % v == integer % v);

                    CHECK(~maybe_integer == ~integer);
                    CHECK((maybe_integer | v) == (integer | v));
                    CHECK((maybe_integer & v) == (integer & v));
                    CHECK((maybe_integer ^ v) == (integer ^ v));
                    CHECK((maybe_integer << 1) == (integer << 1));
                    CHECK((maybe_integer >> 1) == (integer >> 1));

                    CHECK((maybe_integer = v) == (integer = v));
                    maybe_integer = integer = v;
                    CHECK((maybe_integer += v) == (integer += v));
                    maybe_integer = integer = v;
                    CHECK((maybe_integer -= v) == (integer -= v));
                    maybe_integer = integer = v;
                    CHECK((maybe_integer *= v) == (integer *= v));
                    maybe_integer = integer = v;
                    CHECK((maybe_integer /= v) == (integer /= v));
                    maybe_integer = integer = v;
                    CHECK((maybe_integer %= v) == (integer %= v));
                    maybe_integer = integer = v;

                    CHECK((maybe_integer |= v) == (integer |= v));
                    maybe_integer = integer = v;
                    CHECK((maybe_integer &= v) == (integer &= v));
                    maybe_integer = integer = v;
                    CHECK((maybe_integer ^= v) == (integer ^= v));
                    maybe_integer = integer = v;
                    CHECK((maybe_integer <<= 1) == (integer <<= 1));
                    maybe_integer = integer = v;
                    CHECK((maybe_integer >>= 1) == (integer >>= 1));
                    maybe_integer = integer = v;

                    CHECK(++maybe_integer == ++integer);
                    CHECK(maybe_integer++ == integer++);
                    CHECK(--maybe_integer == --integer);
                    CHECK(maybe_integer-- == integer--);

                    CHECK((maybe_integer, integer));
                    CHECK((!!maybe_integer, !!integer));
                    CHECK(maybe_integer && integer);
                    CHECK(maybe_integer || integer);

                    CHECK(maybe_integer == integer);
                    CHECK_FALSE(maybe_integer != integer);
                    CHECK_FALSE(maybe_integer < integer);
                    CHECK_FALSE(maybe_integer > integer);
                    CHECK(maybe_integer <= integer);
                    CHECK(maybe_integer >= integer);
                    CHECK((maybe_integer <=> integer == 0));
                    CHECK(maybe_integer ? maybe_integer() : integer);

                    CHECK(&maybe_integer() != &integer);
                }

                TEST_CASE("character")
                {
                    using character_t = c32_t;
                    constexpr const character_t v = 'a';
                    character_t character = v;
                    maybe_t<character_t> maybe_character = v;

                    CHECK(+maybe_character == +character);
                    CHECK(maybe_character + v == character + v);
                    CHECK(maybe_character - v == character - v);
                    CHECK(maybe_character * v == character * v);
                    CHECK(maybe_character / v == character / v);
                    CHECK(maybe_character % v == character % v);

                    CHECK(~maybe_character == ~character);
                    CHECK((maybe_character | v) == (character | v));
                    CHECK((maybe_character & v) == (character & v));
                    CHECK((maybe_character ^ v) == (character ^ v));
                    CHECK((maybe_character << 1) == (character << 1));
                    CHECK((maybe_character >> 1) == (character >> 1));

                    CHECK((maybe_character = v) == (character = v));
                    maybe_character = character = v;
                    CHECK((maybe_character += v) == (character += v));
                    maybe_character = character = v;
                    CHECK((maybe_character -= v) == (character -= v));
                    maybe_character = character = v;
                    CHECK((maybe_character *= v) == (character *= v));
                    maybe_character = character = v;
                    CHECK((maybe_character /= v) == (character /= v));
                    maybe_character = character = v;
                    CHECK((maybe_character %= v) == (character %= v));
                    maybe_character = character = v;

                    CHECK((maybe_character |= v) == (character |= v));
                    maybe_character = character = v;
                    CHECK((maybe_character &= v) == (character &= v));
                    maybe_character = character = v;
                    CHECK((maybe_character ^= v) == (character ^= v));
                    maybe_character = character = v;
                    CHECK((maybe_character <<= 1) == (character <<= 1));
                    maybe_character = character = v;
                    CHECK((maybe_character >>= 1) == (character >>= 1));
                    maybe_character = character = v;

                    CHECK(++maybe_character == ++character);
                    CHECK(maybe_character++ == character++);
                    CHECK(--maybe_character == --character);
                    CHECK(maybe_character-- == character--);

                    CHECK((maybe_character, character));
                    CHECK((!!maybe_character, !!character));
                    CHECK(maybe_character && character);
                    CHECK(maybe_character || character);

                    CHECK(maybe_character == character);
                    CHECK_FALSE(maybe_character != character);
                    CHECK_FALSE(maybe_character < character);
                    CHECK_FALSE(maybe_character > character);
                    CHECK(maybe_character <= character);
                    CHECK(maybe_character >= character);
                    CHECK((maybe_character <=> character == 0));
                    CHECK(maybe_character ? maybe_character() : character);

                    CHECK(&maybe_character() != &character);
                }

                TEST_CASE("real")
                {
                    constexpr const real_t v = 16.0;
                    real_t real = v;
                    maybe_t<real_t> maybe_real = v;

                    CHECK(+maybe_real == +real);
                    CHECK(-maybe_real == -real);
                    CHECK(maybe_real + v == real + v);
                    CHECK(maybe_real - v == real - v);
                    CHECK(maybe_real * v == real * v);
                    CHECK(maybe_real / v == real / v);

                    CHECK((maybe_real = v) == (real = v));
                    maybe_real = real = v;
                    CHECK((maybe_real += v) == (real += v));
                    maybe_real = real = v;
                    CHECK((maybe_real -= v) == (real -= v));
                    maybe_real = real = v;
                    CHECK((maybe_real *= v) == (real *= v));
                    maybe_real = real = v;
                    CHECK((maybe_real /= v) == (real /= v));
                    maybe_real = real = v;

                    CHECK(++maybe_real == ++real);
                    CHECK(maybe_real++ == real++);
                    CHECK(--maybe_real == --real);
                    CHECK(maybe_real-- == real--);

                    CHECK((maybe_real, real));
                    CHECK((!!maybe_real, !!real));
                    CHECK(maybe_real && real);
                    CHECK(maybe_real || real);

                    CHECK(maybe_real == real);
                    CHECK_FALSE(maybe_real != real);
                    CHECK_FALSE(maybe_real < real);
                    CHECK_FALSE(maybe_real > real);
                    CHECK(maybe_real <= real);
                    CHECK(maybe_real >= real);
                    CHECK((maybe_real <=> real == 0));
                    CHECK(maybe_real ? maybe_real() : real);

                    CHECK(&maybe_real() != &real);
                }

                TEST_CASE("pointer")
                {
                    class type_t
                    {
                    public:
                        word_t value;

                    public:
                        type_t(word_t value) :
                            value(value)
                        {
                        }

                        ~type_t()
                        {
                        }

                    public:
                        bool_t operator ==(const type_t& other)
                        {
                            return this->value == other.value;
                        }
                    };

                    using pointer_t = type_t*;
                    type_t vs[3] = { 16, 16, 16 };
                    pointer_t pointer = vs + 1;
                    maybe_t<pointer_t> maybe_pointer = pointer;

                    CHECK(+maybe_pointer == +pointer);
                    CHECK(maybe_pointer + 1 == pointer + 1);
                    CHECK(maybe_pointer - 1 == pointer - 1);

                    CHECK((maybe_pointer = vs + 1) == (pointer = vs + 1));
                    CHECK((maybe_pointer += 1) == (pointer += 1));
                    CHECK((maybe_pointer -= 1) == (pointer -= 1));

                    CHECK(++maybe_pointer == ++pointer);
                    CHECK(--maybe_pointer == --pointer);
                    CHECK(maybe_pointer++ == pointer++);
                    CHECK(maybe_pointer-- == pointer--);

                    CHECK((maybe_pointer, pointer));
                    CHECK((!!maybe_pointer, !!pointer));
                    CHECK(maybe_pointer && pointer);
                    CHECK(maybe_pointer || pointer);

                    CHECK(maybe_pointer == pointer);
                    CHECK_FALSE(maybe_pointer != pointer);
                    CHECK_FALSE(maybe_pointer < pointer);
                    CHECK_FALSE(maybe_pointer > pointer);
                    CHECK(maybe_pointer <= pointer);
                    CHECK(maybe_pointer >= pointer);
                    CHECK((maybe_pointer <=> pointer == 0));
                    CHECK(maybe_pointer ? maybe_pointer() : pointer);

                    CHECK(*maybe_pointer == *pointer);
                    CHECK(&maybe_pointer() != &pointer);
                    CHECK(maybe_pointer->value == pointer->value);
                    CHECK(maybe_pointer[0] == pointer[0]);
                }
            }
        }
    }

}
