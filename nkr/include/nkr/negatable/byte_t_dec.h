/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/tr_dec.h"

#include "nkr/negatable/integer_t_dec.h"

#include "nkr/trait/negatable_tr_dec.h"
#include "nkr/trait/negatable/any_tr_dec.h"
#include "nkr/trait/negatable/integer_tr_dec.h"

namespace nkr { namespace negatable {

    struct  byte_tg {};

    template <typename type_p>
    concept byte_tr =
        cpp::is_any_tr<type_p, byte_t> ||
        (cpp::negatable_integer_tr<type_p> && sizeof(type_p) == sizeof(byte_t));

}}

namespace nkr { namespace interface {

    template <>
    class type_i<negatable::byte_tg> :
        public type_i<negatable::byte_t>
    {
    public:
    };

}}

#include "nkr/negatable/byte_t_dec_def.h"

namespace nkr { namespace negatable {

    static_assert(trait::negatable_tr<byte_t>);
    static_assert(trait::negatable_tr<const byte_t>);
    static_assert(trait::negatable_tr<volatile byte_t>);
    static_assert(trait::negatable_tr<const volatile byte_t>);

    static_assert(trait::negatable::any_tr<byte_t>);
    static_assert(trait::negatable::any_tr<const byte_t>);
    static_assert(trait::negatable::any_tr<volatile byte_t>);
    static_assert(trait::negatable::any_tr<const volatile byte_t>);

    static_assert(trait::negatable::integer_tr<byte_t>);
    static_assert(trait::negatable::integer_tr<const byte_t>);
    static_assert(trait::negatable::integer_tr<volatile byte_t>);
    static_assert(trait::negatable::integer_tr<const volatile byte_t>);

}}
