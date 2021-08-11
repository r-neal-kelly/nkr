/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/os.h"

namespace nkr { namespace os { namespace heap {

#if defined(nkr_IS_WINDOWS)

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

    byte_t* Reallocate(byte_t* bytes, count_t new_byte_count)
    {
        assert(bytes);
        assert(new_byte_count > 0);

        errno = 0;
        byte_t* new_bytes = static_cast<byte_t*>(::realloc(bytes, new_byte_count));
        if (errno == 0) {
            return new_bytes;
        } else {
            return nullptr;
        }
    }

    void_t Deallocate(byte_t* bytes)
    {
        assert(bytes);

        ::free(bytes);
    }

    byte_t* Callocate(count_t byte_count)
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

    byte_t* Recallocate(byte_t* bytes, count_t new_byte_count)
    {
        assert(bytes);
        assert(new_byte_count > 0);

        errno = 0;
        byte_t* new_bytes = static_cast<byte_t*>(::_recalloc(bytes, new_byte_count, sizeof(byte_t)));
        if (errno == 0) {
            return new_bytes;
        } else {
            return nullptr;
        }
    }

    void_t Decallocate(byte_t* bytes)
    {
        assert(bytes);

        ::free(bytes);
    }

#endif

}}}
