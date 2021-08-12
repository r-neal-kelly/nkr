/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include <intrin.h>

#include "nkr/os.h"

namespace nkr { namespace os { namespace atomic {

#if defined(nkr_IS_WINDOWS)

    template <integral_tr atom_p>
    inline atom_p Access(const volatile atom_p& atom)
    {
        return Exchange_Assign_If_Equals(const_cast<volatile atom_p&>(atom), 0, 0);
    }

    template <pointer_tr atom_p>
    inline atom_p Access(const volatile atom_p& atom)
    {
        return Exchange_Assign_If_Equals(const_cast<volatile atom_p&>(atom), nullptr, nullptr);
    }

    template <integral_tr atom_p>
    inline atom_p Assign(volatile atom_p& atom, integral_tr auto with)
    {
        return Exchange_Assign(atom, with), with;
    }

    template <pointer_tr atom_p>
    inline atom_p Assign(volatile atom_p& atom, pointer_tr auto with)
    {
        static_assert(std::is_convertible<decltype(with), atom_p>::value, "'with' should be convertible to 'atom'.");

        return Exchange_Assign(atom, with), with;
    }

    template <integral_8_bit_tr atom_p>
    inline atom_p Exchange_Assign(volatile atom_p& atom, integral_tr auto with)
    {
        return ::_InterlockedExchange8(reinterpret_cast<volatile char*>(&atom), static_cast<char>(with));
    }

    template <integral_16_bit_tr atom_p>
    inline atom_p Exchange_Assign(volatile atom_p& atom, integral_tr auto with)
    {
        return ::_InterlockedExchange16(reinterpret_cast<volatile short*>(&atom), static_cast<short>(with));
    }

    template <integral_32_bit_tr atom_p>
    inline atom_p Exchange_Assign(volatile atom_p& atom, integral_tr auto with)
    {
        return ::_InterlockedExchange(reinterpret_cast<volatile long*>(&atom), static_cast<long>(with));
    }

    template <integral_64_bit_tr atom_p>
    inline atom_p Exchange_Assign(volatile atom_p& atom, integral_tr auto with)
    {
        return ::_InterlockedExchange64(reinterpret_cast<volatile long long*>(&atom), static_cast<long long>(with));
    }

    template <pointer_tr atom_p>
    inline atom_p Exchange_Assign(volatile atom_p& atom, pointer_tr auto with)
    {
        static_assert(std::is_convertible<decltype(with), atom_p>::value, "'with' should be convertible to 'atom'.");

        return static_cast<atom_p>(::_InterlockedExchangePointer(reinterpret_cast<void* volatile*>(&atom),
                                                                 static_cast<void*>(with)));
    }

    template <integral_8_bit_tr atom_p>
    inline atom_p Exchange_Assign_If_Equals(volatile atom_p& atom, integral_tr auto with, integral_tr auto target)
    {
        return ::_InterlockedCompareExchange8((volatile char*)(&atom),
                                              static_cast<char>(with),
                                              static_cast<char>(target));
    }
    
    template <integral_16_bit_tr atom_p>
    inline atom_p Exchange_Assign_If_Equals(volatile atom_p& atom, integral_tr auto with, integral_tr auto target)
    {
        return ::_InterlockedCompareExchange16(reinterpret_cast<volatile short*>(&atom),
                                               static_cast<short>(with),
                                               static_cast<short>(target));
    }
    
    template <integral_32_bit_tr atom_p>
    inline atom_p Exchange_Assign_If_Equals(volatile atom_p& atom, integral_tr auto with, integral_tr auto target)
    {
        return ::_InterlockedCompareExchange(reinterpret_cast<volatile long*>(&atom),
                                             static_cast<long>(with),
                                             static_cast<long>(target));
    }
    
    template <integral_64_bit_tr atom_p>
    inline atom_p Exchange_Assign_If_Equals(volatile atom_p& atom, integral_tr auto with, integral_tr auto target)
    {
        return ::_InterlockedCompareExchange64(reinterpret_cast<volatile long long*>(&atom),
                                               static_cast<long long>(with),
                                               static_cast<long long>(target));
    }

    template <pointer_tr atom_p>
    inline atom_p Exchange_Assign_If_Equals(volatile atom_p& atom, pointer_tr auto with, pointer_tr auto target)
    {
        static_assert(std::is_convertible<decltype(with), atom_p>::value, "'with' should be convertible to 'atom'.");
        static_assert(std::is_convertible<decltype(target), atom_p>::value, "'target' should be convertible to 'atom'.");

        return static_cast<atom_p>(::_InterlockedCompareExchangePointer(reinterpret_cast<void* volatile*>(&atom),
                                                                        static_cast<void*>(with),
                                                                        static_cast<void*>(target)));
    }

    template <integral_tr atom_p>
    inline atom_p Add(volatile atom_p& atom, integral_tr auto with)
    {
        return Exchange_Add(atom, with) + with;
    }

    template <pointer_tr atom_p>
    inline atom_p Add(volatile atom_p& atom, integral_tr auto with)
    {
        return Exchange_Add(atom, with) + with;
    }

    template <integral_8_bit_tr atom_p>
    inline atom_p Exchange_Add(volatile atom_p& atom, integral_tr auto with)
    {
        return ::_InterlockedExchangeAdd8(reinterpret_cast<volatile char*>(&atom), static_cast<char>(with));
    }

    template <integral_16_bit_tr atom_p>
    inline atom_p Exchange_Add(volatile atom_p& atom, integral_tr auto with)
    {
        return ::_InterlockedExchangeAdd16(reinterpret_cast<volatile short*>(&atom), static_cast<short>(with));
    }

    template <integral_32_bit_tr atom_p>
    inline atom_p Exchange_Add(volatile atom_p& atom, integral_tr auto with)
    {
        return ::_InterlockedExchangeAdd(reinterpret_cast<volatile long*>(&atom), static_cast<long>(with));
    }

    template <integral_64_bit_tr atom_p>
    inline atom_p Exchange_Add(volatile atom_p& atom, integral_tr auto with)
    {
        return ::_InterlockedExchangeAdd64(reinterpret_cast<volatile long long*>(&atom), static_cast<long long>(with));
    }

    template <pointer_tr atom_p>
    inline atom_p Exchange_Add(volatile atom_p& atom, integral_tr auto with)
    {
        return reinterpret_cast<atom_p>(Exchange_Add(reinterpret_cast<volatile address_t&>(atom),
                                                     sizeof(std::remove_pointer_t<atom_p>) * with));
    }

    template <integral_tr atom_p>
    inline atom_p Subtract(volatile atom_p& atom, integral_tr auto with)
    {
        return Exchange_Subtract(atom, with) - with;
    }

    template <pointer_tr atom_p>
    inline atom_p Subtract(volatile atom_p& atom, integral_tr auto with)
    {
        return Exchange_Subtract(atom, with) - with;
    }

    template <integral_8_bit_tr atom_p>
    inline atom_p Exchange_Subtract(volatile atom_p& atom, integral_tr auto with)
    {
        return ::_InterlockedExchangeAdd8(reinterpret_cast<volatile char*>(&atom), -static_cast<char>(with));
    }

    template <integral_16_bit_tr atom_p>
    inline atom_p Exchange_Subtract(volatile atom_p& atom, integral_tr auto with)
    {
        return ::_InterlockedExchangeAdd16(reinterpret_cast<volatile short*>(&atom), -static_cast<short>(with));
    }

    template <integral_32_bit_tr atom_p>
    inline atom_p Exchange_Subtract(volatile atom_p& atom, integral_tr auto with)
    {
        return ::_InterlockedExchangeAdd(reinterpret_cast<volatile long*>(&atom), -static_cast<long>(with));
    }

    template <integral_64_bit_tr atom_p>
    inline atom_p Exchange_Subtract(volatile atom_p& atom, integral_tr auto with)
    {
        return ::_InterlockedExchangeAdd64(reinterpret_cast<volatile long long*>(&atom), -static_cast<long long>(with));
    }

    template <pointer_tr atom_p>
    inline atom_p Exchange_Subtract(volatile atom_p& atom, integral_tr auto with)
    {
        return reinterpret_cast<atom_p>(Exchange_Subtract(reinterpret_cast<volatile address_t&>(atom),
                                                          sizeof(std::remove_pointer_t<atom_p>) * with));
    }

    template <integral_tr atom_p>
    inline atom_p Or(volatile atom_p& atom, integral_tr auto with)
    {
        return Exchange_Or(atom, with) | with;
    }

    template <integral_8_bit_tr atom_p>
    inline atom_p Exchange_Or(volatile atom_p& atom, integral_tr auto with)
    {
        return ::_InterlockedOr8(reinterpret_cast<volatile char*>(&atom), static_cast<char>(with));
    }

    template <integral_16_bit_tr atom_p>
    inline atom_p Exchange_Or(volatile atom_p& atom, integral_tr auto with)
    {
        return ::_InterlockedOr16(reinterpret_cast<volatile short*>(&atom), static_cast<short>(with));
    }

    template <integral_32_bit_tr atom_p>
    inline atom_p Exchange_Or(volatile atom_p& atom, integral_tr auto with)
    {
        return ::_InterlockedOr(reinterpret_cast<volatile long*>(&atom), static_cast<long>(with));
    }

    template <integral_64_bit_tr atom_p>
    inline atom_p Exchange_Or(volatile atom_p& atom, integral_tr auto with)
    {
        return ::_InterlockedOr64(reinterpret_cast<volatile long long*>(&atom), static_cast<long long>(with));
    }

    template <integral_tr atom_p>
    inline atom_p And(volatile atom_p& atom, integral_tr auto with)
    {
        return Exchange_And(atom, with) & with;
    }

    template <integral_8_bit_tr atom_p>
    inline atom_p Exchange_And(volatile atom_p& atom, integral_tr auto with)
    {
        return ::_InterlockedAnd8(reinterpret_cast<volatile char*>(&atom), static_cast<char>(with));
    }

    template <integral_16_bit_tr atom_p>
    inline atom_p Exchange_And(volatile atom_p& atom, integral_tr auto with)
    {
        return ::_InterlockedAnd16(reinterpret_cast<volatile short*>(&atom), static_cast<short>(with));
    }

    template <integral_32_bit_tr atom_p>
    inline atom_p Exchange_And(volatile atom_p& atom, integral_tr auto with)
    {
        return ::_InterlockedAnd(reinterpret_cast<volatile long*>(&atom), static_cast<long>(with));
    }

    template <integral_64_bit_tr atom_p>
    inline atom_p Exchange_And(volatile atom_p& atom, integral_tr auto with)
    {
        return ::_InterlockedAnd64(reinterpret_cast<volatile long long*>(&atom), static_cast<long long>(with));
    }

    template <integral_tr atom_p>
    inline atom_p Xor(volatile atom_p& atom, integral_tr auto with)
    {
        return Exchange_Xor(atom, with) ^ with;
    }

    template <integral_8_bit_tr atom_p>
    inline atom_p Exchange_Xor(volatile atom_p& atom, integral_tr auto with)
    {
        return ::_InterlockedXor8(reinterpret_cast<volatile char*>(&atom), static_cast<char>(with));
    }

    template <integral_16_bit_tr atom_p>
    inline atom_p Exchange_Xor(volatile atom_p& atom, integral_tr auto with)
    {
        return ::_InterlockedXor16(reinterpret_cast<volatile short*>(&atom), static_cast<short>(with));
    }

    template <integral_32_bit_tr atom_p>
    inline atom_p Exchange_Xor(volatile atom_p& atom, integral_tr auto with)
    {
        return ::_InterlockedXor(reinterpret_cast<volatile long*>(&atom), static_cast<long>(with));
    }

    template <integral_64_bit_tr atom_p>
    inline atom_p Exchange_Xor(volatile atom_p& atom, integral_tr auto with)
    {
        return ::_InterlockedXor64(reinterpret_cast<volatile long long*>(&atom), static_cast<long long>(with));
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
