/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include <mutex>

#include "nkr/macros.h"
#include "nkr/os.h"

#if defined(nkr_IS_WINDOWS)
    #include <intrin.h>
#endif

namespace nkr { namespace os { namespace atomic {

    inline boolean_tr auto Access(const volatile boolean_tr auto& atom)
    {
        return Exchange_If_Equals(const_cast<volatile std::remove_cvref_t<decltype(atom)>&>(atom), false, false);
    }

    inline integer_tr auto Access(const volatile integer_tr auto& atom)
    {
        return Exchange_If_Equals(const_cast<volatile std::remove_cvref_t<decltype(atom)>&>(atom), 0, 0);
    }

    inline pointer_tr auto Access(const volatile pointer_tr auto& atom)
    {
        return Exchange_If_Equals(const_cast<volatile std::remove_cvref_t<decltype(atom)>&>(atom), nullptr, nullptr);
    }

    inline integer_tr auto Access_Add(const volatile integer_tr auto& atom, integer_tr auto with)
    {
        return Access(atom) + with;
    }

    inline pointer_tr auto Access_Add(const volatile pointer_tr auto& atom, integer_tr auto with)
    {
        return Access(atom) + with;
    }

    inline integer_tr auto Access_Subtract(const volatile integer_tr auto& atom, integer_tr auto with)
    {
        return Access(atom) - with;
    }

    inline pointer_tr auto Access_Subtract(const volatile pointer_tr auto& atom, integer_tr auto with)
    {
        return Access(atom) - with;
    }

    inline integer_tr auto Access_Or(const volatile integer_tr auto& atom, integer_tr auto with)
    {
        return Access(atom) | with;
    }

    inline integer_tr auto Access_And(const volatile integer_tr auto& atom, integer_tr auto with)
    {
        return Access(atom) & with;
    }

    inline integer_tr auto Access_Xor(const volatile integer_tr auto& atom, integer_tr auto with)
    {
        return Access(atom) ^ with;
    }

    inline boolean_tr auto Assign(volatile boolean_tr auto& atom, bool_t with)
    {
        return Exchange(atom, with), with;
    }

    inline integer_tr auto Assign(volatile integer_tr auto& atom, integer_tr auto with)
    {
        return Exchange(atom, with), with;
    }

    inline pointer_tr auto Assign(volatile pointer_tr auto& atom, pointer_tr auto with)
    {
        return Exchange(atom, with), with;
    }

    inline integer_tr auto Assign_Add(volatile integer_tr auto& atom, integer_tr auto with)
    {
        return Exchange_Add(atom, with) + with;
    }

    inline pointer_tr auto Assign_Add(volatile pointer_tr auto& atom, integer_tr auto with)
    {
        return Exchange_Add(atom, with) + with;
    }

    inline integer_tr auto Assign_Subtract(volatile integer_tr auto& atom, integer_tr auto with)
    {
        return Exchange_Subtract(atom, with) - with;
    }

    inline pointer_tr auto Assign_Subtract(volatile pointer_tr auto& atom, integer_tr auto with)
    {
        return Exchange_Subtract(atom, with) - with;
    }

    inline integer_tr auto Assign_Or(volatile integer_tr auto& atom, integer_tr auto with)
    {
        return Exchange_Or(atom, with) | with;
    }

    inline integer_tr auto Assign_And(volatile integer_tr auto& atom, integer_tr auto with)
    {
        return Exchange_And(atom, with) & with;
    }

    inline integer_tr auto Assign_Xor(volatile integer_tr auto& atom, integer_tr auto with)
    {
        return Exchange_Xor(atom, with) ^ with;
    }

#if defined(nkr_IS_WINDOWS)

    inline boolean_tr auto Exchange(volatile boolean_tr auto& atom, bool_t with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        return static_cast<atom_t>(Exchange(static_cast<volatile word_t&>(atom),
                                            static_cast<word_t>(with)));
    }

    inline integer_8_tr auto Exchange(volatile integer_8_tr auto& atom, integer_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        return static_cast<atom_t>(::_InterlockedExchange8(reinterpret_cast<volatile char*>(&atom),
                                                           static_cast<char>(with)));
    }

    inline integer_16_tr auto Exchange(volatile integer_16_tr auto& atom, integer_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        return static_cast<atom_t>(::_InterlockedExchange16(reinterpret_cast<volatile short*>(&atom),
                                                            static_cast<short>(with)));
    }

    inline integer_32_tr auto Exchange(volatile integer_32_tr auto& atom, integer_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        return static_cast<atom_t>(::_InterlockedExchange(reinterpret_cast<volatile long*>(&atom),
                                                          static_cast<long>(with)));
    }

    inline integer_64_tr auto Exchange(volatile integer_64_tr auto& atom, integer_tr auto with)
    {
    #if defined(nkr_IS_64_BIT)
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        return static_cast<atom_t>(::_InterlockedExchange64(reinterpret_cast<volatile long long*>(&atom),
                                                            static_cast<long long>(with)));
    #else
        static_assert(false, "64 bit atomic unavailable");
    #endif        
    }

    inline pointer_tr auto Exchange(volatile pointer_tr auto& atom, pointer_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        static_assert(std::is_convertible<decltype(with), atom_t>::value,
                      "'with' should be convertible to 'atom'.");

        return static_cast<atom_t>(::_InterlockedExchangePointer(reinterpret_cast<void* volatile*>(&atom),
                                                                 static_cast<void*>(with)));
    }

    inline boolean_tr auto Exchange_If_Equals(volatile boolean_tr auto& atom,
                                              bool_t with,
                                              bool_t target)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        return static_cast<atom_t>(Exchange_If_Equals(static_cast<volatile word_t&>(atom),
                                                      static_cast<word_t>(with),
                                                      static_cast<word_t>(target)));
    }

    inline integer_8_tr auto Exchange_If_Equals(volatile integer_8_tr auto& atom,
                                                integer_tr auto with,
                                                integer_tr auto target)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        return static_cast<atom_t>(::_InterlockedCompareExchange8((volatile char*)(&atom),
                                                                  static_cast<char>(with),
                                                                  static_cast<char>(target)));
    }

    inline integer_16_tr auto Exchange_If_Equals(volatile integer_16_tr auto& atom,
                                                 integer_tr auto with,
                                                 integer_tr auto target)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        return static_cast<atom_t>(::_InterlockedCompareExchange16(reinterpret_cast<volatile short*>(&atom),
                                                                   static_cast<short>(with),
                                                                   static_cast<short>(target)));
    }

    inline integer_32_tr auto Exchange_If_Equals(volatile integer_32_tr auto& atom,
                                                 integer_tr auto with,
                                                 integer_tr auto target)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        return static_cast<atom_t>(::_InterlockedCompareExchange(reinterpret_cast<volatile long*>(&atom),
                                                                 static_cast<long>(with),
                                                                 static_cast<long>(target)));
    }

    inline integer_64_tr auto Exchange_If_Equals(volatile integer_64_tr auto& atom,
                                                 integer_tr auto with,
                                                 integer_tr auto target)
    {
    #if defined(nkr_IS_64_BIT)
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        return static_cast<atom_t>(::_InterlockedCompareExchange64(reinterpret_cast<volatile long long*>(&atom),
                                                                   static_cast<long long>(with),
                                                                   static_cast<long long>(target)));
    #else
        static_assert(false, "64 bit atomic unavailable");
    #endif
    }

    inline pointer_tr auto Exchange_If_Equals(volatile pointer_tr auto& atom,
                                              pointer_tr auto with,
                                              pointer_tr auto target)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        static_assert(std::is_convertible<decltype(with), atom_t>::value,
                      "'with' should be convertible to 'atom'.");
        static_assert(std::is_convertible<decltype(target), atom_t>::value,
                      "'target' should be convertible to 'atom'.");

        return static_cast<atom_t>(::_InterlockedCompareExchangePointer(reinterpret_cast<void* volatile*>(&atom),
                                                                        static_cast<void*>(with),
                                                                        static_cast<void*>(target)));
    }

    inline integer_8_tr auto Exchange_Add(volatile integer_8_tr auto& atom, integer_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        static_assert(std::same_as<bool_t, atom_t> == false, "cannot add to bool_t");

        return static_cast<atom_t>(::_InterlockedExchangeAdd8(reinterpret_cast<volatile char*>(&atom),
                                                              static_cast<char>(with)));
    }

    inline integer_16_tr auto Exchange_Add(volatile integer_16_tr auto& atom, integer_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        return static_cast<atom_t>(::_InterlockedExchangeAdd16(reinterpret_cast<volatile short*>(&atom),
                                                               static_cast<short>(with)));
    }

    inline integer_32_tr auto Exchange_Add(volatile integer_32_tr auto& atom, integer_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        return static_cast<atom_t>(::_InterlockedExchangeAdd(reinterpret_cast<volatile long*>(&atom),
                                                             static_cast<long>(with)));
    }

    inline integer_64_tr auto Exchange_Add(volatile integer_64_tr auto& atom, integer_tr auto with)
    {
    #if defined(nkr_IS_64_BIT)
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        return static_cast<atom_t>(::_InterlockedExchangeAdd64(reinterpret_cast<volatile long long*>(&atom),
                                                               static_cast<long long>(with)));
    #else
        static_assert(false, "64 bit atomic unavailable");
    #endif
    }

    inline pointer_tr auto Exchange_Add(volatile pointer_tr auto& atom, integer_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        return reinterpret_cast<atom_t>(Exchange_Add(reinterpret_cast<volatile address_t&>(atom),
                                                     sizeof(std::remove_pointer_t<atom_t>) * with));
    }

    inline integer_8_tr auto Exchange_Subtract(volatile integer_8_tr auto& atom, integer_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        static_assert(std::same_as<bool_t, atom_t> == false, "cannot subtract from bool_t");

        return static_cast<atom_t>(::_InterlockedExchangeAdd8(reinterpret_cast<volatile char*>(&atom),
                                                              -static_cast<char>(with)));
    }

    inline integer_16_tr auto Exchange_Subtract(volatile integer_16_tr auto& atom, integer_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        return static_cast<atom_t>(::_InterlockedExchangeAdd16(reinterpret_cast<volatile short*>(&atom),
                                                               -static_cast<short>(with)));
    }

    inline integer_32_tr auto Exchange_Subtract(volatile integer_32_tr auto& atom, integer_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        return static_cast<atom_t>(::_InterlockedExchangeAdd(reinterpret_cast<volatile long*>(&atom),
                                                             -static_cast<long>(with)));
    }

    inline integer_64_tr auto Exchange_Subtract(volatile integer_64_tr auto& atom, integer_tr auto with)
    {
    #if defined(nkr_IS_64_BIT)
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        return static_cast<atom_t>(::_InterlockedExchangeAdd64(reinterpret_cast<volatile long long*>(&atom),
                                                               -static_cast<long long>(with)));
    #else
        static_assert(false, "64 bit atomic unavailable");
    #endif
    }

    inline pointer_tr auto Exchange_Subtract(volatile pointer_tr auto& atom, integer_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        return reinterpret_cast<atom_t>(Exchange_Subtract(reinterpret_cast<volatile address_t&>(atom),
                                                          sizeof(std::remove_pointer_t<atom_t>) * with));
    }

    inline integer_8_tr auto Exchange_Or(volatile integer_8_tr auto& atom, integer_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        static_assert(std::same_as<bool_t, atom_t> == false, "cannot OR bool_t");

        return static_cast<atom_t>(::_InterlockedOr8(reinterpret_cast<volatile char*>(&atom),
                                                     static_cast<char>(with)));
    }

    inline integer_16_tr auto Exchange_Or(volatile integer_16_tr auto& atom, integer_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        return static_cast<atom_t>(::_InterlockedOr16(reinterpret_cast<volatile short*>(&atom),
                                                      static_cast<short>(with)));
    }

    inline integer_32_tr auto Exchange_Or(volatile integer_32_tr auto& atom, integer_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        return static_cast<atom_t>(::_InterlockedOr(reinterpret_cast<volatile long*>(&atom),
                                                    static_cast<long>(with)));
    }

    inline integer_64_tr auto Exchange_Or(volatile integer_64_tr auto& atom, integer_tr auto with)
    {
    #if defined(nkr_IS_64_BIT)
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        return static_cast<atom_t>(::_InterlockedOr64(reinterpret_cast<volatile long long*>(&atom),
                                                      static_cast<long long>(with)));
    #else
        static_assert(false, "64 bit atomic unavailable");
    #endif
    }

    inline integer_8_tr auto Exchange_And(volatile integer_8_tr auto& atom, integer_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        static_assert(std::same_as<bool_t, atom_t> == false, "cannot AND bool_t");

        return static_cast<atom_t>(::_InterlockedAnd8(reinterpret_cast<volatile char*>(&atom),
                                                      static_cast<char>(with)));
    }

    inline integer_16_tr auto Exchange_And(volatile integer_16_tr auto& atom, integer_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        return static_cast<atom_t>(::_InterlockedAnd16(reinterpret_cast<volatile short*>(&atom),
                                                       static_cast<short>(with)));
    }

    inline integer_32_tr auto Exchange_And(volatile integer_32_tr auto& atom, integer_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        return static_cast<atom_t>(::_InterlockedAnd(reinterpret_cast<volatile long*>(&atom),
                                                     static_cast<long>(with)));
    }

    inline integer_64_tr auto Exchange_And(volatile integer_64_tr auto& atom, integer_tr auto with)
    {
    #if defined(nkr_IS_64_BIT)
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        return static_cast<atom_t>(::_InterlockedAnd64(reinterpret_cast<volatile long long*>(&atom),
                                                       static_cast<long long>(with)));
    #else
        static_assert(false, "64 bit atomic unavailable");
    #endif
    }

    inline integer_8_tr auto Exchange_Xor(volatile integer_8_tr auto& atom, integer_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        static_assert(std::same_as<bool_t, atom_t> == false, "cannot XOR bool_t");

        return static_cast<atom_t>(::_InterlockedXor8(reinterpret_cast<volatile char*>(&atom),
                                                      static_cast<char>(with)));
    }

    inline integer_16_tr auto Exchange_Xor(volatile integer_16_tr auto& atom, integer_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        return static_cast<atom_t>(::_InterlockedXor16(reinterpret_cast<volatile short*>(&atom),
                                                       static_cast<short>(with)));
    }

    inline integer_32_tr auto Exchange_Xor(volatile integer_32_tr auto& atom, integer_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        return static_cast<atom_t>(::_InterlockedXor(reinterpret_cast<volatile long*>(&atom),
                                                     static_cast<long>(with)));
    }

    inline integer_64_tr auto Exchange_Xor(volatile integer_64_tr auto& atom, integer_tr auto with)
    {
    #if defined(nkr_IS_64_BIT)
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        return static_cast<atom_t>(::_InterlockedXor64(reinterpret_cast<volatile long long*>(&atom),
                                                       static_cast<long long>(with)));
    #else
        static_assert(false, "64 bit atomic unavailable");
    #endif
    }

#endif

}}}

namespace nkr { namespace os { namespace endian {

#if defined(nkr_IS_WINDOWS)

    inline integer_16_tr auto Swap(integer_16_tr auto bytes)
    {
        return ::_byteswap_ushort(bytes);
    }

    inline integer_32_tr auto Swap(integer_32_tr auto bytes)
    {
        return ::_byteswap_ulong(bytes);
    }

    inline integer_64_tr auto Swap(integer_64_tr auto bytes)
    {
        return ::_byteswap_uint64(bytes);
    }

#endif

}}}
