/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_ecdefea7_3f85_4f0d_abda_5193805227d0
#define nkr_INCLUDE_GUARD_ecdefea7_3f85_4f0d_abda_5193805227d0

#include "nkr/built_in/forward_dec.h"
#include "nkr/generic/boolean/any_tr_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/interface/template_i_generic_tag_t_dec.h"

namespace nkr { namespace generic { namespace boolean { namespace impure_tr$ {

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

    struct  impure_tg   { class tag_lb; class generic_lb; };

    template <typename ...>
    struct  impure_ttg  {};

    template <typename type_p>
    concept impure_tr =
        nkr::generic::boolean::any_tr<type_p> &&
        impure_tr$::any_impure_operator_i<type_p>;

    template <template <typename ...> typename template_p>
    concept impure_ttr =
        impure_tr<typename interface::template_i<template_p>::example_t>;

}}}

namespace nkr { namespace generic { namespace boolean { namespace impure_tr$ {

    template <nkr::cpp::is_any_tr<nkr::generic::boolean::impure_tg> type_p>
    class type_i_tag_sp
    {
    public:
        using type_t    = type_p;
        using of_t      = nkr::none::type_t;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any_General() noexcept;
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any_Specific() noexcept;

    public:
        template <typename ...>
        constexpr type_i_tag_sp(...) noexcept   = delete;
    };

}}}}

namespace nkr { namespace interface {

    template <nkr::cpp::is_any_tr<nkr::generic::boolean::impure_tg> type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::generic::boolean::impure_tr$::type_i_tag_sp<type_p>;
    };

}}

namespace nkr { namespace generic { namespace boolean { namespace impure_tr$ {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::generic::boolean::impure_ttg>
    class template_i_tag_sp :
        public nkr::interface::template_i_generic_tag_t<
        nkr::generic::boolean::impure_tg,
        nkr::generic::boolean::impure_ttg>
    {
    public:
        template <template <typename ...> typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr template_i_tag_sp(...) noexcept   = delete;
    };

}}}}

namespace nkr { namespace interface {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::generic::boolean::impure_ttg>
    class template_i_sp<template_p>
    {
    public:
        using type_t    = nkr::generic::boolean::impure_tr$::template_i_tag_sp<template_p>;
    };

}}

#include "nkr/generic/boolean/impure_tr_dec_def.h"

#endif
