/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/z_bool_t.h"
#include "nkr/z_intrinsics.h"
#include "nkr/z_macros.h"
#include "nkr/z_traits.h"
#include "nkr/z_utils.h"

/// @copydoc _a5a2b1f5_e0b0_474a_949d_8fdcbaf67557
namespace nkr::$pointer_t {};

namespace nkr {

    template <typename unit_p>
    class pointer_t;

    struct                      pointer_tg  {};
    template <typename> struct  pointer_ttg {};

}

namespace nkr { namespace $pointer_t {

    template <typename type_p>
    concept any_tr =
        is_any_tr<type_p, pointer_t<typename type_p::unit_t>>;

}}

namespace nkr {

    template <>
    class type_traits_i<pointer_tg>
    {
    public:
        using of_t  = void_t;

    public:
        template <typename other_p>
        static constexpr c_bool_t   Is_Any();
    };

    template <$pointer_t::any_tr type_p>
    class type_traits_i<type_p> :
        public type_traits_i<pointer_tg>
    {
    public:
        using of_t  = type_p::unit_t;
    };

    template <>
    class template_traits_i<pointer_ttg>
    {
    public:
        template <typename of_p>
        using type_t    = pointer_t<of_p>;

    public:
        static constexpr c_bool_t   Is_Implemented();
    };

    template <>
    class template_traits_i<pointer_t> :
        public template_traits_i<pointer_ttg>
    {
    public:
    };

}

namespace nkr { namespace $pointer_t {

    /// @nosubgrouping
    /// @copydoc _4cac11ea_20bf_436b_a218_bd7a024c25ea
    template <any_type_tr unit_p>
    class any_type_sp
    {
    public:
        /// @name aliases
        /// @copydoc _b6a07638_8d8e_4493_873e_104d772023af
        /// @{
        using unit_t    = unit_p;   ///< @copydoc _92ae84ae_55d6_4911_9515_ed7941008d49
        using units_t   = unit_p*;  ///< @copydoc _bc1f6288_e979_4e82_8524_675eee13c515
        /// @}

    private:
        /// @name object data
        /// @copydoc _6ca35d80_e800_4856_a4b3_c43655537937
        /// @{
        units_t units;      ///< @copydoc _3df94cc1_43a4_4d35_ad6f_7a6ffd33d851
        count_t unit_count; ///< @copydoc _d2cf83c1_3e63_4a1a_85c8_351691f0c60d
        /// @}

    public:
        /// @name objects
        /// @copydoc _376ea0b2_78b0_4f2c_9c24_93a6c9f000e0
        /// @{
        any_type_sp();                                                                                          ///< @copydoc _1c8568bf_0ac5_435c_bb5a_05593d20d914

        any_type_sp(convertible_tr<unit_t*> auto unit);                                                         ///< @copydoc _dc28512c_2132_41d1_949d_65f941159534
        any_type_sp(convertible_tr<units_t> auto units, count_t unit_count);                                    ///< @copydoc _7215773f_344a_4e4f_87c7_31e12bfc8843

        any_type_sp(const any_type_sp& other);                                                                  ///< @copydoc _c0da811c_a80b_4636_8071_cd7f5d11462f
        any_type_sp(const volatile any_type_sp& other);                                                         ///< @copydoc _8b1b5b55_1e66_4bc9_bad3_ebfef7468786
        any_type_sp(any_type_sp&& other) noexcept;                                                              ///< @copydoc _bc93001b_b60a_457d_b315_8559c20f4d53
        any_type_sp(volatile any_type_sp&& other) noexcept;                                                     ///< @copydoc _c2685632_397f_4514_bf75_117ab75e291a

        any_type_sp&            operator =(const any_type_sp& other);                                           ///< @copydoc _a3311c87_1524_41ed_b4f1_4b63052493bf
        volatile any_type_sp&   operator =(const any_type_sp& other) volatile;                                  ///< @copydoc _d261c23f_1c7b_47c5_bccd_c9ff79f12e0a
        any_type_sp&            operator =(const volatile any_type_sp& other);                                  ///< @copydoc _93ebbc4c_1ae8_4983_a94b_75bb30a7c441
        volatile any_type_sp&   operator =(const volatile any_type_sp& other) volatile;                         ///< @copydoc _5b59fd59_d903_4976_8aec_e53a797779ec
        any_type_sp&            operator =(any_type_sp&& other) noexcept;                                       ///< @copydoc _54b20bdf_ad18_4306_9560_f7ad819ab2e9
        volatile any_type_sp&   operator =(any_type_sp&& other) volatile noexcept;                              ///< @copydoc _7e14f1c8_db41_4153_9771_cd20947f5b4f
        any_type_sp&            operator =(is_just_volatile_tr<any_type_sp> auto&& other) noexcept;             ///< @copydoc _63ada161_3f30_4c27_955a_6195ed353eb3
        volatile any_type_sp&   operator =(is_just_volatile_tr<any_type_sp> auto&& other) volatile noexcept;    ///< @copydoc _8578437a_9ec0_4990_af69_2826b21f3172

        ~any_type_sp();                                                                                         ///< @copydoc _1fc3694a_7961_45fc_9b96_37103fdef1fb
        /// @}

    public:
        /// @name methods
        /// @copydoc _23c3de4b_21be_4c49_ae51_b102451aa700
        /// @{
        unit_t*&                Unit();                         ///< @copydoc _1c56eb69_0069_411b_806f_8d3b9613d720
        unit_t* const&          Unit() const;                   ///< @copydoc _f50fe904_78fe_43df_ba73_fc9f10d459f8
        unit_t* volatile&       Unit() volatile;                ///< @copydoc _0518f8f0_eb02_40df_ae0f_60b0b405bfa3
        unit_t* const volatile& Unit() const volatile;          ///< @copydoc _27cedfc3_54d9_4160_bf8f_7a05ccb87db5

        units_t&                Units();                        ///< @copydoc _c5f9a133_b082_481e_a84c_fd6ff15b31f6
        const units_t&          Units() const;                  ///< @copydoc _33ec7f42_c7c0_4441_a79c_9e00a8ef1eaa
        volatile units_t&       Units() volatile;               ///< @copydoc _19a5031d_a013_4ab1_b915_88ac00e7b4eb
        const volatile units_t& Units() const volatile;         ///< @copydoc _6273d5f2_da05_45ee_b68b_589de1976d86

        count_t&                Unit_Count();                   ///< @copydoc _4c60b492_a7b6_4d36_ae20_409b21d874ef
        const count_t&          Unit_Count() const;             ///< @copydoc _88cce35b_220e_41c0_b2e7_5fee257e382b
        volatile count_t&       Unit_Count() volatile;          ///< @copydoc _40f0b4d2_91fd_4ec8_bfb2_d7ae757295d3
        const volatile count_t& Unit_Count() const volatile;    ///< @copydoc _51e49569_904a_4b32_b9ae_9c7c7c266f2b
        /// @}

    public:
        /// @name casts
        /// @copydoc _012ca2f7_33c3_49d5_99d5_f5411110a033
        /// @{
        operator    units_t&();                                 ///< @copydoc _ceba70a6_b9fe_4f2d_ae6c_d629708ed612
        operator    const units_t&() const;                     ///< @copydoc _bc287b82_44ec_4926_9154_f9729a9c1fe7
        operator    volatile units_t&() volatile;               ///< @copydoc _0e6d4d71_ef0b_4953_9e6a_038b6678c2c2
        operator    const volatile units_t&() const volatile;   ///< @copydoc _83809130_e0a4_48cd_9ead_4a8680a75f13
        /// @}

    public:
        /// @name operators
        /// @copydoc _59cb3501_f53e_44e8_a2c3_fe845a0b24f9
        /// @{
        units_t&                operator ()();                                                                  ///< @copydoc _771c7948_77bc_41a4_aa5f_87f64cb5975c
        const units_t&          operator ()() const;                                                            ///< @copydoc _15b2305d_9b5c_4ad8_983e_3a32dfeb0da7
        volatile units_t&       operator ()() volatile;                                                         ///< @copydoc _4a4ac859_4ad6_4c53_b207_cb0b04369ffd
        const volatile units_t& operator ()() const volatile;                                                   ///< @copydoc _0a406e7b_2822_4dde_bc55_8489736ced1b
        any_type_sp&            operator ()(convertible_tr<unit_t*> auto unit);                                 ///< @copydoc _c9e40e89_acad_4920_a54f_7e01b977320b
        volatile any_type_sp&   operator ()(convertible_tr<unit_t*> auto unit) volatile;                        ///< @copydoc _6bb1d878_92ab_4719_9210_8c2f817efed8
        any_type_sp&            operator ()(convertible_tr<units_t> auto units, count_t unit_count);            ///< @copydoc _a09d2106_04e4_470e_9221_b659b01e229d
        volatile any_type_sp&   operator ()(convertible_tr<units_t> auto units, count_t unit_count) volatile;   ///< @copydoc _5a6f9877_fc1c_489a_b024_b32b051ec5e9

        any_type_sp             operator +(integer_tr auto amount) const;                                       ///< @copydoc _e301f083_3d5e_42da_8e77_3acaa1e9aa09
        any_type_sp             operator +(integer_tr auto amount) const volatile;                              ///< @copydoc _1ed17124_582f_4376_8398_88733a32b921
        any_type_sp             operator -(integer_tr auto amount) const;                                       ///< @copydoc _875e34d4_d560_49f3_b210_a6df9d88ef06
        any_type_sp             operator -(integer_tr auto amount) const volatile;                              ///< @copydoc _67adb21c_e639_4e3b_9c26_0afdf2bb0bef

        any_type_sp&            operator +=(integer_tr auto amount);                                            ///< @copydoc _1b2dca97_2fa5_4f2c_b11e_3b14e0e98206
        volatile any_type_sp&   operator +=(integer_tr auto amount) volatile;                                   ///< @copydoc _f67c4d55_7d0c_4f2e_81d5_4f6555082e17
        any_type_sp&            operator -=(integer_tr auto amount);                                            ///< @copydoc _42369c67_1da6_4d9e_ac47_117f6970bfb4
        volatile any_type_sp&   operator -=(integer_tr auto amount) volatile;                                   ///< @copydoc _7af64f3d_3d85_4408_84ea_518d108a105c

        any_type_sp&            operator ++();                                                                  ///< @copydoc _f1737231_af90_4c9c_b95b_ec5eb2e7f450
        volatile any_type_sp&   operator ++() volatile;                                                         ///< @copydoc _eb9350f0_32aa_46a5_993f_55ebdb9a34cf
        any_type_sp             operator ++(int);                                                               ///< @copydoc _2f97eb81_3d20_45aa_bdc0_8a3d47d356a8
        any_type_sp             operator ++(int) volatile;                                                      ///< @copydoc _ecbb4360_3af0_471f_b94d_0e34603c4e41
        any_type_sp&            operator --();                                                                  ///< @copydoc _5e3fc904_5f6c_448b_a2aa_ab2ac055b7fb
        volatile any_type_sp&   operator --() volatile;                                                         ///< @copydoc _5f902ac6_965c_4947_ba12_8f0387fa5237
        any_type_sp             operator --(int);                                                               ///< @copydoc _bfcdc54e_f98d_4156_844e_e039627cb986
        any_type_sp             operator --(int) volatile;                                                      ///< @copydoc _68c72174_ae0a_4086_8eae_c1780d1b2234

        units_t                 operator ->() const;                                                            ///< @copydoc _ecb3f076_6b07_4ebe_a1c1_e519c52ae5d4
        units_t                 operator ->() const volatile;                                                   ///< @copydoc _f0c4692a_f3a4_4f06_8743_8929b7ba5304
        unit_t&                 operator *() const;                                                             ///< @copydoc _0d908434_2b38_4c9b_825e_9c1d6601bbc2
        unit_t&                 operator *() const volatile;                                                    ///< @copydoc _4824a700_3433_4c7f_9f6f_9528ccb17c1b
        unit_t&                 operator [](index_t index) const;                                               ///< @copydoc _a138c11a_3a11_44e0_b98b_6bf89bcaea09
        unit_t&                 operator [](index_t index) const volatile;                                      ///< @copydoc _3bf83803_d863_4f44_b227_bb7da6b7225a
        /// @}

    public:
        /// @name none_t interface
        /// @copydoc _839fa066_8b16_4951_a6d7_1fa27efb1a6a
        /// @{
        any_type_sp(none_t);                                        ///< @copydoc _9d5cf4be_18c1_4f02_b0a5_ac4b05160414

        any_type_sp&            operator =(none_t);                 ///< @copydoc _17a283ad_7c14_497b_ab48_21b2395c7b88
        volatile any_type_sp&   operator =(none_t) volatile;        ///< @copydoc _7e5ffc67_94ec_46e7_8046_25b0b689b6d6

        bool_t                  operator ==(none_t) const;          ///< @copydoc _de6fa37c_fa49_47e0_81b9_188f7f4d3212
        bool_t                  operator ==(none_t) const volatile; ///< @copydoc _9c596a46_a3af_434b_9ea3_30cedd7b5473
        bool_t                  operator !=(none_t) const;          ///< @copydoc _559f619a_aa33_40ac_8c52_f4daaeff5c59
        bool_t                  operator !=(none_t) const volatile; ///< @copydoc _96405476_0e1b_4233_8c8a_3bde316329f0
        /// @}
    };

    /// @nosubgrouping
    /// @copydoc _4c92f1e4_18e6_4f53_84aa_79861d6edfc3
    template <any_non_type_tr unit_p>
    class any_non_type_sp
    {
    public:
        /// @name aliases
        /// @copydoc _6d178bfd_8931_4666_a9f5_ddb184bed5c2
        /// @{
        using unit_t    = unit_p;   ///< @copydoc _a1bd28d4_dd52_4df5_a8c4_71c23084b858
        using units_t   = unit_p*;  ///< @copydoc _48d29ef7_5d22_41f3_8d75_01b8509d2d36
        /// @}

    private:
        /// @name object data
        /// @copydoc _e9a447d1_530b_44a4_ad80_d9700c7b718d
        /// @{
        units_t units;      ///< @copydoc _ee3b9730_4ef5_4423_8d50_2e1c4dd568d9
        count_t unit_count; ///< @copydoc _8349cb90_8bd1_4c28_9268_6a10c96395a1
        /// @}

    public:
        /// @name objects
        /// @copydoc _1dd1de0b_2b60_4cc7_a0b9_9404515162ca
        /// @{
        any_non_type_sp();                                                                                              ///< @copydoc _fd4cb9f3_981d_4428_b08f_b84844264664
        any_non_type_sp(convertible_tr<unit_t*> auto unit);                                                             ///< @copydoc _f92563fb_d82f_40df_a9bc_ea3cf1d9f8cc
        any_non_type_sp(convertible_tr<units_t> auto units, count_t unit_count);                                        ///< @copydoc _7305c030_e245_4ca6_be99_f51e7db9aea8

        any_non_type_sp(const any_non_type_sp& other);                                                                  ///< @copydoc _97bf1598_b159_4b71_94d0_3b3a37dae639
        any_non_type_sp(const volatile any_non_type_sp& other);                                                         ///< @copydoc _f3f461da_c78f_4060_862b_6b1e07356dc3
        any_non_type_sp(any_non_type_sp&& other) noexcept;                                                              ///< @copydoc _00ebd123_400e_4aa9_b7a7_7ca0932fcf7a
        any_non_type_sp(volatile any_non_type_sp&& other) noexcept;                                                     ///< @copydoc _a89d0874_ed05_451d_b9a1_d1badaa4b084

        any_non_type_sp&            operator =(const any_non_type_sp& other);                                           ///< @copydoc _96b931a4_ba96_4679_91d1_1ed8bec9396c
        volatile any_non_type_sp&   operator =(const any_non_type_sp& other) volatile;                                  ///< @copydoc _9231978e_46d8_4e62_a169_010b10d84ad6
        any_non_type_sp&            operator =(const volatile any_non_type_sp& other);                                  ///< @copydoc _4c157309_a133_4160_8fa8_843920acc7b3
        volatile any_non_type_sp&   operator =(const volatile any_non_type_sp& other) volatile;                         ///< @copydoc _e2f10a34_b38e_450b_8013_2e1fe76752f2
        any_non_type_sp&            operator =(any_non_type_sp&& other) noexcept;                                       ///< @copydoc _f0477023_82a3_4048_9313_62387fdff537
        volatile any_non_type_sp&   operator =(any_non_type_sp&& other) volatile noexcept;                              ///< @copydoc _5da75588_c326_4cdf_b75d_a76ef69babfc
        any_non_type_sp&            operator =(is_just_volatile_tr<any_non_type_sp> auto&& other) noexcept;             ///< @copydoc _1b70321c_f92a_45d7_aba4_aa2d61cb621b
        volatile any_non_type_sp&   operator =(is_just_volatile_tr<any_non_type_sp> auto&& other) volatile noexcept;    ///< @copydoc _ca3664b2_a4d2_428a_a135_49e51f8fd63a

        ~any_non_type_sp();                                                                                             ///< @copydoc _459bbcf9_2eae_4ac5_a795_192dede69071
        /// @}

    public:
        /// @name methods
        /// @copydoc _22e54a53_78bc_4bed_be09_e3f9ffb503ee
        /// @{
        unit_t*&                Unit();                         ///< @copydoc _a43c8247_1d23_43a7_8876_590f55f25d72
        unit_t* const&          Unit() const;                   ///< @copydoc _509d6dcd_295f_4b06_9a65_1ebd6094fa7f
        unit_t* volatile&       Unit() volatile;                ///< @copydoc _12c45eff_16d4_437a_9513_440ef7ebb9a0
        unit_t* const volatile& Unit() const volatile;          ///< @copydoc _a1d6665b_1eea_43f6_91da_d1213ee7e047

        units_t&                Units();                        ///< @copydoc _f68ef888_8644_4395_a175_62d32fa0eace
        const units_t&          Units() const;                  ///< @copydoc _434d2816_c402_4cee_bf83_48944a14d932
        volatile units_t&       Units() volatile;               ///< @copydoc _262e6f48_f738_4fc0_b093_de8245d684e8
        const volatile units_t& Units() const volatile;         ///< @copydoc _953b5ac5_1ed5_424b_b8f0_88f421ad4bfe

        count_t&                Unit_Count();                   ///< @copydoc _547d6e2e_7505_4f5d_9087_28060695980c
        const count_t&          Unit_Count() const;             ///< @copydoc _b2ea1c73_095f_4e58_b6e0_abfb43f29860
        volatile count_t&       Unit_Count() volatile;          ///< @copydoc _ba0df937_e384_437c_8fe8_d92be3989e99
        const volatile count_t& Unit_Count() const volatile;    ///< @copydoc _f05031e8_c9f4_4ea5_ace7_454373e81e36
        /// @}

    public:
        /// @name casts
        /// @copydoc _6ba21839_d029_4444_a388_e963e6cf432f
        /// @{
        operator    units_t&();                                 ///< @copydoc _6586aca8_e591_4822_a9fc_f2de2c0b834d
        operator    const units_t&() const;                     ///< @copydoc _f1be559d_58a5_4d6a_8dea_6b80e0ee1065
        operator    volatile units_t&() volatile;               ///< @copydoc _7b5233ee_8c56_453f_a431_4dbf83879f4e
        operator    const volatile units_t&() const volatile;   ///< @copydoc _7e1cb906_3aad_4960_89fd_981cb8e4830a
        /// @}

    public:
        /// @name operators
        /// @copydoc _fe6b1e12_7a52_4c6c_a924_9cf46a10c3ca
        /// @{
        units_t&                    operator ()();                                                                  ///< @copydoc _4b79370c_f362_45f9_9d37_b731f316025d
        const units_t&              operator ()() const;                                                            ///< @copydoc _bbf32227_c0fc_4838_894e_6a906cefdf0e
        volatile units_t&           operator ()() volatile;                                                         ///< @copydoc _a491545e_894b_432c_9317_1fc2afe6d66d
        const volatile units_t&     operator ()() const volatile;                                                   ///< @copydoc _be62344a_26ad_486c_b424_610bfc35ec80
        any_non_type_sp&            operator ()(convertible_tr<unit_t*> auto unit);                                 ///< @copydoc _aaf4fd00_88d2_4dde_8bde_526c30eaf395
        volatile any_non_type_sp&   operator ()(convertible_tr<unit_t*> auto unit) volatile;                        ///< @copydoc _d9232d93_f804_4769_a277_4fb9e488f865
        any_non_type_sp&            operator ()(convertible_tr<units_t> auto units, count_t unit_count);            ///< @copydoc _533c931e_e282_44b8_8737_12a14ba71e6f
        volatile any_non_type_sp&   operator ()(convertible_tr<units_t> auto units, count_t unit_count) volatile;   ///< @copydoc _7768ca0a_8a99_41d2_9f01_623d7d889d5e
        /// @}

    public:
        /// @name none_t interface
        /// @copydoc _2862d75a_5b99_4855_aa88_475d95f59e46
        /// @{
        any_non_type_sp(none_t);                                        ///< @copydoc _eb685f00_492e_4754_a81e_99599e24ddb0

        any_non_type_sp&            operator =(none_t);                 ///< @copydoc _28b31b9e_9fb9_4ae1_a8b4_6e960c7f83c4
        volatile any_non_type_sp&   operator =(none_t) volatile;        ///< @copydoc _d88af58e_246d_4232_9f71_c77678a0c641

        bool_t                      operator ==(none_t) const;          ///< @copydoc _db3bfe56_5f15_4002_81c8_b5d3e54bd300
        bool_t                      operator ==(none_t) const volatile; ///< @copydoc _fa1b4d58_e708_427a_a61b_25d80d660d41
        bool_t                      operator !=(none_t) const;          ///< @copydoc _2afca332_ab8d_4ae4_b89b_3afcbe8370c4
        bool_t                      operator !=(none_t) const volatile; ///< @copydoc _5ca204d1_cae9_4cf7_8ae2_6e452d788063
        /// @}
    };

}}

namespace nkr {

    /// @nosubgrouping
    /// @copydoc _e370da3e_9474_437e_843e_e14b8ccf6a1c
    template <typename unit_p>
    class pointer_t
    {
    public:
        /// @name objects
        /// @copydoc 
        /// @{
        pointer_t()                                                                                     = delete;

        pointer_t(const pointer_t& other)                                                               = delete;
        pointer_t(const volatile pointer_t& other)                                                      = delete;
        pointer_t(pointer_t&& other) noexcept                                                           = delete;
        pointer_t(volatile pointer_t&& other) noexcept                                                  = delete;

        pointer_t&          operator =(const pointer_t& other)                                          = delete;
        volatile pointer_t& operator =(const pointer_t& other) volatile                                 = delete;
        pointer_t&          operator =(const volatile pointer_t& other)                                 = delete;
        volatile pointer_t& operator =(const volatile pointer_t& other) volatile                        = delete;
        pointer_t&          operator =(pointer_t&& other) noexcept                                      = delete;
        volatile pointer_t& operator =(pointer_t&& other) volatile noexcept                             = delete;
        pointer_t&          operator =(is_just_volatile_tr<pointer_t> auto&& other) noexcept            = delete;
        volatile pointer_t& operator =(is_just_volatile_tr<pointer_t> auto&& other) volatile noexcept   = delete;

        ~pointer_t()                                                                                    = delete;
        /// @}
    };

    /// @nosubgrouping
    /// @copydoc _7598e667_809c_4a66_99a0_4a061980c7f9
    template <any_type_tr any_type_p>
    class pointer_t<any_type_p> :
        public $pointer_t::any_type_sp<any_type_p>
    {
    public:
        /// @name aliases
        /// @copydoc 
        /// @{
        using base_t    = $pointer_t::any_type_sp<any_type_p>;
        /// @}

    public:
        /// @name objects
        /// @copydoc 
        /// @{
        nkr_DEFINE_INHERITANCE_WRAPPER_CTORS_AND_DTOR(pointer_t, base_t);
        /// @}

    private:
        nkr_DEFINE_INHERITANCE_WRAPPER_BASE_ACCESSORS(Base, base_t);
    };

    /// @nosubgrouping
    /// @copydoc _f850063c_8453_4b64_959a_562c8cf9037b
    template <any_non_type_tr any_non_type_p>
    class pointer_t<any_non_type_p> :
        public $pointer_t::any_non_type_sp<any_non_type_p>
    {
    public:
        /// @name aliases
        /// @copydoc 
        /// @{
        using base_t    = $pointer_t::any_non_type_sp<any_non_type_p>;
        /// @}

    public:
        /// @name objects
        /// @copydoc 
        /// @{
        nkr_DEFINE_INHERITANCE_WRAPPER_CTORS_AND_DTOR(pointer_t, base_t);
        /// @}

    private:
        nkr_DEFINE_INHERITANCE_WRAPPER_BASE_ACCESSORS(Base, base_t);
    };

}

namespace nkr {

    bool_t  operator ==(const tr1<any_tg, pointer_tg> auto& a, const tr0<any_tg> auto& b);
    bool_t  operator ==(const tr1<any_tg, pointer_tg> auto& a, const tr0<any_tg> auto&& b);
    bool_t  operator ==(const tr1<any_tg, pointer_tg> auto&& a, const tr0<any_tg> auto& b);
    bool_t  operator ==(const tr1<any_tg, pointer_tg> auto&& a, const tr0<any_tg> auto&& b);

    bool_t  operator !=(const tr1<any_tg, pointer_tg> auto& a, const tr0<any_tg> auto& b);
    bool_t  operator !=(const tr1<any_tg, pointer_tg> auto& a, const tr0<any_tg> auto&& b);
    bool_t  operator !=(const tr1<any_tg, pointer_tg> auto&& a, const tr0<any_tg> auto& b);
    bool_t  operator !=(const tr1<any_tg, pointer_tg> auto&& a, const tr0<any_tg> auto&& b);

}
