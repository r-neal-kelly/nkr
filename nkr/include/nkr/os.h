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
    inline atom_p   Assign(volatile atom_p& atom, integral_tr auto with);
    template <pointer_tr atom_p>
    inline atom_p   Assign(volatile atom_p& atom, pointer_tr auto with);
    template <integral_8_tr atom_p>
    inline atom_p   Exchange_Assign(volatile atom_p& atom, integral_tr auto with);
    template <integral_16_tr atom_p>
    inline atom_p   Exchange_Assign(volatile atom_p& atom, integral_tr auto with);
    template <integral_32_tr atom_p>
    inline atom_p   Exchange_Assign(volatile atom_p& atom, integral_tr auto with);
    template <integral_64_tr atom_p>
    inline atom_p   Exchange_Assign(volatile atom_p& atom, integral_tr auto with);
    template <pointer_tr atom_p>
    inline atom_p   Exchange_Assign(volatile atom_p& atom, pointer_tr auto with);
    template <integral_8_tr atom_p>
    inline atom_p   Exchange_Assign_If_Equals(volatile atom_p& atom, integral_tr auto with, integral_tr auto target);
    template <integral_16_tr atom_p>
    inline atom_p   Exchange_Assign_If_Equals(volatile atom_p& atom, integral_tr auto with, integral_tr auto target);
    template <integral_32_tr atom_p>
    inline atom_p   Exchange_Assign_If_Equals(volatile atom_p& atom, integral_tr auto with, integral_tr auto target);
    template <integral_64_tr atom_p>
    inline atom_p   Exchange_Assign_If_Equals(volatile atom_p& atom, integral_tr auto with, integral_tr auto target);
    template <pointer_tr atom_p>
    inline atom_p   Exchange_Assign_If_Equals(volatile atom_p& atom, pointer_tr auto with, pointer_tr auto target);

    template <integral_tr atom_p>
    inline atom_p   Add(volatile atom_p& atom, integral_tr auto with);
    template <pointer_tr atom_p>
    inline atom_p   Add(volatile atom_p& atom, integral_tr auto with);
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

    template <integral_tr atom_p>
    inline atom_p   Subtract(volatile atom_p& atom, integral_tr auto with);
    template <pointer_tr atom_p>
    inline atom_p   Subtract(volatile atom_p& atom, integral_tr auto with);
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

    template <integral_tr atom_p>
    inline atom_p   Or(volatile atom_p& atom, integral_tr auto with);
    template <integral_8_tr atom_p>
    inline atom_p   Exchange_Or(volatile atom_p& atom, integral_tr auto with);
    template <integral_16_tr atom_p>
    inline atom_p   Exchange_Or(volatile atom_p& atom, integral_tr auto with);
    template <integral_32_tr atom_p>
    inline atom_p   Exchange_Or(volatile atom_p& atom, integral_tr auto with);
    template <integral_64_tr atom_p>
    inline atom_p   Exchange_Or(volatile atom_p& atom, integral_tr auto with);

    template <integral_tr atom_p>
    inline atom_p   And(volatile atom_p& atom, integral_tr auto with);
    template <integral_8_tr atom_p>
    inline atom_p   Exchange_And(volatile atom_p& atom, integral_tr auto with);
    template <integral_16_tr atom_p>
    inline atom_p   Exchange_And(volatile atom_p& atom, integral_tr auto with);
    template <integral_32_tr atom_p>
    inline atom_p   Exchange_And(volatile atom_p& atom, integral_tr auto with);
    template <integral_64_tr atom_p>
    inline atom_p   Exchange_And(volatile atom_p& atom, integral_tr auto with);

    template <integral_tr atom_p>
    inline atom_p   Xor(volatile atom_p& atom, integral_tr auto with);
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

    inline u16_t    Swap(u16_t bytes);
    inline u32_t    Swap(u32_t bytes);
    inline u64_t    Swap(u64_t bytes);

}}}

namespace nkr { namespace os { namespace heap {

    byte_t* Allocate(count_t byte_count);
    byte_t* Reallocate(byte_t* bytes, count_t new_byte_count);
    void_t  Deallocate(byte_t* bytes);

    byte_t* Callocate(count_t byte_count);
    byte_t* Recallocate(byte_t* bytes, count_t new_byte_count);
    void_t  Decallocate(byte_t* bytes);

}}}

#include "nkr/os.inl"
