/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include <thread>

#include "nkr/os.h"

#include "intrinsics.h"

namespace nkr { namespace os { namespace atomic {

    TEST_SUITE("Access")
    {
        TEST_SUITE("should return value without changing it")
        {
            TEST_CASE("bool_t")
            {
                bool_t boolean = false;
                bool_t access = nkr::os::atomic::Access(boolean);
                CHECK(nkr::os::atomic::Access(boolean) == access);
                CHECK(nkr::os::atomic::Access(boolean) == false);
            }
            TEST_CASE("u8_t")
            {
                u8_t u8 = 8;
                u8_t access = nkr::os::atomic::Access(u8);
                CHECK(nkr::os::atomic::Access(u8) == access);
                CHECK(nkr::os::atomic::Access(u8) == 8);
            }
            TEST_CASE("u16_t")
            {
                u16_t u16 = 16;
                u16_t access = nkr::os::atomic::Access(u16);
                CHECK(nkr::os::atomic::Access(u16) == access);
                CHECK(nkr::os::atomic::Access(u16) == 16);
            }
            TEST_CASE("u32_t")
            {
                u32_t u32 = 32;
                u32_t access = nkr::os::atomic::Access(u32);
                CHECK(nkr::os::atomic::Access(u32) == access);
                CHECK(nkr::os::atomic::Access(u32) == 32);
            }
            TEST_CASE("u64_t")
            {
            #if defined(nkr_IS_64_BIT)
                u64_t u64 = 64;
                u64_t access = nkr::os::atomic::Access(u64);
                CHECK(nkr::os::atomic::Access(u64) == access);
                CHECK(nkr::os::atomic::Access(u64) == 64);
            #endif
            }
            TEST_CASE("s8_t")
            {
                s8_t s8 = -8;
                s8_t access = nkr::os::atomic::Access(s8);
                CHECK(nkr::os::atomic::Access(s8) == access);
                CHECK(nkr::os::atomic::Access(s8) == -8);
            }
            TEST_CASE("s16_t")
            {
                s16_t s16 = -16;
                s16_t access = nkr::os::atomic::Access(s16);
                CHECK(nkr::os::atomic::Access(s16) == access);
                CHECK(nkr::os::atomic::Access(s16) == -16);
            }
            TEST_CASE("s32_t")
            {
                s32_t s32 = -32;
                s32_t access = nkr::os::atomic::Access(s32);
                CHECK(nkr::os::atomic::Access(s32) == access);
                CHECK(nkr::os::atomic::Access(s32) == -32);
            }
            TEST_CASE("s64_t")
            {
            #if defined(nkr_IS_64_BIT)
                s64_t s64 = -64;
                s64_t access = nkr::os::atomic::Access(s64);
                CHECK(nkr::os::atomic::Access(s64) == access);
                CHECK(nkr::os::atomic::Access(s64) == -64);
            #endif
            }
            TEST_CASE("void_t*")
            {
                void_t* void_pointer = nullptr;
                void_t* access = nkr::os::atomic::Access(void_pointer);
                CHECK(nkr::os::atomic::Access(void_pointer) == access);
                CHECK(nkr::os::atomic::Access(void_pointer) == nullptr);
            }
            TEST_CASE("bool_t*")
            {
                bool_t boolean = false;
                bool_t* boolean_pointer = &boolean;
                bool_t* access = nkr::os::atomic::Access(boolean_pointer);
                CHECK(nkr::os::atomic::Access(boolean_pointer) == access);
                CHECK(nkr::os::atomic::Access(boolean_pointer) == &boolean);
            }
        }
    }

    TEST_SUITE("Access_Add")
    {
        TEST_SUITE("should return added values without changing the original")
        {
            TEST_CASE("u8_t")
            {
                u8_t u8 = 8;
                CHECK(nkr::os::atomic::Access_Add(u8, 1) == 9);
                CHECK(u8 == 8);
            }
            TEST_CASE("u16_t")
            {
                u16_t u16 = 16;
                CHECK(nkr::os::atomic::Access_Add(u16, 1) == 17);
                CHECK(u16 == 16);
            }
            TEST_CASE("u32_t")
            {
                u32_t u32 = 32;
                CHECK(nkr::os::atomic::Access_Add(u32, 1) == 33);
                CHECK(u32 == 32);
            }
            TEST_CASE("u64_t")
            {
            #if defined(nkr_IS_64_BIT)
                u64_t u64 = 64;
                CHECK(nkr::os::atomic::Access_Add(u64, 1) == 65);
                CHECK(u64 == 64);
            #endif
            }
            TEST_CASE("s8_t")
            {
                s8_t s8 = -8;
                CHECK(nkr::os::atomic::Access_Add(s8, -1) == -9);
                CHECK(s8 == -8);
            }
            TEST_CASE("s16_t")
            {
                s16_t s16 = -16;
                CHECK(nkr::os::atomic::Access_Add(s16, -1) == -17);
                CHECK(s16 == -16);
            }
            TEST_CASE("s32_t")
            {
                s32_t s32 = -32;
                CHECK(nkr::os::atomic::Access_Add(s32, -1) == -33);
                CHECK(s32 == -32);
            }
            TEST_CASE("s64_t")
            {
            #if defined(nkr_IS_64_BIT)
                s64_t s64 = -64;
                CHECK(nkr::os::atomic::Access_Add(s64, -1) == -65);
                CHECK(s64 == -64);
            #endif
            }
            TEST_CASE("bool_t*")
            {
                bool_t booleans[2] = { true, true };
                bool_t* boolean_pointer = booleans;
                CHECK(nkr::os::atomic::Access_Add(boolean_pointer, 1) == booleans + 1);
                CHECK(boolean_pointer == booleans + 0);
            }
        }
    }

    TEST_SUITE("Access_Subtract")
    {
        TEST_SUITE("should return subtracted values without changing the original")
        {
            TEST_CASE("u8_t")
            {
                u8_t u8 = 8;
                CHECK(nkr::os::atomic::Access_Subtract(u8, 1) == 7);
                CHECK(u8 == 8);
            }
            TEST_CASE("u16_t")
            {
                u16_t u16 = 16;
                CHECK(nkr::os::atomic::Access_Subtract(u16, 1) == 15);
                CHECK(u16 == 16);
            }
            TEST_CASE("u32_t")
            {
                u32_t u32 = 32;
                CHECK(nkr::os::atomic::Access_Subtract(u32, 1) == 31);
                CHECK(u32 == 32);
            }
            TEST_CASE("u64_t")
            {
            #if defined(nkr_IS_64_BIT)
                u64_t u64 = 64;
                CHECK(nkr::os::atomic::Access_Subtract(u64, 1) == 63);
                CHECK(u64 == 64);
            #endif
            }
            TEST_CASE("s8_t")
            {
                s8_t s8 = -8;
                CHECK(nkr::os::atomic::Access_Subtract(s8, -1) == -7);
                CHECK(s8 == -8);
            }
            TEST_CASE("s16_t")
            {
                s16_t s16 = -16;
                CHECK(nkr::os::atomic::Access_Subtract(s16, -1) == -15);
                CHECK(s16 == -16);
            }
            TEST_CASE("s32_t")
            {
                s32_t s32 = -32;
                CHECK(nkr::os::atomic::Access_Subtract(s32, -1) == -31);
                CHECK(s32 == -32);
            }
            TEST_CASE("s64_t")
            {
            #if defined(nkr_IS_64_BIT)
                s64_t s64 = -64;
                CHECK(nkr::os::atomic::Access_Subtract(s64, -1) == -63);
                CHECK(s64 == -64);
            #endif
            }
            TEST_CASE("bool_t*")
            {
                bool_t booleans[2] = { true, true };
                bool_t* boolean_pointer = booleans + 1;
                CHECK(nkr::os::atomic::Access_Subtract(boolean_pointer, 1) == booleans + 0);
                CHECK(boolean_pointer == booleans + 1);
            }
        }
    }

    TEST_SUITE("Access_Or")
    {
        TEST_SUITE("should return or'd values without changing the original")
        {
            TEST_CASE("u8_t")
            {
                u8_t u8 = 0x0F;
                CHECK(nkr::os::atomic::Access_Or(u8, 0xF0) == 0xFF);
                CHECK(u8 == 0x0F);
            }
            TEST_CASE("u16_t")
            {
                u16_t u16 = 0x00FF;
                CHECK(nkr::os::atomic::Access_Or(u16, 0xFF00) == 0xFFFF);
                CHECK(u16 == 0x00FF);
            }
            TEST_CASE("u32_t")
            {
                u32_t u32 = 0x0000FFFF;
                CHECK(nkr::os::atomic::Access_Or(u32, 0xFFFF0000) == 0xFFFFFFFF);
                CHECK(u32 == 0x0000FFFF);
            }
            TEST_CASE("u64_t")
            {
            #if defined(nkr_IS_64_BIT)
                u64_t u64 = 0x00000000FFFFFFFF;
                CHECK(nkr::os::atomic::Access_Or(u64, 0xFFFFFFFF00000000) == 0xFFFFFFFFFFFFFFFF);
                CHECK(u64 == 0x00000000FFFFFFFF);
            #endif
            }
            TEST_CASE("s8_t")
            {
                s8_t s8 = 0x0F;
                CHECK(nkr::os::atomic::Access_Or(s8, 0x70) == 0x7F);
                CHECK(s8 == 0x0F);
            }
            TEST_CASE("s16_t")
            {
                s16_t s16 = 0x00FF;
                CHECK(nkr::os::atomic::Access_Or(s16, 0x7F00) == 0x7FFF);
                CHECK(s16 == 0x00FF);
            }
            TEST_CASE("s32_t")
            {
                s32_t s32 = 0x0000FFFF;
                CHECK(nkr::os::atomic::Access_Or(s32, 0x7FFF0000) == 0x7FFFFFFF);
                CHECK(s32 == 0x0000FFFF);
            }
            TEST_CASE("s64_t")
            {
            #if defined(nkr_IS_64_BIT)
                s64_t s64 = 0x00000000FFFFFFFF;
                CHECK(nkr::os::atomic::Access_Or(s64, 0x7FFFFFFF00000000) == 0x7FFFFFFFFFFFFFFF);
                CHECK(s64 == 0x00000000FFFFFFFF);
            #endif
            }
        }
    }

    TEST_SUITE("Access_And")
    {
        TEST_SUITE("should return and'd values without changing the original")
        {
            TEST_CASE("u8_t")
            {
                u8_t u8 = 0x0F;
                CHECK(nkr::os::atomic::Access_And(u8, 0xF0) == 0x0);
                CHECK(u8 == 0x0F);
            }
            TEST_CASE("u16_t")
            {
                u16_t u16 = 0x00FF;
                CHECK(nkr::os::atomic::Access_And(u16, 0xFF00) == 0x0);
                CHECK(u16 == 0x00FF);
            }
            TEST_CASE("u32_t")
            {
                u32_t u32 = 0x0000FFFF;
                CHECK(nkr::os::atomic::Access_And(u32, 0xFFFF0000) == 0x0);
                CHECK(u32 == 0x0000FFFF);
            }
            TEST_CASE("u64_t")
            {
            #if defined(nkr_IS_64_BIT)
                u64_t u64 = 0x00000000FFFFFFFF;
                CHECK(nkr::os::atomic::Access_And(u64, 0xFFFFFFFF00000000) == 0x0);
                CHECK(u64 == 0x00000000FFFFFFFF);
            #endif
            }
            TEST_CASE("s8_t")
            {
                s8_t s8 = 0x0F;
                CHECK(nkr::os::atomic::Access_And(s8, 0x70) == 0x0);
                CHECK(s8 == 0x0F);
            }
            TEST_CASE("s16_t")
            {
                s16_t s16 = 0x00FF;
                CHECK(nkr::os::atomic::Access_And(s16, 0x7F00) == 0x0);
                CHECK(s16 == 0x00FF);
            }
            TEST_CASE("s32_t")
            {
                s32_t s32 = 0x0000FFFF;
                CHECK(nkr::os::atomic::Access_And(s32, 0x7FFF0000) == 0x0);
                CHECK(s32 == 0x0000FFFF);
            }
            TEST_CASE("s64_t")
            {
            #if defined(nkr_IS_64_BIT)
                s64_t s64 = 0x00000000FFFFFFFF;
                CHECK(nkr::os::atomic::Access_And(s64, 0x7FFFFFFF00000000) == 0x0);
                CHECK(s64 == 0x00000000FFFFFFFF);
            #endif
            }
        }
    }

    TEST_SUITE("Access_Xor")
    {
        TEST_SUITE("should return xor'd values without changing the original")
        {
            TEST_CASE("u8_t")
            {
                u8_t u8 = 0xFF;
                CHECK(nkr::os::atomic::Access_Xor(u8, 0x01) == 0xFE);
                CHECK(u8 == 0xFF);
            }
            TEST_CASE("u16_t")
            {
                u16_t u16 = 0xFFFF;
                CHECK(nkr::os::atomic::Access_Xor(u16, 0x0001) == 0xFFFE);
                CHECK(u16 == 0xFFFF);
            }
            TEST_CASE("u32_t")
            {
                u32_t u32 = 0xFFFFFFFF;
                CHECK(nkr::os::atomic::Access_Xor(u32, 0x00000001) == 0xFFFFFFFE);
                CHECK(u32 == 0xFFFFFFFF);
            }
            TEST_CASE("u64_t")
            {
            #if defined(nkr_IS_64_BIT)
                u64_t u64 = 0xFFFFFFFFFFFFFFFF;
                CHECK(nkr::os::atomic::Access_Xor(u64, 0x0000000000000001) == 0xFFFFFFFFFFFFFFFE);
                CHECK(u64 == 0xFFFFFFFFFFFFFFFF);
            #endif
            }
            TEST_CASE("s8_t")
            {
                s8_t s8 = 0x7F;
                CHECK(nkr::os::atomic::Access_Xor(s8, 0x01) == 0x7E);
                CHECK(s8 == 0x7F);
            }
            TEST_CASE("s16_t")
            {
                s16_t s16 = 0x7FFF;
                CHECK(nkr::os::atomic::Access_Xor(s16, 0x0001) == 0x7FFE);
                CHECK(s16 == 0x7FFF);
            }
            TEST_CASE("s32_t")
            {
                s32_t s32 = 0x7FFFFFFF;
                CHECK(nkr::os::atomic::Access_Xor(s32, 0x00000001) == 0x7FFFFFFE);
                CHECK(s32 == 0x7FFFFFFF);
            }
            TEST_CASE("s64_t")
            {
            #if defined(nkr_IS_64_BIT)
                s64_t s64 = 0x7FFFFFFFFFFFFFFF;
                CHECK(nkr::os::atomic::Access_Xor(s64, 0x0000000000000001) == 0x7FFFFFFFFFFFFFFE);
                CHECK(s64 == 0x7FFFFFFFFFFFFFFF);
            #endif
            }
        }
    }

    TEST_SUITE("Assign")
    {
        TEST_SUITE("should atomically assign integers and pointers and return the new value")
        {
            TEST_CASE("bool_t")
            {
                bool_t boolean = false;
                CHECK(nkr::os::atomic::Assign(boolean, true) == true);
                CHECK(boolean == true);
            }
            TEST_CASE("u8_t")
            {
                u8_t u8 = 8;
                CHECK(nkr::os::atomic::Assign(u8, 1) == 1);
                CHECK(u8 == 1);
            }
            TEST_CASE("u16_t")
            {
                u16_t u16 = 16;
                CHECK(nkr::os::atomic::Assign(u16, 1) == 1);
                CHECK(u16 == 1);
            }
            TEST_CASE("u32_t")
            {
                u32_t u32 = 32;
                CHECK(nkr::os::atomic::Assign(u32, 1) == 1);
                CHECK(u32 == 1);
            }
            TEST_CASE("u64_t")
            {
            #if defined(nkr_IS_64_BIT)
                u64_t u64 = 64;
                CHECK(nkr::os::atomic::Assign(u64, 1) == 1);
                CHECK(u64 == 1);
            #endif
            }
            TEST_CASE("s8_t")
            {
                s8_t s8 = -8;
                CHECK(nkr::os::atomic::Assign(s8, -1) == -1);
                CHECK(s8 == -1);
            }
            TEST_CASE("s16_t")
            {
                s16_t s16 = -16;
                CHECK(nkr::os::atomic::Assign(s16, -1) == -1);
                CHECK(s16 == -1);
            }
            TEST_CASE("s32_t")
            {
                s32_t s32 = -32;
                CHECK(nkr::os::atomic::Assign(s32, -1) == -1);
                CHECK(s32 == -1);
            }
            TEST_CASE("s64_t")
            {
            #if defined(nkr_IS_64_BIT)
                s64_t s64 = -64;
                CHECK(nkr::os::atomic::Assign(s64, -1) == -1);
                CHECK(s64 == -1);
            #endif
            }
            TEST_CASE("void_t*")
            {
                bool_t boolean = false;
                void_t* void_pointer = nullptr;
                CHECK(nkr::os::atomic::Assign(void_pointer, &boolean) == &boolean);
                CHECK(void_pointer == &boolean);
            }
            TEST_CASE("bool_t*")
            {
                bool_t boolean = false;
                bool_t* boolean_pointer = &boolean;
                CHECK(nkr::os::atomic::Assign(boolean_pointer, nullptr) == nullptr);
                CHECK(boolean_pointer == nullptr);
            }
        }
    }

    TEST_SUITE("Assign_Add")
    {
        TEST_SUITE("should atomically add to integers and pointers and return the new value")
        {
            TEST_CASE("u8_t")
            {
                u8_t u8 = 8;
                CHECK(nkr::os::atomic::Assign_Add(u8, 1) == 9);
                CHECK(u8 == 9);
            }
            TEST_CASE("u16_t")
            {
                u16_t u16 = 16;
                CHECK(nkr::os::atomic::Assign_Add(u16, 1) == 17);
                CHECK(u16 == 17);
            }
            TEST_CASE("u32_t")
            {
                u32_t u32 = 32;
                CHECK(nkr::os::atomic::Assign_Add(u32, 1) == 33);
                CHECK(u32 == 33);
            }
            TEST_CASE("u64_t")
            {
            #if defined(nkr_IS_64_BIT)
                u64_t u64 = 64;
                CHECK(nkr::os::atomic::Assign_Add(u64, 1) == 65);
                CHECK(u64 == 65);
            #endif
            }
            TEST_CASE("s8_t")
            {
                s8_t s8 = -8;
                CHECK(nkr::os::atomic::Assign_Add(s8, -1) == -9);
                CHECK(s8 == -9);
            }
            TEST_CASE("s16_t")
            {
                s16_t s16 = -16;
                CHECK(nkr::os::atomic::Assign_Add(s16, -1) == -17);
                CHECK(s16 == -17);
            }
            TEST_CASE("s32_t")
            {
                s32_t s32 = -32;
                CHECK(nkr::os::atomic::Assign_Add(s32, -1) == -33);
                CHECK(s32 == -33);
            }
            TEST_CASE("s64_t")
            {
            #if defined(nkr_IS_64_BIT)
                s64_t s64 = -64;
                CHECK(nkr::os::atomic::Assign_Add(s64, -1) == -65);
                CHECK(s64 == -65);
            #endif
            }
            TEST_CASE("bool_t*")
            {
                bool_t booleans[2] = { true, true };
                bool_t* boolean_pointer = booleans;
                CHECK(nkr::os::atomic::Assign_Add(boolean_pointer, 1) == booleans + 1);
                CHECK(nkr::os::atomic::Assign_Add(boolean_pointer, -1) == booleans + 0);
            }
        }
        TEST_CASE("should be able to increment a variable atomically without data loss"
                  * doctest::no_breaks(true))
        {
            const u8_t thread_count = 64;
            std::vector<std::thread> threads;
            threads.reserve(thread_count);

            word_t atomic_counter = 0;
            for (index_t idx = 0, end = thread_count; idx < end; idx += 1) {
                threads.push_back(std::thread(
                    [&atomic_counter]() -> void_t
                    {
                        word_t micro_seconds = 0;
                        {
                            std::lock_guard<std::mutex> locker(random_lock);
                            micro_seconds = std::uniform_int_distribution<word_t>(1, 5)(random_generator);
                        }
                        std::this_thread::sleep_for(std::chrono::microseconds(micro_seconds));
                        nkr::os::atomic::Assign_Add(atomic_counter, 7);
                    }
                ));
            }
            for (index_t idx = 0, end = thread_count; idx < end; idx += 1) {
                threads[idx].join();
            }

            CHECK(atomic_counter == thread_count * 7);
        }
    }

    TEST_SUITE("Assign_Subtract")
    {
        TEST_SUITE("should atomically subtract from integers and pointers and return the new value")
        {
            TEST_CASE("u8_t")
            {
                u8_t u8 = 8;
                CHECK(nkr::os::atomic::Assign_Subtract(u8, 1) == 7);
                CHECK(u8 == 7);
            }
            TEST_CASE("u16_t")
            {
                u16_t u16 = 16;
                CHECK(nkr::os::atomic::Assign_Subtract(u16, 1) == 15);
                CHECK(u16 == 15);
            }
            TEST_CASE("u32_t")
            {
                u32_t u32 = 32;
                CHECK(nkr::os::atomic::Assign_Subtract(u32, 1) == 31);
                CHECK(u32 == 31);
            }
            TEST_CASE("u64_t")
            {
            #if defined(nkr_IS_64_BIT)
                u64_t u64 = 64;
                CHECK(nkr::os::atomic::Assign_Subtract(u64, 1) == 63);
                CHECK(u64 == 63);
            #endif
            }
            TEST_CASE("s8_t")
            {
                s8_t s8 = -8;
                CHECK(nkr::os::atomic::Assign_Subtract(s8, -1) == -7);
                CHECK(s8 == -7);
            }
            TEST_CASE("s16_t")
            {
                s16_t s16 = -16;
                CHECK(nkr::os::atomic::Assign_Subtract(s16, -1) == -15);
                CHECK(s16 == -15);
            }
            TEST_CASE("s32_t")
            {
                s32_t s32 = -32;
                CHECK(nkr::os::atomic::Assign_Subtract(s32, -1) == -31);
                CHECK(s32 == -31);
            }
            TEST_CASE("s64_t")
            {
            #if defined(nkr_IS_64_BIT)
                s64_t s64 = -64;
                CHECK(nkr::os::atomic::Assign_Subtract(s64, -1) == -63);
                CHECK(s64 == -63);
            #endif
            }
            TEST_CASE("bool_t*")
            {
                bool_t booleans[2] = { true, true };
                bool_t* boolean_pointer = booleans + 1;
                CHECK(nkr::os::atomic::Assign_Subtract(boolean_pointer, 1) == booleans + 0);
                CHECK(nkr::os::atomic::Assign_Subtract(boolean_pointer, -1) == booleans + 1);
            }
        }
        TEST_CASE("should be able to decrement a variable atomically without data loss"
                  * doctest::no_breaks(true))
        {
            const u8_t thread_count = 64;
            std::vector<std::thread> threads;
            threads.reserve(thread_count);

            word_t atomic_counter = thread_count * 7;
            for (index_t idx = 0, end = thread_count; idx < end; idx += 1) {
                threads.push_back(std::thread(
                    [&atomic_counter]() -> void_t
                    {
                        word_t micro_seconds = 0;
                        {
                            std::lock_guard<std::mutex> locker(random_lock);
                            micro_seconds = std::uniform_int_distribution<word_t>(1, 5)(random_generator);
                        }
                        std::this_thread::sleep_for(std::chrono::microseconds(micro_seconds));
                        nkr::os::atomic::Assign_Subtract(atomic_counter, 7);
                    }
                ));
            }
            for (index_t idx = 0, end = thread_count; idx < end; idx += 1) {
                threads[idx].join();
            }

            CHECK(atomic_counter == 0);
        }
    }

    TEST_SUITE("Assign_Or")
    {
        TEST_SUITE("should atomically OR integers and return the new value")
        {
            TEST_CASE("u8_t")
            {
                u8_t u8 = 0x0F;
                CHECK(nkr::os::atomic::Assign_Or(u8, 0xF0) == 0xFF);
                CHECK(u8 == 0xFF);
            }
            TEST_CASE("u16_t")
            {
                u16_t u16 = 0x00FF;
                CHECK(nkr::os::atomic::Assign_Or(u16, 0xFF00) == 0xFFFF);
                CHECK(u16 == 0xFFFF);
            }
            TEST_CASE("u32_t")
            {
                u32_t u32 = 0x0000FFFF;
                CHECK(nkr::os::atomic::Assign_Or(u32, 0xFFFF0000) == 0xFFFFFFFF);
                CHECK(u32 == 0xFFFFFFFF);
            }
            TEST_CASE("u64_t")
            {
            #if defined(nkr_IS_64_BIT)
                u64_t u64 = 0x00000000FFFFFFFF;
                CHECK(nkr::os::atomic::Assign_Or(u64, 0xFFFFFFFF00000000) == 0xFFFFFFFFFFFFFFFF);
                CHECK(u64 == 0xFFFFFFFFFFFFFFFF);
            #endif
            }
            TEST_CASE("s8_t")
            {
                s8_t s8 = 0x0F;
                CHECK(nkr::os::atomic::Assign_Or(s8, 0x70) == 0x7F);
                CHECK(s8 == 0x7F);
            }
            TEST_CASE("s16_t")
            {
                s16_t s16 = 0x00FF;
                CHECK(nkr::os::atomic::Assign_Or(s16, 0x7F00) == 0x7FFF);
                CHECK(s16 == 0x7FFF);
            }
            TEST_CASE("s32_t")
            {
                s32_t s32 = 0x0000FFFF;
                CHECK(nkr::os::atomic::Assign_Or(s32, 0x7FFF0000) == 0x7FFFFFFF);
                CHECK(s32 == 0x7FFFFFFF);
            }
            TEST_CASE("s64_t")
            {
            #if defined(nkr_IS_64_BIT)
                s64_t s64 = 0x00000000FFFFFFFF;
                CHECK(nkr::os::atomic::Assign_Or(s64, 0x7FFFFFFF00000000) == 0x7FFFFFFFFFFFFFFF);
                CHECK(s64 == 0x7FFFFFFFFFFFFFFF);
            #endif
            }
        }
    }

    TEST_SUITE("Assign_And")
    {
        TEST_SUITE("should atomically AND integers and return the new value")
        {
            TEST_CASE("u8_t")
            {
                u8_t u8 = 0x0F;
                CHECK(nkr::os::atomic::Assign_And(u8, 0xF0) == 0x0);
                CHECK(u8 == 0x0);
            }
            TEST_CASE("u16_t")
            {
                u16_t u16 = 0x00FF;
                CHECK(nkr::os::atomic::Assign_And(u16, 0xFF00) == 0x0);
                CHECK(u16 == 0x0);
            }
            TEST_CASE("u32_t")
            {
                u32_t u32 = 0x0000FFFF;
                CHECK(nkr::os::atomic::Assign_And(u32, 0xFFFF0000) == 0x0);
                CHECK(u32 == 0x0);
            }
            TEST_CASE("u64_t")
            {
            #if defined(nkr_IS_64_BIT)
                u64_t u64 = 0x00000000FFFFFFFF;
                CHECK(nkr::os::atomic::Assign_And(u64, 0xFFFFFFFF00000000) == 0x0);
                CHECK(u64 == 0x0);
            #endif
            }
            TEST_CASE("s8_t")
            {
                s8_t s8 = 0x0F;
                CHECK(nkr::os::atomic::Assign_And(s8, 0x70) == 0x0);
                CHECK(s8 == 0x0);
            }
            TEST_CASE("s16_t")
            {
                s16_t s16 = 0x00FF;
                CHECK(nkr::os::atomic::Assign_And(s16, 0x7F00) == 0x0);
                CHECK(s16 == 0x0);
            }
            TEST_CASE("s32_t")
            {
                s32_t s32 = 0x0000FFFF;
                CHECK(nkr::os::atomic::Assign_And(s32, 0x7FFF0000) == 0x0);
                CHECK(s32 == 0x0);
            }
            TEST_CASE("s64_t")
            {
            #if defined(nkr_IS_64_BIT)
                s64_t s64 = 0x00000000FFFFFFFF;
                CHECK(nkr::os::atomic::Assign_And(s64, 0x7FFFFFFF00000000) == 0x0);
                CHECK(s64 == 0x0);
            #endif
            }
        }
    }

    TEST_SUITE("Assign_Xor")
    {
        TEST_SUITE("should atomically XOR integers and return the new value")
        {
            TEST_CASE("u8_t")
            {
                u8_t u8 = 0xFF;
                CHECK(nkr::os::atomic::Assign_Xor(u8, 0x01) == 0xFE);
                CHECK(u8 == 0xFE);
            }
            TEST_CASE("u16_t")
            {
                u16_t u16 = 0xFFFF;
                CHECK(nkr::os::atomic::Assign_Xor(u16, 0x0001) == 0xFFFE);
                CHECK(u16 == 0xFFFE);
            }
            TEST_CASE("u32_t")
            {
                u32_t u32 = 0xFFFFFFFF;
                CHECK(nkr::os::atomic::Assign_Xor(u32, 0x00000001) == 0xFFFFFFFE);
                CHECK(u32 == 0xFFFFFFFE);
            }
            TEST_CASE("u64_t")
            {
            #if defined(nkr_IS_64_BIT)
                u64_t u64 = 0xFFFFFFFFFFFFFFFF;
                CHECK(nkr::os::atomic::Assign_Xor(u64, 0x0000000000000001) == 0xFFFFFFFFFFFFFFFE);
                CHECK(u64 == 0xFFFFFFFFFFFFFFFE);
            #endif
            }
            TEST_CASE("s8_t")
            {
                s8_t s8 = 0x7F;
                CHECK(nkr::os::atomic::Assign_Xor(s8, 0x01) == 0x7E);
                CHECK(s8 == 0x7E);
            }
            TEST_CASE("s16_t")
            {
                s16_t s16 = 0x7FFF;
                CHECK(nkr::os::atomic::Assign_Xor(s16, 0x0001) == 0x7FFE);
                CHECK(s16 == 0x7FFE);
            }
            TEST_CASE("s32_t")
            {
                s32_t s32 = 0x7FFFFFFF;
                CHECK(nkr::os::atomic::Assign_Xor(s32, 0x00000001) == 0x7FFFFFFE);
                CHECK(s32 == 0x7FFFFFFE);
            }
            TEST_CASE("s64_t")
            {
            #if defined(nkr_IS_64_BIT)
                s64_t s64 = 0x7FFFFFFFFFFFFFFF;
                CHECK(nkr::os::atomic::Assign_Xor(s64, 0x0000000000000001) == 0x7FFFFFFFFFFFFFFE);
                CHECK(s64 == 0x7FFFFFFFFFFFFFFE);
            #endif
            }
        }
    }

    TEST_SUITE("Exchange")
    {
        TEST_SUITE("should atomically assign integers and pointers and return the initial value")
        {
            TEST_CASE("bool_t")
            {
                bool_t boolean = false;
                CHECK(nkr::os::atomic::Exchange(boolean, true) == false);
                CHECK(nkr::os::atomic::Access(boolean) == true);
            }
            TEST_CASE("u8_t")
            {
                u8_t u8 = 8;
                CHECK(nkr::os::atomic::Exchange(u8, 1) == 8);
                CHECK(nkr::os::atomic::Access(u8) == 1);
            }
            TEST_CASE("u16_t")
            {
                u16_t u16 = 16;
                CHECK(nkr::os::atomic::Exchange(u16, 1) == 16);
                CHECK(nkr::os::atomic::Access(u16) == 1);
            }
            TEST_CASE("u32_t")
            {
                u32_t u32 = 32;
                CHECK(nkr::os::atomic::Exchange(u32, 1) == 32);
                CHECK(nkr::os::atomic::Access(u32) == 1);
            }
            TEST_CASE("u64_t")
            {
            #if defined(nkr_IS_64_BIT)
                u64_t u64 = 64;
                CHECK(nkr::os::atomic::Exchange(u64, 1) == 64);
                CHECK(nkr::os::atomic::Access(u64) == 1);
            #endif
            }
            TEST_CASE("s8_t")
            {
                s8_t s8 = -8;
                CHECK(nkr::os::atomic::Exchange(s8, -1) == -8);
                CHECK(nkr::os::atomic::Access(s8) == -1);
            }
            TEST_CASE("s16_t")
            {
                s16_t s16 = -16;
                CHECK(nkr::os::atomic::Exchange(s16, -1) == -16);
                CHECK(nkr::os::atomic::Access(s16) == -1);
            }
            TEST_CASE("s32_t")
            {
                s32_t s32 = -32;
                CHECK(nkr::os::atomic::Exchange(s32, -1) == -32);
                CHECK(nkr::os::atomic::Access(s32) == -1);
            }
            TEST_CASE("s64_t")
            {
            #if defined(nkr_IS_64_BIT)
                s64_t s64 = -64;
                CHECK(nkr::os::atomic::Exchange(s64, -1) == -64);
                CHECK(nkr::os::atomic::Access(s64) == -1);
            #endif
            }
            TEST_CASE("void_t*")
            {
                bool_t boolean = false;
                void_t* void_pointer = nullptr;
                CHECK(nkr::os::atomic::Exchange(void_pointer, &boolean) == nullptr);
                CHECK(nkr::os::atomic::Access(void_pointer) == &boolean);
            }
            TEST_CASE("bool_t*")
            {
                bool_t boolean = false;
                bool_t* boolean_pointer = &boolean;
                CHECK(nkr::os::atomic::Exchange(boolean_pointer, nullptr) == &boolean);
                CHECK(nkr::os::atomic::Access(boolean_pointer) == nullptr);
            }
        }
    }

    TEST_SUITE("Exchange_If_Equals")
    {
        TEST_SUITE("should atomically assign integers and pointers if they equal target and return the initial value")
        {
            TEST_CASE("bool_t")
            {
                bool_t boolean = false;
                CHECK(nkr::os::atomic::Exchange_If_Equals(boolean, true, true) == false);
                CHECK(nkr::os::atomic::Access(boolean) == false);
                CHECK(nkr::os::atomic::Exchange_If_Equals(boolean, true, false) == false);
                CHECK(nkr::os::atomic::Access(boolean) == true);
            }
            TEST_CASE("u8_t")
            {
                u8_t u8 = 8;
                CHECK(nkr::os::atomic::Exchange_If_Equals(u8, 1, 1) == 8);
                CHECK(nkr::os::atomic::Access(u8) == 8);
                CHECK(nkr::os::atomic::Exchange_If_Equals(u8, 1, 8) == 8);
                CHECK(nkr::os::atomic::Access(u8) == 1);
            }
            TEST_CASE("u16_t")
            {
                u16_t u16 = 16;
                CHECK(nkr::os::atomic::Exchange_If_Equals(u16, 1, 1) == 16);
                CHECK(nkr::os::atomic::Access(u16) == 16);
                CHECK(nkr::os::atomic::Exchange_If_Equals(u16, 1, 16) == 16);
                CHECK(nkr::os::atomic::Access(u16) == 1);
            }
            TEST_CASE("u32_t")
            {
                u32_t u32 = 32;
                CHECK(nkr::os::atomic::Exchange_If_Equals(u32, 1, 1) == 32);
                CHECK(nkr::os::atomic::Access(u32) == 32);
                CHECK(nkr::os::atomic::Exchange_If_Equals(u32, 1, 32) == 32);
                CHECK(nkr::os::atomic::Access(u32) == 1);
            }
            TEST_CASE("u64_t")
            {
            #if defined(nkr_IS_64_BIT)
                u64_t u64 = 64;
                CHECK(nkr::os::atomic::Exchange_If_Equals(u64, 1, 1) == 64);
                CHECK(nkr::os::atomic::Access(u64) == 64);
                CHECK(nkr::os::atomic::Exchange_If_Equals(u64, 1, 64) == 64);
                CHECK(nkr::os::atomic::Access(u64) == 1);
            #endif
            }
            TEST_CASE("s8_t")
            {
                s8_t s8 = -8;
                CHECK(nkr::os::atomic::Exchange_If_Equals(s8, -1, -1) == -8);
                CHECK(nkr::os::atomic::Access(s8) == -8);
                CHECK(nkr::os::atomic::Exchange_If_Equals(s8, -1, -8) == -8);
                CHECK(nkr::os::atomic::Access(s8) == -1);
            }
            TEST_CASE("s16_t")
            {
                s16_t s16 = -16;
                CHECK(nkr::os::atomic::Exchange_If_Equals(s16, -1, -1) == -16);
                CHECK(nkr::os::atomic::Access(s16) == -16);
                CHECK(nkr::os::atomic::Exchange_If_Equals(s16, -1, -16) == -16);
                CHECK(nkr::os::atomic::Access(s16) == -1);
            }
            TEST_CASE("s32_t")
            {
                s32_t s32 = -32;
                CHECK(nkr::os::atomic::Exchange_If_Equals(s32, -1, -1) == -32);
                CHECK(nkr::os::atomic::Access(s32) == -32);
                CHECK(nkr::os::atomic::Exchange_If_Equals(s32, -1, -32) == -32);
                CHECK(nkr::os::atomic::Access(s32) == -1);
            }
            TEST_CASE("s64_t")
            {
            #if defined(nkr_IS_64_BIT)
                s64_t s64 = -64;
                CHECK(nkr::os::atomic::Exchange_If_Equals(s64, -1, -1) == -64);
                CHECK(nkr::os::atomic::Access(s64) == -64);
                CHECK(nkr::os::atomic::Exchange_If_Equals(s64, -1, -64) == -64);
                CHECK(nkr::os::atomic::Access(s64) == -1);
            #endif
            }
            TEST_CASE("void_t*")
            {
                bool_t boolean = false;
                void_t* void_pointer = nullptr;
                CHECK(nkr::os::atomic::Exchange_If_Equals(void_pointer, &boolean, &boolean) == nullptr);
                CHECK(nkr::os::atomic::Access(void_pointer) == nullptr);
                CHECK(nkr::os::atomic::Exchange_If_Equals(void_pointer, &boolean, nullptr) == nullptr);
                CHECK(nkr::os::atomic::Access(void_pointer) == &boolean);
            }
            TEST_CASE("bool_t*")
            {
                bool_t boolean = false;
                bool_t* boolean_pointer = &boolean;
                CHECK(nkr::os::atomic::Exchange_If_Equals(boolean_pointer, nullptr, nullptr) == &boolean);
                CHECK(nkr::os::atomic::Access(boolean_pointer) == &boolean);
                CHECK(nkr::os::atomic::Exchange_If_Equals(boolean_pointer, nullptr, &boolean) == &boolean);
                CHECK(nkr::os::atomic::Access(boolean_pointer) == nullptr);
            }
        }
    }

    TEST_SUITE("Exchange_Add")
    {
        TEST_SUITE("should atomically add to integers and pointers and return the initial value")
        {
            TEST_CASE("u8_t")
            {
                u8_t u8 = 8;
                CHECK(nkr::os::atomic::Exchange_Add(u8, 1) == 8);
                CHECK(nkr::os::atomic::Access(u8) == 9);
            }
            TEST_CASE("u16_t")
            {
                u16_t u16 = 16;
                CHECK(nkr::os::atomic::Exchange_Add(u16, 1) == 16);
                CHECK(nkr::os::atomic::Access(u16) == 17);
            }
            TEST_CASE("u32_t")
            {
                u32_t u32 = 32;
                CHECK(nkr::os::atomic::Exchange_Add(u32, 1) == 32);
                CHECK(nkr::os::atomic::Access(u32) == 33);
            }
            TEST_CASE("u64_t")
            {
            #if defined(nkr_IS_64_BIT)
                u64_t u64 = 64;
                CHECK(nkr::os::atomic::Exchange_Add(u64, 1) == 64);
                CHECK(nkr::os::atomic::Access(u64) == 65);
            #endif
            }
            TEST_CASE("s8_t")
            {
                s8_t s8 = -8;
                CHECK(nkr::os::atomic::Exchange_Add(s8, -1) == -8);
                CHECK(nkr::os::atomic::Access(s8) == -9);
            }
            TEST_CASE("s16_t")
            {
                s16_t s16 = -16;
                CHECK(nkr::os::atomic::Exchange_Add(s16, -1) == -16);
                CHECK(nkr::os::atomic::Access(s16) == -17);
            }
            TEST_CASE("s32_t")
            {
                s32_t s32 = -32;
                CHECK(nkr::os::atomic::Exchange_Add(s32, -1) == -32);
                CHECK(nkr::os::atomic::Access(s32) == -33);
            }
            TEST_CASE("s64_t")
            {
            #if defined(nkr_IS_64_BIT)
                s64_t s64 = -64;
                CHECK(nkr::os::atomic::Exchange_Add(s64, -1) == -64);
                CHECK(nkr::os::atomic::Access(s64) == -65);
            #endif
            }
            TEST_CASE("bool_t*")
            {
                bool_t booleans[2] = { true, true };
                bool_t* boolean_pointer = booleans;
                CHECK(nkr::os::atomic::Exchange_Add(boolean_pointer, 1) == booleans + 0);
                CHECK(nkr::os::atomic::Access(boolean_pointer) == booleans + 1);
                CHECK(nkr::os::atomic::Exchange_Add(boolean_pointer, -1) == booleans + 1);
                CHECK(nkr::os::atomic::Access(boolean_pointer) == booleans + 0);
            }
        }
    }

    TEST_SUITE("Exchange_Subtract")
    {
        TEST_SUITE("should atomically subtract from integers and pointers and return the initial value")
        {
            TEST_CASE("u8_t")
            {
                u8_t u8 = 8;
                CHECK(nkr::os::atomic::Exchange_Subtract(u8, 1) == 8);
                CHECK(nkr::os::atomic::Access(u8) == 7);
            }
            TEST_CASE("u16_t")
            {
                u16_t u16 = 16;
                CHECK(nkr::os::atomic::Exchange_Subtract(u16, 1) == 16);
                CHECK(nkr::os::atomic::Access(u16) == 15);
            }
            TEST_CASE("u32_t")
            {
                u32_t u32 = 32;
                CHECK(nkr::os::atomic::Exchange_Subtract(u32, 1) == 32);
                CHECK(nkr::os::atomic::Access(u32) == 31);
            }
            TEST_CASE("u64_t")
            {
            #if defined(nkr_IS_64_BIT)
                u64_t u64 = 64;
                CHECK(nkr::os::atomic::Exchange_Subtract(u64, 1) == 64);
                CHECK(nkr::os::atomic::Access(u64) == 63);
            #endif
            }
            TEST_CASE("s8_t")
            {
                s8_t s8 = -8;
                CHECK(nkr::os::atomic::Exchange_Subtract(s8, -1) == -8);
                CHECK(nkr::os::atomic::Access(s8) == -7);
            }
            TEST_CASE("s16_t")
            {
                s16_t s16 = -16;
                CHECK(nkr::os::atomic::Exchange_Subtract(s16, -1) == -16);
                CHECK(nkr::os::atomic::Access(s16) == -15);
            }
            TEST_CASE("s32_t")
            {
                s32_t s32 = -32;
                CHECK(nkr::os::atomic::Exchange_Subtract(s32, -1) == -32);
                CHECK(nkr::os::atomic::Access(s32) == -31);
            }
            TEST_CASE("s64_t")
            {
            #if defined(nkr_IS_64_BIT)
                s64_t s64 = -64;
                CHECK(nkr::os::atomic::Exchange_Subtract(s64, -1) == -64);
                CHECK(nkr::os::atomic::Access(s64) == -63);
            #endif
            }
            TEST_CASE("bool_t*")
            {
                bool_t booleans[2] = { true, true };
                bool_t* boolean_pointer = booleans + 1;
                CHECK(nkr::os::atomic::Exchange_Subtract(boolean_pointer, 1) == booleans + 1);
                CHECK(nkr::os::atomic::Access(boolean_pointer) == booleans + 0);
                CHECK(nkr::os::atomic::Exchange_Subtract(boolean_pointer, -1) == booleans + 0);
                CHECK(nkr::os::atomic::Access(boolean_pointer) == booleans + 1);
            }
        }
    }

    TEST_SUITE("Exchange_Or")
    {
        TEST_SUITE("should atomically OR integers and return the initial value")
        {
            TEST_CASE("u8_t")
            {
                u8_t u8 = 0x0F;
                CHECK(nkr::os::atomic::Exchange_Or(u8, 0xF0) == 0x0F);
                CHECK(nkr::os::atomic::Access(u8) == 0xFF);
            }
            TEST_CASE("u16_t")
            {
                u16_t u16 = 0x00FF;
                CHECK(nkr::os::atomic::Exchange_Or(u16, 0xFF00) == 0x00FF);
                CHECK(nkr::os::atomic::Access(u16) == 0xFFFF);
            }
            TEST_CASE("u32_t")
            {
                u32_t u32 = 0x0000FFFF;
                CHECK(nkr::os::atomic::Exchange_Or(u32, 0xFFFF0000) == 0x0000FFFF);
                CHECK(nkr::os::atomic::Access(u32) == 0xFFFFFFFF);
            }
            TEST_CASE("u64_t")
            {
            #if defined(nkr_IS_64_BIT)
                u64_t u64 = 0x00000000FFFFFFFF;
                CHECK(nkr::os::atomic::Exchange_Or(u64, 0xFFFFFFFF00000000) == 0x00000000FFFFFFFF);
                CHECK(nkr::os::atomic::Access(u64) == 0xFFFFFFFFFFFFFFFF);
            #endif
            }
            TEST_CASE("s8_t")
            {
                s8_t s8 = 0x0F;
                CHECK(nkr::os::atomic::Exchange_Or(s8, 0x70) == 0x0F);
                CHECK(nkr::os::atomic::Access(s8) == 0x7F);
            }
            TEST_CASE("s16_t")
            {
                s16_t s16 = 0x00FF;
                CHECK(nkr::os::atomic::Exchange_Or(s16, 0x7F00) == 0x00FF);
                CHECK(nkr::os::atomic::Access(s16) == 0x7FFF);
            }
            TEST_CASE("s32_t")
            {
                s32_t s32 = 0x0000FFFF;
                CHECK(nkr::os::atomic::Exchange_Or(s32, 0x7FFF0000) == 0x0000FFFF);
                CHECK(nkr::os::atomic::Access(s32) == 0x7FFFFFFF);
            }
            TEST_CASE("s64_t")
            {
            #if defined(nkr_IS_64_BIT)
                s64_t s64 = 0x00000000FFFFFFFF;
                CHECK(nkr::os::atomic::Exchange_Or(s64, 0x7FFFFFFF00000000) == 0x00000000FFFFFFFF);
                CHECK(nkr::os::atomic::Access(s64) == 0x7FFFFFFFFFFFFFFF);
            #endif
            }
        }
    }

    TEST_SUITE("Exchange_And")
    {
        TEST_SUITE("should atomically AND integers and return the initial value")
        {
            TEST_CASE("u8_t")
            {
                u8_t u8 = 0x0F;
                CHECK(nkr::os::atomic::Exchange_And(u8, 0xF0) == 0x0F);
                CHECK(nkr::os::atomic::Access(u8) == 0x0);
            }
            TEST_CASE("u16_t")
            {
                u16_t u16 = 0x00FF;
                CHECK(nkr::os::atomic::Exchange_And(u16, 0xFF00) == 0x00FF);
                CHECK(nkr::os::atomic::Access(u16) == 0x0);
            }
            TEST_CASE("u32_t")
            {
                u32_t u32 = 0x0000FFFF;
                CHECK(nkr::os::atomic::Exchange_And(u32, 0xFFFF0000) == 0x0000FFFF);
                CHECK(nkr::os::atomic::Access(u32) == 0x0);
            }
            TEST_CASE("u64_t")
            {
            #if defined(nkr_IS_64_BIT)
                u64_t u64 = 0x00000000FFFFFFFF;
                CHECK(nkr::os::atomic::Exchange_And(u64, 0xFFFFFFFF00000000) == 0x00000000FFFFFFFF);
                CHECK(nkr::os::atomic::Access(u64) == 0x0);
            #endif
            }
            TEST_CASE("s8_t")
            {
                s8_t s8 = 0x0F;
                CHECK(nkr::os::atomic::Exchange_And(s8, 0x70) == 0x0F);
                CHECK(nkr::os::atomic::Access(s8) == 0x0);
            }
            TEST_CASE("s16_t")
            {
                s16_t s16 = 0x00FF;
                CHECK(nkr::os::atomic::Exchange_And(s16, 0x7F00) == 0x00FF);
                CHECK(nkr::os::atomic::Access(s16) == 0x0);
            }
            TEST_CASE("s32_t")
            {
                s32_t s32 = 0x0000FFFF;
                CHECK(nkr::os::atomic::Exchange_And(s32, 0x7FFF0000) == 0x0000FFFF);
                CHECK(nkr::os::atomic::Access(s32) == 0x0);
            }
            TEST_CASE("s64_t")
            {
            #if defined(nkr_IS_64_BIT)
                s64_t s64 = 0x00000000FFFFFFFF;
                CHECK(nkr::os::atomic::Exchange_And(s64, 0x7FFFFFFF00000000) == 0x00000000FFFFFFFF);
                CHECK(nkr::os::atomic::Access(s64) == 0x0);
            #endif
            }
        }
    }

    TEST_SUITE("Exchange_Xor")
    {
        TEST_SUITE("should atomically XOR integers and return the initial value")
        {
            TEST_CASE("u8_t")
            {
                u8_t u8 = 0xFF;
                CHECK(nkr::os::atomic::Exchange_Xor(u8, 0x01) == 0xFF);
                CHECK(nkr::os::atomic::Access(u8) == 0xFE);
            }
            TEST_CASE("u16_t")
            {
                u16_t u16 = 0xFFFF;
                CHECK(nkr::os::atomic::Exchange_Xor(u16, 0x0001) == 0xFFFF);
                CHECK(nkr::os::atomic::Access(u16) == 0xFFFE);
            }
            TEST_CASE("u32_t")
            {
                u32_t u32 = 0xFFFFFFFF;
                CHECK(nkr::os::atomic::Exchange_Xor(u32, 0x00000001) == 0xFFFFFFFF);
                CHECK(nkr::os::atomic::Access(u32) == 0xFFFFFFFE);
            }
            TEST_CASE("u64_t")
            {
            #if defined(nkr_IS_64_BIT)
                u64_t u64 = 0xFFFFFFFFFFFFFFFF;
                CHECK(nkr::os::atomic::Exchange_Xor(u64, 0x0000000000000001) == 0xFFFFFFFFFFFFFFFF);
                CHECK(nkr::os::atomic::Access(u64) == 0xFFFFFFFFFFFFFFFE);
            #endif
            }
            TEST_CASE("s8_t")
            {
                s8_t s8 = 0x7F;
                CHECK(nkr::os::atomic::Exchange_Xor(s8, 0x01) == 0x7F);
                CHECK(nkr::os::atomic::Access(s8) == 0x7E);
            }
            TEST_CASE("s16_t")
            {
                s16_t s16 = 0x7FFF;
                CHECK(nkr::os::atomic::Exchange_Xor(s16, 0x0001) == 0x7FFF);
                CHECK(nkr::os::atomic::Access(s16) == 0x7FFE);
            }
            TEST_CASE("s32_t")
            {
                s32_t s32 = 0x7FFFFFFF;
                CHECK(nkr::os::atomic::Exchange_Xor(s32, 0x00000001) == 0x7FFFFFFF);
                CHECK(nkr::os::atomic::Access(s32) == 0x7FFFFFFE);
            }
            TEST_CASE("s64_t")
            {
            #if defined(nkr_IS_64_BIT)
                s64_t s64 = 0x7FFFFFFFFFFFFFFF;
                CHECK(nkr::os::atomic::Exchange_Xor(s64, 0x0000000000000001) == 0x7FFFFFFFFFFFFFFF);
                CHECK(nkr::os::atomic::Access(s64) == 0x7FFFFFFFFFFFFFFE);
            #endif
            }
        }
    }

}}}

namespace nkr { namespace os { namespace endian {

    TEST_SUITE("Is_Big")
    {
        TEST_CASE("should in a thread-safe manner efficiently determine if the runtime is in big endian"
                  * doctest::may_fail(true)
                  * doctest::no_breaks(true))
        {
        #if defined(nkr_IS_WINDOWS)
            CHECK(nkr::os::endian::Is_Big() == false);
        #else
            CHECK(nkr::os::endian::Is_Big() == true);
        #endif
        }
    }

    TEST_SUITE("Is_Little")
    {
        TEST_CASE("should in a thread-safe manner efficiently determine if the runtime is in little endian"
                  * doctest::may_fail(true)
                  * doctest::no_breaks(true))
        {
        #if defined(nkr_IS_WINDOWS)
            CHECK(nkr::os::endian::Is_Little() == true);
        #else
            CHECK(nkr::os::endian::Is_Little() == false);
        #endif
        }
    }

    TEST_SUITE("Swap")
    {
        TEST_SUITE("should swap the bytes of 16 bit, 32 bit, and 64 bit numbers")
        {
            TEST_CASE("u16_t")
            {
                u16_t u16 = 0x0102;
                CHECK(nkr::os::endian::Swap(u16) == 0x0201);
            }
            TEST_CASE("u32_t")
            {
                u32_t u32 = 0x01020304;
                CHECK(nkr::os::endian::Swap(u32) == 0x04030201);
            }
            TEST_CASE("u64_t")
            {
                u64_t u64 = 0x0102030405060708;
                CHECK(nkr::os::endian::Swap(u64) == 0x0807060504030201);
            }
            TEST_CASE("s16_t")
            {
                s16_t s16 = 0x0102;
                CHECK(nkr::os::endian::Swap(s16) == 0x0201);
            }
            TEST_CASE("s32_t")
            {
                s32_t s32 = 0x01020304;
                CHECK(nkr::os::endian::Swap(s32) == 0x04030201);
            }
            TEST_CASE("s64_t")
            {
                s64_t s64 = 0x0102030405060708;
                CHECK(nkr::os::endian::Swap(s64) == 0x0807060504030201);
            }
            TEST_CASE("built-in int literal")
            {
                CHECK(nkr::os::endian::Swap(0x0102) != 0x0201);
                CHECK(nkr::os::endian::Swap(0x0102) == 0x02010000);
                CHECK(nkr::os::endian::Swap(static_cast<u16_t>(0x0102)) == 0x0201);

                CHECK(nkr::os::endian::Swap(0x01020304) == 0x04030201);
                CHECK(nkr::os::endian::Swap(0x0102030405060708) == 0x0807060504030201);
            }
        }
    }

}}}

namespace nkr { namespace os { namespace heap {

    TEST_SUITE("Allocate")
    {
        TEST_CASE("should allocate heap memory or return nullptr if it can't")
        {
            byte_t* bytes = os::heap::Allocate(0xFF);
            CHECK(bytes != nullptr);

            wprintf(L"%s", bytes[0xFF - 1] == 1 ? L"\u0001" : L"\u0000");
            CHECK(true);

            byte_t* too_much = os::heap::Allocate(std::numeric_limits<count_t>::max());
            CHECK(too_much == nullptr);

            os::heap::Deallocate(bytes);
        }
    }

    TEST_SUITE("Reallocate")
    {
        TEST_CASE("should reallocate heap memory, set bytes, and return true, else leave bytes and return false")
        {
            byte_t* bytes = os::heap::Allocate(0xFF);
            CHECK(os::heap::Reallocate(bytes, 0xFFFF) == true);

            wprintf(L"%s", bytes[0xFFFF - 1] == 1 ? L"\u0001" : L"\u0000");
            CHECK(true);

            byte_t* bytes_backup = bytes;
            CHECK(os::heap::Reallocate(bytes, std::numeric_limits<count_t>::max()) == false);
            CHECK(bytes == bytes_backup);

            os::heap::Deallocate(bytes);
        }
    }

    TEST_SUITE("Deallocate")
    {
        TEST_CASE("should deallocate heap memory and set bytes to nullptr")
        {
            byte_t* bytes = os::heap::Allocate(0xFF);
            CHECK(bytes != nullptr);

            os::heap::Deallocate(bytes);
            CHECK(bytes == nullptr);
        }
    }

    TEST_SUITE("Allocate_Zeros")
    {
        TEST_CASE("should allocate heap memory and set to zero or return nullptr if it can't")
        {
            byte_t* bytes = os::heap::Allocate_Zeros(0xFF);
            CHECK(bytes != nullptr);
            for (index_t idx = 0, end = 0xFF; idx < end; idx += 1) {
                WARN(bytes[idx] == 0);
            }

            byte_t* too_much = os::heap::Allocate_Zeros(std::numeric_limits<count_t>::max());
            CHECK(too_much == nullptr);

            os::heap::Deallocate_Zeros(bytes);
        }
    }

    TEST_SUITE("Reallocate_Zeros")
    {
        TEST_CASE("should reallocate heap memory, set to zero, set bytes, and return true, else leave bytes and return false")
        {
            byte_t* bytes = os::heap::Allocate_Zeros(0xFF);
            CHECK(os::heap::Reallocate_Zeros(bytes, 0xFFFF) == true);
            for (index_t idx = 0, end = 0xFFFF; idx < end; idx += 1) {
                WARN(bytes[idx] == 0);
            }

            byte_t* bytes_backup = bytes;
            CHECK(os::heap::Reallocate_Zeros(bytes, std::numeric_limits<count_t>::max()) == false);
            CHECK(bytes == bytes_backup);

            os::heap::Deallocate_Zeros(bytes);
        }
    }

    TEST_SUITE("Deallocate_Zeros")
    {
        TEST_CASE("should deallocate heap memory and set bytes to nullptr")
        {
            byte_t* bytes = os::heap::Allocate_Zeros(0xFF);
            CHECK(bytes != nullptr);

            os::heap::Deallocate_Zeros(bytes);
            CHECK(bytes == nullptr);
        }
    }

}}}
