/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/tr_dec.h"

#include "nkr/generic/negatable_tr_dec.h"
#include "nkr/generic/negatable/any_tr_dec.h"
#include "nkr/generic/negatable/integer_tr_dec.h"

namespace nkr { namespace negatable {

    using   integer_64_t =
        nkr::cpp::negatable::integer_64_t;

    struct  integer_64_tg   {};

    template <typename type_p>
    concept integer_64_tr =
        nkr::cpp::is_any_tr<type_p, integer_64_t> ||
        (nkr::cpp::negatable_integer_tr<type_p> && sizeof(type_p) * 8 == 64);

    template <integer_64_t value_p>
    using   integer_64_c =
        nkr::cpp::constant_t<integer_64_t, value_p>;

}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::negatable::integer_64_tg>
    {
    public:
        using type_t    = nkr::negatable::integer_64_tg;
        using of_t      = nkr::none::type_t;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr type_i(...) noexcept  = delete;
    };

    template <nkr::negatable::integer_64_tr type_p>
    class type_i<type_p> :
        public type_i<nkr::negatable::integer_64_tg>
    {
    public:
        using type_t    = type_p;
    };

}}

#include "nkr/negatable/integer_64_t_dec_def.h"

namespace nkr { namespace negatable {

    static_assert(generic::negatable_tr<integer_64_t>);
    static_assert(generic::negatable_tr<const integer_64_t>);
    static_assert(generic::negatable_tr<volatile integer_64_t>);
    static_assert(generic::negatable_tr<const volatile integer_64_t>);

    static_assert(generic::negatable::any_tr<integer_64_t>);
    static_assert(generic::negatable::any_tr<const integer_64_t>);
    static_assert(generic::negatable::any_tr<volatile integer_64_t>);
    static_assert(generic::negatable::any_tr<const volatile integer_64_t>);

    static_assert(generic::negatable::integer_tr<integer_64_t>);
    static_assert(generic::negatable::integer_tr<const integer_64_t>);
    static_assert(generic::negatable::integer_tr<volatile integer_64_t>);
    static_assert(generic::negatable::integer_tr<const volatile integer_64_t>);

}}
