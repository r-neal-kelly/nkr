/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsics.h"
#include "nkr/traits.h"


namespace nkr {

    /// @ingroup namespaces
    /// @copydoc doc_nkr_os
    namespace os {

        /// @ingroup namespaces
        /// @copydoc doc_nkr_os_atomic
        namespace atomic {}

        /// @ingroup namespaces
        /// @copydoc doc_nkr_os_endian
        namespace endian {}

        /// @ingroup namespaces
        /// @copydoc doc_nkr_os_heap
        namespace heap {}

    }

}

namespace nkr { namespace os { namespace atomic {

    template <integer_tr atom_p>
    inline atom_p   Access(const volatile atom_p& atom);
    template <pointer_tr atom_p>
    inline atom_p   Access(const volatile atom_p& atom);

    template <integer_tr atom_p>
    inline atom_p   Access_Add(const volatile atom_p& atom, integer_tr auto with);
    template <pointer_tr atom_p>
    inline atom_p   Access_Add(const volatile atom_p& atom, integer_tr auto with);

    template <integer_tr atom_p>
    inline atom_p   Access_Subtract(const volatile atom_p& atom, integer_tr auto with);
    template <pointer_tr atom_p>
    inline atom_p   Access_Subtract(const volatile atom_p& atom, integer_tr auto with);

    template <integer_tr atom_p>
    inline atom_p   Access_Or(const volatile atom_p& atom, integer_tr auto with);

    template <integer_tr atom_p>
    inline atom_p   Access_And(const volatile atom_p& atom, integer_tr auto with);

    template <integer_tr atom_p>
    inline atom_p   Access_Xor(const volatile atom_p& atom, integer_tr auto with);

    template <integer_tr atom_p>
    inline atom_p   Assign(volatile atom_p& atom, integer_tr auto with);
    template <pointer_tr atom_p>
    inline atom_p   Assign(volatile atom_p& atom, pointer_tr auto with);

    template <integer_tr atom_p>
    inline atom_p   Assign_Add(volatile atom_p& atom, integer_tr auto with);
    template <pointer_tr atom_p>
    inline atom_p   Assign_Add(volatile atom_p& atom, integer_tr auto with);

    template <integer_tr atom_p>
    inline atom_p   Assign_Subtract(volatile atom_p& atom, integer_tr auto with);
    template <pointer_tr atom_p>
    inline atom_p   Assign_Subtract(volatile atom_p& atom, integer_tr auto with);

    template <integer_tr atom_p>
    inline atom_p   Assign_Or(volatile atom_p& atom, integer_tr auto with);

    template <integer_tr atom_p>
    inline atom_p   Assign_And(volatile atom_p& atom, integer_tr auto with);

    template <integer_tr atom_p>
    inline atom_p   Assign_Xor(volatile atom_p& atom, integer_tr auto with);

    template <integer_8_tr atom_p>
    inline atom_p   Exchange(volatile atom_p& atom, integer_tr auto with);
    template <integer_16_tr atom_p>
    inline atom_p   Exchange(volatile atom_p& atom, integer_tr auto with);
    template <integer_32_tr atom_p>
    inline atom_p   Exchange(volatile atom_p& atom, integer_tr auto with);
    template <integer_64_tr atom_p>
    inline atom_p   Exchange(volatile atom_p& atom, integer_tr auto with);
    template <pointer_tr atom_p>
    inline atom_p   Exchange(volatile atom_p& atom, pointer_tr auto with);

    template <integer_8_tr atom_p>
    inline atom_p   Exchange_If_Equals(volatile atom_p& atom, integer_tr auto with, integer_tr auto target);
    template <integer_16_tr atom_p>
    inline atom_p   Exchange_If_Equals(volatile atom_p& atom, integer_tr auto with, integer_tr auto target);
    template <integer_32_tr atom_p>
    inline atom_p   Exchange_If_Equals(volatile atom_p& atom, integer_tr auto with, integer_tr auto target);
    template <integer_64_tr atom_p>
    inline atom_p   Exchange_If_Equals(volatile atom_p& atom, integer_tr auto with, integer_tr auto target);
    template <pointer_tr atom_p>
    inline atom_p   Exchange_If_Equals(volatile atom_p& atom, pointer_tr auto with, pointer_tr auto target);

    template <integer_8_tr atom_p>
    inline atom_p   Exchange_Add(volatile atom_p& atom, integer_tr auto with);
    template <integer_16_tr atom_p>
    inline atom_p   Exchange_Add(volatile atom_p& atom, integer_tr auto with);
    template <integer_32_tr atom_p>
    inline atom_p   Exchange_Add(volatile atom_p& atom, integer_tr auto with);
    template <integer_64_tr atom_p>
    inline atom_p   Exchange_Add(volatile atom_p& atom, integer_tr auto with);
    template <pointer_tr atom_p>
    inline atom_p   Exchange_Add(volatile atom_p& atom, integer_tr auto with);

    template <integer_8_tr atom_p>
    inline atom_p   Exchange_Subtract(volatile atom_p& atom, integer_tr auto with);
    template <integer_16_tr atom_p>
    inline atom_p   Exchange_Subtract(volatile atom_p& atom, integer_tr auto with);
    template <integer_32_tr atom_p>
    inline atom_p   Exchange_Subtract(volatile atom_p& atom, integer_tr auto with);
    template <integer_64_tr atom_p>
    inline atom_p   Exchange_Subtract(volatile atom_p& atom, integer_tr auto with);
    template <pointer_tr atom_p>
    inline atom_p   Exchange_Subtract(volatile atom_p& atom, integer_tr auto with);

    template <integer_8_tr atom_p>
    inline atom_p   Exchange_Or(volatile atom_p& atom, integer_tr auto with);
    template <integer_16_tr atom_p>
    inline atom_p   Exchange_Or(volatile atom_p& atom, integer_tr auto with);
    template <integer_32_tr atom_p>
    inline atom_p   Exchange_Or(volatile atom_p& atom, integer_tr auto with);
    template <integer_64_tr atom_p>
    inline atom_p   Exchange_Or(volatile atom_p& atom, integer_tr auto with);

    template <integer_8_tr atom_p>
    inline atom_p   Exchange_And(volatile atom_p& atom, integer_tr auto with);
    template <integer_16_tr atom_p>
    inline atom_p   Exchange_And(volatile atom_p& atom, integer_tr auto with);
    template <integer_32_tr atom_p>
    inline atom_p   Exchange_And(volatile atom_p& atom, integer_tr auto with);
    template <integer_64_tr atom_p>
    inline atom_p   Exchange_And(volatile atom_p& atom, integer_tr auto with);

    template <integer_8_tr atom_p>
    inline atom_p   Exchange_Xor(volatile atom_p& atom, integer_tr auto with);
    template <integer_16_tr atom_p>
    inline atom_p   Exchange_Xor(volatile atom_p& atom, integer_tr auto with);
    template <integer_32_tr atom_p>
    inline atom_p   Exchange_Xor(volatile atom_p& atom, integer_tr auto with);
    template <integer_64_tr atom_p>
    inline atom_p   Exchange_Xor(volatile atom_p& atom, integer_tr auto with);

}}}

namespace nkr { namespace os { namespace endian {

    /// @name attain info
    /// @copydoc doc_nkr_os_endian_group_info
    /// @{
    bool_t  Is_Big();       ///< @copydoc doc_nkr_os_endian_Is_Big
    bool_t  Is_Little();    ///< @copydoc doc_nkr_os_endian_Is_Little
    /// @}


    /// @name swap compound integers
    /// @copydoc doc_nkr_os_endian_group_swap
    /// @{
    inline integer_16_tr auto   Swap(integer_16_tr auto bytes); ///< @copydoc doc_nkr_os_endian_Swap_16
    inline integer_32_tr auto   Swap(integer_32_tr auto bytes); ///< @copydoc doc_nkr_os_endian_Swap_32
    inline integer_64_tr auto   Swap(integer_64_tr auto bytes); ///< @copydoc doc_nkr_os_endian_Swap_64
    /// @}

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
