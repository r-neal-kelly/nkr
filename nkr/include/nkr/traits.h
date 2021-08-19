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
        std::is_integral<type_p>::value;    ///< @copydoc traits_integers_integer_tr

    template <typename type_p>
    concept integer_unsigned_tr =
        std::is_integral<type_p>::value &&
        std::is_unsigned<type_p>::value;    ///< @copydoc traits_integers_integer_unsigned_tr

    template <typename type_p>
    concept integer_signed_tr =
        std::is_integral<type_p>::value &&
        std::is_signed<type_p>::value;      ///< @copydoc traits_integers_integer_signed_tr

    template <typename type_p>
    concept integer_8_tr =
        std::is_integral<type_p>::value &&
        (sizeof(type_p) == sizeof(u8_t));   ///< @copydoc traits_integers_integer_8_tr

    template <typename type_p>
    concept integer_16_tr =
        std::is_integral<type_p>::value &&
        (sizeof(type_p) == sizeof(u16_t));  ///< @copydoc traits_integers_integer_16_tr

    template <typename type_p>
    concept integer_32_tr =
        std::is_integral<type_p>::value &&
        (sizeof(type_p) == sizeof(u32_t));  ///< @copydoc traits_integers_integer_32_tr

    template <typename type_p>
    concept integer_64_tr =
        std::is_integral<type_p>::value &&
        (sizeof(type_p) == sizeof(u64_t));  ///< @copydoc traits_integers_integer_64_tr

    template <typename type_p>
    concept integer_word_tr =
        std::is_integral<type_p>::value &&
        (sizeof(type_p) == sizeof(word_t)); ///< @copydoc traits_integers_integer_word_tr
    /// @}

    
    /// @addtogroup traits_casts
    /// @{
    template <typename type_p>
    concept cast_word_tr =
        std::convertible_to<type_p, word_t>;    ///< @copydoc traits_casts_cast_word_tr
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
    concept sized_tr =
        sizeof(type_p) > 0;                     ///< @copydoc traits_misc_sized_tr
    /// @}

}
