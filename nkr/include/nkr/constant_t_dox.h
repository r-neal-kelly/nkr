/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

// nkr::constant_t
/**
    @class _09f6d63e_f4b7_46e1_b499_fcfa5132d76f
    @private

    @brief
    Represents an unchangable literal value in a compile-time or run-time context.

    @details
    nkr::constant_t is primarily used as a template type parameter in place of a template value parameter, for the sake of the @ref _ab449a60_e674_4d0a_91d9_557ec4c5660c "one kind of template parameter principle". However, there's nothing restricting its use in other contexts if it is desireable.

    @par
    @note
    This type is similar to the standard C++ [std::integral_constant](https://en.cppreference.com/w/cpp/types/integral_constant).
*/

    // nkr::constant_t::value_t
    /**
        @class _3930c6fb_a15c_42cd_a6db_b41d3318b998
        @private

        @brief
        The [primary inner type](@ref _8f6a1988_bbdb_46ba_8746_40c02acda41c) of nkr::constant_t.
    */

// nkr::constant_tg
/**
    @class _c8ccd7aa_610c_4f1b_ba49_de22374f3b78
    @private

    @brief
    The type tag for nkr::constant_t.
*/

// nkr::constant_ttg
/**
    @class _96f44ebd_b97a_46fc_b2cc_8ed5ac09da45
    @private

    @brief
    The template tag for nkr::constant_t.
*/

// nkr::constant_tr
/**
    @class _7011a9e2_12cb_4fb5_b2b0_83080a091ab4
    @private

    @brief
    The type identity trait for nkr::constant_t.
*/

// nkr::constant_ttr
/**
    @class _651a47d3_40f7_4a6f_be9c_5fbc92a159ec
    @private

    @brief
    The template identity trait for nkr::constant_t.
*/
