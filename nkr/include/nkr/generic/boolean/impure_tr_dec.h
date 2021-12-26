/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/built_ins_dec.h"

#include "nkr/generic/boolean/any_tr_dec.h"

namespace nkr { namespace generic { namespace boolean { namespace $impure_tr {

    template <typename type_p>
    concept any_impure_operator_i =
        requires(type_p type) { +type; } ||
        requires(type_p type) { -type; } ||

        requires(type_p type) { type + 1; } ||
        requires(type_p type) { type - 1; } ||
        requires(type_p type) { type * 1; } ||
        requires(type_p type) { type / 1; } ||
        requires(type_p type) { type % 1; } ||

        requires(type_p type) { ~type; } ||
        requires(type_p type) { type | 1; } ||
        requires(type_p type) { type & 1; } ||
        requires(type_p type) { type ^ 1; } ||
        requires(type_p type) { type << 1; } ||
        requires(type_p type) { type >> 1; } ||

        requires(type_p type) { type += 1; } ||
        requires(type_p type) { type -= 1; } ||
        requires(type_p type) { type *= 1; } ||
        requires(type_p type) { type /= 1; } ||
        requires(type_p type) { type %= 1; } ||

        requires(type_p type) { type |= 1; } ||
        requires(type_p type) { type &= 1; } ||
        requires(type_p type) { type ^= 1; } ||
        requires(type_p type) { type <<= 1; } ||
        requires(type_p type) { type >>= 1; } ||

        requires(type_p type) { ++type; } ||
        requires(type_p type) { type++; } ||
        requires(type_p type) { --type; } ||
        requires(type_p type) { type--; } ||

        requires(type_p type) { type < 1; } ||
        requires(type_p type) { type > 1; } ||
        requires(type_p type) { type <= 1; } ||
        requires(type_p type) { type >= 1; } ||
        requires(type_p type) { type <=> 1; };

}}}}

namespace nkr { namespace generic { namespace boolean {

    struct  impure_tg   {};

    template <typename>
    struct  impure_ttg  {};

    template <typename type_p>
    concept impure_tr =
        any_tr<type_p> &&
        $impure_tr::any_impure_operator_i<type_p>;

}}}

namespace nkr { namespace interface {

    template <>
    class type_i<generic::boolean::impure_tg>
    {
    public:
        using of_t  = none::type_t;

    public:
        template <typename other_p>
        static constexpr boolean::cpp_t Is_Any() noexcept;
    };

    template <>
    class template_i<generic::boolean::impure_ttg>
    {
    public:
        template <typename of_p>
        using type_t    = generic::boolean::impure_tg;

    public:
        static constexpr boolean::cpp_t Is_Implemented() noexcept;
    };

}}

#include "nkr/generic/boolean/impure_tr_dec_def.h"
