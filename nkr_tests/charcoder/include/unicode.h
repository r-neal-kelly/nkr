/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/z_intrinsics.h"
#include "nkr/z_os.h"
#include "nkr/z_utils.h"

#include "nkr/z_array/dynamic_t.h"
#include "nkr/z_array/stack_t.h"

#include "nkr/z_charcoder_i.h"
#include "nkr/z_charcoder/ascii_t.h"
#include "nkr/z_charcoder/utf_8_t.h"
#include "nkr/z_charcoder/utf_16_t.h"
#include "nkr/z_charcoder/utf_32_t.h"

namespace nkr { namespace charcoder {

    template <typename charcoder_p>
    concept has_native_endianness_tr =
        is_any_tr<charcoder_p, utf_16_be_t> && os::endian::Is_Big() ||
        is_any_tr<charcoder_p, utf_16_le_t> && os::endian::Is_Little() ||
        is_any_tr<charcoder_p, utf_32_be_t> && os::endian::Is_Big() ||
        is_any_tr<charcoder_p, utf_32_le_t> && os::endian::Is_Little();

    template <typename charcoder_p>
    concept has_non_native_endianness_tr =
        is_any_tr<charcoder_p, utf_16_be_t> && os::endian::Is_Little() ||
        is_any_tr<charcoder_p, utf_16_le_t> && os::endian::Is_Big() ||
        is_any_tr<charcoder_p, utf_32_be_t> && os::endian::Is_Little() ||
        is_any_tr<charcoder_p, utf_32_le_t> && os::endian::Is_Big();

    inline point_t
        Random_Value()
    {
        return Random<point_t>();
    }

    inline point_t
        Random_Point()
    {
        return Random<point_t>(utf_32_t::POINT_FIRST, utf_32_t::POINT_LAST);
    }

    inline point_t
        Random_Non_Point()
    {
        return Random<point_t>(utf_32_t::POINT_LAST + 1);
    }

    inline point_t
        Random_BMP_Point()
    {
        return Random<point_t>(utf_32_t::BMP_FIRST, utf_32_t::BMP_LAST);
    }

    inline point_t
        Random_Non_BMP_Point()
    {
        return Random<point_t>(utf_32_t::BMP_LAST + 1, utf_32_t::POINT_LAST);
    }

    inline point_t
        Random_Scalar()
    {
        point_t random;
        do {
            random = Random_Point();
        } while (!utf_32_t::Is_Scalar(random));

        return random;
    }

    inline point_t
        Random_Non_Terminus_Scalar()
    {
        point_t random;
        do {
            random = Random_Scalar();
        } while (random == 0);

        return random;
    }

    inline point_t
        Random_Non_Replacement_Scalar()
    {
        point_t random;
        do {
            random = Random_Scalar();
        } while (random == utf_32_t::REPLACEMENT_CHARACTER);

        return random;
    }

    inline point_t
        Random_Non_Terminus_And_Non_Replacement_Scalar()
    {
        point_t random;
        do {
            random = Random_Scalar();
        } while (random == 0 ||
                 random == utf_32_t::REPLACEMENT_CHARACTER);

        return random;
    }

    inline point_t
        Random_BMP_Scalar()
    {
        point_t random;
        do {
            random = Random_BMP_Point();
        } while (!utf_32_t::Is_Scalar(random));

        return random;
    }

    inline point_t
        Random_Non_BMP_Scalar()
    {
        return Random_Non_BMP_Point();
    }

    inline point_t
        Random_Non_Terminus_BMP_Scalar()
    {
        point_t random;
        do {
            random = Random_BMP_Scalar();
        } while (random == 0);

        return random;
    }

    inline point_t
        Random_Non_Replacement_BMP_Scalar()
    {
        point_t random;
        do {
            random = Random_BMP_Scalar();
        } while (random == utf_32_t::REPLACEMENT_CHARACTER);

        return random;
    }

    inline point_t
        Random_Non_Terminus_And_Non_Replacement_BMP_Scalar()
    {
        point_t random;
        do {
            random = Random_BMP_Scalar();
        } while (random == 0 ||
                 random == utf_32_t::REPLACEMENT_CHARACTER);

        return random;
    }

    inline point_t
        Random_Surrogate()
    {
        return Random<point_t>(utf_32_t::SURROGATE_HIGH_FIRST, utf_32_t::SURROGATE_LOW_LAST);
    }

    inline point_t
        Random_High_Surrogate()
    {
        return Random<point_t>(utf_32_t::SURROGATE_HIGH_FIRST, utf_32_t::SURROGATE_HIGH_LAST);
    }

    inline point_t
        Random_Low_Surrogate()
    {
        return Random<point_t>(utf_32_t::SURROGATE_LOW_FIRST, utf_32_t::SURROGATE_LOW_LAST);
    }

    inline point_t
        Random_UTF_8_Bracket_1_Point()
    {
        return Random<point_t>(utf_32_t::UTF_8_BRACKET_1_FIRST, utf_32_t::UTF_8_BRACKET_1_LAST);
    }

    inline point_t
        Random_UTF_8_Bracket_2_Point()
    {
        return Random<point_t>(utf_32_t::UTF_8_BRACKET_2_FIRST, utf_32_t::UTF_8_BRACKET_2_LAST);
    }

    inline point_t
        Random_UTF_8_Bracket_3_Point()
    {
        return Random<point_t>(utf_32_t::UTF_8_BRACKET_3_FIRST, utf_32_t::UTF_8_BRACKET_3_LAST);
    }

    inline point_t
        Random_UTF_8_Bracket_4_Point()
    {
        return Random<point_t>(utf_32_t::UTF_8_BRACKET_4_FIRST, utf_32_t::UTF_8_BRACKET_4_LAST);
    }

    inline point_t
        Random_UTF_8_Bracket_1_Scalar()
    {
        point_t random;
        do {
            random = Random_UTF_8_Bracket_1_Point();
        } while (!utf_32_t::Is_Scalar(random));

        return random;
    }

    inline point_t
        Random_UTF_8_Bracket_2_Scalar()
    {
        point_t random;
        do {
            random = Random_UTF_8_Bracket_2_Point();
        } while (!utf_32_t::Is_Scalar(random));

        return random;
    }

    inline point_t
        Random_UTF_8_Bracket_3_Scalar()
    {
        point_t random;
        do {
            random = Random_UTF_8_Bracket_3_Point();
        } while (!utf_32_t::Is_Scalar(random));

        return random;
    }

    inline point_t
        Random_UTF_8_Bracket_4_Scalar()
    {
        point_t random;
        do {
            random = Random_UTF_8_Bracket_4_Point();
        } while (!utf_32_t::Is_Scalar(random));

        return random;
    }

}}
