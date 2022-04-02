/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_a3610953_2c56_4c2e_a876_1e2e36aceb93
#define nkr_INCLUDE_GUARD_a3610953_2c56_4c2e_a876_1e2e36aceb93

// nkr::constant_t Identity
/**
    @defgroup _144407f2_f15c_4e13_9507_168de44b2b1f nkr::constant_t Identity
    @ingroup _c8774f4a_9a1a_4339_9147_4d0ded6c301f

    @brief
    The [entity group](@ref _f2fd9706_47ef_4a9d_bb60_39f7055128ee) that forms the [identity](@ref _fd6e7324_a83c_4317_a5a8_9edfabfa7fce) of nkr::constant_t.
*/

// nkr::constant_t
/**
    @class _09f6d63e_f4b7_46e1_b499_fcfa5132d76f
    @private

    @brief
    Represents an immutable [literal value](@ref _aafc1022_913c_4a2a_8747_dacdbef8f762) in a [compile-time](@ref _b11fed50_b607_4f57_b5e7_af27886ddb6a) or [run-time](@ref _6486340c_e540_4c05_8d06_90e4cc18c1b3) context.

    @details
    nkr::constant_t is primarily used as a [template type parameter](@ref _4e8909a3_7865_4a80_ba3f_1eaef38fb24f) in place of a [template value parameter](@ref _a259e988_bc05_43c7_bcd8_ac5831d2153c), for the sake of the [one kind of template parameter design](@ref _ab449a60_e674_4d0a_91d9_557ec4c5660c). However, there's nothing restricting its use in other contexts where desirable.

    @note
    nkr::constant_t is the [primary entity](@ref _75c3be6c_da45_4652_bf67_513fde1b9a06) of the [nkr::constant_t Identity](@ref _144407f2_f15c_4e13_9507_168de44b2b1f).
    <br><br>
    This type is similar to [std::integral_constant](https://en.cppreference.com/w/cpp/types/integral_constant).
*/

    // nkr::constant_t::value_t
    /**
        @class _3930c6fb_a15c_42cd_a6db_b41d3318b998
        @private

        @brief
        The [primary inner type](@ref _8f6a1988_bbdb_46ba_8746_40c02acda41c) of nkr::constant_t.
    */

    // nkr::constant_t::Value
    /**
        @class _0e8b0f54_647f_4838_a696_bc19fd0ef14f
        @private

        @brief
        Returns the [primary inner value](@ref _efa732b7_12bb_4ff3_bdf7_d309717a1699) of an [instantiated](@ref _be26724f_df26_4658_8cab_109d0b853c27) nkr::constant_t.

        @details
        This is a [static function](@ref _320d56ae_eec3_4d75_8ef3_677f4dd31c82) and not a [method](@ref _c6831e56_fbb1_445d_b3fc_7b35c60286a5) because the most frequent use case for nkr::constant_t is to be passed as a [template argument](@ref _c1c0e928_ba39_4137_babb_17726e128d1c), therefore it should be easily accessible through an [instantiated type](@ref _be26724f_df26_4658_8cab_109d0b853c27) more so than as a [type instance](@ref _7c636ccf_7f4b_40c1_a955_2dca05506ac4).

        Because C++ does not allow for both a [static function](@ref _320d56ae_eec3_4d75_8ef3_677f4dd31c82) and a [method](@ref _c6831e56_fbb1_445d_b3fc_7b35c60286a5) to have the same [label](@ref _f2d4e658_c44a_4b89_b00b_35184f78db10), we can only define one or the other. However, according to the [primary inner value design](@ref _94c723c3_0213_4866_a383_50edc6ef02bd) the [primary inner value](@ref _efa732b7_12bb_4ff3_bdf7_d309717a1699) is also accessible through the @ref nkr::constant_t::operator ()() const and @ref nkr::constant_t::operator nkr::constant_t::value_t() const methods as well as their volatile [complements](@ref _015c3e2c_827b_46b1_bdd0_3a337bbd3f60).
    */

    // nkr::constant_t::operator nkr::constant_t::value_t const
    /**
        @class _92c0cf7e_3299_4b26_8925_51a2bb742f40
        @private

        @brief
        Casts to the [primary inner value](@ref _efa732b7_12bb_4ff3_bdf7_d309717a1699) of an [instanced](@ref _7c636ccf_7f4b_40c1_a955_2dca05506ac4) nkr::constant_t.

        @details
        This [caster](@ref _7cc08c80_b12d_4849_abac_d2e553b74267) returns the same [primary inner value](@ref _efa732b7_12bb_4ff3_bdf7_d309717a1699) as nkr::constant_t::Value.
    */

    // nkr::constant_t::operator nkr::constant_t::value_t const volatile
    /**
        @class _fb9e9b09_08ef_4200_8b62_650ee3288bf6
        @private

        @brief
        @copybrief _92c0cf7e_3299_4b26_8925_51a2bb742f40

        @details
        This is the const volatile [complement](@ref _015c3e2c_827b_46b1_bdd0_3a337bbd3f60) of @ref nkr::constant_t::operator nkr::constant_t::value_t() const.
    */

    // nkr::constant_t::operator () const
    /**
        @class _88bb3161_7ba1_4e16_9e75_db8a07e0adaa
        @private

        @brief
        Returns the [primary inner value](@ref _efa732b7_12bb_4ff3_bdf7_d309717a1699) of an [instanced](@ref _7c636ccf_7f4b_40c1_a955_2dca05506ac4) nkr::constant_t.

        @details
        This [operator](@ref _611647a3_9703_4f6c_bb5f_84132533dc23) returns the same [primary inner value](@ref _efa732b7_12bb_4ff3_bdf7_d309717a1699) as nkr::constant_t::Value.
    */

    // nkr::constant_t::operator () const volatile
    /**
        @class _c3f090d1_cfa0_4212_b596_01d86b9c4a07
        @private

        @brief
        @copybrief _88bb3161_7ba1_4e16_9e75_db8a07e0adaa

        @details
        This is the const volatile [complement](@ref _015c3e2c_827b_46b1_bdd0_3a337bbd3f60) of @ref nkr::constant_t::operator ()() const.
    */

// nkr::constant_tr
/**
    @class _7011a9e2_12cb_4fb5_b2b0_83080a091ab4
    @private

    @brief
    The [identity type trait](@ref _5579f9ac_41ef_49be_ba96_98a19cd04121) for nkr::constant_t.

    @details
    @note
    nkr::constant_tr is an [entity](@ref _beac6b26_2cf9_4051_99ba_4ae5a39e66ec) of the [nkr::constant_t Identity](@ref _144407f2_f15c_4e13_9507_168de44b2b1f).
*/

// nkr::constant_ttr
/**
    @class _651a47d3_40f7_4a6f_be9c_5fbc92a159ec
    @private

    @brief
    The [identity template trait](@ref _2d942eaa_04fe_4671_8aa0_3969a2bcf5b7) for nkr::constant_t.

    @details
    @note
    nkr::constant_ttr is an [entity](@ref _beac6b26_2cf9_4051_99ba_4ae5a39e66ec) of the [nkr::constant_t Identity](@ref _144407f2_f15c_4e13_9507_168de44b2b1f).
*/

// nkr::constant_of_tr
/**
    @class _fba50840_494c_4a81_8772_9c5315bc8cd2
    @private

    @brief
    The [identity inner type trait](@ref _c4966e47_6f21_49bc_b253_75a881583731) for nkr::constant_t.

    @details
    @note
    nkr::constant_of_tr is an [entity](@ref _beac6b26_2cf9_4051_99ba_4ae5a39e66ec) of the [nkr::constant_t Identity](@ref _144407f2_f15c_4e13_9507_168de44b2b1f).
*/

// nkr::constant_tg
/**
    @class _c8ccd7aa_610c_4f1b_ba49_de22374f3b78
    @private

    @brief
    The [identity type tag](@ref _e127f763_d3a9_4042_8c0b_654120967de3) for nkr::constant_t.

    @details
    @note
    nkr::constant_tg is an [entity](@ref _beac6b26_2cf9_4051_99ba_4ae5a39e66ec) of the [nkr::constant_t Identity](@ref _144407f2_f15c_4e13_9507_168de44b2b1f).

    ### Examples:
    @snippet "./constant/src/constant_t.cpp" _a75ee664_019d_4764_a2fc_947dc3d384e7
    @snippet "./constant/src/constant_t.cpp" _d7f5b641_e756_4d14_be2e_6511ef9f0110
*/

    // nkr::constant_tg::tag_lb
    /**
        @class _ce94d1e4_a278_45b7_810b_cefc31748bb7
        @private

        @brief
        A [label label](@ref _e6b57146_2f9c_4636_a4f8_7b2022688e41) that identifies its [outer type](@ref _d863f410_28d6_4442_a353_f2851abc33f5) as a [tag](@ref _aa695b0f_e642_4521_928e_5deba76d9bc6).

        ### Examples:
        @snippet "./constant/src/constant_t.cpp" _a56cef09_b052_434e_9d00_99b1fb4a6baf
    */

    // nkr::constant_tg::type_lb
    /**
        @class _ecc4588e_6d37_42e1_a034_46d91bc1105b
        @private

        @brief
        A [label label](@ref _e6b57146_2f9c_4636_a4f8_7b2022688e41) that identifies its [outer type](@ref _d863f410_28d6_4442_a353_f2851abc33f5) as a [type](@ref _d5fa5645_f7f9_446a_936d_459b0e0e4982).

        ### Examples:
        @snippet "./constant/src/constant_t.cpp" _18f1d1f0_6477_425a_831a_7549d5b1335d
    */

    // nkr::constant_tg::identity_lb
    /**
        @class _c09f867d_57cb_452a_83a2_ee9b677b193c
        @private

        @brief
        A [label label](@ref _e6b57146_2f9c_4636_a4f8_7b2022688e41) that identifies its [outer type](@ref _d863f410_28d6_4442_a353_f2851abc33f5) as a member of an [identity](@ref _fd6e7324_a83c_4317_a5a8_9edfabfa7fce).

        ### Examples:
        @snippet "./constant/src/constant_t.cpp" _bee91228_cb6b_42f5_b11e_c6dc9c716b2f
    */

// nkr::constant_ttg
/**
    @class _96f44ebd_b97a_46fc_b2cc_8ed5ac09da45
    @private

    @brief
    The [identity template tag](@ref _af64f18b_d770_41fb_929e_7eb973ddfd03) for nkr::constant_t.

    @details
    @note
    nkr::constant_ttg is an [entity](@ref _beac6b26_2cf9_4051_99ba_4ae5a39e66ec) of the [nkr::constant_t Identity](@ref _144407f2_f15c_4e13_9507_168de44b2b1f).

    ### Examples:
    @snippet "./constant/src/constant_t.cpp" _1f16a7a9_ef47_4a1c_8755_3b0d4f953087
    @snippet "./constant/src/constant_t.cpp" _61c47f9b_a744_4135_96a8_74caa38a4b63
*/

    // nkr::constant_ttg::tag_lb
    /**
        @class _f2b5c812_c49d_48ce_b4f0_a3747def4f5f
        @private

        @brief
        A [label label](@ref _e6b57146_2f9c_4636_a4f8_7b2022688e41) that identifies its [outer template](@ref _8d98abf9_d254_4d79_8a45_fd732c7c519b) and instantiated [outer type](@ref _d863f410_28d6_4442_a353_f2851abc33f5) as a [tag](@ref _aa695b0f_e642_4521_928e_5deba76d9bc6).

        ### Examples:
        @snippet "./constant/src/constant_t.cpp" _0ea2e923_3526_4842_8d0a_df32fe816a10
        @snippet "./constant/src/constant_t.cpp" _bba6e116_37df_4f5d_a98c_dda7aac7c45d
    */

    // nkr::constant_ttg::template_lb
    /**
        @class _4fe39de6_ce5d_4ecd_985f_d214044ce654
        @private

        @brief
        A [label label](@ref _e6b57146_2f9c_4636_a4f8_7b2022688e41) that identifies its [outer template](@ref _8d98abf9_d254_4d79_8a45_fd732c7c519b) and instantiated [outer type](@ref _d863f410_28d6_4442_a353_f2851abc33f5) as a [template of type](@ref _a13ace0b_d5fa_4445_87cc_c6beca57ff12).

        ### Examples:
        @snippet "./constant/src/constant_t.cpp" _29beed5a_a3f3_4b23_aedd_38e86ec36819
        @snippet "./constant/src/constant_t.cpp" _65846497_ba0c_41be_9534_c2e46baf01d2
    */

    // nkr::constant_ttg::identity_lb
    /**
        @class _22613a5f_f098_47c3_bb33_fde978e6e70a
        @private

        @brief
        A [label label](@ref _e6b57146_2f9c_4636_a4f8_7b2022688e41) that identifies its [outer template](@ref _8d98abf9_d254_4d79_8a45_fd732c7c519b) and instantiated [outer type](@ref _d863f410_28d6_4442_a353_f2851abc33f5) as a member of an [identity](@ref _fd6e7324_a83c_4317_a5a8_9edfabfa7fce).

        ### Examples:
        @snippet "./constant/src/constant_t.cpp" _2050293a_1fb1_4f94_bfc4_23ef2b32f123
        @snippet "./constant/src/constant_t.cpp" _0c11ab3d_1046_4492_8bcf_cda94bbc48a9
    */

// nkr::constant_t$
/**
    @class _b8badf6a_299c_4743_a288_9ba6f3291672
    @private

    @brief
    The [private namespace](@ref _31e7e083_2557_4598_b990_1b76deabd5fc) of nkr::constant_t.
*/

    // nkr::constant_t$::type_i_type_sp
    /**
        @class _c15eb0da_f76f_4d1d_be3d_2b422553f090
        @private

        @brief
        The [interface implementation](@ref _e930ffa6_a82e_461e_9bd9_427f2d51d568) of nkr::interface::type_i for [type instantiations](@ref _be26724f_df26_4658_8cab_109d0b853c27) of nkr::constant_t.
    */

        // nkr::constant_t$::type_i_type_sp::type_t
        /**
            @class _fac7a231_ac0a_438e_87e3_e3e442ccca46
            @private

            @brief
            The [qualified](@ref _db33c623_ed4b_4daf_809a_2e105d0d76dd) [instantiation](@ref _be26724f_df26_4658_8cab_109d0b853c27) of nkr::constant_t that is the subject of this [implementation](@ref _e930ffa6_a82e_461e_9bd9_427f2d51d568) of nkr::interface::type_i.
        */

        // nkr::constant_t$::type_i_type_sp::of_t
        /**
            @class _e41a23cd_be1c_454b_ae8a_e3cbf986c095
            @private

            @brief
            The [primary inner type](@ref _4e605182_03fd_45fe_ad99_66ef95f8af15) of nkr::constant_t$::type_i_type_sp::type_t.
        */

        // nkr::constant_t$::type_i_type_sp::Is_Any_General
        /**
            @class _421197dc_59cd_48ab_a5ce_68c5c425d35b
            @private

            @brief
            Checks if the passed in [type](@ref _d5fa5645_f7f9_446a_936d_459b0e0e4982) is any [qualification](@ref _db33c623_ed4b_4daf_809a_2e105d0d76dd) of any [instantiation](@ref _be26724f_df26_4658_8cab_109d0b853c27) of nkr::constant_t regardless of its [template arguments](@ref _c1c0e928_ba39_4137_babb_17726e128d1c).

            @details
            Fulfills the generic need to determine if two potentially different [types](@ref _d5fa5645_f7f9_446a_936d_459b0e0e4982) come from the same [template](@ref _a13ace0b_d5fa_4445_87cc_c6beca57ff12). Because nkr::constant_t$::type_i_type_sp::type_t is passed in to [instantiate](@ref _be26724f_df26_4658_8cab_109d0b853c27) this [interface implementation](@ref _e930ffa6_a82e_461e_9bd9_427f2d51d568), this essentially acts as an equality operator for [templates](@ref _a13ace0b_d5fa_4445_87cc_c6beca57ff12) with [types](@ref _d5fa5645_f7f9_446a_936d_459b0e0e4982) as operands.
        */

        // nkr::constant_t$::type_i_type_sp::Is_Any_Specific
        /**
            @class _0097b52c_af79_4c0c_bf25_8276d5c12c9b
            @private

            @brief
            Checks if the passed in [type](@ref _d5fa5645_f7f9_446a_936d_459b0e0e4982) is any [qualification](@ref _db33c623_ed4b_4daf_809a_2e105d0d76dd) of nkr::constant_t$::type_i_type_sp::type_t.
        */

    // nkr::constant_t$::type_i_tag_sp
    /**
        @class _fb5c885f_76ed_4ca7_bbcc_b926514253f9
        @private

        @brief
        The [interface implementation](@ref _e930ffa6_a82e_461e_9bd9_427f2d51d568) of nkr::interface::type_i for nkr::constant_tg.
    */

        // nkr::constant_t$::type_i_tag_sp::type_t
        /**
            @class _df6ca327_f69b_47c6_8a1f_34d42baf44ea
            @private

            @brief
            The [qualified](@ref _db33c623_ed4b_4daf_809a_2e105d0d76dd) nkr::constant_tg that is the subject of this [implementation](@ref _e930ffa6_a82e_461e_9bd9_427f2d51d568) of nkr::interface::type_i.
        */

        // nkr::constant_t$::type_i_tag_sp::of_t
        /**
            @class _adec56d0_18cf_477f_8211_75e297395bc7
            @private

            @brief
            The [primary inner type](@ref _4e605182_03fd_45fe_ad99_66ef95f8af15) of nkr::constant_t$::type_i_tag_sp::type_t.

            @details
            The subject of this [interface implementation](@ref _e930ffa6_a82e_461e_9bd9_427f2d51d568) is nkr::constant_tg and so it has no [primary inner type](@ref _4e605182_03fd_45fe_ad99_66ef95f8af15). One would need to use the interface for an actual [instantiation](@ref _be26724f_df26_4658_8cab_109d0b853c27) of nkr::constant_t to get a [primary inner type](@ref _4e605182_03fd_45fe_ad99_66ef95f8af15).
        */

        // nkr::constant_t$::type_i_tag_sp::Is_Any_General
        /**
            @class _f6286d5e_a240_463d_a47e_96b6cd5a8c54
            @private

            @brief
            Checks if the passed in [type](@ref _d5fa5645_f7f9_446a_936d_459b0e0e4982) is any [qualification](@ref _db33c623_ed4b_4daf_809a_2e105d0d76dd) of any [instantiation](@ref _be26724f_df26_4658_8cab_109d0b853c27) of nkr::constant_t regardless of its [template arguments](@ref _c1c0e928_ba39_4137_babb_17726e128d1c).

            @details
            Fulfills the generic need to determine if a [type](@ref _d5fa5645_f7f9_446a_936d_459b0e0e4982) comes from the same [template](@ref _a13ace0b_d5fa_4445_87cc_c6beca57ff12) represented by a [tag](@ref _aa695b0f_e642_4521_928e_5deba76d9bc6). Because nkr::constant_t$::type_i_tag_sp::type_t is a [tag](@ref _aa695b0f_e642_4521_928e_5deba76d9bc6) and is passed in to [instantiate](@ref _be26724f_df26_4658_8cab_109d0b853c27) this [interface implementation](@ref _e930ffa6_a82e_461e_9bd9_427f2d51d568), this essentially acts as an equality operator for [templates](@ref _a13ace0b_d5fa_4445_87cc_c6beca57ff12) with a [type](@ref _d5fa5645_f7f9_446a_936d_459b0e0e4982) and [tag](@ref _aa695b0f_e642_4521_928e_5deba76d9bc6) as operands.
        */

        // nkr::constant_t$::type_i_tag_sp::Is_Any_Specific
        /**
            @class _a16deaf5_8c03_4f30_83b0_c8aa636832b6
            @private

            @brief
            Checks if the passed in [type](@ref _d5fa5645_f7f9_446a_936d_459b0e0e4982) is any [qualification](@ref _db33c623_ed4b_4daf_809a_2e105d0d76dd) of nkr::constant_t$::type_i_tag_sp::type_t.
        */

    // nkr::constant_t$::template_i_tag_sp
    /**
        @class _925b6ca6_622f_44d1_9c35_30b158addbc7
        @private

        @brief
        The [interface implementation](@ref _e930ffa6_a82e_461e_9bd9_427f2d51d568) of nkr::interface::template_i for nkr::constant_ttg.
    */

#endif
