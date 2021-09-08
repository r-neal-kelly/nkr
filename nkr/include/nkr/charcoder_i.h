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
            - the decoded subsequence, or "point" can fit within a word_t.
            - the encoded string ends with a null-terminated unit, i.e., the last unit must be 0.
    */

    template <typename type_p>
    concept charcoder_i = requires (type_p charcoder,
                                    type_p const_charcoder,

                                    bool_t is_well_formed,

                                    count_t read_count,
                                    const typename type_p::unit_t* from_unit,
                                    const typename type_p::unit_t* first_unit,

                                    charcoder::point_t point,

                                    count_t unit_count,
                                    index_t unit_index,
                                    typename type_p::unit_t unit)
    {
        typename type_p::unit_t;

        is_well_formed = const_charcoder.Is_Well_Formed();

        read_count = charcoder.Read_Forward(from_unit);
        read_count = charcoder.Read_Reverse(from_unit, first_unit);

        charcoder.Encode(point);
        point = const_charcoder.Decode();

        unit_count = const_charcoder.Unit_Count();
        unit = const_charcoder.operator[](unit_index);
    };

}
