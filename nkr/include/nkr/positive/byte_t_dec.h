/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/tr_dec.h"

#include "nkr/positive/integer_t_dec.h"

#include "nkr/trait/positive_tr_dec.h"
#include "nkr/trait/positive/any_tr_dec.h"
#include "nkr/trait/positive/integer_tr_dec.h"

namespace nkr { namespace positive {

    struct  byte_tg {};

    template <typename type_p>
    concept byte_tr =
        cpp::is_any_tr<type_p, byte_t> ||
        (cpp::positive_integer_tr<type_p> && sizeof(type_p) == sizeof(byte_t));

}}

namespace nkr { namespace interface {

    template <>
    class type_i<positive::byte_tg> :
        public type_i<positive::byte_t>
    {
    public:
    };

}}

#include "nkr/positive/byte_t_dec_def.h"

namespace nkr { namespace positive {

    static_assert(trait::positive_tr<byte_t>);
    static_assert(trait::positive_tr<const byte_t>);
    static_assert(trait::positive_tr<volatile byte_t>);
    static_assert(trait::positive_tr<const volatile byte_t>);

    static_assert(trait::positive::any_tr<byte_t>);
    static_assert(trait::positive::any_tr<const byte_t>);
    static_assert(trait::positive::any_tr<volatile byte_t>);
    static_assert(trait::positive::any_tr<const volatile byte_t>);

    static_assert(trait::positive::integer_tr<byte_t>);
    static_assert(trait::positive::integer_tr<const byte_t>);
    static_assert(trait::positive::integer_tr<volatile byte_t>);
    static_assert(trait::positive::integer_tr<const volatile byte_t>);

}}
