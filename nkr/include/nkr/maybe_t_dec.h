/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/bool_t.h"
#include "nkr/intrinsics.h"
#include "nkr/macros.h"
#include "nkr/none_i.h"
#include "nkr/traits.h"

namespace nkr {

    /// @ingroup _d1cd4369_e0f4_4062_8f58_611395da215e
    /// @copydoc _c8a34890_b904_42a7_a88c_ada39529db42
    namespace $maybe_t {
    
        /// @ingroup _d1cd4369_e0f4_4062_8f58_611395da215e
        /// @copydoc _1145e7f5_3595_468d_8aca_2c1336bdc5b8
        namespace $built_in_sp {};
    
    }

}

namespace nkr { namespace $maybe_t { namespace $built_in_sp {

    /// @nosubgrouping
    /// @copydoc _0d45c64a_558d_4bd7_baa2_6f521f6656d5
    template <typename any_p>
    class any_sp
    {
    public:
        /// @name aliases
        /// @copydoc _1acc637c_5d07_41c7_9a7c_996d963c2a59
        /// @{
        using value_t   = any_p;    ///< @copydoc _6d9bde0e_f973_4668_a07d_05729f4af0f6
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
        any_sp();                                       ///< @copydoc _d18299ac_6d7e_4560_88ff_e53f4bb77069
        any_sp(value_t value);                          ///< @copydoc _aa14e4f4_23ce_4d01_a6be_c12342adf7e7
        any_sp(const any_sp& other);                    ///< @copydoc _b8bf31fb_a852_4c94_aa33_f6dc791a7a9f
        any_sp(any_sp&& other) noexcept;                ///< @copydoc _72a66390_63d7_4076_966f_c4a6c6d94c0a
        any_sp& operator =(value_t value);              ///< @copydoc _40d586e6_43ec_4f57_a15f_9809bb2a36b4
        any_sp& operator =(const any_sp& other);        ///< @copydoc _6693684a_9d8b_45e3_9196_3e20af210319
        any_sp& operator =(any_sp&& other) noexcept;    ///< @copydoc _003d4488_8885_414a_b34c_e6beb6c1019a
        ~any_sp();                                      ///< @copydoc _8befff79_9dcc_4bd8_91e6_a3cddab84821
        /// @}

    public:
        /// @name casts
        /// @copydoc _c2859fff_ae85_4e8e_8b1a_c9228bb961b4
        /// @{
        operator    value_t&();             ///< @copydoc _2a09a3db_f1fb_41ff_bb7d_83c4d2193bd5
        operator    const value_t&() const; ///< @copydoc _508d5690_a07a_42b9_b255_435e786ec73a
        /// @}

    public:
        /// @name operators
        /// @copydoc _b2f6d1e6_2a05_4d53_b01f_45f46cefe7c3
        /// @{
        value_t&        operator ()();          ///< @copydoc _0a0d6fe6_f1dc_4a12_8678_185933cbf587
        const value_t&  operator ()() const;    ///< @copydoc _b0a0511e_f1e4_4c6a_a9f4_487e27a55d9f

        auto*           operator &();           ///< @copydoc _818b2694_ff2d_40b7_bb82_b91338a71319
        const auto*     operator &() const;     ///< @copydoc _11a0b137_9ce6_4389_b814_fc3dbd707581
        /// @}

        /// @name none_t interface
        /// @copydoc _1dfe08c1_275f_46e1_af39_240c6b354178
        /// @{
        any_sp(none_t);                     ///< @copydoc _3c6a0391_99dd_46ef_aebd_c6cd2a474a2b
        any_sp& operator =(none_t);         ///< @copydoc _8a90b1f2_c65f_4ad3_8d73_d985f67d6293
        
        bool_t  operator ==(none_t) const;  ///< @copydoc _ba6bc412_5d93_402c_aa70_359a0fe73cce
        bool_t  operator !=(none_t) const;  ///< @copydoc _f148b5f5_a869_429b_afcd_5f391558954a
        /// @}
    };

    /// @nosubgrouping
    /// @copydoc _38ebec22_bbe8_4dca_a3dd_e0d3ce7f680f
    template <real_tr real_p>
    class real_sp :
        public any_sp<real_p>
    {
    public:
        /// @name aliases
        /// @copydoc _bb2c1a35_af7a_4084_ad9d_59a969254b54
        /// @{
        using base_t    = any_sp<real_p>;   ///< @copydoc 
        using value_t   = real_p;           ///< @copydoc _6337ae7b_7866_4d54_8259_2228811679c6
        /// @}

    public:
        /// @name objects
        /// @copydoc 
        /// @{
        nkr_DEFINE_INHERITANCE_WRAPPER_CTORS_AND_DTOR(real_sp, base_t);
        /// @}

    public:
        /// @name operators
        /// @copydoc _21a14be3_cb6c_4bbe_831d_6da25cb18a1d
        /// @{
        value_t operator ++();      ///< @copydoc _45465f70_1de8_47e3_a10d_586e5c4636cc
        value_t operator ++(int);   ///< @copydoc _cc4463c5_573f_4fda_8971_f19e7a91d744
        value_t operator --();      ///< @copydoc _08e887d6_7157_460f_b91e_13073571bb06
        value_t operator --(int);   ///< @copydoc _47619a94_f70e_422d_bc75_a57a426c325f
        /// @}
    };

    /// @nosubgrouping
    /// @copydoc _853d9bea_a9d0_40eb_81c1_aa874fcbdfb1
    template <pointer_tr pointer_p>
    class pointer_sp :
        public any_sp<pointer_p>
    {
    public:
        /// @name aliases
        /// @copydoc _9f86f607_6972_4326_b817_4a06a53d154d
        /// @{
        using base_t    = any_sp<pointer_p>;    ///< @copydoc 
        using value_t   = pointer_p;            ///< @copydoc _febf525c_e1d2_43d7_93f2_8cc96a495097
        /// @}

    public:
        /// @name objects
        /// @copydoc 
        /// @{
        nkr_DEFINE_INHERITANCE_WRAPPER_CTORS_AND_DTOR(pointer_sp, base_t);
        /// @}

    public:
        /// @name operators
        /// @copydoc _73f0a437_cda0_4e5d_91e0_8e4563970b36
        /// @{
        value_t operator ->() const; ///< @copydoc _203f8176_57e2_42f5_9ef2_850f3151f3a9
        /// @}
    };

}}}

namespace nkr { namespace $maybe_t {

    /// @nosubgrouping
    /// @copydoc _476cf1d5_7332_4bfc_acfb_d3a5e3802c6f
    template <typename any_p>
    class built_in_sp :
        public $built_in_sp::any_sp<any_p>
    {
    private:
        using base_t    = $built_in_sp::any_sp<any_p>;

    public:
        /// @name objects
        /// @copydoc _f4d38cc3_7d9e_402c_8ddb_0917ce83dc55
        /// @{
        nkr_DEFINE_INHERITANCE_WRAPPER_CTORS_AND_DTOR(built_in_sp, base_t);
        /// @}
    };

    /// @nosubgrouping
    /// @copydoc _54610ffc_35de_47f2_9b0a_03da52782104
    template <real_tr real_p>
    class built_in_sp<real_p> :
        public $built_in_sp::real_sp<real_p>
    {
    private:
        using base_t    = $built_in_sp::real_sp<real_p>;

    public:
        /// @name objects
        /// @copydoc _5b844485_95be_4c1a_a964_62ddfce97452
        /// @{
        nkr_DEFINE_INHERITANCE_WRAPPER_CTORS_AND_DTOR(built_in_sp, base_t);
        /// @}
    };

    /// @nosubgrouping
    /// @copydoc _eb401275_a224_48ec_ab23_6d0c82b83d8a
    template <pointer_tr pointer_p>
    class built_in_sp<pointer_p> :
        public $built_in_sp::pointer_sp<pointer_p>
    {
    private:
        using base_t    = $built_in_sp::pointer_sp<pointer_p>;

    public:
        /// @name objects
        /// @copydoc _04720ddf_c679_4933_bf4f_f0da04fe53f8
        /// @{
        nkr_DEFINE_INHERITANCE_WRAPPER_CTORS_AND_DTOR(built_in_sp, base_t);
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
        /// @name objects
        /// @copydoc _bace7444_fb65_41c3_affb_6fd3c6dee6a1
        /// @{
        nkr_DEFINE_INHERITANCE_WRAPPER_CTORS_AND_DTOR(user_defined_sp, value_t);
        /// @}

    public:
        /// @name casts
        /// @copydoc _4d8d9df3_d8f9_4b63_bacf_e7cb8d2a45f4
        /// @{
        operator    bool_t() const; ///< @copydoc _a4d05d29_07c0_4bdf_857d_2e932c5a77a8
        /// @}

    public:
        /// @name operators
        /// @copydoc _923f1cf1_39a3_4bdb_87a2_0378c0de9bf4
        /// @{
        value_t&        operator ()();          ///< @copydoc _c0521baf_74a7_4a40_9cd7_f474802ebfbe
        const value_t&  operator ()() const;    ///< @copydoc _110607cd_bdbe_488b_8c8a_15a03e07523b

        bool_t          operator !() const;     ///< @copydoc _ca79e353_f369_498d_9002_23fc79478493

        auto*           operator &();           ///< @copydoc _3aa1aabe_9154_40a3_8e90_4159a3e155a3
        const auto*     operator &() const;     ///< @copydoc _82fde6d1_3c38_4a5e_9686_8dac3c57c28c
        /// @}

        /// @name none_t interface
        /// @copydoc _83fd4e8c_fb12_4092_b6b7_0a2a5fe7e3ae
        /// @{
        user_defined_sp(none_t);                ///< @copydoc _e6a84081_f2de_4db3_8d9b_ba72a93e5455
        user_defined_sp& operator =(none_t);    ///< @copydoc _89e3c342_705e_4f5e_8c5a_d4a30c8e93aa
        
        bool_t  operator ==(none_t) const;      ///< @copydoc _0ba0e3d3_efa9_47a9_9843_c0bd2bb99dd5
        bool_t  operator !=(none_t) const;      ///< @copydoc _e03588e1_54fd_4f9b_9b34_54ff74341ccd
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
    private:
        using base_t    = $maybe_t::built_in_sp<built_in_p>;

    public:
        /// @name objects
        /// @copydoc _26036428_887b_4bb1_a423_e576810532b5
        /// @{
        nkr_DEFINE_INHERITANCE_WRAPPER_CTORS_AND_DTOR(maybe_t, base_t);
        /// @}
    };

    /// @nosubgrouping
    /// @copydoc _28243913_2a03_428d_95ac_cbabc3cb3baa
    template <none_i user_defined_p>
    class maybe_t<user_defined_p> :
        public $maybe_t::user_defined_sp<user_defined_p>
    {
    private:
        using base_t    = $maybe_t::user_defined_sp<user_defined_p>;

    public:
        /// @name objects
        /// @copydoc _6f6b3ac8_c46b_4c2c_87c1_5cd210808876
        /// @{
        nkr_DEFINE_INHERITANCE_WRAPPER_CTORS_AND_DTOR(maybe_t, base_t);
        /// @}
    };

}
