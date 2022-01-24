/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#if defined(nkr_IS_WINDOWS)
    #define NOMINMAX

    #undef interface
    #include <intrin.h>
    #include <windows.h>

    #undef interface
    #include "nkr/z_intrinsics_def.h"
#endif

#include <bit>
#include <mutex>

#include "nkr/z_fors.h"
#include "nkr/z_macros_def.h"
#include "nkr/z_os_dec.h"

namespace nkr { namespace os { namespace atomic {

    template <fundamental_tr atom_p>
    inline atom_p
        Access(const volatile atom_p& atom)
    {
        atom_p snapshot = atom_p();
        Exchange_If_Equals(const_cast<volatile std::remove_cvref_t<decltype(atom)>&>(atom), snapshot, atom_p());
        return snapshot;
    }

    template <fundamental_tr atom_p, convertible_tr<atom_p> value_p>
    inline atom_p
        Assign(volatile atom_p& atom, value_p value)
    {
        return Exchange(atom, value), static_cast<atom_p>(value);
    }

    template <number_tr atom_p, convertible_tr<atom_p> value_p>
    inline atom_p
        Assign_Add(volatile atom_p& atom, value_p value)
    {
        return Exchange_Add(atom, value) + static_cast<atom_p>(value);
    }

    template <type_pointer_tr atom_p, integer_tr value_p>
    inline atom_p
        Assign_Add(volatile atom_p& atom, value_p value)
    {
        return Exchange_Add(atom, value) + value;
    }

    template <number_tr atom_p, convertible_tr<atom_p> value_p>
    inline atom_p
        Assign_Subtract(volatile atom_p& atom, value_p value)
    {
        return Exchange_Subtract(atom, value) - static_cast<atom_p>(value);
    }

    template <type_pointer_tr atom_p, integer_tr value_p>
    inline atom_p
        Assign_Subtract(volatile atom_p& atom, value_p value)
    {
        return Exchange_Subtract(atom, value) - value;
    }

    template <number_tr atom_p, convertible_tr<atom_p> value_p>
    inline atom_p
        Assign_Multiply(volatile atom_p& atom, value_p value)
    {
        return Exchange_Multiply(atom, value) * static_cast<atom_p>(value);
    }

    template <number_tr atom_p, convertible_tr<atom_p> value_p>
    inline atom_p
        Assign_Divide(volatile atom_p& atom, value_p value)
    {
        return Exchange_Divide(atom, value) / static_cast<atom_p>(value);
    }

    template <integer_tr atom_p, integer_tr value_p>
    inline atom_p
        Assign_Modulus(volatile atom_p& atom, value_p value)
    {
        return Exchange_Modulus(atom, value) % static_cast<atom_p>(value);
    }

    template <integer_tr atom_p, integer_tr value_p>
    inline atom_p
        Assign_Or(volatile atom_p& atom, value_p value)
    {
        return Exchange_Or(atom, value) | static_cast<atom_p>(value);
    }

    template <integer_tr atom_p, integer_tr value_p>
    inline atom_p
        Assign_And(volatile atom_p& atom, value_p value)
    {
        return Exchange_And(atom, value) & static_cast<atom_p>(value);
    }

    template <integer_tr atom_p, integer_tr value_p>
    inline atom_p
        Assign_Xor(volatile atom_p& atom, value_p value)
    {
        return Exchange_Xor(atom, value) ^ static_cast<atom_p>(value);
    }

    template <integer_tr atom_p, integer_tr value_p>
    inline atom_p
        Assign_Left_Shift(volatile atom_p& atom, value_p value)
    {
        return Exchange_Left_Shift(atom, value) << static_cast<atom_p>(value);
    }

    template <integer_tr atom_p, integer_tr value_p>
    inline atom_p
        Assign_Right_Shift(volatile atom_p& atom, value_p value)
    {
        return Exchange_Right_Shift(atom, value) >> static_cast<atom_p>(value);
    }

#if defined(nkr_IS_WINDOWS)

    template <fundamental_tr atom_p, convertible_tr<atom_p> value_p>
    inline atom_p
        Exchange(volatile atom_p& atom, value_p value)
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
                             (c_pointer_tr<atom_p> && sizeof(atom_p) == sizeof(u32_t)) ||
                             (boolean_tr<atom_p> && sizeof(atom_p) == sizeof(u32_t))) {
            long result = ::_InterlockedExchange(reinterpret_cast<volatile long*>(&atom),
                                                 reinterpret_cast<long&>(atom_value));
            return reinterpret_cast<atom_p&>(result);
        } else if constexpr (integer_64_tr<atom_p> ||
                             real_64_tr<atom_p> ||
                             (c_pointer_tr<atom_p> && sizeof(atom_p) == sizeof(u64_t)) ||
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

    template <number_tr atom_p, convertible_tr<atom_p> value_p>
    inline atom_p
        Exchange_Add(volatile atom_p& atom, value_p value)
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
    inline atom_p
        Exchange_Add(volatile atom_p& atom, value_p value)
    {
        address_t result = Exchange_Add(reinterpret_cast<volatile address_t&>(atom),
                                        sizeof(std::remove_pointer_t<atom_p>) * value);
        return reinterpret_cast<atom_p&>(result);
    }

    template <number_tr atom_p, convertible_tr<atom_p> value_p>
    inline atom_p
        Exchange_Subtract(volatile atom_p& atom, value_p value)
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
    inline atom_p
        Exchange_Subtract(volatile atom_p& atom, value_p value)
    {
        address_t result = Exchange_Subtract(reinterpret_cast<volatile address_t&>(atom),
                                             sizeof(std::remove_pointer_t<atom_p>) * value);
        return reinterpret_cast<atom_p&>(result);
    }

    template <number_tr atom_p, convertible_tr<atom_p> value_p>
    inline atom_p
        Exchange_Multiply(volatile atom_p& atom, value_p value)
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

    template <number_tr atom_p, convertible_tr<atom_p> value_p>
    inline atom_p
        Exchange_Divide(volatile atom_p& atom, value_p value)
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

    template <integer_tr atom_p, integer_tr value_p>
    inline atom_p
        Exchange_Modulus(volatile atom_p& atom, value_p value)
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

    template <integer_tr atom_p, integer_tr value_p>
    inline atom_p
        Exchange_Or(volatile atom_p& atom, value_p value)
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

    template <integer_tr atom_p, integer_tr value_p>
    inline atom_p
        Exchange_And(volatile atom_p& atom, value_p value)
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

    template <integer_tr atom_p, integer_tr value_p>
    inline atom_p
        Exchange_Xor(volatile atom_p& atom, value_p value)
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

    template <integer_tr atom_p, integer_tr value_p>
    inline atom_p
        Exchange_Left_Shift(volatile atom_p& atom, value_p value)
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

    template <integer_tr atom_p, integer_tr value_p>
    inline atom_p
        Exchange_Right_Shift(volatile atom_p& atom, value_p value)
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

    template <fundamental_tr atom_p, convertible_tr<atom_p> value_p>
    inline bool_t
        Exchange_If_Equals(volatile atom_p& atom, atom_p& snapshot, value_p value)
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
                             (c_pointer_tr<atom_p> && sizeof(atom_p) == sizeof(u32_t)) ||
                             (boolean_tr<atom_p> && sizeof(atom_p) == sizeof(u32_t))) {
            long result = ::_InterlockedCompareExchange(reinterpret_cast<volatile long*>(&atom),
                                                        reinterpret_cast<long&>(atom_value),
                                                        reinterpret_cast<long&>(snapshot));
            atom_result = reinterpret_cast<atom_p&>(result);
        } else if constexpr (integer_64_tr<atom_p> ||
                             real_64_tr<atom_p> ||
                             (c_pointer_tr<atom_p> && sizeof(atom_p) == sizeof(u64_t)) ||
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

    inline constexpr c_bool_t
        Is_Big()
    {
        return std::endian::native == std::endian::big;
    }

    inline constexpr c_bool_t
        Is_Little()
    {
        return std::endian::native == std::endian::little;
    }

#if defined(nkr_IS_WINDOWS)

    template <integer_16_tr integer_p>
    inline integer_p
        Swap(integer_p bytes)
    {
        return ::_byteswap_ushort(bytes);
    }

    template <integer_32_tr integer_p>
    inline integer_p
        Swap(integer_p bytes)
    {
        return ::_byteswap_ulong(bytes);
    }

    template <integer_64_tr integer_p>
    inline integer_p
        Swap(integer_p bytes)
    {
        return ::_byteswap_uint64(bytes);
    }

#endif

}}}

namespace nkr { namespace os { namespace heap {

#if defined(nkr_IS_WINDOWS)

    // since C++11, using errno is thread-safe.

    inline maybe_t<allocator_err>
        Allocate(type_pointer_tr auto& units, count_t unit_count)
    {
        using units_t = std::remove_cvref_t<decltype(units)>;
        using unit_t = std::remove_pointer_t<units_t>;

        nkr_ASSERT_THAT(units == nullptr);
        nkr_ASSERT_THAT(unit_count <= std::numeric_limits<count_t>::max() / sizeof(unit_t));

        if (unit_count > 0) {
            errno = 0;
            units = static_cast<units_t>(::malloc(unit_count * sizeof(unit_t)));
            if (errno == 0) {
                return allocator_err::NONE;
            } else {
                units = nullptr;

                return allocator_err::OUT_OF_MEMORY;
            }
        } else {
            units = nullptr;

            return allocator_err::NONE;
        }
    }

    inline maybe_t<allocator_err>
        Reallocate(type_pointer_tr auto& units, count_t new_unit_count)
    {
        using units_t = std::remove_cvref_t<decltype(units)>;
        using unit_t = std::remove_pointer_t<units_t>;

        nkr_ASSERT_THAT(new_unit_count <= std::numeric_limits<count_t>::max() / sizeof(unit_t));

        if (units != nullptr || new_unit_count > 0) {
            errno = 0;
            units_t new_units = static_cast<units_t>(::realloc(const_cast<std::remove_cv_t<unit_t>*&>(units),
                                                               new_unit_count * sizeof(unit_t)));
            if (errno == 0) {
                units = new_units;

                return allocator_err::NONE;
            } else {
                return allocator_err::OUT_OF_MEMORY;
            }
        } else {
            return allocator_err::NONE;
        }
    }

    inline void_t
        Deallocate(type_pointer_tr auto& units)
    {
        using units_t = std::remove_cvref_t<decltype(units)>;
        using unit_t = std::remove_pointer_t<units_t>;

        if (units != nullptr) {
            ::free(const_cast<std::remove_cv_t<unit_t>*&>(units));
            units = nullptr;
        }
    }

    inline maybe_t<allocator_err>
        Allocate_Zeros(type_pointer_tr auto& units, count_t unit_count)
    {
        using units_t = std::remove_cvref_t<decltype(units)>;
        using unit_t = std::remove_pointer_t<units_t>;

        nkr_ASSERT_THAT(units == nullptr);
        nkr_ASSERT_THAT(unit_count <= std::numeric_limits<count_t>::max() / sizeof(unit_t));

        if (unit_count > 0) {
            errno = 0;
            units = static_cast<units_t>(::calloc(unit_count, sizeof(unit_t)));
            if (errno == 0) {
                return allocator_err::NONE;
            } else {
                units = nullptr;

                return allocator_err::OUT_OF_MEMORY;
            }
        } else {
            units = nullptr;

            return allocator_err::NONE;
        }
    }

    inline maybe_t<allocator_err>
        Reallocate_Zeros(type_pointer_tr auto& units, count_t new_unit_count)
    {
        using units_t = std::remove_cvref_t<decltype(units)>;
        using unit_t = std::remove_pointer_t<units_t>;

        nkr_ASSERT_THAT(new_unit_count <= std::numeric_limits<count_t>::max() / sizeof(unit_t));

        if (units != nullptr || new_unit_count > 0) {
            errno = 0;
            units_t new_units = static_cast<units_t>(::_recalloc(const_cast<std::remove_cv_t<unit_t>*&>(units),
                                                                 new_unit_count,
                                                                 sizeof(unit_t)));
            if (errno == 0) {
                units = new_units;

                return allocator_err::NONE;
            } else {
                return allocator_err::OUT_OF_MEMORY;
            }
        } else {
            return allocator_err::NONE;
        }
    }

    inline void_t
        Deallocate_Zeros(type_pointer_tr auto& units)
    {
        using units_t = std::remove_cvref_t<decltype(units)>;
        using unit_t = std::remove_pointer_t<units_t>;

        return Deallocate(units);
    }

#endif

}}}

namespace nkr { namespace os { namespace time {

#if defined(nkr_IS_WINDOWS)

    inline r64_t
        Microseconds()
    {
        LARGE_INTEGER frequency;
        LARGE_INTEGER counter;
        QueryPerformanceFrequency(&frequency);
        QueryPerformanceCounter(&counter);

        return (counter.QuadPart * 1000000.0) / frequency.QuadPart;
    }

    inline r64_t
        Milliseconds()
    {
        return Microseconds() * 0.001;
    }

    inline r64_t
        Seconds()
    {
        return Milliseconds() * 0.001;
    }

    template <typename functor_p, typename ...args_p>
    inline r64_t
        Test_In_Microseconds(count_t trial_count, functor_p functor, args_p&&... args)
    {
        r64_t total_time = 0.0;
        for (index_t idx = 0, end = trial_count; idx < end; idx += 1) {
            r64_t start_time = Microseconds();
            functor(std::forward<args_p>(args)...);
            total_time += Microseconds() - start_time;
        }

        return total_time / trial_count;
    }

    template <typename functor_p, typename ...args_p>
    inline r64_t
        Test_In_Milliseconds(count_t trial_count, functor_p functor, args_p&&... args)
    {
        r64_t total_time = 0.0;
        for (index_t idx = 0, end = trial_count; idx < end; idx += 1) {
            r64_t start_time = Milliseconds();
            functor(std::forward<args_p>(args)...);
            total_time += Milliseconds() - start_time;
        }

        return total_time / trial_count;
    }

#endif

}}}
