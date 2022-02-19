/*
    Copyright 2022 r-neal-kelly
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
        static constexpr count_t        Min_Unit_Count();                                                               ///< @copydoc _2733158c_4527_4730_b96d_71633b9dcc7e
        static constexpr count_t        Max_Unit_Count();                                                               ///< @copydoc _6985e2eb_c95b_4dfb_9a12_ac58e1759c07

        static maybe_t<allocator_err>   Allocate(is_any_non_const_tr<units_t> auto& units, count_t unit_count);         ///< @copydoc _9be86f6c_8114_453a_8dc6_31e4ec38ac06
        static maybe_t<allocator_err>   Allocate(is_any_non_const_tr<pointer_t> auto& units, count_t unit_count);       ///< @copydoc _a4ade59f_0458_4747_895b_f498fb33b8ab

        static maybe_t<allocator_err>   Reallocate(is_any_non_const_tr<units_t> auto& units, count_t new_unit_count);   ///< @copydoc _daaa50b9_d86f_4b06_95ac_7a06790526d5
        static maybe_t<allocator_err>   Reallocate(is_any_non_const_tr<pointer_t> auto& units, count_t new_unit_count); ///< @copydoc _b2db59c8_c954_43c3_b292_496d8a8e6184

        static void_t                   Deallocate(is_any_non_const_tr<units_t> auto& units);                           ///< @copydoc _1ceb289c_99eb_41d6_a6f1_3c6503dbe0ef
        static void_t                   Deallocate(is_any_non_const_tr<pointer_t> auto& units);                         ///< @copydoc _df9976c6_21ba_4064_ba40_b966f83b7805
        /// @}
    };
    static_assert(allocator_i<heap_zeros_t<word_t>>);

}}
