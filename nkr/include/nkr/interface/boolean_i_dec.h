/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/cpp_dec.h"
#include "nkr/intrinsics_dec.h"

#include "nkr/interface/template_traits_i_dec.h"
#include "nkr/interface/type_traits_i_dec.h"

namespace nkr { namespace interface { namespace $boolean_i {

    template <typename type_p>
    concept static_constexpr_methods_i = requires
    {
        { type_p::Is_Boolean_Type() }   -> cpp::is_tr<cpp::bool_t>;
    };

    template <typename type_p>
    concept pure_operators_i = requires(cpp::just_non_qualified_t<type_p> type,
                                        cpp::just_const_t<type_p> const_type,
                                        cpp::just_volatile_t<type_p> volatile_type,
                                        cpp::just_const_volatile_t<type_p> const_volatile_type)
    {
        { type == true };
        { const_type == true };
        { volatile_type == true };
        { const_volatile_type == true };

        { type != true };
        { const_type != true };
        { volatile_type != true };
        { const_volatile_type != true };
    };

    template <typename type_p>
    concept any_impure_operators_i =
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

}}}

namespace nkr { namespace interface {

    template <typename type_p>
    concept boolean_i =
        cpp::is_any_tr<type_p, cpp::bool_t> ||
        ($boolean_i::static_constexpr_methods_i<type_p> &&
         $boolean_i::pure_operators_i<type_p> &&
         type_p::Is_Boolean_Type());

    // these should probably go in their own files, so that we can have defs that don't clash.
    // we may even have them as interface::boolean::pure_i, etc.
    // and just like the main library may have an nkr::boolean_t that aliases nkr::boolean::fast_t, we can have the nkr::boolean_i
    template <typename type_p>
    concept pure_boolean_i =
        boolean_i<type_p> &&
        !$boolean_i::any_impure_operators_i<type_p>;

    template <typename type_p>
    concept impure_boolean_i =
        boolean_i<type_p> &&
        $boolean_i::any_impure_operators_i<type_p>;

}}

namespace nkr { namespace interface {

    struct                      boolean_tg  {};
    template <typename> struct  boolean_ttg {};

    template <>
    class type_traits_i<boolean_tg>
    {
    public:
        using of_t  = cpp::void_t;

    public:
        template <typename other_p>
        static constexpr cpp::bool_t    Is_Any();
    };

    template <>
    class template_traits_i<boolean_ttg>
    {
    public:
        template <typename of_p>
        using type_t    = boolean_tg;

    public:
        static constexpr cpp::bool_t    Is_Implemented();
    };

}}
