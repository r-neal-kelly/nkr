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
        Requirements:
            - strings (sequences) are made of a continguous series of units, which are divided into substrings (subsequences).
            - each unit in a string is of the same integral size, e.g. u8_t, u16_t, u32_t, etc.
            - strings must terminate with a 0 (the terminus), i.e. the last unit must be 0.
            - the terminus must take up the space of a single unit, no more and no less.

            - substrings (subsequences) are an encoded series of units that can be decoded into a point, and vice-versa.
            - each substring may be of varying width or each substring may be of the same width.
            - a charcoder contains and operates only one substring at a time.
            - a charcoder's contained units must always have the same endianness as their encoding.
            - a charcoder must at all times be well-formed and thus valid. it should not cache any errorneous units.
            - a charcoder should replace errorneous units with a substring that decodes into a singular replacement point, defined per encoding.
            - during the reading process, the charcoder must return the actual number of units read, whether they are errorneous or not.

            - points are decoded substrings and are completely distinct from every other point defined by the encoding.
            - points must fit within the word of the machine.
            - points always have the same endianness as that of the excecuting machine.
            - a charcoder's encoding scheme may decode into points of its own definition. but most charcoders use Unicode for points.
            - although not a hard rule, the best practice is to decode into the Unicode point if you wish it to be translated into other encodings.
            - a static array can be used to efficiently translate a different point into a Unicode point if desired.
    */

    template <typename type_p>
    concept unit_i =
        any_integer_tr<typename type_p::unit_t> ||
        any_character_tr<typename type_p::unit_t>;

    template <typename type_p>
    concept static_constexpr_functions_i = requires()
    {
        { std::remove_cv_t<type_p>::Last_Point() }          -> is_tr<charcoder::point_t>;
        { std::remove_cv_t<type_p>::Replacement_Point() }   -> is_tr<charcoder::point_t>;

        { std::remove_cv_t<type_p>::Max_Unit_Count() }      -> is_tr<count_t>;
    };

    template <typename type_p>
    concept objects_i = requires()
    {
        { std::remove_cv_t<type_p>(charcoder::point_t()) } -> is_tr<std::remove_cv_t<type_p>>;
    };

    template <typename type_p>
    concept methods_i = requires (std::remove_cv_t<type_p> charcoder,
                                  const std::remove_cv_t<type_p> const_charcoder,
                                  volatile std::remove_cv_t<type_p> volatile_charcoder,
                                  const volatile std::remove_cv_t<type_p> const_volatile_charcoder,

                                  typename type_p::unit_t* from_unit,
                                  const typename type_p::unit_t* const_from_unit,
                                  volatile typename type_p::unit_t* volatile_from_unit,
                                  const volatile typename type_p::unit_t* const_volatile_from_unit,

                                  typename type_p::unit_t* first_unit,
                                  const typename type_p::unit_t* const_first_unit,
                                  volatile typename type_p::unit_t* volatile_first_unit,
                                  const volatile typename type_p::unit_t* const_volatile_first_unit,
                                  
                                  index_t unit_index,

                                  count_t read_count)
    {
        { charcoder.Encode(typename charcoder::point_t()) }                                         -> is_tr<void_t>;
        { volatile_charcoder.Encode(typename charcoder::point_t()) }                                -> is_tr<void_t>;
        { charcoder.Decode() }                                                                      -> is_tr<typename charcoder::point_t>;
        { const_charcoder.Decode() }                                                                -> is_tr<typename charcoder::point_t>;
        { volatile_charcoder.Decode() }                                                             -> is_tr<typename charcoder::point_t>;
        { const_volatile_charcoder.Decode() }                                                       -> is_tr<typename charcoder::point_t>;

        { charcoder.Read_Forward(from_unit) }                                                       -> is_tr<count_t>;
        { charcoder.Read_Forward(const_from_unit) }                                                 -> is_tr<count_t>;
        { charcoder.Read_Forward(volatile_from_unit) }                                              -> is_tr<count_t>;
        { charcoder.Read_Forward(const_volatile_from_unit) }                                        -> is_tr<count_t>;
        { volatile_charcoder.Read_Forward(from_unit) }                                              -> is_tr<count_t>;
        { volatile_charcoder.Read_Forward(const_from_unit) }                                        -> is_tr<count_t>;
        { volatile_charcoder.Read_Forward(volatile_from_unit) }                                     -> is_tr<count_t>;
        { volatile_charcoder.Read_Forward(const_volatile_from_unit) }                               -> is_tr<count_t>;
        { charcoder.Read_Reverse(from_unit, first_unit) }                                           -> is_tr<count_t>;
        { charcoder.Read_Reverse(const_from_unit, const_first_unit) }                               -> is_tr<count_t>;
        { charcoder.Read_Reverse(volatile_from_unit, volatile_first_unit) }                         -> is_tr<count_t>;
        { charcoder.Read_Reverse(const_volatile_from_unit, const_volatile_first_unit) }             -> is_tr<count_t>;
        { volatile_charcoder.Read_Reverse(from_unit, first_unit) }                                  -> is_tr<count_t>;
        { volatile_charcoder.Read_Reverse(const_from_unit, const_first_unit) }                      -> is_tr<count_t>;
        { volatile_charcoder.Read_Reverse(volatile_from_unit, volatile_first_unit) }                -> is_tr<count_t>;
        { volatile_charcoder.Read_Reverse(const_volatile_from_unit, const_volatile_first_unit) }    -> is_tr<count_t>;

        { charcoder.Unit_Count() }                                                                  -> is_tr<count_t>;
        { const_charcoder.Unit_Count() }                                                            -> is_tr<count_t>;
        { volatile_charcoder.Unit_Count() }                                                         -> is_tr<count_t>;
        { const_volatile_charcoder.Unit_Count() }                                                   -> is_tr<count_t>;
        { charcoder.Unit(unit_index) }                                                              -> is_tr<typename type_p::unit_t>;
        { const_charcoder.Unit(unit_index) }                                                        -> is_tr<typename type_p::unit_t>;
        { volatile_charcoder.Unit(unit_index) }                                                     -> is_tr<typename type_p::unit_t>;
        { const_volatile_charcoder.Unit(unit_index) }                                               -> is_tr<typename type_p::unit_t>;

        { charcoder.operator[](unit_index) }                                                        -> is_tr<typename type_p::unit_t>;
        { const_charcoder.operator[](unit_index) }                                                  -> is_tr<typename type_p::unit_t>;
        { volatile_charcoder.operator[](unit_index) }                                               -> is_tr<typename type_p::unit_t>;
        { const_volatile_charcoder.operator[](unit_index) }                                         -> is_tr<typename type_p::unit_t>;

        read_count = charcoder.Read_Forward(from_unit);
        read_count = charcoder.Read_Reverse(from_unit, first_unit);
    };

}}

namespace nkr {

    template <typename type_p>
    concept charcoder_i =
        $charcoder_i::unit_i<type_p> &&
        $charcoder_i::static_constexpr_functions_i<type_p> &&
        $charcoder_i::objects_i<type_p> &&
        $charcoder_i::methods_i<type_p> &&
        none_i<type_p>;

}
