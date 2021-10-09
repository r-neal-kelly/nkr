/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/bool_t.h"
#include "nkr/intrinsics.h"
#include "nkr/none_i.h"

namespace nkr { namespace charcoder {

    using point_t   = word_t;

}}

namespace nkr { namespace $charcoder_i {

    /*
        Assumptions:
            - strings (sequences) are made of a continguous series of units, which are grouped into substrings.
            - each unit is of the same integral size, e.g. u8_t, u16_t, u32_t, etc.
            - strings end with a null-terminated unit (the terminus), i.e. the last unit must be 0.

            - substrings (subsequences) are an encoded subseries of units that can be decoded.
            - a charcoder either contains or operates upon one substring at a time.
            - a charcoder's contained units always have the same endianness as their encoding.
            - a charcoder must at all times be well-formed and thus valid.

            - points are decoded substrings.
            - points must fit within the word of the machine.
            - points always have the same endianness as that of the excecuting machine.
    */

    // the charcoder implementations should probably be able to accept const unit_ts, however it is not expected that
    // the implementation will use const in its footprint. but this is helfpul for string_t which utilizes the unit_t
    // on charcoder, and the array the string uses needs to know the actual type to be stored qualified or not.

    template <typename type_p>
    concept unit_i =
        any_integer_tr<typename type_p::unit_t> ||
        any_character_tr<typename type_p::unit_t>;

    template <typename type_p>
    concept methods_i = requires (std::remove_cv_t<type_p> charcoder,
                                  const std::remove_cv_t<type_p> const_charcoder,
                                  volatile std::remove_cv_t<type_p> volatile_charcoder,
                                  const volatile std::remove_cv_t<type_p> const_volatile_charcoder,

                                  count_t read_count,
                                  const typename type_p::unit_t* from_unit,
                                  const typename type_p::unit_t* first_unit)
    {
        { std::remove_cv_t<type_p>::Has_1_To_1_Unit_To_Point_Ratio() }  -> is_tr<std_bool_t>; // constexpr

        { charcoder.Encode(typename charcoder::point_t()) }             -> is_tr<void_t>;
        { volatile_charcoder.Encode(typename charcoder::point_t()) }    -> is_tr<void_t>;
        { charcoder.Decode() }                                          -> is_tr<typename charcoder::point_t>;
        { const_charcoder.Decode() }                                    -> is_tr<typename charcoder::point_t>;
        { volatile_charcoder.Decode() }                                 -> is_tr<typename charcoder::point_t>;
        { const_volatile_charcoder.Decode() }                           -> is_tr<typename charcoder::point_t>;

        { charcoder.Read_Forward(from_unit) }                           -> is_tr<count_t>;
        { volatile_charcoder.Read_Forward(from_unit) }                  -> is_tr<count_t>;
        { charcoder.Read_Reverse(from_unit, first_unit) }               -> is_tr<count_t>;
        { volatile_charcoder.Read_Reverse(from_unit, first_unit) }      -> is_tr<count_t>;

        { charcoder.Unit_Count() }                                      -> is_tr<count_t>;
        { const_charcoder.Unit_Count() }                                -> is_tr<count_t>;
        { volatile_charcoder.Unit_Count() }                             -> is_tr<count_t>;
        { const_volatile_charcoder.Unit_Count() }                       -> is_tr<count_t>;

        { charcoder.operator[](index_t()) }                             -> is_tr<typename type_p::unit_t>;
        { const_charcoder.operator[](index_t()) }                       -> is_tr<typename type_p::unit_t>;
        { volatile_charcoder.operator[](index_t()) }                    -> is_tr<typename type_p::unit_t>;
        { const_volatile_charcoder.operator[](index_t()) }              -> is_tr<typename type_p::unit_t>;

        read_count = charcoder.Read_Forward(from_unit);
        read_count = charcoder.Read_Reverse(from_unit, first_unit);
    };

}}

namespace nkr {

    template <typename type_p>
    concept charcoder_i =
        $charcoder_i::unit_i<type_p> &&
        $charcoder_i::methods_i<type_p> &&
        none_i<type_p>;

}
