/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include <intrin.h>

#include "nkr/os.h"

namespace nkr { namespace os { namespace atomic {

#if defined(nkr_IS_WINDOWS)

    inline bool_tr auto Exchange_Assign(volatile bool_tr auto& atom, bool_tr auto with)
    {
        return ::_InterlockedExchange8(reinterpret_cast<volatile char*>(&atom), static_cast<char>(with));
    }

    inline integral_8_bit_tr auto Exchange_Assign(volatile integral_8_bit_tr auto& atom, integral_tr auto with)
    {
        return ::_InterlockedExchange8(reinterpret_cast<volatile char*>(&atom), static_cast<char>(with));
    }

    inline integral_16_bit_tr auto Exchange_Assign(volatile integral_16_bit_tr auto& atom, integral_tr auto with)
    {
        return ::_InterlockedExchange16(reinterpret_cast<volatile short*>(&atom), static_cast<short>(with));
    }

    inline integral_32_bit_tr auto Exchange_Assign(volatile integral_32_bit_tr auto& atom, integral_tr auto with)
    {
        return ::_InterlockedExchange(reinterpret_cast<volatile long*>(&atom), static_cast<long>(with));
    }

    inline integral_64_bit_tr auto Exchange_Assign(volatile integral_64_bit_tr auto& atom, integral_tr auto with)
    {
        return ::_InterlockedExchange64(reinterpret_cast<volatile long long*>(&atom), static_cast<long long>(with));
    }

    inline pointer_tr auto Exchange_Assign(volatile pointer_tr auto& atom, pointer_tr auto with)
    {
        static_assert(std::is_convertible<decltype(atom), decltype(with)>::value, "type of 'atom' and 'with' should be convertible.");

        return ::_InterlockedExchangePointer(reinterpret_cast<void* volatile*>(&atom), static_cast<void*>(with));
    }

#endif

}}}

namespace nkr { namespace os { namespace endian {

    inline bool_t Is_Big()
    {
        volatile word_t word = 1;
        return ((const byte_t*)&word)[0] == 0;
    }

    inline bool_t Is_Little()
    {
        volatile word_t word = 1;
        return ((const byte_t*)&word)[0] == 1;
    }

#if defined(nkr_IS_WINDOWS)

    inline u16_t Swap(u16_t bytes)
    {
        return ::_byteswap_ushort(bytes);
    }

    inline u32_t Swap(u32_t bytes)
    {
        return ::_byteswap_ulong(bytes);
    }

    inline u64_t Swap(u64_t bytes)
    {
        return ::_byteswap_uint64(bytes);
    }

#endif

}}}
