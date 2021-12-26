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

    struct  byte_tg {};

    template <typename type_p>
    concept byte_tr =
        cpp::is_any_tr<type_p, byte_t> ||
        (cpp::negatable_integer_tr<type_p> && sizeof(type_p) == sizeof(byte_t));

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
