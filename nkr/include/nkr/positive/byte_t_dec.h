/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/tr_dec.h"

#include "nkr/positive/integer_t_dec.h"

#include "nkr/generic/positive_tr_dec.h"
#include "nkr/generic/positive/any_tr_dec.h"
#include "nkr/generic/positive/integer_tr_dec.h"

namespace nkr { namespace positive {

    struct  byte_tg {};

    template <typename type_p>
    concept byte_tr =
        cpp::is_any_tr<type_p, byte_t> ||
        (cpp::positive_integer_tr<type_p> && sizeof(type_p) == sizeof(byte_t));

}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::positive::byte_tg> :
        public type_i<nkr::positive::byte_t>
    {
    public:
        using type_t    = nkr::positive::byte_tg;
    };

}}

#include "nkr/positive/byte_t_dec_def.h"

namespace nkr { namespace positive {

    static_assert(generic::positive_tr<byte_t>);
    static_assert(generic::positive_tr<const byte_t>);
    static_assert(generic::positive_tr<volatile byte_t>);
    static_assert(generic::positive_tr<const volatile byte_t>);

    static_assert(generic::positive::any_tr<byte_t>);
    static_assert(generic::positive::any_tr<const byte_t>);
    static_assert(generic::positive::any_tr<volatile byte_t>);
    static_assert(generic::positive::any_tr<const volatile byte_t>);

    static_assert(generic::positive::integer_tr<byte_t>);
    static_assert(generic::positive::integer_tr<const byte_t>);
    static_assert(generic::positive::integer_tr<volatile byte_t>);
    static_assert(generic::positive::integer_tr<const volatile byte_t>);

}}
