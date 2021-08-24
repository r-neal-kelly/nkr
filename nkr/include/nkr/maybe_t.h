/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsics.h"
#include "nkr/traits.h"

namespace nkr {

    /// @nosubgrouping
    /// @copydoc _e81dde10_53a3_4c5e_b5e3_fa01c3325510
    class none_t
    {
    public:
        /// @name objects
        /// @copydoc _013126e0_1378_4f23_a393_bf330ab0b823
        /// @{
        none_t()                                    = default;  ///< @copydoc _4945c7b2_9854_48c5_9ffb_6e5e0d9ea8a2
        none_t(const none_t& other)                 = delete;   ///< @copydoc _9a1760ef_b09e_4e12_8008_54228eb4db46
        none_t(none_t&& other) noexcept             = delete;   ///< @copydoc _e4d8014b_ba97_4051_be28_9e60a1a81047
        none_t& operator =(const none_t& other)     = delete;   ///< @copydoc _c5b4d034_9395_4c88_b3cc_33d6ef0b44a3
        none_t& operator =(none_t&& other) noexcept = delete;   ///< @copydoc _8c3dca16_1f37_4d7b_bd14_522498aeb2e9
        ~none_t()                                   = default;  ///< @copydoc _d85fbe4a_ed6e_4ea0_8552_91e433238648
        /// @}
    };

    /// @nosubgrouping
    /// @ingroup _7752ee81_def2_4386_b164_bc31f29ce7b8
    /// @copydoc _9d52d2e1_c6dc_4dbb_ad58_01a219c6e510
    template <typename type_p>
    concept none_i = requires(type_p instance, const type_p const_instance)
    {
        { instance.operator =(none_t()) }           -> same_or_base_of_tr<type_p>;
        { const_instance.operator ==(none_t()) }    -> std::same_as<bool_t>;
        { const_instance.operator !=(none_t()) }    -> std::same_as<bool_t>;
    };

}

namespace nkr {

    /// @ingroup namespaces
    /// @copydoc _c8a34890_b904_42a7_a88c_ada39529db42
    namespace $maybe_t {};

}

namespace nkr { namespace $maybe_t {

    /// @nosubgrouping
    /// @copydoc _0d45c64a_558d_4bd7_baa2_6f521f6656d5
    template <built_in_tr built_in_p>
    class built_in_sp
    {
    public:
        /// @name aliases
        /// @copydoc _1acc637c_5d07_41c7_9a7c_996d963c2a59
        /// @{
        using value_t   = built_in_p;   ///< @copydoc _6d9bde0e_f973_4668_a07d_05729f4af0f6
        /// @}

    public:
        /// @name object data
        /// @copydoc _a132ddc6_1af5_4637_9b5d_3114ee912dff
        /// @{
        value_t value;  ///< @copydoc _acce0e58_343c_4481_a91a_7db997eb42b4
        /// @}

    public:
        /// @name objects
        /// @copydoc _1fcb90e5_b65a_4312_ac7f_9951456b3425
        /// @{
        built_in_sp();                                          ///< @copydoc _d18299ac_6d7e_4560_88ff_e53f4bb77069
        built_in_sp(value_t value);                             ///< @copydoc _aa14e4f4_23ce_4d01_a6be_c12342adf7e7
        built_in_sp(const built_in_sp& other);                  ///< @copydoc _b8bf31fb_a852_4c94_aa33_f6dc791a7a9f
        built_in_sp(built_in_sp&& other) noexcept;              ///< @copydoc _72a66390_63d7_4076_966f_c4a6c6d94c0a
        built_in_sp& operator =(value_t value);                 ///< @copydoc _40d586e6_43ec_4f57_a15f_9809bb2a36b4
        built_in_sp& operator =(const built_in_sp& other);      ///< @copydoc _6693684a_9d8b_45e3_9196_3e20af210319
        built_in_sp& operator = (built_in_sp&& other) noexcept; ///< @copydoc _003d4488_8885_414a_b34c_e6beb6c1019a
        ~built_in_sp();                                         ///< @copydoc _8befff79_9dcc_4bd8_91e6_a3cddab84821
        /// @}

    public:
        /// @name casts
        /// @copydoc _c2859fff_ae85_4e8e_8b1a_c9228bb961b4
        /// @{
        operator            value_t&();             ///< @copydoc _2a09a3db_f1fb_41ff_bb7d_83c4d2193bd5
        operator            const value_t&() const; ///< @copydoc _508d5690_a07a_42b9_b255_435e786ec73a

        explicit operator   bool_t() const;         ///< @copydoc _8e7ecbaa_f10a_41d8_814b_d462e8447e77
        /// @}

    public:
        /// @name operators
        /// @copydoc _b2f6d1e6_2a05_4d53_b01f_45f46cefe7c3
        /// @{
        value_t&        operator ()();              ///< @copydoc _0a0d6fe6_f1dc_4a12_8678_185933cbf587
        const value_t&  operator ()() const;        ///< @copydoc _b0a0511e_f1e4_4c6a_a9f4_487e27a55d9f

        bool_t          operator !() const;         ///< @copydoc _2324f3b7_bace_46c4_a6b1_093fda935391
        /// @}

        /// @name none_t interface
        /// @copydoc _1dfe08c1_275f_46e1_af39_240c6b354178
        /// @{
        built_in_sp&    operator =(none_t);         ///< @copydoc _8a90b1f2_c65f_4ad3_8d73_d985f67d6293
        bool_t          operator ==(none_t) const;  ///< @copydoc _ba6bc412_5d93_402c_aa70_359a0fe73cce
        bool_t          operator !=(none_t) const;  ///< @copydoc _f148b5f5_a869_429b_afcd_5f391558954a
        /// @}
    };

    /// @nosubgrouping
    /// @copydoc _870ca0b2_c146_47a9_838f_140187d046e9
    template <none_i user_defined_p>
    class user_defined_sp :
        public user_defined_p
    {
    public:
        /// @name aliases
        /// @copydoc _9582d918_063d_484b_be3a_28b753f1e85b
        /// @{
        using value_t   = user_defined_p;   ///< @copydoc _6cc07b8c_e756_474e_886d_be8bbee3392e
        /// @}

    public:
        /// @name inherited objects
        /// @{
        using value_t::value_t;
        using value_t::operator =;
        /// @}

    public:
        /// @name casts
        /// @copydoc _4d8d9df3_d8f9_4b63_bacf_e7cb8d2a45f4
        /// @{
        explicit operator   bool_t() const; ///< @copydoc _a4d05d29_07c0_4bdf_857d_2e932c5a77a8
        /// @}

    public:
        /// @name operators
        /// @copydoc _923f1cf1_39a3_4bdb_87a2_0378c0de9bf4
        /// @{
        value_t&            operator ()();              ///< @copydoc _c0521baf_74a7_4a40_9cd7_f474802ebfbe
        const value_t&      operator ()() const;        ///< @copydoc _110607cd_bdbe_488b_8c8a_15a03e07523b

        bool_t              operator !() const;         ///< @copydoc _ca79e353_f369_498d_9002_23fc79478493
        /// @}

        /// @name none_t interface
        /// @copydoc _83fd4e8c_fb12_4092_b6b7_0a2a5fe7e3ae
        /// @{
        user_defined_sp&    operator =(none_t);         ///< @copydoc _89e3c342_705e_4f5e_8c5a_d4a30c8e93aa
        bool_t              operator ==(none_t) const;  ///< @copydoc _0ba0e3d3_efa9_47a9_9843_c0bd2bb99dd5
        bool_t              operator !=(none_t) const;  ///< @copydoc _e03588e1_54fd_4f9b_9b34_54ff74341ccd
        /// @}
    };

}}

namespace nkr {

    /// @nosubgrouping
    /// @copydoc _1f11b26a_7bf8_462e_a657_b37f6313bff3
    template <typename invalid_p>
    class maybe_t
    {
    public:
        /// @name objects
        /// @copydoc _dbabc9c5_cd8c_484e_9c15_b2a1b9a189a6
        /// @{
        maybe_t()                                       = delete;   ///< @copydoc _b38b11f9_98b1_45b5_8242_7d1da0aa4949
        maybe_t(const maybe_t& other)                   = delete;   ///< @copydoc _4ad91ffe_91d1_4aab_b371_2e45fced4bb0
        maybe_t(maybe_t&& other) noexcept               = delete;   ///< @copydoc _783181a7_0ea9_467e_8c37_c0cee4b8cd77
        maybe_t& operator =(const maybe_t& other)       = delete;   ///< @copydoc _2fffa10c_fa78_4309_8ce7_0c9dfef9d911
        maybe_t& operator =(maybe_t&& other) noexcept   = delete;   ///< @copydoc _b57f9ee7_7133_4f1d_b8aa_e93038b42189
        ~maybe_t()                                      = delete;   ///< @copydoc _60fcb0e7_0dbe_4f97_a940_a31508f6363f
        /// @}
    };

    /// @nosubgrouping
    /// @copydoc _b0155c57_e98a_479c_b659_c2e869035bec
    template <built_in_tr built_in_p>
    class maybe_t<built_in_p> :
        public $maybe_t::built_in_sp<built_in_p>
    {
    public:
        /// @name inherited objects
        /// @{
        using $maybe_t::built_in_sp<built_in_p>::built_in_sp;
        using $maybe_t::built_in_sp<built_in_p>::operator =;
        /// @}
    };

    /// @nosubgrouping
    /// @copydoc _28243913_2a03_428d_95ac_cbabc3cb3baa
    template <none_i user_defined_p>
    class maybe_t<user_defined_p> :
        public $maybe_t::user_defined_sp<user_defined_p>
    {
    public:
        /// @name inherited objects
        /// @{
        using $maybe_t::user_defined_sp<user_defined_p>::user_defined_sp;
        using $maybe_t::user_defined_sp<user_defined_p>::operator =;
        /// @}
    };

}

namespace nkr {

    /// @nosubgrouping
    /// @copydoc _fe4b1321_2470_4544_b8c0_0e93c38e7275
    template <typename any_p>
    class some_t :
        public maybe_t<any_p>
    {
    public:
        /// @name aliases
        /// @copydoc _68e8ea24_c725_481e_96e2_83379ee8f177
        /// @{
        using value_t   = any_p;    ///< @copydoc _afe969ef_b9ff_4532_a311_5900ca7fba62
        /// @}

    public:
        /// @name inherited objects
        /// @{
        using maybe_t<value_t>::maybe_t;
        using maybe_t<value_t>::operator =;
        /// @}

    public:
        /// @name operators
        /// @copydoc _a9c2409d_1948_4a2d_a709_73323203c246
        /// @{
        some_t& operator =(none_t)  = delete;   ///< @copydoc _7e0c8790_9442_454e_aa96_8dd70e9e804e
        /// @}
    };

}

#include "nkr/maybe_t.inl"
