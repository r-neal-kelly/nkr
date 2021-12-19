/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/cpp_dec.h"
#include "nkr/intrinsics_dec.h"
#include "nkr/tr_dec.h"

#include "nkr/boolean/cpp_t_dec.h"
#include "nkr/boolean/deleted_operators_t_dec.h"

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
        static constexpr cpp::bool_t    Is_Any() noexcept;
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
        static constexpr boolean::cpp_t Is_Boolean_Type() noexcept;

    private:
        static constexpr auto&  Assign_Copy(tr1<any_non_const_tg, fast_t> auto& self, const tr1<any_tg, fast_t> auto& other) noexcept;
        static constexpr auto&  Assign_Move(tr1<any_non_const_tg, fast_t> auto& self, tr1<any_non_const_tg, fast_t> auto&& other) noexcept;

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
        constexpr fast_t() noexcept;                                                                            ///< @copydoc _507e6865_70dc_4e5b_97ab_c0d33e53dc67

        constexpr fast_t(const tr1<any_to_tg, boolean::cpp_t> auto& value) noexcept;                            ///< @copydoc _2381ceb1_96d5_433e_a68e_898e08e5ef7f

        constexpr fast_t(const fast_t& other) noexcept;                                                         ///< @copydoc _c692880f_ea8a_47c2_b8c8_98a00607b79b
        constexpr fast_t(const volatile fast_t& other) noexcept;                                                ///< @copydoc _c2c40c6d_4153_4079_8231_a8f818fc4999
        constexpr fast_t(fast_t&& other) noexcept;                                                              ///< @copydoc _f2621569_562c_44b6_a4be_cddfaf0b1147
        constexpr fast_t(volatile fast_t&& other) noexcept;                                                     ///< @copydoc _e5e66483_541d_4798_b386_2874446fb0de

        constexpr fast_t&           operator =(const fast_t& other) noexcept;                                   ///< @copydoc _9b3a1871_d4ff_4afb_886d_e0d16ebaad08
        constexpr volatile fast_t&  operator =(const fast_t& other) volatile noexcept;                          ///< @copydoc 
        constexpr fast_t&           operator =(const volatile fast_t& other) noexcept;                          ///< @copydoc 
        constexpr volatile fast_t&  operator =(const volatile fast_t& other) volatile noexcept;                 ///< @copydoc _462d0286_9a2d_4ea9_8b92_3f75d50199ae
        constexpr fast_t&           operator =(fast_t&& other) noexcept;                                        ///< @copydoc _cf5bcded_4eb2_4cdb_92cd_aa5b66b3138b
        constexpr volatile fast_t&  operator =(fast_t&& other) volatile noexcept;                               ///< @copydoc 
        constexpr fast_t&           operator =(tr1<just_volatile_tg, fast_t> auto&& other) noexcept;            ///< @copydoc 
        constexpr volatile fast_t&  operator =(tr1<just_volatile_tg, fast_t> auto&& other) volatile noexcept;   ///< @copydoc _b047b3ab_68ee_46f3_b210_6f27f6f34ef1

        constexpr ~fast_t() noexcept;                                                                           ///< @copydoc _4c312eec_919f_4b48_98e5_a3539442c7d2
        /// @}

    public:
        /// @name casts
        /// @copydoc _6a6f9172_06fd_4b0f_b1ee_1817e0c013a9
        /// @{
        explicit constexpr operator boolean::cpp_t::value_t() const noexcept;           ///< @copydoc _27d5dbc6_c0b3_47f7_94c9_fda617dd82c8
        explicit constexpr operator boolean::cpp_t::value_t() const volatile noexcept;  ///< @copydoc _676141d7_bb06_45a8_8b65_0f5ae7bee673
        /// @}
    };

}}

namespace nkr {

    /*constexpr boolean::fast_t   operator ==(const tr1<any_tg, boolean::fast_t> auto& a, const auto& b) noexcept;
    constexpr boolean::fast_t   operator ==(const tr1<any_tg, boolean::fast_t> auto& a, const auto&& b) noexcept;
    constexpr boolean::fast_t   operator ==(const tr1<any_tg, boolean::fast_t> auto&& a, const auto& b) noexcept;
    constexpr boolean::fast_t   operator ==(const tr1<any_tg, boolean::fast_t> auto&& a, const auto&& b) noexcept;

    constexpr boolean::fast_t   operator !=(const tr1<any_tg, boolean::fast_t> auto& a, const auto& b) noexcept;
    constexpr boolean::fast_t   operator !=(const tr1<any_tg, boolean::fast_t> auto& a, const auto&& b) noexcept;
    constexpr boolean::fast_t   operator !=(const tr1<any_tg, boolean::fast_t> auto&& a, const auto& b) noexcept;
    constexpr boolean::fast_t   operator !=(const tr1<any_tg, boolean::fast_t> auto&& a, const auto&& b) noexcept;*/

}
