/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsic.h"
#include "nkr/traits.h"

namespace nkr { namespace os { namespace atomic {

    template <integral_tr atom_p>
    inline atom_p   Access(const volatile atom_p& atom);
    template <pointer_tr atom_p>
    inline atom_p   Access(const volatile atom_p& atom);

    template <integral_tr atom_p>
    inline atom_p   Access_Add(const volatile atom_p& atom, integral_tr auto with);
    template <pointer_tr atom_p>
    inline atom_p   Access_Add(const volatile atom_p& atom, integral_tr auto with);

    template <integral_tr atom_p>
    inline atom_p   Access_Subtract(const volatile atom_p& atom, integral_tr auto with);
    template <pointer_tr atom_p>
    inline atom_p   Access_Subtract(const volatile atom_p& atom, integral_tr auto with);

    template <integral_tr atom_p>
    inline atom_p   Access_Or(const volatile atom_p& atom, integral_tr auto with);

    template <integral_tr atom_p>
    inline atom_p   Access_And(const volatile atom_p& atom, integral_tr auto with);

    template <integral_tr atom_p>
    inline atom_p   Access_Xor(const volatile atom_p& atom, integral_tr auto with);

    template <integral_tr atom_p>
    inline atom_p   Assign(volatile atom_p& atom, integral_tr auto with);
    template <pointer_tr atom_p>
    inline atom_p   Assign(volatile atom_p& atom, pointer_tr auto with);

    template <integral_tr atom_p>
    inline atom_p   Assign_Add(volatile atom_p& atom, integral_tr auto with);
    template <pointer_tr atom_p>
    inline atom_p   Assign_Add(volatile atom_p& atom, integral_tr auto with);

    template <integral_tr atom_p>
    inline atom_p   Assign_Subtract(volatile atom_p& atom, integral_tr auto with);
    template <pointer_tr atom_p>
    inline atom_p   Assign_Subtract(volatile atom_p& atom, integral_tr auto with);

    template <integral_tr atom_p>
    inline atom_p   Assign_Or(volatile atom_p& atom, integral_tr auto with);

    template <integral_tr atom_p>
    inline atom_p   Assign_And(volatile atom_p& atom, integral_tr auto with);

    template <integral_tr atom_p>
    inline atom_p   Assign_Xor(volatile atom_p& atom, integral_tr auto with);

    template <integral_8_tr atom_p>
    inline atom_p   Exchange(volatile atom_p& atom, integral_tr auto with);
    template <integral_16_tr atom_p>
    inline atom_p   Exchange(volatile atom_p& atom, integral_tr auto with);
    template <integral_32_tr atom_p>
    inline atom_p   Exchange(volatile atom_p& atom, integral_tr auto with);
    template <integral_64_tr atom_p>
    inline atom_p   Exchange(volatile atom_p& atom, integral_tr auto with);
    template <pointer_tr atom_p>
    inline atom_p   Exchange(volatile atom_p& atom, pointer_tr auto with);

    template <integral_8_tr atom_p>
    inline atom_p   Exchange_If_Equals(volatile atom_p& atom, integral_tr auto with, integral_tr auto target);
    template <integral_16_tr atom_p>
    inline atom_p   Exchange_If_Equals(volatile atom_p& atom, integral_tr auto with, integral_tr auto target);
    template <integral_32_tr atom_p>
    inline atom_p   Exchange_If_Equals(volatile atom_p& atom, integral_tr auto with, integral_tr auto target);
    template <integral_64_tr atom_p>
    inline atom_p   Exchange_If_Equals(volatile atom_p& atom, integral_tr auto with, integral_tr auto target);
    template <pointer_tr atom_p>
    inline atom_p   Exchange_If_Equals(volatile atom_p& atom, pointer_tr auto with, pointer_tr auto target);

    template <integral_8_tr atom_p>
    inline atom_p   Exchange_Add(volatile atom_p& atom, integral_tr auto with);
    template <integral_16_tr atom_p>
    inline atom_p   Exchange_Add(volatile atom_p& atom, integral_tr auto with);
    template <integral_32_tr atom_p>
    inline atom_p   Exchange_Add(volatile atom_p& atom, integral_tr auto with);
    template <integral_64_tr atom_p>
    inline atom_p   Exchange_Add(volatile atom_p& atom, integral_tr auto with);
    template <pointer_tr atom_p>
    inline atom_p   Exchange_Add(volatile atom_p& atom, integral_tr auto with);

    template <integral_8_tr atom_p>
    inline atom_p   Exchange_Subtract(volatile atom_p& atom, integral_tr auto with);
    template <integral_16_tr atom_p>
    inline atom_p   Exchange_Subtract(volatile atom_p& atom, integral_tr auto with);
    template <integral_32_tr atom_p>
    inline atom_p   Exchange_Subtract(volatile atom_p& atom, integral_tr auto with);
    template <integral_64_tr atom_p>
    inline atom_p   Exchange_Subtract(volatile atom_p& atom, integral_tr auto with);
    template <pointer_tr atom_p>
    inline atom_p   Exchange_Subtract(volatile atom_p& atom, integral_tr auto with);

    template <integral_8_tr atom_p>
    inline atom_p   Exchange_Or(volatile atom_p& atom, integral_tr auto with);
    template <integral_16_tr atom_p>
    inline atom_p   Exchange_Or(volatile atom_p& atom, integral_tr auto with);
    template <integral_32_tr atom_p>
    inline atom_p   Exchange_Or(volatile atom_p& atom, integral_tr auto with);
    template <integral_64_tr atom_p>
    inline atom_p   Exchange_Or(volatile atom_p& atom, integral_tr auto with);

    template <integral_8_tr atom_p>
    inline atom_p   Exchange_And(volatile atom_p& atom, integral_tr auto with);
    template <integral_16_tr atom_p>
    inline atom_p   Exchange_And(volatile atom_p& atom, integral_tr auto with);
    template <integral_32_tr atom_p>
    inline atom_p   Exchange_And(volatile atom_p& atom, integral_tr auto with);
    template <integral_64_tr atom_p>
    inline atom_p   Exchange_And(volatile atom_p& atom, integral_tr auto with);

    template <integral_8_tr atom_p>
    inline atom_p   Exchange_Xor(volatile atom_p& atom, integral_tr auto with);
    template <integral_16_tr atom_p>
    inline atom_p   Exchange_Xor(volatile atom_p& atom, integral_tr auto with);
    template <integral_32_tr atom_p>
    inline atom_p   Exchange_Xor(volatile atom_p& atom, integral_tr auto with);
    template <integral_64_tr atom_p>
    inline atom_p   Exchange_Xor(volatile atom_p& atom, integral_tr auto with);

}}}

namespace nkr { namespace os { namespace endian {

    bool_t          Is_Big();
    bool_t          Is_Little();

    template <integral_16_tr i16_p>
    inline i16_p    Swap(i16_p bytes);
    template <integral_32_tr i32_p>
    inline i32_p    Swap(i32_p bytes);
    template <integral_64_tr i64_p>
    inline i64_p    Swap(i64_p bytes);

}}}

namespace nkr { namespace os { namespace heap {

/// @name allocation
/// @copydoc doc_nkr_os_heap_group_allocation
/// @{
    byte_t* Allocate(count_t byte_count);                       ///< @copydoc doc_nkr_os_heap_Allocate
    bool_t  Reallocate(byte_t*& bytes, count_t new_byte_count); ///< @copydoc doc_nkr_os_heap_Reallocate
    void_t  Deallocate(byte_t*& bytes);                         ///< @copydoc doc_nkr_os_heap_Deallocate
/// @}

/// @name zero-initialized allocation
/// @copydoc doc_nkr_os_heap_group_allocation_zero
/// @{
    byte_t* Allocate_Zeros(count_t byte_count);                         ///< @copydoc doc_nkr_os_heap_Allocate_Zeros
    bool_t  Reallocate_Zeros(byte_t*& bytes, count_t new_byte_count);   ///< @copydoc doc_nkr_os_heap_Reallocate_Zeros
    void_t  Deallocate_Zeros(byte_t*& bytes);                           ///< @copydoc doc_nkr_os_heap_Deallocate_Zeros
/// @}

}}}

#include "nkr/os.inl"
