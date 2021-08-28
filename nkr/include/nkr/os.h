/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsics.h"
#include "nkr/traits.h"

namespace nkr {

    /// @ingroup _d1cd4369_e0f4_4062_8f58_611395da215e
    /// @copydoc _ae5b9a84_c87b_4c0a_b714_4933761921d7
    namespace os {

        /// @ingroup _d1cd4369_e0f4_4062_8f58_611395da215e
        /// @copydoc _a6ff4022_7389_4e35_b146_066ce313290e
        namespace atomic {}

        
        /// @ingroup _d1cd4369_e0f4_4062_8f58_611395da215e
        /// @copydoc _652312c1_72a2_4b36_88ab_aee6adf8e9c9
        namespace endian {}

        
        /// @ingroup _d1cd4369_e0f4_4062_8f58_611395da215e
        /// @copydoc _a6c4699b_8fe4_4664_ac57_062765decc2b
        namespace heap {}

    }

}

namespace nkr { namespace os { namespace atomic {

    /// @name Access
    /// @copydoc _ebc609cf_5026_47e9_87e7_c8ea9ecc71a9
    /// @{
    boolean_tr auto Access(const volatile boolean_tr auto& atom);                                   ///< @copydoc _f108db58_8738_44fc_8660_a9f2806661f3
    integer_tr auto Access(const volatile integer_tr auto& atom);                                   ///< @copydoc doc_nkr_os_atomic_Access
    float_tr auto   Access(const volatile float_tr auto& atom);                                     ///< @copydoc doc_nkr_os_atomic_Access
    pointer_tr auto Access(const volatile pointer_tr auto& atom);                                   ///< @copydoc doc_nkr_os_atomic_Access

    integer_tr auto Access_Add(const volatile integer_tr auto& atom, integer_tr auto with);         ///< @copydoc doc_nkr_os_atomic_Access_Add
    float_tr auto   Access_Add(const volatile float_tr auto& atom, float_tr auto with);             ///< @copydoc doc_nkr_os_atomic_Access_Add
    pointer_tr auto Access_Add(const volatile pointer_tr auto& atom, integer_tr auto with);         ///< @copydoc doc_nkr_os_atomic_Access_Add

    integer_tr auto Access_Subtract(const volatile integer_tr auto& atom, integer_tr auto with);    ///< @copydoc doc_nkr_os_atomic_Access_Subtract
    float_tr auto   Access_Subtract(const volatile float_tr auto& atom, float_tr auto with);        ///< @copydoc doc_nkr_os_atomic_Access_Subtract
    pointer_tr auto Access_Subtract(const volatile pointer_tr auto& atom, integer_tr auto with);    ///< @copydoc doc_nkr_os_atomic_Access_Subtract

    integer_tr auto Access_Multiply(const volatile integer_tr auto& atom, integer_tr auto with);    ///< @copydoc 
    float_tr auto   Access_Multiply(const volatile float_tr auto& atom, float_tr auto with);        ///< @copydoc 

    integer_tr auto Access_Divide(const volatile integer_tr auto& atom, integer_tr auto with);      ///< @copydoc 
    float_tr auto   Access_Divide(const volatile float_tr auto& atom, float_tr auto with);          ///< @copydoc 

    integer_tr auto Access_Modulus(const volatile integer_tr auto& atom, integer_tr auto with);     ///< @copydoc 

    integer_tr auto Access_Or(const volatile integer_tr auto& atom, integer_tr auto with);          ///< @copydoc doc_nkr_os_atomic_Access_Or

    integer_tr auto Access_And(const volatile integer_tr auto& atom, integer_tr auto with);         ///< @copydoc doc_nkr_os_atomic_Access_And

    integer_tr auto Access_Xor(const volatile integer_tr auto& atom, integer_tr auto with);         ///< @copydoc doc_nkr_os_atomic_Access_Xor

    integer_tr auto Access_Left_Shift(const volatile integer_tr auto& atom, integer_tr auto with);  ///< @copydoc 

    integer_tr auto Access_Right_Shift(const volatile integer_tr auto& atom, integer_tr auto with); ///< @copydoc 
    /// @}

    /// @name Assign
    /// @copydoc _d42247f7_a7b1_442f_beef_c88857ee5682
    /// @{
    boolean_tr auto Assign(volatile boolean_tr auto& atom, boolean_tr auto with);           ///< @copydoc _5c4929b4_7b2c_49b7_946a_1dc7085f362c
    integer_tr auto Assign(volatile integer_tr auto& atom, integer_tr auto with);           ///< @copydoc doc_nkr_os_atomic_Assign
    float_tr auto   Assign(volatile float_tr auto& atom, float_tr auto with);               ///< @copydoc doc_nkr_os_atomic_Assign
    pointer_tr auto Assign(volatile pointer_tr auto& atom, pointer_tr auto with);           ///< @copydoc doc_nkr_os_atomic_Assign

    integer_tr auto Assign_Add(volatile integer_tr auto& atom, integer_tr auto with);       ///< @copydoc doc_nkr_os_atomic_Assign_Add
    float_tr auto   Assign_Add(volatile float_tr auto& atom, float_tr auto with);           ///< @copydoc doc_nkr_os_atomic_Assign_Add
    pointer_tr auto Assign_Add(volatile pointer_tr auto& atom, integer_tr auto with);       ///< @copydoc doc_nkr_os_atomic_Assign_Add

    integer_tr auto Assign_Subtract(volatile integer_tr auto& atom, integer_tr auto with);  ///< @copydoc doc_nkr_os_atomic_Assign_Subtract
    float_tr auto   Assign_Subtract(volatile float_tr auto& atom, float_tr auto with);      ///< @copydoc doc_nkr_os_atomic_Assign_Subtract
    pointer_tr auto Assign_Subtract(volatile pointer_tr auto& atom, integer_tr auto with);  ///< @copydoc doc_nkr_os_atomic_Assign_Subtract

    integer_tr auto Assign_Multiply(volatile integer_tr auto& atom, integer_tr auto with);  ///< @copydoc 
    float_tr auto   Assign_Multiply(volatile float_tr auto& atom, float_tr auto with);      ///< @copydoc 

    integer_tr auto Assign_Divide(volatile integer_tr auto& atom, integer_tr auto with);    ///< @copydoc 
    float_tr auto   Assign_Divide(volatile float_tr auto& atom, float_tr auto with);        ///< @copydoc 

    integer_tr auto Assign_Modulus(volatile integer_tr auto& atom, integer_tr auto with);   ///< @copydoc 

    integer_tr auto Assign_Or(volatile integer_tr auto& atom, integer_tr auto with);        ///< @copydoc doc_nkr_os_atomic_Assign_Or

    integer_tr auto Assign_And(volatile integer_tr auto& atom, integer_tr auto with);       ///< @copydoc doc_nkr_os_atomic_Assign_And

    integer_tr auto Assign_Xor(volatile integer_tr auto& atom, integer_tr auto with);       ///< @copydoc doc_nkr_os_atomic_Assign_Xor

    integer_tr auto Assign_Left_Shift(volatile integer_tr auto& atom, integer_tr auto with);    ///< @copydoc 

    integer_tr auto Assign_Right_Shift(volatile integer_tr auto& atom, integer_tr auto with);   ///< @copydoc 
    /// @}
    
    /// @name Exchange
    /// @copydoc _73d8454a_28bc_4509_b695_6bd373d375f2
    /// @{
    boolean_tr auto     Exchange(volatile boolean_tr auto& atom, boolean_tr auto with);                                             ///< @copydoc _acf46593_b662_4d8a_9596_25f347ef5cbf
    integer_8_tr auto   Exchange(volatile integer_8_tr auto& atom, integer_tr auto with);                                           ///< @copydoc doc_nkr_os_atomic_Exchange
    integer_16_tr auto  Exchange(volatile integer_16_tr auto& atom, integer_tr auto with);                                          ///< @copydoc doc_nkr_os_atomic_Exchange
    integer_32_tr auto  Exchange(volatile integer_32_tr auto& atom, integer_tr auto with);                                          ///< @copydoc doc_nkr_os_atomic_Exchange
    integer_64_tr auto  Exchange(volatile integer_64_tr auto& atom, integer_tr auto with);                                          ///< @copydoc doc_nkr_os_atomic_Exchange
    float_32_tr auto    Exchange(volatile float_32_tr auto& atom, float_tr auto with);                                              ///< @copydoc doc_nkr_os_atomic_Exchange
    float_64_tr auto    Exchange(volatile float_64_tr auto& atom, float_tr auto with);                                              ///< @copydoc doc_nkr_os_atomic_Exchange
    pointer_tr auto     Exchange(volatile pointer_tr auto& atom, pointer_tr auto with);                                             ///< @copydoc doc_nkr_os_atomic_Exchange

    integer_8_tr auto   Exchange_Add(volatile integer_8_tr auto& atom, integer_tr auto with);                                       ///< @copydoc doc_nkr_os_atomic_Exchange_Add
    integer_16_tr auto  Exchange_Add(volatile integer_16_tr auto& atom, integer_tr auto with);                                      ///< @copydoc doc_nkr_os_atomic_Exchange_Add
    integer_32_tr auto  Exchange_Add(volatile integer_32_tr auto& atom, integer_tr auto with);                                      ///< @copydoc doc_nkr_os_atomic_Exchange_Add
    integer_64_tr auto  Exchange_Add(volatile integer_64_tr auto& atom, integer_tr auto with);                                      ///< @copydoc doc_nkr_os_atomic_Exchange_Add
    float_32_tr auto    Exchange_Add(volatile float_32_tr auto& atom, float_tr auto with);                                          ///< @copydoc doc_nkr_os_atomic_Exchange_Add
    float_64_tr auto    Exchange_Add(volatile float_64_tr auto& atom, float_tr auto with);                                          ///< @copydoc doc_nkr_os_atomic_Exchange_Add
    pointer_tr auto     Exchange_Add(volatile pointer_tr auto& atom, integer_tr auto with);                                         ///< @copydoc doc_nkr_os_atomic_Exchange_Add

    integer_8_tr auto   Exchange_Subtract(volatile integer_8_tr auto& atom, integer_tr auto with);                                  ///< @copydoc doc_nkr_os_atomic_Exchange_Subtract
    integer_16_tr auto  Exchange_Subtract(volatile integer_16_tr auto& atom, integer_tr auto with);                                 ///< @copydoc doc_nkr_os_atomic_Exchange_Subtract
    integer_32_tr auto  Exchange_Subtract(volatile integer_32_tr auto& atom, integer_tr auto with);                                 ///< @copydoc doc_nkr_os_atomic_Exchange_Subtract
    integer_64_tr auto  Exchange_Subtract(volatile integer_64_tr auto& atom, integer_tr auto with);                                 ///< @copydoc doc_nkr_os_atomic_Exchange_Subtract
    float_32_tr auto    Exchange_Subtract(volatile float_32_tr auto& atom, float_tr auto with);                                     ///< @copydoc doc_nkr_os_atomic_Exchange_Subtract
    float_64_tr auto    Exchange_Subtract(volatile float_64_tr auto& atom, float_tr auto with);                                     ///< @copydoc doc_nkr_os_atomic_Exchange_Subtract
    pointer_tr auto     Exchange_Subtract(volatile pointer_tr auto& atom, integer_tr auto with);                                    ///< @copydoc doc_nkr_os_atomic_Exchange_Subtract

    integer_8_tr auto   Exchange_Multiply(volatile integer_8_tr auto& atom, integer_tr auto with);                                  ///< @copydoc 
    integer_16_tr auto  Exchange_Multiply(volatile integer_16_tr auto& atom, integer_tr auto with);                                 ///< @copydoc 
    integer_32_tr auto  Exchange_Multiply(volatile integer_32_tr auto& atom, integer_tr auto with);                                 ///< @copydoc 
    integer_64_tr auto  Exchange_Multiply(volatile integer_64_tr auto& atom, integer_tr auto with);                                 ///< @copydoc 
    float_32_tr auto    Exchange_Multiply(volatile float_32_tr auto& atom, float_tr auto with);                                     ///< @copydoc 
    float_64_tr auto    Exchange_Multiply(volatile float_64_tr auto& atom, float_tr auto with);                                     ///< @copydoc 

    integer_8_tr auto   Exchange_Divide(volatile integer_8_tr auto& atom, integer_tr auto with);                                    ///< @copydoc 
    integer_16_tr auto  Exchange_Divide(volatile integer_16_tr auto& atom, integer_tr auto with);                                   ///< @copydoc 
    integer_32_tr auto  Exchange_Divide(volatile integer_32_tr auto& atom, integer_tr auto with);                                   ///< @copydoc 
    integer_64_tr auto  Exchange_Divide(volatile integer_64_tr auto& atom, integer_tr auto with);                                   ///< @copydoc 
    float_32_tr auto    Exchange_Divide(volatile float_32_tr auto& atom, float_tr auto with);                                       ///< @copydoc 
    float_64_tr auto    Exchange_Divide(volatile float_64_tr auto& atom, float_tr auto with);                                       ///< @copydoc 

    integer_8_tr auto   Exchange_Modulus(volatile integer_8_tr auto& atom, integer_tr auto with);                                   ///< @copydoc 
    integer_16_tr auto  Exchange_Modulus(volatile integer_16_tr auto& atom, integer_tr auto with);                                  ///< @copydoc 
    integer_32_tr auto  Exchange_Modulus(volatile integer_32_tr auto& atom, integer_tr auto with);                                  ///< @copydoc 
    integer_64_tr auto  Exchange_Modulus(volatile integer_64_tr auto& atom, integer_tr auto with);                                  ///< @copydoc 

    integer_8_tr auto   Exchange_Or(volatile integer_8_tr auto& atom, integer_tr auto with);                                        ///< @copydoc doc_nkr_os_atomic_Exchange_Or
    integer_16_tr auto  Exchange_Or(volatile integer_16_tr auto& atom, integer_tr auto with);                                       ///< @copydoc doc_nkr_os_atomic_Exchange_Or
    integer_32_tr auto  Exchange_Or(volatile integer_32_tr auto& atom, integer_tr auto with);                                       ///< @copydoc doc_nkr_os_atomic_Exchange_Or
    integer_64_tr auto  Exchange_Or(volatile integer_64_tr auto& atom, integer_tr auto with);                                       ///< @copydoc doc_nkr_os_atomic_Exchange_Or

    integer_8_tr auto   Exchange_And(volatile integer_8_tr auto& atom, integer_tr auto with);                                       ///< @copydoc doc_nkr_os_atomic_Exchange_And
    integer_16_tr auto  Exchange_And(volatile integer_16_tr auto& atom, integer_tr auto with);                                      ///< @copydoc doc_nkr_os_atomic_Exchange_And
    integer_32_tr auto  Exchange_And(volatile integer_32_tr auto& atom, integer_tr auto with);                                      ///< @copydoc doc_nkr_os_atomic_Exchange_And
    integer_64_tr auto  Exchange_And(volatile integer_64_tr auto& atom, integer_tr auto with);                                      ///< @copydoc doc_nkr_os_atomic_Exchange_And

    integer_8_tr auto   Exchange_Xor(volatile integer_8_tr auto& atom, integer_tr auto with);                                       ///< @copydoc doc_nkr_os_atomic_Exchange_Xor
    integer_16_tr auto  Exchange_Xor(volatile integer_16_tr auto& atom, integer_tr auto with);                                      ///< @copydoc doc_nkr_os_atomic_Exchange_Xor
    integer_32_tr auto  Exchange_Xor(volatile integer_32_tr auto& atom, integer_tr auto with);                                      ///< @copydoc doc_nkr_os_atomic_Exchange_Xor
    integer_64_tr auto  Exchange_Xor(volatile integer_64_tr auto& atom, integer_tr auto with);                                      ///< @copydoc doc_nkr_os_atomic_Exchange_Xor
    
    integer_8_tr auto   Exchange_Left_Shift(volatile integer_8_tr auto& atom, integer_tr auto with);                                ///< @copydoc 
    integer_16_tr auto  Exchange_Left_Shift(volatile integer_16_tr auto& atom, integer_tr auto with);                               ///< @copydoc 
    integer_32_tr auto  Exchange_Left_Shift(volatile integer_32_tr auto& atom, integer_tr auto with);                               ///< @copydoc 
    integer_64_tr auto  Exchange_Left_Shift(volatile integer_64_tr auto& atom, integer_tr auto with);                               ///< @copydoc 

    integer_8_tr auto   Exchange_Right_Shift(volatile integer_8_tr auto& atom, integer_tr auto with);                               ///< @copydoc 
    integer_16_tr auto  Exchange_Right_Shift(volatile integer_16_tr auto& atom, integer_tr auto with);                              ///< @copydoc 
    integer_32_tr auto  Exchange_Right_Shift(volatile integer_32_tr auto& atom, integer_tr auto with);                              ///< @copydoc 
    integer_64_tr auto  Exchange_Right_Shift(volatile integer_64_tr auto& atom, integer_tr auto with);                              ///< @copydoc 

    boolean_tr auto     Exchange_If_Equals(volatile boolean_tr auto& atom, boolean_tr auto& snapshot, boolean_tr auto with);        ///< @copydoc _6705c0d6_baf4_4cd6_b4bf_727403e9d2c2
    boolean_tr auto     Exchange_If_Equals(volatile integer_8_tr auto& atom, integer_8_tr auto& snapshot, integer_tr auto with);    ///< @copydoc doc_nkr_os_atomic_Exchange_If_Equals
    boolean_tr auto     Exchange_If_Equals(volatile integer_16_tr auto& atom, integer_16_tr auto& snapshot, integer_tr auto with);  ///< @copydoc doc_nkr_os_atomic_Exchange_If_Equals
    boolean_tr auto     Exchange_If_Equals(volatile integer_32_tr auto& atom, integer_32_tr auto& snapshot, integer_tr auto with);  ///< @copydoc doc_nkr_os_atomic_Exchange_If_Equals
    boolean_tr auto     Exchange_If_Equals(volatile integer_64_tr auto& atom, integer_64_tr auto& snapshot, integer_tr auto with);  ///< @copydoc doc_nkr_os_atomic_Exchange_If_Equals
    boolean_tr auto     Exchange_If_Equals(volatile float_32_tr auto& atom, float_32_tr auto& snapshot, float_tr auto with);        ///< @copydoc doc_nkr_os_atomic_Exchange_If_Equals
    boolean_tr auto     Exchange_If_Equals(volatile float_64_tr auto& atom, float_64_tr auto& snapshot, float_tr auto with);        ///< @copydoc doc_nkr_os_atomic_Exchange_If_Equals
    boolean_tr auto     Exchange_If_Equals(volatile pointer_tr auto& atom, pointer_tr auto& snapshot, pointer_tr auto with);        ///< @copydoc doc_nkr_os_atomic_Exchange_If_Equals
    /// @}

}}}

namespace nkr { namespace os { namespace endian {

    /// @name Info
    /// @copydoc _026b191f_2e76_4010_9760_e1215a647d9c
    /// @{
    bool_t  Is_Big();       ///< @copydoc _9d5ef4e6_ff8f_4d63_9fdc_0c0422259d90
    bool_t  Is_Little();    ///< @copydoc _884ae9eb_da64_4306_aab9_50aeb3f85298
    /// @}

    /// @name Swap
    /// @copydoc _b5b179fb_1f64_485e_9510_80260e3a6c33
    /// @{
    integer_16_tr auto  Swap(integer_16_tr auto bytes); ///< @copydoc _857ce8b6_02ca_48e5_9d19_4a7581b8e4c6
    integer_32_tr auto  Swap(integer_32_tr auto bytes); ///< @copydoc _02c0499c_c8c8_43b9_8afc_96545310eb3a
    integer_64_tr auto  Swap(integer_64_tr auto bytes); ///< @copydoc _eabf9a88_080f_445d_88ab_b0dae4a55316
    /// @}

}}}

namespace nkr { namespace os { namespace heap {

    /// @name Allocation
    /// @copydoc _30c0ffe4_d85f_45e5_ab29_bd3f18629cb9
    /// @{
    bool_t  Allocate(type_tr auto*& units, count_t unit_count);         ///< @copydoc _52a0d839_49c8_4d77_93b1_353137fecd3b
    bool_t  Reallocate(type_tr auto*& units, count_t new_unit_count);   ///< @copydoc _06fa627b_ba42_4b70_b0dd_66146e6d863a
    void_t  Deallocate(type_tr auto*& units);                           ///< @copydoc _de0237bf_9b0a_47fc_a5ab_99f21504f570
    /// @}
    
    /// @name Zero-Initialized Allocation
    /// @copydoc _eca47636_431b_4d2a_a102_679075b3cf17
    /// @{
    bool_t  Allocate_Zeros(type_tr auto*& units, count_t unit_count);       ///< @copydoc _9c5a7296_5644_47bf_bd3f_ff7de3518ce9
    bool_t  Reallocate_Zeros(type_tr auto*& units, count_t new_unit_count); ///< @copydoc _7d7887a0_3e2d_4502_af8c_d409aae73f0b
    void_t  Deallocate_Zeros(type_tr auto*& units);                         ///< @copydoc _04d9a3fe_30b3_4ae2_bbc4_2a3cfc4768d6
    /// @}

}}}

#include "nkr/os.inl"
