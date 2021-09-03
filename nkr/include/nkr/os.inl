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

    template <atomic_tr atom_p>
    inline atom_p Access(const volatile atom_p& atom)
    {
        atom_p snapshot = atom_p();
        Exchange_If_Equals(const_cast<volatile std::remove_cvref_t<decltype(atom)>&>(atom), snapshot, atom_p());
        return snapshot;
    }

    template <atomic_tr atom_p, convertible_tr<atom_p> value_p>
    inline atom_p Assign(volatile atom_p& atom, value_p value)
    {
        return Exchange(atom, value), static_cast<atom_p>(value);
    }

    template <atomic_tr atom_p, convertible_tr<atom_p> value_p>
    inline atom_p Assign_Add(volatile atom_p& atom, value_p value)
    {
        return Exchange_Add(atom, value) + static_cast<atom_p>(value);
    }

    template <type_pointer_tr atom_p, integer_tr value_p>
    inline atom_p Assign_Add(volatile atom_p& atom, value_p value)
    {
        return Exchange_Add(atom, value) + value;
    }

    template <atomic_tr atom_p, convertible_tr<atom_p> value_p>
    inline atom_p Assign_Subtract(volatile atom_p& atom, value_p value)
    {
        return Exchange_Subtract(atom, value) - static_cast<atom_p>(value);
    }

    template <type_pointer_tr atom_p, integer_tr value_p>
    inline atom_p Assign_Subtract(volatile atom_p& atom, value_p value)
    {
        return Exchange_Subtract(atom, value) - value;
    }

    template <atomic_tr atom_p, convertible_tr<atom_p> value_p>
    inline atom_p Assign_Multiply(volatile atom_p& atom, value_p value)
    {
        return Exchange_Multiply(atom, value) * static_cast<atom_p>(value);
    }

    template <atomic_tr atom_p, convertible_tr<atom_p> value_p>
    inline atom_p Assign_Divide(volatile atom_p& atom, value_p value)
    {
        return Exchange_Divide(atom, value) / static_cast<atom_p>(value);
    }

    template <atomic_tr atom_p, integer_tr value_p>
    inline atom_p Assign_Modulus(volatile atom_p& atom, value_p value)
    {
        return Exchange_Modulus(atom, value) % static_cast<atom_p>(value);
    }

    template <atomic_tr atom_p, integer_tr value_p>
    inline atom_p Assign_Or(volatile atom_p& atom, value_p value)
    {
        return Exchange_Or(atom, value) | static_cast<atom_p>(value);
    }

    template <atomic_tr atom_p, integer_tr value_p>
    inline atom_p Assign_And(volatile atom_p& atom, value_p value)
    {
        return Exchange_And(atom, value) & static_cast<atom_p>(value);
    }

    template <atomic_tr atom_p, integer_tr value_p>
    inline atom_p Assign_Xor(volatile atom_p& atom, value_p value)
    {
        return Exchange_Xor(atom, value) ^ static_cast<atom_p>(value);
    }

    template <atomic_tr atom_p, integer_tr value_p>
    inline atom_p Assign_Left_Shift(volatile atom_p& atom, value_p value)
    {
        return Exchange_Left_Shift(atom, value) << static_cast<atom_p>(value);
    }

    template <atomic_tr atom_p, integer_tr value_p>
    inline atom_p Assign_Right_Shift(volatile atom_p& atom, value_p value)
    {
        return Exchange_Right_Shift(atom, value) >> static_cast<atom_p>(value);
    }

#if defined(nkr_IS_WINDOWS)

    template <atomic_tr atom_p, convertible_tr<atom_p> value_p>
    inline atom_p Exchange(volatile atom_p& atom, value_p value)
    {
        atom_p atom_value = static_cast<atom_p>(value);
        if constexpr (integer_8_tr<atom_p> ||
                      (boolean_tr<atom_p> && sizeof(atom_p) == sizeof(u8_t))) {
            char result = ::_InterlockedExchange8(reinterpret_cast<volatile char*>(&atom),
                                                  reinterpret_cast<char&>(atom_value));
            return reinterpret_cast<atom_p&>(result);
        } else if constexpr (integer_16_tr<atom_p> ||
                             (boolean_tr<atom_p> && sizeof(atom_p) == sizeof(u16_t))) {
            short result = ::_InterlockedExchange16(reinterpret_cast<volatile short*>(&atom),
                                                    reinterpret_cast<short&>(atom_value));
            return reinterpret_cast<atom_p&>(result);
        } else if constexpr (integer_32_tr<atom_p> ||
                             real_32_tr<atom_p> ||
                             (pointer_tr<atom_p> && sizeof(atom_p) == sizeof(u32_t)) ||
                             (boolean_tr<atom_p> && sizeof(atom_p) == sizeof(u32_t))) {
            long result = ::_InterlockedExchange(reinterpret_cast<volatile long*>(&atom),
                                                 reinterpret_cast<long&>(atom_value));
            return reinterpret_cast<atom_p&>(result);
        } else if constexpr (integer_64_tr<atom_p> ||
                             real_64_tr<atom_p> ||
                             (pointer_tr<atom_p> && sizeof(atom_p) == sizeof(u64_t)) ||
                             (boolean_tr<atom_p> && sizeof(atom_p) == sizeof(u64_t))) {
        #if defined(nkr_IS_64_BIT)
            long long result = ::_InterlockedExchange64(reinterpret_cast<volatile long long*>(&atom),
                                                        reinterpret_cast<long long&>(atom_value));
            return reinterpret_cast<atom_p&>(result);
        #else
            static_assert(false, "64 bit atomic unavailable");
        #endif
        } else {
            static_assert(false, "invalid atom_p");
        }
    }

    template <atomic_tr atom_p, convertible_tr<atom_p> value_p>
    inline atom_p Exchange_Add(volatile atom_p& atom, value_p value)
    {
        atom_p atom_value = static_cast<atom_p>(value);
        if constexpr (integer_8_tr<atom_p>) {
            char result = ::_InterlockedExchangeAdd8(reinterpret_cast<volatile char*>(&atom),
                                                     reinterpret_cast<char&>(atom_value));
            return reinterpret_cast<atom_p&>(result);
        } else if constexpr (integer_16_tr<atom_p>) {
            short result = ::_InterlockedExchangeAdd16(reinterpret_cast<volatile short*>(&atom),
                                                       reinterpret_cast<short&>(atom_value));
            return reinterpret_cast<atom_p&>(result);
        } else if constexpr (integer_32_tr<atom_p>) {
            long result = ::_InterlockedExchangeAdd(reinterpret_cast<volatile long*>(&atom),
                                                    reinterpret_cast<long&>(atom_value));
            return reinterpret_cast<atom_p&>(result);
        } else if constexpr (integer_64_tr<atom_p>) {
        #if defined(nkr_IS_64_BIT)
            long long result = ::_InterlockedExchangeAdd64(reinterpret_cast<volatile long long*>(&atom),
                                                           reinterpret_cast<long long&>(atom_value));
            return reinterpret_cast<atom_p&>(result);
        #else
            static_assert(false, "64 bit atomic unavailable");
        #endif
        } else if constexpr (real_32_tr<atom_p>) {
            atom_p snapshot = Access(atom);
            while (!Exchange_If_Equals(atom, snapshot, snapshot + atom_value));
            return snapshot;
        } else if constexpr (real_64_tr<atom_p>) {
        #if defined(nkr_IS_64_BIT)
            atom_p snapshot = Access(atom);
            while (!Exchange_If_Equals(atom, snapshot, snapshot + atom_value));
            return snapshot;
        #else
            static_assert(false, "64 bit atomic unavailable");
        #endif
        } else {
            static_assert(false, "invalid atom_p");
        }
    }

    template <type_pointer_tr atom_p, integer_tr value_p>
    inline atom_p Exchange_Add(volatile atom_p& atom, value_p value)
    {
        address_t result = Exchange_Add(reinterpret_cast<volatile address_t&>(atom),
                                        sizeof(std::remove_pointer_t<atom_p>) * value);
        return reinterpret_cast<atom_p&>(result);
    }

    template <atomic_tr atom_p, convertible_tr<atom_p> value_p>
    inline atom_p Exchange_Subtract(volatile atom_p& atom, value_p value)
    {
        atom_p atom_value = static_cast<atom_p>(value);
        if constexpr (integer_8_tr<atom_p>) {
            char result = ::_InterlockedExchangeAdd8(reinterpret_cast<volatile char*>(&atom),
                                                     -reinterpret_cast<char&>(atom_value));
            return reinterpret_cast<atom_p&>(result);
        } else if constexpr (integer_16_tr<atom_p>) {
            short result = ::_InterlockedExchangeAdd16(reinterpret_cast<volatile short*>(&atom),
                                                       -reinterpret_cast<short&>(atom_value));
            return reinterpret_cast<atom_p&>(result);
        } else if constexpr (integer_32_tr<atom_p>) {
            long result = ::_InterlockedExchangeAdd(reinterpret_cast<volatile long*>(&atom),
                                                    -reinterpret_cast<long&>(atom_value));
            return reinterpret_cast<atom_p&>(result);
        } else if constexpr (integer_64_tr<atom_p>) {
        #if defined(nkr_IS_64_BIT)
            long long result = ::_InterlockedExchangeAdd64(reinterpret_cast<volatile long long*>(&atom),
                                                           -reinterpret_cast<long long&>(atom_value));
            return reinterpret_cast<atom_p&>(result);
        #else
            static_assert(false, "64 bit atomic unavailable");
        #endif
        } else if constexpr (real_32_tr<atom_p>) {
            atom_p snapshot = Access(atom);
            while (!Exchange_If_Equals(atom, snapshot, snapshot - atom_value));
            return snapshot;
        } else if constexpr (real_64_tr<atom_p>) {
        #if defined(nkr_IS_64_BIT)
            atom_p snapshot = Access(atom);
            while (!Exchange_If_Equals(atom, snapshot, snapshot - atom_value));
            return snapshot;
        #else
            static_assert(false, "64 bit atomic unavailable");
        #endif
        } else {
            static_assert(false, "invalid atom_p");
        }
    }

    template <type_pointer_tr atom_p, integer_tr value_p>
    inline atom_p Exchange_Subtract(volatile atom_p& atom, value_p value)
    {
        address_t result = Exchange_Subtract(reinterpret_cast<volatile address_t&>(atom),
                                             sizeof(std::remove_pointer_t<atom_p>) * value);
        return reinterpret_cast<atom_p&>(result);
    }

    template <atomic_tr atom_p, convertible_tr<atom_p> value_p>
    inline atom_p Exchange_Multiply(volatile atom_p& atom, value_p value)
    {
        atom_p atom_value = static_cast<atom_p>(value);
        if constexpr (integer_8_tr<atom_p> ||
                      integer_16_tr<atom_p> ||
                      integer_32_tr<atom_p> ||
                      real_32_tr<atom_p>) {
            atom_p snapshot = Access(atom);
            while (!Exchange_If_Equals(atom, snapshot, snapshot * atom_value));
            return snapshot;
        } else if constexpr (integer_64_tr<atom_p> ||
                             real_64_tr<atom_p>) {
        #if defined(nkr_IS_64_BIT)
            atom_p snapshot = Access(atom);
            while (!Exchange_If_Equals(atom, snapshot, snapshot * atom_value));
            return snapshot;
        #else
            static_assert(false, "64 bit atomic unavailable");
        #endif
        } else {
            static_assert(false, "invalid atom_p");
        }
    }

    template <atomic_tr atom_p, convertible_tr<atom_p> value_p>
    inline atom_p Exchange_Divide(volatile atom_p& atom, value_p value)
    {
        atom_p atom_value = static_cast<atom_p>(value);
        if constexpr (integer_8_tr<atom_p> ||
                      integer_16_tr<atom_p> ||
                      integer_32_tr<atom_p> ||
                      real_32_tr<atom_p>) {
            atom_p snapshot = Access(atom);
            while (!Exchange_If_Equals(atom, snapshot, snapshot / atom_value));
            return snapshot;
        } else if constexpr (integer_64_tr<atom_p> ||
                             real_64_tr<atom_p>) {
        #if defined(nkr_IS_64_BIT)
            atom_p snapshot = Access(atom);
            while (!Exchange_If_Equals(atom, snapshot, snapshot / atom_value));
            return snapshot;
        #else
            static_assert(false, "64 bit atomic unavailable");
        #endif
        } else {
            static_assert(false, "invalid atom_p");
        }
    }

    template <atomic_tr atom_p, integer_tr value_p>
    inline atom_p Exchange_Modulus(volatile atom_p& atom, value_p value)
    {
        atom_p atom_value = static_cast<atom_p>(value);
        if constexpr (integer_8_tr<atom_p> ||
                      integer_16_tr<atom_p> ||
                      integer_32_tr<atom_p>) {
            atom_p snapshot = Access(atom);
            while (!Exchange_If_Equals(atom, snapshot, snapshot % atom_value));
            return snapshot;
        } else if constexpr (integer_64_tr<atom_p>) {
        #if defined(nkr_IS_64_BIT)
            atom_p snapshot = Access(atom);
            while (!Exchange_If_Equals(atom, snapshot, snapshot % atom_value));
            return snapshot;
        #else
            static_assert(false, "64 bit atomic unavailable");
        #endif
        } else {
            static_assert(false, "invalid atom_p");
        }
    }

    template <atomic_tr atom_p, integer_tr value_p>
    inline atom_p Exchange_Or(volatile atom_p& atom, value_p value)
    {
        atom_p atom_value = static_cast<atom_p>(value);
        if constexpr (integer_8_tr<atom_p>) {
            char result = ::_InterlockedOr8(reinterpret_cast<volatile char*>(&atom),
                                            reinterpret_cast<char&>(atom_value));
            return reinterpret_cast<atom_p&>(result);
        } else if constexpr (integer_16_tr<atom_p>) {
            short result = ::_InterlockedOr16(reinterpret_cast<volatile short*>(&atom),
                                              reinterpret_cast<short&>(atom_value));
            return reinterpret_cast<atom_p&>(result);
        } else if constexpr (integer_32_tr<atom_p>) {
            long result = ::_InterlockedOr(reinterpret_cast<volatile long*>(&atom),
                                           reinterpret_cast<long&>(atom_value));
            return reinterpret_cast<atom_p&>(result);
        } else if constexpr (integer_64_tr<atom_p>) {
        #if defined(nkr_IS_64_BIT)
            long long result = ::_InterlockedOr64(reinterpret_cast<volatile long long*>(&atom),
                                                  reinterpret_cast<long long&>(atom_value));
            return reinterpret_cast<atom_p&>(result);
        #else
            static_assert(false, "64 bit atomic unavailable");
        #endif
        } else {
            static_assert(false, "invalid atom_p");
        }
    }

    template <atomic_tr atom_p, integer_tr value_p>
    inline atom_p Exchange_And(volatile atom_p& atom, value_p value)
    {
        atom_p atom_value = static_cast<atom_p>(value);
        if constexpr (integer_8_tr<atom_p>) {
            char result = ::_InterlockedAnd8(reinterpret_cast<volatile char*>(&atom),
                                             reinterpret_cast<char&>(atom_value));
            return reinterpret_cast<atom_p&>(result);
        } else if constexpr (integer_16_tr<atom_p>) {
            short result = ::_InterlockedAnd16(reinterpret_cast<volatile short*>(&atom),
                                               reinterpret_cast<short&>(atom_value));
            return reinterpret_cast<atom_p&>(result);
        } else if constexpr (integer_32_tr<atom_p>) {
            long result = ::_InterlockedAnd(reinterpret_cast<volatile long*>(&atom),
                                            reinterpret_cast<long&>(atom_value));
            return reinterpret_cast<atom_p&>(result);
        } else if constexpr (integer_64_tr<atom_p>) {
        #if defined(nkr_IS_64_BIT)
            long long result = ::_InterlockedAnd64(reinterpret_cast<volatile long long*>(&atom),
                                                   reinterpret_cast<long long&>(atom_value));
            return reinterpret_cast<atom_p&>(result);
        #else
            static_assert(false, "64 bit atomic unavailable");
        #endif
        } else {
            static_assert(false, "invalid atom_p");
        }
    }

    template <atomic_tr atom_p, integer_tr value_p>
    inline atom_p Exchange_Xor(volatile atom_p& atom, value_p value)
    {
        atom_p atom_value = static_cast<atom_p>(value);
        if constexpr (integer_8_tr<atom_p>) {
            char result = ::_InterlockedXor8(reinterpret_cast<volatile char*>(&atom),
                                             reinterpret_cast<char&>(atom_value));
            return reinterpret_cast<atom_p&>(result);
        } else if constexpr (integer_16_tr<atom_p>) {
            short result = ::_InterlockedXor16(reinterpret_cast<volatile short*>(&atom),
                                               reinterpret_cast<short&>(atom_value));
            return reinterpret_cast<atom_p&>(result);
        } else if constexpr (integer_32_tr<atom_p>) {
            long result = ::_InterlockedXor(reinterpret_cast<volatile long*>(&atom),
                                            reinterpret_cast<long&>(atom_value));
            return reinterpret_cast<atom_p&>(result);
        } else if constexpr (integer_64_tr<atom_p>) {
        #if defined(nkr_IS_64_BIT)
            long long result = ::_InterlockedXor64(reinterpret_cast<volatile long long*>(&atom),
                                                   reinterpret_cast<long long&>(atom_value));
            return reinterpret_cast<atom_p&>(result);
        #else
            static_assert(false, "64 bit atomic unavailable");
        #endif
        } else {
            static_assert(false, "invalid atom_p");
        }
    }

    template <atomic_tr atom_p, integer_tr value_p>
    inline atom_p Exchange_Left_Shift(volatile atom_p& atom, value_p value)
    {
        atom_p atom_value = static_cast<atom_p>(value);
        if constexpr (integer_8_tr<atom_p> ||
                      integer_16_tr<atom_p> ||
                      integer_32_tr<atom_p>) {
            atom_p snapshot = Access(atom);
            while (!Exchange_If_Equals(atom, snapshot, snapshot << atom_value));
            return snapshot;
        } else if constexpr (integer_64_tr<atom_p>) {
        #if defined(nkr_IS_64_BIT)
            atom_p snapshot = Access(atom);
            while (!Exchange_If_Equals(atom, snapshot, snapshot << atom_value));
            return snapshot;
        #else
            static_assert(false, "64 bit atomic unavailable");
        #endif
        } else {
            static_assert(false, "invalid atom_p");
        }
    }

    template <atomic_tr atom_p, integer_tr value_p>
    inline atom_p Exchange_Right_Shift(volatile atom_p& atom, value_p value)
    {
        atom_p atom_value = static_cast<atom_p>(value);
        if constexpr (integer_8_tr<atom_p> ||
                      integer_16_tr<atom_p> ||
                      integer_32_tr<atom_p>) {
            atom_p snapshot = Access(atom);
            while (!Exchange_If_Equals(atom, snapshot, snapshot >> atom_value));
            return snapshot;
        } else if constexpr (integer_64_tr<atom_p>) {
        #if defined(nkr_IS_64_BIT)
            atom_p snapshot = Access(atom);
            while (!Exchange_If_Equals(atom, snapshot, snapshot >> atom_value));
            return snapshot;
        #else
            static_assert(false, "64 bit atomic unavailable");
        #endif
        } else {
            static_assert(false, "invalid atom_p");
        }
    }

    template <atomic_tr atom_p, convertible_tr<atom_p> value_p>
    bool_t Exchange_If_Equals(volatile atom_p& atom, atom_p& snapshot, value_p value)
    {
        atom_p atom_value = static_cast<atom_p>(value);
        atom_p atom_result;
        if constexpr (integer_8_tr<atom_p> ||
                      (boolean_tr<atom_p> && sizeof(atom_p) == sizeof(u8_t))) {
            char result = ::_InterlockedCompareExchange8(reinterpret_cast<volatile char*>(&atom),
                                                         reinterpret_cast<char&>(atom_value),
                                                         reinterpret_cast<char&>(snapshot));
            atom_result = reinterpret_cast<atom_p&>(result);
        } else if constexpr (integer_16_tr<atom_p> ||
                             (boolean_tr<atom_p> && sizeof(atom_p) == sizeof(u16_t))) {
            short result = ::_InterlockedCompareExchange16(reinterpret_cast<volatile short*>(&atom),
                                                           reinterpret_cast<short&>(atom_value),
                                                           reinterpret_cast<short&>(snapshot));
            atom_result = reinterpret_cast<atom_p&>(result);
        } else if constexpr (integer_32_tr<atom_p> ||
                             real_32_tr<atom_p> ||
                             (pointer_tr<atom_p> && sizeof(atom_p) == sizeof(u32_t)) ||
                             (boolean_tr<atom_p> && sizeof(atom_p) == sizeof(u32_t))) {
            long result = ::_InterlockedCompareExchange(reinterpret_cast<volatile long*>(&atom),
                                                        reinterpret_cast<long&>(atom_value),
                                                        reinterpret_cast<long&>(snapshot));
            atom_result = reinterpret_cast<atom_p&>(result);
        } else if constexpr (integer_64_tr<atom_p> ||
                             real_64_tr<atom_p> ||
                             (pointer_tr<atom_p> && sizeof(atom_p) == sizeof(u64_t)) ||
                             (boolean_tr<atom_p> && sizeof(atom_p) == sizeof(u64_t))) {
        #if defined(nkr_IS_64_BIT)
            long long result = ::_InterlockedCompareExchange64(reinterpret_cast<volatile long long*>(&atom),
                                                               reinterpret_cast<long long&>(atom_value),
                                                               reinterpret_cast<long long&>(snapshot));
            atom_result = reinterpret_cast<atom_p&>(result);
        #else
            static_assert(false, "64 bit atomic unavailable");
        #endif
        } else {
            static_assert(false, "invalid atom_p");
        }

        if (snapshot == atom_result) {
            return true;
        } else {
            snapshot = atom_result;
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
