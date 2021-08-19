/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/macros.h"
#include "nkr/os.h"

namespace nkr { namespace os { namespace endian {

    bool_t Is_Big()
    {
        static bool_t is_big = false;

        nkr_INITIALIZE_STATIC_SAFELY(
            []() -> void_t
            {
                const volatile word_t word = 1;
                is_big = reinterpret_cast<const volatile byte_t*>(&word)[0] == 0;
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
                const volatile word_t word = 1;
                is_little = reinterpret_cast<const volatile byte_t*>(&word)[0] == 1;
            }
        );

        return is_little;
    }

}}}

namespace nkr { namespace os { namespace heap {

#if defined(nkr_IS_WINDOWS)

    // since C++11 using errno is thread-safe.
    
    // most of these calls are standard, but we're currently wrapping them
    // until I know for sure that we don't need to handle them differently.

    byte_t* Allocate(count_t byte_count)
    {
        assert(byte_count > 0);

        errno = 0;
        byte_t* bytes = static_cast<byte_t*>(::malloc(byte_count));
        if (errno == 0) {
            return bytes;
        } else {
            return nullptr;
        }
    }

    bool_t Reallocate(byte_t*& bytes, count_t new_byte_count)
    {
        assert(new_byte_count > 0);

        errno = 0;
        byte_t* new_bytes = static_cast<byte_t*>(::realloc(bytes, new_byte_count));
        if (errno == 0) {
            bytes = new_bytes;
            return true;
        } else {
            return false;
        }
    }

    void_t Deallocate(byte_t*& bytes)
    {
        ::free(bytes);
        bytes = nullptr;
    }

    byte_t* Allocate_Zeros(count_t byte_count)
    {
        assert(byte_count > 0);

        errno = 0;
        byte_t* bytes = static_cast<byte_t*>(::calloc(byte_count, sizeof(byte_t)));
        if (errno == 0) {
            return bytes;
        } else {
            return nullptr;
        }
    }

    bool_t Reallocate_Zeros(byte_t*& bytes, count_t new_byte_count)
    {
        assert(new_byte_count > 0);

        errno = 0;
        byte_t* new_bytes = static_cast<byte_t*>(::_recalloc(bytes, new_byte_count, sizeof(byte_t)));
        if (errno == 0) {
            bytes = new_bytes;
            return true;
        } else {
            return false;
        }
    }

    void_t Deallocate_Zeros(byte_t*& bytes)
    {
        ::free(bytes);
        bytes = nullptr;
    }

#endif

}}}
