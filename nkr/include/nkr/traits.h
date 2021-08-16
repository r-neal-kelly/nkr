/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsic.h"

namespace nkr {

    /**
    * @defgroup traits traits
    * 
    * @brief
    *   C++20 concepts that are used to filter types in templates.
    * 
    * @details
    *   The term "trait" is not used in any standard C++ capacity, but specifically for use with this library. All trait names are followed by the "_tr" postfix to indicate that they are C++20 concepts used in place of 'typename' in template declarations.
    * 
    * @todo
    *   Add an example or several.
    */

    /**
    * @defgroup traits_integral integral
    * @ingroup traits
    * 
    * @brief
    *   Filter types that can be treated as integers.
    */
    /** @{ **/
    template <typename type_p>
    concept integral_tr =
        std::is_integral<type_p>::value;

    /// Allows nkr::bool_t.
    template <typename type_p>
    concept integral_unsigned_tr =
        std::is_integral<type_p>::value &&
        std::is_unsigned<type_p>::value;

    /// Does not allow nkr::bool_t.
    template <typename type_p>
    concept integral_signed_tr =
        std::is_integral<type_p>::value &&
        std::is_signed<type_p>::value;

    /// Allows nkr::bool_t.
    template <typename type_p>
    concept integral_8_tr =
        std::is_integral<type_p>::value &&
        (sizeof(type_p) == sizeof(u8_t));

    template <typename type_p>
    concept integral_16_tr =
        std::is_integral<type_p>::value &&
        (sizeof(type_p) == sizeof(u16_t));

    template <typename type_p>
    concept integral_32_tr =
        std::is_integral<type_p>::value &&
        (sizeof(type_p) == sizeof(u32_t));

    template <typename type_p>
    concept integral_64_tr =
        std::is_integral<type_p>::value &&
        (sizeof(type_p) == sizeof(u64_t));

    /// Only allows integers that are the same size as nkr::word_t.
    template <typename type_p>
    concept integral_word_tr =
        std::is_integral<type_p>::value &&
        (sizeof(type_p) == sizeof(word_t));
    /** @} **/

    /**
    * @defgroup traits_casts casts
    * @ingroup traits
    *
    * @brief
    *   Filter types that can cast to other types.
    */
    /** @{ **/
    template <typename type_p>
    concept cast_i8_ref_tr =
        std::convertible_to<type_p, u8_t&> ||
        std::convertible_to<type_p, s8_t&>;

    template <typename type_p>
    concept cast_i16_ref_tr =
        std::convertible_to<type_p, u16_t&> ||
        std::convertible_to<type_p, s16_t&>;

    template <typename type_p>
    concept cast_i32_ref_tr =
        std::convertible_to<type_p, u32_t&> ||
        std::convertible_to<type_p, s32_t&>;

    template <typename type_p>
    concept cast_i64_ref_tr =
        std::convertible_to<type_p, u64_t&> ||
        std::convertible_to<type_p, s64_t&>;
    /** @} **/

    /**
    * @defgroup traits_operators operators
    * @ingroup traits
    * 
    * @brief
    *   Filter types that can use particular operators.
    */
    /** @{ **/
    template <typename type_p>
    concept operator_add_tr =
        requires(type_p instance) { instance + 1; };

    template <typename type_p>
    concept operator_subtract_tr =
        requires(type_p instance) { instance - 1; };
    /** @} **/

    /**
    * @defgroup traits_misc misc
    * @ingroup traits
    * 
    * @brief
    *   Filter types by various predicates.
    */
    /** @{ **/
    /// In addition to regular pointers, this also allows nullptr.
    template <typename type_p>
    concept pointer_tr =
        std::is_null_pointer<type_p>::value ||
        std::is_pointer<type_p>::value;

    /// Does not allow types like nkr::void_t, which have no size.
    template <typename type_p>
    concept sized_tr =
        sizeof(type_p) > 0;
    /** @} **/

}
