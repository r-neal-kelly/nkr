/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/bool_t.h"
#include "nkr/macros.h"
#include "nkr/os.h"

namespace nkr { namespace os { namespace endian {

    bool_t Is_Big()
    {
        static bool_t is_big = false;

        nkr_INITIALIZE_STATIC_SAFELY(
            []() -> void_t
            {
                volatile const word_t word = 1;
                is_big = reinterpret_cast<volatile const byte_t*>(&word)[0] == 0;
            }
        );

        return is_big;
    }

    bool_t Is_Little()
    {
        static bool_t is_little = false;

        nkr_INITIALIZE_STATIC_SAFELY(
            []() -> void_t
            {
                volatile const word_t word = 1;
                is_little = reinterpret_cast<volatile const byte_t*>(&word)[0] == 1;
            }
        );

        return is_little;
    }

}}}
