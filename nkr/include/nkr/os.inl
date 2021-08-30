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
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        atom_t snapshot = atom_t();
        Exchange_If_Equals(const_cast<volatile std::remove_cvref_t<decltype(atom)>&>(atom), snapshot, atom_t());
        return snapshot;
    }

    inline integer_tr auto Access(const volatile integer_tr auto& atom)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        atom_t snapshot = atom_t();
        Exchange_If_Equals(const_cast<volatile std::remove_cvref_t<decltype(atom)>&>(atom), snapshot, atom_t());
        return snapshot;
    }

    inline real_tr auto Access(const volatile real_tr auto& atom)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        atom_t snapshot = atom_t();
        Exchange_If_Equals(const_cast<volatile std::remove_cvref_t<decltype(atom)>&>(atom), snapshot, atom_t());
        return snapshot;
    }

    inline pointer_tr auto Access(const volatile pointer_tr auto& atom)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        atom_t snapshot = atom_t();
        Exchange_If_Equals(const_cast<volatile std::remove_cvref_t<decltype(atom)>&>(atom), snapshot, atom_t());
        return snapshot;
    }

    inline integer_tr auto Access_Add(const volatile integer_tr auto& atom, to_integer_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        return static_cast<atom_t>(Access(atom) + static_cast<atom_t>(with));
    }

    inline real_tr auto Access_Add(const volatile real_tr auto& atom, to_real_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        return static_cast<atom_t>(Access(atom) + static_cast<atom_t>(with));
    }

    inline type_pointer_tr auto Access_Add(const volatile type_pointer_tr auto& atom, integer_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        return static_cast<atom_t>(Access(atom) + with);
    }

    inline integer_tr auto Access_Subtract(const volatile integer_tr auto& atom, to_integer_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        return static_cast<atom_t>(Access(atom) - static_cast<atom_t>(with));
    }

    inline real_tr auto Access_Subtract(const volatile real_tr auto& atom, to_real_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        return static_cast<atom_t>(Access(atom) - static_cast<atom_t>(with));
    }

    inline type_pointer_tr auto Access_Subtract(const volatile type_pointer_tr auto& atom, integer_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        return static_cast<atom_t>(Access(atom) - with);
    }

    integer_tr auto Access_Multiply(const volatile integer_tr auto& atom, to_integer_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        return static_cast<atom_t>(Access(atom) * static_cast<atom_t>(with));
    }

    real_tr auto Access_Multiply(const volatile real_tr auto& atom, to_real_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        return static_cast<atom_t>(Access(atom) * static_cast<atom_t>(with));
    }

    integer_tr auto Access_Divide(const volatile integer_tr auto& atom, to_integer_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        return static_cast<atom_t>(Access(atom) / static_cast<atom_t>(with));
    }

    real_tr auto Access_Divide(const volatile real_tr auto& atom, to_real_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        return static_cast<atom_t>(Access(atom) / static_cast<atom_t>(with));
    }

    integer_tr auto Access_Modulus(const volatile integer_tr auto& atom, integer_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        return static_cast<atom_t>(Access(atom) % with);
    }

    inline integer_tr auto Access_Or(const volatile integer_tr auto& atom, integer_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        return static_cast<atom_t>(Access(atom) | with);
    }

    inline integer_tr auto Access_And(const volatile integer_tr auto& atom, integer_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        return static_cast<atom_t>(Access(atom) & with);
    }

    inline integer_tr auto Access_Xor(const volatile integer_tr auto& atom, integer_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        return static_cast<atom_t>(Access(atom) ^ with);
    }

    inline integer_tr auto Access_Left_Shift(const volatile integer_tr auto& atom, integer_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        return static_cast<atom_t>(Access(atom) << with);
    }

    inline integer_tr auto Access_Right_Shift(const volatile integer_tr auto& atom, integer_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        return static_cast<atom_t>(Access(atom) >> with);
    }

    inline boolean_tr auto Assign(volatile boolean_tr auto& atom, to_boolean_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        return static_cast<atom_t>(Exchange(atom, with), static_cast<atom_t>(with));
    }

    inline integer_tr auto Assign(volatile integer_tr auto& atom, to_integer_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        return static_cast<atom_t>(Exchange(atom, with), static_cast<atom_t>(with));
    }

    inline real_tr auto Assign(volatile real_tr auto& atom, to_real_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        return static_cast<atom_t>(Exchange(atom, with), static_cast<atom_t>(with));
    }

    inline pointer_tr auto Assign(volatile pointer_tr auto& atom, pointer_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        return static_cast<atom_t>(Exchange(atom, with), with);
    }

    inline integer_tr auto Assign_Add(volatile integer_tr auto& atom, to_integer_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        return static_cast<atom_t>(Exchange_Add(atom, with) + static_cast<atom_t>(with));
    }

    inline real_tr auto Assign_Add(volatile real_tr auto& atom, to_real_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        return static_cast<atom_t>(Exchange_Add(atom, with) + static_cast<atom_t>(with));
    }

    inline type_pointer_tr auto Assign_Add(volatile type_pointer_tr auto& atom, integer_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        return static_cast<atom_t>(Exchange_Add(atom, with) + with);
    }

    inline integer_tr auto Assign_Subtract(volatile integer_tr auto& atom, to_integer_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        return static_cast<atom_t>(Exchange_Subtract(atom, with) - static_cast<atom_t>(with));
    }

    inline real_tr auto Assign_Subtract(volatile real_tr auto& atom, to_real_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        return static_cast<atom_t>(Exchange_Subtract(atom, with) - static_cast<atom_t>(with));
    }

    inline type_pointer_tr auto Assign_Subtract(volatile type_pointer_tr auto& atom, integer_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        return static_cast<atom_t>(Exchange_Subtract(atom, with) - with);
    }

    integer_tr auto Assign_Multiply(volatile integer_tr auto& atom, to_integer_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        return static_cast<atom_t>(Exchange_Multiply(atom, with) * static_cast<atom_t>(with));
    }

    real_tr auto Assign_Multiply(volatile real_tr auto& atom, to_real_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        return static_cast<atom_t>(Exchange_Multiply(atom, with) * static_cast<atom_t>(with));
    }

    integer_tr auto Assign_Divide(volatile integer_tr auto& atom, to_integer_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        return static_cast<atom_t>(Exchange_Divide(atom, with) / static_cast<atom_t>(with));
    }

    real_tr auto Assign_Divide(volatile real_tr auto& atom, to_real_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        return static_cast<atom_t>(Exchange_Divide(atom, with) / static_cast<atom_t>(with));
    }

    integer_tr auto Assign_Modulus(volatile integer_tr auto& atom, integer_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        return static_cast<atom_t>(Exchange_Modulus(atom, with) % with);
    }

    inline integer_tr auto Assign_Or(volatile integer_tr auto& atom, integer_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        return static_cast<atom_t>(Exchange_Or(atom, with) | with);
    }

    inline integer_tr auto Assign_And(volatile integer_tr auto& atom, integer_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        return static_cast<atom_t>(Exchange_And(atom, with) & with);
    }

    inline integer_tr auto Assign_Xor(volatile integer_tr auto& atom, integer_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        return static_cast<atom_t>(Exchange_Xor(atom, with) ^ with);
    }

    integer_tr auto Assign_Left_Shift(volatile integer_tr auto& atom, integer_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        return static_cast<atom_t>(Exchange_Left_Shift(atom, with) << with);
    }

    integer_tr auto Assign_Right_Shift(volatile integer_tr auto& atom, integer_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        return static_cast<atom_t>(Exchange_Right_Shift(atom, with) >> with);
    }

#if defined(nkr_IS_WINDOWS)

    inline boolean_tr auto Exchange(volatile boolean_tr auto& atom, to_boolean_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        atom_t atom_with = static_cast<atom_t>(with);
        if constexpr (std::same_as<atom_t, bool_t>) {
            return static_cast<atom_t>(Exchange(static_cast<volatile word_t&>(atom),
                                                static_cast<word_t>(atom_with)));
        } else if constexpr (sizeof(atom_t) == sizeof(u8_t)) {
            return static_cast<atom_t>(Exchange(reinterpret_cast<volatile u8_t&>(atom),
                                                reinterpret_cast<u8_t&>(atom_with)));
        } else {
            static_assert(false, "invalid boolean type size");
        }
    }

    inline integer_8_tr auto Exchange(volatile integer_8_tr auto& atom, to_integer_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        atom_t atom_with = static_cast<atom_t>(with);
        return static_cast<atom_t>(::_InterlockedExchange8(reinterpret_cast<volatile char*>(&atom),
                                                           static_cast<char>(atom_with)));
    }

    inline integer_16_tr auto Exchange(volatile integer_16_tr auto& atom, to_integer_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        atom_t atom_with = static_cast<atom_t>(with);
        return static_cast<atom_t>(::_InterlockedExchange16(reinterpret_cast<volatile short*>(&atom),
                                                            static_cast<short>(atom_with)));
    }

    inline integer_32_tr auto Exchange(volatile integer_32_tr auto& atom, to_integer_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        atom_t atom_with = static_cast<atom_t>(with);
        return static_cast<atom_t>(::_InterlockedExchange(reinterpret_cast<volatile long*>(&atom),
                                                          static_cast<long>(atom_with)));
    }

    inline integer_64_tr auto Exchange(volatile integer_64_tr auto& atom, to_integer_tr auto with)
    {
    #if defined(nkr_IS_64_BIT)
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        atom_t atom_with = static_cast<atom_t>(with);
        return static_cast<atom_t>(::_InterlockedExchange64(reinterpret_cast<volatile long long*>(&atom),
                                                            static_cast<long long>(atom_with)));
    #else
        static_assert(false, "64 bit atomic unavailable");
    #endif
    }

    inline real_32_tr auto Exchange(volatile real_32_tr auto& atom, to_real_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        atom_t atom_with = static_cast<atom_t>(with);
        u32_t u32_result = Exchange(reinterpret_cast<volatile u32_t&>(atom),
                                    reinterpret_cast<u32_t&>(atom_with));
        return reinterpret_cast<atom_t&>(u32_result);
    }

    inline real_64_tr auto Exchange(volatile real_64_tr auto& atom, to_real_tr auto with)
    {
    #if defined(nkr_IS_64_BIT)
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        atom_t atom_with = static_cast<atom_t>(with);
        u64_t u64_result = Exchange(reinterpret_cast<volatile u64_t&>(atom),
                                    reinterpret_cast<u64_t&>(atom_with));
        return reinterpret_cast<atom_t&>(u64_result);
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

    inline integer_8_tr auto Exchange_Add(volatile integer_8_tr auto& atom, to_integer_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        atom_t atom_with = static_cast<atom_t>(with);
        return static_cast<atom_t>(::_InterlockedExchangeAdd8(reinterpret_cast<volatile char*>(&atom),
                                                              static_cast<char>(atom_with)));
    }

    inline integer_16_tr auto Exchange_Add(volatile integer_16_tr auto& atom, to_integer_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        atom_t atom_with = static_cast<atom_t>(with);
        return static_cast<atom_t>(::_InterlockedExchangeAdd16(reinterpret_cast<volatile short*>(&atom),
                                                               static_cast<short>(atom_with)));
    }

    inline integer_32_tr auto Exchange_Add(volatile integer_32_tr auto& atom, to_integer_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        atom_t atom_with = static_cast<atom_t>(with);
        return static_cast<atom_t>(::_InterlockedExchangeAdd(reinterpret_cast<volatile long*>(&atom),
                                                             static_cast<long>(atom_with)));
    }

    inline integer_64_tr auto Exchange_Add(volatile integer_64_tr auto& atom, to_integer_tr auto with)
    {
    #if defined(nkr_IS_64_BIT)
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        atom_t atom_with = static_cast<atom_t>(with);
        return static_cast<atom_t>(::_InterlockedExchangeAdd64(reinterpret_cast<volatile long long*>(&atom),
                                                               static_cast<long long>(atom_with)));
    #else
        static_assert(false, "64 bit atomic unavailable");
    #endif
    }

    inline real_32_tr auto Exchange_Add(volatile real_32_tr auto& atom, to_real_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        atom_t snapshot = Access(atom);
        while (!Exchange_If_Equals(atom, snapshot, snapshot + static_cast<atom_t>(with)));
        return snapshot;
    }

    inline real_64_tr auto Exchange_Add(volatile real_64_tr auto& atom, to_real_tr auto with)
    {
    #if defined(nkr_IS_64_BIT)
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        atom_t snapshot = Access(atom);
        while (!Exchange_If_Equals(atom, snapshot, snapshot + static_cast<atom_t>(with)));
        return snapshot;
    #else
        static_assert(false, "64 bit atomic unavailable");
    #endif
    }

    inline type_pointer_tr auto Exchange_Add(volatile type_pointer_tr auto& atom, integer_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        return reinterpret_cast<atom_t>(Exchange_Add(reinterpret_cast<volatile address_t&>(atom),
                                                     sizeof(std::remove_pointer_t<atom_t>) * with));
    }

    inline integer_8_tr auto Exchange_Subtract(volatile integer_8_tr auto& atom, to_integer_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        atom_t atom_with = static_cast<atom_t>(with);
        return static_cast<atom_t>(::_InterlockedExchangeAdd8(reinterpret_cast<volatile char*>(&atom),
                                                              -static_cast<char>(atom_with)));
    }

    inline integer_16_tr auto Exchange_Subtract(volatile integer_16_tr auto& atom, to_integer_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        atom_t atom_with = static_cast<atom_t>(with);
        return static_cast<atom_t>(::_InterlockedExchangeAdd16(reinterpret_cast<volatile short*>(&atom),
                                                               -static_cast<short>(atom_with)));
    }

    inline integer_32_tr auto Exchange_Subtract(volatile integer_32_tr auto& atom, to_integer_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        atom_t atom_with = static_cast<atom_t>(with);
        return static_cast<atom_t>(::_InterlockedExchangeAdd(reinterpret_cast<volatile long*>(&atom),
                                                             -static_cast<long>(atom_with)));
    }

    inline integer_64_tr auto Exchange_Subtract(volatile integer_64_tr auto& atom, to_integer_tr auto with)
    {
    #if defined(nkr_IS_64_BIT)
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        atom_t atom_with = static_cast<atom_t>(with);
        return static_cast<atom_t>(::_InterlockedExchangeAdd64(reinterpret_cast<volatile long long*>(&atom),
                                                               -static_cast<long long>(atom_with)));
    #else
        static_assert(false, "64 bit atomic unavailable");
    #endif
    }

    inline real_32_tr auto Exchange_Subtract(volatile real_32_tr auto& atom, to_real_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        atom_t snapshot = Access(atom);
        while (!Exchange_If_Equals(atom, snapshot, snapshot - static_cast<atom_t>(with)));
        return snapshot;
    }

    inline real_64_tr auto Exchange_Subtract(volatile real_64_tr auto& atom, to_real_tr auto with)
    {
    #if defined(nkr_IS_64_BIT)
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        atom_t snapshot = Access(atom);
        while (!Exchange_If_Equals(atom, snapshot, snapshot - static_cast<atom_t>(with)));
        return snapshot;
    #else
        static_assert(false, "64 bit atomic unavailable");
    #endif
    }

    inline type_pointer_tr auto Exchange_Subtract(volatile type_pointer_tr auto& atom, integer_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        return reinterpret_cast<atom_t>(Exchange_Subtract(reinterpret_cast<volatile address_t&>(atom),
                                                          sizeof(std::remove_pointer_t<atom_t>) * with));
    }

    inline integer_8_tr auto Exchange_Multiply(volatile integer_8_tr auto& atom, to_integer_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        atom_t snapshot = Access(atom);
        while (!Exchange_If_Equals(atom, snapshot, snapshot * static_cast<atom_t>(with)));
        return snapshot;
    }

    inline integer_16_tr auto Exchange_Multiply(volatile integer_16_tr auto& atom, to_integer_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        atom_t snapshot = Access(atom);
        while (!Exchange_If_Equals(atom, snapshot, snapshot * static_cast<atom_t>(with)));
        return snapshot;
    }

    inline integer_32_tr auto Exchange_Multiply(volatile integer_32_tr auto& atom, to_integer_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        atom_t snapshot = Access(atom);
        while (!Exchange_If_Equals(atom, snapshot, snapshot * static_cast<atom_t>(with)));
        return snapshot;
    }

    inline integer_64_tr auto Exchange_Multiply(volatile integer_64_tr auto& atom, to_integer_tr auto with)
    {
    #if defined(nkr_IS_64_BIT)
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        atom_t snapshot = Access(atom);
        while (!Exchange_If_Equals(atom, snapshot, snapshot * static_cast<atom_t>(with)));
        return snapshot;
    #else
        static_assert(false, "64 bit atomic unavailable");
    #endif
    }

    inline real_32_tr auto Exchange_Multiply(volatile real_32_tr auto& atom, to_real_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        atom_t snapshot = Access(atom);
        while (!Exchange_If_Equals(atom, snapshot, snapshot * static_cast<atom_t>(with)));
        return snapshot;
    }

    inline real_64_tr auto Exchange_Multiply(volatile real_64_tr auto& atom, to_real_tr auto with)
    {
    #if defined(nkr_IS_64_BIT)
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        atom_t snapshot = Access(atom);
        while (!Exchange_If_Equals(atom, snapshot, snapshot * static_cast<atom_t>(with)));
        return snapshot;
    #else
        static_assert(false, "64 bit atomic unavailable");
    #endif
    }

    inline integer_8_tr auto Exchange_Divide(volatile integer_8_tr auto& atom, to_integer_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        atom_t snapshot = Access(atom);
        while (!Exchange_If_Equals(atom, snapshot, snapshot / static_cast<atom_t>(with)));
        return snapshot;
    }

    inline integer_16_tr auto Exchange_Divide(volatile integer_16_tr auto& atom, to_integer_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        atom_t snapshot = Access(atom);
        while (!Exchange_If_Equals(atom, snapshot, snapshot / static_cast<atom_t>(with)));
        return snapshot;
    }

    inline integer_32_tr auto Exchange_Divide(volatile integer_32_tr auto& atom, to_integer_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        atom_t snapshot = Access(atom);
        while (!Exchange_If_Equals(atom, snapshot, snapshot / static_cast<atom_t>(with)));
        return snapshot;
    }

    inline integer_64_tr auto Exchange_Divide(volatile integer_64_tr auto& atom, to_integer_tr auto with)
    {
    #if defined(nkr_IS_64_BIT)
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        atom_t snapshot = Access(atom);
        while (!Exchange_If_Equals(atom, snapshot, snapshot / static_cast<atom_t>(with)));
        return snapshot;
    #else
        static_assert(false, "64 bit atomic unavailable");
    #endif
    }

    inline real_32_tr auto Exchange_Divide(volatile real_32_tr auto& atom, to_real_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        atom_t snapshot = Access(atom);
        while (!Exchange_If_Equals(atom, snapshot, snapshot / static_cast<atom_t>(with)));
        return snapshot;
    }

    inline real_64_tr auto Exchange_Divide(volatile real_64_tr auto& atom, to_real_tr auto with)
    {
    #if defined(nkr_IS_64_BIT)
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        atom_t snapshot = Access(atom);
        while (!Exchange_If_Equals(atom, snapshot, snapshot / static_cast<atom_t>(with)));
        return snapshot;
    #else
        static_assert(false, "64 bit atomic unavailable");
    #endif
    }

    inline integer_8_tr auto Exchange_Modulus(volatile integer_8_tr auto& atom, integer_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        atom_t snapshot = Access(atom);
        while (!Exchange_If_Equals(atom, snapshot, snapshot % static_cast<atom_t>(with)));
        return snapshot;
    }

    inline integer_16_tr auto Exchange_Modulus(volatile integer_16_tr auto& atom, integer_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        atom_t snapshot = Access(atom);
        while (!Exchange_If_Equals(atom, snapshot, snapshot % static_cast<atom_t>(with)));
        return snapshot;
    }

    inline integer_32_tr auto Exchange_Modulus(volatile integer_32_tr auto& atom, integer_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        atom_t snapshot = Access(atom);
        while (!Exchange_If_Equals(atom, snapshot, snapshot % static_cast<atom_t>(with)));
        return snapshot;
    }

    inline integer_64_tr auto Exchange_Modulus(volatile integer_64_tr auto& atom, integer_tr auto with)
    {
    #if defined(nkr_IS_64_BIT)
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        atom_t snapshot = Access(atom);
        while (!Exchange_If_Equals(atom, snapshot, snapshot % static_cast<atom_t>(with)));
        return snapshot;
    #else
        static_assert(false, "64 bit atomic unavailable");
    #endif
    }

    inline integer_8_tr auto Exchange_Or(volatile integer_8_tr auto& atom, integer_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

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

    inline integer_8_tr auto Exchange_Left_Shift(volatile integer_8_tr auto& atom, integer_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        atom_t snapshot = Access(atom);
        while (!Exchange_If_Equals(atom, snapshot, snapshot << static_cast<atom_t>(with)));
        return snapshot;
    }

    inline integer_16_tr auto Exchange_Left_Shift(volatile integer_16_tr auto& atom, integer_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        atom_t snapshot = Access(atom);
        while (!Exchange_If_Equals(atom, snapshot, snapshot << static_cast<atom_t>(with)));
        return snapshot;
    }

    inline integer_32_tr auto Exchange_Left_Shift(volatile integer_32_tr auto& atom, integer_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        atom_t snapshot = Access(atom);
        while (!Exchange_If_Equals(atom, snapshot, snapshot << static_cast<atom_t>(with)));
        return snapshot;
    }

    inline integer_64_tr auto Exchange_Left_Shift(volatile integer_64_tr auto& atom, integer_tr auto with)
    {
    #if defined(nkr_IS_64_BIT)
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        atom_t snapshot = Access(atom);
        while (!Exchange_If_Equals(atom, snapshot, snapshot << static_cast<atom_t>(with)));
        return snapshot;
    #else
        static_assert(false, "64 bit atomic unavailable");
    #endif
    }

    inline integer_8_tr auto Exchange_Right_Shift(volatile integer_8_tr auto& atom, integer_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        atom_t snapshot = Access(atom);
        while (!Exchange_If_Equals(atom, snapshot, snapshot >> static_cast<atom_t>(with)));
        return snapshot;
    }

    inline integer_16_tr auto Exchange_Right_Shift(volatile integer_16_tr auto& atom, integer_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        atom_t snapshot = Access(atom);
        while (!Exchange_If_Equals(atom, snapshot, snapshot >> static_cast<atom_t>(with)));
        return snapshot;
    }

    inline integer_32_tr auto Exchange_Right_Shift(volatile integer_32_tr auto& atom, integer_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        atom_t snapshot = Access(atom);
        while (!Exchange_If_Equals(atom, snapshot, snapshot >> static_cast<atom_t>(with)));
        return snapshot;
    }

    inline integer_64_tr auto Exchange_Right_Shift(volatile integer_64_tr auto& atom, integer_tr auto with)
    {
    #if defined(nkr_IS_64_BIT)
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        atom_t snapshot = Access(atom);
        while (!Exchange_If_Equals(atom, snapshot, snapshot >> static_cast<atom_t>(with)));
        return snapshot;
    #else
        static_assert(false, "64 bit atomic unavailable");
    #endif
    }

    inline boolean_tr auto Exchange_If_Equals(volatile boolean_tr auto& atom,
                                              boolean_tr auto& snapshot,
                                              to_boolean_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        atom_t atom_with = static_cast<atom_t>(with);
        if constexpr (std::same_as<atom_t, bool_t>) {
            return Exchange_If_Equals(static_cast<volatile word_t&>(atom),
                                      static_cast<word_t&>(snapshot),
                                      static_cast<word_t>(atom_with));
        } else if constexpr (sizeof(atom_t) == sizeof(u8_t)) {
            return Exchange_If_Equals(reinterpret_cast<volatile u8_t&>(atom),
                                      reinterpret_cast<u8_t&>(snapshot),
                                      reinterpret_cast<u8_t&>(atom_with));
        } else {
            static_assert(false, "invalid boolean type size");
        }
    }

    inline boolean_tr auto Exchange_If_Equals(volatile integer_8_tr auto& atom,
                                              integer_8_tr auto& snapshot,
                                              to_integer_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        atom_t atom_with = static_cast<atom_t>(with);
        atom_t value = static_cast<atom_t>(::_InterlockedCompareExchange8((volatile char*)(&atom),
                                                                          static_cast<char>(atom_with),
                                                                          static_cast<char>(snapshot)));
        if (snapshot == value) {
            return true;
        } else {
            snapshot = value;
            return false;
        }
    }

    inline boolean_tr auto Exchange_If_Equals(volatile integer_16_tr auto& atom,
                                              integer_16_tr auto& snapshot,
                                              to_integer_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        atom_t atom_with = static_cast<atom_t>(with);
        atom_t value = static_cast<atom_t>(::_InterlockedCompareExchange16(reinterpret_cast<volatile short*>(&atom),
                                                                           static_cast<short>(atom_with),
                                                                           static_cast<short>(snapshot)));
        if (snapshot == value) {
            return true;
        } else {
            snapshot = value;
            return false;
        }
    }

    inline boolean_tr auto Exchange_If_Equals(volatile integer_32_tr auto& atom,
                                              integer_32_tr auto& snapshot,
                                              to_integer_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        atom_t atom_with = static_cast<atom_t>(with);
        atom_t value = static_cast<atom_t>(::_InterlockedCompareExchange(reinterpret_cast<volatile long*>(&atom),
                                                                         static_cast<long>(atom_with),
                                                                         static_cast<long>(snapshot)));
        if (snapshot == value) {
            return true;
        } else {
            snapshot = value;
            return false;
        }
    }

    inline boolean_tr auto Exchange_If_Equals(volatile integer_64_tr auto& atom,
                                              integer_64_tr auto& snapshot,
                                              to_integer_tr auto with)
    {
    #if defined(nkr_IS_64_BIT)
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        atom_t atom_with = static_cast<atom_t>(with);
        atom_t value = static_cast<atom_t>(::_InterlockedCompareExchange64(reinterpret_cast<volatile long long*>(&atom),
                                                                           static_cast<long long>(atom_with),
                                                                           static_cast<long long>(snapshot)));
        if (snapshot == value) {
            return true;
        } else {
            snapshot = value;
            return false;
        }
    #else
        static_assert(false, "64 bit atomic unavailable");
    #endif
    }

    inline boolean_tr auto Exchange_If_Equals(volatile real_32_tr auto& atom,
                                              real_32_tr auto& snapshot,
                                              to_real_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        atom_t atom_with = static_cast<atom_t>(with);
        return Exchange_If_Equals(reinterpret_cast<volatile u32_t&>(atom),
                                  reinterpret_cast<u32_t&>(snapshot),
                                  reinterpret_cast<u32_t&>(atom_with));
    }

    inline boolean_tr auto Exchange_If_Equals(volatile real_64_tr auto& atom,
                                              real_64_tr auto& snapshot,
                                              to_real_tr auto with)
    {
    #if defined(nkr_IS_64_BIT)
        using atom_t = std::remove_cvref_t<decltype(atom)>;

        atom_t atom_with = static_cast<atom_t>(with);
        return Exchange_If_Equals(reinterpret_cast<volatile u64_t&>(atom),
                                  reinterpret_cast<u64_t&>(snapshot),
                                  reinterpret_cast<u64_t&>(atom_with));
    #else
        static_assert(false, "64 bit atomic unavailable");
    #endif
    }

    inline boolean_tr auto Exchange_If_Equals(volatile pointer_tr auto& atom,
                                              pointer_tr auto& snapshot,
                                              pointer_tr auto with)
    {
        using atom_t = std::remove_cvref_t<decltype(atom)>;
        using snapshot_t = std::remove_cvref_t<decltype(snapshot)>;
        using with_t = std::remove_cvref_t<decltype(with)>;

        static_assert(std::is_convertible<snapshot_t, atom_t>::value,
                      "'snapshot' should be convertible to 'atom'.");
        static_assert(std::is_convertible<with_t, atom_t>::value,
                      "'with' should be convertible to 'atom'.");

        atom_t value = static_cast<atom_t>(::_InterlockedCompareExchangePointer(reinterpret_cast<void* volatile*>(&atom),
                                                                                static_cast<void*>(with),
                                                                                static_cast<void*>(snapshot)));
        if (snapshot == value) {
            return true;
        } else {
            snapshot = value;
            return false;
        }
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

namespace nkr { namespace os { namespace heap {

#if defined(nkr_IS_WINDOWS)

    // since C++11 using errno is thread-safe.
    
    // most of these calls are standard, but we're currently wrapping them
    // until I know for sure that we don't need to handle them differently,
    // on other systems.

    inline bool_t Allocate(type_tr auto*& units, count_t unit_count)
    {
        using units_t = std::remove_reference_t<decltype(units)>;
        using unit_t = std::remove_pointer_t<units_t>;

        assert(unit_count > 0);
        assert(unit_count <= std::numeric_limits<count_t>::max() / sizeof(unit_t));

        errno = 0;
        units = static_cast<units_t>(::malloc(unit_count * sizeof(unit_t)));
        if (errno == 0) {
            return true;
        } else {
            units = nullptr;
            return false;
        }
    }

    inline bool_t Reallocate(type_tr auto*& units, count_t new_unit_count)
    {
        using units_t = std::remove_reference_t<decltype(units)>;
        using unit_t = std::remove_pointer_t<units_t>;

        assert(new_unit_count > 0);
        assert(new_unit_count <= std::numeric_limits<count_t>::max() / sizeof(unit_t));

        errno = 0;
        units_t new_units = static_cast<units_t>(::realloc(units, new_unit_count * sizeof(unit_t)));
        if (errno == 0) {
            units = new_units;
            return true;
        } else {
            return false;
        }
    }

    inline void_t Deallocate(type_tr auto*& units)
    {
        if (units != nullptr) {
            ::free(units);
            units = nullptr;
        }
    }

    inline bool_t Allocate_Zeros(type_tr auto*& units, count_t unit_count)
    {
        using units_t = std::remove_reference_t<decltype(units)>;
        using unit_t = std::remove_pointer_t<units_t>;

        assert(unit_count > 0);
        assert(unit_count <= std::numeric_limits<count_t>::max() / sizeof(unit_t));

        errno = 0;
        units = static_cast<units_t>(::calloc(unit_count, sizeof(unit_t)));
        if (errno == 0) {
            return true;
        } else {
            units = nullptr;
            return false;
        }
    }

    inline bool_t Reallocate_Zeros(type_tr auto*& units, count_t new_unit_count)
    {
        using units_t = std::remove_reference_t<decltype(units)>;
        using unit_t = std::remove_pointer_t<units_t>;

        assert(new_unit_count > 0);
        assert(new_unit_count <= std::numeric_limits<count_t>::max() / sizeof(unit_t));

        errno = 0;
        units_t new_units = static_cast<units_t>(::_recalloc(units, new_unit_count, sizeof(unit_t)));
        if (errno == 0) {
            units = new_units;
            return true;
        } else {
            return false;
        }
    }

    inline void_t Deallocate_Zeros(type_tr auto*& units)
    {
        return Deallocate(units);
    }

#endif

}}}
