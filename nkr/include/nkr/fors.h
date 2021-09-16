/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsics.h"
#include "nkr/traits.h"

namespace nkr {

    template <typename type_p>
    class word_for_type
    {
    };

    template <typename type_p>
    requires boolean_tr<type_p> && size_le_tr<type_p, word_t>
        class word_for_type<type_p>
    {
    public:
        using type_t    = unsigned_word_t;
    };

    template <typename type_p>
    requires integer_unsigned_tr<type_p>&& size_le_tr<type_p, word_t>
        class word_for_type<type_p>
    {
    public:
        using type_t    = unsigned_word_t;
    };

    template <typename type_p>
    requires integer_signed_tr<type_p>&& size_le_tr<type_p, word_t>
        class word_for_type<type_p>
    {
    public:
        using type_t    = signed_word_t;
    };

    template <typename type_p>
    requires real_tr<type_p>&& size_le_tr<type_p, word_t>
        class word_for_type<type_p>
    {
    public:
        using type_t    = signed_word_t;
    };

    template <typename type_p>
    using word_for_t    = word_for_type<type_p>::type_t;

    template <typename type_p>
    class integer_unsigned_for_type
    {
    };

    template <typename type_p>
    requires size_eq_tr<type_p, u8_t>
        class integer_unsigned_for_type<type_p>
    {
    public:
        using type_t    = u8_t;
    };

    template <typename type_p>
    requires size_eq_tr<type_p, u16_t>
        class integer_unsigned_for_type<type_p>
    {
    public:
        using type_t    = u16_t;
    };

    template <typename type_p>
    requires size_eq_tr<type_p, u32_t>
        class integer_unsigned_for_type<type_p>
    {
    public:
        using type_t    = u32_t;
    };

    template <typename type_p>
    requires size_eq_tr<type_p, u64_t>
        class integer_unsigned_for_type<type_p>
    {
    public:
        using type_t    = u64_t;
    };

    template <typename type_p>
    using integer_unsigned_for_t    = integer_unsigned_for_type<type_p>::type_t;

    template <typename type_p>
    class integer_signed_for_type
    {
    };

    template <typename type_p>
    requires size_eq_tr<type_p, s8_t>
        class integer_signed_for_type<type_p>
    {
    public:
        using type_t    = s8_t;
    };

    template <typename type_p>
    requires size_eq_tr<type_p, s16_t>
        class integer_signed_for_type<type_p>
    {
    public:
        using type_t    = s16_t;
    };

    template <typename type_p>
    requires size_eq_tr<type_p, s32_t>
        class integer_signed_for_type<type_p>
    {
    public:
        using type_t    = s32_t;
    };

    template <typename type_p>
    requires size_eq_tr<type_p, s64_t>
        class integer_signed_for_type<type_p>
    {
    public:
        using type_t    = s64_t;
    };

    template <typename type_p>
    using integer_signed_for_t  = integer_signed_for_type<type_p>::type_t;

    template <typename type_p>
    using plain_for_t   = std::remove_cv_t<type_p>;

}
