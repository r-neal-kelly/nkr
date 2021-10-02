/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/allocator_err.h"
#include "nkr/allocator_i.h"
#include "nkr/bool_t.h"
#include "nkr/intrinsics.h"
#include "nkr/maybe_t.h"
#include "nkr/pointer_t.h"
#include "nkr/traits.h"

namespace nkr { namespace allocator {

    /// @nosubgrouping
    /// @copydoc _9ed461b6_85ad_4d8b_a9f0_2dda17493f3a
    template <any_type_tr unit_p>
    class heap_zeros_t
    {
    public:
        /// @name aliases
        /// @copydoc _105f3971_d302_4b0d_84e2_255bc40106e4
        /// @{
        using unit_t    = unit_p;               ///< @copydoc _2eea32f9_12d5_49c9_8dd7_88ad04f76c2f
        using units_t   = unit_p*;              ///< @copydoc _777776f2_6fd5_432d_9a52_9dcafc41114a
        using pointer_t = pointer_t<unit_p>;    ///< @copydoc _b3f6bc08_befb_4809_b834_a95cc5822e65
        /// @}

    public:
        /// @name static functions
        /// @copydoc _97cee72c_8d09_4b00_b71e_12167666c774
        /// @{
        static constexpr count_t    Min_Unit_Count();   ///< @copydoc _2733158c_4527_4730_b96d_71633b9dcc7e
        static constexpr count_t    Max_Unit_Count();   ///< @copydoc _6985e2eb_c95b_4dfb_9a12_ac58e1759c07
        /// @}

    private:
        static maybe_t<allocator_err>   Allocate(is_any_tr<heap_zeros_t> auto& self,
                                                 is_any_non_const_tr<units_t> auto& units,
                                                 count_t unit_count);
        static maybe_t<allocator_err>   Allocate(is_any_tr<heap_zeros_t> auto& self,
                                                 is_any_non_const_tr<pointer_t> auto& units,
                                                 count_t unit_count);

        static maybe_t<allocator_err>   Reallocate(is_any_tr<heap_zeros_t> auto& self,
                                                   is_any_non_const_tr<units_t> auto& units,
                                                   count_t new_unit_count);
        static maybe_t<allocator_err>   Reallocate(is_any_tr<heap_zeros_t> auto& self,
                                                   is_any_non_const_tr<pointer_t> auto& units,
                                                   count_t new_unit_count);

        static void_t                   Deallocate(is_any_tr<heap_zeros_t> auto& self,
                                                   is_any_non_const_tr<units_t> auto& units);
        static void_t                   Deallocate(is_any_tr<heap_zeros_t> auto& self,
                                                   is_any_non_const_tr<pointer_t> auto& units);

        static bool_t                   Is_Equal_To(is_any_tr<heap_zeros_t> auto a, is_any_tr<heap_zeros_t> auto b);

    public:
        /// @name friends
        /// @copydoc _9cec351a_06bc_4963_bcfa_f04eec68ad0c
        /// @{
        friend bool_t operator ==(is_any_tr<heap_zeros_t> auto a, is_any_tr<heap_zeros_t> auto b)
        {
            return Is_Equal_To(a, b);
        }                                                                                           ///< @copydoc _b293e326_07c6_4d55_88ae_0df2609ea4ac

        friend bool_t operator !=(is_any_tr<heap_zeros_t> auto a, is_any_tr<heap_zeros_t> auto b)
        {
            return !Is_Equal_To(a, b);
        }                                                                                           ///< @copydoc _c69fa1a6_4ce8_476d_aeb3_55de07e9eec5
        /// @}

    public:
        /// @name objects
        /// @copydoc _db7a0f47_4799_4207_bf0e_2304a225ce78
        /// @{
        heap_zeros_t()                                                                                          = default;  ///< @copydoc _8221efd2_f2a0_41d1_adb8_6b496bfce46e

        heap_zeros_t(const heap_zeros_t& other);                                                                            ///< @copydoc _9d1d0678_861d_4714_aa68_01d231df8814
        heap_zeros_t(const volatile heap_zeros_t& other);                                                                   ///< @copydoc _3b1b6bf4_f26c_4884_abf7_c3405de9fa44
        heap_zeros_t(heap_zeros_t&& other) noexcept;                                                                        ///< @copydoc _1924a0ce_e6e0_47a5_bd2b_3f4201d4cf46
        heap_zeros_t(volatile heap_zeros_t&& other) noexcept;                                                               ///< @copydoc _817212c4_cb85_4a0a_8f46_b85da743b270

        heap_zeros_t&           operator =(const heap_zeros_t& other);                                                      ///< @copydoc _3ba77c5d_06d2_4266_80ba_e1e38234a761
        volatile heap_zeros_t&  operator =(const heap_zeros_t& other) volatile;                                             ///< @copydoc _d924b3d5_9170_425e_94b9_bf941a6fc61b
        heap_zeros_t&           operator =(const volatile heap_zeros_t& other);                                             ///< @copydoc _4c4d31c0_8a3d_4dd4_89cb_fa690012091d
        volatile heap_zeros_t&  operator =(const volatile heap_zeros_t& other) volatile;                                    ///< @copydoc _b9b767c1_3021_479e_905e_5774631d80df
        heap_zeros_t&           operator =(heap_zeros_t&& other) noexcept;                                                  ///< @copydoc _a3ab8033_f3a8_4203_a309_2455ba032954
        volatile heap_zeros_t&  operator =(heap_zeros_t&& other) volatile noexcept;                                         ///< @copydoc _9e177763_dd02_4d3e_a45b_f1b9e25a5e2b
        heap_zeros_t&           operator =(is_just_volatile_tr<heap_zeros_t> auto&& other) noexcept;                        ///< @copydoc _c7d05983_50e9_4f48_8069_34028a118042
        volatile heap_zeros_t&  operator =(is_just_volatile_tr<heap_zeros_t> auto&& other) volatile noexcept;               ///< @copydoc _e7400c29_88f7_44fa_811b_6e072bef6193

        ~heap_zeros_t()                                                                                         = default;  ///< @copydoc _71f33510_0167_444f_94c1_98964626275f
        /// @}

    public:
        /// @name methods
        /// @copydoc _0d318fcd_846e_4498_a0f5_6cd5f76d9e89
        /// @{
        maybe_t<allocator_err>  Allocate(is_any_non_const_tr<units_t> auto& units, count_t unit_count) const;                   ///< @copydoc _9be86f6c_8114_453a_8dc6_31e4ec38ac06
        maybe_t<allocator_err>  Allocate(is_any_non_const_tr<units_t> auto& units, count_t unit_count) const volatile;          ///< @copydoc _e05b1798_8e90_4b76_929c_a720f3c08e97
        maybe_t<allocator_err>  Allocate(is_any_non_const_tr<pointer_t> auto& units, count_t unit_count) const;                 ///< @copydoc _a4ade59f_0458_4747_895b_f498fb33b8ab
        maybe_t<allocator_err>  Allocate(is_any_non_const_tr<pointer_t> auto& units, count_t unit_count) const volatile;        ///< @copydoc _2e6609e3_6c75_4834_bf34_f05b0d49a965

        maybe_t<allocator_err>  Reallocate(is_any_non_const_tr<units_t> auto& units, count_t new_unit_count) const;             ///< @copydoc _daaa50b9_d86f_4b06_95ac_7a06790526d5
        maybe_t<allocator_err>  Reallocate(is_any_non_const_tr<units_t> auto& units, count_t new_unit_count) const volatile;    ///< @copydoc _c8a45565_1648_4140_abdc_19c38bebfe9f
        maybe_t<allocator_err>  Reallocate(is_any_non_const_tr<pointer_t> auto& units, count_t new_unit_count) const;           ///< @copydoc _b2db59c8_c954_43c3_b292_496d8a8e6184
        maybe_t<allocator_err>  Reallocate(is_any_non_const_tr<pointer_t> auto& units, count_t new_unit_count) const volatile;  ///< @copydoc _ad6e5660_6f11_434a_8bbc_4310cd419dab

        void_t                  Deallocate(is_any_non_const_tr<units_t> auto& units) const;                                     ///< @copydoc _1ceb289c_99eb_41d6_a6f1_3c6503dbe0ef
        void_t                  Deallocate(is_any_non_const_tr<units_t> auto& units) const volatile;                            ///< @copydoc _20755a8c_2f56_48b8_9bd9_c3d3e59f6412
        void_t                  Deallocate(is_any_non_const_tr<pointer_t> auto& units) const;                                   ///< @copydoc _df9976c6_21ba_4064_ba40_b966f83b7805
        void_t                  Deallocate(is_any_non_const_tr<pointer_t> auto& units) const volatile;                          ///< @copydoc _8c2a6b84_9814_4c4b_a863_7d7bd5b3f10a
        /// @}
    };
    static_assert(allocator_i<heap_zeros_t<word_t>>);

}}
