/*
    Copyright 2022 r-neal-kelly
*/

#include "nkr/array/local/dynamic_t.h"
#include "nkr/concurrency/lockee_t.h"
#include "nkr/cpp/concurrency/thread_t.h"
#include "nkr/negatable/integer_t.h"
#include "nkr/pointer/cpp_t.h"
#include "nkr/randomness.h"

#include "doctest.h"

namespace nkr {

    TEST_SUITE("nkr::array::local::dynamic_t")
    {
        TEST_CASE("temp")
        {
            nkr::array::local::dynamic_t<int, nkr::constant::positive::count_t<2>> a;
            nkr::array::local::dynamic_t<int, nkr::constant::positive::count_t<2>> b;
            nkr::array::local::dynamic_t<int, nkr::constant::positive::count_t<2>> c{ int(1), int(2) };
            nkr::array::local::dynamic_t<int, nkr::constant::positive::count_t<2>> d(c);

            CHECK(c.Unit_Count() == 2);
            CHECK(c.Unit(0) == 1);
            CHECK(c.Unit(1) == 2);
            CHECK(c.Pop_Unit() == 2);
            CHECK(c.Unit_Count() == 1);

            CHECK(d.Unit_Count() == 2);
            CHECK(d[0] == 1);
            CHECK(d[1] == 2);

            c = a;
            CHECK(c.Unit_Count() == 0);

            nkr::array::local::dynamic_t<volatile int, nkr::constant::positive::count_t<2>> e{ int(1), int(2) };
            CHECK(e.Unit_Count() == 2);
            CHECK(e[0] == 1);
            CHECK(e[1] == 2);
            CHECK(e.Pop_Unit() == 2);
            CHECK(e.Unit_Count() == 1);
        }

        TEST_SUITE("concurrent read section")
        {
            struct message_t
            {
            public:
                nkr::positive::index_t          idx;
                nkr::pointer::cpp_t<const char> message;
            };

            using messages_t =
                nkr::array::local::dynamic_t<message_t, nkr::constant::positive::count_t<64>>;

            messages_t                                      g_messages;
            nkr::cpp::concurrency::lock::perpetual::deep_t  g_messages_lock;

            TEST_CASE("access read section concurrently")
            {
                nkr::array::local::dynamic_t<nkr::cpp::concurrency::thread_t, typename messages_t::unit_capacity_t> write_threads;
                nkr::array::local::dynamic_t<nkr::cpp::concurrency::thread_t, typename messages_t::unit_capacity_t> read_threads;
                for (nkr::positive::index_t idx = 0, end = messages_t::Unit_Capacity(); idx < end; idx += 1) {
                    write_threads.Push_Units(nkr::cpp::concurrency::thread_t(
                        [idx]()
                        {
                            std::this_thread::sleep_for(std::chrono::milliseconds(nkr::randomness::Value<int>(0, 64)));

                            nkr::concurrency::lockee_t<messages_t> messages(g_messages, g_messages_lock);
                            nkr::pointer::cpp_t<const char> message = "a message";
                            messages.Value().Push_Units(message_t(idx, message));

                            printf("Added message %i\n", int(idx));
                        }
                    ));

                    read_threads.Push_Units(nkr::cpp::concurrency::thread_t(
                        []()
                        {
                            while (true) {
                                std::this_thread::sleep_for(std::chrono::milliseconds(nkr::randomness::Value<int>(0, 64)));

                                nkr::concurrency::lockee_t<messages_t> messages(g_messages, g_messages_lock);
                                if (messages.Value().Unit_Count() > 0) {
                                    message_t message = messages.Value().Pop_Unit();

                                    printf("Removed message %i\n", int(message.idx));

                                    return;
                                }
                            }
                        }
                    ));
                }
            }
        }
    }

}
