/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

// nkr::constant_t Identity
/**
    @defgroup _144407f2_f15c_4e13_9507_168de44b2b1f nkr::constant_t Identity
    @ingroup _c8774f4a_9a1a_4339_9147_4d0ded6c301f

    @brief
    The [entity group](@ref _f2fd9706_47ef_4a9d_bb60_39f7055128ee) that forms the [identity](@ref _fd6e7324_a83c_4317_a5a8_9edfabfa7fce) of nkr::constant_t.

    @details
    [Primary Entity](@ref _75c3be6c_da45_4652_bf67_513fde1b9a06):
    - nkr::constant_t

    [Traits](@ref _a7aaad0a_73cd_4237_92ee_0ea24814c2a7):
    - nkr::constant_tr
    - nkr::constant_ttr

    [Tags](@ref _aa695b0f_e642_4521_928e_5deba76d9bc6):
    - nkr::constant_tg
    - nkr::constant_ttg
*/

// nkr::constant_t
/**
    @class _09f6d63e_f4b7_46e1_b499_fcfa5132d76f
    @private

    @brief
    Represents an immutable [literal value](@ref _aafc1022_913c_4a2a_8747_dacdbef8f762) in a [compile-time](@ref _b11fed50_b607_4f57_b5e7_af27886ddb6a) or [run-time](@ref _6486340c_e540_4c05_8d06_90e4cc18c1b3) context.

    @details
    nkr::constant_t is primarily used as a [template type parameter](@ref _4e8909a3_7865_4a80_ba3f_1eaef38fb24f) in place of a [template value parameter](@ref _a259e988_bc05_43c7_bcd8_ac5831d2153c), for the sake of the [one kind of template parameter design](@ref _ab449a60_e674_4d0a_91d9_557ec4c5660c). However, there's nothing restricting its use in other contexts where desirable.

    @par
    @note
    nkr::constant_t is the [primary entity](@ref _75c3be6c_da45_4652_bf67_513fde1b9a06) of the [nkr::constant_t Identity](@ref _144407f2_f15c_4e13_9507_168de44b2b1f).

    @par
    @note
    This type is similar to [std::integral_constant](https://en.cppreference.com/w/cpp/types/integral_constant).
*/

    // nkr::constant_t::value_t
    /**
        @class _3930c6fb_a15c_42cd_a6db_b41d3318b998
        @private

        @brief
        The [primary inner type](@ref _8f6a1988_bbdb_46ba_8746_40c02acda41c) of nkr::constant_t.
    */

// nkr::constant_tr
/**
    @class _7011a9e2_12cb_4fb5_b2b0_83080a091ab4
    @private

    @brief
    The [identity type trait](@ref _5579f9ac_41ef_49be_ba96_98a19cd04121) for nkr::constant_t.

    @par
    @note
    nkr::constant_tr is an [entity](@ref _beac6b26_2cf9_4051_99ba_4ae5a39e66ec) of the [nkr::constant_t Identity](@ref _144407f2_f15c_4e13_9507_168de44b2b1f).
*/

// nkr::constant_ttr
/**
    @class _651a47d3_40f7_4a6f_be9c_5fbc92a159ec
    @private

    @brief
    The [identity template trait](@ref _2d942eaa_04fe_4671_8aa0_3969a2bcf5b7) for nkr::constant_t.

    @par
    @note
    nkr::constant_ttr is an [entity](@ref _beac6b26_2cf9_4051_99ba_4ae5a39e66ec) of the [nkr::constant_t Identity](@ref _144407f2_f15c_4e13_9507_168de44b2b1f).
*/

// nkr::constant_tg
/**
    @class _c8ccd7aa_610c_4f1b_ba49_de22374f3b78
    @private

    @brief
    The [identity type tag](@ref _e127f763_d3a9_4042_8c0b_654120967de3) for nkr::constant_t.

    @par
    @note
    nkr::constant_tg is an [entity](@ref _beac6b26_2cf9_4051_99ba_4ae5a39e66ec) of the [nkr::constant_t Identity](@ref _144407f2_f15c_4e13_9507_168de44b2b1f).
*/

    // nkr::constant_tg::tag_lb
    /**
        @class _ce94d1e4_a278_45b7_810b_cefc31748bb7
        @private

        @brief
        A [label label](@ref _e6b57146_2f9c_4636_a4f8_7b2022688e41) that identifies its [outer type](@ref _d863f410_28d6_4442_a353_f2851abc33f5) as a [tag](@ref _aa695b0f_e642_4521_928e_5deba76d9bc6).

        @snippet "./constant/src/constant_t.cpp" _a56cef09_b052_434e_9d00_99b1fb4a6baf
    */

    // nkr::constant_tg::type_lb
    /**
        @class _ecc4588e_6d37_42e1_a034_46d91bc1105b
        @private

        @brief
        A [label label](@ref _e6b57146_2f9c_4636_a4f8_7b2022688e41) that identifies its [outer type](@ref _d863f410_28d6_4442_a353_f2851abc33f5) as a [type](@ref _d5fa5645_f7f9_446a_936d_459b0e0e4982).

        @snippet "./constant/src/constant_t.cpp" _18f1d1f0_6477_425a_831a_7549d5b1335d
    */

    // nkr::constant_tg::identity_lb
    /**
        @class _c09f867d_57cb_452a_83a2_ee9b677b193c
        @private

        @brief
        A [label label](@ref _e6b57146_2f9c_4636_a4f8_7b2022688e41) that identifies its [outer type](@ref _d863f410_28d6_4442_a353_f2851abc33f5) as a member of an [identity](@ref _fd6e7324_a83c_4317_a5a8_9edfabfa7fce).

        @snippet "./constant/src/constant_t.cpp" _bee91228_cb6b_42f5_b11e_c6dc9c716b2f
    */

// nkr::constant_ttg
/**
    @class _96f44ebd_b97a_46fc_b2cc_8ed5ac09da45
    @private

    @brief
    The [identity template tag](@ref _af64f18b_d770_41fb_929e_7eb973ddfd03) for nkr::constant_t.

    @par
    @note
    nkr::constant_ttg is an [entity](@ref _beac6b26_2cf9_4051_99ba_4ae5a39e66ec) of the [nkr::constant_t Identity](@ref _144407f2_f15c_4e13_9507_168de44b2b1f).
*/

    // nkr::constant_ttg::tag_lb
    /**
        @class _f2b5c812_c49d_48ce_b4f0_a3747def4f5f
        @private

        @brief
        A [label label](@ref _e6b57146_2f9c_4636_a4f8_7b2022688e41) that identifies its [outer template](@ref _8d98abf9_d254_4d79_8a45_fd732c7c519b) and instantiated [outer type](@ref _d863f410_28d6_4442_a353_f2851abc33f5) as a [tag](@ref _aa695b0f_e642_4521_928e_5deba76d9bc6).

        @snippet "./constant/src/constant_t.cpp" _bba6e116_37df_4f5d_a98c_dda7aac7c45d
    */

    // nkr::constant_ttg::template_lb
    /**
        @class _4fe39de6_ce5d_4ecd_985f_d214044ce654
        @private

        @brief
        A [label label](@ref _e6b57146_2f9c_4636_a4f8_7b2022688e41) that identifies its [outer template](@ref _8d98abf9_d254_4d79_8a45_fd732c7c519b) and instantiated [outer type](@ref _d863f410_28d6_4442_a353_f2851abc33f5) as a [template of type](@ref _a13ace0b_d5fa_4445_87cc_c6beca57ff12).

        @snippet "./constant/src/constant_t.cpp" _65846497_ba0c_41be_9534_c2e46baf01d2
    */

    // nkr::constant_ttg::identity_lb
    /**
        @class _22613a5f_f098_47c3_bb33_fde978e6e70a
        @private

        @brief
        A [label label](@ref _e6b57146_2f9c_4636_a4f8_7b2022688e41) that identifies its [outer template](@ref _8d98abf9_d254_4d79_8a45_fd732c7c519b) and instantiated [outer type](@ref _d863f410_28d6_4442_a353_f2851abc33f5) as a member of an [identity](@ref _fd6e7324_a83c_4317_a5a8_9edfabfa7fce).

        @snippet "./constant/src/constant_t.cpp" _0c11ab3d_1046_4492_8bcf_cda94bbc48a9
    */
