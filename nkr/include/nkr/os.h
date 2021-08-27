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

    /// @name Access
    /// @copydoc doc_nkr_os_atomic_group_Access
    /// @{
    boolean_tr auto Access(const volatile boolean_tr auto& atom);                                   ///< @copydoc _f108db58_8738_44fc_8660_a9f2806661f3
    integer_tr auto Access(const volatile integer_tr auto& atom);                                   ///< @copydoc doc_nkr_os_atomic_Access
    pointer_tr auto Access(const volatile pointer_tr auto& atom);                                   ///< @copydoc doc_nkr_os_atomic_Access

    integer_tr auto Access_Add(const volatile integer_tr auto& atom, integer_tr auto with);         ///< @copydoc doc_nkr_os_atomic_Access_Add
    pointer_tr auto Access_Add(const volatile pointer_tr auto& atom, integer_tr auto with);         ///< @copydoc doc_nkr_os_atomic_Access_Add

    integer_tr auto Access_Subtract(const volatile integer_tr auto& atom, integer_tr auto with);    ///< @copydoc doc_nkr_os_atomic_Access_Subtract
    pointer_tr auto Access_Subtract(const volatile pointer_tr auto& atom, integer_tr auto with);    ///< @copydoc doc_nkr_os_atomic_Access_Subtract

    integer_tr auto Access_Or(const volatile integer_tr auto& atom, integer_tr auto with);          ///< @copydoc doc_nkr_os_atomic_Access_Or

    integer_tr auto Access_And(const volatile integer_tr auto& atom, integer_tr auto with);         ///< @copydoc doc_nkr_os_atomic_Access_And

    integer_tr auto Access_Xor(const volatile integer_tr auto& atom, integer_tr auto with);         ///< @copydoc doc_nkr_os_atomic_Access_Xor
    /// @}


    /// @name Assign
    /// @copydoc doc_nkr_os_atomic_group_Assign
    /// @{
    boolean_tr auto Assign(volatile boolean_tr auto& atom, bool_t with);                    ///< @copydoc _5c4929b4_7b2c_49b7_946a_1dc7085f362c
    integer_tr auto Assign(volatile integer_tr auto& atom, integer_tr auto with);           ///< @copydoc doc_nkr_os_atomic_Assign
    pointer_tr auto Assign(volatile pointer_tr auto& atom, pointer_tr auto with);           ///< @copydoc doc_nkr_os_atomic_Assign

    integer_tr auto Assign_Add(volatile integer_tr auto& atom, integer_tr auto with);       ///< @copydoc doc_nkr_os_atomic_Assign_Add
    pointer_tr auto Assign_Add(volatile pointer_tr auto& atom, integer_tr auto with);       ///< @copydoc doc_nkr_os_atomic_Assign_Add

    integer_tr auto Assign_Subtract(volatile integer_tr auto& atom, integer_tr auto with);  ///< @copydoc doc_nkr_os_atomic_Assign_Subtract
    pointer_tr auto Assign_Subtract(volatile pointer_tr auto& atom, integer_tr auto with);  ///< @copydoc doc_nkr_os_atomic_Assign_Subtract

    integer_tr auto Assign_Or(volatile integer_tr auto& atom, integer_tr auto with);        ///< @copydoc doc_nkr_os_atomic_Assign_Or

    integer_tr auto Assign_And(volatile integer_tr auto& atom, integer_tr auto with);       ///< @copydoc doc_nkr_os_atomic_Assign_And

    integer_tr auto Assign_Xor(volatile integer_tr auto& atom, integer_tr auto with);       ///< @copydoc doc_nkr_os_atomic_Assign_Xor
    /// @}
    

    /// @name Exchange
    /// @copydoc doc_nkr_os_atomic_group_Exchange
    /// @{
    boolean_tr auto     Exchange(volatile boolean_tr auto& atom, bool_t with);                                                  ///< @copydoc _acf46593_b662_4d8a_9596_25f347ef5cbf
    integer_8_tr auto   Exchange(volatile integer_8_tr auto& atom, integer_tr auto with);                                       ///< @copydoc doc_nkr_os_atomic_Exchange
    integer_16_tr auto  Exchange(volatile integer_16_tr auto& atom, integer_tr auto with);                                      ///< @copydoc doc_nkr_os_atomic_Exchange
    integer_32_tr auto  Exchange(volatile integer_32_tr auto& atom, integer_tr auto with);                                      ///< @copydoc doc_nkr_os_atomic_Exchange
    integer_64_tr auto  Exchange(volatile integer_64_tr auto& atom, integer_tr auto with);                                      ///< @copydoc doc_nkr_os_atomic_Exchange
    pointer_tr auto     Exchange(volatile pointer_tr auto& atom, pointer_tr auto with);                                         ///< @copydoc doc_nkr_os_atomic_Exchange

    boolean_tr auto     Exchange_If_Equals(volatile boolean_tr auto& atom, bool_t with, bool_t target);                         ///< @copydoc _6705c0d6_baf4_4cd6_b4bf_727403e9d2c2
    integer_8_tr auto   Exchange_If_Equals(volatile integer_8_tr auto& atom, integer_tr auto with, integer_tr auto target);     ///< @copydoc doc_nkr_os_atomic_Exchange_If_Equals
    integer_16_tr auto  Exchange_If_Equals(volatile integer_16_tr auto& atom, integer_tr auto with, integer_tr auto target);    ///< @copydoc doc_nkr_os_atomic_Exchange_If_Equals
    integer_32_tr auto  Exchange_If_Equals(volatile integer_32_tr auto& atom, integer_tr auto with, integer_tr auto target);    ///< @copydoc doc_nkr_os_atomic_Exchange_If_Equals
    integer_64_tr auto  Exchange_If_Equals(volatile integer_64_tr auto& atom, integer_tr auto with, integer_tr auto target);    ///< @copydoc doc_nkr_os_atomic_Exchange_If_Equals
    pointer_tr auto     Exchange_If_Equals(volatile pointer_tr auto& atom, pointer_tr auto with, pointer_tr auto target);       ///< @copydoc doc_nkr_os_atomic_Exchange_If_Equals

    integer_8_tr auto   Exchange_Add(volatile integer_8_tr auto& atom, integer_tr auto with);                                   ///< @copydoc doc_nkr_os_atomic_Exchange_Add
    integer_16_tr auto  Exchange_Add(volatile integer_16_tr auto& atom, integer_tr auto with);                                  ///< @copydoc doc_nkr_os_atomic_Exchange_Add
    integer_32_tr auto  Exchange_Add(volatile integer_32_tr auto& atom, integer_tr auto with);                                  ///< @copydoc doc_nkr_os_atomic_Exchange_Add
    integer_64_tr auto  Exchange_Add(volatile integer_64_tr auto& atom, integer_tr auto with);                                  ///< @copydoc doc_nkr_os_atomic_Exchange_Add
    pointer_tr auto     Exchange_Add(volatile pointer_tr auto& atom, integer_tr auto with);                                     ///< @copydoc doc_nkr_os_atomic_Exchange_Add

    integer_8_tr auto   Exchange_Subtract(volatile integer_8_tr auto& atom, integer_tr auto with);                              ///< @copydoc doc_nkr_os_atomic_Exchange_Subtract
    integer_16_tr auto  Exchange_Subtract(volatile integer_16_tr auto& atom, integer_tr auto with);                             ///< @copydoc doc_nkr_os_atomic_Exchange_Subtract
    integer_32_tr auto  Exchange_Subtract(volatile integer_32_tr auto& atom, integer_tr auto with);                             ///< @copydoc doc_nkr_os_atomic_Exchange_Subtract
    integer_64_tr auto  Exchange_Subtract(volatile integer_64_tr auto& atom, integer_tr auto with);                             ///< @copydoc doc_nkr_os_atomic_Exchange_Subtract
    pointer_tr auto     Exchange_Subtract(volatile pointer_tr auto& atom, integer_tr auto with);                                ///< @copydoc doc_nkr_os_atomic_Exchange_Subtract

    integer_8_tr auto   Exchange_Or(volatile integer_8_tr auto& atom, integer_tr auto with);                                    ///< @copydoc doc_nkr_os_atomic_Exchange_Or
    integer_16_tr auto  Exchange_Or(volatile integer_16_tr auto& atom, integer_tr auto with);                                   ///< @copydoc doc_nkr_os_atomic_Exchange_Or
    integer_32_tr auto  Exchange_Or(volatile integer_32_tr auto& atom, integer_tr auto with);                                   ///< @copydoc doc_nkr_os_atomic_Exchange_Or
    integer_64_tr auto  Exchange_Or(volatile integer_64_tr auto& atom, integer_tr auto with);                                   ///< @copydoc doc_nkr_os_atomic_Exchange_Or

    integer_8_tr auto   Exchange_And(volatile integer_8_tr auto& atom, integer_tr auto with);                                   ///< @copydoc doc_nkr_os_atomic_Exchange_And
    integer_16_tr auto  Exchange_And(volatile integer_16_tr auto& atom, integer_tr auto with);                                  ///< @copydoc doc_nkr_os_atomic_Exchange_And
    integer_32_tr auto  Exchange_And(volatile integer_32_tr auto& atom, integer_tr auto with);                                  ///< @copydoc doc_nkr_os_atomic_Exchange_And
    integer_64_tr auto  Exchange_And(volatile integer_64_tr auto& atom, integer_tr auto with);                                  ///< @copydoc doc_nkr_os_atomic_Exchange_And

    integer_8_tr auto   Exchange_Xor(volatile integer_8_tr auto& atom, integer_tr auto with);                                   ///< @copydoc doc_nkr_os_atomic_Exchange_Xor
    integer_16_tr auto  Exchange_Xor(volatile integer_16_tr auto& atom, integer_tr auto with);                                  ///< @copydoc doc_nkr_os_atomic_Exchange_Xor
    integer_32_tr auto  Exchange_Xor(volatile integer_32_tr auto& atom, integer_tr auto with);                                  ///< @copydoc doc_nkr_os_atomic_Exchange_Xor
    integer_64_tr auto  Exchange_Xor(volatile integer_64_tr auto& atom, integer_tr auto with);                                  ///< @copydoc doc_nkr_os_atomic_Exchange_Xor
    /// @}

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
    integer_16_tr auto  Swap(integer_16_tr auto bytes); ///< @copydoc doc_nkr_os_endian_Swap_16
    integer_32_tr auto  Swap(integer_32_tr auto bytes); ///< @copydoc doc_nkr_os_endian_Swap_32
    integer_64_tr auto  Swap(integer_64_tr auto bytes); ///< @copydoc doc_nkr_os_endian_Swap_64
    /// @}

}}}

namespace nkr { namespace os { namespace heap {

    /// @name allocation
    /// @copydoc _30c0ffe4_d85f_45e5_ab29_bd3f18629cb9
    /// @{
    bool_t  Allocate(sized_tr auto*& units, count_t unit_count);        ///< @copydoc _52a0d839_49c8_4d77_93b1_353137fecd3b
    bool_t  Reallocate(sized_tr auto*& units, count_t new_unit_count);  ///< @copydoc _06fa627b_ba42_4b70_b0dd_66146e6d863a
    void_t  Deallocate(sized_tr auto*& units);                          ///< @copydoc _de0237bf_9b0a_47fc_a5ab_99f21504f570
    /// @}
    
    /// @name zero-initialized allocation
    /// @copydoc _eca47636_431b_4d2a_a102_679075b3cf17
    /// @{
    bool_t  Allocate_Zeros(sized_tr auto*& units, count_t unit_count);          ///< @copydoc _9c5a7296_5644_47bf_bd3f_ff7de3518ce9
    bool_t  Reallocate_Zeros(sized_tr auto*& units, count_t new_unit_count);    ///< @copydoc _7d7887a0_3e2d_4502_af8c_d409aae73f0b
    void_t  Deallocate_Zeros(sized_tr auto*& units);                            ///< @copydoc _04d9a3fe_30b3_4ae2_bbc4_2a3cfc4768d6
    /// @}

}}}

#include "nkr/os.inl"
