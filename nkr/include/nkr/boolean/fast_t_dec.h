/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/cpp_dec.h"
#include "nkr/intrinsics_dec.h"
#include "nkr/tr_dec.h"

#include "nkr/boolean/deleted_operators_t_dec.h"

#include "nkr/interface/template_i_dec.h"
#include "nkr/interface/type_i_dec.h"

#include "nkr/trait/boolean_tr_dec.h"
#include "nkr/trait/boolean/any_tr_dec.h"
#include "nkr/trait/boolean/pure_tr_dec.h"

namespace nkr { namespace boolean {

    class   fast_t;

    struct  fast_tg {};

    template <typename type_p>
    concept fast_tr =
        cpp::is_any_tr<type_p, fast_t>;

}}

namespace nkr { namespace interface {

    template <>
    class type_i<boolean::fast_tg>
    {
    public:
        using of_t  = cpp::void_t;

    public:
        template <typename other_p>
        static constexpr cpp::bool_t    Is_Any();
    };

    template <boolean::fast_tr type_p>
    class type_i<type_p> :
        public type_i<boolean::fast_tg>
    {
    public:
    };

}}

namespace nkr { namespace boolean {

    /// @nosubgrouping
    /// @copydoc _2add9928_e370_4943_ba5b_2950d9e1da99
    class fast_t :
        public deleted_operators_t
    {
    public:
        using value_t   = cpp::word_t;

    public:
        static constexpr cpp::bool_t    Is_Boolean_Type();

    protected:
        /// @name object data
        /// @copydoc _3dbc082f_9df8_4eda_b07f_fca297cc63a9
        /// @{
        value_t value;  ///< @copydoc _9eefd4d6_1786_42ec_970a_c16c9bde2d42
        /// @}

    public:
        /// @name objects
        /// @copydoc _727e30a1_ed17_4451_aefd_e9ff35d4be9c
        /// @{
        fast_t();                                                                                       ///< @copydoc _507e6865_70dc_4e5b_97ab_c0d33e53dc67

        // this is obviously temporary until we update our traits syntax to be able to test for conversion.
        template <typename type_p>
            requires std::convertible_to<type_p, value_t>
        fast_t(type_p value);                                                                           ///< @copydoc _2381ceb1_96d5_433e_a68e_898e08e5ef7f

        fast_t(const fast_t& other);                                                                    ///< @copydoc _c692880f_ea8a_47c2_b8c8_98a00607b79b
        fast_t(const volatile fast_t& other);                                                           ///< @copydoc _c2c40c6d_4153_4079_8231_a8f818fc4999
        fast_t(fast_t&& other) noexcept;                                                                ///< @copydoc _f2621569_562c_44b6_a4be_cddfaf0b1147
        fast_t(volatile fast_t&& other) noexcept;                                                       ///< @copydoc _e5e66483_541d_4798_b386_2874446fb0de

        fast_t&             operator =(const fast_t& other);                                            ///< @copydoc _9b3a1871_d4ff_4afb_886d_e0d16ebaad08
        volatile fast_t&    operator =(const fast_t& other) volatile;                                   ///< @copydoc 
        fast_t&             operator =(const volatile fast_t& other);                                   ///< @copydoc 
        volatile fast_t&    operator =(const volatile fast_t& other) volatile;                          ///< @copydoc _462d0286_9a2d_4ea9_8b92_3f75d50199ae
        fast_t&             operator =(fast_t&& other) noexcept;                                        ///< @copydoc _cf5bcded_4eb2_4cdb_92cd_aa5b66b3138b
        volatile fast_t&    operator =(fast_t&& other) volatile noexcept;                               ///< @copydoc 
        fast_t&             operator =(tr1<just_volatile_tg, fast_t> auto&& other) noexcept;            ///< @copydoc 
        volatile fast_t&    operator =(tr1<just_volatile_tg, fast_t> auto&& other) volatile noexcept;   ///< @copydoc _b047b3ab_68ee_46f3_b210_6f27f6f34ef1

        ~fast_t();                                                                                      ///< @copydoc _4c312eec_919f_4b48_98e5_a3539442c7d2
        /// @}

    public:
        /// @name casts
        /// @copydoc _6a6f9172_06fd_4b0f_b1ee_1817e0c013a9
        /// @{
        explicit operator   cpp::bool_t() const;                        ///< @copydoc _27d5dbc6_c0b3_47f7_94c9_fda617dd82c8
        explicit operator   cpp::bool_t() const volatile;               ///< @copydoc _676141d7_bb06_45a8_8b65_0f5ae7bee673

        explicit operator   value_t&();                                 ///< @copydoc _4d0e7d29_353a_459f_89af_e11de2f19eea
        explicit operator   const value_t&() const;                     ///< @copydoc _9f6d257a_fc13_4dda_ad1b_7b268caf6dff
        explicit operator   volatile value_t&() volatile;               ///< @copydoc _64e5638b_29ea_4e16_bde9_bfddde8c22b2
        explicit operator   const volatile value_t&() const volatile;   ///< @copydoc _3e6e7fd1_df11_44b3_a3d6_4f5073359d92
        /// @}

    public:
        /// @name none_t interface
        /// @copydoc _a3769981_7e0b_4a14_9376_c341849febfb
        /// @{
        fast_t(none_t);                                         ///< @copydoc _a74f5e68_66db_41d5_8778_6d49efcefb3f

        fast_t&             operator =(none_t);                 ///< @copydoc _9a7b8a4a_ce15_44e4_8900_5a09049c8b8a
        volatile fast_t&    operator =(none_t) volatile;        ///< @copydoc 

        fast_t              operator ==(none_t) const;          ///< @copydoc _c21ea269_d645_4b2c_b938_27fce7ad0617
        fast_t              operator ==(none_t) const volatile; ///< @copydoc 
        fast_t              operator !=(none_t) const;          ///< @copydoc _37796b19_cde7_4029_a5f3_4203fa2315c8
        fast_t              operator !=(none_t) const volatile; ///< @copydoc 
        /// @}
    };

}}

namespace nkr {

    boolean::fast_t operator ==(const tr1<any_tg, boolean::fast_t> auto& a, const tr0<any_tg> auto& b);
    boolean::fast_t operator ==(const tr1<any_tg, boolean::fast_t> auto& a, const tr0<any_tg> auto&& b);
    boolean::fast_t operator ==(const tr1<any_tg, boolean::fast_t> auto&& a, const tr0<any_tg> auto& b);
    boolean::fast_t operator ==(const tr1<any_tg, boolean::fast_t> auto&& a, const tr0<any_tg> auto&& b);

    boolean::fast_t operator !=(const tr1<any_tg, boolean::fast_t> auto& a, const tr0<any_tg> auto& b);
    boolean::fast_t operator !=(const tr1<any_tg, boolean::fast_t> auto& a, const tr0<any_tg> auto&& b);
    boolean::fast_t operator !=(const tr1<any_tg, boolean::fast_t> auto&& a, const tr0<any_tg> auto& b);
    boolean::fast_t operator !=(const tr1<any_tg, boolean::fast_t> auto&& a, const tr0<any_tg> auto&& b);

}
