/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsics.h"

namespace nkr {

    /// @addtogroup traits_integers
    /// @{
    template <typename type_p>
    concept integer_tr =
        std::is_integral<type_p>::value &&
        !std::same_as<type_p, bool_t>;      ///< @copydoc traits_integers_integer_tr

    template <typename type_p>
    concept integer_unsigned_tr =
        integer_tr<type_p> &&
        std::is_unsigned<type_p>::value;    ///< @copydoc traits_integers_integer_unsigned_tr

    template <typename type_p>
    concept integer_signed_tr =
        integer_tr<type_p> &&
        std::is_signed<type_p>::value;      ///< @copydoc traits_integers_integer_signed_tr

    template <typename type_p>
    concept integer_8_tr =
        integer_tr<type_p> &&
        (sizeof(type_p) == sizeof(u8_t));   ///< @copydoc traits_integers_integer_8_tr

    template <typename type_p>
    concept integer_16_tr =
        integer_tr<type_p> &&
        (sizeof(type_p) == sizeof(u16_t));  ///< @copydoc traits_integers_integer_16_tr

    template <typename type_p>
    concept integer_32_tr =
        integer_tr<type_p> &&
        (sizeof(type_p) == sizeof(u32_t));  ///< @copydoc traits_integers_integer_32_tr

    template <typename type_p>
    concept integer_64_tr =
        integer_tr<type_p> &&
        (sizeof(type_p) == sizeof(u64_t));  ///< @copydoc traits_integers_integer_64_tr

    template <typename type_p>
    concept integer_word_tr =
        integer_tr<type_p> &&
        (sizeof(type_p) == sizeof(word_t)); ///< @copydoc traits_integers_integer_word_tr
    /// @}

    
    /// @addtogroup traits_casts
    /// @{
    template <typename type_p>
    concept cast_word_t_tr =
        std::convertible_to<type_p, word_t>;    ///< @copydoc traits_casts_cast_word_tr
    
    template <typename type_p>
    concept cast_bool_t_tr =
        std::convertible_to<type_p, bool_t>;    ///< @copydoc _64560adf_d76d_47dd_875a_1a345cf9189e
    /// @}

    
    /// @addtogroup traits_operators
    /// @{
    template <typename type_p>
    concept operator_add_tr =
        requires(type_p instance) { instance + 1; };    ///< @copydoc traits_operators_operator_add_tr

    template <typename type_p>
    concept operator_subtract_tr =
        requires(type_p instance) { instance - 1; };    ///< @copydoc traits_operators_operator_subtract_tr
    /// @}


    /// @addtogroup traits_misc
    /// @{
    template <typename type_p>
    concept pointer_tr =
        std::is_null_pointer<type_p>::value ||
        std::is_pointer<type_p>::value;         ///< @copydoc traits_misc_pointer_tr

    template <typename type_p>
    concept boolean_tr =
        std::same_as<type_p, bool_t>;           ///< @copydoc _3e4ef7df_7326_49f0_83e0_378911e03952

    template <typename type_p>
    concept floating_point_tr =
        std::is_floating_point<type_p>::value;  ///< @copydoc _7436208f_39ce_49f4_accb_a3bee797b12a

    template <typename type_p>
    concept sized_tr =
        sizeof(type_p) > 0;                     ///< @copydoc traits_misc_sized_tr

    template <typename type_p>
    concept built_in_tr =
        boolean_tr<type_p> ||
        integer_tr<type_p> ||
        floating_point_tr<type_p> ||
        pointer_tr<type_p>;                     ///< @copydoc _13b4b6b8_807a_4ed1_beae_dfd94e04e0f0
    /// @}

}
