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
    /// @copydoc _b755f31e_b7ac_41ef_8835_c78b953b5de4
    template <any_type_tr unit_p>
    class heap_t
    {
    public:
        /// @name aliases
        /// @copydoc _8b3d52c2_1232_4297_8978_c9a842ee8e96
        /// @{
        using unit_t    = unit_p;               ///< @copydoc _baa9a29c_b2a6_4310_bb01_be33343423b0
        using units_t   = unit_p*;              ///< @copydoc _d395167f_1ed2_4c91_bfb4_eb4090f818a9
        using pointer_t = pointer_t<unit_p>;    ///< @copydoc _b897f43c_b3e5_4b4f_b5fc_e2d18c22d294
        /// @}

    public:
        /// @name static functions
        /// @copydoc _e981621a_045f_4df5_b5db_81f1b32c5af7
        /// @{
        static constexpr count_t    Min_Unit_Count();   ///< @copydoc _dd4ec220_c0a0_40ac_9c9c_e53c46d59f18
        static constexpr count_t    Max_Unit_Count();   ///< @copydoc _78c258f0_e7fe_476b_b06f_5e56cb6259a0
        /// @}

    private:
        static maybe_t<allocator_err>   Allocate(is_any_tr<heap_t> auto& self,
                                                 is_any_non_const_tr<units_t> auto& units,
                                                 count_t unit_count);
        static maybe_t<allocator_err>   Allocate(is_any_tr<heap_t> auto& self,
                                                 is_any_non_const_tr<pointer_t> auto& units,
                                                 count_t unit_count);

        static maybe_t<allocator_err>   Reallocate(is_any_tr<heap_t> auto& self,
                                                   is_any_non_const_tr<units_t> auto& units,
                                                   count_t new_unit_count);
        static maybe_t<allocator_err>   Reallocate(is_any_tr<heap_t> auto& self,
                                                   is_any_non_const_tr<pointer_t> auto& units,
                                                   count_t new_unit_count);

        static void_t                   Deallocate(is_any_tr<heap_t> auto& self,
                                                   is_any_non_const_tr<units_t> auto& units);
        static void_t                   Deallocate(is_any_tr<heap_t> auto& self,
                                                   is_any_non_const_tr<pointer_t> auto& units);

        static bool_t                   Is_Equal_To(is_any_tr<heap_t> auto a, is_any_tr<heap_t> auto b);

    public:
        /// @name friends
        /// @copydoc _badab020_8220_44a0_9663_cb16dfac0e9b
        /// @{
        friend bool_t operator ==(is_any_tr<heap_t> auto a, is_any_tr<heap_t> auto b)
        {
            return Is_Equal_To(a, b);
        }                                                                               ///< @copydoc _eb1c1043_8f5c_4867_89c9_021726b8e08f

        friend bool_t operator !=(is_any_tr<heap_t> auto a, is_any_tr<heap_t> auto b)
        {
            return !Is_Equal_To(a, b);
        }                                                                               ///< @copydoc _666c4bd5_d39e_47a9_93bb_2f283c39f3a5
        /// @}

    public:
        /// @name objects
        /// @copydoc _14f4e31c_1660_4507_9ee2_1dbcfd5f4047
        /// @{
        heap_t()                                                                                    = default;  ///< @copydoc _72bb8488_2e92_4c3b_a911_ad1b21aaf99a

        heap_t(const heap_t& other);                                                                            ///< @copydoc _96a83762_dfba_470b_b386_f1db4b6eadee
        heap_t(const volatile heap_t& other);                                                                   ///< @copydoc _828c6c9c_474b_43de_aca6_d25e3ef8fbfe
        heap_t(heap_t&& other) noexcept;                                                                        ///< @copydoc _c5f44802_9d14_42e1_ab68_169226dc8849
        heap_t(volatile heap_t&& other) noexcept;                                                               ///< @copydoc _150cf0da_1e36_499c_84bb_46fcffbf13d5

        heap_t&             operator =(const heap_t& other);                                                    ///< @copydoc _b510eae7_0066_414f_9f31_bdf31ad9de23
        volatile heap_t&    operator =(const heap_t& other) volatile;                                           ///< @copydoc _6ab2bd34_0053_41cb_b9e6_5fd68c266b33
        heap_t&             operator =(const volatile heap_t& other);                                           ///< @copydoc _e94eb433_6630_4054_bc68_d35c23d5c232
        volatile heap_t&    operator =(const volatile heap_t& other) volatile;                                  ///< @copydoc _f26fe407_c8a4_4afc_93df_4ff085a75981
        heap_t&             operator =(heap_t&& other) noexcept;                                                ///< @copydoc _b52e44e0_52f7_4d81_8295_97247f58eb28
        volatile heap_t&    operator =(heap_t&& other) volatile noexcept;                                       ///< @copydoc _a3722f4c_acc2_49ab_acd4_ece68183e095
        heap_t&             operator =(is_just_volatile_tr<heap_t> auto&& other) noexcept;                      ///< @copydoc _9b58de38_ab92_4cfb_a0b3_1b2bc3f32cb6
        volatile heap_t&    operator =(is_just_volatile_tr<heap_t> auto&& other) volatile noexcept;             ///< @copydoc _94af172e_120d_44b5_80c6_e6b4dc30a742

        ~heap_t()                                                                                   = default;  ///< @copydoc _59244c8e_73d5_4e11_a2f7_58a3db2ef3bb
        /// @}

    public:
        /// @name methods
        /// @copydoc _b3eebf07_c7e1_4ce6_824d_012253f28371
        /// @{
        maybe_t<allocator_err>  Allocate(is_any_non_const_tr<units_t> auto& units, count_t unit_count) const;                   ///< @copydoc _a1cd4e17_bb03_4c42_85be_fe91bb3b21f3
        maybe_t<allocator_err>  Allocate(is_any_non_const_tr<units_t> auto& units, count_t unit_count) const volatile;          ///< @copydoc _bd5b60f3_b822_4f35_ab98_b5ff98ad8779
        maybe_t<allocator_err>  Allocate(is_any_non_const_tr<pointer_t> auto& units, count_t unit_count) const;                 ///< @copydoc _1c1a3ee2_5ae4_4be1_89a0_ab555f37660d
        maybe_t<allocator_err>  Allocate(is_any_non_const_tr<pointer_t> auto& units, count_t unit_count) const volatile;        ///< @copydoc _3a4d96a3_16d5_4515_8c81_2a61096c75da
        
        maybe_t<allocator_err>  Reallocate(is_any_non_const_tr<units_t> auto& units, count_t new_unit_count) const;             ///< @copydoc _cd380e7e_2493_42d7_837e_5f993f5c0676
        maybe_t<allocator_err>  Reallocate(is_any_non_const_tr<units_t> auto& units, count_t new_unit_count) const volatile;    ///< @copydoc _4c81b585_1a41_42ea_9b16_b3867e517b31
        maybe_t<allocator_err>  Reallocate(is_any_non_const_tr<pointer_t> auto& units, count_t new_unit_count) const;           ///< @copydoc _931cb620_74fd_423d_8294_0ecb4bd0f550
        maybe_t<allocator_err>  Reallocate(is_any_non_const_tr<pointer_t> auto& units, count_t new_unit_count) const volatile;  ///< @copydoc _89101faa_a287_42a8_b946_6c9585b51cb2

        void_t                  Deallocate(is_any_non_const_tr<units_t> auto& units) const;                                     ///< @copydoc _fe8a3e78_0335_4de8_8283_c6a7a2a2322b
        void_t                  Deallocate(is_any_non_const_tr<units_t> auto& units) const volatile;                            ///< @copydoc _ff19cbdc_d4d9_4c50_b9db_493f833701b2
        void_t                  Deallocate(is_any_non_const_tr<pointer_t> auto& units) const;                                   ///< @copydoc _f9a2828e_5083_4628_afe9_35d66bd17d69
        void_t                  Deallocate(is_any_non_const_tr<pointer_t> auto& units) const volatile;                          ///< @copydoc _7fb233cf_5433_47e9_8cd8_9fbe593b9e3a
        /// @}
    };
    static_assert(allocator_i<heap_t<word_t>>);

}}
