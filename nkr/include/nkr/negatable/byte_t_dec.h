/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/tr_dec.h"

#include "nkr/negatable/integer_t_dec.h"

#include "nkr/generic/negatable_tr_dec.h"
#include "nkr/generic/negatable/any_tr_dec.h"
#include "nkr/generic/negatable/integer_tr_dec.h"

namespace nkr { namespace negatable {

    using   byte_t =
        nkr::cpp::negatable::byte_t;

    struct  byte_tg {};

    template <typename type_p>
    concept byte_tr =
        nkr::cpp::is_any_tr<type_p, byte_t> ||
        (nkr::cpp::negatable_integer_tr<type_p> && sizeof(type_p) == sizeof(byte_t));

    template <byte_t value_p>
    using   byte_c =
        nkr::cpp::constant_t<byte_t, value_p>;

}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::negatable::byte_tg> :
        public type_i<nkr::negatable::byte_t>
    {
    public:
        using type_t    = nkr::negatable::byte_tg;
    };

}}

#include "nkr/negatable/byte_t_dec_def.h"

namespace nkr { namespace negatable {

    static_assert(generic::negatable_tr<byte_t>);
    static_assert(generic::negatable_tr<const byte_t>);
    static_assert(generic::negatable_tr<volatile byte_t>);
    static_assert(generic::negatable_tr<const volatile byte_t>);

    static_assert(generic::negatable::any_tr<byte_t>);
    static_assert(generic::negatable::any_tr<const byte_t>);
    static_assert(generic::negatable::any_tr<volatile byte_t>);
    static_assert(generic::negatable::any_tr<const volatile byte_t>);

    static_assert(generic::negatable::integer_tr<byte_t>);
    static_assert(generic::negatable::integer_tr<const byte_t>);
    static_assert(generic::negatable::integer_tr<volatile byte_t>);
    static_assert(generic::negatable::integer_tr<const volatile byte_t>);

}}
