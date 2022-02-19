/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/z_intrinsics.h"
#include "nkr/z_none_t.h"
#include "nkr/z_traits.h"

#include "nkr/boolean/deleted_operators_t_dec.h"

namespace nkr {

    template <typename type_p>
    concept has_bool_deleted_operator_tr =
        requires(type_p instance) { +instance; } ||
        requires(type_p instance) { -instance; } ||

        requires(type_p instance) { instance + 1; } ||
        requires(type_p instance) { instance - 1; } ||
        requires(type_p instance) { instance * 1; } ||
        requires(type_p instance) { instance / 1; } ||
        requires(type_p instance) { instance % 1; } ||

        requires(type_p instance) { ~instance; } ||
        requires(type_p instance) { instance | 1; } ||
        requires(type_p instance) { instance & 1; } ||
        requires(type_p instance) { instance ^ 1; } ||
        requires(type_p instance) { instance << 1; } ||
        requires(type_p instance) { instance >> 1; } ||

        requires(type_p instance) { instance += 1; } ||
        requires(type_p instance) { instance -= 1; } ||
        requires(type_p instance) { instance *= 1; } ||
        requires(type_p instance) { instance /= 1; } ||
        requires(type_p instance) { instance %= 1; } ||

        requires(type_p instance) { instance |= 1; } ||
        requires(type_p instance) { instance &= 1; } ||
        requires(type_p instance) { instance ^= 1; } ||
        requires(type_p instance) { instance <<= 1; } ||
        requires(type_p instance) { instance >>= 1; } ||

        requires(type_p instance) { ++instance; } ||
        requires(type_p instance) { instance++; } ||
        requires(type_p instance) { --instance; } ||
        requires(type_p instance) { instance--; } ||

        requires(type_p instance) { instance < 1; } ||
        requires(type_p instance) { instance > 1; } ||
        requires(type_p instance) { instance <= 1; } ||
        requires(type_p instance) { instance >= 1; } ||
        requires(type_p instance) { instance <=> 1; };

    /// @nosubgrouping
    /// @copydoc _2add9928_e370_4943_ba5b_2950d9e1da99
    class bool_t :
        public boolean::deleted_operators_t
    {
    protected:
        /// @name object data
        /// @copydoc _3dbc082f_9df8_4eda_b07f_fca297cc63a9
        /// @{
        word_t  value;  ///< @copydoc _9eefd4d6_1786_42ec_970a_c16c9bde2d42
        /// @}

    public:
        /// @name objects
        /// @copydoc _727e30a1_ed17_4451_aefd_e9ff35d4be9c
        /// @{
        bool_t();                                                                                   ///< @copydoc _507e6865_70dc_4e5b_97ab_c0d33e53dc67

        bool_t(to_c_bool_tr auto value);                                                            ///< @copydoc _2381ceb1_96d5_433e_a68e_898e08e5ef7f
        
        bool_t(const bool_t& other);                                                                ///< @copydoc _c692880f_ea8a_47c2_b8c8_98a00607b79b
        bool_t(const volatile bool_t& other);                                                       ///< @copydoc _c2c40c6d_4153_4079_8231_a8f818fc4999
        bool_t(bool_t&& other) noexcept;                                                            ///< @copydoc _f2621569_562c_44b6_a4be_cddfaf0b1147
        bool_t(volatile bool_t&& other) noexcept;                                                   ///< @copydoc _e5e66483_541d_4798_b386_2874446fb0de

        bool_t&             operator =(const bool_t& other);                                        ///< @copydoc _9b3a1871_d4ff_4afb_886d_e0d16ebaad08
        volatile bool_t&    operator =(const bool_t& other) volatile;                               ///< @copydoc 
        bool_t&             operator =(const volatile bool_t& other);                               ///< @copydoc 
        volatile bool_t&    operator =(const volatile bool_t& other) volatile;                      ///< @copydoc _462d0286_9a2d_4ea9_8b92_3f75d50199ae
        bool_t&             operator =(bool_t&& other) noexcept;                                    ///< @copydoc _cf5bcded_4eb2_4cdb_92cd_aa5b66b3138b
        volatile bool_t&    operator =(bool_t&& other) volatile noexcept;                           ///< @copydoc 
        bool_t&             operator =(is_just_volatile_tr<bool_t> auto&& other) noexcept;          ///< @copydoc 
        volatile bool_t&    operator =(is_just_volatile_tr<bool_t> auto&& other) volatile noexcept; ///< @copydoc _b047b3ab_68ee_46f3_b210_6f27f6f34ef1

        ~bool_t();                                                                                  ///< @copydoc _4c312eec_919f_4b48_98e5_a3539442c7d2
        /// @}

    public:
        /// @name casts
        /// @copydoc _6a6f9172_06fd_4b0f_b1ee_1817e0c013a9
        /// @{
        operator            c_bool_t() const;                           ///< @copydoc _27d5dbc6_c0b3_47f7_94c9_fda617dd82c8
        operator            c_bool_t() const volatile;                  ///< @copydoc _676141d7_bb06_45a8_8b65_0f5ae7bee673

        explicit operator   word_t&();                                  ///< @copydoc _4d0e7d29_353a_459f_89af_e11de2f19eea
        explicit operator   const word_t&() const;                      ///< @copydoc _9f6d257a_fc13_4dda_ad1b_7b268caf6dff
        explicit operator   volatile word_t&() volatile;                ///< @copydoc _64e5638b_29ea_4e16_bde9_bfddde8c22b2
        explicit operator   const volatile word_t&() const volatile;    ///< @copydoc _3e6e7fd1_df11_44b3_a3d6_4f5073359d92
        /// @}

    public:
        /// @name none_t interface
        /// @copydoc _a3769981_7e0b_4a14_9376_c341849febfb
        /// @{
        bool_t(none_t);                                         ///< @copydoc _a74f5e68_66db_41d5_8778_6d49efcefb3f

        bool_t&             operator =(none_t);                 ///< @copydoc _9a7b8a4a_ce15_44e4_8900_5a09049c8b8a
        volatile bool_t&    operator =(none_t) volatile;        ///< @copydoc 

        bool_t              operator ==(none_t) const;          ///< @copydoc _c21ea269_d645_4b2c_b938_27fce7ad0617
        bool_t              operator ==(none_t) const volatile; ///< @copydoc 
        bool_t              operator !=(none_t) const;          ///< @copydoc _37796b19_cde7_4029_a5f3_4203fa2315c8
        bool_t              operator !=(none_t) const volatile; ///< @copydoc 
        /// @}
    };
    static_assert(sizeof(bool_t) == sizeof(word_t));

}
