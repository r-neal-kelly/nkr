/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include <mutex>

#include "nkr/fors.h"
#include "nkr/macros.h"
#include "nkr/os.h"

#if defined(nkr_IS_WINDOWS)
    #include <intrin.h>
#endif

namespace nkr { namespace os { namespace atomic {

    template <boolean_tr atom_p>
    inline atom_p Access(const volatile atom_p& atom)
    {
        atom_p snapshot = atom_p();
        Exchange_If_Equals(const_cast<volatile std::remove_cvref_t<decltype(atom)>&>(atom), snapshot, atom_p());
        return snapshot;
    }

    template <integer_tr atom_p>
    inline atom_p Access(const volatile atom_p& atom)
    {
        atom_p snapshot = atom_p();
        Exchange_If_Equals(const_cast<volatile std::remove_cvref_t<decltype(atom)>&>(atom), snapshot, atom_p());
        return snapshot;
    }

    template <real_tr atom_p>
    inline atom_p Access(const volatile atom_p& atom)
    {
        atom_p snapshot = atom_p();
        Exchange_If_Equals(const_cast<volatile std::remove_cvref_t<decltype(atom)>&>(atom), snapshot, atom_p());
        return snapshot;
    }

    template <pointer_tr atom_p>
    inline atom_p Access(const volatile atom_p& atom)
    {
        atom_p snapshot = atom_p();
        Exchange_If_Equals(const_cast<volatile std::remove_cvref_t<decltype(atom)>&>(atom), snapshot, atom_p());
        return snapshot;
    }

    template <boolean_tr atom_p, convertible_tr<atom_p> value_p>
    inline atom_p Assign(volatile atom_p& atom, value_p with)
    {
        return Exchange(atom, with), static_cast<atom_p>(with);
    }

    template <integer_tr atom_p, convertible_tr<atom_p> value_p>
    inline atom_p Assign(volatile atom_p& atom, value_p with)
    {
        return Exchange(atom, with), static_cast<atom_p>(with);
    }

    template <real_tr atom_p, convertible_tr<atom_p> value_p>
    inline atom_p Assign(volatile atom_p& atom, value_p with)
    {
        return Exchange(atom, with), static_cast<atom_p>(with);
    }

    template <pointer_tr atom_p, convertible_tr<atom_p> value_p>
    inline atom_p Assign(volatile atom_p& atom, value_p with)
    {
        return Exchange(atom, with), static_cast<atom_p>(with);
    }

    template <integer_tr atom_p, convertible_tr<atom_p> value_p>
    inline atom_p Assign_Add(volatile atom_p& atom, value_p with)
    {
        return Exchange_Add(atom, with) + static_cast<atom_p>(with);
    }

    template <real_tr atom_p, convertible_tr<atom_p> value_p>
    inline atom_p Assign_Add(volatile atom_p& atom, value_p with)
    {
        return Exchange_Add(atom, with) + static_cast<atom_p>(with);
    }

    template <type_pointer_tr atom_p, integer_tr value_p>
    inline atom_p Assign_Add(volatile atom_p& atom, value_p with)
    {
        return Exchange_Add(atom, with) + with;
    }

    template <integer_tr atom_p, convertible_tr<atom_p> value_p>
    inline atom_p Assign_Subtract(volatile atom_p& atom, value_p with)
    {
        return Exchange_Subtract(atom, with) - static_cast<atom_p>(with);
    }

    template <real_tr atom_p, convertible_tr<atom_p> value_p>
    inline atom_p Assign_Subtract(volatile atom_p& atom, value_p with)
    {
        return Exchange_Subtract(atom, with) - static_cast<atom_p>(with);
    }

    template <type_pointer_tr atom_p, integer_tr value_p>
    inline atom_p Assign_Subtract(volatile atom_p& atom, value_p with)
    {
        return Exchange_Subtract(atom, with) - with;
    }

    template <integer_tr atom_p, convertible_tr<atom_p> value_p>
    inline atom_p Assign_Multiply(volatile atom_p& atom, value_p with)
    {
        return Exchange_Multiply(atom, with) * static_cast<atom_p>(with);
    }

    template <real_tr atom_p, convertible_tr<atom_p> value_p>
    inline atom_p Assign_Multiply(volatile atom_p& atom, value_p with)
    {
        return Exchange_Multiply(atom, with) * static_cast<atom_p>(with);
    }

    template <integer_tr atom_p, convertible_tr<atom_p> value_p>
    inline atom_p Assign_Divide(volatile atom_p& atom, value_p with)
    {
        return Exchange_Divide(atom, with) / static_cast<atom_p>(with);
    }

    template <real_tr atom_p, convertible_tr<atom_p> value_p>
    inline atom_p Assign_Divide(volatile atom_p& atom, value_p with)
    {
        return Exchange_Divide(atom, with) / static_cast<atom_p>(with);
    }

    template <integer_tr atom_p, integer_tr value_p>
    inline atom_p Assign_Modulus(volatile atom_p& atom, value_p with)
    {
        return Exchange_Modulus(atom, with) % static_cast<atom_p>(with);
    }

    template <integer_tr atom_p, integer_tr value_p>
    inline atom_p Assign_Or(volatile atom_p& atom, value_p with)
    {
        return Exchange_Or(atom, with) | static_cast<atom_p>(with);
    }

    template <integer_tr atom_p, integer_tr value_p>
    inline atom_p Assign_And(volatile atom_p& atom, value_p with)
    {
        return Exchange_And(atom, with) & static_cast<atom_p>(with);
    }

    template <integer_tr atom_p, integer_tr value_p>
    inline atom_p Assign_Xor(volatile atom_p& atom, value_p with)
    {
        return Exchange_Xor(atom, with) ^ static_cast<atom_p>(with);
    }

    template <integer_tr atom_p, integer_tr value_p>
    inline atom_p Assign_Left_Shift(volatile atom_p& atom, value_p with)
    {
        return Exchange_Left_Shift(atom, with) << static_cast<atom_p>(with);
    }

    template <integer_tr atom_p, integer_tr value_p>
    inline atom_p Assign_Right_Shift(volatile atom_p& atom, value_p with)
    {
        return Exchange_Right_Shift(atom, with) >> static_cast<atom_p>(with);
    }

#if defined(nkr_IS_WINDOWS)

    template <boolean_tr atom_p, convertible_tr<atom_p> value_p>
    inline atom_p Exchange(volatile atom_p& atom, value_p with)
    {
        atom_p atom_with = static_cast<atom_p>(with);
        if constexpr (std::same_as<atom_p, bool_t>) {
            return static_cast<atom_p>(Exchange(static_cast<volatile word_t&>(atom),
                                                static_cast<word_t>(atom_with)));
        } else {
            using integer_unsigned_t = integer_unsigned_for_t<atom_p>;

            return static_cast<atom_p>(Exchange(reinterpret_cast<volatile integer_unsigned_t&>(atom),
                                                reinterpret_cast<integer_unsigned_t&>(atom_with)));
        }
    }

    template <integer_8_tr atom_p, convertible_tr<atom_p> value_p>
    inline atom_p Exchange(volatile atom_p& atom, value_p with)
    {
        atom_p atom_with = static_cast<atom_p>(with);
        return static_cast<atom_p>(::_InterlockedExchange8(reinterpret_cast<volatile char*>(&atom),
                                                           static_cast<char>(atom_with)));
    }

    template <integer_16_tr atom_p, convertible_tr<atom_p> value_p>
    inline atom_p Exchange(volatile atom_p& atom, value_p with)
    {
        atom_p atom_with = static_cast<atom_p>(with);
        return static_cast<atom_p>(::_InterlockedExchange16(reinterpret_cast<volatile short*>(&atom),
                                                            static_cast<short>(atom_with)));
    }

    template <integer_32_tr atom_p, convertible_tr<atom_p> value_p>
    inline atom_p Exchange(volatile atom_p& atom, value_p with)
    {
        atom_p atom_with = static_cast<atom_p>(with);
        return static_cast<atom_p>(::_InterlockedExchange(reinterpret_cast<volatile long*>(&atom),
                                                          static_cast<long>(atom_with)));
    }

    template <integer_64_tr atom_p, convertible_tr<atom_p> value_p>
    inline atom_p Exchange(volatile atom_p& atom, value_p with)
    {
    #if defined(nkr_IS_64_BIT)
        atom_p atom_with = static_cast<atom_p>(with);
        return static_cast<atom_p>(::_InterlockedExchange64(reinterpret_cast<volatile long long*>(&atom),
                                                            static_cast<long long>(atom_with)));
    #else
        static_assert(false, "64 bit atomic unavailable");
    #endif
    }

    template <real_32_tr atom_p, convertible_tr<atom_p> value_p>
    inline atom_p Exchange(volatile atom_p& atom, value_p with)
    {
        atom_p atom_with = static_cast<atom_p>(with);
        u32_t u32_result = Exchange(reinterpret_cast<volatile u32_t&>(atom),
                                    reinterpret_cast<u32_t&>(atom_with));
        return reinterpret_cast<atom_p&>(u32_result);
    }

    template <real_64_tr atom_p, convertible_tr<atom_p> value_p>
    inline atom_p Exchange(volatile atom_p& atom, value_p with)
    {
    #if defined(nkr_IS_64_BIT)
        atom_p atom_with = static_cast<atom_p>(with);
        u64_t u64_result = Exchange(reinterpret_cast<volatile u64_t&>(atom),
                                    reinterpret_cast<u64_t&>(atom_with));
        return reinterpret_cast<atom_p&>(u64_result);
    #else
        static_assert(false, "64 bit atomic unavailable");
    #endif
    }

    template <pointer_tr atom_p, convertible_tr<atom_p> value_p>
    inline atom_p Exchange(volatile atom_p& atom, value_p with)
    {
        return static_cast<atom_p>(::_InterlockedExchangePointer(reinterpret_cast<void* volatile*>(&atom),
                                                                 static_cast<void*>(with)));
    }

    template <integer_8_tr atom_p, convertible_tr<atom_p> value_p>
    inline atom_p Exchange_Add(volatile atom_p& atom, value_p with)
    {
        atom_p atom_with = static_cast<atom_p>(with);
        return static_cast<atom_p>(::_InterlockedExchangeAdd8(reinterpret_cast<volatile char*>(&atom),
                                                              static_cast<char>(atom_with)));
    }

    template <integer_16_tr atom_p, convertible_tr<atom_p> value_p>
    inline atom_p Exchange_Add(volatile atom_p& atom, value_p with)
    {
        atom_p atom_with = static_cast<atom_p>(with);
        return static_cast<atom_p>(::_InterlockedExchangeAdd16(reinterpret_cast<volatile short*>(&atom),
                                                               static_cast<short>(atom_with)));
    }

    template <integer_32_tr atom_p, convertible_tr<atom_p> value_p>
    inline atom_p Exchange_Add(volatile atom_p& atom, value_p with)
    {
        atom_p atom_with = static_cast<atom_p>(with);
        return static_cast<atom_p>(::_InterlockedExchangeAdd(reinterpret_cast<volatile long*>(&atom),
                                                             static_cast<long>(atom_with)));
    }

    template <integer_64_tr atom_p, convertible_tr<atom_p> value_p>
    inline atom_p Exchange_Add(volatile atom_p& atom, value_p with)
    {
    #if defined(nkr_IS_64_BIT)
        atom_p atom_with = static_cast<atom_p>(with);
        return static_cast<atom_p>(::_InterlockedExchangeAdd64(reinterpret_cast<volatile long long*>(&atom),
                                                               static_cast<long long>(atom_with)));
    #else
        static_assert(false, "64 bit atomic unavailable");
    #endif
    }

    template <real_32_tr atom_p, convertible_tr<atom_p> value_p>
    inline atom_p Exchange_Add(volatile atom_p& atom, value_p with)
    {
        atom_p snapshot = Access(atom);
        while (!Exchange_If_Equals(atom, snapshot, snapshot + static_cast<atom_p>(with)));
        return snapshot;
    }

    template <real_64_tr atom_p, convertible_tr<atom_p> value_p>
    inline atom_p Exchange_Add(volatile atom_p& atom, value_p with)
    {
    #if defined(nkr_IS_64_BIT)
        atom_p snapshot = Access(atom);
        while (!Exchange_If_Equals(atom, snapshot, snapshot + static_cast<atom_p>(with)));
        return snapshot;
    #else
        static_assert(false, "64 bit atomic unavailable");
    #endif
    }

    template <type_pointer_tr atom_p, integer_tr value_p>
    inline atom_p Exchange_Add(volatile atom_p& atom, value_p with)
    {
        return reinterpret_cast<atom_p>(Exchange_Add(reinterpret_cast<volatile address_t&>(atom),
                                                     sizeof(std::remove_pointer_t<atom_p>) * with));
    }

    template <integer_8_tr atom_p, convertible_tr<atom_p> value_p>
    inline atom_p Exchange_Subtract(volatile atom_p& atom, value_p with)
    {
        atom_p atom_with = static_cast<atom_p>(with);
        return static_cast<atom_p>(::_InterlockedExchangeAdd8(reinterpret_cast<volatile char*>(&atom),
                                                              -static_cast<char>(atom_with)));
    }

    template <integer_16_tr atom_p, convertible_tr<atom_p> value_p>
    inline atom_p Exchange_Subtract(volatile atom_p& atom, value_p with)
    {
        atom_p atom_with = static_cast<atom_p>(with);
        return static_cast<atom_p>(::_InterlockedExchangeAdd16(reinterpret_cast<volatile short*>(&atom),
                                                               -static_cast<short>(atom_with)));
    }

    template <integer_32_tr atom_p, convertible_tr<atom_p> value_p>
    inline atom_p Exchange_Subtract(volatile atom_p& atom, value_p with)
    {
        atom_p atom_with = static_cast<atom_p>(with);
        return static_cast<atom_p>(::_InterlockedExchangeAdd(reinterpret_cast<volatile long*>(&atom),
                                                             -static_cast<long>(atom_with)));
    }

    template <integer_64_tr atom_p, convertible_tr<atom_p> value_p>
    inline atom_p Exchange_Subtract(volatile atom_p& atom, value_p with)
    {
    #if defined(nkr_IS_64_BIT)
        atom_p atom_with = static_cast<atom_p>(with);
        return static_cast<atom_p>(::_InterlockedExchangeAdd64(reinterpret_cast<volatile long long*>(&atom),
                                                               -static_cast<long long>(atom_with)));
    #else
        static_assert(false, "64 bit atomic unavailable");
    #endif
    }

    template <real_32_tr atom_p, convertible_tr<atom_p> value_p>
    inline atom_p Exchange_Subtract(volatile atom_p& atom, value_p with)
    {
        atom_p snapshot = Access(atom);
        while (!Exchange_If_Equals(atom, snapshot, snapshot - static_cast<atom_p>(with)));
        return snapshot;
    }

    template <real_64_tr atom_p, convertible_tr<atom_p> value_p>
    inline atom_p Exchange_Subtract(volatile atom_p& atom, value_p with)
    {
    #if defined(nkr_IS_64_BIT)
        atom_p snapshot = Access(atom);
        while (!Exchange_If_Equals(atom, snapshot, snapshot - static_cast<atom_p>(with)));
        return snapshot;
    #else
        static_assert(false, "64 bit atomic unavailable");
    #endif
    }

    template <type_pointer_tr atom_p, integer_tr value_p>
    inline atom_p Exchange_Subtract(volatile atom_p& atom, value_p with)
    {
        return reinterpret_cast<atom_p>(Exchange_Subtract(reinterpret_cast<volatile address_t&>(atom),
                                                          sizeof(std::remove_pointer_t<atom_p>) * with));
    }

    template <integer_8_tr atom_p, convertible_tr<atom_p> value_p>
    inline atom_p Exchange_Multiply(volatile atom_p& atom, value_p with)
    {
        atom_p snapshot = Access(atom);
        while (!Exchange_If_Equals(atom, snapshot, snapshot * static_cast<atom_p>(with)));
        return snapshot;
    }

    template <integer_16_tr atom_p, convertible_tr<atom_p> value_p>
    inline atom_p Exchange_Multiply(volatile atom_p& atom, value_p with)
    {
        atom_p snapshot = Access(atom);
        while (!Exchange_If_Equals(atom, snapshot, snapshot * static_cast<atom_p>(with)));
        return snapshot;
    }

    template <integer_32_tr atom_p, convertible_tr<atom_p> value_p>
    inline atom_p Exchange_Multiply(volatile atom_p& atom, value_p with)
    {
        atom_p snapshot = Access(atom);
        while (!Exchange_If_Equals(atom, snapshot, snapshot * static_cast<atom_p>(with)));
        return snapshot;
    }

    template <integer_64_tr atom_p, convertible_tr<atom_p> value_p>
    inline atom_p Exchange_Multiply(volatile atom_p& atom, value_p with)
    {
    #if defined(nkr_IS_64_BIT)
        atom_p snapshot = Access(atom);
        while (!Exchange_If_Equals(atom, snapshot, snapshot * static_cast<atom_p>(with)));
        return snapshot;
    #else
        static_assert(false, "64 bit atomic unavailable");
    #endif
    }

    template <real_32_tr atom_p, convertible_tr<atom_p> value_p>
    inline atom_p Exchange_Multiply(volatile atom_p& atom, value_p with)
    {
        atom_p snapshot = Access(atom);
        while (!Exchange_If_Equals(atom, snapshot, snapshot * static_cast<atom_p>(with)));
        return snapshot;
    }

    template <real_64_tr atom_p, convertible_tr<atom_p> value_p>
    inline atom_p Exchange_Multiply(volatile atom_p& atom, value_p with)
    {
    #if defined(nkr_IS_64_BIT)
        atom_p snapshot = Access(atom);
        while (!Exchange_If_Equals(atom, snapshot, snapshot * static_cast<atom_p>(with)));
        return snapshot;
    #else
        static_assert(false, "64 bit atomic unavailable");
    #endif
    }

    template <integer_8_tr atom_p, convertible_tr<atom_p> value_p>
    inline atom_p Exchange_Divide(volatile atom_p& atom, value_p with)
    {
        atom_p snapshot = Access(atom);
        while (!Exchange_If_Equals(atom, snapshot, snapshot / static_cast<atom_p>(with)));
        return snapshot;
    }

    template <integer_16_tr atom_p, convertible_tr<atom_p> value_p>
    inline atom_p Exchange_Divide(volatile atom_p& atom, value_p with)
    {
        atom_p snapshot = Access(atom);
        while (!Exchange_If_Equals(atom, snapshot, snapshot / static_cast<atom_p>(with)));
        return snapshot;
    }

    template <integer_32_tr atom_p, convertible_tr<atom_p> value_p>
    inline atom_p Exchange_Divide(volatile atom_p& atom, value_p with)
    {
        atom_p snapshot = Access(atom);
        while (!Exchange_If_Equals(atom, snapshot, snapshot / static_cast<atom_p>(with)));
        return snapshot;
    }

    template <integer_64_tr atom_p, convertible_tr<atom_p> value_p>
    inline atom_p Exchange_Divide(volatile atom_p& atom, value_p with)
    {
    #if defined(nkr_IS_64_BIT)
        atom_p snapshot = Access(atom);
        while (!Exchange_If_Equals(atom, snapshot, snapshot / static_cast<atom_p>(with)));
        return snapshot;
    #else
        static_assert(false, "64 bit atomic unavailable");
    #endif
    }

    template <real_32_tr atom_p, convertible_tr<atom_p> value_p>
    inline atom_p Exchange_Divide(volatile atom_p& atom, value_p with)
    {
        atom_p snapshot = Access(atom);
        while (!Exchange_If_Equals(atom, snapshot, snapshot / static_cast<atom_p>(with)));
        return snapshot;
    }

    template <real_64_tr atom_p, convertible_tr<atom_p> value_p>
    inline atom_p Exchange_Divide(volatile atom_p& atom, value_p with)
    {
    #if defined(nkr_IS_64_BIT)
        atom_p snapshot = Access(atom);
        while (!Exchange_If_Equals(atom, snapshot, snapshot / static_cast<atom_p>(with)));
        return snapshot;
    #else
        static_assert(false, "64 bit atomic unavailable");
    #endif
    }

    template <integer_8_tr atom_p, integer_tr value_p>
    inline atom_p Exchange_Modulus(volatile atom_p& atom, value_p with)
    {
        atom_p snapshot = Access(atom);
        while (!Exchange_If_Equals(atom, snapshot, snapshot % static_cast<atom_p>(with)));
        return snapshot;
    }

    template <integer_16_tr atom_p, integer_tr value_p>
    inline atom_p Exchange_Modulus(volatile atom_p& atom, value_p with)
    {
        atom_p snapshot = Access(atom);
        while (!Exchange_If_Equals(atom, snapshot, snapshot % static_cast<atom_p>(with)));
        return snapshot;
    }

    template <integer_32_tr atom_p, integer_tr value_p>
    inline atom_p Exchange_Modulus(volatile atom_p& atom, value_p with)
    {
        atom_p snapshot = Access(atom);
        while (!Exchange_If_Equals(atom, snapshot, snapshot % static_cast<atom_p>(with)));
        return snapshot;
    }

    template <integer_64_tr atom_p, integer_tr value_p>
    inline atom_p Exchange_Modulus(volatile atom_p& atom, value_p with)
    {
    #if defined(nkr_IS_64_BIT)
        atom_p snapshot = Access(atom);
        while (!Exchange_If_Equals(atom, snapshot, snapshot % static_cast<atom_p>(with)));
        return snapshot;
    #else
        static_assert(false, "64 bit atomic unavailable");
    #endif
    }

    template <integer_8_tr atom_p, integer_tr value_p>
    inline atom_p Exchange_Or(volatile atom_p& atom, value_p with)
    {
        atom_p atom_with = static_cast<atom_p>(with);
        return static_cast<atom_p>(::_InterlockedOr8(reinterpret_cast<volatile char*>(&atom),
                                                     static_cast<char>(atom_with)));
    }

    template <integer_16_tr atom_p, integer_tr value_p>
    inline atom_p Exchange_Or(volatile atom_p& atom, value_p with)
    {
        atom_p atom_with = static_cast<atom_p>(with);
        return static_cast<atom_p>(::_InterlockedOr16(reinterpret_cast<volatile short*>(&atom),
                                                      static_cast<short>(atom_with)));
    }

    template <integer_32_tr atom_p, integer_tr value_p>
    inline atom_p Exchange_Or(volatile atom_p& atom, value_p with)
    {
        atom_p atom_with = static_cast<atom_p>(with);
        return static_cast<atom_p>(::_InterlockedOr(reinterpret_cast<volatile long*>(&atom),
                                                    static_cast<long>(atom_with)));
    }

    template <integer_64_tr atom_p, integer_tr value_p>
    inline atom_p Exchange_Or(volatile atom_p& atom, value_p with)
    {
    #if defined(nkr_IS_64_BIT)
        atom_p atom_with = static_cast<atom_p>(with);
        return static_cast<atom_p>(::_InterlockedOr64(reinterpret_cast<volatile long long*>(&atom),
                                                      static_cast<long long>(atom_with)));
    #else
        static_assert(false, "64 bit atomic unavailable");
    #endif
    }

    template <integer_8_tr atom_p, integer_tr value_p>
    inline atom_p Exchange_And(volatile atom_p& atom, value_p with)
    {
        atom_p atom_with = static_cast<atom_p>(with);
        return static_cast<atom_p>(::_InterlockedAnd8(reinterpret_cast<volatile char*>(&atom),
                                                      static_cast<char>(atom_with)));
    }

    template <integer_16_tr atom_p, integer_tr value_p>
    inline atom_p Exchange_And(volatile atom_p& atom, value_p with)
    {
        atom_p atom_with = static_cast<atom_p>(with);
        return static_cast<atom_p>(::_InterlockedAnd16(reinterpret_cast<volatile short*>(&atom),
                                                       static_cast<short>(atom_with)));
    }

    template <integer_32_tr atom_p, integer_tr value_p>
    inline atom_p Exchange_And(volatile atom_p& atom, value_p with)
    {
        atom_p atom_with = static_cast<atom_p>(with);
        return static_cast<atom_p>(::_InterlockedAnd(reinterpret_cast<volatile long*>(&atom),
                                                     static_cast<long>(atom_with)));
    }

    template <integer_64_tr atom_p, integer_tr value_p>
    inline atom_p Exchange_And(volatile atom_p& atom, value_p with)
    {
    #if defined(nkr_IS_64_BIT)
        atom_p atom_with = static_cast<atom_p>(with);
        return static_cast<atom_p>(::_InterlockedAnd64(reinterpret_cast<volatile long long*>(&atom),
                                                       static_cast<long long>(atom_with)));
    #else
        static_assert(false, "64 bit atomic unavailable");
    #endif
    }

    template <integer_8_tr atom_p, integer_tr value_p>
    inline atom_p Exchange_Xor(volatile atom_p& atom, value_p with)
    {
        atom_p atom_with = static_cast<atom_p>(with);
        return static_cast<atom_p>(::_InterlockedXor8(reinterpret_cast<volatile char*>(&atom),
                                                      static_cast<char>(atom_with)));
    }

    template <integer_16_tr atom_p, integer_tr value_p>
    inline atom_p Exchange_Xor(volatile atom_p& atom, value_p with)
    {
        atom_p atom_with = static_cast<atom_p>(with);
        return static_cast<atom_p>(::_InterlockedXor16(reinterpret_cast<volatile short*>(&atom),
                                                       static_cast<short>(atom_with)));
    }

    template <integer_32_tr atom_p, integer_tr value_p>
    inline atom_p Exchange_Xor(volatile atom_p& atom, value_p with)
    {
        atom_p atom_with = static_cast<atom_p>(with);
        return static_cast<atom_p>(::_InterlockedXor(reinterpret_cast<volatile long*>(&atom),
                                                     static_cast<long>(atom_with)));
    }

    template <integer_64_tr atom_p, integer_tr value_p>
    inline atom_p Exchange_Xor(volatile atom_p& atom, value_p with)
    {
    #if defined(nkr_IS_64_BIT)
        atom_p atom_with = static_cast<atom_p>(with);
        return static_cast<atom_p>(::_InterlockedXor64(reinterpret_cast<volatile long long*>(&atom),
                                                       static_cast<long long>(atom_with)));
    #else
        static_assert(false, "64 bit atomic unavailable");
    #endif
    }

    template <integer_8_tr atom_p, integer_tr value_p>
    inline atom_p Exchange_Left_Shift(volatile atom_p& atom, value_p with)
    {
        atom_p snapshot = Access(atom);
        while (!Exchange_If_Equals(atom, snapshot, snapshot << static_cast<atom_p>(with)));
        return snapshot;
    }

    template <integer_16_tr atom_p, integer_tr value_p>
    inline atom_p Exchange_Left_Shift(volatile atom_p& atom, value_p with)
    {
        atom_p snapshot = Access(atom);
        while (!Exchange_If_Equals(atom, snapshot, snapshot << static_cast<atom_p>(with)));
        return snapshot;
    }

    template <integer_32_tr atom_p, integer_tr value_p>
    inline atom_p Exchange_Left_Shift(volatile atom_p& atom, value_p with)
    {
        atom_p snapshot = Access(atom);
        while (!Exchange_If_Equals(atom, snapshot, snapshot << static_cast<atom_p>(with)));
        return snapshot;
    }

    template <integer_64_tr atom_p, integer_tr value_p>
    inline atom_p Exchange_Left_Shift(volatile atom_p& atom, value_p with)
    {
    #if defined(nkr_IS_64_BIT)
        atom_p snapshot = Access(atom);
        while (!Exchange_If_Equals(atom, snapshot, snapshot << static_cast<atom_p>(with)));
        return snapshot;
    #else
        static_assert(false, "64 bit atomic unavailable");
    #endif
    }

    template <integer_8_tr atom_p, integer_tr value_p>
    inline atom_p Exchange_Right_Shift(volatile atom_p& atom, value_p with)
    {
        atom_p snapshot = Access(atom);
        while (!Exchange_If_Equals(atom, snapshot, snapshot >> static_cast<atom_p>(with)));
        return snapshot;
    }

    template <integer_16_tr atom_p, integer_tr value_p>
    inline atom_p Exchange_Right_Shift(volatile atom_p& atom, value_p with)
    {
        atom_p snapshot = Access(atom);
        while (!Exchange_If_Equals(atom, snapshot, snapshot >> static_cast<atom_p>(with)));
        return snapshot;
    }

    template <integer_32_tr atom_p, integer_tr value_p>
    inline atom_p Exchange_Right_Shift(volatile atom_p& atom, value_p with)
    {
        atom_p snapshot = Access(atom);
        while (!Exchange_If_Equals(atom, snapshot, snapshot >> static_cast<atom_p>(with)));
        return snapshot;
    }

    template <integer_64_tr atom_p, integer_tr value_p>
    inline atom_p Exchange_Right_Shift(volatile atom_p& atom, value_p with)
    {
    #if defined(nkr_IS_64_BIT)
        atom_p snapshot = Access(atom);
        while (!Exchange_If_Equals(atom, snapshot, snapshot >> static_cast<atom_p>(with)));
        return snapshot;
    #else
        static_assert(false, "64 bit atomic unavailable");
    #endif
    }

    template <boolean_tr atom_p, convertible_tr<atom_p> value_p>
    inline bool_t Exchange_If_Equals(volatile atom_p& atom,
                                     atom_p& snapshot,
                                     value_p with)
    {
        atom_p atom_with = static_cast<atom_p>(with);
        if constexpr (std::same_as<atom_p, bool_t>) {
            return Exchange_If_Equals(static_cast<volatile word_t&>(atom),
                                      static_cast<word_t&>(snapshot),
                                      static_cast<word_t>(atom_with));
        } else {
            using integer_unsigned_t = integer_unsigned_for_t<atom_p>;

            return Exchange_If_Equals(reinterpret_cast<volatile integer_unsigned_t&>(atom),
                                      reinterpret_cast<integer_unsigned_t&>(snapshot),
                                      reinterpret_cast<integer_unsigned_t&>(atom_with));
        }
    }

    template <integer_8_tr atom_p, convertible_tr<atom_p> value_p>
    inline bool_t Exchange_If_Equals(volatile atom_p& atom,
                                     atom_p& snapshot,
                                     value_p with)
    {
        atom_p atom_with = static_cast<atom_p>(with);
        atom_p value = static_cast<atom_p>(::_InterlockedCompareExchange8((volatile char*)(&atom),
                                                                          static_cast<char>(atom_with),
                                                                          static_cast<char>(snapshot)));
        if (snapshot == value) {
            return true;
        } else {
            snapshot = value;
            return false;
        }
    }

    template <integer_16_tr atom_p, convertible_tr<atom_p> value_p>
    inline bool_t Exchange_If_Equals(volatile atom_p& atom,
                                     atom_p& snapshot,
                                     value_p with)
    {
        atom_p atom_with = static_cast<atom_p>(with);
        atom_p value = static_cast<atom_p>(::_InterlockedCompareExchange16(reinterpret_cast<volatile short*>(&atom),
                                                                           static_cast<short>(atom_with),
                                                                           static_cast<short>(snapshot)));
        if (snapshot == value) {
            return true;
        } else {
            snapshot = value;
            return false;
        }
    }

    template <integer_32_tr atom_p, convertible_tr<atom_p> value_p>
    inline bool_t Exchange_If_Equals(volatile atom_p& atom,
                                     atom_p& snapshot,
                                     value_p with)
    {
        atom_p atom_with = static_cast<atom_p>(with);
        atom_p value = static_cast<atom_p>(::_InterlockedCompareExchange(reinterpret_cast<volatile long*>(&atom),
                                                                         static_cast<long>(atom_with),
                                                                         static_cast<long>(snapshot)));
        if (snapshot == value) {
            return true;
        } else {
            snapshot = value;
            return false;
        }
    }

    template <integer_64_tr atom_p, convertible_tr<atom_p> value_p>
    inline bool_t Exchange_If_Equals(volatile atom_p& atom,
                                     atom_p& snapshot,
                                     value_p with)
    {
    #if defined(nkr_IS_64_BIT)
        atom_p atom_with = static_cast<atom_p>(with);
        atom_p value = static_cast<atom_p>(::_InterlockedCompareExchange64(reinterpret_cast<volatile long long*>(&atom),
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

    template <real_32_tr atom_p, convertible_tr<atom_p> value_p>
    inline bool_t Exchange_If_Equals(volatile atom_p& atom,
                                     atom_p& snapshot,
                                     value_p with)
    {
        atom_p atom_with = static_cast<atom_p>(with);
        return Exchange_If_Equals(reinterpret_cast<volatile u32_t&>(atom),
                                  reinterpret_cast<u32_t&>(snapshot),
                                  reinterpret_cast<u32_t&>(atom_with));
    }

    template <real_64_tr atom_p, convertible_tr<atom_p> value_p>
    inline bool_t Exchange_If_Equals(volatile atom_p& atom,
                                     atom_p& snapshot,
                                     value_p with)
    {
    #if defined(nkr_IS_64_BIT)
        atom_p atom_with = static_cast<atom_p>(with);
        return Exchange_If_Equals(reinterpret_cast<volatile u64_t&>(atom),
                                  reinterpret_cast<u64_t&>(snapshot),
                                  reinterpret_cast<u64_t&>(atom_with));
    #else
        static_assert(false, "64 bit atomic unavailable");
    #endif
    }

    template <pointer_tr atom_p, convertible_tr<atom_p> value_p>
    inline bool_t Exchange_If_Equals(volatile atom_p& atom,
                                     atom_p& snapshot,
                                     value_p with)
    {
        atom_p value = static_cast<atom_p>(::_InterlockedCompareExchangePointer(reinterpret_cast<void* volatile*>(&atom),
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
