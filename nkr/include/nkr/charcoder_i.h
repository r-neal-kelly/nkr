/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/bool_t.h"
#include "nkr/intrinsics.h"

namespace nkr { namespace charcoder {

    using point_t   = word_t;

}}

namespace nkr {

    /*
        Assumptions:
            - strings (sequences) are made of a continguous series of units, which are grouped into substrings.
            - each unit is of the same integral size, e.g. u8_t, u16_t, u32_t, etc.
            - strings end with a null-terminated unit, i.e. the last unit must be 0.

            - substrings (subsequences) are an encoded subseries of units that can be decoded.
            - a charcoder either contains or operates upon one substring at a time.
            - a charcoder's contained units always have the same endianness as their encoding.
            - a charcoder must at all times be well-formed and thus valid.

            - points are decoded substrings.
            - points must fit within the word of the machine.
            - points always have the same endianness as that of the excecuting machine.
    */

    template <typename type_p>
    concept charcoder_i = requires (type_p charcoder,
                                    type_p const_charcoder,

                                    count_t read_count,
                                    const typename type_p::unit_t* from_unit,
                                    const typename type_p::unit_t* first_unit)
    {
        typename type_p::unit_t;

        { const_charcoder.Is_Well_Formed() }                -> std::same_as<bool_t>;

        { charcoder.Encode(typename charcoder::point_t()) } -> std::same_as<void_t>;
        { const_charcoder.Decode() }                        -> std::same_as<typename charcoder::point_t>;

        { charcoder.Read_Forward(from_unit) }               -> std::same_as<count_t>;
        { charcoder.Read_Reverse(from_unit, first_unit) }   -> std::same_as<count_t>;

        { const_charcoder.Unit_Count() }                    -> std::same_as<count_t>;
        { const_charcoder.operator[](index_t()) }           -> std::same_as<typename type_p::unit_t>;

        read_count = charcoder.Read_Forward(from_unit);
        read_count = charcoder.Read_Reverse(from_unit, first_unit);
    };

}
