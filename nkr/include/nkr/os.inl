/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/macros.h"

#if defined(nkr_IS_WINDOWS)
    #include <intrin.h>
#endif

#include <mutex>

#include "nkr/os.h"

namespace nkr { namespace os { namespace atomic {

    template <integer_tr atom_p>
    inline atom_p Access(const volatile atom_p& atom)
    {
        return Exchange_If_Equals(const_cast<volatile atom_p&>(atom), 0, 0);
    }

    template <pointer_tr atom_p>
    inline atom_p Access(const volatile atom_p& atom)
    {
        return Exchange_If_Equals(const_cast<volatile atom_p&>(atom), nullptr, nullptr);
    }

    template <integer_tr atom_p>
    inline atom_p Access_Add(const volatile atom_p& atom, integer_tr auto with)
    {
        return Access(atom) + with;
    }

    template <pointer_tr atom_p>
    inline atom_p Access_Add(const volatile atom_p& atom, integer_tr auto with)
    {
        return Access(atom) + with;
    }

    template <integer_tr atom_p>
    inline atom_p Access_Subtract(const volatile atom_p& atom, integer_tr auto with)
    {
        return Access(atom) - with;
    }

    template <pointer_tr atom_p>
    inline atom_p Access_Subtract(const volatile atom_p& atom, integer_tr auto with)
    {
        return Access(atom) - with;
    }

    template <integer_tr atom_p>
    inline atom_p Access_Or(const volatile atom_p& atom, integer_tr auto with)
    {
        return Access(atom) | with;
    }

    template <integer_tr atom_p>
    inline atom_p Access_And(const volatile atom_p& atom, integer_tr auto with)
    {
        return Access(atom) & with;
    }

    template <integer_tr atom_p>
    inline atom_p Access_Xor(const volatile atom_p& atom, integer_tr auto with)
    {
        return Access(atom) ^ with;
    }

    template <integer_tr atom_p>
    inline atom_p Assign(volatile atom_p& atom, integer_tr auto with)
    {
        return Exchange(atom, with), with;
    }

    template <pointer_tr atom_p>
    inline atom_p Assign(volatile atom_p& atom, pointer_tr auto with)
    {
        static_assert(std::is_convertible<decltype(with), atom_p>::value,
                      "'with' should be convertible to 'atom'.");

        return Exchange(atom, with), with;
    }

    template <integer_tr atom_p>
    inline atom_p Assign_Add(volatile atom_p& atom, integer_tr auto with)
    {
        return Exchange_Add(atom, with) + with;
    }

    template <pointer_tr atom_p>
    inline atom_p Assign_Add(volatile atom_p& atom, integer_tr auto with)
    {
        return Exchange_Add(atom, with) + with;
    }

    template <integer_tr atom_p>
    inline atom_p Assign_Subtract(volatile atom_p& atom, integer_tr auto with)
    {
        return Exchange_Subtract(atom, with) - with;
    }

    template <pointer_tr atom_p>
    inline atom_p Assign_Subtract(volatile atom_p& atom, integer_tr auto with)
    {
        return Exchange_Subtract(atom, with) - with;
    }

    template <integer_tr atom_p>
    inline atom_p Assign_Or(volatile atom_p& atom, integer_tr auto with)
    {
        return Exchange_Or(atom, with) | with;
    }

    template <integer_tr atom_p>
    inline atom_p Assign_And(volatile atom_p& atom, integer_tr auto with)
    {
        return Exchange_And(atom, with) & with;
    }

    template <integer_tr atom_p>
    inline atom_p Assign_Xor(volatile atom_p& atom, integer_tr auto with)
    {
        return Exchange_Xor(atom, with) ^ with;
    }

#if defined(nkr_IS_WINDOWS)

    template <integer_8_tr atom_p>
    inline atom_p Exchange(volatile atom_p& atom, integer_tr auto with)
    {
        return ::_InterlockedExchange8(reinterpret_cast<volatile char*>(&atom), static_cast<char>(with));
    }

    template <integer_16_tr atom_p>
    inline atom_p Exchange(volatile atom_p& atom, integer_tr auto with)
    {
        return ::_InterlockedExchange16(reinterpret_cast<volatile short*>(&atom), static_cast<short>(with));
    }

    template <integer_32_tr atom_p>
    inline atom_p Exchange(volatile atom_p& atom, integer_tr auto with)
    {
        return ::_InterlockedExchange(reinterpret_cast<volatile long*>(&atom), static_cast<long>(with));
    }

    template <integer_64_tr atom_p>
    inline atom_p Exchange(volatile atom_p& atom, integer_tr auto with)
    {
    #if defined(nkr_IS_64_BIT)
        return ::_InterlockedExchange64(reinterpret_cast<volatile long long*>(&atom),
                                        static_cast<long long>(with));
    #else
        static_assert(false, "64 bit atomic unavailable");
    #endif
    }

    template <pointer_tr atom_p>
    inline atom_p Exchange(volatile atom_p& atom, pointer_tr auto with)
    {
        static_assert(std::is_convertible<decltype(with), atom_p>::value,
                      "'with' should be convertible to 'atom'.");

        return static_cast<atom_p>(::_InterlockedExchangePointer(reinterpret_cast<void* volatile*>(&atom),
                                                                 static_cast<void*>(with)));
    }

    template <integer_8_tr atom_p>
    inline atom_p Exchange_If_Equals(volatile atom_p& atom, integer_tr auto with, integer_tr auto target)
    {
        return ::_InterlockedCompareExchange8((volatile char*)(&atom),
                                              static_cast<char>(with),
                                              static_cast<char>(target));
    }
    
    template <integer_16_tr atom_p>
    inline atom_p Exchange_If_Equals(volatile atom_p& atom, integer_tr auto with, integer_tr auto target)
    {
        return ::_InterlockedCompareExchange16(reinterpret_cast<volatile short*>(&atom),
                                               static_cast<short>(with),
                                               static_cast<short>(target));
    }
    
    template <integer_32_tr atom_p>
    inline atom_p Exchange_If_Equals(volatile atom_p& atom, integer_tr auto with, integer_tr auto target)
    {
        return ::_InterlockedCompareExchange(reinterpret_cast<volatile long*>(&atom),
                                             static_cast<long>(with),
                                             static_cast<long>(target));
    }
    
    template <integer_64_tr atom_p>
    inline atom_p Exchange_If_Equals(volatile atom_p& atom, integer_tr auto with, integer_tr auto target)
    {
    #if defined(nkr_IS_64_BIT)
        return ::_InterlockedCompareExchange64(reinterpret_cast<volatile long long*>(&atom),
                                               static_cast<long long>(with),
                                               static_cast<long long>(target));
    #else
        static_assert(false, "64 bit atomic unavailable");
    #endif
    }

    template <pointer_tr atom_p>
    inline atom_p Exchange_If_Equals(volatile atom_p& atom, pointer_tr auto with, pointer_tr auto target)
    {
        static_assert(std::is_convertible<decltype(with), atom_p>::value,
                      "'with' should be convertible to 'atom'.");
        static_assert(std::is_convertible<decltype(target), atom_p>::value,
                      "'target' should be convertible to 'atom'.");

        return static_cast<atom_p>(::_InterlockedCompareExchangePointer(reinterpret_cast<void* volatile*>(&atom),
                                                                        static_cast<void*>(with),
                                                                        static_cast<void*>(target)));
    }

    template <integer_8_tr atom_p>
    inline atom_p Exchange_Add(volatile atom_p& atom, integer_tr auto with)
    {
        static_assert(std::same_as<bool_t, atom_p> == false, "cannot add to bool_t");

        return ::_InterlockedExchangeAdd8(reinterpret_cast<volatile char*>(&atom), static_cast<char>(with));
    }

    template <integer_16_tr atom_p>
    inline atom_p Exchange_Add(volatile atom_p& atom, integer_tr auto with)
    {
        return ::_InterlockedExchangeAdd16(reinterpret_cast<volatile short*>(&atom), static_cast<short>(with));
    }

    template <integer_32_tr atom_p>
    inline atom_p Exchange_Add(volatile atom_p& atom, integer_tr auto with)
    {
        return ::_InterlockedExchangeAdd(reinterpret_cast<volatile long*>(&atom), static_cast<long>(with));
    }

    template <integer_64_tr atom_p>
    inline atom_p Exchange_Add(volatile atom_p& atom, integer_tr auto with)
    {
    #if defined(nkr_IS_64_BIT)
        return ::_InterlockedExchangeAdd64(reinterpret_cast<volatile long long*>(&atom),
                                           static_cast<long long>(with));
    #else
        static_assert(false, "64 bit atomic unavailable");
    #endif
    }

    template <pointer_tr atom_p>
    inline atom_p Exchange_Add(volatile atom_p& atom, integer_tr auto with)
    {
        return reinterpret_cast<atom_p>(Exchange_Add(reinterpret_cast<volatile address_t&>(atom),
                                                     sizeof(std::remove_pointer_t<atom_p>) * with));
    }

    template <integer_8_tr atom_p>
    inline atom_p Exchange_Subtract(volatile atom_p& atom, integer_tr auto with)
    {
        static_assert(std::same_as<bool_t, atom_p> == false, "cannot subtract from bool_t");

        return ::_InterlockedExchangeAdd8(reinterpret_cast<volatile char*>(&atom), -static_cast<char>(with));
    }

    template <integer_16_tr atom_p>
    inline atom_p Exchange_Subtract(volatile atom_p& atom, integer_tr auto with)
    {
        return ::_InterlockedExchangeAdd16(reinterpret_cast<volatile short*>(&atom), -static_cast<short>(with));
    }

    template <integer_32_tr atom_p>
    inline atom_p Exchange_Subtract(volatile atom_p& atom, integer_tr auto with)
    {
        return ::_InterlockedExchangeAdd(reinterpret_cast<volatile long*>(&atom), -static_cast<long>(with));
    }

    template <integer_64_tr atom_p>
    inline atom_p Exchange_Subtract(volatile atom_p& atom, integer_tr auto with)
    {
    #if defined(nkr_IS_64_BIT)
        return ::_InterlockedExchangeAdd64(reinterpret_cast<volatile long long*>(&atom),
                                           -static_cast<long long>(with));
    #else
        static_assert(false, "64 bit atomic unavailable");
    #endif
    }

    template <pointer_tr atom_p>
    inline atom_p Exchange_Subtract(volatile atom_p& atom, integer_tr auto with)
    {
        return reinterpret_cast<atom_p>(Exchange_Subtract(reinterpret_cast<volatile address_t&>(atom),
                                                          sizeof(std::remove_pointer_t<atom_p>) * with));
    }

    template <integer_8_tr atom_p>
    inline atom_p Exchange_Or(volatile atom_p& atom, integer_tr auto with)
    {
        static_assert(std::same_as<bool_t, atom_p> == false, "cannot OR bool_t");

        return ::_InterlockedOr8(reinterpret_cast<volatile char*>(&atom), static_cast<char>(with));
    }

    template <integer_16_tr atom_p>
    inline atom_p Exchange_Or(volatile atom_p& atom, integer_tr auto with)
    {
        return ::_InterlockedOr16(reinterpret_cast<volatile short*>(&atom), static_cast<short>(with));
    }

    template <integer_32_tr atom_p>
    inline atom_p Exchange_Or(volatile atom_p& atom, integer_tr auto with)
    {
        return ::_InterlockedOr(reinterpret_cast<volatile long*>(&atom), static_cast<long>(with));
    }

    template <integer_64_tr atom_p>
    inline atom_p Exchange_Or(volatile atom_p& atom, integer_tr auto with)
    {
    #if defined(nkr_IS_64_BIT)
        return ::_InterlockedOr64(reinterpret_cast<volatile long long*>(&atom), static_cast<long long>(with));
    #else
        static_assert(false, "64 bit atomic unavailable");
    #endif
    }

    template <integer_8_tr atom_p>
    inline atom_p Exchange_And(volatile atom_p& atom, integer_tr auto with)
    {
        static_assert(std::same_as<bool_t, atom_p> == false, "cannot AND bool_t");

        return ::_InterlockedAnd8(reinterpret_cast<volatile char*>(&atom), static_cast<char>(with));
    }

    template <integer_16_tr atom_p>
    inline atom_p Exchange_And(volatile atom_p& atom, integer_tr auto with)
    {
        return ::_InterlockedAnd16(reinterpret_cast<volatile short*>(&atom), static_cast<short>(with));
    }

    template <integer_32_tr atom_p>
    inline atom_p Exchange_And(volatile atom_p& atom, integer_tr auto with)
    {
        return ::_InterlockedAnd(reinterpret_cast<volatile long*>(&atom), static_cast<long>(with));
    }

    template <integer_64_tr atom_p>
    inline atom_p Exchange_And(volatile atom_p& atom, integer_tr auto with)
    {
    #if defined(nkr_IS_64_BIT)
        return ::_InterlockedAnd64(reinterpret_cast<volatile long long*>(&atom), static_cast<long long>(with));
    #else
        static_assert(false, "64 bit atomic unavailable");
    #endif
    }

    template <integer_8_tr atom_p>
    inline atom_p Exchange_Xor(volatile atom_p& atom, integer_tr auto with)
    {
        static_assert(std::same_as<bool_t, atom_p> == false, "cannot XOR bool_t");

        return ::_InterlockedXor8(reinterpret_cast<volatile char*>(&atom), static_cast<char>(with));
    }

    template <integer_16_tr atom_p>
    inline atom_p Exchange_Xor(volatile atom_p& atom, integer_tr auto with)
    {
        return ::_InterlockedXor16(reinterpret_cast<volatile short*>(&atom), static_cast<short>(with));
    }

    template <integer_32_tr atom_p>
    inline atom_p Exchange_Xor(volatile atom_p& atom, integer_tr auto with)
    {
        return ::_InterlockedXor(reinterpret_cast<volatile long*>(&atom), static_cast<long>(with));
    }

    template <integer_64_tr atom_p>
    inline atom_p Exchange_Xor(volatile atom_p& atom, integer_tr auto with)
    {
    #if defined(nkr_IS_64_BIT)
        return ::_InterlockedXor64(reinterpret_cast<volatile long long*>(&atom), static_cast<long long>(with));
    #else
        static_assert(false, "64 bit atomic unavailable");
    #endif
    }

#endif

}}}

namespace nkr { namespace os { namespace endian {

#if defined(nkr_IS_WINDOWS)

    template <integer_16_tr i16_p>
    inline i16_p Swap(i16_p bytes)
    {
        return ::_byteswap_ushort(bytes);
    }

    template <integer_32_tr i32_p>
    inline i32_p Swap(i32_p bytes)
    {
        return ::_byteswap_ulong(bytes);
    }

    template <integer_64_tr i64_p>
    inline i64_p Swap(i64_p bytes)
    {
        return ::_byteswap_uint64(bytes);
    }

#endif

}}}
