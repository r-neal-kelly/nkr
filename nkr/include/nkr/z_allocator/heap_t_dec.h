/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/z_allocator_err.h"
#include "nkr/z_allocator_i.h"
#include "nkr/z_bool_t.h"
#include "nkr/z_intrinsics.h"
#include "nkr/z_maybe_t.h"
#include "nkr/z_pointer_t.h"
#include "nkr/z_traits.h"

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
        static constexpr count_t        Min_Unit_Count();                                                               ///< @copydoc _dd4ec220_c0a0_40ac_9c9c_e53c46d59f18
        static constexpr count_t        Max_Unit_Count();                                                               ///< @copydoc _78c258f0_e7fe_476b_b06f_5e56cb6259a0

        static maybe_t<allocator_err>   Allocate(is_any_non_const_tr<units_t> auto& units, count_t unit_count);         ///< @copydoc _a1cd4e17_bb03_4c42_85be_fe91bb3b21f3
        static maybe_t<allocator_err>   Allocate(is_any_non_const_tr<pointer_t> auto& units, count_t unit_count);       ///< @copydoc _1c1a3ee2_5ae4_4be1_89a0_ab555f37660d
        
        static maybe_t<allocator_err>   Reallocate(is_any_non_const_tr<units_t> auto& units, count_t new_unit_count);   ///< @copydoc _cd380e7e_2493_42d7_837e_5f993f5c0676
        static maybe_t<allocator_err>   Reallocate(is_any_non_const_tr<pointer_t> auto& units, count_t new_unit_count); ///< @copydoc _931cb620_74fd_423d_8294_0ecb4bd0f550

        static void_t                   Deallocate(is_any_non_const_tr<units_t> auto& units);                           ///< @copydoc _fe8a3e78_0335_4de8_8283_c6a7a2a2322b
        static void_t                   Deallocate(is_any_non_const_tr<pointer_t> auto& units);                         ///< @copydoc _f9a2828e_5083_4628_afe9_35d66bd17d69
        /// @}
    };
    static_assert(allocator_i<heap_t<word_t>>);

}}
